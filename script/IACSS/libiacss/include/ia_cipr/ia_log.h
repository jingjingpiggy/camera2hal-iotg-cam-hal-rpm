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

/**
 * \file ia_log.h
 *
 * Debug log print header
 *
 * \defgroup ia_log Debug log interface
 * \ingroup ia_cipr
 *
 * Debug log print interface for wrapping platform specific log interfaces.
 */

#ifndef IA_LOG_H_
#define IA_LOG_H_
#include <stdarg.h>

typedef enum ia_log_level {
    IA_CSS_LOG_LEVEL_D    = 1,
    IA_CSS_LOG_LEVEL_V    = 2,
    IA_CSS_LOG_LEVEL_M    = 4,
    IA_CSS_LOG_LEVEL_ERR  = 8,
    IA_CSS_LOG_LEVEL_WARN = 16
} ia_log_level_t;

/* Logging context */
struct log_context {
    void *value;
    char name[5];
};

#define CSS_DEBUG_ENTRY()           CSS_DEBUG_V("E:%s", __FUNCTION__)

#if defined(RNDBUILD)

void* ia_log_create_context(void *ref);
void ia_log_destroy_context(void *context);

#define CONTEXT_PRETTY
/* Define CONTEXT_PRETTY to output four-letter combination instead of pointer */
#if defined(CONTEXT_PRETTY)
#define CONTEXT_PREFIX "P[%s] "
#else
#define CONTEXT_PREFIX "P[%p] "
#endif //CONTEXT_PRETTY

#define CONTEXT_ARGS_NOT_NULL(p) ((p) && (p)->context && (p)->context->value)

/* Create and allocate memory for the context. */
#define CSS_CONTEXT_CREATE(p)                                               \
    do {                                                                    \
    if (p) {                                                                \
        (p)->context = ia_log_create_context(p);                            \
        CSS_CONTEXT_DEBUG((p), "Created logging context");                  \
    }                                                                       \
    } while (0)

/* Assign the same context to another object */
#define CSS_CONTEXT_SET(to, from)                                           \
    do {                                                                    \
    if((to) && (from) && (from)->context) {                                 \
        (to)->context = (from)->context;                                    \
    }                                                                       \
    } while (0)

/* Free allocated memory for context */
#define CSS_CONTEXT_DESTROY(p)                                              \
    do {                                                                    \
    if ((p) && (p)->context) {                                              \
        ia_log_destroy_context((p)->context);                               \
    }                                                                       \
    } while (0)

/* Debugging with context */
#define CSS_CONTEXT_DEBUG(p, ...) CSS_CONTEXT_DEBUG_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_(p, msg, ...)                                     \
    do {                                                                    \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                         \
        CSS_DEBUG(CONTEXT_PREFIX msg, (p)->context->value, __VA_ARGS__);    \
    } else {                                                                \
        CSS_DEBUG(msg, __VA_ARGS__);                                        \
    }                                                                       \
    } while (0)

/* Verbose debugging with context */
#define CSS_CONTEXT_DEBUG_V(p, ...) CSS_CONTEXT_DEBUG_V_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_V_(p, msg, ...)                                   \
    do {                                                                    \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                         \
        CSS_DEBUG_V(CONTEXT_PREFIX msg, (p)->context->value, __VA_ARGS__);  \
    } else {                                                                \
        CSS_DEBUG_V(msg, __VA_ARGS__);                                      \
    }                                                                       \
    } while (0)

/* Memory debugging with context */
#define CSS_CONTEXT_DEBUG_M(p, ...) CSS_CONTEXT_DEBUG_M_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_M_(p, msg, ...)                                   \
    do {                                                                    \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                         \
        CSS_DEBUG_M(CONTEXT_PREFIX msg, (p)->context->value, __VA_ARGS__);  \
    } else {                                                                \
        CSS_DEBUG_M(msg, __VA_ARGS__);                                      \
    }                                                                       \
    } while (0)

