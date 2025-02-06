# rules for finding the SIMDE library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_SIMDE simde)

find_path(SIMDE_INCLUDE_DIR simde/x86/sse2.h simde/x86/ssse3.h HINTS ${PC_SIMDE_INCLUDEDIR} ${PC_SIMDE_INCLUDE_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SIMDE DEFAULT_MSG SIMDE_INCLUDE_DIR)

mark_as_advanced(SIMDE_INCLUDE_DIR)

set(SIMDE_INCLUDE_DIRS ${SIMDE_INCLUDE_DIR})
