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

#include "FastResampler_FirFilter.h"

#if SSR_USE_X86_ASM

#include <xmmintrin.h> // sse
#include <emmintrin.h> // sse2

void FastResampler_FirFilter2_C1_SSE2(unsigned int channels, unsigned int filter_length, float* coef1, float* coef2, float frac, float* input, float* output) {
	Q_UNUSED(channels);
	__m128 sum = _mm_setzero_ps();
	__m128 v_frac = _mm_set1_ps(frac);
	for(unsigned int i = 0; i < filter_length / 4; ++i) {
		__m128 v_coef1 = _mm_load_ps(coef1), v_coef2 = _mm_load_ps(coef2);
		coef1 += 4; coef2 += 4;
		__m128 filter_value = _mm_add_ps(v_coef1, _mm_mul_ps(_mm_sub_ps(v_coef2, v_coef1), v_frac));
		__m128 v_input = _mm_loadu_ps(input);
		input += 4;
		sum = _mm_add_ps(sum, _mm_mul_ps(v_input, filter_value));
	}
	__m128 sum2 = _mm_add_ps(sum, _mm_shuffle_ps(sum, sum, 0x0e));
	__m128 sum3 = _mm_add_ss(sum2, _mm_shuffle_ps(sum2, sum2, 0x01));
	_mm_store_ss(output, sum3);
}

void FastResampler_FirFilter2_C2_SSE2(unsigned int channels, unsigned int filter_length, float* coef1, float* coef2, float frac, float* input, float* output) {
	Q_UNUSED(channels);
	__m128 sum = _mm_setzero_ps();
	__m128 v_frac = _mm_set1_ps(frac);
	for(unsigned int i = 0; i < filter_length / 4; ++i) {
		__m128 v_coef1 = _mm_load_ps(coef1), v_coef2 = _mm_load_ps(coef2);
		coef1 += 4; coef2 += 4;
		__m128 filter_value = _mm_add_ps(v_coef1, _mm_mul_ps(_mm_sub_ps(v_coef2, v_coef1), v_frac));
		__m128 v_input1 = _mm_loadu_ps(input), v_input2 = _mm_loadu_ps(input + 4);
		input += 8;
		sum = _mm_add_ps(sum, _mm_mul_ps(v_input1, _mm_unpacklo_ps(filter_value, filter_value)));
		sum = _mm_add_ps(sum, _mm_mul_ps(v_input2, _mm_unpackhi_ps(filter_value, filter_value)));
	}
	__m128 sum2 = _mm_add_ps(sum, _mm_shuffle_ps(sum, sum, 0xee));
	_mm_store_sd((double*) output, _mm_castps_pd(sum2));
}

void FastResampler_FirFilter2_Cn_SSE2(unsigned int channels, unsigned int filter_length, float* coef1, float* coef2, float frac, float* input, float* output) {
	Q_UNUSED(channels);
	for(unsigned int c = 0; c < channels; ++c) {
		__m128 sum = _mm_setzero_ps();
		__m128 v_frac = _mm_set1_ps(frac);
		float *input2 = input + c;
		for(unsigned int i = 0; i < filter_length / 4; ++i) {
			__m128 v_coef1 = _mm_load_ps(coef1), v_coef2 = _mm_load_ps(coef2);
			coef1 += 4; coef2 += 4;
			__m128 filter_value = _mm_add_ps(v_coef1, _mm_mul_ps(_mm_sub_ps(v_coef2, v_coef1), v_frac));
			__m128 v_input1 = _mm_load_ss(input2); input2 += channels;
			__m128 v_input2 = _mm_load_ss(input2); input2 += channels;
			__m128 v_input3 = _mm_load_ss(input2); input2 += channels;
			__m128 v_input4 = _mm_load_ss(input2); input2 += channels;
			__m128 v_input = _mm_movelh_ps(_mm_unpacklo_ps(v_input1, v_input2), _mm_unpacklo_ps(v_input3, v_input4));
			sum = _mm_add_ps(sum, _mm_mul_ps(v_input, filter_value));
		}
		__m128 sum2 = _mm_add_ps(sum, _mm_shuffle_ps(sum, sum, 0x0e));
		__m128 sum3 = _mm_add_ss(sum2, _mm_shuffle_ps(sum2, sum2, 0x01));
		_mm_store_ss(output + c, sum3);
	}
}

#endif
