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
#include "FastScaler_Scale.h"

#include "TempBuffer.h"

#if SSR_USE_X86_ASM

void MipMap_BGRA_SSSE3_Dynamic(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
							   uint8_t* out_data, int out_stride, unsigned int mx, unsigned int my) __attribute__((__target__("mmx,sse,sse2,sse3,ssse3")));
void MipMap_BGRA_SSSE3(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
					   uint8_t* out_data, int out_stride, unsigned int mx, unsigned int my) __attribute__((__target__("mmx,sse,sse2,sse3,ssse3")));
void Bilinear_BGRA_SSSE3(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						 unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride,
						 unsigned int mx, unsigned int my) __attribute__((__target__("mmx,sse,sse2,sse3,ssse3")));

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

inline uint64_t vec4x16(uint16_t x) {
	return ((uint64_t) x << 48) | ((uint64_t) x << 32) | ((uint64_t) x << 16) | ((uint64_t) x);
}

inline void Bilinear_MapIndex(unsigned int out_i, unsigned int in_w, unsigned int out_w, unsigned int mipmap, unsigned int& offset, unsigned int& fraction) {
	uint64_t inter = (((uint64_t) out_i << 8) + 128) * (uint64_t) in_w;
	unsigned int div = out_w << mipmap;
	int64_t ii = (int64_t) ((inter + (uint64_t) (div >> 1)) / (uint64_t) div) - 128;
	int off = ii >> 8;
	if(off < 0) {
		offset = 0;
		fraction = 0;
	} else if(off > (int) ((in_w - 1) >> mipmap)) {
		offset = (in_w - 1) >> mipmap;
		fraction = 256;
	} else {
		offset = off;
		fraction = ii & 255;
	}
}

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
	Q_ASSERT(mx + my <= 8);
	switch((mx << 8) | my) {
		case 0x0000: Q_ASSERT(false); break;
		case 0x0001: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 0, 1); break;
		case 0x0002: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 0, 2); break;
		case 0x0100: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 0); break;
		case 0x0101: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 1); break;
		case 0x0102: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 2); break;
		case 0x0103: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 3); break;
		case 0x0200: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 0); break;
		case 0x0201: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 1); break;
		case 0x0202: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 2); break;
		case 0x0203: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 3); break;
		case 0x0301: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 1); break;
		case 0x0302: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 2); break;
		case 0x0303: MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 3); break;
		default:     MipMap_BGRA_Fallback_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, mx, my); break;
	}
}

#if SSR_USE_X86_ASM

/*
==== SSSE3 MipMapper ====

Very similar to the fallback mipmapper. There are three different SSSE3 kernels depending on the horizontal mipmap factor (mx).
The principle is the same as with 'wannabe-SIMD', but here we want to use larger reads/writes so horizontal addition is used.
This complicates the loops a lot and this is the reason why there are three different kernels: the first one has no horizontal addition,
the second one has one horizontal addition, and the third one has three horizontal additions. The horizontal additions are slower and not associative,
so they are avoided as much as possible by delaying them until the end.

The remainders (edges of the image that require special attention) don't use SSSE3 because it's not worth it.

You won't see huge improvements compared to the fallback mipmapper, since both algorithms are usually limited by the memory bandwidth.

It's important that this function is force-inlined because this allows the compiler to eliminate the inner loops for common mipmap factors.
*/

