/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2017-2020 Evan Nemerson <evan@nemerson.com>
 *   2015-2017 John W. Ratcliff <jratcliffscarab@gmail.com>
 *   2015      Brandon Rowlett <browlett@nvidia.com>
 *   2015      Ken Fast <kfast@gdeb.com>
 *   2017      Hasindu Gamaarachchi <hasindu@unsw.edu.au>
 *   2018      Jeff Daily <jeff.daily@amd.com>
 */

#if !defined(SIMDE_X86_SSE2_H)
#define SIMDE_X86_SSE2_H

#include "sse.h"
#include "../simde-f16.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

typedef union {
  #if defined(SIMDE_VECTOR_SUBSCRIPT)
    SIMDE_ALIGN_TO_16 int8_t          i8 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 int16_t        i16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 int32_t        i32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 int64_t        i64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint8_t         u8 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint16_t       u16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint32_t       u32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint64_t       u64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_ALIGN_TO_16 simde_int128  i128 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 simde_uint128 u128 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    #endif
    #if defined(SIMDE_FLOAT16_VECTOR)
    SIMDE_ALIGN_TO_16 simde_float16  f16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    #else
    SIMDE_ALIGN_TO_16 simde_float16  f16[8];
    #endif
    SIMDE_ALIGN_TO_16 simde_float32  f32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 simde_float64  f64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;

    SIMDE_ALIGN_TO_16 int_fast32_t  i32f SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint_fast32_t u32f SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  #else
    SIMDE_ALIGN_TO_16 int8_t         i8[16];
    SIMDE_ALIGN_TO_16 int16_t        i16[8];
    SIMDE_ALIGN_TO_16 int32_t        i32[4];
    SIMDE_ALIGN_TO_16 int64_t        i64[2];
    SIMDE_ALIGN_TO_16 uint8_t        u8[16];
    SIMDE_ALIGN_TO_16 uint16_t       u16[8];
    SIMDE_ALIGN_TO_16 uint32_t       u32[4];
    SIMDE_ALIGN_TO_16 uint64_t       u64[2];
    #if defined(SIMDE_HAVE_INT128_)
    SIMDE_ALIGN_TO_16 simde_int128  i128[1];
    SIMDE_ALIGN_TO_16 simde_uint128 u128[1];
    #endif
    SIMDE_ALIGN_TO_16 simde_float16  f16[8];
    SIMDE_ALIGN_TO_16 simde_float32  f32[4];
    SIMDE_ALIGN_TO_16 simde_float64  f64[2];

    SIMDE_ALIGN_TO_16 int_fast32_t  i32f[16 / sizeof(int_fast32_t)];
    SIMDE_ALIGN_TO_16 uint_fast32_t u32f[16 / sizeof(uint_fast32_t)];
  #endif

    SIMDE_ALIGN_TO_16 simde__m64_private m64_private[2];
    SIMDE_ALIGN_TO_16 simde__m64         m64[2];

  #if defined(SIMDE_X86_SSE2_NATIVE)
    SIMDE_ALIGN_TO_16 __m128i        n;
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    SIMDE_ALIGN_TO_16 int8x16_t      neon_i8;
    SIMDE_ALIGN_TO_16 int16x8_t      neon_i16;
    SIMDE_ALIGN_TO_16 int32x4_t      neon_i32;
    SIMDE_ALIGN_TO_16 int64x2_t      neon_i64;
    SIMDE_ALIGN_TO_16 uint8x16_t     neon_u8;
    SIMDE_ALIGN_TO_16 uint16x8_t     neon_u16;
    SIMDE_ALIGN_TO_16 uint32x4_t     neon_u32;
    SIMDE_ALIGN_TO_16 uint64x2_t     neon_u64;
    #if defined(__ARM_FP16_FORMAT_IEEE)
    SIMDE_ALIGN_TO_16 float16x8_t    neon_f16;
    #endif
    SIMDE_ALIGN_TO_16 float32x4_t    neon_f32;
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    SIMDE_ALIGN_TO_16 float64x2_t    neon_f64;
    #endif
  #elif defined(SIMDE_MIPS_MSA_NATIVE)
    v16i8 msa_i8;
    v8i16 msa_i16;
    v4i32 msa_i32;
    v2i64 msa_i64;
    v16u8 msa_u8;
    v8u16 msa_u16;
    v4u32 msa_u32;
    v2u64 msa_u64;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    SIMDE_ALIGN_TO_16 v128_t         wasm_v128;
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed char)          altivec_i8;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed short)         altivec_i16;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed int)           altivec_i32;
    #if defined(__UINT_FAST32_TYPE__) && (defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE))
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(__INT_FAST32_TYPE__)  altivec_i32f;
    #else
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed int)           altivec_i32f;
    #endif
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)        altivec_u8;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)       altivec_u16;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)         altivec_u32;
    #if defined(__UINT_FAST32_TYPE__) && (defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE))
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(__UINT_FAST32_TYPE__) altivec_u32f;
    #else
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)         altivec_u32f;
    #endif
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(float)                altivec_f32;
    #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64;
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64;
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64;
    #endif
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    v16i8 lsx_i8;
    v8i16 lsx_i16;
    v4i32 lsx_i32;
    v2i64 lsx_i64;
    v16u8 lsx_u8;
    v8u16 lsx_u16;
    v4u32 lsx_u32;
    v2u64 lsx_u64;
    v4f32 lsx_f32;
    v2f64 lsx_f64;
  #endif
} simde__m128i_private;

typedef union {
  #if defined(SIMDE_VECTOR_SUBSCRIPT)
    SIMDE_ALIGN_TO_16 int8_t          i8 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 int16_t        i16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 int32_t        i32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 int64_t        i64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint8_t         u8 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint16_t       u16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint32_t       u32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint64_t       u64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 simde_float32  f32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 simde_float64  f64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 int_fast32_t  i32f SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
    SIMDE_ALIGN_TO_16 uint_fast32_t u32f SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  #else
    SIMDE_ALIGN_TO_16 int8_t         i8[16];
    SIMDE_ALIGN_TO_16 int16_t        i16[8];
    SIMDE_ALIGN_TO_16 int32_t        i32[4];
    SIMDE_ALIGN_TO_16 int64_t        i64[2];
    SIMDE_ALIGN_TO_16 uint8_t        u8[16];
    SIMDE_ALIGN_TO_16 uint16_t       u16[8];
    SIMDE_ALIGN_TO_16 uint32_t       u32[4];
    SIMDE_ALIGN_TO_16 uint64_t       u64[2];
    SIMDE_ALIGN_TO_16 simde_float32  f32[4];
    SIMDE_ALIGN_TO_16 simde_float64  f64[2];
    SIMDE_ALIGN_TO_16 int_fast32_t  i32f[16 / sizeof(int_fast32_t)];
    SIMDE_ALIGN_TO_16 uint_fast32_t u32f[16 / sizeof(uint_fast32_t)];
  #endif

    SIMDE_ALIGN_TO_16 simde__m64_private m64_private[2];
    SIMDE_ALIGN_TO_16 simde__m64         m64[2];

  #if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_X86_SVML_NATIVE)
    SIMDE_ALIGN_TO_16 __m128d        n;
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    SIMDE_ALIGN_TO_16 int8x16_t      neon_i8;
    SIMDE_ALIGN_TO_16 int16x8_t      neon_i16;
    SIMDE_ALIGN_TO_16 int32x4_t      neon_i32;
    SIMDE_ALIGN_TO_16 int64x2_t      neon_i64;
    SIMDE_ALIGN_TO_16 uint8x16_t     neon_u8;
    SIMDE_ALIGN_TO_16 uint16x8_t     neon_u16;
    SIMDE_ALIGN_TO_16 uint32x4_t     neon_u32;
    SIMDE_ALIGN_TO_16 uint64x2_t     neon_u64;
    SIMDE_ALIGN_TO_16 float32x4_t    neon_f32;
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    SIMDE_ALIGN_TO_16 float64x2_t    neon_f64;
    #endif
  #elif defined(SIMDE_MIPS_MSA_NATIVE)
    v16i8 msa_i8;
    v8i16 msa_i16;
    v4i32 msa_i32;
    v2i64 msa_i64;
    v16u8 msa_u8;
    v8u16 msa_u16;
    v4u32 msa_u32;
    v2u64 msa_u64;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    SIMDE_ALIGN_TO_16 v128_t         wasm_v128;
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed char)          altivec_i8;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed short)         altivec_i16;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed int)           altivec_i32;
    #if defined(__INT_FAST32_TYPE__) && (defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE))
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(__INT_FAST32_TYPE__)  altivec_i32f;
    #else
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed int)           altivec_i32f;
    #endif
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)        altivec_u8;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)       altivec_u16;
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)         altivec_u32;
    #if defined(__UINT_FAST32_TYPE__) && (defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE))
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(__UINT_FAST32_TYPE__) altivec_u32f;
    #else
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)         altivec_u32f;
    #endif
    SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(float)                altivec_f32;
    #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64;
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64;
      SIMDE_ALIGN_TO_16 SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64;
    #endif
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    v16i8 lsx_i8;
    v8i16 lsx_i16;
    v4i32 lsx_i32;
    v2i64 lsx_i64;
    v16u8 lsx_u8;
    v8u16 lsx_u16;
    v4u32 lsx_u32;
    v2u64 lsx_u64;
    v4f32 lsx_f32;
    v2f64 lsx_f64;
  #endif
} simde__m128d_private;

#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_X86_SVML_NATIVE)
  typedef __m128i simde__m128i;
  typedef __m128d simde__m128d;
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
   typedef int64x2_t simde__m128i;
#  if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
     typedef float64x2_t simde__m128d;
#  elif defined(SIMDE_VECTOR_SUBSCRIPT)
     typedef simde_float64 simde__m128d SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
#  else
     typedef simde__m128d_private simde__m128d;
#  endif
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
   typedef v128_t simde__m128i;
   typedef v128_t simde__m128d;
#elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
  typedef SIMDE_POWER_ALTIVEC_VECTOR(float) simde__m128i;
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
     typedef SIMDE_POWER_ALTIVEC_VECTOR(double) simde__m128d;
  #else
     typedef simde__m128d_private simde__m128d;
  #endif
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  typedef v2i64 simde__m128i;
  typedef v2f64 simde__m128d;
#elif defined(SIMDE_VECTOR_SUBSCRIPT)
  typedef int64_t simde__m128i SIMDE_ALIGN_TO_16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  typedef simde_float64 simde__m128d SIMDE_ALIGN_TO_16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
#else
  typedef simde__m128i_private simde__m128i;
  typedef simde__m128d_private simde__m128d;
#endif

#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  typedef simde__m128i __m128i;
  typedef simde__m128d __m128d;
#endif

HEDLEY_STATIC_ASSERT(16 == sizeof(simde__m128i), "simde__m128i size incorrect");
HEDLEY_STATIC_ASSERT(16 == sizeof(simde__m128i_private), "simde__m128i_private size incorrect");
HEDLEY_STATIC_ASSERT(16 == sizeof(simde__m128d), "simde__m128d size incorrect");
HEDLEY_STATIC_ASSERT(16 == sizeof(simde__m128d_private), "simde__m128d_private size incorrect");
#if defined(SIMDE_CHECK_ALIGNMENT) && defined(SIMDE_ALIGN_OF)
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m128i) == 16, "simde__m128i is not 16-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m128i_private) == 16, "simde__m128i_private is not 16-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m128d) == 16, "simde__m128d is not 16-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m128d_private) == 16, "simde__m128d_private is not 16-byte aligned");
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde__m128i_from_private(simde__m128i_private v) {
  simde__m128i r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i_private
simde__m128i_to_private(simde__m128i v) {
  simde__m128i_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde__m128d_from_private(simde__m128d_private v) {
  simde__m128d r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d_private
simde__m128d_to_private(simde__m128d v) {
  simde__m128d_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, int8x16_t, neon, i8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, int16x8_t, neon, i16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, int32x4_t, neon, i32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, int64x2_t, neon, i64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, uint8x16_t, neon, u8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, uint16x8_t, neon, u16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, uint32x4_t, neon, u32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, uint64x2_t, neon, u64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, float32x4_t, neon, f32)
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, float64x2_t, neon, f64)
  #endif
#elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(signed char), altivec, i8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(signed short), altivec, i16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(signed int), altivec, i32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), altivec, u8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), altivec, u16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(unsigned int), altivec, u32)
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long), altivec, u64)
    SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, SIMDE_POWER_ALTIVEC_VECTOR(signed long long), altivec, i64)
  #endif
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v16i8, lsx, i8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v8i16, lsx, i16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v4i32, lsx, i32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v2i64, lsx, i64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v16u8, lsx, u8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v8u16, lsx, u16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v4u32, lsx, u32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v2u64, lsx, u64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v4f32, lsx, f32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v2f64, lsx, f64)
#endif /* defined(SIMDE_ARM_NEON_A32V7_NATIVE) */

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, int8x16_t, neon, i8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, int16x8_t, neon, i16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, int32x4_t, neon, i32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, int64x2_t, neon, i64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, uint8x16_t, neon, u8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, uint16x8_t, neon, u16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, uint32x4_t, neon, u32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, uint64x2_t, neon, u64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, float32x4_t, neon, f32)
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, float64x2_t, neon, f64)
  #endif
#elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(signed char), altivec, i8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(signed short), altivec, i16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(signed int), altivec, i32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), altivec, u8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), altivec, u16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(unsigned int), altivec, u32)
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long), altivec, u64)
    SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(signed long long), altivec, i64)
    #if defined(SIMDE_BUG_GCC_95782)
      SIMDE_FUNCTION_ATTRIBUTES
      SIMDE_POWER_ALTIVEC_VECTOR(double)
      simde__m128d_to_altivec_f64(simde__m128d value) {
        simde__m128d_private r_ = simde__m128d_to_private(value);
        return r_.altivec_f64;
      }

      SIMDE_FUNCTION_ATTRIBUTES
      simde__m128d
      simde__m128d_from_altivec_f64(SIMDE_POWER_ALTIVEC_VECTOR(double) value) {
        simde__m128d_private r_;
        r_.altivec_f64 = value;
        return simde__m128d_from_private(r_);
      }
    #else
      SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, SIMDE_POWER_ALTIVEC_VECTOR(double), altivec, f64)
    #endif
  #endif
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v128_t, wasm, v128);
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128i, v128_t, wasm, v128);
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v16i8, lsx, i8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v8i16, lsx, i16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v4i32, lsx, i32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v2i64, lsx, i64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v16u8, lsx, u8)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v8u16, lsx, u16)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v4u32, lsx, u32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v2u64, lsx, u64)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v4f32, lsx, f32)
  SIMDE_X86_GENERATE_CONVERSION_FUNCTION(m128d, v2f64, lsx, f64)
