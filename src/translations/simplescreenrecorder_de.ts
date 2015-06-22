<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="de_DE">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="78"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Über SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="87"/>
        <source>For more information:</source>
        <translation>Für weitere Informationen:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="88"/>
        <source>The source code of this program can be found at:</source>
        <translation>Der Quellcode dieses Programmes befindet sich hier:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>This program uses:</source>
        <translation>Dieses Programm verwendet:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 für das graphische User-Interface</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 oder %2 (abhängig von Ihrer Distribution) für Video/Audio-Encoding</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 für die System-Funktion zur OpenGL-Aufnahme</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="34"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL EInstellungen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="37"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Achtung: OpenGL-Aufnahme funktioniert durch das injizieren einer Bibliothek in das aufzunehmende Programm. Diese Bibliothek wird einige System-Funktionen außer Kraft setzen, um die Bilder abzugreifen, bevor sie auf dem Bildschirm angezeigt werden. Wenn Sie ein Spiel aufnehmen möchten, dass zu erkennen versucht, ob es client-seitig gehackt wurde, ist es (theoretisch) möglich, das dies das Spiel fälschlicherweise als &quot;Hack&quot; erkennt. Das könnte sogar zu einem &quot;Bann&quot; führen. Also versichern Sie sich erst, dass das aufzunehmende Programm sie nicht &quot;bannt&quot;, *bevor* Sie versuchen, es aufzunehmen. Sie wurden gewarnt. :). &lt;/p&gt;

&lt;p&gt;Eine weitere Warnung: OpenGL-Aufnahme ist experimentell, könnte nicht funktionieren oder sogar das Programm zum Absturz bringen welches Sie aufnehmen möchten. Wenn Sie sich Gedanken über mögliche Datenverluste machen, fertigen Sie zuerst ein Backup an!&lt;/p&gt;

Wenn Sie Steam-Spiele aufnehmen möchten,&lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;lesen Sie zuerst dies&lt;/a&gt;.&lt;/p&gt; </translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="51"/>
        <source>Choose channel</source>
        <translation>Kanal wählen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="53"/>
        <source>Channel name:</source>
        <translation>Name des Kanals:</translation>
    </message>
    <message>
        <source>Channel names are used to identify applications. You only need to change this if you want to record multiple applications at the same time.</source>
        <translation type="obsolete">Kanal-Namen werden zur Identifikation von Applikationen verwendet. Sie müssen dies nur ändern, wenn Sie mehrere Applikationen gleichzeitig aufnehmen möchten.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="55"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Kanal Namen werden für die Identifikation von Anwendungen benutzt. Sie müssen nur geändert werden wenn Sie mehrere Anwendungen zur gleichen Zeit aufnehmen wollen.
Wenn leer gelassen wird der Standard Kanal &apos;channel-DEINBENUTZERNAME&apos; verwendet.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="57"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Berechtigung des geteilten Speichers lockern (unsicher)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Wenn ausgewählt, können andere Benutzer auf dieser Maschine auf das selbe geteilte Speicher-Segment zugreifen, welches für die Kommunikation mit dem OpenGL-Programm verwendet wird.
Dies bedeutet, dass andere Benutzer (theoretisch) sehen können was Sie aufnehmen, die Einzelbilder modifizieren, ihre eigenen Bilder einfügen oder einfach die Kommunikation trennen können. Dies trifft sogar für Benutzer zu, die aus der Ferne eingeloggt sind (ssh). Sie sollten dies nur aktivieren, wenn Sie ein Programm aufnehmen möchten, welches unter einem anderen Benutzer-Kontext läuft. </translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="73"/>
        <source>Launch application</source>
        <translation>Applikation starten</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="75"/>
        <source>Command:</source>
        <translation>Befehl:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="77"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Dieser Befehl wird ausgeführt um das aufzunehmende Programm zu starten.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="79"/>
        <source>Working directory:</source>
        <translation>Arbeitsverzeichnis:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="81"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Der Befehl wird in diesem Verzeichnis ausgeführt. Wenn Sie dies leer lassen, wird das Verzeichnis nicht verändert.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="83"/>
        <source>Launch automatically</source>
        <translation>Automatisch starten</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Wenn ausgewählt, wird die Applikation automatisch gestartet, sobald sie auf die Aufnahme-Seite wechseln. Wenn nicht ausgewählt, müssen Sie sie von Hand starten.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="86"/>
        <source>Launch now</source>
        <translation>Jetzt starten</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="107"/>
        <source>Stream settings</source>
        <translation>Stream Einstellungen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="109"/>
        <source>Limit application frame rate</source>
        <translation>Bild-Rate der Applikation begrenzen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Wenn ausgewählt, wird die injizierende Bibliothek die Applikation verlangsamen, so dass die Bild-Rate nicht höher wird als die aufzunehmende Bild-Rate.
