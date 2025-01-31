/*
 * Copyright 2012 Intel Corporation
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

/*! \file ia_abstraction.h
   \brief Constants, definitions and macros used IA modules.
*/
#ifndef _IA_ABSTRACTION_H_
#define _IA_ABSTRACTION_H_

#include <stdlib.h>  /* defines malloc and free */
#include <string.h>  /* defines memcpy and memset */
#include <stddef.h>  /* defines NULL */
#include <stdint.h>  /* defines fixed width integers */
#include <assert.h>
#include <math.h>

/*!
 * \brief extra Q number format typedefs.
 */
typedef int16_t sq7_8_t;
typedef uint16_t uq8_8_t;
typedef uint16_t uq6_10_t;
typedef uint16_t uq4_12_t;
typedef int32_t sq15_16_t;
typedef uint32_t uq16_16_t;

#define FLOAT_TO_Q16_16(n) (uint32_t)(((float)(n))*65536.0f)
#define INT_TO_Q16_16(n)   ((n)<<16)
#define Q16_16_TO_FLOAT(n) (((float)(n))*0.0000152587890625f)
#define Q16_16_TO_INT(n)   ((n)>>16)

#define FLOAT_TO_Q1_15(n)  (uint16_t)(((float)(n))*32768.0f)
#define Q1_15_TO_FLOAT(n)  (((float)(n))*0.000030518f)
#define QX_15_TO_FLOAT(n)  (((float)(n))*0.000030517578125f)

#define FLOAT_TO_Q8_8(n)   (uint16_t)(((float)(n))*256.0f)
#define INT_TO_Q8_8(n)     ((n)<<8)
#define Q8_8_TO_FLOAT(n)   (((float)(n))*0.00390625f)
#define Q8_8_TO_INT(n)     ((n)>>8)

#define FLOAT_TO_QX_10(n)  ((n)*1024.0f)
#define FLOAT_TO_QX_11(n)  ((float)(n)*2048.0f)
#define FLOAT_TO_QX_12(n)  ((float)(n)*4096.0f)
#define FLOAT_TO_QX_15(n)  ((float)(n)*32768.0f)
#define INT_TO_QX_10(n)    ((n)<<10)
#define QX_10_TO_FLOAT(n)  (((float)(n))*0.0009765625f)
#define QX_18_TO_FLOAT(n)  (((float)(n))*0.00000381469f)
#define QX_20_TO_FLOAT(n)  (((float)(n))*0.00000095367431640625f)
#define QX_10_TO_INT(n)    ((n)>>10)

#define Q16_12_TO_FLOAT(n) (((float)(n))*0.000244141f)



/*!
 * \brief Calculates aligned value.
 * Works only with unsigned values.
 * \param a Number to align.
 * \param b Alignment.
 * \return  Aligned number.
 */
#define IA_ALIGN(a,b)            (((unsigned)(a)+(unsigned)(b-1)) & ~(unsigned)(b-1))

#define IA_ALLOC(x)              malloc(x)
#define IA_CALLOC(x)             calloc(1, x)
#define IA_REALLOC(x, y)         realloc(x, y)
#define IA_FREEZ(x)              { free(x); x = NULL;}
#define IA_MEMCOPY(x, y, z)      memcpy(x, y, z)
#define IA_MEMMOVE(x,y,z)        memmove(x, y, z)
#define IA_MEMSET(x, y, z)       memset(x, y, z)
#define IA_MEMCOMPARE(x,y,z)     memcmp(x, y, z)
#define IA_ABS(a)                abs((int)(a))
#define IA_FABS(a)               fabsf((float)(a))
#define IA_MIN(a, b)             ((a) < (b) ? (a) : (b))
#define IA_MAX(a, b)             ((a) > (b) ? (a) : (b))
#define IA_LIMIT(val, min, max)  IA_MIN(IA_MAX(val, min), max)
#define IA_POW(a, b)             powf((float)(a), (float)(b))
#define IA_EXP(a)                expf((float)(a))
#define IA_SQRT(a)               sqrtf((float)(a))
#define IA_ROUND(a)              (((float)(a) > 0.0f) ? floorf((float)(a) + 0.5f) : ceilf((float)(a) - 0.5f))
#define IA_CEIL(a)               ceilf((float)(a))
#define IA_FLOOR(a)              floorf((float)(a))
#define IA_SIN(a)                sinf((float)(a))
#define IA_COS(a)                cosf((float)(a))
#define IA_ATAN(a)               atanf((float)(a))
#define IA_LN(a)                 logf((float)(a))
#define IA_UNUSED(x)             (void)x
#define IA_LOG2(x)               (logf((float)(x)) / logf(2.0f))
#define IA_ASSERT                assert
#define IA_SIGN(a)               (((a) > 0) - ((a) < 0))

#ifdef __BUILD_FOR_GSD_AOH__

