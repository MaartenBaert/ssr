# rules for finding the V4L2 library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_V4L2 libv4l2)

find_path(V4L2_INCLUDE_DIR libv4l2.h HINTS ${PC_V4L2_INCLUDEDIR} ${PC_V4L2_INCLUDE_DIRS})
find_library(V4L2_LIBRARY NAMES v4l2 HINTS ${PC_V4L2_LIBDIR} ${PC_V4L2_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(V4L2 DEFAULT_MSG V4L2_LIBRARY V4L2_INCLUDE_DIR)

mark_as_advanced(V4L2_INCLUDE_DIR V4L2_LIBRARY)

set(V4L2_INCLUDE_DIRS ${V4L2_INCLUDE_DIR})
set(V4L2_LIBRARIES ${V4L2_LIBRARY})
