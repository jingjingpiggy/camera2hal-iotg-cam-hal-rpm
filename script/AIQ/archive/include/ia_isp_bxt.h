/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2014 Intel Corporation
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its
 * suppliers or licensors. Title to the Material remains with Intel
 * Corporation or its suppliers and licensors. The Material may contain trade
 * secrets and proprietary and confidential information of Intel Corporation
 * and its suppliers and licensors, and is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may be
 * used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 *
 * Unless otherwise agreed by Intel in writing, you may not remove or alter
 * this notice or any other notice embedded in Materials by Intel or Intels
 * suppliers or licensors in any way.
 */

/*!
 * \file ia_isp_bxt.h
 * \brief ia_isp_bxt specific implementation.
*/

#ifndef IA_ISP_BXT_H_
#define IA_ISP_BXT_H_

#include "ia_aiq_types.h"
#include "ia_types.h"
#include "ia_isp_bxt_types.h"
#include "ia_isp_types.h"
#include "ia_dvs_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ia_isp_bxt_t ia_isp_bxt;

/*!
 * \brief Initialize IA_ISP and its submodules.
 * This function must be called before any other function in the library. It allocates memories and parses ISP specific parts from CPFF.
 * Initialization returns a handle to the ISP instance, which is given as input parameter for all the
 * ISP functions.
 *
 * \param[in]     aiqb_data          Mandatory although function will not return error, if it not given.\n
 *                                   Reads generic AIC records Block from CPFF.
 * \param[in]     ia_cmc             Mandatory.\n
 *                                   Parsed camera module characterization structure. Essential parts of the structure will be copied
 *                                   into internal structure.
 * \param[in]     max_stats_width    Mandatory.\n Maximum width of RGBS and AF statistics grids from ISP. Used to calculate size of
 *                                   memory buffers for the IA_AIQ algorithms. The same maximum width will be used for all RGBS
 *                                   and AF statistics grid allocations.
 * \param[in]     max_stats_height   Mandatory. Maximum height of RGBS and AF statistics grids from ISP. Used to calculate size of
 *                                   memory buffers for the IA_AIQ algorithms. The same maximum height will be used for all RGBS
 *                                   and AF statistics grid allocations.l
 *                                   Initialization parameters for statistics conversion.
 */

LIBEXPORT ia_isp_bxt*
ia_isp_bxt_init(const ia_binary_data *aiqb_data,
        ia_cmc_t *ia_cmc,
        unsigned int max_stats_width,
        unsigned int max_stats_height);

LIBEXPORT void
ia_isp_bxt_deinit(
        ia_isp_bxt *ia_isp_bxt);

/*!
 *  \brief IA_ISP_BXT parameter input structure.
 */
typedef struct
{
    ia_aiq_frame_params *sensor_frame_params;        /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_awb_results *awb_results;                 /*!< Mandatory. WB results which are to be used to calculate next ISP parameters (WB gains, color matrix,etc). */
    ia_aiq_gbce_results *gbce_results;               /*!< Mandatory. GBCE Gamma tables which are to be used to calculate next ISP parameters.*/
    ia_aiq_exposure_parameters *exposure_results;    /*!< Mandatory. Exposure parameters which are to be used to calculate next ISP parameters. */
    ia_aiq_pa_results *pa_results;                   /*!< Mandatory. Parameter adaptor results from AIQ. */
    ia_aiq_sa_results *sa_results;                   /*!< Mandatory. Shading adaptor results from AIQ. */
    ia_aiq_hist_weight_grid *weight_grid;            /*!< Mandatory. Weight map to be used in the next frame histogram calculation. */
    ia_isp_bxt_program_group *program_group;         /*!< Optional. List of kernels associated with this program group */
    unsigned int stream_id;                          /*!< Optional. If program_group is not given, stream_id is used to fetch all the tunings for all the kernels
                                                                    associated with the stream_id. */
    ia_isp_feature_setting nr_setting;               /*!< Mandatory. Feature setting for noise reduction algorithms. */
    ia_isp_feature_setting ee_setting;               /*!< Mandatory. Feature setting for edge enhancement algorithms. */
    char manual_brightness;                          /*!< Optional. Manual brightness value range [-128,127]. */
    char manual_contrast;                            /*!< Optional. Manual contrast value range [-128,127]. */
    char manual_hue;                                 /*!< Optional. Manual hue value range [-128,127]. */
    char manual_saturation;                          /*!< Optional. Manual saturation value range [-128,127]. */
    ia_isp_effect effects;                           /*!< Optional. Manual setting for special effects. Combination of ia_isp_effect enums.*/
} ia_isp_bxt_input_params;

