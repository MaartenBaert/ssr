
cmake_policy(SET CMP0048 NEW)

project(ssr VERSION 0.3.6)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(PATH_TR ${CMAKE_INSTALL_PREFIX}/share/simplescreenrecorder/translations)

add_subdirectory(glinject)
add_subdirectory(src)
add_subdirectory(src/translations)
