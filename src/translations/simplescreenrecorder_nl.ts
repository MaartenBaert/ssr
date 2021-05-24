<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="nl_NL">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Over SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="120"/>
        <source>For more information:</source>
        <translation>Voor meer informatie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="121"/>
        <source>The source code of this program can be found at:</source>
        <translation>De broncode van dit programma kan gevonden worden op:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="122"/>
        <source>This program uses:</source>
        <translation>Dit programma gebruikt:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="123"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 voor de grafische gebruikersinterface</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="124"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 of %2 (afhankelijk van je distributie) voor video/audio-encoding</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="125"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 voor het hooken van systeemfuncties voor OpenGL opnames</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="35"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL instellingen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="38"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Waarschuwing: OpenGL opname werkt door een library te injecteren in het programma dat wordt opgenomen. Deze library zal sommige systeemfuncties vervangen om beelden op te nemen voor ze weergegeven worden op het scherm. Als je probeert om een spel op te nemen dat probeert om hacking-pogingen te detecteren, dan is het (theoretisch) mogelijk dat het spel dit als een hack zal zien. Dit zou ervoor kunnen zorgen dat je geband wordt, dus het is een goed idee om eerst te controleren dat het programma dat je wil opnemen je niet zal bannen, *voordat* je het probeert. Je bent gewaarschuwd :).&lt;/p&gt;

&lt;p&gt;Nog een waarschuwing: OpenGL opname is experimenteel, het werkt niet altijd en het kan het programma dat je wil opnemen zelfs laten crashen. Als je vreest data te verliezen, maak dan eerst een backup!&lt;/p&gt;

&lt;p&gt;Als je Steam-spellen wil opnemen, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;lees dan eerst dit&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="52"/>
        <source>Choose channel</source>
        <translation>Kies kanaal</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="54"/>
        <source>Channel name:</source>
        <translation>Kanaalnaam:</translation>
    </message>
    <message>
        <source>Channel names are used to identify applications. You only need to change this if you want to record multiple applications at the same time.</source>
        <translation type="obsolete">Kanaalnamen worden gebruikt om applicaties te identificeren. Je moet dit enkel aanpassen als je meerdere applicaties tegelijk wil opnemen.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="56"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Kanaalnamen worden gebruikt om applicaties te identificeren. Je moet dit enkel gebruiken als je meerdere applicaties tegelijk wil opnemen. Als je dit leeg laat, wordt de standaardnaam &apos;channel-JOUWGEBRUIKERSNAAM&apos; gebruikt.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="74"/>
        <source>Launch application</source>
        <translation>Start applicatie</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="76"/>
        <source>Command:</source>
        <translation>Commando:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="78"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Dit commando zal worden uitgevoerd om het programma dat opgenomen moet worden te starten.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="80"/>
        <source>Working directory:</source>
        <translation>Werkmap:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="82"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Het commando zal worden uitgevoerd in deze map. Als je dit leeglaat, dan wordt de werkmap niet veranderd.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>Launch automatically</source>
        <translation>Start automatisch</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="85"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Indien aangevinkt zal de applicatie automatisch gestart worden zodra je naar de opnamepagina gaat. Indien niet aangevinkt moet de applicatie manueel gestart worden.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="87"/>
        <source>Launch now</source>
        <translation>Start nu</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="108"/>
        <source>Stream settings</source>
        <translation>Streaminstellingen</translation>
    </message>
    <message>
        <source>Select stream</source>
        <translation type="obsolete">Selecteer stream</translation>
    </message>
    <message>
        <source>Active streams:</source>
        <translation type="obsolete">Actieve streams:</translation>
    </message>
    <message>
        <source>Record newest stream that matches:</source>
        <translation type="obsolete">Neem nieuwste stream op die overeenkomt met:</translation>
    </message>
    <message>
        <source>User:</source>
        <translation type="obsolete">Gebruiker:</translation>
    </message>
    <message>
        <source>Process:</source>
        <translation type="obsolete">Proces:</translation>
    </message>
    <message>
        <source>Source:</source>
        <translation type="obsolete">Bron:</translation>
    </message>
    <message>
        <source>Program name:</source>
        <translation type="obsolete">Programmanaam:</translation>
    </message>
    <message>
        <source>Error: Could not create stream watcher!</source>
        <translation type="obsolete">Fout: Kan geen stream watcher maken!</translation>
    </message>
    <message>
        <source>Error: Could not update streams!</source>
        <translation type="obsolete">Fout: Kan streams niet updaten!</translation>
    </message>
    <message>
        <source>Start the OpenGL application automatically</source>
        <translation type="obsolete">Start de OpenGL-applicatie automatisch</translation>
    </message>
    <message>
        <source>If checked, the above command will be executed automatically (combined with some environment variables). If not checked,
you have to start the OpenGL application yourself (the full command, including the required environment variables, is shown in the log).</source>
        <translation type="obsolete">Indien aangevinkt zal het bovenstaande commando automatisch worden uitgevoerd (samen met een aantal omgevingsvariabelen).
Indien niet aangevinkt moet je zelf de OpenGL-applicatie starten (het volledige commando, inclusief de vereiste omgevingsvariabelen, zal worden weergegeven in de log).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Geen strikte permissies voor gedeeld geheugen (onveilig)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Indien aangevinkt zullen andere gebruikers op dezelfde machine toegang hebben tot het gedeeld geheugen dat gebruikt wordt om te communiceren met het OpenGL-programma.
Dit betekent dat andere gebruikers (theoretisch) kunnen zien wat je opneemt, de beelden aanpassen, hun eigen beelden injecteren, of simpelweg de communicatie verstoren.
Dit geldt zelfs voor gebruikers die op afstand inloggen (ssh). Je moet dit enkel inschakelen als je een programma moet opnemen dat uitgevoerd wordt als een andere gebruiker.</translation>
    </message>
    <message>
        <source>Maximum image size (megapixels):</source>
        <translation type="obsolete">Maximum afbeeldingsgrootte (megapixels):</translation>
    </message>
    <message>
        <source>This setting changes the amount of shared memory that will be allocated to send frames back to the main program.
The size of the shared memory can&apos;t be changed anymore once the program has been started, so if the program you
are trying to record is too large, recording won&apos;t work. 2 megapixels should be enough in almost all cases. Be careful,
high values will use a lot of memory!</source>
        <translation type="obsolete">Deze instelling verandert de hoeveelheid gedeeld geheugen die zal worden gereserveerd om beelden terug te sturen naar het hoofdprogramma.
De grootte van het gedeeld geheugen kan niet meer veranderd worden eens het programma gestart is, dus als het programma dat je probeert
op te nemen te groot is, dan zal de opname mislukken. 2 megapixels zou genoeg moeten zijn in bijna alle gevallen. Wees voorzichtig, grote waarden
zullen veel geheugen gebruiken!</translation>
    </message>
    <message>
        <source>Capture front buffer instead of back buffer</source>
        <translation type="obsolete">Neem de front buffer op in plaats van de back buffer</translation>
    </message>
    <message>
        <source>If checked, the injected library will read the front buffer (the frame that&apos;s currently on the screen) rather than the back buffer
(the new frame). This may be useful for some special applications that draw directly to the screen.</source>
        <translation type="obsolete">Indien aangevinkt zal de geinjecteerde library de front buffer lezen (het beeld dat op dit moment op het scherm staat) in plaats van de back buffer
(het nieuwe beeld). Dit zou nuttig kunnen zijn voor sommige speciale applicaties die rechtstreeks op het scherm tekenen.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>Limit application frame rate</source>
        <translation>Limiteer beelden per seconde van de applicatie</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="111"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Indien ingeschakeld zal de geinjecteerde library de applicatie vertragen zodat het aantal beelden per seconde niet hoger wordt dan de frame rate van de opname.
Dit verhindert dat de applicatie CPU-tijd gebruikt voor beelden die niet opgenomen zullen worden, en resulteert soms in vloeiendere video
(dit hangt af van de applicatie).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="120"/>
        <source>Close</source>
        <translation>Sluiten</translation>
    </message>