/*!
 * \brief ISP configuration for the next frame
 * Computes ISP parameters from input parameters and CPF values for the next image.
 *
 * \param[in] ia_isp_bxt                    Mandatory.\n
 *                                          ISP instance handle.
 * \param[in] ia_isp_bxt_input_params       Mandatory.\n
 *                                          Input parameters for ISP calculations.
 * \return                                  Binary data structure with pointer to the ISP configuration structure.
 *
 */
LIBEXPORT ia_err
ia_isp_bxt_run(
        ia_isp_bxt *ia_isp_bxt,
        const ia_isp_bxt_input_params *input_params,
        ia_binary_data *output_data);

/*!
 * \brief Get version.
 * Get version from version header.
 *
 * \return                         Version string.
 */
LIBEXPORT const char*
ia_isp_bxt_get_version(void);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in] ia_isp_bxt        Mandatory.\n
 *                              ia_isp_bxt instance handle.
 * \param[in]  statistics_ptr   Mandatory.\n
 *                              AWB statistics in ISP specific format.
 * \param[out] rgbs_grid        Mandatory.\n
 *                              Pointer's pointer where address of converted statistics are stored.
 *                              Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                              if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
 * \return                      Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_from_binary(
    ia_isp_bxt *ia_isp_bxt_ptr,
    const ia_binary_data *statistics_ptr,
    ia_aiq_rgbs_grid **out_rgbs_grid);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in]  statistics    Mandatory.\n
 *                           Statistics in ISP specific format.
 * \param[in] ia_isp_bxt     Mandatory.\n
 *                           ia_isp_bxt instance handle.
 * \param[in]  stats_width   Mandatory actual width of the statistics grid.
 * \param[in]  stats_height  Mandatory actual height of the statistics grid.
 * \param[in]  c0_avg        Mandatory Average level of c0 color
 * \param[in]  c1_avg        Mandatory Average level of c0 color
 * \param[in]  c2_avg        Mandatory Average level of c0 color
 * \param[in]  c3_avg        Mandatory Average level of c0 color
 * \param[in]  c4_avg        Mandatory Average level of c0 color
 * \param[in]  c5_avg        Mandatory Average level of c0 color
 * \param[in]  c6_avg        Mandatory Average level of c0 color
 * \param[in]  c7_avg        Mandatory Average level of c0 color
 * \param[in]  sat_ratio_0   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 * \param[in]  sat_ratio_1   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 * \param[in]  sat_ratio_2   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 * \param[in]  sat_ratio_3   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 *
 * \param[out] rgbs_grid Mandatory.\n
 *                           Pointer's pointer where address of converted statistics are stored.
 *                           Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                           if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
 * \return                   Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb(
                    ia_isp_bxt *ia_isp_bxt_ptr,
                    unsigned int stats_width,
                    unsigned int stats_height,
                    void *c0_avg,
                    void *c1_avg,
                    void *c2_avg,
                    void *c3_avg,
                    void *c4_avg,
                    void *c5_avg,
                    void *c6_avg,
                    void *c7_avg,
                    void *sat_ratio_0,
                    void *sat_ratio_1,
                    void *sat_ratio_2,
                    void *sat_ratio_3,
                    ia_aiq_rgbs_grid **out_rgbs_grid);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in]  ia_isp_bxt    Mandatory.\n
 *                           ia_isp_bxt instance handle.
 * \param[in]  statistics_ptr   Mandatory.\n
 *                              AF statistics in ISP specific format.
 *
 * \param[out] af_grid Mandatory.\n
 *                           this pointer is returned from the initialize function
 *                           Pointer's pointer where address of converted statistics are stored.
 *                           Converted af grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                           if the external buffer is provided in out_af_grid it will be used otherwise internal buffer is used.
 * \return                   Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_af_from_binary(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics_ptr,
    ia_aiq_af_grid **out_af_grid);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in]  ia_isp_bxt    Mandatory.\n
 *                           ia_isp_bxt instance handle.
 * \param[in]  stats_width   Mandatory actual width of the statistics grid.
 * \param[in]  stats_height  Mandatory actual height of the statistics grid.
 * \param[in]  y00_avg       Mandatory Block value of Y00 filter response
 * \param[in]  y01_avg       Mandatory Block value of Y01 filter response
 *
 * \param[out] af_grid       Mandatory.\n
 *                           Pointer's pointer where address of converted statistics are stored.
 *                           Converted af grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                           if the external buffer is provided in out_af_grid it will be used otherwise internal buffer is used.
 * \return                   Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_af(
    ia_isp_bxt *ia_isp_bxt,
    unsigned int stats_width,
    unsigned int stats_height,
    void *y00_avg,
    void *y01_avg,
    ia_aiq_af_grid **out_af_grid);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in]  ia_isp_bxt       Mandatory.\n
 *                              ia_isp_bxt instance handle.
 * \param[in]  statistics_ptr   Mandatory.\n
 *                              Ae statistics in ISP specific format.
 * \param[out] aiq_histogram    Mandatory.\n
 *                              Pointer's pointer where address of converted statistics are stored.
 *                              Converted aiq histogram statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                              if the external buffer is provided in out_aiq_histogram it will be used otherwise internal buffer is used.
 * \return                      Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_ae_from_binary(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics_ptr,
    ia_aiq_histogram **out_aiq_histogram);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in]  ia_isp_bxt    Mandatory.\n
 *                           ia_isp_bxt instance handle.
 * \param[in]  c0_histogram  Mandatory Block value of c0_histogram
 * \param[in]  c1_histogram  Mandatory Block value of c1_histogram
 * \param[in]  c2_histogram  Mandatory Block value of c2_histogram
 * \param[in]  c3_histogram  Mandatory Block value of c3_histogram
 * \param[out] aiq_histogram Mandatory.\n
 *                           Pointer's pointer where address of converted statistics are stored.
 *                           Converted aiq histogram statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                           if the external buffer is provided in out_aiq_histogram it will be used otherwise internal buffer is used.
 * \return                   Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_ae(
    ia_isp_bxt *ia_isp_bxt,
    void *c0_histogram,
    void *c1_histogram,
    void *c2_histogram,
    void *c3_histogram,
    unsigned int num_bins,
    ia_aiq_histogram **out_aiq_histogram);