inline __attribute__((always_inline))
void MipMap_BGRA_SSSE3_Dynamic(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
							   uint8_t* out_data, int out_stride, unsigned int mx, unsigned int my) {
	Q_ASSERT((uintptr_t) out_data % 16 == 0 && out_stride % 16 == 0);
	__m128i v_mask = _mm_set1_epi16(0xff);
	__m128i v_offset = _mm_set1_epi16(1u << (mx + my - 1));
	const uint64_t mask = vec4x16(0xff);
	const uint64_t offset = vec4x16(1u << (mx + my - 1));
	unsigned int wrem = in_w & ((1u << mx) - 1);
	unsigned int hrem = in_h & ((1u << my) - 1);
	for(unsigned int out_j = 0; out_j < (in_h >> my); ++out_j) {
		const uint32_t *in = (const uint32_t*) (in_data + in_stride * (int) (out_j << my));
		uint32_t *out = (uint32_t*) (out_data + out_stride * (int) out_j);
		unsigned int blockrem;
		if(mx == 0) {
			for(unsigned int out_i = 0; out_i < (in_w >> (mx + 2)); ++out_i) {
				__m128i sum1br = _mm_setzero_si128(), sum1ga = _mm_setzero_si128();
				const uint32_t *in2 = in;
				for(unsigned int mj = 0; mj < (1u << my); ++mj) {
					__m128i c1 = _mm_loadu_si128((__m128i*) in2);
					sum1br = _mm_add_epi16(sum1br, _mm_and_si128(c1, v_mask));
					sum1ga = _mm_add_epi16(sum1ga, _mm_and_si128(_mm_srli_si128(c1, 1), v_mask));
					in2 = (const uint32_t*) ((const uint8_t*) in2 + in_stride);
				}
				in += 4;
				__m128i qbr = _mm_srli_epi16(_mm_add_epi16(sum1br, v_offset), my);
				__m128i qga = _mm_srli_epi16(_mm_add_epi16(sum1ga, v_offset), my);
				_mm_stream_si128((__m128i*) out, _mm_or_si128(qbr, _mm_slli_si128(qga, 1)));
				out += 4;
			}
			blockrem = (in_w >> mx) & 3;
		} else if(mx == 1) {
			for(unsigned int out_i = 0; out_i < (in_w >> (mx + 2)); ++out_i) {
				__m128i sum1br = _mm_setzero_si128(), sum1ga = _mm_setzero_si128(), sum2br = _mm_setzero_si128(), sum2ga = _mm_setzero_si128();
				const uint32_t *in2 = in;
				for(unsigned int mj = 0; mj < (1u << my); ++mj) {
					__m128i c1 = _mm_loadu_si128((__m128i*) in2);
					__m128i c2 = _mm_loadu_si128((__m128i*) (in2 + 4));
					sum1br = _mm_add_epi16(sum1br, _mm_and_si128(c1, v_mask));
					sum1ga = _mm_add_epi16(sum1ga, _mm_and_si128(_mm_srli_si128(c1, 1), v_mask));
					sum2br = _mm_add_epi16(sum2br, _mm_and_si128(c2, v_mask));
					sum2ga = _mm_add_epi16(sum2ga, _mm_and_si128(_mm_srli_si128(c2, 1), v_mask));
					in2 = (const uint32_t*) ((const uint8_t*) in2 + in_stride);
				}
				in += 8;
				__m128i qbr = _mm_srli_epi16(_mm_add_epi16(_mm_hadd_epi32(sum1br, sum2br), v_offset), 1 + my);
				__m128i qga = _mm_srli_epi16(_mm_add_epi16(_mm_hadd_epi32(sum1ga, sum2ga), v_offset), 1 + my);
				_mm_stream_si128((__m128i*) out, _mm_or_si128(qbr, _mm_slli_si128(qga, 1)));
				out += 4;
			}
			blockrem = (in_w >> mx) & 3;
		} else {
			for(unsigned int out_i = 0; out_i < (in_w >> (mx + 1)); ++out_i) {
				__m128i sum1br = _mm_setzero_si128(), sum1ga = _mm_setzero_si128(), sum2br = _mm_setzero_si128(), sum2ga = _mm_setzero_si128();
				const uint32_t *in2 = in;
				for(unsigned int mj = 0; mj < (1u << my); ++mj) {
					for(unsigned int mi = 0; mi < (1u << (mx - 2)); ++mi) {
						__m128i c1 = _mm_loadu_si128((__m128i*) (in2 + mi * 4));
						sum1br = _mm_add_epi16(sum1br, _mm_and_si128(c1, v_mask));
						sum1ga = _mm_add_epi16(sum1ga, _mm_and_si128(_mm_srli_si128(c1, 1), v_mask));
					}
					for(unsigned int mi = (1u << (mx - 2)); mi < (1u << (mx - 1)); ++mi) {
						__m128i c2 = _mm_loadu_si128((__m128i*) (in2 + mi * 4));
						sum2br = _mm_add_epi16(sum2br, _mm_and_si128(c2, v_mask));
						sum2ga = _mm_add_epi16(sum2ga, _mm_and_si128(_mm_srli_si128(c2, 1), v_mask));
					}
					in2 = (const uint32_t*) ((const uint8_t*) in2 + in_stride);
				}
				in += (1u << (mx + 1));
				__m128i q = _mm_srli_epi16(_mm_add_epi16(_mm_hadd_epi32(_mm_hadd_epi32(sum1br, sum2br), _mm_hadd_epi32(sum1ga, sum2ga)), v_offset), mx + my);
#if defined(__x86_64__) && TEST_GCC_VERSION(4, 8)
				_mm_stream_si64((long long*) out, _mm_cvtsi128_si64(_mm_or_si128(q, _mm_srli_si128(q, 7))));
#else
				_mm_storel_epi64((__m128i*) out, _mm_or_si128(q, _mm_srli_si128(q, 7)));
#endif
				out += 2;
			}
			blockrem = (in_w >> mx) & 1;
		}
		for(unsigned int out_i = 0; out_i < blockrem; ++out_i) {
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
	_mm_sfence();
}

void MipMap_BGRA_SSSE3(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
				  uint8_t* out_data, int out_stride, unsigned int mx, unsigned int my) {
	Q_ASSERT(mx + my <= 8);
	switch((mx << 8) | my) {
		case 0x0000: Q_ASSERT(false); break;
		case 0x0001: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 0, 1); break;
		case 0x0002: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 0, 2); break;
		case 0x0100: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 0); break;
		case 0x0101: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 1); break;
		case 0x0102: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 2); break;
		case 0x0103: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 1, 3); break;
		case 0x0200: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 0); break;
		case 0x0201: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 1); break;
		case 0x0202: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 2); break;
		case 0x0203: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 2, 3); break;
		case 0x0301: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 1); break;
		case 0x0302: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 2); break;
		case 0x0303: MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, 3, 3); break;
		default:     MipMap_BGRA_SSSE3_Dynamic(in_w, in_h, in_data, in_stride, out_data, out_stride, mx, my); break;
	}
}

