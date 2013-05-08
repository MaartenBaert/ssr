SimpleScreenRecorder
====================

A screen recorder for Linux. Despite the name, this program is actually quite complex. It's 'simple' in the sense that it's easier to use than ffmpeg/avconv or VLC :).

License
-------

GNU GPL v3 - read 'COPYING' for more info.

Build dependencies
------------------

This list may be incomplete. All instructions and package names are for Ubuntu 12.10, it could be different for other versions/distros.
- Qt 4 (package qt4-qmake, libqt4-dev)
- libavformat (package libavformat-dev)
- libavcodec (package libavcodec-dev)
- libavutil (package libavutil-dev)
- libswscale (package libswscale-dev)
- ALSA library  (package libasound2-dev)
- libGL (32/64) (package libgl1-mesa-dev)
- libX11 (32/64) (package libx11-dev)
- libXext (package libxext-dev)
- libXfixes (package libxfixes-dev)
- 32-bit libraries (package g++-multilib, ia32-libs)

Everything combined:

    sudo apt-get install qt4-qmake libqt4-dev libavformat-dev libavcodec-dev libavutil-dev libswscale-dev libasound2-dev libgl1-mesa-dev libx11-dev libxext-dev libxfixes-dev g++-multilib ia32-libs

If the 32-bit version of libGL and libX11 isn't found during linking, but 64-bit works fine, try this:

    cd /usr/lib/i386-linux-gnu/
    sudo ln -s libGL.so.1 mesa/libGL.so
    sudo ln -s mesa/libGL.so libGL.so
    sudo ln -s libX11.so.6 libX11.so
    sudo ln -s libXfixes.so.3 libXfixes.so
    sudo ldconfig

I don't know whether this is the right way to do it, but it works for me.

Compiling
---------

To compile everything, just run:

    ./compile

This will first compile GLInject for 32-bit and 64-bit. If 32-bit fails because libraries are missing, but 64-bit works fine, read the instructions above again :). After GLInject has been compiled, it will run the pre-build script, then qmake, then make.

You can also use Qt Creator if you want. Just run all the commands in the 'compile' script except qmake and make, then open the .pro file in Qt Creator and compile it.

Other files you may want to read
--------------------------------

notes.txt contains notes about the design of the program. It's a good idea read this first if you want to make changes to the code.

todo.txt contains a list of things that I still need to do. This file changes a lot of course.
