SimpleScreenRecorder
====================

A screen recorder for Linux. Despite the name, this program is actually quite complex. It's 'simple' in the sense that it's easier to use than ffmpeg/avconv or VLC :).

License
-------

GNU GPL v3 - read 'COPYING' for more info.

Build dependencies
------------------

This list may be incomplete. All instructions and package names are for Ubuntu 12.04/12.10/13.04, it could be different for other versions/distros.
- GCC and make (package build-essential)
- pkg-config (package pkg-config)
- Qt 4 (package qt4-qmake, libqt4-dev)
- libavformat (package libavformat-dev)
- libavcodec (package libavcodec-dev)
- libavutil (package libavutil-dev)
- libswscale (package libswscale-dev)
- ALSA library (package libasound2-dev)
- PulseAudio library (package libpulse-dev)
- libGL (32/64) (package libgl1-mesa-dev)
- libX11 (32/64) (package libx11-dev)
- libXext (package libxext-dev)
- libXfixes (package libxfixes-dev)
- 32-bit libraries (package g++-multilib, ia32-libs)

Everything combined:

    sudo apt-get install build-essential pkg-config qt4-qmake libqt4-dev libavformat-dev libavcodec-dev libavutil-dev libswscale-dev libasound2-dev libpulse-dev libgl1-mesa-dev libx11-dev libxext-dev libxfixes-dev g++-multilib ia32-libs

If the 32-bit version of some library isn't found, but 64-bit works fine, try this:

    cd /usr/lib/i386-linux-gnu/
    sudo ln -s libGL.so.1 mesa/libGL.so
    sudo ln -s mesa/libGL.so libGL.so
    sudo ln -s libGLU.so.1 libGLU.so
    sudo ln -s libX11.so.6 libX11.so
    sudo ln -s libXext.so.6 libXext.so
    sudo ln -s libXfixes.so.3 libXfixes.so
    sudo ldconfig

I don't know whether this is the right way to do it, but it works for me. If you are using a proprietary driver, the location of libGL will be different. In that case, use 'libGL.so' instead of 'mesa/libGL.so'.

Compiling and installing
------------------------

If you have installed SimpleScreenRecorder as a package from a repository, you should uninstall that version first to avoid conflicts. If you don't do this, the two versions may overwrite each other or use the wrong version of the GLInject library.

The simplest way to compile and install everything is to run:

    ./simple-build-and-install

This will compile the 64-bit main program and library, and then the 32-bit library. If the 32-bit build fails because libraries are missing, but 64-bit works fine, read the instructions above again :).

If you want to compile step-by-step, just run configure followed by make. It's a good idea to build in a separate directory, because you will need to build the library twice (32-bit and 64-bit). Look at the 'simple-build-and-install' script to see how this is done.

You don't need to install the program to use it, but installing will give you a desktop entry and an icon. Also, if you don't install the program, you will need to specify where the GLInject libraries are located with LD_LIBRARY_PATH when using OpenGL recording.

Other files you may want to read
--------------------------------

notes.txt contains notes about the design of the program. It's a good idea read this first if you want to make changes to the code.

todo.txt contains a list of things that I still need to do. This file changes a lot of course.
