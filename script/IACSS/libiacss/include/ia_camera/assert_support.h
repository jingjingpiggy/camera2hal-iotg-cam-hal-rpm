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

#ifndef __ASSERT_SUPPORT_H_INCLUDED__
#define __ASSERT_SUPPORT_H_INCLUDED__

/* This file provides support for run-time assertions and compile-time assertions.
 *
 * Run-time asstions are provided via the following syntax:
 *     assert(condition)
 * Run-time assertions are disabled using the NDEBUG flag.
 *
 * Compile time assertions are provided via the following syntax:
 *     COMPILATION_ERROR_IF(condition);
 * A compile-time assertion will fail to compile if the condition is false.
 * The condition must be constant, such that it can be evaluated at compile time.
 *
 * OP___assert is deprecated.
 */

#ifdef __KLOCWORK__
/* Klocwork does not see that assert will lead to abortion
 * as there is no good way to tell this to KW and the code
 * should not depend on assert to function (actually the assert
 * could be disabled in a release build) it was decided to
 * disable the assert for KW scans (by defining NDEBUG)
 * see also: http://www.klocwork.com/products/documentation/current/Tuning_C/C%2B%2B_analysis#Assertions
 */
#define NDEBUG
#endif /* __KLOCWORK__ */

/**
 * The following macro can help to test the size of a struct at compile
 * time rather than at run-time. It does not work for all compilers; see
 * below.
 *
 * Depending on the value of 'condition', the following macro is expanded to:
 * - condition==true:
 *     an expression containing an array declaration with negative size,
 *     usually resulting in a compilation error
 * - condition==false:
 *     (void) 1; // C statement with no effect
 *
 * example:
 *  COMPILATION_ERROR_IF( sizeof(struct host_sp_queues) != SIZE_OF_HOST_SP_QUEUES_STRUCT);
 *
 * verify that the macro indeed triggers a compilation error with your compiler:
 *  COMPILATION_ERROR_IF( sizeof(struct host_sp_queues) != (sizeof(struct host_sp_queues)+1) );
 *
 * Not all compilers will trigger an error with this macro; use a search engine to search for
 * BUILD_BUG_ON to find other methods.
 */
#define COMPILATION_ERROR_IF(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

/* Compile time assertion */
#ifndef CT_ASSERT
#define CT_ASSERT(cnd) ((void)sizeof(char[(cnd)?1:-1]))
#endif /* CT_ASSERT */

#ifdef NDEBUG

#define assert(cnd) ((void)0)

#else

#include "storage_class.h"

#if defined(_MSC_VER)
#ifdef _KERNEL_MODE
/* Windows kernel mode compilation */
#include <ntddk.h>
#define assert(cnd) ASSERT(cnd)
#else
/* Windows usermode compilation */
#include <assert.h>
#endif

#elif defined(__HIVECC)

/*
 * target: assert disabled
 * sched: assert enabled only when SCHED_DEBUG is defined
 * unsched: assert enabled
 */
#if defined(HRT_HW)
#define assert(cnd) ((void)0)
#elif defined(HRT_SCHED) && !defined(DEBUG_SCHED)
#define assert(cnd) ((void)0)
#elif defined(PIPE_GENERATION)
#define assert(cnd) ((void)0)
#else
#include <hive/support.h>
#define assert(cnd) OP___csim_assert(cnd)
#endif

#elif defined(__KERNEL__)
#include <linux/bug.h>

/* TODO: it would be cleaner to use this:
 * #define assert(cnd) BUG_ON(cnd)
 * but that causes many compiler warnings (==errors) under Android
 * because it seems that the BUG_ON() macro is not seen as a check by
 * gcc like the BUG() macro is. */
#define assert(cnd)                                                     \
        do {                                                            \
                if (!(cnd)) {                                           \
                        BUG();                                          \
                }                                                       \
        } while (0)

#elif defined(__FIST__) || defined(__GNUC__)

#include "assert.h"

#else /* default is for unknown environments */
#define assert(cnd) ((void)0)
#endif

#endif /* NDEBUG */

#ifndef PIPE_GENERATION
/* Deprecated OP___assert, this is still used in ~1000 places
 * in the code. This will be removed over time.
 * The implemenation for the pipe generation tool is in see support.isp.h */
#define OP___assert(cnd) assert(cnd)

#ifdef C_RUN
#define compile_time_assert(cond) OP___assert(cond)
#else
extern void _compile_time_assert (void);
STORAGE_CLASS_INLINE void compile_time_assert (unsigned cond)
{
	/* Call undefined function if cond is false */
	if (!cond) _compile_time_assert();
}
#endif
#endif /* PIPE_GENERATION */

#endif /* __ASSERT_SUPPORT_H_INCLUDED__ */
