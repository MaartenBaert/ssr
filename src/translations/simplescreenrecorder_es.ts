<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="es_ES">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="79"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Acerca de SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="88"/>
        <source>For more information:</source>
        <translation>Para más información:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>The source code of this program can be found at:</source>
        <translation>El código fuente de este programa puede encontrarse en:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>This program uses:</source>
        <translation>Este programa usa:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 para la interfaz gráfica</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 o %2 (según tu distribución) para codificar el vídeo y el audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="93"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 para interceptar las llamadas a sistema para grabar OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="34"/>
        <source>OpenGL Settings</source>
        <translation>Opciones de OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="37"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Cuidado: la grabación de OpenGL funciona inyectando una librería en el programa que será grabado. Esta librería reemplazará algunas llamadas al sistema para capturar los fotogramas antes de que sean mostrados por pantalla. Si intentas grabar un juego que intente detectar hacks en el cliente, es (teóricamente) posible que el juego considere esto un hack. Esto podría provocar que te expulsen, así que es una buena idea comprobar que el programa que intentas grabar no te echará, *antes* de que lo intentes grabar. Te he avisado :).&lt;/p&gt;

Otro aviso: la grabación OpenGL es experimental, podría no funcionar o incluso hacer que el programa que estés grabando falle. ¡Si te preocupa perder datos de programa, guarda antes!&lt;/p&gt;

Si quieres grabar un juego de Steam, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;lee esto primero&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="51"/>
        <source>Launch application</source>
        <translation>Iniciar aplicación</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="53"/>
        <source>Command:</source>
        <translation>Comando:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="55"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Este comando se ejecutará para empezar el programa que se debe grabar.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="57"/>
        <source>Working directory:</source>
        <translation>Directorio de trabajo:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>El comando será ejecutado en este directorio. Si lo dejas en blanco, el directorio de trabajo no será cambiado.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="61"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Relajar permisos de memoria compartida (inseguro)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="62"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Si se marca, otros usuarios en la misma máquina serán capaces de usar la memoria compartida que se usa para comunicarse con el progrma OpenGL.
Esto significa que otros usuarios pueden (teóricamente) ver qué estás grabando, modificar los fotogramas, inyectar sus propios fotogramas, o simplemente interrumpir la comunicación.
Esto incluso funciona con usuarios que estén conectados de forma remota (ssh). Sólo deberías activar esto si necesitas grabar un programa que se ejecuta como otro usuario.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="66"/>
        <source>Launch automatically</source>
        <translation>Iniciar automáticamente</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="67"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Si se marca, la aplicación se ejecutará automáticamente una vez que llegues a la ventana de grabación. Si no se marca, deberás iniciarla manualmente..</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="69"/>
        <source>Launch now</source>
        <translation>Iniciar ahora</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="92"/>
        <source>Select stream</source>
        <translation>Seleccionar origen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="94"/>
        <source>Active streams:</source>
        <translation>Orígenes activos:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="97"/>
        <source>Record newest stream that matches:</source>
        <translation>Grabar la fuente más reciente que concuerde con:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>Error: Could not create stream watcher!</source>
        <translation>Error: ¡No se pudo crear el observador de fuentes!</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="214"/>
        <source>Error: Could not update streams!</source>
        <translation>Error: ¡No se pudieron actualizar las fuentes!</translation>
    </message>
    <message>
        <source>Record the latest stream that matches:</source>
        <translation type="obsolete">Grabar el último origen que concuerde:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="98"/>
        <source>User:</source>
        <translation>Usuario:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="100"/>
        <source>Process:</source>
        <translation>Proceso:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="102"/>
        <source>Source:</source>
        <translation>Fuente:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="104"/>
        <source>Program name:</source>
        <translation>Nombre de programa:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="106"/>
        <source>Limit application frame rate</source>
        <translation>Limitar la tasa de fotogramas de la aplicación</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="107"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Si se marca, la librería inyectada reducirá la velocidad de la aplicación para que la tasa de fotogramas no sea más alta que la tasa de fotogramas de grabación.
