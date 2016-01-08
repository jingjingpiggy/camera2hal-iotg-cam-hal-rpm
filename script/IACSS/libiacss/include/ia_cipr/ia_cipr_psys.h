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

/** \file ia_cipr_psys.h
 *
 * CIPR PSYS Command Queue device header
 *
 * \defgroup ia_cipr_command_queue_device Command Queue Device
 * \ingroup ia_cipr
 * \brief Command Queue Device abstraction module exists only in documentation
 * since there is only PSYS command queue device supported in CIPR.
 * \see ia_cipr_psys.
 *
 * \defgroup ia_cipr_psys Processing System (PSYS)
 * \ingroup ia_cipr_command_queue_device
 * \brief CIPR PSYS implements command queue interface on top of IPU
 * processing system hardware. Interface calls are used to manage compute
 * on IPU in atomic units of execution. Each command includes memory objects
 * dealt opaquely as indexed array of ia_cipr_buffer_t's.
 *
 * CIPR PSYS command queue lies on top of low level scheduler that manages
 * work from multiple queues of concurrent CIPR clients. Semantics of the
 * array and data transmission between compute kernels and CIPR clients is
 * further specified by IPU firmware architecture.
 *
 * \note Current datatypes for the command specification are tentative and
 *       expose naming conventions derived from firmware architecture, namely
 *       program group manifest and parameters. These are specific to
 *       existing IPU4 implementation and subject to change. Conceptually
 *       CIPR command is a bundle of buffers that may consist of both memory
 *       and program objects.
 */

#ifndef _IA_CIPR_PSYS_H_
#define _IA_CIPR_PSYS_H_

#include "ia_tools/ia_types.h"
#include <ia_cipr/ia_cipr_memory_device.h>

/**
 * CIPR Device ID definition for PSYS device
 */
#define CIPR_DEVICE_PSYS    (ia_cipr_device_id_t)0xFE

/**
 * \ingroup ia_cipr_psys
 */
typedef struct _psys_context* ia_cipr_psys_context_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct _psys_command* ia_cipr_psys_command_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct _psys_event* ia_cipr_psys_event_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct ia_cipr_psys_event_config {
    uint32_t type;      /* TODO create enums for this?*/
    uint32_t id;
    uint64_t command_issue_id;
    uint32_t buffer_idx;
    uint32_t error;
    int32_t timeout;
} ia_cipr_psys_event_config_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct ia_cipr_psys_command_config {
    uint32_t id;
    uint64_t issue_id;
    uint32_t priority;
    uint32_t bufcount;
    ia_cipr_buffer_t **buffers;
    void *pg_manifest;
    void *pg_params;
    uint32_t pg_manifest_size;
    uint32_t pg_params_size;
    ia_cipr_buffer_t *pg;
} ia_cipr_psys_command_config_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct ia_cipr_psys_capability_s {
    uint32_t version;
    uint8_t driver[20];
    uint32_t program_group_count;
} ia_cipr_psys_capability_t;

/**
 * Create PSYS context
 *
 * Returns handle to PSYS context that can be used to access
 * ia_cipr_psys interface. Single command queue gets created
 * per each create and following functions are bound to this
 * queue:
 *
 * ia_cipr_psys_queue_command()
 *
 * ia_cipr_psys_wait_for_event()
 *
 * The rest of interface operations are independent from the
 * queue and for example the buffer objects are interchangeable
 * between the contexts of the same process. For memory sharing
 * between processes, per process ia_cipr_buffer_t object needs
 * to be used in combination with shared memory handle.
 *
 * \see ia_cipr_memory
 *
 * \ingroup ia_cipr_psys
 */
ia_cipr_psys_context_t ia_cipr_psys_create_context(void);

/**
 * Destroy PSYS context
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 */

void ia_cipr_psys_destroy_context(ia_cipr_psys_context_t ctx);

/**
 * Get CIPR Memory device handle
 *
 * Returns ia_cipr_memory_device_t handle that can be used
 * with CIPR Memory interface for memory primitives offered
 * by the device.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 */
ia_cipr_memory_device_t*
ia_cipr_psys_get_memory_device(ia_cipr_psys_context_t ctx);

/**
 * Get CIPR device capabilities
 *
 * Fills ia_cipr_psys_capability_t with information supported by the
 * device.
 *
 * \todo make this direct query of capability info data, having separate
 *       _config_t does not make sense.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[out] capability pointer to ia_cipr_psys_capability_t
 */
ia_err_t ia_cipr_psys_get_capabilities(ia_cipr_psys_context_t ctx,
                                       ia_cipr_psys_capability_t *capability);