#if defined(_MSC_VER)
#define snprintf _snprintf
#if !defined(__BOOL_DEFINED)
typedef unsigned char bool;
#define true 1
#define false 0
#endif
#else
#include <stdbool.h> /* defines bool */
#endif

typedef char mutex_t;
typedef char rwlock_t;
#define IA_MUTEX_CREATE(m)
#define IA_MUTEX_DELETE(m)
#define IA_MUTEX_LOCK(m)
#define IA_MUTEX_UNLOCK(m)
#define IA_RWLOCK_CREATE(l)
#define IA_RWLOCK_DELETE(l)
#define IA_RWLOCK_WRLOCK(l)
#define IA_RWLOCK_WRUNLOCK(l)
#define IA_RWLOCK_RDLOCK(l)
#define IA_RWLOCK_RDUNLOCK(l)

#else/*__BUILD_FOR_GSD_AOH__*/

#ifdef _WIN32

// P2P_WINDOWS_KERNELSPACE
// To be fixed properly.
#ifndef P2P_WINDOWS_KERNELSPACE
#include <windows.h>
#endif

#if defined(_MSC_VER)
#ifndef P2P_WINDOWS_KERNELSPACE
#define snprintf _snprintf
#endif
#if !defined(__BOOL_DEFINED) && !defined(__bool_true_false_are_defined)
typedef unsigned char bool;
#define true 1
#define false 0
#endif
#else
#include <stdbool.h> /* defines bool */
#endif

// P2P_WINDOWS_KERNELSPACE
// To be fixed properly.
#ifndef P2P_WINDOWS_KERNELSPACE
typedef HANDLE mutex_t;
typedef PSRWLOCK rwlock_t;
#endif

#define IA_MUTEX_CREATE(m)       (m) = CreateMutex(NULL, false, NULL)
#define IA_MUTEX_DELETE(m)       CloseHandle(m)
#define IA_MUTEX_LOCK(m)         WaitForSingleObject(m, INFINITE)
#define IA_MUTEX_UNLOCK(m)       (ReleaseMutex(m) != 0) ? IA_ASSERT(true) : ((void)0)
#define IA_RWLOCK_CREATE(l)      InitializeSRWLock(&l)
#define IA_RWLOCK_DELETE(l)      ((void)0)
#define IA_RWLOCK_WRLOCK(l)      AcquireSRWLockExclusive(&l)
#define IA_RWLOCK_WRUNLOCK(l)    ReleaseSRWLockExclusive(&l)
#define IA_RWLOCK_RDLOCK(l)      AcquireSRWLockShared(&l)
#define IA_RWLOCK_RDUNLOCK(l)    ReleaseSRWLockShared(&l)
#else
#include <stdbool.h> /* defines bool */
#include <pthread.h> /* defined POSIX thread model */

typedef pthread_mutex_t mutex_t;
typedef pthread_rwlock_t rwlock_t;

#define IA_MUTEX_CREATE(m)       (pthread_mutex_init(&m, NULL) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_MUTEX_DELETE(m)       (pthread_mutex_destroy(&m) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_MUTEX_LOCK(m)         (pthread_mutex_lock(&m) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_MUTEX_UNLOCK(m)       (pthread_mutex_unlock(&m) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_RWLOCK_CREATE(l)      (pthread_rwlock_init(&l, NULL) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_RWLOCK_DELETE(l)      (pthread_rwlock_destroy(&l) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_RWLOCK_WRLOCK(l)      (pthread_rwlock_wrlock(&l) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_RWLOCK_WRUNLOCK(l)    (pthread_rwlock_unlock(&l) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_RWLOCK_RDLOCK(l)      (pthread_rwlock_rdlock(&l) == 0) ? IA_ASSERT(true) : ((void)0)
#define IA_RWLOCK_RDUNLOCK(l)    (pthread_rwlock_unlock(&l) == 0) ? IA_ASSERT(true) : ((void)0)
#endif
#endif /*__BUILD_FOR_GSD_AOH__*/
/* These macros are used for allocating one big chunk of memory and assigning parts of it.
* MEMDEBUG flag can be used to debug / check with if memory read & writes stay within the
* boundaries by allocating each memory block individually from system memory. */
#ifdef MEMDEBUG
#define IA_MEMASSIGN(ptr, size)  IA_CALLOC(size); IA_UNUSED(ptr)
#else
#define IA_MEMASSIGN(ptr, size)  ptr; ptr += IA_ALIGN(size, 8);
#endif

#ifndef __cplusplus
#if (defined(_WIN32) || defined(WIN32)) && !defined(__GNUC__)
#define inline __inline
#elif defined(__GNUC__)
#define inline  __inline__
#else
#define inline                    /* default is to define inline to empty */
#endif
#endif

#endif /* _IA_ABSTRACTION_H_ */

