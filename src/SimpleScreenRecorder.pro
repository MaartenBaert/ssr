# Don't try to compile this with qmake! This file is only meant for Qt Creator, not for actual compilation.

QT += core gui

TARGET = SimpleScreenRecorder
TEMPLATE = app

DEFINES += SSR_USE_X86_ASM=1 SSR_USE_FFMPEG_VERSIONS=1 SSR_USE_OPENGL_RECORDING=1 SSR_USE_ALSA=1 SSR_USE_PULSEAUDIO=1 SSR_USE_JACK=1 SSR_SYSTEM_DIR=\\"/usr/share/simplescreenrecorder\\"
QMAKE_CXXFLAGS += -std=c++0x -flax-vector-conversions
LIBS += -lavformat -lavcodec -lavutil -lswscale -lX11 -lXext -lXfixes -lasound

INCLUDEPATH += AV AV/Input AV/Output common GUI
DEPENDPATH += AV AV/Input AV/Output common GUI

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
	AV/FastResampler.cpp \
	AV/FastResampler_FirFilter_Fallback.cpp \
	AV/FastResampler_FirFilter_SSE2.cpp \
	AV/FastScaler.cpp \
	AV/FastScaler_Convert_Fallback.cpp \
	AV/FastScaler_Convert_SSSE3.cpp \
	AV/FastScaler_Scale_Fallback.cpp \
	AV/FastScaler_Scale_Generic.cpp \
	AV/FastScaler_Scale_SSSE3.cpp \
	AV/SimpleSynth.cpp \
	AV/SourceSink.cpp \
	common/CPUFeatures.cpp \
	common/Dialogs.cpp \
	common/Logger.cpp \
	GUI/AudioPreviewer.cpp \
	GUI/DialogGLInject.cpp \
	GUI/ElidedLabel.cpp \
	GUI/HiddenScrollArea.cpp \
	GUI/HotkeyListener.cpp \
	GUI/Icons.cpp \
	GUI/MainWindow.cpp \
	GUI/PageDone.cpp \
	GUI/PageInput.cpp \
	GUI/PageOutput.cpp \
	GUI/PageRecord.cpp \
	GUI/PageWelcome.cpp \
	GUI/ProfileBox.cpp \
	GUI/VideoPreviewer.cpp \
	Benchmark.cpp \
	Main.cpp \
	NVidia.cpp

HEADERS  += \
	AV/Input/ALSAInput.h \
	AV/Input/GLInjectInput.h \
	AV/Input/JACKInput.h \
	AV/Input/PulseAudioInput.h \
	AV/Input/SSRVideoStream.h \
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
	AV/FastResampler.h \
	AV/FastResampler_FirFilter.h \
	AV/FastScaler.h \
	AV/FastScaler_Convert.h \
	AV/FastScaler_Scale.h \
	AV/FastScaler_Scale_Generic.h \
	AV/SampleCast.h \
	AV/SimpleSynth.h \
	AV/SourceSink.h \
	common/CPUFeatures.h \
	common/Dialogs.h \
	common/EnumStrings.h \
	common/LockFreeMessageQueue.h \
	common/Logger.h \
	common/MutexDataPair.h \
	common/QueueBuffer.h \
	common/TempBuffer.h \
	GUI/AudioPreviewer.h \
	GUI/DialogGLInject.h \
	GUI/ElidedLabel.h \
	GUI/HiddenScrollArea.h \
	GUI/HotkeyListener.h \
	GUI/Icons.h \
	GUI/MainWindow.h \
	GUI/PageDone.h \
	GUI/PageInput.h \
	GUI/PageOutput.h \
	GUI/PageRecord.h \
	GUI/PageWelcome.h \
	GUI/ProfileBox.h \
	GUI/VideoPreviewer.h \
	Benchmark.h \
	Global.h \
	Main.h \
	NVidia.h

RESOURCES += \
	resources.qrc