Esto evita que la aplicación gaste tiempo de CPU para fotogramas que no serán grabados, y a veces resulta en un vídeo más suave
(depende de la aplicación).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="131"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="29"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>La grabación se ha guardado. Ahora puedes editar el vídeo, o recodificarlo con mejores opciones para hacer el tamaño del archivo menor (las opciones por defecto están optimizadas para calidad y velocidad, no tamaño de archivo).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="32"/>
        <source>Back to the start screen</source>
        <translation>Volver a la pantalla inicial</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="94"/>
        <source>Video input</source>
        <translation>Entrada de vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="97"/>
        <source>Record the entire screen</source>
        <translation>Grabar la pantalla completa</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="98"/>
        <source>Record a fixed rectangle</source>
        <translation>Grabar un rectángulo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="99"/>
        <source>Follow the cursor</source>
        <translation>Seguir el cursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="100"/>
        <source>Record OpenGL (experimental)</source>
        <translation>Grabar OpenGL (experimental)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="106"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Selecciona qué monitor debería grabarse en una configuración multimonitor.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="107"/>
        <source>Select rectangle...</source>
        <translation>Seleccionar rectángulo...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="108"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Usa el ratón para seleccionar el rectángulo de grabación.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="109"/>
        <source>Select window...</source>
        <translation>Seleccionar ventana...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="110"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Usa el ratón para seleccionar una ventana que grabar.
Pista: Si haces clic sobre el borde de la ventana, la ventana completa será grabada (incluyendo bordes). De otro modo sólo
el área cliente de la ventana será grabado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="113"/>
        <source>OpenGL settings...</source>
        <translation>Opciones de OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="114"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Cambia las opciones para grabar OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="115"/>
        <source>Left:</source>
        <translation>Izquierda:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="119"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>La coordenada x de la esquina superior izquierda del rectángulo de grabación.
Pista: También puedes cambiar este valor con la rueda del ratón o con las flechas Arriba/Abajo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="121"/>
        <source>Top:</source>
        <translation>Arriba:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="125"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>La coordenada y de la esquina superior izquierda del rectángulo de grabación.
Pista: También puedes cambiar este valor con la rueda del ratón o con las flechas Arriba/Abajo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>Width:</source>
        <translation>Ancho:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="131"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>El ancho del rectángulo de grabación.
Pista: También puedes cambiar este valor con la rueda del ratón o con las flechas Arriba/Abajo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Height:</source>
        <translation>Alto:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="137"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>El alto del rectángulo de grabación.
Pista: También puedes cambiar este valor con la rueda del ratón o con las flechas Arriba/Abajo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="139"/>
        <source>Frame rate:</source>
        <translation>Tasa de fotogramas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="143"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>El número de fotogramas por segundo del vídeo. Una tasa mayor usa más tiempo de CPU.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="144"/>
        <source>Scale video</source>
        <translation>Escalar vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="145"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Activa o desactiva el escalado. El escalado usa más tiempo de CPU pero si el vídeo es más pequeño, podría codificarse más rápido.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="146"/>
        <source>Scaled width:</source>
        <translation>Ancho escalado:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="150"/>
        <source>Scaled height:</source>
        <translation>Alto escalado:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="154"/>
        <source>Record cursor</source>
        <translation>Grabar cursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="224"/>
        <source>Audio input</source>
        <translation>Entrada de audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="226"/>
        <source>Record audio</source>
        <translation>Grabar audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="227"/>
        <source>Backend:</source>
        <translation>Sistema:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="236"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>El sistema de audio que será usado para grabar.
El sistema ALSA también funcionará en sistmeas que usan PulseAudio, pero es mejor usar directamente el sistema PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="238"/>
        <source>Device:</source>
        <translation>Dispositivo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="240"/>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation>El dispositivo ALSA que será usado para grabar. Normalmente debería ser &apos;default&apos;.
Puedes cambiar esto por algo como plughw:0,0 (que normalmente significa tarjeta 0 entrada 0 con complementos activados).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Source:</source>
        <translation>Fuente:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>La fuente PulseAudio que será usada para grabar.
Un &apos;monitor&apos; es una fuente que graba el audio reproducido por otras aplicaciones.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="248"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="249"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Actualiza la lista de fuentes de PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="274"/>
        <source>Back</source>
        <translation>Atrás</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="275"/>
        <source>Continue</source>
        <translation>Continuar</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="597"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Todas las pantallas: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="601"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Pantalla %1: %2x%3 en %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="743"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Pantalla %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="775"/>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation>No has introducido un comando para iniciar la aplicación OpeNGL que intentas grabar.
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
        <location filename="../GUI/PageOutput.cpp" line="70"/>
        <location filename="../GUI/PageOutput.cpp" line="76"/>
        <location filename="../GUI/PageOutput.cpp" line="83"/>
        <source>Other...</source>
        <translation>Otros...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <source>Uncompressed</source>
        <translation>Sin comprimir</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="58"/>
        <location filename="../GUI/PageOutput.cpp" line="61"/>
        <location filename="../GUI/PageOutput.cpp" line="64"/>
        <location filename="../GUI/PageOutput.cpp" line="67"/>
        <location filename="../GUI/PageOutput.cpp" line="103"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>Archivos %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="137"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Error: ¡No se pudo encontrar ningún contenedor compatible en libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="141"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Error: ¡No se pudo encontrar ningún códec de vídeo en libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="145"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Error: ¡No se pudo encontrar ningún códec de audio en libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="149"/>
        <source>File</source>
        <translation>Archivo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="151"/>
        <source>Save as:</source>
        <translation>Guardar como:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="153"/>
        <source>The recording will be saved to this location.</source>
        <translation>La grabación se guardará en esta ubicación.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="154"/>
        <source>Browse...</source>
        <translation>Buscar...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="155"/>
        <source>Separate file per segment</source>
        <translation>Separar archivos por segmentos</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="156"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation>Si se marca, se creará un archvio de vídeo separado cada vez que pauses y continúes la grabación.