</context>
<context>
    <name>DialogRecordSchedule</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="78"/>
        <source>Recording schedule</source>
        <translation>Opnameplanning</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="80"/>
        <source>Time zone:</source>
        <translation>Tijdzone:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="82"/>
        <source>Local time</source>
        <translation>Lokale tijd</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="83"/>
        <source>UTC</source>
        <translation>UTC</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="85"/>
        <source>Current time:</source>
        <translation>Huidige tijd:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="102"/>
        <source>Add</source>
        <translation>Toevoegen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="103"/>
        <source>Remove</source>
        <translation>Verwijderen</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="104"/>
        <source>Move up</source>
        <translation>Verplaats omhoog</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="105"/>
        <source>Move down</source>
        <translation>Verplaats omlaag</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="107"/>
        <source>Close</source>
        <translation>Sluiten</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Fout: Hersampleratio is buiten bereik!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Fout: Driftratio is buiten bereik!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Hersampleratio is %1 (was %2).</translation>
    </message>
    <message>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="obsolete">Waarschuwing: Pixelformaat wordt niet ondersteund (%1 -&gt; %2), swscale wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="129"/>
        <source>Warning: No fast pixel format conversion available (%1,%2 -&gt; %3,%4), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Waarschuwing: Geen snelle pixelformaatconversie beschikbaar (%1,%2 -&gt; %3,%4), swscale wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="138"/>
        <location filename="../Benchmark.cpp" line="124"/>
        <location filename="../Benchmark.cpp" line="205"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Fout: Kan geen swscale context krijgen!</translation>
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
        <translation>Waarschuwing: Geheugen is niet goed uitgelijnd voor SSE, de fallback converter wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Waarschuwing: Er was een overrun, een aantal samples gingen verloren.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="37"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fout: Kan apparaat niet herstellen na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="41"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fout: Kan het PCM apparaat niet starten na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="71"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="59"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="66"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation>Stop input thread ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="102"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation>Bronnenlijst genereren ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="121"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Fout: Kan ALSA configuratie niet updaten!</translation>
    </message>
    <message>
        <source>Warning: Could not find PCM plugins.</source>
        <translation type="obsolete">Waarschuwing: Kan PCM plugins niet vinden.</translation>
    </message>
    <message>
        <source>Found plugin %1 = %2.</source>
        <translation type="obsolete">Plugin %1 = %2 gevonden.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Waarschuwing: Kan geluidskaart %1 niet openen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="187"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Waarschuwing: Kan geen informatie verkrijgen over geluidskaard %1.</translation>
    </message>
    <message>
        <source>Found card %1 = %2.</source>
        <translation type="obsolete">Kaart %1 = %2 gevonden.</translation>
    </message>
    <message>
        <source>Found device %1 = %2.</source>
        <translation type="obsolete">Apparaat %1 = %2 gevonden.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="168"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Plugin gevonden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="191"/>
        <source>Found card: [%1] %2</source>
        <translation>Kaart gevonden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="216"/>
        <source>Found device: [%1] %2</source>
        <translation>Apparaat gevonden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="271"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Fout: Kan PCM apparaat niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="281"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Fout: Kan toegangstype niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="292"/>
        <source>Error: Can&apos;t set sample format mask!</source>
        <translation>Fout: Kan sampleformaatmasker niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="297"/>
        <location filename="../AV/SimpleSynth.cpp" line="140"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Fout: Kan sampleformaat niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="330"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Fout: Kan samplefrequentie niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Samplefrequentie %1 wordt niet ondersteund, %2 wordt gebruikt in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="343"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Fout: Kan het aantal kanalen niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="347"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Aantal kanalen %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="356"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Fout: Kan periodegrootte niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="360"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Periodegrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="369"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Fout: Kan de buffergrootte niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Buffergrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="381"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet toepassen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="407"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Fout: Kan het PCM apparaat niet starten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="428"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="263"/>
        <location filename="../AV/Input/X11Input.cpp" line="465"/>
        <source>Input thread started.</source>
        <translation>Input thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="452"/>
        <source>Error: Can&apos;t wait for new samples!</source>
        <translation>Fout: Kan niet wachten op nieuwe samples!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation type="obsolete">Fout: Kan niet controleren of samples beschikbaar zijn!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="469"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Fout: Kan samples niet lezen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="500"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="358"/>
        <location filename="../AV/Input/JACKInput.cpp" line="302"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="294"/>
        <location filename="../AV/Input/X11Input.cpp" line="585"/>
        <source>Input thread stopped.</source>
        <translation>Input thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="504"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="362"/>
        <location filename="../AV/Input/JACKInput.cpp" line="306"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="589"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Exceptie &apos;%1&apos; in input thread.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="507"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="365"/>
        <location filename="../AV/Input/JACKInput.cpp" line="309"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="301"/>
        <location filename="../AV/Input/X11Input.cpp" line="592"/>
        <source>Unknown exception in input thread.</source>
        <translation>Onbekende exceptie in input thread.</translation>
    </message>
    <message>
        <source>Error: Image is too small!</source>
        <translation type="obsolete">Fout: De afbeelding is te klein!</translation>
    </message>
    <message>
        <source>Error: Image is too large!</source>
        <translation type="obsolete">Fout: De afbeelding is te groot!</translation>
    </message>
    <message>
        <source>Error: Image doesn&apos;t fit in memory!</source>
        <translation type="obsolete">Fout: De afbeelding past niet in het geheugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="318"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Fout: Kan geen gedeeld geheugen krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="323"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Fout: Kan niet vastmaken aan gedeeld geheugen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation type="obsolete">Fout: Kan geen frame gedeeld geheugen krijgen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation type="obsolete">Fout: Kan niet vastmaken aan frame gedeeld geheugen!</translation>
    </message>
    <message>
        <source>Full command</source>
        <translation type="obsolete">Volledig commando</translation>
    </message>
    <message>
        <source>Error: Can&apos;t run command!</source>
        <translation type="obsolete">Fout: Kan commando niet uitvoeren!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="75"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Fout: Kan niet verbinden met JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="84"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Fout: Kan geen JACK poort maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="100"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Fout: Kan geen JACK verwerkingscallback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Fout: Kan geen JACK samplefrequentiecallback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="108"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Fout: Kan geen JACK xrun callback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Fout: Kan geen JACK poortverbindingscallback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="117"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Fout: Kan JACK client niet activeren!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="125"/>
        <location filename="../AV/Input/JACKInput.cpp" line="136"/>
        <location filename="../AV/Input/JACKInput.cpp" line="265"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Verbinding van poort %1 naar %2 gemaakt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="269"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>Verbinding van poort %1 naar %2 verbroken.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="34"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Fout: pa_mainloop_prepare mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="38"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Fout: pa_mainloop_poll mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="42"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Fout: pa_mainloop_dispatch mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="52"/>
        <source>Error: Could not create main loop!</source>
        <translation>Fout: Kan geen hoofdlus maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="59"/>
        <source>Error: Could not create context!</source>
        <translation>Fout: Kan geen context maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Fout: Kan niet verbinden! Reden: %1
Het is mogelijk dat je systeem geen PulseAudio gebruikt. Probeer om de ALSA-backend te gebruiken in de plaats.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="68"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio.</source>
        <translation>Fout: Kan niet verbinden! Reden: %1
