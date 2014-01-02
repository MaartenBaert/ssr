/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

This file is part of SimpleScreenRecorder.

SimpleScreenRecorder is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SimpleScreenRecorder is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SimpleScreenRecorder.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Global.h"
#include "FastScaler_Convert.h"

#if SSR_USE_X86_ASM

#ifndef __MMX__
#define __MMX__
#endif
#ifndef __SSE__
#define __SSE__
#endif
#ifndef __SSE2__
#define __SSE2__
#endif
#ifndef __SSE3__
#define __SSE3__
#endif
#ifndef __SSSE3__
#define __SSSE3__
#endif

#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <tmmintrin.h>

#endif

/*
==== Fallback BGRA-to-YUV420 Converter ====

Nothing special, just plain C code. It processes blocks of 2x2 pixels of the input image and produces 2x2 Y, 1x1 U and 1x1 V values.
*/

void Convert_BGRA_YUV420_Fallback(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	Q_ASSERT(w % 2 == 0 && h % 2 == 0);

	const int offset_y = 128 + (16 << 8), offset_uv = (128 + (128 << 8)) << 2;

	for(unsigned int j = 0; j < h / 2; ++j) {
		const uint32_t *rgb1 = (const uint32_t*) (in_data + in_stride * (int) j * 2);
		const uint32_t *rgb2 = (const uint32_t*) (in_data + in_stride * ((int) j * 2 + 1));
		uint8_t *yuv_y1 = out_data[0] + out_stride[0] * (int) j * 2;
		uint8_t *yuv_y2 = out_data[0] + out_stride[0] * ((int) j * 2 + 1);
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 2; ++i) {
			uint32_t c[4] = {rgb1[0], rgb1[1], rgb2[0], rgb2[1]};
			rgb1 += 2; rgb2 += 2;
			int r[4] = {(int) ((c[0] >> 16) & 0xff), (int) ((c[1] >> 16) & 0xff), (int) ((c[2] >> 16) & 0xff), (int) ((c[3] >> 16) & 0xff)};
			int g[4] = {(int) ((c[0] >>  8) & 0xff), (int) ((c[1] >>  8) & 0xff), (int) ((c[2] >>  8) & 0xff), (int) ((c[3] >>  8) & 0xff)};
			int b[4] = {(int) ((c[0]      ) & 0xff), (int) ((c[1]      ) & 0xff), (int) ((c[2]      ) & 0xff), (int) ((c[3]      ) & 0xff)};
			yuv_y1[0] = (66 * r[0] + 129 * g[0] + 25 * b[0] + offset_y) >> 8;
			yuv_y1[1] = (66 * r[1] + 129 * g[1] + 25 * b[1] + offset_y) >> 8;
			yuv_y2[0] = (66 * r[2] + 129 * g[2] + 25 * b[2] + offset_y) >> 8;
			yuv_y2[1] = (66 * r[3] + 129 * g[3] + 25 * b[3] + offset_y) >> 8;
			yuv_y1 += 2; yuv_y2 += 2;
			int sr = r[0] + r[1] + r[2] + r[3];
			int sg = g[0] + g[1] + g[2] + g[3];
			int sb = b[0] + b[1] + b[2] + b[3];
			*yuv_u = (-38 * sr + -74 * sg + 112 * sb + offset_uv) >> 10;
			*yuv_v = (112 * sr + -94 * sg + -18 * sb + offset_uv) >> 10;
			++yuv_u; ++yuv_v;
		}
	}

}

#if SSR_USE_X86_ASM

/*
==== SSSE3 BGRA-to-YUV420 Converter ====

Uses the same principle as the fallback converter, but uses 16-bit integers so it can do 8 operations at once.
It processes blocks of 16x2 pixels of the input image and produces 16x2 Y, 8x1 U and 8x1 V values.

The code uses interleaving to reduce the number of shuffles. So for example the order for red is [ r0 r4 r1 r5 r2 r6 r3 r7 ].
For the averaging of 2x2 blocks, it uses 32-bit horizontal addition instead of 16-bit because of this interleaving.
The order of the final result is [ sr0 sr2 sr1 sr3 sr4 sr6 sr5 sr7 ].

If the width is not a multiple of 16, the remainder (right edge of the image) is converted without SSSE3.

This converter is about 4 times faster than the fallback converter.
*/

