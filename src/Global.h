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

#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtGui>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stdint.h>
#include <unistd.h>
#include <sys/shm.h>

#include <limits>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <memory>

#include <atomic>
#include <thread>
#include <mutex>

#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/extensions/XShm.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavutil/mathematics.h>
#include <libswscale/swscale.h>
}

// Whether x86/x64 specific instructions should be used.
#ifndef SSR_USE_X86_ASM
#error SSR_USE_X86_ASM should be defined!
#endif

// Whether ffmpeg or libav version numbers should be used for tests. The ffmpeg version number is usually slightly higher,
// so that's the default (deprecation warnings are better than compilation errors).
#ifndef SSR_USE_FFMPEG_VERSIONS
#error SSR_USE_FFMPEG_VERSIONS should be defined!
#endif

// Whether PulseAudio should be used.
#ifndef SSR_USE_PULSEAUDIO
#error SSR_USE_PULSEAUDIO should be defined!
#endif

// Whether JACK should be used.
#ifndef SSR_USE_JACK
#error SSR_USE_JACK should be defined!
#endif

// Path to translation files.
#ifndef SSR_TRANSLATIONS_PATH
#error SSR_TRANSLATIONS_PATH should be defined!
#endif

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

// libav/ffmpeg API changes with version numbers are listed in their repositories in the file 'doc/APIchanges'
// I recommend using the ffmpeg one:
// http://git.videolan.org/?p=ffmpeg.git;a=blob;f=doc/APIchanges
// this one lists version numbers for both ffmpeg and libav whereas libav just ignores ffmpeg.

#if SSR_USE_FFMPEG_VERSIONS
#define TEST_AV_VERSION(prefix, ffmpeg_major, ffmpeg_minor, libav_major, libav_minor) TEST_MAJOR_MINOR(prefix##_VERSION_MAJOR, prefix##_VERSION_MINOR, ffmpeg_major, ffmpeg_minor)
#else
#define TEST_AV_VERSION(prefix, ffmpeg_major, ffmpeg_minor, libav_major, libav_minor) TEST_MAJOR_MINOR(prefix##_VERSION_MAJOR, prefix##_VERSION_MINOR, libav_major, libav_minor)
#endif

// avformat_network_init: lavf 53.19.0 / 53.13.0
#define SSR_USE_AVFORMAT_NETWORK_INIT    TEST_AV_VERSION(LIBAVFORMAT, 53, 19, 53, 13)
// avformat_new_stream: lavf 53.17.0 / 53.10.0
#define SSR_USE_AVFORMAT_NEW_STREAM      TEST_AV_VERSION(LIBAVFORMAT, 53, 17, 53, 10)
// avformat_query_codec: lavf 53.11.0 / 53.8.0
#define SSR_USE_AVFORMAT_QUERY_CODEC     TEST_AV_VERSION(LIBAVFORMAT, 53, 11, 53, 8)

// avcodec_free_frame: lavc 54.59.100 / 54.28.0
#define SSR_USE_AVCODEC_FREE_FRAME       TEST_AV_VERSION(LIBAVCODEC, 54, 59, 54, 28)
// AV_CODEC_ID_* instead of CODEC_ID_*: lavc 54.51.100 / 54.25.0
#define SSR_USE_AV_CODEC_ID              TEST_AV_VERSION(LIBAVCODEC, 54, 51, 54, 25)
// av_codec_is_encoder: lavc 54.8.100 / 54.7.0
#define SSR_USE_AV_CODEC_IS_ENCODER      TEST_AV_VERSION(LIBAVCODEC, 54, 8, 54, 7)
// avcodec_encode_video2: lavc 54.2.100 / 54.1.0
#define SSR_USE_AVCODEC_ENCODE_VIDEO2    TEST_AV_VERSION(LIBAVCODEC, 54, 2, 54, 1)
// avcodec_encode_audio2: lavc 53.56.105 / 53.34.0
#define SSR_USE_AVCODEC_ENCODE_AUDIO2    TEST_AV_VERSION(LIBAVCODEC, 53, 56, 53, 34)
// AVFrame::format: lavc 53.31 / 53.31
// - ffmpeg: missing, commit: http://git.videolan.org/?p=ffmpeg.git;a=commit;h=8a4a5f6ff756fdba44254015c714f173b2db6f64
// - libav: APIchanges says 53.31
#define SSR_USE_AVFRAME_FORMAT           TEST_AV_VERSION(LIBAVCODEC, 53, 31, 53, 31)
// AVFrame::nb_samples, AVFrame::extended_data and avcodec_decode_audio4: lavc 53.40.0 / 53.25.0
#define SSR_USE_AVFRAME_NB_SAMPLES       TEST_AV_VERSION(LIBAVCODEC, 53, 40, 53, 25)
#define SSR_USE_AVFRAME_EXTENDED_DATA    SSR_USE_AVFRAME_NB_SAMPLES
#define SSR_USE_AVCODEC_DECODE_AUDIO4    SSR_USE_AVFRAME_NB_SAMPLES
// the 'preset' private option: lavc 53.8 / 53.8
// - ffmpeg: missing, commit: http://git.videolan.org/?p=ffmpeg.git;a=commit;h=07a227b432e49f4c0f35bbef48009f4d8438b32e
// - libav: missing, commit: https://git.libav.org/?p=libav.git;a=commit;h=07a227b432e49f4c0f35bbef48009f4d8438b32e
#define SSR_USE_AVCODEC_PRIVATE_PRESET   TEST_AV_VERSION(LIBAVCODEC, 53, 8, 53, 8)
// the 'crf' private option: lavc 53.8 / 53.8
// - ffmpeg: missing, commit: http://git.videolan.org/?p=ffmpeg.git;a=commit;h=d5dc8cc2974c816ba964692b75c9f17f40830414
// - libav: missing, commit: https://git.libav.org/?p=libav.git;a=commit;f=libavcodec/libx264.c;h=d5dc8cc2974c816ba964692b75c9f17f40830414
#define SSR_USE_AVCODEC_PRIVATE_CRF      TEST_AV_VERSION(LIBAVCODEC, 53, 8, 53, 8)

