# rules for finding the PipeWire library

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_PIPEWIRE libpipewire-0.3)

find_path(PIPEWIRE_INCLUDE_DIR pipewire/pipewire.h HINTS ${PC_PIPEWIRE_INCLUDEDIR} ${PC_PIPEWIRE_INCLUDE_DIRS})
find_library(PIPEWIRE_LIBRARY NAMES pipewire-0.3 HINTS ${PC_PIPEWIRE_LIBDIR} ${PC_PIPEWIRE_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PipeWire DEFAULT_MSG PIPEWIRE_LIBRARY PIPEWIRE_INCLUDE_DIR)

mark_as_advanced(PIPEWIRE_INCLUDE_DIR PIPEWIRE_LIBRARY)

set(PIPEWIRE_INCLUDE_DIRS ${PIPEWIRE_INCLUDE_DIR})
set(PIPEWIRE_LIBRARIES ${PIPEWIRE_LIBRARY})