#define Convert3_ReadRGB(ptr1, ptr2, ca, cb, r, g, b) \
	__m128i ca = _mm_loadu_si128((__m128i*) (ptr1)), cb = _mm_loadu_si128((__m128i*) (ptr2)); \
	__m128i r = _mm_or_si128(_mm_and_si128(_mm_srli_si128(ca, 2), v_byte1), _mm_and_si128(               cb    , v_byte3)); \
	__m128i g = _mm_or_si128(_mm_and_si128(_mm_srli_si128(ca, 1), v_byte1), _mm_and_si128(_mm_slli_si128(cb, 1), v_byte3)); \
	__m128i b = _mm_or_si128(_mm_and_si128(               ca    , v_byte1), _mm_and_si128(_mm_slli_si128(cb, 2), v_byte3));
#define Convert3_CalcY(r, g, b, y) \
	__m128i y = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(r, v_mat_yr), _mm_mullo_epi16(g, v_mat_yg)), _mm_add_epi16(_mm_mullo_epi16(b, v_mat_yb), v_offset_y));
#define Convert3_WriteY(ptr, y1, y2) \
	_mm_stream_si128((__m128i*) (ptr), _mm_or_si128(_mm_shuffle_epi8(y1, v_shuffle1), _mm_shuffle_epi8(y2, v_shuffle2)));

