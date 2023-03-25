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

void Scale_BGRA_Fallback(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
						 unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride);

#if SSR_USE_X86_ASM
void Scale_BGRA_SSSE3(unsigned int in_w, unsigned int in_h, const uint8_t* in_data, int in_stride,
					  unsigned int out_w, unsigned int out_h, uint8_t* out_data, int out_stride);
#endif