Dies hält die Applikation davon ab, CPU-Zeit für Bilder zu verschwenden, die nicht aufgenommen werden, und kann manchmal zu einem weicheren Video führen
(abhängig von der Applikation).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="119"/>
        <source>Close</source>
        <translation>Schließen</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Fehler: Resample Rate außerhalb des Bereichs!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Fehler: Drift Rate außerhalb des Bereichs!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Resample Rate ist %1 (war %2).</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="116"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Warnung: Pixel-Format wird nicht unterstützt (%1 -&gt; %2), es wird swscale anstelle verwendet. Das ist kein Problem, aber die Performance wird schlechter sein.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="125"/>
        <location filename="../Benchmark.cpp" line="119"/>
        <location filename="../Benchmark.cpp" line="200"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Fehler: Konnte den swscale Kontext nicht erhalten!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="147"/>
        <location filename="../AV/FastScaler.cpp" line="172"/>
        <location filename="../AV/FastScaler.cpp" line="197"/>
        <location filename="../AV/FastScaler.cpp" line="219"/>
        <location filename="../AV/FastScaler.cpp" line="242"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation>Warnung: der Speicher ist nicht richtig für SSE ausgerichtet, es wird ein Rückgriff-Konvertierer statt dessen verwendet. Das ist kein Problem, aber die Performance wird schlechter sein.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Warnung: Ein overrun wurde festgestellt, einige Samples sind verloren.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fehler: Kann das Gerät nach einem overrun nicht wieder erlangen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fehler: Kann das PCM-Gerät nach einem overrun nicht starten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="63"/>
        <location filename="../AV/Input/JACKInput.cpp" line="56"/>
        <location filename="../AV/Input/X11Input.cpp" line="207"/>
        <source>Stopping input thread ...</source>
        <translation>Stoppe Eingabe Prozess...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="96"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="232"/>
        <source>Generating source list ...</source>
        <translation>Generiere Quell-Liste...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="115"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Fehler: die ALSA-Konfiguration konnte nicht aktualisiert werden!</translation>
    </message>
    <message>
        <source>Warning: Could not find PCM plugins.</source>
        <translation type="obsolete">Warnung: es konnten keine PCM-PLugins gefunden werden.</translation>
    </message>
    <message>
        <source>Found plugin %1 = %2.</source>
        <translation type="obsolete">Plugin gefunden %1 = %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="175"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Warnung: konnte die Sound-Karte %1 nicht öffnen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Warnung: konnte keine Informationen für Sound-Karte %1 abrufen.</translation>
    </message>
    <message>
        <source>Found card %1 = %2.</source>
        <translation type="obsolete">Karte gefunden %1 = %2. </translation>
    </message>
    <message>
        <source>Found device %1 = %2.</source>
        <translation type="obsolete">Gerät gefunden %1 = %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="162"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Plugin gefunden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="185"/>
        <source>Found card: [%1] %2</source>
        <translation>Karte gefunden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="210"/>
        <source>Found device: [%1] %2</source>
        <translation>Gerät gefunden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="259"/>
        <location filename="../AV/SimpleSynth.cpp" line="123"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Fehler: konnte das PCM-Gerät nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="263"/>
        <location filename="../AV/SimpleSynth.cpp" line="127"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Fehler: konnte keine PCM-Hardware-Parameter abrufen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="269"/>
        <location filename="../AV/SimpleSynth.cpp" line="133"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Fehler: konnte Zugriffs-Typ nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="139"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Fehler: konnte das Sample-Format nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="282"/>
        <location filename="../AV/SimpleSynth.cpp" line="146"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Fehler: konnte die Sample-Rate nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="286"/>
        <location filename="../AV/SimpleSynth.cpp" line="150"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Warnung: Sample-Rate %1 wird nicht unterstützt, es wird statt dessen %2 verwendet. Das ist kein Problem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="295"/>
        <location filename="../AV/SimpleSynth.cpp" line="158"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Fehler: konnte die Kanal-Anzahl nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="299"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Warnung: Kanal-Anzahl %1 wird nicht unterstützt, benutze statt dessen %2. Das ist kein Problem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="308"/>
        <location filename="../AV/SimpleSynth.cpp" line="165"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Fehler: Konnte die Zeitraum-Größe nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="312"/>
        <location filename="../AV/SimpleSynth.cpp" line="169"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Warnung: Zeitraum-Größe %1 wird nicht unterstützt, es wird %2 anstatt verwendet. Das ist kein Problem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="321"/>
        <location filename="../AV/SimpleSynth.cpp" line="178"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Fehler: Konnte die Puffer-Größe nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/SimpleSynth.cpp" line="182"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Warnung: Puffer-Größe %1 wird nicht unterstützt, es wird %2 anstatt verwendet. Das ist kein Problem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="333"/>
        <location filename="../AV/SimpleSynth.cpp" line="190"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Fehler: konnte die PCM-Hardware Parameters nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="351"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Fehler: Kann das PCM-Gerät nicht starten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="372"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="180"/>
        <location filename="../AV/Input/JACKInput.cpp" line="238"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="299"/>
        <location filename="../AV/Input/X11Input.cpp" line="345"/>
        <source>Input thread started.</source>
        <translation>Eingabe-Prozess gestartet.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="387"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Fehler: konnte keine Samples lesen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="413"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="248"/>
        <location filename="../AV/Input/JACKInput.cpp" line="289"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="388"/>
        <location filename="../AV/Input/X11Input.cpp" line="444"/>
        <source>Input thread stopped.</source>
        <translation>Eingabe-Prozess angehalten.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="417"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="252"/>
        <location filename="../AV/Input/JACKInput.cpp" line="293"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="392"/>
        <location filename="../AV/Input/X11Input.cpp" line="448"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Ausnahme &apos;%1&apos; im Eingabe-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="420"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="255"/>
        <location filename="../AV/Input/JACKInput.cpp" line="296"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="395"/>
        <location filename="../AV/Input/X11Input.cpp" line="451"/>
        <source>Unknown exception in input thread.</source>
        <translation>Unbekannte Ausnahme im Eingabe-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="149"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Fehler: konnte keinen Stream lesen, das bedeutet üblicherweise das der Stream schon nicht mehr da war.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="72"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Fehler: konnte nicht zu JACK verbinden!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="81"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Fehler: konnte keinen JACK-Port erzeugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="87"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Fehler: konnte keinen JACK Callback-Prozess setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="91"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Fehler: konnte keine JACK Callback-Sample-Rate setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="95"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Fehler: konnte keinen JACK xrun-Callback setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="99"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Fehler: konnte keinen JACK Verbindungs-Port Callback setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Fehler: konnte den JACK-Client nicht aktivieren!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <location filename="../AV/Input/JACKInput.cpp" line="123"/>
        <location filename="../AV/Input/JACKInput.cpp" line="252"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Verbinde Port %1 nach %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="256"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>Trenne Port %1 von %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Fehler: pa_mainloop_prepare fehlgeschlagen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Fehler: pa_mainloop_poll fehlgeschlagen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Fehler: pa_mainloop_dispatch fehlgeschlagen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation>Fehler: konnte die Haupt-Schleife nicht erzeugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
        <source>Error: Could not create context!</source>
        <translation>Fehler: konnte keinen Kontext erzeugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Fehler: Konnte keine Verbindung herstellen. Grund: %1
