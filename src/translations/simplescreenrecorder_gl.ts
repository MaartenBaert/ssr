<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="gl_ES">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Sobre SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="120"/>
        <source>For more information:</source>
        <translation>Para máis información:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="121"/>
        <source>The source code of this program can be found at:</source>
        <translation>O código fonte deste programa pódese atopar en:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="122"/>
        <source>This program uses:</source>
        <translation>Este programa usa:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="123"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 para a interface gráfica</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="124"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 o %2 (según a túa distribución) para codificar o vídeo e o audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="125"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 para intercepta-las chamadas ao sistema para grabar OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="35"/>
        <source>OpenGL Settings</source>
        <translation>Opcións de OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="38"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Aviso: a grabación de OpenGL funciona inxectando unha biblioteca no programa que será grabado. Esta biblioteca substituirá algunhas chamadas ao sistema para capturar os fotogramas antes de que sexan mostrados por pantalla. Se intentas grabar un xogo que detecte hacks no cliente, é (teóricamente) posible que o xogo considere esto un hack. Esto podería provocar que te expulsen, así que é unha boa idea comprobar que o programa que intentas grabar non te botará, *antes* de intentar grabar. Estás avisado :).&lt;/p&gt;

Outro aviso: a grabación OpenGL é experimental, podería non funcionar ou incluso facer que o programa que estés grabando falle. ¡Se che preocupa perder datos do programa, garda antes!&lt;/p&gt;

Se queres grabar un xogo de Steam, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;lee esto primeiro&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="52"/>
        <source>Choose channel</source>
        <translation>Seleccione canal</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="54"/>
        <source>Channel name:</source>
        <translation>Nome do canal:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="74"/>
        <source>Launch application</source>
        <translation>Iniciar aplicación</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="76"/>
        <source>Command:</source>
        <translation>Comando:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="78"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Este comando executarase para empezar o programa que se quere grabar.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="80"/>
        <source>Working directory:</source>
        <translation>Directorio de traballo:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="82"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>O comando será executado neste directorio. Se queda valeiro, o directorio de traballo non será cambiado.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="108"/>
        <source>Stream settings</source>
        <translation>Opcións de fluxo</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Relaxar permisos de memoria compartida (inseguro)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="56"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Os nomes de canal son usados para identificar aplicacións. Só e necesario para grabar de varias aplicacións ao mesmo tempo.
Se queda valeiro, o nome por defecto usado será &apos;channel-YOURUSERNAME&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Si se marca, outros usuarios na mesma máquina serán capaces de usar a memoria compartida que se usa para comunicarse co progrma OpenGL.
Esto significa que outros usuarios poden (teóricamente) ver qué estás grabando, modificar os fotogramas, inxectar seus propios fotogramas, ou simplemente interrumpir a comunicación.
Esto incluso funciona con usuarios que estén conectados de forma remota (ssh). Só deberías activar esto se necesitas grabar un programa que se executa como outro usuario.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>Launch automatically</source>
        <translation>Iniciar automáticamente</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="85"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Se se marca, a aplicación executarase automáticamente unha vez que chegues á fiestra de grabación. Se non se marca, deberás iniciala manualmente.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="87"/>
        <source>Launch now</source>
        <translation>Iniciar ahora</translation>
    </message>
    <message>
        <source>Select stream</source>
        <translation type="obsolete">Seleccionar origen</translation>
    </message>
    <message>
        <source>Active streams:</source>
        <translation type="obsolete">Orígenes activos:</translation>
    </message>
    <message>
        <source>Record newest stream that matches:</source>
        <translation type="obsolete">Grabar la fuente más reciente que concuerde con:</translation>
    </message>
    <message>
        <source>Error: Could not create stream watcher!</source>
        <translation type="obsolete">Error: ¡No se pudo crear el observador de fuentes!</translation>
    </message>
    <message>
        <source>Error: Could not update streams!</source>
        <translation type="obsolete">Error: ¡No se pudieron actualizar las fuentes!</translation>
    </message>
    <message>
        <source>Record the latest stream that matches:</source>
        <translation type="obsolete">Grabar el último origen que concuerde:</translation>
    </message>
    <message>
        <source>User:</source>
        <translation type="obsolete">Usuario:</translation>
    </message>
    <message>
        <source>Process:</source>
        <translation type="obsolete">Proceso:</translation>
    </message>
    <message>
        <source>Source:</source>
        <translation type="obsolete">Fuente:</translation>
    </message>
    <message>
        <source>Program name:</source>
        <translation type="obsolete">Nombre de programa:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>Limit application frame rate</source>
        <translation>Limitar a tasa de fotogramas da aplicación</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="111"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Se se marca, a biblioteca inxectada reducirá a velocidade da aplicación para que a tasa de fotogramas non sexa máis alta que a tasa de fotogramas de grabación.
Esto evita que a aplicación gaste tempo de CPU para fotogramas que non serán grabados, e as veces resulta en un vídeo máis suave.
(depende da aplicación).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="120"/>
        <source>Close</source>
        <translation>Pechar</translation>
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
        <translation type="unfinished">Pechar</translation>
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
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="obsolete">Aviso: Formato de píxeles no soportado (%1 -&gt; %2), usando swscale en su lugar. Esto no es un problema, pero la calidad será peor.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="129"/>
        <source>Warning: No fast pixel format conversion available (%1,%2 -&gt; %3,%4), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="138"/>
        <location filename="../Benchmark.cpp" line="124"/>
        <location filename="../Benchmark.cpp" line="205"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="unfinished">Error: ¡No se pudo obtener el contexto de swscale!</translation>
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
        <translation type="unfinished">Aviso: La memoria no está alineada para SSE, usando el conversor fallback en su lugar. Esto no es un problema, pero el rendimiento será peor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Aviso: Ha habido un overrun, algunas muestras se han perdido.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="37"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Error: ¡No se puede recuperar el dispositivo tras el overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="41"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Error: ¡No se puede iniciar el dispositivo PCM tras el overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="71"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="59"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="66"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation type="unfinished">Deteniendo hilo de grabación ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="102"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="121"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="187"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="168"/>
        <source>Found plugin: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="191"/>
        <source>Found card: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="216"/>
        <source>Found device: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="271"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation type="unfinished">Error: ¡No se puede abrir el dispositivo PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation type="unfinished">Error: ¡No se pueden obtener los parámetros de hardware PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="281"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation type="unfinished">Error: ¡No se puede establecer el tipo de acceso!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="292"/>
        <source>Error: Can&apos;t set sample format mask!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="297"/>
        <location filename="../AV/SimpleSynth.cpp" line="140"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation type="unfinished">Error: ¡No se puede establecer el formato de muestreo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="330"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation type="unfinished">Error: ¡No se puede establecer una tasa de muestreo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Aviso: La tasa de muestro %1 no está soportada, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="343"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation type="unfinished">Error: ¡No se puede establecer el número de canales!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="347"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="356"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation type="unfinished">Error: ¡No se puede establecer el tamaño del periodo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="360"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Aviso: El tamaño del periodo %1 no está soportado, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="369"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation type="unfinished">Error: ¡No se puede ajustar el tamaño del buffer!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Aviso: el tamaño del buffer %1 no está soportado, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="381"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation type="unfinished">Error: ¡No se pueden aplicar los parámetros de hardware PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="407"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation type="unfinished">Error: ¡No se puede iniciar el dispositivo PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="428"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="263"/>
        <location filename="../AV/Input/X11Input.cpp" line="465"/>
        <source>Input thread started.</source>
        <translation type="unfinished">Hilo de entrada iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="452"/>
        <source>Error: Can&apos;t wait for new samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation type="obsolete">Error: ¡No se puede comprobar si las muestras están disponibles!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="469"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation type="unfinished">Error: ¡No se pueden leer las muestras!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="500"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="358"/>
        <location filename="../AV/Input/JACKInput.cpp" line="302"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="294"/>
        <location filename="../AV/Input/X11Input.cpp" line="585"/>
        <source>Input thread stopped.</source>
        <translation type="unfinished">Hilo de entrada detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="504"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="362"/>
        <location filename="../AV/Input/JACKInput.cpp" line="306"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="589"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation type="unfinished">Excepción &apos;%1&apos; en el hilo de entrada.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="507"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="365"/>
        <location filename="../AV/Input/JACKInput.cpp" line="309"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="301"/>
        <location filename="../AV/Input/X11Input.cpp" line="592"/>
        <source>Unknown exception in input thread.</source>
        <translation type="unfinished">Excepción desconocida en el hilo de entrada.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="318"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="unfinished">Error: ¡No se puede obtener la memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="323"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="unfinished">Error: ¡No se puede acceder a la memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="75"/>
        <source>Error: Could not connect to JACK!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="84"/>
        <source>Error: Could not create JACK port!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="100"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="108"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="117"/>
        <source>Error: Could not activate JACK client!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="125"/>
        <location filename="../AV/Input/JACKInput.cpp" line="136"/>
        <location filename="../AV/Input/JACKInput.cpp" line="265"/>
        <source>Connecting port %1 to %2.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="269"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="34"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation type="unfinished">Error: ¡pa_mainloop_prepare falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="38"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="unfinished">Error: ¡pa_mainloop_poll falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="42"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="unfinished">Error: ¡pa_mainloop_dispatch falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="52"/>
        <source>Error: Could not create main loop!</source>
        <translation type="unfinished">Error: ¡No se pudo crear el bucle principal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="59"/>
        <source>Error: Could not create context!</source>
        <translation type="unfinished">Error: ¡No se pudo crear un contexto!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation type="unfinished">Error: ¡No se pudo conectar! Motivo: %1
