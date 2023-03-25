# rules for finding the AVFormat library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_AVFORMAT libavformat)

find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h HINTS ${PC_AVFORMAT_INCLUDEDIR} ${PC_AVFORMAT_INCLUDE_DIRS})
find_library(AVFORMAT_LIBRARY NAMES avformat HINTS ${PC_AVFORMAT_LIBDIR} ${PC_AVFORMAT_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AVFormat DEFAULT_MSG AVFORMAT_LIBRARY AVFORMAT_INCLUDE_DIR)

mark_as_advanced(AVFORMAT_INCLUDE_DIR AVFORMAT_LIBRARY)

set(AVFORMAT_INCLUDE_DIRS ${AVFORMAT_INCLUDE_DIR})
set(AVFORMAT_LIBRARIES ${AVFORMAT_LIBRARY})
