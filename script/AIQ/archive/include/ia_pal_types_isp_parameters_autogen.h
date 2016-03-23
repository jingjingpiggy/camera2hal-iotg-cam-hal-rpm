

/*
* INTEL CONFIDENTIAL
* Copyright (c) 2016 Intel Corporation
* All Rights Reserved.
*
* The source code contained or described herein and all documents related to
* the source code (Material) are owned by Intel Corporation or its
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
* this notice or any other notice embedded in Materials by Intel or Intel's
* suppliers or licensors in any way.
*/
#pragma once
#include <stdint.h>
#include <memory.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef enum
{
ia_pal_uuid_isp_debug_info = 12967,
ia_pal_uuid_isp_bxt_pixelformatter = 13503,
ia_pal_uuid_isp_bxt_norm_lin = 64791,
ia_pal_uuid_isp_bxt_blc = 40661,
ia_pal_uuid_isp_bxt_gridbaseob = 46517,
ia_pal_uuid_isp_bxt_linearization = 33288,
ia_pal_uuid_isp_bxt_lsc = 53711,
ia_pal_uuid_isp_bxt_dpc = 52031,
ia_pal_uuid_isp_bxt_disparity = 55093,
ia_pal_uuid_isp_bxt_applycorrection = 45482,
ia_pal_uuid_isp_bxt_3a_ccm = 15593,
ia_pal_uuid_isp_bxt_pixprecadapter_precropstills = 29575,
ia_pal_uuid_isp_bxt_cropstills = 34611,
ia_pal_uuid_isp_bxt_cropvideo = 42997,
ia_pal_uuid_isp_bxt_wb = 32398,
ia_pal_uuid_isp_bxt_aestatistics = 21985,
ia_pal_uuid_isp_bxt_af_awb_fr_statistics = 21650,
ia_pal_uuid_isp_bxt_awbstatistics = 10104,
ia_pal_uuid_isp_bxt_inputscaler = 29163,
ia_pal_uuid_isp_bxt_vcsc = 60680,
ia_pal_uuid_isp_bxt_pixprecadapter_precropvideo = 13533,
ia_pal_uuid_isp_bxt_xnr4_m = 19837,
ia_pal_uuid_isp_bxt_rynr_splitter = 61356,
ia_pal_uuid_isp_bxt_pixprecadapter_prevcud = 23002,
ia_pal_uuid_isp_bxt_bnlm = 54605,
ia_pal_uuid_isp_bxt_vcud = 17897,
ia_pal_uuid_isp_bxt_rynr_collector = 28476,
ia_pal_uuid_isp_bxt_demosaic = 18227,
ia_pal_uuid_isp_bxt_pixprecadapter_precsc2 = 60774,
ia_pal_uuid_isp_bxt_csc2 = 39659,
ia_pal_uuid_isp_bxt_vcr = 21834,
ia_pal_uuid_isp_bxt_ccm = 16559,
ia_pal_uuid_isp_bxt_acm = 13506,
ia_pal_uuid_isp_bxt_gammatm = 44304,
ia_pal_uuid_isp_bxt_csc = 31704,
ia_pal_uuid_isp_sc_iefd = 2442,
ia_pal_uuid_isp_bxt_dvsstatistics = 10794,
ia_pal_uuid_isp_bxt_pixprecadapter_pregdc = 12215,
ia_pal_uuid_isp_gdc3 = 39767,
ia_pal_uuid_isp_bxt_ofa_mp = 27648,
ia_pal_uuid_isp_sc_outputscaler_dp = 5852,
ia_pal_uuid_isp_sc_outputscaler_ppp = 60118,
ia_pal_uuid_isp_bxt_ofa_dp = 5037,
ia_pal_uuid_isp_bxt_ofa_ppp = 63080,
ia_pal_uuid_isp_sc_chromaupsample = 1777,
ia_pal_uuid_isp_sc_rgbconversion = 23037,
ia_pal_uuid_isp_bxt_mirror = 52528,
ia_pal_uuid_isp_bxt_reducerange = 35761,
ia_pal_uuid_isp_sc_packer = 57497,
ia_pal_uuid_isp_bxt_dpcm = 19294,
ia_pal_uuid_isp_bxt_pafstatistics = 51522,
ia_pal_uuid_isp_bxt_vcr2 = 5194,
ia_pal_uuid_isp_bxt_inputscalerv2 = 10913,
ia_pal_uuid_isp_bxt_convert16sto8u = 48932,
ia_pal_uuid_isp_bxt_pixprecadapter = 15868,
ia_pal_uuid_isp_bxt_flip = 58270,
ia_pal_uuid_isp_bxt_shift14to16bit = 49150,
ia_pal_uuid_isp_sc_ylpf = 50844,
ia_pal_uuid_isp_sc_iefd_v2 = 33433,
ia_pal_uuid_isp_bxt_gdc_reference = 40503,
ia_pal_uuid_isp_bxt_xnr4_mh = 47865,
ia_pal_uuid_isp_bxt_pixprecadapter_prewb = 20178,
ia_pal_uuid_isp_bxt_pixprecadapter_postvcr = 64780,
ia_pal_uuid_isp_bxt_inputscaler_a0 = 41839,
ia_pal_uuid_isp_bxt_demosaic_a0 = 46791,
ia_pal_uuid_isp_bxt_bitcomp_a0 = 41588,
ia_pal_uuid_isp_bxt_bitdecomp_a0 = 7104,
ia_pal_uuid_isp_bxt_tnr5v1 = 43225,
ia_pal_uuid_isp_dma_cropper_mp = 27230,
ia_pal_uuid_isp_dma_cropper_dp = 47638,
ia_pal_uuid_isp_dma_cropper_ppp = 49162,
ia_pal_uuid_isp_drc_1 = 63426,
ia_pal_uuid_isp_exy = 35008,
ia_pal_uuid_isp_hdrstats_1 = 23432,
ia_pal_uuid_isp_see = 20631,
ia_pal_uuid_isp_tnr5_21 = 41505,
ia_pal_uuid_isp_xnr_dss = 42418,

} ia_pal_uuid;

/*! \struct debug_info
    
*/
typedef struct 
{
     /*!< output_data_id Output data ID. Debugging data to match P2P call sequence with correct PAL output data. AIC increments this value by 1 on every call to ia_isp_bxt_run(). */
    int32_t output_data_id;

} ia_pal_isp_debug_info_t; 

/*! \struct bxt_pixelformatter
    
*/
typedef struct 
{
     /*!< m_bypass Bypass     {0,1} */
    int32_t m_bypass;
     /*!< m_xstart Horizontal Starting Pixel. FIXME: Put correct max and default values */
    int32_t m_xstart;
     /*!< m_ystart Vertical   Starting Pixel. FIXME: Put correct max and default values */
    int32_t m_ystart;
     /*!< m_xsize Horizontal Frame Size. FIXME: Put correct max and default values */
    int32_t m_xsize;
     /*!< m_ysize Vertical   Frame Size. FIXME: Put correct max and default values */
    int32_t m_ysize;
     /*!< m_padval Padding value : zero(0), MaxVal(1), DuplicateLast(2) */
    int32_t m_padval;

} ia_pal_isp_bxt_pixelformatter_t; 

/*! \struct bxt_norm_lin
    
*/
typedef struct 
{
     /*!< lut[257] Normalization lut */
    int32_t lut[257];
     /*!< lin_en Linearization enable */
    int32_t lin_en;
     /*!< lshift The size of normalized shift (signed) */
    int32_t lshift;
     /*!< bypass bypass */
    int32_t bypass;

} ia_pal_isp_bxt_norm_lin_t; 

/*! \struct bxt_blc
    
*/
typedef struct 
{
     /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4 */
    int32_t cfa_type;
     /*!< bypass bypass for the filter */
    int32_t bypass;
     /*!< fixobc00 black level value */
    int32_t fixobc00;
     /*!< fixobc01 black level value */
    int32_t fixobc01;
     /*!< fixobc02 black level value */
    int32_t fixobc02;
     /*!< fixobc03 black level value */
    int32_t fixobc03;
     /*!< fixobc10 black level value */
    int32_t fixobc10;
     /*!< fixobc11 black level value */
    int32_t fixobc11;
     /*!< fixobc12 black level value */
    int32_t fixobc12;
     /*!< fixobc13 black level value */
    int32_t fixobc13;
     /*!< fixobc20 black level value */
    int32_t fixobc20;
     /*!< fixobc21 black level value */
    int32_t fixobc21;
     /*!< fixobc22 black level value */
    int32_t fixobc22;
     /*!< fixobc23 black level value */
    int32_t fixobc23;
     /*!< fixobc30 black level value */
    int32_t fixobc30;
     /*!< fixobc31 black level value */
    int32_t fixobc31;
     /*!< fixobc32 black level value */
    int32_t fixobc32;
     /*!< fixobc33 black level value */
    int32_t fixobc33;

} ia_pal_isp_bxt_blc_t; 

/*! \struct bxt_gridbaseob
    
*/
typedef struct 
{
     /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4 */
    int32_t cfa_type;
     /*!< blc_log2gridwidth log2 of grid of each subplane width */
    int32_t blc_log2gridwidth;
     /*!< blc_log2gridheight log2 of grid of each subplane height */
    int32_t blc_log2gridheight;
     /*!< blc_col_start X value of top left corner of sensor relative to ROI */
    int32_t blc_col_start;
     /*!< blc_row_start Y value of top left corner of sensor relative to ROI */
    int32_t blc_row_start;
     /*!< blc_grid_tablec00[4096] gridob grid table */
    int32_t blc_grid_tablec00[4096];
     /*!< blc_grid_tablec01[4096] gridob grid table */
    int32_t blc_grid_tablec01[4096];
     /*!< blc_grid_tablec02[4096] gridob grid table */
    int32_t blc_grid_tablec02[4096];
     /*!< blc_grid_tablec03[4096] gridob grid table */
    int32_t blc_grid_tablec03[4096];
     /*!< blc_grid_tablec10[4096] gridob grid table */
    int32_t blc_grid_tablec10[4096];
     /*!< blc_grid_tablec11[4096] gridob grid table */
    int32_t blc_grid_tablec11[4096];
     /*!< blc_grid_tablec12[4096] gridob grid table */
    int32_t blc_grid_tablec12[4096];
     /*!< blc_grid_tablec13[4096] gridob grid table */
    int32_t blc_grid_tablec13[4096];
     /*!< blc_grid_tablec20[4096] gridob grid table */
    int32_t blc_grid_tablec20[4096];
     /*!< blc_grid_tablec21[4096] gridob grid table */
    int32_t blc_grid_tablec21[4096];
     /*!< blc_grid_tablec22[4096] gridob grid table */
    int32_t blc_grid_tablec22[4096];
     /*!< blc_grid_tablec23[4096] gridob grid table */
    int32_t blc_grid_tablec23[4096];
     /*!< blc_grid_tablec30[4096] gridob grid table */
    int32_t blc_grid_tablec30[4096];
     /*!< blc_grid_tablec31[4096] gridob grid table */
    int32_t blc_grid_tablec31[4096];
     /*!< blc_grid_tablec32[4096] gridob grid table */
    int32_t blc_grid_tablec32[4096];
     /*!< blc_grid_tablec33[4096] gridob grid table */
    int32_t blc_grid_tablec33[4096];
     /*!< blc_table_width table width */
    int32_t blc_table_width;
     /*!< blc_table_height table height */
    int32_t blc_table_height;
     /*!< bypass bypass for the filter */
    int32_t bypass;

} ia_pal_isp_bxt_gridbaseob_t; 

/*! \struct bxt_linearization
    
*/
typedef struct 
{
     /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4 */
    int32_t cfa_type;
     /*!< linc00[65] linearization grid table */
    int32_t linc00[65];
     /*!< linc01[65] linearization grid table */
    int32_t linc01[65];
     /*!< linc02[65] linearization grid table */
    int32_t linc02[65];
     /*!< linc03[65] linearization grid table */
    int32_t linc03[65];
     /*!< linc10[65] linearization grid table */
    int32_t linc10[65];
     /*!< linc11[65] linearization grid table */
    int32_t linc11[65];
     /*!< linc12[65] linearization grid table */
    int32_t linc12[65];
     /*!< linc13[65] linearization grid table */
    int32_t linc13[65];
     /*!< linc20[65] linearization grid table */
    int32_t linc20[65];
     /*!< linc21[65] linearization grid table */
    int32_t linc21[65];
     /*!< linc22[65] linearization grid table */
    int32_t linc22[65];
     /*!< linc23[65] linearization grid table */
    int32_t linc23[65];
     /*!< linc30[65] linearization grid table */
    int32_t linc30[65];
     /*!< linc31[65] linearization grid table */
    int32_t linc31[65];
     /*!< linc32[65] linearization grid table */
    int32_t linc32[65];
     /*!< linc33[65] linearization grid table */
    int32_t linc33[65];
     /*!< bypass bypass for the filter */
    int32_t bypass;

} ia_pal_isp_bxt_linearization_t; 

/*! \struct bxt_lsc
    
*/
typedef struct 
{
     /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4 */
    int32_t cfa_type;
     /*!< lsclog2gridwidth log2 width of each subplane */
    int32_t lsclog2gridwidth;
     /*!< lsclog2gridheight log2 height of each subplane */
    int32_t lsclog2gridheight;
     /*!< lsc_col_start X value of top left corner of sensor relative to ROI */
    int32_t lsc_col_start;
     /*!< lsc_row_start Y value of top left corner of sensor relative to ROI */
    int32_t lsc_row_start;
     /*!< lsc_exp resolution modifier of the lsc tables */
    int32_t lsc_exp;
     /*!< lsc_grid_tablec00[4096] lsc grid table */
    int32_t lsc_grid_tablec00[4096];
     /*!< lsc_grid_tablec01[4096] lsc grid table */
    int32_t lsc_grid_tablec01[4096];
     /*!< lsc_grid_tablec02[4096] lsc grid table */
    int32_t lsc_grid_tablec02[4096];
     /*!< lsc_grid_tablec03[4096] lsc grid table */
    int32_t lsc_grid_tablec03[4096];
     /*!< lsc_grid_tablec10[4096] lsc grid table */
    int32_t lsc_grid_tablec10[4096];
     /*!< lsc_grid_tablec11[4096] lsc grid table */
    int32_t lsc_grid_tablec11[4096];
     /*!< lsc_grid_tablec12[4096] lsc grid table */
    int32_t lsc_grid_tablec12[4096];
     /*!< lsc_grid_tablec13[4096] lsc grid table */
    int32_t lsc_grid_tablec13[4096];
     /*!< lsc_grid_tablec20[4096] lsc grid table */
    int32_t lsc_grid_tablec20[4096];
     /*!< lsc_grid_tablec21[4096] lsc grid table */
    int32_t lsc_grid_tablec21[4096];
     /*!< lsc_grid_tablec22[4096] lsc grid table */
    int32_t lsc_grid_tablec22[4096];
     /*!< lsc_grid_tablec23[4096] lsc grid table */
    int32_t lsc_grid_tablec23[4096];
     /*!< lsc_grid_tablec30[4096] lsc grid table */
    int32_t lsc_grid_tablec30[4096];
     /*!< lsc_grid_tablec31[4096] lsc grid table */
    int32_t lsc_grid_tablec31[4096];
     /*!< lsc_grid_tablec32[4096] lsc grid table */
    int32_t lsc_grid_tablec32[4096];
     /*!< lsc_grid_tablec33[4096] lsc grid table */
    int32_t lsc_grid_tablec33[4096];
     /*!< lsc_table_width table width */
    int32_t lsc_table_width;
     /*!< lsc_table_height table height */
    int32_t lsc_table_height;
     /*!< bypass bypass for the filter */
    int32_t bypass;

} ia_pal_isp_bxt_lsc_t; 

/*! \struct bxt_dpc
    
*/
typedef struct 
{
     /*!< afxoffset[8] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod */
    int32_t afxoffset[8];
     /*!< afxperiod[8] 8 Autofocus pixels X axis period */
    int32_t afxperiod[8];
     /*!< afyoffset[8] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod */
    int32_t afyoffset[8];
     /*!< afyperiod[8] 8 Autofocus pixels Y axis period */
    int32_t afyperiod[8];
     /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8 */
    int32_t hdrfactors[16];
     /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors */
    int32_t hdrfactorsinverse[16];
     /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier */
    int32_t configunitcolddistvsmedian_slope[7];
     /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier */
    int32_t configunitcolddistvsmedian_x[8];
     /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier */
    int32_t configunitcolddistvsmedian_y[7];
     /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier */
    int32_t configunitcolddistvsneighb_slope[7];
     /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier */
    int32_t configunitcolddistvsneighb_x[8];
     /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier */
    int32_t configunitcolddistvsneighb_y[7];
     /*!< configunitfix_slope[3] fix config unit */
    int32_t configunitfix_slope[3];
     /*!< configunitfix_x[4] fix config unit */
    int32_t configunitfix_x[4];
     /*!< configunitfix_y[3] fix config unit */
    int32_t configunitfix_y[3];
     /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier */
    int32_t configunithotdistvsmedian_slope[7];
     /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier */
    int32_t configunithotdistvsmedian_x[8];
     /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier */
    int32_t configunithotdistvsmedian_y[7];
     /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier */
    int32_t configunithotdistvsneighb_slope[7];
     /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier */
    int32_t configunithotdistvsneighb_x[8];
     /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier */
    int32_t configunithotdistvsneighb_y[7];
     /*!< configunitrawvslb_slope[7] configunitrawvslb_slope */
    int32_t configunitrawvslb_slope[7];
     /*!< configunitrawvslb_x[8] configunitrawvslb_x */
    int32_t configunitrawvslb_x[8];
     /*!< configunitrawvslb_y[7] configunitrawvslb_y */
    int32_t configunitrawvslb_y[7];
     /*!< configunitrawvsub_slope[7] configunitrawvsub_slope */
    int32_t configunitrawvsub_slope[7];
     /*!< configunitrawvsub_x[8] configunitrawvsub_x */
    int32_t configunitrawvsub_x[8];
     /*!< configunitrawvsub_y[7] configunitrawvsub_y */
    int32_t configunitrawvsub_y[7];
     /*!< curx[1024] x locations of the static bad pixels */
    int32_t curx[1024];
     /*!< cury[1024] y locations of the static bad pixels */
    int32_t cury[1024];
     /*!< lbtype[16] 0 - B1,   1 - B2,  2 - B3 */
    int32_t lbtype[16];
     /*!< ubtype[16] 0 - B1,   1 - B2,  2 - B3 */
    int32_t ubtype[16];
     /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6 */
    int32_t pelesttype[16];
     /*!< dtype[16] 0-D1 1-D2  2-D3 */
    int32_t dtype[16];
     /*!< lbmasks[64] configurations related to the bayer pattern */
    int32_t lbmasks[64];
     /*!< ubmasks[64] configurations related to the bayer pattern */
    int32_t ubmasks[64];
     /*!< pmasks[384] configurations related to the bayer pattern */
    int32_t pmasks[384];
     /*!< dmasks[48] configurations related to the bayer pattern */
    int32_t dmasks[48];
     /*!< bitreduceshift Shift value for bit reduce block */
    int32_t bitreduceshift;
     /*!< afenable enable for the AF unit block */
    int32_t afenable;
     /*!< staticenable enable for the static LUT block */
    int32_t staticenable;
     /*!< dynamicenable enable for the dynamic detection block */
    int32_t dynamicenable;
     /*!< n_static_lut_entries number of static lut entries */
    int32_t n_static_lut_entries;
     /*!< frame_width frame width */
    int32_t frame_width;
     /*!< paf_grid0_en paf enable0 */
    int32_t paf_grid0_en;
     /*!< paf_grid1_en paf enable1 */
    int32_t paf_grid1_en;
     /*!< paf_grid2_en paf enable2 */
    int32_t paf_grid2_en;
     /*!< paf_grid3_en paf enable3 */
    int32_t paf_grid3_en;
     /*!< paf_grid4_en paf enable4 */
    int32_t paf_grid4_en;
     /*!< paf_grid5_en paf enable5 */
    int32_t paf_grid5_en;
     /*!< paf_grid6_en paf enable6 */
    int32_t paf_grid6_en;
     /*!< paf_grid7_en paf enable7 */
    int32_t paf_grid7_en;

} ia_pal_isp_bxt_dpc_t; 

/*! \struct bxt_disparity
    
*/
typedef struct 
{
     /*!< green_pos gb position */
    int32_t green_pos;
     /*!< lc_cu_x[4] local contrast config unit x */
    int32_t lc_cu_x[4];
     /*!< lc_cu_y[3] local contrast config unit y */
    int32_t lc_cu_y[3];
     /*!< lc_cu_slope[3] local contrast config unit slope */
    int32_t lc_cu_slope[3];
     /*!< delta_cu_x[4] delta config unit x */
    int32_t delta_cu_x[4];
     /*!< delta_cu_y[3] delta config unit y */
    int32_t delta_cu_y[3];
     /*!< delta_cu_slope[3] delta config unit slope */
    int32_t delta_cu_slope[3];
     /*!< inv_lc_cu_x[8] inverse local contarst config unit x */
    int32_t inv_lc_cu_x[8];
     /*!< inv_lc_cu_y[7] inverse local contarst config unit y */
    int32_t inv_lc_cu_y[7];
     /*!< inv_lc_cu_slope[7] inverse local contarst config unit slope */
    int32_t inv_lc_cu_slope[7];
     /*!< inv_delta_cu_x[8] inverse delta config unit x */
    int32_t inv_delta_cu_x[8];
     /*!< inv_delta_cu_y[7] inverse delta config unit y */
    int32_t inv_delta_cu_y[7];
     /*!< inv_delta_cu_slope[7] inverse delta config unit slope */
    int32_t inv_delta_cu_slope[7];
     /*!< detail_pres detail preservation factor */
    int32_t detail_pres;
     /*!< invscale scale factor after normalizing by inverse */
    int32_t invscale;

} ia_pal_isp_bxt_disparity_t; 

/*! \struct bxt_applycorrection
    
*/
typedef struct 
{
     /*!< global_enable global enable */
    int32_t global_enable;
     /*!< gdc_enable gdc enable */
    int32_t gdc_enable;
     /*!< dpc_enable dpc enable */
    int32_t dpc_enable;
     /*!< green_pos gb position */
    int32_t green_pos;

} ia_pal_isp_bxt_applycorrection_t; 

