SimpleScreenRecorder
====================

SimpleScreenRecorder is a screen recorder for Linux. Despite the name, this program is actually quite complex. It's 'simple' in the sense that it's easier to use than ffmpeg/avconv or VLC :).

There is a separate repository for SimpleScreenRecorder packages:
https://github.com/MaartenBaert/ssr-packages

License
-------

GNU GPL v3 - read 'COPYING' for more info.

Build dependencies
------------------

If you have a 64-bit system, you have to install some 32-bit libraries as well. These are required to compile the 32-bit SSR-GLInject library (which is needed to record 32-bit OpenGL applications).

You will need the following packages to compile SimpleScreenRecorder:

- GCC (>= 4.6) and make
- pkg-config
- Qt 4
- ffmpeg or libav (libavformat, libavcodec, libavutil, libswscale)
- ALSA library
- PulseAudio library (optional, disable with --without-pulseaudio)
- JACK library (optional, disable with --without-jack)
- libGL (32 and 64 bit)
- libGLU (32 and 64 bit)
- libX11 (32 and 64 bit)
- libXfixes (32 and 64 bit)
- libXext
- libXi

For Ubuntu 12.04 - 13.04:

    sudo apt-get install build-essential pkg-config qt4-qmake libqt4-dev libavformat-dev \
    libavcodec-dev libavutil-dev libswscale-dev libasound2-dev libpulse-dev libjack-jackd2-dev \
    libgl1-mesa-dev libglu1-mesa-dev libx11-dev libxfixes-dev libxext-dev libxi-dev g++-multilib ia32-libs

For Ubuntu 13.10 - 14.04:

    sudo apt-get install build-essential pkg-config qt4-qmake libqt4-dev libavformat-dev \
    libavcodec-dev libavutil-dev libswscale-dev libasound2-dev libpulse-dev libjack-jackd2-dev \
    libgl1-mesa-dev libglu1-mesa-dev libx11-dev libxfixes-dev libxext-dev libxi-dev g++-multilib \
    libx11-6:i386 libxfixes3:i386 libglu1-mesa:i386

If the 32-bit version of some library isn't found, but 64-bit works fine, try this:

    # if you are using open-source drivers:
    cd /usr/lib/i386-linux-gnu
    sudo ln -s libGL.so.1 mesa/libGL.so
    sudo ln -s mesa/libGL.so libGL.so
    sudo ln -s mesa/libGL.so.1 libGL.so.1
    
    # if you are using the proprietary AMD drivers:
    # first figure out where the fglrx directory is located,
    # this can be /usr/lib32 or /usr/lib/i386-linux-gnu
    cd /usr/lib/i386-linux-gnu
    sudo ln -s libGL.so.1 fglrx/libGL.so
    sudo ln -s fglrx/libGL.so libGL.so
    sudo ln -s fglrx/libGL.so.1 libGL.so.1
    
    # if you are using the proprietary NVIDIA drivers:
    # first figure out where the nvidia directory is located,
    # this can be /usr/lib32 or /usr/lib/i386-linux-gnu
    cd /usr/lib/i386-linux-gnu
    sudo ln -s libGL.so.1 nvidia*/libGL.so
    sudo ln -s nvidia*/libGL.so libGL.so
    sudo ln -s nvidia*/libGL.so.1 libGL.so.1
    
    # for all drivers:
    cd /usr/lib/i386-linux-gnu
    sudo ln -s libGLU.so.1 libGLU.so
    sudo ln -s libX11.so.6 libX11.so
    sudo ln -s libXext.so.6 libXext.so
    sudo ln -s libXfixes.so.3 libXfixes.so
    sudo ldconfig

I don't know whether this is the right way to do it, but it works for me. If you are using a combination of open-source and proprietary drivers (e.g. for laptops with Intel + NVIDIA GPUs a.k.a. 'Optimus'), follow only the steps for the open-source drivers.

For Debian:

    sudo dpkg --add-architecture i386
    sudo apt-get update
    sudo apt-get install build-essential pkg-config qt4-qmake libqt4-dev libavformat-dev \
    libavcodec-dev libavutil-dev libswscale-dev libasound2-dev libpulse-dev libjack-jackd2-dev \
    libgl1-mesa-dev libglu1-mesa-dev libx11-dev libxfixes-dev libxext-dev libxi-dev g++-multilib \
    libx11-6 libxext6 libxfixes3 libxfixes3:i386 libglu1-mesa:i386
    
    cd /usr/lib/i386-linux-gnu
    sudo ln -s libGL.so.1 libGL.so
    sudo ln -s libGLU.so.1 libGLU.so
    sudo ln -s libX11.so.6 libX11.so
    sudo ln -s libXext.so.6 libXext.so
    sudo ln -s libXfixes.so.3 libXfixes.so
    sudo ldconfig

For OpenSUSE (incomplete list but usually enough):

    sudo zypper install gcc gcc-32bit libffmpeg-devel libqt4-devel libpulse-devel libjack-devel \
    glu-devel glu-devel-32bit libX11-devel libX11-devel-32bit libXfixes-devel libXfixes-devel-32bit \
    libXext-devel libXi-devel libstdc++47-devel-32bit
    
    cd /usr/lib/i386-linux-gnu
    sudo ln -s libGLU.so.1 libGLU.so
    sudo ln -s libX11.so.6 libX11.so
    sudo ln -s libXext.so.6 libXext.so
    sudo ln -s libXfixes.so.3 libXfixes.so
    sudo ldconfig

Some packages (e.g. ffmpeg) are not in the official repository, but can be installed from the [Packman repository](http://packman.links2linux.org/). You can add the Packman repository with this command:

    zypper addrepo -f http://ftp.gwdg.de/pub/linux/packman/suse/12.3/ packman

For Fedora:

    sudo yum install ffmpeg-devel qt4-devel alsa-lib-devel pulseaudio-libs-devel jack-audio-connection-kit-devel \
    gcc make gcc-c++ glibc-devel.i686 libgcc.i686 libX11-devel.i686 libXfixes-devel.i686 mesa-libGL-devel.i686 \
    mesa-libGLU-devel.i686

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
