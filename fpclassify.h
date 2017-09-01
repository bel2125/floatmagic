/*
 * MIT License
 *
 * Copyright (c) 2017 bel2125
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef FPCLASSIFY_H
#define FPCLASSIFY_H

/* define NAN, INFINITY, isnan(), isinf(), isfinite() */
#include <math.h>

/* However, some older Visual Studio Versions do not */
#if !defined(INFINITY) || !defined(NAN)
extern double DOUBLE_ZERO;
#define INFINITY (1.0/DOUBLE_ZERO)
#define NAN (DOUBLE_ZERO/DOUBLE_ZERO)
#endif
#if !defined(isnan) || !defined(isinf) || !defined(isfinite)
#define NEED_fpclassify
extern int fpclassify(double d);
extern int signbit(double d);
#define FP_INFINITE (1)
#define FP_NAN (2)
#define FP_ZERO (4)
#define FP_NORMAL (8)
#define FP_SUBNORMAL (16)
#define isnan(x) ((fpclassify((double)(x)) & FP_NAN) == FP_NAN)
#define isinf(x) ((fpclassify((double)(x)) & FP_INFINITE) == FP_INFINITE)
#define isfinite(x) ((fpclassify((double)(x)) & (FP_NAN|FP_INFINITE)) == 0)
#define isnormal(x) ((fpclassify((double)(x)) & FP_NORMAL) == FP_NORMAL)
#endif

#endif /* FPCLASSIFY_H */