/*! \struct bxt_3a_ccm
    
*/
typedef struct 
{
     /*!< gain_cx[8] WB coefficients */
    int32_t gain_cx[8];
     /*!< m_1x[4] CCM matrix coefficients M11 - M14 */
    int32_t m_1x[4];
     /*!< m_2x[4] CCM matrix coefficients M21 - M24 */
    int32_t m_2x[4];
     /*!< m_3x[4] CCM matrix coefficients M31 - M34 */
    int32_t m_3x[4];
     /*!< c_0x[8] Y-calc matrix coefficients C01 - C08 */
    int32_t c_0x[8];
     /*!< c_1x[8] Y-calc matrix coefficients C11 - C18 */
    int32_t c_1x[8];
     /*!< c_2x[8] Y-calc matrix coefficients C21 - C28 */
    int32_t c_2x[8];
     /*!< c_3x[8] Y-calc matrix coefficients C31 - C38 */
    int32_t c_3x[8];
     /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA */
    int32_t sensor_mode;
     /*!< ccm_ycalc_en 0: CCM_YCALC is bypassed; 1: CCM_YCALC is enabled */
    int32_t ccm_ycalc_en;
     /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_00;
     /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_01;
     /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_02;
     /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_03;
     /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_10;
     /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_11;
     /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_12;
     /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_13;
     /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_20;
     /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_21;
     /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_22;
     /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_23;
     /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_30;
     /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_31;
     /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_32;
     /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_33;

} ia_pal_isp_bxt_3a_ccm_t; 

/*! \struct bxt_pixprecadapter_precropstills
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_precropstills_t; 

/*! \struct bxt_cropstills
    
*/
typedef struct 
{
     /*!< Bypass block bypass */
    int32_t Bypass;
     /*!< LeftBorder crop left border */
    int32_t LeftBorder;
     /*!< TopBorder crop top border */
    int32_t TopBorder;
     /*!< RightBorder crop right border */
    int32_t RightBorder;
     /*!< BottomBorder crop bottom border */
    int32_t BottomBorder;

} ia_pal_isp_bxt_cropstills_t; 

/*! \struct bxt_cropvideo
    
*/
typedef struct 
{
     /*!< Bypass block bypass */
    int32_t Bypass;
     /*!< LeftBorder crop left border */
    int32_t LeftBorder;
     /*!< TopBorder crop top border */
    int32_t TopBorder;
     /*!< RightBorder crop right border */
    int32_t RightBorder;
     /*!< BottomBorder crop bottom border */
    int32_t BottomBorder;

} ia_pal_isp_bxt_cropvideo_t; 

/*! \struct bxt_wb
    
*/
typedef struct 
{
     /*!< m_bypass Bypass            {0,1} */
    int32_t m_bypass;
     /*!< m_gainch0 Gain Channel0 (Gr) (U4.12) */
    int32_t m_gainch0;
     /*!< m_gainch1 Gain Channel1 (Gb) (U4.12) */
    int32_t m_gainch1;
     /*!< m_gainch2 Gain Channel2 (G)  (U4.12) */
    int32_t m_gainch2;
     /*!< m_gainch3 Gain Channel3 (B)  (U4.12) */
    int32_t m_gainch3;
     /*!< m_gainch4 Gain Channel4 (R)  (U4.12) */
    int32_t m_gainch4;
     /*!< m_gainch5 Gain Channel5 (W)  (U4.12) */
    int32_t m_gainch5;
     /*!< m_gainch6 Gain Channel6 (U4.12) */
    int32_t m_gainch6;
     /*!< m_gainch7 Gain Channel7 (U4.12) */
    int32_t m_gainch7;
     /*!< m_sensormode 1x1 (0), 2x2 (1), 4x4 (2) */
    int32_t m_sensormode;
     /*!< m_wbindmat[16] Vector WB matrix */
    int32_t m_wbindmat[16];

} ia_pal_isp_bxt_wb_t; 

/*! \struct bxt_aestatistics
    
*/
typedef struct 
{
     /*!< cell0[96] weighted histogram grid values */
    int32_t cell0[96];
     /*!< cell1[96] weighted histogram grid values */
    int32_t cell1[96];
     /*!< cell2[96] weighted histogram grid values */
    int32_t cell2[96];
     /*!< cell3[96] weighted histogram grid values */
    int32_t cell3[96];
     /*!< cell4[96] weighted histogram grid values */
    int32_t cell4[96];
     /*!< cell5[96] weighted histogram grid values */
    int32_t cell5[96];
     /*!< cell6[96] weighted histogram grid values */
    int32_t cell6[96];
     /*!< cell7[96] weighted histogram grid values */
    int32_t cell7[96];
     /*!< grid_width represents number of horizontal grid cells */
    int32_t grid_width;
     /*!< grid_height represents number of vertical grid cells */
    int32_t grid_height;
     /*!< block_width Log2 the width of each grid cell (8,16,32,64,128, 256) */
    int32_t block_width;
     /*!< block_height Log2 the height of each grid cell (8,16,32,64,128, 256) */
    int32_t block_height;
     /*!< ae_en 0: FF will not write to the AE  array; 1: FF will write */
    int32_t ae_en;
     /*!< rst_hist_array 1: triggers the reset mechanism for the GLB_HIST */
    int32_t rst_hist_array;
     /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1) */
    int32_t x_start;
     /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1) */
    int32_t y_start;
     /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1 */
    int32_t x_end;
     /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1 */
    int32_t y_end;
     /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA */
    int32_t sensor_mode;
     /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_00;
     /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_01;
     /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_02;
     /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_03;
     /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_10;
     /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_11;
     /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_12;
     /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_13;
     /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_20;
     /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_21;
     /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_22;
     /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_23;
     /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_30;
     /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_31;
     /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_32;
     /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_33;

} ia_pal_isp_bxt_aestatistics_t; 

/*! \struct bxt_af_awb_fr_statistics
    
*/
typedef struct 
{
     /*!< grid_width represents number of horizontal grid cells */
    int32_t grid_width;
     /*!< grid_height represents number of vertical grid cells */
    int32_t grid_height;
     /*!< block_width Log2 the width of each grid cell (8,16,32,64,128,256) */
    int32_t block_width;
     /*!< block_height Log2 the height of each grid cell (8,16,32,64,128,256) */
    int32_t block_height;
     /*!< grid_height_per_slice # of blocks (vert) per Meta-Data Slice (grid_height_per_slice * grid_width <= 32; grid_height_per_slice <= 2) */
    int32_t grid_height_per_slice;
     /*!< y_fr_en 0: FF will not write to the Y array; 1: FF will write */
    int32_t y_fr_en;
     /*!< awb_fr_en 0: FF will not write to the AWB_FR array; 1: FF will write */
    int32_t awb_fr_en;
     /*!< ff_en 0: FF is bypassed; 1: FF is enabled */
    int32_t ff_en;
     /*!< x_start X top left corner of the grid. 20 <= x_start <= (frame_width - 1) */
    int32_t x_start;
     /*!< y_start Y top left corner of the grid. 0 <= x_start <= (frame_height - 1) */
    int32_t y_start;
     /*!< x_end X bottom right corner of the grid. x_end <= (frame_width - 1 - 20) */
    int32_t x_end;
     /*!< y_end Y bottom right corner of the grid. y_end <= (frame_height - 1) */
    int32_t y_end;
     /*!< shftr_val_x[7] represents log2(num of pixels of the estimated colour component in a block) for Y00, Y01, Y10, Y11, R, G, B */
    int32_t shftr_val_x[7];
     /*!< gx0[4] Ycalc contribution ratio for Pat_ij */
    int32_t gx0[4];
     /*!< gx1[4] Ycalc contribution ratio for Pat_ij */
    int32_t gx1[4];
     /*!< gx2[4] Ycalc contribution ratio for Pat_ij */
    int32_t gx2[4];
     /*!< gx3[4] Ycalc contribution ratio for Pat_ij */
    int32_t gx3[4];
     /*!< mask_y0 selecting the relevant pixels for Y0; bit k corresponds to Row * 4 + Column */
    int32_t mask_y0;
     /*!< mask_y1 selecting the relevant pixels for Y1; bit k corresponds to Row * 4 + Column */
    int32_t mask_y1;
     /*!< oe_y0 Output Enable for Y0; bit k corresponds to Row * 2 + Column */
    int32_t oe_y0;
     /*!< oe_y1 Output Enable for Y1; bit k corresponds to Row * 2 + Column */
    int32_t oe_y1;
     /*!< on_x_y0[4] Y0 estimation normalization (00, 01, 10, 11) */
    int32_t on_x_y0[4];
     /*!< on_x_y1[4] Y1 estimation normalization (00, 01, 10, 11) */
    int32_t on_x_y1[4];
     /*!< r_select selecting the relevant R pixels; bit k corresponds to Row * 4 + Column */
    int32_t r_select;
     /*!< g_select selecting the relevant G pixels; bit k corresponds to Row * 4 + Column + 16 */
    int32_t g_select;
     /*!< b_select selecting the relevant B pixels; bit k corresponds to Row * 4 + Column */
    int32_t b_select;
     /*!< y00_filter_coeff[6] filter coefficients for Y00 (A1, A2, A3, A4, A5, A6) */
    int32_t y00_filter_coeff[6];
     /*!< y00_filter_sign_vec sign vector for Y00 */
    int32_t y00_filter_sign_vec;
     /*!< y01_filter_coeff[6] filter coefficients for Y01 (A1, A2, A3, A4, A5, A6) */
    int32_t y01_filter_coeff[6];
     /*!< y01_filter_sign_vec sign vector for Y01 */
    int32_t y01_filter_sign_vec;
     /*!< y10_filter_coeff[6] filter coefficients for Y10 (A1, A2, A3, A4, A5, A6) */
    int32_t y10_filter_coeff[6];
     /*!< y10_filter_sign_vec sign vector for Y10 */
    int32_t y10_filter_sign_vec;
     /*!< y11_filter_coeff[6] filter coefficients for Y11 (A1, A2, A3, A4, A5, A6) */
    int32_t y11_filter_coeff[6];
     /*!< y11_filter_sign_vec sign vector for Y11 */
    int32_t y11_filter_sign_vec;
     /*!< r_filter_coeff[6] filter coefficients for R (A1, A2, A3, A4, A5, A6) */
    int32_t r_filter_coeff[6];
     /*!< r_filter_sign_vec sign vector for R */
    int32_t r_filter_sign_vec;
     /*!< g_filter_coeff[6] filter coefficients for G (A1, A2, A3, A4, A5, A6) */
    int32_t g_filter_coeff[6];
     /*!< g_filter_sign_vec sign vector for G */
    int32_t g_filter_sign_vec;
     /*!< b_filter_coeff[6] filter coefficients for B (A1, A2, A3, A4, A5, A6) */
    int32_t b_filter_coeff[6];
     /*!< b_filter_sign_vec sign vector for B */
    int32_t b_filter_sign_vec;
     /*!< nf_x[7] Filter response normalization factors for Y00, Y01, Y10, Y11, R, G, B */
    int32_t nf_x[7];
     /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA */
    int32_t sensor_mode;

} ia_pal_isp_bxt_af_awb_fr_statistics_t; 

/*! \struct bxt_awbstatistics
    
*/
typedef struct 
{
     /*!< grid_width represents number of horizontal grid cells */
    int32_t grid_width;
     /*!< grid_height represents number of vertical grid cells */
    int32_t grid_height;
     /*!< block_width Log2 the width of each grid cell (8,16,32,64,128) */
    int32_t block_width;
     /*!< block_height Log2 the height of each grid cell (8,16,32,64,128) */
    int32_t block_height;
     /*!< grid_height_per_slice # of blocks in vert.axis per Meta-Data Slice (grid_height_per_slice * grid_width <= 160) */
    int32_t grid_height_per_slice;
     /*!< awb_en 0: FF will not write to the AWB  array; 1: FF will write */
    int32_t awb_en;
     /*!< rgbs_incl_sat 0: do not include saturated quads in the average; 1: include saturated quads in the average */
    int32_t rgbs_incl_sat;
     /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1) */
    int32_t x_start;
     /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1) */
    int32_t y_start;
     /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1 */
    int32_t x_end;
     /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1 */
    int32_t y_end;
     /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA */
    int32_t sensor_mode;
     /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_00;
     /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_01;
     /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_02;
     /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_03;
     /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_10;
     /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_11;
     /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_12;
     /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_13;
     /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_20;
     /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_21;
     /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_22;
     /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_23;
     /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_30;
     /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_31;
     /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_32;
     /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column */
    int32_t pat_33;
     /*!< rgbs_thr_cx[8] RGBS threshold value (C0, C1, C2, C3, C4, C5, C6, C7) */
    int32_t rgbs_thr_cx[8];
     /*!< shftr_val_cx[8] ShiftVal is derived from log2(number of pixels from C0-C7 color channel in a cell) */
    int32_t shftr_val_cx[8];
     /*!< shftr_sat represents log2(num of pixels in cell) */
    int32_t shftr_sat;

} ia_pal_isp_bxt_awbstatistics_t; 

/*! \struct bxt_inputscaler
    
*/
typedef struct 
{
     /*!< block_bypass block bypass bit. Note that in ATE this parameters is "bypass" (0 - enable. 1 - disable) while in HW it is "enable" (0 - bypass. 1 - enable).
In case block_bypass = 1, demo_bypass and scaler_bypass will turn to 1. */
    int32_t block_bypass;
     /*!< demo_bypass demosaic bypass bit.  Note that in ATE this parameters is "bypass" (0 - enable. 1 - disable) while in HW it is "enable" (0 - bypass. 1 - enable). */
    int32_t demo_bypass;
     /*!< scaler_bypass scaler bypass bit.  Note that in ATE this parameters is "bypass" (0 - enable. 1 - disable) while in HW it is "enable" (0 - bypass. 1 - enable). */
    int32_t scaler_bypass;
     /*!< vnumerator Vertical SF Numerator */
    int32_t vnumerator;
     /*!< hnumerator Horizontal SF Numerator */
    int32_t hnumerator;
     /*!< vdenominator Vertical SF Denominator */
    int32_t vdenominator;
     /*!< hdenominator Horizontal SF Denominator */
    int32_t hdenominator;
     /*!< norm_mul Normalization multiply coefficient */
    int32_t norm_mul;
     /*!< norm_shift Normalization shift */
    int32_t norm_shift;
     /*!< output_sensor_mode Output Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode. */
    int32_t output_sensor_mode;
     /*!< output_format_matrix[16] Output format matrix [4,4]. 0=R. 1=G. 2=G. 3=W */
    int32_t output_format_matrix[16];
     /*!< Input_Frame_Width Input frame width. Has to be a multiple of 4. */
    int32_t Input_Frame_Width;
     /*!< input_is_bayer 0 - Bayer, 1 - RGBC */
    int32_t input_is_bayer;
     /*!< output_height Has to be a multiple of 4. */
    int32_t output_height;
     /*!< output_width Better be a mutiplication of 32 to avoid RTL zero padding (?). When block is stationed in isla (isla=on) then maximum is 2560. Has to be a multiple of 4. */
    int32_t output_width;
     /*!< shift_to_lb Shifting before LB */
    int32_t shift_to_lb;
     /*!< input_sensor_mode Input Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode. */
    int32_t input_sensor_mode;
     /*!< is_ul_w Is the first pixel in frame G/W 1-true, 0-false */
    int32_t is_ul_w;
     /*!< bayer_type Bayer Type - BGGR(0), RGGB(1), GRBG(2), GBRG(3) */
    int32_t bayer_type;
     /*!< lut_values[16] QNN LUT - Values. Restriction - rising monotonic. */
    int32_t lut_values[16];
     /*!< lut_shifts1[16] QNN LUT - Shift1. lut_shift2 >= lut_shift1. */
    int32_t lut_shifts1[16];
     /*!< lut_shifts2[16] QNN LUT - Shift2. lut_shift2 >= lut_shift1. */
    int32_t lut_shifts2[16];
     /*!< lut_subtraction_flags[16] QNN LUT - Flags */
    int32_t lut_subtraction_flags[16];
     /*!< lut_output_values[16] QNN LUT - Output Values */
    int32_t lut_output_values[16];
     /*!< kernel_g_coef[6] G kernel - Coefs */
    int32_t kernel_g_coef[6];
     /*!< kernel_g_norm File for G kernel - Norm */
    int32_t kernel_g_norm;
     /*!< cbf_div_cu_x[12] Config unit division - X points */
    int32_t cbf_div_cu_x[12];
     /*!< cbf_div_cu_y[11] Config unit division - Y points */
    int32_t cbf_div_cu_y[11];
     /*!< cbf_div_cu_slope[11] Config unit division - Slopes */
    int32_t cbf_div_cu_slope[11];
     /*!< cbi_r_pos[96] .CBI R Positions. Valid range {0-17} */
    int32_t cbi_r_pos[96];
     /*!< cbi_r_wgt[96] CBI R Weights. Valid range: {0-4 , 7} */
    int32_t cbi_r_wgt[96];
     /*!< cbi_g_pos[96] CBI G Positions. Valid range {0-17} */
    int32_t cbi_g_pos[96];
     /*!< cbi_g_wgt[96] CBI G Weights. Valid range {0-4 , 7} */
    int32_t cbi_g_wgt[96];
     /*!< cbi_b_pos[96] CBI B Positions. Valid range {0-17} */
    int32_t cbi_b_pos[96];
     /*!< cbi_b_wgt[96] CBI B Weights. Valid range {0-4 , 7} */
    int32_t cbi_b_wgt[96];
     /*!< wb_matrix[16] Matrix[4][4] for WB. 0=no gain. 1=R. 2=B. 3=G. (in each quad must use at least two zeros (no gain)). */
    int32_t wb_matrix[16];
     /*!< r_wb_gain WB R gain */
    int32_t r_wb_gain;
     /*!< g_wb_gain WB G gain */
    int32_t g_wb_gain;
     /*!< b_wb_gain WB B gain */
    int32_t b_wb_gain;

} ia_pal_isp_bxt_inputscaler_t; 

/*! \struct bxt_vcsc
    
*/
typedef struct 
{
     /*!< bypass Block bypass for HW use */
    int32_t bypass;
     /*!< gain Matrix table gain exponent */
    int32_t gain;
     /*!< coef_matrix[12] 3x4 Matrix coeffcients, Q10 */
    int32_t coef_matrix[12];
     /*!< t0 matrix offeset 0 (y) */
    int32_t t0;
     /*!< t1 matrix offeset 1 (u) */
    int32_t t1;
     /*!< t2 matrix offeset y (v) */
    int32_t t2;
     /*!< fir_alpha_h Horizontal filter 2nd tap coeffcient , Q10 */
    int32_t fir_alpha_h;
     /*!< fir_alpha_v Horizontal filter 2nd tap coeffcient , Q10 */
    int32_t fir_alpha_v;

} ia_pal_isp_bxt_vcsc_t; 

/*! \struct bxt_pixprecadapter_precropvideo
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_precropvideo_t; 

/*! \struct bxt_xnr4_m
    Scalable Chroma and Luma Denoise, Medium and High Frequency
*/
typedef struct 
{
     /*!< jbl_mf_bypass_y Bypass JBL MF Luma */
    int32_t jbl_mf_bypass_y;
     /*!< jbl_mf_bypass_c Bypass MF Chroma */
    int32_t jbl_mf_bypass_c;
     /*!< noise_sigma_mf_y_y Noise Sigma MF Luma per Luma */
    int32_t noise_sigma_mf_y_y;
     /*!< noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration */
    int32_t noise_sigma_mf_y_s;
     /*!< noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma */
    int32_t noise_sigma_mf_c_y;
     /*!< noise_sigma_mf_c_u Noise Sigma MF Chroma per U */
    int32_t noise_sigma_mf_c_u;
     /*!< noise_sigma_mf_c_v Noise Sigma MF Chroma per V */
    int32_t noise_sigma_mf_c_v;
     /*!< rad_noise_sigma_mf_y_y Noise Sigma MF Luma per Luma - radial */
    int32_t rad_noise_sigma_mf_y_y;
     /*!< rad_noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration - radial */
    int32_t rad_noise_sigma_mf_y_s;
     /*!< rad_noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma - radial */
    int32_t rad_noise_sigma_mf_c_y;
     /*!< rad_noise_sigma_mf_c_u Noise Sigma MF Chroma per U - radial */
    int32_t rad_noise_sigma_mf_c_u;
     /*!< rad_noise_sigma_mf_c_v Noise Sigma MF Chroma per V - radial */
    int32_t rad_noise_sigma_mf_c_v;
     /*!< noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 */
    int32_t noise_epsilon_mf_y_y;
     /*!< noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 */
    int32_t noise_epsilon_mf_c_y;
     /*!< noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 */
    int32_t noise_epsilon_mf_c_u;
     /*!< noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 */
    int32_t noise_epsilon_mf_c_v;
     /*!< rad_noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 - radial */
    int32_t rad_noise_epsilon_mf_y_y;
     /*!< rad_noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_y;
     /*!< rad_noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_u;
     /*!< rad_noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_v;
     /*!< jbl_weight_th_mf_y Luma Weight threshold of MF JBL */
    int32_t jbl_weight_th_mf_y;
     /*!< jbl_weight_th_mf_c Chroma Weight threshold of MF JBL */
    int32_t jbl_weight_th_mf_c;
     /*!< lpf_mf_coef_y[49] MF JBL Spatial coefs for Luma */
    int32_t lpf_mf_coef_y[49];
     /*!< lpf_mf_coef_c[49] MF JBL Spatial coefs for Chroma */
    int32_t lpf_mf_coef_c[49];
     /*!< range_weight_lut[7] JBL range Weight LUT */
    int32_t range_weight_lut[7];
     /*!< blend_mf_power_y MF denoise blending power y */
    int32_t blend_mf_power_y;
     /*!< blend_mf_power_c MF denoise blending power chroma */
    int32_t blend_mf_power_c;
     /*!< rad_blend_mf_power_y MF denoise blending power y - radial */
    int32_t rad_blend_mf_power_y;
     /*!< rad_blend_mf_power_c MF denoise blending power chroma -radial */
    int32_t rad_blend_mf_power_c;
     /*!< noise_beta_y_0 noise model for y - coef 0, Q12 */
    int32_t noise_beta_y_0;
     /*!< noise_beta_u_0 noise model for u - coef 0, Q12 */
    int32_t noise_beta_u_0;
     /*!< noise_beta_u_1 noise model for u - coef 1, Q12 */
    int32_t noise_beta_u_1;
     /*!< noise_beta_v_0 noise model for v - coef 0, Q12 */
    int32_t noise_beta_v_0;
     /*!< noise_beta_v_2 noise model for v - coef 2, Q12 */
    int32_t noise_beta_v_2;
     /*!< rad_center_x X location of the radial center location relative to the top left pixel */
    int32_t rad_center_x;
     /*!< rad_center_y Y location of the radial center location relative to the top left pixel */
    int32_t rad_center_y;
     /*!< rad_exp Radial scale bit into the Lut */
    int32_t rad_exp;
     /*!< rad_lut[128] Radial LUT */
    int32_t rad_lut[128];
     /*!< one_div_64_lut[64] 1/SQRT(x), first 64 values LUT */
    int32_t one_div_64_lut[64];
     /*!< xcu_divsqrt_exp XCU divsqrt exponent */
    int32_t xcu_divsqrt_exp;
     /*!< xcu_divsqrt_slp_a_res XCU divsqrt slope precision */
    int32_t xcu_divsqrt_slp_a_res;
     /*!< xcu_divsqrt_offset[16] XCU divsqrt offset(y) vector */
    int32_t xcu_divsqrt_offset[16];
     /*!< xcu_divsqrt_slope[16] XCU divsqrt slope vector */
    int32_t xcu_divsqrt_slope[16];
     /*!< xcu_divsqrt_x[17] XCU divsqrt x points vector + maximal x value */
    int32_t xcu_divsqrt_x[17];

} ia_pal_isp_bxt_xnr4_m_t; 