Es ist möglich, dass ihr System kein PulseAudio verwendet. Versuchen Sie es statt dessen mit ALSA.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Fehler: Verbindungs-Versuch fehlgeschlagen. Grund: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Fehler: konnte keinen Stream erzeugen. Grund: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Fehler: konnte keinen Stream verbinden. Grund: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Fehler: Stream-Verbindungs-Versuch fehlgeschlagen. Grund: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="223"/>
        <source>Found source: [%1] %2</source>
        <translation>Quelle gefunden: [%1] %2</translation>
    </message>
    <message>
        <source>Got %1 = %2.</source>
        <translation type="obsolete">Erhielt %1 = %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Fehler: konnte die Namen der Quellen nicht erhalten. Grund: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="313"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Fehler: pa_stream_peek fehlgeschlagen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="377"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Warnung: Audio-Quelle wurde ausgesetzt. Das aktuelle segment wird gestoppt, bis die Quelle wieder fortgesetzt wird.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="382"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Warnung: Stream wurde zu einer anderen Quelle bewegt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation>Video Stream Reader wurde erzeugt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Fehler: konnte die Video-Stream-Datei nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation>Fehler: konnte die Video-Stream-Datei nicht in der Größe verändern!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Fehler: konnte die Video-Stream-Datei nicht mit dem Speicher zusammenführen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Fehler: konnte die Video-Frame-Datei nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation>Video-Stream-Reader wurde zerstört.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Fehler: Größe der Video-Frame-Datei ist falsch!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Fehler: konnte die Video-Frame-Datei nicht mit dem Speicher zusammenführen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="88"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation>Fehler: konnte kein Kanal-Verzeichnis erzeugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="95"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation>Fehler: konnte das Kanal-Verzeichnis nicht testen - überprüfen Sie die Zugriffsrechte!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="99"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Fehler: Kanal-Verzeichnis ist kein normales Verzeichnis!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="104"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation>Fehler: konnte die Zugriffsrechte auf dem Kanal-Verzeichnis nicht setzen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="109"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Fehler: Kanal-Verzeichnis gehört einem anderem Benutzer! Verwenden Sie einen anderen Kanal-Namen, oder schalten Sie Sie gelockerte Datei-Berechtigungen an, um es dennoch zu verwenden.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="121"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fehler: konnte inotify nicht initialisieren!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t watch shared memory directory!</source>
        <translation type="obsolete">Fehler: konnte das geteilte Speicher-Verzeichnis nicht beobachten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="127"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation>Fehler: kann das Kanal-Verzeichnis nicht überwachen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open shared memory directory!</source>
        <translation type="obsolete">Fehler: konnte das geteilte Speicher-Verzeichnis nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="139"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation>Fehler: kann das Kanal-Verzeichnis nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="157"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Bereits existierender Stream %1 hinzugefügt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="192"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fehler: konnte die Lese-Länge von inotify nicht erhalten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="200"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fehler: konnte von inotify nicht lesen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="210"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fehler: teilweises Ereignis von inotify erhalten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="222"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fehler: teilweiser Name von inotify erhalten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="236"/>
        <source>Added stream %1.</source>
        <translation>Stream %1 hinzugefügt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="244"/>
        <source>Removed stream %1.</source>
        <translation>Stream %1 entfernt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="270"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Verwaister Stream %1 gelöscht.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Fehler: Nicht unterstütztes X11 Image-Pixel-Format!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="186"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="112"/>
        <source>Error: Width or height is zero!</source>
        <translation>Fehler: Breite oder Höhe ist Null!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="190"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="116"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Fehler: Breite oder Höhe ist zu groß, maximal erlaubte Breite und Höhe ist %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="236"/>
        <location filename="../GUI/HotkeyListener.cpp" line="118"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Fehler: konnte das X-Display nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="245"/>
        <source>Using X11 shared memory.</source>
        <translation>Verwende X11 geteilten Speicher.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Fehler: konnte kein geteiltes Image erzeugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="253"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Fehler: konnte keinen geteilten Speicher erhalten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Fehler: kann nicht mit geteiltem Speicher verbinden!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="264"/>
        <source>Not using X11 shared memory.</source>
        <translation>Verwende keinen X11 geteilten Speicher.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="271"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Warnung: XFixes wird nicht vom X server unterstützt, der Cursor wird verborgen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="329"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Fehler: falsche Bounding-Box des Bildschirms!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="393"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Fehler: kann den Server nicht mit dem geteiltem Speicher verbinden!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="399"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Fehler: konnte kein Bild erhalten (mit geteiltem Speicher)!
    Üblicherweise bedeutet dies, dass der Aufnahme-Bereich nicht vollständig innerhalb des Bildschirms liegt. Oder haben Sie die Bildschirm-Auflösung verändert?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="410"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Fehler: konnte kein Bild erhalten (ohne geteiltem Speicher)!
    Üblicherweise bedeutet dies, dass der Aufnahme-Bereich nicht vollständig innerhalb des Bildschirms liegt. Oder haben Sie die Bildschirm-Auflösung verändert?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="99"/>
        <source>Error: Channel count is zero.</source>
        <translation>Fehler: Anzahl der Kanäle ist Null.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="103"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Fehler: Sample-Rate ist null.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="140"/>
        <source>Using sample format %1.</source>
        <translation>Verwende Sample-Format %1</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="145"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Fehler: Enkodierer erfordert ein nicht unterstütztes Sample-Format!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Fehler: Kodieren eines Audio-Frames fehlgeschlagen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="31"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="40"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Fehler: Option &apos;%1&apos; wurde nicht erkannt!</translation>
    </message>
    <message>
        <source>Warning: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="obsolete">Warnung: Option &apos;%1&apos; wurde nicht verstanden!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation>Stoppe Kodierungs-Prozess...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="155"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Fehler: konnte Codec nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="163"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation>Fehler: Codec-Option &apos;%1&apos; wurde nicht erkannt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="179"/>
        <source>Encoder thread started.</source>
        <translation>Starte Kodierungs-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="211"/>
        <source>Flushing encoder ...</source>
        <translation>Kodierer wird geleert...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="225"/>
        <source>Encoder thread stopped.</source>
        <translation>Kodierungs-Prozess angehalten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="229"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Ausnahme &apos;%1&apos; im Kodierungs-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Unbekannte Ausnahme im Kodierungs-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="71"/>
        <source>Stopping encoders ...</source>
        <translation>Kodierer werden gestoppt...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="78"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Warte darauf, dass der Muxer-Prozess angehalten wird...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="133"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Fehler: konnte keinen Header schreiben!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="144"/>
        <source>Finishing encoders ...</source>
        <translation>Finalisiere Kodierer...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="186"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Fehler: konnte gewähltes Ausgabe-Format nicht finden!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="190"/>
        <source>Using format %1 (%2).</source>
        <translation>Verwende Format %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="196"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Fehler: konnte Format-Kontext nicht zuweisen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Fehler: konnte Ausgabe-Datei nicht öffnen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Fehler: konnte trailer nicht schreiben, mache dennoch weiter.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="254"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Fehler: Codec konnte nicht gefunden werden!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="264"/>
        <source>Using codec %1 (%2).</source>
        <translation>Verwende Codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="273"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Fehler: konnte keinen neuen Stream erzeugen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="283"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Fehler: konnte die Codec-Kontext-Voreinstellungen nicht erhalten!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="296"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Warnung: Dieser Codec wird als experimentell bezeichnet von libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="312"/>
        <source>Muxer thread started.</source>
        <translation>Muxer-Prozess gestartet.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="371"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Fehler: konnte Frame nicht an Muxer schreiben!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="399"/>
        <source>Muxer thread stopped.</source>
        <translation>Muxer-Prozess angehalten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="403"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Ausnahme &apos;%1&apos; im Muxer-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="406"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Unbekannte Ausnahme im Muxer-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="205"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Stoppe Synchronisierungs-Prozess...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="322"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Warnung: Video-Bild mit nicht eindeutigem Zeitstempel erhalten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="348"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Warnung: Video-Puffer-Überlauf, einige Bilder gehen verloren. Die Audio-Eingabe scheint zu langsam zu sein.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="405"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Warnung: Audio-Samples mit nicht eindeutigem Zeitstempel erhalten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="430"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Warnung: zu viele Audio-Samples, schmeiße einige Samples weg, um Audio synchron zum Video zu halten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="436"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Warnung: nicht genug Audio-Samples, füge Stille ein, um Audio synchron zum Video zu halten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="502"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Warnung: Audio-Eingabe ist mehr als 2% zu langsam!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="506"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Warnung: Audio-Eingabe ist mehr als 2% zu schnell!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="541"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Warnung: Audio-Puffer-Überlauf, erzeuge neues Segment um Audio und Video synchron zu halten (etwas vom Video und/oder Audio könnte verloren sein). Die Video-Eingabe scheint zu langsam zu sein.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="577"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Warnung: erhielt ein Lock im Audio-Stream, füge Stille ein, um Audio synchron zum Video zu halten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="877"/>
        <source>Synchronizer thread started.</source>
        <translation>Synchronisierungs-Prozess gestartet.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="899"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Synchronisierungs-Prozess angehalten.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="903"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Ausnahme &apos;%1&apos; im Synchronisierungs-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="906"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Unbekannte Ausnahme im Synchronisierungs-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="120"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Fehler: Breite oder Höhe ist keine gerade Zahl!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="124"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Fehler: Bild-Rate ist null!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="181"/>
        <source>Using pixel format %1.</source>
        <translation>Verwende Pixel-Format %1</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="195"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Fehler: das Pixel-Format wird vom Codec nicht unterstützt!</translation>
    </message>
    <message>
        <source>Error: Encoder requires an unsupported pixel format!</source>
        <translation type="obsolete">Fehler: Enkodierer erfordert ein nicht unterstütztes Pixel-Format!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="225"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="245"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Fehler: Kodieren eines Video-Frames fehlgeschlagen!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="40"/>
        <source>Using real-time priority.</source>
        <translation>Verwende Echtzeit-Priorität.</translation>
    </message>
    <message>
        <source>Using nice priority.</source>
        <translation type="obsolete">Verwende Priorität von &quot;nice&quot;.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="50"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation>Verwende Priorität von &quot;nice&quot;.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="55"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation>Warnung: konnte die Prozess-Priorität nicht erhöhen.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="63"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Fehler: Kann das Gerät nach einem underrun nicht wieder erlangen!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="90"/>
        <source>Stopping synth thread ...</source>
        <translation>Stoppe Synth-Prozess...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="223"/>
        <source>Synth thread started.</source>
        <translation>Synth-Prozess gestartet.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="276"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Fehler: konnte Samples nicht schreiben!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="284"/>
        <source>Synth thread stopped.</source>
        <translation>Synth-Prozess angehalten.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="288"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Ausnahme &apos;%1&apos; im Synth-Prozess.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="291"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Unbekannte Ausnahme im Synth-Prozess.</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="46"/>
        <source>CPU features</source>
        <translation>CPU Merkmale</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="159"/>
        <source>The application could not be launched.</source>
        <translation>Die Applikation konnte nicht gestartet werden.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="164"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation>Warnung: XInput2 wird nicht vom X-Server unterstützt, Schnelltasten könnten in einigen Applikationen nicht funktionieren.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="119"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Fehler: Kommando-Zeilen-Option &apos;%1&apos; erlaubt keine Werte!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="150"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Fehler: unbekannte Kommando-Zeilen-Option &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="160"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Fehler: unbekanntes Kommando-Zeilen-Argument &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="200"/>
        <source>SSR started</source>
        <translation>SSR gestartet</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="228"/>
        <source>SSR stopped</source>
        <translation>SSR angehalten</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="245"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Fehler: konnte Verzeichnis .ssr nicht anlegen!</translation>
    </message>
    <message>
        <source>Scale %1 to %2  |  Fallback %3 ms  |  SSSE3 %4 ms  |  %5%</source>
        <translation type="obsolete">Skalierung %1 zu %2  |  Fallback %3 ms  |  SSSE3 %4 ms  |  %5%</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="160"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translatorcomment>What does &quot;us&quot; in this Context mean?</translatorcomment>
        <translation>BGRA %1 zu BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="238"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translatorcomment>What does &quot;us&quot; in this Context mean?</translatorcomment>
        <translation>%1 %2 zu %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="248"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Starte Skalierungs-Benchmark...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="255"/>
        <source>Starting converter benchmark ...</source>
        <translation>Starte Konvertierungs-Benchmark...</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder hat erkannt, dass Sie den proprietären NVIDIA-Treiber verwenden und &quot;flipping&quot; aktiviert haben. Dies könnte zu bekannten Fehlern bei der Aufnahme führen. Es wird empfohlen, &quot;flipping&quot; zu deaktivieren. Soll dies nun durchgeführt werden?

