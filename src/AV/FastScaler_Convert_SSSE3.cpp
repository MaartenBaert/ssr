/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

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

#include "FastScaler_Convert.h"

#if SSR_USE_X86_ASM

#include <xmmintrin.h> // sse
#include <emmintrin.h> // sse2
#include <pmmintrin.h> // sse3
#include <tmmintrin.h> // ssse3

/*
==== SSSE3 BGRA-to-YUV444/YUV420 Converter ====

Uses the same principle as the fallback converter, but uses 16-bit integers so it can do 8 operations at once.
- YUV444: takes blocks of 16x1 pixels, produces 16x1 Y/U/V values
- YUV422: takes blocks of 16x1 pixels, produces 16x1 Y and 8x1 U/V values
- YUV420: takes blocks of 16x2 pixels, produces 16x2 Y and 8x1 U/V values

The code uses interleaving to reduce the number of shuffles. So for example the order for red is [ r0 r4 r1 r5 r2 r6 r3 r7 ].
For the averaging of 2x2 blocks, it uses 32-bit horizontal addition instead of 16-bit because of this interleaving.
The order of the final result is [ sr0 sr2 sr1 sr3 sr4 sr6 sr5 sr7 ].

If the width is not a multiple of 8/16, the remainder (right edge of the image) is converted without SSSE3.

This converter is about 4 times faster than the fallback converter.
*/

#define ReadBGRAInterleaved(ptr1, ptr2, ca, cb, r, g, b) \
	__m128i ca = _mm_loadu_si128((__m128i*) (ptr1)), cb = _mm_loadu_si128((__m128i*) (ptr2)); \
	__m128i r = _mm_or_si128(_mm_and_si128(_mm_srli_si128(ca, 2), v_byte1), _mm_and_si128(               cb    , v_byte3)); \
	__m128i g = _mm_or_si128(_mm_and_si128(_mm_srli_si128(ca, 1), v_byte1), _mm_and_si128(_mm_slli_si128(cb, 1), v_byte3)); \
	__m128i b = _mm_or_si128(_mm_and_si128(               ca    , v_byte1), _mm_and_si128(_mm_slli_si128(cb, 2), v_byte3));
#define Convert_RGB_Y(r, g, b, y) \
	__m128i y = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(r, v_mat_yr), _mm_mullo_epi16(g, v_mat_yg)), _mm_add_epi16(_mm_mullo_epi16(b, v_mat_yb), v_offset_y));
#define Convert_RGB_U(r, g, b, u) \
	__m128i u = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(r, v_mat_ur), _mm_mullo_epi16(g, v_mat_ug)), _mm_add_epi16(_mm_mullo_epi16(b, v_mat_ub_vr), v_offset_uv));
#define Convert_RGB_V(r, g, b, v) \
	__m128i v = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(r, v_mat_ub_vr), _mm_mullo_epi16(g, v_mat_vg)), _mm_add_epi16(_mm_mullo_epi16(b, v_mat_vb), v_offset_uv));
#define WritePlaneInterleaved(ptr, y1, y2, sh1, sh2) \
	_mm_stream_si128((__m128i*) (ptr), _mm_or_si128(_mm_shuffle_epi8(y1, sh1), _mm_shuffle_epi8(y2, sh2)));

