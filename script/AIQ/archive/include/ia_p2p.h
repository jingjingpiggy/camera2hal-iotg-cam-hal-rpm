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
 * \file ia_p2p.h
 * \brief Declares the public2private converter API interface.
 */

/*! \mainpage
 *
 *  Public2Private (P2P) is a component designed for converting algorithm-related parameters between the ISP algo API and the actual
 *  register layouts what firmware expects in its terminals. In the context of P2P, ISP algo parameters are referred as public data
 *  and the register layouts as private data.
 *
 *  P2P has three main responsibilities:
 *   - Converting public data to private data (encoding parameters)
 *   - Converting private data to public data (decoding statistics)
 *   - Filling the actual terminal descriptors accordingly
 *
 *  \section deps Dependencies
 *
 *  P2P has dependencies to other repositories:
 *   - \b ia_imaging-include: contains include files that are common to all AIQ libraries
 *   - \b ia_imaging-ia_log: the log library used in all AIQ libraries
 *   - \b ia_imaging-ia_pal: contains the public parameter definitions
 *   - \b vied-viedifw-ispfw: P2P uses the CSS functions related to accessing data inside terminals
 *
 *  \section supported_kernels Supported Program Groups & Kernels
 *
 *  Supported platforms:
 *   - BXT B0
 *   - CNL A0
 *   - CNL B0
 *
 *  P2P implementation currently supports the following program groups:
 *   - IA_P2P_PG_ISYS
 *   - IA_P2P_PG_ISL
 *   - IA_P2P_PG_VPREGDC
 *   - IA_P2P_PG_VPOSTGDC
 *   - IA_P2P_PG_SPREGDC
 *   - IA_P2P_PG_SPOSTGDC
 *
 *  P2P implementation currently supports the following kernels from ISYS:
 *   - INL
 *   - BLC_GLOBAL
 *   - BLC_SENSOR_TYPE_0
 *   - BLC_SENSOR_TYPE_1
 *   - BLC_SENSOR_TYPE_2
 *   - PCLN
 *   - LSC_SENSOR_TYPE_0
 *   - LSC_SENSOR_TYPE_1
 *   - LSC_SENSOR_TYPE_2
 *   - 3A_STAT_AWB
 *   - 3A_STAT_AF
 *   - 3A_STAT_AE_CCM
 *   - 3A_STAT_AE
 *   - IDS
 *   - 3A_STAT_PAF
 *
 *  P2P implementation currently supports the following kernels from VPREGDC:
 *   - WBA_WBA
 *   - RYNR_VCUD (B0)
 *   - RYNR_BNLM (B0)
 *   - DEMOSAIC_DEMOSAIC
 *   - CCM_CCM (A0)
 *   - CCM_BDC (A0)
 *   - ACM_CCM (B0)
 *   - ACM_ACM (B0)
 *   - GTC_CSC_CDS
 *   - GTC_GTM
 *   - YUV1_IEFD
 *   - YUV1_YDS (defaults)
 *   - YUV1_TCC (defaults)
 *   - DVS_YBIN
 *   - DVS_DVS
 *   - DVS_L0
 *   - DVS_L1
 *   - DVS_L2
 *
 *  P2P implementation currently supports the following kernels from VPOSTGDC:
 *   - DVS_COORDS
 *   - DVS_CONFIG
 *   - OFS_OF
 *   - OFS_SC0 (without fragmentation support)
 *   - OFS_SC1 (without fragmentation support)
 *   - OFS_ISP
 *
 *  \section init Initialization and deinitialization
 *
 *  P2P must be initialized before its conversion functions can be used. Initialization happens during the camera start-up with ia_p2p_init().
 *  This function returns a handle to the created P2P instance, required by the encoding and decoding functions. When cleaning up, P2P must be
 *  deinitialized with ia_p2p_deinit().
 *
 *  The user has to allocate a cache buffer which is used during encoding and decoding to store parameters which are cached between frames.
 *  The cache buffer is specific to a stream, so each stream must have its own cache buffer. The user takes care of giving the correct cache
 *  buffer to P2P. The size of the cache buffer must be queried with ia_p2p_get_cache_buffer_size().
 *
 *  \section runtime Runtime use
 *
 *  The high-level execution flow during runtime is illustrated in Figure 1. On each frame, P2P expects to get public data from PAL. The user
 *  is responsible for calling pal_run() to produce the public data as a binary data chunk and give this as an input to ia_p2p_parse() which
 *  parses the data to a form that is more easily accessible by the encoding functions. ia_p2p_parse() also requires the pointer to the cache
 *  buffer to use for encoding the cached data. After parsing the public data, the requirements for the terminals and the payload can be queried
 *  from P2P in order to allocate memory for the payload and to create terminals.
 *
 *  \mscfile overview.signalling Figure 1. Using P2P at runtime.
 *
 *  After the terminals have been created, the encoding functions can be used to fill the terminals and their payload with private data.
 *
 *  \subsection runtime_terminal_creation Querying requirements and creating terminals
 *
 *  There are five different terminal types relevant to P2P: three input terminals and two output terminals.
 *
 *  Input terminals:
 *      - <b>Parameter input terminal</b>: contains global kernel parameters
 *      - <b>Program terminal</b>: contains program-specific information, i.e. information related to fragmentation and fragment-specific kernel parameters
 *      - <b>Spatial parameter input terminal</b>: contains spatial kernel parameters, e.g. 2D lookup tables for LSC and GridBLC
 *
 *  Output terminals:
 *      - <b>Parameter output terminal</b>: contains global statistics, e.g. histograms
 *      - <b>Spatial parameter output terminal</b>: contains spatial statistics, e.g. RGBS grid
 *
 *  Parameter input terminal contains global parameters for all kernels, so only one parameter input terminal is required. The order of the sections
 *  in the parameter input terminal is such that first comes all the sections for kernel 0, then all sections for kernel 1 and so on. The order of the
 *  kernels for ISYS is currently defined by the IA_CSS_ISA_KERNEL_ID enumeration.
 *
 *  Program terminal contains program-specific information, i.e. parameters which are not global but fragment-specific. The user can decide into how many
 *  fragments the full frame is split. Only one program terminal is needed, and it contains fragment-specific parameters for all kernels and for each and every
 *  fragment. The order of the sections in the program terminal is such that first comes all the sections of all kernels for the first fragment (similar to
 *  parameter input terminal) and then for the second fragment and so on.
 *
 *  Spatial parameter input terminals are kernel-specific, so there is one for each kernel which requires spatial input parameters. The spatial parameter
 *  input terminal contains lookup tables e.g. LSC table.
 *
 *  Parameter output terminal contains global statistics, such as the histograms. There is only one parameter output terminal which contains statistics
 *  data for all kernels producing global statistics. Since the image might be fragmented, parameter output terminal contains the statistics for each
 *  fragment individually. The order of the sections is such that first comes the statistics of all kernels for the first fragment, then for the second
 *  fragment and so on.
 *
 *  Spatial parameter output terminal contains spatial statistics, such as the RGBS grid. There is one spatial parameter output terminal for each kernel
 *  which produces spatial statistics and it contains only the data for that specific kernel.
 *
 *  Figure 2 illustrates the process of querying terminal and payload requirements and creating the terminals. The number of sections in the
 *  terminals must be queried from P2P using ia_p2p_get_kernel_terminal_requirements(). Since this function returns the requirements for a single
 *  kernel, the user is responsible for looping it over all kernels and accumulating the results to determine the total number of sections in the
 *  parameter terminal and program terminal.
 *
 *  In order to calculate how much memory should be allocated for the actual payload, ia_p2p_get_kernel_payload_desc() is used. This function returns
 *  the required payload size for a single kernel for each terminal type. The user must accumulate the payload sizes over all kernels to determine the
 *  total amount of memory required for payload.
 *
 *  \mscfile terminal_creation.signalling Figure 2. Querying requirements and creating terminals.
 *
 *  After requirements for the terminals and the payload have been determined, memory should be allocated for the terminals and the payload.
 *  Terminals are created using the functions provided by the firmware. As previously explained, only one parameter input terminal, one parameter
 *  output terminal and one program terminal is needed, whereas there must be one spatial parameter input terminal for each kernel having spatial
 *  input parameters. The same applies to spatial output terminals.
 *
 *  \subsection runtime_encoding Encoding
 *
 *  Figure 3 illustrates the encoding process. P2P expects that the user will keep track of the section index where to write the parameters for each
 *  kernel. For each terminal, encoding is performed kernel by kernel in the order of increasing kernel identifier. The first kernel will write to section 0.
 *  The results of ia_p2p_get_kernel_requirements() define how much to increment the section index counter between loop iterations. E.g., if the first
 *  kernel requires 3 sections, the second kernel will be written to section index 3 and so on. The following pseudo code shows how the loop could look like
 *  for the parameter input terminal in case of ISYS:
 *
 *  \code{.c}
 *  unsigned int cur_section = 0;
 *  unsigned int cur_offset = 0;
 *
 *  for (kernel = 0; kernel < N_IA_CSS_ISYS_KERNEL_ID; ++kernel)
 *  {
 *      ia_p2p_parameter_terminal_encode(ia_p2p, IA_P2P_PG_ISYS, kernel, terminal, cur_section, payload_buffer, cur_offset);
 *
 *      ia_p2p_get_kernel_terminal_requirements(ia_p2p, IA_P2P_PG_ISYS, kernel, &reqs); // These could be cached before the loop.
 *      cur_section += reqs.parameter_section_count;
 *
 *      ia_p2p_get_kernel_payload_desc(ia_p2p, IA_P2P_PG_ISYS, kernel, fragment_count, &desc); // These could be cached before the loop.
 *      cur_offset += desc.parameter_payload_size;
 *  }
 *  \endcode
 *
 *  \mscfile encoding.signalling 3. Encoding process.
 *
 *  Parameter terminal does not have any dependencies, so it can be encoded at any point of execution by looping through all kernel identifiers using
 *  ia_p2p_param_in_terminal_encode(). Same is true for the parameter output terminal which is prepared using ia_p2p_param_out_terminal_prepare() at any time.
 *  Preparation only fills in the payload offsets so that firmware knows where to write the statistics.
 *
 *  Program terminal encoding must be started with ia_p2p_program_terminal_init(). This is executed only once per frame. Then, ia_p2p_program_terminal_encode()
 *  needs to be run for each kernel individually, just as was with ia_p2p_param_in_terminal_encode(). Program terminal encode needs the fragment descriptors,
 *  which define which part of the full frame the fragment contains.
 *
 *  Spatial param terminals are encoded/prepared with ia_p2p_spatial_param_in_terminal_encode() / ia_p2p_spatial_param_out_terminal_prepare(). Each kernel has its
 *  own spatial terminals, so the function is called only once per terminal for each kernel.
 *
 *  \subsection runtime_decoding_stats Decoding statistics
 *
 *  Figure 4 illustrates the decoding process for statistics. Decoding the parameter output terminal should be done with a similar loop as encoding the parameter
 *  input terminal and keeping track of the current section index. ia_p2p_param_out_terminal_decode() is used to decode the global statistics. Spatial statistics are
 *  decoded similarly with ia_p2p_spatial_param_out_terminal_decode() with the exception that every statistics block producing spatial statistics has its own spatial
 *  param output terminal.
 *
 *  \mscfile decoding_stats.signalling 4. Decoding process for statistics.
 *
 *  After all statistics have been decoded, the statistics buffer can be requested from P2P by ia_p2p_serialize_statistics(). The returned ia_binary_data buffer is
 *  owned by P2P and remains valid until ia_p2p_serialize_statistics() is called the next time. The user is responsible of copying the data from the ia_binary_data
 *  structure to another location to preserve it over several frames.
 *
 *  \subsection runtime_decoding_inputs Decoding input parameters (only for debugging purposes)
 *
 *  P2P offers functions for decoding also the input parameters. This is meant only for debugging purposes and should not be used on a real device. Decoding input
 *  parameters has strict requirements for the order of executing the decoding functions. It is mandatory to first decode the parameter terminal with
 *  ia_p2p_param_in_terminal_encode() since the parameter terminal contains the information about which kernels have been enabled. This is needed to determine
 *  how the other terminals are decoded. Before the program terminal can be decoded, the sequencer fragment grid descriptors for a specific kernel must be retrieved
 *  from the spatial parameter input terminal using ia_p2p_spatial_param_in_terminal_decode_grid_descriptors(). After this step, ia_p2p_program_terminal_decode()
 *  can be used to decode program-specific parameters. Finally, ia_p2p_spatial_param_in_terminal_decode() is used to decode the spatial input terminals.
 *
 *  \mscfile decoding.signalling 5. Decoding process for input parameters.
 */