Sie können diese Option auch manuell im NVIDIA-Control-Panel ändern.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="90"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Leider konnte &quot;flipping&quot; nicht deaktiviert werden. Versuchen Sie es im NVIDIA-Control-Panel selbst zu deaktivieren.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Die Aufnahme wurde gespeichert. Sie können das Video nun bearbeiten oder mit anderen Einstellungen re-enkodieren um die Datei zu verkleinern (die Standard-Einstellungen sind für Qualität und nicht für Datei-Größe optimiert).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>Zurück zum Start-Bildschirm</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="113"/>
        <source>Video input</source>
        <translation>Video Eingang</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="116"/>
        <source>Record the entire screen</source>
        <translation>Vollständigen Bildschirm aufnehmen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="117"/>
        <source>Record a fixed rectangle</source>
        <translation>Ein festes Rechteck aufnehmen </translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="118"/>
        <source>Follow the cursor</source>
        <translation>Dem Mauszeiger folgen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="119"/>
        <source>Record OpenGL (experimental)</source>
        <translation>OpenGL Aufnahme (experimentell)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="125"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Auswahl des aufzunehmenden Monitors in einer Multi-Monitor-Umgebung.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="126"/>
        <source>Select rectangle...</source>
        <translation>Rechteck auswählen...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Benutzen Sie die Maus um das aufzunehmende Rechteck festzulegen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="128"/>
        <source>Select window...</source>
        <translation>Fenster auswählen...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="129"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Benutzen Sie die Maus um das aufzunehmende Fenster festzulegen.
