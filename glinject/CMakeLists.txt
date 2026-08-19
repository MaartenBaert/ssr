# 'libssr-glinject' library

find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
find_package(OpenGL REQUIRED)

set(sources
	GLInject.cpp
	GLInject.h
	Global.h
	GLXFrameGrabber.cpp
	GLXFrameGrabber.h
	Hook.cpp
	plthook_elf.c
	plthook.h
	ShmStructs.h
	SSRVideoStreamWriter.cpp
	SSRVideoStreamWriter.h
)

set(include_directories
	${X11_X11_INCLUDE_PATH}
	${X11_Xfixes_INCLUDE_PATH}
	${OPENGL_INCLUDE_DIR}
)

set(link_libraries
	${CMAKE_THREAD_LIBS_INIT}
	${X11_X11_LIB}
	${X11_Xfixes_LIB}
	${OPENGL_LIBRARIES}
	-lrt
	${CMAKE_DL_LIBS}
)

get_filename_component(X11_X11_LIB_file ${X11_X11_LIB} NAME)
get_filename_component(X11_Xfixes_LIB_file ${X11_Xfixes_LIB} NAME)

set(OPENGL_LIBRARIES_files "")
foreach(path IN LISTS OPENGL_LIBRARIES)
	get_filename_component(name "${OPENGL_LIBRARIES}" NAME)
	list(APPEND OPENGL_LIBRARIES_files "${name}")
endforeach()

set(link_libraries_32bit
	${CMAKE_THREAD_LIBS_INIT}
	${X11_X11_LIB_file}
	${X11_Xfixes_LIB_file}
	${OPENGL_LIBRARIES_files}
	-lrt
	${CMAKE_DL_LIBS}
)

add_library(ssr-glinject SHARED ${sources})
target_include_directories(ssr-glinject PRIVATE ${include_directories})
target_link_libraries(ssr-glinject PRIVATE ${link_libraries})
install(TARGETS ssr-glinject LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})

if(ENABLE_32BIT_GLINJECT)

	add_library(ssr-glinject32 SHARED ${sources})
	target_include_directories(ssr-glinject32 PRIVATE ${include_directories})
	target_link_libraries(ssr-glinject32 PRIVATE ${link_libraries_32bit})
	install(TARGETS ssr-glinject32 LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIB32DIR})

	set_target_properties(ssr-glinject32 PROPERTIES COMPILE_FLAGS -m32 LINK_FLAGS -m32)
	set_target_properties(ssr-glinject32 PROPERTIES COMPILE_FLAGS -m64 LINK_FLAGS -m64)
	set_target_properties(ssr-glinject32 PROPERTIES OUTPUT_NAME ssr-glinject LIBRARY_OUTPUT_DIRECTORY "lib32")

endif()