void Convert_BGRA_YUV444_SSSE3(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	assert((uintptr_t) out_data[0] % 16 == 0 && out_stride[0] % 16 == 0);
	assert((uintptr_t) out_data[1] % 16 == 0 && out_stride[1] % 16 == 0);
	assert((uintptr_t) out_data[2] % 16 == 0 && out_stride[2] % 16 == 0);

	__m128i v_byte1     = _mm_set1_epi32(0x000000ff);
	__m128i v_byte3     = _mm_set1_epi32(0x00ff0000);
	__m128i v_mat_yr    = _mm_set1_epi16(47);
	__m128i v_mat_yg    = _mm_set1_epi16(157);
	__m128i v_mat_yb    = _mm_set1_epi16(16);
	__m128i v_mat_ur    = _mm_set1_epi16(-26);
	__m128i v_mat_ug    = _mm_set1_epi16(-86);
	__m128i v_mat_ub_vr = _mm_set1_epi16(112);
	__m128i v_mat_vg    = _mm_set1_epi16(-102);
	__m128i v_mat_vb    = _mm_set1_epi16(-10);
	__m128i v_offset_y  = _mm_set1_epi16((int16_t) (128 + (16 << 8)));
	__m128i v_offset_uv = _mm_set1_epi16((int16_t) (128 + (128 << 8)));
	__m128i v_shuffle1  = _mm_setr_epi8(1, 5, 9, 13, 3, 7, 11, 15, -1, -1, -1, -1, -1, -1, -1, -1);
	__m128i v_shuffle2  = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 1, 5, 9, 13, 3, 7, 11, 15);

	const int offset_y = 128 + (16 << 8), offset_uv = 128 + (128 << 8);

	for(unsigned int j = 0; j < h; ++j) {
		const uint32_t *rgb = (const uint32_t*) (in_data + in_stride * (int) j);
		uint8_t *yuv_y = out_data[0] + out_stride[0] * (int) j;
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 16; ++i) {
			ReadBGRAInterleaved(rgb    , rgb +  4, ca1, cb1, r1, g1, b1);
			ReadBGRAInterleaved(rgb + 8, rgb + 12, ca2, cb2, r2, g2, b2);
			_mm_prefetch(rgb + 48, _MM_HINT_T0);
			rgb += 16;
			Convert_RGB_Y(r1, g1, b1, y1);
			Convert_RGB_Y(r2, g2, b2, y2);
			WritePlaneInterleaved(yuv_y, y1, y2, v_shuffle1, v_shuffle2);
			yuv_y += 16;
			Convert_RGB_U(r1, g1, b1, u1);
			Convert_RGB_U(r2, g2, b2, u2);
			WritePlaneInterleaved(yuv_u, u1, u2, v_shuffle1, v_shuffle2);
			yuv_u += 16;
			Convert_RGB_V(r1, g1, b1, v1);
			Convert_RGB_V(r2, g2, b2, v2);
			WritePlaneInterleaved(yuv_v, v1, v2, v_shuffle1, v_shuffle2);
			yuv_v += 16;
		}
		for(unsigned int i = 0; i < (w & 15); ++i) {
			uint32_t c = *(rgb++);
			int r = (int) ((c >> 16) & 0xff);
			int g = (int) ((c >>  8) & 0xff);
			int b = (int) ((c      ) & 0xff);
			*(yuv_y++) = ( 47 * r +  157 * g +  16 * b + offset_y) >> 8;
			*(yuv_u++) = (-26 * r +  -86 * g + 112 * b + offset_uv) >> 8;
			*(yuv_v++) = (112 * r + -102 * g + -10 * b + offset_uv) >> 8;
		}
	}

	_mm_sfence();

}

