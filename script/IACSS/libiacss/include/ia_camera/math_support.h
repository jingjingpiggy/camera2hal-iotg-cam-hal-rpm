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

#ifndef __MATH_SUPPORT_H__
#define __MATH_SUPPORT_H__

#include "storage_class.h" /* for STORAGE_CLASS_INLINE */
#include "type_support.h"
#include "assert_support.h"

/* in case we have min/max/MIN/MAX macro's undefine them */
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#ifdef MIN /* also defined in include/hrt/numeric.h from SDK */
#undef MIN
#endif
#ifdef MAX
#undef MAX
#endif

#define IS_ODD(a) ((a) & 0x1)
#define IS_EVEN(a) (!IS_ODD(a))
#define IS_POWER2(a) (!((a)&((a)-1)))

/*To Find next power of 2 number from x */
#define bit2(x)            ((x)      | ((x) >> 1))
#define bit4(x)            (bit2(x)  | (bit2(x) >> 2))
#define bit8(x)            (bit4(x)  | (bit4(x) >> 4))
#define bit16(x)           (bit8(x)  | (bit8(x) >> 8))
#define bit32(x)           (bit16(x) | (bit16(x) >> 16))
#define NEXT_POWER_OF_2(x) (bit32(x-1) + 1)

/* force a value to a lower even value */
#define EVEN_FLOOR(x)	((x) & ~1UL)

/* A => B */
#define IMPLIES(a, b) (!(a) || (b))

/* The ORIG_BITS th bit is the sign bit */
/* Sign extends a ORIG_BITS bits long signed number to a 64-bit signed number */
/* By type casting it can relimited to any valid type-size (32-bit signed or 16-bit or 8-bit) */
/* By masking it can be transformed to any arbitrary bit size */
#define SIGN_EXTEND(VAL, ORIG_BITS)	((~(((VAL)&(1ULL<<((ORIG_BITS)-1)))-1))|(VAL))

/* for preprocessor and array sizing use MIN and MAX
   otherwise use min and max */
#define MAX(a, b)		(((a) > (b)) ? (a) : (b))
#define MIN(a, b)		(((a) < (b)) ? (a) : (b))
#define CLIP(a, b, c)		MIN((MAX((a), (b))), (c))
/* Integer round-down division of a with b */
#define FLOOR_DIV(a, b)		((b) ? ((a) / (b)) : 0)
/* Align a to the lower multiple of b */
#define FLOOR_MUL(a, b)		(FLOOR_DIV(a, b) * (b))
/* Integer round-up division of a with b */
#define CEIL_DIV(a, b)		((b) ? (((a) + (b) - 1) / (b)) : 0)
/* Align a to the upper multiple of b */
#define CEIL_MUL(a, b)		(CEIL_DIV(a, b) * (b))
/* Align a to the upper multiple of b - fast implementation for cases when b=pow(2,n) */
#define CEIL_MUL2(a, b)		(((a) + (b) - 1) & ~((b) - 1))
/* integer round-up division of a with pow(2,b) */
#define CEIL_SHIFT(a, b)	(((a) + (1UL << (b)) - 1) >> (b))
/* Align a to the upper multiple of pow(2,b) */
#define CEIL_SHIFT_MUL(a, b)	(CEIL_SHIFT(a, b) << (b))
/* Absolute difference of a and b */
#define ABS_DIF(a, b)		(((a) > (b)) ? ((a) - (b)) : ((b) - (a)))
/* Square of x */
#define SQR(x) 			((x)*(x))
/* Integer round-half-down division of a nad b */
#define ROUND_HALF_DOWN_DIV(a, b)	((b) ? ((a) + (b / 2) - 1) / (b) : 0)
/* Align a to the round-half-down multiple of b */
#define ROUND_HALF_DOWN_MUL(a, b)	(ROUND_HALF_DOWN_DIV(a, b) * (b))

/* Following 3 defines to support - reuse of Skycam OFS code for BXT */
#define CEIL(a, b)	CEIL_MUL(a, b)
#define FLOOR(a, b)	FLOOR_MUL(a, b)
#define ABS(a) ABS_DIF(a, 0)

#define MAX3(a, b, c)		MAX((a), MAX((b), (c)))
#define MAX4(a, b, c, d)	MAX((MAX((a), (b))), (MAX((c), (d))))

/* min and max should not be macros as they will evaluate their arguments twice.
   if you really need a macro (e.g. for CPP or for initializing an array)
   use MIN() and MAX(), otherwise use min() and max() */

