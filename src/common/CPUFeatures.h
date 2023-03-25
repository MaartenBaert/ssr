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

#if SSR_USE_X86_ASM

class CPUFeatures {

private:
	static bool s_mmx;
	static bool s_sse, s_sse2, s_sse3, s_ssse3, s_sse41, s_sse42;
	static bool s_avx, s_avx2;
	static bool s_bmi1, s_bmi2;

public:
	static void Detect();

	inline static bool HasMMX() { return s_mmx; }
	inline static bool HasSSE() { return s_sse; }
	inline static bool HasSSE2() { return s_sse2; }
	inline static bool HasSSE3() { return s_sse3; }
	inline static bool HasSSSE3() { return s_ssse3; }
	inline static bool HasSSE41() { return s_sse41; }
	inline static bool HasSSE42() { return s_sse42; }
	inline static bool HasAVX() { return s_avx; }
	inline static bool HasAVX2() { return s_avx2; }
	inline static bool HasBMI1() { return s_bmi1; }
	inline static bool HasBMI2() { return s_bmi2; }

};

#endif // SSR_USE_X86_ASM