Es posible que tu sistema no use PulseAudio. Intenta usar el sistema de ALSA en su lugar.</translation>
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
        <translation type="unfinished">Error: ¡Intento de conexión fallido! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="119"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="unfinished">Error: ¡No se pudo crear el flujo! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="126"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="unfinished">Error: ¡No se pudo conectar al flujo! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="137"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="unfinished">Error: ¡El intento de conexión al flujo falló! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="228"/>
        <source>Found source: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="249"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="unfinished">Error: ¡No se pudo obtener los nombres de las fuentes! Motivo: %1</translation>
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
        <translation type="unfinished">Error: ¡pa_stream_peek falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="416"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="unfinished">Aviso: la fuente de audio se suspendió. El segmento actual será detenido hasta que la fuente continúe.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="421"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="unfinished">Aviso: El flujo fue movido a otra fuente diferente.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="68"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="unfinished">Error: ¡Formato del píxel de la imagen X11 no soportado!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="41"/>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="118"/>
        <source>Error: Width or height is zero!</source>
        <translation type="unfinished">Error: ¡El ancho o el alto es cero!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="45"/>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="122"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="unfinished">Error: ¡Ancho o alto muy grande, el tamaño máximo de ancho y alto es %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="99"/>
        <source>Error: Can&apos;t open V4L2 device!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="107"/>
        <source>Error: Can&apos;t read capabilities of V4L2 device!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="111"/>
        <source>Error: V4L2 device does not support video capture!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="115"/>
        <source>Error: V4L2 device does not support streaming io!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="132"/>
        <source>Error: Can&apos;t set capture format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="136"/>
        <source>Error: V4L2 device does not support YUYV pixel format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="140"/>
        <source>Warning: Resolution %1x%2 is not supported, using %3x%4 instead. The video will be scaled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="183"/>
        <source>Using color space %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="193"/>
        <source>Error: Buffer request failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="203"/>
        <source>Error: Buffer query failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="209"/>
        <source>Error: Buffer mmap failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="222"/>
        <source>Error: Buffer queue failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="230"/>
        <source>Error: Failed to start stream!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="273"/>
        <source>Error: Buffer dequeue failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="288"/>
        <source>Error: Buffer requeue failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="257"/>
        <location filename="../GUI/HotkeyListener.cpp" line="115"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="unfinished">Error: ¡No se pudo abrir el display X!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="266"/>
        <source>Using X11 shared memory.</source>
        <translation type="unfinished">Usando la memoria compartida de X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="313"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="unfinished">Error: ¡No se puede crear una imagen compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="268"/>
        <source>Not using X11 shared memory.</source>
        <translation type="unfinished">No se usa la memoria compartida X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="275"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="obsolete">Error: El servidor no soporta XFixes, el cursor está oculto.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="406"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="unfinished">Error: ¡Bounding box de la pantalla inválido!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="328"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="unfinished">Error: ¡No se puede conectar a la memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="355"/>
        <source>Detecting screen configuration ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="373"/>
        <source>Warning: Xinerama is not supported by X server, multi-monitor support may not work properly.</source>
        <comment>Don&apos;t translate &apos;Xinerama&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="386"/>
        <source>Screen %1:</source>
        <translation type="unfinished">Pantalla %1:</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="450"/>
        <source>Dead space %1:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="536"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished">Error: ¡No se puede obtener la imagen (usando memoria compartida)!
    Normalmente esto significa que el área de grabación no está dentro de la pantalla. ¿O has cambiado la resolución de la pantalla?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="547"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished">Error: ¡No se puede obtener la imagen (sin usar memoria compartida)!
    Normalmente esto significa que el área de grabación no está dentro de la pantalla. ¿O has cambiado la resolución de la pantalla?</translation>
    </message>
    <message>
        <source>Error: Sample rate it zero.</source>
        <translation type="obsolete">Error: La tasa de muestreo es cero.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="172"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation type="unfinished">Aviso: ¡La opción de códec &apos;%1&apos; no se reconoció!</translation>
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
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="142"/>
        <source>Using sample format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="147"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="unfinished">Error: ¡El codificador requiere un formato de muestreo no soportado!</translation>
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
        <translation type="unfinished">Error: ¡La codificación del audio falló!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="30"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="39"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="unfinished">Error: ¡La opción %1 no se pudo analizar!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation type="unfinished">Deteniendo hilo del codificador ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="267"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="unfinished">Error: ¡No se puede encontrar el códec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="277"/>
        <source>Using codec %1 (%2).</source>
        <translation type="unfinished">Usando codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="320"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="unfinished">Aviso: este codec se considera experimental por libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="164"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="unfinished">Error: ¡No se puede abrir el códec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="188"/>
        <source>Encoder thread started.</source>
        <translation type="unfinished">Hilo del codificador iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="217"/>
        <source>Flushing encoder ...</source>
        <translation type="unfinished">Vaciando codificador ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="228"/>
        <source>Encoder thread stopped.</source>
        <translation type="unfinished">Hilo del codificador detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="unfinished">Excepción &apos;%1&apos; en el hilo del codificador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="235"/>
        <source>Unknown exception in encoder thread.</source>
        <translation type="unfinished">Excepción desconocida en el hilo del codificador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="70"/>
        <source>Stopping encoders ...</source>
        <translation type="unfinished">Deteniendo codificadores ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="77"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="unfinished">Esperando al hilo muxer para detenerse ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="146"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="unfinished">Error: ¡No se puede escribir el encabezado!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="157"/>
        <source>Finishing encoders ...</source>
        <translation type="unfinished">Deteniendo codificadores ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="288"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="unfinished">Error: ¡No se puede crear un nuevo flujo!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="307"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="unfinished">Error: ¡No se puede obtener los ajustes por defecto del contexto del códec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="unfinished">Error: ¡No se puede encontrar el formato de salida elegido!</translation>
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
        <translation type="unfinished">Usando formato %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="209"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="unfinished">Error: ¡No se puede asignar un contexto de formato!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="unfinished">Error: ¡No se puede abrir el archivo de salida!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="229"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="unfinished">Error: No se puede escribir el trailer, continuando de todos modos.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="295"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="336"/>
        <source>Muxer thread started.</source>
        <translation type="unfinished">Hilo del muxer iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="396"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="unfinished">Error: ¡No se puede escribir el fotograma en el muxer!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="424"/>
        <source>Muxer thread stopped.</source>
        <translation type="unfinished">Hilo del muxer detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="428"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="unfinished">Excepción &apos;%1&apos; en el hilo del mutex.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="431"/>
        <source>Unknown exception in muxer thread.</source>
        <translation type="unfinished">Excepción desconocida en el hilo del mutex.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="220"/>
        <source>Stopping synchronizer thread ...</source>
        <translation type="unfinished">Deteniendo hilo del sincronizador...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="328"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="unfinished">Aviso: Se recibió un fotograma de vídeo con una marca de tiempo no monotónica.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="355"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="unfinished">Aviso: el buffer de vídeo se desbordó, algunos fotogramas se perderán. La entrada de audio es lenta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="412"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="unfinished">Aviso: se recibieron muestras de audio con una marca de tiempo no monotónica.</translation>
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
        <location filename="../AV/Output/Synchronizer.cpp" line="511"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation type="unfinished">Aviso: ¡La entrada de audio es más de un 5% de lenta! {2%?}</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="515"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="unfinished">Aviso: ¡La entrada de audio es más de un 5% rápida! {2%?}</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="554"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="unfinished">Aviso: el buffer de audio se desbordó, iniciando un nuevo segmento para mantener el audio sincronizado con el vídeo (se puede haber perdido algo de vídeo y/o audio). La entrada de vídeo parece ser muy lenta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="590"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="891"/>
        <source>Synchronizer thread started.</source>
        <translation type="unfinished">Hilo del sincronizador iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="913"/>
        <source>Synchronizer thread stopped.</source>
        <translation type="unfinished">Hilo del sincronizador detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="917"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="unfinished">Excepción &apos;%1&apos; en el hilo del sincronizador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="920"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="unfinished">Excepción desconocida en el hilo del sincronizador.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="49"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="126"/>
        <source>Error: Width or height is not an even number!</source>
        <translation type="unfinished">Error: ¡El ancho o el alto no es un número par!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="130"/>
        <source>Error: Frame rate is zero!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="187"/>
        <source>Using pixel format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="201"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="229"/>
        <source>Error: Sending of video frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="250"/>
        <source>Error: Receiving of video packet failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Frame rate it zero!</source>
        <translation type="obsolete">Error: ¡La tasa de fotogramas es cero!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="263"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="284"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="unfinished">Error: ¡La codificación del vídeo falló!</translation>
    </message>
    <message>
        <source>Warning: An underrun has occurred, some samples were too late.</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="obsolete">Aviso: ha habido un underrun, algunas muestras llegaron demasiado tarde.</translation>
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
        <translation type="unfinished">Error: ¡No se puede recuperar el dispositivo tras el overrun!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="91"/>
        <source>Stopping synth thread ...</source>
        <translation type="unfinished">Deteniendo hilo del notificador de audio ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="224"/>
        <source>Synth thread started.</source>
        <translation type="unfinished">Hilo del notificador de audio iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="277"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="unfinished">Error: ¡No se pueden escribir las muestras!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="285"/>
        <source>Synth thread stopped.</source>
        <translation type="unfinished">Hilo del notificador de audio detenido.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="289"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="unfinished">Excepción &apos;%1&apos; en el hilo del notificador de audio.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="292"/>
        <source>Unknown exception in synth thread.</source>
        <translation type="unfinished">Excepción desconocida en el hilo del notificador de audio.</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="45"/>
        <source>CPU features</source>
        <translation type="unfinished">Características de la CPU</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="90"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="98"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="unfinished">Error: ¡El parámetro de línea de comandos &apos;%1&apos; no tiene un valor!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="195"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="unfinished">Error: ¡Parámetro de línea de comandos &apos;%1&apos; desconocido!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="203"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="unfinished">Error: ¡Argumento de la línea de comandos &apos;%1&apos; desconocido!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="253"/>
        <source>Error: Can&apos;t create configuration directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="99"/>
        <source>SSR started</source>
        <translation type="unfinished">SSR iniciado</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="133"/>
        <source>SSR stopped</source>
        <translation type="unfinished">SSR detenido</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="obsolete">Error: ¡No se puede crear el directorio .ssr!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="259"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation type="unfinished">Error: No se pudo leer el stream, esto suele indicar que el stream ya ha desaparecido.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation type="unfinished">Creado lector de stream de vídeo.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation type="unfinished">Error: ¡No se puede abrir el archivo del stream de vídeo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation type="unfinished">Error: ¡No se puede cargar en memoria el archivo del stream de vídeo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation type="unfinished">Error: ¡no se puede abrir el archivo con el fotograma de vídeo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation type="unfinished">Destruido lector de stream de vídeo.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation type="unfinished">Error: ¡El tamaño del archivo del fotograma de vídeo es incorrecto!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation type="unfinished">Error: ¡No se puede cargar el archivo del fotograma de vídeo en memoria!</translation>
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
        <translation type="unfinished">Error: ¡No se puede inicializar inotify!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t watch shared memory directory!</source>
        <translation type="obsolete">Error: ¡No se puede vigilar el directory de memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open shared memory directory!</source>
        <translation type="obsolete">Error: ¡No se puede abrir el directorio de memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation type="unfinished">Añadiendo stream pre-existente %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Error: ¡No se puede obtener la longitud desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Error: ¡No se puede leer desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Error: ¡Recibido evento parcial desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Error: ¡Recibido nombre parcial desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation type="unfinished">Añadido stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation type="unfinished">Eliminando stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>The application could not be launched.</source>
        <translation type="unfinished">La aplicación no pudo iniciarse.</translation>
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
        <location filename="../AV/Output/OutputManager.cpp" line="347"/>
        <source>Fragment thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="365"/>
        <source>Next fragment ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="369"/>
        <source>Finishing ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="381"/>
        <source>Fragment thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="385"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="388"/>
        <source>Unknown exception in fragment thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/ScreenScaling.cpp" line="120"/>
        <source>Detected fractional screen scale factor, scaling was disabled.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>You are using a non-X11 window system (e.g. Wayland) which is currently not supported by SimpleScreenRecorder. Several features will most likely not work properly. In order to solve this, you should log out, choose a X11/Xorg session at the login screen, and then log back in.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="86"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder detectou que estás usando o driver propietario NVIDIA coa opción de flipping activada. Esto causa problemas durante a grabación. Recoméndase desactivar o flipping. ¿Queres que o faga por tí?

