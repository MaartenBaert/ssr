/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef GLOBAL_H
#define GLOBAL_H

#define __STDC_FORMAT_MACROS
#define GL_GLEXT_PROTOTYPES

//#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/glx.h>
#include <X11/X.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <stdint.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/shm.h>

#include <memory>
#include <vector>

#include <atomic>

typedef void (*GLXextFuncPtr)(void);

// generic macro to test version numbers
#define TEST_MAJOR_MINOR(major, minor, required_major, required_minor) (major > required_major || (major == required_major && minor >= required_minor))

// test GCC version
#define TEST_GCC_VERSION(major, minor) TEST_MAJOR_MINOR(__GNUC__, __GNUC_MINOR__, major, minor)

// 'override' was added in GCC 4.7
#if !TEST_GCC_VERSION(4, 7)
#define override
#endif

// std::atomic_thread_fence exists in GCC 4.6 but it doesn't link properly for some reason
#if !TEST_GCC_VERSION(4, 7)
#define atomic_thread_fence atomic_thread_fence_replacement
namespace std {
inline void atomic_thread_fence_replacement(memory_order) {
	__sync_synchronize();
}
}
#endif

// simple function to do n-byte alignment
inline size_t grow_align16(size_t size) {
	return (size_t) (size + 15) & ~((size_t) 15);
}

// high resolution timer
inline int64_t hrt_time_micro() {
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (uint64_t) ts.tv_sec * (uint64_t) 1000000 + (uint64_t) (ts.tv_nsec / 1000);
}

template<typename T>
T positive_mod(T x, T y) {
	T z = x % y;
	return (z < 0)? z + y : z;
}

#endif // GLOBAL_H