#ifndef IA_P2P_H_
#define IA_P2P_H_

#include "ia_css_terminal_types.h"
#include "ia_p2p_types.h"

#ifdef IA_P2P_ENABLE_DEBUG_SUPPORT
#include "ia_p2p_private.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  Initializes IA_P2P module for the given platform.
 *
 *  \param [in] platform The platform for which to initialize P2P.
 *
 *  \return The IA_P2P instance handle, or NULL if errors.
 */
ia_p2p_handle ia_p2p_init(ia_p2p_platform_t platform);

/*!
 *  De-initializes IA_P2P module.
 *
 *  \param [in] ia_p2p IA_P2P instance handle.
 */
void ia_p2p_deinit(ia_p2p_handle ia_p2p);

/*!
 *  Returns the required size for the cache buffer.
 *
 *  \param [in] ia_p2p IA_P2P instance handle.
 */
uint32_t ia_p2p_get_cache_buffer_size(ia_p2p_handle ia_p2p);

/*!
 *  Parses the public data ready to be used for encoding.
 *
 *  \param [in] ia_p2p          IA_P2P instance handle.
 *  \param [in] public_data     The public data to parse (from PAL output).
 *  \param [in] cache_buffer    A pointer to the cache buffer. The buffer is allocated and managed by the user (query the required size with ia_p2p_get_cache_buffer_size()).
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 *          ia_err_data, if public_data doesn't contain enough data.
 */
