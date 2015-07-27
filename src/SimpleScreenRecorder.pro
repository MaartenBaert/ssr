# Don't try to compile this with qmake! This file is only meant for Qt Creator, not for actual compilation.

QT += core gui

TARGET = SimpleScreenRecorder
TEMPLATE = app

DEFINES += SSR_USE_X86_ASM=1 SSR_USE_FFMPEG_VERSIONS=1 SSR_USE_PULSEAUDIO=1 SSR_USE_JACK=1 SSR_SYSTEM_DIR=\"/usr/share/simplescreenrecorder\"
QMAKE_CXXFLAGS += -std=c++0x
LIBS += -lrt -lavformat -lavcodec -lavutil -lswscale -lX11 -lXext -lXfixes -lXi -lasound -lpulse -ljack

########## Warning: Everything below this line is auto-generated and will be overwritten! ##########

HEADERS += \
	libelfhacks/elfhacks.h \
	libssr-glinject/GLInject.h \
	libssr-glinject/GLInjectGlobal.h \
	libssr-glinject/GLXFrameGrabber.h \
	libssr-glinject/SSRVideoStreamWriter.h \
	libssr-glinject/ShmStructs.h \
	libssr-stream/ClientConnection.h \
	libssr-stream/Common.h \
	libssr-stream/FileDescriptor.h \
	libssr-stream/MessageHelpers.h \
	libssr-stream/Protocol.h \
	libssr-stream/QueueBuffer.h \
	libssr-stream/Server.h \
	libssr-stream/ServerConnection.h \
	libssr-stream/VideoFrame.h \
	simplescreenrecorder/AV/Input/ALSAInput.h \
	simplescreenrecorder/AV/Input/GLInjectInput.h \
	simplescreenrecorder/AV/Input/JACKInput.h \
	simplescreenrecorder/AV/Input/PulseAudioInput.h \
	simplescreenrecorder/AV/Input/X11Input.h \
	simplescreenrecorder/AV/Output/AudioEncoder.h \
	simplescreenrecorder/AV/Output/BaseEncoder.h \
	simplescreenrecorder/AV/Output/Muxer.h \
	simplescreenrecorder/AV/Output/OutputManager.h \
	simplescreenrecorder/AV/Output/OutputSettings.h \
	simplescreenrecorder/AV/Output/SyncDiagram.h \
	simplescreenrecorder/AV/Output/Synchronizer.h \
	simplescreenrecorder/AV/Output/VideoEncoder.h \
	simplescreenrecorder/AV/Output/X264Presets.h \
	simplescreenrecorder/AV/AVWrapper.h \
	simplescreenrecorder/AV/FastResampler.h \
	simplescreenrecorder/AV/FastResampler_FirFilter.h \
	simplescreenrecorder/AV/FastScaler.h \
	simplescreenrecorder/AV/FastScaler_Convert.h \
	simplescreenrecorder/AV/FastScaler_Scale.h \
	simplescreenrecorder/AV/FastScaler_Scale_Generic.h \
	simplescreenrecorder/AV/SampleCast.h \
	simplescreenrecorder/AV/SimpleSynth.h \
	simplescreenrecorder/AV/SourceSink.h \
	simplescreenrecorder/Common/CPUFeatures.h \
	simplescreenrecorder/Common/Dialogs.h \
	simplescreenrecorder/Common/EnumStrings.h \
	simplescreenrecorder/Common/LockFreeMessageQueue.h \
	simplescreenrecorder/Common/Logger.h \
	simplescreenrecorder/Common/MutexDataPair.h \
	simplescreenrecorder/Common/QueueBuffer.h \
	simplescreenrecorder/Common/TempBuffer.h \
	simplescreenrecorder/GUI/AudioPreviewer.h \
	simplescreenrecorder/GUI/DialogGLInject.h \
	simplescreenrecorder/GUI/ElidedLabel.h \
	simplescreenrecorder/GUI/HotkeyListener.h \
	simplescreenrecorder/GUI/Icons.h \
	simplescreenrecorder/GUI/MainWindow.h \
	simplescreenrecorder/GUI/PageDone.h \
	simplescreenrecorder/GUI/PageInput.h \
	simplescreenrecorder/GUI/PageOutput.h \
	simplescreenrecorder/GUI/PageRecord.h \
	simplescreenrecorder/GUI/PageWelcome.h \
	simplescreenrecorder/GUI/ProfileBox.h \
	simplescreenrecorder/GUI/VideoPreviewer.h \
	simplescreenrecorder/Benchmark.h \
	simplescreenrecorder/Global.h \
	simplescreenrecorder/Main.h \
	simplescreenrecorder/NVidia.h

