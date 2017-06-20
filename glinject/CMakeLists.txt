
set(sources
    elfhacks.c
    GLInject.h
    SSRVideoStreamWriter.h
    Global.h
    GLXFrameGrabber.h
    Hook.cpp
    SSRVideoStreamWriter.cpp
    GLInject.cpp
    ShmStructs.h
    elfhacks.h
    GLXFrameGrabber.cpp

)

add_library(ssr-glinject SHARED ${sources})

install(TARGETS ssr-glinject LIBRARY DESTINATION ${PATH_LIBS})

if(ENABLE_32BIT_GLInject)
    add_library(ssr-glinject32 SHARED ${sources})

    install(TARGETS ssr-glinject32 LIBRARY DESTINATION ${PATH_LIBS})

    set_target_properties(ssr-glinject32 PROPERTIES COMPILE_FLAGS -m32)
endif()
