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
#include "YUVConverter.h"

#include "Logger.h"

/* In GCC 4.8 this should work:
__builtin_cpu_init();
m_use_sse = __builtin_cpu_supports("sse2") && __builtin_cpu_supports("ssse3");
... but for now I have to use CPUID manually. The detection code is based on:
http://softpixel.com/~cwright/programming/simd/cpuid.php
http://software.intel.com/en-us/forums/topic/305798
*/

#if SSR_USE_X86_ASM
#define CPUID(func,ax,bx,cx,dx) {\
	__asm__ __volatile__ ("cpuid" : "=a" (ax), "=b" (bx), "=c" (cx), "=d" (dx) : "a" (func));\
}
#define MMX_FLAG    0x00800000  // from edx
#define SSE_FLAG    0x02000000  // from edx
#define SSE2_FLAG   0x04000000  // from edx
#define SSE3_FLAG   0x00000001  // from ecx
#define SSSE3_FLAG  0x00000200  // from ecx
#define SSE4_FLAG   0x00080000  // from ecx
#define SSE42_FLAG  0x00100000  // from ecx
#endif

static void Convert_Fallback(unsigned int w, unsigned int h, uint8_t* in_data, int in_stride, uint8_t* out_data[3], int out_stride[3]);

#if SSR_USE_X86_ASM
static void Convert_SSSE3(unsigned int w, unsigned int h, uint8_t* in_data, int in_stride, uint8_t* out_data[3], int out_stride[3]) __attribute__((__target__("sse2,ssse3")));
#endif

YUVConverter::YUVConverter() {
#if SSR_USE_X86_ASM
	{
		unsigned int a, b, c, d;
		CPUID(1, a, b, c, d);
		m_use_sse = ((d & SSE2_FLAG) != 0 && (c & SSSE3_FLAG) != 0);
	}
	if(m_use_sse)
		Logger::LogInfo("[YUVConverter::YUVConverter] Using SSSE3 converter.");
	else
		Logger::LogInfo("[YUVConverter::YUVConverter] No SSSE3, using fallback converter.");
	m_warn_alignment = true;
#else
	Logger::LogInfo("[YUVConverter::YUVConverter] Using fallback converter.");
#endif
}

void YUVConverter::Convert(unsigned int w, unsigned int h, uint8_t* in_data, int in_stride, uint8_t* out_data[3], int out_stride[3]) {
	Q_ASSERT(w % 2 == 0 && h % 2 == 0);
#if SSR_USE_X86_ASM
	if(m_use_sse) {
		if((uintptr_t)(in_data) % 16 == 0 && in_stride % 16 == 0 &&
		   (uintptr_t)(out_data[0]) % 16 == 0 && out_stride[0] % 16 == 0 &&
		   (uintptr_t)(out_data[1]) % 16 == 0 && out_stride[1] % 16 == 0 &&
		   (uintptr_t)(out_data[2]) % 16 == 0 && out_stride[2] % 16 == 0) {
			unsigned int w16 = (w / 16) * 16;
			Convert_SSSE3(w16, h, in_data, in_stride, out_data, out_stride);
			if(w != w16) {
				uint8_t* out_data_b[3] = {out_data[0] + w16, out_data[1] + w16 / 2, out_data[2] + w16 / 2};
				Convert_Fallback(w - w16, h, in_data + 4 * w16, in_stride, out_data_b, out_stride);
			}
		} else {
			if(m_warn_alignment) {
				m_warn_alignment = false;
				Logger::LogWarning("[YUVConverter::Convert] Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem but performance will be worse.");
			}
			Convert_Fallback(w, h, in_data, in_stride, out_data, out_stride);
		}
	} else {
		Convert_Fallback(w, h, in_data, in_stride, out_data, out_stride);
	}
#else
	Convert_Fallback(w, h, in_data, in_stride, out_data, out_stride);
#endif
}

