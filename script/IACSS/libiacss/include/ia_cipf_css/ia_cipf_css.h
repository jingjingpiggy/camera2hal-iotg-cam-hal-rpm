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

#ifndef _IA_CIPF_CSS_H_
#define _IA_CIPF_CSS_H_

#include <ia_cipf/ia_cipf_types.h>

/* Note:
 * PSYS Library is considered to query UIDs from binary releases
 * or from other external definition (markup language?)
 *
 * Here we would define only the ones statically integrated
 */

#define psys_2401_vfpp_pg_uid       ia_fourcc('V','F','P','P')
#define psys_2401_vfpp_in_uid       psys_2401_vfpp_pg_uid + 1
#define psys_2401_vfpp_out_uid      psys_2401_vfpp_pg_uid + 2
#define psys_2401_vfpp_params_uid   psys_2401_vfpp_pg_uid + 3

#define psys_2401_preview_pg_uid     ia_fourcc('P','R','E','0')
#define psys_2401_preview_in_uid     psys_2401_preview_pg_uid + 1
#define psys_2401_preview_out_uid    psys_2401_preview_pg_uid + 2
#define psys_2401_preview_params_uid psys_2401_preview_pg_uid + 3

#define psys_2401_capture_pg_uid                ia_fourcc('P','R','I','0')
#define psys_2401_capture_in_uid                psys_2401_capture_pg_uid + 1
#define psys_2401_capture_params_uid            psys_2401_capture_pg_uid + 2
#define psys_2401_capture_main_output_uid       psys_2401_capture_pg_uid + 3
#define psys_2401_capture_vfpp_output_uid       psys_2401_capture_pg_uid + 4

#define psys_2401_codec_uid               ia_fourcc('2','4','C','O')
#define psys_2401_3A_grid_info_uid        psys_2401_codec_uid + 1
#define psys_2401_3A_statistics_uid       psys_2401_codec_uid + 2

#define psys_2401_lsc_table_uid         ia_fourcc('2','4','P','A')
#define psys_2401_3A_statistics_hi_uid  psys_2401_lsc_table_uid + 1
#define psys_2401_3A_statistics_lo_uid  psys_2401_lsc_table_uid + 2
#define psys_2401_3A_histogram_uid      psys_2401_lsc_table_uid + 3

/* 2600 UIDS */
#define psys_2600_small_uid         ia_fourcc('S','M','A','0')
#define psys_2600_small_input_uid   psys_2600_small_uid + 1
#define psys_2600_small_output_uid  psys_2600_small_uid + 2
#define psys_2600_small_param_uid   psys_2600_small_uid + 3
#define psys_2600_small_secondary_output_uid psys_2600_small_uid + 4

#define psys_2600_4k60_pg_id        107
#define psys_2600_4k60_uid          ia_fourcc('P',psys_2600_4k60_pg_id,'G','0')
#define psys_2600_4k60_input_uid    psys_2600_4k60_uid + 1
#define psys_2600_4k60_output_uid   psys_2600_4k60_uid + 2
#define psys_2600_4k60_param_uid    psys_2600_4k60_uid + 3
#define psys_2600_4k60_secondary_output_uid psys_2600_4k60_uid + 4

#define psys_2600_popg_pg_id                201
#define psys_2600_popg_uid                  ia_fourcc('P',psys_2600_popg_pg_id,'G','0')
#define psys_2600_popg_param_uid            psys_2600_popg_uid + 1
#define psys_2600_popg_program_uid          psys_2600_popg_uid + 2
#define psys_2600_popg_input_uid            psys_2600_popg_uid + 3
#define psys_2600_popg_output_uid           psys_2600_popg_uid + 4
#define psys_2600_popg_secondary_output_uid psys_2600_popg_uid + 5

#define psys_2600_post_gdc_pg_id                114
#define psys_2600_post_gdc_uid                  ia_fourcc('P',psys_2600_post_gdc_pg_id,'G','0')
#define psys_2600_post_gdc_param_uid            psys_2600_post_gdc_uid + 1
#define psys_2600_post_gdc_program_uid          psys_2600_post_gdc_uid + 2
#define psys_2600_post_gdc_input_uid            psys_2600_post_gdc_uid + 3
#define psys_2600_post_gdc_spatial_param_uid    psys_2600_post_gdc_uid + 4
#define psys_2600_post_gdc_output_uid           psys_2600_post_gdc_uid + 5
#define psys_2600_post_gdc_secondary_output_uid psys_2600_post_gdc_uid + 6

