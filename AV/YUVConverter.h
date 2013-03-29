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
#include "StdAfx.h"

// Faster BGRA to YUV converter.
// Note: this code assumes little-endianness.
class YUVConverter {
private:
	bool m_use_sse, m_warn_alignment;
public:
	YUVConverter();
	void Convert(unsigned int w, unsigned int h, uint8_t* in_data, int in_stride, uint8_t* out_data[3], int out_stride[3]);
};