ia_err ia_p2p_parse(
    ia_p2p_handle ia_p2p,
    const ia_binary_data* public_data,
    void* cache_buffer);

/*!
 *  Serializes the statistics to a single binary blob.
 *
 *  \param [in]  ia_p2p     IA_P2P instance handle.
 *  \param [out] statistics The resulting statistics data.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 *
 *  \remarks The returned data buffer is owned by P2P and is valid as long as any P2P decode functions are not called.
 */
ia_err ia_p2p_serialize_statistics(
    ia_p2p_handle ia_p2p,
    ia_binary_data* statistics);

/*!
 *  Generates a kernel bitmap for the requested program group.
 *
 *  \param [in] ia_p2p  IA_P2P instance handle.
 *  \param [in] pg_id   The program group id.
 *
 *  \return The kernel bitmap where set bit means that the kernel is an imaging kernel and should be encoded by P2P.
 */
uint64_t ia_p2p_get_kernel_bitmap(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id);

/*!
 *  Calculates proper fragments for post-GDC.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]   fragment_count        The number of fragments.
 *  \param [out]  pixel_fragment_descs  The resulting array of fragment descriptors, one for each fragment.
 */
ia_err ia_p2p_calculate_postgdc_fragments(
    ia_p2p_handle ia_p2p,
    unsigned int fragment_count,
    ia_p2p_fragment_desc* pixel_fragment_descs);

