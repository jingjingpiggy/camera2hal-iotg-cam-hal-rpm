/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2014 Intel Corporation. All Rights Reserved.
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

#ifndef _IA_CIPF_BUFFER_BACKEND_H_
#define _IA_CIPF_BUFFER_BACKEND_H_

#include "ia_cipf_buffer.h"
#include "ia_cipf_types_internal.h"

/**
 * \ingroup ia_cipf_backend
 */
typedef ia_err_t (*ia_cipf_buffer_reference_destroy_op)(void *ref);

/** Add new reference associated with buffer
 *
 * \ingroup ia_cipf_backend
 *
 * \param[in]      buffer          ia_cipf_buffer_t handle
 * \param[in]      uid             uid of the reference
 * \param[in]      ref             pointer to the reference
 *
 * \return         ia_err_none if successful
 */
ia_err_t
ia_cipf_buffer_add_reference(ia_cipf_buffer_t *buffer,
                             ia_uid uid,
                             void *ref);

/** Add a new reference with destroy operation
 *
 * This function is otherwise similar to ia_cipf_buffer_add_reference, except
 * that an additional destroy operation is also included. The destroy operation
 * can be used for e.g. freeing allocated memory.
 *
 * \see ia_cipf_buffer_add_reference
 *
 * \ingroup ia_cipf_backend
 *
 * \param[in]      buffer          ia_cipf_buffer_t handle
 * \param[in]      uid             uid of the reference
 * \param[in]      ref             pointer to the reference
 * \param[in]      op              function pointer to reference destroy op
 *
 * \return         ia_err_none if successful
 */
ia_err_t
ia_cipf_buffer_add_reference_with_ops(ia_cipf_buffer_t *buffer,
                                      ia_uid uid,
                                      void *ref,
                                      ia_cipf_buffer_reference_destroy_op op);

#endif /* _IA_CIPF_BUFFER_BACKEND_H_ */
