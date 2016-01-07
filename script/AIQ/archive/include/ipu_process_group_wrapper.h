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

/** \file ipu_process_group_wrapper.h
 *
 * \defgroup ipu_process_group_wrapper IPU Process Group Wrapper
 * \brief Tentative wrapper for process group create and steps to encode to
 * and decode from its terminal payloads.
 *
 * The intention of this wrapper is to make OS dependent code agnostic
 * of PG specification internals (the kernels) operated by cross-os imaging
 * stack. OS dependent code (HAL) is responsible to query and allocate the
 * memory requirements, construct the process group object as well as give
 * data address mappings for P2P to encode to and decode from the terminal
 * payloads. In proposed architecture this type of interface would be owned
 * by the imaging libraries.
 */

#include "ia_tools/ia_types.h"
#include "ia_p2p_types.h"
#include "ia_p2p.h"

#define IPU_MAX_TERMINAL_COUNT 16
#define IPU_MAX_KERNELS_PER_PG 64

typedef struct ipu_pg_die_s* ipu_pg_die_t;

/** Initialize wrapper
 *
 * Needs to be provided with P2P instance already filled with PAL input
 * parameters at least for kernels covered by the given program group
 * specification.
 *
 * Init retrieves the memory requirement information for a process group
 * with configuration given to P2P.parse().
 *
 * Available program group specifications can be queried runtime using CIPR.
 *
 * Note: implemented only for ISYS ISA
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param[in] p2p handle to P2P instance
 * \param[in] pg  program group specification ID
 */
ipu_pg_die_t
ipu_pg_die_init(ia_p2p_handle p2p,
                const uint32_t pg_specification);

/** Destroy wrapper
 *
 * \ingroup ipu_process_group_wrapper
 * \param pg_die wrapper handle
 */
void
ipu_pg_die_destroy(ipu_pg_die_t pg_die);

/** Query memory requirement for process group object
 *
 * \ingroup ipu_process_group_wrapper
 * \param pg_die wrapper handle
 */
uint32_t
ipu_pg_die_sizeof_process_group(ipu_pg_die_t pg_die);

/** Create process group structure
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in,out] process_group ia_binary_data pointing to memory allocated
 *                              for process group object
 */
ia_err_t
ipu_pg_die_create_process_group(ipu_pg_die_t pg_die,
                                ia_binary_data *process_group);

/** Get number of terminals
 *
 * Retrieve the number of terminals in a process group. This information
 * is encoded in the process group object but was cached in the wrapper
 * based on p2p input configuration.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 */
ia_err_t
ipu_pg_die_get_number_of_terminals(ipu_pg_die_t pg_die);

/** Get memory requirement for a terminal payload
 *
 * Retrieve the size for payload that is required by a terminal.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 */
ia_err_t
ipu_pg_die_sizeof_terminal_payload(ipu_pg_die_t pg_die,
                                   uint8_t terminal_index);

/** Get terminal direction
 *
 * Retrieve the direction of terminal data
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param terminal_index index of the terminal
 */
bool
ipu_pg_die_is_input_terminal(ipu_pg_die_t pg_die,
                             uint8_t terminal_index);

/** Get terminal index of a terminal with specific use
 *
 * Returns terminal index by given unique identifier. By default, all the
 * terminal data can be encoded and decoded transparently to the purpose of
 * the data. In other words, user can enumerate through all the terminals to
 * encode and decode the data between process group payloads and P2P.
 *
 * Decode operations for 3A statistics are currently implemented in P2P with
 * explicit result binary datas and there is dedicated library from ia_imaging
 * to convert it further to AIQ input.
 *
 * When data from or to process group needs special handling, the terminal of
 * a program group specification needs to be uniquely mapped with ID's that
 * shall include version handling of the data interface.
 *
 * Note: For back and forward compatibility unsigned 32-bit value is used as
 *       ID. Current implementation for ISYS ISA responds to kernel ID's
 *       directly when the terminal is associated with only one kernel:
 *       IA_CSS_ISYS_KERNEL_ID_3A_STAT_AE,
 *       IA_CSS_ISYS_KERNEL_ID_3A_STAT_AWB,
 *       IA_CSS_ISYS_KERNEL_ID_3A_STAT_AF
 *       (vied_parameters/support/ia_css_isys_parameter_defs.h).
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in] uid unique ID of the terminal
 * \param[out] terminal_index index of the terminal
 */
ia_err_t
ipu_pg_die_get_terminal_by_uid(ipu_pg_die_t pg_die,
                               uint32_t uid,
                               int *terminal_index);

/** Encode a terminal payload
 *
 * In process group there are input and output terminals. For input terminals
 * P2P is used to encode all the parameter data into the payloads that user
 * allocates. P2P is also responsible to fill in the terminal descriptors
 * in the process group object. Filling the terminal descriptors is also
 * needed with output terminals before submitting the process group to IPU
 * FW. Therefore user needs to enumerate through all of the terminal buffers.
 * In P2P API the operation for output terminals is called preparing.
 *
 * PG specification and manifest shall be used internally to control what
 * kernels are covered by the program group.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in] uid unique ID of the terminal
 * \param[out] terminal_index index of the terminal
 * \param[in] terminal_offset offset from the base of the payload buffer to the
 *            start of the payload sections specific for this terminal
 */
ia_err_t
ipu_pg_die_encode_terminal_payload(ipu_pg_die_t pg_die,
                                   ia_p2p_handle p2p,
                                   ia_binary_data *process_group,
                                   uint8_t terminal_index,
                                   ia_binary_data *payload,
                                   uint64_t terminal_offset);

/** Decode a terminal payload
 *
 * Decodes a process group terminal payload into binary results compatible
 * with other ia_imaging component.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in] uid unique ID of the terminal
 * \param[in] payload pointer to the payload binary data
 * \param[out] terminal_index index of the terminal
 * \param[out] result binary blob containing the decoded parameters. Is should
 *             be provided by the client
 */
ia_err_t
ipu_pg_die_decode_terminal_payload(ipu_pg_die_t pg_die,
                                   ia_p2p_handle p2p,
                                   ia_binary_data *process_group,
                                   uint8_t terminal_index,
                                   ia_binary_data *payload,
                                   ia_binary_data *result);

/** Dump to traces the information about process group
 *
 * Used only for debugging purposes.
 * For the given P2P wrapper it prints the size of the process group
 * the number of terminals
 * For each terminal it reports the type and the payload size.
 *
 * In case process_group binary is provided, it is interpreted and dumped into
 * logs as well.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param[in] pg_die wrapper handle
 */
ia_err_t
ipu_pg_die_dump_info(ipu_pg_die_t pg_die, ia_binary_data *process_group);
