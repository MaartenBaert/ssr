SimpleScreenRecorder changes
============================

Git master
----------

- Allow user to start recording with hotkey or systray even when not on the recording page.
- Fixed JACK input bug that could cause deadlocks in rare cases.
- ?

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