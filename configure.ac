AC_INIT([simplescreenrecorder], [0.3.3], [maarten-baert@hotmail.com], [simplescreenrecorder], [http://www.maartenbaert.be/simplescreenrecorder/])
AC_CONFIG_SRCDIR([src/Main.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile data/Makefile glinject/Makefile scripts/Makefile src/Makefile])

AM_INIT_AUTOMAKE([foreign subdir-objects -Wall -Werror])
AM_MAINTAINER_MODE
AM_PROG_AR

LT_INIT
AC_SUBST([LIBTOOL_DEPS])

AC_PROG_CC
AC_PROG_CXX
AC_PROG_SED
AC_PROG_INSTALL
PKG_PROG_PKG_CONFIG

AC_ARG_ENABLE([ssrprogram], AS_HELP_STRING([--disable-ssrprogram], [don't build the SimpleScreenRecorder program]))
AC_ARG_ENABLE([glinjectlib], AS_HELP_STRING([--disable-glinjectlib], [don't build the GLInject library]))
AC_ARG_ENABLE([assert], AS_HELP_STRING([--disable-assert], [don't use assertions meant for debugging]))
AC_ARG_ENABLE([x86-asm], AS_HELP_STRING([--disable-x86-asm], [don't use x86/x64 assembly instructions]))
AC_ARG_ENABLE([ffmpeg-versions], AS_HELP_STRING([--disable-ffmpeg-versions], [use Libav version numbers instead of FFmpeg version numbers]))
AC_ARG_WITH([qt5], AS_HELP_STRING([--with-qt5], [use Qt5 (instead of Qt4)]))
AC_ARG_WITH([pulseaudio], AS_HELP_STRING([--without-pulseaudio], [don't use PulseAudio]))
AC_ARG_WITH([jack], AS_HELP_STRING([--without-jack], [don't use JACK]))
AM_CONDITIONAL([ENABLE_SSRPROGRAM], [test x"$enable_ssrprogram" != x"no"])
AM_CONDITIONAL([ENABLE_GLINJECTLIB], [test x"$enable_glinjectlib" != x"no"])
AM_CONDITIONAL([ENABLE_ASSERT], [test x"$enable_assert" != x"no"])
AM_CONDITIONAL([ENABLE_X86_ASM], [test x"$enable_x86_asm" != x"no"])
AM_CONDITIONAL([ENABLE_FFMPEG_VERSIONS], [test x"$enable_ffmpeg_versions" != x"no"])
AM_CONDITIONAL([WITH_QT5], [test x"$with_qt5" == x"yes"])
AM_CONDITIONAL([WITH_PULSEAUDIO], [test x"$with_pulseaudio" != x"no"])
AM_CONDITIONAL([WITH_JACK], [test x"$with_jack" != x"no"])

AC_DEFUN([SSR_CONDITIONAL_DEFINE], [
	AM_COND_IF([$1], [
		AC_DEFINE([$2], [1], [$3])
	], [
		AC_DEFINE([$2], [0], [$3])
	])
])

AM_COND_IF([ENABLE_ASSERT], [], [
	AC_DEFINE([NDEBUG], [1], [Disable assert().])
	AC_DEFINE([QT_NO_DEBUG], [1], [Disable Q_ASSERT().])
])
SSR_CONDITIONAL_DEFINE([ENABLE_X86_ASM], [SSR_USE_X86_ASM], [Allow x86/x64 assembly or intrinsics.])
SSR_CONDITIONAL_DEFINE([ENABLE_FFMPEG_VERSIONS], [SSR_USE_FFMPEG_VERSIONS], [Use FFmpeg version numbers (rather than Libav).])
SSR_CONDITIONAL_DEFINE([WITH_PULSEAUDIO], [SSR_USE_PULSEAUDIO], [Use PulseAudio.])
SSR_CONDITIONAL_DEFINE([WITH_JACK], [SSR_USE_JACK], [Use JACK.])

AM_COND_IF([ENABLE_SSRPROGRAM], [
	AM_COND_IF([WITH_QT5], [
		PKG_CHECK_MODULES([QT5], [Qt5Core >= 5.1.0 Qt5Gui Qt5Widgets Qt5X11Extras], [
			QT_PATH1="$( eval $PKG_CONFIG --variable=libdir Qt5Core )/qt5/bin"
			QT_PATH2="$( eval $PKG_CONFIG --variable=exec_prefix Qt5Core )/bin"
			AC_PATH_PROGS([MOC], [moc-qt5 moc], [moc], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([RCC], [rcc-qt5 rcc], [rcc], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([UIC], [uic-qt5 uic], [uic], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([LUPDATE], [lupdate-qt5 lupdate], [lupdate], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([LRELEASE], [lrelease-qt5 lrelease], [lrelease], [$QT_PATH1:$QT_PATH2])
		], [
			AC_MSG_ERROR([Qt5 not found])
		])
	], [
		PKG_CHECK_MODULES([QT4], [QtCore >= 4.8.0 QtGui], [
			QT_PATH1="$( eval $PKG_CONFIG --variable=libdir QtCore )/qt4/bin"
			QT_PATH2="$( eval $PKG_CONFIG --variable=exec_prefix QtCore )/bin"
			AC_PATH_PROGS([MOC], [moc-qt4 moc], [moc], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([RCC], [rcc-qt4 rcc], [rcc], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([UIC], [uic-qt4 uic], [uic], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([LUPDATE], [lupdate-qt4 lupdate], [lupdate], [$QT_PATH1:$QT_PATH2])
			AC_PATH_PROGS([LRELEASE], [lrelease-qt4 lrelease], [lrelease], [$QT_PATH1:$QT_PATH2])
		], [
			AC_MSG_ERROR([Qt4 not found])
		])
	])
])

dnl IMPORTANT: Do not remove the space in '[ ]' below - it is required to stop autoconf from adding the library to the LIBS variable.

AC_CHECK_LIB([rt], [clock_gettime], [ ], [AC_MSG_ERROR([required library missing])])

AM_COND_IF([ENABLE_GLINJECTLIB], [
	AC_CHECK_HEADER([dlfcn.h], [ ], [AC_MSG_ERROR([required header missing])])
	AC_CHECK_LIB([dl], [dlsym], [ ], [AC_MSG_ERROR([required library missing])])
])

AM_COND_IF([ENABLE_SSRPROGRAM], [
	PKG_CHECK_MODULES([FFMPEG], [libavformat >= 53 libavcodec >= 53 libavutil >= 51 libswscale >= 2])
])

AC_CHECK_HEADER([X11/Xlib.h], [ ], [AC_MSG_ERROR([required header missing])])
AC_CHECK_HEADER([X11/Xutil.h], [ ], [AC_MSG_ERROR([required header missing])], [#include <X11/Xlib.h>])
AC_CHECK_LIB([X11], [XOpenDisplay], [ ], [AC_MSG_ERROR([required library missing])])
AC_CHECK_HEADER([X11/extensions/Xfixes.h], [ ], [AC_MSG_ERROR([required header missing])], [#include <X11/Xlib.h>])
AC_CHECK_LIB([Xfixes], [XFixesGetCursorImage], [ ], [AC_MSG_ERROR([required library missing])])
AM_COND_IF([ENABLE_SSRPROGRAM], [
	AC_CHECK_HEADER([X11/extensions/XShm.h], [ ], [AC_MSG_ERROR([required header missing])], [#include <X11/Xlib.h>])
	AC_CHECK_LIB([Xext], [XShmCreateImage], [ ], [AC_MSG_ERROR([required library missing])])
	AC_CHECK_HEADER([X11/extensions/XInput2.h], [ ], [AC_MSG_ERROR([required header missing])], [#include <X11/Xlib.h>])
	AC_CHECK_LIB([Xi], [XIQueryVersion], [ ], [AC_MSG_ERROR([required library missing])])
])

AM_COND_IF([ENABLE_SSRPROGRAM], [
	AC_CHECK_HEADER([alsa/asoundlib.h], [ ], [AC_MSG_ERROR([required header missing])])
	AC_CHECK_LIB([asound], [snd_pcm_open], [ ], [AC_MSG_ERROR([required library missing])])
	AM_COND_IF([WITH_PULSEAUDIO], [
		AC_CHECK_HEADER([pulse/context.h], [ ], [AC_MSG_ERROR([required header missing])])
		AC_CHECK_LIB([pulse], [pa_context_new], [ ], [AC_MSG_ERROR([required library missing])])
	])
	AM_COND_IF([WITH_JACK], [
		AC_CHECK_HEADER([jack/jack.h], [ ], [AC_MSG_ERROR([required header missing])])
		AC_CHECK_LIB([jack], [jack_client_open], [ ], [AC_MSG_ERROR([required library missing])])
	])
])

AM_COND_IF([ENABLE_GLINJECTLIB], [
	AC_CHECK_HEADER([GL/gl.h], [ ], [AC_MSG_ERROR([required header missing])])
	AC_CHECK_HEADER([GL/glext.h], [ ], [AC_MSG_ERROR([required header missing])], [#include <GL/gl.h>])
	AC_CHECK_HEADER([GL/glx.h], [ ], [AC_MSG_ERROR([required header missing])], [#include <GL/gl.h>])
	AC_CHECK_LIB([GL], [glPushAttrib], [ ], [AC_MSG_ERROR([required library missing])])
	AC_CHECK_HEADER([GL/glu.h], [ ], [AC_MSG_ERROR([required header missing])])
	AC_CHECK_LIB([GLU], [gluErrorString], [ ], [AC_MSG_ERROR([required library missing])])
])

AC_OUTPUT
