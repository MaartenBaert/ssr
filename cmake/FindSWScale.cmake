# rules for finding the FFmpeg libraries

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_SWSCALE libavformat libavcodec libavutil libswscale)

find_path(SWSCALE_INCLUDE_DIR libswscale/swscale.h HINTS ${PC_SWSCALE_INCLUDEDIR} ${PC_SWSCALE_INCLUDE_DIRS})
find_library(SWSCALE_LIBRARY NAMES swscale HINTS ${PC_SWSCALE_LIBDIR} ${PC_SWSCALE_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SWScale DEFAULT_MSG SWSCALE_LIBRARY SWSCALE_INCLUDE_DIR)

mark_as_advanced(SWSCALE_INCLUDE_DIR SWSCALE_LIBRARY)

set(SWSCALE_INCLUDE_DIRS ${SWSCALE_INCLUDE_DIR})
set(SWSCALE_LIBRARIES ${SWSCALE_LIBRARY})
