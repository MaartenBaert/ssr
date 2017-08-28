# rules for finding library AVCodec

find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h)
find_library(AVCODEC_LIBRARY NAMES avcodec)

set(AVCODEC_LIBRARIES ${AVCODEC_LIBRARY} )
set(AVCODEC_INCLUDE_DIRS ${AVCODEC_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AVCodec DEFAULT_MSG AVCODEC_LIBRARY AVCODEC_INCLUDE_DIR)

mark_as_advanced(AVCODEC_INCLUDE_DIR AVCODEC_LIBRARY)
