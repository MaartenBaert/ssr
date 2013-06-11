# Don't try to compile this with qmake! This file is only meant for Qt Creator, not for actual compilation.

QT += core gui

TARGET = SimpleScreenRecorder
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x -D__STDC_CONSTANT_MACROS -flax-vector-conversions
LIBS += -lavformat -lavcodec -lavutil -lswscale -lX11 -lXext -lXfixes -lasound

INCLUDEPATH += AV AV/Encoder AV/Input GUI
DEPENDPATH += AV AV/Encoder AV/Input GUI

SOURCES += \
	AV/Encoder/AudioEncoder.cpp \
	AV/Encoder/BaseEncoder.cpp \
	AV/Encoder/VideoEncoder.cpp \
	AV/Encoder/X264Presets.cpp \
	AV/Input/ALSAInput.cpp \
	AV/Input/GLInjectInput.cpp \
	AV/Input/GLInjectLauncher.cpp \
	AV/Input/X11Input.cpp \
	AV/AVWrapper.cpp \
	AV/Muxer.cpp \
	AV/Synchronizer.cpp \
	AV/YUVConverter.cpp \
	GUI/AudioPreviewer.cpp \
	GUI/HotkeyListener.cpp \
	GUI/MainWindow.cpp \
	GUI/PageDone.cpp \
	GUI/PageInput.cpp \
	GUI/PageOutput.cpp \
	GUI/PageRecord.cpp \
	GUI/PageWelcome.cpp \
	GUI/VideoPreviewer.cpp \
	ByteQueue.cpp \
	Logger.cpp \
	Main.cpp \
	Version.cpp \
    AV/Input/VideoConnection.cpp

HEADERS  += \
	AV/Encoder/AudioEncoder.h \
	AV/Encoder/BaseEncoder.h \
	AV/Encoder/VideoEncoder.h \
	AV/Encoder/X264Presets.h \
	AV/Input/ALSAInput.h \
	AV/Input/GLInjectInput.h \
	AV/Input/GLInjectLauncher.h \
	AV/Input/X11Input.h \
	AV/AVWrapper.h \
	AV/Muxer.h \
	AV/Synchronizer.h \
	AV/YUVConverter.h \
	GUI/AudioPreviewer.h \
	GUI/HotkeyListener.h \
	GUI/MainWindow.h \
	GUI/PageDone.h \
	GUI/PageInput.h \
	GUI/PageOutput.h \
	GUI/PageRecord.h \
	GUI/PageWelcome.h \
	GUI/VideoPreviewer.h \
	ByteQueue.h \
	Global.h \
	Logger.h \
	Main.h \
	Version.h \
	VPair.h \
    AV/Input/VideoConnection.h

RESOURCES += \
	resources.qrc

