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

#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtGui>

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)

#include <QProcess>
#include <QTimer>

#include <QAction>
#include <QApplication>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QProgressDialog>
#include <QSystemTrayIcon>

#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QSpinBox>
#include <QSplitter>
#include <QTextBrowser>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QVBoxLayout>

#endif

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stdint.h>

#include <fcntl.h>
#include <pwd.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#include <array>
#include <atomic>
#include <deque>
#include <limits>
#include <memory>
#include <mutex>
#include <random>
#include <set>
#include <sstream>
#include <thread>
#include <vector>

#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xfixes.h>
#include <X11/extensions/Xinerama.h>
#include <X11/extensions/XShm.h>
#include <X11/extensions/XInput2.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

// replacement for Qt::WindowTransparentForInput.
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <X11/extensions/shape.h>
#endif

// replacement for QX11Info::isPlatformX11()
inline bool IsPlatformX11() {
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
	if(!QX11Info::isPlatformX11())
		return false;
#endif
	char *v = getenv("XDG_SESSION_TYPE");
	if(v != NULL) {
		if(strcasecmp(v, "x11") == 0)
			return true;
		if(strcasecmp(v, "wayland") == 0 || strcasecmp(v, "mir") == 0)
			return false;
	}
	char *d = getenv("DISPLAY");
	return (d != NULL);
}

// replacement for QFontMetrics::width()
inline int GetTextWidth(const QFontMetrics& font, const QString& str) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
	return font.horizontalAdvance(str);
#else
	return QFontMetrics(font).width(str);
#endif
}
inline int GetTextWidth(const QFont& font, const QString& str) {
	return GetTextWidth(QFontMetrics(font), str);
}

// replacement for QString::split() with QString::SkipEmptyParts
inline QStringList SplitSkipEmptyParts(const QString& str, QChar sep) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
	return str.split(sep, Qt::SkipEmptyParts);
#else
	return str.split(sep, QString::SkipEmptyParts);
#endif
}

// undefine problematic Xlib macros
#undef Bool

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavutil/channel_layout.h>
#include <libavutil/mathematics.h>
#include <libavutil/pixfmt.h>
#include <libavutil/samplefmt.h>
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

// Whether the JACK metadata API should be used. Does not work with really old JACK versions.
#ifndef SSR_USE_JACK_METADATA
#error SSR_USE_JACK_METADATA should be defined!
#endif

// Whether OpenGL recording should be used.
#ifndef SSR_USE_OPENGL_RECORDING
#error SSR_USE_OPENGL_RECORDING should be defined!
#endif

// Whether V4L2 should be used.
#ifndef SSR_USE_V4L2
#error SSR_USE_V4L2 should be defined!
#endif

// Whether ALSA should be used.
#ifndef SSR_USE_ALSA
#error SSR_USE_ALSA should be defined!
#endif

// Whether PulseAudio should be used.
#ifndef SSR_USE_PULSEAUDIO
#error SSR_USE_PULSEAUDIO should be defined!
#endif

// Whether JACK should be used.
#ifndef SSR_USE_JACK
#error SSR_USE_JACK should be defined!
#endif

// Path to system-wide application directory (usually /usr/share/simplescreenrecorder).
#ifndef SSR_SYSTEM_DIR
#error SSR_SYSTEM_DIR should be defined!
#endif

// Maximum allowed image size (to avoid 32-bit integer overflow)
#define SSR_MAX_IMAGE_SIZE 20000

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
// This one lists version numbers for both ffmpeg and libav whereas libav just ignores ffmpeg.

#if SSR_USE_FFMPEG_VERSIONS
#define TEST_AV_VERSION(prefix, ffmpeg_major, ffmpeg_minor, libav_major, libav_minor) TEST_MAJOR_MINOR(prefix##_VERSION_MAJOR, prefix##_VERSION_MINOR, ffmpeg_major, ffmpeg_minor)
#else
#define TEST_AV_VERSION(prefix, ffmpeg_major, ffmpeg_minor, libav_major, libav_minor) TEST_MAJOR_MINOR(prefix##_VERSION_MAJOR, prefix##_VERSION_MINOR, libav_major, libav_minor)
#endif

// av_muxer_iterate: lavf 58.9.100 / ???
#define SSR_USE_AV_MUXER_ITERATE                   TEST_AV_VERSION(LIBAVFORMAT, 58, 9, 999, 999)
// av_register_all deprecated: lavf 58.9.100 / ???
#define SSR_USE_AV_REGISTER_ALL_DEPRECATED         TEST_AV_VERSION(LIBAVFORMAT, 58, 9, 999, 999)
// AVStream::codecpar: lavf 57.33.100 / 57.5.0
#define SSR_USE_AVSTREAM_CODECPAR                  TEST_AV_VERSION(LIBAVFORMAT, 57, 33, 57, 5)
// AVStream::time_base as time base hint: lavf 55.44.100 / 55.20.0
#define SSR_USE_AVSTREAM_TIME_BASE                 TEST_AV_VERSION(LIBAVFORMAT, 55, 44, 55, 20)
// avformat_network_init: lavf 53.19.0 / 53.13.0
#define SSR_USE_AVFORMAT_NETWORK_INIT              TEST_AV_VERSION(LIBAVFORMAT, 53, 19, 53, 13)
// avformat_new_stream: lavf 53.17.0 / 53.10.0
#define SSR_USE_AVFORMAT_NEW_STREAM                TEST_AV_VERSION(LIBAVFORMAT, 53, 17, 53, 10)
// avformat_query_codec: lavf 53.11.0 / 53.8.0
#define SSR_USE_AVFORMAT_QUERY_CODEC               TEST_AV_VERSION(LIBAVFORMAT, 53, 11, 53, 8)
// avformat_free_context: lavf 52.96.0 / 52.96.0
#define SSR_USE_AVFORMAT_FREE_CONTEXT              TEST_AV_VERSION(LIBAVFORMAT, 52, 96, 52, 96)