Si el archivo original se llama &apos;test.mkv&apos;, los segmentos se guardarán como &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
Los archivos que ya existan serán saltados.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="159"/>
        <source>Container:</source>
        <translation>Contenedor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="167"/>
        <source>The container (file format) that will be used to save the recording.
Note that not all codecs are supported by all containers, and that not all media players can read all file formats.
- Matroska (MKV) supports all the codecs, but is less well-known.
- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video
   (and many media players only support AAC audio).
- WebM is intended for embedding video into websites (with the HTML5 &lt;video&gt; tag). The format was created by Google.
   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.
   It supports only VP8 and Vorbis.
- OGG supports only Theora and Vorbis.</source>
        <translation>El contenedor (tipo de archivo) que se usará para guardar la grabación.
Ten en cuenta que no todos los códecs son soportados en todos los contenedores, y que no todos los reproductores pueden leer todos los formatos.
- Matroska (MKV) soporta todos los códecs, pero es el menos conocido.
- MP4 es el formato más conocido y se reproducirá en cualquier reproductor de vídeo moderno, pero sólo soporta vídeo H.264
   (y muchos reproductores multimedia sólo soportan audio AAC).
- WebM está diseñado para acoplar vídeo en las páginas web (usando el tag HTML5 &lt;video&gt;). El formato fue creado por Google.
   WebM está soportado por defecto en FIrefox, Chrome y Opera, y algunos plugins están disponibles para Internet Explorer y Safari.
   Sólo soporta VP8 y Vorbis.
- OGG soporta sólo Theora y Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="176"/>
        <source>Container name:</source>
        <translation>Nombre del contenedor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Para usuarios avanzados. Puedes usar cualquier formato de libav/ffmpeg, pero muchos de ellos son poco útiles o podrían no funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>Video</source>
        <translation>Vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <location filename="../GUI/PageOutput.cpp" line="280"/>
        <source>Codec:</source>
        <translation>Códec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="205"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>El códec que se usará para comprimir el flujo de vídeo.