Tipp: Wenn Sie auf den Rahmen eines Fensters klicken, wird das komplette Fenster (inkl. Rahmen) aufgenommen. 
Sonst wird nur der Fenster-Inhalt aufgenommen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="132"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL Einstellungen...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Ändern Sie die Einstellungen für die OpenGL-Aufnahme.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="134"/>
        <source>Left:</source>
        <translation>Links:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="138"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Die X-Koordinate der oberen linken Ecke des aufzunehmenden Vierecks.
Tipp: Sie können diese Werte auch mit dem Mausrad oder den Pfeiltasten Hoch/Runter ändern.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="140"/>
        <source>Top:</source>
        <translation>Oben:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="144"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>DIe Y-Koordinate der oberen linken Ecke des aufzunehmenden Vierecks.
Tipp: Sie können diese Werte auch mit dem Mausrad oder den Pfeiltasten Hoch/Runter ändern.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="146"/>
        <source>Width:</source>
        <translation>Breite:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="150"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Die Breite des aufzunehmenden Vierecks.
Tipp: Sie können diese Werte auch mit dem Mausrad oder den Pfeiltasten Hoch/Runter ändern.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="152"/>
        <source>Height:</source>
        <translation>Höhe:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="156"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Die Höhe des aufzunehmenden Vierecks.
Tipp: Sie können diese Werte auch mit dem Mausrad oder den Pfeiltasten Hoch/Runter ändern.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="158"/>
        <source>Frame rate:</source>
        <translation>Bild-Rate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="162"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Die Anzahl der Bilder pro Sekunde im aufgenommen Video. Höhere Bild-Raten verbrauchen mehr CPU-Zeit.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="163"/>
        <source>Scale video</source>
        <translation>Skalierung des Videos</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="164"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Skalierung an- oder ausschalten. Skalierung verbraucht mehr CPU-Zeit, aber wenn das skalierte Video kleiner ist, könnte es das Kodieren beschleunigen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="165"/>
        <source>Scaled width:</source>
        <translation>Skalierte Breite:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="169"/>
        <source>Scaled height:</source>
        <translation>Skalierte Höhe:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="173"/>
        <source>Record cursor</source>
        <translation>Mauszeiger aufnehmen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Audio input</source>
        <translation>Audio Eingang</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="245"/>
        <source>Record audio</source>
        <translation>Audio aufnehmen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>Backend:</source>
        <translatorcomment>There&apos;s no real translation for &quot;backend&quot; in german, so i changed it to &quot;Audio-System&quot;. Because &quot;backend&quot; in german means &quot;baking&quot; in english. :-)</translatorcomment>
        <translation>Audio-System:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="255"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Das Audio-System, welches zur Aufnahme verwendet wird.
Alsa funktioniert auch auf Systemen, die PulseAudio verwenden, aber es ist besser, PulseAudio direkt zu verwenden.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="257"/>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>Source:</source>
        <translation>Quelle:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Die Alsa-Quelle die zur Aufnahme verwendet wird.
Der Standard (default) ist gewöhnlich in Ordnung. Die &apos;shared&apos; (geteilten) Quellen erlauben die Aufnahme von mehreren Programmen
gleichzeitig, sind aber weniger zuverlässig.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Refresh</source>
        <translation>Aktualisieren</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="263"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Aktualisiert die Liste der ALSA-Quellen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="268"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Die PulseAudio-Quelle die zur Aufnahme verwendet wird.