static void Convert_Fallback(unsigned int w, unsigned int h, uint8_t* in_data, int in_stride, uint8_t* out_data[3], int out_stride[3]) {
	Q_ASSERT(w % 2 == 0 && h % 2 == 0);

	int y_offset = 128 + (16 << 8), u_offset = 512 + (128 << 10), v_offset = 512 + (128 << 10);

	for(unsigned int j = 0; j < h / 2; ++j) {
		uint32_t *rgb1 = (uint32_t*)(in_data + in_stride * (int) j * 2);
		uint32_t *rgb2 = (uint32_t*)(in_data + in_stride * ((int) j * 2 + 1));
		uint8_t *yuv_y1 = out_data[0] + out_stride[0] * (int) j * 2;
		uint8_t *yuv_y2 = out_data[0] + out_stride[0] * ((int) j * 2 + 1);
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 2; ++i) {
			uint32_t c[4] = {rgb1[0], rgb1[1], rgb2[0], rgb2[1]};
			int r[4] = {(int) ((c[0] >> 16) & 0xff), (int) ((c[1] >> 16) & 0xff), (int) ((c[2] >> 16) & 0xff), (int) ((c[3] >> 16) & 0xff)};
			int g[4] = {(int) ((c[0] >>  8) & 0xff), (int) ((c[1] >>  8) & 0xff), (int) ((c[2] >>  8) & 0xff), (int) ((c[3] >>  8) & 0xff)};
			int b[4] = {(int) ((c[0]      ) & 0xff), (int) ((c[1]      ) & 0xff), (int) ((c[2]      ) & 0xff), (int) ((c[3]      ) & 0xff)};
			yuv_y1[0] = (66 * r[0] + 129 * g[0] + 25 * b[0] + y_offset) >> 8;
			yuv_y1[1] = (66 * r[1] + 129 * g[1] + 25 * b[1] + y_offset) >> 8;
			yuv_y2[0] = (66 * r[2] + 129 * g[2] + 25 * b[2] + y_offset) >> 8;
			yuv_y2[1] = (66 * r[3] + 129 * g[3] + 25 * b[3] + y_offset) >> 8;
			int sr = r[0] + r[1] + r[2] + r[3];
			int sg = g[0] + g[1] + g[2] + g[3];
			int sb = b[0] + b[1] + b[2] + b[3];
			*yuv_u = (-38 * sr + -74 * sg + 112 * sb + u_offset) >> 10;
			*yuv_v = (112 * sr + -94 * sg + -18 * sb + v_offset) >> 10;
			rgb1 += 2; rgb2 += 2;
			yuv_y1 += 2; yuv_y2 += 2;
			++yuv_u; ++yuv_v;
		}
	}

}

#if SSR_USE_X86_ASM

/*
My SSE2/SSSE3-optimized BGRA-to-YUV converter: about 4 times faster than the fallback implementation on my CPU (first gen Intel Core i5),
and 8 times faster than swscale.

This code is GCC-only, unfortunately. I don't know much about assembly, so I'm using GCC's build-in functions and vector extensions:
http://gcc.gnu.org/onlinedocs/gcc/X86-Built_002din-Functions.html
http://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html

To use this converter, the data for each row (both input and output) should be 16-byte aligned, the width should be a multiple
of 16 and the height should be a multiple of 2. Note that the convertor may write slightly past the end of the data block,
into the padding bytes.

This file should be compiled with the option -flax-vector-conversions.

The vector integer instructions are SSE2. The horizontal addition and byte-shuffle instructions are SSSE3.
The code uses interleaving to reduce the number of shuffles. So for example the order for red is [ r0 r4 r1 r5 r2 r6 r3 r7 ].
For the averaging of 2x2 blocks, I use 32-bit horizontal addition instead of 16-bit because of this interleaving.
The order of the final result is [ sr0 sr2 sr1 sr3 sr4 sr6 sr5 sr7 ].
*/

