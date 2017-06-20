
#rules for finding Jack library
find_path(JACK_INCLUDE_DIR jack/jack.h)
find_library(JACK_LIBRARY NAMES jack)

set(JACK_LIBRARIES ${JACK_LIBRARY} )
set(JACK_INCLUDE_DIRS ${JACK_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(JAck DEFAULT_MSG JACK_LIBRARY JACK_INCLUDE_DIR)

mark_as_advanced(JACK_INCLUDE_DIR JACK_LIBRARY)
