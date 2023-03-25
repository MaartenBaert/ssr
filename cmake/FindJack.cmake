# rules for finding the Jack library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_JACK jack)

find_path(JACK_INCLUDE_DIR jack/jack.h HINTS ${PC_JACK_INCLUDEDIR} ${PC_JACK_INCLUDE_DIRS})
find_library(JACK_LIBRARY NAMES jack HINTS ${PC_JACK_LIBDIR} ${PC_JACK_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Jack DEFAULT_MSG JACK_LIBRARY JACK_INCLUDE_DIR)

mark_as_advanced(JACK_INCLUDE_DIR JACK_LIBRARY)

set(JACK_INCLUDE_DIRS ${JACK_INCLUDE_DIR})
set(JACK_LIBRARIES ${JACK_LIBRARY})