Tamén podes cambiar esta opción manualmente no panel de control de NVIDIA.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="104"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Non se desactivou o &apos;flipping&apos; por algunha razón - ¡Sintoo! Intenta desactivalo desde o panel de control de NVIDIA.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="31"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>La grabación se ha guardado. Ahora puedes editar el vídeo, o recodificarlo con mejores opciones para hacer el tamaño del archivo menor (las opciones por defecto están optimizadas para calidad y velocidad, no tamaño de archivo).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="35"/>
        <source>Open folder</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="38"/>
        <source>Back to the start screen</source>
        <translation>Volver a la pantalla inicial</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="273"/>
        <source>Video input</source>
        <translation>Entrada de vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record the entire screen</source>
        <translation>Grabar la pantalla completa</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>Record a fixed rectangle</source>
        <translation>Grabar un rectángulo fixo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="278"/>
        <source>Follow the cursor</source>
        <translation>Seguir o cursor</translation>
    </message>
    <message>
        <source>Record OpenGL (experimental)</source>
        <translation type="obsolete">Grabar OpenGL (experimental)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="295"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Selecciona qué monitor debería grabarse en configuracións multimonitor.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="296"/>
        <source>Record entire screen with cursor</source>
        <translation>Grabar toda a pantalla incluido o cursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="297"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation>Grabar toda a pantalla na que está o cursor en vez de seguir a posición do cursor.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="298"/>
        <source>Select rectangle...</source>
        <translation>Seleccionar rectángulo...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="299"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Usar o rato para seleccionar o rectángulo de grabación.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="300"/>
        <source>Select window...</source>
        <translation>Seleccionar fiestra...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="301"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Usar o rato para seleccionar unha fiestra que grabar.
