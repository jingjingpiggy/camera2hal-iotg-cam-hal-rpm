/*
 * Copyright 2014 Intel Corporation
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
 * \file ia_isp_bxt_types.h
*/

#ifndef IA_ISP_BXT_TYPES_H_
#define IA_ISP_BXT_TYPES_H_

#include "ia_types.h"
#include <stdint.h>  /* defines fixed width integers */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Input structure for resolution changing ISP block.
 *
 * If ISP block changes resolution as part of its processing, this structure defines
 * resolutions and cropping parameters for one input and output pins. If ISP block has
 * multiple outputs, structure needs to be passed for each output pin. Order of operations:
 *
 * -# Input image is cropped according to input_crop structure parameters. New cropped input resolution is calculated.
 * -# Cropped input image is scaled from cropped input resolution to output resolution (output_width & output_height).
 * -# Output image is cropped according to output_crop structure parameters.
 *
 * If ISP block doesn't change resolution of the image as part of its processing, this structure defines
 * resolution changes done to the image from the beginning of the pipe until now. For example if some scaling or
 * cropping was done before, they are combined.
 *
 * Example:
 *
 * -# Sensor outputs 6528 x 4896. Sensor crops 3264 x 2448 ROI from bottom right corner.
 * -# ISP block downscales the image from 3264 x 2448 to 2176 x 1632 (scale 0.6667) and crops to 1920 x 1080 (RCB):
 *    - resolution_info { 6528, 4896, { 3264, 2448, 0, 0 }, 2176, 1632, { 128, 276, 128, 276 } }
 *
 * -# ISP block needs to know what resolution changes were done with respect to full sensor frame:
 *    - resolution_history { 6528, 4896, { 3264+(128/0.6667), 2448+(276/0.6667), (128/0.6667), (276/0.6667) }, 1920, 1080, { 0, 0, 0, 0 } }
 *
 * -# ISP block forther downscales the image to 1280 x 720 (RCB):
 *    - resolution_info { 1920, 1080, { 0, 0, 0, 0 }, 1280, 720, { 0, 0, 0, 0 } }
 *
 * -# ISP block needs to know what resolution changes were done:
 *    - resolution_history { 6528, 4896, { 3264+(128/0.6667), 2448+(276/0.6667), (128/0.6667), (276/0.6667) }, 1280, 720, { 0, 0, 0, 0 } }
 *
 */
typedef struct
{
    int input_width;          /*!< Input image width. */
    int input_height;         /*!< Input image height. */
    ia_rectangle input_crop;  /*!< Crop offsets for input image. Cropping happens before processing the input image. */
    int output_width;         /*!< Output image width. */
    int output_height;        /*!< Output image height. */
    ia_rectangle output_crop; /*!< Crop offsets for output image. Cropping happens after scaling to output resolution. */
} ia_isp_bxt_resolution_info_t;


typedef struct
{
    uint32_t stream_id;                                     /*!< Used to identify, in which branch of the pipe the kernel is located. */
    uint32_t kernel_uuid;                                   /*!< ia_pal_uuid. ISP API (output) UUID. */
    uint32_t enable;                                        /*!< Run-time control to bypass kernel. */
    const ia_isp_bxt_resolution_info_t *resolution_info;    /*!< Resolution change to be done in this kernel. NULL, if kernel doesn't change resolution. */
    const ia_isp_bxt_resolution_info_t *resolution_history; /*!< Resolution changes done before current kernel with respect to sensor output. NULL, if not available*/
    uint32_t metadata[4];                                   /*!< Kernel specific metadata. For example image data format etc. */
} ia_isp_bxt_run_kernels_t;

typedef struct
{
    unsigned int kernel_count;                    /*!< Number of kernels in the program group .*/
    ia_isp_bxt_run_kernels_t *run_kernels;        /*!< Array of kernels in the program group. */
} ia_isp_bxt_program_group;

typedef struct
{
    bool rgbs_grid;     /*!< If true, RGBS grid is available. */
    bool af_grid;       /*!< If true, AF grid is available. */
    bool histograms;    /*!< If true, histograms are available. */
    bool dvs_stats;     /*!< If true, DVS statistics are available. */
} ia_isp_bxt_statistics_query_results_t;

#ifdef __cplusplus
}
#endif
#endif /* IA_ISP_BXT_TYPES_H_ */
