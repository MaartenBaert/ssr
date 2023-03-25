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

#pragma once
#include "Global.h"

inline uint64_t vec4x16(uint16_t x) {
	return ((uint64_t) x << 48) | ((uint64_t) x << 32) | ((uint64_t) x << 16) | ((uint64_t) x);
}

inline void Bilinear_MapIndex(unsigned int out_i, unsigned int in_w, unsigned int out_w, unsigned int mipmap, unsigned int& offset, unsigned int& fraction) {
	uint64_t inter = (((uint64_t) out_i << 8) + 128) * (uint64_t) in_w;
	unsigned int div = out_w << mipmap;
	int64_t ii = (int64_t) ((inter + (uint64_t) (div >> 1)) / (uint64_t) div) - 128;
	int off = ii >> 8;
	int max_offset = (int) ((in_w - 1) >> mipmap) - 1;
	if(off < 0) {
		offset = 0;
		fraction = 0;
	} else if(off > max_offset) {
		offset = max_offset;
		fraction = 256;
	} else {
		offset = off;
		fraction = ii & 255;
	}
}

typedef void (*MipMapFunction)(unsigned int, unsigned int, const uint8_t*, int, uint8_t*, int, unsigned int, unsigned int);
typedef void (*BilinearFunction)(unsigned int, unsigned int, const uint8_t*, int, unsigned int, unsigned int, uint8_t*, int, unsigned int, unsigned int);

void Scale_BGRA_Generic(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride,
						MipMapFunction mipmap_function, BilinearFunction bilinear_function);
