SimpleScreenRecorder changes
============================

Git master
----------

- ?

Version 0.4.4
-------------

- Some minor improvements.
- Updated translations.
- Bugfixes.

Version 0.4.3
-------------

- Added V4L2 support (most webcams and capture cards).
- Added option to mark recorded area on screen during recording.
- Added JACK metadata.
- Optionally support XDG config directory (`~/.config/simplescreenrecorder`) instead of home directory (`~/.ssr`).
- Bugfixes.

Version 0.4.2
-------------

- Improved X11/Wayland detection.
- Changed ALSA input to use non-blocking API. This seems to reduce the latency in some cases.
- Added support for s24, s32 and f32 sample formats for ALSA input.
- Added 'open folder' button after saving the recording.
- Several minor improvements.

Version 0.4.1
-------------

- Added warning for Wayland users.
- Internal error messages from FFmpeg and other libraries are now shown in the log window.
- Fixed blocked continue button after selecting a window.

Version 0.4.0
-------------

- Added high-DPI monitor support.
- Added option to skip the welcome screen.
- Increased maximum video size to 20000x20000.
- Added more command-line options.
- Added recording schedule.
- Add command-line control over stdin.
- Many bugfixes.

Version 0.3.11
--------------

- Fixed FFmpeg 4.0 compatibility.
- Fixed AAC codec (missing channel layout).
- Improved build system.
- Minor bugfixes.

Version 0.3.10
--------------

- Custom recording frame to replace QRubberBand (important for Qt5).
- Improved build system.

Version 0.3.9
-------------

- Switched to CMake build system.
- Added RGB24 support.
- Automatically add scroll bars when the screen resolution is too low to display the complete window.
- Improved PulseAudio latency handling of monitors.
- Added a separate checkbox to enable timestamps.
- Provide a default file name, so now all options are set to a sensible default value.
- Use base-10 units for bitrate for consistency with FFmpeg (1 kbit/s = 1000 bit/s).
- Minor bugfixes.

Version 0.3.8
-------------

- Revert sample rate to 44.1 kHz for FLV container, since it does not support 48 kHz.

Version 0.3.7
-------------

- Added support for latest FFmpeg/libav.
- Make relaxed GLInject permissions actually work.
- The backend now supports fragmented recording, but there is no GUI for this yet.
- The default audio sample rate is now 48 kHz. This makes SSR compatible with Opus.
- System tray icon now indicates errors during recording.

Version 0.3.6
-------------

- Fixed another bug in YUV420 converter related to the previous one.

Version 0.3.5
-------------

- Fixed bug in YUV420 fallback converter introduced by refactoring.

Version 0.3.4
-------------

- Allowed user to start recording with hotkey or systray even when not on the recording page.
- Fixed JACK input bug that could cause deadlocks in rare cases.
- Added full support for NV12. If FFmpeg is compiled with NVENC support, this will allow you to use it.

Version 0.3.3
-------------

- Fixed mistake in configure.ac that was causing libssr-glinject.so to be linked with unwanted libraries.

Version 0.3.2
-------------

- Added Qt5 support (optional, Qt4 is still the default)
- Added YUV422, YUV444 and RGB support (YUV420 is still the default)
- Added pixelformat and sampleformat codec options.
- Added benchmark.
- Improved RTL support.
- Bugfixes

Version 0.3.1
-------------

- Small change to ssr-glinject script for improved compatibility with Steam.
- Added qscale option.
- Disabled PulseAudio latency estimation (apparently it made things worse).
- New muxing code for improved compatibility with the latest ffmpeg/libav.
- Switched to the BT.709 color space.

Version 0.3.0
-------------

- Added profile support.
- New, more flexible OpenGL recording system (glinject-next branch merged).
- More robust sound notifications.
- Show progress dialog while flushing the encoders.
- Improved hotkey support using XInput2.
- Improved synchronizer.
- Native support for mono microphones (plughw no longer needed).
- Added source detection for ALSA.
- Partially rewritten output backend.
- Improved mouse following algorithm.
- New icon.
- Bugfixes.

Version 0.2.2
-------------

- Bugfixes.

Version 0.2.1
-------------

- Bugfixes.

Version 0.2.0
-------------

- Added JACK support.
- Added fast audio resampler with drift correction support.
- Added translation support.
- Added sound notifications.
- Added much faster scaler.
- Added keyint custom codec option.
- Improved NVIDIA flipping dialog.
- Bugfixes.

Version 0.1.2
-------------

- Added minrate, maxrate and bufsize custom codec options.
- Bugfixes.

Version 0.1.1
-------------

- Bugfixes.

Version 0.1.0
-------------

- Native PulseAudio input.
- Show recording frame while entering x/y/width/height.
- Improved some GUI elements.
- Added system tray icon.
- Added custom video/audio codec options.
- Added workaround for PulseAudio-related glitches.
- Previewer works even when not recording.
- Don't show RTMP urls on the recording page.
- Added 'separate file per segment' option.
- Hotkey workaround for misbehaving applications in GLInject.
- Improved statistics and added external statistics file.
- Improved synchronizer.
- Added synchronization diagram for debugging.
- Optimizations.
- Bugfixes.

Version 0.0.7
-------------

- Improved streaming support.

Version 0.0.6
-------------

- Added link to Steam recording instructions for GLInject.

Version 0.0.5
-------------

- Detect and fix NVIDIA flipping issue.

Version 0.0.4
-------------

- Audio previewer is hidden if there is no audio.
- Bugfixes.

Version 0.0.3
-------------

- Added desktop entry.
- Switch from qmake to autotools.
- Bugfixes.

Version 0.0.2
-------------

- Added icon and welcome image.
- Bugfixes.

Version 0.0.1
-------------

- Native ALSA input to replace libavdevice.
- Improved synchronizer.
- Better audio codec support.
- GLInject can record the cursor.
- Added video and audio previewer.
- Added 'about' dialog.
- Many bugfixes.

Version 0.0.0
-------------

- First public version.