- H.264 (libx264) es sin duda el mejor códec - alta calidad y muy rápido.
- VP8 (libvpx) es también bueno pero es un poco lento.
- Theora (libtheora) no se recomienda porque la calidad no es muy buena.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="209"/>
        <location filename="../GUI/PageOutput.cpp" line="293"/>
        <source>Codec name:</source>
        <translation>Nombre del códec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="215"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Para usuarios avanzados. Puedes usar cualquier códec de vídeo libav/ffmpeg, pero muchos de ellos no son útiles o podrían no funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="216"/>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <source>Bit rate (in kbps):</source>
        <translation>Tasa de bits (en kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="218"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>La tasa de bits del vídeo (en kilobits por segundo). Una tasa mayor implica una mayor calidad.
Si no tienes ni idea de cómo ajustarlo, prueba con 5000 y cámbialo si lo necesitas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Esta opción cambia la calidad de vídeo. Un valor menor implica una calidad mayor.
El rango permitido está entre 0 y 51 (0 implica sin pérdidas, por defecto es 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="231"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="236"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>La velocidad de compresión. Una mayor velocidad usa menos CPU (permitiendo grabar a mayor FPS),
pero provoca archivos más grandes. La calidad no debería alterarse mucho.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="238"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU usada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>fastest</source>
        <translation>más rápido</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="245"/>
        <source>slowest</source>
        <translation>más lento</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="246"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>La velocidad de grabación. Un valor mayor usa *menos* tiempo de CPU (yo no escogí el nombre, es el nombre
que usa el codificador VP8). Un valor mayor implica menor calidad de vídeo, salvo que incrementes la tasa de bits también.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="248"/>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Custom options:</source>
        <translation>Opciones personalizadas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <location filename="../GUI/PageOutput.cpp" line="305"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Opciones personalizadas del códec separadas por comas (ej opcion1=valor1,opcion2=valor2,opcion3=valor3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="251"/>
        <source>Allow frame skipping</source>
        <translation>Permitir saltar fotogramas</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="252"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Si se marca, el codificador de vídeo tendrá permiso para saltar fotogramas si la tasa de entrada es
menor que la tasa de salida. Si no se marca, los fotogramas de entrada se duplicarán para tapar los agujeros.
Esto incrementa el tamaño del archivo y el uso de CPU, pero reduce la latencia en emisiones en directo en algunos casos.
No debería afectar al aspecto del vídeo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="278"/>
        <source>Audio</source>
        <translation>Audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="285"/>
        <source>The codec that will be used to compress the audio stream. You shouldn&apos;t worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you&apos;re only recording your own voice (i.e. no music), the quality won&apos;t matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it&apos;s very fast.</source>
        <translation>El códec que usarás para comprimir el flujo de audio. No deberías preocuparte mucho sobre
esto, porque el tamaño de los datos de audio normalmente es insignificante comparada con el tamaño del vídeo.
Y si sólo estás grabando tu voz (sin música), entonces la calidad no importará en cualquier caso.
- Vorbis (libvorbis) es bueno y es el códec recomendado.
- MP3 (libmp3lame) es medianamente bueno.
- AAC es un buen códec, pero la implementación usada aquí (libvo_aacenc o la experimental ffmpeg aac encoder)
   son muy malas. Úsala sólo si no tienes otra alternativa.
- Sin comprimir simplemente almacena los datos sin comprimirlos. El archivo será mayor pero es muy rápido.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="299"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Para usuarios avanzados. Puedes usar cualquier códec de audio libav/ffmpeg, pero muchos de ellos no son útiles o podrían no funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>La tasa de bits del audio (en kilobits por segundo). Una tasa mayor implica una mayor calidad. El valor típico es 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="319"/>
        <source>Back</source>
        <translation>Atrás</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="320"/>
        <source>Continue</source>
        <translation>Continuar</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="546"/>
        <location filename="../GUI/PageOutput.cpp" line="554"/>
        <source>not installed</source>
        <translation>no instalado</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="548"/>
        <location filename="../GUI/PageOutput.cpp" line="556"/>
        <source>not supported by container</source>
        <translation>no soportado por el contenedor</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="599"/>
        <source>Save recording as</source>
        <translation>Guardar grabación como</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <source>You did not select an output file!</source>
        <translation>¡No seleccionaste un archivo de salida!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="644"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>El archivo &apos;%1&apos; ya existe. ¿Estás seguro que quieres sobreescribirlo?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="145"/>
        <source>Recording</source>
        <translation>Grabando</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="149"/>
        <source>Enable recording hotkey</source>
        <translation>Activar tecla rápida para grabar</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="150"/>
        <source>Enable sound notifications</source>
        <translation>Activar notificaciones de audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Hotkey:</source>
        <translation>Tecla rápida:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="153"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="154"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="155"/>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="157"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>La tecla que tendrás que pulsar (combinada con los modificadores) para iniciar o parar la grabación.
El programa que estás grabando no recibirá la pulsación de teclas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="197"/>
        <source>Information</source>
        <translation>Información</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="199"/>
        <source>Total time:</source>
        <translation>Tiempo total:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="201"/>
        <source>FPS in:</source>
        <translation>FPS de entrada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="203"/>
        <source>FPS out:</source>
        <translation>FPS de salida:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="205"/>
        <source>Size in:</source>
        <translation>Tamaño de entrada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="207"/>
        <source>Size out:</source>
        <translation>Tamaño de salida:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="209"/>
        <source>File name:</source>
        <translation>Archivo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="212"/>
        <source>File size:</source>
        <translation>Tamaño:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="214"/>
        <source>Bit rate:</source>
        <translation>Tasa de bits:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="237"/>
        <source>Preview</source>
        <translation>Vista previa</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="241"/>
        <source>Preview frame rate:</source>
        <translation>FPS de la vista previa:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="245"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Nota: la vista previa requiere más tiempo de CPU (especialmente a altas tasas de fotogramas).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="294"/>
        <source>Log</source>
        <translation>Registro</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="309"/>
        <location filename="../GUI/PageRecord.cpp" line="317"/>
        <source>Cancel recording</source>
        <translation>Cancelar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="310"/>
        <location filename="../GUI/PageRecord.cpp" line="316"/>
        <source>Save recording</source>
        <translation>Guardar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="364"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>No has guardado la grabación actual, si sales ahora se perderá.
¿De verdad quieres salir?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="514"/>
        <source>Starting page ...</source>
        <translation>Iniciando página ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="533"/>
        <location filename="../GUI/PageRecord.cpp" line="679"/>
        <location filename="../GUI/PageRecord.cpp" line="764"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Error: algo ha salido mal durante la inicialización.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="540"/>
        <source>Started page.</source>
        <translation>Página iniciada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="566"/>
        <source>Stopping page ...</source>
        <translation>Deteniendo página ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="591"/>
        <source>Stopped page.</source>
        <translation>Página detenida.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="618"/>
        <source>Starting output ...</source>
        <translation>Iniciando salida ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="629"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Error: No se pudo obtener el tamaño de la aplicación OpenGL porque GLInject no ha sido creado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="634"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Error: No se pudo obtener el tamaño de la aplicación OpenGL. O la aplicación no ha iniciado correctamente, o la aplicación no ha creado una ventana OpenGL todavía. Si quieres empezar a grabar antes de iniciar la grabación debes permitir el escalado e introducir el tamaño del vídeo manualmente.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application.</source>
        <translation type="obsolete">Error: No se pudo obtener el tamaño de la aplicación OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="670"/>
        <source>Started output.</source>
        <translation>Iniciada salida.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="690"/>
        <source>Stopping output ...</source>
        <translation>Deteniendo salida ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="708"/>
        <source>Stopped output.</source>
        <translation>Detenida salida.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="735"/>
        <source>Starting input ...</source>
        <translation>Iniciando entrada ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="740"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Error: No se pudo iniciar la entrada de GLInject porque aún no se ha creado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="759"/>
        <source>Started input.</source>
        <translation>Entrada iniciada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="784"/>
        <source>Stopping input ...</source>
        <translation>Deteniendo entrada ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="795"/>
        <source>Stopped input.</source>
        <translation>Detenida entrada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="858"/>
        <location filename="../GUI/PageRecord.cpp" line="872"/>
        <source>Pause recording</source>
        <translation>Pausar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="861"/>
        <location filename="../GUI/PageRecord.cpp" line="865"/>
        <location filename="../GUI/PageRecord.cpp" line="875"/>
        <source>Start recording</source>
        <translation>Iniciar grabación</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="883"/>
        <source>Stop preview</source>
        <translation>Detener vista previa</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="886"/>
        <source>Start preview</source>
        <translation>Iniciar vista previa</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="921"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Error: algo ha salido mal mientras se creaba la notificación de audio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="953"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>¿Estás seguro de que quieres cancelar la grabación?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="966"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>No has grabado nada, no hay nada que grabar.

El botón de grabación está arriba ;).</translation>
    </message>
</context>
<context>
    <name>PageWelcome</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="35"/>
        <source>&lt;p&gt;Welcome to SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Despite the name, this program actually has a lot of options. Don&apos;t worry though, there are really just two things that you need to know. One, the default settings are usually fine. If you don&apos;t know what something does, just use the default. Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.&lt;/p&gt;

&lt;p&gt;For more information:&lt;br&gt;
%1&lt;/p&gt;</source>
        <translation>&lt;p&gt;¡Bienvenido a SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;A pesar del nombre, este programa realmente tiene un montón de opciones. Pero no te preocupes, sólo hay dos cosas que debes saber. Una, las opciones por defecto suelen estar bien. Si no sabes qué hace algo, sólo usa la opción por defecto. Dos, casi todas las opciones tienen ayudas contextuales. Pon el ratón sobre algo para descubrir qué hace.&lt;/p&gt;

&lt;p&gt;Para más información:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="45"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Acerca de SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="46"/>
        <source>Continue</source>
        <translation>Continuar</translation>
    </message>
</context>
<context>
    <name>QMessageBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="31"/>
        <source>&amp;Yes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="33"/>
        <source>&amp;No</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <source>&amp;Cancel</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../AV/FastScaler.cpp" line="76"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Aviso: Formato de píxeles no soportado (%1 -&gt; %2), usando swscale en su lugar. Esto no es un problema, pero la calidad será peor.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="85"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Error: ¡No se pudo obtener el contexto de swscale!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="104"/>
        <location filename="../AV/FastScaler.cpp" line="127"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation>Aviso: La memoria no está alineada para SSE, usando el conversor fallback en su lugar. Esto no es un problema, pero el rendimiento será peor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Aviso: Ha habido un overrun, algunas muestras se han perdido.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Error: ¡No se puede recuperar el dispositivo tras el overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Error: ¡No se puede iniciar el dispositivo PCM tras el overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="52"/>
        <location filename="../AV/Input/X11Input.cpp" line="206"/>
        <source>Stopping input thread ...</source>
        <translation>Deteniendo hilo de grabación ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="89"/>
        <location filename="../AV/SimpleSynth.cpp" line="89"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Error: ¡No se puede abrir el dispositivo PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="93"/>
        <location filename="../AV/SimpleSynth.cpp" line="93"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Error: ¡No se pueden obtener los parámetros de hardware PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="99"/>
        <location filename="../AV/SimpleSynth.cpp" line="99"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Error: ¡No se puede establecer el tipo de acceso!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="105"/>
        <location filename="../AV/SimpleSynth.cpp" line="105"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Error: ¡No se puede establecer el formato de muestreo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="112"/>
        <location filename="../AV/SimpleSynth.cpp" line="112"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Error: ¡No se puede establecer una tasa de muestreo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
        <location filename="../AV/SimpleSynth.cpp" line="116"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Aviso: La tasa de muestro %1 no está soportada, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="124"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Error: ¡No se puede establecer el número de canales!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="131"/>
        <location filename="../AV/SimpleSynth.cpp" line="131"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Error: ¡No se puede establecer el tamaño del periodo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="135"/>
        <location filename="../AV/SimpleSynth.cpp" line="135"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Aviso: El tamaño del periodo %1 no está soportado, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="144"/>
        <location filename="../AV/SimpleSynth.cpp" line="144"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Error: ¡No se puede ajustar el tamaño del buffer!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="148"/>
        <location filename="../AV/SimpleSynth.cpp" line="148"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Aviso: el tamaño del buffer %1 no está soportado, usando %2 en su lugar. Esto no es un problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="156"/>
        <location filename="../AV/SimpleSynth.cpp" line="156"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Error: ¡No se pueden aplicar los parámetros de hardware PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="174"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Error: ¡No se puede iniciar el dispositivo PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="195"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="176"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="341"/>
        <source>Input thread started.</source>
        <translation>Hilo de entrada iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="215"/>
        <location filename="../AV/SimpleSynth.cpp" line="207"/>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation>Error: ¡No se puede comprobar si las muestras están disponibles!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="228"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Error: ¡No se pueden leer las muestras!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="254"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="228"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="387"/>
        <location filename="../AV/Input/X11Input.cpp" line="431"/>
        <source>Input thread stopped.</source>
        <translation>Hilo de entrada detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="258"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="232"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="391"/>
        <location filename="../AV/Input/X11Input.cpp" line="435"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Excepción &apos;%1&apos; en el hilo de entrada.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="261"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="235"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="394"/>
        <location filename="../AV/Input/X11Input.cpp" line="438"/>
        <source>Unknown exception in input thread.</source>
        <translation>Excepción desconocida en el hilo de entrada.</translation>
    </message>
    <message>
        <source>Error: No streams found!</source>
        <translation type="obsolete">Error: ¡No se encontraron streams!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Error: ¡pa_mainloop_prepare falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Error: ¡pa_mainloop_poll falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Error: ¡pa_mainloop_dispatch falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation>Error: ¡No se pudo crear el bucle principal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
        <source>Error: Could not create context!</source>
        <translation>Error: ¡No se pudo crear un contexto!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Error: ¡No se pudo conectar! Motivo: %1
Es posible que tu sistema no use PulseAudio. Intenta usar el sistema de ALSA en su lugar.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Error: ¡Intento de conexión fallido! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Error: ¡No se pudo crear el flujo! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Error: ¡No se pudo conectar al flujo! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Error: ¡El intento de conexión al flujo falló! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Error: ¡No se pudo obtener los nombres de las fuentes! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="312"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Error: ¡pa_stream_peek falló!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="375"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Aviso: la fuente de audio se suspendió. El segmento actual será detenido hasta que la fuente continúe.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="380"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Aviso: El flujo fue movido a otra fuente diferente.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="65"/>
        <source>Created video stream reader.</source>
        <translation>Creado lector de stream de vídeo.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="70"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Error: ¡No se puede abrir el archivo del stream de vídeo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t lock video stream file!</source>
        <translation>Error: ¡No se puede bloquear el archivo del stream de víeo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="85"/>
        <source>Error: Size of video stream file is incorrect!</source>
        <translation>Error: ¡El tamaño del stream de vídeo es incorrecto!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="93"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Error: ¡No se puede cargar en memoria el archivo del stream de vídeo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="102"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Error: ¡no se puede abrir el archivo con el fotograma de vídeo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="146"/>
        <source>Destroyed video stream reader.</source>
        <translation>Destruido lector de stream de vídeo.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="236"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Error: ¡El tamaño del archivo del fotograma de vídeo es incorrecto!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="245"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Error: ¡No se puede cargar el archivo del fotograma de vídeo en memoria!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="86"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Error: ¡No se puede inicializar inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="92"/>
        <source>Error: Can&apos;t watch shared memory directory!</source>
        <translation>Error: ¡No se puede vigilar el directory de memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="103"/>
        <source>Error: Can&apos;t open shared memory directory!</source>
        <translation>Error: ¡No se puede abrir el directorio de memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="121"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Añadiendo stream pre-existente %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="155"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Error: ¡No se puede obtener la longitud desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="164"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Error: ¡No se puede leer desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="174"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Error: ¡Recibido evento parcial desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="186"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Error: ¡Recibido nombre parcial desde inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="200"/>
        <source>Added stream %1.</source>
        <translation>Añadido stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="204"/>
        <source>Warning: Tried to add stream %1, but it exists already!</source>
        <translation>Aviso: ¡Intentando añadir stream %1, pero ya existe!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="210"/>
        <source>Removed stream %1.</source>
        <translation>Eliminando stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Warning: Tried to remove stream %1, but it does not exist!</source>
        <translation>Aviso: ¡Intentando eliminar el stream %1, pero no existe!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Error: ¡Formato del píxel de la imagen X11 no soportado!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="185"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="58"/>
        <source>Error: Width or height is zero!</source>
        <translation>Error: ¡El ancho o el alto es cero!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="189"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="62"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Error: ¡Ancho o alto muy grande, el tamaño máximo de ancho y alto es %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="232"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Error: ¡No se pudo abrir el display X!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="241"/>
        <source>Using X11 shared memory.</source>
        <translation>Usando la memoria compartida de X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="244"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Error: ¡No se puede crear una imagen compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="249"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Error: ¡No se puede obtener la memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="254"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Error: ¡No se puede acceder a la memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="260"/>
        <source>Not using X11 shared memory.</source>
        <translation>No se usa la memoria compartida X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="268"/>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Error: El servidor no soporta XFixes, el cursor está oculto.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="325"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Error: ¡Bounding box de la pantalla inválido!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="381"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Error: ¡No se puede conectar a la memoria compartida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="387"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Error: ¡No se puede obtener la imagen (usando memoria compartida)!
    Normalmente esto significa que el área de grabación no está dentro de la pantalla. ¿O has cambiado la resolución de la pantalla?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="398"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Error: ¡No se puede obtener la imagen (sin usar memoria compartida)!
    Normalmente esto significa que el área de grabación no está dentro de la pantalla. ¿O has cambiado la resolución de la pantalla?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="45"/>
        <source>Error: Sample rate it zero.</source>
        <translation>Error: La tasa de muestreo es cero.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="63"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="104"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation>Aviso: ¡La opción de códec &apos;%1&apos; no se reconoció!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="132"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Error: ¡El codificador requiere un formato de muestreo no soportado!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="155"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Error: ¡La codificación del audio falló!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="33"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Error: ¡La opción %1 no se pudo analizar!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="73"/>
        <source>Stopping encoder thread ...</source>
        <translation>Deteniendo hilo del codificador ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="93"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Error: ¡No se puede encontrar el códec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="98"/>
        <source>Using codec %1 (%2).</source>
        <translation>Usando codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="107"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Aviso: este codec se considera experimental por libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="117"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Error: ¡No se puede abrir el códec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="171"/>
        <source>Encoder thread started.</source>
        <translation>Hilo del codificador iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="200"/>
        <source>Flushing encoder ...</source>
        <translation>Vaciando codificador ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="207"/>
        <source>Encoder thread stopped.</source>
        <translation>Hilo del codificador detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="211"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Excepción &apos;%1&apos; en el hilo del codificador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="214"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Excepción desconocida en el hilo del codificador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="72"/>
        <source>Stopping encoders ...</source>
        <translation>Deteniendo codificadores ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="79"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Esperando al hilo muxer para detenerse ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Error: ¡No se puede escribir el encabezado!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="111"/>
        <source>Finishing encoders ...</source>
        <translation>Deteniendo codificadores ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="143"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Error: ¡No se puede crear un nuevo flujo!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="149"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Error: ¡No se puede obtener los ajustes por defecto del contexto del códec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="195"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Error: ¡No se puede encontrar el formato de salida elegido!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Using format %1 (%2).</source>
        <translation>Usando formato %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="204"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Error: ¡No se puede asignar un contexto de formato!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="211"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Error: ¡No se puede abrir el archivo de salida!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="224"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Error: No se puede escribir el trailer, continuando de todos modos.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="257"/>
        <source>Muxer thread started.</source>
        <translation>Hilo del muxer iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="311"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Error: ¡No se puede escribir el fotograma en el muxer!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="339"/>
        <source>Muxer thread stopped.</source>
        <translation>Hilo del muxer detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="343"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Excepción &apos;%1&apos; en el hilo del mutex.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="346"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Excepción desconocida en el hilo del mutex.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="119"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Deteniendo hilo del sincronizador...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="237"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Aviso: Se recibió un fotograma de vídeo con una marca de tiempo no monotónica.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="269"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Aviso: el buffer de vídeo se desbordó, algunos fotogramas se perderán. La entrada de audio es lenta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="341"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Aviso: se recibieron muestras de audio con una marca de tiempo no monotónica.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="365"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Aviso: el buffer de audio se desbordó, iniciando un nuevo segmento para mantener el audio sincronizado con el vídeo (se puede haber perdido algo de vídeo y/o audio). La entrada de vídeo parece ser muy lenta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="388"/>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Aviso: La desincronización es muy alta, iniciando un nuevo segmento para mantener el audio en sincronía con el vídeo (puede que se haya perdido algo de audio y/o vídeo).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="398"/>
        <source>Warning: Audio input is more than 5% too slow!</source>
        <translation>Aviso: ¡La entrada de audio es más de un 5% de lenta!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="402"/>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation>Aviso: ¡La entrada de audio es más de un 5% rápida!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="432"/>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Aviso: se recibió un hueco en el flujo de audio, iniciando un nuevo segmento para mantener el auydio en sincronía con el vídeo (algo de vídeo y/o de audio se puede haber perdido).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="712"/>
        <source>Synchronizer thread started.</source>
        <translation>Hilo del sincronizador iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="734"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Hilo del sincronizador detenido.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="738"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Excepción &apos;%1&apos; en el hilo del sincronizador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="741"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Excepción desconocida en el hilo del sincronizador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="66"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Error: ¡El ancho o el alto no es un número par!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="70"/>
        <source>Error: Frame rate it zero!</source>
        <translation>Error: ¡La tasa de fotogramas es cero!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="213"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="233"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Error: ¡La codificación del vídeo falló!</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="73"/>
        <source>Error: Flushing resampler failed! Reason: %s</source>
        <translation>Error: ¡No se pudo vaciar el remuestrador! Motivo: %s</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="90"/>
        <source>Resampling from %1 to %2.</source>
        <translation>Remuestreando de %1 a %2.</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="96"/>
        <source>Error: Can&apos;t create resampler! Reason: %s</source>
        <translation>Error: ¡No se puede crear el remuestreador! Motivo: %s</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="100"/>
        <source>Resampling not needed.</source>
        <translation>No se necesita remuestrear.</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="140"/>
        <source>Error: Resampling failed!</source>
        <translation>Error: ¡No se pudo remuestrear!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="27"/>
        <source>Warning: An underrun has occurred, some samples were too late.</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Aviso: ha habido un underrun, algunas muestras llegaron demasiado tarde.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="29"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Error: ¡No se puede recuperar el dispositivo tras el overrun!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Stopping synth thread ...</source>
        <translation>Deteniendo hilo del notificador de audio ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="189"/>
        <source>Synth thread started.</source>
        <translation>Hilo del notificador de audio iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="257"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Error: ¡No se pueden escribir las muestras!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="265"/>
        <source>Synth thread stopped.</source>
        <translation>Hilo del notificador de audio detenido.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="269"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Excepción &apos;%1&apos; en el hilo del notificador de audio.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="272"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Excepción desconocida en el hilo del notificador de audio.</translation>
    </message>
    <message>
        <location filename="../common/DetectCPUFeatures.cpp" line="39"/>
        <source>CPU features</source>
        <translation>Características de la CPU</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="204"/>
        <source>The application could not be launched.</source>
        <translation>La aplicación no pudo iniciarse.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="116"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Error: ¡El parámetro de línea de comandos &apos;%1&apos; no tiene un valor!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="144"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Error: ¡Parámetro de línea de comandos &apos;%1&apos; desconocido!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="154"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Error: ¡Argumento de la línea de comandos &apos;%1&apos; desconocido!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="181"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder ha detectado que estás usando el driver propietario NVIDIA con la opción de flipping activada. Esto causa problemas durante la grabación. Se recomienda desactivar el flipping. ¿Quieres que lo haga por tí?

También puedes cambiar esta opción manualmente en el panel de control de NVIDIA.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="186"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>No he podido desactivar el flipping por alguna razón - ¡lo siento! Intenta desactivarlo desde el panel de control de NVIDIA.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="192"/>
        <source>SSR started</source>
        <translation>SSR iniciado</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="201"/>
        <source>SSR stopped</source>
        <translation>SSR detenido</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="209"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Error: ¡No se puede crear el directorio .ssr!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="144"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Error: No se pudo leer el stream, esto suele indicar que el stream ya ha desaparecido.</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="49"/>
        <source>Synchronization Diagram</source>
        <translation>Diagrama de sincronización</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="187"/>
        <source>Video in</source>
        <translation>Entrada de vídeo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="188"/>
        <source>Audio in</source>
        <translation>Entrada de audio</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="189"/>
        <source>Video out</source>
        <translation>Salida de vídeo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="190"/>
        <source>Audio out</source>
        <translation>Salida de audio</translation>
    </message>
</context>
</TS>
