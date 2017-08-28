# rules for finding library PulseAudio

find_path(PULSEAUDIO_INCLUDE_DIR pulse/pulseaudio.h)
find_library(PULSEAUDIO_LIBRARY NAMES pulse)

set(PULSEAUDIO_LIBRARIES ${PULSEAUDIO_LIBRARY} )
set(PULSEAUDIO_INCLUDE_DIRS ${PULSEAUDIO_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PulseAudio DEFAULT_MSG PULSEAUDIO_LIBRARY PULSEAUDIO_INCLUDE_DIR)

mark_as_advanced(PULSEAUDIO_INCLUDE_DIR PULSEAUDIO_LIBRARY)
