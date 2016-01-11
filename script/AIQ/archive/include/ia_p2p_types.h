/*
 * Copyright 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*!
 * \file ia_p2p_types.h
 * \brief Declares public2private interface data types.
 */

#ifndef IA_P2P_TYPES_H_
#define IA_P2P_TYPES_H_

#include <stdint.h>

#include "ia_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  P2P instance handle type.
 */
typedef struct ia_p2p_t* ia_p2p_handle;

/*!
 *  Fragment descriptor.
 */
typedef struct
{
    uint16_t fragment_width;    /*!< The width of the fragment. */
    uint16_t fragment_height;   /*!< The height of the fragment. */
    uint16_t fragment_start_x;  /*!< The x offset from the top-left corner of the full image. */
    uint16_t fragment_start_y;  /*!< The y offset from the top-left corner of the full image. */
} ia_p2p_fragment_desc;

/*!
 *  Structure for terminal requirements, specifying the number of sections required for each terminal type.
 */
typedef struct
{
    unsigned int param_in_section_count;                /*!< The number of parameter input sections required. */
    unsigned int param_out_section_count_per_fragment;  /*!< The number of parameter output sections required per fragment. */
    unsigned int program_section_count_per_fragment;    /*!< The number of program sections required per fragment. */
    unsigned int spatial_param_in_section_count;        /*!< The number of spatial param input sections required. */
    unsigned int spatial_param_out_section_count;       /*!< The number of spatial param output sections required. */
} ia_p2p_terminal_requirements_t;

/*!
 *  Payload descriptor specifying the total size of payload required for each terminal type.
 */
typedef struct
{
    uint32_t param_in_payload_size;             /*!< The total size of the parameter input payload in bytes. */
    uint32_t param_out_payload_size;            /*!< The total size of the parameter output payload in bytes. */
    uint32_t program_payload_size;              /*!< The total size of the program payload in bytes. */
    uint32_t spatial_param_in_payload_size;     /*!< The total size of the spatial param input payload in bytes. */
    uint32_t spatial_param_out_payload_size;    /*!< The total size of the spatial param output payoad in bytes. */
} ia_p2p_payload_desc;

/* Currently supported program groups. TODO: Add dependency to ia_css_bxt_pss_program_groups.h. */
#define IA_P2P_PG_ISYS      0       /* No manifest available so we define a custom PG specification id for ISYS. */
#define IA_P2P_PG_ISL       120
#define IA_P2P_PG_VPREGDC   116     /* IA_CSS_BXT_PSS_PG_SPECIFICATION_VPREGDC */
#define IA_P2P_PG_SPREGDC   117
#define IA_P2P_PG_VPOSTGDC  114     /* IA_CSS_BXT_PSS_PG_SPECIFICATION_VPOSTGDC */
#define IA_P2P_PG_SPOSTGDC  118
#define IA_P2P_PG_POWERON   201     /* Power-on program group. */
#define IA_P2P_PG_TEST      1       /* For internal P2P testing. */

#ifdef __cplusplus
}
#endif

#endif /* IA_P2P_TYPES_H_ */
