
find_package(AVFormat REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5X11Extras REQUIRED)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)

option(ENABLE_X86_ASM "Allow x86/x64 assembly or intrinsics." TRUE)
option(ENABLE_FFMPEG_VERSIONS "Whether ffmpeg or libav version numbers should be used for tests. The ffmpeg version number is usually slightly higher, so that's the default (deprecation warnings are better than compilation errors)." TRUE)
option(WITH_PULSEAUDIO "Whether PulseAudio should be used." TRUE)
option(WITH_JACK "Whether JACK should be used." TRUE)

set(sources
        Benchmark.cpp
        Benchmark.h
        Global.h
        Main.cpp
        NVidia.cpp
        NVidia.h

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
        AV/SourceSink.h
        AV/FastResampler_FirFilter_Fallback.cpp
        AV/FastScaler.h
        AV/FastResampler_FirFilter.h
        AV/FastScaler_Scale_Generic.h
        AV/FastResampler.cpp
        AV/SimpleSynth.h
        AV/FastScaler_Scale.h
        AV/FastScaler_Convert.h
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
)

add_executable(simplescreenrecorder
                ${sources}
)

target_include_directories(simplescreenrecorder
                            PRIVATE
                                ${AVFORMAT_INCLUDE_DIRS}
                                ${Qt5Core_INCLIDE_DIRS}
                                ${Qt5Gui_INCLUDE_DIRS}
                                ${Qt5Widgets_INCLUDE_DIRS}
                                ${Qt5X11Extras_INCLUDE_DIRS}
                                ${X11_INCLUDE_DIR}

                                ${CMAKE_CURRENT_SOURCE_DIR}
                                ${CMAKE_CURRENT_SOURCE_DIR}/AV
                                ${CMAKE_CURRENT_SOURCE_DIR}/AV/Input
                                ${CMAKE_CURRENT_SOURCE_DIR}/AV/Output
                                ${CMAKE_CURRENT_SOURCE_DIR}/common
                                ${CMAKE_CURRENT_SOURCE_DIR}/GUI
)

target_link_libraries(simplescreenrecorder
                        PRIVATE
                            ${AVFORMAT_LIBRARIES}
                            Qt5::Core
                            Qt5::Gui
                            Qt5::Widgets
                            Qt5::X11Extras
                            ${CMAKE_THREAD_LIBS_INIT}
                            ${X11_LIBRARIES}
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
