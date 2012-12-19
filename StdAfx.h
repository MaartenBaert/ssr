/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

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

#ifndef STDAFX_H
#define STDAFX_H

#include <QtGui>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stdint.h>
#include <unistd.h>
#include <sys/shm.h>

#include <limits>
#include <vector>
#include <deque>
#include <memory>

#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/extensions/XShm.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libavutil/mathematics.h>
#include <libswscale/swscale.h>
}

// avformat_close_input requires libavformat >= 53.17
#define SSR_USE_AVFORMAT_CLOSE_INPUT   (LIBAVFORMAT_VERSION_MAJOR > 53 || (LIBAVFORMAT_VERSION_MAJOR == 53 && LIBAVFORMAT_VERSION_MINOR >= 17))
// avformat_new_stream requires libavformat >= 53.10
#define SSR_USE_AVFORMAT_NEW_STREAM    (LIBAVFORMAT_VERSION_MAJOR > 53 || (LIBAVFORMAT_VERSION_MAJOR == 53 && LIBAVFORMAT_VERSION_MINOR >= 10))

// avcodec_encode_audio2 requires libavcodec >= 53.34
#define SSR_USE_AVCODEC_ENCODE_AUDIO2  (LIBAVCODEC_VERSION_MAJOR > 53 || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR >= 34))
// AVFrame::format requires libavcodec >= 53.31
#define SSR_USE_AVFRAME_FORMAT         (LIBAVCODEC_VERSION_MAJOR > 53 || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR >= 31))
// AVFrame::nb_samples and avcodec_decode_audio4 requires libavcodec >= 53.25
#define SSR_USE_AVFRAME_NB_SAMPLES     (LIBAVCODEC_VERSION_MAJOR > 53 || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR >= 25))
#define SSR_USE_AVCODEC_DECODE_AUDIO4  (LIBAVCODEC_VERSION_MAJOR > 53 || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR >= 25))

// simple function to do n-byte alignment
inline size_t grow_align8(size_t size) {
	return (size_t) (size + 7) & ~((size_t) 7);
}
inline size_t grow_align16(size_t size) {
	return (size_t) (size + 15) & ~((size_t) 15);
}

// convert weird types from libav to doubles
inline double ToDouble(const AVRational& r) {
	return (double) r.num / (double) r.den;
}
inline double ToDouble(const AVFrac& f) {
	return (double) f.val + (double) f.num / (double) f.den;
}

// exception thrown when an error occurs in libav
class LibavException : public std::exception {
public:
	inline virtual const char* what() const throw() {
		return "LibavException";
	}
};
class X11Exception : public std::exception {
public:
	inline virtual const char* what() const throw() {
		return "X11Exception";
	}
};
class GLInjectException : public std::exception {
public:
	inline virtual const char* what() const throw() {
		return "GLInjectException";
	}
};

// high resolution timer
inline int64_t hrt_time_micro() {
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (uint64_t) ts.tv_sec * (uint64_t) 1000000 + (uint64_t) (ts.tv_nsec / 1000);
}

template<typename T>
inline T clamp(T minval, T maxval, T x) {
	if(x <= minval)
		return minval;
	if(x >= maxval)
		return maxval;
	return x;
}

template<typename T>
T positive_mod(T x, T y) {
	T z = x % y;
	return (z < 0)? z + y : z;
}

#endif