typedef uint32_t v4u32 __attribute__((vector_size(16)));
typedef int32_t  v4i32 __attribute__((vector_size(16)));
typedef uint16_t v8u16 __attribute__((vector_size(16)));
typedef int16_t  v8i16 __attribute__((vector_size(16)));
typedef uint8_t  v16u8 __attribute__((vector_size(16)));
typedef int8_t   v16i8 __attribute__((vector_size(16)));

#define vec2(x) {(x), (x)}
#define vec4(x) {(x), (x), (x), (x)}
#define vec8(x) {(x), (x), (x), (x), (x), (x), (x), (x)}
#define vecmem(v, p) (*((v*)(p)))

#define SSSE3_ReadRGB(ca, cb, r, g, b)\
	v8u16 r = (__builtin_ia32_psrldi128(ca, 16) & v_0xff) | (                         cb      & v_0xff0000);\
	v8u16 g = (__builtin_ia32_psrldi128(ca,  8) & v_0xff) | (__builtin_ia32_pslldi128(cb,  8) & v_0xff0000);\
	v8u16 b = (                         ca      & v_0xff) | (__builtin_ia32_pslldi128(cb, 16) & v_0xff0000);
#define SSSE3_CalcY(r, g, b, y)\
	v16u8 y = v_66 * r + v_129 * g + v_25 * b + y_offset;
#define SSSE3_WriteY(ptr, yl, yr)\
	vecmem(v16u8, ptr) = __builtin_ia32_pshufb128(yl, v_shuffle1) | __builtin_ia32_pshufb128(yr, v_shuffle2);

#define SSSE3_Convert(rgb1, rgb2, yuv_y1, yuv_y2, up, vp) {\
	\
	v4i32 c0a = vecmem(v4i32, (rgb1)), c0b = vecmem(v4i32, (rgb1) + 16);\
	SSSE3_ReadRGB(c0a, c0b, r0, g0, b0);\
	SSSE3_CalcY(r0, g0, b0, y0);\
	v4i32 c1a = vecmem(v4i32, (rgb1) + 32), c1b = vecmem(v4i32, (rgb1) + 48);\
	SSSE3_ReadRGB(c1a, c1b, r1, g1, b1);\
	SSSE3_CalcY(r1, g1, b1, y1);\
	SSSE3_WriteY((yuv_y1), y0, y1);\
	v8u16 r01 = (v8u16)(__builtin_ia32_phaddd128(r0, r1));\
	v8u16 g01 = (v8u16)(__builtin_ia32_phaddd128(g0, g1));\
	v8u16 b01 = (v8u16)(__builtin_ia32_phaddd128(b0, b1));\
	\
	v4i32 c2a = vecmem(v4i32, (rgb2)), c2b = vecmem(v4i32, (rgb2) + 16);\
	SSSE3_ReadRGB(c2a, c2b, r2, g2, b2);\
	SSSE3_CalcY(r2, g2, b2, y2);\
	v4i32 c3a = vecmem(v4i32, (rgb2) + 32), c3b = vecmem(v4i32, (rgb2) + 48);\
	SSSE3_ReadRGB(c3a, c3b, r3, g3, b3);\
	SSSE3_CalcY(r3, g3, b3, y3);\
	SSSE3_WriteY((yuv_y2), y2, y3);\
	v8u16 r23 = (v8u16)(__builtin_ia32_phaddd128(r2, r3));\
	v8u16 g23 = (v8u16)(__builtin_ia32_phaddd128(g2, g3));\
	v8u16 b23 = (v8u16)(__builtin_ia32_phaddd128(b2, b3));\
	\
	v8i16 sr = __builtin_ia32_psrlwi128(r01 + r23 + v_2, 2);\
	v8i16 sg = __builtin_ia32_psrlwi128(g01 + g23 + v_2, 2);\
	v8i16 sb = __builtin_ia32_psrlwi128(b01 + b23 + v_2, 2);\
	up = v_n38 * sr + v_n74 * sg + v_112 * sb + uv_offset;\
	vp = v_112 * sr + v_n94 * sg + v_n18 * sb + uv_offset;\
	\
}