/**
 * Get Program Group manifest
 *
 * Fills ia_css_program_group_manifest_t for given index.
 * Needs to be used to query size of the manifest first using NULL as manifest
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in] index index of the manifest in platform
 * \param[in,out] size_of_manifest pointer to the size of manifest
 *                                 gets filled with correct size in case
 *                                 \manifest is NULL.
 * \param[in,out] manifest pointer to memory to hold the manifest
 */
ia_err_t ia_cipr_psys_get_manifest(ia_cipr_psys_context_t ctx,
                                   uint32_t index,
                                   uint32_t *manifest_size,
                                   void *manifest);

/**
 * Queue compute command for PSYS execution
 *
 * Places the command object in queue to be scheduled and executed
 * asynchronously in the PSYS device. Completion of each command issued
 * can be tracked with ia_cipr_psys_wait_for_event() using issue-id's.
 *
 * \todo introduce bitflags to control wakeup events.
 *       wakeup control flag can be used also for bundling commands for
 *       the l-scheduler.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in] cmd ia_cipr_psys_command_t object
 */
ia_err_t ia_cipr_psys_queue_command(ia_cipr_psys_context_t ctx,
                                    ia_cipr_psys_command_t cmd);
/**
 * Cancel compute command
 *
 * Cancels the compute command or removes the corresponding command
 * from command queue in case the command didn't reach execution.
 *
 * \note Canceling command that has reached execution introduces
 *       device dependent latencies. Currently not supported.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in] cmd ia_cipr_psys_command_t object
 */
ia_err_t ia_cipr_psys_cancel_command(ia_cipr_psys_context_t ctx,
                                     ia_cipr_psys_command_t cmd);
/**
 * Wait for specific command completion
 *
 * Returns after the command specified by ia_cipr_psys_event_t
 * completes or there was an error in execution.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in,out] event ia_cipr_psys_event_t object
 */
ia_err_t ia_cipr_psys_wait_for_event(ia_cipr_psys_context_t ctx,
                                     ia_cipr_psys_event_t event);

/**
 * Create PSYS event object
 *
 * Returns ia_cipr_psys_event_t object handle. Object is created based on
 * ia_cipr_psys_event_config_t specification and can be further used with
 * ia_cipr_psys_wait_for_event()
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cfg ia_cipr_psys_event_config_t event config specification
 */
ia_cipr_psys_event_t
ia_cipr_psys_create_event(ia_cipr_psys_event_config_t *cfg);

/**
 * Destroy PSYS event object
 *
 * \ingroup ia_cipr_psys
 * \param[in] event event object handle
 */
void ia_cipr_psys_destroy_event(ia_cipr_psys_event_t event);

/**
 * Read event config specification from event object
 *
 * \ingroup ia_cipr_psys
 * \param[out] cfg ia_cipr_psys_event_config_t
 */
ia_err_t
ia_cipr_psys_get_event_config(ia_cipr_psys_event_t event,
                              ia_cipr_psys_event_config_t *cfg);

/**
 * Create PSYS command object
 *
 * Returns ia_cipr_psys_command_t object handle. Object is created based on
 * ia_cipr_psys_command_config_t specification and can be further used with
 * ia_cipr_psys_queue_command()
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cfg ia_cipr_psys_command_config_t command config specification
 */
ia_cipr_psys_command_t
ia_cipr_psys_create_command(ia_cipr_psys_command_config_t *cfg);

/**
 * Destroy PSYS command object
 *
 * \ingroup ia_cipr_psys
 * \param[in] cmd command object handle
 */
void ia_cipr_psys_destroy_command(ia_cipr_psys_command_t cmd);

/**
 * Read command config specification from command object
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cmd command object handle
 * \param[out] cfg ia_cipr_psys_command_config_t
 */
ia_err_t
ia_cipr_psys_get_command_config(ia_cipr_psys_command_t cmd,
                                ia_cipr_psys_command_config_t *cfg);
/**
 * Update command config specification of command object
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cmd command object handle
 * \param[in] cfg ia_cipr_psys_command_config_t
 */
ia_err_t
ia_cipr_psys_set_command_config(ia_cipr_psys_command_t cmd,
                                const ia_cipr_psys_command_config_t *cfg);

/* obsolete
 * \todo replace by memory_device ops
 */
ia_err_t ia_cipr_psys_register_buffer(ia_cipr_psys_context_t ctx,
                                      ia_cipr_buffer_t *buffer);

/* obsolete
 * \todo replace by memory_device ops
 */
ia_err_t ia_cipr_psys_unregister_buffer(ia_cipr_psys_context_t ctx,
                                        ia_cipr_buffer_t *buffers);


#endif  /* _IA_CIPR_PSYS_H_ */
