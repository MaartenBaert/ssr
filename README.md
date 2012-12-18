SimpleScreenRecorder
====================

A screen recorder for Linux. Despite the name, this program is actually quite complex. It's 'simple' in the sense that it's easier to use than ffmpeg/avconv or VLC :).

License
-------
GNU GPL v3 - read 'COPYING' for more info.

Build dependencies
------------------

This list may be incomplete. All instructions and package names are for Ubuntu 12.10, it could be different for other versions/distros.
- Qt (package qt4-qmake)
- libavformat (package libavformat-dev)
- libavcodec (package libavcodec-dev)
- libavdevice (package libavdevice-dev)
- libavutil (package libavutil-dev)
- libswscale (package libswscale-dev)
- libGL (32/64) (package libgl1-mesa-dev)
- libX11 (32/64) (package libx11-dev)
- libXext (package libxext-dev)
- libXfixes (package libxfixes-dev)

To compile the 32-bit GLInject library, you will also need g++-multilib and ia32-libs.
If the 32-bit version of libGL and libX11 isn't found during linking, but 64-bit works fine, try this:
    cd /usr/lib/i386-linux-gnu/
    sudo ln -s libGL.so.1.2.0 mesa/libGL.so       (replace 1.2.0 with the highest version you have)
    sudo ln -s mesa/libGL.so libGL.so
    sudo ln -s libX11.so.6 libX11.so
I don't know whether this is the right way to do it, but it works for me.

Compiling
---------

First compile GLInject. Go to the glinject directory and run both 'compile32' and 'compile64'.

For now, I recommend using Qt Creator to compile the main program. Running 'qmake' followed by 'make' should work too I think, but I haven't tested it.

Other files you may want to read
--------------------------------

notes.txt contains notes about the design of the program. It's a good idea read this first if you want to make changes to the code.

todo.txt contains a list of things that I still need to do. This file changes a lot of course.
