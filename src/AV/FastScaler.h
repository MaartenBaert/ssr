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

#pragma once
#include "Global.h"

class FastScaler {

private:
#if SSR_USE_X86_ASM
	bool m_use_ssse3, m_warn_alignment;
#endif

	bool m_warn_swscale;
	SwsContext *m_sws_context;

public:
	FastScaler();
	~FastScaler();
	void Scale(unsigned int in_width, unsigned int in_height, const uint8_t* const* in_data, const int* in_stride, PixelFormat in_format,
			   unsigned int out_width, unsigned int out_height, uint8_t* const* out_data, const int* out_stride, PixelFormat out_format);

};
