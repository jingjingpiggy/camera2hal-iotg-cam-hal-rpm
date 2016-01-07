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

#ifndef __IA_CSS_TERMINAL_DEFS_H__
#define __IA_CSS_TERMINAL_DEFS_H__


#include "type_support.h"

#define IA_CSS_TERMINAL_ID_BITS					8
typedef uint8_t						ia_css_terminal_ID_t;

/*
 * Terminal Base Type
 */
typedef enum ia_css_terminal_type {
	IA_CSS_TERMINAL_TYPE_DATA_IN = 0,		/**< Data input */
	IA_CSS_TERMINAL_TYPE_DATA_OUT,			/**< Data output */
	IA_CSS_TERMINAL_TYPE_PARAM_STREAM,		/**< Type 6 parameter input */
	IA_CSS_TERMINAL_TYPE_PARAM_CACHED_IN,		/**< Type 1-5 parameter input */
	IA_CSS_TERMINAL_TYPE_PARAM_CACHED_OUT,		/**< Type 1-5 parameter output */
	IA_CSS_TERMINAL_TYPE_PARAM_SPATIAL_IN,		/**< Represent the new type of terminal for the "spatial dependent parameters", when params go in */
	IA_CSS_TERMINAL_TYPE_PARAM_SPATIAL_OUT,		/**< Represent the new type of terminal for the "spatial dependent parameters", when params go out */
	IA_CSS_TERMINAL_TYPE_PARAM_SLICED_IN,		/**< Represent the new type of terminal for the explicit slicing, when params go in */
	IA_CSS_TERMINAL_TYPE_PARAM_SLICED_OUT,		/**< Represent the new type of terminal for the explicit slicing, when params go out */
	IA_CSS_TERMINAL_TYPE_STATE_IN,			/**< State (private data) input */
	IA_CSS_TERMINAL_TYPE_STATE_OUT,			/**< State (private data) output */
	IA_CSS_TERMINAL_TYPE_PROGRAM,
	IA_CSS_N_TERMINAL_TYPES
} ia_css_terminal_type_t;

#define IA_CSS_TERMINAL_TYPE_BITS				32

/* Temporary redirection needed to facilicate merging with the drivers
   in a backwards compatible manner */
#define IA_CSS_TERMINAL_TYPE_PARAM_CACHED IA_CSS_TERMINAL_TYPE_PARAM_CACHED_IN

/*
 * Dimensions of the data objects. Note that a C-style
 * data order is assumed. Data stored by row.
 */
/* A strange problem with hivecc compiler which is described
 * here https://icggerrit.ir.intel.com/#/c/51630/1 forces this
 * enum to be explicitly initialized for the moment
 */
typedef enum ia_css_dimension {
	IA_CSS_COL_DIMENSION = 0,			/**< The number of columns, i.e. the size of the row */
	IA_CSS_ROW_DIMENSION = 1,			/**< The number of rows, i.e. the size of the column */
	IA_CSS_N_DATA_DIMENSION = 2
} ia_css_dimension_t;

#define IA_CSS_N_COMMAND_COUNT (4)

#endif /*__IA_CSS_TERMINAL_DEFS_H__*/