void Convert_BGRA_YUV422_SSSE3(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	assert(w % 2 == 0);
	assert((uintptr_t) out_data[0] % 16 == 0 && out_stride[0] % 16 == 0);
	assert((uintptr_t) out_data[1] % 16 == 0 && out_stride[1] % 16 == 0);
	assert((uintptr_t) out_data[2] % 16 == 0 && out_stride[2] % 16 == 0);

	__m128i v_byte1     = _mm_set1_epi32(0x000000ff);
	__m128i v_byte3     = _mm_set1_epi32(0x00ff0000);
	__m128i v_mat_yr    = _mm_set1_epi16(47);
	__m128i v_mat_yg    = _mm_set1_epi16(157);
	__m128i v_mat_yb    = _mm_set1_epi16(16);
	__m128i v_mat_ur    = _mm_set1_epi16(-26);
	__m128i v_mat_ug    = _mm_set1_epi16(-86);
	__m128i v_mat_ub_vr = _mm_set1_epi16(112);
	__m128i v_mat_vg    = _mm_set1_epi16(-102);
	__m128i v_mat_vb    = _mm_set1_epi16(-10);
	__m128i v_offset_y  = _mm_set1_epi16((int16_t) (128 + (16 << 8)));
	__m128i v_offset_uv = _mm_set1_epi16((int16_t) (128 + (128 << 8)));
	__m128i v_shuffle1  = _mm_setr_epi8(1, 5, 9, 13, 3, 7, 11, 15, -1, -1, -1, -1, -1, -1, -1, -1);
	__m128i v_shuffle2  = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 1, 5, 9, 13, 3, 7, 11, 15);
	__m128i v_shuffle3  = _mm_setr_epi8(1, 5, 3, 7, 9, 13, 11, 15, -1, -1, -1, -1, -1, -1, -1, -1);

	const int offset_y = 128 + (16 << 8), offset_uv = (128 + (128 << 8)) << 1;

	for(unsigned int j = 0; j < h; ++j) {
		const uint32_t *rgb = (const uint32_t*) (in_data + in_stride * (int) j);
		uint8_t *yuv_y = out_data[0] + out_stride[0] * (int) j;
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 16; ++i) {
			ReadBGRAInterleaved(rgb    , rgb +  4, ca1, cb1, r1, g1, b1);
			ReadBGRAInterleaved(rgb + 8, rgb + 12, ca2, cb2, r2, g2, b2);
			_mm_prefetch(rgb + 48, _MM_HINT_T0);
			rgb += 16;
			Convert_RGB_Y(r1, g1, b1, y1);
			Convert_RGB_Y(r2, g2, b2, y2);
			WritePlaneInterleaved(yuv_y, y1, y2, v_shuffle1, v_shuffle2);
			yuv_y += 16;
			__m128i ra = _mm_srli_epi16(_mm_hadd_epi32(r1, r2), 1);
			__m128i ga = _mm_srli_epi16(_mm_hadd_epi32(g1, g2), 1);
			__m128i ba = _mm_srli_epi16(_mm_hadd_epi32(b1, b2), 1);
			__m128i u = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(ra, v_mat_ur), _mm_mullo_epi16(ga, v_mat_ug)), _mm_add_epi16(_mm_mullo_epi16(ba, v_mat_ub_vr), v_offset_uv));
			_mm_storel_epi64((__m128i*) yuv_u, _mm_shuffle_epi8(u, v_shuffle3));
			yuv_u += 8;
			__m128i v = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(ra, v_mat_ub_vr), _mm_mullo_epi16(ga, v_mat_vg)), _mm_add_epi16(_mm_mullo_epi16(ba, v_mat_vb), v_offset_uv));
			_mm_storel_epi64((__m128i*) yuv_v, _mm_shuffle_epi8(v, v_shuffle3));
			yuv_v += 8;
		}
		for(unsigned int i = 0; i < (w & 15) / 2; ++i) {
			uint32_t c1 = rgb[0], c2 = rgb[1];
			rgb += 2;
			int r1 = (int) ((c1 >> 16) & 0xff), r2 = (int) ((c2 >> 16) & 0xff);
			int g1 = (int) ((c1 >>  8) & 0xff), g2 = (int) ((c2 >>  8) & 0xff);
			int b1 = (int) ((c1      ) & 0xff), b2 = (int) ((c2      ) & 0xff);
			yuv_y[0] = (47 * r1 + 157 * g1 + 16 * b1 + offset_y) >> 8;
			yuv_y[1] = (47 * r2 + 157 * g2 + 16 * b2 + offset_y) >> 8;
			yuv_y += 2;
			int sr = r1 + r2;
			int sg = g1 + g2;
			int sb = b1 + b2;
			*(yuv_u++) = (-26 * sr +  -86 * sg + 112 * sb + offset_uv) >> 9;
			*(yuv_v++) = (112 * sr + -102 * sg + -10 * sb + offset_uv) >> 9;
		}
	}

	_mm_sfence();

}

