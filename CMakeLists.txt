cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)

project(simplescreenrecorder VERSION 0.3.8)

option(ENABLE_32BIT_GLINJECT "Build the 32-bit version of 'libssr-glinject' on 64-bit systems (in addition to the 64-bit version). Required for OpenGL recording of 32-bit applications on 64-bit systems." FALSE)
option(ENABLE_X86_ASM "Allow x86/x64 assembly or intrinsics." TRUE)
option(ENABLE_FFMPEG_VERSIONS "Use FFmpeg version numbers for feature support tests. Enable when using FFmpeg, disable when using Libav." TRUE)
option(WITH_PULSEAUDIO "Build with PulseAudio support." TRUE)
option(WITH_JACK "Build with JACK support." TRUE)
option(WITH_QT5 "Build with Qt5 (instead of Qt4)." FALSE)
option(WITH_SIMPLESCREENRECORDER "Build the 'simplescreenrecorder' executable." TRUE)
option(WITH_GLINJECT "Build the 'libssr-glinject' library. Required for OpenGL recording." TRUE)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(PATH_BIN "bin")
set(PATH_LIBS "lib")
set(PATH_DATA "share")
set(PATH_APP "${PATH_DATA}/applications")
set(PATH_PRIV_DATA "${PATH_DATA}/simplescreenrecorder")
set(PATH_TR "${PATH_PRIV_DATA}/translations")

if(WITH_GLINJECT)
	add_subdirectory(glinject)
endif()

if(WITH_SIMPLESCREENRECORDER)
	add_subdirectory(src)
	add_subdirectory(src/translations)
endif()

install(
	DIRECTORY data/man
	DESTINATION ${PATH_DATA}/man/man1
)
install(
	DIRECTORY data/output-profiles
	DESTINATION ${PATH_PRIV_DATA}
)
install(
	FILES data/simplescreenrecorder.desktop
	DESTINATION ${PATH_APP}
)

# icons
set(icons_res 16 22 24 32 48 64 96 128 192 256)

foreach(res IN LISTS icons_res)
	install(
		DIRECTORY data/icons/${res}
		DESTINATION ${PATH_DATA}/icons/hicolor/${res}x${res}/apps
	)
endforeach()

install(
	DIRECTORY data/icons/scalable/
	DESTINATION ${PATH_DATA}/icons/hicolor/scalable/apps
)