Ein &apos;monitor&apos; ist eine Quelle, die Audio von anderen Applikationen aufnimmt.
</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Aktualisiert die Liste der PulseAudio-Quellen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="274"/>
        <source>Record system microphone</source>
        <translation>Aufnahme des System-Mikrofons</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="275"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Wenn ausgewählt, werden die Ports automatisch mit den Aufnahme-Ports des Systems verbunden.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record system speakers</source>
        <translation>Aufname der System-Lautsprecher</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Wenn ausgewählt, werden die Ports automatisch mit allem verbunden, dass mit den Wiedergabe-Ports des Systems verbunden ist.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Back</source>
        <translation>Zurück</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="313"/>
        <source>Continue</source>
        <translation>Weiter</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="673"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Alle Bildschirme: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="677"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Bildschirm %1: %2x%3 bei %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="839"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Bildschirm %1</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <location filename="../GUI/PageOutput.cpp" line="85"/>
        <location filename="../GUI/PageOutput.cpp" line="88"/>
        <location filename="../GUI/PageOutput.cpp" line="91"/>
        <location filename="../GUI/PageOutput.cpp" line="127"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>%1 Dateien</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>Andere...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>Unkomprimiert</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="161"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Fehler: konnte keinen passenden Container in libavformat finden!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="165"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Fehler: konnte keinen passenden Container in libavformat finden!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="169"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Fehler: konnte keinen passenden Audio-Codec in libavcodec finden!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="175"/>
        <source>File</source>
        <translation>Datei</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Save as:</source>
        <translation>Speichern als:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="179"/>
        <source>The recording will be saved to this location.</source>
        <translation>Die Aufnahme wird an diesem Ort gespeichert.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="180"/>
        <source>Browse...</source>
        <translation>Wählen...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Separate file per segment</source>
        <translation>Separate Datei pro Segment</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Wenn ausgewählt, wird jedesmal beim Pausieren und Fortsetzen der Aufnahme eine neue Datei angelegt.
Wenn die Original-Datei &apos;test.mkv&apos; heißt, werden die Segmente als &apos;test-JJJJ-MM-TT_SS.MM.SS.mkv&apos; erzeugt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="184"/>
        <source>Container:</source>
        <translation>Container:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="192"/>
        <source>The container (file format) that will be used to save the recording.
Note that not all codecs are supported by all containers, and that not all media players can read all file formats.
- Matroska (MKV) supports all the codecs, but is less well-known.
- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video
   (and many media players only support AAC audio).
- WebM is intended for embedding video into websites (with the HTML5 &lt;video&gt; tag). The format was created by Google.
   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.
   It supports only VP8 and Vorbis.
- OGG supports only Theora and Vorbis.</source>
        <translation>Der Container (Datei-Format), der zum Speichern der Aufnahme verwendet wird.
Beachten Sie, dass nicht alle Codecs von allen Containern unterstützt werden, und das nicht alle Media-Player alle Datei-Formate lesen können.
- Matroska (MKV) unterstützt alle Codecs, ist aber nicht weit verbreitet.
- MP4 ist das verbreiteste Format und wird von fast allen Media-Playern wiedergegeben, aber unterstützt nur H.264 Video
   (und viele Media-Player unterstützen nur AAC Audio).
- WebM ist für eingebette Videos in Webseiten gedacht (mit dem HTML5 &lt;video&gt;-Tag). Das Format wurde von Google entwickelt.
   WebM wird standardmäßig von Firefox, Chrome und Opera unterstützt, und es gibt Plugins für Internet Explorer und Safari.
   Es unterstützt nur VP8 und Vorbis.
- OGG unterstützt nur Theora und Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>Container name:</source>
        <translation>Name des Containers:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="207"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Für fortgeschrittene Benutzer. Sie können jedes libav/ffmpeg Format verwenden, aber viele sind u. U. nicht nützlich oder funktionieren nicht.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="223"/>
        <source>Video</source>
        <translation>Video</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <location filename="../GUI/PageOutput.cpp" line="305"/>
        <source>Codec:</source>
        <translation>Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="230"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Der Codec, der zum Komprimieren des Video-Stroms verwendet wird.
- H.264 (libx264) ist bei weitem der beste Codec - hohe Qualität und sehr schnell.
- VP8 (libvpx) ist ziemlich gut, aber auch ziemlich langsam.
- Theora (libtheora) wird wegen der nicht besonders guten Qualität nicht empfohlen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="234"/>
        <location filename="../GUI/PageOutput.cpp" line="318"/>
        <source>Codec name:</source>
        <translation>Name des Codecs:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Für fortgeschrittene Benutzer. Sie können jeden libav/ffmpeg Video-Codec verwenden, aber viele sind u. U. nicht nützlich oder funktionieren nicht.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="241"/>
        <location filename="../GUI/PageOutput.cpp" line="325"/>
        <source>Bit rate (in kbps):</source>
        <translation>Bit-Rate (in kb pro Sekunde):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="243"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Die Video Bit-Rate (in Kilobit pro Sekunde). Ein höherer Wert bedeutet höhere Qualität.