void Convert_BGRA_YUV420_SSSE3(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	assert(w % 2 == 0 && h % 2 == 0);
	assert((uintptr_t) out_data[0] % 16 == 0 && out_stride[0] % 16 == 0);
	assert((uintptr_t) out_data[1] % 16 == 0 && out_stride[1] % 16 == 0);
	assert((uintptr_t) out_data[2] % 16 == 0 && out_stride[2] % 16 == 0);

	__m128i v_byte1     = _mm_set1_epi32(0x000000ff);
	__m128i v_byte3     = _mm_set1_epi32(0x00ff0000);
	__m128i v_mat_yr    = _mm_set1_epi16(47);
	__m128i v_mat_yg    = _mm_set1_epi16(157);
	__m128i v_mat_yb    = _mm_set1_epi16(16);
	__m128i v_mat_ur    = _mm_set1_epi16(-26);
	__m128i v_mat_ug    = _mm_set1_epi16(-86);
	__m128i v_mat_ub_vr = _mm_set1_epi16(112);
	__m128i v_mat_vg    = _mm_set1_epi16(-102);
	__m128i v_mat_vb    = _mm_set1_epi16(-10);
	__m128i v_offset_y  = _mm_set1_epi16((int16_t) (128 + (16 << 8)));
	__m128i v_offset_uv = _mm_set1_epi16((int16_t) (128 + (128 << 8)));
	__m128i v_2         = _mm_set1_epi16(2);
	__m128i v_shuffle1  = _mm_setr_epi8(1, 5, 9, 13, 3, 7, 11, 15, -1, -1, -1, -1, -1, -1, -1, -1);
	__m128i v_shuffle2  = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 1, 5, 9, 13, 3, 7, 11, 15);
	__m128i v_shuffle3  = _mm_setr_epi8(1, 5, 3, 7, 9, 13, 11, 15, -1, -1, -1, -1, -1, -1, -1, -1);

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
				ReadBGRAInterleaved(rgb1    , rgb1 +  4, ca1, cb1, r1, g1, b1);
				ReadBGRAInterleaved(rgb1 + 8, rgb1 + 12, ca2, cb2, r2, g2, b2);
				rgb1 += 16;
				Convert_RGB_Y(r1, g1, b1, y1);
				Convert_RGB_Y(r2, g2, b2, y2);
				WritePlaneInterleaved(yuv_y1, y1, y2, v_shuffle1, v_shuffle2);
				yuv_y1 += 16;
				_mm_prefetch(rgb1 + 16, _MM_HINT_T0);
				ra = _mm_hadd_epi32(r1, r2);
				ga = _mm_hadd_epi32(g1, g2);
				ba = _mm_hadd_epi32(b1, b2);
			}
			{
				ReadBGRAInterleaved(rgb2    , rgb2 +  4, ca1, cb1, r1, g1, b1);
				ReadBGRAInterleaved(rgb2 + 8, rgb2 + 12, ca2, cb2, r2, g2, b2);
				rgb2 += 16;
				Convert_RGB_Y(r1, g1, b1, y1);
				Convert_RGB_Y(r2, g2, b2, y2);
				WritePlaneInterleaved(yuv_y2, y1, y2, v_shuffle1, v_shuffle2);
				yuv_y2 += 16;
				_mm_prefetch(rgb2 + 16, _MM_HINT_T0);
				ra = _mm_add_epi16(ra, _mm_hadd_epi32(r1, r2));
				ga = _mm_add_epi16(ga, _mm_hadd_epi32(g1, g2));
				ba = _mm_add_epi16(ba, _mm_hadd_epi32(b1, b2));
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
			uint32_t c1 = rgb1[0], c2 = rgb1[1], c3 = rgb2[0], c4 = rgb2[1];
			rgb1 += 2; rgb2 += 2;
			int r1 = (int) ((c1 >> 16) & 0xff), r2 = (int) ((c2 >> 16) & 0xff), r3 = (int) ((c3 >> 16) & 0xff), r4 = (int) ((c4 >> 16) & 0xff);
			int g1 = (int) ((c1 >>  8) & 0xff), g2 = (int) ((c2 >>  8) & 0xff), g3 = (int) ((c3 >>  8) & 0xff), g4 = (int) ((c4 >>  8) & 0xff);
			int b1 = (int) ((c1      ) & 0xff), b2 = (int) ((c2      ) & 0xff), b3 = (int) ((c3      ) & 0xff), b4 = (int) ((c4      ) & 0xff);
			yuv_y1[0] = (47 * r1 + 157 * g1 + 16 * b1 + offset_y) >> 8;
			yuv_y1[1] = (47 * r2 + 157 * g2 + 16 * b2 + offset_y) >> 8;
			yuv_y2[0] = (47 * r3 + 157 * g3 + 16 * b3 + offset_y) >> 8;
			yuv_y2[1] = (47 * r4 + 157 * g4 + 16 * b4 + offset_y) >> 8;
			yuv_y1 += 2; yuv_y2 += 2;
			int sr = r1 + r2 + r3 + r4;
			int sg = g1 + g2 + g3 + g4;
			int sb = b1 + b2 + b3 + b4;
			*(yuv_u++) = (-26 * sr +  -86 * sg + 112 * sb + offset_uv) >> 10;
			*(yuv_v++) = (112 * sr + -102 * sg + -10 * sb + offset_uv) >> 10;
		}
	}

	_mm_sfence();

}

