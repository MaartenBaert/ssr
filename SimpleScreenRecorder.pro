#-------------------------------------------------
#
# Project created by QtCreator 2012-09-11T00:50:57
#
#-------------------------------------------------

QT				+= core gui

TARGET = SimpleScreenRecorder
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x -D__STDC_CONSTANT_MACROS -flax-vector-conversions
LIBS += -lavformat -lavcodec -lavdevice -lavutil -lswscale -lX11 -lXext -lXfixes

QMAKE_CXXFLAGS_RELEASE -= -O1 -O2 -O3
QMAKE_CXXFLAGS_RELEASE += -O3 -g
QMAKE_LFLAGS_RELEASE -= -Wl,-O1 -Wl,-O2 -Wl,-O3
QMAKE_LFLAGS_RELEASE += -Wl,-O3

INCLUDEPATH += AV AV/Encoder AV/Input GUI
DEPENDPATH += AV AV/Encoder AV/Input GUI

PRECOMPILED_HEADER = StdAfx.h

SOURCES += \
	AV/Encoder/AudioEncoder.cpp \
    AV/Encoder/BaseEncoder.cpp \
    AV/Encoder/VideoEncoder.cpp \
    AV/Encoder/X264Presets.cpp \
    AV/Input/AudioInput.cpp \
    AV/Input/BaseInput.cpp \
    AV/Input/GLInjectInput.cpp \
    AV/Input/GLInjectLauncher.cpp \
    AV/Input/X11Input.cpp \
    AV/AVWrapper.cpp \
    AV/Muxer.cpp \
    AV/Synchronizer.cpp \
    AV/YUVConverter.cpp \
    GUI/HotkeyListener.cpp \
    GUI/MainWindow.cpp \
	GUI/PageDone.cpp \
    GUI/PageInput.cpp \
    GUI/PageOutput.cpp \
    GUI/PageRecord.cpp \
    GUI/PageWelcome.cpp \
    Logger.cpp \
    Main.cpp

HEADERS  += \
	AV/Encoder/AudioEncoder.h \
    AV/Encoder/BaseEncoder.h \
    AV/Encoder/VideoEncoder.h \
    AV/Encoder/X264Presets.h \
    AV/Input/AudioInput.h \
    AV/Input/BaseInput.h \
    AV/Input/GLInjectInput.h \
    AV/Input/GLInjectLauncher.h \
    AV/Input/X11Input.h \
    AV/AVWrapper.h \
    AV/Muxer.h \
    AV/Synchronizer.h \
    AV/YUVConverter.h \
    GUI/HotkeyListener.h \
    GUI/MainWindow.h \
	GUI/PageDone.h \
    GUI/PageInput.h \
    GUI/PageOutput.h \
    GUI/PageRecord.h \
    GUI/PageWelcome.h \
    Logger.h \
    StdAfx.h \
	VPair.h \
    Main.h

RESOURCES += \
    resources.qrc