// av_codec_iterate: lavc 58.10.100 / ???
#define SSR_USE_AV_CODEC_ITERATE                   TEST_AV_VERSION(LIBAVCODEC, 58, 10, 999, 999)
// av_lockmgr_register deprecated: lavc 58.9.100 / ???
#define SSR_USE_AV_LOCKMGR_REGISTER_DEPRECATED     TEST_AV_VERSION(LIBAVCODEC, 58, 9, 999, 999)
// avcodec_send_packet, avcodec_receive_frame, avcodec_send_frame, avcodec_receive_packet: lavc 57.37.100 / ???
#define SSR_USE_AVCODEC_SEND_RECEIVE               TEST_AV_VERSION(LIBAVCODEC, 57, 37, 999, 999)
// av_packet_alloc: lavc 57.12.100 / 57.8.0
#define SSR_USE_AV_PACKET_ALLOC                    TEST_AV_VERSION(LIBAVCODEC, 57, 12, 57, 8)
// AV_CODEC_CAP_*, AV_CODEC_FLAG_*: lavc 56.56.100 / 56.35.0
#define SSR_USE_AV_CODEC_CAP                       TEST_AV_VERSION(LIBAVCODEC, 56, 56, 56, 35)
#define SSR_USE_AV_CODEC_FLAG                      TEST_AV_VERSION(LIBAVCODEC, 56, 56, 56, 35)
// av_packet_rescale_ts: lavc 55.68.100 / 55.55.0
#define SSR_USE_AV_PACKET_RESCALE_TS               TEST_AV_VERSION(LIBAVCODEC, 55, 68, 55, 55)
// AVCodecContext::side_data_only_packets added: lavc 55.66.100 / 55.54.0
#define SSR_USE_SIDE_DATA_ONLY_PACKETS             TEST_AV_VERSION(LIBAVCODEC, 55, 66, 55, 54)
// AVCodecContext::side_data_only_packets deprecated: lavc 57.2 / 57.2
// - ffmpeg: missing, commit: https://git.videolan.org/?p=ffmpeg.git;a=commit;h=6064f697a321174232a3fad351afb21150c3e9e5
// - libav: missing, commit: https://git.libav.org/?p=libav.git;a=commit;h=6064f697a321174232a3fad351afb21150c3e9e5
#define SSR_USE_SIDE_DATA_ONLY_PACKETS_DEPRECATED  TEST_AV_VERSION(LIBAVCODEC, 57, 2, 57, 2)
// av_frame_alloc, av_frame_free: lavc 55.45.101 / 55.28.1
#define SSR_USE_AV_FRAME_ALLOC                     TEST_AV_VERSION(LIBAVCODEC, 55, 45, 55, 28)
#define SSR_USE_AV_FRAME_FREE                      SSR_USE_AV_FRAME_ALLOC
// avcodec_free_frame: lavc 54.59.100 / 54.28.0
#define SSR_USE_AVCODEC_FREE_FRAME                 TEST_AV_VERSION(LIBAVCODEC, 54, 59, 54, 28)
// AV_CODEC_ID_* instead of CODEC_ID_*: lavc 54.51.100 / 54.25.0
#define SSR_USE_AV_CODEC_ID                        TEST_AV_VERSION(LIBAVCODEC, 54, 51, 54, 25)
// AVFrame::channels: lavc 54.46.100 / ???
#define SSR_USE_AVFRAME_CHANNELS                   TEST_AV_VERSION(LIBAVCODEC, 54, 46, 999, 999)
// AVFrame::sample_rate: lavc 54.20.100 / 54.13.0
#define SSR_USE_AVFRAME_SAMPLE_RATE                TEST_AV_VERSION(LIBAVCODEC, 54, 20, 54, 13)
// av_codec_is_encoder: lavc 54.8.100 / 54.7.0
#define SSR_USE_AV_CODEC_IS_ENCODER                TEST_AV_VERSION(LIBAVCODEC, 54, 8, 54, 7)
// avcodec_encode_video2: lavc 54.2.100 / 54.1.0
#define SSR_USE_AVCODEC_ENCODE_VIDEO2              TEST_AV_VERSION(LIBAVCODEC, 54, 2, 54, 1)
// avcodec_encode_audio2: lavc 53.56.105 / 53.34.0
#define SSR_USE_AVCODEC_ENCODE_AUDIO2              TEST_AV_VERSION(LIBAVCODEC, 53, 56, 53, 34)
// AVFrame::nb_samples, AVFrame::extended_data and avcodec_decode_audio4: lavc 53.40.0 / 53.25.0
#define SSR_USE_AVFRAME_NB_SAMPLES                 TEST_AV_VERSION(LIBAVCODEC, 53, 40, 53, 25)
#define SSR_USE_AVFRAME_EXTENDED_DATA              SSR_USE_AVFRAME_NB_SAMPLES
#define SSR_USE_AVCODEC_DECODE_AUDIO4              SSR_USE_AVFRAME_NB_SAMPLES
// the 'preset' private option: lavc 53.8 / 53.8
// - ffmpeg: missing, commit: http://git.videolan.org/?p=ffmpeg.git;a=commit;h=07a227b432e49f4c0f35bbef48009f4d8438b32e
// - libav: missing, commit: https://git.libav.org/?p=libav.git;a=commit;h=07a227b432e49f4c0f35bbef48009f4d8438b32e
#define SSR_USE_AVCODEC_PRIVATE_PRESET             TEST_AV_VERSION(LIBAVCODEC, 53, 8, 53, 8)
// the 'crf' private option: lavc 53.8 / 53.8
// - ffmpeg: missing, commit: http://git.videolan.org/?p=ffmpeg.git;a=commit;h=d5dc8cc2974c816ba964692b75c9f17f40830414
// - libav: missing, commit: https://git.libav.org/?p=libav.git;a=commit;h=d5dc8cc2974c816ba964692b75c9f17f40830414
#define SSR_USE_AVCODEC_PRIVATE_CRF                TEST_AV_VERSION(LIBAVCODEC, 53, 8, 53, 8)
// AVFrame::format: lavc 53.5.0 / 53.31.0
#define SSR_USE_AVFRAME_FORMAT                     TEST_AV_VERSION(LIBAVCODEC, 53, 5, 53, 31)
// AVFrame::width, AVFrame::height: lavc 53.4.0 / 53.31.0
#define SSR_USE_AVFRAME_WIDTH_HEIGHT               TEST_AV_VERSION(LIBAVCODEC, 53, 4, 53, 31)
// AVFrame::sample_aspect_ratio: lavc 53.3.0 / 53.31.0
#define SSR_USE_AVFRAME_SAR                        TEST_AV_VERSION(LIBAVCODEC, 53, 3, 53, 31)

