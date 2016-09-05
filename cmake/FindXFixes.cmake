
#rules for finding library XFixes
find_path(XFIXES_INCLUDE_DIR X11/extensions/Xfixes.h)
find_library(XFIXES_LIBRARY NAMES Xfixes)

set(XFIXES_LIBRARIES ${XFIXES_LIBRARY} )
set(XFIXES_INCLUDE_DIRS ${XFIXES_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(XFixes DEFAULT_MSG XFIXES_LIBRARY XFIXES_INCLUDE_DIR)

mark_as_advanced(XFIXES_INCLUDE_DIR XFIXES_LIBRARY)