Pista: Se fas clic sobre o borde da fiestra, toda ela completa será grabada (incluindo bordes). De outro modo só
a área cliente da fiestra será grabada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="305"/>
        <source>OpenGL settings...</source>
        <translation>Opcións de OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="306"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Cambia as opcións para grabar OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="310"/>
        <source>The V4L2 device to record (e.g. /dev/video0).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Left:</source>
        <translation>Esquerda:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="316"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A coordenada x do canto superior esquerdo do rectángulo de grabación.
Pista: Tamén podes cambiar este valor coa roeda do rato ou coas frechas Arriba/Abaixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="318"/>
        <source>Top:</source>
        <translation>Arriba:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="322"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A coordenada y do canto superior esquerdo do rectángulo de grabación.
Pista: Tamén podes cambiar este valor coa roda do rato ou coas frechas Arriba/Abaixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="324"/>
        <source>Width:</source>
        <translation>Ancho:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="328"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>O ancho do rectángulo de grabación.
Pista: Tamén podes cambiar este valor coa roda do rato ou coas frechas Arriba/Abaixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="330"/>
        <source>Height:</source>
        <translation>Alto:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="334"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>O alto do rectángulo de grabación.
Pista: Tamén podes cambiar este valor coa roda do rato ou coas frechas Arriba/Abaixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="336"/>
        <source>Frame rate:</source>
        <translation>Tasa de fotogramas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="340"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>O número de fotogramas por segundo do vídeo. Unha tasa maior usa máis tempo de CPU.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="341"/>
        <source>Scale video</source>
        <translation>Escalar vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="342"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Activa ou desactiva o escalado. O escalado usa máis tempo de CPU pero se o vídeo é máis pequeno, podería codificarse máis rápido.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="343"/>
        <source>Scaled width:</source>
        <translation>Ancho do escalado:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="347"/>
        <source>Scaled height:</source>
        <translation>Alto do escalado:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="351"/>
        <source>Record cursor</source>
        <translation>Grabar o cursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="441"/>
        <source>Audio input</source>
        <translation>Entrada de audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="443"/>
        <source>Record audio</source>
        <translation>Grabar audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="444"/>
        <source>Backend:</source>
        <translation>Sistema:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="456"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>O sistema de audio que será usado para grabar.
O sistema ALSA tamén funcionará en sistemas que usan PulseAudio, pero é mellor usar directamente o sistema PulseAudio.</translation>
    </message>
    <message>
        <source>Device:</source>
        <translation type="obsolete">Dispositivo:</translation>
    </message>
    <message>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation type="obsolete">El dispositivo ALSA que será usado para grabar. Normalmente debería ser &apos;default&apos;.
Puedes cambiar esto por algo como plughw:0,0 (que normalmente significa tarjeta 0 entrada 0 con complementos activados).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="462"/>
        <location filename="../GUI/PageInput.cpp" line="471"/>
        <source>Source:</source>
        <translation>Orixe:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="474"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>A entrada PulseAudio que será usada para grabar.
Un &apos;monitor&apos; é unha entrada que graba o audio reproducido por outras aplicacións.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="467"/>
        <location filename="../GUI/PageInput.cpp" line="476"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Input profile</source>
        <translation>Perfil de entrada</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="280"/>
        <source>Record OpenGL</source>
        <translation>Grabar OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="283"/>
        <source>Record V4L2 device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="459"/>
        <source>The audio backend that will be used for recording.</source>
        <translation>O sistema de audio que será usado para grabar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="465"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>O sistema ALSA que será usado para grabar.
O predeterminado-soe-funcionar ben. As orixes &quot;compartidas&quot; permiten grabacións simultáneas, pero son menos fiables.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="468"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Actualizar a lista de orixes ALSA.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="477"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Actualiza a lista de orixes de PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="480"/>
        <source>Record system microphone</source>
        <translation>Grabar o micrófono do sistema</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="481"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Se se marca, os portos serán conectados automáticamente aos portos do sistema de captura.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="482"/>
        <source>Record system speakers</source>
        <translation>Grabar altofalantes do sistema</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="483"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Se se marca, os portos conectarán automáticamente a calquera dispositivo que se conecte a os portos de reprodución do sistema.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="530"/>
        <source>Back</source>
        <translation>Atrás</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="531"/>
        <source>Continue</source>
        <translation>Continuar</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="964"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Todas as pantallas: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="968"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Pantalla %1: %2x%3 en %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1206"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Pantalla %1</translation>
    </message>
    <message>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation type="obsolete">No has introducido un comando para iniciar la aplicación OpeNGL que intentas grabar.
Haz clic en el botón &apos;Opciones de OpenGL&apos; e introdude un comando.</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation type="obsolete">archivos</translation>
    </message>
    <message>
        <source>Matroska files</source>
        <comment>This appears in the file dialog</comment>
        <translation type="obsolete">Archivos Matroska</translation>
    </message>
    <message>
        <source>MP4 files</source>
        <comment>This appears in the file dialog</comment>
        <translation type="obsolete">Archivos MP4</translation>
    </message>
    <message>
        <source>WebM files</source>
        <comment>This appears in the file dialog</comment>
        <translation type="obsolete">Archivos WebM</translation>
    </message>
    <message>
        <source>OGG files</source>
        <comment>This appears in the file dialog</comment>
        <translation type="obsolete">Archivos OGG</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>Outros...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>Sen comprimir</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <location filename="../GUI/PageOutput.cpp" line="85"/>
        <location filename="../GUI/PageOutput.cpp" line="88"/>
        <location filename="../GUI/PageOutput.cpp" line="91"/>
        <location filename="../GUI/PageOutput.cpp" line="133"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>%1 arquivos</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="173"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Erro: ¡Non se puido atopar ningún recipiente compatible en libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Erro: ¡Non se puido atopar ningún códec de vídeo en libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Erro: ¡Non se puido atopar ningún códec de audio en libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Output profile</source>
        <translation>Perfil de salida</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="191"/>
        <source>File</source>
        <translation>Arquivo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="193"/>
        <source>Save as:</source>
        <translation>Gardar como:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="195"/>
        <source>The recording will be saved to this location.</source>
        <translation>A grabación gardarase nesta ubicación.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="196"/>
        <source>Browse...</source>
        <translation>Buscar...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>Separate file per segment</source>
        <translation>Separar arquivos por segmentos</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation type="obsolete">Si se marca, se creará un archvio de vídeo separado cada vez que pauses y continúes la grabación.
Si el archivo original se llama &apos;test.mkv&apos;, los segmentos se guardarán como &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
Los archivos que ya existan serán saltados.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="203"/>
        <source>Container:</source>
        <translation>Recipiente:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="208"/>
        <source>(not installed)</source>
        <translation>(non instalado)</translation>
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
        <translation>O recipiente (tipo de arquivo) que se usará para gardar a grabación.
Ten en conta que non todos os códecs son soportados en todos os contenedores, e que non todos os reproductores poden ler todos os formatos.
- Matroska (MKV) soporta todos os códecs, pero é o menos conocido.
- MP4 é o formato máis conocido e reproducirase en calquera reproductor de vídeo moderno, pero só soporta vídeo H.264
   (e moitos reproductores multimedia só soportan audio AAC).
- WebM está deseñado para acoplar vídeo nas web (usando o tag HTML5 &lt;video&gt;). O formato foi creado por Google.
   WebM está soportado por defecto en FIrefox, Chrome e Opera, e algúns plugins están dispoñibles para Internet Explorer e Safari.
   Só soporta VP8 e Vorbis.