void Convert_BGRA_NV12_SSSE3(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[2], const int out_stride[2]) {
	assert(w % 2 == 0 && h % 2 == 0);
	assert((uintptr_t) out_data[0] % 16 == 0 && out_stride[0] % 16 == 0);
	assert((uintptr_t) out_data[1] % 16 == 0 && out_stride[1] % 16 == 0);

	__m128i v_byte1     = _mm_set1_epi32(0x000000ff);
	__m128i v_byte3     = _mm_set1_epi32(0x00ff0000);
	__m128i v_mat_yr    = _mm_set1_epi16(47);
	__m128i v_mat_yg    = _mm_set1_epi16(157);
	__m128i v_mat_yb    = _mm_set1_epi16(16);
	__m128i v_mat_ur    = _mm_set1_epi16(-26);
	__m128i v_mat_ug    = _mm_set1_epi16(-86);
	__m128i v_mat_ub_vr = _mm_set1_epi16(112);
	__m128i v_mat_vg    = _mm_set1_epi16(-102);
	__m128i v_mat_vb    = _mm_set1_epi16(-10);
	__m128i v_offset_y  = _mm_set1_epi16((int16_t) (128 + (16 << 8)));
	__m128i v_offset_uv = _mm_set1_epi16((int16_t) (128 + (128 << 8)));
	__m128i v_2         = _mm_set1_epi16(2);
	__m128i v_shuffle1  = _mm_setr_epi8( 1,  5,  9, 13,  3,  7, 11, 15, -1, -1, -1, -1, -1, -1, -1, -1);
	__m128i v_shuffle2  = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1,  1,  5,  9, 13,  3,  7, 11, 15);
	__m128i v_shuffle3  = _mm_setr_epi8( 1, -1,  5, -1,  3, -1,  7, -1,  9, -1, 13, -1, 11, -1, 15, -1);
	__m128i v_shuffle4  = _mm_setr_epi8(-1,  1, -1,  5, -1,  3, -1,  7, -1,  9, -1, 13, -1, 11, -1, 15);

	const int offset_y = 128 + (16 << 8), offset_uv = (128 + (128 << 8)) << 2;

	for(unsigned int j = 0; j < h / 2; ++j) {
		const uint32_t *rgb1 = (const uint32_t*) (in_data + in_stride * (int) (j * 2));
		const uint32_t *rgb2 = (const uint32_t*) (in_data + in_stride * (int) (j * 2 + 1));
		uint8_t *yuv_y1 = out_data[0] + out_stride[0] * (int) (j * 2);
		uint8_t *yuv_y2 = out_data[0] + out_stride[0] * (int) (j * 2 + 1);
		uint8_t *yuv_uv = out_data[1] + out_stride[1] * (int) j;
		for(unsigned int i = 0; i < w / 16; ++i) {
			__m128i ra, ga, ba;
			{
				ReadBGRAInterleaved(rgb1    , rgb1 +  4, ca1, cb1, r1, g1, b1);
				ReadBGRAInterleaved(rgb1 + 8, rgb1 + 12, ca2, cb2, r2, g2, b2);
				rgb1 += 16;
				Convert_RGB_Y(r1, g1, b1, y1);
				Convert_RGB_Y(r2, g2, b2, y2);
				WritePlaneInterleaved(yuv_y1, y1, y2, v_shuffle1, v_shuffle2);
				yuv_y1 += 16;
				_mm_prefetch(rgb1 + 16, _MM_HINT_T0);
				ra = _mm_hadd_epi32(r1, r2);
				ga = _mm_hadd_epi32(g1, g2);
				ba = _mm_hadd_epi32(b1, b2);
			}
			{
				ReadBGRAInterleaved(rgb2    , rgb2 +  4, ca1, cb1, r1, g1, b1);
				ReadBGRAInterleaved(rgb2 + 8, rgb2 + 12, ca2, cb2, r2, g2, b2);
				rgb2 += 16;
				Convert_RGB_Y(r1, g1, b1, y1);
				Convert_RGB_Y(r2, g2, b2, y2);
				WritePlaneInterleaved(yuv_y2, y1, y2, v_shuffle1, v_shuffle2);
				yuv_y2 += 16;
				_mm_prefetch(rgb2 + 16, _MM_HINT_T0);
				ra = _mm_add_epi16(ra, _mm_hadd_epi32(r1, r2));
				ga = _mm_add_epi16(ga, _mm_hadd_epi32(g1, g2));
				ba = _mm_add_epi16(ba, _mm_hadd_epi32(b1, b2));
			}
			{
				ra = _mm_srli_epi16(_mm_add_epi16(ra, v_2), 2);
				ga = _mm_srli_epi16(_mm_add_epi16(ga, v_2), 2);
				ba = _mm_srli_epi16(_mm_add_epi16(ba, v_2), 2);
				__m128i u = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(ra, v_mat_ur), _mm_mullo_epi16(ga, v_mat_ug)), _mm_add_epi16(_mm_mullo_epi16(ba, v_mat_ub_vr), v_offset_uv));
				__m128i v = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(ra, v_mat_ub_vr), _mm_mullo_epi16(ga, v_mat_vg)), _mm_add_epi16(_mm_mullo_epi16(ba, v_mat_vb), v_offset_uv));
				WritePlaneInterleaved(yuv_uv, u, v, v_shuffle3, v_shuffle4);
				yuv_uv += 16;
			}
		}
		for(unsigned int i = 0; i < (w & 15) / 2; ++i) {
			uint32_t c1 = rgb1[0], c2 = rgb1[1], c3 = rgb2[0], c4 = rgb2[1];
			rgb1 += 2; rgb2 += 2;
			int r1 = (int) ((c1 >> 16) & 0xff), r2 = (int) ((c2 >> 16) & 0xff), r3 = (int) ((c3 >> 16) & 0xff), r4 = (int) ((c4 >> 16) & 0xff);
			int g1 = (int) ((c1 >>  8) & 0xff), g2 = (int) ((c2 >>  8) & 0xff), g3 = (int) ((c3 >>  8) & 0xff), g4 = (int) ((c4 >>  8) & 0xff);
			int b1 = (int) ((c1      ) & 0xff), b2 = (int) ((c2      ) & 0xff), b3 = (int) ((c3      ) & 0xff), b4 = (int) ((c4      ) & 0xff);
			yuv_y1[0] = (47 * r1 + 157 * g1 + 16 * b1 + offset_y) >> 8;
			yuv_y1[1] = (47 * r2 + 157 * g2 + 16 * b2 + offset_y) >> 8;
			yuv_y2[0] = (47 * r3 + 157 * g3 + 16 * b3 + offset_y) >> 8;
			yuv_y2[1] = (47 * r4 + 157 * g4 + 16 * b4 + offset_y) >> 8;
			yuv_y1 += 2; yuv_y2 += 2;
			int sr = r1 + r2 + r3 + r4;
			int sg = g1 + g2 + g3 + g4;
			int sb = b1 + b2 + b3 + b4;
			yuv_uv[0] = (-26 * sr +  -86 * sg + 112 * sb + offset_uv) >> 10;
			yuv_uv[1] = (112 * sr + -102 * sg + -10 * sb + offset_uv) >> 10;
			yuv_uv += 2;
		}
	}

	_mm_sfence();

}