/*!
 * \brief This function converts corner based statistics to generic DVS statistics.
 *
 * ISP generated statistics may not be in the format in which DVS algorithms expect. Statistics need to be converted
 * from various ISP formats into DVS statistics format.
 *
 * \param[in]  ia_isp_bxt                  Mandatory.\n
 *                                         ia_isp_bxt instance handle.
 * \param[in]  bxt_dvs_statistics          Mandatory.\n
 *                                         Binary data which contains pointer to BXT specific DVS statistics structure.
 * \param[in]  dvs_statistics_input_width  Mandatory.\n
 *                                         DVS statistics input width. Used only in DVS statistics conversion.
 * \param[in]  dvs_statistics_input_height Mandatory.\n
 *                                         DVS statistics input height. Used only in DVS statistics conversion.
 * \param[out] dvs_statistics              Mandatory.\n
 *                                         Converted DVS statistics. Output can be directly used as input in function ia_dvs_set_statistics.
 *                                         If the external buffer is provided in dvs_statistics it will be used otherwise internal buffer is used.
 * \return                                 Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_dvs(
        ia_isp_bxt *ia_isp_bxt,
        const ia_binary_data *bxt_dvs_statistics,
        unsigned int dvs_statistics_input_width,
        unsigned int dvs_statistics_input_height,
        ia_dvs_statistics **dvs_statistics);


#ifdef __cplusplus
}
#endif
#endif /* IA_ISP_BXT_H_ */