#endif

/*
==== Fallback Bilinear Scaler ====

Uses 'wannabe-SIMD' like the mipmapper. It's slightly less efficient here because of the multiplications, but still much faster than plain 32-bit integers.
*/

void Bilinear_BGRA_Fallback(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
							unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride,
							unsigned int mx, unsigned int my) {
	Q_ASSERT(in_w > 1 && in_h > 1); //TODO// support size 1?
	Q_ASSERT(out_w > 1 && out_h > 1); //TODO// support size 1?
	Q_ASSERT(in_w < (1 << 28) && in_h < (1 << 28));
	Q_ASSERT(out_w < (1 << 28) && out_w < (1 << 28));

	// precompute horizontal offsets and fractions
	TempBuffer<unsigned int> x_offset_table, x_fraction_table;
	x_offset_table.alloc(out_w);
	x_fraction_table.alloc(out_w);
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
		unsigned int *x_offset_ptr = x_offset_table.data(), *x_fraction_ptr = x_fraction_table.data();
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

#if SSR_USE_X86_ASM

/*
==== SSSE3 Bilinear Scaler ====

Same principle as the fallback scaler, but this version produces two pixels per iteration. That means it can read 64-bit blocks and write 64-bit blocks,
and the shuffles are also more efficient than just shifting.
*/

void Bilinear_BGRA_SSSE3(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						 unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride,
						 unsigned int mx, unsigned int my) {
	Q_ASSERT(in_w > 1 && in_h > 1); //TODO// support size 1?
	Q_ASSERT(out_w > 1 && out_h > 1); //TODO// support size 1?
	Q_ASSERT(in_w < (1 << 28) && in_h < (1 << 28));
	Q_ASSERT(out_w < (1 << 28) && out_w < (1 << 28));
	Q_ASSERT((uintptr_t) out_data % 16 == 0 && out_stride % 16 == 0);

	// precompute horizontal offsets and fractions
	TempBuffer<unsigned int> x_offset_table;
	TempBuffer<uint64_t> x_fraction_table;
	x_offset_table.alloc(out_w);
	x_fraction_table.alloc(out_w);
	for(unsigned int out_i = 0; out_i < out_w; ++out_i) {
		unsigned int x_fraction;
		Bilinear_MapIndex(out_i, in_w, out_w, mx, x_offset_table[out_i], x_fraction);
		x_fraction_table[out_i] = ((uint64_t) x_fraction << 48) | ((uint64_t) x_fraction << 32) | ((uint64_t) x_fraction << 16) | ((uint64_t) x_fraction);
	}

	// constants
	__m128i v_128       = _mm_set1_epi16(128);
	__m128i v_256       = _mm_set1_epi16(256);
	__m128i v_shuffle1  = _mm_setr_epi8(0, 255, 1, 255, 2, 255, 3, 255, 255, 255, 255, 255, 255, 255, 255, 255);
	__m128i v_shuffle2  = _mm_setr_epi8(255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 1, 255, 2, 255, 3, 255);
	__m128i v_shuffle3  = _mm_setr_epi8(4, 255, 5, 255, 6, 255, 7, 255, 255, 255, 255, 255, 255, 255, 255, 255);
	__m128i v_shuffle4  = _mm_setr_epi8(255, 255, 255, 255, 255, 255, 255, 255, 4, 255, 5, 255, 6, 255, 7, 255);
	__m128i v_shuffle5  = _mm_setr_epi8(1, 3, 5, 7, 9, 11, 13, 15, 255, 255, 255, 255, 255, 255, 255, 255);

	// scale
	for(unsigned int out_j = 0; out_j < out_h; ++out_j) {
		unsigned int y_offset, y_fraction;
		Bilinear_MapIndex(out_j, in_h, out_h, my, y_offset, y_fraction);
		__m128i vy_fraction = _mm_set1_epi16(y_fraction);
		__m128i vy_fraction_inv = _mm_sub_epi16(v_256, vy_fraction);
		unsigned int *x_offset_ptr = x_offset_table.data();
		uint64_t *x_fraction_ptr = x_fraction_table.data();
		const uint32_t *in1 = (const uint32_t*) (in_data + in_stride * (int) y_offset);
		const uint32_t *in2 = (const uint32_t*) (in_data + in_stride * ((int) y_offset + 1));
		uint32_t *out = (uint32_t*) (out_data + out_stride * (int) out_j);
		for(unsigned int out_i = 0; out_i < out_w / 2; ++out_i) {

			unsigned int x_offset1 = x_offset_ptr[0];
			unsigned int x_offset2 = x_offset_ptr[1];
			__m128i vx_fraction = _mm_load_si128((__m128i*) x_fraction_ptr);
			__m128i vx_fraction_inv = _mm_sub_epi16(v_256, vx_fraction);
			x_offset_ptr += 2;
			x_fraction_ptr += 2;

			__m128i c1a = _mm_loadl_epi64((__m128i*) (in1 + x_offset1));
			__m128i c2a = _mm_loadl_epi64((__m128i*) (in1 + x_offset2));
			__m128i c1b = _mm_loadl_epi64((__m128i*) (in2 + x_offset1));
			__m128i c2b = _mm_loadl_epi64((__m128i*) (in2 + x_offset2));

			//_mm_prefetch(in1 + x_offset2 + 64, _MM_HINT_T0);
			//_mm_prefetch(in2 + x_offset2 + 64, _MM_HINT_T0);

			__m128i p1 = _mm_or_si128(_mm_shuffle_epi8(c1a, v_shuffle1), _mm_shuffle_epi8(c2a, v_shuffle2));
			__m128i p2 = _mm_or_si128(_mm_shuffle_epi8(c1a, v_shuffle3), _mm_shuffle_epi8(c2a, v_shuffle4));
			__m128i q1 = _mm_srli_epi16(_mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(p1, vx_fraction_inv), v_128), _mm_mullo_epi16(p2, vx_fraction)), 8);

			__m128i p3 = _mm_or_si128(_mm_shuffle_epi8(c1b, v_shuffle1), _mm_shuffle_epi8(c2b, v_shuffle2));
			__m128i p4 = _mm_or_si128(_mm_shuffle_epi8(c1b, v_shuffle3), _mm_shuffle_epi8(c2b, v_shuffle4));
			__m128i q2 = _mm_srli_epi16(_mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(p3, vx_fraction_inv), v_128), _mm_mullo_epi16(p4, vx_fraction)), 8);

			__m128i r = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(q1, vy_fraction_inv), v_128), _mm_mullo_epi16(q2, vy_fraction));

			_mm_storel_epi64((__m128i*) out, _mm_shuffle_epi8(r, v_shuffle5));
			out += 2;

		}
		if(out_w & 1) {

			unsigned int x_offset1 = x_offset_ptr[0];
			__m128i vx_fraction = _mm_loadl_epi64((__m128i*) x_fraction_ptr);
			__m128i vx_fraction_inv = _mm_sub_epi16(v_256, vx_fraction);

			__m128i c1a = _mm_loadl_epi64((__m128i*) (in1 + x_offset1));
			__m128i c1b = _mm_loadl_epi64((__m128i*) (in2 + x_offset1));

			__m128i p1 = _mm_shuffle_epi8(c1a, v_shuffle1);
			__m128i p2 = _mm_shuffle_epi8(c1a, v_shuffle3);
			__m128i q1 = _mm_srli_epi16(_mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(p1, vx_fraction_inv), v_128), _mm_mullo_epi16(p2, vx_fraction)), 8);

			__m128i p3 = _mm_shuffle_epi8(c1b, v_shuffle1);
			__m128i p4 = _mm_shuffle_epi8(c1b, v_shuffle3);
			__m128i q2 = _mm_srli_epi16(_mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(p3, vx_fraction_inv), v_128), _mm_mullo_epi16(p4, vx_fraction)), 8);

			__m128i r = _mm_add_epi16(_mm_add_epi16(_mm_mullo_epi16(q1, vy_fraction_inv), v_128), _mm_mullo_epi16(q2, vy_fraction));

			*out = _mm_cvtsi128_si32(_mm_shuffle_epi8(r, v_shuffle5));

		}
	}

}

