# rules for finding the FFmpeg libraries

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_AVUTIL libavformat libavcodec libavutil libswscale)

find_path(AVUTIL_INCLUDE_DIR libavutil/avutil.h HINTS ${PC_AVUTIL_INCLUDEDIR} ${PC_AVUTIL_INCLUDE_DIRS})
find_library(AVUTIL_LIBRARY NAMES avutil HINTS ${PC_AVUTIL_LIBDIR} ${PC_AVUTIL_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AVUtil DEFAULT_MSG AVUTIL_LIBRARY AVUTIL_INCLUDE_DIR)

mark_as_advanced(AVUTIL_INCLUDE_DIR AVUTIL_LIBRARY)

set(AVUTIL_INCLUDE_DIRS ${AVUTIL_INCLUDE_DIR})
set(AVUTIL_LIBRARIES ${AVUTIL_LIBRARY})