/* Error debugging with context */
#define CSS_CONTEXT_DEBUG_ERR(p, ...) \
    CSS_CONTEXT_DEBUG_ERR_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_ERR_(p, msg, ...)                                 \
    do {                                                                    \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                         \
        CSS_DEBUG_ERR(CONTEXT_PREFIX msg, (p)->context->value, __VA_ARGS__);\
    } else {                                                                \
        CSS_DEBUG_ERR(msg, __VA_ARGS__);                                    \
    }                                                                       \
    } while (0)

/* Warn debugging with context */
#define CSS_CONTEXT_DEBUG_WARN(p, ...) \
    CSS_CONTEXT_DEBUG_WARN_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_WARN_(p, msg, ...)                                 \
    do {                                                                     \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                          \
        CSS_DEBUG_WARN(CONTEXT_PREFIX msg, (p)->context->value, __VA_ARGS__);\
    } else {                                                                 \
        CSS_DEBUG_WARN(msg, __VA_ARGS__);                                    \
    }                                                                        \
    } while (0)

/* Entry logging with context, argument is object with context member */
#define CSS_CONTEXT_ENTRY(p)        do {                                    \
                                    if (CONTEXT_ARGS_NOT_NULL(p)) {         \
                                        CSS_CONTEXT_ENTRY_(p);              \
                                    } else {                                \
                                        CSS_DEBUG_ENTRY();                  \
                                    }                                       \
                                    } while (0)

#define CSS_CONTEXT_ENTRY_(p)                                               \
    CSS_DEBUG_V(CONTEXT_PREFIX "E:%s", (p)->context->value, __FUNCTION__)

#else
#define CSS_CONTEXT_SET(...)            ((void)0)
#define CSS_CONTEXT_CREATE(...)         ((void)0)
#define CSS_CONTEXT_DESTROY(...)        ((void)0)
#define CSS_CONTEXT_DEBUG(p, ...)       CSS_DEBUG(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_V(p, ...)     CSS_DEBUG_V(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_M(p, ...)     CSS_DEBUG_M(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_ERR(p, ...)   CSS_DEBUG_ERR(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_WARN(p, ...)  CSS_DEBUG_WARN(__VA_ARGS__)
#define CSS_CONTEXT_ENTRY(...)          CSS_DEBUG_ENTRY()
#endif //RNDBUILD

#if defined(USE_PRINTF_DEBUGGING)
#include <stdio.h>
#define CSS_DEBUG           printf
#define CSS_DEBUG_V         printf
#define CSS_DEBUG_M         printf
#define CSS_DEBUG_ERR       printf
#define CSS_DEBUG_WARN      printf
#elif defined(RNDBUILD) || defined(_MSC_VER)

void ia_css_debug(ia_log_level_t level,
                  const char *tag,
                  const char *fmt,
                  ...);

void ia_css_vdebug(ia_log_level_t level,
                   const char *tag,
                   const char *fmt,
                   va_list args);

/**
 * \ingroup ia_log
 * normal debug
 */
#define CSS_DEBUG(...) \
        ia_css_debug(IA_CSS_LOG_LEVEL_D, LOG_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * verbose debug
 */
#define CSS_DEBUG_V(...) \
        ia_css_debug(IA_CSS_LOG_LEVEL_V, LOG_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * memory allocation & free debug
 */
#define CSS_DEBUG_M(...) \
        ia_css_debug(IA_CSS_LOG_LEVEL_M, LOG_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * error debug
 */
#define CSS_DEBUG_ERR(...) \
        ia_css_debug(IA_CSS_LOG_LEVEL_ERR, LOG_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * warning debug
 */
#define CSS_DEBUG_WARN(...) \
        ia_css_debug(IA_CSS_LOG_LEVEL_WARN, LOG_TAG, __VA_ARGS__)

#else
#define CSS_DEBUG(...)      ((void)0)
#define CSS_DEBUG_V(...)    ((void)0)
#define CSS_DEBUG_M(...)    ((void)0)
#define CSS_DEBUG_ERR(...)  ((void)0)
#define CSS_DEBUG_WARN(...) ((void)0)
#endif

#endif /* IA_LOG_H_ */
