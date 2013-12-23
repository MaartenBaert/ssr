# Don't try to compile this with qmake! This file is only meant for Qt Creator, not for actual compilation.

QT += core gui

TARGET = GLInject
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x
LIBS += -rt -ldl -lGL -lGLU -lX11 -lXfixes

SOURCES += \
	elfhacks.c \
	GLInject.cpp \
	GLXFrameGrabber.cpp \
	Hook.cpp \
	SSRVideoStreamWriter.cpp

HEADERS  += \
	elfhacks.h \
	GLInject.h \
	Global.h \
	GLXFrameGrabber.h \
	ShmStructs.h \
	SSRVideoStreamWriter.h
