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

#include "FastScaler_Scale.h"

#include "FastScaler_Scale_Generic.h"
#include "TempBuffer.h"

/*
==== Fallback MipMapper ====

Uses 'wannabe-SIMD': 4x 16-bit values in normal 64-bit registers. This works as long as overflow is avoided.
Performs best on 64-bit systems, but even on 32-bit it should still be reasonably good.

It's important that this function is force-inlined because this allows the compiler to eliminate the inner loops for common mipmap factors.
*/

inline __attribute__((always_inline))
void MipMap_BGRA_Fallback_Dynamic(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
								  uint8_t* out_data, int out_stride, unsigned int mx, unsigned int my) {
	const uint64_t mask = vec4x16(0xff);
	const uint64_t offset = vec4x16(1u << (mx + my - 1));
	unsigned int wrem = in_w & ((1u << mx) - 1);
	unsigned int hrem = in_h & ((1u << my) - 1);
	for(unsigned int out_j = 0; out_j < (in_h >> my); ++out_j) {
		const uint32_t *in = (const uint32_t*) (in_data + in_stride * (int) (out_j << my));
		uint32_t *out = (uint32_t*) (out_data + out_stride * (int) out_j);
		for(unsigned int out_i = 0; out_i < (in_w >> mx); ++out_i) {
			uint64_t sum = 0;
			const uint32_t *in2 = in;
			for(unsigned int mj = 0; mj < (1u << my); ++mj) {
				for(unsigned int mi = 0; mi < (1u << mx); ++mi) {
					uint64_t c = in2[mi];
					sum += ((c << 24) | c) & mask;
				}
				in2 = (const uint32_t*) ((const uint8_t*) in2 + in_stride);
			}
			in += (1u << mx);
			uint64_t q = ((sum + offset) >> (mx + my)) & mask;
			*(out++) = ((uint32_t) (q >> 24)) | ((uint32_t) q);
		}
		if(wrem != 0) {
			uint64_t sum = 0;
			const uint32_t *in2 = in;
			for(unsigned int mj = 0; mj < (1u << my); ++mj) {
				for(unsigned int mi = 0; mi < wrem - 1; ++mi) {
					uint64_t c = in2[mi];
					sum += ((c << 24) | c) & mask;
				}
				uint64_t c = in2[wrem - 1];
				sum += (((c << 24) | c) & mask) * ((1u << mx) - (wrem - 1));
				in2 = (const uint32_t*) ((const uint8_t*) in2 + in_stride);
			}
			uint64_t q = ((sum + offset) >> (mx + my)) & mask;
			*out = ((uint32_t) (q >> 24)) | ((uint32_t) q);
		}
	}
	if(hrem != 0) {
		unsigned int out_j = in_h >> my;
		const uint32_t *in = (const uint32_t*) (in_data + in_stride * (int) (out_j << my));
		uint32_t *out = (uint32_t*) (out_data + out_stride * (int) out_j);
		for(unsigned int out_i = 0; out_i < (in_w >> mx); ++out_i) {
			uint64_t sum = 0;
			const uint32_t *in2 = in;
			for(unsigned int mj = 0; mj < hrem - 1; ++mj) {
				for(unsigned int mi = 0; mi < (1u << mx); ++mi) {
					uint64_t c = in2[mi];
					sum += ((c << 24) | c) & mask;
				}
				in2 = (const uint32_t*) ((const uint8_t*) in2 + in_stride);
			}
			for(unsigned int mi = 0; mi < (1u << mx); ++mi) {
				uint64_t c = in2[mi];
				sum += (((c << 24) | c) & mask) * ((1u << my) - (hrem - 1));
			}
			in += (1u << mx);
			uint64_t q = ((sum + offset) >> (mx + my)) & mask;
			*(out++) = ((uint32_t) (q >> 24)) | ((uint32_t) q);
		}
		if(wrem != 0) {
			uint64_t sum = 0;
			const uint32_t *in2 = in;
			for(unsigned int mj = 0; mj < hrem - 1; ++mj) {
				for(unsigned int mi = 0; mi < wrem - 1; ++mi) {
					uint64_t c = in2[mi];
					sum += ((c << 24) | c) & mask;
				}
				uint64_t c = in2[wrem - 1];
				sum += (((c << 24) | c) & mask) * ((1u << mx) - (wrem - 1));
				in2 = (const uint32_t*) ((const uint8_t*) in2 + in_stride);
			}
			for(unsigned int mi = 0; mi < wrem - 1; ++mi) {
				uint64_t c = in2[mi];
				sum += (((c << 24) | c) & mask) * ((1u << my) - (hrem - 1));
			}
			uint64_t c = in2[wrem - 1];
			sum += (((c << 24) | c) & mask) * ((1u << my) - (hrem - 1)) * ((1u << mx) - (wrem - 1));
			uint64_t q = ((sum + offset) >> (mx + my)) & mask;
			*out = ((uint32_t) (q >> 24)) | ((uint32_t) q);
		}
	}
}