/*! \struct bxt_rynr_splitter
    
*/
typedef struct 
{
     /*!< input_pin Which input pin connect to output: if 1 (Stills), output pin is InputPin1 (pcsBayer), if 0 (Video), output pin is InputPin0 (pcsYUV420) */
    int32_t input_pin;

} ia_pal_isp_bxt_rynr_splitter_t; 

/*! \struct bxt_pixprecadapter_prevcud
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_prevcud_t; 

/*! \struct bxt_bnlm
    
*/
typedef struct 
{
     /*!< div_unit_slope[15] DIV_UNIT_SLOPE - fixed value array for config unit */
    int32_t div_unit_slope[15];
     /*!< div_unit_x[16] DIV_UNIT_X - fixed value array for config unit */
    int32_t div_unit_x[16];
     /*!< div_unit_y[15] DIV_UNIT_Y - fixed value array for config unit */
    int32_t div_unit_y[15];
     /*!< m_bypass Block bypass for HW use */
    int32_t m_bypass;
     /*!< m_bcandshift1[4] m_BCandShift1: Group B candidate factoring params */
    int32_t m_bcandshift1[4];
     /*!< m_bcandshift2[4] m_BCandShift2: Group B candidate factoring params */
    int32_t m_bcandshift2[4];
     /*!< m_bcandsubflag[4] m_BCandSubFlag: Group B candidate factoring params */
    int32_t m_bcandsubflag[4];
     /*!< m_ccandshift1[4] m_CCandShift1: Group C candidate factoring params */
    int32_t m_ccandshift1[4];
     /*!< m_ccandshift2[4] m_CCandShift2:  Group C candidate factoring params */
    int32_t m_ccandshift2[4];
     /*!< m_ccandsubflag[4] m_CCandSubFlag:  Group C candidate factoring params */
    int32_t m_ccandsubflag[4];
     /*!< m_candconstellation[2] m_CandConstellation: (0,1,2)  (1=Dendse 10x10 for Y video  0=16x16 sparse for Bayer)    2=Obsolete   input format related params;   Only first element is in use */
    int32_t m_candconstellation[2];
     /*!< m_dcandshift1[4] m_DCandShift1:  Group D candidate factoring params */
    int32_t m_dcandshift1[4];
     /*!< m_dcandshift2[4] m_DCandShift2:   Group D candidate factoring params */
    int32_t m_dcandshift2[4];
     /*!< m_dcandsubflag[4] m_DCandSubFlag:   Group D candidate factoring params */
    int32_t m_dcandsubflag[4];
     /*!< m_detail_radial_lut_f1[12] m_DETAIL_RADIAL_LUT_f1 */
    int32_t m_detail_radial_lut_f1[12];
     /*!< m_detail_radial_lut_f2[12] m_DETAIL_RADIAL_LUT_f2 */
    int32_t m_detail_radial_lut_f2[12];
     /*!< m_detail_radial_lut_s1[12] m_DETAIL_RADIAL_LUT_s1 */
    int32_t m_detail_radial_lut_s1[12];
     /*!< m_detail_radial_lut_s2[12] m_DETAIL_RADIAL_LUT_s2 */
    int32_t m_detail_radial_lut_s2[12];
     /*!< m_detail_radial_lut_s3[12] m_DETAIL_RADIAL_LUT_s3 */
    int32_t m_detail_radial_lut_s3[12];
     /*!< m_detail_radial_lut_v[12] m_DETAIL_RADIAL_LUT_v */
    int32_t m_detail_radial_lut_v[12];
     /*!< m_exp_lut_f1[12] m_EXP_LUT_f1 */
    int32_t m_exp_lut_f1[12];
     /*!< m_exp_lut_f2[12] m_EXP_LUT_f2 */
    int32_t m_exp_lut_f2[12];
     /*!< m_exp_lut_o[12] m_EXP_LUT_o */
    int32_t m_exp_lut_o[12];
     /*!< m_exp_lut_s1[12] m_EXP_LUT_s1 */
    int32_t m_exp_lut_s1[12];
     /*!< m_exp_lut_s2[12] m_EXP_LUT_s2 */
    int32_t m_exp_lut_s2[12];
     /*!< m_exp_lut_s3[12] m_EXP_LUT_s3 */
    int32_t m_exp_lut_s3[12];
     /*!< m_exp_lut_v[12] m_EXP_LUT_v */
    int32_t m_exp_lut_v[12];
     /*!< m_frame_width OBSOLETE */
    int32_t m_frame_width;
     /*!< m_matchqualitymaxidx[4] OBSOLETE */
    int32_t m_matchqualitymaxidx[4];
     /*!< m_mu_root_lut_f1[12] m_MU_ROOT_LUT_f1 */
    int32_t m_mu_root_lut_f1[12];
     /*!< m_mu_root_lut_f2[12] m_MU_ROOT_LUT_f2 */
    int32_t m_mu_root_lut_f2[12];
     /*!< m_mu_root_lut_s1[12] m_MU_ROOT_LUT_s1 */
    int32_t m_mu_root_lut_s1[12];
     /*!< m_mu_root_lut_s2[12] m_MU_ROOT_LUT_s2 */
    int32_t m_mu_root_lut_s2[12];
     /*!< m_mu_root_lut_s3[12] m_MU_ROOT_LUT_s3 */
    int32_t m_mu_root_lut_s3[12];
     /*!< m_mu_root_lut_v[12] m_MU_ROOT_LUT_v */
    int32_t m_mu_root_lut_v[12];
     /*!< m_nl_lut1_f1[10] m_NL_LUT1_f1 */
    int32_t m_nl_lut1_f1[10];
     /*!< m_nl_lut1_f2[10] m_NL_LUT1_f1 */
    int32_t m_nl_lut1_f2[10];
     /*!< m_nl_lut1_s1[10] m_NL_LUT1_s1 */
    int32_t m_nl_lut1_s1[10];
     /*!< m_nl_lut1_s2[10] m_NL_LUT1_s2 */
    int32_t m_nl_lut1_s2[10];
     /*!< m_nl_lut1_s3[10] m_NL_LUT1_s2 */
    int32_t m_nl_lut1_s3[10];
     /*!< m_nl_lut1_v[10] m_NL_LUT1_v */
    int32_t m_nl_lut1_v[10];
     /*!< m_nl_lut2_f1[10] m_NL_LUT2_f1 */
    int32_t m_nl_lut2_f1[10];
     /*!< m_nl_lut2_f2[10] m_NL_LUT2_f1 */
    int32_t m_nl_lut2_f2[10];
     /*!< m_nl_lut2_s1[10] m_NL_LUT2_s1 */
    int32_t m_nl_lut2_s1[10];
     /*!< m_nl_lut2_s2[10] m_NL_LUT2_s2 */
    int32_t m_nl_lut2_s2[10];
     /*!< m_nl_lut2_s3[10] m_NL_LUT2_s2 */
    int32_t m_nl_lut2_s3[10];
     /*!< m_nl_lut2_v[10] m_NL_LUT2_v */
    int32_t m_nl_lut2_v[10];
     /*!< m_nl_lut3_f1[10] m_NL_LUT3_f1 */
    int32_t m_nl_lut3_f1[10];
     /*!< m_nl_lut3_f2[10] m_NL_LUT3_f1 */
    int32_t m_nl_lut3_f2[10];
     /*!< m_nl_lut3_s1[10] m_NL_LUT3_s1 */
    int32_t m_nl_lut3_s1[10];
     /*!< m_nl_lut3_s2[10] m_NL_LUT3_s2 */
    int32_t m_nl_lut3_s2[10];
     /*!< m_nl_lut3_s3[10] m_NL_LUT3_s2 */
    int32_t m_nl_lut3_s3[10];
     /*!< m_nl_lut3_v[10] m_NL_LUT3_v */
    int32_t m_nl_lut3_v[10];
     /*!< m_nl_lut4_f1[10] m_NL_LUT4_f1 */
    int32_t m_nl_lut4_f1[10];
     /*!< m_nl_lut4_f2[10] m_NL_LUT4_f1 */
    int32_t m_nl_lut4_f2[10];
     /*!< m_nl_lut4_s1[10] m_NL_LUT4_s1 */
    int32_t m_nl_lut4_s1[10];
     /*!< m_nl_lut4_s2[10] m_NL_LUT4_s2 */
    int32_t m_nl_lut4_s2[10];
     /*!< m_nl_lut4_s3[10] m_NL_LUT4_s2 */
    int32_t m_nl_lut4_s3[10];
     /*!< m_nl_lut4_v[10] m_NL_LUT4_v */
    int32_t m_nl_lut4_v[10];
     /*!< m_nl_th[3] m_NL_TH: detailIx-->detailType 3 THs for classification 1=Flat.vs.Weak; 2=Weak.vs.Texture 3=Texture.vs.Edge 4=OBSOLETE & not implemented */
    int32_t m_nl_th[3];
     /*!< m_radial_power_lut_f1[12] m_RADIAL_POWER_LUT_f1 */
    int32_t m_radial_power_lut_f1[12];
     /*!< m_radial_power_lut_f2[12] m_RADIAL_POWER_LUT_f2 */
    int32_t m_radial_power_lut_f2[12];
     /*!< m_radial_power_lut_s1[12] m_RADIAL_POWER_LUT_s1 */
    int32_t m_radial_power_lut_s1[12];
     /*!< m_radial_power_lut_s2[12] m_RADIAL_POWER_LUT_s2 */
    int32_t m_radial_power_lut_s2[12];
     /*!< m_radial_power_lut_s3[12] m_RADIAL_POWER_LUT_s3 */
    int32_t m_radial_power_lut_s3[12];
     /*!< m_radial_power_lut_v[12] m_RADIAL_POWER_LUT_v */
    int32_t m_radial_power_lut_v[12];
     /*!< m_rxinitial m_RxInitial: Radial  (coordinates of corner) - Initial X [0,m_frame_width-1]  Default=m_frame_width/2 */
    int32_t m_rxinitial;
     /*!< m_rxsqrinitial m_RxSqrInitial: m_RxInitial^2 */
    int32_t m_rxsqrinitial;
     /*!< m_ryinitial m_RyInitial: : Radial  (coordinates of corner) - Initial Y [0,m_frame_height-1]  Default=m_frame_height/2 */
    int32_t m_ryinitial;
     /*!< m_rysqrinitial m_RySqrInitial: m_RyInitial^2 */
    int32_t m_rysqrinitial;
     /*!< m_sad_norm_lut_f1[12] m_SAD_NORM_LUT_f1 */
    int32_t m_sad_norm_lut_f1[12];
     /*!< m_sad_norm_lut_f2[12] m_SAD_NORM_LUT_f2 */
    int32_t m_sad_norm_lut_f2[12];
     /*!< m_sad_norm_lut_s1[12] m_SAD_NORM_LUT_s1 */
    int32_t m_sad_norm_lut_s1[12];
     /*!< m_sad_norm_lut_s2[12] m_SAD_NORM_LUT_s2 */
    int32_t m_sad_norm_lut_s2[12];
     /*!< m_sad_norm_lut_s3[12] m_SAD_NORM_LUT_s3 */
    int32_t m_sad_norm_lut_s3[12];
     /*!< m_sad_norm_lut_v[12] m_SAD_NORM_LUT_v */
    int32_t m_sad_norm_lut_v[12];
     /*!< m_sig_n_detail_lut_f1[10] m_SIG_N_DETAIL_LUT_f1 */
    int32_t m_sig_n_detail_lut_f1[10];
     /*!< m_sig_n_detail_lut_f2[10] m_SIG_N_DETAIL_LUT_f1 */
    int32_t m_sig_n_detail_lut_f2[10];
     /*!< m_sig_n_detail_lut_s1[10] m_SIG_N_DETAIL_LUT_s1 */
    int32_t m_sig_n_detail_lut_s1[10];
     /*!< m_sig_n_detail_lut_s2[10] m_SIG_N_DETAIL_LUT_s2 */
    int32_t m_sig_n_detail_lut_s2[10];
     /*!< m_sig_n_detail_lut_s3[10] m_SIG_N_DETAIL_LUT_s2 */
    int32_t m_sig_n_detail_lut_s3[10];
     /*!< m_sig_n_detail_lut_v[10] m_SIG_N_DETAIL_LUT_v */
    int32_t m_sig_n_detail_lut_v[10];
     /*!< m_sig_n_rad_lut_f1[12] m_SIG_N_RAD_LUT_f1 */
    int32_t m_sig_n_rad_lut_f1[12];
     /*!< m_sig_n_rad_lut_f2[12] m_SIG_N_RAD_LUT_f2 */
    int32_t m_sig_n_rad_lut_f2[12];
     /*!< m_sig_n_rad_lut_s1[12] m_SIG_N_RAD_LUT_s1 */
    int32_t m_sig_n_rad_lut_s1[12];
     /*!< m_sig_n_rad_lut_s2[12] m_SIG_N_RAD_LUT_s2 */
    int32_t m_sig_n_rad_lut_s2[12];
     /*!< m_sig_n_rad_lut_s3[12] m_SIG_N_RAD_LUT_s3 */
    int32_t m_sig_n_rad_lut_s3[12];
     /*!< m_sig_n_rad_lut_v[12] m_SIG_N_RAD_LUT_v */
    int32_t m_sig_n_rad_lut_v[12];
     /*!< m_sve_groups m_SVE_Groups: OBSOLETE */
    int32_t m_sve_groups;
     /*!< m_sve_enable m_SVE_enable: OBSOLETE */
    int32_t m_sve_enable;
     /*!< m_sve_gain[2] m_SVE_gain: OBSOLETE */
    int32_t m_sve_gain[2];
     /*!< m_sve_shift[2] m_SVE_shift: OBSOLETE */
    int32_t m_sve_shift[2];
     /*!< m_signglobal_shift1 m_SigNGlobal_SHIFT1: OBSOLETE */
    int32_t m_signglobal_shift1;
     /*!< m_signglobal_shift2 m_SigNGlobal_SHIFT2: OBSOLETE */
    int32_t m_signglobal_shift2;
     /*!< m_signglobal_sub_flag m_SigNGlobal_SUB_FLAG: OBSOLETE */
    int32_t m_signglobal_sub_flag;
     /*!< m_detailidxshiftleft m_detailIdxShiftLeft: detail index shift left - Dynamic range normalization  Fixed=2  [2:7] */
    int32_t m_detailidxshiftleft;
     /*!< m_matchqualitycands[16] m_matchQualityCands: match quality index weight pick  4X4   alpha0 inputs  (4 canidates [ 0 */
    int32_t m_matchqualitycands[16];
     /*!< m_ncandforavgpixel[4] m_nCandForAvgPixel: number of cands. for average pixel  per detail Type  (15..0)+1  Typically=[16 6 4 6] */
    int32_t m_ncandforavgpixel[4];
     /*!< m_sortth[15] m_sortTh: sort th index set - THs for Pseudo SORT (Const not to be configured) */
    int32_t m_sortth[15];
     /*!< m_statusetopleft m_statUseTopLeft: is top left pixel G/W  (for Bayer start) */
    int32_t m_statusetopleft;
     /*!< m_wmaxminth m_wMaxMinTh: Final TH on Max(Weight) to overright Alpha */
    int32_t m_wmaxminth;
     /*!< m_wsumminth m_wSumMinTh:  Final TH on Sum(Weight) to overright Alpha */
    int32_t m_wsumminth;
     /*!< rad_enable OBSOLETE */
    int32_t rad_enable;

} ia_pal_isp_bxt_bnlm_t; 

/*! \struct bxt_vcud
    
*/
typedef struct 
{
     /*!< bypass Block bypass for HW use */
    int32_t bypass;
     /*!< chm_offset_u U bias */
    int32_t chm_offset_u;
     /*!< chm_offset_v V bias */
    int32_t chm_offset_v;
     /*!< chm_gain gain exponent of chroma metric */
    int32_t chm_gain;
     /*!< lcs_th_low Low Chroma suppression threshold low */
    int32_t lcs_th_low;
     /*!< lcs_th_high Low Chroma suppression threshold high */
    int32_t lcs_th_high;
     /*!< cu_lcs_x_points[6] CU LCS X points */
    int32_t cu_lcs_x_points[6];
     /*!< cu_lcs_y_points[5] CU LCS Y points */
    int32_t cu_lcs_y_points[5];
     /*!< cu_lcs_slopes[5] CU LCS Slopes, Q4 */
    int32_t cu_lcs_slopes[5];
     /*!< cu_noise_x_points[7] CU Noise X points */
    int32_t cu_noise_x_points[7];
     /*!< cu_noise_y_points[6] CU Noise Y points */
    int32_t cu_noise_y_points[6];
     /*!< cu_noise_slopes[6] CU Noise Slopes, Q5 */
    int32_t cu_noise_slopes[6];
     /*!< cu_radial_x_points[6] CU Radial X points */
    int32_t cu_radial_x_points[6];
     /*!< cu_radial_y_points[5] CU Radial Y points */
    int32_t cu_radial_y_points[5];
     /*!< cu_radial_slopes[5] CU Radial Slopes, Q8 */
    int32_t cu_radial_slopes[5];
     /*!< cu_psdiv_lcs_x_points[12] CU psdiv_lcs X points */
    int32_t cu_psdiv_lcs_x_points[12];
     /*!< cu_psdiv_lcs_y_points[11] CU psdiv_lcs Y points */
    int32_t cu_psdiv_lcs_y_points[11];
     /*!< cu_psdiv_lcs_slopes[11] CU psdiv_lcs Slopes, Q10 */
    int32_t cu_psdiv_lcs_slopes[11];
     /*!< cu_psdiv_jbl_x_points[12] CU psdiv_jbl X points */
    int32_t cu_psdiv_jbl_x_points[12];
     /*!< cu_psdiv_jbl_y_points[11] CU psdiv_jbl Y points */
    int32_t cu_psdiv_jbl_y_points[11];
     /*!< cu_psdiv_jbl_slopes[11] CU psdiv_jbl Slopes, Q10 */
    int32_t cu_psdiv_jbl_slopes[11];
     /*!< noise_beta[9] Noise model Beta coefficients */
    int32_t noise_beta[9];
     /*!< lpf_coefs[6] Bilatheral Spatial filter coefficients , Q10, {c0, c3,c4,c6,c7,c8} */
    int32_t lpf_coefs[6];
     /*!< jbl_center_loc JBL center location for noise model */
    int32_t jbl_center_loc;
     /*!< jbl_sigma_y JBL Y noise sigma power, Q6 */
    int32_t jbl_sigma_y;
     /*!< jbl_sigma_u JBL U noise  sigma power, Q6 */
    int32_t jbl_sigma_u;
     /*!< jbl_sigma_v JBL V noise sigma power, Q6 */
    int32_t jbl_sigma_v;
     /*!< jbl_dist_epsilon JBL minmum distance */
    int32_t jbl_dist_epsilon;
     /*!< jbl_noise_epsilon2 JBL minimum noise estimation */
    int32_t jbl_noise_epsilon2;
     /*!< jbl_exp2_min JBL minimum value similarity weight (exp^1/2x^2) */
    int32_t jbl_exp2_min;
     /*!< jbl_weight_th JBL minimum weight threshold */
    int32_t jbl_weight_th;
     /*!< upscale_only_en 0 - VCUD do denoising and duplicate chroma to 4:4:4, 1 - VCUD do only bicubic chroma upsampling to 4:4:4 */
    int32_t upscale_only_en;
     /*!< rad_en Enable Radial parameters */
    int32_t rad_en;
     /*!< rad_x_reset top left pixel X location relative to the optical center point */
    int32_t rad_x_reset;
     /*!< rad_y_reset top left pixel Y location relative to the optical center point */
    int32_t rad_y_reset;
     /*!< rad_x2_reset rad_x_reset * rad_x_reset */
    int32_t rad_x2_reset;
     /*!< rad_y2_reset rad_y_reset * rad_y_reset */
    int32_t rad_y2_reset;
     /*!< rad_nf exponent gain for rad_inv_r2 */
    int32_t rad_nf;
     /*!< rad_inv_r2 1/radius * 2^??? */
    int32_t rad_inv_r2;
     /*!< rad_jbl_sigma_y Radial */
    int32_t rad_jbl_sigma_y;
     /*!< rad_jbl_sigma_u Radial */
    int32_t rad_jbl_sigma_u;
     /*!< rad_jbl_sigma_v Radial */
    int32_t rad_jbl_sigma_v;
     /*!< rad_jbl_dist_epsilon Radial */
    int32_t rad_jbl_dist_epsilon;
     /*!< rad_jbl_noise_epsilon2 Radial */
    int32_t rad_jbl_noise_epsilon2;

} ia_pal_isp_bxt_vcud_t; 

/*! \struct bxt_rynr_collector
    
*/
typedef struct 
{
     /*!< input_pin dummy parameter for HW purpose; 1 - Stills, 0 - Video */
    int32_t input_pin;

} ia_pal_isp_bxt_rynr_collector_t; 

