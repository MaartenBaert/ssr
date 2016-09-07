
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

if(ENABLE_32BIT_GLInject)
    add_library(glinject32 SHARED ${sources})

    set_target_properties(glinject32 PROPERTIES COMPILE_FLAGS -m32)
endif()