/*
==== SSSE3 BGRA-to-BGR Converter ====

Same as the fallback converter, but with a larger block size and shuffles instead of shifts and bitwise or.
- BGR: converts blocks of 16x1 pixels
*/

void Convert_BGRA_BGR_SSSE3(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* out_data, int out_stride) {
	assert((uintptr_t) out_data % 16 == 0 && out_stride % 16 == 0);

	__m128i v_shuffle1  = _mm_setr_epi8( 0,  1,  2,  4,  5,  6,  8,  9, 10, 12, 13, 14, -1, -1, -1, -1);
	__m128i v_shuffle2  = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0,  1,  2,  4);
	__m128i v_shuffle3  = _mm_setr_epi8( 5,  6,  8,  9, 10, 12, 13, 14, -1, -1, -1, -1, -1, -1, -1, -1);
	__m128i v_shuffle4  = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1,  0,  1,  2,  4,  5,  6,  8,  9);
	__m128i v_shuffle5  = _mm_setr_epi8(10, 12, 13, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
	__m128i v_shuffle6  = _mm_setr_epi8(-1, -1, -1, -1,  0,  1,  2,  4,  5,  6,  8,  9, 10, 12, 13, 14);

	for(unsigned int j = 0; j < h; ++j) {
		const uint8_t *in = in_data + in_stride * (int) j;
		uint8_t *out = out_data + out_stride * (int) j;
		for(unsigned int i = 0; i < w / 16; ++i) {
			__m128i c0 = _mm_loadu_si128((__m128i*) (in     ));
			__m128i c1 = _mm_loadu_si128((__m128i*) (in + 16));
			__m128i c2 = _mm_loadu_si128((__m128i*) (in + 32));
			__m128i c3 = _mm_loadu_si128((__m128i*) (in + 48));
			//_mm_prefetch(in + 192, _MM_HINT_T0);
			in += 64;
			_mm_stream_si128((__m128i*) (out     ), _mm_or_si128(_mm_shuffle_epi8(c0, v_shuffle1), _mm_shuffle_epi8(c1, v_shuffle2)));
			_mm_stream_si128((__m128i*) (out + 16), _mm_or_si128(_mm_shuffle_epi8(c1, v_shuffle3), _mm_shuffle_epi8(c2, v_shuffle4)));
			_mm_stream_si128((__m128i*) (out + 32), _mm_or_si128(_mm_shuffle_epi8(c2, v_shuffle5), _mm_shuffle_epi8(c3, v_shuffle6)));
			out += 48;
		}
		for(unsigned int i = 0; i < (w & 15); ++i) {
			uint32_t c = *((uint32_t*) in);
			in += 4;
			out[0] = c;
			out[1] = c >> 8;
			out[2] = c >> 16;
			out += 3;
		}
	}

	_mm_sfence();

}

#endif
