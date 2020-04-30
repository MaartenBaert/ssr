<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="zh_CN">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>About SimpleScreenRecorder</source>
        <translation>关于SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="120"/>
        <source>For more information:</source>
        <translation>更多信息：</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="121"/>
        <source>The source code of this program can be found at:</source>
        <translation>程序源码见：</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="122"/>
        <source>This program uses:</source>
        <translation>程序使用了：</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="123"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 用于图形用户界面</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="124"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 或者 %2 （取决于您使用的发行版）用于视频/音频编码</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="125"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 用于挂钩系统函数来为OpenGL录制</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="35"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL设置</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="38"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;警告：OpenGL录制需要将库加载到录制的目标，此库会把一些系统函数替换掉以用来捕获目标程序在窗口显示前的帧。如果你试图录制会在本地检测外挂的游戏，（理论上）游戏会将此行为当作作弊，可能导致您被封锁。因此，在录制前请先确认目标会不会将您封锁。&lt;/p&gt;
&lt;p&gt;再次警告：OpenGL录制处于实验性阶段，可能用不了甚至会导致目标程序崩溃。如果外您担心数据丢失，请先做好备份！&lt;/p&gt;
&lt;p&gt;如果您想录制Steam游戏，&lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;请先阅读这个&lt;/a&gt;。&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="52"/>
        <source>Choose channel</source>
        <translation>选择通道</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="54"/>
        <source>Channel name:</source>
        <translation>通道名称：</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="56"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>通道名称是用来区分不同的应用程序。在您需要同时录制不同的应用程序时才需要设置。
如果留空，则使用默认的名称”通道-您的用户名“。</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="74"/>
        <source>Launch application</source>
        <translation>启动应用程序</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="76"/>
        <source>Command:</source>
        <translation>命令：</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="78"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>此命令将会启动将要被录制的目标程序。</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="80"/>
        <source>Working directory:</source>
        <translation>工作目录：</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="82"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>此命令将会在此目录执行，如果您留空，工作目录将不会改变。</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>Launch automatically</source>
        <translation>自动启动</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="85"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>如果勾选，目标应用程序将在您切换到录制页面时自动启动；否则您需要手动启动。</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="87"/>
        <source>Launch now</source>
        <translation>立即启动</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="108"/>
        <source>Stream settings</source>
        <translation>流设置</translation>
    </message>
    <message>
        <source>Source:</source>
        <translation type="obsolete">源：</translation>
    </message>
    <message>
        <source>Start the OpenGL application automatically</source>
        <translation type="obsolete">自动运行OpenGL应用程序</translation>
    </message>
    <message>
        <source>If checked, the above command will be executed automatically (combined with some environment variables). If not checked,
you have to start the OpenGL application yourself (the full command, including the required environment variables, is shown in the log).</source>
        <translation type="obsolete">如果选中，上述命令将会自动执行（结合当前环境变量）。如果不选，您得自行运行OpenGL应用程序（完整的命令，包括在日志显示需要的环境变量）。</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>放松共享内存的权限（不安全）</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>如果选中，其他本机用户将可以访问到用于跟OpenGL程序通信的共享内存，（理论上）这意味着其他用户可以知道您在录制什么、修改帧、加入他们的帧或者断开通信，甚至是通过ssh远程登陆的用户也可以。您应只在录制以不同用户身份执行的目标程序时选中此选项。</translation>
    </message>
    <message>
        <source>Maximum image size (megapixels):</source>
        <translation type="obsolete">最大图像大小（百万像素）：</translation>
    </message>
    <message>
        <source>This setting changes the amount of shared memory that will be allocated to send frames back to the main program.
The size of the shared memory can&apos;t be changed anymore once the program has been started, so if the program you
are trying to record is too large, recording won&apos;t work. 2 megapixels should be enough in almost all cases. Be careful,
high values will use a lot of memory!</source>
        <translation type="obsolete">此设置会改变将帧发送到主程序的共享内存大小，程序一旦启动您将不能再更改其大小。因此，如果您录制的目标程序过大，录制将会失败。通常情况下，200万像素足够了，但请注意，值越大占用的内存将越大！</translation>
    </message>
    <message>
        <source>Capture front buffer instead of back buffer</source>
        <translation type="obsolete">捕获前端缓冲而不是后端缓冲</translation>
    </message>
    <message>
        <source>If checked, the injected library will read the front buffer (the frame that&apos;s currently on the screen) rather than the back buffer
