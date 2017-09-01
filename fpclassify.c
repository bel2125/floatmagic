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


#include "fpclassify.h"

double DOUBLE_ZERO = 0.0;


#if defined(NEED_fpclassify)

#if defined(HAVE_STDINT_H)
#include <stdint.h>
typedef uint64_t bitfield64;
#elif defined(_MSC_VER)
typedef unsigned __int64 bitfield64;
#else
typedef unsigned long long bitfield64;
#endif


static bitfield64 ms = 0x8000000000000000;
static bitfield64 me = 0x7FF0000000000000;
static bitfield64 mf = 0x000FFFFFFFFFFFFF;


int fpclassify(double d) 
{
  bitfield64 *p = (bitfield64 *)&d;
  if ((*p & me) != me) {
    /* finite */
    if (*p & mf) {
      /* finite and not null */
      if (*p & me) {
        return FP_NORMAL;
      }
      return FP_SUBNORMAL;
    }	
    return FP_ZERO;
  }
  if (*p & mf) {
    return FP_NAN;
  }
  return FP_INFINITE;
}


int signbit(double d)
{
  bitfield64 *p = (bitfield64 *)&d;
  return ((*p & ms) != 0);
}

#endif