#endif

typedef void (*MipMapFunction)(unsigned int, unsigned int, const uint8_t*, int, uint8_t*, int, unsigned int, unsigned int);
typedef void (*BilinearFunction)(unsigned int, unsigned int, const uint8_t*, int, unsigned int, unsigned int, uint8_t*, int, unsigned int, unsigned int);

void Scale_BGRA_Generic(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride,
						MipMapFunction mipmap_function, BilinearFunction bilinear_function) {

	// no scaling?
	if(in_w == out_w && in_h == out_h) {
		for(unsigned int out_j = 0; out_j < out_h; ++out_j) {
			memcpy(out_data, in_data, in_w * 4);
			in_data += in_stride;
			out_data += out_stride;
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
		mipmap.alloc(mipmap_stride * mipmap_h);
		mipmap_function(in_w, in_h, in_data, in_stride, mipmap.data(), mipmap_stride, mx, my);
		in_data = mipmap.data();
		in_stride = mipmap_stride;
	}

	bilinear_function(in_w, in_h, in_data, in_stride, out_w, out_h, out_data, out_stride, mx, my);

}

void Scale_BGRA_Fallback(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						 unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride) {
	Scale_BGRA_Generic(in_w, in_h, in_data, in_stride, out_w, out_h, out_data, out_stride, MipMap_BGRA_Fallback, Bilinear_BGRA_Fallback);
}

#if SSR_USE_X86_ASM
void Scale_BGRA_SSSE3(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
					  unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride) {
	Scale_BGRA_Generic(in_w, in_h, in_data, in_stride, out_w, out_h, out_data, out_stride, MipMap_BGRA_SSSE3, Bilinear_BGRA_SSSE3);
}
#endif
