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

#ifndef _IA_CIPF_TYPES_H_
#define _IA_CIPF_TYPES_H_

#include <ia_tools/ia_list.h>
#include <ia_tools/ia_types.h>

/** \file ia_cipf_types.h
 *
 * Definitions for datatypes used with public CIPF interfaces
 *
 * \ingroup ia_cipf
 *
 * Includes opaque CIPF objects and types for data management
 */

/**
 * \ingroup ia_cipf
 */
typedef struct _cipf_terminal ia_cipf_terminal_t;

/**
 * \ingroup ia_cipf
 */
typedef struct _cipf_container ia_cipf_container_t;

/**
 * \ingroup ia_cipf
 */
typedef struct _cipf_connection ia_cipf_connection_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_registry ia_cipf_registry_t;

/**
 * \ingroup ia_cipf
 */
typedef struct _cipf_property ia_cipf_property_t;

/**
 * \ingroup ia_cipf
 */
typedef struct _cipf_stage ia_cipf_stage_t;

/**
 * \ingroup ia_cipf
 */
typedef ia_err_t (*ia_cipf_stage_completion_op_t)(ia_cipf_stage_t*, void *priv);

/** ia_cipf_iterator_t - context of single pipeline iteration
 *
 * \ingroup ia_cipf
 *
 * Iterator object holds accessors (<stage, container>-pairs called parcels)
 * for pipeline components associated with single execution step. Amount of
 * stages and terminals within single execution step may vary based on
 * DAG definition.
 */
typedef struct ia_cipf_iterator ia_cipf_iterator_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_pipe ia_cipf_pipe_t;

/**
 * \ingroup ia_cipf
 */
typedef uint32_t ia_uid;

/**
 * \ingroup ia_cipf
 */
#define ia_fourcc(a, b, c, d) ((uint32_t)(d) | ((uint32_t)(c) << 8) \
                              | ((uint32_t)(b) << 16) | ((uint32_t)(a) << 24))

typedef struct log_context log_context_t;

/* Native UID definitions for fourcc pixel formats */
#define ia_cipf_frame_fourcc_i420 ia_fourcc('I','4','2','0')
#define ia_cipf_frame_fourcc_iyuv ia_fourcc('I','Y','U','V')
#define ia_cipf_frame_fourcc_nv12 ia_fourcc('N','V','1','2')
#define ia_cipf_frame_fourcc_nv21 ia_fourcc('N','V','2','1')
#define ia_cipf_frame_fourcc_yuy2 ia_fourcc('Y','U','Y','2')
#define ia_cipf_frame_fourcc_ba10 ia_fourcc('B','A','1','0')
#define ia_cipf_frame_fourcc_gr08 ia_fourcc('G','R','0','8')
#define ia_cipf_frame_fourcc_gr10 ia_fourcc('G','R','1','0')
#define ia_cipf_frame_fourcc_grbg ia_fourcc('G','R','B','G')
#define ia_cipf_frame_fourcc_rggb ia_fourcc('R','G','G','B')
#define ia_cipf_frame_fourcc_bggr ia_fourcc('B','G','G','R')
#define ia_cipf_frame_fourcc_gbrg ia_fourcc('G','B','R','G')
#define ia_cipf_frame_fourcc_tile ia_fourcc('T','I','L','E')

/* Native object type reference UIDs */
#define ia_cipf_pipeline_location_ref_uid   ia_fourcc('P','O','L','R')
#define ia_cipf_platform_buffer_ref_uid     ia_fourcc('P','O','B','R')
#define ia_cipf_platform_memory_ref_uid     ia_fourcc('P','O','M','R')
#define ia_cipf_platform_memory_device_ref_uid ia_fourcc('P','O','M','D')