/*! \struct bxt_demosaic
    
*/
typedef struct 
{
     /*!< bypass Block bypass for HW use */
    int32_t bypass;
     /*!< gammasg Sharpening coefficient */
    int32_t gammasg;
     /*!< lcctrl Checkers removal control */
    int32_t lcctrl;
     /*!< crparam1 High frequency denoise param1 */
    int32_t crparam1;
     /*!< crparam2 High frequency denoise param2 */
    int32_t crparam2;
     /*!< coringparam False color correction gain */
    int32_t coringparam;
     /*!< char_en Checkers removal enable */
    int32_t char_en;
     /*!< fcc_en False color correction enable */
    int32_t fcc_en;
     /*!< car_en Chroam artifacts removal enable */
    int32_t car_en;
     /*!< hfar_en High frequency aliasing reduction correction enable */
    int32_t hfar_en;
     /*!< es_enable Edge smoothing enable */
    int32_t es_enable;
     /*!< es_pow Edge smoohing enable. */
    int32_t es_pow;
     /*!< diag_car_trade_off_th Diagonal regions protection param1 */
    int32_t diag_car_trade_off_th;
     /*!< diag_car_trade_off_slope Diagonal regions protection param2 */
    int32_t diag_car_trade_off_slope;
     /*!< stream_ylp_c Coefficient for the YLP for central element of 3x3 neighborhood */
    int32_t stream_ylp_c;
     /*!< stream_ylp_p Coefficient for the YLP for peripheral element of 3x3 neighborhood */
    int32_t stream_ylp_p;
     /*!< stream_ylp_d Coefficient for the YLP for diagonal element of 3x3 neighborhood */
    int32_t stream_ylp_d;
     /*!< stream_ylp_mul_norm Coefficient for multiplier in YLP stream */
    int32_t stream_ylp_mul_norm;
     /*!< stream_ylp_norm_shift Coefficient for YLP stream */
    int32_t stream_ylp_norm_shift;
     /*!< configunitdiag1_x[2] CU_DIAG1 - x input */
    int32_t configunitdiag1_x[2];
     /*!< configunitdiag2_x[2] CU_DIAG2 - x input */
    int32_t configunitdiag2_x[2];
     /*!< configunitdiag3_x[2] CU_DIAG3 - x input */
    int32_t configunitdiag3_x[2];
     /*!< configunitcar_sat_x[2] CU_CAR_SAT - x input */
    int32_t configunitcar_sat_x[2];
     /*!< configunitdiag1_y[1] CU_DIAG1 - y input */
    int32_t configunitdiag1_y[1];
     /*!< configunitdiag1_slope[1] CU_DIAG1 - slope input */
    int32_t configunitdiag1_slope[1];
     /*!< configunitdiag2_y[1] CU_DIAG2 - y input */
    int32_t configunitdiag2_y[1];
     /*!< configunitdiag2_slope[1] CU_DIAG2 - slope input */
    int32_t configunitdiag2_slope[1];
     /*!< configunitdiag3_y[1] CU_DIAG3 - y input */
    int32_t configunitdiag3_y[1];
     /*!< configunitdiag3_slope[1] CU_DIAG3 - slope input */
    int32_t configunitdiag3_slope[1];
     /*!< configunitcar_sat_y[1] CU_CAR_SAT - y input */
    int32_t configunitcar_sat_y[1];
     /*!< configunitcar_sat_slope[1] CU_CAR_SAT - slope input */
    int32_t configunitcar_sat_slope[1];

} ia_pal_isp_bxt_demosaic_t; 

/*! \struct bxt_pixprecadapter_precsc2
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_precsc2_t; 

/*! \struct bxt_csc2
    Color Space Conversion and down-sample to 4:2:0
*/
typedef struct 
{
     /*!< bypass_0_1 Bypass CSC2 */
    int32_t bypass_0_1;
     /*!< use_fir_flag use ani-aliasing filter before decimation */
    int32_t use_fir_flag;
     /*!< rgb2yuv_coef[3] 3 coefs for Y , 1 for U and 1 for V , Q15 */
    int32_t rgb2yuv_coef[3];

} ia_pal_isp_bxt_csc2_t; 

/*! \struct bxt_vcr
    
*/
typedef struct 
{
     /*!< bypass_0_1 Bypass VCR */
    int32_t bypass_0_1;

} ia_pal_isp_bxt_vcr_t; 

/*! \struct bxt_ccm
    
*/
typedef struct 
{
     /*!< bypass block bypass bit */
    int32_t bypass;
     /*!< nb1 offset 1 for the transform */
    int32_t nb1;
     /*!< nb2 offset 2 for the transform */
    int32_t nb2;
     /*!< nb3 offset 3 for the transform */
    int32_t nb3;
     /*!< configuration_matrix[9] ccm configuration matrix precision: S4.11 */
    int32_t configuration_matrix[9];

} ia_pal_isp_bxt_ccm_t; 

/*! \struct bxt_acm
    
*/
typedef struct 
{
     /*!< m_acm_bypass Block bypass for HW use */
    int32_t m_acm_bypass;
     /*!< m_enable_chroma_lut Enable Chroma adaptation by LUT */
    int32_t m_enable_chroma_lut;
     /*!< m_enable_luma_lut Enable Luma adaptation by LUT */
    int32_t m_enable_luma_lut;
     /*!< m_enable_negative_pixels enable negative pixels in output */
    int32_t m_enable_negative_pixels;
     /*!< m_enable_chroma_low_light_mode Enable Chroma adaptation in low light mode */
    int32_t m_enable_chroma_low_light_mode;
     /*!< m_enable_luma_low_light_mode Enable Luma adaptation in low light mode */
    int32_t m_enable_luma_low_light_mode;
     /*!< m_num_of_sectors number of sectors, U5.0 */
    int32_t m_num_of_sectors;
     /*!< m_chromagrid2uniformlut_cu_x[9] U12.0 */
    int32_t m_chromagrid2uniformlut_cu_x[9];
     /*!< m_chromagrid2uniformlut_cu_a[8] S4.10 */
    int32_t m_chromagrid2uniformlut_cu_a[8];
     /*!< m_lumagrid2uniformlut_cu_x[9] U12.0 */
    int32_t m_lumagrid2uniformlut_cu_x[9];
     /*!< m_lumagrid2uniformlut_cu_a[8] S4.10 */
    int32_t m_lumagrid2uniformlut_cu_a[8];
     /*!< m_ccm_matrix_arr[216] CCM's table (one per sector), S3.11 */
    int32_t m_ccm_matrix_arr[216];
     /*!< m_hue_boundary_arr[24] Table of sectors boundaries, U11.0 */
    int32_t m_hue_boundary_arr[24];
     /*!< m_ccm_index_arr[25] Table of the sectors indices, U5.0 */
    int32_t m_ccm_index_arr[25];
     /*!< m_offr CCM bias for R, S13.0 */
    int32_t m_offr;
     /*!< m_offg CCM bias for G, S13.0 */
    int32_t m_offg;
     /*!< m_offb CCM bias for B, S13.0 */
    int32_t m_offb;
     /*!< m_luma_coeff_arr[3] Luna coefficients (weights), U0.8 */
    int32_t m_luma_coeff_arr[3];
     /*!< m_adapt_chroma_lut[81] Chroma adaptation LUT, U2.7 */
    int32_t m_adapt_chroma_lut[81];
     /*!< m_adapt_luma_lut[81] Luma adaptation LUT, S13.0 */
    int32_t m_adapt_luma_lut[81];
     /*!< m_enable_low_light_mode Enable CC's adaptation low light mode */
    int32_t m_enable_low_light_mode;

} ia_pal_isp_bxt_acm_t; 

/*! \struct bxt_gammatm
    
*/
typedef struct 
{
     /*!< enable enable for the filter */
    int32_t enable;
     /*!< gammaBeforeTM order of operations whether Gamma correction should precede TM or vise versa */
    int32_t gammaBeforeTM;
     /*!< a1 shift amount at stage 1 */
    int32_t a1;
     /*!< a2 shift amount at stage 2 */
    int32_t a2;
     /*!< a3 shift amount at stage 3 */
    int32_t a3;
     /*!< gamma_lut_enable enable for gamma lut */
    int32_t gamma_lut_enable;
     /*!< gamma_lut_base_level[5] base level for gamma lut */
    int32_t gamma_lut_base_level[5];
     /*!< gamma_lut_step[5] step for gamma lut */
    int32_t gamma_lut_step[5];
     /*!< gamma_lut_start_bin[5] start bin for gamma lut */
    int32_t gamma_lut_start_bin[5];
     /*!< gamma_lut_size gamma lut size */
    int32_t gamma_lut_size;
     /*!< gamma_lut_gen_lut[385] generalized lut for gamma lut */
    int32_t gamma_lut_gen_lut[385];
     /*!< tm_lut_enable enable for tone mapping lut */
    int32_t tm_lut_enable;
     /*!< tm_lut_base_level[1] base level for  tone mapping lut */
    int32_t tm_lut_base_level[1];
     /*!< tm_lut_step[1] step for  tone mapping lut */
    int32_t tm_lut_step[1];
     /*!< tm_lut_start_bin[1] start bin for  tone mapping lut */
    int32_t tm_lut_start_bin[1];
     /*!< tm_lut_size tone mapping lut size */
    int32_t tm_lut_size;
     /*!< tm_lut_gen_lut[513] generalized lut for tone mapping lut */
    int32_t tm_lut_gen_lut[513];

} ia_pal_isp_bxt_gammatm_t; 

/*! \struct bxt_csc
    
*/
typedef struct 
{
     /*!< m_csc_c_matrix_arr[9] CSC Matrix components (S0.14) */
    int32_t m_csc_c_matrix_arr[9];
     /*!< m_csc_b_vec_arr[3] CSC Vector components (S0.13) */
    int32_t m_csc_b_vec_arr[3];
     /*!< m_chroma_ds_coeff_arr[8] Chroma downsample 4x2 filter coefficients (U2.0) */
    int32_t m_chroma_ds_coeff_arr[8];
     /*!< m_chroma_ds_nf Chroma downsample 4x2 filter normalization factor */
    int32_t m_chroma_ds_nf;
     /*!< m_bypass Bypassing CSC. Outputting RGB to the Chroma downscale */
    int32_t m_bypass;
     /*!< m_uv_bin_output 0 = YUV4:2:0 output, 1 = YUV4:2:2 output */
    int32_t m_uv_bin_output;

} ia_pal_isp_bxt_csc_t; 

/*! \struct sc_iefd
    
*/
typedef struct 
{
     /*!< bypass Block bypass for HW use */
    int32_t bypass;
     /*!< horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal gradient metric */
    int32_t horver_diag_coeff;
     /*!< ed_horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal edge metric */
    int32_t ed_horver_diag_coeff;
     /*!< dir_far_sharp_w Weight of wide kernel direct sharpening */
    int32_t dir_far_sharp_w;
     /*!< dir_far_dns_w Weight of wide kernel direct denoising */
    int32_t dir_far_dns_w;
     /*!< ndir_dns_power Power of non-direct denoising */
    int32_t ndir_dns_power;
     /*!< shrpn_posi_lmt_dir Overshoot limit for edge */
    int32_t shrpn_posi_lmt_dir;
     /*!< shrpn_nega_lmt_dir Undershoot limit for edge */
    int32_t shrpn_nega_lmt_dir;
     /*!< shrpn_posi_lmt_txt Overshoot limit for texture */
    int32_t shrpn_posi_lmt_txt;
     /*!< shrpn_nega_lmt_txt Undershoot limit for texture */
    int32_t shrpn_nega_lmt_txt;
     /*!< clamp_stitch Slope to stitch between clamped and unclamped edge values */
    int32_t clamp_stitch;
     /*!< denoise_en Denoise enable flag */
    int32_t denoise_en;
     /*!< cu6_ndir_shrpn_pwr Power of direct sharpening */
    int32_t cu6_ndir_shrpn_pwr;
     /*!< cuunsharpen_power Power of unsharp-mask sharpening */
    int32_t cuunsharpen_power;
     /*!< unsharp_weight Blending weight between unsharp-mask and direct sharpening */
    int32_t unsharp_weight;
     /*!< unsharp_amount Unsharp-mask extra sharpening power */
    int32_t unsharp_amount;
     /*!< direct_metric_update Update coefficient for direction metric with 2nd direction */
    int32_t direct_metric_update;
     /*!< directional_smooth_en Enable smoothing of best direction with second best direction */
    int32_t directional_smooth_en;
     /*!< rad_enable Enable radial dependency flag */
    int32_t rad_enable;
     /*!< rad_xreset Radial reset of  x (width) */
    int32_t rad_xreset;
     /*!< rad_yreset Radial reset of y (height) */
    int32_t rad_yreset;
     /*!< rad_x2reset Radial reset of x^2 (width^2) */
    int32_t rad_x2reset;
     /*!< rad_y2reset Radial reset of y^2 (height^2) */
    int32_t rad_y2reset;
     /*!< rad_nf Scaling down factor of radius^2 */
    int32_t rad_nf;
     /*!< rad_inv_r2 Normalization factor of inverse of radius^2 */
    int32_t rad_inv_r2;
     /*!< rad_dir_far_sharp_w Weight of wide kernel direct sharpening in the periphery */
    int32_t rad_dir_far_sharp_w;
     /*!< rad_cu6_ndir_shrpn_pwr Power of direct sharpening n the periphery */
    int32_t rad_cu6_ndir_shrpn_pwr;
     /*!< rad_cuun_shrpn_pwr Power of unsharp-mask sharpening in the periphery */
    int32_t rad_cuun_shrpn_pwr;
     /*!< rad_cu6_x1 X1 point of ConfigUnit1 in the periphery */
    int32_t rad_cu6_x1;
     /*!< rad_cuunshrp_x1 X1 point of ConfigUnitUnsharpMask in the periphery */
    int32_t rad_cuunshrp_x1;
     /*!< rad_dir_far_dns_w Weight of wide kernel direct denoising in the periphery */
    int32_t rad_dir_far_dns_w;
     /*!< rad_ndir_dns_power Power of non-direct denoising in the periphery */
    int32_t rad_ndir_dns_power;
     /*!< vssnlm_enable Enable of edge denoising flag */
    int32_t vssnlm_enable;
     /*!< vs_x0 Edge denoising LUT x0 */
    int32_t vs_x0;
     /*!< vs_x1 Edge denoising LUT x1 */
    int32_t vs_x1;
     /*!< vs_x2 Edge denoising LUT x2 */
    int32_t vs_x2;
     /*!< vs_y1 Edge denoising LUT y0 */
    int32_t vs_y1;
     /*!< vs_y2 Edge denoising LUT y1 */
    int32_t vs_y2;
     /*!< vs_y3 Edge denoising LUT y2 */
    int32_t vs_y3;
     /*!< unsharpfilter[15] Unsharp-mask filter coefficients */
    int32_t unsharpfilter[15];
     /*!< denoisefilter[6] Denoising filter coefficients */
    int32_t denoisefilter[6];
     /*!< configunit1_x[2] CU1 x points */
    int32_t configunit1_x[2];
     /*!< configunit1_slope[1] CU1 slope vlaues */
    int32_t configunit1_slope[1];
     /*!< configunit3_x[2] CU3 x points */
    int32_t configunit3_x[2];
     /*!< configunit3_slope[1] CU3 slope vlaues */
    int32_t configunit3_slope[1];
     /*!< configunit5_x[2] CU5 x points */
    int32_t configunit5_x[2];
     /*!< configunit5_y[1] CU5 y points */
    int32_t configunit5_y[1];
     /*!< configunit5_slope[1] CU5 x slope values */
    int32_t configunit5_slope[1];
     /*!< configunit6_opt_x[4] CU6 x points */
    int32_t configunit6_opt_x[4];
     /*!< configunit6_opt_y[3] CU6 y points */
    int32_t configunit6_opt_y[3];
     /*!< configunit6_opt_slope[3] CU6 slope values */
    int32_t configunit6_opt_slope[3];
     /*!< configunit7_x[2] CU7 x points */
    int32_t configunit7_x[2];
     /*!< configunit7_slope[1] CU7 slope vlaues */
    int32_t configunit7_slope[1];
     /*!< configunited_x[6] CU_ED x points */
    int32_t configunited_x[6];
     /*!< configunited_y[5] CU_ED y points */
    int32_t configunited_y[5];
     /*!< configunited_slope[5] CU_ED slope vlaues */
    int32_t configunited_slope[5];
     /*!< configunitunsharp_opt_x[4] CU_UnsharpMask x points */
    int32_t configunitunsharp_opt_x[4];
     /*!< configunitunsharp_opt_y[3] CU_UnsharpMask y points */
    int32_t configunitunsharp_opt_y[3];
     /*!< configunitunsharp_opt_slope[3] CU_UnsharpMask slope vlaues */
    int32_t configunitunsharp_opt_slope[3];
     /*!< configunitradial_x[6] CU_RAD x points */
    int32_t configunitradial_x[6];
     /*!< configunitradial_y[5] CU_RAD y points */
    int32_t configunitradial_y[5];
     /*!< configunitradial_slope[5] CU_RAD slope vlaues */
    int32_t configunitradial_slope[5];
     /*!< configunitvssnlm_x[2] CU_VSSNLM x points */
    int32_t configunitvssnlm_x[2];
     /*!< configunitvssnlm_slope[1] C_VSSNLM slope vlaues */
    int32_t configunitvssnlm_slope[1];

} ia_pal_isp_sc_iefd_t; 

/*! \struct bxt_dvsstatistics
    
*/
typedef struct 
{
     /*!< kappa Global configuration - kappa */
    int32_t kappa;
     /*!< match_shift Global configuration - match_shift */
    int32_t match_shift;
     /*!< ybin_mode Global configuration - y binning mode */
    int32_t ybin_mode;
     /*!< grid_width_l0 DVS statistics grid width level 0 */
    int32_t grid_width_l0;
     /*!< grid_height_l0 DVS statistics grid height level 0 */
    int32_t grid_height_l0;
     /*!< block_width_l0 DVS statistics block width level 0 */
    int32_t block_width_l0;
     /*!< block_height_l0 DVS statistics block height level 0 */
    int32_t block_height_l0;
     /*!< x_start_l0 DVS statistics level 0 x start */
    int32_t x_start_l0;
     /*!< y_start_l0 DVS statistics level 0 y start */
    int32_t y_start_l0;
     /*!< enabled_l0 DVS statistics level 0 enable */
    int32_t enabled_l0;
     /*!< x_end_l0 DVS statistics level 0 x end */
    int32_t x_end_l0;
     /*!< y_end_l0 DVS statistics level 0 y end */
    int32_t y_end_l0;
     /*!< grid_width_l1 DVS statistics grid width level 1 */
    int32_t grid_width_l1;
     /*!< grid_height_l1 DVS statistics grid height level 1 */
    int32_t grid_height_l1;
     /*!< block_width_l1 DVS statistics block width level 1 */
    int32_t block_width_l1;
     /*!< block_height_l1 DVS statistics block height level 1 */
    int32_t block_height_l1;
     /*!< x_start_l1 DVS statistics level 1 x start */
    int32_t x_start_l1;
     /*!< y_start_l1 DVS statistics level 1 y start */
    int32_t y_start_l1;
     /*!< enabled_l1 DVS statistics level 1 enable */
    int32_t enabled_l1;
     /*!< x_end_l1 DVS statistics level 1 x end */
    int32_t x_end_l1;
     /*!< y_end_l1 DVS statistics level 1 y end */
    int32_t y_end_l1;
     /*!< grid_width_l2 DVS statistics grid width level 2 */
    int32_t grid_width_l2;
     /*!< grid_height_l2 DVS statistics grid height level 2 */
    int32_t grid_height_l2;
     /*!< block_width_l2 DVS statistics block width level 2 */
    int32_t block_width_l2;
     /*!< block_height_l2 DVS statistics block height level 2 */
    int32_t block_height_l2;
     /*!< x_start_l2 DVS statistics level 2 x start */
    int32_t x_start_l2;
     /*!< y_start_l2 DVS statistics level 2 y start */
    int32_t y_start_l2;
     /*!< enabled_l2 DVS statistics level 2 enable */
    int32_t enabled_l2;
     /*!< x_end_l2 DVS statistics level 2 x end */
    int32_t x_end_l2;
     /*!< y_end_l2 DVS statistics level 2 y end */
    int32_t y_end_l2;
     /*!< feroi_x_start_l0 DVS statistics fe-roi level 0 x start */
    int32_t feroi_x_start_l0;
     /*!< feroi_y_start_l0 DVS statistics fe-roi level 0 y start */
    int32_t feroi_y_start_l0;
     /*!< feroi_x_end_l0 DVS statistics fe-roi level 0 x end */
    int32_t feroi_x_end_l0;
     /*!< feroi_y_end_l0 DVS statistics fe-roi level 0 y end */
    int32_t feroi_y_end_l0;
     /*!< feroi_x_start_l1 DVS statistics fe-roi level 1 x start */
    int32_t feroi_x_start_l1;
     /*!< feroi_y_start_l1 DVS statistics fe-roi level 1 y start */
    int32_t feroi_y_start_l1;
     /*!< feroi_x_end_l1 DVS statistics fe-roi level 1 x end */
    int32_t feroi_x_end_l1;
     /*!< feroi_y_end_l1 DVS statistics fe-roi level 1 y end */
    int32_t feroi_y_end_l1;
     /*!< feroi_x_start_l2 DVS statistics fe-roi level 2 x start */
    int32_t feroi_x_start_l2;
     /*!< feroi_y_start_l2 DVS statistics fe-roi level 2 y start */
    int32_t feroi_y_start_l2;
     /*!< feroi_x_end_l2 DVS statistics fe-roi level 2 x end */
    int32_t feroi_x_end_l2;
     /*!< feroi_y_end_l2 DVS statistics fe-roi level 2 y end */
    int32_t feroi_y_end_l2;

} ia_pal_isp_bxt_dvsstatistics_t; 

/*! \struct bxt_pixprecadapter_pregdc
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_pregdc_t; 

/*! \struct gdc3
    HW filter reference with FW ISP API
*/
typedef struct 
{
     /*!< filter_size filter size. {4-BCI, 6-Lancos} */
    int32_t filter_size;
     /*!< nums_luts number of LUTs partioning. {1-4} */
    int32_t nums_luts;
     /*!< lut_sel LUT part selection. {0:nums_lut} */
    int32_t lut_sel;
     /*!< lut[1536] LUT s5.10 */
    int32_t lut[1536];
     /*!< interpolation_type interpolation type */
    int32_t interpolation_type;
     /*!< nums_hgrid_luma size of horizontal grig for luma. {} */
    int32_t nums_hgrid_luma;
     /*!< nums_vgrid_luma size of vertical grig for luma. {} */
    int32_t nums_vgrid_luma;
     /*!< nums_hgrid_chroma size of horizontal grig for chroma. {} */
    int32_t nums_hgrid_chroma;
     /*!< nums_vgrid_chroma size of vertical grig for chroma {} */
    int32_t nums_vgrid_chroma;
     /*!< luma_block_width_power luma_block_width_power */
    int32_t luma_block_width_power;
     /*!< luma_block_height_power luma_block_height_power */
    int32_t luma_block_height_power;
     /*!< chroma_block_width_power chroma_block_width_power */
    int32_t chroma_block_width_power;
     /*!< chroma_block_height_power chroma_block_height_power */
    int32_t chroma_block_height_power;
     /*!< luma_origin_x[65025] luma_origin_x */
    int32_t luma_origin_x[65025];
     /*!< luma_origin_y[65025] luma_origin_y */
    int32_t luma_origin_y[65025];
     /*!< luma_in_block_width[65025] luma_in_block_width */
    int32_t luma_in_block_width[65025];
     /*!< luma_in_block_height[65025] luma_in_block_heght */
    int32_t luma_in_block_height[65025];
     /*!< luma_p0_x[65025] luma_p0_x */
    int32_t luma_p0_x[65025];
     /*!< luma_p0_y[65025] luma_p0_y */
    int32_t luma_p0_y[65025];
     /*!< luma_p1_x[65025] luma_p1_x */
    int32_t luma_p1_x[65025];
     /*!< luma_p1_y[65025] luma_p1_y */
    int32_t luma_p1_y[65025];
     /*!< luma_p2_x[65025] luma_p2_x */
    int32_t luma_p2_x[65025];
     /*!< luma_p2_y[65025] luma_p2_y */
    int32_t luma_p2_y[65025];
     /*!< luma_p3_x[65025] luma_p3_x */
    int32_t luma_p3_x[65025];
     /*!< luma_p3_y[65025] luma_p3_y */
    int32_t luma_p3_y[65025];
     /*!< chroma_origin_x[65025] chroma_origin_x */
    int32_t chroma_origin_x[65025];
     /*!< chroma_origin_y[65025] chroma_origin_y */
    int32_t chroma_origin_y[65025];
     /*!< chroma_in_block_width[65025] chroma_in_block_width */
    int32_t chroma_in_block_width[65025];
     /*!< chroma_in_block_height[65025] chroma_in_block_heght */
    int32_t chroma_in_block_height[65025];
     /*!< chroma_p0_x[65025] chroma_p0_x */
    int32_t chroma_p0_x[65025];
     /*!< chroma_p0_y[65025] chroma_p0_y */
    int32_t chroma_p0_y[65025];
     /*!< chroma_p1_x[65025] chroma_p1_x */
    int32_t chroma_p1_x[65025];
     /*!< chroma_p1_y[65025] chroma_p1_y */
    int32_t chroma_p1_y[65025];
     /*!< chroma_p2_x[65025] chroma_p2_x */
    int32_t chroma_p2_x[65025];
     /*!< chroma_p2_y[65025] chroma_p2_y */
    int32_t chroma_p2_y[65025];
     /*!< chroma_p3_x[65025] chroma_p3_x */
    int32_t chroma_p3_x[65025];
     /*!< chroma_p3_y[65025] chroma_p3_y */
    int32_t chroma_p3_y[65025];

} ia_pal_isp_gdc3_t; 

