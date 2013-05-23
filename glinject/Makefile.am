if ENABLE_GLINJECTLIB

lib_LTLIBRARIES = libssr-glinject.la

libssr_glinject_la_SOURCES = \
	elfhacks.c \
	elfhacks.h \
	GLFrameGrabber.cpp \
	GLFrameGrabber.h \
	GLInject.cpp \
	GLInject.h \
	Global.h \
	Hook.cpp \
	ShmStructs.h
libssr_glinject_la_LDFLAGS = \
	-avoid-version -shared \
	 -lrt -ldl -lGL -lGLU -lX11 -lXfixes

endif
