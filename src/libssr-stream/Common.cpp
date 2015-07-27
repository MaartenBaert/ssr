/*
Copyright (c) 2012-2015 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
*/

#include "Common.h"

#include <ctime>

#include <mutex>
#include <random>

#include <unistd.h>
#include <sys/types.h>

std::mt19937_64 g_global_rng(MonotonicTimeMicro());
std::mutex g_global_rng_mutex;

uint64_t MonotonicTimeMicro() {
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (uint64_t) ts.tv_sec * (uint64_t) 1000000 + (uint64_t) (ts.tv_nsec / 1000);
}

uint64_t RandomUInt64() {
	std::lock_guard<std::mutex> lock(g_global_rng_mutex);
	return g_global_rng();
}

std::string GetRuntimeDir() {
	char *xdg_runtime_dir = getenv("XDG_RUNTIME_DIR");
	if(xdg_runtime_dir == NULL) {
		std::cerr << "[SSR-Stream] Warning: XDG_RUNTIME_DIR is undefined! Using /tmp instead." << std::endl;
		return "/tmp";
	}
	return xdg_runtime_dir;
}

std::string GetProgramName() {
	char buffer[10000];
	ssize_t size = readlink("/proc/self/exe", buffer, sizeof(buffer));
	if(size < 0)
		return std::string();
	std::string path(buffer, size);
	size_t p = path.find_last_of('/');
	if(p == std::string::npos)
		return path;
	return path.substr(p + 1);
}

std::string ErrorString() {
	char buffer[1000];
#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !_GNU_SOURCE
	if(strerror_r(errno, buffer, sizeof(buffer)) != 0) {
		return "Unknown error";
	}
	return std::string(buffer);
#else
	return std::string(strerror_r(errno, buffer, sizeof(buffer)));
#endif
}
