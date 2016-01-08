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

#ifndef _IA_CIPF_BUFFER_H_
#define _IA_CIPF_BUFFER_H_

#include "ia_cipf_types.h"

/** \defgroup ia_cipf_buffer Buffer (ia_cipf_buffer_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf_buffer_t object interface
 */

/**
 * \ingroup ia_cipf_buffer
 */
ia_cipf_buffer_t*
ia_cipf_buffer_create(void);

/** Replicate association to buffer based on reference buffer
 *
 * All buffers in CIPF need to be associated to some terminal or property
 * container. This is automatic for buffers queried. But usually multiple
 * buffers need to be allocated and separately created. With this function
 * caller can copy association from buffer to another.
 *
 * \ingroup ia_cipf_buffer
 */
ia_err_t
ia_cipf_buffer_replicate_association(ia_cipf_buffer_t *buffer,
                                     const ia_cipf_buffer_t *ref);

/** Create a copy of ia_cipf_buffer_t
 *
 * Function creates a copy of ia_cipf_buffer_t including its association
 * and payload when it is allocated using ia_cipf_buffer_allocate_payload().
 *
 * By default ia_cipf_buffer_t::payload is reference owned by the caller.
 * Copying this type of payloads is not supported and caller must use
 * ia_cipf_buffer_replicate_association() added with custom operations
 * to copy the payload.
 *
 * \ingroup ia_cipf_buffer
 */
ia_cipf_buffer_t*
ia_cipf_buffer_create_copy(const ia_cipf_buffer_t *ref);

/** Allocate payload for the buffer
 *
 * By default ia_cipf_buffer_t::payload is reference owned by the caller.
 *
 * This function allocates the payload as data owned by the buffer.
 * This is the only type of payload that gets copied by
 * ia_cipf_buffer_create_copy().
 *
 * \ingroup ia_cipf_buffer
 */
ia_err_t
ia_cipf_buffer_allocate_payload(ia_cipf_buffer_t *buffer, uint32_t size);

/**
 * \ingroup ia_cipf_buffer
 */
void
ia_cipf_buffer_destroy(ia_cipf_buffer_t *buffer);

/**
 * \ingroup ia_cipf_buffer
 */
ia_err_t
ia_cipf_buffer_get_terminal_type(ia_cipf_buffer_t *buffer,
                                 ia_cipf_terminal_type_t *type);

/**
 * \ingroup ia_cipf_buffer
 */
ia_cipf_terminal_t*
ia_cipf_buffer_get_terminal(ia_cipf_buffer_t *buffer);

/**
 * Get identifier for association of given buffer object
 *
 * Returned identifier is ia_uid of container object, that
 * may derive to either terminal or property buffer requirement
 * of a stage in pipeline.
 *
 * \ingroup ia_cipf_buffer
 */
ia_uid
ia_cipf_buffer_get_association_uid(ia_cipf_buffer_t *buffer);

/** Get stage associated with buffer
 *
 * \ingroup ia_cipf_buffer
 */
ia_cipf_stage_t*
ia_cipf_buffer_get_stage(ia_cipf_buffer_t *buffer);

/** Get frame format associated with buffer
 *
 * In case buffer payload is identified as frame format, the payload
 * data is copied into frame format given as argument.
 *
 * In case buffer payload is something else, function queries the
 * native ia_cipf_frame_format_uid through the association.
 * \see ia_cipf_buffer_associate.
 *
 * \ingroup ia_cipf_buffer
 */
ia_err_t
ia_cipf_buffer_get_frame_format(ia_cipf_buffer_t *buffer, ia_cipf_frame_format_t *ff);

/** Get frame stucture refence
 *
 * \ingroup ia_cipf_buffer
 */
ia_cipf_frame_t*
ia_cipf_buffer_get_frame_ref(ia_cipf_buffer_t *buffer);

/** Get payload of buffer section
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer  handle to ia_cipf_buffer_t
 * \param[in]       uid     uid of the payload section to search
 * \param[out]      payload object to fill with relative reference
 *                          to buffer section.
 */
ia_err_t
ia_cipf_buffer_get_payload_section_ref(ia_cipf_buffer_t *buffer,
                                       ia_uid uid,
                                       ia_cipf_payload_t *payload);

/** Query associated references from buffer
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer  handle to ia_cipf_buffer_t.
 * \param[in]       uid     uid specifying the type of reference.
 * \param[out]      reference Pointers pointer to updated with reference if
 *                            found.
 */
ia_err_t
ia_cipf_buffer_query_reference(const ia_cipf_buffer_t *buffer,
                               ia_uid uid,
                               void **reference);

/** Get access to buffer payload
 *
 * Fetch payload information including host address to the data associated
 * with buffer object. While payload is public information in buffer object,
 * it may contain payload that requires interpretation or memory operations
 * before the data can be accessed by host code. This function includes the
 * operations for natively identified payloads, like buffer objects of
 * platform runtime.
 *
 * Note: function also skips one dimension with frame object of frame
 *       terminal. In this case, the first the payload of first plane is
 *       chosen. Handling multiplane frame requires specific care from a
 *       stage.
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer handle to ia_cipf_buffer_t
 * \param[out]      payload object to fill with description of
 *                  buffer associated payload data
 *
 * \return          ia_err_none if successful
 */
ia_err_t
ia_cipf_buffer_access_payload(ia_cipf_buffer_t *buffer,
                              ia_cipf_payload_t *payload);

/** Check if buffer payload is external reference
 *
 * Convenience function to check whether the memory of payload is external
 * to buffer object.
 *
 * Note: In cases of complex CIPF pipelines, there can be memory providers in
 * the backend. Therefore this information is not enough to identify user
 * allocated buffers alone. More sophisticated bookkeeping of buffers is
 * suggested.
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer handle to ia_cipf_buffer_t
 * \param[out]      is_reference true in case payload is external reference
 * \return          ia_err_none if successful
 */
ia_err_t
ia_cipf_buffer_is_reference_payload(ia_cipf_buffer_t *buffer,
                                    bool *is_reference);

#endif /* _IA_CIPF_BUFFER_H_ */
