find_package(ALSA REQUIRED)
find_package(AVCodec REQUIRED)
find_package(AVFormat REQUIRED)
find_package(AVUtil REQUIRED)
find_package(PulseAudio REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5X11Extras REQUIRED)
find_package(SWScale REQUIRED)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
find_package(XExtensions REQUIRED)

set(sources
	AV/Input/X11Input.cpp
	AV/Input/ALSAInput.cpp
	AV/Input/PulseAudioInput.h
	AV/Input/X11Input.h
	AV/Input/GLInjectInput.cpp
	AV/Input/GLInjectInput.h
	AV/Input/PulseAudioInput.cpp
	AV/Input/SSRVideoStreamWatcher.h
	AV/Input/JACKInput.h
	AV/Input/SSRVideoStreamReader.h
	AV/Input/SSRVideoStream.h
	AV/Input/SSRVideoStreamWatcher.cpp
	AV/Input/SSRVideoStreamReader.cpp
	AV/Input/ALSAInput.h
	AV/Input/JACKInput.cpp

	AV/Output/OutputManager.h
	AV/Output/SyncDiagram.cpp
	AV/Output/VideoEncoder.cpp
	AV/Output/Muxer.h
	AV/Output/BaseEncoder.h
	AV/Output/Muxer.cpp
	AV/Output/AudioEncoder.cpp
	AV/Output/BaseEncoder.cpp
	AV/Output/VideoEncoder.h
	AV/Output/SyncDiagram.h
	AV/Output/OutputManager.cpp
	AV/Output/Synchronizer.h
	AV/Output/X264Presets.h
	AV/Output/X264Presets.cpp
	AV/Output/Synchronizer.cpp
	AV/Output/AudioEncoder.h
	AV/Output/OutputSettings.h

	AV/AVWrapper.cpp
	AV/AVWrapper.h
	AV/FastScaler_Convert_SSSE3.cpp
	AV/FastScaler.cpp
	AV/FastResampler.h
	AV/FastScaler_Scale_Generic.cpp
	AV/FastScaler_Scale_Fallback.cpp
	AV/SourceSink.cpp
	AV/SimpleSynth.cpp
	AV/FastResampler_FirFilter_SSE2.cpp
	AV/FastScaler_Convert_Fallback.cpp
	AV/SourceSink.h
	AV/FastResampler_FirFilter_Fallback.cpp
	AV/FastScaler.h
	AV/FastResampler_FirFilter.h
	AV/FastScaler_Scale_Generic.h
	AV/FastResampler.cpp
	AV/SimpleSynth.h
	AV/FastScaler_Scale.h
	AV/FastScaler_Convert.h
	AV/FastScaler_Scale_SSSE3.cpp
	AV/SampleCast.h

	common/CPUFeatures.cpp
	common/CPUFeatures.h
	common/Dialogs.cpp
	common/Dialogs.h
	common/EnumStrings.h
	common/LockFreeMessageQueue.h
	common/Logger.cpp
	common/Logger.h
	common/MutexDataPair.h
	common/QueueBuffer.h
	common/TempBuffer.h

	GUI/AudioPreviewer.cpp
	GUI/PageInput.cpp
	GUI/DialogGLInject.h
	GUI/PageOutput.cpp
	GUI/HotkeyListener.cpp
	GUI/AudioPreviewer.h
	GUI/PageDone.cpp
	GUI/PageInput.h
	GUI/PageWelcome.h
	GUI/MainWindow.h
	GUI/VideoPreviewer.h
	GUI/MainWindow.cpp
	GUI/PageDone.h
	GUI/PageOutput.h
	GUI/DialogGLInject.cpp
	GUI/Icons.cpp
	GUI/PageRecord.h
	GUI/HotkeyListener.h
	GUI/ElidedLabel.cpp
	GUI/ElidedLabel.h
	GUI/PageWelcome.cpp
	GUI/Icons.h
	GUI/PageRecord.cpp
	GUI/ProfileBox.cpp
	GUI/VideoPreviewer.cpp
	GUI/ProfileBox.h

	Benchmark.cpp
	Benchmark.h
	Global.h
	Main.cpp
	Main.h
	NVidia.cpp
	NVidia.h
)

set(files_to_moc
	AV/Input/X11Input.h

	AV/Output/SyncDiagram.h

	GUI/PageInput.cpp
	GUI/DialogGLInject.h
	GUI/AudioPreviewer.h
	GUI/PageInput.h
	GUI/PageWelcome.h
	GUI/MainWindow.h
	GUI/VideoPreviewer.h
	GUI/PageDone.h
	GUI/PageOutput.h
	GUI/PageRecord.h
	GUI/HotkeyListener.h
	GUI/ElidedLabel.h
	GUI/ProfileBox.h

	common/Logger.h
)

qt5_wrap_cpp(moced_files ${files_to_moc})

set_source_files_properties(
	AV/FastResampler_FirFilter_SSE2.cpp
	PROPERTIES COMPILE_FLAGS -msse2
)

set_source_files_properties(
	AV/FastScaler_Convert_SSSE3.cpp
	AV/FastScaler_Scale_SSSE3.cpp
	PROPERTIES COMPILE_FLAGS -mssse3
)

add_executable(simplescreenrecorder
	${sources}
	${moced_files}
)

target_include_directories(simplescreenrecorder
	PRIVATE
	${ALSA_INCLUDE_DIRS}
	${AVCODEC_INCLUDE_DIRS}
	${AVFORMAT_INCLUDE_DIRS}
	${AVUTIL_INCLUDE_DIRS}
	${PULSEAUDIO_INCLUDE_DIRS}
	${Qt5Core_INCLUDE_DIRS}
	${Qt5Gui_INCLUDE_DIRS}
	${Qt5Widgets_INCLUDE_DIRS}
	${Qt5X11Extras_INCLUDE_DIRS}
	${SWSCALE_INCLUDE_DIRS}
	${X11_INCLUDE_DIR}
	${XEXTENSIONS_INCLUDE_DIR}

	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/AV
	${CMAKE_CURRENT_SOURCE_DIR}/AV/Input
	${CMAKE_CURRENT_SOURCE_DIR}/AV/Output
	${CMAKE_CURRENT_SOURCE_DIR}/common
	${CMAKE_CURRENT_SOURCE_DIR}/GUI
)

target_link_libraries(simplescreenrecorder
	PRIVATE
	${ALSA_LIBRARIES}
	${AVCODEC_LIBRARIES}
	${AVFORMAT_LIBRARIES}
	${AVUTIL_LIBRARIES}
	${PULSEAUDIO_LIBRARIES}
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	Qt5::X11Extras
	${CMAKE_THREAD_LIBS_INIT}
	${SWSCALE_LIBRARIES}
	${X11_LIBRARIES}
	${XEXTENSIONS_LIBRARIES}
)

target_compile_definitions(simplescreenrecorder
	PRIVATE
	-DSSR_USE_X86_ASM=$<BOOL:${ENABLE_X86_ASM}>
	-DSSR_USE_FFMPEG_VERSIONS=$<BOOL:${ENABLE_FFMPEG_VERSIONS}>
	-DSSR_USE_PULSEAUDIO=$<BOOL:${WITH_PULSEAUDIO}>
	-DSSR_USE_JACK=$<BOOL:${}>
	-DSSR_SYSTEM_DIR="${CMAKE_INSTALL_PREFIX}"
	-DPACKAGE_VERSION="${PROJECT_VERSION}"
)

install(TARGETS simplescreenrecorder RUNTIME DESTINATION ${PATH_BIN})
