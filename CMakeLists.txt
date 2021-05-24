cmake_minimum_required(VERSION 3.1)
cmake_policy(VERSION 3.1)

if(POLICY CMP0072)
	cmake_policy(SET CMP0072 NEW)
endif(POLICY CMP0072)

set(CMAKE_CXX_STANDARD 11)

project(simplescreenrecorder VERSION 0.4.4)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|i386|i686")
	set(PROCESSOR_IS_X86 TRUE)
else()
	set(PROCESSOR_IS_X86 FALSE)
endif()

option(ENABLE_32BIT_GLINJECT "Build the 32-bit version of 'libssr-glinject' on 64-bit systems (in addition to the 64-bit version). Required for OpenGL recording of 32-bit applications on 64-bit systems." FALSE)
option(ENABLE_X86_ASM "Allow x86/x64 assembly or intrinsics." ${PROCESSOR_IS_X86})
option(ENABLE_FFMPEG_VERSIONS "Use FFmpeg version numbers for feature support tests. Enable when using FFmpeg, disable when using Libav." TRUE)
option(ENABLE_JACK_METADATA "Use the JACK metadata API. May not work with very old JACK versions." TRUE)
option(WITH_OPENGL_RECORDING "Build with OpenGL recording support." TRUE)
option(WITH_V4L2 "Build with V4L2 support." TRUE)
option(WITH_ALSA "Build with ALSA support." TRUE)
option(WITH_PULSEAUDIO "Build with PulseAudio support." TRUE)
option(WITH_JACK "Build with JACK support." TRUE)
option(WITH_QT5 "Build with Qt5 (instead of Qt4)." FALSE)
option(WITH_SIMPLESCREENRECORDER "Build the 'simplescreenrecorder' executable." TRUE)
option(WITH_GLINJECT "Build the 'libssr-glinject' library. Required for OpenGL recording." TRUE)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(FeatureSummary)
include(GNUInstallDirs)

# try to guess the correct 32-bit library path on 64-bit systems
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

endif()

if(WITH_SIMPLESCREENRECORDER)

	add_subdirectory(src)
	add_subdirectory(src/translations)

	if(WITH_OPENGL_RECORDING)
		# the 'ssr-glinject' script is installed together with the main SSR executable to avoid problems with multiarch packages
		install(
			FILES scripts/ssr-glinject
			DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
			PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
		)
	endif()
	install(
		DIRECTORY data/output-profiles
		DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/simplescreenrecorder
	)
	install(
		DIRECTORY data/man/
		DESTINATION ${CMAKE_INSTALL_FULL_MANDIR}/man1
	)
	install(
		FILES data/simplescreenrecorder.desktop
		DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/applications
	)
	install(
		FILES data/simplescreenrecorder.metainfo.xml
		DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/metainfo
	)

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

endif()

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