#endif /* defined(SIMDE_ARM_NEON_A32V7_NATIVE) */

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_set_pd (simde_float64 e1, simde_float64 e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_pd(e1, e0);
  #else
    simde__m128d_private r_;

    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_make(e0, e1);
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      SIMDE_ALIGN_TO_16 simde_float64 data[2] = { e0, e1 };
      r_.neon_f64 = vld1q_f64(data);
    #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_TO_16 simde_float64 data[2] = { e0, e1 };
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.f64[0] = e0;
      r_.f64[1] = e1;
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set_pd(e1, e0) simde_mm_set_pd(e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_set1_pd (simde_float64 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set1_pd(a);
  #else
    simde__m128d_private r_;

    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_splat(a);
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vdupq_n_f64(a);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = vec_splats(HEDLEY_STATIC_CAST(double, a));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vldrepl_d(&a, 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.f64[i] = a;
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#define simde_mm_set_pd1(a) simde_mm_set1_pd(a)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set1_pd(a) simde_mm_set1_pd(a)
  #define _mm_set_pd1(a) simde_mm_set1_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_abs_pd(simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    simde_float64 mask_;
    uint64_t u64_ = UINT64_C(0x7FFFFFFFFFFFFFFF);
    simde_memcpy(&mask_, &u64_, sizeof(u64_));
    return _mm_and_pd(_mm_set1_pd(mask_), a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vabsq_f64(a_.neon_f64);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = vec_abs(a_.altivec_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_abs(a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      uint64_t u64_ = UINT64_C(0x7FFFFFFFFFFFFFFF);
      r_.lsx_i64 = __lsx_vand_v(__lsx_vldrepl_d(&u64_, 0), a_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = simde_math_fabs(a_.f64[i]);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_not_pd(simde__m128d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    __m128i ai = _mm_castpd_si128(a);
    return _mm_castsi128_pd(_mm_ternarylogic_epi64(ai, ai, ai, 0x55));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vmvnq_s32(a_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r_.altivec_f64 = vec_nor(a_.altivec_f64, a_.altivec_f64);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32 = vec_nor(a_.altivec_i32, a_.altivec_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_not(a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vnor_v(a_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = ~a_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = ~(a_.i32f[i]);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_select_pd(simde__m128d a, simde__m128d b, simde__m128d mask) {
  /* This function is for when you want to blend two elements together
   * according to a mask.  It is similar to _mm_blendv_pd, except that
   * it is undefined whether the blend is based on the highest bit in
   * each lane (like blendv) or just bitwise operations.  This allows
   * us to implement the function efficiently everywhere.
   *
   * Basically, you promise that all the lanes in mask are either 0 or
   * ~0. */
  #if defined(SIMDE_X86_SSE4_1_NATIVE)
    return _mm_blendv_pd(a, b, mask);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b),
      mask_ = simde__m128d_to_private(mask);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 ^ ((a_.i64 ^ b_.i64) & mask_.i64);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vbslq_s64(mask_.neon_u64, b_.neon_i64, a_.neon_i64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vbitsel_v(a_.lsx_i64, b_.lsx_i64, mask_.lsx_u64)
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] ^ ((a_.i64[i] ^ b_.i64[i]) & mask_.i64[i]);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_add_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vaddq_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i8 = vec_add(a_.altivec_i8, b_.altivec_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_add(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vadd_b(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 + b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] + b_.i8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_add_epi8(a, b) simde_mm_add_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_add_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vaddq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i16 = vec_add(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_add(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vadd_h(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 + b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] + b_.i16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_add_epi16(a, b) simde_mm_add_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_add_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vaddq_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32 = vec_add(a_.altivec_i32, b_.altivec_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_add(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vadd_w(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 + b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] + b_.i32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_add_epi32(a, b) simde_mm_add_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_add_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vaddq_s64(a_.neon_i64, b_.neon_i64);
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r_.altivec_i64 = vec_add(a_.altivec_i64, b_.altivec_i64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vadd_d(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_add(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 + b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] + b_.i64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_add_epi64(a, b) simde_mm_add_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_add_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vaddq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r_.altivec_f64 = vec_add(a_.altivec_f64, b_.altivec_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_add(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vfadd_d(a_.lsx_f64, b_.lsx_f64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 + b_.f64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = a_.f64[i] + b_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_add_pd(a, b) simde_mm_add_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_move_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_move_sd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vsetq_lane_f64(vgetq_lane_f64(b_.neon_f64, 0), a_.neon_f64, 0);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      #if defined(HEDLEY_IBM_VERSION)
        r_.altivec_f64 = vec_xxpermdi(a_.altivec_f64, b_.altivec_f64, 1);
      #else
        r_.altivec_f64 = vec_xxpermdi(b_.altivec_f64, a_.altivec_f64, 1);
      #endif
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_shuffle(a_.wasm_v128, b_.wasm_v128, 2, 1);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(b_.lsx_i64, a_.lsx_i64, 0b00010001);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.f64 = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.f64, b_.f64, 2, 1);
    #else
      r_.f64[0] = b_.f64[0];
      r_.f64[1] = a_.f64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_move_sd(a, b) simde_mm_move_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_broadcastlow_pd(simde__m128d a) {
  /* This function broadcasts the first element in the input vector to
   * all lanes.  It is used to avoid generating spurious exceptions in
   * *_sd functions since there may be garbage in the upper lanes. */

  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_castsi128_pd(_mm_shuffle_epi32(_mm_castpd_si128(a), 0x44));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vdupq_laneq_f64(a_.neon_f64, 0);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r_.altivec_f64 = vec_splat(a_.altivec_f64, 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_splat(a_.f64[0]);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vreplvei_d(a_.lsx_i64, 0);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.f64 = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.f64, a_.f64, 0, 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = a_.f64[0];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_add_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_add_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_add_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfadd_d(b_.lsx_f64, a_.lsx_f64), 0);
    #else
      r_.f64[0] = a_.f64[0] + b_.f64[0];
      r_.f64[1] = a_.f64[1];
    #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_add_sd(a, b) simde_mm_add_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_add_si64 (simde__m64 a, simde__m64 b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_add_si64(a, b);
  #else
    simde__m64_private
      r_,
      a_ = simde__m64_to_private(a),
      b_ = simde__m64_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vadd_s64(a_.neon_i64, b_.neon_i64);
    #else
      r_.i64[0] = a_.i64[0] + b_.i64[0];
    #endif

    return simde__m64_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_add_si64(a, b) simde_mm_add_si64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_adds_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_adds_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vqaddq_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_add_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i8 = vec_adds(a_.altivec_i8, b_.altivec_i8);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsadd_b(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = simde_math_adds_i8(a_.i8[i], b_.i8[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_adds_epi8(a, b) simde_mm_adds_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_adds_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_adds_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vqaddq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_add_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i16 = vec_adds(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsadd_h(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = simde_math_adds_i16(a_.i16[i], b_.i16[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_adds_epi16(a, b) simde_mm_adds_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_adds_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_adds_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vqaddq_u8(a_.neon_u8, b_.neon_u8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u8x16_add_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r_.altivec_u8 = vec_adds(a_.altivec_u8, b_.altivec_u8);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsadd_bu(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = simde_math_adds_u8(a_.u8[i], b_.u8[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_adds_epu8(a, b) simde_mm_adds_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_adds_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_adds_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vqaddq_u16(a_.neon_u16, b_.neon_u16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u16x8_add_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_u16 = vec_adds(a_.altivec_u16, b_.altivec_u16);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsadd_hu(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = simde_math_adds_u16(a_.u16[i], b_.u16[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_adds_epu16(a, b) simde_mm_adds_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_and_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_and_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vandq_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_and(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r_.altivec_f64 = vec_and(a_.altivec_f64, b_.altivec_f64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vand_v(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f & b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] & b_.i32f[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_and_pd(a, b) simde_mm_and_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_and_si128 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_and_si128(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vandq_s32(b_.neon_i32, a_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_u32f = vec_and(a_.altivec_u32f, b_.altivec_u32f);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_and(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vand_v(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f & b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] & b_.i32f[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_and_si128(a, b) simde_mm_and_si128(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_andnot_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_andnot_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vbicq_s32(b_.neon_i32, a_.neon_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_andnot(b_.wasm_v128, a_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = vec_andc(b_.altivec_f64, a_.altivec_f64);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32f = vec_andc(b_.altivec_i32f, a_.altivec_i32f);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vandn_v(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = ~a_.i32f & b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = ~a_.u64[i] & b_.u64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_andnot_pd(a, b) simde_mm_andnot_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_andnot_si128 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_andnot_si128(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vbicq_s32(b_.neon_i32, a_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i32 = vec_andc(b_.altivec_i32, a_.altivec_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_andnot(b_.wasm_v128, a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vandn_v(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = ~a_.i32f & b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = ~(a_.i32f[i]) & b_.i32f[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_andnot_si128(a, b) simde_mm_andnot_si128(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_xor_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_xor_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f ^ b_.i32f;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_xor(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = veorq_s64(a_.neon_i64, b_.neon_i64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vxor_v(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] ^ b_.i32f[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_xor_pd(a, b) simde_mm_xor_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_avg_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_avg_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vrhaddq_u8(b_.neon_u8, a_.neon_u8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u8x16_avgr(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_u8 = vec_avg(a_.altivec_u8, b_.altivec_u8);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vavgr_bu(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && defined(SIMDE_CONVERT_VECTOR_)
      uint16_t wa SIMDE_VECTOR(32);
      uint16_t wb SIMDE_VECTOR(32);
      uint16_t wr SIMDE_VECTOR(32);
      SIMDE_CONVERT_VECTOR_(wa, a_.u8);
      SIMDE_CONVERT_VECTOR_(wb, b_.u8);
      wr = (wa + wb + 1) >> 1;
      SIMDE_CONVERT_VECTOR_(r_.u8, wr);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = (a_.u8[i] + b_.u8[i] + 1) >> 1;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_avg_epu8(a, b) simde_mm_avg_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_avg_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_avg_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vrhaddq_u16(b_.neon_u16, a_.neon_u16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u16x8_avgr(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_u16 = vec_avg(a_.altivec_u16, b_.altivec_u16);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vavgr_hu(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && defined(SIMDE_CONVERT_VECTOR_)
      uint32_t wa SIMDE_VECTOR(32);
      uint32_t wb SIMDE_VECTOR(32);
      uint32_t wr SIMDE_VECTOR(32);
      SIMDE_CONVERT_VECTOR_(wa, a_.u16);
      SIMDE_CONVERT_VECTOR_(wb, b_.u16);
      wr = (wa + wb + 1) >> 1;
      SIMDE_CONVERT_VECTOR_(r_.u16, wr);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = (a_.u16[i] + b_.u16[i] + 1) >> 1;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_avg_epu16(a, b) simde_mm_avg_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setzero_si128 (void) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_setzero_si128();
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vdupq_n_s32(0);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i32 = vec_splats(HEDLEY_STATIC_CAST(signed int, 0));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_splat(INT32_C(0));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vreplgr2vr_w(0);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT)
      r_.i32 = __extension__ (__typeof__(r_.i32)) { 0, 0, 0, 0 };
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = 0;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_setzero_si128() (simde_mm_setzero_si128())
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_bslli_si128 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  if (HEDLEY_UNLIKELY((imm8 & ~15))) {
    return simde_mm_setzero_si128();
  }

  #if defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) && defined(SIMDE_ENDIAN_ORDER)
    r_.altivec_i8 =
      #if (SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_LITTLE)
        vec_slo
      #else /* SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG */
        vec_sro
      #endif
        (a_.altivec_i8, vec_splats(HEDLEY_STATIC_CAST(unsigned char, imm8 * 8)));
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    r_.altivec_i8 = vec_srb(a_.altivec_i8, vec_splats(HEDLEY_STATIC_CAST(unsigned char, (imm8 & 15) << 3)));
  #elif defined(SIMDE_HAVE_INT128_) && (SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_LITTLE)
    r_.u128[0] = a_.u128[0] << (imm8 * 8);
  #else
    r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    for (int i = imm8 ; i < HEDLEY_STATIC_CAST(int, sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i - imm8];
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
  #define simde_mm_bslli_si128(a, imm8) _mm_slli_si128(a, imm8)
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_mm_bslli_si128(a, imm8) \
  (((imm8)<=0) ? (a) : (((imm8)>15) ? simde_mm_setzero_si128() : simde__m128i_from_lsx_i8((v16i8)__lsx_vbsll_v(simde__m128i_to_private(a).lsx_i64, (imm8)))))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(__clang__)
  #define simde_mm_bslli_si128(a, imm8) \
  simde__m128i_from_neon_i8(((imm8) <= 0) ? simde__m128i_to_neon_i8(a) : (((imm8) > 15) ? (vdupq_n_s8(0)) : (vextq_s8(vdupq_n_s8(0), simde__m128i_to_neon_i8(a), 16 - (imm8)))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_bslli_si128(a, imm8) __extension__ ({        \
    simde__m128i_from_wasm_v128(                                \
      wasm_i8x16_shuffle(wasm_i32x4_splat(INT32_C(0)),          \
                         simde__m128i_to_wasm_v128((a)),        \
                         ((imm8)&0xF0) ? 0 : 16 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 17 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 18 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 19 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 20 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 21 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 22 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 23 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 24 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 25 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 26 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 27 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 28 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 29 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 30 - ((imm8)&0xF), \
                         ((imm8)&0xF0) ? 0 : 31 - ((imm8)&0xF))); })
#elif defined(SIMDE_SHUFFLE_VECTOR_) && !defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) && !defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
  #define simde_mm_bslli_si128(a, imm8) (__extension__ ({ \
    const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
    const simde__m128i_private simde_tmp_z_ = simde__m128i_to_private(simde_mm_setzero_si128()); \
    simde__m128i_private simde_tmp_r_; \
    if (HEDLEY_UNLIKELY(imm8 > 15)) { \
      simde_tmp_r_ = simde__m128i_to_private(simde_mm_setzero_si128()); \
    } else { \
      simde_tmp_r_.i8 = \
        SIMDE_SHUFFLE_VECTOR_(8, 16, \
          simde_tmp_z_.i8, \
          (simde_tmp_a_).i8, \
          HEDLEY_STATIC_CAST(int8_t, (16 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (17 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (18 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (19 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (20 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (21 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (22 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (23 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (24 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (25 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (26 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (27 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (28 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (29 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (30 - imm8) & 31), \
          HEDLEY_STATIC_CAST(int8_t, (31 - imm8) & 31)); \
    } \
    simde__m128i_from_private(simde_tmp_r_); }))
#endif
#define simde_mm_slli_si128(a, imm8) simde_mm_bslli_si128(a, imm8)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_bslli_si128(a, imm8) simde_mm_bslli_si128(a, imm8)
  #define _mm_slli_si128(a, imm8) simde_mm_bslli_si128(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_bsrli_si128 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  if (HEDLEY_UNLIKELY((imm8 & ~15))) {
    return simde_mm_setzero_si128();
  }

  #if defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) && defined(SIMDE_ENDIAN_ORDER)
    r_.altivec_i8 =
    #if (SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_LITTLE)
      vec_sro
    #else /* SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG */
      vec_slo
    #endif
        (a_.altivec_i8, vec_splats(HEDLEY_STATIC_CAST(unsigned char, imm8 * 8)));
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    r_.altivec_i8 = vec_slb(a_.altivec_i8, vec_splats(HEDLEY_STATIC_CAST(unsigned char, (imm8 & 15) << 3)));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      const int e = HEDLEY_STATIC_CAST(int, i) + imm8;
      r_.i8[i] = (e < 16) ? a_.i8[e] : 0;
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
  #define simde_mm_bsrli_si128(a, imm8) _mm_srli_si128(a, imm8)
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_mm_bsrli_si128(a, imm8) \
  (((imm8)<=0) ? (a) : (((imm8)>15) ? simde_mm_setzero_si128() : simde__m128i_from_lsx_i8((v16i8)__lsx_vbsrl_v(simde__m128i_to_private(a).lsx_i64, (imm8)))))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(__clang__)
  #define simde_mm_bsrli_si128(a, imm8) \
  simde__m128i_from_neon_i8(((imm8 < 0) || (imm8 > 15)) ? vdupq_n_s8(0) : (vextq_s8(simde__m128i_to_private(a).neon_i8, vdupq_n_s8(0), ((imm8 & 15) != 0) ? imm8 : (imm8 & 15))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_bsrli_si128(a, imm8) (__extension__ ({ \
    const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
    const simde__m128i_private simde_tmp_z_ = simde__m128i_to_private(simde_mm_setzero_si128()); \
    simde__m128i_private simde_tmp_r_ = simde__m128i_to_private(a); \
    if (HEDLEY_UNLIKELY(imm8 > 15)) { \
      simde_tmp_r_ = simde__m128i_to_private(simde_mm_setzero_si128()); \
    } else { \
      simde_tmp_r_.wasm_v128 = \
      wasm_i8x16_shuffle( \
        simde_tmp_z_.wasm_v128, \
        simde_tmp_a_.wasm_v128, \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 16) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 17) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 18) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 19) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 20) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 21) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 22) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 23) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 24) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 25) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 26) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 27) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 28) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 29) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 30) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 31) & 31)); \
    } \
    simde__m128i_from_private(simde_tmp_r_); }))
#elif defined(SIMDE_SHUFFLE_VECTOR_) && !defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) && !defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
  #define simde_mm_bsrli_si128(a, imm8) (__extension__ ({ \
    const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
    const simde__m128i_private simde_tmp_z_ = simde__m128i_to_private(simde_mm_setzero_si128()); \
    simde__m128i_private simde_tmp_r_ = simde__m128i_to_private(a); \
    if (HEDLEY_UNLIKELY(imm8 > 15)) { \
      simde_tmp_r_ = simde__m128i_to_private(simde_mm_setzero_si128()); \
    } else { \
      simde_tmp_r_.i8 = \
      SIMDE_SHUFFLE_VECTOR_(8, 16, \
        simde_tmp_z_.i8, \
        (simde_tmp_a_).i8, \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 16) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 17) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 18) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 19) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 20) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 21) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 22) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 23) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 24) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 25) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 26) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 27) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 28) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 29) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 30) & 31), \
        HEDLEY_STATIC_CAST(int8_t, (imm8 + 31) & 31)); \
    } \
    simde__m128i_from_private(simde_tmp_r_); }))
#endif
#define simde_mm_srli_si128(a, imm8) simde_mm_bsrli_si128((a), (imm8))
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_bsrli_si128(a, imm8) simde_mm_bsrli_si128((a), (imm8))
  #define _mm_srli_si128(a, imm8) simde_mm_bsrli_si128((a), (imm8))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_clflush (void const* p) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_clflush(p);
  #else
    (void) p;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_clflush(p) simde_mm_clflush(p)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_comieq_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_comieq_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      return !!vgetq_lane_u64(vceqq_f64(a_.neon_f64, b_.neon_f64), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) == wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return !!__lsx_vpickve2gr_d(__lsx_vfcmp_ceq_d(b_.lsx_f64, a_.lsx_f64), 0);
    #else
      return a_.f64[0] == b_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_comieq_sd(a, b) simde_mm_comieq_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_comige_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_comige_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      return !!vgetq_lane_u64(vcgeq_f64(a_.neon_f64, b_.neon_f64), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) >= wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return !!__lsx_vpickve2gr_d(__lsx_vfcmp_cle_d(b_.lsx_f64, a_.lsx_f64), 0);
    #else
      return a_.f64[0] >= b_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_comige_sd(a, b) simde_mm_comige_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_comigt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_comigt_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      return !!vgetq_lane_u64(vcgtq_f64(a_.neon_f64, b_.neon_f64), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) > wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return !!__lsx_vpickve2gr_d(__lsx_vfcmp_clt_d(b_.lsx_f64, a_.lsx_f64), 0);
    #else
      return a_.f64[0] > b_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_comigt_sd(a, b) simde_mm_comigt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_comile_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_comile_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      return !!vgetq_lane_u64(vcleq_f64(a_.neon_f64, b_.neon_f64), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) <= wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return !!__lsx_vpickve2gr_d(__lsx_vfcmp_cle_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      return a_.f64[0] <= b_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_comile_sd(a, b) simde_mm_comile_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_comilt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_comilt_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      return !!vgetq_lane_u64(vcltq_f64(a_.neon_f64, b_.neon_f64), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) < wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return !!__lsx_vpickve2gr_d(__lsx_vfcmp_clt_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      return a_.f64[0] < b_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_comilt_sd(a, b) simde_mm_comilt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_comineq_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_comineq_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      return !vgetq_lane_u64(vceqq_f64(a_.neon_f64, b_.neon_f64), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) != wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return !__lsx_vpickve2gr_d(__lsx_vfcmp_ceq_d(b_.lsx_f64, a_.lsx_f64), 0);
    #else
      return a_.f64[0] != b_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_comineq_sd(a, b) simde_mm_comineq_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_copysign_pd(simde__m128d dest, simde__m128d src) {
  simde__m128d_private
    r_,
    dest_ = simde__m128d_to_private(dest),
    src_ = simde__m128d_to_private(src);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t sign_pos = vreinterpretq_u64_f64(vdupq_n_f64(-SIMDE_FLOAT64_C(0.0)));
    #else
      simde_float64 dbl_nz = -SIMDE_FLOAT64_C(0.0);
      uint64_t u64_nz;
      simde_memcpy(&u64_nz, &dbl_nz, sizeof(u64_nz));
      uint64x2_t sign_pos = vdupq_n_u64(u64_nz);
    #endif
    r_.neon_u64 = vbslq_u64(sign_pos, src_.neon_u64, dest_.neon_u64);
  #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    #if defined(SIMDE_BUG_VEC_CPSGN_REVERSED_ARGS)
      r_.altivec_f64 = vec_cpsgn(dest_.altivec_f64, src_.altivec_f64);
    #else
      r_.altivec_f64 = vec_cpsgn(src_.altivec_f64, dest_.altivec_f64);
    #endif
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    const v2f64 sign_pos = {-0.0f, -0.0f};
    r_.lsx_i64 = __lsx_vbitsel_v(dest_.lsx_i64, src_.lsx_i64, (v2i64)sign_pos);
  #elif defined(simde_math_copysign)
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = simde_math_copysign(dest_.f64[i], src_.f64[i]);
    }
  #else
    simde__m128d sgnbit = simde_mm_set1_pd(-SIMDE_FLOAT64_C(0.0));
    return simde_mm_xor_pd(simde_mm_and_pd(sgnbit, src), simde_mm_andnot_pd(sgnbit, dest));
  #endif

  return simde__m128d_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_xorsign_pd(simde__m128d dest, simde__m128d src) {
  return simde_mm_xor_pd(simde_mm_and_pd(simde_mm_set1_pd(-0.0), src), dest);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_castpd_ps (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_castpd_ps(a);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vreinterpretq_f32_f64(a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return (simde__m128)a;
  #else
    simde__m128 r;
    simde_memcpy(&r, &a, sizeof(a));
    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_castpd_ps(a) simde_mm_castpd_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_castpd_si128 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_castpd_si128(a);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vreinterpretq_s64_f64(a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return (simde__m128i)a;
  #else
    simde__m128i r;
    simde_memcpy(&r, &a, sizeof(a));
    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_castpd_si128(a) simde_mm_castpd_si128(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_castps_pd (simde__m128 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_castps_pd(a);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vreinterpretq_f64_f32(a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return (simde__m128d)a;
  #else
    simde__m128d r;
    simde_memcpy(&r, &a, sizeof(a));
    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_castps_pd(a) simde_mm_castps_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_castps_si128 (simde__m128 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_castps_si128(a);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return simde__m128i_from_neon_i32(simde__m128_to_private(a).neon_i32);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return (simde__m128i)a;
  #else
    simde__m128i r;
    simde_memcpy(&r, &a, sizeof(a));
    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_castps_si128(a) simde_mm_castps_si128(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_castsi128_pd (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_castsi128_pd(a);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vreinterpretq_f64_s64(a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return (simde__m128d)a;
  #else
    simde__m128d r;
    simde_memcpy(&r, &a, sizeof(a));
    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_castsi128_pd(a) simde_mm_castsi128_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_castsi128_ps (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_castsi128_ps(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(float), a);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return simde__m128_from_neon_i32(simde__m128i_to_private(a).neon_i32);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return HEDLEY_REINTERPRET_CAST(__m128, a);
  #else
    simde__m128 r;
    simde_memcpy(&r, &a, sizeof(a));
    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_castsi128_ps(a) simde_mm_castsi128_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpeq_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpeq_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vceqq_s8(b_.neon_i8, a_.neon_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_eq(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i8 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed char), vec_cmpeq(a_.altivec_i8, b_.altivec_i8));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vseq_b(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i8), (a_.i8 == b_.i8));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = (a_.i8[i] == b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpeq_epi8(a, b) simde_mm_cmpeq_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpeq_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpeq_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vceqq_s16(b_.neon_i16, a_.neon_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_eq(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i16 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed short), vec_cmpeq(a_.altivec_i16, b_.altivec_i16));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vseq_h(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = (a_.i16 == b_.i16);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = (a_.i16[i] == b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpeq_epi16(a, b) simde_mm_cmpeq_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpeq_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpeq_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u32 = vceqq_s32(b_.neon_i32, a_.neon_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_eq(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i32 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed int), vec_cmpeq(a_.altivec_i32, b_.altivec_i32));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vseq_w(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i32), a_.i32 == b_.i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = (a_.i32[i] == b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpeq_epi32(a, b) simde_mm_cmpeq_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpeq_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpeq_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_u64 = vceqq_f64(b_.neon_f64, a_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_eq(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(double), vec_cmpeq(a_.altivec_f64, b_.altivec_f64));
    #elif defined(SIMDE_MIPS_MSA_NATIVE)
      r_.msa_i32 = __msa_addv_w(a_.msa_i32, b_.msa_i32);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vfcmp_ceq_d(a_.lsx_f64, b_.lsx_f64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i64), (a_.f64 == b_.f64));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (a_.f64[i] == b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpeq_pd(a, b) simde_mm_cmpeq_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpeq_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpeq_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmpeq_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmpeq_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfcmp_ceq_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.u64[0] = (a_.u64[0] == b_.u64[0]) ? ~UINT64_C(0) : 0;
      r_.u64[1] = a_.u64[1];
    #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpeq_sd(a, b) simde_mm_cmpeq_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpneq_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpneq_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_u32 = vmvnq_u32(vreinterpretq_u32_u64(vceqq_f64(b_.neon_f64, a_.neon_f64)));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_ne(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vfcmp_cune_d(a_.lsx_f64, b_.lsx_f64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i64), (a_.f64 != b_.f64));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (a_.f64[i] != b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpneq_pd(a, b) simde_mm_cmpneq_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpneq_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpneq_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmpneq_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmpneq_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfcmp_cune_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.u64[0] = (a_.f64[0] != b_.f64[0]) ? ~UINT64_C(0) : UINT64_C(0);
      r_.u64[1] = a_.u64[1];
    #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpneq_sd(a, b) simde_mm_cmpneq_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmplt_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmplt_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vcltq_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i8 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed char),vec_cmplt(a_.altivec_i8, b_.altivec_i8));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_lt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vslt_b(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i8), (a_.i8 < b_.i8));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = (a_.i8[i] < b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmplt_epi8(a, b) simde_mm_cmplt_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmplt_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmplt_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vcltq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i16 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed short), vec_cmplt(a_.altivec_i16, b_.altivec_i16));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_lt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vslt_h(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i16), (a_.i16 < b_.i16));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = (a_.i16[i] < b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmplt_epi16(a, b) simde_mm_cmplt_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmplt_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmplt_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u32 = vcltq_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i32 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed int), vec_cmplt(a_.altivec_i32, b_.altivec_i32));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_lt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vslt_w(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i32), (a_.i32 < b_.i32));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = (a_.i32[i] < b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmplt_epi32(a, b) simde_mm_cmplt_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmplt_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmplt_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_u64 = vcltq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(double), vec_cmplt(a_.altivec_f64, b_.altivec_f64));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_lt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vfcmp_clt_d(a_.lsx_f64, b_.lsx_f64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i64), (a_.f64 < b_.f64));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (a_.f64[i] < b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmplt_pd(a, b) simde_mm_cmplt_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmplt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmplt_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmplt_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmplt_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfcmp_clt_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.u64[0] = (a_.f64[0] < b_.f64[0]) ? ~UINT64_C(0) : UINT64_C(0);
      r_.u64[1] = a_.u64[1];
    #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmplt_sd(a, b) simde_mm_cmplt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmple_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmple_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i64), (a_.f64 <= b_.f64));
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_u64 = vcleq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_le(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(double), vec_cmple(a_.altivec_f64, b_.altivec_f64));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vfcmp_cle_d(a_.lsx_f64, b_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (a_.f64[i] <= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmple_pd(a, b) simde_mm_cmple_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmple_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmple_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmple_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmple_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfcmp_cle_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.u64[0] = (a_.f64[0] <= b_.f64[0]) ? ~UINT64_C(0) : UINT64_C(0);
      r_.u64[1] = a_.u64[1];
    #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmple_sd(a, b) simde_mm_cmple_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpgt_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpgt_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vcgtq_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_gt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i8 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed char), vec_cmpgt(a_.altivec_i8, b_.altivec_i8));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vslt_b(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i8), (a_.i8 > b_.i8));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = (a_.i8[i] > b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpgt_epi8(a, b) simde_mm_cmpgt_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpgt_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpgt_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vcgtq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_gt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i16 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed short), vec_cmpgt(a_.altivec_i16, b_.altivec_i16));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vslt_h(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i16), (a_.i16 > b_.i16));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpgt_epi16(a, b) simde_mm_cmpgt_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpgt_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpgt_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u32 = vcgtq_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_gt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i32 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed int), vec_cmpgt(a_.altivec_i32, b_.altivec_i32));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vslt_w(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i32), (a_.i32 > b_.i32));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = (a_.i32[i] > b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpgt_epi32(a, b) simde_mm_cmpgt_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpgt_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpgt_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i64), (a_.f64 > b_.f64));
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_u64 = vcgtq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_gt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(double), vec_cmpgt(a_.altivec_f64, b_.altivec_f64));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vfcmp_clt_d(b_.lsx_f64, a_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (a_.f64[i] > b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpgt_pd(a, b) simde_mm_cmpgt_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpgt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
    return _mm_cmpgt_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmpgt_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmpgt_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfcmp_clt_d(b_.lsx_f64, a_.lsx_f64), 0);
    #else
      r_.u64[0] = (a_.f64[0] > b_.f64[0]) ? ~UINT64_C(0) : UINT64_C(0);
      r_.u64[1] = a_.u64[1];
    #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpgt_sd(a, b) simde_mm_cmpgt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpge_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpge_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i64), (a_.f64 >= b_.f64));
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_u64 = vcgeq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_ge(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(double), vec_cmpge(a_.altivec_f64, b_.altivec_f64));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vfcmp_cle_d(b_.lsx_f64, a_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (a_.f64[i] >= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpge_pd(a, b) simde_mm_cmpge_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpge_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
    return _mm_cmpge_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmpge_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmpge_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfcmp_cle_d(b_.lsx_f64, a_.lsx_f64), 0);
    #else
      r_.u64[0] = (a_.f64[0] >= b_.f64[0]) ? ~UINT64_C(0) : UINT64_C(0);
      r_.u64[1] = a_.u64[1];
    #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpge_sd(a, b) simde_mm_cmpge_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpngt_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpngt_pd(a, b);
  #else
    return simde_mm_cmple_pd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpngt_pd(a, b) simde_mm_cmpngt_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpngt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
    return _mm_cmpngt_sd(a, b);
  #else
    return simde_mm_cmple_sd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpngt_sd(a, b) simde_mm_cmpngt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpnge_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpnge_pd(a, b);
  #else
    return simde_mm_cmplt_pd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpnge_pd(a, b) simde_mm_cmpnge_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpnge_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
    return _mm_cmpnge_sd(a, b);
  #else
    return simde_mm_cmplt_sd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpnge_sd(a, b) simde_mm_cmpnge_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpnlt_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpnlt_pd(a, b);
  #else
    return simde_mm_cmpge_pd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpnlt_pd(a, b) simde_mm_cmpnlt_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpnlt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpnlt_sd(a, b);
  #else
    return simde_mm_cmpge_sd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpnlt_sd(a, b) simde_mm_cmpnlt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpnle_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpnle_pd(a, b);
  #else
    return simde_mm_cmpgt_pd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpnle_pd(a, b) simde_mm_cmpnle_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpnle_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpnle_sd(a, b);
  #else
    return simde_mm_cmpgt_sd(a, b);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpnle_sd(a, b) simde_mm_cmpnle_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpord_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpord_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      /* Note: NEON does not have ordered compare builtin
        Need to compare a eq a and b eq b to check for NaN
        Do AND of results to get final */
      uint64x2_t ceqaa = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t ceqbb = vceqq_f64(b_.neon_f64, b_.neon_f64);
      r_.neon_u64 = vandq_u64(ceqaa, ceqbb);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_and(wasm_f64x2_eq(a_.wasm_v128, a_.wasm_v128),
                                   wasm_f64x2_eq(b_.wasm_v128, b_.wasm_v128));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vand_v(__lsx_vfcmp_ceq_d(a_.lsx_f64, a_.lsx_f64),
                                __lsx_vfcmp_ceq_d(b_.lsx_f64, b_.lsx_f64));
    #elif defined(simde_math_isnan)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (!simde_math_isnan(a_.f64[i]) && !simde_math_isnan(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpord_pd(a, b) simde_mm_cmpord_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64
simde_mm_cvtsd_f64 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
    return _mm_cvtsd_f64(a);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      return HEDLEY_STATIC_CAST(simde_float64, vgetq_lane_f64(a_.neon_f64, 0));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return HEDLEY_STATIC_CAST(simde_float64, wasm_f64x2_extract_lane(a_.wasm_v128, 0));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __lsx_vstelm_d(a_.lsx_i64, &a_.f64, 0, 0);
      return a_.f64[0];
    #else
      return a_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtsd_f64(a) simde_mm_cvtsd_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpord_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpord_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmpord_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmpord_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, __lsx_vand_v(__lsx_vfcmp_ceq_d(a_.lsx_f64,
                                    a_.lsx_f64), __lsx_vfcmp_ceq_d(b_.lsx_f64, b_.lsx_f64)), 0);
    #elif defined(simde_math_isnan)
      r_.u64[0] = (!simde_math_isnan(a_.f64[0]) && !simde_math_isnan(b_.f64[0])) ? ~UINT64_C(0) : UINT64_C(0);
      r_.u64[1] = a_.u64[1];
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpord_sd(a, b) simde_mm_cmpord_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpunord_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpunord_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t ceqaa = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t ceqbb = vceqq_f64(b_.neon_f64, b_.neon_f64);
      r_.neon_u64 = vreinterpretq_u64_u32(vmvnq_u32(vreinterpretq_u32_u64(vandq_u64(ceqaa, ceqbb))));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_or(wasm_f64x2_ne(a_.wasm_v128, a_.wasm_v128),
                                  wasm_f64x2_ne(b_.wasm_v128, b_.wasm_v128));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vor_v(__lsx_vfcmp_cune_d(a_.lsx_f64, a_.lsx_f64),
                               __lsx_vfcmp_cune_d(b_.lsx_f64, b_.lsx_f64));
    #elif defined(simde_math_isnan)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.u64[i] = (simde_math_isnan(a_.f64[i]) || simde_math_isnan(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
      }
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpunord_pd(a, b) simde_mm_cmpunord_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmpunord_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cmpunord_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_cmpunord_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_cmpunord_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, __lsx_vor_v(__lsx_vfcmp_cune_d(a_.lsx_f64, a_.lsx_f64), __lsx_vfcmp_cune_d(b_.lsx_f64, b_.lsx_f64)), 0);
    #elif defined(simde_math_isnan)
      r_.u64[0] = (simde_math_isnan(a_.f64[0]) || simde_math_isnan(b_.f64[0])) ? ~UINT64_C(0) : UINT64_C(0);
      r_.u64[1] = a_.u64[1];
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpunord_sd(a, b) simde_mm_cmpunord_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cvtepi32_pd (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtepi32_pd(a);
  #else
    simde__m128d_private r_;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_convert_low_i32x4(a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vffintl_d_w(a_.lsx_i64);
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.f64, a_.m64_private[0].i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = (simde_float64) a_.i32[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtepi32_pd(a) simde_mm_cvtepi32_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtepi32_ps (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtepi32_ps(a);
  #else
    simde__m128_private r_;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_f32 = vcvtq_f32_s32(a_.neon_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f32x4_convert_i32x4(a_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      HEDLEY_DIAGNOSTIC_PUSH
      #if HEDLEY_HAS_WARNING("-Wc11-extensions")
        #pragma clang diagnostic ignored "-Wc11-extensions"
      #endif
      r_.altivec_f32 = vec_ctf(a_.altivec_i32, 0);
      HEDLEY_DIAGNOSTIC_POP
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f32 = __lsx_vffint_s_w(a_.lsx_i64);
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.f32, a_.i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        r_.f32[i] = (simde_float32) a_.i32[i];
      }
    #endif

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtepi32_ps(a) simde_mm_cvtepi32_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtpd_pi32 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_cvtpd_pi32(a);
  #else
    simde__m64_private r_;
    simde__m128d_private a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      simde_float64 v = simde_math_round(a_.f64[i]);
      #if defined(SIMDE_FAST_CONVERSION_RANGE)
        r_.i32[i] = SIMDE_CONVERT_FTOI(int32_t, v);
      #else
        r_.i32[i] = ((v > HEDLEY_STATIC_CAST(simde_float64, INT32_MIN)) && (v < HEDLEY_STATIC_CAST(simde_float64, INT32_MAX))) ?
          SIMDE_CONVERT_FTOI(int32_t, v) : INT32_MIN;
      #endif
    }

    return simde__m64_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtpd_pi32(a) simde_mm_cvtpd_pi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtpd_epi32 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(SIMDE_BUG_PGI_30107)
    return _mm_cvtpd_epi32(a);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE) && defined(SIMDE_FAST_NANS)
      const v2f64 zero_f64 = {-0.0f, -0.0f};
      r_.lsx_i64 = __lsx_vftintrne_w_d(zero_f64, simde__m128d_to_private(a).lsx_f64);
    #else
      r_.m64[0] = simde_mm_cvtpd_pi32(a);
      r_.m64[1] = simde_mm_setzero_si64();
    #endif
    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtpd_epi32(a) simde_mm_cvtpd_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpd_ps (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtpd_ps(a);
  #else
    simde__m128_private r_;
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f32 = vcombine_f32(vcvt_f32_f64(a_.neon_f64), vdup_n_f32(0.0f));
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r_.altivec_f32 = vec_float2(a_.altivec_f64, vec_splats(0.0));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f32x4_demote_f64x2_zero(a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      const v2f64 zero_f64 = {-0.0f, -0.0f};
      r_.lsx_f32 = __lsx_vfcvt_s_d(zero_f64, a_.lsx_f64);
    #elif HEDLEY_HAS_BUILTIN(__builtin_shufflevector) && HEDLEY_HAS_BUILTIN(__builtin_convertvector)
      float __attribute__((__vector_size__(8))) z = { 0.0f, 0.0f };
      r_.f32 =
        __builtin_shufflevector(
          __builtin_convertvector(__builtin_shufflevector(a_.f64, a_.f64, 0, 1), __typeof__(z)), z,
          0, 1, 2, 3
        );
    #else
      r_.f32[0] = HEDLEY_STATIC_CAST(simde_float32, a_.f64[0]);
      r_.f32[1] = HEDLEY_STATIC_CAST(simde_float32, a_.f64[1]);
      r_.f32[2] = SIMDE_FLOAT32_C(0.0);
      r_.f32[3] = SIMDE_FLOAT32_C(0.0);
    #endif

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtpd_ps(a) simde_mm_cvtpd_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cvtpi32_pd (simde__m64 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_cvtpi32_pd(a);
  #else
    simde__m128d_private r_;
    simde__m64_private a_ = simde__m64_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.f64, a_.i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = (simde_float64) a_.i32[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtpi32_pd(a) simde_mm_cvtpi32_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtps_epi32 (simde__m128 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtps_epi32(a);
  #else
    simde__m128i_private r_;
    simde__m128_private a_;

    #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FAST_ROUND_TIES) && !defined(SIMDE_BUG_GCC_95399)
      a_ = simde__m128_to_private(a);
      r_.neon_i32 = vcvtnq_s32_f32(a_.neon_f32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FAST_ROUND_TIES)
      a_ = simde__m128_to_private(a);
      HEDLEY_DIAGNOSTIC_PUSH
      SIMDE_DIAGNOSTIC_DISABLE_C11_EXTENSIONS_
      SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_
      r_.altivec_i32 = vec_cts(a_.altivec_f32, 1);
      HEDLEY_DIAGNOSTIC_POP
    #elif defined(SIMDE_WASM_SIMD128_NATIVE) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FAST_ROUND_TIES)
      a_ = simde__m128_to_private(a);
      r_.wasm_v128 = wasm_i32x4_trunc_sat_f32x4(a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FAST_ROUND_TIES)
      a_ = simde__m128_to_private(a);
      r_.lsx_i32 = __lsx_vftintrne_w_s(a_.lsx_f32);
    #else
      a_ = simde__m128_to_private(simde_x_mm_round_ps(a, SIMDE_MM_FROUND_TO_NEAREST_INT, 1));
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        simde_float32 v = simde_math_roundf(a_.f32[i]);
        #if defined(SIMDE_FAST_CONVERSION_RANGE)
          r_.i32[i] = SIMDE_CONVERT_FTOI(int32_t, v);
        #else
          r_.i32[i] = ((v > HEDLEY_STATIC_CAST(simde_float32, INT32_MIN)) && (v < HEDLEY_STATIC_CAST(simde_float32, INT32_MAX))) ?
            SIMDE_CONVERT_FTOI(int32_t, v) : INT32_MIN;
        #endif
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtps_epi32(a) simde_mm_cvtps_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cvtps_pd (simde__m128 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtps_pd(a);
  #else
    simde__m128d_private r_;
    simde__m128_private a_ = simde__m128_to_private(a);

    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_promote_low_f32x4(a_.wasm_v128);
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.f64, a_.m64_private[0].f32);
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vcvt_f64_f32(vget_low_f32(a_.neon_f32));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 =  __lsx_vfcvtl_d_s(a_.lsx_f32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = a_.f32[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtps_pd(a) simde_mm_cvtps_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtsd_si32 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtsd_si32(a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE) && defined(SIMDE_FAST_CONVERSION_RANGE)
     simde__m128d_private a_ = simde__m128d_to_private(a);
     return __lsx_vpickve2gr_w(__lsx_vftintrne_w_d(a_.lsx_f64, a_.lsx_f64), 0);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);

    simde_float64 v = simde_math_round(a_.f64[0]);
    #if defined(SIMDE_FAST_CONVERSION_RANGE)
      return SIMDE_CONVERT_FTOI(int32_t, v);
    #else
      return ((v > HEDLEY_STATIC_CAST(simde_float64, INT32_MIN)) && (v < HEDLEY_STATIC_CAST(simde_float64, INT32_MAX))) ?
        SIMDE_CONVERT_FTOI(int32_t, v) : INT32_MIN;
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtsd_si32(a) simde_mm_cvtsd_si32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvtsd_si64 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64)
    #if defined(__PGI)
      return _mm_cvtsd_si64x(a);
    #else
      return _mm_cvtsd_si64(a);
    #endif
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);
    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
       return __lsx_vpickve2gr_d(__lsx_vftintrne_l_d(a_.lsx_f64), 0);
    #else
       return SIMDE_CONVERT_FTOI(int64_t, simde_math_round(a_.f64[0]));
    #endif
  #endif
}
#define simde_mm_cvtsd_si64x(a) simde_mm_cvtsd_si64(a)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_AMD64))
  #define _mm_cvtsd_si64(a) simde_mm_cvtsd_si64(a)
  #define _mm_cvtsd_si64x(a) simde_mm_cvtsd_si64x(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtsd_ss (simde__m128 a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtsd_ss(a, b);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);
    simde__m128d_private b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f32 = vsetq_lane_f32(vcvtxd_f32_f64(vgetq_lane_f64(b_.neon_f64, 0)), a_.neon_f32, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_w(a_.lsx_i64, __lsx_vfcvt_s_d(b_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.f32[0] = HEDLEY_STATIC_CAST(simde_float32, b_.f64[0]);

      SIMDE_VECTORIZE
      for (size_t i = 1 ; i < (sizeof(r_) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i];
      }
    #endif
    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtsd_ss(a, b) simde_mm_cvtsd_ss(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_x_mm_cvtsi128_si16 (simde__m128i a) {
  simde__m128i_private
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_s16(a_.neon_i16, 0);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return HEDLEY_STATIC_CAST(int16_t, wasm_i16x8_extract_lane(a_.wasm_v128, 0));
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    #if defined(SIMDE_BUG_GCC_95227)
      (void) a_;
    #endif
    return vec_extract(a_.altivec_i16, 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return __lsx_vpickve2gr_h(a_.lsx_i64, 0);
  #else
    return a_.i16[0];
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtsi128_si32 (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtsi128_si32(a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      return vgetq_lane_s32(a_.neon_i32, 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return HEDLEY_STATIC_CAST(int32_t, wasm_i32x4_extract_lane(a_.wasm_v128, 0));
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      #if defined(SIMDE_BUG_GCC_95227)
        (void) a_;
      #endif
      return vec_extract(a_.altivec_i32, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return __lsx_vpickve2gr_w(a_.lsx_i64, 0);
    #else
      return a_.i32[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtsi128_si32(a) simde_mm_cvtsi128_si32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvtsi128_si64 (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64)
    #if defined(__PGI)
      return _mm_cvtsi128_si64x(a);
    #else
      return _mm_cvtsi128_si64(a);
    #endif
  #else
    simde__m128i_private a_ = simde__m128i_to_private(a);
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) && !defined(HEDLEY_IBM_VERSION)
    return vec_extract(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed long long), a_.i64), 0);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_s64(a_.neon_i64, 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return __lsx_vpickve2gr_d(a_.lsx_i64, 0);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return HEDLEY_STATIC_CAST(int64_t, wasm_i64x2_extract_lane(a_.wasm_v128, 0));
  #endif
    return a_.i64[0];
  #endif
}
#define simde_mm_cvtsi128_si64x(a) simde_mm_cvtsi128_si64(a)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_AMD64))
  #define _mm_cvtsi128_si64(a) simde_mm_cvtsi128_si64(a)
  #define _mm_cvtsi128_si64x(a) simde_mm_cvtsi128_si64x(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cvtsi32_sd (simde__m128d a, int32_t b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtsi32_sd(a, b);
  #else
    simde__m128d_private r_;
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vsetq_lane_f64(HEDLEY_STATIC_CAST(float64_t, b), a_.neon_f64, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      simde_float64 b_float64 = (simde_float64)b;
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, __lsx_vldrepl_d(&(b_float64), 0), 0);
    #else
      r_.f64[0] = HEDLEY_STATIC_CAST(simde_float64, b);
      r_.i64[1] = a_.i64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtsi32_sd(a, b) simde_mm_cvtsi32_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_cvtsi16_si128 (int16_t a) {
  simde__m128i_private r_;

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i16 = vsetq_lane_s16(a, vdupq_n_s16(0), 0);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i16x8_make(a, 0, 0, 0, 0, 0, 0, 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vinsgr2vr_h(__lsx_vreplgr2vr_h(0), a, 0);
  #else
    r_.i16[0] = a;
    r_.i16[1] = 0;
    r_.i16[2] = 0;
    r_.i16[3] = 0;
    r_.i16[4] = 0;
    r_.i16[5] = 0;
    r_.i16[6] = 0;
    r_.i16[7] = 0;
  #endif

  return simde__m128i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsi32_si128 (int32_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtsi32_si128(a);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vsetq_lane_s32(a, vdupq_n_s32(0), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_make(a, 0, 0, 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vinsgr2vr_w(__lsx_vreplgr2vr_w(0), a, 0);
    #else
      r_.i32[0] = a;
      r_.i32[1] = 0;
      r_.i32[2] = 0;
      r_.i32[3] = 0;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtsi32_si128(a) simde_mm_cvtsi32_si128(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cvtsi64_sd (simde__m128d a, int64_t b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64)
    #if !defined(__PGI)
      return _mm_cvtsi64_sd(a, b);
    #else
      return _mm_cvtsi64x_sd(a, b);
    #endif
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vsetq_lane_f64(HEDLEY_STATIC_CAST(float64_t, b), a_.neon_f64, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      simde_float64 b_float64 = (simde_float64)b;
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, __lsx_vldrepl_d(&(b_float64), 0), 0);
    #else
      r_.f64[0] = HEDLEY_STATIC_CAST(simde_float64, b);
      r_.f64[1] = a_.f64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#define simde_mm_cvtsi64x_sd(a, b) simde_mm_cvtsi64_sd(a, b)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_AMD64))
  #define _mm_cvtsi64_sd(a, b) simde_mm_cvtsi64_sd(a, b)
  #define _mm_cvtsi64x_sd(a, b) simde_mm_cvtsi64x_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsi64_si128 (int64_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64)
    #if !defined(__PGI)
      return _mm_cvtsi64_si128(a);
    #else
      return _mm_cvtsi64x_si128(a);
    #endif
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vsetq_lane_s64(a, vdupq_n_s64(0), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_make(a, 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vinsgr2vr_d(__lsx_vreplgr2vr_d(0), a, 0);
    #else
      r_.i64[0] = a;
      r_.i64[1] = 0;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_cvtsi64x_si128(a) simde_mm_cvtsi64_si128(a)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_AMD64))
  #define _mm_cvtsi64_si128(a) simde_mm_cvtsi64_si128(a)
  #define _mm_cvtsi64x_si128(a) simde_mm_cvtsi64x_si128(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cvtss_sd (simde__m128d a, simde__m128 b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvtss_sd(a, b);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    float64x2_t temp = vcvt_f64_f32(vset_lane_f32(vgetq_lane_f32(simde__m128_to_private(b).neon_f32, 0), vdup_n_f32(0), 0));
    return vsetq_lane_f64(vgetq_lane_f64(simde__m128d_to_private(a).neon_f64, 1), temp, 1);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a);
    simde__m128_private b_ = simde__m128_to_private(b);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      a_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfcvtl_d_s(b_.lsx_f32), 0);
    #else
      a_.f64[0] = HEDLEY_STATIC_CAST(simde_float64, b_.f32[0]);
    #endif
    return simde__m128d_from_private(a_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtss_sd(a, b) simde_mm_cvtss_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvttpd_pi32 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_cvttpd_pi32(a);
  #else
    simde__m64_private r_;
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.i32, a_.f64);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        simde_float64 v = a_.f64[i];
        #if defined(SIMDE_FAST_CONVERSION_RANGE)
          r_.i32[i] = SIMDE_CONVERT_FTOI(int32_t, v);
        #else
          r_.i32[i] = ((v > HEDLEY_STATIC_CAST(simde_float64, INT32_MIN)) && (v < HEDLEY_STATIC_CAST(simde_float64, INT32_MAX))) ?
            SIMDE_CONVERT_FTOI(int32_t, v) : INT32_MIN;
        #endif
      }
    #endif

    return simde__m64_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvttpd_pi32(a) simde_mm_cvttpd_pi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvttpd_epi32 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvttpd_epi32(a);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE) && defined(SIMDE_FAST_NANS)
      const v2f64 zero_f64 = {-0.0f, -0.0f};
      r_.lsx_i64 = __lsx_vftintrz_w_d(zero_i64, simde__m128d_to_private(a).lsx_f64);
    #else
    r_.m64[0] = simde_mm_cvttpd_pi32(a);
    r_.m64[1] = simde_mm_setzero_si64();
    #endif
    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvttpd_epi32(a) simde_mm_cvttpd_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvttps_epi32 (simde__m128 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvttps_epi32(a);
  #else
    simde__m128i_private r_;
    simde__m128_private a_ = simde__m128_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vcvtq_s32_f32(a_.neon_f32);

      #if !defined(SIMDE_FAST_CONVERSION_RANGE) || !defined(SIMDE_FAST_NANS)
        /* Values below INT32_MIN saturate anyways, so we don't need to
         * test for that. */
        #if !defined(SIMDE_FAST_CONVERSION_RANGE) && !defined(SIMDE_FAST_NANS)
          uint32x4_t valid_input =
            vandq_u32(
              vcltq_f32(a_.neon_f32, vdupq_n_f32(SIMDE_FLOAT32_C(2147483648.0))),
              vceqq_f32(a_.neon_f32, a_.neon_f32)
            );
        #elif !defined(SIMDE_FAST_CONVERSION_RANGE)
          uint32x4_t valid_input = vcltq_f32(a_.neon_f32, vdupq_n_f32(SIMDE_FLOAT32_C(2147483648.0)));
        #elif !defined(SIMDE_FAST_NANS)
          uint32x4_t valid_input = vceqq_f32(a_.neon_f32, a_.neon_f32);
        #endif

        r_.neon_i32 = vbslq_s32(valid_input, r_.neon_i32, vdupq_n_s32(INT32_MIN));
      #endif
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_trunc_sat_f32x4(a_.wasm_v128);

      #if !defined(SIMDE_FAST_CONVERSION_RANGE) || !defined(SIMDE_FAST_NANS)
        #if !defined(SIMDE_FAST_CONVERSION_RANGE) && !defined(SIMDE_FAST_NANS)
          v128_t valid_input =
            wasm_v128_and(
              wasm_f32x4_lt(a_.wasm_v128, wasm_f32x4_splat(SIMDE_FLOAT32_C(2147483648.0))),
              wasm_f32x4_eq(a_.wasm_v128, a_.wasm_v128)
            );
        #elif !defined(SIMDE_FAST_CONVERSION_RANGE)
          v128_t valid_input = wasm_f32x4_lt(a_.wasm_v128, wasm_f32x4_splat(SIMDE_FLOAT32_C(2147483648.0)));
        #elif !defined(SIMDE_FAST_NANS)
          v128_t valid_input = wasm_f32x4_eq(a_.wasm_v128, a_.wasm_v128);
        #endif

        r_.wasm_v128 = wasm_v128_bitselect(r_.wasm_v128, wasm_i32x4_splat(INT32_MIN), valid_input);
      #endif
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __m128i temp = __lsx_vftintrz_w_s(a_.lsx_f32);
      #if !defined(SIMDE_FAST_CONVERSION_RANGE) || !defined(SIMDE_FAST_NANS)
        #if !defined(SIMDE_FAST_CONVERSION_RANGE) && !defined(SIMDE_FAST_NANS)
          simde_float32 f1 = 2147483648.0f;
          __m128i valid_input =
            __lsx_vand_v(
              __lsx_vfcmp_clt_s(a_.lsx_f32, (__m128)__lsx_vldrepl_w(&f1, 0)),
              __lsx_vfcmp_ceq_s(a_.lsx_f32, a_.lsx_f32)
            );
        #elif !defined(SIMDE_FAST_CONVERSION_RANGE)
          simde_float32 f1 = 2147483648.0f;
          __m128i valid_input = __lsx_vfcmp_clt_s(a_.lsx_f32, (__m128)__lsx_vldrepl_w(&f1, 0));
        #elif !defined(SIMDE_FAST_NANS)
          __m128i valid_input = __lsx_vfcmp_ceq_s(a_.lsx_f32, a_.lsx_f32);
        #endif

        r_.lsx_i64 = __lsx_vbitsel_v(__lsx_vreplgr2vr_w(INT32_MIN), temp, valid_input);
      #endif
    #elif defined(SIMDE_CONVERT_VECTOR_) && !defined(SIMDE_ARCH_POWER)
      SIMDE_CONVERT_VECTOR_(r_.i32, a_.f32);

      #if !defined(SIMDE_FAST_CONVERSION_RANGE) || !defined(SIMDE_FAST_NANS)
        #if !defined(SIMDE_FAST_CONVERSION_RANGE)
          static const simde_float32 SIMDE_VECTOR(16) first_too_high = { SIMDE_FLOAT32_C(2147483648.0), SIMDE_FLOAT32_C(2147483648.0), SIMDE_FLOAT32_C(2147483648.0), SIMDE_FLOAT32_C(2147483648.0) };

          __typeof__(r_.i32) valid_input =
            HEDLEY_REINTERPRET_CAST(
              __typeof__(r_.i32),
              (a_.f32 < first_too_high) & (a_.f32 >= -first_too_high)
            );
        #elif !defined(SIMDE_FAST_NANS)
          __typeof__(r_.i32) valid_input = HEDLEY_REINTERPRET_CAST( __typeof__(valid_input), a_.f32 == a_.f32);
        #endif

        __typeof__(r_.i32) invalid_output = { INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN };
        r_.i32 = (r_.i32 & valid_input) | (invalid_output & ~valid_input);
      #endif
    #else
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        simde_float32 v = a_.f32[i];
        #if defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FAST_NANS)
          r_.i32[i] = SIMDE_CONVERT_FTOI(int32_t, v);
        #else
          r_.i32[i] = ((v > HEDLEY_STATIC_CAST(simde_float32, INT32_MIN)) && (v < HEDLEY_STATIC_CAST(simde_float32, INT32_MAX))) ?
            SIMDE_CONVERT_FTOI(int32_t, v) : INT32_MIN;
        #endif
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvttps_epi32(a) simde_mm_cvttps_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvttsd_si32 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_cvttsd_si32(a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE) && defined(SIMDE_FAST_CONVERSION_RANGE)
    simde__m128d_private a_ = simde__m128d_to_private(a);
    return __lsx_vpickve2gr_w(__lsx_vftintrz_w_d(a_.lsx_f64, a_.lsx_f64), 0);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);
    simde_float64 v = a_.f64[0];
    #if defined(SIMDE_FAST_CONVERSION_RANGE)
      return SIMDE_CONVERT_FTOI(int32_t, v);
    #else
      return ((v > HEDLEY_STATIC_CAST(simde_float64, INT32_MIN)) && (v < HEDLEY_STATIC_CAST(simde_float64, INT32_MAX))) ?
        SIMDE_CONVERT_FTOI(int32_t, v) : INT32_MIN;
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_cvttsd_si32(a) simde_mm_cvttsd_si32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvttsd_si64 (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64)
    #if !defined(__PGI)
      return _mm_cvttsd_si64(a);
    #else
      return _mm_cvttsd_si64x(a);
    #endif
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    simde__m128d_private a_ = simde__m128d_to_private(a);
    return __lsx_vpickve2gr_d(__lsx_vftintrz_l_d(a_.lsx_f64), 0);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);
    return SIMDE_CONVERT_FTOI(int64_t, a_.f64[0]);
  #endif
}
#define simde_mm_cvttsd_si64x(a) simde_mm_cvttsd_si64(a)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_AMD64))
  #define _mm_cvttsd_si64(a) simde_mm_cvttsd_si64(a)
  #define _mm_cvttsd_si64x(a) simde_mm_cvttsd_si64x(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_div_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 / b_.f64;
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vdivq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 =  wasm_f64x2_div(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vfdiv_d(b_.lsx_f64, a_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = a_.f64[i] / b_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_div_pd(a, b) simde_mm_div_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_div_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_div_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_div_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      float64x2_t temp = vdivq_f64(a_.neon_f64, b_.neon_f64);
      r_.neon_f64 = vsetq_lane_f64(vgetq_lane(a_.neon_f64, 1), temp, 1);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __m128d temp = __lsx_vfdiv_d(a_.lsx_f64, b_.lsx_f64);
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)temp, 0);
    #else
      r_.f64[0] = a_.f64[0] / b_.f64[0];
      r_.f64[1] = a_.f64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_div_sd(a, b) simde_mm_div_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_mm_extract_epi16 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 7)  {
  uint16_t r;
  simde__m128i_private a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    #if defined(SIMDE_BUG_GCC_95227)
      (void) a_;
      (void) imm8;
    #endif
    r = HEDLEY_STATIC_CAST(uint16_t, vec_extract(a_.altivec_i16, imm8));
  #else
    r = a_.u16[imm8 & 7];
  #endif

  return  HEDLEY_STATIC_CAST(int32_t, r);
}
#if defined(SIMDE_X86_SSE2_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(4,6,0))
  #define simde_mm_extract_epi16(a, imm8) _mm_extract_epi16(a, imm8)
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_extract_epi16(a, imm8) (HEDLEY_STATIC_CAST(int32_t, vgetq_lane_s16(simde__m128i_to_private(a).neon_i16, (imm8))) & (INT32_C(0x0000ffff)))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_extract_epi16(a, imm8) HEDLEY_STATIC_CAST(int32_t, wasm_u16x8_extract_lane(simde__m128i_to_wasm_v128((a)), (imm8) & 7))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    #define simde_mm_extract_epi16(a, imm8) HEDLEY_STATIC_CAST(int32_t, __lsx_vpickve2gr_hu(simde__m128i_to_private(a).lsx_i64, imm8))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_extract_epi16(a, imm8) simde_mm_extract_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_insert_epi16 (simde__m128i a, int16_t i, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 7)  {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  a_.i16[imm8 & 7] = i;
  return simde__m128i_from_private(a_);
}
#if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
  #define simde_mm_insert_epi16(a, i, imm8) _mm_insert_epi16((a), (i), (imm8))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_insert_epi16(a, i, imm8) simde__m128i_from_neon_i16(vsetq_lane_s16((i), simde__m128i_to_neon_i16(a), (imm8)))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_insert_epi16(a, i, imm8) wasm_i16x8_replace_lane(simde__m128i_to_wasm_v128((a)), (imm8) & 7, (i))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_mm_insert_epi16(a, i, imm8) simde__m128i_from_lsx_i16((v8i16)__lsx_vinsgr2vr_h(simde__m128i_to_private(a).lsx_i64, i, imm8))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_insert_epi16(a, i, imm8) simde_mm_insert_epi16(a, i, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_load_pd (simde_float64 const mem_addr[HEDLEY_ARRAY_PARAM(2)]) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_load_pd(mem_addr);
  #else
    simde__m128d_private r_;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vld1q_f64(mem_addr);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u32 = vld1q_u32(HEDLEY_REINTERPRET_CAST(uint32_t const*, mem_addr));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_load(mem_addr);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vld(mem_addr, 0);
    #else
      simde_memcpy(&r_, SIMDE_ALIGN_ASSUME_LIKE(mem_addr, simde__m128d), sizeof(r_));
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_load_pd(mem_addr) simde_mm_load_pd(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_load1_pd (simde_float64 const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_load1_pd(mem_addr);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return simde__m128d_from_neon_f64(vld1q_dup_f64(mem_addr));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128d_from_wasm_v128(wasm_v128_load64_splat(mem_addr));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return (simde__m128d)__lsx_vldrepl_d(mem_addr, 0);
  #else
    return simde_mm_set1_pd(*mem_addr);
  #endif
}
#define simde_mm_load_pd1(mem_addr) simde_mm_load1_pd(mem_addr)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_load_pd1(mem_addr) simde_mm_load1_pd(mem_addr)
  #define _mm_load1_pd(mem_addr) simde_mm_load1_pd(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_load_sd (simde_float64 const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_load_sd(mem_addr);
  #else
    simde__m128d_private r_;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vsetq_lane_f64(*mem_addr, vdupq_n_f64(0), 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_load64_zero(HEDLEY_REINTERPRET_CAST(const void*, mem_addr));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(__lsx_vreplgr2vr_d(0), __lsx_vldrepl_d(mem_addr, 0), 0);
    #else
      r_.f64[0] = *mem_addr;
      r_.u64[1] = UINT64_C(0);
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_load_sd(mem_addr) simde_mm_load_sd(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_load_si128 (simde__m128i const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_load_si128(HEDLEY_REINTERPRET_CAST(__m128i const*, mem_addr));
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld1q_s64(HEDLEY_REINTERPRET_CAST(int64_t const*, mem_addr));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return (simde__m128i)__lsx_vld(mem_addr, 0);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32 = vec_ld(0, HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(int) const*, mem_addr));
    #else
      simde_memcpy(&r_, SIMDE_ALIGN_ASSUME_LIKE(mem_addr, simde__m128i), sizeof(simde__m128i));
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_load_si128(mem_addr) simde_mm_load_si128(mem_addr)
#endif

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_loadh_pd (simde__m128d a, simde_float64 const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadh_pd(a, mem_addr);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vcombine_f64(vget_low_f64(a_.neon_f64), vld1_f64(HEDLEY_REINTERPRET_CAST(const float64_t*, mem_addr)));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_load64_lane(HEDLEY_REINTERPRET_CAST(const void*, mem_addr), a_.wasm_v128, 1);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvl_d(__lsx_vldrepl_d(mem_addr, 0), a_.lsx_i64);
    #else
      simde_float64 t;

      simde_memcpy(&t, mem_addr, sizeof(t));
      r_.f64[0] = a_.f64[0];
      r_.f64[1] = t;
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadh_pd(a, mem_addr) simde_mm_loadh_pd(a, mem_addr)
#endif

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
HEDLEY_DIAGNOSTIC_POP
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadl_epi64 (simde__m128i const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadl_epi64(mem_addr);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vcombine_s64(vld1_s64(HEDLEY_REINTERPRET_CAST(int64_t const *, mem_addr)), vdup_n_s64(0));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vinsgr2vr_d(__lsx_vldrepl_d(mem_addr, 0), 0, 1);
    #else
      int64_t value;
      simde_memcpy(&value, mem_addr, sizeof(value));
      r_.i64[0] = value;
      r_.i64[1] = 0;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadl_epi64(mem_addr) simde_mm_loadl_epi64(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_loadl_pd (simde__m128d a, simde_float64 const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadl_pd(a, mem_addr);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vcombine_f64(vld1_f64(
        HEDLEY_REINTERPRET_CAST(const float64_t*, mem_addr)), vget_high_f64(a_.neon_f64));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_load64_lane(HEDLEY_REINTERPRET_CAST(const void*, mem_addr), a_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvh_d(a_.lsx_i64, __lsx_vldrepl_d(mem_addr, 0));
    #else
      r_.f64[0] = *mem_addr;
      r_.u64[1] = a_.u64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadl_pd(a, mem_addr) simde_mm_loadl_pd(a, mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_loadr_pd (simde_float64 const mem_addr[HEDLEY_ARRAY_PARAM(2)]) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadr_pd(mem_addr);
  #else
    simde__m128d_private
      r_;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vld1q_f64(mem_addr);
      r_.neon_f64 = vextq_f64(r_.neon_f64, r_.neon_f64, 1);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vld1q_s64(HEDLEY_REINTERPRET_CAST(int64_t const *, mem_addr));
      r_.neon_i64 = vextq_s64(r_.neon_i64, r_.neon_i64, 1);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      v128_t tmp = wasm_v128_load(mem_addr);
      r_.wasm_v128 = wasm_i64x2_shuffle(tmp, tmp, 1, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __m128i temp = __lsx_vld(mem_addr, 0);
      r_.lsx_i64 = __lsx_vshuf4i_d(temp, temp, 0b0001);
    #else
      r_.f64[0] = mem_addr[1];
      r_.f64[1] = mem_addr[0];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadr_pd(mem_addr) simde_mm_loadr_pd(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_loadu_pd (simde_float64 const mem_addr[HEDLEY_ARRAY_PARAM(2)]) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadu_pd(mem_addr);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vld1q_f64(mem_addr);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return (simde__m128d)__lsx_vld(mem_addr, 0);
  #else
    simde__m128d_private r_;

    simde_memcpy(&r_, mem_addr, sizeof(r_));

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadu_pd(mem_addr) simde_mm_loadu_pd(mem_addr)
#endif

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE) \
    && !defined(SIMDE_BUG_GCC_95483) && !defined(SIMDE_BUG_CLANG_REV_344862) \
    && (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,20,0))
  #define simde_mm_loadu_epi8(mem_addr) _mm_loadu_epi8(mem_addr)
#else
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_epi8(void const * mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadu_si128(SIMDE_ALIGN_CAST(__m128i const *, mem_addr));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vld1q_s8(HEDLEY_REINTERPRET_CAST(int8_t const*, mem_addr));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vld(mem_addr, 0);
    #else
      simde_memcpy(&r_, mem_addr, sizeof(r_));
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#endif
#define simde_x_mm_loadu_epi8(mem_addr) simde_mm_loadu_epi8(mem_addr)
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && (defined(SIMDE_BUG_GCC_95483) || defined(SIMDE_BUG_CLANG_REV_344862)))
  #undef _mm_loadu_epi8
  #define _mm_loadu_epi8(a) simde_mm_loadu_epi8(a)
#endif

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE) \
    && !defined(SIMDE_BUG_GCC_95483) && !defined(SIMDE_BUG_CLANG_REV_344862) \
    && (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,20,0))
  #define simde_mm_loadu_epi16(mem_addr) _mm_loadu_epi16(mem_addr)
#else
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_epi16(void const * mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadu_si128(SIMDE_ALIGN_CAST(__m128i const *, mem_addr));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vreinterpretq_s16_s8(vld1q_s8(HEDLEY_REINTERPRET_CAST(int8_t const*, mem_addr)));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vld(mem_addr, 0);
    #else
      simde_memcpy(&r_, mem_addr, sizeof(r_));
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#endif
#define simde_x_mm_loadu_epi16(mem_addr) simde_mm_loadu_epi16(mem_addr)
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && (defined(SIMDE_BUG_GCC_95483) || defined(SIMDE_BUG_CLANG_REV_344862)))
  #undef _mm_loadu_epi16
  #define _mm_loadu_epi16(a) simde_mm_loadu_epi16(a)
#endif

#if defined(SIMDE_X86_AVX512VL_NATIVE) && !defined(SIMDE_BUG_GCC_95483) \
    && !defined(SIMDE_BUG_CLANG_REV_344862) && (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,20,0))
  #define simde_mm_loadu_epi32(mem_addr) _mm_loadu_epi32(mem_addr)
#else
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_epi32(void const * mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadu_si128(SIMDE_ALIGN_CAST(__m128i const *, mem_addr));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vreinterpretq_s32_s8(vld1q_s8(HEDLEY_REINTERPRET_CAST(int8_t const*, mem_addr)));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vld(HEDLEY_REINTERPRET_CAST(int8_t const*, mem_addr), 0);
    #else
      simde_memcpy(&r_, mem_addr, sizeof(r_));
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#endif
#define simde_x_mm_loadu_epi32(mem_addr) simde_mm_loadu_epi32(mem_addr)
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && (defined(SIMDE_BUG_GCC_95483) || defined(SIMDE_BUG_CLANG_REV_344862)))
  #undef _mm_loadu_epi32
  #define _mm_loadu_epi32(a) simde_mm_loadu_epi32(a)
#endif

#if defined(SIMDE_X86_AVX512VL_NATIVE) && !defined(SIMDE_BUG_GCC_95483) \
    && !defined(SIMDE_BUG_CLANG_REV_344862) \
    && (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,20,0))
  #define simde_mm_loadu_epi64(mem_addr) _mm_loadu_epi64(mem_addr)
#else
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_epi64(void const * mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadu_si128(SIMDE_ALIGN_CAST(__m128i const *, mem_addr));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vreinterpretq_s64_s8(vld1q_s8(HEDLEY_REINTERPRET_CAST(int8_t const*, mem_addr)));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vld(mem_addr, 0);
    #else
      simde_memcpy(&r_, mem_addr, sizeof(r_));
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#endif
#define simde_x_mm_loadu_epi64(mem_addr) simde_mm_loadu_epi64(mem_addr)
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && (defined(SIMDE_BUG_GCC_95483) || defined(SIMDE_BUG_CLANG_REV_344862)))
  #undef _mm_loadu_epi64
  #define _mm_loadu_epi64(a) simde_mm_loadu_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_si128 (void const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_loadu_si128(HEDLEY_STATIC_CAST(__m128i const*, mem_addr));
  #else
    simde__m128i_private r_;

    #if HEDLEY_GNUC_HAS_ATTRIBUTE(may_alias,3,3,0)
      HEDLEY_DIAGNOSTIC_PUSH
      SIMDE_DIAGNOSTIC_DISABLE_PACKED_
      struct simde_mm_loadu_si128_s {
        __typeof__(r_) v;
      } __attribute__((__packed__, __may_alias__));
      r_ = HEDLEY_REINTERPRET_CAST(const struct simde_mm_loadu_si128_s *, mem_addr)->v;
      HEDLEY_DIAGNOSTIC_POP
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vld1q_s8(HEDLEY_REINTERPRET_CAST(int8_t const*, mem_addr));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vld(mem_addr, 0);
    #else
      simde_memcpy(&r_, mem_addr, sizeof(r_));
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadu_si128(mem_addr) simde_mm_loadu_si128(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_madd_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_madd_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      int32x4_t pl = vmull_s16(vget_low_s16(a_.neon_i16),  vget_low_s16(b_.neon_i16));
      int32x4_t ph = vmull_high_s16(a_.neon_i16, b_.neon_i16);
      r_.neon_i32 = vpaddq_s32(pl, ph);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int32x4_t pl = vmull_s16(vget_low_s16(a_.neon_i16),  vget_low_s16(b_.neon_i16));
      int32x4_t ph = vmull_s16(vget_high_s16(a_.neon_i16), vget_high_s16(b_.neon_i16));
      int32x2_t rl = vpadd_s32(vget_low_s32(pl), vget_high_s32(pl));
      int32x2_t rh = vpadd_s32(vget_low_s32(ph), vget_high_s32(ph));
      r_.neon_i32 = vcombine_s32(rl, rh);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32 = vec_msum(a_.altivec_i16, b_.altivec_i16, vec_splats(0));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i32 = vec_mule(a_.altivec_i16, b_.altivec_i16) + vec_mulo(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_dot_i16x8(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && defined(SIMDE_CONVERT_VECTOR_) && HEDLEY_HAS_BUILTIN(__builtin_shufflevector)
      int32_t SIMDE_VECTOR(32) a32, b32, p32;
      SIMDE_CONVERT_VECTOR_(a32, a_.i16);
      SIMDE_CONVERT_VECTOR_(b32, b_.i16);
      p32 = a32 * b32;
      r_.i32 =
        __builtin_shufflevector(p32, p32, 0, 2, 4, 6) +
        __builtin_shufflevector(p32, p32, 1, 3, 5, 7);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __m128i temp_ev = __lsx_vmulwev_w_h(a_.lsx_i64, b_.lsx_i64);
      r_.lsx_i64 = __lsx_vmaddwod_w_h(temp_ev, a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_) / sizeof(r_.i16[0])) ; i += 2) {
        r_.i32[i / 2] = (a_.i16[i] * b_.i16[i]) + (a_.i16[i + 1] * b_.i16[i + 1]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_madd_epi16(a, b) simde_mm_madd_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_maskmoveu_si128 (simde__m128i a, simde__m128i mask, int8_t mem_addr[HEDLEY_ARRAY_PARAM(16)]) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_maskmoveu_si128(a, mask, HEDLEY_REINTERPRET_CAST(char*, mem_addr));
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      mask_ = simde__m128i_to_private(mask);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __m128i temp = __lsx_vld(mem_addr, 0);
      __m128i temp1 = __lsx_vbitsel_v(temp, a_.lsx_i64, __lsx_vslti_b(mask_.lsx_i64, 0));
      __lsx_vst(temp1, mem_addr, 0);
    #else
      for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++) {
        if (mask_.u8[i] & 0x80) {
          mem_addr[i] = a_.i8[i];
        }
      }
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_maskmoveu_si128(a, mask, mem_addr) simde_mm_maskmoveu_si128((a), (mask), SIMDE_CHECKED_REINTERPRET_CAST(int8_t*, char*, (mem_addr)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_mm_movemask_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__INTEL_COMPILER)
    /* ICC has trouble with _mm_movemask_epi8 at -O2 and above: */
    return _mm_movemask_epi8(a);
  #else
    int32_t r = 0;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      /* https://github.com/WebAssembly/simd/pull/201#issue-380682845 */
      static const uint8_t md[16] = {
        1 << 0, 1 << 1, 1 << 2, 1 << 3,
        1 << 4, 1 << 5, 1 << 6, 1 << 7,
        1 << 0, 1 << 1, 1 << 2, 1 << 3,
        1 << 4, 1 << 5, 1 << 6, 1 << 7,
      };

      /* Extend sign bit over entire lane */
      uint8x16_t extended = vreinterpretq_u8_s8(vshrq_n_s8(a_.neon_i8, 7));
      /* Clear all but the bit we're interested in. */
      uint8x16_t masked = vandq_u8(vld1q_u8(md), extended);
      /* Alternate bytes from low half and high half */
      uint8x8x2_t tmp = vzip_u8(vget_low_u8(masked), vget_high_u8(masked));
      uint16x8_t x = vreinterpretq_u16_u8(vcombine_u8(tmp.val[0], tmp.val[1]));
      #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
        r = vaddvq_u16(x);
      #else
        uint64x2_t t64 = vpaddlq_u32(vpaddlq_u16(x));
        r =
          HEDLEY_STATIC_CAST(int32_t, vgetq_lane_u64(t64, 0)) +
          HEDLEY_STATIC_CAST(int32_t, vgetq_lane_u64(t64, 1));
      #endif
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE) && !defined(HEDLEY_IBM_VERSION) && (SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_LITTLE)
      static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) perm = { 120, 112, 104, 96, 88, 80, 72, 64, 56, 48, 40, 32, 24, 16, 8, 0 };
      r = HEDLEY_STATIC_CAST(int32_t, vec_extract(vec_vbpermq(a_.altivec_u8, perm), 1));
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE) && !defined(HEDLEY_IBM_VERSION) && (SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG)
      static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) perm = { 120, 112, 104, 96, 88, 80, 72, 64, 56, 48, 40, 32, 24, 16, 8, 0 };
      r = HEDLEY_STATIC_CAST(int32_t, vec_extract(vec_vbpermq(a_.altivec_u8, perm), 14));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r = HEDLEY_STATIC_CAST(int32_t, wasm_i8x16_bitmask(a_.wasm_v128));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = __lsx_vpickve2gr_w(__lsx_vmskltz_b(a_.lsx_i64), 0);
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[15 - i] >> 7) << (15 - i);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_movemask_epi8(a) simde_mm_movemask_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_mm_movemask_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_movemask_pd(a);
  #else
    int32_t r = 0;
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      HEDLEY_DIAGNOSTIC_PUSH
      SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_
      uint64x2_t shifted = vshrq_n_u64(a_.neon_u64, 63);
      r =
        HEDLEY_STATIC_CAST(int32_t, vgetq_lane_u64(shifted, 0)) +
        (HEDLEY_STATIC_CAST(int32_t, vgetq_lane_u64(shifted, 1)) << 1);
      HEDLEY_DIAGNOSTIC_POP
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE) && defined(SIMDE_BUG_CLANG_50932)
      SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) idx = { 64, 0, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128 };
      SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) res = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), vec_bperm(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned __int128), a_.altivec_u64), idx));
      r = HEDLEY_STATIC_CAST(int32_t, vec_extract(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed int), res), 2));
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) idx = { 64, 0, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128 };
      SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) res = vec_bperm(a_.altivec_u8, idx);
      r = HEDLEY_STATIC_CAST(int32_t, vec_extract(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed int), res), 2));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r = HEDLEY_STATIC_CAST(int32_t, wasm_i64x2_bitmask(a_.wasm_v128));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = __lsx_vpickve2gr_w(__lsx_vmskltz_d(a_.lsx_i64), 0);
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
        r |= (a_.u64[i] >> 63) << i;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_movemask_pd(a) simde_mm_movemask_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_movepi64_pi64 (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_movepi64_pi64(a);
  #else
    simde__m64_private r_;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i64 = vget_low_s64(a_.neon_i64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.i64[0] = __lsx_vpickve2gr_d(a_.lsx_i64, 0);
    #else
      r_.i64[0] = a_.i64[0];
    #endif

    return simde__m64_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_movepi64_pi64(a) simde_mm_movepi64_pi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_movpi64_epi64 (simde__m64 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_movpi64_epi64(a);
  #else
    simde__m128i_private r_;
    simde__m64_private a_ = simde__m64_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vcombine_s64(a_.neon_i64, vdup_n_s64(0));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vinsgr2vr_d(__lsx_vreplgr2vr_d(0), a_.i64[0], 0);
    #else
      r_.i64[0] = a_.i64[0];
      r_.i64[1] = 0;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_movpi64_epi64(a) simde_mm_movpi64_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_min_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vminq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_min(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i16 = vec_min(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmin_h(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = (a_.i16[i] < b_.i16[i]) ? a_.i16[i] : b_.i16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_min_epi16(a, b) simde_mm_min_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_min_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vminq_u8(a_.neon_u8, b_.neon_u8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u8x16_min(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_u8 = vec_min(a_.altivec_u8, b_.altivec_u8);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmin_bu(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = (a_.u8[i] < b_.u8[i]) ? a_.u8[i] : b_.u8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_min_epu8(a, b) simde_mm_min_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_min_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_min_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = vec_min(a_.altivec_f64, b_.altivec_f64);
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vminq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_min(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vfmin_d(a_.lsx_f64, b_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = (a_.f64[i] < b_.f64[i]) ? a_.f64[i] : b_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_min_pd(a, b) simde_mm_min_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_min_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_min_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_min_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_min_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      float64x2_t temp = vminq_f64(a_.neon_f64, b_.neon_f64);
      r_.neon_f64 = vsetq_lane_f64(vgetq_lane(a_.neon_f64, 1), temp, 1);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfmin_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.f64[0] = (a_.f64[0] < b_.f64[0]) ? a_.f64[0] : b_.f64[0];
      r_.f64[1] = a_.f64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_min_sd(a, b) simde_mm_min_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_max_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vmaxq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_max(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i16 = vec_max(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmax_h(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? a_.i16[i] : b_.i16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_max_epi16(a, b) simde_mm_max_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_max_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vmaxq_u8(a_.neon_u8, b_.neon_u8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u8x16_max(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_u8 = vec_max(a_.altivec_u8, b_.altivec_u8);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmax_bu(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? a_.u8[i] : b_.u8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_max_epu8(a, b) simde_mm_max_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_max_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_max_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = vec_max(a_.altivec_f64, b_.altivec_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_max(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vmaxq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vfmax_d(a_.lsx_f64, b_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = (a_.f64[i] > b_.f64[i]) ? a_.f64[i] : b_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_max_pd(a, b) simde_mm_max_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_max_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_max_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_max_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_max_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      float64x2_t temp = vmaxq_f64(a_.neon_f64, b_.neon_f64);
      r_.neon_f64 = vsetq_lane_f64(vgetq_lane(a_.neon_f64, 1), temp, 1);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfmax_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.f64[0] = (a_.f64[0] > b_.f64[0]) ? a_.f64[0] : b_.f64[0];
      r_.f64[1] = a_.f64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_max_sd(a, b) simde_mm_max_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_move_epi64 (simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_move_epi64(a);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vsetq_lane_s64(0, a_.neon_i64, 1);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_shuffle(a_.wasm_v128, wasm_i64x2_const(0, 0), 0, 2);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvl_d(__lsx_vreplgr2vr_d(0), a_.lsx_i64);
    #else
      r_.i64[0] = a_.i64[0];
      r_.i64[1] = 0;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_move_epi64(a) simde_mm_move_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mul_epu32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_mul_epu32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      uint32x2_t a_lo = vmovn_u64(a_.neon_u64);
      uint32x2_t b_lo = vmovn_u64(b_.neon_u64);
      r_.neon_u64 = vmull_u32(a_lo, b_lo);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u64x2_extmul_low_u32x4(
        wasm_i32x4_shuffle(a_.wasm_v128, a_.wasm_v128, 0, 2, 0, 2),
        wasm_i32x4_shuffle(b_.wasm_v128, b_.wasm_v128, 0, 2, 0, 2));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmulwev_d_wu(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_) && (SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_LITTLE)
      __typeof__(a_.u32) z = { 0, };
      a_.u32 = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.u32, z, 0, 4, 2, 6);
      b_.u32 = SIMDE_SHUFFLE_VECTOR_(32, 16, b_.u32, z, 0, 4, 2, 6);
      r_.u64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.u64), a_.u32) *
               HEDLEY_REINTERPRET_CAST(__typeof__(r_.u64), b_.u32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = HEDLEY_STATIC_CAST(uint64_t, a_.u32[i * 2]) * HEDLEY_STATIC_CAST(uint64_t, b_.u32[i * 2]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mul_epu32(a, b) simde_mm_mul_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_mul_epi64 (simde__m128i a, simde__m128i b) {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i64x2_mul(a_.wasm_v128, b_.wasm_v128);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vmul_d(a_.lsx_i64, b_.lsx_i64);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = a_.i64 * b_.i64;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] * b_.i64[i];
    }
  #endif

  return simde__m128i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_mod_epi64 (simde__m128i a, simde__m128i b) {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vmod_d(a_.lsx_i64, b_.lsx_i64);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && !defined(SIMDE_BUG_PGI_30104)
    r_.i64 = a_.i64 % b_.i64;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] % b_.i64[i];
    }
  #endif

  return simde__m128i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_mul_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_mul_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 * b_.f64;
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vmulq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_mul(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vfmul_d(a_.lsx_f64, b_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = a_.f64[i] * b_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mul_pd(a, b) simde_mm_mul_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_mul_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_mul_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_mul_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_mul_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      float64x2_t temp = vmulq_f64(a_.neon_f64, b_.neon_f64);
      r_.neon_f64 = vsetq_lane_f64(vgetq_lane(a_.neon_f64, 1), temp, 1);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfmul_d(a_.lsx_f64, b_.lsx_f64), 0);
    #else
      r_.f64[0] = a_.f64[0] * b_.f64[0];
      r_.f64[1] = a_.f64[1];
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mul_sd(a, b) simde_mm_mul_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mul_su32 (simde__m64 a, simde__m64 b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE) && !defined(__PGI)
    return _mm_mul_su32(a, b);
  #else
    simde__m64_private
      r_,
      a_ = simde__m64_to_private(a),
      b_ = simde__m64_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.u64[0] = vget_lane_u64(vget_low_u64(vmull_u32(vreinterpret_u32_s64(a_.neon_i64), vreinterpret_u32_s64(b_.neon_i64))), 0);
    #else
      r_.u64[0] = HEDLEY_STATIC_CAST(uint64_t, a_.u32[0]) * HEDLEY_STATIC_CAST(uint64_t, b_.u32[0]);
    #endif

    return simde__m64_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mul_su32(a, b) simde_mm_mul_su32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mulhi_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_mulhi_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int16x4_t a3210 = vget_low_s16(a_.neon_i16);
      int16x4_t b3210 = vget_low_s16(b_.neon_i16);
      int32x4_t ab3210 = vmull_s16(a3210, b3210); /* 3333222211110000 */
      #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
        int32x4_t ab7654 = vmull_high_s16(a_.neon_i16, b_.neon_i16);
        r_.neon_i16 = vuzp2q_s16(vreinterpretq_s16_s32(ab3210), vreinterpretq_s16_s32(ab7654));
      #else
        int16x4_t a7654 = vget_high_s16(a_.neon_i16);
        int16x4_t b7654 = vget_high_s16(b_.neon_i16);
        int32x4_t ab7654 = vmull_s16(a7654, b7654); /* 7777666655554444 */
        uint16x8x2_t rv = vuzpq_u16(vreinterpretq_u16_s32(ab3210), vreinterpretq_u16_s32(ab7654));
        r_.neon_u16 = rv.val[1];
      #endif
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      const v128_t lo = wasm_i32x4_extmul_low_i16x8(a_.wasm_v128, b_.wasm_v128);
      const v128_t hi = wasm_i32x4_extmul_high_i16x8(a_.wasm_v128, b_.wasm_v128);
      r_.wasm_v128 = wasm_i16x8_shuffle(lo, hi, 1, 3, 5, 7, 9, 11, 13, 15);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmuh_h(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (HEDLEY_STATIC_CAST(uint32_t, HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) >> 16));
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mulhi_epi16(a, b) simde_mm_mulhi_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mulhi_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
    return _mm_mulhi_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      uint16x4_t a3210 = vget_low_u16(a_.neon_u16);
      uint16x4_t b3210 = vget_low_u16(b_.neon_u16);
      uint32x4_t ab3210 = vmull_u16(a3210, b3210); /* 3333222211110000 */
      #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
        uint32x4_t ab7654 = vmull_high_u16(a_.neon_u16, b_.neon_u16);
        r_.neon_u16 = vuzp2q_u16(vreinterpretq_u16_u32(ab3210), vreinterpretq_u16_u32(ab7654));
      #else
        uint16x4_t a7654 = vget_high_u16(a_.neon_u16);
        uint16x4_t b7654 = vget_high_u16(b_.neon_u16);
        uint32x4_t ab7654 = vmull_u16(a7654, b7654); /* 7777666655554444 */
        uint16x8x2_t neon_r = vuzpq_u16(vreinterpretq_u16_u32(ab3210), vreinterpretq_u16_u32(ab7654));
        r_.neon_u16 = neon_r.val[1];
      #endif
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      const v128_t lo = wasm_u32x4_extmul_low_u16x8(a_.wasm_v128, b_.wasm_v128);
      const v128_t hi = wasm_u32x4_extmul_high_u16x8(a_.wasm_v128, b_.wasm_v128);
      r_.wasm_v128 = wasm_i16x8_shuffle(lo, hi, 1, 3, 5, 7, 9, 11, 13, 15);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmuh_hu(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]) >> 16);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mulhi_epu16(a, b) simde_mm_mulhi_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mullo_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_mullo_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vmulq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      (void) a_;
      (void) b_;
      r_.altivec_i16 = vec_mul(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_mul(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vmul_h(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]));
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mullo_epi16(a, b) simde_mm_mullo_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_or_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_or_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f | b_.i32f;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_or(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vorrq_s64(a_.neon_i64, b_.neon_i64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vor_v(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_or_pd(a, b) simde_mm_or_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_or_si128 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_or_si128(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vorrq_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32 = vec_or(a_.altivec_i32, b_.altivec_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_or(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vor_v(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f | b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_or_si128(a, b) simde_mm_or_si128(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_packs_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_packs_epi16(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b),
      r_;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i8 = vqmovn_high_s16(vqmovn_s16(a_.neon_i16), b_.neon_i16);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vcombine_s8(vqmovn_s16(a_.neon_i16), vqmovn_s16(b_.neon_i16));
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i8 = vec_packs(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_narrow_i16x8(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vssrarni_b_h(b_.lsx_i64, a_.lsx_i64, 0);
    #elif defined(SIMDE_CONVERT_VECTOR_) && HEDLEY_HAS_BUILTIN(__builtin_shufflevector)
      int16_t SIMDE_VECTOR(32) v = SIMDE_SHUFFLE_VECTOR_(16, 32, a_.i16, b_.i16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
      const int16_t SIMDE_VECTOR(32) min = { INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN, INT8_MIN };
      const int16_t SIMDE_VECTOR(32) max = { INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX };

      int16_t m SIMDE_VECTOR(32);
      m = HEDLEY_REINTERPRET_CAST(__typeof__(m), v < min);
      v = (v & ~m) | (min & m);

      m = v > max;
      v = (v & ~m) | (max & m);

      SIMDE_CONVERT_VECTOR_(r_.i8, v);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        int16_t v = (i < (sizeof(a_.i16) / sizeof(a_.i16[0]))) ? a_.i16[i] : b_.i16[i & 7];
        r_.i8[i] = (v < INT8_MIN) ? INT8_MIN : ((v > INT8_MAX) ? INT8_MAX : HEDLEY_STATIC_CAST(int8_t, v));
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_packs_epi16(a, b) simde_mm_packs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_packs_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_packs_epi32(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b),
      r_;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i16 = vqmovn_high_s32(vqmovn_s32(a_.neon_i32), b_.neon_i32);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vcombine_s16(vqmovn_s32(a_.neon_i32), vqmovn_s32(b_.neon_i32));
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i16 = vec_packs(a_.altivec_i32, b_.altivec_i32);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.sse_m128i = _mm_packs_epi32(a_.sse_m128i, b_.sse_m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_narrow_i32x4(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vssrarni_h_w(b_.lsx_i64, a_.lsx_i64, 0);
    #elif defined(SIMDE_CONVERT_VECTOR_) && HEDLEY_HAS_BUILTIN(__builtin_shufflevector)
      int32_t SIMDE_VECTOR(32) v = SIMDE_SHUFFLE_VECTOR_(32, 32, a_.i32, b_.i32, 0, 1, 2, 3, 4, 5, 6, 7);
      const int32_t SIMDE_VECTOR(32) min = { INT16_MIN, INT16_MIN, INT16_MIN, INT16_MIN, INT16_MIN, INT16_MIN, INT16_MIN, INT16_MIN };
      const int32_t SIMDE_VECTOR(32) max = { INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX };

      int32_t m SIMDE_VECTOR(32);
      m = HEDLEY_REINTERPRET_CAST(__typeof__(m), v < min);
      v = (v & ~m) | (min & m);

      m = HEDLEY_REINTERPRET_CAST(__typeof__(m), v > max);
      v = (v & ~m) | (max & m);

      SIMDE_CONVERT_VECTOR_(r_.i16, v);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        int32_t v = (i < (sizeof(a_.i32) / sizeof(a_.i32[0]))) ? a_.i32[i] : b_.i32[i & 3];
        r_.i16[i] = (v < INT16_MIN) ? INT16_MIN : ((v > INT16_MAX) ? INT16_MAX : HEDLEY_STATIC_CAST(int16_t, v));
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_packs_epi32(a, b) simde_mm_packs_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_packus_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_packus_epi16(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b),
      r_;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      #if defined(SIMDE_BUG_CLANG_46840)
        r_.neon_u8 = vqmovun_high_s16(vreinterpret_s8_u8(vqmovun_s16(a_.neon_i16)), b_.neon_i16);
      #else
        r_.neon_u8 = vqmovun_high_s16(vqmovun_s16(a_.neon_i16), b_.neon_i16);
      #endif
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 =
        vcombine_u8(
          vqmovun_s16(a_.neon_i16),
          vqmovun_s16(b_.neon_i16)
        );
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_u8 = vec_packsu(a_.altivec_i16, b_.altivec_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u8x16_narrow_i16x8(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vssrarni_bu_h(b_.lsx_i64, a_.lsx_i64, 0);
    #elif defined(SIMDE_CONVERT_VECTOR_) && HEDLEY_HAS_BUILTIN(__builtin_shufflevector) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      int16_t v SIMDE_VECTOR(32) = SIMDE_SHUFFLE_VECTOR_(16, 32, a_.i16, b_.i16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

      v &= ~(v >> 15);
      v |= HEDLEY_REINTERPRET_CAST(__typeof__(v), v > UINT8_MAX);

      SIMDE_CONVERT_VECTOR_(r_.i8, v);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        int16_t v = (i < (sizeof(a_.i16) / sizeof(a_.i16[0]))) ? a_.i16[i] : b_.i16[i & 7];
        r_.u8[i] = (v < 0) ? UINT8_C(0) : ((v > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, v));
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_packus_epi16(a, b) simde_mm_packus_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_pause (void) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_pause();
  #elif defined(SIMDE_ARCH_X86)
    #if defined(_MSC_VER)
      __asm pause;
    #else
      __asm__ __volatile__("pause");
    #endif
  #elif defined(SIMDE_ARCH_ARM_NEON)
    #if defined(_MSC_VER)
      __isb(SIMDE_ARM64_BARRIER_SY);
    #else
      __asm__ __volatile__("isb\n");
    #endif
  #elif defined(SIMDE_ARCH_POWER)
    __asm__ __volatile__ ("or 27,27,27" ::: "memory");
  #elif defined(SIMDE_ARCH_WASM)
    __asm__ __volatile__ ("nop");
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __asm__ __volatile ("dbar 0");
  #elif defined(HEDLEY_GCC_VERSION)
    #if defined(SIMDE_ARCH_RISCV32) || defined(SIMDE_ARCH_RISCV64)
      __builtin_riscv_pause();
    #else
      __asm__ __volatile__ ("nop" ::: "memory");
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_pause() (simde_mm_pause())
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sad_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sad_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      const uint16x8_t t = vpaddlq_u8(vabdq_u8(a_.neon_u8, b_.neon_u8));
      r_.neon_u64 = vcombine_u64(
        vpaddl_u32(vpaddl_u16(vget_low_u16(t))),
        vpaddl_u32(vpaddl_u16(vget_high_u16(t))));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      v128_t tmp = wasm_v128_or(wasm_u8x16_sub_sat(a_.wasm_v128, b_.wasm_v128),
                                wasm_u8x16_sub_sat(b_.wasm_v128, a_.wasm_v128));
      tmp = wasm_i16x8_add(wasm_u16x8_shr(tmp, 8),
                           wasm_v128_and(tmp, wasm_i16x8_splat(0x00FF)));
      tmp = wasm_i16x8_add(tmp, wasm_i32x4_shl(tmp, 16));
      tmp = wasm_i16x8_add(tmp, wasm_i64x2_shl(tmp, 32));
      r_.wasm_v128 = wasm_u64x2_shr(tmp, 48);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __m128i temp = __lsx_vabsd_bu(a_.lsx_i64, b_.lsx_i64);
      temp = __lsx_vhaddw_hu_bu(temp, temp);
      temp = __lsx_vhaddw_wu_hu(temp, temp);
      r_.lsx_i64 = __lsx_vhaddw_du_wu(temp, temp);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        uint16_t tmp = 0;
        SIMDE_VECTORIZE_REDUCTION(+:tmp)
        for (size_t j = 0 ; j < ((sizeof(r_.u8) / sizeof(r_.u8[0])) / 2) ; j++) {
          const size_t e = j + (i * 8);
          tmp += (a_.u8[e] > b_.u8[e]) ? (a_.u8[e] - b_.u8[e]) : (b_.u8[e] - a_.u8[e]);
        }
        r_.i64[i] = tmp;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sad_epu8(a, b) simde_mm_sad_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi8 (int8_t e15, int8_t e14, int8_t e13, int8_t e12,
       int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
       int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4,
       int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {

  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_epi8(
      e15, e14, e13, e12, e11, e10,  e9,  e8,
       e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_make(
         e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
         e8,  e9, e10, e11, e12, e13, e14, e15);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(int8x16_t) int8_t data[16] = {
        e0,  e1,  e2,  e3,
        e4,  e5,  e6,  e7,
        e8,  e9,  e10, e11,
        e12, e13, e14, e15};
      r_.neon_i8 = vld1q_s8(data);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v16i8) int8_t data[16] = {
        e0,  e1,  e2,  e3,
        e4,  e5,  e6,  e7,
        e8,  e9,  e10, e11,
        e12, e13, e14, e15};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.i8[ 0] =  e0;
      r_.i8[ 1] =  e1;
      r_.i8[ 2] =  e2;
      r_.i8[ 3] =  e3;
      r_.i8[ 4] =  e4;
      r_.i8[ 5] =  e5;
      r_.i8[ 6] =  e6;
      r_.i8[ 7] =  e7;
      r_.i8[ 8] =  e8;
      r_.i8[ 9] =  e9;
      r_.i8[10] = e10;
      r_.i8[11] = e11;
      r_.i8[12] = e12;
      r_.i8[13] = e13;
      r_.i8[14] = e14;
      r_.i8[15] = e15;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,  e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0) simde_mm_set_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,  e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi16 (int16_t e7, int16_t e6, int16_t e5, int16_t e4,
        int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_epi16(e7, e6, e5, e4, e3, e2, e1, e0);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(int16x8_t) int16_t data[8] = { e0, e1, e2, e3, e4, e5, e6, e7 };
      r_.neon_i16 = vld1q_s16(data);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_make(e0, e1, e2, e3, e4, e5, e6, e7);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v8i16) int16_t data[8] = {e0, e1, e2, e3, e4, e5, e6, e7};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.i16[0] = e0;
      r_.i16[1] = e1;
      r_.i16[2] = e2;
      r_.i16[3] = e3;
      r_.i16[4] = e4;
      r_.i16[5] = e5;
      r_.i16[6] = e6;
      r_.i16[7] = e7;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set_epi16(e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0) simde_mm_set_epi16(e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_si16 (void const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && ( \
      SIMDE_DETECT_CLANG_VERSION_CHECK(8,0,0) || \
      HEDLEY_INTEL_VERSION_CHECK(20,21,1) || \
      HEDLEY_GCC_VERSION_CHECK(12,1,0))
    return _mm_loadu_si16(mem_addr);
  #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
    return __lsx_vld(mem_addr, 0);
  #else
    int16_t val;
    simde_memcpy(&val, mem_addr, sizeof(val));
    return simde_x_mm_cvtsi16_si128(val);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadu_si16(mem_addr) simde_mm_loadu_si16(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi32 (int32_t e3, int32_t e2, int32_t e1, int32_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_epi32(e3, e2, e1, e0);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(int32x4_t) int32_t data[4] = { e0, e1, e2, e3 };
      r_.neon_i32 = vld1q_s32(data);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_make(e0, e1, e2, e3);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v4i32) int32_t data[4] = {e0, e1, e2, e3};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.i32[0] = e0;
      r_.i32[1] = e1;
      r_.i32[2] = e2;
      r_.i32[3] = e3;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set_epi32(e3,  e2,  e1,  e0) simde_mm_set_epi32(e3,  e2,  e1,  e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_si32 (void const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && ( \
      SIMDE_DETECT_CLANG_VERSION_CHECK(8,0,0) || \
      HEDLEY_INTEL_VERSION_CHECK(20,21,1) || \
      HEDLEY_GCC_VERSION_CHECK(12,1,0))
    return _mm_loadu_si32(mem_addr);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128i_from_wasm_v128(wasm_v128_load32_zero(mem_addr));
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    simde__m128i_private r_;
    r_.neon_i32 = vsetq_lane_s32(* HEDLEY_REINTERPRET_CAST(const int32_t *, mem_addr), vdupq_n_s32(0), 0);
    return simde__m128i_from_private(r_);
  #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
    return __lsx_vld(mem_addr, 0);
  #else
    int32_t val;
    simde_memcpy(&val, mem_addr, sizeof(val));
    return simde_mm_cvtsi32_si128(val);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadu_si32(mem_addr) simde_mm_loadu_si32(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi64 (simde__m64 e1, simde__m64 e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_set_epi64(e1, e0);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vcombine_s64(simde__m64_to_neon_i64(e0), simde__m64_to_neon_i64(e1));
   #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_TO_16 simde__m64 data[2] = {e0, e1};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.m64[0] = e0;
      r_.m64[1] = e1;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set_epi64(e1, e0) (simde_mm_set_epi64((e1), (e0)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi64x (int64_t e1, int64_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,0,0))
    return _mm_set_epi64x(e1, e0);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(int64x2_t) int64_t data[2] = {e0, e1};
      r_.neon_i64 = vld1q_s64(data);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_make(e0, e1);
   #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v2i64) int64_t data[2] = {e0, e1};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.i64[0] = e0;
      r_.i64[1] = e1;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set_epi64x(e1, e0) simde_mm_set_epi64x(e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_si64 (void const* mem_addr) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && ( \
      SIMDE_DETECT_CLANG_VERSION_CHECK(8,0,0) || \
      HEDLEY_GCC_VERSION_CHECK(11,0,0) || \
      HEDLEY_INTEL_VERSION_CHECK(20,21,1))
    return _mm_loadu_si64(mem_addr);
  #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
    return __lsx_vld(mem_addr, 0);
  #else
  int64_t val;
    simde_memcpy(&val, mem_addr, sizeof(val));
    return simde_mm_cvtsi64_si128(val);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_loadu_si64(mem_addr) simde_mm_loadu_si64(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set_epu8 (uint8_t e15, uint8_t e14, uint8_t e13, uint8_t e12,
         uint8_t e11, uint8_t e10, uint8_t  e9, uint8_t  e8,
         uint8_t  e7, uint8_t  e6, uint8_t  e5, uint8_t  e4,
         uint8_t  e3, uint8_t  e2, uint8_t  e1, uint8_t  e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_epi8(
      HEDLEY_STATIC_CAST(char, e15), HEDLEY_STATIC_CAST(char, e14), HEDLEY_STATIC_CAST(char, e13), HEDLEY_STATIC_CAST(char, e12),
      HEDLEY_STATIC_CAST(char, e11), HEDLEY_STATIC_CAST(char, e10), HEDLEY_STATIC_CAST(char,  e9), HEDLEY_STATIC_CAST(char,  e8),
      HEDLEY_STATIC_CAST(char,  e7), HEDLEY_STATIC_CAST(char,  e6), HEDLEY_STATIC_CAST(char,  e5), HEDLEY_STATIC_CAST(char,  e4),
      HEDLEY_STATIC_CAST(char,  e3), HEDLEY_STATIC_CAST(char,  e2), HEDLEY_STATIC_CAST(char,  e1), HEDLEY_STATIC_CAST(char,  e0));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(uint8x16_t) uint8_t data[16] = {
        e0,  e1,  e2,  e3,
        e4,  e5,  e6,  e7,
        e8,  e9,  e10, e11,
        e12, e13, e14, e15};
      r_.neon_u8 = vld1q_u8(data);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u8x16_make(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
    #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v16u8) uint8_t data[16] = {
        e0,  e1,  e2,  e3,
        e4,  e5,  e6,  e7,
        e8,  e9,  e10, e11,
        e12, e13, e14, e15};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.u8[ 0] =  e0; r_.u8[ 1] =  e1; r_.u8[ 2] =  e2; r_.u8[ 3] =  e3;
      r_.u8[ 4] =  e4; r_.u8[ 5] =  e5; r_.u8[ 6] =  e6; r_.u8[ 7] =  e7;
      r_.u8[ 8] =  e8; r_.u8[ 9] =  e9; r_.u8[10] = e10; r_.u8[11] = e11;
      r_.u8[12] = e12; r_.u8[13] = e13; r_.u8[14] = e14; r_.u8[15] = e15;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set_epu16 (uint16_t e7, uint16_t e6, uint16_t e5, uint16_t e4,
          uint16_t e3, uint16_t e2, uint16_t e1, uint16_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_epi16(
      HEDLEY_STATIC_CAST(short,  e7), HEDLEY_STATIC_CAST(short,  e6), HEDLEY_STATIC_CAST(short,  e5), HEDLEY_STATIC_CAST(short,  e4),
      HEDLEY_STATIC_CAST(short,  e3), HEDLEY_STATIC_CAST(short,  e2), HEDLEY_STATIC_CAST(short,  e1), HEDLEY_STATIC_CAST(short,  e0));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(uint16x8_t) uint16_t data[8] = { e0, e1, e2, e3, e4, e5, e6, e7 };
      r_.neon_u16 = vld1q_u16(data);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u16x8_make(e0, e1, e2, e3, e4, e5, e6, e7);
    #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v8u16) uint16_t data[8] = {e0, e1, e2, e3, e4, e5, e6, e7};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.u16[0] = e0; r_.u16[1] = e1; r_.u16[2] = e2; r_.u16[3] = e3;
      r_.u16[4] = e4; r_.u16[5] = e5; r_.u16[6] = e6; r_.u16[7] = e7;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set_epu32 (uint32_t e3, uint32_t e2, uint32_t e1, uint32_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_epi32(
      HEDLEY_STATIC_CAST(int,  e3), HEDLEY_STATIC_CAST(int,  e2), HEDLEY_STATIC_CAST(int,  e1), HEDLEY_STATIC_CAST(int,  e0));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(uint32x4_t) uint32_t data[4] = { e0, e1, e2, e3 };
      r_.neon_u32 = vld1q_u32(data);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u32x4_make(e0, e1, e2, e3);
    #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v4u32) uint32_t data[4] = {e0, e1, e2, e3};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.u32[0] = e0;
      r_.u32[1] = e1;
      r_.u32[2] = e2;
      r_.u32[3] = e3;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set_epu64x (uint64_t e1, uint64_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,0,0))
    return _mm_set_epi64x(HEDLEY_STATIC_CAST(int64_t,  e1), HEDLEY_STATIC_CAST(int64_t,  e0));
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      SIMDE_ALIGN_LIKE_16(uint64x2_t) uint64_t data[2] = {e0, e1};
      r_.neon_u64 = vld1q_u64(data);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u64x2_make(e0, e1);
    #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
      SIMDE_ALIGN_LIKE_16(v2u64) uint64_t data[2] = {e0, e1};
      r_.lsx_i64 = __lsx_vld(data, 0);
    #else
      r_.u64[0] = e0;
      r_.u64[1] = e1;
    #endif

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_set_sd (simde_float64 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set_sd(a);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vsetq_lane_f64(a, vdupq_n_f64(SIMDE_FLOAT64_C(0.0)), 0);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128d_from_wasm_v128(wasm_f64x2_make(a, 0));
  #elif defined(SIMD_LOONGARCH_LSX_NATIVE)
    return (__m128d)__lsx_vinsgr2vr_d(__lsx_vldrepl_d(&a, 0), 0, 1);
  #else
    return simde_mm_set_pd(SIMDE_FLOAT64_C(0.0), a);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set_sd(a) simde_mm_set_sd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi8 (int8_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set1_epi8(a);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vdupq_n_s8(a);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_splat(a);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i8 = vec_splats(HEDLEY_STATIC_CAST(signed char, a));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vreplgr2vr_b(a);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set1_epi8(a) simde_mm_set1_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi16 (int16_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set1_epi16(a);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vdupq_n_s16(a);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_splat(a);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i16 = vec_splats(HEDLEY_STATIC_CAST(signed short, a));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vreplgr2vr_h(a);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set1_epi16(a) simde_mm_set1_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi32 (int32_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_set1_epi32(a);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vdupq_n_s32(a);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_splat(a);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i32 = vec_splats(HEDLEY_STATIC_CAST(signed int, a));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vreplgr2vr_w(a);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set1_epi32(a) simde_mm_set1_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi64x (int64_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,0,0))
    return _mm_set1_epi64x(a);
  #else
    simde__m128i_private r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vdupq_n_s64(a);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_splat(a);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_i64 = vec_splats(HEDLEY_STATIC_CAST(signed long long, a));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vreplgr2vr_d(a);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set1_epi64x(a) simde_mm_set1_epi64x(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi64 (simde__m64 a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_set1_epi64(a);
  #else
    simde__m64_private a_ = simde__m64_to_private(a);
    return simde_mm_set1_epi64x(a_.i64[0]);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_set1_epi64(a) simde_mm_set1_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set1_epu8 (uint8_t value) {
  #if defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return simde__m128i_from_altivec_u8(vec_splats(HEDLEY_STATIC_CAST(unsigned char, value)));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128i_from_wasm_v128(wasm_u8x16_splat(value));
  #else
    return simde_mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, value));
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set1_epu16 (uint16_t value) {
  #if defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return simde__m128i_from_altivec_u16(vec_splats(HEDLEY_STATIC_CAST(unsigned short, value)));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128i_from_wasm_v128(wasm_u16x8_splat(value));
  #else
    return simde_mm_set1_epi16(HEDLEY_STATIC_CAST(int16_t, value));
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set1_epu32 (uint32_t value) {
  #if defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return simde__m128i_from_altivec_u32(vec_splats(HEDLEY_STATIC_CAST(unsigned int, value)));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128i_from_wasm_v128(wasm_u32x4_splat(value));
  #else
    return simde_mm_set1_epi32(HEDLEY_STATIC_CAST(int32_t, value));
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_set1_epu64 (uint64_t value) {
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    return simde__m128i_from_altivec_u64(vec_splats(HEDLEY_STATIC_CAST(unsigned long long, value)));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128i_from_wasm_v128(wasm_u64x2_splat(value));
  #else
    return simde_mm_set1_epi64x(HEDLEY_STATIC_CAST(int64_t, value));
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi8 (int8_t e15, int8_t e14, int8_t e13, int8_t e12,
        int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
        int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4,
        int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_setr_epi8(
      e15, e14, e13, e12, e11, e10,  e9,    e8,
      e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
  #else
    return simde_mm_set_epi8(
      e0, e1, e2, e3, e4, e5, e6, e7,
      e8, e9, e10, e11, e12, e13, e14, e15);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_setr_epi8(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm_setr_epi8(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi16 (int16_t e7, int16_t e6, int16_t e5, int16_t e4,
         int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_setr_epi16(e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
  #else
    return simde_mm_set_epi16(e0, e1, e2, e3, e4, e5, e6, e7);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_setr_epi16(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm_setr_epi16(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi32 (int32_t e3, int32_t e2, int32_t e1, int32_t e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_setr_epi32(e3, e2, e1, e0);
  #else
    return simde_mm_set_epi32(e0, e1, e2, e3);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_setr_epi32(e3, e2, e1, e0) simde_mm_setr_epi32(e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi64 (simde__m64 e1, simde__m64 e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_setr_epi64(e1, e0);
  #else
    return simde_mm_set_epi64(e0, e1);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_setr_epi64(e1, e0) (simde_mm_setr_epi64((e1), (e0)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_setr_pd (simde_float64 e1, simde_float64 e0) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_setr_pd(e1, e0);
  #else
    return simde_mm_set_pd(e0, e1);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_setr_pd(e1, e0) simde_mm_setr_pd(e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_setzero_pd (void) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_setzero_pd();
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return simde__m128d_from_wasm_v128(wasm_f64x2_const(0.0, 0.0));
  #else
    return simde_mm_castsi128_pd(simde_mm_setzero_si128());
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_setzero_pd() simde_mm_setzero_pd()
#endif

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_undefined_pd (void) {
  simde__m128d_private r_;

  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE__HAVE_UNDEFINED128)
    r_.n = _mm_undefined_pd();
  #elif !defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
    r_ = simde__m128d_to_private(simde_mm_setzero_pd());
  #endif

  return simde__m128d_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_undefined_pd() simde_mm_undefined_pd()
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_undefined_si128 (void) {
  simde__m128i_private r_;

  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE__HAVE_UNDEFINED128)
    r_.n = _mm_undefined_si128();
  #elif !defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
    r_ = simde__m128i_to_private(simde_mm_setzero_si128());
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_undefined_si128() (simde_mm_undefined_si128())
#endif

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
HEDLEY_DIAGNOSTIC_POP
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_setone_pd (void) {
  return simde_mm_castps_pd(simde_x_mm_setone_ps());
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_setone_si128 (void) {
  return simde_mm_castps_si128(simde_x_mm_setone_ps());
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_shuffle_epi32 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[(imm8 >> (i * 2)) & 3];
  }

  return simde__m128i_from_private(r_);
}

#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_shuffle_epi32(a, imm8) _mm_shuffle_epi32((a), (imm8))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_mm_shuffle_epi32(a, imm8) (__lsx_vshuf4i_w(simde__m128i_to_private(a).lsx_i64, (imm8)))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_shuffle_epi32(a, imm8) (__extension__ ({ \
      const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
      simde__m128i_from_wasm_v128( \
        wasm_i32x4_shuffle( \
          (simde_tmp_a_).wasm_v128, \
          (simde_tmp_a_).wasm_v128, \
          ((imm8)     ) & 3, \
          ((imm8) >> 2) & 3, \
          ((imm8) >> 4) & 3, \
          ((imm8) >> 6) & 3)); }))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm_shuffle_epi32(a, imm8) \
    (__extension__ ({ \
      const int32x4_t simde_mm_shuffle_epi32_a_ = simde__m128i_to_neon_i32(a); \
      int32x4_t simde_mm_shuffle_epi32_r_; \
      simde_mm_shuffle_epi32_r_ = vmovq_n_s32(vgetq_lane_s32(simde_mm_shuffle_epi32_a_, (imm8) & (0x3))); \
      simde_mm_shuffle_epi32_r_ = vsetq_lane_s32(vgetq_lane_s32(simde_mm_shuffle_epi32_a_, ((imm8) >> 2) & 0x3), simde_mm_shuffle_epi32_r_, 1); \
      simde_mm_shuffle_epi32_r_ = vsetq_lane_s32(vgetq_lane_s32(simde_mm_shuffle_epi32_a_, ((imm8) >> 4) & 0x3), simde_mm_shuffle_epi32_r_, 2); \
      simde_mm_shuffle_epi32_r_ = vsetq_lane_s32(vgetq_lane_s32(simde_mm_shuffle_epi32_a_, ((imm8) >> 6) & 0x3), simde_mm_shuffle_epi32_r_, 3); \
      vreinterpretq_s64_s32(simde_mm_shuffle_epi32_r_); \
    }))
#elif defined(SIMDE_SHUFFLE_VECTOR_)
  #define simde_mm_shuffle_epi32(a, imm8) (__extension__ ({ \
      const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
      simde__m128i_from_private((simde__m128i_private) { .i32 = \
        SIMDE_SHUFFLE_VECTOR_(32, 16, \
          (simde_tmp_a_).i32, \
          (simde_tmp_a_).i32, \
          ((imm8)     ) & 3, \
          ((imm8) >> 2) & 3, \
          ((imm8) >> 4) & 3, \
          ((imm8) >> 6) & 3) }); }))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_shuffle_epi32(a, imm8) simde_mm_shuffle_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_shuffle_pd (simde__m128d a, simde__m128d b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 3)  {
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

  r_.f64[0] = ((imm8 & 1) == 0) ? a_.f64[0] : a_.f64[1];
  r_.f64[1] = ((imm8 & 2) == 0) ? b_.f64[0] : b_.f64[1];

  return simde__m128d_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
  #define simde_mm_shuffle_pd(a, b, imm8) _mm_shuffle_pd((a), (b), (imm8))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_mm_shuffle_pd(a, b, imm8)  \
      ({ \
          simde__m128d res; \
          if ((imm8) & 0x01) { \
            res = (simde__m128d)__lsx_vshuf4i_d(simde__m128d_to_private(a).lsx_i64, simde__m128d_to_private(b).lsx_i64, 0b1001); \
          } else if ((imm8) & 0x02) { \
            res = (simde__m128d)__lsx_vshuf4i_d(simde__m128d_to_private(a).lsx_i64, simde__m128d_to_private(b).lsx_i64, 0b1100); \
          } else if ((imm8) & 0x03) { \
            res = (simde__m128d)__lsx_vshuf4i_d(simde__m128d_to_private(a).lsx_i64, simde__m128d_to_private(b).lsx_i64, 0b1101); \
          } else { \
            res = (simde__m128d)__lsx_vshuf4i_d(simde__m128d_to_private(a).lsx_i64, simde__m128d_to_private(b).lsx_i64, 0b1000); \
          } \
          res; \
      })
#elif defined(SIMDE_SHUFFLE_VECTOR_)
  #define simde_mm_shuffle_pd(a, b, imm8) (__extension__ ({ \
      simde__m128d_from_private((simde__m128d_private) { .f64 = \
        SIMDE_SHUFFLE_VECTOR_(64, 16, \
          simde__m128d_to_private(a).f64, \
          simde__m128d_to_private(b).f64, \
          (((imm8)     ) & 1), \
          (((imm8) >> 1) & 1) + 2) }); }))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_shuffle_pd(a, b, imm8) simde_mm_shuffle_pd(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_shufflehi_epi16 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < ((sizeof(a_.i16) / sizeof(a_.i16[0])) / 2) ; i++) {
    r_.i16[i] = a_.i16[i];
  }
  for (size_t i = ((sizeof(a_.i16) / sizeof(a_.i16[0])) / 2) ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[((imm8 >> ((i - 4) * 2)) & 3) + 4];
  }

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_shufflehi_epi16(a, imm8) _mm_shufflehi_epi16((a), (imm8))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_mm_shufflehi_epi16(a, imm8) \
    ((simde__m128i)__lsx_vextrins_d(__lsx_vshuf4i_h(simde__m128i_to_private(a).lsx_i64, imm8), simde__m128i_to_private(a).lsx_i64, 0x00))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm_shufflehi_epi16(a, imm8) \
    (__extension__ ({ \
      int16x8_t simde_mm_shufflehi_epi16_a_ = simde__m128i_to_neon_i16(a); \
      int16x8_t simde_mm_shufflehi_epi16_r_ = simde_mm_shufflehi_epi16_a_; \
      simde_mm_shufflehi_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflehi_epi16_a_, (((imm8)     ) & 0x3) + 4), simde_mm_shufflehi_epi16_r_, 4); \
      simde_mm_shufflehi_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflehi_epi16_a_, (((imm8) >> 2) & 0x3) + 4), simde_mm_shufflehi_epi16_r_, 5); \
      simde_mm_shufflehi_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflehi_epi16_a_, (((imm8) >> 4) & 0x3) + 4), simde_mm_shufflehi_epi16_r_, 6); \
      simde_mm_shufflehi_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflehi_epi16_a_, (((imm8) >> 6) & 0x3) + 4), simde_mm_shufflehi_epi16_r_, 7); \
      simde__m128i_from_neon_i16(simde_mm_shufflehi_epi16_r_); \
    }))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_shufflehi_epi16(a, imm8) (__extension__ ({ \
      const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
      simde__m128i_from_private((simde__m128i_private) { .wasm_v128 = \
        wasm_i16x8_shuffle( \
          (simde_tmp_a_).wasm_v128, \
          (simde_tmp_a_).wasm_v128, \
          0, 1, 2, 3, \
          (((imm8)     ) & 3) + 4, \
          (((imm8) >> 2) & 3) + 4, \
          (((imm8) >> 4) & 3) + 4, \
          (((imm8) >> 6) & 3) + 4) }); }))
#elif defined(SIMDE_SHUFFLE_VECTOR_)
  #define simde_mm_shufflehi_epi16(a, imm8) (__extension__ ({ \
      const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
      simde__m128i_from_private((simde__m128i_private) { .i16 = \
        SIMDE_SHUFFLE_VECTOR_(16, 16, \
          (simde_tmp_a_).i16, \
          (simde_tmp_a_).i16, \
          0, 1, 2, 3, \
          (((imm8)     ) & 3) + 4, \
          (((imm8) >> 2) & 3) + 4, \
          (((imm8) >> 4) & 3) + 4, \
          (((imm8) >> 6) & 3) + 4) }); }))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_shufflehi_epi16(a, imm8) simde_mm_shufflehi_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_shufflelo_epi16 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  for (size_t i = 0 ; i < ((sizeof(r_.i16) / sizeof(r_.i16[0])) / 2) ; i++) {
    r_.i16[i] = a_.i16[((imm8 >> (i * 2)) & 3)];
  }
  SIMDE_VECTORIZE
  for (size_t i = ((sizeof(a_.i16) / sizeof(a_.i16[0])) / 2) ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i];
  }

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_shufflelo_epi16(a, imm8) _mm_shufflelo_epi16((a), (imm8))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_mm_shufflelo_epi16(a, imm8) \
    ((simde__m128i)__lsx_vextrins_d(__lsx_vshuf4i_h(simde__m128i_to_private(a).lsx_i64, imm8), simde__m128i_to_private(a).lsx_i64, 0b00010001))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_shufflelo_epi16(a, imm8) \
    simde__m128i_from_wasm_v128(            \
      wasm_i16x8_shuffle(                   \
        simde__m128i_to_wasm_v128((a)),     \
        wasm_i16x8_splat(0),                \
        (((imm8) & 0x03)     ),             \
        (((imm8) & 0x0c) >> 2),             \
        (((imm8) & 0x30) >> 4),             \
        (((imm8) & 0xc0) >> 6),             \
        4, 5, 6, 7))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm_shufflelo_epi16(a, imm8) \
    (__extension__({ \
      int16x8_t simde_mm_shufflelo_epi16_a_ = simde__m128i_to_neon_i16(a); \
      int16x8_t simde_mm_shufflelo_epi16_r_ = simde_mm_shufflelo_epi16_a_; \
      simde_mm_shufflelo_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflelo_epi16_a_, (((imm8)     ) & 0x3)), simde_mm_shufflelo_epi16_r_, 0); \
      simde_mm_shufflelo_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflelo_epi16_a_, (((imm8) >> 2) & 0x3)), simde_mm_shufflelo_epi16_r_, 1); \
      simde_mm_shufflelo_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflelo_epi16_a_, (((imm8) >> 4) & 0x3)), simde_mm_shufflelo_epi16_r_, 2); \
      simde_mm_shufflelo_epi16_r_ = vsetq_lane_s16(vgetq_lane_s16(simde_mm_shufflelo_epi16_a_, (((imm8) >> 6) & 0x3)), simde_mm_shufflelo_epi16_r_, 3); \
      simde__m128i_from_neon_i16(simde_mm_shufflelo_epi16_r_); \
    }))
#elif defined(SIMDE_SHUFFLE_VECTOR_)
  #define simde_mm_shufflelo_epi16(a, imm8) (__extension__ ({ \
      const simde__m128i_private simde_tmp_a_ = simde__m128i_to_private(a); \
      simde__m128i_from_private((simde__m128i_private) { .i16 = \
        SIMDE_SHUFFLE_VECTOR_(16, 16, \
          (simde_tmp_a_).i16, \
          (simde_tmp_a_).i16, \
          (((imm8)     ) & 3), \
          (((imm8) >> 2) & 3), \
          (((imm8) >> 4) & 3), \
          (((imm8) >> 6) & 3), \
          4, 5, 6, 7) }); }))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_shufflelo_epi16(a, imm8) simde_mm_shufflelo_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sll_epi16 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sll_epi16(a, count);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      count_ = simde__m128i_to_private(count);

    if (count_.u64[0] > 15)
      return simde_mm_setzero_si128();

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.u16 = (a_.u16 << count_.u64[0]);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vshlq_u16(a_.neon_u16, vdupq_n_s16(HEDLEY_STATIC_CAST(int16_t, count_.u64[0])));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsll_h(a_.lsx_i64, __lsx_vreplgr2vr_h(count_.u64[0]));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = ((wasm_i64x2_extract_lane(count_.wasm_v128, 0) < 16) ? wasm_i16x8_shl(a_.wasm_v128, HEDLEY_STATIC_CAST(int32_t, wasm_i64x2_extract_lane(count_.wasm_v128, 0))) : wasm_i16x8_const(0,0,0,0,0,0,0,0));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (a_.u16[i] << count_.u64[0]));
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sll_epi16(a, count) simde_mm_sll_epi16((a), (count))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sll_epi32 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sll_epi32(a, count);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      count_ = simde__m128i_to_private(count);

    if (count_.u64[0] > 31)
      return simde_mm_setzero_si128();

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.u32 = (a_.u32 << count_.u64[0]);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u32 = vshlq_u32(a_.neon_u32, vdupq_n_s32(HEDLEY_STATIC_CAST(int32_t, count_.u64[0])));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsll_w(a_.lsx_i64, __lsx_vreplgr2vr_w(count_.u64[0]));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = ((wasm_i64x2_extract_lane(count_.wasm_v128, 0) < 32) ? wasm_i32x4_shl(a_.wasm_v128, HEDLEY_STATIC_CAST(int32_t, wasm_i64x2_extract_lane(count_.wasm_v128, 0))) : wasm_i32x4_const(0,0,0,0));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, (a_.u32[i] << count_.u64[0]));
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sll_epi32(a, count) (simde_mm_sll_epi32(a, (count)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sll_epi64 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sll_epi64(a, count);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      count_ = simde__m128i_to_private(count);

    if (count_.u64[0] > 63)
      return simde_mm_setzero_si128();

    const int_fast16_t s = HEDLEY_STATIC_CAST(int_fast16_t, count_.u64[0]);
    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u64 = vshlq_u64(a_.neon_u64, vdupq_n_s64(HEDLEY_STATIC_CAST(int64_t, s)));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = (s < 64) ? wasm_i64x2_shl(a_.wasm_v128, HEDLEY_STATIC_CAST(uint32_t, s)) : wasm_i64x2_const(0,0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsll_d(a_.lsx_i64, __lsx_vreplgr2vr_d(HEDLEY_STATIC_CAST(int64_t, s)));
    #else
      #if !defined(SIMDE_BUG_GCC_94488)
        SIMDE_VECTORIZE
      #endif
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] << s;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sll_epi64(a, count) (simde_mm_sll_epi64(a, (count)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sqrt_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sqrt_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vsqrtq_f64(a_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_sqrt(a_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r_.altivec_f64 = vec_sqrt(a_.altivec_f64);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vfsqrt_d(a_.lsx_f64);
    #elif defined(simde_math_sqrt)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = simde_math_sqrt(a_.f64[i]);
      }
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sqrt_pd(a) simde_mm_sqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sqrt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sqrt_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_sqrt_pd(b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_sqrt_pd(simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfsqrt_d(b_.lsx_f64), 0);
    #elif defined(simde_math_sqrt)
      r_.f64[0] = simde_math_sqrt(b_.f64[0]);
      r_.f64[1] = a_.f64[1];
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sqrt_sd(a, b) simde_mm_sqrt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srl_epi16 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_srl_epi16(a, count);
  #else
    simde__m128i_private
      r_,
      a_,
      count_ = simde__m128i_to_private(count);

    if (HEDLEY_UNLIKELY(count_.i64[0] > 15)) {
      return simde_mm_setzero_si128();
    }

    const int cnt = HEDLEY_STATIC_CAST(int, count_.i64[0]);

    a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vshlq_u16(a_.neon_u16, vdupq_n_s16(HEDLEY_STATIC_CAST(int16_t, -cnt)));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsrl_h(a_.lsx_i64, __lsx_vreplgr2vr_h(cnt));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] >> cnt;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srl_epi16(a, count) (simde_mm_srl_epi16(a, (count)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srl_epi32 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_srl_epi32(a, count);
  #else
    simde__m128i_private
      r_,
      a_,
      count_ = simde__m128i_to_private(count);

    if (HEDLEY_UNLIKELY(count_.i64[0] > 31)) {
      return simde_mm_setzero_si128();
    }

    const int cnt = HEDLEY_STATIC_CAST(int, count_.i64[0]);

    a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u32 = vshlq_u32(a_.neon_u32, vdupq_n_s32(HEDLEY_STATIC_CAST(int32_t, -cnt)));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u32x4_shr(a_.wasm_v128, HEDLEY_STATIC_CAST(uint32_t, cnt));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsrl_w(a_.lsx_i64, __lsx_vreplgr2vr_w(cnt));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] >> cnt;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srl_epi32(a, count) (simde_mm_srl_epi32(a, (count)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srl_epi64 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_srl_epi64(a, count);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      count_ = simde__m128i_to_private(count);

    if (HEDLEY_UNLIKELY(count_.i64[0] > 63)) {
      return simde_mm_setzero_si128();
    }

    const int cnt = HEDLEY_STATIC_CAST(int, count_.i64[0]);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u64 = vshlq_u64(a_.neon_u64, vdupq_n_s64(HEDLEY_STATIC_CAST(int64_t, -cnt)));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u64x2_shr(a_.wasm_v128, HEDLEY_STATIC_CAST(uint32_t, cnt));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsrl_d(a_.lsx_i64, __lsx_vreplgr2vr_d(cnt));
    #else
      #if !defined(SIMDE_BUG_GCC_94488)
        SIMDE_VECTORIZE
      #endif
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] >> cnt;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srl_epi64(a, count) (simde_mm_srl_epi64(a, (count)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srai_epi16 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  /* MSVC requires a range of (0, 255). */
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  const int cnt = (imm8 & ~15) ? 15 : imm8;

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i16 = vshlq_s16(a_.neon_i16, vdupq_n_s16(HEDLEY_STATIC_CAST(int16_t, -cnt)));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i16x8_shr(a_.wasm_v128, HEDLEY_STATIC_CAST(uint32_t, cnt));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vsra_h(a_.lsx_i64, __lsx_vreplgr2vr_h(cnt));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] >> cnt;
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_srai_epi16(a, imm8) _mm_srai_epi16((a), (imm8))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srai_epi16(a, imm8) simde_mm_srai_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srai_epi32 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  /* MSVC requires a range of (0, 255). */
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  const int cnt = (imm8 & ~31) ? 31 : imm8;

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i32 = vshlq_s32(a_.neon_i32, vdupq_n_s32(-cnt));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i32x4_shr(a_.wasm_v128, HEDLEY_STATIC_CAST(uint32_t, cnt));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vsra_w(a_.lsx_i64, __lsx_vreplgr2vr_w(cnt));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] >> cnt;
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_srai_epi32(a, imm8) _mm_srai_epi32((a), (imm8))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srai_epi32(a, imm8) simde_mm_srai_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sra_epi16 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sra_epi16(a, count);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      count_ = simde__m128i_to_private(count);

    const int cnt = HEDLEY_STATIC_CAST(int, (count_.i64[0] > 15 ? 15 : count_.i64[0]));

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vshlq_s16(a_.neon_i16, vdupq_n_s16(HEDLEY_STATIC_CAST(int16_t, -cnt)));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_shr(a_.wasm_v128, HEDLEY_STATIC_CAST(uint32_t, cnt));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vsra_h(a_.lsx_i64, __lsx_vreplgr2vr_h(cnt));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] >> cnt;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sra_epi16(a, count) (simde_mm_sra_epi16(a, count))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sra_epi32 (simde__m128i a, simde__m128i count) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(SIMDE_BUG_GCC_BAD_MM_SRA_EPI32)
    return _mm_sra_epi32(a, count);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      count_ = simde__m128i_to_private(count);

    const int cnt = count_.u64[0] > 31 ? 31 : HEDLEY_STATIC_CAST(int, count_.u64[0]);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vshlq_s32(a_.neon_i32, vdupq_n_s32(HEDLEY_STATIC_CAST(int32_t, -cnt)));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_shr(a_.wasm_v128, HEDLEY_STATIC_CAST(uint32_t, cnt));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsra_w(a_.lsx_i64, __lsx_vreplgr2vr_w(cnt));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] >> cnt;
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sra_epi32(a, count) (simde_mm_sra_epi32(a, (count)))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_slli_epi16 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  if (HEDLEY_UNLIKELY((imm8 > 15))) {
    return simde_mm_setzero_si128();
  }

  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vsll_h(a_.lsx_i64, __lsx_vreplgr2vr_h(imm8));
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.i16 = a_.i16 << SIMDE_CAST_VECTOR_SHIFT_COUNT(8, imm8 & 0xff);
  #else
    const int s = (imm8 > HEDLEY_STATIC_CAST(int, sizeof(r_.i16[0]) * CHAR_BIT) - 1) ? 0 : imm8;
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i16[i] << s);
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_slli_epi16(a, imm8) _mm_slli_epi16(a, imm8)
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_slli_epi16(a, imm8) \
    (((imm8) <= 0) ? \
      (a) : \
      simde__m128i_from_neon_i16( \
        ((imm8) > 15) ? \
          vandq_s16(simde__m128i_to_neon_i16(a), vdupq_n_s16(0)) : \
          vshlq_n_s16(simde__m128i_to_neon_i16(a), ((imm8) & 15))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_slli_epi16(a, imm8) \
    ((imm8 < 16) ? wasm_i16x8_shl(simde__m128i_to_private(a).wasm_v128, imm8) : wasm_i16x8_const(0,0,0,0,0,0,0,0))
#elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
  #define simde_mm_slli_epi16(a, imm8) \
    ((imm8 & ~15) ? simde_mm_setzero_si128() : simde__m128i_from_altivec_i16(vec_sl(simde__m128i_to_altivec_i16(a), vec_splat_u16(HEDLEY_STATIC_CAST(unsigned short, imm8)))))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_slli_epi16(a, imm8) simde_mm_slli_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_slli_epi32 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  if (HEDLEY_UNLIKELY((imm8 > 31))) {
    return simde_mm_setzero_si128();
  }
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vsll_w(a_.lsx_i64, __lsx_vreplgr2vr_w(imm8));
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.i32 = a_.i32 << imm8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] << (imm8 & 0xff);
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_slli_epi32(a, imm8) _mm_slli_epi32(a, imm8)
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_slli_epi32(a, imm8) \
    (((imm8) <= 0) ? \
      (a) : \
      simde__m128i_from_neon_i32( \
        ((imm8) > 31) ? \
          vandq_s32(simde__m128i_to_neon_i32(a), vdupq_n_s32(0)) : \
          vshlq_n_s32(simde__m128i_to_neon_i32(a), ((imm8) & 31))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_slli_epi32(a, imm8) \
    ((imm8 < 32) ? wasm_i32x4_shl(simde__m128i_to_private(a).wasm_v128, imm8) : wasm_i32x4_const(0,0,0,0))
#elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
  #define simde_mm_slli_epi32(a, imm8) \
     (__extension__ ({ \
       simde__m128i ret; \
       if ((imm8) <= 0) { \
         ret = a; \
       } else if ((imm8) > 31) { \
         ret = simde_mm_setzero_si128(); \
       } else { \
         ret = simde__m128i_from_altivec_i32( \
           vec_sl(simde__m128i_to_altivec_i32(a), \
             vec_splats(HEDLEY_STATIC_CAST(unsigned int, (imm8) & 31)))); \
       } \
       ret; \
     }))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_slli_epi32(a, imm8) simde_mm_slli_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_slli_epi64 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  if (HEDLEY_UNLIKELY((imm8 > 63))) {
    return simde_mm_setzero_si128();
  }
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vsll_d(a_.lsx_i64, __lsx_vreplgr2vr_d(imm8));
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.i64 = a_.i64 << imm8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] << (imm8 & 0xff);
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_slli_epi64(a, imm8) _mm_slli_epi64(a, imm8)
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_slli_epi64(a, imm8) \
    (((imm8) <= 0) ? \
      (a) : \
      simde__m128i_from_neon_i64( \
        ((imm8) > 63) ? \
          vandq_s64(simde__m128i_to_neon_i64(a), vdupq_n_s64(0)) : \
          vshlq_n_s64(simde__m128i_to_neon_i64(a), ((imm8) & 63))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_slli_epi64(a, imm8) \
    ((imm8 < 64) ? wasm_i64x2_shl(simde__m128i_to_private(a).wasm_v128, imm8) : wasm_i64x2_const(0,0))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_slli_epi64(a, imm8) simde_mm_slli_epi64(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srli_epi16 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  if (HEDLEY_UNLIKELY((imm8 > 15))) {
    return simde_mm_setzero_si128();
  }
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
   r_.lsx_i64 = __lsx_vsrl_h(a_.lsx_i64, __lsx_vreplgr2vr_h(imm8));
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u16 = a_.u16 >> SIMDE_CAST_VECTOR_SHIFT_COUNT(8, imm8);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.u16[i] = a_.u16[i] >> (imm8 & 0xff);
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_srli_epi16(a, imm8) _mm_srli_epi16(a, imm8)
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_srli_epi16(a, imm8) \
    (((imm8) <= 0) ? \
      (a) : \
      simde__m128i_from_neon_u16( \
        ((imm8) > 15) ? \
          vandq_u16(simde__m128i_to_neon_u16(a), vdupq_n_u16(0)) : \
          vshrq_n_u16(simde__m128i_to_neon_u16(a), ((imm8) & 15) | (((imm8) & 15) == 0))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_srli_epi16(a, imm8) \
    ((imm8 < 16) ? wasm_u16x8_shr(simde__m128i_to_private(a).wasm_v128, imm8) : wasm_i16x8_const(0,0,0,0,0,0,0,0))
#elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
  #define simde_mm_srli_epi16(a, imm8) \
    ((imm8 & ~15) ? simde_mm_setzero_si128() : simde__m128i_from_altivec_i16(vec_sr(simde__m128i_to_altivec_i16(a), vec_splat_u16(HEDLEY_STATIC_CAST(unsigned short, imm8)))))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srli_epi16(a, imm8) simde_mm_srli_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srli_epi32 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  if (HEDLEY_UNLIKELY((imm8 > 31))) {
    return simde_mm_setzero_si128();
  }
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
   r_.lsx_i64 = __lsx_vsrl_w(a_.lsx_i64, __lsx_vreplgr2vr_w(imm8));
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u32 = a_.u32 >> SIMDE_CAST_VECTOR_SHIFT_COUNT(8, imm8 & 0xff);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] >> (imm8 & 0xff);
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_srli_epi32(a, imm8) _mm_srli_epi32(a, imm8)
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_srli_epi32(a, imm8) \
    (((imm8) <= 0) ? \
      (a) : \
      simde__m128i_from_neon_u32( \
        ((imm8) > 31) ? \
          vandq_u32(simde__m128i_to_neon_u32(a), vdupq_n_u32(0)) : \
          vshrq_n_u32(simde__m128i_to_neon_u32(a), ((imm8) & 31) | (((imm8) & 31) == 0))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_srli_epi32(a, imm8) \
    ((imm8 < 32) ? wasm_u32x4_shr(simde__m128i_to_private(a).wasm_v128, imm8) : wasm_i32x4_const(0,0,0,0))
#elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
  #define simde_mm_srli_epi32(a, imm8) \
    (__extension__ ({ \
        simde__m128i ret; \
        if ((imm8) <= 0) { \
            ret = a; \
        } else if ((imm8) > 31) { \
            ret = simde_mm_setzero_si128(); \
        } else { \
            ret = simde__m128i_from_altivec_i32( \
              vec_sr(simde__m128i_to_altivec_i32(a), \
                vec_splats(HEDLEY_STATIC_CAST(unsigned int, (imm8) & 31)))); \
        } \
        ret; \
    }))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srli_epi32(a, imm8) simde_mm_srli_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srli_epi64 (simde__m128i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  if (HEDLEY_UNLIKELY((imm8 & 63) != imm8))
    return simde_mm_setzero_si128();

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_u64 = vshlq_u64(a_.neon_u64, vdupq_n_s64(-imm8));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
   r_.lsx_i64 = __lsx_vsrl_d(a_.lsx_i64, __lsx_vreplgr2vr_d(imm8));
  #else
    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && !defined(SIMDE_BUG_GCC_94488)
      r_.u64 = a_.u64 >> SIMDE_CAST_VECTOR_SHIFT_COUNT(8, imm8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] >> imm8;
      }
    #endif
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_mm_srli_epi64(a, imm8) _mm_srli_epi64(a, imm8)
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_mm_srli_epi64(a, imm8) \
    (((imm8) <= 0) ? \
      (a) : \
      simde__m128i_from_neon_u64( \
        ((imm8) > 63) ? \
          vandq_u64(simde__m128i_to_neon_u64(a), vdupq_n_u64(0)) : \
          vshrq_n_u64(simde__m128i_to_neon_u64(a), ((imm8) & 63) | (((imm8) & 63) == 0))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  #define simde_mm_srli_epi64(a, imm8) \
    ((imm8 < 64) ? wasm_u64x2_shr(simde__m128i_to_private(a).wasm_v128, imm8) : wasm_i64x2_const(0,0))
#endif
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_srli_epi64(a, imm8) simde_mm_srli_epi64(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_store_pd (simde_float64 mem_addr[HEDLEY_ARRAY_PARAM(2)], simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_store_pd(mem_addr, a);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst1q_f64(mem_addr, simde__m128d_to_private(a).neon_f64);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1q_s64(HEDLEY_REINTERPRET_CAST(int64_t*, mem_addr), simde__m128d_to_private(a).neon_i64);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vst(simde__m128d_to_private(a).lsx_i64, mem_addr, 0);
  #else
    simde_memcpy(SIMDE_ALIGN_ASSUME_LIKE(mem_addr, simde__m128d), &a, sizeof(a));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_store_pd(mem_addr, a) simde_mm_store_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_store1_pd (simde_float64 mem_addr[HEDLEY_ARRAY_PARAM(2)], simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_store1_pd(mem_addr, a);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      vst1q_f64(mem_addr, vdupq_laneq_f64(a_.neon_f64, 0));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vst(__lsx_vilvl_d(a_.lsx_i64, a_.lsx_i64), mem_addr, 0);
    #else
      mem_addr[0] = a_.f64[0];
      mem_addr[1] = a_.f64[0];
    #endif
  #endif
}
#define simde_mm_store_pd1(mem_addr, a) simde_mm_store1_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_store1_pd(mem_addr, a) simde_mm_store1_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
  #define _mm_store_pd1(mem_addr, a) simde_mm_store_pd1(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_store_sd (simde_float64* mem_addr, simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_store_sd(mem_addr, a);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      const simde_float64 v = vgetq_lane_f64(a_.neon_f64, 0);
      simde_memcpy(mem_addr, &v, sizeof(v));
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      const int64_t v = vgetq_lane_s64(a_.neon_i64, 0);
      simde_memcpy(HEDLEY_REINTERPRET_CAST(int64_t*, mem_addr), &v, sizeof(v));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      wasm_v128_store64_lane(HEDLEY_REINTERPRET_CAST(void*, mem_addr), a_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __lsx_vstelm_d(a_.lsx_i64, mem_addr, 0, 0);
    #else
      simde_float64 v = a_.f64[0];
      simde_memcpy(mem_addr, &v, sizeof(simde_float64));
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_store_sd(mem_addr, a) simde_mm_store_sd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_store_si128 (simde__m128i* mem_addr, simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_store_si128(HEDLEY_STATIC_CAST(__m128i*, mem_addr), a);
  #else
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      vst1q_s32(HEDLEY_REINTERPRET_CAST(int32_t*, mem_addr), a_.neon_i32);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __lsx_vst(a_.lsx_i64, mem_addr, 0);
    #else
      simde_memcpy(SIMDE_ALIGN_ASSUME_LIKE(mem_addr, simde__m128i), &a_, sizeof(a_));
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_store_si128(mem_addr, a) simde_mm_store_si128(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
  simde_mm_storeh_pd (simde_float64* mem_addr, simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_storeh_pd(mem_addr, a);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      *mem_addr = vgetq_lane_f64(a_.neon_f64, 1);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
       wasm_v128_store64_lane(HEDLEY_REINTERPRET_CAST(void*, mem_addr), a_.wasm_v128, 1);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __lsx_vstelm_d(a_.lsx_i64, mem_addr, 0, 1);
    #else
      *mem_addr = a_.f64[1];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storeh_pd(mem_addr, a) simde_mm_storeh_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storel_epi64 (simde__m128i* mem_addr, simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_storel_epi64(HEDLEY_STATIC_CAST(__m128i*, mem_addr), a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vstelm_d(simde__m128i_to_private(a).lsx_i64, mem_addr, 0, 0);
  #else
    simde__m128i_private a_ = simde__m128i_to_private(a);
    int64_t tmp;

    /* memcpy to prevent aliasing, tmp because we can't take the
     * address of a vector element. */

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      tmp = vgetq_lane_s64(a_.neon_i64, 0);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      #if defined(SIMDE_BUG_GCC_95227)
        (void) a_;
      #endif
      tmp = vec_extract(a_.altivec_i64, 0);
    #else
      tmp = a_.i64[0];
    #endif

    simde_memcpy(mem_addr, &tmp, sizeof(tmp));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storel_epi64(mem_addr, a) simde_mm_storel_epi64(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storel_pd (simde_float64* mem_addr, simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_storel_pd(mem_addr, a);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    wasm_v128_store64_lane(HEDLEY_REINTERPRET_CAST(void*, mem_addr), simde__m128d_to_wasm_v128(a), 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vstelm_d(simde__m128d_to_private(a).lsx_f64, mem_addr, 0, 0);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);

    simde_float64 tmp;
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      tmp = vgetq_lane_f64(a_.neon_f64, 0);
    #else
      tmp = a_.f64[0];
    #endif
    simde_memcpy(mem_addr, &tmp, sizeof(tmp));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storel_pd(mem_addr, a) simde_mm_storel_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storer_pd (simde_float64 mem_addr[2], simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_storer_pd(mem_addr, a);
  #else
    simde__m128d_private a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      vst1q_s64(HEDLEY_REINTERPRET_CAST(int64_t*, mem_addr), vextq_s64(a_.neon_i64, a_.neon_i64, 1));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      a_.wasm_v128 = wasm_i64x2_shuffle(a_.wasm_v128, a_.wasm_v128, 1, 0);
      simde_mm_store_pd(mem_addr, simde__m128d_from_private(a_));
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      a_.f64 = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.f64, a_.f64, 1, 0);
      simde_mm_store_pd(mem_addr, simde__m128d_from_private(a_));
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      __m128i temp = __lsx_vshuf4i_d(a_.lsx_i64, a_.lsx_i64, 0b0001);
      __lsx_vst(temp, mem_addr, 0);
    #else
      mem_addr[0] = a_.f64[1];
      mem_addr[1] = a_.f64[0];
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storer_pd(mem_addr, a) simde_mm_storer_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storeu_pd (simde_float64* mem_addr, simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_storeu_pd(mem_addr, a);
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst1q_f64(mem_addr, simde__m128d_to_private(a).neon_f64);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vst(simde__m128d_to_private(a).lsx_f64, mem_addr, 0);
  #else
    simde_memcpy(mem_addr, &a, sizeof(a));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storeu_pd(mem_addr, a) simde_mm_storeu_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storeu_si128 (void* mem_addr, simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_storeu_si128(HEDLEY_STATIC_CAST(__m128i*, mem_addr), a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vst(simde__m128i_to_private(a).lsx_i64, mem_addr, 0);
  #else
    simde_memcpy(mem_addr, &a, sizeof(a));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storeu_si128(mem_addr, a) simde_mm_storeu_si128(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storeu_si16 (void* mem_addr, simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && ( \
      SIMDE_DETECT_CLANG_VERSION_CHECK(8,0,0) || \
      HEDLEY_GCC_VERSION_CHECK(11,0,0) || \
      HEDLEY_INTEL_VERSION_CHECK(20,21,1))
    _mm_storeu_si16(mem_addr, a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vstelm_h(simde__m128i_to_private(a).lsx_i64, mem_addr, 0, 0);
  #else
    int16_t val = simde_x_mm_cvtsi128_si16(a);
    simde_memcpy(mem_addr, &val, sizeof(val));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storeu_si16(mem_addr, a) simde_mm_storeu_si16(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storeu_si32 (void* mem_addr, simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && ( \
      SIMDE_DETECT_CLANG_VERSION_CHECK(8,0,0) || \
      HEDLEY_GCC_VERSION_CHECK(11,0,0) || \
      HEDLEY_INTEL_VERSION_CHECK(20,21,1))
    _mm_storeu_si32(mem_addr, a);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    wasm_v128_store32_lane(mem_addr, simde__m128i_to_wasm_v128(a), 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vstelm_w(simde__m128i_to_private(a).lsx_i64, mem_addr, 0, 0);
  #else
    int32_t val = simde_mm_cvtsi128_si32(a);
    simde_memcpy(mem_addr, &val, sizeof(val));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storeu_si32(mem_addr, a) simde_mm_storeu_si32(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_storeu_si64 (void* mem_addr, simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && ( \
      SIMDE_DETECT_CLANG_VERSION_CHECK(8,0,0) || \
      HEDLEY_GCC_VERSION_CHECK(11,0,0) || \
      HEDLEY_INTEL_VERSION_CHECK(20,21,1))
    _mm_storeu_si64(mem_addr, a);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    __lsx_vstelm_d(simde__m128i_to_private(a).lsx_i64, mem_addr, 0, 0);
  #else
    int64_t val = simde_mm_cvtsi128_si64(a);
    simde_memcpy(mem_addr, &val, sizeof(val));
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_storeu_si64(mem_addr, a) simde_mm_storeu_si64(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_stream_pd (simde_float64 mem_addr[HEDLEY_ARRAY_PARAM(2)], simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_stream_pd(mem_addr, a);
  #elif HEDLEY_HAS_BUILTIN(__builtin_nontemporal_store) && ( \
      defined(SIMDE_VECTOR_SUBSCRIPT) || defined(SIMDE_ARM_NEON_A64V8_NATIVE) || \
      defined(SIMDE_WASM_SIMD128_NATIVE) || defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) || \
      defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE) || defined(SIMDE_LOONGARCH_LSX_NATIVE))
      __builtin_nontemporal_store(a, SIMDE_ALIGN_CAST(__typeof__(a)*, mem_addr));
  #else
    simde_mm_store_pd(mem_addr, a);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_stream_pd(mem_addr, a) simde_mm_stream_pd(HEDLEY_REINTERPRET_CAST(double*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_stream_si128 (simde__m128i* mem_addr, simde__m128i a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64)
    _mm_stream_si128(HEDLEY_STATIC_CAST(__m128i*, mem_addr), a);
  #elif HEDLEY_HAS_BUILTIN(__builtin_nontemporal_store) && ( \
      defined(SIMDE_VECTOR_SUBSCRIPT) || defined(SIMDE_ARM_NEON_A32V7_NATIVE) || \
      defined(SIMDE_WASM_SIMD128_NATIVE) || defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || \
      defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE) || defined(SIMDE_LOONGARCH_LSX_NATIVE))
      __builtin_nontemporal_store(a, SIMDE_ALIGN_CAST(__typeof__(a)*, mem_addr));
  #else
    simde_mm_store_si128(mem_addr, a);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_stream_si128(mem_addr, a) simde_mm_stream_si128(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_stream_si32 (int32_t* mem_addr, int32_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_stream_si32(mem_addr, a);
  #elif HEDLEY_HAS_BUILTIN(__builtin_nontemporal_store)
    __builtin_nontemporal_store(a, mem_addr);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1q_lane_s32(mem_addr, vdupq_n_s32(a), 0);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return __lsx_vstelm_w(__lsx_vreplgr2vr_w(a), mem_addr, 0, 0);
  #else
    *mem_addr = a;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_stream_si32(mem_addr, a) simde_mm_stream_si32(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_stream_si64 (int64_t* mem_addr, int64_t a) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64) && !defined(HEDLEY_MSVC_VERSION)
    _mm_stream_si64(SIMDE_CHECKED_REINTERPRET_CAST(long long int*, int64_t*, mem_addr), a);
  #elif HEDLEY_HAS_BUILTIN(__builtin_nontemporal_store)
    __builtin_nontemporal_store(a, mem_addr);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_s64(mem_addr, vdup_n_s64(a));
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    return __lsx_vstelm_d(__lsx_vreplgr2vr_d(a), mem_addr, 0, 0);
  #else
    *mem_addr = a;
  #endif
}
#define simde_mm_stream_si64x(mem_addr, a) simde_mm_stream_si64(mem_addr, a)
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_AMD64))
  #define _mm_stream_si64(mem_addr, a) simde_mm_stream_si64(SIMDE_CHECKED_REINTERPRET_CAST(int64_t*, __int64*, mem_addr), a)
  #define _mm_stream_si64x(mem_addr, a) simde_mm_stream_si64(SIMDE_CHECKED_REINTERPRET_CAST(int64_t*, __int64*, mem_addr), a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sub_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sub_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vsubq_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_sub(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsub_b(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 - b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] - b_.i8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sub_epi8(a, b) simde_mm_sub_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sub_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sub_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vsubq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_sub(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsub_h(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 - b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] - b_.i16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sub_epi16(a, b) simde_mm_sub_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sub_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sub_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vsubq_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_sub(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsub_w(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 - b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] - b_.i32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sub_epi32(a, b) simde_mm_sub_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sub_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sub_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vsubq_s64(a_.neon_i64, b_.neon_i64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_sub(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vsub_d(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 - b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] - b_.i64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sub_epi64(a, b) simde_mm_sub_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_sub_epu32 (simde__m128i a, simde__m128i b) {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u32 = a_.u32 - b_.u32;
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_u32 = vsubq_u32(a_.neon_u32, b_.neon_u32);
  #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
    r_.lsx_i64 = __lsx_vsub_w(a_.lsx_i64, b_.lsx_i64);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] - b_.u32[i];
    }
  #endif

  return simde__m128i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sub_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sub_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 - b_.f64;
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vsubq_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_sub(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_f64 = __lsx_vfsub_d(a_.lsx_f64, b_.lsx_f64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = a_.f64[i] - b_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sub_pd(a, b) simde_mm_sub_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sub_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_sub_sd(a, b);
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0) && defined(SIMDE_FAST_EXCEPTIONS)
    return simde_mm_move_sd(a, simde_mm_sub_pd(a, b));
  #elif (SIMDE_NATURAL_VECTOR_SIZE > 0)
    return simde_mm_move_sd(a, simde_mm_sub_pd(simde_x_mm_broadcastlow_pd(a), simde_x_mm_broadcastlow_pd(b)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
      #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
          r_.lsx_i64 = __lsx_vextrins_d(a_.lsx_i64, (__m128i)__lsx_vfsub_d(a_.lsx_f64, b_.lsx_f64), 0);
      #else
          r_.f64[0] = a_.f64[0] - b_.f64[0];
          r_.f64[1] = a_.f64[1];
      #endif
    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sub_sd(a, b) simde_mm_sub_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sub_si64 (simde__m64 a, simde__m64 b) {
  #if defined(SIMDE_X86_SSE2_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_sub_si64(a, b);
  #else
    simde__m64_private
      r_,
      a_ = simde__m64_to_private(a),
      b_ = simde__m64_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 - b_.i64;
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i64 = vsub_s64(a_.neon_i64, b_.neon_i64);
    #else
      r_.i64[0] = a_.i64[0] - b_.i64[0];
    #endif

    return simde__m64_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_sub_si64(a, b) simde_mm_sub_si64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_subs_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_subs_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vqsubq_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_sub_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vssub_b(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = simde_math_subs_i8(a_.i8[i], b_.i8[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_subs_epi8(a, b) simde_mm_subs_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_subs_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_subs_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i16 = vqsubq_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_sub_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vssub_h(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = simde_math_subs_i16(a_.i16[i], b_.i16[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_subs_epi16(a, b) simde_mm_subs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_subs_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_subs_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u8 = vqsubq_u8(a_.neon_u8, b_.neon_u8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u8x16_sub_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_u8 = vec_subs(a_.altivec_u8, b_.altivec_u8);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vssub_bu(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = simde_math_subs_u8(a_.u8[i], b_.u8[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_subs_epu8(a, b) simde_mm_subs_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_subs_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_subs_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_u16 = vqsubq_u16(a_.neon_u16, b_.neon_u16);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_u16x8_sub_sat(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_u16 = vec_subs(a_.altivec_u16, b_.altivec_u16);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vssub_hu(a_.lsx_i64, b_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = simde_math_subs_u16(a_.u16[i], b_.u16[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_subs_epu16(a, b) simde_mm_subs_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_ucomieq_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_ucomieq_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    int r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t a_not_nan = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t b_not_nan = vceqq_f64(b_.neon_f64, b_.neon_f64);
      uint64x2_t a_or_b_nan = vreinterpretq_u64_u32(vmvnq_u32(vreinterpretq_u32_u64(vandq_u64(a_not_nan, b_not_nan))));
      uint64x2_t a_eq_b = vceqq_f64(a_.neon_f64, b_.neon_f64);
      r = !!(vgetq_lane_u64(vorrq_u64(a_or_b_nan, a_eq_b), 0) != 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) == wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = !!__lsx_vpickve2gr_d(__lsx_vfcmp_ceq_d(a_.lsx_f64, b_.lsx_f64), 0);
    #elif defined(SIMDE_HAVE_FENV_H)
      fenv_t envp;
      int x = feholdexcept(&envp);
      r =  a_.f64[0] == b_.f64[0];
      if (HEDLEY_LIKELY(x == 0))
        fesetenv(&envp);
    #else
      r =  a_.f64[0] == b_.f64[0];
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_ucomieq_sd(a, b) simde_mm_ucomieq_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_ucomige_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_ucomige_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    int r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t a_not_nan = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t b_not_nan = vceqq_f64(b_.neon_f64, b_.neon_f64);
      uint64x2_t a_and_b_not_nan = vandq_u64(a_not_nan, b_not_nan);
      uint64x2_t a_ge_b = vcgeq_f64(a_.neon_f64, b_.neon_f64);
      r = !!(vgetq_lane_u64(vandq_u64(a_and_b_not_nan, a_ge_b), 0) != 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) >= wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = !!__lsx_vpickve2gr_d(__lsx_vfcmp_cle_d(b_.lsx_f64, a_.lsx_f64), 0);
    #elif defined(SIMDE_HAVE_FENV_H)
      fenv_t envp;
      int x = feholdexcept(&envp);
      r = a_.f64[0] >= b_.f64[0];
      if (HEDLEY_LIKELY(x == 0))
        fesetenv(&envp);
    #else
      r = a_.f64[0] >= b_.f64[0];
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_ucomige_sd(a, b) simde_mm_ucomige_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_ucomigt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_ucomigt_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    int r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t a_not_nan = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t b_not_nan = vceqq_f64(b_.neon_f64, b_.neon_f64);
      uint64x2_t a_and_b_not_nan = vandq_u64(a_not_nan, b_not_nan);
      uint64x2_t a_gt_b = vcgtq_f64(a_.neon_f64, b_.neon_f64);
      r = !!(vgetq_lane_u64(vandq_u64(a_and_b_not_nan, a_gt_b), 0) != 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) > wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = !!__lsx_vpickve2gr_d(__lsx_vfcmp_clt_d(b_.lsx_f64, a_.lsx_f64), 0);
    #elif defined(SIMDE_HAVE_FENV_H)
      fenv_t envp;
      int x = feholdexcept(&envp);
      r = a_.f64[0] > b_.f64[0];
      if (HEDLEY_LIKELY(x == 0))
        fesetenv(&envp);
    #else
      r = a_.f64[0] > b_.f64[0];
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_ucomigt_sd(a, b) simde_mm_ucomigt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_ucomile_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_ucomile_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    int r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t a_not_nan = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t b_not_nan = vceqq_f64(b_.neon_f64, b_.neon_f64);
      uint64x2_t a_or_b_nan = vreinterpretq_u64_u32(vmvnq_u32(vreinterpretq_u32_u64(vandq_u64(a_not_nan, b_not_nan))));
      uint64x2_t a_le_b = vcleq_f64(a_.neon_f64, b_.neon_f64);
      r = !!(vgetq_lane_u64(vorrq_u64(a_or_b_nan, a_le_b), 0) != 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) <= wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = !!__lsx_vpickve2gr_d(__lsx_vfcmp_cle_d(a_.lsx_f64, b_.lsx_f64), 0);
    #elif defined(SIMDE_HAVE_FENV_H)
      fenv_t envp;
      int x = feholdexcept(&envp);
      r = a_.f64[0] <= b_.f64[0];
      if (HEDLEY_LIKELY(x == 0))
        fesetenv(&envp);
    #else
      r = a_.f64[0] <= b_.f64[0];
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_ucomile_sd(a, b) simde_mm_ucomile_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_ucomilt_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_ucomilt_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    int r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t a_not_nan = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t b_not_nan = vceqq_f64(b_.neon_f64, b_.neon_f64);
      uint64x2_t a_or_b_nan = vreinterpretq_u64_u32(vmvnq_u32(vreinterpretq_u32_u64(vandq_u64(a_not_nan, b_not_nan))));
      uint64x2_t a_lt_b = vcltq_f64(a_.neon_f64, b_.neon_f64);
      r = !!(vgetq_lane_u64(vorrq_u64(a_or_b_nan, a_lt_b), 0) != 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) < wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = !!__lsx_vpickve2gr_d(__lsx_vfcmp_clt_d(a_.lsx_f64, b_.lsx_f64), 0);
    #elif defined(SIMDE_HAVE_FENV_H)
      fenv_t envp;
      int x = feholdexcept(&envp);
      r = a_.f64[0] < b_.f64[0];
      if (HEDLEY_LIKELY(x == 0))
        fesetenv(&envp);
    #else
      r = a_.f64[0] < b_.f64[0];
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_ucomilt_sd(a, b) simde_mm_ucomilt_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_ucomineq_sd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_ucomineq_sd(a, b);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);
    int r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      uint64x2_t a_not_nan = vceqq_f64(a_.neon_f64, a_.neon_f64);
      uint64x2_t b_not_nan = vceqq_f64(b_.neon_f64, b_.neon_f64);
      uint64x2_t a_and_b_not_nan = vandq_u64(a_not_nan, b_not_nan);
      uint64x2_t a_neq_b = vreinterpretq_u64_u32(vmvnq_u32(vreinterpretq_u32_u64(vceqq_f64(a_.neon_f64, b_.neon_f64))));
      r = !!(vgetq_lane_u64(vandq_u64(a_and_b_not_nan, a_neq_b), 0) != 0);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      return wasm_f64x2_extract_lane(a_.wasm_v128, 0) != wasm_f64x2_extract_lane(b_.wasm_v128, 0);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r = !!__lsx_vpickve2gr_d(__lsx_vfcmp_cune_d(a_.lsx_f64, b_.lsx_f64), 0);
    #elif defined(SIMDE_HAVE_FENV_H)
      fenv_t envp;
      int x = feholdexcept(&envp);
      r = a_.f64[0] != b_.f64[0];
      if (HEDLEY_LIKELY(x == 0))
        fesetenv(&envp);
    #else
      r = a_.f64[0] != b_.f64[0];
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_ucomineq_sd(a, b) simde_mm_ucomineq_sd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_lfence (void) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_lfence();
  #else
    simde_mm_sfence();
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_lfence() simde_mm_lfence()
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm_mfence (void) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    _mm_mfence();
  #else
    simde_mm_sfence();
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_mfence() simde_mm_mfence()
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpackhi_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpackhi_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i8 = vzip2q_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int8x8_t a1 = vreinterpret_s8_s16(vget_high_s16(a_.neon_i16));
      int8x8_t b1 = vreinterpret_s8_s16(vget_high_s16(b_.neon_i16));
      int8x8x2_t result = vzip_s8(a1, b1);
      r_.neon_i8 = vcombine_s8(result.val[0], result.val[1]);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_shuffle(a_.wasm_v128, b_.wasm_v128, 8, 24, 9, 25, 10, 26, 11, 27, 12, 28, 13, 29, 14, 30, 15, 31);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvh_b(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i8 = SIMDE_SHUFFLE_VECTOR_(8, 16, a_.i8, b_.i8, 8, 24, 9, 25, 10, 26, 11, 27, 12, 28, 13, 29, 14, 30, 15, 31);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i8[0])) / 2) ; i++) {
        r_.i8[(i * 2)]     = a_.i8[i + ((sizeof(r_) / sizeof(r_.i8[0])) / 2)];
        r_.i8[(i * 2) + 1] = b_.i8[i + ((sizeof(r_) / sizeof(r_.i8[0])) / 2)];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpackhi_epi8(a, b) simde_mm_unpackhi_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpackhi_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpackhi_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i16 = vzip2q_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int16x4_t a1 = vget_high_s16(a_.neon_i16);
      int16x4_t b1 = vget_high_s16(b_.neon_i16);
      int16x4x2_t result = vzip_s16(a1, b1);
      r_.neon_i16 = vcombine_s16(result.val[0], result.val[1]);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_shuffle(a_.wasm_v128, b_.wasm_v128, 4, 12, 5, 13, 6, 14, 7, 15);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvh_h(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i16 = SIMDE_SHUFFLE_VECTOR_(16, 16, a_.i16, b_.i16, 4, 12, 5, 13, 6, 14, 7, 15);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i16[0])) / 2) ; i++) {
        r_.i16[(i * 2)]     = a_.i16[i + ((sizeof(r_) / sizeof(r_.i16[0])) / 2)];
        r_.i16[(i * 2) + 1] = b_.i16[i + ((sizeof(r_) / sizeof(r_.i16[0])) / 2)];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpackhi_epi16(a, b) simde_mm_unpackhi_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpackhi_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpackhi_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i32 = vzip2q_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int32x2_t a1 = vget_high_s32(a_.neon_i32);
      int32x2_t b1 = vget_high_s32(b_.neon_i32);
      int32x2x2_t result = vzip_s32(a1, b1);
      r_.neon_i32 = vcombine_s32(result.val[0], result.val[1]);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_shuffle(a_.wasm_v128, b_.wasm_v128, 2, 6, 3, 7);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvh_w(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i32 = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.i32, b_.i32, 2, 6, 3, 7);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i32[0])) / 2) ; i++) {
        r_.i32[(i * 2)]     = a_.i32[i + ((sizeof(r_) / sizeof(r_.i32[0])) / 2)];
        r_.i32[(i * 2) + 1] = b_.i32[i + ((sizeof(r_) / sizeof(r_.i32[0])) / 2)];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpackhi_epi32(a, b) simde_mm_unpackhi_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpackhi_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpackhi_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int64x1_t a_h = vget_high_s64(a_.neon_i64);
      int64x1_t b_h = vget_high_s64(b_.neon_i64);
      r_.neon_i64 = vcombine_s64(a_h, b_h);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_shuffle(a_.wasm_v128, b_.wasm_v128, 1, 3);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvh_d(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i64 = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.i64, b_.i64, 1, 3);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i64[0])) / 2) ; i++) {
        r_.i64[(i * 2)]     = a_.i64[i + ((sizeof(r_) / sizeof(r_.i64[0])) / 2)];
        r_.i64[(i * 2) + 1] = b_.i64[i + ((sizeof(r_) / sizeof(r_.i64[0])) / 2)];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpackhi_epi64(a, b) simde_mm_unpackhi_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_unpackhi_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpackhi_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vzip2q_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_shuffle(a_.wasm_v128, b_.wasm_v128, 1, 3);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.f64 = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.f64, b_.f64, 1, 3);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvh_d(b_.lsx_i64, a_.lsx_i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.f64[0])) / 2) ; i++) {
        r_.f64[(i * 2)]     = a_.f64[i + ((sizeof(r_) / sizeof(r_.f64[0])) / 2)];
        r_.f64[(i * 2) + 1] = b_.f64[i + ((sizeof(r_) / sizeof(r_.f64[0])) / 2)];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpackhi_pd(a, b) simde_mm_unpackhi_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpacklo_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpacklo_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i8 = vzip1q_s8(a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int8x8_t a1 = vreinterpret_s8_s16(vget_low_s16(a_.neon_i16));
      int8x8_t b1 = vreinterpret_s8_s16(vget_low_s16(b_.neon_i16));
      int8x8x2_t result = vzip_s8(a1, b1);
      r_.neon_i8 = vcombine_s8(result.val[0], result.val[1]);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x16_shuffle(a_.wasm_v128, b_.wasm_v128, 0, 16, 1, 17, 2, 18, 3, 19, 4, 20, 5, 21, 6, 22, 7, 23);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvl_b(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i8 = SIMDE_SHUFFLE_VECTOR_(8, 16, a_.i8, b_.i8, 0, 16, 1, 17, 2, 18, 3, 19, 4, 20, 5, 21, 6, 22, 7, 23);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i8[0])) / 2) ; i++) {
        r_.i8[(i * 2)]     = a_.i8[i];
        r_.i8[(i * 2) + 1] = b_.i8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpacklo_epi8(a, b) simde_mm_unpacklo_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpacklo_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpacklo_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i16 = vzip1q_s16(a_.neon_i16, b_.neon_i16);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int16x4_t a1 = vget_low_s16(a_.neon_i16);
      int16x4_t b1 = vget_low_s16(b_.neon_i16);
      int16x4x2_t result = vzip_s16(a1, b1);
      r_.neon_i16 = vcombine_s16(result.val[0], result.val[1]);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x8_shuffle(a_.wasm_v128, b_.wasm_v128, 0, 8, 1, 9, 2, 10, 3, 11);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvl_h(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i16 = SIMDE_SHUFFLE_VECTOR_(16, 16, a_.i16, b_.i16, 0, 8, 1, 9, 2, 10, 3, 11);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i16[0])) / 2) ; i++) {
        r_.i16[(i * 2)]     = a_.i16[i];
        r_.i16[(i * 2) + 1] = b_.i16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpacklo_epi16(a, b) simde_mm_unpacklo_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpacklo_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpacklo_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i32 = vzip1q_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int32x2_t a1 = vget_low_s32(a_.neon_i32);
      int32x2_t b1 = vget_low_s32(b_.neon_i32);
      int32x2x2_t result = vzip_s32(a1, b1);
      r_.neon_i32 = vcombine_s32(result.val[0], result.val[1]);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_shuffle(a_.wasm_v128, b_.wasm_v128, 0, 4, 1, 5);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvl_w(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i32 = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.i32, b_.i32, 0, 4, 1, 5);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i32[0])) / 2) ; i++) {
        r_.i32[(i * 2)]     = a_.i32[i];
        r_.i32[(i * 2) + 1] = b_.i32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpacklo_epi32(a, b) simde_mm_unpacklo_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_unpacklo_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpacklo_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int64x1_t a_l = vget_low_s64(a_.neon_i64);
      int64x1_t b_l = vget_low_s64(b_.neon_i64);
      r_.neon_i64 = vcombine_s64(a_l, b_l);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_shuffle(a_.wasm_v128, b_.wasm_v128, 0, 2);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvl_d(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i64 = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.i64, b_.i64, 0, 2);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.i64[0])) / 2) ; i++) {
        r_.i64[(i * 2)]     = a_.i64[i];
        r_.i64[(i * 2) + 1] = b_.i64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpacklo_epi64(a, b) simde_mm_unpacklo_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_unpacklo_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_unpacklo_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vzip1q_f64(a_.neon_f64, b_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_shuffle(a_.wasm_v128, b_.wasm_v128, 0, 2);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vilvl_d(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_SHUFFLE_VECTOR_)
      r_.f64 = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.f64, b_.f64, 0, 2);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < ((sizeof(r_) / sizeof(r_.f64[0])) / 2) ; i++) {
        r_.f64[(i * 2)]     = a_.f64[i];
        r_.f64[(i * 2) + 1] = b_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_unpacklo_pd(a, b) simde_mm_unpacklo_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_negate_pd(simde__m128d a) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return simde_mm_xor_pd(a, _mm_set1_pd(SIMDE_FLOAT64_C(-0.0)));
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    #if defined(SIMDE_POWER_ALTIVEC_P8_NATIVE) && \
        (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,1,0))
      r_.altivec_f64 = vec_neg(a_.altivec_f64);
    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_f64 = vnegq_f64(a_.neon_f64);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_f64x2_neg(a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vneg_d(a_.lsx_i64);
    #elif defined(SIMDE_VECTOR_NEGATE)
      r_.f64 = -a_.f64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = -a_.f64[i];
      }
    #endif

    return simde__m128d_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_xor_si128 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_xor_si128(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = veorq_s32(a_.neon_i32, b_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32 = vec_xor(a_.altivec_i32, b_.altivec_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_xor(b_.wasm_v128, a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vxor_v(a_.lsx_i64, b_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f ^ b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] ^ b_.i32f[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _mm_xor_si128(a, b) simde_mm_xor_si128(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_not_si128 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, a, a, 0x55);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i32 = vmvnq_s32(a_.neon_i32);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i32 = vec_nor(a_.altivec_i32, a_.altivec_i32);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_not(a_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vnor_v(a_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = ~a_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = ~(a_.i32f[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}

#define SIMDE_MM_SHUFFLE2(x, y) (((x) << 1) | (y))
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
  #define _MM_SHUFFLE2(x, y) SIMDE_MM_SHUFFLE2(x, y)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_SSE2_H) */