void MipMap_BGRA_Fallback(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						  uint8_t* out_data, int out_stride, unsigned int mx, unsigned int my) {
	assert(mx + my <= 8);
	switch((mx << 4) | my) {
		case 0x00: assert(false); break;
		case 0x01: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 0, 1); break;
		case 0x02: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 0, 2); break;
		case 0x03: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 0, 3); break;
		case 0x10: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 0); break;
		case 0x11: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 1); break;
		case 0x12: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 2); break;
		case 0x13: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 3); break;
		case 0x20: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 0); break;
		case 0x21: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 1); break;
		case 0x22: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 2); break;
		case 0x23: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 3); break;
		case 0x30: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 0); break;
		case 0x31: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 1); break;
		case 0x32: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 2); break;
		case 0x33: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 3); break;
		default:   MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, mx, my); break;
	}
}

/*
==== Fallback Bilinear Scaler ====

Uses 'wannabe-SIMD' like the mipmapper. It's slightly less efficient here because of the multiplications, but still much faster than plain 32-bit integers.
*/

void Bilinear_BGRA_Fallback(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
							unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride,
							unsigned int mx, unsigned int my) {
	assert(in_w > 1 && in_h > 1); //TODO// support size 1?
	assert(out_w > 1 && out_h > 1); //TODO// support size 1?
	assert(in_w < (1 << 28) && in_h < (1 << 28));
	assert(out_w < (1 << 28) && out_h < (1 << 28));

	// precompute horizontal offsets and fractions
	TempBuffer<unsigned int> x_offset_table, x_fraction_table;
	x_offset_table.Alloc(out_w);
	x_fraction_table.Alloc(out_w);
	for(unsigned int out_i = 0; out_i < out_w; ++out_i) {
		Bilinear_MapIndex(out_i, in_w, out_w, mx, x_offset_table[out_i], x_fraction_table[out_i]);
	}

	const uint64_t mask = vec4x16(0xff);
	const uint64_t offset = vec4x16(128);

	// scale
	for(unsigned int out_j = 0; out_j < out_h; ++out_j) {
		unsigned int y_offset, y_fraction;
		Bilinear_MapIndex(out_j, in_h, out_h, my, y_offset, y_fraction);
		unsigned int y_fraction_inv = 256 - y_fraction;
		unsigned int *x_offset_ptr = x_offset_table.GetData(), *x_fraction_ptr = x_fraction_table.GetData();
		const uint32_t *in1 = (const uint32_t*) (in_data + in_stride * (int) y_offset);
		const uint32_t *in2 = (const uint32_t*) (in_data + in_stride * ((int) y_offset + 1));
		uint32_t *out = (uint32_t*) (out_data + out_stride * (int) out_j);
		for(unsigned int out_i = 0; out_i < out_w; ++out_i) {
			unsigned int x_offset = *(x_offset_ptr++), x_fraction = *(x_fraction_ptr++), x_fraction_inv = 256 - x_fraction;
			uint64_t c[4] = {in1[x_offset], in1[x_offset + 1], in2[x_offset], in2[x_offset + 1]};
			uint64_t p[4] = {((c[0] << 24) | c[0]) & mask, ((c[1] << 24) | c[1]) & mask, ((c[2] << 24) | c[2]) & mask, ((c[3] << 24) | c[3]) & mask};
			uint64_t q[2] = {((p[0] * x_fraction_inv + p[1] * x_fraction + offset) >> 8) & mask, ((p[2] * x_fraction_inv + p[3] * x_fraction + offset) >> 8) & mask};
			uint64_t r = ((q[0] * y_fraction_inv + q[1] * y_fraction + offset) >> 8) & mask;
			*(out++) = ((uint32_t) (r >> 24)) | ((uint32_t) r);
		}
	}

}

void Scale_BGRA_Fallback(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						 unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride) {
	Scale_BGRA_Generic(in_w, in_h, in_data, in_stride, out_w, out_h, out_data, out_stride, MipMap_BGRA_Fallback, Bilinear_BGRA_Fallback);
}
