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

#include "FastScaler_Scale_Generic.h"

#include "TempBuffer.h"

void Scale_BGRA_Generic(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride,
						MipMapFunction mipmap_function, BilinearFunction bilinear_function) {

	// no scaling?
	if(in_w == out_w && in_h == out_h) {
		if(in_stride == out_stride) {
			memcpy(out_data, in_data, in_stride * in_h);
		} else {
			for(unsigned int out_j = 0; out_j < out_h; ++out_j) {
				memcpy(out_data, in_data, in_w * 4);
				in_data += in_stride;
				out_data += out_stride;
			}
		}
		return;
	}

	// calculate mipmap factors
	unsigned int mx = 0, my = 0;
	while((out_w << (mx + 1)) <= in_w) ++mx;
	while((out_h << (my + 1)) <= in_h) ++my;
	if(mx + my > 8) {
		if(mx <= 4)
			my = 8 - mx;
		else if(my <= 4)
			mx = 8 - my;
		else
			mx = my = 4;
	}

	// pure mipmap scaling?
	if((out_w << mx) == in_w && (out_h << my) == in_h) {
		mipmap_function(in_w, in_h, in_data, in_stride, out_data, out_stride, mx, my);
		return;
	}

	// create mipmap
	TempBuffer<uint8_t> mipmap;
	if(mx != 0 || my != 0) {
		unsigned int mipmap_w = ((in_w - 1) >> mx) + 1, mipmap_h = ((in_h - 1) >> my) + 1;
		int mipmap_stride = grow_align16(mipmap_w * 4);
		mipmap.Alloc(mipmap_stride * mipmap_h);
		mipmap_function(in_w, in_h, in_data, in_stride, mipmap.GetData(), mipmap_stride, mx, my);
		in_data = mipmap.GetData();
		in_stride = mipmap_stride;
	}

	bilinear_function(in_w, in_h, in_data, in_stride, out_w, out_h, out_data, out_stride, mx, my);

}

