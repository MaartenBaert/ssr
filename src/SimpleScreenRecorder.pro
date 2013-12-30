# Don't try to compile this with qmake! This file is only meant for Qt Creator, not for actual compilation.

QT += core gui

TARGET = SimpleScreenRecorder
TEMPLATE = app

DEFINES += SSR_USE_X86_ASM=1 SSR_USE_FFMPEG_VERSIONS=1 SSR_USE_PULSEAUDIO=1 SSR_USE_JACK=1 SSR_TRANSLATIONS_PATH=\"/usr/share/simplescreenrecorder/translations\"
QMAKE_CXXFLAGS += -std=c++0x -flax-vector-conversions
LIBS += -lavformat -lavcodec -lavutil -lswscale -lX11 -lXext -lXfixes -lasound

INCLUDEPATH += AV AV/Input AV/Output common GUI ../build/3rdparty
DEPENDPATH += AV AV/Input AV/Output common GUI ../build/3rdparty

SOURCES += \
	AV/Input/ALSAInput.cpp \
	AV/Input/GLInjectInput.cpp \
	AV/Input/JACKInput.cpp \
	AV/Input/PulseAudioInput.cpp \
	AV/Input/SSRVideoStreamReader.cpp \
	AV/Input/SSRVideoStreamWatcher.cpp \
	AV/Input/X11Input.cpp \
	AV/Output/AudioEncoder.cpp \
	AV/Output/BaseEncoder.cpp \
	AV/Output/Muxer.cpp \
	AV/Output/OutputManager.cpp \
	AV/Output/SyncDiagram.cpp \
	AV/Output/Synchronizer.cpp \
	AV/Output/VideoEncoder.cpp \
	AV/Output/X264Presets.cpp \
	AV/AVWrapper.cpp \
	AV/FastScaler.cpp \
	AV/FastScaler_Convert.cpp \
	AV/FastScaler_Scale.cpp \
	AV/Resampler.cpp \
	AV/SimpleSynth.cpp \
	AV/SourceSink.cpp \
	common/ByteQueue.cpp \
	common/DetectCPUFeatures.cpp \
	common/Logger.cpp \
	GUI/AudioPreviewer.cpp \
	GUI/DialogGLInject.cpp \
	GUI/ElidedLabel.cpp \
	GUI/HotkeyListener.cpp \
	GUI/Icons.cpp \
	GUI/MainWindow.cpp \
	GUI/PageDone.cpp \
	GUI/PageInput.cpp \
	GUI/PageOutput.cpp \
	GUI/PageRecord.cpp \
	GUI/PageWelcome.cpp \
	GUI/VideoPreviewer.cpp \
	Main.cpp \
	Version.cpp

HEADERS  += \
	AV/Input/ALSAInput.h \
	AV/Input/GLInjectInput.h \
	AV/Input/JACKInput.h \
	AV/Input/PulseAudioInput.h \
	AV/Input/SSRVideoStreamReader.h \
	AV/Input/SSRVideoStreamWatcher.h \
	AV/Input/X11Input.h \
	AV/Output/AudioEncoder.h \
	AV/Output/BaseEncoder.h \
	AV/Output/Muxer.h \
	AV/Output/OutputManager.h \
	AV/Output/OutputSettings.h \
	AV/Output/SyncDiagram.h \
	AV/Output/Synchronizer.h \
	AV/Output/VideoEncoder.h \
	AV/Output/X264Presets.h \
	AV/AVWrapper.h \
	AV/FastScaler.h \
	AV/FastScaler_Convert.h \
	AV/FastScaler_Scale.h \
	AV/Resampler.h \
	AV/SimpleSynth.h \
	AV/SourceSink.h \
	common/ByteQueue.h \
	common/DetectCPUFeatures.h \
	common/Logger.h \
	common/MutexDataPair.h \
	common/TempBuffer.h \
	GUI/AudioPreviewer.h \
	GUI/DialogGLInject.h \
	GUI/ElidedLabel.h \
	GUI/HotkeyListener.h \
	GUI/Icons.h \
	GUI/MainWindow.h \
	GUI/PageDone.h \
	GUI/PageInput.h \
	GUI/PageOutput.h \
	GUI/PageRecord.h \
	GUI/PageWelcome.h \
	GUI/VideoPreviewer.h \
	Global.h \
	Main.h \
	Version.h

RESOURCES += \
	resources.qrc