Het is mogelijk dat je systeem geen PulseAudio gebruikt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="82"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Fout: Verbindingspoging mislukt! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="119"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Fout: Kan geen stream maken! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="126"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Fout: Kan stream niet verbinden! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="137"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Fout: Stream verbindingspoging mislukt! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="228"/>
        <source>Found source: [%1] %2</source>
        <translation>Bron gevonden: [%1] %2</translation>
    </message>
    <message>
        <source>Got %1 = %2.</source>
        <translation type="obsolete">Verkreeg %1 = %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="249"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Fout: Kan geen namen van bronnen krijgen! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="297"/>
        <source>Error: Could not get source info! Reason: %1</source>
        <translation>Fout: Kan geen broninfo krijgen! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="302"/>
        <source>Stream is a monitor.</source>
        <translation>Stream is een monitor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="304"/>
        <source>Stream is not a monitor.</source>
        <translation>Stream is geen monitor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="349"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Fout: pa_stream_peek mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="416"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Waarschuwing: De audiobron werd gestopt. Het huidige segment zal gestopt worden totdat de bron herstart.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="421"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Waarschuwing: Stream werd verplaatst naar een andere bron.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="68"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Fout: X11-afbeeldingspixelformaat wordt niet ondersteund!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="41"/>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="118"/>
        <source>Error: Width or height is zero!</source>
        <translation>Fout: Breedte of hoogte is nul!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="45"/>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="122"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Fout: Breedte of hoogte is te groot, de maximum breedte en hoogte is %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="99"/>
        <source>Error: Can&apos;t open V4L2 device!</source>
        <translation>Fout: Kan V4L2 apparaat niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="107"/>
        <source>Error: Can&apos;t read capabilities of V4L2 device!</source>
        <translation>Fout: Kan mogelijkheden van V4L2 apparaat niet uitlezen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="111"/>
        <source>Error: V4L2 device does not support video capture!</source>
        <translation>Fout: V4L2 apparaat ondersteunt geen video-opname!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="115"/>
        <source>Error: V4L2 device does not support streaming io!</source>
        <translation>Fout: V4L2 apparaat ondersteunt geen streaming io!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="132"/>
        <source>Error: Can&apos;t set capture format!</source>
        <translation>Fout: Kan opnameformaat niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="136"/>
        <source>Error: V4L2 device does not support YUYV pixel format!</source>
        <translation>Fout: V4L2 apparaat ondersteunt het YUYV pixelformaat niet!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="140"/>
        <source>Warning: Resolution %1x%2 is not supported, using %3x%4 instead. The video will be scaled.</source>
        <translation>Fout: Resolutie %1x%2 wordt niet ondersteund, %3x%4 wordt gebruikt in de plaats. De video zal geschaald worden.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="183"/>
        <source>Using color space %1.</source>
        <translation>Gebruik kleurruimte %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="193"/>
        <source>Error: Buffer request failed!</source>
        <translation>Fout: Buffer request mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="203"/>
        <source>Error: Buffer query failed!</source>
        <translation>Fout: Buffer query mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="209"/>
        <source>Error: Buffer mmap failed!</source>
        <translation>Fout: Buffer mmap mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="222"/>
        <source>Error: Buffer queue failed!</source>
        <translation>Fout: Buffer queue mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="230"/>
        <source>Error: Failed to start stream!</source>
        <translation>Fout: Starten van stream mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="273"/>
        <source>Error: Buffer dequeue failed!</source>
        <translation>Fout: Buffer dequeue mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="288"/>
        <source>Error: Buffer requeue failed!</source>
        <translation>Fout: Buffer requeue mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="257"/>
        <location filename="../GUI/HotkeyListener.cpp" line="115"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Fout: Kan X display niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="266"/>
        <source>Using X11 shared memory.</source>
        <translation>Gebruik X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="313"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Fout: Kan geen gedeelde afbeelding maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="268"/>
        <source>Not using X11 shared memory.</source>
        <translation>Gebruik geen X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="275"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Waarschuwing: XFixes wordt niet ondersteund door de X server, de cursor is verborgen.</translation>
    </message>
    <message>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="obsolete">Waarschuwing: XFixes wordt niet ondersteund door de server, de cursor is verborgen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="406"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Fout: Ongeldige schermrechthoek!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="328"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Fout: Kan server niet vastmaken aan gedeeld geheugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="355"/>
        <source>Detecting screen configuration ...</source>
        <translation>Schermconfiguratie detecteren ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="373"/>
        <source>Warning: Xinerama is not supported by X server, multi-monitor support may not work properly.</source>
        <comment>Don&apos;t translate &apos;Xinerama&apos;</comment>
        <translation>Waarschuwing: Xinerama wordt niet ondersteund door de X server, multi-monitor ondersteuning werkt mogelijk niet correct.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation>Waarschuwing: Geen monitors gedetecteerd, multi-monitor ondersteuning werkt mogelijk niet correct.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="386"/>
        <source>Screen %1:</source>
        <translation>Scherm %1:</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="450"/>
        <source>Dead space %1:</source>
        <translation>Dode ruimte %1:</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="536"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Fout: Kan geen afbeelding krijgen (met gedeeld geheugen)!
    Meestal betekent dit dat het opgenomen gebied niet volledig binnen het scherm is. Of heb je de schermresolutie veranderd?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="547"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Fout: Kan geen afbeelding krijgen (zonder gedeeld geheugen)!
    Meestal betekent dit dat het opgenomen gebied niet volledig binnen het scherm is. Of heb je de schermresolutie veranderd?</translation>
    </message>
    <message>
        <source>Error: Sample rate it zero.</source>
        <translation type="obsolete">Fout: Samplefrequentie is nul.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="172"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="100"/>
        <source>Error: Channel count is zero.</source>
        <translation>Fout: Aantal kanalen is nul.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="104"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Fout: Samplefrequentie is nul.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="142"/>
        <source>Using sample format %1.</source>
        <translation>Gebruik sampleformaat %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="147"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Fout: Encoder vereist een sampleformaat dat niet ondersteund wordt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <source>Error: Sending of audio frame failed!</source>
        <translation>Fout: Versturen van audioframe mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Receiving of audio packet failed!</source>
        <translation>Fout: Ontvangen van audiopakket mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="210"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="232"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Fout: Encoderen van audioframe mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation>Stop encoder thread ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="267"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Fout: Kan de codec niet vinden!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="277"/>
        <source>Using codec %1 (%2).</source>
        <translation>Gebruik codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="320"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Waarschuwing: Deze codec wordt gezien als experimenteel door libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="30"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="39"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Fout: Kan optie &apos;%1&apos; niet parsen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="164"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Fout: Kan codec niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="188"/>
        <source>Encoder thread started.</source>
        <translation>Encoder thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="217"/>
        <source>Flushing encoder ...</source>
        <translation>Encoder afwerken ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="228"/>
        <source>Encoder thread stopped.</source>
        <translation>Encoder thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Exceptie &apos;%1&apos; in encoder thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="235"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Onbekende exceptie in encoder thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="70"/>
        <source>Stopping encoders ...</source>
        <translation>Encoders stoppen ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="77"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Wacht tot muxer thread stopt ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="146"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Fout: Kan header niet schrijven!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="157"/>
        <source>Finishing encoders ...</source>
        <translation>Encoders afwerken ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="288"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Fout: Kan geen nieuwe stream maken!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="307"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Fout: Kan codec-context standaardwaarden niet krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Fout: Kan gekozen outputformaat niet vinden!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <location filename="../AV/Output/Muxer.cpp" line="124"/>
        <source>Error: Can&apos;t copy parameters to stream!</source>
        <translation>Fout: Kan parameters niet kopiëren naar stream!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Using format %1 (%2).</source>
        <translation>Gebruik formaat %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="209"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Fout: Kan geen formaat-context maken!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Fout: Kan outputbestand niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="229"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Fout: Kan trailer niet schrijven, ga toch verder.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="295"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation>Fout: Kan geen nieuwe codec-context maken!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="336"/>
        <source>Muxer thread started.</source>
        <translation>Muxer thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="396"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Fout: Kan geen frame naar de muxer schrijven!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="424"/>
        <source>Muxer thread stopped.</source>
        <translation>Muxer thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="428"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Exceptie &apos;%1&apos; in muxer thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="431"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Onbekende exceptie in muxer thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="220"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Synchronisator thread stoppen ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="328"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Waarschuwing: Videobeeld met niet-monotone tijdswaarde ontvangen.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="355"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Waarschuwing: Video buffer overflow, sommige beelden zullen verloren gaan. De audio-input lijkt te traag te zijn.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="412"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Waarschuwing: Audiosamples met niet-monotone tijdswaarde ontvangen.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="437"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Waarschuwing: Te veel audiosamples, laat samples vallen om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="443"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Waarschuwing: Niet genoeg audiosamples, voeg stilte in om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="511"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Waarschuwing: Audio-input is meer dan 2% te traag!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="515"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Waarschuwing: Audio-input is meer dan 2% te snel!</translation>
    </message>
    <message>
        <source>Error: Audio sample format is not supported!</source>
        <translation type="obsolete">Fout: Audiosampleformaat wordt niet ondersteund!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="554"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Waarschuwing: Audio buffer overflow, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan). De video-input lijkt te traag te zijn.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="590"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Waarschuwing: Ontving gat in audiostream, voeg stilte in om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="891"/>
        <source>Synchronizer thread started.</source>
        <translation>Synchronisator thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="913"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Synchronisator thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="917"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Exceptie &apos;%1&apos; in synchronisator thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="920"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Onbekende exceptie in synchronisator thread.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="49"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="126"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Fout: Breedte of hoogte is geen even getal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="130"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Fout: Beelden per seconde is nul!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="187"/>
        <source>Using pixel format %1.</source>
        <translation>Gebruik pixelformaat %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="201"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Fout: Het pixelformaat wordt niet ondersteund door de codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="229"/>
        <source>Error: Sending of video frame failed!</source>
        <translation>Fout: Versturen van videoframe mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="250"/>
        <source>Error: Receiving of video packet failed!</source>
        <translation>Fout: Ontvangen van videopakket mislukt!</translation>
    </message>
    <message>
        <source>Error: Encoder requires an unsupported pixel format!</source>
        <translation type="obsolete">Fout: Encoder vereist een sampleformaat dat niet ondersteund wordt!</translation>
    </message>
    <message>
        <source>Error: Frame rate it zero!</source>
        <translation type="obsolete">Fout: Beelden per seconde is nul!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="263"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="284"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Fout: Encoderen van videobeeld mislukt!</translation>
    </message>
    <message>
        <source>Warning: An underrun has occurred, some samples were too late.</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="obsolete">Waarschuwing: Er was een underrun, een aantal samples waren te laat.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="41"/>
        <source>Using real-time priority.</source>
        <translation>Gebruik real-time prioriteit.</translation>
    </message>
    <message>
        <source>Using nice priority.</source>
        <translation type="obsolete">Gebruik nice prioriteit.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="51"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation>Gebruik nice prioriteit.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation>Waarschuwing: Kan de thread prioriteit niet verhogen.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="64"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Fout: Kan apparaat niet herstellen na underrun!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="91"/>
        <source>Stopping synth thread ...</source>
        <translation>Stop synth thread ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="224"/>
        <source>Synth thread started.</source>
        <translation>Synth thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="277"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Fout: Kan samples niet schrijven!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="285"/>
        <source>Synth thread stopped.</source>
        <translation>Synth thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="289"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Exceptie &apos;%1&apos; in synth thread.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="292"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Onbekende exceptie in synth thread.</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="45"/>
        <source>CPU features</source>
        <translation>CPU-eigenschappen</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="90"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation>Fout: Command-line optie &apos;%1&apos; vereist een waarde!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="98"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Fout: Command-line optie &apos;%1&apos; neemt geen waarde aan!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="195"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Fout: Onbekende command-line optie &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="203"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Fout: Onbekend command-line argument &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="253"/>
        <source>Error: Can&apos;t create configuration directory!</source>
        <translation>Fout: Kan configuratiemap niet aanmaken!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="99"/>
        <source>SSR started</source>
        <translation>SSR gestart</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="133"/>
        <source>SSR stopped</source>
        <translation>SSR gestopt</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="obsolete">Fout: Kan geen .ssr map maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="259"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Fout: Kan stream niet lezen, dit betekent meestal dat de stream al verdwenen is.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation>Video stream lezer gemaakt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Fout: Kan video stream bestand niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation>Fout: Kan video stream bestand niet vergroten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Fout: Kan video stream bestand niet memory-mappen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Fout: Kan video frame bestand niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation>Video stream lezer vernietigd.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Fout: Grootte van video frame bestand is incorrect!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Fout: Kan video frame bestand niet memory-mappen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="94"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation>Fout: Kan kanaalmap niet aanmaken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="102"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation>Fout: Kan &apos;stat&apos; niet uitvoeren op kanaalmap!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="106"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Fout: Kanaalmap is geen normale map!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="111"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation>Fout: Kan mode van kanaalmap niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="116"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Fout: Kanaalmap is eigendom van een andere gebruiker! Kies een andere kanaalnaam of schakel stricte permissies uit om deze toch te gebruiken.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="126"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fout: Kan inotify niet initialiseren!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t watch shared memory directory!</source>
        <translation type="obsolete">Fout: Kan </translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation>Fout: Kan kanaalmap niet bekijken!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open shared memory directory!</source>
        <translation type="obsolete">Fout: </translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation>Fout: Kan kanaalmap niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Bestaande stream %1 toegevoegd.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fout: Kan leeslengte van inotify niet krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fout: Kan niet lezen van inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fout: Onvolledige event ontvangen van inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Fout: Onvolledige naam ontvangen van inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation>Stream %1 toegevoegd.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation>Stream %1 verwijderd.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Verlaten stream %1 gewist.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>The application could not be launched.</source>
        <translation>De applicatie kon niet gestart worden.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="161"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation>Waarschuwing: XInput2 wordt niet ondersteund door de X server, sneltoetsen werken mogelijk niet in sommige applicaties.</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="165"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation>BGRA %1 naar BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="243"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation>%1 %2 naar %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="253"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Start scaler-benchmark ...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="260"/>
        <source>Starting converter benchmark ...</source>
        <translation>Start converter-benchmark ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="70"/>
        <source>Stopping fragment thread ...</source>
        <translation>Stop fragment-thread ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="347"/>
        <source>Fragment thread started.</source>
        <translation>Fragment-thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="365"/>
        <source>Next fragment ...</source>
        <translation>Volgende fragment ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="369"/>
        <source>Finishing ...</source>
        <translation>Afwerken ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="381"/>
        <source>Fragment thread stopped.</source>
        <translation>Fragment-thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="385"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation>Exceptie &apos;%1&apos; in fragment-thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="388"/>
        <source>Unknown exception in fragment thread.</source>
        <translation>Onbekende exceptie in fragment-thread.</translation>
    </message>
    <message>
        <location filename="../common/ScreenScaling.cpp" line="120"/>
        <source>Detected fractional screen scale factor, scaling was disabled.</source>
        <translation>Fractionele schermschaalfactor gedetecteerd, schalen werd uitgeschakeld.</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>You are using a non-X11 window system (e.g. Wayland) which is currently not supported by SimpleScreenRecorder. Several features will most likely not work properly. In order to solve this, you should log out, choose a X11/Xorg session at the login screen, and then log back in.</source>
        <translation>U gebruikt een niet-X11 venstersysteem (bijvoorbeeld Wayland) dat momenteel niet wordt ondersteund door SimpleScreenRecorder. Sommige functies zullen waarschijnlijk niet correct werken. Om dit op te lossen moet u uitloggen, een X11/Xorg sessie selecteren vanaf het loginscherm, en daarna terug inloggen.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="86"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder heeft gedetecteerd dat je de propriëtaire NVIDIA-driver gebruikt met flipping ingeschakeld. Het is bekend dat dit storingen veroorzaakt tijdens de opname. Het is aangeraden om flipping uit te schakelen. Wil je dat ik dit voor je doe?