/* Native type payload UIDs */
#define ia_cipf_payload_uid_int32           ia_fourcc('D','A','$','0')
#define ia_cipf_payload_uid_uint32          ia_fourcc('D','A','$','1')
#define ia_cipf_payload_uid_resolution      ia_fourcc('D','A','$','2')
#define ia_cipf_payload_uid_boolean         ia_fourcc('D','A','$','3')
#define ia_cipf_payload_uid_uint64          ia_fourcc('D','A','$','4')
#define ia_cipf_payload_uid_void_ref        ia_fourcc('D','R','$','0')
#define ia_cipf_payload_uid_int32_ref       ia_fourcc('D','R','$','1')
#define ia_cipf_payload_uid_uint32_ref      ia_fourcc('D','R','$','2')
#define ia_cipf_payload_uid_resolution_ref  ia_fourcc('D','R','$','3')
#define ia_cipf_payload_uid_string_ref      ia_fourcc('D','R','$','4')
#define ia_cipf_payload_uid_uint64_ref      ia_fourcc('D','R','$','5')
#define ia_cipf_payload_uid_offset_ref      ia_fourcc('D','O','$','0')

/* Native payload for special unidentified property */
#define ia_cipf_payload_uid_unidentified    ia_fourcc('U','I','P','R')

/* Native property UIDs */
#define ia_cipf_frame_format_uid ia_fourcc('P','X','F','M')
#define ia_cipf_frame_uid ia_fourcc('F','R','A','M')
#define ia_cipf_property_data_uid ia_fourcc('D','A','T','A')
#define ia_cipf_tunneled_terminal_data_uid  ia_fourcc('A','U','T','O')

/** Identifiable data payload type
 *
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_payload {
    ia_uid     uid;  /* data type identifier */
    uint32_t   size; /* size in bytes allocated to data.cpu_ptr */
    union {
        void        *cpu_ptr;
        uint32_t    offset;
        uint32_t    handle;
        uint8_t     raw[8];
        uint32_t    uvalue;
        uint64_t    u64value;
        int32_t     svalue;
    } data;
} ia_cipf_payload_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_frame_format {
    uint32_t        width;    /**< Width of the frame in pixels */
    uint32_t        height;   /**< Height of the frame in lines */
    uint32_t        fourcc;   /**< Frame format */
    uint32_t        bpl;      /**< Bytes per line*/
    uint32_t        bpp;      /**< Bits per pixel */
} ia_cipf_frame_format_t;

#define IA_CIPF_MAX_PLANES 6

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_timestamp {
    uint64_t seconds; /**< Number of whole seconds */
    uint64_t useconds; /**< Rest of the time in microseconds */
} ia_cipf_timestamp_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_frame {
    ia_uid              uid;
    uint32_t            id;
    uint32_t            sequence;
    ia_cipf_timestamp_t timestamp;
    uint32_t            flags;
    uint32_t            allocated;
    uint32_t            planes;
    ia_cipf_payload_t   payload[IA_CIPF_MAX_PLANES];
} ia_cipf_frame_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_buffer {
    ia_cipf_payload_t    payload;
} ia_cipf_buffer_t;

/**
 * \ingroup ia_cipf
 */
typedef enum ia_cipf_terminal_type {
    ia_cipf_terminal_type_frame_input,
    ia_cipf_terminal_type_frame_output,
    ia_cipf_terminal_type_param_input,
    ia_cipf_terminal_type_param_output
} ia_cipf_terminal_type_t;

/**
 * \ingroup ia_cipf
 */
typedef enum ia_cipf_connection_type {
    connection_type_push, /* data is pushed by source stage execute */
    connection_type_pull  /* data is pulled by sink stage execute */
} ia_cipf_connection_type_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_point {
    uint16_t x;
    uint16_t y;
} ia_cipf_point_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_rect {
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
} ia_cipf_rect_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_resolution {
    uint16_t width;
    uint16_t height;
} ia_cipf_resolution_t;

/**
 * \ingroup ia_cipf
 */
typedef struct ia_cipf_association {
    ia_uid stage;
    ia_uid terminal;
    ia_uid property;
} ia_cipf_association_t;

#endif /* _IA_CIPF_TYPES_H_ */