#if !defined(PIPE_GENERATION)
STORAGE_CLASS_INLINE int max(int a, int b)
{
	return MAX(a, b);
}

STORAGE_CLASS_INLINE int min(int a, int b)
{
	return MIN(a, b);
}

STORAGE_CLASS_INLINE int clip(int a, int b, int c)
{
	return min(max(a, b), c);
}

STORAGE_CLASS_INLINE unsigned int umax(unsigned int a, unsigned int b)
{
	return MAX(a, b);
}

STORAGE_CLASS_INLINE unsigned int umin(unsigned int a, unsigned int b)
{
	return MIN(a, b);
}

STORAGE_CLASS_INLINE unsigned int uclip(unsigned int a, unsigned int b, unsigned int c)
{
	return umin(umax(a, b), c);
}

STORAGE_CLASS_INLINE unsigned int ceil_div(unsigned int a, unsigned int b)
{
	return CEIL_DIV(a, b);
}

STORAGE_CLASS_INLINE unsigned int ceil_mul(unsigned int a, unsigned int b)
{
	return CEIL_MUL(a, b);
}

STORAGE_CLASS_INLINE unsigned int ceil_mul2(unsigned int a, unsigned int b)
{
	return CEIL_MUL2(a, b);
}

STORAGE_CLASS_INLINE unsigned int ceil_shift(unsigned int a, unsigned int b)
{
	return CEIL_SHIFT(a, b);
}

STORAGE_CLASS_INLINE unsigned int ceil_shift_mul(unsigned int a, unsigned int b)
{
	return CEIL_SHIFT_MUL(a, b);
}

STORAGE_CLASS_INLINE int abs_dif(int a, int b)
{
	return ABS_DIF(a, b);
}

STORAGE_CLASS_INLINE unsigned int uabs_dif(unsigned int a, unsigned int b)
{
	return ABS_DIF(a, b);
}

STORAGE_CLASS_INLINE unsigned int round_half_down_div(unsigned int a, unsigned int b)
{
	return ROUND_HALF_DOWN_DIV(a, b);
}

STORAGE_CLASS_INLINE unsigned int round_half_down_mul(unsigned int a, unsigned int b)
{
	return ROUND_HALF_DOWN_MUL(a, b);
}

STORAGE_CLASS_INLINE unsigned int ceil_pow2(uint32_t a)
{
	if (IS_POWER2(a)) {
		return (unsigned int)a;
	}
	else {
		unsigned int v = a;
		v |= v>>1;
		v |= v>>2;
		v |= v>>4;
		v |= v>>8;
		v |= v>>16;
		return (unsigned int)(v+1);
	}
}

STORAGE_CLASS_INLINE unsigned int floor_log2(uint32_t a)
{
	static const uint8_t de_bruijn[] =
	{
		0,  9,  1, 10, 13, 21,  2, 29, 11, 14, 16, 18, 22, 25,  3, 30,
		8, 12, 20, 28, 15, 17, 24,  7, 19, 27, 23,  6, 26,  5,  4, 31
	};
	uint32_t v = a;
	v |= v>>1;
	v |= v>>2;
	v |= v>>4;
	v |= v>>8;
	v |= v>>16;
	return (unsigned int)de_bruijn[(v*0x07C4ACDDU)>>27];
}

/* Divide by small power of two */
STORAGE_CLASS_INLINE unsigned int
udiv2_small_i(uint32_t a, uint32_t b)
{
	assert (b <= 2);
	return a >> (b-1);
}

#if !defined(__VIED_CELL)
/*
 * For SP and ISP, SDK provides the definition of OP_std_modadd.
 * We need it only for host
 */
STORAGE_CLASS_INLINE unsigned int OP_std_modadd(int a, int b, int c)
{
	return (a+b<0 ? a+b+c : a+b>=c ? a+b-c : a+b);
}

/*
 * For SP and ISP, SDK provides the definition of OP_asp_slor.
 * We need it only for host
 */
STORAGE_CLASS_INLINE unsigned int OP_asp_slor(int a, int b, int c)
{
	return ((a << c) | b);
}
#else
#include "hive/customops.h"
#endif /* !defined(__VIED_CELL) */

#endif /* !defined(PIPE_GENERATION) */

#if !defined(__KERNEL__)
#define clamp(a, min_val, max_val) MIN(MAX((a), (min_val)), (max_val))
#endif /* !defined(__KERNEL__) */

#endif /*__MATH_SUPPORT_H__*/
