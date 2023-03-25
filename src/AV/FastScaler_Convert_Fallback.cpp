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

/*
Color space standards are a mess.

==== BT.601 ====
Y =  16 + round((  66 * R +  129 * G +   25 * B) / 256)
U = 128 + round(( -38 * R +  -74 * G +  112 * B) / 256)
V = 128 + round(( 112 * R +  -94 * G +  -18 * B) / 256)

==== BT.709 ====
Y =  16 + round((  47 * R +  157 * G +   16 * B) / 256)
U = 128 + round(( -26 * R +  -86 * G +  112 * B) / 256)
V = 128 + round(( 112 * R + -102 * G +  -10 * B) / 256)

The converters below are currently hard-coded for BT.709.
*/

/*
==== Fallback BGRA-to-YUV444/YUV422/YUV420/NV12 Converter ====

Nothing special, just plain C code.
- YUV444: one-to-one mapping
- YUV422: takes blocks of 2x1 pixels, produces 2x1 Y and 1x1 U/V values
- YUV420: takes blocks of 2x2 pixels, produces 2x2 Y and 1x1 U/V values
- NV12: like YUV420, but U/V are in the same plane
*/

void Convert_BGRA_YUV444_Fallback(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	const int offset_y = 128 + (16 << 8), offset_uv = 128 + (128 << 8);
	for(unsigned int j = 0; j < h; ++j) {
		const uint32_t *rgb = (const uint32_t*) (in_data + in_stride * (int) j);
		uint8_t *yuv_y = out_data[0] + out_stride[0] * (int) j;
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w; ++i) {
			uint32_t c = *(rgb++);
			int r = (int) ((c >> 16) & 0xff);
			int g = (int) ((c >>  8) & 0xff);
			int b = (int) ((c      ) & 0xff);
			*(yuv_y++) = ( 47 * r +  157 * g +  16 * b + offset_y) >> 8;
			*(yuv_u++) = (-26 * r +  -86 * g + 112 * b + offset_uv) >> 8;
			*(yuv_v++) = (112 * r + -102 * g + -10 * b + offset_uv) >> 8;
		}
	}
}

void Convert_BGRA_YUV422_Fallback(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	assert(w % 2 == 0);
	const int offset_y = 128 + (16 << 8), offset_uv = (128 + (128 << 8)) << 1;
	for(unsigned int j = 0; j < h; ++j) {
		const uint32_t *rgb = (const uint32_t*) (in_data + in_stride * (int) j);
		uint8_t *yuv_y = out_data[0] + out_stride[0] * (int) j;
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 2; ++i) {
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
}

void Convert_BGRA_YUV420_Fallback(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]) {
	assert(w % 2 == 0 && h % 2 == 0);
	const int offset_y = 128 + (16 << 8), offset_uv = (128 + (128 << 8)) << 2;
	for(unsigned int j = 0; j < h / 2; ++j) {
		const uint32_t *rgb1 = (const uint32_t*) (in_data + in_stride * (int) j * 2);
		const uint32_t *rgb2 = (const uint32_t*) (in_data + in_stride * ((int) j * 2 + 1));
		uint8_t *yuv_y1 = out_data[0] + out_stride[0] * (int) j * 2;
		uint8_t *yuv_y2 = out_data[0] + out_stride[0] * ((int) j * 2 + 1);
		uint8_t *yuv_u = out_data[1] + out_stride[1] * (int) j;
		uint8_t *yuv_v = out_data[2] + out_stride[2] * (int) j;
		for(unsigned int i = 0; i < w / 2; ++i) {
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
}

void Convert_BGRA_NV12_Fallback(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const out_data[2], const int out_stride[2]) {
	assert(w % 2 == 0 && h % 2 == 0);
	const int offset_y = 128 + (16 << 8), offset_uv = (128 + (128 << 8)) << 2;
	for(unsigned int j = 0; j < h / 2; ++j) {
		const uint32_t *rgb1 = (const uint32_t*) (in_data + in_stride * (int) j * 2);
		const uint32_t *rgb2 = (const uint32_t*) (in_data + in_stride * ((int) j * 2 + 1));
		uint8_t *yuv_y1 = out_data[0] + out_stride[0] * (int) j * 2;
		uint8_t *yuv_y2 = out_data[0] + out_stride[0] * ((int) j * 2 + 1);
		uint8_t *yuv_uv = out_data[1] + out_stride[1] * (int) j;
		for(unsigned int i = 0; i < w / 2; ++i) {
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
}

/*
==== Fallback BGRA-to-BGR Converter ====

Nothing special, just plain C code.
- BGR: converts blocks of 8x1 pixels
*/

void Convert_BGRA_BGR_Fallback(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* out_data, int out_stride) {
	for(unsigned int j = 0; j < h; ++j) {
		const uint8_t *in = in_data + in_stride * (int) j;
		uint8_t *out = out_data + out_stride * (int) j;
		for(unsigned int i = 0; i < w / 8; ++i) {
			uint64_t c0 = ((uint64_t*) in)[0];
			uint64_t c1 = ((uint64_t*) in)[1];
			uint64_t c2 = ((uint64_t*) in)[2];
			uint64_t c3 = ((uint64_t*) in)[3];
			in += 32;
			((uint64_t*) out)[0] = ((c0 & UINT64_C(0x0000000000ffffff))      ) | ((c0 & UINT64_C(0x00ffffff00000000)) >>  8) | ((c1 & UINT64_C(0x000000000000ffff)) << 48);
			((uint64_t*) out)[1] = ((c1 & UINT64_C(0x0000000000ff0000)) >> 16) | ((c1 & UINT64_C(0x00ffffff00000000)) >> 24) | ((c2 & UINT64_C(0x0000000000ffffff)) << 32) | ((c2 & UINT64_C(0x000000ff00000000)) << 24);
			((uint64_t*) out)[2] = ((c2 & UINT64_C(0x00ffff0000000000)) >> 40) | ((c3 & UINT64_C(0x0000000000ffffff)) << 16) | ((c3 & UINT64_C(0x00ffffff00000000)) <<  8);
			out += 24;
		}
		for(unsigned int i = 0; i < (w & 7); ++i) {
			uint32_t c = *((uint32_t*) in);
			in += 4;
			out[0] = c;
			out[1] = c >> 8;
			out[2] = c >> 16;
			out += 3;
		}
	}
}