/*! \struct bxt_ofa_mp
    
*/
typedef struct 
{
     /*!< bypass_0_1 Bypass OFA */
    int32_t bypass_0_1;
     /*!< y_tiling tiling parameter for NV12 y_tiled format */
    int32_t y_tiling;
     /*!< pack_mode pack mode for packer */
    int32_t pack_mode;
     /*!< bypass_flip bypass flip */
    int32_t bypass_flip;
     /*!< bypass_mirror bypass mirror */
    int32_t bypass_mirror;
     /*!< bypass_reduced_range bypass reduced range */
    int32_t bypass_reduced_range;
     /*!< p_e[2] Multiplication parameters for pixel with even vertical index */
    int32_t p_e[2];
     /*!< p_o[2] Multiplication parameters for pixel with odd vertical index */
    int32_t p_o[2];

} ia_pal_isp_bxt_ofa_mp_t; 

/*! \struct sc_outputscaler_dp
    
*/
typedef struct 
{
     /*!< bypass bypass the scaler */
    int32_t bypass;
     /*!< block_width Horizontal size of output block */
    int32_t block_width;
     /*!< block_height Vertical size of output block */
    int32_t block_height;
     /*!< chunk_width Horizontal size of input chunk */
    int32_t chunk_width;
     /*!< chunk_height Vertical size of input chunk */
    int32_t chunk_height;
     /*!< input_image_y_start_column AKA "Start column" of the Y plane: support for left croping. Always 0 unless striping mode is applied. */
    int32_t input_image_y_start_column;
     /*!< input_image_uv_start_column AKA "Start column" of the UV plane: support for left croping. Always 0 unless striping mode is applied. */
    int32_t input_image_uv_start_column;
     /*!< in_width_y Width of the input image Y plane (in pixels) */
    int32_t in_width_y;
     /*!< in_height_y Height of the input image Y plane (in pixels) */
    int32_t in_height_y;
     /*!< in_width_uv Width of the input image UV plane (in pixels) */
    int32_t in_width_uv;
     /*!< in_height_uv Height of the input image UV plane (in pixels) */
    int32_t in_height_uv;
     /*!< out_width_y Width of the output image Y plane (in pixels) */
    int32_t out_width_y;
     /*!< out_height_y Height of the output image Y plane (in pixels) */
    int32_t out_height_y;
     /*!< out_width_uv Width of the output image UV plane (in pixels) */
    int32_t out_width_uv;
     /*!< out_height_uv Height of the output image UV plane (in pixels) */
    int32_t out_height_uv;
     /*!< updown_sel Processing mode: 0-bypass. 1-upscale. 2-downscale */
    int32_t updown_sel;
     /*!< coeff_lut_y[128] Polyphase Y look-up table */
    int32_t coeff_lut_y[128];
     /*!< coeff_lut_uv[64] Polyphase U/V look-up table */
    int32_t coeff_lut_uv[64];
     /*!< scaling_ratio AKA "phase_step" - defines up- or downscaling factor. For up-scaling minimum is 682 and for down scaling minimum is 171. maximum is for both 2048. */
    int32_t scaling_ratio;
     /*!< phase_init_y_top Starting phase of polyphase Y filter on top image boundary */
    int32_t phase_init_y_top;
     /*!< phase_init_y_left Starting phase of polyphase Y filter on left image boundary */
    int32_t phase_init_y_left;
     /*!< phase_init_uv_top Starting phase of polyphase U/V filter on top image boundary */
    int32_t phase_init_uv_top;
     /*!< phase_init_uv_left Starting phase of polyphase U/V filter on left image boundary */
    int32_t phase_init_uv_left;
     /*!< pad_left_y Image left padding: Y component */
    int32_t pad_left_y;
     /*!< pad_left_uv Image left padding: U/V components */
    int32_t pad_left_uv;
     /*!< pad_right_y Image right padding: Y component */
    int32_t pad_right_y;
     /*!< pad_right_uv Image right padding: U/V components */
    int32_t pad_right_uv;
     /*!< pad_top_y Image top padding: Y component */
    int32_t pad_top_y;
     /*!< pad_top_uv Image top padding: U/V components */
    int32_t pad_top_uv;
     /*!< pad_bttm_y Image bottom padding: Y component */
    int32_t pad_bttm_y;
     /*!< pad_bttm_uv Image bottom padding: U/V components */
    int32_t pad_bttm_uv;
     /*!< exp_shift Scaling filter coefficients exponent shift */
    int32_t exp_shift;
     /*!< output0_out_y_left_crop Left cropping of filter output Y plane */
    int32_t output0_out_y_left_crop;
     /*!< output0_out_uv_left_crop Left cropping of filter output U/V planes */
    int32_t output0_out_uv_left_crop;
     /*!< output0_out_y_top_crop Top cropping of filter output Y plane */
    int32_t output0_out_y_top_crop;
     /*!< output0_out_uv_top_crop Top cropping of filter output U/V planes */
    int32_t output0_out_uv_top_crop;

} ia_pal_isp_sc_outputscaler_dp_t; 

/*! \struct sc_outputscaler_ppp
    
*/
typedef struct 
{
     /*!< bypass bypass the scaler */
    int32_t bypass;
     /*!< block_width Horizontal size of output block */
    int32_t block_width;
     /*!< block_height Vertical size of output block */
    int32_t block_height;
     /*!< chunk_width Horizontal size of input chunk */
    int32_t chunk_width;
     /*!< chunk_height Vertical size of input chunk */
    int32_t chunk_height;
     /*!< input_image_y_start_column AKA "Start column" of the Y plane: support for left croping. Always 0 unless striping mode is applied. */
    int32_t input_image_y_start_column;
     /*!< input_image_uv_start_column AKA "Start column" of the UV plane: support for left croping. Always 0 unless striping mode is applied. */
    int32_t input_image_uv_start_column;
     /*!< in_width_y Width of the input image Y plane (in pixels) */
    int32_t in_width_y;
     /*!< in_height_y Height of the input image Y plane (in pixels) */
    int32_t in_height_y;
     /*!< in_width_uv Width of the input image UV plane (in pixels) */
    int32_t in_width_uv;
     /*!< in_height_uv Height of the input image UV plane (in pixels) */
    int32_t in_height_uv;
     /*!< out_width_y Width of the output image Y plane (in pixels) */
    int32_t out_width_y;
     /*!< out_height_y Height of the output image Y plane (in pixels) */
    int32_t out_height_y;
     /*!< out_width_uv Width of the output image UV plane (in pixels) */
    int32_t out_width_uv;
     /*!< out_height_uv Height of the output image UV plane (in pixels) */
    int32_t out_height_uv;
     /*!< updown_sel Processing mode: 0-bypass. 1-upscale. 2-downscale */
    int32_t updown_sel;
     /*!< coeff_lut_y[128] Polyphase Y look-up table */
    int32_t coeff_lut_y[128];
     /*!< coeff_lut_uv[64] Polyphase U/V look-up table */
    int32_t coeff_lut_uv[64];
     /*!< scaling_ratio AKA "phase_step" - defines up- or downscaling factor. For up-scaling minimum is 682 and for down scaling minimum is 171. maximum is for both 2048. */
    int32_t scaling_ratio;
     /*!< phase_init_y_top Starting phase of polyphase Y filter on top image boundary */
    int32_t phase_init_y_top;
     /*!< phase_init_y_left Starting phase of polyphase Y filter on left image boundary */
    int32_t phase_init_y_left;
     /*!< phase_init_uv_top Starting phase of polyphase U/V filter on top image boundary */
    int32_t phase_init_uv_top;
     /*!< phase_init_uv_left Starting phase of polyphase U/V filter on left image boundary */
    int32_t phase_init_uv_left;
     /*!< pad_left_y Image left padding: Y component */
    int32_t pad_left_y;
     /*!< pad_left_uv Image left padding: U/V components */
    int32_t pad_left_uv;
     /*!< pad_right_y Image right padding: Y component */
    int32_t pad_right_y;
     /*!< pad_right_uv Image right padding: U/V components */
    int32_t pad_right_uv;
     /*!< pad_top_y Image top padding: Y component */
    int32_t pad_top_y;
     /*!< pad_top_uv Image top padding: U/V components */
    int32_t pad_top_uv;
     /*!< pad_bttm_y Image bottom padding: Y component */
    int32_t pad_bttm_y;
     /*!< pad_bttm_uv Image bottom padding: U/V components */
    int32_t pad_bttm_uv;
     /*!< exp_shift Scaling filter coefficients exponent shift */
    int32_t exp_shift;
     /*!< output0_out_y_left_crop Left cropping of filter output Y plane */
    int32_t output0_out_y_left_crop;
     /*!< output0_out_uv_left_crop Left cropping of filter output U/V planes */
    int32_t output0_out_uv_left_crop;
     /*!< output0_out_y_top_crop Top cropping of filter output Y plane */
    int32_t output0_out_y_top_crop;
     /*!< output0_out_uv_top_crop Top cropping of filter output U/V planes */
    int32_t output0_out_uv_top_crop;

} ia_pal_isp_sc_outputscaler_ppp_t; 

/*! \struct bxt_ofa_dp
    
*/
typedef struct 
{
     /*!< bypass_0_1 Bypass OFA */
    int32_t bypass_0_1;
     /*!< y_tiling tiling parameter for NV12 y_tiled format */
    int32_t y_tiling;
     /*!< pack_mode pack mode for packer */
    int32_t pack_mode;
     /*!< bypass_flip bypass flip */
    int32_t bypass_flip;
     /*!< bypass_mirror bypass mirror */
    int32_t bypass_mirror;
     /*!< bypass_reduced_range bypass reduced range */
    int32_t bypass_reduced_range;
     /*!< p_e[2] Multiplication parameters for pixel with even vertical index */
    int32_t p_e[2];
     /*!< p_o[2] Multiplication parameters for pixel with odd vertical index */
    int32_t p_o[2];

} ia_pal_isp_bxt_ofa_dp_t; 

/*! \struct bxt_ofa_ppp
    
*/
typedef struct 
{
     /*!< bypass_0_1 Bypass OFA */
    int32_t bypass_0_1;
     /*!< y_tiling tiling parameter for NV12 y_tiled format */
    int32_t y_tiling;
     /*!< pack_mode pack mode for packer */
    int32_t pack_mode;
     /*!< bypass_flip bypass flip */
    int32_t bypass_flip;
     /*!< bypass_mirror bypass mirror */
    int32_t bypass_mirror;
     /*!< bypass_reduced_range bypass reduced range */
    int32_t bypass_reduced_range;
     /*!< p_e[2] Multiplication parameters for pixel with even vertical index */
    int32_t p_e[2];
     /*!< p_o[2] Multiplication parameters for pixel with odd vertical index */
    int32_t p_o[2];

} ia_pal_isp_bxt_ofa_ppp_t; 

/*! \struct sc_chromaupsample
    
*/
typedef struct 
{
     /*!< m_bypass Block Bypass. 1: Block bypassed output is 4:2:0    0: Block Enabled. Works according to m_upsamplemode */
    int32_t m_bypass;
     /*!< m_upsamplemode Upsamples mode to: 0- 4:2:2,  1- 4:4:4,  2- 4:2:0 */
    int32_t m_upsamplemode;
     /*!< m_dsmode Resampling mode for 4:2:0: relevant if (m_upsamplemode == 2).  DS was: mpeg1{1}, mpeg2{2} */
    int32_t m_dsmode;
     /*!< m_sw_mode Should be 0 in case of HW (IPU4 is HW) SW/GEN upsample: Disable{0}, Bicubic{1}, Lanczos3{2} */
    int32_t m_sw_mode;
     /*!< p_ee_444[4] U5.0 - Multiplication parameters for pixel with even vertical and even horizontal index */
    int32_t p_ee_444[4];
     /*!< p_eo_444[4] U5.0 - Multiplication parameters for pixel with even vertical and odd horizontal index */
    int32_t p_eo_444[4];
     /*!< p_oe_444[4] U5.0 - Multiplication parameters for pixel with odd vertical and even horizontal index */
    int32_t p_oe_444[4];
     /*!< p_oo_444[4] U5.0 - Multiplication parameters for pixel with odd vertical and odd horizontal index */
    int32_t p_oo_444[4];
     /*!< p_e_422[2] U3.0 - Multiplication parameters for pixel with even vertical index */
    int32_t p_e_422[2];
     /*!< p_o_422[2] U3.0 - Multiplication parameters for pixel with odd vertical index */
    int32_t p_o_422[2];
     /*!< p_r_420[5] S9.0 - 4:2:0 Interpolation parameters */
    int32_t p_r_420[5];

} ia_pal_isp_sc_chromaupsample_t; 

/*! \struct sc_rgbconversion
    
*/
typedef struct 
{
     /*!< bypass bypass */
    int32_t bypass;
     /*!< nb1 B1 [-8191, 8191] */
    int32_t nb1;
     /*!< nb2 B2 [-8191, 8191] */
    int32_t nb2;
     /*!< nb3 B3 [-8191, 8191] */
    int32_t nb3;
     /*!< rgb2yuv[9] conversion matrix U3.8 */
    int32_t rgb2yuv[9];

} ia_pal_isp_sc_rgbconversion_t; 

/*! \struct bxt_mirror
    
*/
typedef struct 
{
     /*!< m_bypass Bypass        {0,1} */
    int32_t m_bypass;

} ia_pal_isp_bxt_mirror_t; 

/*! \struct bxt_reducerange
    
*/
typedef struct 
{
     /*!< m_bypass Bypass        {0,1} */
    int32_t m_bypass;

} ia_pal_isp_bxt_reducerange_t; 

/*! \struct sc_packer
    
*/
typedef struct 
{
     /*!< m_bypass Bypass [0,1] */
    int32_t m_bypass;
     /*!< m_packmode Packing mode NV12(0), NV21(1), I420(2), M240(3), YV12(4), NV12Tiled(5), YUY2(6), NV16(8), BGRA(9), RGBA(10), Y Tile RGBA(11) Y Tile YUY2(12) */
    int32_t m_packmode;
     /*!< m_alpha Alpha Factor FIXME: Put correct max and default values */
    int32_t m_alpha;
     /*!< m_tiling Tiling mode No tiling (0), Y tiling (1), YF tiling (2) */
    int32_t m_tiling;

} ia_pal_isp_sc_packer_t; 

/*! \struct bxt_dpcm
    
*/
typedef struct 
{
     /*!< first_pix_res first pixel resolution */
    int32_t first_pix_res;
     /*!< bypass block bypass bit */
    int32_t bypass;
     /*!< code[6] The codes array */
    int32_t code[6];
     /*!< codethr[5] The threshold for using the next code */
    int32_t codethr[5];
     /*!< codemask[6] Used for extracting the code from the coded word */
    int32_t codemask[6];
     /*!< valuemask[6] Used for extracting the value from the coded word */
    int32_t valuemask[6];
     /*!< signmask[6] Used for extracting the sign from the coded word */
    int32_t signmask[6];
     /*!< lowresthrnum Code threshold for lower resolution coding */
    int32_t lowresthrnum;
     /*!< decode 0=encode, 1=decode */
    int32_t decode;

} ia_pal_isp_bxt_dpcm_t; 

/*! \struct bxt_pafstatistics
    
*/
typedef struct 
{
     /*!< paf_en 0: FF will not write to the PAF  array; 1: FF will write */
    int32_t paf_en;
     /*!< skip_horizontal_start number of skipped PAF pixel pairs at the start of each line pair */
    int32_t skip_horizontal_start;
     /*!< skip_vertical_start number of skipped PAF line pairs at the start of the frame */
    int32_t skip_vertical_start;
     /*!< block_width number of PAF pixel pairs per block in horizontal direction */
    int32_t block_width;
     /*!< block_height number of PAF pixel pairs per block in vertical direction */
    int32_t block_height;
     /*!< accum_horizontal number of consecutive PAF pixel pairs accumulated in horizontal direction */
    int32_t accum_horizontal;
     /*!< skip_horizontal number of PAF pixel pairs skipped between accumulated pixel pairs in horizontal direction */
    int32_t skip_horizontal;
     /*!< accum_vertical number of consecutive PAF pixel pairs accumulated in vertical direction */
    int32_t accum_vertical;
     /*!< skip_vertical number of PAF line pairs skipped between accumulated pixel pairs in vertical direction */
    int32_t skip_vertical;
     /*!< min_shift minimum evaluation shift in steps */
    int32_t min_shift;
     /*!< shift_steps number of evaluation points, starting from m_paf_min_shift */
    int32_t shift_steps;
     /*!< paf_shift_step_size phase evaluation step size in pixels */
    int32_t paf_shift_step_size;
     /*!< paf_shifter configured so that the accumulated phase difference fits in the output register */
    int32_t paf_shifter;
     /*!< split_accross_multiple_lines 0: SOP = SOL, EOP = EOL; 1: SOF determined by the reset, EOL determined by pixels per line */
    int32_t split_accross_multiple_lines;
     /*!< pixels_per_line number of pixels per line */
    int32_t pixels_per_line;
     /*!< input_modes 0: RRRR + LLLL; 1: LLLL + RRRR; 2: RLRL; 3: LRLR */
    int32_t input_modes;
     /*!< input_bpp 0: 8 bits; 1: 10 bits; 2: 12 bits; 3: 14 bits; 4: 16 bits */
    int32_t input_bpp;
     /*!< int_prec internal precition of PAF pixels */
    int32_t int_prec;

} ia_pal_isp_bxt_pafstatistics_t; 

/*! \struct bxt_vcr2
    
*/
typedef struct 
{
     /*!< bypass_0_1 Bypass VCR2 */
    int32_t bypass_0_1;
     /*!< input_format_420 0 - input 4:4:4 , 1 - input 4:2:0 */
    int32_t input_format_420;
     /*!< lpf_p0_c0 Phase 0 - coef 0 */
    int32_t lpf_p0_c0;
     /*!< lpf_p0_c1 Phase 0 - coef 1 */
    int32_t lpf_p0_c1;
     /*!< lpf_p0_c2 Phase 0 - coef 2 */
    int32_t lpf_p0_c2;
     /*!< lpf_p0_c3 Phase 0 - coef 3 */
    int32_t lpf_p0_c3;
     /*!< lpf_p1_c0 Phase 1 - coef 0 */
    int32_t lpf_p1_c0;
     /*!< lpf_p1_c1 Phase 1 - coef 1 */
    int32_t lpf_p1_c1;
     /*!< lpf_p1_c2 Phase 1 - coef 2 */
    int32_t lpf_p1_c2;
     /*!< lpf_p1_c3 Phase 1 - coef 3 */
    int32_t lpf_p1_c3;

} ia_pal_isp_bxt_vcr2_t; 

/*! \struct bxt_inputscalerv2
    
*/
typedef struct 
{
     /*!< block_bypass block bypass bit. Note that in ATE this parameters is "bypass" (0 - enable. 1 - disable) while in HW it is "enable" (0 - bypass. 1 - enable).
In case block_bypass = 1, demo_bypass and scaler_bypass will turn to 1. */
    int32_t block_bypass;
     /*!< demo_bypass demosaic bypass bit.  Note that in ATE this parameters is "bypass" (0 - enable. 1 - disable) while in HW it is "enable" (0 - bypass. 1 - enable). */
    int32_t demo_bypass;
     /*!< scaler_bypass scaler bypass bit.  Note that in ATE this parameters is "bypass" (0 - enable. 1 - disable) while in HW it is "enable" (0 - bypass. 1 - enable). */
    int32_t scaler_bypass;
     /*!< vnumerator Vertical   SF Numerator */
    int32_t vnumerator;
     /*!< hnumerator Horizontal SF Numerator */
    int32_t hnumerator;
     /*!< vdenominator Vertical   SF Denominator */
    int32_t vdenominator;
     /*!< hdenominator Horizontal SF Denominator */
    int32_t hdenominator;
     /*!< norm_mul Normalization multiply coeffiecient */
    int32_t norm_mul;
     /*!< norm_shift Normalization shift */
    int32_t norm_shift;
     /*!< output_sensor_mode Output Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode. */
    int32_t output_sensor_mode;
     /*!< output_format_matrix[16] Output format matrix [4,4]. 0=R. 1=G. 2=G. 3=W */
    int32_t output_format_matrix[16];
     /*!< Input_Frame_Width Input frame width. Has to be a multiple of 4. */
    int32_t Input_Frame_Width;
     /*!< input_is_bayer 0 - Bayer, 1 - RGBC */
    int32_t input_is_bayer;
     /*!< output_height Has to be a multiple of 4. */
    int32_t output_height;
     /*!< output_width Better be a mutiplication of 32 to avoid RTL zero padding (?). When block is stationed in isla (isla=on) then maximum is 2560. Has to be a multiple of 4. */
    int32_t output_width;
     /*!< shift_to_lb Shifting before LB */
    int32_t shift_to_lb;
     /*!< input_sensor_mode Input Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode. */
    int32_t input_sensor_mode;
     /*!< is_ul_w Is the first pixel in frame G/W 1-true, 0-false */
    int32_t is_ul_w;
     /*!< bayer_type Bayer Type - BGGR(0), RGGB(1), GRBG(2), GBRG(3) */
    int32_t bayer_type;
     /*!< lut_values[16] QNN LUT - Values. Restriction - rising monotonic. */
    int32_t lut_values[16];
     /*!< lut_shifts1[16] QNN LUT - Shift1. lut_shift2 >= lut_shift1. */
    int32_t lut_shifts1[16];
     /*!< lut_shifts2[16] QNN LUT - Shift2. lut_shift2 >= lut_shift1. */
    int32_t lut_shifts2[16];
     /*!< lut_subtraction_flags[16] QNN LUT - Flags */
    int32_t lut_subtraction_flags[16];
     /*!< lut_output_values[16] QNN LUT - Output Values */
    int32_t lut_output_values[16];
     /*!< kernel_g_coef[6] G kernel - Coefs */
    int32_t kernel_g_coef[6];
     /*!< kernel_g_norm File for G kernel - Norm */
    int32_t kernel_g_norm;
     /*!< cbf_div_cu_x[12] Config unit division - X points */
    int32_t cbf_div_cu_x[12];
     /*!< cbf_div_cu_y[11] Config unit division - Y points */
    int32_t cbf_div_cu_y[11];
     /*!< cbf_div_cu_slope[11] Config unit division - Slopes */
    int32_t cbf_div_cu_slope[11];
     /*!< cbi_r_pos[96] .CBI R Positions. Valid range {0-17} */
    int32_t cbi_r_pos[96];
     /*!< cbi_r_wgt[96] CBI R Weights. Valid range: {0-4 , 7} */
    int32_t cbi_r_wgt[96];
     /*!< cbi_g_pos[96] CBI G Positions. Valid range {0-17}. Not used in Bayer (only in RGBC). */
    int32_t cbi_g_pos[96];
     /*!< cbi_g_wgt[96] CBI G Weights. Valid range {0-4 , 7}. Not used in Bayer (only in RGBC). */
    int32_t cbi_g_wgt[96];
     /*!< cbi_b_pos[96] CBI B Positions. Valid range {0-17} */
    int32_t cbi_b_pos[96];
     /*!< cbi_b_wgt[96] CBI B Weights. Valid range {0-4 , 7} */
    int32_t cbi_b_wgt[96];
     /*!< wb_matrix[16] Matrix[4][4] for WB. 0=no gain. 1=R. 2=B. 3=G. (in each quad must use at least two zeros (no gain)). */
    int32_t wb_matrix[16];
     /*!< r_wb_gain WB R gain. 4096 is equal to gain 1. */
    int32_t r_wb_gain;
     /*!< g_wb_gain WB G gain. 4096 is equal to gain 1. */
    int32_t g_wb_gain;
     /*!< b_wb_gain WB B gain. 4096 is equal to gain 1. */
    int32_t b_wb_gain;
     /*!< g_min_r_en Enable "G-R" mode */
    int32_t g_min_r_en;

} ia_pal_isp_bxt_inputscalerv2_t; 

