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

#ifndef _IA_CIPF_STAGE_INTERNAL_H_
#define _IA_CIPF_STAGE_INTERNAL_H_

#include "ia_cipf_types.h"
#include <ia_cipf/ia_cipf_stage_backend.h>

/**
 * \ingroup ia_cipf_internals
 */
ia_err_t
ia_cipf_stage_load(ia_cipf_stage_t *stage);

/**
 * \ingroup ia_cipf_internals
 */
ia_err_t
ia_cipf_stage_execute(ia_cipf_stage_t *stage);

/**
 * \ingroup ia_cipf_internals
 */
ia_err_t
ia_cipf_stage_wait(ia_cipf_stage_t *stage);

#endif /* _IA_CIPF_STAGE_INTERNAL_H_ */
