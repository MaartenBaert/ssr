
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

#target_include_directories(glinject)

#target_link_libraries(glinject)

#target_compile_definitions(glinject)