/*!
 *  Returns the required slice counts for each fragment for the given kernel.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]  pg_id                  The program group id.
 *  \param [in]  kernel_id              The program group specific identifier of the kernel whose payload sizes to calculate.
 *  \param [in]  fragment_count         The number of fragments.
 *  \param [in]  pixel_fragment_descs   An array of fragment descriptors, one for each fragment.
 *  \param [out] slice_counts           The resulting array of slice counts, one for each fragment.
 */
ia_err ia_p2p_get_slice_counts(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    unsigned int* slice_counts);

/*!
 *  Calculates the required number of section descriptors for each terminal type for the given kernel.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]  pg_id                  The program group id.
 *  \param [in]  kernel_id              The program group specific identifier of the kernel whose descriptor to calculate.
 *  \param [out] kernel_requirements    The calculated requirements for each terminal for the given kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_get_kernel_terminal_requirements(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_p2p_terminal_requirements_t* kernel_requirements);

/*!
 *  Calculates the total size of payload for each terminal type for the given kernel.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]  pg_id                  The program group id.
 *  \param [in]  kernel_id              The program group specific identifier of the kernel whose payload sizes to calculate.
 *  \param [in]  fragment_count         The number of fragments.
 *  \param [in]  pixel_fragment_descs   An array of fragment descriptors, one for each fragment.
 *  \param [out] kernel_payload_desc    The calculated total payload size for each terminal for the given kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_get_kernel_payload_desc(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_p2p_payload_desc* kernel_payload_desc);

/*!
 *  Encodes data for a single kernel in a parameter terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel to encode.
 *  \param [in,out] terminal            The parameter terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in,out] payload_buffer      A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_base_offset The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_in_terminal_encode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned char* payload_buffer,
    unsigned int payload_base_offset);

/*!
 *  Initializes the program terminal sequencer with fragment information.
 *
 *  \param [in]     ia_p2p                  IA_P2P instance handle.
 *  \param [in]     pg_id                   The program group id.
 *  \param [in]     fragment_count          The number of fragments.
 *  \param [in]     pixel_fragment_descs    An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                The program terminal.
 */