Je kan deze optie ook manueel veranderen in het NVIDIA-controlepaneel.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="104"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Ik kon flipping niet uitschakelen om een of andere reden - sorry! Probeer om het uit te schakelen in het NVIDIA-controlepaneel.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="31"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>De opname is opgeslagen. Je kan nu de video bewerken, of her-encoderen met betere instellingen om het bestand kleiner te maken (de standaardinstellingen zijn geoptimaliseerd voor kwaliteit en snelheid, niet bestandsgrootte).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="35"/>
        <source>Open folder</source>
        <translation>Map openen</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="38"/>
        <source>Back to the start screen</source>
        <translation>Terug naar het beginscherm</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="273"/>
        <source>Video input</source>
        <translation>Video input</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record the entire screen</source>
        <translation>Neem het hele scherm op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>Record a fixed rectangle</source>
        <translation>Neem een vaste rechthoek op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="278"/>
        <source>Follow the cursor</source>
        <translation>Volg de cursor</translation>
    </message>
    <message>
        <source>Record OpenGL (experimental)</source>
        <translation type="obsolete">OpenGL opname (experimenteel)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Input profile</source>
        <translation>Inputprofiel</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="280"/>
        <source>Record OpenGL</source>
        <translation>Neem OpenGL op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="283"/>
        <source>Record V4L2 device</source>
        <translation>Neem V4L2 apparaat op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="295"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Selecteer welke monitor opgenomen moet worden in een multi-monitor configuratie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="296"/>
        <source>Record entire screen with cursor</source>
        <translation>Neem het hele scherm met cursor op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="297"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation>Neem het hele scherm waarop de cursor zich bevindt op, in plaats van de cursorpositie te volgen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="298"/>
        <source>Select rectangle...</source>
        <translation>Selecteer rechthoek...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="299"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Gebruik de muis om de opgenomen rechthoek te selecteren.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="300"/>
        <source>Select window...</source>
        <translation>Selecteer venster...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="301"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Gebruik de muis om een venster te selecteren om op te nemen.
Hint: Als je op de rand van het venster klikt, zal het hele venster worden opgenomen (inclusief de randen). Anders wordt
enkel het client-gedeelte (binnenkant) van het venster opgenomen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="305"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL-instellingen...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="306"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Verander de instellingen voor OpenGL opnames.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="310"/>
        <source>The V4L2 device to record (e.g. /dev/video0).</source>
        <translation>Het V4L2 apparaat dat wordt opgenomen (bijvoorbeeld /dev/video0).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Left:</source>
        <translation>Links:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="316"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De x-coordinaat van de linkerbovenhoek van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="318"/>
        <source>Top:</source>
        <translation>Boven:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="322"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De y-coordinaat van de linkerbovenhoek van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="324"/>
        <source>Width:</source>
        <translation>Breedte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="328"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De breedte van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="330"/>
        <source>Height:</source>
        <translation>Hoogte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="334"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De hoogte van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="336"/>
        <source>Frame rate:</source>
        <translation>Beelden per seconde:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="340"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Het aantal beelden per seconde in de uiteindelijke video. Hogere frame rates gebruiken meer CPU-tijd.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="341"/>
        <source>Scale video</source>
        <translation>Schaal video</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="342"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Schakel schalen in of uit. Schalen gebruikt meer CPU-tijd, maar als de geschaalde video kleiner is, zou dit het encoderen sneller kunnen maken.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="343"/>
        <source>Scaled width:</source>
        <translation>Geschaalde breedte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="347"/>
        <source>Scaled height:</source>
        <translation>Geschaalde hoogte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="351"/>
        <source>Record cursor</source>
        <translation>Neem de cursor op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="441"/>
        <source>Audio input</source>
        <translation>Audio input</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="443"/>
        <source>Record audio</source>
        <translation>Neem audio op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="444"/>
        <source>Backend:</source>
        <translation>Backend:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="459"/>
        <source>The audio backend that will be used for recording.</source>
        <translation>De audio-backend die gebruikt zal worden voor opname.</translation>
    </message>
    <message>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation type="obsolete">Het ALSA-apparaat dat gebruikt zal worden om op te nemen. Normaal hoort dit &apos;default&apos; te zijn.
Je kan dit veranderen naar iets zoals plughw:0,0 (dit betekent geluidskaard 0 input 0 met plugins ingeschakeld).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="474"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>De PulseAudio-bron die gebruikt zal worden om op te nemen.
Een &apos;monitor&apos; is een bron die de audio opneemt die wordt afgespeeld door andere applicaties.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="481"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Indien aangevinkt zullen de poorten automatisch verbonden worden met de systeemopnamepoorten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="483"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Indien aangevinkt zullen de poorten automatisch verbonden worden met alles dat verbinding maakt met de systeemafspeelpoorten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="964"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Alle schermen: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="968"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Scherm %1: %2x%3 op %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1206"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Scherm %1</translation>
    </message>
    <message>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation type="obsolete">Je hebt geen commando ingegeven om de OpenGL-applicatie die je wil opnemen te starten.
Klik op de &apos;OpenGL instellingen&apos; knop en geef een commando in.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="456"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>De audio-backend die gebruikt zal worden om op te nemen.
De ALSA-backend zal ook werken op systemen die PulseAudio gebruiken, maar het is beter om de PulseAudio-backend rechtstreeks te gebruiken.</translation>
    </message>
    <message>
        <source>Device:</source>
        <translation type="obsolete">Apparaat:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="462"/>
        <location filename="../GUI/PageInput.cpp" line="471"/>
        <source>Source:</source>
        <translation>Bron:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="465"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>De ALSA-bron die gebruikt wordt voor opname.