// planar sample formats: lavu 51.27.0 / 51.17.0
#define SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT TEST_AV_VERSION(LIBAVUTIL, 51, 27, 51, 17)

// simple function to do n-byte alignment
inline size_t grow_align16(size_t size) {
	return (size_t) (size + 15) & ~((size_t) 15);
}

// convert weird types from libav/ffmpeg to doubles
inline double ToDouble(const AVRational& r) {
	return (double) r.num / (double) r.den;
}
inline double ToDouble(const AVFrac& f) {
	return (double) f.val + (double) f.num / (double) f.den;
}

// exception thrown when errors occur in external libraries
class LibavException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "LibavException";
	}
};
class ResamplerException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "ResamplerException";
	}
};
class X11Exception : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "X11Exception";
	}
};
class GLInjectException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "GLInjectException";
	}
};
class ALSAException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "ALSAException";
	}
};
#if SSR_USE_PULSEAUDIO
class PulseAudioException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "PulseAudioException";
	}
};
#endif
class JACKException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "JACKException";
	}
};

// high resolution timer
inline int64_t hrt_time_micro() {
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (uint64_t) ts.tv_sec * (uint64_t) 1000000 + (uint64_t) (ts.tv_nsec / 1000);
}

template<typename T>
inline T clamp(T v, T lo, T hi) {
	assert(lo <= hi);
	if(v < lo)
		return lo;
	if(v > hi)
		return hi;
	return v;
}

template<typename T>
inline T positive_mod(T x, T y) {
	T z = x % y;
	return (z < 0)? z + y : z;
}

template<typename T>
inline int32_t round_int32(T x) {
	if(sizeof(long) >= sizeof(int32_t))
		return lrint(x);
	if(sizeof(long long) >= sizeof(int32_t))
		return llrint(x);
	return (int32_t) rint(x);
}

template<typename T>
inline int64_t round_int64(T x) {
	if(sizeof(long) >= sizeof(int64_t))
		return lrint(x);
	if(sizeof(long long) >= sizeof(int64_t))
		return llrint(x);
	return (int64_t) rint(x);
}

inline void GroupEnabled(std::initializer_list<QAction*> actions, bool enabled) {
	for(QAction *a : actions) {
		a->setEnabled(enabled);
	}
}
inline void GroupEnabled(std::initializer_list<QWidget*> widgets, bool enabled) {
	for(QWidget *w : widgets) {
		w->setEnabled(enabled);
	}
}
inline void GroupVisible(std::initializer_list<QWidget*> widgets, bool visible) {
	for(QWidget *w : widgets) {
		w->setVisible(visible);
	}
}
inline void MultiGroupVisible(std::initializer_list<std::pair<std::initializer_list<QWidget*>, bool> > conditions) {
	// Qt updates the layout every time something is made visible or invisible, so the order is important.
	// First hide everything that needs to be hidden, then show everything that needs to be shown.
	// If the order is wrong, Qt will make the widget larger than necessary.
	for(auto &c : conditions) {
		if(!c.second)
			GroupVisible(c.first, false);
	}
	for(auto &c : conditions) {
		if(c.second)
			GroupVisible(c.first, true);
	}
}

#endif // GLOBAL_H