// AV_PIX_FMT_* instead of PIX_FMT_*: lavu 51.74.100 / 51.42.0
#define SSR_USE_AV_PIX_FMT                         TEST_AV_VERSION(LIBAVUTIL, 51, 74, 51, 42)
// planar sample formats: lavu 51.27.0 / 51.17.0
#define SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT           TEST_AV_VERSION(LIBAVUTIL, 51, 27, 51, 17)

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
class SSRStreamException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "SSRStreamException";
	}
};
#if SSR_USE_V4L2
class V4L2Exception : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "V4L2Exception";
	}
};
#endif
#if SSR_USE_ALSA
class ALSAException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "ALSAException";
	}
};
#endif
#if SSR_USE_PULSEAUDIO
class PulseAudioException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "PulseAudioException";
	}
};
#endif
#if SSR_USE_JACK
class JACKException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "JACKException";
	}
};
#endif

// simple function to do 16-byte alignment
inline size_t grow_align16(size_t size) {
	return (size_t) (size + 15) & ~((size_t) 15);
}

// high resolution timer
inline int64_t hrt_time_micro() {
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (uint64_t) ts.tv_sec * (uint64_t) 1000000 + (uint64_t) (ts.tv_nsec / 1000);
}

// Returns the name of the user.
inline std::string GetUserName() {
	std::vector<char> buf(std::max((long) 16384, sysconf(_SC_GETPW_R_SIZE_MAX)));
	passwd pwd, *result = NULL;
	if(getpwuid_r(geteuid(), &pwd, buf.data(), buf.size(), &result) == 0 && result != NULL)
		return std::string(result->pw_name);
	return "unknownuser";
}

template<typename T>
inline T positive_mod(T x, T y) {
	T z = x % y;
	return (z < 0)? z + y : z;
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
template<> inline float clamp<float>(float v, float lo, float hi) {
	assert(lo <= hi);
	return fmin(fmax(v, lo), hi);
}
template<> inline double clamp<double>(double v, double lo, double hi) {
	assert(lo <= hi);
	return fmin(fmax(v, lo), hi);
}

// Generic number-to-string conversion and vice versa
// Unlike the standard functions, these are locale-independent, and the functions never throw exceptions.
template<typename T>
inline std::string NumToString(T number) {
	std::ostringstream ss;
	ss << number;
	return ss.str();
}
template<typename T>
inline bool StringToNum(const std::string& str, T* number) {
	std::istringstream ss(str);
	ss >> *number;
	return !ss.fail();
}

// convert weird types from libav/ffmpeg to doubles
inline double ToDouble(const AVRational& r) {
	return (double) r.num / (double) r.den;
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