Wenn Sie keine Idee haben, womit Sie beginnen sollen, versuchen Sie 5000 und verändern Sie es nach Bedarf.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="245"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Diese Einstellung ändert die Video-Qualität. Ein niedrigerer Wert bedeutet höhere Qualität.
Der erlaubte Bereich liegt bei 0-51 (0 bedeutet verlustlos, der Standard ist 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="256"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Die Kodierungs-Geschwindigkeit. Eine höhere Geschwindigkeit verbraucht weniger CPU (dadurch werden 
Aufnahmen mit höheren Bild-Raten möglich), aber die Datei-Größe steigt. Die Qualität sollte hiervon
nicht zu sehr betroffen sein.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="263"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU used:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="265"/>
        <source>fastest</source>
        <translation>schnellster</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>slowest</source>
        <translation>langsamste</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="271"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Die Kodierungs-Geschwindigkeit. Ein höherer Wert verbraucht *weniger* CPU-Zeit (dies ist eine Einstellung 
des VP8-Encoders und wurde nicht vom Autor so benannt). Höhere Werte resultieren in schlechterer
Video-Qualität, es sei denn, Sie setzen gleichzeitig die Bit-Rate herauf.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="273"/>
        <location filename="../GUI/PageOutput.cpp" line="328"/>
        <source>Custom options:</source>
        <translation>Benutzerspezifische Optionen:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="275"/>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Benutzerspezifische Codec-Optionen, mit Komma geteilt (z. B. option=wert1,option2=wert2,option3=wert3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="276"/>
        <source>Allow frame skipping</source>
        <translation>Frame-Skipping erlauben</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Wenn ausgewählt, wird dem Video-Encoder erlaubt, Bilder zu überspringen, wenn die Eingabe-Bild-Rate
geringer ist als die Ausgabe-Bild-Rate. Wenn nicht ausgewählt, werden Eingangs-Bilder dupliziert um die
Löcher zu füllen. Dies erhöht die Datei-Größe und den CPU Verbrauch, aber reduziert die Latenz für
Live-Streams in einigen Fällen. Dies sollte sich nicht auf das Aussehen des Videos auswirken.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Audio</source>
        <translation>Audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="310"/>
        <source>The codec that will be used to compress the audio stream. You shouldn&apos;t worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you&apos;re only recording your own voice (i.e. no music), the quality won&apos;t matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it&apos;s very fast.</source>
        <translation>Der verwendete Codec um den Audio-Strom zu kodieren. Sie sollten sich hierüber keine großen Gedanken
machen, denn die Größe der Audio-Daten ist gewöhnlich zu vernachlässigen im Vergleich zu der Größe der
Video-Daten. Und wenn Sie nur Ihre eigene Stimme aufzeichnen (d. h. keine Musik), spielt die Qualität keine
große Rolle.
- Vorbis (libvorbis) ist großartig, dies ist der empfohlene Codec
- MP3 (libmp3lame) ist akzeptabel gut
- AAC ist ein guter Codec, aber die hier verwendete Implementierung (libvo_aacenc oder der experimentelle ffmpeg aac encoder)
   ist ziemlich schlecht. Benutzen Sie dies nur, wenn Sie keine andere Wahl haben.
- Unkomprimiert speichert die Audio-Daten einfach ohne Komprimierung. Die Datei wird ziemlich groß, aber es ist sehr schnell.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="324"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Für fortgeschrittene Benutzer. Sie können jeden libav/ffmpeg Audio-Codec verwenden, aber viele sind u. U. nicht nützlich oder funktionieren nicht.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="327"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Die Audio Bit-Rate (in Kilobit pro Sekunde). Ein höherer Wert bedeutet höhere Qualität. Der typische Wert ist 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="344"/>
        <source>Back</source>
        <translation>Zurück</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Continue</source>
        <translation>Weiter</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="564"/>
        <location filename="../GUI/PageOutput.cpp" line="572"/>
        <source>not installed</source>
        <translation>nicht installiert</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="566"/>
        <location filename="../GUI/PageOutput.cpp" line="574"/>
        <source>not supported by container</source>
        <translation>vom Container nicht unterstützt</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="617"/>
        <source>Save recording as</source>
        <translation>Speichere Aufnahme als</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="657"/>
        <source>You did not select an output file!</source>
        <translation>Sie haben keine Ausgangs-Datei ausgewählt!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="662"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>Die Datei &apos;%1&apos; existiert bereits. Sind Sie sicher, daß Sie diese überschreiben möchten?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="146"/>
        <source>Recording</source>
        <translation>Aufnehmen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="150"/>
        <source>Enable recording hotkey</source>
        <translation>Aufnahme-Hotkey aktivieren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Enable sound notifications</source>
        <translation>Sound-Mitteilungen aktivieren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Hotkey:</source>
        <translation>Schnelltaste:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="153"/>
        <source>Ctrl +</source>
        <translation>Strg +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="154"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="155"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="156"/>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="158"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>Die Taste, die zusammen mit dem angegebenen Modifizierer gedrückt werden muss, um die Aufnahme zu starten oder pausieren.
Das aufgenommene Programm wird diesen Tastendruck nicht erhalten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="198"/>
        <source>Information</source>
        <translation>Information</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="200"/>
        <source>Total time:</source>
        <translation>Gesamt Zeit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="202"/>
        <source>FPS in:</source>
        <translation>FPS ein:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="204"/>
        <source>FPS out:</source>
        <translation>FPS aus:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="206"/>
        <source>Size in:</source>
        <translation>Größe ein:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="208"/>
        <source>Size out:</source>
        <translation>Größe aus:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="210"/>
        <source>File name:</source>
        <translation>Datei-Name:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="213"/>
        <source>File size:</source>
        <translation>Datei-Größe:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="215"/>
        <source>Bit rate:</source>
        <translation>Bit-Rate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Preview</source>
        <translation>Vorschau</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>Preview frame rate:</source>
        <translation>Vorschau Bild-Rate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Hinweis: Vorschau benötigt extra CPU-Zeit (besonders bei hohen Bild-Raten).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="295"/>
        <source>Log</source>
        <translation>Log</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="310"/>
        <location filename="../GUI/PageRecord.cpp" line="318"/>
        <source>Cancel recording</source>
        <translation>Aufnahme abbrechen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="311"/>
        <location filename="../GUI/PageRecord.cpp" line="320"/>
        <source>Save recording</source>
        <translation>Aufnahme speichern</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="325"/>
        <source>Quit</source>
        <translation>Beenden</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="368"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Sie haben die aktuelle Aufnahme noch nicht gespeichert, wenn Sie jetzt beenden, ist sie verloren.
Sind Sie sicher, dass Sie beenden wollen?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="380"/>
        <source>Hide window</source>
        <translation>Verstecke Fenster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="382"/>
        <source>Show window</source>
        <translation>Zeige Fenster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="535"/>
        <source>Starting page ...</source>
        <translation>Start-Seite...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="556"/>
        <location filename="../GUI/PageRecord.cpp" line="698"/>
        <location filename="../GUI/PageRecord.cpp" line="783"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Fehler: etwas ging während der Initialisierung schief.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="563"/>
        <source>Started page.</source>
        <translatorcomment>Where does this appear?</translatorcomment>
        <translation>Seite gestartet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="587"/>
        <source>Stopping page ...</source>
        <translatorcomment>Where does this appear? Log only?</translatorcomment>
        <translation>Seite wird angehalten...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="830"/>
        <source>Encoding remaining data ...</source>
        <translation>Verbleibende Daten werden kodiert...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="612"/>
        <source>Stopped page.</source>
        <translatorcomment>Where does this appear?</translatorcomment>
        <translation>Seite gestoppt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="637"/>
        <source>Starting output ...</source>
        <translation>Ausgabe wird gestoppt...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="648"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Fehler: die Größe der OpenGL-Applikation konnte nicht bestimmt werden, da die GLInject-Eingabe nicht erzeugt wurde.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="653"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Fehler: die Größe der OpenGL-Applikation konnte nicht bestimmt werden. Entweder wurde die Applikation nicht korrekt gestartet, oder die Applikation hat noch kein OpenGL Fenster erzeugt. Wenn Sie die Aufnahme starten möchten, bevor Sie die Applikation gestartet haben, müssen Sie Skalierung aktivieren und die Größe des Videos manuell eingeben.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="689"/>
        <source>Started output.</source>
        <translation>Ausgabe gestartet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="709"/>
        <source>Stopping output ...</source>
        <translation>Ausgabe wird angehalten...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="727"/>
        <source>Stopped output.</source>
        <translation>Ausgabe angehalten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="754"/>
        <source>Starting input ...</source>
        <translation>Eingabe wird gestartet...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="759"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Fehler: GLInject-Eingabe konnte nicht gestartet werden, weil es nicht erzeugt wurde.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="778"/>
        <source>Started input.</source>
        <translation>Eingabe gestartet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="803"/>
        <source>Stopping input ...</source>
        <translation>Eingabe wird angehalten...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="814"/>
        <source>Stopped input.</source>
        <translation>Eingabe angehalten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="901"/>
        <location filename="../GUI/PageRecord.cpp" line="912"/>
        <source>Pause recording</source>
        <translation>Aufnahme pausieren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="905"/>
        <location filename="../GUI/PageRecord.cpp" line="915"/>
        <source>Start recording</source>
        <translation>Aufnahme starten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="923"/>
        <source>Stop preview</source>
        <translation>Aufnahme stoppen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="926"/>
        <source>Start preview</source>
        <translation>Vorschau starten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="955"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Fehler: etwas ging während des Erzeugens des Synths schief.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="995"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Sind Sie sicher, daß Sie die Aufnahme abbrechen möchten?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1010"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>SIe haben nichts aufgenommen, es gibt nichts zum Speichern.

Der Start-Knopf ist oben ;).</translation>
    </message>
</context>
<context>
    <name>PageWelcome</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="34"/>
        <source>&lt;p&gt;Welcome to SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Despite the name, this program actually has a lot of options. Don&apos;t worry though, there are really just two things that you need to know. One, the default settings are usually fine. If you don&apos;t know what something does, just use the default. Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.&lt;/p&gt;

&lt;p&gt;For more information:&lt;br&gt;
%1&lt;/p&gt;</source>
        <translation>&lt;p&gt;Willkommen zu SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Trotz des Namens hat das Programm viele Optionen. Machen Sie sich aber keine Gedanken, denn es sind nur zwei Dinge, die Sie wissen müssen. Erstens: die Standard-Einstellungen sind in den meisten Fällen ausreichend. Wenn Sie nicht wissen, was eine Option bewirkt, benutzen Sie die Standard-Einstellung. Zweitens: fast alle Optionen besitzen eine Hilfe als Tooltip. Um herauszufinden, was eine Einstellung bewirkt, bewegen Sie einfach Ihre Maus darüber.&lt;/p&gt;

&lt;p&gt;Für weitere Informationen:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="44"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Über SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="45"/>
        <source>Continue</source>
        <translation>Weiter</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="28"/>
        <source>Profile</source>
        <translation>Profil</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Speichern</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Speichere die aktuellen Einstellungen in diesem Profil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Neu</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Erzeuge ein neues Profil mit den aktuellen EInstellungen.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Löschen</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Lösche dieses Profil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(keins)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Fehler: Profil konnte nicht geladen werden!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Sind Sie sicher, dass dieses Profil überschrieben werden soll?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Geben Sie einen Namen für das neue Profil ein:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Ein Profil mit dem selben Namen existiert bereits. Sind Sie sicher, dass es ersetzt werden soll?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Sind Sie sicher, dass dieses Profil gelöscht werden soll?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation>&amp;OK</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation>&amp;Abbruch</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Ja</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Ja, immer</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Nein</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Nein, niemals</translation>
    </message>
</context>
<context>
    <name>QMessageBox</name>
    <message>
        <source>&amp;OK</source>
        <translation type="obsolete">&amp;OK</translation>
    </message>
    <message>
        <source>&amp;Cancel</source>
        <translation type="obsolete">&amp;Abbruch</translation>
    </message>
    <message>
        <source>&amp;Yes</source>
        <translation type="obsolete">&amp;Ja</translation>
    </message>
    <message>
        <source>Yes, always</source>
        <translation type="obsolete">Ja, immer</translation>
    </message>
    <message>
        <source>&amp;No</source>
        <translation type="obsolete">&amp;Nein</translation>
    </message>
    <message>
        <source>No, never</source>
        <translation type="obsolete">Nein, niemals</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Synchronitäts-Diagramm</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="251"/>
        <source>Video in</source>
        <translation>Video Eingang</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="252"/>
        <source>Audio in</source>
        <translation>Audio Eingang</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="253"/>
        <source>Video out</source>
        <translation>Video Ausgang</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="254"/>
        <source>Audio out</source>
        <translation>Audio Ausgang</translation>
    </message>
</context>
</TS>