De standaardkeuze is meestal goed. De &apos;shared&apos; bronnen kunnen door meerdere programma&apos;s tegelijk worden opgenomen, maar zijn mogelijk minder betrouwbaar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="467"/>
        <location filename="../GUI/PageInput.cpp" line="476"/>
        <source>Refresh</source>
        <translation>Vernieuwen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="468"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Vernieuwt de lijst met ALSA-bronnen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="477"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Vernieuwt de lijst met PulseAudio-bronnen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="480"/>
        <source>Record system microphone</source>
        <translation>Neem systeemmicrofoon op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="482"/>
        <source>Record system speakers</source>
        <translation>Neem systeemluidsprekers op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="530"/>
        <source>Back</source>
        <translation>Terug</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="531"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
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
        <translation>Ongecomprimeerd</translation>
    </message>
    <message>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation type="obsolete">bestanden</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="173"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Fout: Kon geen enkele geschikte container vinden in libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Fout: Kon geen enkele geschikte videocodec vinden in libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Fout: Kon geen enkele geschikte audiocodec vinden in libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Output profile</source>
        <translation>Outputprofiel</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="191"/>
        <source>File</source>
        <translation>Bestand</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="193"/>
        <source>Save as:</source>
        <translation>Opslaan als:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="195"/>
        <source>The recording will be saved to this location.</source>
        <translation>De opname wordt opgeslagen op deze locatie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="196"/>
        <source>Browse...</source>
        <translation>Bladeren...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>Separate file per segment</source>
        <translation>Apart bestand per segment</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation type="obsolete">Indien aangevinkt zal een apart videobestand aangemaakt worden elke keer wanneer je de opname pauzeert en hervat.
Als de originele bestandsnaam &apos;test.mkv&apos; is, zullen de segmenten worden opgeslagen als &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
Bestandsnamen die al bestaan zullen worden overgeslagen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="203"/>
        <source>Container:</source>
        <translation>Container:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="208"/>
        <source>(not installed)</source>
        <translation>(niet geinstalleerd)</translation>
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
        <translation>De container (bestandsformaat) die gebruikt zal worden om de opname op te slaan.
Merk op dat niet alle codecs ondersteund worden door alle containers, en dat niet alle mediaspelers alle bestandsformaten kunnen lezen.
- Matroska (MKV) ondersteunt alle codecs, maar is minder bekend.
- MP4 is het meest bekende formaat en kan worden afgespeeld op bijna elke moderne mediaspeler, maar ondersteunt enkel H.264-video
   (en veel mediaspelers ondersteunen enkel AAC-audio).
- WebM is bedoeld om video in te bouwen in websites (met de HTML5 &lt;video&gt; tag). Het formaat is gemaakt door Google.
   WebM wordt standaard ondersteund door Firefox, Chrome en Opera, en plugins bestaan voor Internet Explorer en Safari.
   Het ondersteunt enkel VP8 en Vorbis.
- OGG ondersteunt enkel Theora en Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Container name:</source>
        <translation>Containernaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elk libav/ffmpeg-formaat gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <source>Video</source>
        <translation>Video</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="252"/>
        <location filename="../GUI/PageOutput.cpp" line="332"/>
        <source>Codec:</source>
        <translation>Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="257"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>De codec die gebruikt zal worden om de videostream te comprimeren.