void Convert_BGRA_YUV420_SSSE3(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	Q_ASSERT(w % 2 == 0 && h % 2 == 0);
	Q_ASSERT((uintptr_t) out_data[0] % 16 == 0 && out_stride[0] % 16 == 0);
	Q_ASSERT((uintptr_t) out_data[1] % 16 == 0 && out_stride[1] % 16 == 0);
	Q_ASSERT((uintptr_t) out_data[2] % 16 == 0 && out_stride[2] % 16 == 0);

	__m128i v_byte1     = _mm_set1_epi32(0x000000ff);
	__m128i v_byte3     = _mm_set1_epi32(0x00ff0000);
	__m128i v_mat_yr    = _mm_set1_epi16(66);
	__m128i v_mat_yg    = _mm_set1_epi16(129);
	__m128i v_mat_yb    = _mm_set1_epi16(25);
	__m128i v_mat_ur    = _mm_set1_epi16(-38);
	__m128i v_mat_ug    = _mm_set1_epi16(-74);
	__m128i v_mat_ub_vr = _mm_set1_epi16(112);
	__m128i v_mat_vg    = _mm_set1_epi16(-94);
	__m128i v_mat_vb    = _mm_set1_epi16(-18);
	__m128i v_offset_y  = _mm_set1_epi16(128 + (16 << 8));
	__m128i v_offset_uv = _mm_set1_epi16(128 + (128 << 8));
	__m128i v_2         = _mm_set1_epi16(2);
	__m128i v_shuffle1  = _mm_setr_epi8(1, 5, 9, 13, 3, 7, 11, 15, 255, 255, 255, 255, 255, 255, 255, 255);
	__m128i v_shuffle2  = _mm_setr_epi8(255, 255, 255, 255, 255, 255, 255, 255, 1, 5, 9, 13, 3, 7, 11, 15);
	__m128i v_shuffle3  = _mm_setr_epi8(1, 5, 3, 7, 9, 13, 11, 15, 255, 255, 255, 255, 255, 255, 255, 255);
	//__m128i v_shuffle4  = _mm_setr_epi8(255, 255, 255, 255, 255, 255, 255, 255, 1, 5, 3, 7, 9, 13, 11, 15);

	const int offset_y = 128 + (16 << 8), offset_uv = (128 + (128 << 8)) << 2;

	for(unsigned int j = 0; j < h / 2; ++j) {
		const uint32_t *rgb1 = (const uint32_t*) (in_data + in_stride * (int) (j * 2));
		const uint32_t *rgb2 = (const uint32_t*) (in_data + in_stride * (int) (j * 2 + 1));
		uint8_t *yuv_y1 = out_data[0] + out_stride[0] * (int) (j * 2);
		uint8_t *yuv_y2 = out_data[0] + out_stride[0] * (int) (j * 2 + 1);
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 16; ++i) {
			__m128i ra, ga, ba;
			{
				Convert3_ReadRGB(rgb1, rgb1 + 4, ca0, cb0, r0, g0, b0);
				Convert3_ReadRGB(rgb1 + 8, rgb1 + 12, ca1, cb1, r1, g1, b1);
				rgb1 += 16;
				Convert3_CalcY(r0, g0, b0, y0);
				Convert3_CalcY(r1, g1, b1, y1);
				Convert3_WriteY(yuv_y1, y0, y1);
				yuv_y1 += 16;
				_mm_prefetch(rgb1 + 16, _MM_HINT_T0);
				ra = _mm_hadd_epi32(r0, r1);
				ga = _mm_hadd_epi32(g0, g1);
				ba = _mm_hadd_epi32(b0, b1);
			}
			{
				Convert3_ReadRGB(rgb2, rgb2 + 4, ca0, cb0, r0, g0, b0);
				Convert3_ReadRGB(rgb2 + 8, rgb2 + 12, ca1, cb1, r1, g1, b1);
				rgb2 += 16;
				Convert3_CalcY(r0, g0, b0, y0);
				Convert3_CalcY(r1, g1, b1, y1);
				Convert3_WriteY(yuv_y2, y0, y1);
				yuv_y2 += 16;
				_mm_prefetch(rgb2 + 16, _MM_HINT_T0);
				ra = _mm_add_epi16(ra, _mm_hadd_epi32(r0, r1));
				ga = _mm_add_epi16(ga, _mm_hadd_epi32(g0, g1));
				ba = _mm_add_epi16(ba, _mm_hadd_epi32(b0, b1));
			}
			{
				ra = _mm_srli_epi16(_mm_add_epi16(ra, v_2), 2);
				ga = _mm_srli_epi16(_mm_add_epi16(ga, v_2), 2);
				ba = _mm_srli_epi16(_mm_add_epi16(ba, v_2), 2);
				__m128i u = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(ra, v_mat_ur), _mm_mullo_epi16(ga, v_mat_ug)), _mm_add_epi16(_mm_mullo_epi16(ba, v_mat_ub_vr), v_offset_uv));
				_mm_storel_epi64((__m128i*) yuv_u, _mm_shuffle_epi8(u, v_shuffle3));
				yuv_u += 8;
				__m128i v = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(ra, v_mat_ub_vr), _mm_mullo_epi16(ga, v_mat_vg)), _mm_add_epi16(_mm_mullo_epi16(ba, v_mat_vb), v_offset_uv));
				_mm_storel_epi64((__m128i*) yuv_v, _mm_shuffle_epi8(v, v_shuffle3));
				yuv_v += 8;
			}
		}
		for(unsigned int i = 0; i < (w & 15) / 2; ++i) {
			uint32_t c[4] = {rgb1[0], rgb1[1], rgb2[0], rgb2[1]};
			rgb1 += 2; rgb2 += 2;
			int r[4] = {(int) ((c[0] >> 16) & 0xff), (int) ((c[1] >> 16) & 0xff), (int) ((c[2] >> 16) & 0xff), (int) ((c[3] >> 16) & 0xff)};
			int g[4] = {(int) ((c[0] >>  8) & 0xff), (int) ((c[1] >>  8) & 0xff), (int) ((c[2] >>  8) & 0xff), (int) ((c[3] >>  8) & 0xff)};
			int b[4] = {(int) ((c[0]      ) & 0xff), (int) ((c[1]      ) & 0xff), (int) ((c[2]      ) & 0xff), (int) ((c[3]      ) & 0xff)};
			yuv_y1[0] = (66 * r[0] + 129 * g[0] + 25 * b[0] + offset_y) >> 8;
			yuv_y1[1] = (66 * r[1] + 129 * g[1] + 25 * b[1] + offset_y) >> 8;
			yuv_y2[0] = (66 * r[2] + 129 * g[2] + 25 * b[2] + offset_y) >> 8;
			yuv_y2[1] = (66 * r[3] + 129 * g[3] + 25 * b[3] + offset_y) >> 8;
			yuv_y1 += 2; yuv_y2 += 2;
			int sr = r[0] + r[1] + r[2] + r[3];
			int sg = g[0] + g[1] + g[2] + g[3];
			int sb = b[0] + b[1] + b[2] + b[3];
			*yuv_u = (-38 * sr + -74 * sg + 112 * sb + offset_uv) >> 10;
			*yuv_v = (112 * sr + -94 * sg + -18 * sb + offset_uv) >> 10;
			++yuv_u; ++yuv_v;
		}
	}

	_mm_sfence();

}

#endif
