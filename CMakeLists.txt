
cmake_policy(SET CMP0048 NEW)

project(ssr VERSION 0.3.6)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(PATH_BIN       "bin")
set(PATH_LIBS      "lib")
set(PATH_TR        "share/simplescreenrecorder/translations")
set(PATH_DATA      "share")
set(PATH_APP       "${PATH_DATA}/applications")
set(PATH_PRIV_DATA "${PATH_DATA}/simplescreenrecorder")

add_subdirectory(glinject)
add_subdirectory(src)
add_subdirectory(src/translations)


install(DIRECTORY data/man DESTINATION ${PATH_DATA})
install(DIRECTORY data/output-profiles DESTINATION ${PATH_PRIV_DATA})
install(FILES     data/simplescreenrecorder.desktop DESTINATION ${PATH_APP})


#icons
set(icons_res 128  16  192  22  24  256  32  48  64  96)

foreach(res IN LISTS icons_res)

    install(DIRECTORY data/icons/${res}/
            DESTINATION ${PATH_DATA}/icons/hicolor/${res}x${res}/apps
    )

endforeach()

install(DIRECTORY data/icons/scalable/
        DESTINATION ${PATH_DATA}/icons/hicolor/scalable/apps
)
