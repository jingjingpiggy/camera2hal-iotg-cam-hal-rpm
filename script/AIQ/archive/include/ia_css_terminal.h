/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2015 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code (\"Material\") are owned by Intel Corporation or its suppliers
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

#ifndef __IA_CSS_TERMINAL_H__
#define __IA_CSS_TERMINAL_H__

#include "type_support.h"


typedef struct ia_css_program_terminal_s			ia_css_program_terminal_t;
typedef struct ia_css_fragment_param_section_desc_s		ia_css_fragment_param_section_desc_t;
typedef struct ia_css_kernel_fragment_sequencer_info_desc_s	ia_css_kernel_fragment_sequencer_info_desc_t;
typedef struct ia_css_kernel_fragment_sequencer_command_desc_s	ia_css_kernel_fragment_sequencer_command_desc_t;

typedef struct ia_css_sliced_param_terminal_s			ia_css_sliced_param_terminal_t;
typedef struct ia_css_fragment_slice_desc_s			ia_css_fragment_slice_desc_t;
typedef struct ia_css_slice_param_section_desc_s		ia_css_slice_param_section_desc_t;

typedef struct ia_css_spatial_param_terminal_s			ia_css_spatial_param_terminal_t;
typedef struct ia_css_frame_grid_desc_s				ia_css_frame_grid_desc_t;
typedef struct ia_css_frame_grid_param_section_desc_s		ia_css_frame_grid_param_section_desc_t;
typedef struct ia_css_fragment_grid_desc_s			ia_css_fragment_grid_desc_t;

typedef struct ia_css_param_terminal_s				ia_css_param_terminal_t;
typedef struct ia_css_param_section_desc_s			ia_css_param_section_desc_t;

typedef struct ia_css_param_payload_s				ia_css_param_payload_t;
typedef struct ia_css_terminal_s				ia_css_terminal_t;


extern unsigned int ia_css_param_in_terminal_get_descriptor_size(
	const unsigned int nof_sections
);

extern ia_css_param_section_desc_t *ia_css_param_in_terminal_get_param_section_desc(
	const ia_css_param_terminal_t *param_terminal,
	const unsigned int section_index
);

extern unsigned int ia_css_param_out_terminal_get_descriptor_size(
	const unsigned int nof_sections,
	const unsigned int nof_fragments
);

extern ia_css_param_section_desc_t *ia_css_param_out_terminal_get_param_section_desc(
	const ia_css_param_terminal_t *param_terminal,
	const unsigned int section_index,
	const unsigned int nof_sections,
	const unsigned int fragment_index
);

extern int ia_css_param_terminal_create(
	ia_css_param_terminal_t *param_terminal,
	const uint16_t terminal_offset,
	const uint16_t terminal_size,
	const uint16_t is_input_terminal
);

extern unsigned int ia_css_spatial_param_terminal_get_descriptor_size(
	const unsigned int nof_frame_param_sections,
	const unsigned int nof_fragments
);

extern ia_css_fragment_grid_desc_t *ia_css_spatial_param_terminal_get_fragment_grid_desc(
	const ia_css_spatial_param_terminal_t *spatial_param_terminal,
	const unsigned int fragment_index
);

extern ia_css_frame_grid_param_section_desc_t *ia_css_spatial_param_terminal_get_frame_grid_param_section_desc(
	const ia_css_spatial_param_terminal_t *spatial_param_terminal,
	const unsigned int section_index
);

extern int ia_css_spatial_param_terminal_create(
	ia_css_spatial_param_terminal_t *spatial_param_terminal,
	const uint16_t terminal_offset,
	const uint16_t terminal_size,
	const uint16_t is_input_terminal,
	const unsigned int nof_fragments,
	const uint32_t kernel_id
);

extern unsigned int ia_css_sliced_param_terminal_get_descriptor_size(
	const unsigned int nof_slice_param_sections,
	const unsigned int nof_slices[],
	const unsigned int nof_fragments
);

extern ia_css_fragment_slice_desc_t *ia_css_sliced_param_terminal_get_fragment_slice_desc(
	const ia_css_sliced_param_terminal_t *sliced_param_terminal,
	const unsigned int fragment_index
);

extern ia_css_slice_param_section_desc_t *ia_css_sliced_param_terminal_get_slice_param_section_desc(
	const ia_css_sliced_param_terminal_t *sliced_param_terminal,
	const unsigned int fragment_index,
	const unsigned int slice_index,
	const unsigned int section_index,
	const unsigned int nof_slice_param_sections
);

extern int ia_css_sliced_param_terminal_create(
	ia_css_sliced_param_terminal_t *sliced_param_terminal,
	const uint16_t terminal_offset,
	const uint16_t terminal_size,
	const uint16_t is_input_terminal,
	const unsigned int nof_slice_param_sections,
	const unsigned int nof_slices[],
	const unsigned int nof_fragments,
	const uint32_t kernel_id
);

extern unsigned int ia_css_program_terminal_get_descriptor_size(
	const unsigned int nof_fragments,
	const unsigned int nof_fragment_param_sections,
	const unsigned int nof_kernel_fragment_sequencer_infos,
	const unsigned int nof_command_objs
);

extern ia_css_fragment_param_section_desc_t *ia_css_program_terminal_get_fragment_param_section_desc(
	const ia_css_program_terminal_t *program_terminal,
	const unsigned int fragment_index,
	const unsigned int section_index,
	const unsigned int nof_fragment_param_sections
);

extern ia_css_kernel_fragment_sequencer_info_desc_t *ia_css_program_terminal_get_kernel_fragment_sequencer_info_desc(
	const ia_css_program_terminal_t *program_terminal,
	const unsigned int fragment_index,
	const unsigned int info_index,
	const unsigned int nof_kernel_fragment_sequencer_infos
);

extern int ia_css_program_terminal_create(
	ia_css_program_terminal_t *program_terminal,
	const uint16_t terminal_offset,
	const uint16_t terminal_size,
	const unsigned int nof_fragments,
	const unsigned int nof_kernel_fragment_sequencer_infos,
	const unsigned int nof_command_objs
);

extern int ia_css_program_terminal_get_command_base_offset(
	const ia_css_program_terminal_t *program_terminal,
	const unsigned int nof_fragments,
	const unsigned int nof_kernel_fragment_sequencer_infos,
	const unsigned int commands_slots_used,
	uint16_t *command_desc_offset
);

extern uint16_t *ia_css_program_terminal_get_line_count(
	const ia_css_kernel_fragment_sequencer_command_desc_t *kernel_fragment_sequencer_command_desc_base,
	const unsigned int set_count
);

#endif /* __IA_CSS_TERMINAL_H__ */
