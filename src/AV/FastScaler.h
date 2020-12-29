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

#include "AVWrapper.h"

class FastScaler {

private:
#if SSR_USE_X86_ASM
	bool m_warn_alignment;
#endif

	bool m_warn_swscale;
	SwsContext *m_sws_context;

public:
	FastScaler();
	~FastScaler();
	void Scale(unsigned int in_width, unsigned int in_height, AVPixelFormat in_format, int in_colorspace, const uint8_t* const* in_data, const int* in_stride,
			   unsigned int out_width, unsigned int out_height, AVPixelFormat out_format, int out_colorspace, uint8_t* const* out_data, const int* out_stride);

private:
	void Convert_BGRA_YUV444(unsigned int width, unsigned int height, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]);
	void Convert_BGRA_YUV422(unsigned int width, unsigned int height, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]);
	void Convert_BGRA_YUV420(unsigned int width, unsigned int height, const uint8_t* in_data, int in_stride, uint8_t* const out_data[3], const int out_stride[3]);
	void Convert_BGRA_NV12(unsigned int width, unsigned int height, const uint8_t* in_data, int in_stride, uint8_t* const out_data[2], const int out_stride[2]);
	void Convert_BGRA_BGR(unsigned int width, unsigned int height, const uint8_t* in_data, int in_stride, uint8_t* out_data, int out_stride);
	void Scale_BGRA(unsigned int in_width, unsigned int in_height, const uint8_t* in_data, int in_stride,
					unsigned int out_width, unsigned int out_height, uint8_t* out_data, int out_stride);

};
