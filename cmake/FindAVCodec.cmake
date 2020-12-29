# rules for finding the AVCodec library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_AVCODEC libavcodec)

find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h HINTS ${PC_AVCODEC_INCLUDEDIR} ${PC_AVCODEC_INCLUDE_DIRS})
find_library(AVCODEC_LIBRARY NAMES avcodec HINTS ${PC_AVCODEC_LIBDIR} ${PC_AVCODEC_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AVCodec DEFAULT_MSG AVCODEC_LIBRARY AVCODEC_INCLUDE_DIR)

mark_as_advanced(AVCODEC_INCLUDE_DIR AVCODEC_LIBRARY)

set(AVCODEC_INCLUDE_DIRS ${AVCODEC_INCLUDE_DIR})
set(AVCODEC_LIBRARIES ${AVCODEC_LIBRARY})
