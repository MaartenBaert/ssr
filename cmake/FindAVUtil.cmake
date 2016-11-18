
#rules for finding library AVUtil
find_path(AVUTIL_INCLUDE_DIR libavutil/avutil.h)
find_library(AVUTIL_LIBRARY NAMES avutil)

set(AVUTIL_LIBRARIES ${AVUTIL_LIBRARY} )
set(AVUTIL_INCLUDE_DIRS ${AVUTIL_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AVUtil DEFAULT_MSG AVUTIL_LIBRARY AVUTIL_INCLUDE_DIR)

mark_as_advanced(AVUTIL_INCLUDE_DIR AVUTIL_LIBRARY)
