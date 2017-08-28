# 'libssr-glinject' library

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

add_library(ssr-glinject SHARED ${sources})

install(TARGETS ssr-glinject LIBRARY DESTINATION ${PATH_LIBS})

if(ENABLE_32BIT_GLINJECT)

	add_library(ssr-glinject32 SHARED ${sources})

	install(TARGETS ssr-glinject32 LIBRARY DESTINATION ${PATH_LIBS})

	set_target_properties(ssr-glinject32 PROPERTIES COMPILE_FLAGS -m32)

endif()
