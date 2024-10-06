# rules for finding the SPA library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_SPA libspa-0.2)

find_path(SPA_INCLUDE_DIR spa/param/props.h HINTS ${PC_SPA_INCLUDEDIR} ${PC_SPA_INCLUDE_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SPA DEFAULT_MSG SPA_INCLUDE_DIR)

mark_as_advanced(SPA_INCLUDE_DIR)

set(SPA_INCLUDE_DIRS ${SPA_INCLUDE_DIR})