static void Convert_SSSE3(unsigned int w, unsigned int h, uint8_t* in_data, int in_stride, uint8_t* out_data[3], int out_stride[3]) {
	Q_ASSERT(w % 16 == 0 && h % 2 == 0);
	Q_ASSERT((uintptr_t)(in_data) % 16 == 0 && in_stride % 16 == 0);
	Q_ASSERT((uintptr_t)(out_data[0]) % 16 == 0 && out_stride[0] % 16 == 0);
	Q_ASSERT((uintptr_t)(out_data[1]) % 16 == 0 && out_stride[1] % 16 == 0);
	Q_ASSERT((uintptr_t)(out_data[2]) % 16 == 0 && out_stride[2] % 16 == 0);

	v8u16 y_offset = vec8(128 + (16 << 8));
	v8i16 uv_offset = vec8((int16_t)(128 + (128 << 8))); // the value doesn't fit in int16_t but it works :)
	v4u32 v_0xff = vec4(0xff);
	v4u32 v_0xff0000 = vec4(0xff0000);
	v8u16 v_66 = vec8(66);
	v8u16 v_129 = vec8(129);
	v8u16 v_25 = vec8(25);
	v8u16 v_2 = vec8(2);
	v8i16 v_n38 = vec8(-38);
	v8i16 v_n74 = vec8(-74);
	v8i16 v_112 = vec8(112);
	v8i16 v_n94 = vec8(-94);
	v8i16 v_n18 = vec8(-18);
	v16u8 v_shuffle1 = {1, 5, 9, 13, 3, 7, 11, 15, 255, 255, 255, 255, 255, 255, 255, 255};
	v16u8 v_shuffle2 = {255, 255, 255, 255, 255, 255, 255, 255, 1, 5, 9, 13, 3, 7, 11, 15};
	v16u8 v_shuffle3 = {1, 5, 3, 7, 9, 13, 11, 15, 255, 255, 255, 255, 255, 255, 255, 255};
	v16u8 v_shuffle4 = {255, 255, 255, 255, 255, 255, 255, 255, 1, 5, 3, 7, 9, 13, 11, 15};

	for(unsigned int j = 0; j < h / 2; ++j) {
		uint8_t *rgb1 = in_data + in_stride * (int) j * 2;
		uint8_t *rgb2 = in_data + in_stride * ((int) j * 2 + 1);
		uint8_t *yuv_y1 = out_data[0] + out_stride[0] * (int) j * 2;
		uint8_t *yuv_y2 = out_data[0] + out_stride[0] * ((int) j * 2 + 1);
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 32; ++i) {
			v16u8 up1, vp1, up2, vp2;
			SSSE3_Convert(rgb1, rgb2, yuv_y1, yuv_y2, up1, vp1);
			SSSE3_Convert(rgb1 + 64, rgb2 + 64, yuv_y1 + 16, yuv_y2 + 16, up2, vp2);
			vecmem(v16u8, yuv_u) = __builtin_ia32_pshufb128(up1, v_shuffle3) | __builtin_ia32_pshufb128(up2, v_shuffle4);
			vecmem(v16u8, yuv_v) = __builtin_ia32_pshufb128(vp1, v_shuffle3) | __builtin_ia32_pshufb128(vp2, v_shuffle4);
			rgb1 += 128; rgb2 += 128;
			yuv_y1 += 32; yuv_y2 += 32;
			yuv_u += 16; yuv_v += 16;
		}
		if((w / 16) & 1) {
			v16u8 up1, vp1;
			SSSE3_Convert(rgb1, rgb2, yuv_y1, yuv_y2, up1, vp1);
			vecmem(v16u8, yuv_u) = __builtin_ia32_pshufb128(up1, v_shuffle3);
			vecmem(v16u8, yuv_v) = __builtin_ia32_pshufb128(vp1, v_shuffle3);
		}
	}

}

#endif