- H.264 (libx264) is verreweg de beste codec - hoge kwaliteit en zeer snel.
- VP8 (libvpx) is redelijk goed maar ook redelijk traag.
- Theora (libtheora) is niet echt aangeraden omdat de kwaliteit niet erg goed is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Codec name:</source>
        <translation>Codecnaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elke libav/ffmpeg-videocodec gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <source>Bit rate (in kbps):</source>
        <translation type="obsolete">Bitrate (in kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>De video-bitrate (in kilobit per seconde). Een hogere waarde betekent een hogere kwaliteit.
Als je geen idee hebt waar je moet beginnen, probeer dan 5000 en verander het indien nodig.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="272"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="283"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="290"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU-gebruik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="292"/>
        <source>fastest</source>
        <translation>snelste</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <source>slowest</source>
        <translation>traagste</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="298"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>De encodeersnelheid. Een hogere waarde gebruikt *minder* CPU-tijd. (Ik heb de naam niet gekozen, dit is de naam
die gebruikt wordt door de VP8-encoder). Hogere waarden resulteren in lagere beeldkwaliteit, tenzij je de bitrate ook verhoogt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Deze instelling verandert de videokwaliteit. Een lagere waarde betekent een hogere kwaliteit.
Het toegestane bereik is 0-51 (0 betekent verliesvrij, de standaardwaarde is 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <location filename="../GUI/PageOutput.cpp" line="85"/>
        <location filename="../GUI/PageOutput.cpp" line="88"/>
        <location filename="../GUI/PageOutput.cpp" line="91"/>
        <location filename="../GUI/PageOutput.cpp" line="133"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>%1 bestanden</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="obsolete">Indien aangevinkt zal een apart videobestand aangemaakt worden elke keer wanneer je de opname pauzeert en hervat.
Als de originele bestandsnaam &apos;test.mkv&apos; is, zullen de segmenten worden opgeslagen als &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation>Indien aangevinkt zal een apart videobestand aangemaakt worden elke keer wanneer je de opname pauzeert en hervat.
Indien niet aangevinkt zullen alle opgenomen segmenten gecombineerd worden in één videobestand.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <source>Add timestamp</source>
        <translation>Voeg tijdstempel toe</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Indien aangevinkt zal de huidige datum en tijd automatisch toegevoegd worden aan de bestandsnaam.
Als de originele bestandsnaam &apos;test.mkv&apos; is, zal de video worden opgeslagen als &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="227"/>
        <source>Warning: This format will produce unreadable files if the recording is interrupted! Consider using MKV instead.</source>
        <translation>Waarschuwing: Dit formaat zal tot onleesbare bestanden leiden als de opname wordt onderbroken! Het is aangeraden om MKV te gebruiken in de plaats.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="268"/>
        <location filename="../GUI/PageOutput.cpp" line="352"/>
        <source>Bit rate (in kbit/s):</source>
        <translation>Bitrate (in kbit/s):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="288"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>De encodeersnelheid. Een hogere snelheid gebruikt minder CPU (waardoor meer beelden per seconde opgenomen kunnen worden),
maar resulteert in grotere bestanden. De kwaliteit verandert normaal gezien niet veel.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <location filename="../GUI/PageOutput.cpp" line="355"/>
        <source>Custom options:</source>
        <translation>Aangepaste opties:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <location filename="../GUI/PageOutput.cpp" line="357"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Aangepaste opties gescheiden door komma&apos;s (b.v. optie1=waarde1,optie2=waarde2,optie3=waarde3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Allow frame skipping</source>
        <translation>Frames overslaan toestaan</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="304"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Indien aangevinkt zal de video-encoder beelden overslaan als de input-FPS lager is
dan de output-FPS. Indien niet aangevinkt zullen inputbeelden worden verdubbeld om de gaten op te vullen.
Dit verhoogt de bestandsgrootte en het CPU-gebruik, maar vermindert de vertraging voor live streams in sommige gevallen.
Het heeft normaal gezien geen effect op de videobeelden zelf.</translation>
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
        <translation>De codec die gebruikt zal worden om de audiostream te comprimeren. Je moet je niet te veel zorgen maken hierover,
want de grootte van de audiodata is meestal verwaarloosbaar vergeleken met de grootte van de videodata.
En als je enkel je eigen stem opneemt (d.w.z. geen muziek), dan zal de kwaliteit toch niet zo veel verschil maken.
- Vorbis (libvorbis) is geweldig, dit is de aangeraden codec.
- MP3 (libmp3lame) is redelijk goed.
- AAC is een goede codec, maar de implementaties die hier gebruikt worden (libvo_aacenc of de experimentele ffmpeg aac encoder)
   zijn nogal slecht. Gebruikt deze enkel als je geen andere keuze hebt.
- Ongecomprimeerd zal simpelweg de geluidsdata opslaan zonder compressie. Het bestand zal erg groot zijn, maar het is zeer snel.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elke libav/ffmpeg-audiocodec gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>De video-bitrate (in kilobit per seconde). Een hogere waarde betekent een hogere kwaliteit. De typische waarde is 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="379"/>
        <source>Back</source>
        <translation>Terug</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="380"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="637"/>
        <location filename="../GUI/PageOutput.cpp" line="645"/>
        <source>not installed</source>
        <translation>niet geinstalleerd</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <location filename="../GUI/PageOutput.cpp" line="647"/>
        <source>not supported by container</source>
        <translation>niet ondersteund door container</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="690"/>
        <source>Save recording as</source>
        <translation>Opname opslaan als</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="528"/>
        <source>You did not select an output file!</source>
        <translation>Je hebt geen outputbestand gekozen!</translation>
    </message>
    <message>
        <source>Create separate timestamped file for each segment</source>
        <translation type="obsolete">Creëer apart bestand met tijdsstempel voor elk segment</translation>
    </message>
    <message>
        <source>If checked, a separate timestamped video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="obsolete">Indien aangevinkt zal er een apart videobestand met tijdsstempel aangemaakt worden elke keer wanneer je de opname pauzeert en hervat.
Als de originele bestandsnaam &apos;test.mkv&apos; is, zullen de segmenten worden opgeslagen als &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</translation>
    </message>
    <message>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation type="obsolete">Het bestand &apos;%1&apos; bestaat al. Weet je zeker dat je het wil overschrijven?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="176"/>
        <source>Recording</source>
        <translation>Opname</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="182"/>
        <source>Edit schedule</source>
        <translation>Planning aanpassen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="183"/>
        <source>The recording schedule can be used to automatically start or pause the recording at a predefined time.</source>
        <translation>De opnameplanning kan worden gebruikt om automatisch de opname te starten of te pauzeren op een vooraf gedefinieerd tijdstip.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="185"/>
        <source>Enable recording hotkey</source>
        <translation>Opname-sneltoets inschakelen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="186"/>
        <source>The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,
even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the
SimpleScreenRecorder window show up in the final video.</source>
        <translation>De opname-sneltoets is een globale toetsenbordsnelkoppeling die kan worden gebruikt om de opname te starten of te pauzeren
op eender welk moment, zelfs wanneer het SimpleScreenRecorder-venster niet zichtbaar is. Op deze manier is het mogelijk om
opnames te maken zonder dat het SimpleScreenRecorder venster zichtbaar is in de uiteindelijke video.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="190"/>
        <source>Enable sound notifications</source>
        <translation>Schakel geluidsnotificaties in</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="191"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation>Indien ingeschakeld zal een geluid worden afgespeeld wanneer de opname wordt gestart op gepauzeerd, of wanneer er zich een fout voordoet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="193"/>
        <source>Hotkey:</source>
        <translation>Sneltoets:</translation>
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
        <translation>De toets die je moet indrukken (in combinatie met de gegeven modifiers) om de opname te starten of te pauzeren.
Het programma dat je aan het opnemen bent zal de toets niet ontvangen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="252"/>
        <source>Information</source>
        <translation>Informatie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="254"/>
        <source>Total time:</source>
        <translation>Totale tijd:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="256"/>
        <source>FPS in:</source>
        <translation>FPS in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="258"/>
        <source>FPS out:</source>
        <translation>FPS uit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="260"/>
        <source>Size in:</source>
        <translation>Grootte in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="262"/>
        <source>Size out:</source>
        <translation>Grootte uit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="264"/>
        <source>File name:</source>
        <translation>Bestandsnaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="267"/>
        <source>File size:</source>
        <translation>Bestandsgrootte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="269"/>
        <source>Bit rate:</source>
        <translation>Bitrate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="271"/>
        <source>Show recording area</source>
        <translation>Toon opnameregio</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="272"/>
        <source>When enabled, the recorded area is marked on the screen.</source>
        <translation>Indien ingeschakeld zal de opgenomen regio worden gemarkeerd op het scherm.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="297"/>
        <source>Preview</source>
        <translation>Voorbeeld</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="301"/>
        <source>Preview frame rate:</source>
        <translation>Voorbeeld FPS:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="305"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Opmerking: Voorbeeld vereist extra CPU-tijd (vooral bij hoge FPS).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="354"/>
        <source>Log</source>
        <translation>Log</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="369"/>
        <location filename="../GUI/PageRecord.cpp" line="377"/>
        <source>Cancel recording</source>
        <translation>Opname annuleren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="370"/>
        <location filename="../GUI/PageRecord.cpp" line="379"/>
        <source>Save recording</source>
        <translation>Opname opslaan</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="384"/>
        <source>Quit</source>
        <translation>Afsluiten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="435"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Je hebt de huidige opname nog niet opgeslagen, als je het programma nu sluit zal deze verloren gaan.
Weet je zeker dat je het programma wilt sluiten?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="447"/>
        <source>Hide window</source>
        <translation>Verberg venster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="449"/>
        <source>Show window</source>
        <translation>Toon venster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="793"/>
        <source>Output file: %1</source>
        <translation>Outputbestand: %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1022"/>
        <source>Encoding remaining data ...</source>
        <translation>Overblijvende data encoderen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1281"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.</source>
        <translation>U heeft nog niets opgenomen, er is niets om op te slaan.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1298"/>
        <source>Triggering scheduled action &apos;%1&apos; ...</source>
        <translation>Geplande actie &apos;%1&apos; wordt uitgevoerd ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1309"/>
        <source>Schedule: %1 in %2</source>
        <translation>Planning: %1 over %2</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1316"/>
        <source>Schedule: (none)</source>
        <translation>Planning: (geen)</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1320"/>
        <source>Schedule: (inactive)</source>
        <translation>Planning: (inactief)</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1384"/>
        <location filename="../GUI/PageRecord.cpp" line="1401"/>
        <source>Standard input read error (%1).</source>
        <translation>Standaardinput leesfout (%1).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1389"/>
        <location filename="../GUI/PageRecord.cpp" line="1406"/>
        <source>Standard input closed (%1).</source>
        <translation>Standaardinput gesloten (%1).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1419"/>
        <source>Received command &apos;%1&apos;.</source>
        <translation>Commando &apos;%1&apos; ontvangen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1439"/>
        <source>Unknown command.</source>
        <translation>Onbekend commando.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="779"/>
        <source>Starting output ...</source>
        <translation>Output starten ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="804"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Fout: Kan de grootte van de OpenGL-applicatie niet krijgen omdat de GLInject input niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="848"/>
        <source>Started output.</source>
        <translation>Output gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="869"/>
        <source>Stopping output ...</source>
        <translation>Output stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="887"/>
        <source>Stopped output.</source>
        <translation>Output gestopt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="919"/>
        <source>Starting input ...</source>
        <translation>Input starten ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="930"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Fout: Kan de GLInject input niet starten omdat deze niet aangemaakt is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="956"/>
        <source>Started input.</source>
        <translation>Input gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="988"/>
        <source>Stopping input ...</source>
        <translation>Input stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1006"/>
        <source>Stopped input.</source>
        <translation>Input gestopt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="659"/>
        <source>Starting page ...</source>
        <translation>Pagina starten ...</translation>
    </message>
    <message>
        <source>Error: Something went wrong during GLInject initialization.</source>
        <translation type="obsolete">Fout: Er ging iets fout tijdens de GLInject initialisatie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="690"/>
        <source>Started page.</source>
        <translation>Pagina gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="723"/>
        <source>Stopping page ...</source>
        <translation>Pagina stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="750"/>
        <source>Stopped page.</source>
        <translation>Pagina gestopt.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application because GLInject has not been started.</source>
        <translation type="obsolete">Fout: Kan de grootte van de OpenGL-applicatie niet krijgen omdat GLInject niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="809"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Fout: Kon de grootte van de OpenGL-applicatie niet krijgen. Ofwel is de applicatie niet correct gestart, ofwel heeft de applicatie nog geen OpenGL-venster gemaakt. Als je wil beginnen met opnemen voordat de applicatie is gestart, dan moet je schalen inschakelen en manueel de videogrootte instellen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="681"/>
        <location filename="../GUI/PageRecord.cpp" line="858"/>
        <location filename="../GUI/PageRecord.cpp" line="961"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Fout: Er ging iets fout tijdens de initialisatie.</translation>
    </message>
    <message>
        <source>Error: Could not create a GLInject input because GLInject has not been started.</source>
        <translation type="obsolete">Fout: Kan geen GLInject input maken omdat GLInject niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1116"/>
        <location filename="../GUI/PageRecord.cpp" line="1126"/>
        <source>Pause recording</source>
        <translation>Opname pauzeren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1119"/>
        <location filename="../GUI/PageRecord.cpp" line="1129"/>
        <source>Start recording</source>
        <translation>Opname starten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1137"/>
        <source>Deactivate schedule</source>
        <translation>Planning deactiveren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1147"/>
        <source>Activate schedule</source>
        <translation>Planning activeren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1156"/>
        <source>Stop preview</source>
        <translation>Voorbeeld stoppen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1159"/>
        <source>Start preview</source>
        <translation>Voorbeeld starten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1200"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Fout: Er ging iets fout bij het maken van de synth.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1264"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Weet je zeker dat je deze opname wilt annuleren?</translation>
    </message>
    <message>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation type="obsolete">Je hebt nog niets opgenomen, er is niets om op te slaan.

De startknop staat bovenaan ;).</translation>
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
        <translation>&lt;p&gt;Welkom bij SimpleScreenRecorder&lt;/p&gt;

&lt;p&gt;Ondanks de naam heeft dit programma behoorlijk veel opties. Maar maak je geen zorgen, er zijn maar twee dingen die je moet weten. Eén, de standaardinstellingen zijn meestal oké. Als je niet weet wat iets doet, neem dan de standaardwaarde. Twee, bijna alle instellingen hebben tooltips. Hou gewoon de muis boven iets om te weten wat het doet.&lt;/p&gt;

&lt;p&gt;Voor meer informatie:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="51"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Over SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="52"/>
        <source>Skip this page next time</source>
        <translation>Deze pagina volgende keer overslaan</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="53"/>
        <source>Go directly to the input page when the program is started.</source>
        <translation>Ga direct naar de inputpagina wanneer het programma wordt gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="76"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <source>Profile</source>
        <translation type="obsolete">Profiel</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Opslaan</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Sla de huidige instellingen op in dit profiel.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Nieuw</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Maak een nieuw profiel met de huidige instellingen.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Verwijder</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Verwijder dit profiel.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(geen)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Fout: Kan profiel niet laden!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Weet je zeker dat je dit profiel wil overschrijven?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Geef een naam in voor het nieuwe profiel:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Een profiel met dezelfde naam bestaat al. Weet je zeker dat je het wil vervangen?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Weet je zeker dat je dit profiel wil verwijderen?</translation>
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
        <translation>&amp;Annuleren</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Ja</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Ja, altijd</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Nee</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Nee, nooit</translation>
    </message>
</context>
<context>
    <name>QMessageBox</name>
    <message>
        <source>&amp;OK</source>
        <translation type="obsolete">&amp;OK</translation>
    </message>
    <message>
        <source>&amp;Yes</source>
        <translation type="obsolete">&amp;Ja</translation>
    </message>
    <message>
        <source>Yes, always</source>
        <translation type="obsolete">Ja, altijd</translation>
    </message>
    <message>
        <source>&amp;No</source>
        <translation type="obsolete">&amp;Nee</translation>
    </message>
    <message>
        <source>No, never</source>
        <translation type="obsolete">Nee, nooit</translation>
    </message>
    <message>
        <source>&amp;Cancel</source>
        <translation type="obsolete">&amp;Annuleren</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <source>CPU features</source>
        <translation type="obsolete">CPU-eigenschappen</translation>
    </message>
    <message>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="obsolete">Waarschuwing: Pixelformaat wordt niet ondersteund (%1 -&gt; %2), swscale wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="obsolete">Fout: Kan geen swscale context krijgen!</translation>
    </message>
    <message>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="obsolete">Waarschuwing: Geheugen is niet goed uitgelijnd voor SSE, de fallback converter wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation type="obsolete">Fout: Kan PCM apparaat niet openen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation type="obsolete">Fout: Kan PCM hardwareparameters niet krijgen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set access type!</source>
        <translation type="obsolete">Fout: Kan toegangstype niet instellen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample format!</source>
        <translation type="obsolete">Fout: Kan sampleformaat niet instellen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation type="obsolete">Fout: Kan samplefrequentie niet instellen!</translation>
    </message>
    <message>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Waarschuwing: Er was een overrun, een aantal samples gingen verloren.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Fout: Kan apparaat niet herstellen na overrun!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Fout: Kan het PCM apparaat niet starten na overrun!</translation>
    </message>
    <message>
        <source>Stopping input thread ...</source>
        <translation type="obsolete">Stop input thread ...</translation>
    </message>
    <message>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Waarschuwing: Samplefrequentie %1 wordt niet ondersteund, %2 wordt gebruikt in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set channel count!</source>
        <translation type="obsolete">Fout: Kan het aantal kanalen niet instellen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set period count!</source>
        <translation type="obsolete">Fout: Kan het aantal periodes niet instellen!</translation>
    </message>
    <message>
        <source>Warning: Period count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Waarschuwing: Aantal periodes %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set period size!</source>
        <translation type="obsolete">Fout: Kan periodegrootte niet instellen!</translation>
    </message>
    <message>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Waarschuwing: Periodegrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation type="obsolete">Fout: Kan de buffergrootte niet instellen!</translation>
    </message>
    <message>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Waarschuwing: Buffergrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation type="obsolete">Fout: Kan PCM hardwareparameters niet toepassen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation type="obsolete">Fout: Kan het PCM apparaat niet starten!</translation>
    </message>
    <message>
        <source>Input thread started.</source>
        <translation type="obsolete">Input thread gestart.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation type="obsolete">Fout: Kan niet controleren of samples beschikbaar zijn!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t read samples!</source>
        <translation type="obsolete">Fout: Kan samples niet lezen!</translation>
    </message>
    <message>
        <source>Input thread stopped.</source>
        <translation type="obsolete">Input thread gestopt.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation type="obsolete">Exceptie &apos;%1&apos; in input thread.</translation>
    </message>
    <message>
        <source>Unknown exception in input thread.</source>
        <translation type="obsolete">Onbekende exceptie in input thread.</translation>
    </message>
    <message>
        <source>Error: Image is too small!</source>
        <translation type="obsolete">Fout: De afbeelding is te klein!</translation>
    </message>
    <message>
        <source>Error: Image is too large!</source>
        <translation type="obsolete">Fout: De afbeelding is te groot!</translation>
    </message>
    <message>
        <source>Error: Image doesn&apos;t fit in memory!</source>
        <translation type="obsolete">Fout: De afbeelding past niet in het geheugen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation type="obsolete">Fout: Kan geen frame gedeeld geheugen krijgen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation type="obsolete">Fout: Kan niet vastmaken aan frame gedeeld geheugen!</translation>
    </message>
    <message>
        <source>Full command</source>
        <translation type="obsolete">Volledig commando</translation>
    </message>
    <message>
        <source>Error: Can&apos;t run command!</source>
        <translation type="obsolete">Fout: Kan commando niet uitvoeren!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation type="obsolete">Fout: pa_mainloop_prepare mislukt!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="obsolete">Fout: pa_mainloop_poll mislukt!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="obsolete">Fout: pa_mainloop_dispatch mislukt!</translation>
    </message>
    <message>
        <source>Error: Could not create main loop!</source>
        <translation type="obsolete">Fout: Kan geen hoofdlus maken!</translation>
    </message>
    <message>
        <source>Error: Could not create context!</source>
        <translation type="obsolete">Fout: Kan geen context maken!</translation>
    </message>
    <message>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation type="obsolete">Fout: Kan niet verbinden! Reden: %1
Het is mogelijk dat je systeem geen PulseAudio gebruikt. Probeer om de ALSA-backend te gebruiken in de plaats.</translation>
    </message>
    <message>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation type="obsolete">Fout: Verbindingspoging mislukt! Reden: %1</translation>
    </message>
    <message>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="obsolete">Fout: Kan geen stream maken! Reden: %1</translation>
    </message>
    <message>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="obsolete">Fout: Kan stream niet verbinden! Reden: %1</translation>
    </message>
    <message>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="obsolete">Fout: Stream verbindingspoging mislukt! Reden: %1</translation>
    </message>
    <message>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="obsolete">Fout: Kan geen namen van bronnen krijgen! Reden: %1</translation>
    </message>
    <message>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation type="obsolete">Fout: pa_stream_peek mislukt!</translation>
    </message>
    <message>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="obsolete">Waarschuwing: De audiobron werd gestopt. Het huidige segment zal gestopt worden totdat de bron herstart.</translation>
    </message>
    <message>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="obsolete">Waarschuwing: Stream werd verplaatst naar een andere bron.</translation>
    </message>
    <message>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="obsolete">Fout: X11-afbeeldingspixelformaat wordt niet ondersteund!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="obsolete">Fout: Kan X display niet openen!</translation>
    </message>
    <message>
        <source>Using X11 shared memory.</source>
        <translation type="obsolete">Gebruik X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="obsolete">Fout: Kan geen gedeelde afbeelding maken!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="obsolete">Fout: Kan geen gedeeld geheugen krijgen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="obsolete">Fout: Kan niet vastmaken aan gedeeld geheugen!</translation>
    </message>
    <message>
        <source>Not using X11 shared memory.</source>
        <translation type="obsolete">Gebruik geen X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <source>Error: Width or height is zero!</source>
        <translation type="obsolete">Fout: Breedte of hoogte is nul!</translation>
    </message>
    <message>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="obsolete">Fout: Breedte of hoogte is te groot, de maximum breedte en hoogte is %1!</translation>
    </message>
    <message>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="obsolete">Waarschuwing: XFixes wordt niet ondersteund door de server, de cursor is verborgen.</translation>
    </message>
    <message>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="obsolete">Fout: Ongeldige schermrechthoek!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="obsolete">Fout: Kan server niet vastmaken aan gedeeld geheugen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="obsolete">Fout: Kan geen afbeelding krijgen (met gedeeld geheugen)!
    Meestal betekent dit dat het opgenomen gebied niet volledig binnen het scherm is. Of heb je de schermresolutie veranderd?</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="obsolete">Fout: Kan geen afbeelding krijgen (zonder gedeeld geheugen)!
    Meestal betekent dit dat het opgenomen gebied niet volledig binnen het scherm is. Of heb je de schermresolutie veranderd?</translation>
    </message>
    <message>
        <source>Error: Sample rate it zero.</source>
        <translation type="obsolete">Fout: Samplefrequentie is nul.</translation>
    </message>
    <message>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="obsolete">Fout: Encoder vereist een sampleformaat dat niet ondersteund wordt!</translation>
    </message>
    <message>
        <source>Error: Encoding of audio frame failed!</source>
        <translation type="obsolete">Fout: Encoderen van audioframe mislukt!</translation>
    </message>
    <message>
        <source>Stopping encoder thread ...</source>
        <translation type="obsolete">Stop encoder thread ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="obsolete">Fout: Kan de codec niet vinden!</translation>
    </message>
    <message>
        <source>Using codec %1 (%2).</source>
        <translation type="obsolete">Gebruik codec %1 (%2).</translation>
    </message>
    <message>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="obsolete">Waarschuwing: Deze codec wordt gezien als experimenteel door libav/ffmpeg.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="obsolete">Fout: Kan codec niet openen!</translation>
    </message>
    <message>
        <source>Encoder thread started.</source>
        <translation type="obsolete">Encoder thread gestart.</translation>
    </message>
    <message>
        <source>Flushing encoder ...</source>
        <translation type="obsolete">Encoder afwerken ...</translation>
    </message>
    <message>
        <source>Encoder thread stopped.</source>
        <translation type="obsolete">Encoder thread gestopt.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="obsolete">Exceptie &apos;%1&apos; in encoder thread.</translation>
    </message>
    <message>
        <source>Unknown exception in encoder thread.</source>
        <translation type="obsolete">Onbekende exceptie in encoder thread.</translation>
    </message>
    <message>
        <source>Stopping encoders ...</source>
        <translation type="obsolete">Encoders stoppen ...</translation>
    </message>
    <message>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="obsolete">Wacht tot muxer thread stopt ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="obsolete">Fout: Kan header niet schrijven!</translation>
    </message>
    <message>
        <source>Finishing encoders ...</source>
        <translation type="obsolete">Encoders afwerken ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="obsolete">Fout: Kan geen nieuwe stream maken!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="obsolete">Fout: Kan codec-context standaardwaarden niet krijgen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="obsolete">Fout: Kan gekozen outputformaat niet vinden!</translation>
    </message>
    <message>
        <source>Using format %1 (%2).</source>
        <translation type="obsolete">Gebruik formaat %1 (%2).</translation>
    </message>
    <message>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="obsolete">Fout: Kan geen formaat-context maken!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="obsolete">Fout: Kan outputbestand niet openen!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="obsolete">Fout: Kan trailer niet schrijven, ga toch verder.</translation>
    </message>
    <message>
        <source>Muxer thread started.</source>
        <translation type="obsolete">Muxer thread gestart.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="obsolete">Fout: Kan geen frame naar de muxer schrijven!</translation>
    </message>
    <message>
        <source>Muxer thread stopped.</source>
        <translation type="obsolete">Muxer thread gestopt.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="obsolete">Exceptie &apos;%1&apos; in muxer thread.</translation>
    </message>
    <message>
        <source>Unknown exception in muxer thread.</source>
        <translation type="obsolete">Onbekende exceptie in muxer thread.</translation>
    </message>
    <message>
        <source>Stopping synchronizer thread ...</source>
        <translation type="obsolete">Synchronisator thread stoppen ...</translation>
    </message>
    <message>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="obsolete">Waarschuwing: Videobeeld met niet-monotone tijdswaarde ontvangen.</translation>
    </message>
    <message>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="obsolete">Waarschuwing: Video buffer overflow, sommige beelden zullen verloren gaan. De audio-input lijkt te traag te zijn.</translation>
    </message>
    <message>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="obsolete">Waarschuwing: Audiosamples met niet-monotone tijdswaarde ontvangen.</translation>
    </message>
    <message>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation type="obsolete">Waarschuwing: Te veel audiosamples, laat samples vallen om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation type="obsolete">Waarschuwing: Niet genoeg audiosamples, voeg stilte in om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation type="obsolete">Waarschuwing: Ontving gat in audiostream, voeg stilte in om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <source>Warning: Not enough audio samples, inserting zeros to keep the audio in sync with the video.</source>
        <translation type="obsolete">Waarschuwing: Niet genoeg audiosamples, voeg stilte in om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation type="obsolete">Waarschuwing: Audio-input is meer dan 2% te traag!</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="obsolete">Waarschuwing: Audio-input is meer dan 2% te snel!</translation>
    </message>
    <message>
        <source>Error: Audio sample format is not supported!</source>
        <translation type="obsolete">Fout: Audiosampleformaat wordt niet ondersteund!</translation>
    </message>
    <message>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="obsolete">Waarschuwing: Audio buffer overflow, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan). De video-input lijkt te traag te zijn.</translation>
    </message>
    <message>
        <source>Warning: Received hole in audio stream, inserting zeros to keep the audio in sync with the video.</source>
        <translation type="obsolete">Waarschuwing: Ontving gat in audiostream, voeg stilte in om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="obsolete">Waarschuwing: Desynchronisatie is te groot, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan).</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 5% too slow!</source>
        <translation type="obsolete">Waarschuwing: Audio-input is meer dan 5% te traag!</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation type="obsolete">Waarschuwing: Audio-input is meer dan 5% te snel!</translation>
    </message>
    <message>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="obsolete">Waarschuwing: Gat in de audiostream ontvangen, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan).</translation>
    </message>
    <message>
        <source>Synchronizer thread started.</source>
        <translation type="obsolete">Synchronisator thread gestart.</translation>
    </message>
    <message>
        <source>Synchronizer thread stopped.</source>
        <translation type="obsolete">Synchronisator thread gestopt.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="obsolete">Exceptie &apos;%1&apos; in synchronisator thread.</translation>
    </message>
    <message>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="obsolete">Onbekende exceptie in synchronisator thread.</translation>
    </message>
    <message>
        <source>Error: Width or height is not an even number!</source>
        <translation type="obsolete">Fout: Breedte of hoogte is geen even getal!</translation>
    </message>
    <message>
        <source>Error: Frame rate it zero!</source>
        <translation type="obsolete">Fout: Beelden per seconde is nul!</translation>
    </message>
    <message>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="obsolete">Fout: Encoderen van videobeeld mislukt!</translation>
    </message>
    <message>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="obsolete">Fout: Command-line optie &apos;%1&apos; neemt geen waarde aan!</translation>
    </message>
    <message>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="obsolete">Fout: Onbekende command-line optie &apos;%1&apos;!</translation>
    </message>
    <message>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="obsolete">Fout: Onbekend command-line argument &apos;%1&apos;!</translation>
    </message>
    <message>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">SimpleScreenRecorder heeft gedetecteerd dat je de propriëtaire NVIDIA-driver gebruikt met flipping ingeschakeld. Het is bekend dat dit storingen veroorzaakt tijdens de opname. Het is aangeraden om flipping uit te schakelen. Wil je dat ik dit voor je doe?