(the new frame). This may be useful for some special applications that draw directly to the screen.</source>
        <translation type="obsolete">如果选中，注入的库将会读取前端缓冲（当前屏幕帧）而不是后端缓冲（新帧）。这对于那些直接绘制到屏幕的程序来说是非常有用的。</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>Limit application frame rate</source>
        <translation>限制应用程序帧率</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="111"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>如果选中，注入的库将会使目标程序帧率下降使其不高于录制的帧率，这会减少录制CPU占用时间并且使得录制的视频较流畅（这还得取决于目标程序）。</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="120"/>
        <source>Close</source>
        <translation>关闭</translation>
    </message>
</context>
<context>
    <name>DialogRecordSchedule</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="78"/>
        <source>Recording schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="80"/>
        <source>Time zone:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="82"/>
        <source>Local time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="83"/>
        <source>UTC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="85"/>
        <source>Current time:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="102"/>
        <source>Add</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="103"/>
        <source>Remove</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="104"/>
        <source>Move up</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="105"/>
        <source>Move down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="107"/>
        <source>Close</source>
        <translation type="unfinished">关闭</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="129"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="138"/>
        <location filename="../Benchmark.cpp" line="124"/>
        <location filename="../Benchmark.cpp" line="205"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="160"/>
        <location filename="../AV/FastScaler.cpp" line="185"/>
        <location filename="../AV/FastScaler.cpp" line="210"/>
        <location filename="../AV/FastScaler.cpp" line="234"/>
        <location filename="../AV/FastScaler.cpp" line="256"/>
        <location filename="../AV/FastScaler.cpp" line="279"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="33"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="39"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="67"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="55"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="97"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="176"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="182"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="163"/>
        <source>Found plugin: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="186"/>
        <source>Found card: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="211"/>
        <source>Found device: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="260"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="264"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="270"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="276"/>
        <location filename="../AV/SimpleSynth.cpp" line="140"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="283"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="287"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="296"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="300"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="309"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="313"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="322"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="326"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="352"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="237"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/X11Input.cpp" line="439"/>
        <source>Input thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="388"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="414"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="358"/>
        <location filename="../AV/Input/JACKInput.cpp" line="288"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/X11Input.cpp" line="554"/>
        <source>Input thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="418"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="362"/>
        <location filename="../AV/Input/JACKInput.cpp" line="292"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/X11Input.cpp" line="558"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="421"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="365"/>
        <location filename="../AV/Input/JACKInput.cpp" line="295"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/X11Input.cpp" line="561"/>
        <source>Unknown exception in input thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="310"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="315"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="71"/>
        <source>Error: Could not connect to JACK!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="80"/>
        <source>Error: Could not create JACK port!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="86"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="90"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="94"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="98"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="103"/>
        <source>Error: Could not activate JACK client!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="111"/>
        <location filename="../AV/Input/JACKInput.cpp" line="122"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <source>Connecting port %1 to %2.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="255"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="34"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="38"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="42"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="52"/>
        <source>Error: Could not create main loop!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="59"/>
        <source>Error: Could not create context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="68"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="82"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="119"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="126"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="137"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="228"/>
        <source>Found source: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="249"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="297"/>
        <source>Error: Could not get source info! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="302"/>
        <source>Stream is a monitor.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="304"/>
        <source>Stream is not a monitor.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="349"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="416"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="421"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="70"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="96"/>
        <source>Error: Width or height is zero!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="100"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="249"/>
        <location filename="../GUI/HotkeyListener.cpp" line="115"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Using X11 shared memory.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="305"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="260"/>
        <source>Not using X11 shared memory.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="267"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="363"/>
        <source>Warning: Xinerama is not supported by X server, multi-monitor support may not work properly.</source>
        <comment>Don&apos;t translate &apos;Xinerama&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="369"/>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="388"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="320"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="505"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="516"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="172"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="100"/>
        <source>Error: Channel count is zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="104"/>
        <source>Error: Sample rate is zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="142"/>
        <source>Using sample format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="147"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <source>Error: Sending of audio frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Receiving of audio packet failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="210"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="232"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="267"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="277"/>
        <source>Using codec %1 (%2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="320"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="30"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="39"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="164"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="188"/>
        <source>Encoder thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="217"/>
        <source>Flushing encoder ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="228"/>
        <source>Encoder thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="235"/>
        <source>Unknown exception in encoder thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="70"/>
        <source>Stopping encoders ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="77"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="146"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="157"/>
        <source>Finishing encoders ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="288"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="307"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <location filename="../AV/Output/Muxer.cpp" line="124"/>
        <source>Error: Can&apos;t copy parameters to stream!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Using format %1 (%2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="209"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="229"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="295"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="336"/>
        <source>Muxer thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="396"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="424"/>
        <source>Muxer thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="428"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="431"/>
        <source>Unknown exception in muxer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="220"/>
        <source>Stopping synchronizer thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="328"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="355"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="412"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="437"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="443"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="509"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="513"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="548"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="584"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="885"/>
        <source>Synchronizer thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="907"/>
        <source>Synchronizer thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="911"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="914"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="104"/>
        <source>Error: Width or height is not an even number!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="108"/>
        <source>Error: Frame rate is zero!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="165"/>
        <source>Using pixel format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="179"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="207"/>
        <source>Error: Sending of video frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="228"/>
        <source>Error: Receiving of video packet failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="241"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="262"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="41"/>
        <source>Using real-time priority.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="51"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="64"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="91"/>
        <source>Stopping synth thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="224"/>
        <source>Synth thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="277"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="285"/>
        <source>Synth thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="289"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="292"/>
        <source>Unknown exception in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="45"/>
        <source>CPU features</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="78"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="86"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="179"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="187"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="96"/>
        <source>SSR started</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="127"/>
        <source>SSR stopped</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="228"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="259"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="94"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="102"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="106"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="111"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="116"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="126"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>The application could not be launched.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="161"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="165"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="243"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="253"/>
        <source>Starting scaler benchmark ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="260"/>
        <source>Starting converter benchmark ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="70"/>
        <source>Stopping fragment thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="346"/>
        <source>Fragment thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="364"/>
        <source>Next fragment ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="368"/>
        <source>Finishing ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="380"/>
        <source>Fragment thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="384"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="387"/>
        <source>Unknown exception in fragment thread.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="78"/>
        <source>You are using a non-X11 window system (e.g. Wayland) which is currently not supported by SimpleScreenRecorder. Several features will most likely not work properly. In order to solve this, you should log out, choose a X11/Xorg session at the login screen, and then log back in.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="90"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder检测到您正在使用NVIDIA闭源驱动且开启了flipping功能，这会导致录制不稳定，建议您禁用它。您想要禁用吗？
您也可以在NVIDIA控制面板手动更改它。</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="108"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>非常抱歉，无法禁用flipping功能，请您尝试在NVIDIA面板禁用。</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>录像已保存，你可以现在编辑录像或者更改设置重新编码以减少体积（默认设置为优化质量和速度，并非文件大小）。</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>返回开始页面</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Video input</source>
        <translation>视频输入</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>Record the entire screen</source>
        <translation>录制整个屏幕</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="247"/>
        <source>Record a fixed rectangle</source>
        <translation>录制固定的区域</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="248"/>
        <source>Follow the cursor</source>
        <translation>跟随鼠标</translation>
    </message>
    <message>
        <source>Record OpenGL (experimental)</source>
        <translation type="obsolete">录制OpenGL（实验性）</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="259"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>选择需要录制的显示器。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>Record entire screen with cursor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="261"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <source>Select rectangle...</source>
        <translation>选择区域...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="263"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>使用鼠标选择录制区域。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="264"/>
        <source>Select window...</source>
        <translation>选择窗口...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>使用鼠标选择要录制的窗口。
提示：如果您选中窗口边框，则整个窗口区域都会被录制（包括边框），其它情况的话只会录制窗口客户区域。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="269"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL设置...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>更改OpenGL录制选项。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="272"/>
        <source>Left:</source>
        <translation>左：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>录制区域左上角的x坐标。
提示：您也可以通过鼠标滚轮或上下方向键来改变值。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="278"/>
        <source>Top:</source>
        <translation>上：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="282"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>录制区域左上角的y坐标。
提示：您也可以通过鼠标滚轮或上下方向键来改变值。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="284"/>
        <source>Width:</source>
        <translation>宽：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="288"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>录制区域宽度。
提示：您也可以通过鼠标滚轮或上下方向键来改变值。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="290"/>
        <source>Height:</source>
        <translation>高：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="294"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>录制区域高度。
提示：您也可以通过鼠标滚轮或上下方向键来改变值。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="296"/>
        <source>Frame rate:</source>
        <translation>帧率：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="300"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>录制后视频的每秒帧数，越高越占用CPU。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="301"/>
        <source>Scale video</source>
        <translation>缩放视频</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="302"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>启用或者禁用视频缩放，缩放需要更多的CPU时间，但如果缩放后视频较小，也将会大大加快编码。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="303"/>
        <source>Scaled width:</source>
        <translation>缩放宽度：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="307"/>
        <source>Scaled height:</source>
        <translation>缩放高度：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="311"/>
        <source>Record cursor</source>
        <translation>录制光标</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="393"/>
        <source>Audio input</source>
        <translation>音频输入</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="395"/>
        <source>Record audio</source>
        <translation>录制声音</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="396"/>
        <source>Backend:</source>
        <translation>后端：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="408"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>录制所用音频后端。
ALSA后端在使用PulseAudio的系统上也能工作，但最好直接使用PulseAudio后端。</translation>
    </message>
    <message>
        <source>Device:</source>
        <translation type="obsolete">设备：</translation>
    </message>
    <message>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation type="obsolete">将会使用ALSA设备录制，通常情况下这是默认选项。
您可以改成其它类似plughw:0,0的值（意思是声卡0输入0且启用插件）。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="414"/>
        <location filename="../GUI/PageInput.cpp" line="423"/>
        <source>Source:</source>
        <translation>源：</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="426"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>将会使用PulseAudio作为录制来源。
&quot;monitor&quot;即是录制其它程序播放的声音源。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="419"/>
        <location filename="../GUI/PageInput.cpp" line="428"/>
        <source>Refresh</source>
        <translation>刷新</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="429"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>刷新PulseAudio源列表。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="432"/>
        <source>Record system microphone</source>
        <translation>录制系统麦克风</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="434"/>
        <source>Record system speakers</source>
        <translation>录制系统扬声器</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="433"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation type="unfinished">如果勾选，将会自动连接到系统捕获端口。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="241"/>
        <source>Input profile</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="250"/>
        <source>Record OpenGL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="411"/>
        <source>The audio backend that will be used for recording.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="417"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation type="unfinished">将会使用ALSA源来录制。
默认的设置通常比较好的，”共享“源允许多个应用程序同时录制，但不是稳定的。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="420"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>刷新ALSA源列表。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="435"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation type="unfinished">如果勾选，将会自动连接到任何一个连接到系统回放的端口。</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="482"/>
        <source>Back</source>
        <translation>后退</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="483"/>
        <source>Continue</source>
        <translation>继续</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="916"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>所有屏幕：%1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="920"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>屏幕%1：%2x%3位于%4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1132"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>屏幕%1</translation>
    </message>
    <message>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation type="obsolete">您未输入任何命令来启动想要录制的OpenGL应用程序。
点击“OpenGL设置”按钮，然后输入命令。</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation type="obsolete">文件</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <location filename="../GUI/PageOutput.cpp" line="85"/>
        <location filename="../GUI/PageOutput.cpp" line="88"/>
        <location filename="../GUI/PageOutput.cpp" line="91"/>
        <location filename="../GUI/PageOutput.cpp" line="133"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>%1 文件</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>其它...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>不压缩</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="173"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Output profile</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="191"/>
        <source>File</source>
        <translation>文件</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="193"/>
        <source>Save as:</source>
        <translation>另存为：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="195"/>
        <source>The recording will be saved to this location.</source>
        <translation>录像将会保存到这里。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="196"/>
        <source>Browse...</source>
        <translation>选择...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>Separate file per segment</source>
        <translation type="unfinished">将文件分段</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation type="obsolete">如果选中，在每次您暂停/继续录制时会产生一个分段录像。
如果原来文件名称是“test.mkv”，分段名称将会是“test-0001.mkv”、“test-0002.mkv”...
如果文件名已经存在，则会跳过。</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="obsolete">如果勾选，将会在您每次暂停和继续录制时创建一个分段的视频。
比如原来的文件名是”test.mkv“，分段视频名称将会是”test-YYYY-MM-DD_HH.MM.SS.mkv“。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="203"/>
        <source>Container:</source>
        <translation>容器：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="208"/>
        <source>(not installed)</source>
        <translation>（未安装）</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="211"/>
        <source>The container (file format) that will be used to save the recording.
Note that not all codecs are supported by all containers, and that not all media players can read all file formats.
- Matroska (MKV) supports all the codecs, but is less well-known.
- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video
   (and many media players only support AAC audio).
- WebM is intended for embedding video into websites (with the HTML5 &lt;video&gt; tag). The format was created by Google.
   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.
   It supports only VP8 and Vorbis.
- OGG supports only Theora and Vorbis.</source>
        <translation>用来保存录像的容器（即文件格式）。
请注意并非所有编码所有的容器都支持，也并非所有播放器都支持所有格式。
--Matroska（MKV）支持全部编码，但也不是大家都知道。
--MP4最为人所知的格式，绝大多数现代播放器都可以播放，但仅支持H.264视频
   （大部分播放器仅支持AAC音频）。
--WebM用于将视频放到网站上（使用HTML5的&lt;video&gt;标签），此格式由Google创立。
   WebM在Firefox、Chrome和Opera下默认是支持的，IE和Safari也可以通过插件支持。
   它只支持VP8和Vorbis。
--OGG仅支持Theora和Vorbis。   </translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Container name:</source>
        <translation>容器名称：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>适用于高级用户，您可以任意的libav、ffmpeg格式，但大多数没什么用还可能无法工作。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="247"/>
        <source>Video</source>
        <translation>视频</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="249"/>
        <location filename="../GUI/PageOutput.cpp" line="329"/>
        <source>Codec:</source>
        <translation>编解码器：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="254"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>用于压缩视频流的编码。
--H.264（libx264）目前是最好的编码，高质量且速度快。
--VP8（libvpx）是个不错的选择但十分地慢。
--Theora（libtheora）并不推荐使用它，因为质量不是很好。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="258"/>
        <location filename="../GUI/PageOutput.cpp" line="342"/>
        <source>Codec name:</source>
        <translation>编解码器名称：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="264"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>适用于高级用户，您可以任意的libav、ffmpeg格式，但大多数没什么用还可能无法工作。</translation>
    </message>
    <message>
        <source>Bit rate (in kbps):</source>
        <translation type="obsolete">比特率（kbps）：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <source>Add timestamp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="265"/>
        <location filename="../GUI/PageOutput.cpp" line="349"/>
        <source>Bit rate (in kbit/s):</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>视频的比特率（kb/s），越高质量越高。
如果您不知写多少好，试试5000，如果不行再稍微调整。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="269"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>速率基因常量：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="274"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>此设置会更改视频的质量，值越低质量越高。
允许的范围是0～51（0意味着无损，默认值是23）。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="280"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>预设：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="285"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>编码速度，值越高使用的CPU时间越少（使得录制更高的帧率成为可能），
但同时意味着文件体积大，当然质量不会太受影响。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="287"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU占用：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="289"/>
        <source>fastest</source>
        <translation>最快</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="294"/>
        <source>slowest</source>
        <translation>最慢</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="295"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>编码速度，值越高使用的CPU时间越少（这名称是VP8编码器用的），同时意味着更低的质量，除非您同时增加比特率。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <location filename="../GUI/PageOutput.cpp" line="352"/>
        <source>Custom options:</source>
        <translation>自定义选项：</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="299"/>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>自定义编解码器选项由英文逗号分隔（比如 option1=value1,option2=value2,option3=value3）</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <source>Allow frame skipping</source>
        <translation>允许跳帧</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="301"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>如果选中，视频编码器将会在输入帧率小于输出帧率时跳帧。否则，输入帧将由重复帧来填补空帧。
这会使得文件体积变大和占用更多的CPU时间，但也会减少实时流的延迟。
这不会影响视频的视觉效果。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="327"/>
        <source>Audio</source>
        <translation>音频</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="334"/>
        <source>The codec that will be used to compress the audio stream. You shouldn&apos;t worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you&apos;re only recording your own voice (i.e. no music), the quality won&apos;t matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it&apos;s very fast.</source>
        <translation>用于压缩音频流的编解码器，不用太在意这个，因为音频数据大小相对于视频数据大小来说是微不足道的。
如果您只录制自己的声音（也就是没有音乐之类的），质量不是很重要。
--Vorbis（libvorbis）非常好用，推荐使用它。
--MP3（libmp3lame）还不错
--AAC还可以，但这里实现的（libvo_aacenc或实验性的ffmpeg aac编码器）非常差，
   仅推荐在没有其它选择时使用。
--不压缩只是简单未经压缩地保存声音数据，文件将会非常大，但是速度也很快。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="348"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>适用于高级用户，您可以任意的libav、ffmpeg格式，但大多数没什么用还可能无法工作。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>音频比特率（kb/s），值越高质量超高，通常用128。</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="376"/>
        <source>Back</source>
        <translation>后退</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="377"/>
        <source>Continue</source>
        <translation>继续</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="631"/>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <source>not installed</source>
        <translation>未安装</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="633"/>
        <location filename="../GUI/PageOutput.cpp" line="641"/>
        <source>not supported by container</source>
        <translation>不受容器支持</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="684"/>
        <source>Save recording as</source>
        <translation>保存录像为</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="525"/>
        <source>You did not select an output file!</source>
        <translation>您还没选择输出文件！</translation>
    </message>
    <message>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation type="obsolete">文件%1已经存在，确定要覆盖吗？</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="162"/>
        <source>Recording</source>
        <translation>正在录制</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="168"/>
        <source>Edit schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="171"/>
        <source>Enable recording hotkey</source>
        <translation>启用录制热键</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="172"/>
        <source>The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,
even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the
SimpleScreenRecorder window show up in the final video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="176"/>
        <source>Enable sound notifications</source>
        <translation>启用声音通知</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="177"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="179"/>
        <source>Hotkey:</source>
        <translation>热键：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="180"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="181"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="182"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="183"/>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="185"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>开始/暂停录制的按键（结合修饰按键）。
被录制的程序将无法接收到设定的按键消息。</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Information</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="240"/>
        <source>Total time:</source>
        <translation>总时间：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>FPS in:</source>
        <translation>输入FPS：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="244"/>
        <source>FPS out:</source>
        <translation>输出FPS：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Size in:</source>
        <translation>输入大小：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="248"/>
        <source>Size out:</source>
        <translation>输出大小：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="250"/>
        <source>File name:</source>
        <translation>文件名：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="253"/>
        <source>File size:</source>
        <translation>文件大小：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="255"/>
        <source>Bit rate:</source>
        <translation>比特率：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="278"/>
        <source>Preview</source>
        <translation>预览</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="282"/>
        <source>Preview frame rate:</source>
        <translation>预览帧率：</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="286"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>注意：预览需要额外的CPU时间（尤其是高帧率的）。</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="335"/>
        <source>Log</source>
        <translation>日志</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="350"/>
        <location filename="../GUI/PageRecord.cpp" line="358"/>
        <source>Cancel recording</source>
        <translation>取消录制</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="351"/>
        <location filename="../GUI/PageRecord.cpp" line="360"/>
        <source>Save recording</source>
        <translation>保存录像</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="365"/>
        <source>Quit</source>
        <translation>退出</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="415"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>您尚未保存当前录像，退出将会丢失。
您确定退出程序吗？</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="427"/>
        <source>Hide window</source>
        <translation>隐藏窗口</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="429"/>
        <source>Show window</source>
        <translation>显示窗口</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="630"/>
        <source>Starting page ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="662"/>
        <source>Started page.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="694"/>
        <source>Stopping page ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="968"/>
        <source>Encoding remaining data ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1210"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1227"/>
        <source>Triggering scheduled action &apos;%1&apos; ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1238"/>
        <source>Schedule: %1 in %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1245"/>
        <source>Schedule: (none)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1249"/>
        <source>Schedule: (inactive)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1313"/>
        <location filename="../GUI/PageRecord.cpp" line="1330"/>
        <source>Standard input read error (%1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1318"/>
        <location filename="../GUI/PageRecord.cpp" line="1335"/>
        <source>Standard input closed (%1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1346"/>
        <source>Received command &apos;%1&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1366"/>
        <source>Unknown command.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="721"/>
        <source>Stopped page.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="749"/>
        <source>Starting output ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="764"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="769"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="808"/>
        <source>Started output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="883"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="653"/>
        <location filename="../GUI/PageRecord.cpp" line="817"/>
        <location filename="../GUI/PageRecord.cpp" line="913"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="828"/>
        <source>Stopping output ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="846"/>
        <source>Stopped output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="877"/>
        <source>Starting input ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="908"/>
        <source>Started input.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="937"/>
        <source>Stopping input ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="952"/>
        <source>Stopped input.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1061"/>
        <location filename="../GUI/PageRecord.cpp" line="1071"/>
        <source>Pause recording</source>
        <translation>暂停录制</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1064"/>
        <location filename="../GUI/PageRecord.cpp" line="1074"/>
        <source>Start recording</source>
        <translation>开始录制</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1082"/>
        <source>Deactivate schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1092"/>
        <source>Activate schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1101"/>
        <source>Stop preview</source>
        <translation>停止预览</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1104"/>
        <source>Start preview</source>
        <translation>开始预览</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1145"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1193"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>您确定要放弃本次录制吗？</translation>
    </message>
    <message>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation type="obsolete">您尚未进行录制，无需保存。
开始按钮在顶部呢 ;)。</translation>
    </message>
</context>
<context>
    <name>PageWelcome</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="41"/>
        <source>&lt;p&gt;Welcome to SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Despite the name, this program actually has a lot of options. Don&apos;t worry though, there are really just two things that you need to know. One, the default settings are usually fine. If you don&apos;t know what something does, just use the default. Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.&lt;/p&gt;

&lt;p&gt;For more information:&lt;br&gt;
%1&lt;/p&gt;</source>
        <translation>&lt;p&gt;欢迎使用SimpleScreenRecorder！&lt;/p&gt;
&lt;p&gt;尽管名称“简单”，但本程序实际上是有很多功能的。别担心，事实上您只需要知道两件事。一个是默认设置通常是好的，如果你不知道某些选项是干嘛的，使用默认的就好；另一个是所有选项都会有气泡提示的，将鼠标移动到相应选项上就可以看到了。&lt;/p&gt;
&lt;p&gt;更多信息：&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="51"/>
        <source>About SimpleScreenRecorder</source>
        <translation>关于SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="52"/>
        <source>Skip this page next time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="53"/>
        <source>Go directly to the input page when the program is started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="76"/>
        <source>Continue</source>
        <translation>继续</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <source>Profile</source>
        <translation type="obsolete">配置文件</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>保存当前设置到此配置文件。</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>新建</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>使用当前设置创建一个新的配置文件。</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>删除</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>删除此配置文件。</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>（无）</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>您确定要覆盖此配置文件吗？</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>请给新配置文件输入一个名称：</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>已经存在同名的配置文件，您确定要替换它吗？</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>您确定要删除此配置文件吗？</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation>确定(&amp;O)</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation>取消(&amp;C)</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>是(&amp;Y)</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>总是</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>否(&amp;N)</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>从不</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">SimpleScreenRecorder检测到您正在使用NVIDIA闭源驱动且开启了flipping功能，这会导致录制不稳定，建议您禁用它。您想要禁用吗？
您也可以在NVIDIA控制面板手动更改它。</translation>
    </message>
    <message>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">非常抱歉，无法禁用flipping功能，请您尝试在NVIDIA面板禁用。</translation>
    </message>
</context>
<context>
    <name>RecordScheduleEntryWidget</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="39"/>
        <source>Start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="40"/>
        <source>Pause</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="46"/>
        <source>Time:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="51"/>
        <source>Action:</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>图同步</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="257"/>
        <source>Video in</source>
        <translation>视频输入</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="258"/>
        <source>Audio in</source>
        <translation>音频输入</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="259"/>
        <source>Video out</source>
        <translation>视频输出</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="260"/>
        <source>Audio out</source>
        <translation>音频输出</translation>
    </message>
</context>
</TS>