/*! \struct bxt_convert16sto8u
    
*/
typedef struct 
{
     /*!< m_bypass Bypass     {0,1} */
    int32_t m_bypass;

} ia_pal_isp_bxt_convert16sto8u_t; 

/*! \struct bxt_pixprecadapter
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_t; 

/*! \struct bxt_flip
    
*/
typedef struct 
{
     /*!< m_bypass Bypass        {0,1} */
    int32_t m_bypass;

} ia_pal_isp_bxt_flip_t; 

/*! \struct bxt_shift14to16bit
    
*/
typedef struct 
{
     /*!< m_bypass Bypass        {0,1} */
    int32_t m_bypass;
     /*!< m_shiftmode Shift : 14To16(0), 16To14(1) */
    int32_t m_shiftmode;
     /*!< m_isbayer Is Bayer? - Bayer(0) RGB(1) */
    int32_t m_isbayer;

} ia_pal_isp_bxt_shift14to16bit_t; 

/*! \struct sc_ylpf
    
*/
typedef struct 
{
     /*!< m_bypass Block Bypass. Must be set to 0 for operatinal mode */
    int32_t m_bypass;
     /*!< m_vec_kernels[8] configuration DS kernel vector */
    int32_t m_vec_kernels[8];
     /*!< m_decimationmode decimationMode{0.m444,1.m422,2.m420} */
    int32_t m_decimationmode;

} ia_pal_isp_sc_ylpf_t; 

/*! \struct sc_iefd_v2
    
*/
typedef struct 
{
     /*!< bypass Block bypass for HW use */
    int32_t bypass;
     /*!< horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal gradient metric */
    int32_t horver_diag_coeff;
     /*!< ed_horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal edge metric */
    int32_t ed_horver_diag_coeff;
     /*!< dir_far_sharp_w Weight of wide kernel direct sharpening */
    int32_t dir_far_sharp_w;
     /*!< dir_far_dns_w Weight of wide kernel direct denoising */
    int32_t dir_far_dns_w;
     /*!< ndir_dns_power Power of non-direct denoising */
    int32_t ndir_dns_power;
     /*!< shrpn_posi_lmt_dir Overshoot limit for edge */
    int32_t shrpn_posi_lmt_dir;
     /*!< shrpn_nega_lmt_dir Undershoot limit for edge */
    int32_t shrpn_nega_lmt_dir;
     /*!< shrpn_posi_lmt_txt Overshoot limit for texture */
    int32_t shrpn_posi_lmt_txt;
     /*!< shrpn_nega_lmt_txt Undershoot limit for texture */
    int32_t shrpn_nega_lmt_txt;
     /*!< clamp_stitch Slope to stitch between clamped and unclamped edge values */
    int32_t clamp_stitch;
     /*!< denoise_en Denoise enable flag */
    int32_t denoise_en;
     /*!< cu6_ndir_shrpn_pwr Power of direct sharpening */
    int32_t cu6_ndir_shrpn_pwr;
     /*!< cuunsharpen_power Power of unsharp-mask sharpening */
    int32_t cuunsharpen_power;
     /*!< unsharp_weight Blending weight between unsharp-mask and direct sharpening */
    int32_t unsharp_weight;
     /*!< unsharp_amount Unsharp-mask extra sharpening power */
    int32_t unsharp_amount;
     /*!< direct_metric_update Update coefficient for direction metric with 2nd direction */
    int32_t direct_metric_update;
     /*!< directional_smooth_en Enable smoothing of best direction with second best direction */
    int32_t directional_smooth_en;
     /*!< rad_enable Enable radial dependency flag */
    int32_t rad_enable;
     /*!< rad_xreset Radial reset of  x (width) */
    int32_t rad_xreset;
     /*!< rad_yreset Radial reset of y (height) */
    int32_t rad_yreset;
     /*!< rad_x2reset Radial reset of x^2 (width^2) */
    int32_t rad_x2reset;
     /*!< rad_y2reset Radial reset of y^2 (height^2) */
    int32_t rad_y2reset;
     /*!< rad_nf Scaling down factor of radius^2 */
    int32_t rad_nf;
     /*!< rad_inv_r2 Normalization factor of inverse of radius^2 */
    int32_t rad_inv_r2;
     /*!< rad_dir_far_sharp_w Weight of wide kernel direct sharpening in the periphery */
    int32_t rad_dir_far_sharp_w;
     /*!< rad_cu6_ndir_shrpn_pwr Power of direct sharpening n the periphery */
    int32_t rad_cu6_ndir_shrpn_pwr;
     /*!< rad_cuun_shrpn_pwr Power of unsharp-mask sharpening in the periphery */
    int32_t rad_cuun_shrpn_pwr;
     /*!< rad_cu6_x1 X1 point of ConfigUnit1 in the periphery */
    int32_t rad_cu6_x1;
     /*!< rad_cuunshrp_x1 X1 point of ConfigUnitUnsharpMask in the periphery */
    int32_t rad_cuunshrp_x1;
     /*!< rad_dir_far_dns_w Weight of wide kernel direct denoising in the periphery */
    int32_t rad_dir_far_dns_w;
     /*!< rad_ndir_dns_power Power of non-direct denoising in the periphery */
    int32_t rad_ndir_dns_power;
     /*!< vssnlm_enable Enable of edge denoising flag */
    int32_t vssnlm_enable;
     /*!< vs_x0 Edge denoising LUT x0 */
    int32_t vs_x0;
     /*!< vs_x1 Edge denoising LUT x1 */
    int32_t vs_x1;
     /*!< vs_x2 Edge denoising LUT x2 */
    int32_t vs_x2;
     /*!< vs_y1 Edge denoising LUT y0 */
    int32_t vs_y1;
     /*!< vs_y2 Edge denoising LUT y1 */
    int32_t vs_y2;
     /*!< vs_y3 Edge denoising LUT y2 */
    int32_t vs_y3;
     /*!< unsharpfilter[15] Unsharp-mask filter coefficients */
    int32_t unsharpfilter[15];
     /*!< denoisefilter[6] Denoising filter coefficients */
    int32_t denoisefilter[6];
     /*!< configunit1_x[2] CU1 x points */
    int32_t configunit1_x[2];
     /*!< configunit1_slope CU1 slope values */
    int32_t configunit1_slope;
     /*!< configunit3_x[2] CU3 x points */
    int32_t configunit3_x[2];
     /*!< configunit3_slope CU3 slope values */
    int32_t configunit3_slope;
     /*!< configunit5_x[2] CU5 x points */
    int32_t configunit5_x[2];
     /*!< configunit5_y CU5 y points */
    int32_t configunit5_y;
     /*!< configunit5_slope CU5 x slope values */
    int32_t configunit5_slope;
     /*!< configunit6_opt_x[4] CU6 x points */
    int32_t configunit6_opt_x[4];
     /*!< configunit6_opt_y[3] CU6 y points */
    int32_t configunit6_opt_y[3];
     /*!< configunit6_opt_slope[3] CU6 slope values */
    int32_t configunit6_opt_slope[3];
     /*!< configunit7_x[2] CU7 x points */
    int32_t configunit7_x[2];
     /*!< configunit7_slope CU7 slope vlaues */
    int32_t configunit7_slope;
     /*!< configunited_x[6] CU_ED x points */
    int32_t configunited_x[6];
     /*!< configunited_y[5] CU_ED y points */
    int32_t configunited_y[5];
     /*!< configunited_slope[5] CU_ED slope values */
    int32_t configunited_slope[5];
     /*!< configunitunsharp_opt_x[4] CU_UnsharpMask x points */
    int32_t configunitunsharp_opt_x[4];
     /*!< configunitunsharp_opt_y[3] CU_UnsharpMask y points */
    int32_t configunitunsharp_opt_y[3];
     /*!< configunitunsharp_opt_slope[3] CU_UnsharpMask slope values */
    int32_t configunitunsharp_opt_slope[3];
     /*!< configunitradial_x[6] CU_RAD x points */
    int32_t configunitradial_x[6];
     /*!< configunitradial_y[5] CU_RAD y points */
    int32_t configunitradial_y[5];
     /*!< configunitradial_slope[5] CU_RAD slope values */
    int32_t configunitradial_slope[5];
     /*!< configunitvssnlm_x[2] CU_VSSNLM x points */
    int32_t configunitvssnlm_x[2];
     /*!< configunitvssnlm_slope CU_VSSNLM slope values */
    int32_t configunitvssnlm_slope;
     /*!< configunitusmpownorm_x[6] CU_USM_POW x points */
    int32_t configunitusmpownorm_x[6];
     /*!< configunitusmpownorm_y[5] CU_USM_POW y points */
    int32_t configunitusmpownorm_y[5];
     /*!< configunitusmpownorm_slope[5] CU_USM_POW slope values */
    int32_t configunitusmpownorm_slope[5];
     /*!< unsharpmet Enable gradient protection */
    int32_t unsharpmet;
     /*!< gradth Threshold for zeroing derivative */
    int32_t gradth;

} ia_pal_isp_sc_iefd_v2_t; 

/*! \struct bxt_gdc_reference
    first  filter in pipe HW/FW combined
*/
typedef struct 
{
     /*!< Bypass Bypass{0,1} */
    int32_t Bypass;
     /*!< enable_coords_log Enable log output. {0,1} */
    int32_t enable_coords_log;
     /*!< nums_lut number of LUTs partioning. {} */
    int32_t nums_lut;
     /*!< LUT[1536] LUT s5.10 */
    int32_t LUT[1536];
     /*!< nums_Hgrid_luma size of horizontal grig for luma. {} */
    int32_t nums_Hgrid_luma;
     /*!< nums_Vgrid_luma size of vertical grig for luma. {} */
    int32_t nums_Vgrid_luma;
     /*!< nums_Hgrid_chroma size of horizontal grig for chroma. {} */
    int32_t nums_Hgrid_chroma;
     /*!< nums_Vgrid_chroma size of vertical grig for chroma {} */
    int32_t nums_Vgrid_chroma;
     /*!< h_coords_luma[65536] horizontal luma coordinates. s23.8 */
    int32_t h_coords_luma[65536];
     /*!< v_coords_luma[65536] vertical luma coordinates. s23.8 */
    int32_t v_coords_luma[65536];
     /*!< h_coords_chroma[65536] horizontal chroma coordinates. s23.8 */
    int32_t h_coords_chroma[65536];
     /*!< v_coords_chroma[65536] vertical chroma coordinates. s23.8 */
    int32_t v_coords_chroma[65536];

} ia_pal_isp_bxt_gdc_reference_t; 

/*! \struct bxt_xnr4_mh
    Scalable Chroma and Luma Denoise, Medium and High Frequency
*/
typedef struct 
{
     /*!< jbl_mf_bypass_y Bypass JBL MF Luma */
    int32_t jbl_mf_bypass_y;
     /*!< jbl_mf_bypass_c Bypass MF Chroma */
    int32_t jbl_mf_bypass_c;
     /*!< noise_sigma_mf_y_y Noise Sigma MF Luma per Luma */
    int32_t noise_sigma_mf_y_y;
     /*!< noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration */
    int32_t noise_sigma_mf_y_s;
     /*!< noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma */
    int32_t noise_sigma_mf_c_y;
     /*!< noise_sigma_mf_c_u Noise Sigma MF Chroma per U */
    int32_t noise_sigma_mf_c_u;
     /*!< noise_sigma_mf_c_v Noise Sigma MF Chroma per V */
    int32_t noise_sigma_mf_c_v;
     /*!< rad_noise_sigma_mf_y_y Noise Sigma MF Luma per Luma - radial */
    int32_t rad_noise_sigma_mf_y_y;
     /*!< rad_noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration - radial */
    int32_t rad_noise_sigma_mf_y_s;
     /*!< rad_noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma - radial */
    int32_t rad_noise_sigma_mf_c_y;
     /*!< rad_noise_sigma_mf_c_u Noise Sigma MF Chroma per U - radial */
    int32_t rad_noise_sigma_mf_c_u;
     /*!< rad_noise_sigma_mf_c_v Noise Sigma MF Chroma per V - radial */
    int32_t rad_noise_sigma_mf_c_v;
     /*!< noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 */
    int32_t noise_epsilon_mf_y_y;
     /*!< noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 */
    int32_t noise_epsilon_mf_c_y;
     /*!< noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 */
    int32_t noise_epsilon_mf_c_u;
     /*!< noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 */
    int32_t noise_epsilon_mf_c_v;
     /*!< rad_noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 - radial */
    int32_t rad_noise_epsilon_mf_y_y;
     /*!< rad_noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_y;
     /*!< rad_noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_u;
     /*!< rad_noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_v;
     /*!< jbl_weight_th_mf_y Luma Weight threshold of MF JBL */
    int32_t jbl_weight_th_mf_y;
     /*!< jbl_weight_th_mf_c Chroma Weight threshold of MF JBL */
    int32_t jbl_weight_th_mf_c;
     /*!< lpf_mf_coef_y[49] MF JBL Spatial coefs for Luma */
    int32_t lpf_mf_coef_y[49];
     /*!< lpf_mf_coef_c[49] MF JBL Spatial coefs for Chroma */
    int32_t lpf_mf_coef_c[49];
     /*!< range_weight_lut[7] JBL range Weight LUT */
    int32_t range_weight_lut[7];
     /*!< blend_mf_power_y MF denoise blending power y */
    int32_t blend_mf_power_y;
     /*!< blend_mf_power_c MF denoise blending power chroma */
    int32_t blend_mf_power_c;
     /*!< rad_blend_mf_power_y MF denoise blending power y - radial */
    int32_t rad_blend_mf_power_y;
     /*!< rad_blend_mf_power_c MF denoise blending power chroma -radial */
    int32_t rad_blend_mf_power_c;
     /*!< noise_beta_y_0 noise model for y - coef 0, Q12 */
    int32_t noise_beta_y_0;
     /*!< noise_beta_u_0 noise model for u - coef 0, Q12 */
    int32_t noise_beta_u_0;
     /*!< noise_beta_u_1 noise model for u - coef 1, Q12 */
    int32_t noise_beta_u_1;
     /*!< noise_beta_v_0 noise model for v - coef 0, Q12 */
    int32_t noise_beta_v_0;
     /*!< noise_beta_v_2 noise model for v - coef 2, Q12 */
    int32_t noise_beta_v_2;
     /*!< rad_center_x X location of the radial center location relative to the top left pixel */
    int32_t rad_center_x;
     /*!< rad_center_y Y location of the radial center location relative to the top left pixel */
    int32_t rad_center_y;
     /*!< rad_exp Radial scale bit into the Lut */
    int32_t rad_exp;
     /*!< rad_lut[128] Radial LUT */
    int32_t rad_lut[128];
     /*!< one_div_64_lut[64] 1/SQRT(x), first 64 values LUT */
    int32_t one_div_64_lut[64];
     /*!< xcu_divsqrt_exp XCU divsqrt exponent */
    int32_t xcu_divsqrt_exp;
     /*!< xcu_divsqrt_slp_a_res XCU divsqrt slope precision */
    int32_t xcu_divsqrt_slp_a_res;
     /*!< xcu_divsqrt_offset[16] XCU divsqrt offset(y) vector */
    int32_t xcu_divsqrt_offset[16];
     /*!< xcu_divsqrt_slope[16] XCU divsqrt slope vector */
    int32_t xcu_divsqrt_slope[16];
     /*!< xcu_divsqrt_x[17] XCU divsqrt x points vector + maximal x value */
    int32_t xcu_divsqrt_x[17];
     /*!< jbl_hf_bypass_c Bypass HF Chroma */
    int32_t jbl_hf_bypass_c;
     /*!< noise_sigma_hf_c_y Noise Sigma HF Chroma per Luma */
    int32_t noise_sigma_hf_c_y;
     /*!< noise_sigma_hf_c_u Noise Sigma HF Chroma per U */
    int32_t noise_sigma_hf_c_u;
     /*!< noise_sigma_hf_c_v Noise Sigma HF Chroma per V */
    int32_t noise_sigma_hf_c_v;
     /*!< rad_noise_sigma_hf_c_y Noise Sigma HF Chroma per Luma - radial */
    int32_t rad_noise_sigma_hf_c_y;
     /*!< rad_noise_sigma_hf_c_u Noise Sigma HF Chroma per U - radial */
    int32_t rad_noise_sigma_hf_c_u;
     /*!< rad_noise_sigma_hf_c_v Noise Sigma HF Chroma per V - radial */
    int32_t rad_noise_sigma_hf_c_v;
     /*!< noise_epsilon_hf_c_y Chroma min noise variance per Luma , Q12 */
    int32_t noise_epsilon_hf_c_y;
     /*!< noise_epsilon_hf_c_u Chroma min noise variance per U , Q12 */
    int32_t noise_epsilon_hf_c_u;
     /*!< noise_epsilon_hf_c_v Chroma min noise variance per V , Q12 */
    int32_t noise_epsilon_hf_c_v;
     /*!< rad_noise_epsilon_hf_c_y Chroma min noise variance per Luma , Q12 - radial */
    int32_t rad_noise_epsilon_hf_c_y;
     /*!< rad_noise_epsilon_hf_c_u Chroma min noise variance per U , Q12 -radial */
    int32_t rad_noise_epsilon_hf_c_u;
     /*!< rad_noise_epsilon_hf_c_v Chroma min noise variance per V , Q12 -radial */
    int32_t rad_noise_epsilon_hf_c_v;
     /*!< lpf_hf_coef_c[49] HF JBL Spatial coefs for Chroma */
    int32_t lpf_hf_coef_c[49];
     /*!< jbl_weight_th_hf_c Chroma Weight threshold of HF JBL */
    int32_t jbl_weight_th_hf_c;
     /*!< lcs_th_low Low Chroma Suppertion threshold for black level */
    int32_t lcs_th_low;
     /*!< lcs_th_high_delta Low Chroma Suppertion threshold for white level (delta from black) */
    int32_t lcs_th_high_delta;
     /*!< rad_lcs_th_low Low Chroma Suppertion threshold for black level - radial (delta from low) */
    int32_t rad_lcs_th_low;
     /*!< rad_lcs_th_high_delta Low Chroma Suppertion threshold for white level -radial (delta form high delta) */
    int32_t rad_lcs_th_high_delta;
     /*!< xcu_lcs_exp XCU ed exponent */
    int32_t xcu_lcs_exp;
     /*!< xcu_lcs_slp_a_res XCU ed slope precision */
    int32_t xcu_lcs_slp_a_res;
     /*!< xcu_lcs_offset[32] XCU ed offset(y) vector */
    int32_t xcu_lcs_offset[32];
     /*!< xcu_lcs_slope[32] XCU ed slope vector */
    int32_t xcu_lcs_slope[32];
     /*!< xcu_lcs_x[33] XCU ed x points vector + maximal x value */
    int32_t xcu_lcs_x[33];
     /*!< nncu_hf_luma_blend_exp NNCU HF Luma blend  exponent */
    int32_t nncu_hf_luma_blend_exp;
     /*!< nncu_hf_luma_blend_offset[64] NNCU HF Luma blend offset vector */
    int32_t nncu_hf_luma_blend_offset[64];
     /*!< nncu_hf_luma_blend_x_0 NNCU HF Luma blend first X cordinate */
    int32_t nncu_hf_luma_blend_x_0;
     /*!< nncu_hf_luma_blend_x_max NNCU HF Luma blend last X cordinate ( the #65 corrdinate -1) */
    int32_t nncu_hf_luma_blend_x_max;
     /*!< hf_luma_power HF Luma denoise power, Q15 */
    int32_t hf_luma_power;
     /*!< rad_hf_luma_power HF Luma denoise power, Q15 -radial */
    int32_t rad_hf_luma_power;
     /*!< blend_hf_power_c blend_mf_power_c HF denoise blending power chroma */
    int32_t blend_hf_power_c;

} ia_pal_isp_bxt_xnr4_mh_t; 

/*! \struct bxt_pixprecadapter_prewb
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_prewb_t; 

/*! \struct bxt_pixprecadapter_postvcr
    
*/
typedef struct 
{
     /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixinprec;
     /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixoutprec;
     /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter */
    int32_t m_pixminprec;
     /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1) */
    int32_t m_isbayer;
     /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned */
    int32_t m_cliptous;
     /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL */
    int32_t m_shiftlen;
     /*!< m_shiftval Shift Value {0..7} */
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_postvcr_t; 