#define psys_2600_video_pre_gdc_pg_id        116
#define psys_2600_video_pre_gdc_uid          ia_fourcc('P',psys_2600_video_pre_gdc_pg_id,'G','0')
#define psys_2600_video_pre_gdc_param_uid    psys_2600_video_pre_gdc_uid + 1
#define psys_2600_video_pre_gdc_program_uid  psys_2600_video_pre_gdc_uid + 2
#define psys_2600_video_pre_gdc_input_uid    psys_2600_video_pre_gdc_uid + 3
#define psys_2600_video_pre_gdc_output_uid   psys_2600_video_pre_gdc_uid + 4

#define psys_interleaved_code_uid     ia_fourcc('I','L','C','S')
#define psys_interleaved_code_in_uid  psys_interleaved_code_uid + 1
#define psys_interleaved_code_out_uid psys_interleaved_code_uid + 2

#define psys_command_timeout_ms_uid ia_fourcc('P','S','C','T')

/* COMMON CSS UIDS */
#define css_program_group_params_uid ia_fourcc('C','S','S','P')
#define css_frame_descriptor_uid     ia_fourcc('C','S','S','F')
#define css_fourcc_raw               ia_fourcc('C','S','B','A')
#define css_fourcc_raw_interleaved   ia_fourcc('C','S','R','I')
#define css_fourcc_internal_yuv_line ia_fourcc('C','S','Y','C')
#define css_fourcc_yyuv420_v32       ia_fourcc('C','S','Y','U')
#define css_sc_descriptor_uid        ia_fourcc('C','S','S','C')
#define css_frame_max_resolution_uid ia_fourcc('C','S','M','A')
#define css_frame_min_resolution_uid ia_fourcc('C','S','M','I')
#define css_program_group_manifest_uid ia_fourcc('C','S','S','M')
#define css_process_group_uid        ia_fourcc('C','S','P','G')
#define css_fragment_max_uid         ia_fourcc('C','S','F','<')
#define css_fragment_min_uid         ia_fourcc('C','S','F','>')
#define css_fragment_uid             ia_fourcc('C','S','F','S')
#define css_terminal_descriptor_uid  ia_fourcc('C','S','S','T')
#define css_kernel_bitmap_uid        ia_fourcc('C','S','S','K')

/* Encode 8bit vied_nci_resource_id_t into least significat byte of UID */
#define css_vied_nci_kernel_id_uid_mask ia_fourcc(0xFF,0xFF,0xFF,0)
#define css_vied_nci_kernel_id_uid(x)   ia_fourcc('K','I','#', x)

/*** User control utils for PSYS stage ***/

/** Calculate sizeof unidentified PSYS stage property
 *
 * This function is intended for generalizing the calculus of stage property
 * sizes when they need to be identified by user, but PSYS library provides
 * helper utilities for the purpose.
 *
 * Property sizes may dependent on other configuration details of a stage. In
 * such case the order of sequence needs to be derived from PSYS PG
 * specification.
 *
 * Returns 0 when property cannot be identified or size calculus misses input.
 * Note: value 0 cannot be set as size of property payload and hence the
 * property identification loop will fail unless user handles the case.
 *
 * \param[in]   property    property object to identify
 */
uint32_t psys_library_control_sizeof_property(ia_cipf_property_t *property);

/** Preset data of PSYS stage buffer
 *
 * This function is intended to be called when new buffers are allocated and
 * registered for use of PSYS stage.
 *
 * In case of parameter buffers, this function can be expected to take care
 * of setting the defaults when available.
 *
 * Buffer preset function may be dependent on other configuration details of
 * a stage. This function can be expected to fetch the information from the
 * stage that user has configured according to PSYS PG specification as a
 * precondition (e.g terminal formats need to be configured).
 *
 * \param[in,out] buffer    buffer object to preset
 */
ia_err_t psys_library_control_preset_buffer(ia_cipf_buffer_t *buffer);

#endif