Je kan deze optie ook manueel veranderen in het NVIDIA-controlepaneel.</translation>
    </message>
    <message>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">Ik kon flipping niet uitschakelen om een of andere reden - sorry! Probeer om het uit te schakelen in het NVIDIA-controlepaneel.</translation>
    </message>
    <message>
        <source>SSR started</source>
        <translation type="obsolete">SSR gestart</translation>
    </message>
    <message>
        <source>SSR stopped</source>
        <translation type="obsolete">SSR gestopt</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="obsolete">Fout: Kan geen .ssr-map maken!</translation>
    </message>
    <message>
        <source>Error: Flushing resampler failed! Reason: %s</source>
        <translation type="obsolete">Fout: Afwerken van hersampler mislukt! Reden: %s</translation>
    </message>
    <message>
        <source>Resampling from %1 to %2.</source>
        <translation type="obsolete">Hersamplen van %1 naar %2.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create resampler! Reason: %s</source>
        <translation type="obsolete">Fout: Kan geen hersampler maken! Reden: %s</translation>
    </message>
    <message>
        <source>Resampling not needed.</source>
        <translation type="obsolete">Hersamplen niet nodig.</translation>
    </message>
    <message>
        <source>Error: Resampling failed!</source>
        <translation type="obsolete">Fout: Hersamplen mislukt!</translation>
    </message>
    <message>
        <source>Warning: An underrun has occurred, some samples were too late.</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="obsolete">Waarschuwing: Er was een underrun, een aantal samples waren te laat.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="obsolete">Fout: Kan apparaat niet herstellen na underrun!</translation>
    </message>
    <message>
        <source>Stopping synth thread ...</source>
        <translation type="obsolete">Stop synth thread ...</translation>
    </message>
    <message>
        <source>Synth thread started.</source>
        <translation type="obsolete">Synth thread gestart.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="obsolete">Fout: Kan samples niet schrijven!</translation>
    </message>
    <message>
        <source>Synth thread stopped.</source>
        <translation type="obsolete">Synth thread gestopt.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="obsolete">Exceptie &apos;%1&apos; in synth thread.</translation>
    </message>
    <message>
        <source>Unknown exception in synth thread.</source>
        <translation type="obsolete">Onbekende exceptie in synth thread.</translation>
    </message>
    <message>
        <source>Error: Resample ratio is out of range!</source>
        <translation type="obsolete">Fout: Hersampleratio is buiten bereik!</translation>
    </message>
    <message>
        <source>Error: Drift ratio is out of range!</source>
        <translation type="obsolete">Fout: Driftratio is buiten bereik!</translation>
    </message>
    <message>
        <source>Resample ratio is %1 (was %2).</source>
        <translation type="obsolete">Hersampleratio is %1 (was %2).</translation>
    </message>
    <message>
        <source>Resample ratio is %1 (was %2)</source>
        <translation type="obsolete">Hersampleratio is %1 (was %2).</translation>
    </message>
    <message>
        <source>Error: Could not connect to JACK!</source>
        <translation type="obsolete">Fout: Kan niet verbinden met JACK!</translation>
    </message>
    <message>
        <source>Error: Could not create JACK port!</source>
        <translation type="obsolete">Fout: Kan geen JACK poort maken!</translation>
    </message>
    <message>
        <source>Error: Could not set JACK process callback!</source>
        <translation type="obsolete">Fout: Kan geen JACK verwerkingscallback instellen!</translation>
    </message>
    <message>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation type="obsolete">Fout: Kan geen JACK samplefrequentiecallback instellen!</translation>
    </message>
    <message>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation type="obsolete">Fout: Kan geen JACK xrun callback instellen!</translation>
    </message>
    <message>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation type="obsolete">Fout: Kan geen JACK poortverbindingscallback instellen!</translation>
    </message>
    <message>
        <source>Error: Could not activate JACK client!</source>
        <translation type="obsolete">Fout: Kan JACK client niet activeren!</translation>
    </message>
    <message>
        <source>Connecting port %1 to %2.</source>
        <translation type="obsolete">Verbinding van poort %1 naar %2 gemaakt.</translation>
    </message>
    <message>
        <source>Disconnecting port %1 from %2.</source>
        <translation type="obsolete">Verbinding van poort %1 naar %2 verbroken.</translation>
    </message>
</context>
<context>
    <name>RecordScheduleEntryWidget</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="39"/>
        <source>Start</source>
        <translation>Start</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="40"/>
        <source>Pause</source>
        <translation>Pauze</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="46"/>
        <source>Time:</source>
        <translation>Tijd:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="51"/>
        <source>Action:</source>
        <translation>Actie:</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="257"/>
        <source>Video in</source>
        <translation>Video in</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="258"/>
        <source>Audio in</source>
        <translation>Audio in</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="259"/>
        <source>Video out</source>
        <translation>Video uit</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="260"/>
        <source>Audio out</source>
        <translation>Audio uit</translation>
    </message>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Synchronisatie-diagram</translation>
    </message>
</context>
</TS>