/*! \struct bxt_inputscaler_a0
    
*/
typedef struct 
{
     /*!< hnumerator  */
    int32_t hnumerator;
     /*!< vnumerator  */
    int32_t vnumerator;
     /*!< hdenominator  */
    int32_t hdenominator;
     /*!< vdenominator  */
    int32_t vdenominator;
     /*!< norm_mul  */
    int32_t norm_mul;
     /*!< norm_shift  */
    int32_t norm_shift;
     /*!< shift_to_lb  */
    int32_t shift_to_lb;
     /*!< output_width  */
    int32_t output_width;
     /*!< output_height  */
    int32_t output_height;
     /*!< input_width  */
    int32_t input_width;
     /*!< output_format_matrix[16]  */
    int32_t output_format_matrix[16];
     /*!< output_sensor_mode  */
    int32_t output_sensor_mode;
     /*!< input_sensor_mode  */
    int32_t input_sensor_mode;
     /*!< demosaic_en  */
    int32_t demosaic_en;
     /*!< box_en  */
    int32_t box_en;
     /*!< scaler_en  */
    int32_t scaler_en;
     /*!< input_is_bayer  */
    int32_t input_is_bayer;
     /*!< is_ul_w  */
    int32_t is_ul_w;
     /*!< first_w  */
    int32_t first_w;
     /*!< ConfigTable_Types_EID0_W_Type  */
    int32_t ConfigTable_Types_EID0_W_Type;
     /*!< ConfigTable_WReg_EID0_Data[6]  */
    int32_t ConfigTable_WReg_EID0_Data[6];
     /*!< ConfigTable_Types_EID1_W_Type  */
    int32_t ConfigTable_Types_EID1_W_Type;
     /*!< ConfigTable_WReg_EID1_Data[6]  */
    int32_t ConfigTable_WReg_EID1_Data[6];
     /*!< ConfigTable_Types_EID2_W_Type  */
    int32_t ConfigTable_Types_EID2_W_Type;
     /*!< ConfigTable_WReg_EID2_Data[6]  */
    int32_t ConfigTable_WReg_EID2_Data[6];
     /*!< ConfigTable_Types_EID3_W_Type  */
    int32_t ConfigTable_Types_EID3_W_Type;
     /*!< ConfigTable_WReg_EID3_Data[6]  */
    int32_t ConfigTable_WReg_EID3_Data[6];
     /*!< ConfigTable_Types_EID4_W_Type  */
    int32_t ConfigTable_Types_EID4_W_Type;
     /*!< ConfigTable_WReg_EID4_Data[6]  */
    int32_t ConfigTable_WReg_EID4_Data[6];
     /*!< ConfigTable_Types_EID5_W_Type  */
    int32_t ConfigTable_Types_EID5_W_Type;
     /*!< ConfigTable_WReg_EID5_Data[6]  */
    int32_t ConfigTable_WReg_EID5_Data[6];
     /*!< ConfigTable_Types_EID6_W_Type  */
    int32_t ConfigTable_Types_EID6_W_Type;
     /*!< ConfigTable_WReg_EID6_Data[6]  */
    int32_t ConfigTable_WReg_EID6_Data[6];
     /*!< ConfigTable_Types_EID7_W_Type  */
    int32_t ConfigTable_Types_EID7_W_Type;
     /*!< ConfigTable_WReg_EID7_Data[6]  */
    int32_t ConfigTable_WReg_EID7_Data[6];
     /*!< ConfigTable_Types_EID8_W_Type  */
    int32_t ConfigTable_Types_EID8_W_Type;
     /*!< ConfigTable_WReg_EID8_Data[6]  */
    int32_t ConfigTable_WReg_EID8_Data[6];
     /*!< ConfigTable_Types_EID9_W_Type  */
    int32_t ConfigTable_Types_EID9_W_Type;
     /*!< ConfigTable_WReg_EID9_Data[6]  */
    int32_t ConfigTable_WReg_EID9_Data[6];
     /*!< ConfigTable_Types_EID10_W_Type  */
    int32_t ConfigTable_Types_EID10_W_Type;
     /*!< ConfigTable_WReg_EID10_Data[6]  */
    int32_t ConfigTable_WReg_EID10_Data[6];
     /*!< ConfigTable_Types_EID11_W_Type  */
    int32_t ConfigTable_Types_EID11_W_Type;
     /*!< ConfigTable_WReg_EID11_Data[6]  */
    int32_t ConfigTable_WReg_EID11_Data[6];
     /*!< ConfigTable_Types_EID12_W_Type  */
    int32_t ConfigTable_Types_EID12_W_Type;
     /*!< ConfigTable_WReg_EID12_Data[6]  */
    int32_t ConfigTable_WReg_EID12_Data[6];
     /*!< ConfigTable_Types_EID13_W_Type  */
    int32_t ConfigTable_Types_EID13_W_Type;
     /*!< ConfigTable_WReg_EID13_Data[6]  */
    int32_t ConfigTable_WReg_EID13_Data[6];
     /*!< ConfigTable_Types_EID14_W_Type  */
    int32_t ConfigTable_Types_EID14_W_Type;
     /*!< ConfigTable_WReg_EID14_Data[6]  */
    int32_t ConfigTable_WReg_EID14_Data[6];
     /*!< ConfigTable_Types_EID15_W_Type  */
    int32_t ConfigTable_Types_EID15_W_Type;
     /*!< ConfigTable_WReg_EID15_Data[6]  */
    int32_t ConfigTable_WReg_EID15_Data[6];
     /*!< ConfigTable_Types_EID0_G_Type  */
    int32_t ConfigTable_Types_EID0_G_Type;
     /*!< ConfigTable_GReg_EID0_Data[35]  */
    int32_t ConfigTable_GReg_EID0_Data[35];
     /*!< ConfigTable_Types_EID1_G_Type  */
    int32_t ConfigTable_Types_EID1_G_Type;
     /*!< ConfigTable_GReg_EID1_Data[35]  */
    int32_t ConfigTable_GReg_EID1_Data[35];
     /*!< ConfigTable_Types_EID2_G_Type  */
    int32_t ConfigTable_Types_EID2_G_Type;
     /*!< ConfigTable_GReg_EID2_Data[35]  */
    int32_t ConfigTable_GReg_EID2_Data[35];
     /*!< ConfigTable_Types_EID3_G_Type  */
    int32_t ConfigTable_Types_EID3_G_Type;
     /*!< ConfigTable_GReg_EID3_Data[35]  */
    int32_t ConfigTable_GReg_EID3_Data[35];
     /*!< ConfigTable_Types_EID4_G_Type  */
    int32_t ConfigTable_Types_EID4_G_Type;
     /*!< ConfigTable_GReg_EID4_Data[35]  */
    int32_t ConfigTable_GReg_EID4_Data[35];
     /*!< ConfigTable_Types_EID5_G_Type  */
    int32_t ConfigTable_Types_EID5_G_Type;
     /*!< ConfigTable_GReg_EID5_Data[35]  */
    int32_t ConfigTable_GReg_EID5_Data[35];
     /*!< ConfigTable_Types_EID6_G_Type  */
    int32_t ConfigTable_Types_EID6_G_Type;
     /*!< ConfigTable_GReg_EID6_Data[35]  */
    int32_t ConfigTable_GReg_EID6_Data[35];
     /*!< ConfigTable_Types_EID7_G_Type  */
    int32_t ConfigTable_Types_EID7_G_Type;
     /*!< ConfigTable_GReg_EID7_Data[35]  */
    int32_t ConfigTable_GReg_EID7_Data[35];
     /*!< ConfigTable_Types_EID8_G_Type  */
    int32_t ConfigTable_Types_EID8_G_Type;
     /*!< ConfigTable_GReg_EID8_Data[35]  */
    int32_t ConfigTable_GReg_EID8_Data[35];
     /*!< ConfigTable_Types_EID9_G_Type  */
    int32_t ConfigTable_Types_EID9_G_Type;
     /*!< ConfigTable_GReg_EID9_Data[35]  */
    int32_t ConfigTable_GReg_EID9_Data[35];
     /*!< ConfigTable_Types_EID10_G_Type  */
    int32_t ConfigTable_Types_EID10_G_Type;
     /*!< ConfigTable_GReg_EID10_Data[35]  */
    int32_t ConfigTable_GReg_EID10_Data[35];
     /*!< ConfigTable_Types_EID11_G_Type  */
    int32_t ConfigTable_Types_EID11_G_Type;
     /*!< ConfigTable_GReg_EID11_Data[35]  */
    int32_t ConfigTable_GReg_EID11_Data[35];
     /*!< ConfigTable_Types_EID12_G_Type  */
    int32_t ConfigTable_Types_EID12_G_Type;
     /*!< ConfigTable_GReg_EID12_Data[35]  */
    int32_t ConfigTable_GReg_EID12_Data[35];
     /*!< ConfigTable_Types_EID13_G_Type  */
    int32_t ConfigTable_Types_EID13_G_Type;
     /*!< ConfigTable_GReg_EID13_Data[35]  */
    int32_t ConfigTable_GReg_EID13_Data[35];
     /*!< ConfigTable_Types_EID14_G_Type  */
    int32_t ConfigTable_Types_EID14_G_Type;
     /*!< ConfigTable_GReg_EID14_Data[35]  */
    int32_t ConfigTable_GReg_EID14_Data[35];
     /*!< ConfigTable_Types_EID15_G_Type  */
    int32_t ConfigTable_Types_EID15_G_Type;
     /*!< ConfigTable_GReg_EID15_Data[35]  */
    int32_t ConfigTable_GReg_EID15_Data[35];
     /*!< ConfigTable_Types_EID0_R_Type  */
    int32_t ConfigTable_Types_EID0_R_Type;
     /*!< ConfigTable_RReg_EID0_Data[35]  */
    int32_t ConfigTable_RReg_EID0_Data[35];
     /*!< ConfigTable_Types_EID1_R_Type  */
    int32_t ConfigTable_Types_EID1_R_Type;
     /*!< ConfigTable_RReg_EID1_Data[35]  */
    int32_t ConfigTable_RReg_EID1_Data[35];
     /*!< ConfigTable_Types_EID2_R_Type  */
    int32_t ConfigTable_Types_EID2_R_Type;
     /*!< ConfigTable_RReg_EID2_Data[35]  */
    int32_t ConfigTable_RReg_EID2_Data[35];
     /*!< ConfigTable_Types_EID3_R_Type  */
    int32_t ConfigTable_Types_EID3_R_Type;
     /*!< ConfigTable_RReg_EID3_Data[35]  */
    int32_t ConfigTable_RReg_EID3_Data[35];
     /*!< ConfigTable_Types_EID4_R_Type  */
    int32_t ConfigTable_Types_EID4_R_Type;
     /*!< ConfigTable_RReg_EID4_Data[35]  */
    int32_t ConfigTable_RReg_EID4_Data[35];
     /*!< ConfigTable_Types_EID5_R_Type  */
    int32_t ConfigTable_Types_EID5_R_Type;
     /*!< ConfigTable_RReg_EID5_Data[35]  */
    int32_t ConfigTable_RReg_EID5_Data[35];
     /*!< ConfigTable_Types_EID6_R_Type  */
    int32_t ConfigTable_Types_EID6_R_Type;
     /*!< ConfigTable_RReg_EID6_Data[35]  */
    int32_t ConfigTable_RReg_EID6_Data[35];
     /*!< ConfigTable_Types_EID7_R_Type  */
    int32_t ConfigTable_Types_EID7_R_Type;
     /*!< ConfigTable_RReg_EID7_Data[35]  */
    int32_t ConfigTable_RReg_EID7_Data[35];
     /*!< ConfigTable_Types_EID8_R_Type  */
    int32_t ConfigTable_Types_EID8_R_Type;
     /*!< ConfigTable_RReg_EID8_Data[35]  */
    int32_t ConfigTable_RReg_EID8_Data[35];
     /*!< ConfigTable_Types_EID9_R_Type  */
    int32_t ConfigTable_Types_EID9_R_Type;
     /*!< ConfigTable_RReg_EID9_Data[35]  */
    int32_t ConfigTable_RReg_EID9_Data[35];
     /*!< ConfigTable_Types_EID10_R_Type  */
    int32_t ConfigTable_Types_EID10_R_Type;
     /*!< ConfigTable_RReg_EID10_Data[35]  */
    int32_t ConfigTable_RReg_EID10_Data[35];
     /*!< ConfigTable_Types_EID11_R_Type  */
    int32_t ConfigTable_Types_EID11_R_Type;
     /*!< ConfigTable_RReg_EID11_Data[35]  */
    int32_t ConfigTable_RReg_EID11_Data[35];
     /*!< ConfigTable_Types_EID12_R_Type  */
    int32_t ConfigTable_Types_EID12_R_Type;
     /*!< ConfigTable_RReg_EID12_Data[35]  */
    int32_t ConfigTable_RReg_EID12_Data[35];
     /*!< ConfigTable_Types_EID13_R_Type  */
    int32_t ConfigTable_Types_EID13_R_Type;
     /*!< ConfigTable_RReg_EID13_Data[35]  */
    int32_t ConfigTable_RReg_EID13_Data[35];
     /*!< ConfigTable_Types_EID14_R_Type  */
    int32_t ConfigTable_Types_EID14_R_Type;
     /*!< ConfigTable_RReg_EID14_Data[35]  */
    int32_t ConfigTable_RReg_EID14_Data[35];
     /*!< ConfigTable_Types_EID15_R_Type  */
    int32_t ConfigTable_Types_EID15_R_Type;
     /*!< ConfigTable_RReg_EID15_Data[35]  */
    int32_t ConfigTable_RReg_EID15_Data[35];
     /*!< ConfigTable_Types_EID0_B_Type  */
    int32_t ConfigTable_Types_EID0_B_Type;
     /*!< ConfigTable_BReg_EID0_Data[35]  */
    int32_t ConfigTable_BReg_EID0_Data[35];
     /*!< ConfigTable_Types_EID1_B_Type  */
    int32_t ConfigTable_Types_EID1_B_Type;
     /*!< ConfigTable_BReg_EID1_Data[35]  */
    int32_t ConfigTable_BReg_EID1_Data[35];
     /*!< ConfigTable_Types_EID2_B_Type  */
    int32_t ConfigTable_Types_EID2_B_Type;
     /*!< ConfigTable_BReg_EID2_Data[35]  */
    int32_t ConfigTable_BReg_EID2_Data[35];
     /*!< ConfigTable_Types_EID3_B_Type  */
    int32_t ConfigTable_Types_EID3_B_Type;
     /*!< ConfigTable_BReg_EID3_Data[35]  */
    int32_t ConfigTable_BReg_EID3_Data[35];
     /*!< ConfigTable_Types_EID4_B_Type  */
    int32_t ConfigTable_Types_EID4_B_Type;
     /*!< ConfigTable_BReg_EID4_Data[35]  */
    int32_t ConfigTable_BReg_EID4_Data[35];
     /*!< ConfigTable_Types_EID5_B_Type  */
    int32_t ConfigTable_Types_EID5_B_Type;
     /*!< ConfigTable_BReg_EID5_Data[35]  */
    int32_t ConfigTable_BReg_EID5_Data[35];
     /*!< ConfigTable_Types_EID6_B_Type  */
    int32_t ConfigTable_Types_EID6_B_Type;
     /*!< ConfigTable_BReg_EID6_Data[35]  */
    int32_t ConfigTable_BReg_EID6_Data[35];
     /*!< ConfigTable_Types_EID7_B_Type  */
    int32_t ConfigTable_Types_EID7_B_Type;
     /*!< ConfigTable_BReg_EID7_Data[35]  */
    int32_t ConfigTable_BReg_EID7_Data[35];
     /*!< ConfigTable_Types_EID8_B_Type  */
    int32_t ConfigTable_Types_EID8_B_Type;
     /*!< ConfigTable_BReg_EID8_Data[35]  */
    int32_t ConfigTable_BReg_EID8_Data[35];
     /*!< ConfigTable_Types_EID9_B_Type  */
    int32_t ConfigTable_Types_EID9_B_Type;
     /*!< ConfigTable_BReg_EID9_Data[35]  */
    int32_t ConfigTable_BReg_EID9_Data[35];
     /*!< ConfigTable_Types_EID10_B_Type  */
    int32_t ConfigTable_Types_EID10_B_Type;
     /*!< ConfigTable_BReg_EID10_Data[35]  */
    int32_t ConfigTable_BReg_EID10_Data[35];
     /*!< ConfigTable_Types_EID11_B_Type  */
    int32_t ConfigTable_Types_EID11_B_Type;
     /*!< ConfigTable_BReg_EID11_Data[35]  */
    int32_t ConfigTable_BReg_EID11_Data[35];
     /*!< ConfigTable_Types_EID12_B_Type  */
    int32_t ConfigTable_Types_EID12_B_Type;
     /*!< ConfigTable_BReg_EID12_Data[35]  */
    int32_t ConfigTable_BReg_EID12_Data[35];
     /*!< ConfigTable_Types_EID13_B_Type  */
    int32_t ConfigTable_Types_EID13_B_Type;
     /*!< ConfigTable_BReg_EID13_Data[35]  */
    int32_t ConfigTable_BReg_EID13_Data[35];
     /*!< ConfigTable_Types_EID14_B_Type  */
    int32_t ConfigTable_Types_EID14_B_Type;
     /*!< ConfigTable_BReg_EID14_Data[35]  */
    int32_t ConfigTable_BReg_EID14_Data[35];
     /*!< ConfigTable_Types_EID15_B_Type  */
    int32_t ConfigTable_Types_EID15_B_Type;
     /*!< ConfigTable_BReg_EID15_Data[35]  */
    int32_t ConfigTable_BReg_EID15_Data[35];
     /*!< ConfigTable_Types_EID16_B_Type  */
    int32_t ConfigTable_Types_EID16_B_Type;
     /*!< ConfigTable_BReg_EID16_Data[35]  */
    int32_t ConfigTable_BReg_EID16_Data[35];
     /*!< ConfigTable_Types_EID17_B_Type  */
    int32_t ConfigTable_Types_EID17_B_Type;
     /*!< ConfigTable_BReg_EID17_Data[35]  */
    int32_t ConfigTable_BReg_EID17_Data[35];
     /*!< ConfigTable_Types_EID18_B_Type  */
    int32_t ConfigTable_Types_EID18_B_Type;
     /*!< ConfigTable_BReg_EID18_Data[35]  */
    int32_t ConfigTable_BReg_EID18_Data[35];
     /*!< ConfigTable_Types_EID19_B_Type  */
    int32_t ConfigTable_Types_EID19_B_Type;
     /*!< ConfigTable_BReg_EID19_Data[35]  */
    int32_t ConfigTable_BReg_EID19_Data[35];
     /*!< ConfigTable_Types_EID20_B_Type  */
    int32_t ConfigTable_Types_EID20_B_Type;
     /*!< ConfigTable_BReg_EID20_Data[35]  */
    int32_t ConfigTable_BReg_EID20_Data[35];
     /*!< ConfigTable_Types_EID21_B_Type  */
    int32_t ConfigTable_Types_EID21_B_Type;
     /*!< ConfigTable_BReg_EID21_Data[35]  */
    int32_t ConfigTable_BReg_EID21_Data[35];

} ia_pal_isp_bxt_inputscaler_a0_t; 

/*! \struct bxt_demosaic_a0
    
*/
typedef struct 
{
     /*!< bypass Color Artifact removal flag */
    int32_t bypass;
     /*!< gammasg  */
    int32_t gammasg;
     /*!< lcctrl Parameter that controls weights of Chroma Homogeneity metric in calculation of final homogeneity metric. */
    int32_t lcctrl;
     /*!< crparam1 First Parameter that defines Checker artifact removal feature gain. */
    int32_t crparam1;
     /*!< crparam2 Second Parameter that defines Checker artifact removal feature gain. */
    int32_t crparam2;
     /*!< coringparam Defines power of false color correction operation. */
    int32_t coringparam;
     /*!< char_en Checker artifacts removal enable flag */
    int32_t char_en;
     /*!< fcc_en FCC enable flag */
    int32_t fcc_en;

} ia_pal_isp_bxt_demosaic_a0_t; 

/*! \struct bxt_bitcomp_a0
    
*/
typedef struct 
{
     /*!< lut_size  */
    int32_t lut_size;
     /*!< bc_enable  */
    int32_t bc_enable;
     /*!< lut[256]  */
    int32_t lut[256];
     /*!< base_level1  */
    int32_t base_level1;
     /*!< step_size1  */
    int32_t step_size1;
     /*!< start_bin1  */
    int32_t start_bin1;
     /*!< base_level2  */
    int32_t base_level2;
     /*!< step_size2  */
    int32_t step_size2;
     /*!< start_bin2  */
    int32_t start_bin2;
     /*!< base_level3  */
    int32_t base_level3;
     /*!< step_size3  */
    int32_t step_size3;
     /*!< start_bin3  */
    int32_t start_bin3;
     /*!< base_level4  */
    int32_t base_level4;
     /*!< step_size4  */
    int32_t step_size4;
     /*!< start_bin4  */
    int32_t start_bin4;
     /*!< base_level5  */
    int32_t base_level5;
     /*!< step_size5  */
    int32_t step_size5;
     /*!< start_bin5  */
    int32_t start_bin5;
     /*!< base_level6  */
    int32_t base_level6;
     /*!< step_size6  */
    int32_t step_size6;
     /*!< start_bin6  */
    int32_t start_bin6;
     /*!< base_level7  */
    int32_t base_level7;
     /*!< step_size7  */
    int32_t step_size7;
     /*!< start_bin7  */
    int32_t start_bin7;
     /*!< base_level8  */
    int32_t base_level8;
     /*!< step_size8  */
    int32_t step_size8;
     /*!< start_bin8  */
    int32_t start_bin8;

} ia_pal_isp_bxt_bitcomp_a0_t; 

/*! \struct bxt_bitdecomp_a0
    
*/
typedef struct 
{
     /*!< lut_size  */
    int32_t lut_size;
     /*!< bdc_en  */
    int32_t bdc_en;
     /*!< lut[256]  */
    int32_t lut[256];
     /*!< base_level1  */
    int32_t base_level1;
     /*!< step_size1  */
    int32_t step_size1;
     /*!< start_bin1  */
    int32_t start_bin1;
     /*!< base_level2  */
    int32_t base_level2;
     /*!< step_size2  */
    int32_t step_size2;
     /*!< start_bin2  */
    int32_t start_bin2;
     /*!< base_level3  */
    int32_t base_level3;
     /*!< step_size3  */
    int32_t step_size3;
     /*!< start_bin3  */
    int32_t start_bin3;
     /*!< base_level4  */
    int32_t base_level4;
     /*!< step_size4  */
    int32_t step_size4;
     /*!< start_bin4  */
    int32_t start_bin4;
     /*!< base_level5  */
    int32_t base_level5;
     /*!< step_size5  */
    int32_t step_size5;
     /*!< start_bin5  */
    int32_t start_bin5;
     /*!< base_level6  */
    int32_t base_level6;
     /*!< step_size6  */
    int32_t step_size6;
     /*!< start_bin6  */
    int32_t start_bin6;
     /*!< base_level7  */
    int32_t base_level7;
     /*!< step_size7  */
    int32_t step_size7;
     /*!< start_bin7  */
    int32_t start_bin7;
     /*!< base_level8  */
    int32_t base_level8;
     /*!< step_size8  */
    int32_t step_size8;
     /*!< start_bin8  */
    int32_t start_bin8;

} ia_pal_isp_bxt_bitdecomp_a0_t; 

