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

#include "CPUFeatures.h"

#include "Logger.h"

#if SSR_USE_X86_ASM

#include <cpuid.h>

//#define __cpuid(level, eax, ebx, ecx, edx) __asm__ __volatile__ ("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (level))
//#define __cpuid_count(level, count, eax, ebx, ecx, edx) __asm__ __volatile__ ("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (level), "c" (count))

bool CPUFeatures::s_mmx = false;
bool CPUFeatures::s_sse = false;
bool CPUFeatures::s_sse2 = false;
bool CPUFeatures::s_sse3 = false;
bool CPUFeatures::s_ssse3 = false;
bool CPUFeatures::s_sse41 = false;
bool CPUFeatures::s_sse42 = false;
bool CPUFeatures::s_avx = false;
bool CPUFeatures::s_avx2 = false;
bool CPUFeatures::s_bmi1 = false;
bool CPUFeatures::s_bmi2 = false;

void CPUFeatures::Detect() {

	QString str = "[CPUFeatures::Detect] " + Logger::tr("CPU features") + ":";

	// CPUID exists in i586 ('pentium 1') and higher, older processors are not supported.
	// The meaning of ecx/edx bits are listed in table 3-20 and 3-21 ('Feature Information Returned in the ECX/EDX Register')
	// from the Intel reference manual (page 589), or in AMD's CPUID reference (they are compatible).
	unsigned int eax, ebx, ecx, edx;
	__cpuid(0, eax, ebx, ecx, edx);
	unsigned int cpuid_max = eax;

	if(cpuid_max >= 1) {
		__cpuid(1, eax, ebx, ecx, edx);
		if(edx & (1 << 23)) { s_mmx    = true; str += " mmx"; }
		if(edx & (1 << 25)) { s_sse    = true; str += " sse"; }
		if(edx & (1 << 26)) { s_sse2   = true; str += " sse2"; }
		if(ecx & (1 << 0))  { s_sse3   = true; str += " sse3"; }
		if(ecx & (1 << 9))  { s_ssse3  = true; str += " ssse3"; }
		if(ecx & (1 << 19)) { s_sse41  = true; str += " sse4_1"; }
		if(ecx & (1 << 20)) { s_sse42  = true; str += " sse4_2"; }
		if(ecx & (1 << 28)) { s_avx    = true; str += " avx"; }
	}

	if(cpuid_max >= 7) {
		__cpuid_count(7, 0, eax, ebx, ecx, edx);
		if(ebx & (1 << 5))  { s_avx2   = true; str += " avx2"; }
		if(ebx & (1 << 3))  { s_bmi1   = true; str += " bmi1"; }
		if(ebx & (1 << 8))  { s_bmi2   = true; str += " bmi2"; }
	}

	Logger::LogInfo(str);
}

#endif // SSR_USE_X86_ASM