- OGG soporta só Theora y Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Container name:</source>
        <translation>Nome do recipiente:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Para usuarios avanzados. Podes usar calquera formato de libav/ffmpeg, pero moitos deles son pouco útiles o poderían non funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <source>Video</source>
        <translation>Vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="252"/>
        <location filename="../GUI/PageOutput.cpp" line="332"/>
        <source>Codec:</source>
        <translation>Códec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="257"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>O códec que se usará para comprimir o fluxo de vídeo.
- H.264 (libx264) é sen dúbida o mellor códec - alta calidade e moi rápido.
- VP8 (libvpx) é tamén bó pero é un pouco lento.
- Theora (libtheora) non se recomenda porque a calidade nón é moi boa.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Codec name:</source>
        <translation>Nome do códec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Para usuarios avanzados. Podes usar calquear códec de vídeo libav/ffmpeg, pero moitos delest non son útiles ou poderían non funcionar.</translation>
    </message>
    <message>
        <source>Bit rate (in kbps):</source>
        <translation type="obsolete">Tasa de bits (en kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation>Se se marca, gardarase un vídeo cada vez que se pause e reinicie a grabación. Se se desmarca, cada fragmento será combinado nun só vídeo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <source>Add timestamp</source>
        <translation>Engadir data e hora</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Se se marca, a data e hora atual será engadida ao nome do arquivo automáticamente.
Exemplo: Se o nome orixinal é &apos;test.mkv&quot;, o vídeo será nomeado como &apos;test-YYYY-DD_HH.MM.SS.mkv&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="227"/>
        <source>Warning: This format will produce unreadable files if the recording is interrupted! Consider using MKV instead.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="268"/>
        <location filename="../GUI/PageOutput.cpp" line="352"/>
        <source>Bit rate (in kbit/s):</source>
        <translation>Tasa de bits (en kbit/s):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>A tasa de bits do vídeo (en kilobits por segundo). Unha tasa maior implica unha maior calidade.
Se non sabes cómo axustalo, proba con 5000 e cámbiao se o necesitas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="272"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Esta opción cambia a calidade do vídeo. Un valor menor implica unha calidad maior.
O rango permitido está entre 0 e 51 (0 implica sen perdas, por defecto é 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="283"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="288"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>A velocidade de compresión. Unha maior velocidade usa menos CPU (permitindo grabar a maior FPS),
pero xera arquivos máis grandes. A calidade non debería alterarse moito.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="290"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU usada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="292"/>
        <source>fastest</source>
        <translation>máis rápido</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <source>slowest</source>
        <translation>máis lento</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="298"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>A velocidade de grabación. Un valor maior usa *menos* tempo de CPU (eu non escollín o nome, é o nome que usa o codificador VP8). Un valor maior implica menor calidade de vídeo, salvo que incrementes tamén a tasa de bits.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <location filename="../GUI/PageOutput.cpp" line="355"/>
        <source>Custom options:</source>
        <translation>Opcións personalizadas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <location filename="../GUI/PageOutput.cpp" line="357"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Opcións personalizadas do códec separadas por comas (ex opcion1=valor1,opcion2=valor2,opcion3=valor3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Allow frame skipping</source>
        <translation>Permitir saltar fotogramas</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="304"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Se se marca, o codificador de vídeo terá permiso para saltar fotogramas se a tasa de entrada é menor que a tasa de saída. Se non se marca, os fotogramas de entrada duplicaranse para tapar os buratos.
Esto incrementa o tamaño do arquivo e o uso de CPU, pero reduce a latencia en emisións en directo en algúns casos.
Non debería afectar ao aspecto do vídeo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Audio</source>
        <translation>Audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="337"/>
        <source>The codec that will be used to compress the audio stream. You shouldn&apos;t worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you&apos;re only recording your own voice (i.e. no music), the quality won&apos;t matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it&apos;s very fast.</source>
        <translation>O códec que se usará para comprimir o fluxo de audio. Non deberías preocuparte moito sobre
esto, porque o tamaño dos datos de audio normalmente é insignificante comparada co tamaño do vídeo.
E se só estás grabando a túa voz (sen música), entonces a calidade non importará en calquera caso.
- Vorbis (libvorbis) é bó e é o códec recomendado.
- MP3 (libmp3lame) é medianamente bó.
- AAC é un bó códec, pero a implementación usada eiquí (libvo_aacenc ou a experimental ffmpeg aac encoder)
   son moimalas. Úsaa só se non tés outra alternativa.
- Sen comprimir simplemente almacena os datos sen comprimilos. O arquivo será maior pero é moi rápido.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Para usuarios avanzados. Podes usar calquera códec de audio libav/ffmpeg, pero moitos deles non son útiles ou poderían non funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>La tasa de bits del audio (en kilobits por segundo). Una tasa mayor implica una mayor calidad. El valor típico es 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="379"/>
        <source>Back</source>
        <translation>Atrás</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="380"/>
        <source>Continue</source>
        <translation>Continuar</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="637"/>
        <location filename="../GUI/PageOutput.cpp" line="645"/>
        <source>not installed</source>
        <translation>non instalado</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <location filename="../GUI/PageOutput.cpp" line="647"/>
        <source>not supported by container</source>
        <translation>non soportado polo recipiente</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="690"/>
        <source>Save recording as</source>
        <translation>Gardar grabación como</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="528"/>
        <source>You did not select an output file!</source>
        <translation>¡Non seleccionaches un arquivo de saída!</translation>
    </message>
    <message>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation type="obsolete">El archivo &apos;%1&apos; ya existe. ¿Estás seguro que quieres sobreescribirlo?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="176"/>
        <source>Recording</source>
        <translation>Grabando</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="182"/>
        <source>Edit schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="183"/>
        <source>The recording schedule can be used to automatically start or pause the recording at a predefined time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="185"/>
        <source>Enable recording hotkey</source>
        <translation>Activar tecla rápida para grabar</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="186"/>
        <source>The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,
even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the
SimpleScreenRecorder window show up in the final video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="190"/>
        <source>Enable sound notifications</source>
        <translation>Activar notificacións con sonido</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="191"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="193"/>
        <source>Hotkey:</source>
        <translation>Tecla rápida:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="194"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="195"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="196"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="197"/>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="199"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>A tecla que terás que pulsar (combinada cos modificadores) para iniciar ou parar a grabación.
O programa que estás grabando non recibirá a pulsación das teclas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="252"/>
        <source>Information</source>
        <translation>Información</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="254"/>
        <source>Total time:</source>
        <translation>Tempo total:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="256"/>
        <source>FPS in:</source>
        <translation>FPS de entrada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="258"/>
        <source>FPS out:</source>
        <translation>FPS de saída:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="260"/>
        <source>Size in:</source>
        <translation>Tamaño de entrada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="262"/>
        <source>Size out:</source>
        <translation>Tamaño de saída:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="264"/>
        <source>File name:</source>
        <translation>Arquivo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="267"/>
        <source>File size:</source>
        <translation>Tamaño:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="269"/>
        <source>Bit rate:</source>
        <translation>Tasa de bits:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="271"/>
        <source>Show recording area</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="272"/>
        <source>When enabled, the recorded area is marked on the screen.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="297"/>
        <source>Preview</source>
        <translation>Vista previa</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="301"/>
        <source>Preview frame rate:</source>
        <translation>FPS da vista previa:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="305"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Nota: a vista previa require máis tempo de CPU (especialmente a altas tasas de fotogramas).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="354"/>
        <source>Log</source>
        <translation>Rexistro</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="369"/>
        <location filename="../GUI/PageRecord.cpp" line="377"/>
        <source>Cancel recording</source>
        <translation>Cancelar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="370"/>
        <location filename="../GUI/PageRecord.cpp" line="379"/>
        <source>Save recording</source>
        <translation>Gardar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="384"/>
        <source>Quit</source>
        <translation>Sair</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="435"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Non gardaches a grabación actual, se saes agora perderase.
¿Seguro que queres sair?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="447"/>
        <source>Hide window</source>
        <translation>Ocultar fiestra</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="449"/>
        <source>Show window</source>
        <translation>Amosar fiestra</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="659"/>
        <source>Starting page ...</source>
        <translation>Iniciando páxina ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="681"/>
        <location filename="../GUI/PageRecord.cpp" line="858"/>
        <location filename="../GUI/PageRecord.cpp" line="961"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Erro: algo foi mal durante a inicialización.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="690"/>
        <source>Started page.</source>
        <translation>Páxina iniciada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="723"/>
        <source>Stopping page ...</source>
        <translation>Detendo páxina ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="793"/>
        <source>Output file: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1022"/>
        <source>Encoding remaining data ...</source>
        <translation>Codificando a data restante...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1281"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1298"/>
        <source>Triggering scheduled action &apos;%1&apos; ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1309"/>
        <source>Schedule: %1 in %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1316"/>
        <source>Schedule: (none)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1320"/>
        <source>Schedule: (inactive)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1384"/>
        <location filename="../GUI/PageRecord.cpp" line="1401"/>
        <source>Standard input read error (%1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1389"/>
        <location filename="../GUI/PageRecord.cpp" line="1406"/>
        <source>Standard input closed (%1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1419"/>
        <source>Received command &apos;%1&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1439"/>
        <source>Unknown command.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="750"/>
        <source>Stopped page.</source>
        <translation>Páxina detida.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="779"/>
        <source>Starting output ...</source>
        <translation>Iniciando saída ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="804"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Erro: Non se puido obter o tamaño da aplicación OpenGL porque GLInject non foi creado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="809"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Erro: Non se puido obter o tamaño da aplicación OpenGL. Ou a aplicación non foi iniciada correctamente, ou a aplicación non creou aínda unha ventana OpenGL. Se queres empezar a grabar antes de iniciar a aplicación debes permitir o escalado e introducir o tamaño do vídeo manualmente.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application.</source>
        <translation type="obsolete">Error: No se pudo obtener el tamaño de la aplicación OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="848"/>
        <source>Started output.</source>
        <translation>Iniciada saída.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="869"/>
        <source>Stopping output ...</source>
        <translation>Detendo saída ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="887"/>
        <source>Stopped output.</source>
        <translation>Detida saída.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="919"/>
        <source>Starting input ...</source>
        <translation>Iniciando entrada ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="930"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Erro: Non se puido iniciar a entrada de GLInject porque aínda non foi creado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="956"/>
        <source>Started input.</source>
        <translation>Entrada iniciada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="988"/>
        <source>Stopping input ...</source>
        <translation>Detendo entrada ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1006"/>
        <source>Stopped input.</source>
        <translation>Detida entrada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1116"/>
        <location filename="../GUI/PageRecord.cpp" line="1126"/>
        <source>Pause recording</source>
        <translation>Pausar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1119"/>
        <location filename="../GUI/PageRecord.cpp" line="1129"/>
        <source>Start recording</source>
        <translation>Iniciar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1137"/>
        <source>Deactivate schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1147"/>
        <source>Activate schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1156"/>
        <source>Stop preview</source>
        <translation>Deter vista previa</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1159"/>
        <source>Start preview</source>
        <translation>Iniciar vista previa</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1200"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Erro: algo foi mal mentras se creaba a notificación de audio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1264"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>¿Estás seguro de querer cancelar a grabación?</translation>
    </message>
    <message>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation type="obsolete">Non grabaches nada, non hai nada que grabar.

O botón de grabación está na cima ;).</translation>
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
        <translation>&lt;p&gt;¡Benvido a SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;A pesares do nome, este programa realmente ten moitas opcións. Pero non te preocupes, só hai duas cousas que debes saber. Unha, as opcións por defecto soen estar ben. Se non sabes qué fai algo, só usa a opción por defecto. Duas, case todas as opcións teñen axudas contextuais. Pasa o rató sobre algo para descubrir qué fai.&lt;/p&gt;

&lt;p&gt;Para máis información:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="51"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Sobre SimpleScreenRecorder</translation>
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
        <translation>Continuar</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Grabar</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Grabar as opcións actuais a este perfil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Novo</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Crear un novo perfil coas opcións actuais.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Eliminar</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Eliminar este perfil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(ningún)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Erro: Non se pode cargar o perfil!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>¿Está seguro de queres sobreescribir este perfil?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Introduza un nome para o novo perfil:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Xa existe un perfil co mesmo nome. ¿Está seguro de querer reemplazalo?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>¿Esta seguro de quere eliminar este perfil?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation>&amp;Aceptar</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation>&amp;Cancelar</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Sí</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Sí, sempre</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Non</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Non, nunca</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="obsolete">Aviso: Formato de píxeles no soportado (%1 -&gt; %2), usando swscale en su lugar. Esto no es un problema, pero la calidad será peor.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="obsolete">Error: ¡No se pudo obtener el contexto de swscale!</translation>
    </message>
    <message>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="obsolete">Aviso: La memoria no está alineada para SSE, usando el conversor fallback en su lugar. Esto no es un problema, pero el rendimiento será peor.</translation>
    </message>
    <message>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Aviso: Ha habido un overrun, algunas muestras se han perdido.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Error: ¡No se puede recuperar el dispositivo tras el overrun!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Error: ¡No se puede iniciar el dispositivo PCM tras el overrun!</translation>
    </message>
    <message>
        <source>Stopping input thread ...</source>
        <translation type="obsolete">Deteniendo hilo de grabación ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation type="obsolete">Error: ¡No se puede abrir el dispositivo PCM!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation type="obsolete">Error: ¡No se pueden obtener los parámetros de hardware PCM!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set access type!</source>
        <translation type="obsolete">Error: ¡No se puede establecer el tipo de acceso!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample format!</source>
        <translation type="obsolete">Error: ¡No se puede establecer el formato de muestreo!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation type="obsolete">Error: ¡No se puede establecer una tasa de muestreo!</translation>
    </message>
    <message>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Aviso: La tasa de muestro %1 no está soportada, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set channel count!</source>
        <translation type="obsolete">Error: ¡No se puede establecer el número de canales!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set period size!</source>
        <translation type="obsolete">Error: ¡No se puede establecer el tamaño del periodo!</translation>
    </message>
    <message>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Aviso: El tamaño del periodo %1 no está soportado, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation type="obsolete">Error: ¡No se puede ajustar el tamaño del buffer!</translation>
    </message>
    <message>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Aviso: el tamaño del buffer %1 no está soportado, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation type="obsolete">Error: ¡No se pueden aplicar los parámetros de hardware PCM!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation type="obsolete">Error: ¡No se puede iniciar el dispositivo PCM!</translation>
    </message>
    <message>
        <source>Input thread started.</source>
        <translation type="obsolete">Hilo de entrada iniciado.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation type="obsolete">Error: ¡No se puede comprobar si las muestras están disponibles!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t read samples!</source>
        <translation type="obsolete">Error: ¡No se pueden leer las muestras!</translation>
    </message>
    <message>
        <source>Input thread stopped.</source>
        <translation type="obsolete">Hilo de entrada detenido.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation type="obsolete">Excepción &apos;%1&apos; en el hilo de entrada.</translation>
    </message>
    <message>
        <source>Unknown exception in input thread.</source>
        <translation type="obsolete">Excepción desconocida en el hilo de entrada.</translation>
    </message>
    <message>
        <source>Error: No streams found!</source>
        <translation type="obsolete">Error: ¡No se encontraron streams!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation type="obsolete">Error: ¡pa_mainloop_prepare falló!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="obsolete">Error: ¡pa_mainloop_poll falló!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="obsolete">Error: ¡pa_mainloop_dispatch falló!</translation>
    </message>
    <message>
        <source>Error: Could not create main loop!</source>
        <translation type="obsolete">Error: ¡No se pudo crear el bucle principal!</translation>
    </message>
    <message>
        <source>Error: Could not create context!</source>
        <translation type="obsolete">Error: ¡No se pudo crear un contexto!</translation>
    </message>
    <message>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation type="obsolete">Error: ¡No se pudo conectar! Motivo: %1
Es posible que tu sistema no use PulseAudio. Intenta usar el sistema de ALSA en su lugar.</translation>
    </message>
    <message>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation type="obsolete">Error: ¡Intento de conexión fallido! Motivo: %1</translation>
    </message>
    <message>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="obsolete">Error: ¡No se pudo crear el flujo! Motivo: %1</translation>
    </message>
    <message>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="obsolete">Error: ¡No se pudo conectar al flujo! Motivo: %1</translation>
    </message>
    <message>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="obsolete">Error: ¡El intento de conexión al flujo falló! Motivo: %1</translation>
    </message>
    <message>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="obsolete">Error: ¡No se pudo obtener los nombres de las fuentes! Motivo: %1</translation>
    </message>
    <message>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation type="obsolete">Error: ¡pa_stream_peek falló!</translation>
    </message>
    <message>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="obsolete">Aviso: la fuente de audio se suspendió. El segmento actual será detenido hasta que la fuente continúe.</translation>
    </message>
    <message>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="obsolete">Aviso: El flujo fue movido a otra fuente diferente.</translation>
    </message>
    <message>
        <source>Created video stream reader.</source>
        <translation type="obsolete">Creado lector de stream de vídeo.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation type="obsolete">Error: ¡No se puede abrir el archivo del stream de vídeo!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t lock video stream file!</source>
        <translation type="obsolete">Error: ¡No se puede bloquear el archivo del stream de víeo!</translation>
    </message>
    <message>
        <source>Error: Size of video stream file is incorrect!</source>
        <translation type="obsolete">Error: ¡El tamaño del stream de vídeo es incorrecto!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation type="obsolete">Error: ¡No se puede cargar en memoria el archivo del stream de vídeo!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation type="obsolete">Error: ¡no se puede abrir el archivo con el fotograma de vídeo!</translation>
    </message>
    <message>
        <source>Destroyed video stream reader.</source>
        <translation type="obsolete">Destruido lector de stream de vídeo.</translation>
    </message>
    <message>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation type="obsolete">Error: ¡El tamaño del archivo del fotograma de vídeo es incorrecto!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation type="obsolete">Error: ¡No se puede cargar el archivo del fotograma de vídeo en memoria!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Error: ¡No se puede inicializar inotify!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t watch shared memory directory!</source>
        <translation type="obsolete">Error: ¡No se puede vigilar el directory de memoria compartida!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open shared memory directory!</source>
        <translation type="obsolete">Error: ¡No se puede abrir el directorio de memoria compartida!</translation>
    </message>
    <message>
        <source>Added pre-existing stream %1.</source>
        <translation type="obsolete">Añadiendo stream pre-existente %1.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Error: ¡No se puede obtener la longitud desde inotify!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Error: ¡No se puede leer desde inotify!</translation>
    </message>
    <message>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Error: ¡Recibido evento parcial desde inotify!</translation>
    </message>
    <message>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Error: ¡Recibido nombre parcial desde inotify!</translation>
    </message>
    <message>
        <source>Added stream %1.</source>
        <translation type="obsolete">Añadido stream %1.</translation>
    </message>
    <message>
        <source>Warning: Tried to add stream %1, but it exists already!</source>
        <translation type="obsolete">Aviso: ¡Intentando añadir stream %1, pero ya existe!</translation>
    </message>
    <message>
        <source>Removed stream %1.</source>
        <translation type="obsolete">Eliminando stream %1.</translation>
    </message>
    <message>
        <source>Warning: Tried to remove stream %1, but it does not exist!</source>
        <translation type="obsolete">Aviso: ¡Intentando eliminar el stream %1, pero no existe!</translation>
    </message>
    <message>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="obsolete">Error: ¡Formato del píxel de la imagen X11 no soportado!</translation>
    </message>
    <message>
        <source>Error: Width or height is zero!</source>
        <translation type="obsolete">Error: ¡El ancho o el alto es cero!</translation>
    </message>
    <message>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="obsolete">Error: ¡Ancho o alto muy grande, el tamaño máximo de ancho y alto es %1!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="obsolete">Error: ¡No se pudo abrir el display X!</translation>
    </message>
    <message>
        <source>Using X11 shared memory.</source>
        <translation type="obsolete">Usando la memoria compartida de X11.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="obsolete">Error: ¡No se puede crear una imagen compartida!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="obsolete">Error: ¡No se puede obtener la memoria compartida!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="obsolete">Error: ¡No se puede acceder a la memoria compartida!</translation>
    </message>
    <message>
        <source>Not using X11 shared memory.</source>
        <translation type="obsolete">No se usa la memoria compartida X11.</translation>
    </message>
    <message>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="obsolete">Error: El servidor no soporta XFixes, el cursor está oculto.</translation>
    </message>
    <message>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="obsolete">Error: ¡Bounding box de la pantalla inválido!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="obsolete">Error: ¡No se puede conectar a la memoria compartida!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="obsolete">Error: ¡No se puede obtener la imagen (usando memoria compartida)!
    Normalmente esto significa que el área de grabación no está dentro de la pantalla. ¿O has cambiado la resolución de la pantalla?</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="obsolete">Error: ¡No se puede obtener la imagen (sin usar memoria compartida)!
    Normalmente esto significa que el área de grabación no está dentro de la pantalla. ¿O has cambiado la resolución de la pantalla?</translation>
    </message>
    <message>
        <source>Error: Sample rate it zero.</source>
        <translation type="obsolete">Error: La tasa de muestreo es cero.</translation>
    </message>
    <message>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation type="obsolete">Aviso: ¡La opción de códec &apos;%1&apos; no se reconoció!</translation>
    </message>
    <message>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="obsolete">Error: ¡El codificador requiere un formato de muestreo no soportado!</translation>
    </message>
    <message>
        <source>Error: Encoding of audio frame failed!</source>
        <translation type="obsolete">Error: ¡La codificación del audio falló!</translation>
    </message>
    <message>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="obsolete">Error: ¡La opción %1 no se pudo analizar!</translation>
    </message>
    <message>
        <source>Stopping encoder thread ...</source>
        <translation type="obsolete">Deteniendo hilo del codificador ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="obsolete">Error: ¡No se puede encontrar el códec!</translation>
    </message>
    <message>
        <source>Using codec %1 (%2).</source>
        <translation type="obsolete">Usando codec %1 (%2).</translation>
    </message>
    <message>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="obsolete">Aviso: este codec se considera experimental por libav/ffmpeg.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="obsolete">Error: ¡No se puede abrir el códec!</translation>
    </message>
    <message>
        <source>Encoder thread started.</source>
        <translation type="obsolete">Hilo del codificador iniciado.</translation>
    </message>
    <message>
        <source>Flushing encoder ...</source>
        <translation type="obsolete">Vaciando codificador ...</translation>
    </message>
    <message>
        <source>Encoder thread stopped.</source>
        <translation type="obsolete">Hilo del codificador detenido.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="obsolete">Excepción &apos;%1&apos; en el hilo del codificador.</translation>
    </message>
    <message>
        <source>Unknown exception in encoder thread.</source>
        <translation type="obsolete">Excepción desconocida en el hilo del codificador.</translation>
    </message>
    <message>
        <source>Stopping encoders ...</source>
        <translation type="obsolete">Deteniendo codificadores ...</translation>
    </message>
    <message>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="obsolete">Esperando al hilo muxer para detenerse ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="obsolete">Error: ¡No se puede escribir el encabezado!</translation>
    </message>
    <message>
        <source>Finishing encoders ...</source>
        <translation type="obsolete">Deteniendo codificadores ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="obsolete">Error: ¡No se puede crear un nuevo flujo!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="obsolete">Error: ¡No se puede obtener los ajustes por defecto del contexto del códec!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="obsolete">Error: ¡No se puede encontrar el formato de salida elegido!</translation>
    </message>
    <message>
        <source>Using format %1 (%2).</source>
        <translation type="obsolete">Usando formato %1 (%2).</translation>
    </message>
    <message>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="obsolete">Error: ¡No se puede asignar un contexto de formato!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="obsolete">Error: ¡No se puede abrir el archivo de salida!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="obsolete">Error: No se puede escribir el trailer, continuando de todos modos.</translation>
    </message>
    <message>
        <source>Muxer thread started.</source>
        <translation type="obsolete">Hilo del muxer iniciado.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="obsolete">Error: ¡No se puede escribir el fotograma en el muxer!</translation>
    </message>
    <message>
        <source>Muxer thread stopped.</source>
        <translation type="obsolete">Hilo del muxer detenido.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="obsolete">Excepción &apos;%1&apos; en el hilo del mutex.</translation>
    </message>
    <message>
        <source>Unknown exception in muxer thread.</source>
        <translation type="obsolete">Excepción desconocida en el hilo del mutex.</translation>
    </message>
    <message>
        <source>Stopping synchronizer thread ...</source>
        <translation type="obsolete">Deteniendo hilo del sincronizador...</translation>
    </message>
    <message>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="obsolete">Aviso: Se recibió un fotograma de vídeo con una marca de tiempo no monotónica.</translation>
    </message>
    <message>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="obsolete">Aviso: el buffer de vídeo se desbordó, algunos fotogramas se perderán. La entrada de audio es lenta.</translation>
    </message>
    <message>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="obsolete">Aviso: se recibieron muestras de audio con una marca de tiempo no monotónica.</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation type="obsolete">Aviso: ¡La entrada de audio es más de un 5% de lenta! {2%?}</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="obsolete">Aviso: ¡La entrada de audio es más de un 5% rápida! {2%?}</translation>
    </message>
    <message>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="obsolete">Aviso: el buffer de audio se desbordó, iniciando un nuevo segmento para mantener el audio sincronizado con el vídeo (se puede haber perdido algo de vídeo y/o audio). La entrada de vídeo parece ser muy lenta.</translation>
    </message>
    <message>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="obsolete">Aviso: La desincronización es muy alta, iniciando un nuevo segmento para mantener el audio en sincronía con el vídeo (puede que se haya perdido algo de audio y/o vídeo).</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 5% too slow!</source>
        <translation type="obsolete">Aviso: ¡La entrada de audio es más de un 5% de lenta!</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation type="obsolete">Aviso: ¡La entrada de audio es más de un 5% rápida!</translation>
    </message>
    <message>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="obsolete">Aviso: se recibió un hueco en el flujo de audio, iniciando un nuevo segmento para mantener el auydio en sincronía con el vídeo (algo de vídeo y/o de audio se puede haber perdido).</translation>
    </message>
    <message>
        <source>Synchronizer thread started.</source>
        <translation type="obsolete">Hilo del sincronizador iniciado.</translation>
    </message>
    <message>
        <source>Synchronizer thread stopped.</source>
        <translation type="obsolete">Hilo del sincronizador detenido.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="obsolete">Excepción &apos;%1&apos; en el hilo del sincronizador.</translation>
    </message>
    <message>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="obsolete">Excepción desconocida en el hilo del sincronizador.</translation>
    </message>
    <message>
        <source>Error: Width or height is not an even number!</source>
        <translation type="obsolete">Error: ¡El ancho o el alto no es un número par!</translation>
    </message>
    <message>
        <source>Error: Frame rate it zero!</source>
        <translation type="obsolete">Error: ¡La tasa de fotogramas es cero!</translation>
    </message>
    <message>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="obsolete">Error: ¡La codificación del vídeo falló!</translation>
    </message>
    <message>
        <source>Error: Flushing resampler failed! Reason: %s</source>
        <translation type="obsolete">Error: ¡No se pudo vaciar el remuestrador! Motivo: %s</translation>
    </message>
    <message>
        <source>Resampling from %1 to %2.</source>
        <translation type="obsolete">Remuestreando de %1 a %2.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create resampler! Reason: %s</source>
        <translation type="obsolete">Error: ¡No se puede crear el remuestreador! Motivo: %s</translation>
    </message>
    <message>
        <source>Resampling not needed.</source>
        <translation type="obsolete">No se necesita remuestrear.</translation>
    </message>
    <message>
        <source>Error: Resampling failed!</source>
        <translation type="obsolete">Error: ¡No se pudo remuestrear!</translation>
    </message>
    <message>
        <source>Warning: An underrun has occurred, some samples were too late.</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="obsolete">Aviso: ha habido un underrun, algunas muestras llegaron demasiado tarde.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="obsolete">Error: ¡No se puede recuperar el dispositivo tras el overrun!</translation>
    </message>
    <message>
        <source>Stopping synth thread ...</source>
        <translation type="obsolete">Deteniendo hilo del notificador de audio ...</translation>
    </message>
    <message>
        <source>Synth thread started.</source>
        <translation type="obsolete">Hilo del notificador de audio iniciado.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="obsolete">Error: ¡No se pueden escribir las muestras!</translation>
    </message>
    <message>
        <source>Synth thread stopped.</source>
        <translation type="obsolete">Hilo del notificador de audio detenido.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="obsolete">Excepción &apos;%1&apos; en el hilo del notificador de audio.</translation>
    </message>
    <message>
        <source>Unknown exception in synth thread.</source>
        <translation type="obsolete">Excepción desconocida en el hilo del notificador de audio.</translation>
    </message>
    <message>
        <source>CPU features</source>
        <translation type="obsolete">Características de la CPU</translation>
    </message>
    <message>
        <source>The application could not be launched.</source>
        <translation type="obsolete">La aplicación no pudo iniciarse.</translation>
    </message>
    <message>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="obsolete">Error: ¡El parámetro de línea de comandos &apos;%1&apos; no tiene un valor!</translation>
    </message>
    <message>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="obsolete">Error: ¡Parámetro de línea de comandos &apos;%1&apos; desconocido!</translation>
    </message>
    <message>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="obsolete">Error: ¡Argumento de la línea de comandos &apos;%1&apos; desconocido!</translation>
    </message>
    <message>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">SimpleScreenRecorder ha detectado que estás usando el driver propietario NVIDIA con la opción de flipping activada. Esto causa problemas durante la grabación. Se recomienda desactivar el flipping. ¿Quieres que lo haga por tí?

También puedes cambiar esta opción manualmente en el panel de control de NVIDIA.</translation>
    </message>
    <message>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">No he podido desactivar el flipping por alguna razón - ¡lo siento! Intenta desactivarlo desde el panel de control de NVIDIA.</translation>
    </message>
    <message>
        <source>SSR started</source>
        <translation type="obsolete">SSR iniciado</translation>
    </message>
    <message>
        <source>SSR stopped</source>
        <translation type="obsolete">SSR detenido</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="obsolete">Error: ¡No se puede crear el directorio .ssr!</translation>
    </message>
    <message>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation type="obsolete">Error: No se pudo leer el stream, esto suele indicar que el stream ya ha desaparecido.</translation>
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
        <translation>Diagrama de sincronización</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="257"/>
        <source>Video in</source>
        <translation>Entrada de vídeo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="258"/>
        <source>Audio in</source>
        <translation>Entrada de audio</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="259"/>
        <source>Video out</source>
        <translation>Saída de vídeo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="260"/>
        <source>Audio out</source>
        <translation>Saída de audio</translation>
    </message>
</context>
</TS>
