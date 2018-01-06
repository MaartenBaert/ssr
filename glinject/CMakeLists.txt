# 'libssr-glinject' library

find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
find_package(OpenGL REQUIRED)

set(sources
	elfhacks.c
	elfhacks.h
	GLInject.cpp
	GLInject.h
	Global.h
	GLXFrameGrabber.cpp
	GLXFrameGrabber.h
	Hook.cpp
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

add_library(ssr-glinject SHARED ${sources})
target_include_directories(ssr-glinject PRIVATE ${include_directories})
target_link_libraries(ssr-glinject PRIVATE ${link_libraries})
install(TARGETS ssr-glinject LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})

if(ENABLE_32BIT_GLINJECT)

	add_library(ssr-glinject32 SHARED ${sources})
	target_include_directories(ssr-glinject32 PRIVATE ${include_directories})
	target_link_libraries(ssr-glinject32 PRIVATE ${link_libraries})
	install(TARGETS ssr-glinject32 LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIB32DIR})

	set_target_properties(ssr-glinject32 PROPERTIES COMPILE_FLAGS -m32 LINK_FLAGS -m32)
	set_target_properties(ssr-glinject32 PROPERTIES OUTPUT_NAME ssr-glinject LIBRARY_OUTPUT_DIRECTORY "lib32")

endif()