/*! \struct bxt_tnr5v1
    
*/
typedef struct 
{
     /*!< nm_luma_lut[64] Noise model LUMA lut (for I core) */
    int32_t nm_luma_lut[64];
     /*!< nm_chroma_lut[64] Noise model Chroma LUT (for I core) */
    int32_t nm_chroma_lut[64];
     /*!< nm_spnr_lut[64] Noise model LUMA lut, for II core, beem used by spNR */
    int32_t nm_spnr_lut[64];
     /*!< nm_radial_lut[128] Noise model radial Lut */
    int32_t nm_radial_lut[128];
     /*!< nm_radial_r2_shift Noise model radial shift */
    int32_t nm_radial_r2_shift;
     /*!< nm_radial_x_center Noise model radial- center of image x corr */
    int32_t nm_radial_x_center;
     /*!< nm_radial_y_center Noise model radial- center of image y corr */
    int32_t nm_radial_y_center;
     /*!< co_max_content maximal value for the content */
    int32_t co_max_content;
     /*!< co_content_shift shift right for content */
    int32_t co_content_shift;
     /*!< fm_sim_lut[64] FMVE Similarity LUT for grade calculation */
    int32_t fm_sim_lut[64];
     /*!< fm_dist_weights[128] FMVE distance weight for the tow BMA unit */
    int32_t fm_dist_weights[128];
     /*!< fm_sad_shift shift for the SAD values in the FMVE sub-block (using realigning) */
    int32_t fm_sad_shift;
     /*!< fm_sim_arg_shift shift for FMVE similarity arg values. */
    int32_t fm_sim_arg_shift;
     /*!< mvd_sim_lut[64] MVD Similarity LUT */
    int32_t mvd_sim_lut[64];
     /*!< mvd_sad_shift shift for the SAD values in the MVD sub-block (using realigning) */
    int32_t mvd_sad_shift;
     /*!< mvd_arg_g_static The gain for the recursive similarity at case of static MV . together  with neighbors */
    int32_t mvd_arg_g_static;
     /*!< mvd_arg_g_static_local The gain for the recursive similarity at case of static MV, neighbors have a different MV */
    int32_t mvd_arg_g_static_local;
     /*!< mvd_arg_g_move The gain for the recursive similarity at case of non-static MV,  together  with neighbors */
    int32_t mvd_arg_g_move;
     /*!< mvd_arg_g_move_local The gain for the recursive similarity at case of non-static MV,neighbors have a different MV */
    int32_t mvd_arg_g_move_local;
     /*!< spnr_lut_h[64] spNR BF lut for horizontal direction */
    int32_t spnr_lut_h[64];
     /*!< spnr_lut_v[64] spNR BF lut for vertical direction */
    int32_t spnr_lut_v[64];
     /*!< pb_weight_pre_max maximal spTNR weight */
    int32_t pb_weight_pre_max;
     /*!< pb_weight_in_min The minimal weight of the input frame at the blended output image. */
    int32_t pb_weight_in_min;
     /*!< no_fmve FMVE debug flag, 0-run, 1-don't run, 2- don't run, but run content */
    int32_t no_fmve;
     /*!< bypass bypass flag, output is 4 bit shifted input */
    int32_t bypass;
     /*!< framenumber frame number. Should be in PAL */
    int32_t framenumber;
     /*!< g_mv_x global  MV_X. Should be in PAL */
    int32_t g_mv_x;
     /*!< g_mv_y global  MV_Y. Should be in PAL */
    int32_t g_mv_y;

} ia_pal_isp_bxt_tnr5v1_t; 

/*! \struct dma_cropper_mp
    
*/
typedef struct 
{
     /*!< Bypass bypass the DMA_Cropper */
    int32_t Bypass;
     /*!< crop_left number of pixels to crop from left */
    int32_t crop_left;
     /*!< crop_top number of pixels to crop from top */
    int32_t crop_top;
     /*!< uncropped_output_width output width before any cropping is done */
    int32_t uncropped_output_width;
     /*!< uncropped_output_height output height before any cropping is done */
    int32_t uncropped_output_height;
     /*!< cropped_width input crop width */
    int32_t cropped_width;
     /*!< cropped_height input crop height */
    int32_t cropped_height;

} ia_pal_isp_dma_cropper_mp_t; 

/*! \struct dma_cropper_dp
    
*/
typedef struct 
{
     /*!< Bypass bypass the DMA_Cropper */
    int32_t Bypass;
     /*!< crop_left number of pixels to crop from left */
    int32_t crop_left;
     /*!< crop_top number of pixels to crop from top */
    int32_t crop_top;
     /*!< uncropped_output_width output width before any cropping is done */
    int32_t uncropped_output_width;
     /*!< uncropped_output_height output height before any cropping is done */
    int32_t uncropped_output_height;
     /*!< cropped_width input crop width */
    int32_t cropped_width;
     /*!< cropped_height input crop height */
    int32_t cropped_height;

} ia_pal_isp_dma_cropper_dp_t; 

/*! \struct dma_cropper_ppp
    
*/
typedef struct 
{
     /*!< Bypass bypass the DMA_Cropper */
    int32_t Bypass;
     /*!< crop_left number of pixels to crop from left */
    int32_t crop_left;
     /*!< crop_top number of pixels to crop from top */
    int32_t crop_top;
     /*!< uncropped_output_width output width before any cropping is done */
    int32_t uncropped_output_width;
     /*!< uncropped_output_height output height before any cropping is done */
    int32_t uncropped_output_height;
     /*!< cropped_width input crop width */
    int32_t cropped_width;
     /*!< cropped_height input crop height */
    int32_t cropped_height;

} ia_pal_isp_dma_cropper_ppp_t; 

/*! \struct drc_1
    DRC filter
*/
typedef struct 
{
     /*!< Bypass Bypass filter */
    int32_t Bypass;
     /*!< blus_ds_factor downscale factor: 8 or 16 */
    int32_t blus_ds_factor;
     /*!< blus_sp_coef_a[256] spatial coefficients A (top left), 0.0.15 */
    int32_t blus_sp_coef_a[256];
     /*!< blus_sp_coef_b[256] spatial coefficients B (top right), 0.0.15 */
    int32_t blus_sp_coef_b[256];
     /*!< blus_sp_coef_c[256] spatial coefficients C (bottom left), 0.0.15 */
    int32_t blus_sp_coef_c[256];
     /*!< blus_sp_coef_d[256] spatial coefficients D (bottom right), 0.0.15 */
    int32_t blus_sp_coef_d[256];
     /*!< blus_sim_min min value of similarity, 0.0.15 */
    int32_t blus_sim_min;
     /*!< lce_bypass LCE bypass */
    int32_t lce_bypass;
     /*!< lce_model_slope LCE model slope, 1.7.8 */
    int32_t lce_model_slope;
     /*!< lce_model_offset LCE model offset, 1.7.8 */
    int32_t lce_model_offset;
     /*!< lce_viir_sp_weight VIIR spatial weight, 1.0.15 */
    int32_t lce_viir_sp_weight;
     /*!< lce_power LCE power, 0.3.12 */
    int32_t lce_power;
     /*!< lce_deadzone LCE deadzone, 0.0.15 */
    int32_t lce_deadzone;
     /*!< lce_clip LCE clip, 0.0.15 */
    int32_t lce_clip;
     /*!< lr_gain_map[133584] LRGain, 0.7.8 */
    int32_t lr_gain_map[133584];
     /*!< lr_wgt_map[133584] LRWgt */
    int32_t lr_wgt_map[133584];
     /*!< lr_map_width map width */
    int32_t lr_map_width;
     /*!< lr_map_height map height */
    int32_t lr_map_height;

} ia_pal_isp_drc_1_t; 

/*! \struct exy
    
*/
typedef struct 
{
     /*!< bypass Bypass filter */
    int32_t bypass;
     /*!< Coef[2] filter coefficients */
    int32_t Coef[2];
     /*!< NS_shift shifting noise stream to the relevant range */
    int32_t NS_shift;

} ia_pal_isp_exy_t; 

/*! \struct hdrstats_1
    HDR Statistics Extraction filter
*/
typedef struct 
{
     /*!< rgbsstat_en StatR/G/B/S enable: 0 - disable, 1 - enable */
    int32_t rgbsstat_en;
     /*!< histstat_en HistStatR/G/B/Y enable: 0 - disable, 1 - enable */
    int32_t histstat_en;
     /*!< drcstat_en DRCStatY/V enable: 0 - disable, 1 - enable */
    int32_t drcstat_en;
     /*!< bayer_startcolor Bayer Start Color: 0 - R, 1 - Gr, 2 - Gb, 3 - B */
    int32_t bayer_startcolor;
     /*!< dcn_mode DCN mode: 0 - bypass, 1 - DC2, 2 - DC4, 3 - DC8, Saturation grid size: 0 - 8x8, 1 - 16x16, 2 - 32x32, 3 - 64x64 */
    int32_t dcn_mode;
     /*!< sat_thrsh Saturation threshold */
    int32_t sat_thrsh;
     /*!< sat_rshift Saturation right shift value for converting to saturation ratio: DCN mode * 2 */
    int32_t sat_rshift;
     /*!< drcstat_xx2x_bypass Bypass XX2x sub-block */
    int32_t drcstat_xx2x_bypass;
     /*!< decomp_bypass Bypass decompression sub-block */
    int32_t decomp_bypass;
     /*!< decomp_y_mode decompression Y mode: 0 - average, 1 - max */
    int32_t decomp_y_mode;
     /*!< rgbs_grid_width StatR/G/B/S grid width */
    int32_t rgbs_grid_width;
     /*!< rgbs_grid_height StatR/G/B/S grid height */
    int32_t rgbs_grid_height;
     /*!< hist_grid_width HistStatR/G/B/Y grid width */
    int32_t hist_grid_width;
     /*!< hist_grid_height HistStatR/G/B/Y grid height */
    int32_t hist_grid_height;
     /*!< drc_grid_width DRCStatY/V grid width */
    int32_t drc_grid_width;
     /*!< drc_grid_height DRCStatY/V grid height */
    int32_t drc_grid_height;

} ia_pal_isp_hdrstats_1_t; 

/*! \struct see
    
*/
typedef struct 
{
     /*!< bypass bypass for the filter */
    int32_t bypass;
     /*!< Alpha_LUT[64] edge enhance gain */
    int32_t Alpha_LUT[64];
     /*!< Edge_Max max edge value for clamping */
    int32_t Edge_Max;
     /*!< Edge_Thres threshold for coring */
    int32_t Edge_Thres;

} ia_pal_isp_see_t; 

/*! \struct tnr5_21
    
*/
typedef struct 
{
     /*!< NM_Rad2_Shift Bit shift bumber to calculate index for nm_R_xcu */
    int32_t NM_Rad2_Shift;
     /*!< nm_radial_y_center Opical center y coordinate in chroma resolution */
    int32_t nm_radial_y_center;
     /*!< nm_radial_x_center Opical center x coordinate in chroma resolution */
    int32_t nm_radial_x_center;
     /*!< nm_R_xcu[128] LUT for radial noise model */
    int32_t nm_R_xcu[128];
     /*!< nm_YY_xcu[64] LUT for Y noise model – Y dependency */
    int32_t nm_YY_xcu[64];
     /*!< nm_YC_xcu[64] LUT for Y noise model – C dependency */
    int32_t nm_YC_xcu[64];
     /*!< nm_CY_xcu[64] LUT for C noise model – Y dependency */
    int32_t nm_CY_xcu[64];
     /*!< nm_CC_xcu[64] LUT for C noise model – C dependency */
    int32_t nm_CC_xcu[64];
     /*!< nm_Y_log_est_min Min value for log space Y noise model */
    int32_t nm_Y_log_est_min;
     /*!< nm_Y_log_est_max Max value for log space Y noise model */
    int32_t nm_Y_log_est_max;
     /*!< nm_C_log_est_min Min value for log space C noise model */
    int32_t nm_C_log_est_min;
     /*!< nm_C_log_est_max Max value for log space C noise model */
    int32_t nm_C_log_est_max;
     /*!< nm_lut_frac Fractional bit for noise model LUT */
    int32_t nm_lut_frac;
     /*!< nm_idx_frac Bit number for adjusting to POW LUT index */
    int32_t nm_idx_frac;
     /*!< nm_pow[64] LUT for power function */
    int32_t nm_pow[64];
     /*!< nm_pow_frac Fractional bit for POW LUT */
    int32_t nm_pow_frac;
     /*!< nm_shift_num Pre-calculation of nm_lut_frac - nm_idx_frac */
    int32_t nm_shift_num;
     /*!< nm_Y_alpha Scaling coefficient for Y noise model */
    int32_t nm_Y_alpha;
     /*!< nm_C_alpha Scaling coefficient for C noise model */
    int32_t nm_C_alpha;
     /*!< co_var_thres Variance threshold */
    int32_t co_var_thres;
     /*!< co_var_gain Variance gain */
    int32_t co_var_gain;
     /*!< tbd_sad_Y_gain Y SAD sensitivity gain */
    int32_t tbd_sad_Y_gain;
     /*!< tbd_sad_C_gain C SAD sensitivity gain */
    int32_t tbd_sad_C_gain;
     /*!< tbd_sim_arg_gain_m Similarity argument gain for dynamic */
    int32_t tbd_sim_arg_gain_m;
     /*!< tbd_con_thres Content level threshold */
    int32_t tbd_con_thres;
     /*!< tbd_con_gain Content level gain */
    int32_t tbd_con_gain;
     /*!< tbd_sim_lut[64] Similarity LUT */
    int32_t tbd_sim_lut[64];
     /*!< tbd_rec_sim_thres Similarity threshold for recursive filter */
    int32_t tbd_rec_sim_thres;
     /*!< tbd_rec_gain0 Gain of recursive filter for static region */
    int32_t tbd_rec_gain0;
     /*!< tbd_rec_gain1 Gain of recursive filter for dynamic region */
    int32_t tbd_rec_gain1;
     /*!< pb_weight_in_opp 1.0 - minimum input weight */
    int32_t pb_weight_in_opp;
     /*!< pb_weight_in_min Minimum input weight */
    int32_t pb_weight_in_min;
     /*!< pb_weight_pre PAL - weight w.r.t. frame count */
    int32_t pb_weight_pre;
     /*!< pb_weight_sp_thres Spatial filter weight threshold */
    int32_t pb_weight_sp_thres;
     /*!< pb_weight_sp_gain Spatial filter weight gain */
    int32_t pb_weight_sp_gain;
     /*!< pb_weight_sp_max0 Spatial filter weight max at high similarity region */
    int32_t pb_weight_sp_max0;
     /*!< pb_weight_sp_max1 Spatial filter weight max at low similarity region */
    int32_t pb_weight_sp_max1;
     /*!< NS_weight_LUT[64] LUT for Noise stream weight control by similarity */
    int32_t NS_weight_LUT[64];
     /*!< NS_ConLv_w_LUT[64] LUT for Noise stream weight control by content */
    int32_t NS_ConLv_w_LUT[64];
     /*!< NS_gain Overall noise stream gain */
    int32_t NS_gain;
     /*!< NS_out_max Max value for clipping noise stream */
    int32_t NS_out_max;
     /*!< NS_Norm_bias Bias for noise stream luma dependency model */
    int32_t NS_Norm_bias;
     /*!< NS_Norm_coef Slope for noise stream luma dependency model */
    int32_t NS_Norm_coef;
     /*!< bypass bypass */
    int32_t bypass;
     /*!< framenumber frame number */
    int32_t framenumber;
     /*!< g_mv_x global  MV_X */
    int32_t g_mv_x;
     /*!< g_mv_y global  MV_Y */
    int32_t g_mv_y;

} ia_pal_isp_tnr5_21_t; 

/*! \struct xnr_dss
    Scalable Chroma and Luma Denoise, Medium and High Frequency
*/
typedef struct 
{
     /*!< jbl_mf_bypass_y Bypass JBL MF Luma */
    int32_t jbl_mf_bypass_y;
     /*!< jbl_mf_bypass_c Bypass MF Chroma */
    int32_t jbl_mf_bypass_c;
     /*!< noise_sigma_mf_y_y Noise Sigma MF Luma per Luma */
    int32_t noise_sigma_mf_y_y;
     /*!< noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration */
    int32_t noise_sigma_mf_y_s;
     /*!< noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma */
    int32_t noise_sigma_mf_c_y;
     /*!< noise_sigma_mf_c_u Noise Sigma MF Chroma per U */
    int32_t noise_sigma_mf_c_u;
     /*!< noise_sigma_mf_c_v Noise Sigma MF Chroma per V */
    int32_t noise_sigma_mf_c_v;
     /*!< rad_noise_sigma_mf_y_y Noise Sigma MF Luma per Luma - radial */
    int32_t rad_noise_sigma_mf_y_y;
     /*!< rad_noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration - radial */
    int32_t rad_noise_sigma_mf_y_s;
     /*!< rad_noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma - radial */
    int32_t rad_noise_sigma_mf_c_y;
     /*!< rad_noise_sigma_mf_c_u Noise Sigma MF Chroma per U - radial */
    int32_t rad_noise_sigma_mf_c_u;
     /*!< rad_noise_sigma_mf_c_v Noise Sigma MF Chroma per V - radial */
    int32_t rad_noise_sigma_mf_c_v;
     /*!< noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 */
    int32_t noise_epsilon_mf_y_y;
     /*!< noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 */
    int32_t noise_epsilon_mf_c_y;
     /*!< noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 */
    int32_t noise_epsilon_mf_c_u;
     /*!< noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 */
    int32_t noise_epsilon_mf_c_v;
     /*!< rad_noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 - radial */
    int32_t rad_noise_epsilon_mf_y_y;
     /*!< rad_noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_y;
     /*!< rad_noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_u;
     /*!< rad_noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 - radial */
    int32_t rad_noise_epsilon_mf_c_v;
     /*!< jbl_weight_th_mf_y Luma Weight threshold of MF JBL */
    int32_t jbl_weight_th_mf_y;
     /*!< jbl_weight_th_mf_c Chroma Weight threshold of MF JBL */
    int32_t jbl_weight_th_mf_c;
     /*!< lpf_mf_coef_y[49] MF JBL Spatial coefs for Luma */
    int32_t lpf_mf_coef_y[49];
     /*!< lpf_mf_coef_c[49] MF JBL Spatial coefs for Chroma */
    int32_t lpf_mf_coef_c[49];
     /*!< range_weight_lut[7] JBL range Weight LUT */
    int32_t range_weight_lut[7];
     /*!< blend_mf_power_y MF denoise blending power y */
    int32_t blend_mf_power_y;
     /*!< blend_mf_power_c MF denoise blending power chroma */
    int32_t blend_mf_power_c;
     /*!< rad_blend_mf_power_y MF denoise blending power y - radial */
    int32_t rad_blend_mf_power_y;
     /*!< rad_blend_mf_power_c MF denoise blending power chroma -radial */
    int32_t rad_blend_mf_power_c;
     /*!< noise_beta_y_0 noise model for y - coef 0, Q12 */
    int32_t noise_beta_y_0;
     /*!< noise_beta_u_0 noise model for u - coef 0, Q12 */
    int32_t noise_beta_u_0;
     /*!< noise_beta_u_1 noise model for u - coef 1, Q12 */
    int32_t noise_beta_u_1;
     /*!< noise_beta_v_0 noise model for v - coef 0, Q12 */
    int32_t noise_beta_v_0;
     /*!< noise_beta_v_2 noise model for v - coef 2, Q12 */
    int32_t noise_beta_v_2;
     /*!< rad_center_x X location of the radial center location relative to the top left pixel */
    int32_t rad_center_x;
     /*!< rad_center_y Y location of the radial center location relative to the top left pixel */
    int32_t rad_center_y;
     /*!< rad_exp Radial scale bit into the Lut */
    int32_t rad_exp;
     /*!< rad_lut[128] Radial LUT */
    int32_t rad_lut[128];
     /*!< one_div_64_lut[64] 1/SQRT(x), first 64 values LUT */
    int32_t one_div_64_lut[64];
     /*!< xcu_divsqrt_exp XCU divsqrt exponent */
    int32_t xcu_divsqrt_exp;
     /*!< xcu_divsqrt_slp_a_res XCU divsqrt slope precision */
    int32_t xcu_divsqrt_slp_a_res;
     /*!< xcu_divsqrt_offset[16] XCU divsqrt offset(y) vector */
    int32_t xcu_divsqrt_offset[16];
     /*!< xcu_divsqrt_slope[16] XCU divsqrt slope vector */
    int32_t xcu_divsqrt_slope[16];
     /*!< xcu_divsqrt_x[17] XCU divsqrt x points vector + maximal x value */
    int32_t xcu_divsqrt_x[17];
     /*!< lcs_th_low Low Chroma Suppertion threshold for black level */
    int32_t lcs_th_low;
     /*!< lcs_th_high_delta Low Chroma Suppertion threshold for white level (delta from black) */
    int32_t lcs_th_high_delta;
     /*!< rad_lcs_th_low Low Chroma Suppertion threshold for black level - radial (delta from low) */
    int32_t rad_lcs_th_low;
     /*!< rad_lcs_th_high_delta Low Chroma Suppertion threshold for white level -radial (delta form high delta) */
    int32_t rad_lcs_th_high_delta;
     /*!< xcu_lcs_exp XCU ed exponent */
    int32_t xcu_lcs_exp;
     /*!< xcu_lcs_slp_a_res XCU ed slope precision */
    int32_t xcu_lcs_slp_a_res;
     /*!< xcu_lcs_offset[32] XCU ed offset(y) vector */
    int32_t xcu_lcs_offset[32];
     /*!< xcu_lcs_slope[32] XCU ed slope vector */
    int32_t xcu_lcs_slope[32];
     /*!< xcu_lcs_x[33] XCU ed x points vector + maximal x value */
    int32_t xcu_lcs_x[33];
     /*!< hf_luma_power HF Luma denoise power, Q15 */
    int32_t hf_luma_power;
     /*!< blend_hf_power_y HF blending power luma */
    int32_t blend_hf_power_y;
     /*!< blend_hf_power_c HF blending power chroma */
    int32_t blend_hf_power_c;

} ia_pal_isp_xnr_dss_t; 

  

#ifdef __cplusplus
}
#endif
