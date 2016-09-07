
option(ENABLE_32BIT_GLInject "Build 32 bit version of GLInject." FALSE)

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

add_library(glinject SHARED ${sources})

install(TARGETS glinject LIBRARY DESTINATION ${PATH_LIBS})

if(ENABLE_32BIT_GLInject)
    add_library(glinject32 SHARED ${sources})

    install(TARGETS glinject32 LIBRARY DESTINATION ${PATH_LIBS})

    set_target_properties(glinject32 PROPERTIES COMPILE_FLAGS -m32)
endif()
