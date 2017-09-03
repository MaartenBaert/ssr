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

find_package(GNUInstallDirs REQUIRED)

# try to guess correct 32-bit library path on 64-bit systems
if(ENABLE_32BIT_GLINJECT)

	if(NOT DEFINED CMAKE_INSTALL_LIB32DIR)
		set(_LIB32DIR_DEFAULT "lib32")
		if(EXISTS "/etc/debian_version")
			if(EXISTS "/usr/lib/i386-linux-gnu")
				set(_LIB32DIR_DEFAULT "lib/i386-linux-gnu")
			elseif(EXISTS "/usr/lib/i686-linux-gnu")
				set(_LIB32DIR_DEFAULT "lib/i686-linux-gnu")
			else()
				message(WARNING "Could not find correct multiarch 32-bit library path, falling back to 'lib32'.")
			endif()
		endif()
		set(CMAKE_INSTALL_LIB32DIR "${_LIB32DIR_DEFAULT}" CACHE PATH "object code libraries, 32-bit (${_LIB32DIR_DEFAULT})")
	endif()
	
	mark_as_advanced(CMAKE_INSTALL_LIB32DIR)

	if(NOT IS_ABSOLUTE ${CMAKE_INSTALL_LIB32DIR})
		set(CMAKE_INSTALL_FULL_LIB32DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIB32DIR}")
	else()
		set(CMAKE_INSTALL_FULL_LIB32DIR "${CMAKE_INSTALL_LIB32DIR}")
	endif()

endif()

if(WITH_GLINJECT)

	add_subdirectory(glinject)

	install(
		FILES scripts/ssr-glinject
		DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
	)
	install(
		FILES data/man/ssr-glinject.man
		DESTINATION ${CMAKE_INSTALL_FULL_MANDIR}/man1
	)

endif()

if(WITH_SIMPLESCREENRECORDER)

	add_subdirectory(src)
	add_subdirectory(src/translations)

	install(
		DIRECTORY data/output-profiles
		DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/simplescreenrecorder
	)
	install(
		FILES data/man/simplescreenrecorder.man
		DESTINATION ${CMAKE_INSTALL_FULL_MANDIR}/man1
	)
	install(
		FILES data/simplescreenrecorder.desktop
		DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/applications
	)
	install(
		FILES data/simplescreenrecorder.appdata.xml
		DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/appdata
	)

endif()

# icons
set(icons_res 16 22 24 32 48 64 96 128 192 256)

foreach(res IN LISTS icons_res)
	install(
		DIRECTORY data/icons/${res}/
		DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/icons/hicolor/${res}x${res}/apps
	)
endforeach()

install(
	DIRECTORY data/icons/scalable/
	DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/icons/hicolor/scalable/apps
)
