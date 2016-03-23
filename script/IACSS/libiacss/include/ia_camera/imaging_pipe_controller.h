/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2015 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 */

/** \file imaging_pipe_controller.h
 *
 * \defgroup imaging_pipe_ctrl Pipe controller for graphs with IPU
 * imaging stages
 * \brief Tentative API to unify data-flows between camera control algorithms
 * stack coverned by HAL and CIPF pipelines with IPU stages.
 * TODO: make controller the owner of P2P and pass PAL binary data over the
 *       interface.
 */
#ifndef __IMAGING_PIPE_CONTROLLER_H__
#define __IMAGING_PIPE_CONTROLLER_H__

#include <ia_types.h>
#include <ia_cipf/ia_cipf_pipe.h>

typedef struct imaging_pipe_ctrl_s imaging_pipe_ctrl_t;

typedef enum _imaging_stage_status
{
    IMAGING_STAGE_UNKNOWN,
    IMAGING_STAGE_NEW_IPU,
    IMAGING_STAGE_IPU
} imaging_stage_status_t;

/** Initialize controller
 *
 * \ingroup imaging_pipe_ctrl
 */
imaging_pipe_ctrl_t* imaging_pipe_ctrl_init(ia_cipf_pipe_t *pipe);

/** Destroy controller
 *
 * \ingroup imaging_pipe_ctrl
 * \param ctrl handle
 */
void imaging_pipe_ctrl_destroy(imaging_pipe_ctrl_t *ctrl);

/** Identify CIPF stage
 *
 * Identify stage from pipeline
 *
 * Validates that the stage is among the ones supported by the controller.
 * Reference to newly introduced stage is added to controller. Returns status
 * for the stage that can be used for choosing the correct control path.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] stage_uid stage UID of stage to identify
 * \param[out] status of the identified stage
 */
ia_err_t
imaging_pipe_ctrl_identify_stage(imaging_pipe_ctrl_t *ctrl,
                                 ia_uid stage_uid,
                                 imaging_stage_status_t *status);

/** Identify CIPF property
 *
 * Identifies properties of imaging stages in the pipeline and configures
 * the controller accordingly.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] property object to be indentified
 */
ia_err_t
imaging_pipe_ctrl_identify_property(imaging_pipe_ctrl_t *ctrl,
                                    ia_cipf_property_t *property);

/** Prepare stage
 *
 * Prepare controller to the state ready to exchange data with the stage.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] stage_uid uid of the stage to be configured
 * \param[in] ipu_parameters IPU parameters to prepare the stage with
 */
ia_err_t
imaging_pipe_ctrl_prepare_stage(imaging_pipe_ctrl_t *ctrl,
                                ia_uid stage_uid,
                                const ia_binary_data *ipu_parameters);

/** Add buffer
 *
 * Add buffer to the controller and preset its payload data
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] buffer buffer object to be added
 */
ia_err_t
imaging_pipe_ctrl_add_buffer(imaging_pipe_ctrl_t *ctrl,
                             ia_cipf_buffer_t *buffer);

/** Configure stage for iteration
 *
 * Configure stage for iteration by encoding all parameters to its terminals.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] stage_uid uid of the stage to be configured
 * \param[in] iterator iterator handle
 * \param[in] ipu_parameters IPU parameters to configure the stage with
 */
ia_err_t
imaging_pipe_ctrl_configure_stage(imaging_pipe_ctrl_t *ctrl,
                                  ia_uid stage_uid,
                                  ia_cipf_iterator_t *iterator,
                                  const ia_binary_data *ipu_parameters);

/** Configure all stages in iteration
 *
 * Configures all stages in iteration that were identified and prepared by the
 * controller. The rest of stages are skipped.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] iterator iterator handle
 * \param[in] ipu_parameters IPU parameters to configure the stages with
 */
ia_err_t
imaging_pipe_ctrl_configure_stages(imaging_pipe_ctrl_t *ctrl,
                                   ia_cipf_iterator_t *iterator,
                                   const ia_binary_data *ipu_parameters);

/** Decode statistics from stage in iteration
 *
 * Decodes statistics from all stages in iteration.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] iterator iterator handle
 * \param[in] ipu_parameters IPU parameters to configure the stages with
 */
ia_err_t
imaging_pipe_ctrl_decode_statistics(imaging_pipe_ctrl_t *ctrl,
                                    ia_cipf_iterator_t *iterator,
                                    ia_uid stage_uid,
                                    ia_binary_data *statistics);





#endif