ia_err ia_p2p_program_terminal_init(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_program_terminal_t* terminal);

/*!
 *  Encodes data for a single kernel in a program terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     pixel_fragment_descs            An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                        The program terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     total_section_count             The total number of sections for one fragment including all kernels.
 *  \param [in,out] payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_base_offset             The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_program_terminal_encode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_program_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    unsigned char* payload_buffer,
    unsigned int payload_base_offset);

/*!
 *  Encodes data for a single kernel in a spatial param input terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     pixel_fragment_descs            An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                        The spatial param input terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in,out] payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_base_offset             The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_in_terminal_encode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned char* payload_buffer,
    unsigned int payload_base_offset);

/*!
 *  Encodes data for a single kernel in a spatial param output terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     pixel_fragment_descs            An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                        The spatial param output terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     payload_base_offset             The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_out_terminal_prepare(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned int payload_base_offset);

/*!
 *  Decodes spatial parameter data for a single kernel from a spatial param output terminal.
 *
 *  \param [in]     ia_p2p          IA_P2P instance handle.
 *  \param [in]     pg_id           The program group id.
 *  \param [in]     kernel_id       The program group specific identifier of the kernel to decode.
 *  \param [in]     terminal        The spatial param output terminal.
 *  \param [in]     section_index   The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in]     payload_buffer  A pointer to the beginning of the payload buffer.
 *  \param [in,out] cache_buffer    A pointer to the cache buffer for storing the cached outputs.
 *                                  The buffer is allocated and managed by the user (query the required size with ia_p2p_get_cache_buffer_size()).
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_out_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    const unsigned char* payload_buffer,
    void* cache_buffer);

/*!
 *  Prepares payload for a single kernel in a parameter output terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel whose descriptors to prepare.
 *  \param [in]     fragment_count      The number of fragments.
 *  \param [in,out] terminal            The param output terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     total_section_count The total number of sections for one fragment including all kernels.
 *  \param [in]     payload_base_offset The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_out_terminal_prepare(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    unsigned int payload_base_offset);

/*!
 *  Decodes param out data for a single kernel in a parameter output terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count      The number of fragments.
 *  \param [in]     terminal            The param output terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     total_section_count The total number of sections for one fragment including all kernels.
 *  \param [in]     payload_buffer      A pointer to the beginning of the payload buffer.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_out_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    const unsigned char* payload_buffer);

/*!
 *  Encodes data for a single kernel in a sliced parameter terminal.
 *
 *  \param [in]     ia_p2p                  IA_P2P instance handle.
 *  \param [in]     pg_id                   The program group id.
 *  \param [in]     kernel_id               The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count          The number of fragments.
 *  \param [in]     pixel_fragment_descs    An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                The parameter terminal.
 *  \param [in,out] payload_buffer          A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_base_offset     The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_sliced_param_in_terminal_encode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_sliced_param_terminal_t* terminal,
    unsigned char* payload_buffer,
    unsigned int payload_base_offset);

/*!
 *  Prepares payload for a single kernel in a sliced parameter output terminal.
 *
 *  \param [in]     ia_p2p                  IA_P2P instance handle.
 *  \param [in]     pg_id                   The program group id.
 *  \param [in]     kernel_id               The program group specific identifier of the kernel whose descriptors to prepare.
 *  \param [in]     fragment_count          The number of fragments.
 *  \param [in]     pixel_fragment_descs    An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                The param output terminal.
 *  \param [in]     payload_base_offset     The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_sliced_param_out_terminal_prepare(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_sliced_param_terminal_t* terminal,
    unsigned int payload_base_offset);

/*!
 *  Decodes param out data for a single kernel in a sliced parameter output terminal.
 *
 *  \param [in]     ia_p2p                  IA_P2P instance handle.
 *  \param [in]     pg_id                   The program group id.
 *  \param [in]     kernel_id               The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count          The number of fragments.
 *  \param [in]     pixel_fragment_descs    An array of fragment descriptors, one for each fragment.
 *  \param [in]     terminal                The param output terminal.
 *  \param [in]     payload_buffer          A pointer to the beginning of the payload buffer.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_sliced_param_out_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    const ia_css_sliced_param_terminal_t* terminal,
    const unsigned char* payload_buffer);

#ifdef IA_P2P_ENABLE_DEBUG_SUPPORT
/*!
 *  Decodes data for a single kernel in a parameter terminal.
 *
 *  \param [in]     ia_p2p          IA_P2P instance handle.
 *  \param [in]     pg_id           The program group id.
 *  \param [in]     kernel_id       The program group specific identifier of the kernel to encode.
 *  \param [in,out] terminal        The parameter terminal.
 *  \param [in]     section_index   The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in,out] payload_buffer  A pointer to the beginning of the payload buffer.
 *  \param [out]    public_data_out A structure for the public data output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_in_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    const ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    const unsigned char* payload_buffer,
    ia_p2p_public_data_t* public_data_out);

/*!
 *  Encodes data for a single kernel in a program terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     sequencer_fragment_descs        An array of fragment grid descriptors, one for each fragment. These must be retrieved from the
 *                                                  spatial param terminal via ia_p2p_spatial_param_in_terminal_decode_grid_descriptors().
 *  \param [in,out] terminal                        The program terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in]     total_section_count             The total number of sections for one fragment including all kernels.
 *  \param [in]     payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [out]    public_data_out                 A structure for the decoded output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_program_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_css_fragment_grid_desc_t* sequencer_fragment_descs,
    ia_css_program_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    const unsigned char* payload_buffer,
    ia_p2p_public_data_t* public_data_out);

/*!
 *  Decodes fragment grid descriptors for a single kernel from a spatial param input terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     terminal                        The spatial param input terminal.
 *  \param [in]     public_data_out                 A structure for the decoded output.
 *  \param [out]    sequencer_fragment_descs        The resulting array of fragment grid descriptors.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_in_terminal_decode_grid_descriptors(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    ia_css_spatial_param_terminal_t* terminal,
    ia_p2p_public_data_t* public_data_out,
    ia_css_fragment_grid_desc_t* sequencer_fragment_descs);

/*!
 *  Decodes spatial parameter data for a single kernel from a spatial param input terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     terminal                        The spatial param input terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in]     payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [in,out] public_data_out                 A structure for the decoded output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_in_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    const unsigned char* payload_buffer,
    ia_p2p_public_data_t* public_data_out);

/*!
 *  Decodes fragment grid descriptors for a single kernel from a spatial param output terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     terminal                        The spatial param output terminal.
 *  \param [in]     public_data_out                 A structure for the decoded output.
 *  \param [out]    sequencer_fragment_descs        The resulting array of fragment grid descriptors.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_out_terminal_decode_grid_descriptors(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    ia_css_spatial_param_terminal_t* terminal,
    ia_p2p_public_data_t* public_data_out,
    ia_css_fragment_grid_desc_t* sequencer_fragment_descs);

/*!
 *  Decodes data for a single kernel in a sliced parameter terminal.
 *
 *  \param [in]     ia_p2p                  IA_P2P instance handle.
 *  \param [in]     pg_id                   The program group id.
 *  \param [in]     kernel_id               The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count          The number of fragments.
 *  \param [in]     pixel_fragment_descs    An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                The parameter terminal.
 *  \param [in,out] payload_buffer          A pointer to the beginning of the payload buffer.
 *  \param [out]    public_data_out         A structure for the public data output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_sliced_param_in_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    const ia_css_sliced_param_terminal_t* terminal,
    const unsigned char* payload_buffer,
    ia_p2p_public_data_t* public_data_out);

#endif

#ifdef __cplusplus
}
#endif

#endif /* IA_P2P_H_ */
