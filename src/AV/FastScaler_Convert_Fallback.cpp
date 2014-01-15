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
