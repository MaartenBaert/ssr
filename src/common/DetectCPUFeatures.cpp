/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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
#include "DetectCPUFeatures.h"

#include "Logger.h"

#if SSR_USE_X86_ASM

/*
In GCC 4.8 this should work:
__builtin_cpu_init();
sse2 = __builtin_cpu_supports("sse2");
... but for now I have to use CPUID manually.
*/

void DetectCPUFeatures(CPUFeatures* features) {
	// CPUID exists in i586 ('pentium 1') and higher, older processors are not supported.
	// The meaning of ecx/edx bits are listed in table 3-20 and 3-21 ('Feature Information Returned in the ECX/EDX Register')
	// from the Intel reference manual (page 589), or in AMD's CPUID reference (they are compatible).
	memset(features, 0, sizeof(CPUFeatures));
	QString str = "[DetectCPUFeatures] " + Logger::tr("CPU features") + ":";

	unsigned int eax, ebx, ecx, edx;
	__asm__ __volatile__ ("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
	unsigned int cpuid_max = eax;

	if(cpuid_max >= 1) {
		__asm__ __volatile__ ("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (1));
		if(edx & (1 << 23)) { features->mmx    = true; str += " mmx"; }
		if(edx & (1 << 25)) { features->sse    = true; str += " sse"; }
		if(edx & (1 << 26)) { features->sse2   = true; str += " sse2"; }
		if(ecx & (1 << 0))  { features->sse3   = true; str += " sse3"; }
		if(ecx & (1 << 9))  { features->ssse3  = true; str += " ssse3"; }
		if(ecx & (1 << 19)) { features->sse4_1 = true; str += " sse4_1"; }
		if(ecx & (1 << 20)) { features->sse4_2 = true; str += " sse4_2"; }
		if(ecx & (1 << 28)) { features->avx    = true; str += " avx"; }
	}

	if(cpuid_max >= 7) {
		__asm__ __volatile__ ("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (7), "c" (0));
		if(ebx & (1 << 5))  { features->avx2   = true; str += " avx2"; }
		if(ebx & (1 << 3))  { features->bmi1   = true; str += " bmi1"; }
		if(ebx & (1 << 8))  { features->bmi2   = true; str += " bmi2"; }
	}

	Logger::LogInfo(str);
}

#endif // SSR_USE_X86_ASM