SOURCES += \
	libelfhacks/elfhacks.c \
	libssr-glinject/GLInject.cpp \
	libssr-glinject/GLXFrameGrabber.cpp \
	libssr-glinject/Hook.cpp \
	libssr-glinject/SSRVideoStreamWriter.cpp \
	libssr-stream/ClientConnection.cpp \
	libssr-stream/Common.cpp \
	libssr-stream/FileDescriptor.cpp \
	libssr-stream/Server.cpp \
	libssr-stream/ServerConnection.cpp \
	libssr-stream/VideoFrame.cpp \
	simplescreenrecorder/AV/Input/ALSAInput.cpp \
	simplescreenrecorder/AV/Input/GLInjectInput.cpp \
	simplescreenrecorder/AV/Input/JACKInput.cpp \
	simplescreenrecorder/AV/Input/PulseAudioInput.cpp \
	simplescreenrecorder/AV/Input/X11Input.cpp \
	simplescreenrecorder/AV/Output/AudioEncoder.cpp \
	simplescreenrecorder/AV/Output/BaseEncoder.cpp \
	simplescreenrecorder/AV/Output/Muxer.cpp \
	simplescreenrecorder/AV/Output/OutputManager.cpp \
	simplescreenrecorder/AV/Output/SyncDiagram.cpp \
	simplescreenrecorder/AV/Output/Synchronizer.cpp \
	simplescreenrecorder/AV/Output/VideoEncoder.cpp \
	simplescreenrecorder/AV/Output/X264Presets.cpp \
	simplescreenrecorder/AV/AVWrapper.cpp \
	simplescreenrecorder/AV/FastResampler.cpp \
	simplescreenrecorder/AV/FastResampler_FirFilter_Fallback.cpp \
	simplescreenrecorder/AV/FastResampler_FirFilter_SSE2.cpp \
	simplescreenrecorder/AV/FastScaler.cpp \
	simplescreenrecorder/AV/FastScaler_Convert_Fallback.cpp \
	simplescreenrecorder/AV/FastScaler_Convert_SSSE3.cpp \
	simplescreenrecorder/AV/FastScaler_Scale_Fallback.cpp \
	simplescreenrecorder/AV/FastScaler_Scale_Generic.cpp \
	simplescreenrecorder/AV/FastScaler_Scale_SSSE3.cpp \
	simplescreenrecorder/AV/SimpleSynth.cpp \
	simplescreenrecorder/AV/SourceSink.cpp \
	simplescreenrecorder/Common/CPUFeatures.cpp \
	simplescreenrecorder/Common/Dialogs.cpp \
	simplescreenrecorder/Common/Logger.cpp \
	simplescreenrecorder/GUI/AudioPreviewer.cpp \
	simplescreenrecorder/GUI/DialogGLInject.cpp \
	simplescreenrecorder/GUI/ElidedLabel.cpp \
	simplescreenrecorder/GUI/HotkeyListener.cpp \
	simplescreenrecorder/GUI/Icons.cpp \
	simplescreenrecorder/GUI/MainWindow.cpp \
	simplescreenrecorder/GUI/PageDone.cpp \
	simplescreenrecorder/GUI/PageInput.cpp \
	simplescreenrecorder/GUI/PageOutput.cpp \
	simplescreenrecorder/GUI/PageRecord.cpp \
	simplescreenrecorder/GUI/PageWelcome.cpp \
	simplescreenrecorder/GUI/ProfileBox.cpp \
	simplescreenrecorder/GUI/VideoPreviewer.cpp \
	simplescreenrecorder/Benchmark.cpp \
	simplescreenrecorder/Main.cpp \
	simplescreenrecorder/NVidia.cpp

