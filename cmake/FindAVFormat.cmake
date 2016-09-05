
#rules for finding library AVFormat
find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h)
find_library(AVFORMAT_LIBRARY NAMES avformat)

set(AVFORMAT_LIBRARIES ${AVFORMAT_LIBRARY} )
set(AVFORMAT_INCLUDE_DIRS ${AVFORMAT_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AVFormat DEFAULT_MSG AVFORMAT_LIBRARY AVFORMAT_INCLUDE_DIR)

mark_as_advanced(AVFORMAT_INCLUDE_DIR AVFORMAT_LIBRARY)
