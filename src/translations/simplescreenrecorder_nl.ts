<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="nl_NL">
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
        <translation type="unfinished">Sluiten</translation>
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
        <location filename="../AV/FastScaler.cpp" line="129"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Waarschuwing: Pixelformaat wordt niet ondersteund (%1 -&gt; %2), swscale wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
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
        <location filename="../AV/Input/ALSAInput.cpp" line="33"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Waarschuwing: Er was een overrun, een aantal samples gingen verloren.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fout: Kan apparaat niet herstellen na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="39"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fout: Kan het PCM apparaat niet starten na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="67"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="55"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation>Stop input thread ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="97"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation>Bronnenlijst genereren ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
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
        <location filename="../AV/Input/ALSAInput.cpp" line="176"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Waarschuwing: Kan geluidskaart %1 niet openen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="182"/>
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
        <location filename="../AV/Input/ALSAInput.cpp" line="163"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Plugin gevonden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="186"/>
        <source>Found card: [%1] %2</source>
        <translation>Kaart gevonden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="211"/>
        <source>Found device: [%1] %2</source>
        <translation>Apparaat gevonden: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="260"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Fout: Kan PCM apparaat niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="264"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="270"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Fout: Kan toegangstype niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="276"/>
        <location filename="../AV/SimpleSynth.cpp" line="140"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Fout: Kan sampleformaat niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="283"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Fout: Kan samplefrequentie niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="287"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Samplefrequentie %1 wordt niet ondersteund, %2 wordt gebruikt in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="296"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Fout: Kan het aantal kanalen niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="300"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Aantal kanalen %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="309"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Fout: Kan periodegrootte niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="313"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Periodegrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="322"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Fout: Kan de buffergrootte niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="326"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Buffergrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet toepassen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="352"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Fout: Kan het PCM apparaat niet starten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="237"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/X11Input.cpp" line="439"/>
        <source>Input thread started.</source>
        <translation>Input thread gestart.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation type="obsolete">Fout: Kan niet controleren of samples beschikbaar zijn!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="388"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Fout: Kan samples niet lezen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="414"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="358"/>
        <location filename="../AV/Input/JACKInput.cpp" line="288"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/X11Input.cpp" line="554"/>
        <source>Input thread stopped.</source>
        <translation>Input thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="418"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="362"/>
        <location filename="../AV/Input/JACKInput.cpp" line="292"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/X11Input.cpp" line="558"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Exceptie &apos;%1&apos; in input thread.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="421"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="365"/>
        <location filename="../AV/Input/JACKInput.cpp" line="295"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/X11Input.cpp" line="561"/>
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
        <location filename="../AV/Input/X11Input.cpp" line="310"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Fout: Kan geen gedeeld geheugen krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="315"/>
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
        <location filename="../AV/Input/JACKInput.cpp" line="71"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Fout: Kan niet verbinden met JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="80"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Fout: Kan geen JACK poort maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="86"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Fout: Kan geen JACK verwerkingscallback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="90"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Fout: Kan geen JACK samplefrequentiecallback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="94"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Fout: Kan geen JACK xrun callback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="98"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Fout: Kan geen JACK poortverbindingscallback instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="103"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Fout: Kan JACK client niet activeren!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="111"/>
        <location filename="../AV/Input/JACKInput.cpp" line="122"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Verbinding van poort %1 naar %2 gemaakt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="255"/>
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
        <location filename="../AV/Input/X11Input.cpp" line="70"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Fout: X11-afbeeldingspixelformaat wordt niet ondersteund!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="96"/>
        <source>Error: Width or height is zero!</source>
        <translation>Fout: Breedte of hoogte is nul!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="100"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Fout: Breedte of hoogte is te groot, de maximum breedte en hoogte is %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="249"/>
        <location filename="../GUI/HotkeyListener.cpp" line="115"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Fout: Kan X display niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Using X11 shared memory.</source>
        <translation>Gebruik X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="305"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Fout: Kan geen gedeelde afbeelding maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="260"/>
        <source>Not using X11 shared memory.</source>
        <translation>Gebruik geen X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="267"/>
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
        <location filename="../AV/Input/X11Input.cpp" line="388"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Fout: Ongeldige schermrechthoek!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="320"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Fout: Kan server niet vastmaken aan gedeeld geheugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="363"/>
        <source>Warning: Xinerama is not supported by X server, multi-monitor support may not work properly.</source>
        <comment>Don&apos;t translate &apos;Xinerama&apos;</comment>
        <translation>Waarschuwing: Xinerama wordt niet ondersteund door de X server, multi-monitor ondersteuning werkt mogelijk niet correct.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="369"/>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation>Waarschuwing: Geen monitors gedetecteerd, multi-monitor ondersteuning werkt mogelijk niet correct.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="505"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Fout: Kan geen afbeelding krijgen (met gedeeld geheugen)!
    Meestal betekent dit dat het opgenomen gebied niet volledig binnen het scherm is. Of heb je de schermresolutie veranderd?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="516"/>
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
        <location filename="../AV/Output/Synchronizer.cpp" line="509"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Waarschuwing: Audio-input is meer dan 2% te traag!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="513"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Waarschuwing: Audio-input is meer dan 2% te snel!</translation>
    </message>
    <message>
        <source>Error: Audio sample format is not supported!</source>
        <translation type="obsolete">Fout: Audiosampleformaat wordt niet ondersteund!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="548"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Waarschuwing: Audio buffer overflow, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan). De video-input lijkt te traag te zijn.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="584"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Waarschuwing: Ontving gat in audiostream, voeg stilte in om audio synchroon met de video te houden.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="885"/>
        <source>Synchronizer thread started.</source>
        <translation>Synchronisator thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="907"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Synchronisator thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="911"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Exceptie &apos;%1&apos; in synchronisator thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="914"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Onbekende exceptie in synchronisator thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="104"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Fout: Breedte of hoogte is geen even getal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="108"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Fout: Beelden per seconde is nul!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="165"/>
        <source>Using pixel format %1.</source>
        <translation>Gebruik pixelformaat %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="179"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Fout: Het pixelformaat wordt niet ondersteund door de codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="207"/>
        <source>Error: Sending of video frame failed!</source>
        <translation>Fout: Versturen van videoframe mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="228"/>
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
        <location filename="../AV/Output/VideoEncoder.cpp" line="241"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="262"/>
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
        <location filename="../common/CommandLineOptions.cpp" line="78"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="86"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Fout: Command-line optie &apos;%1&apos; neemt geen waarde aan!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="179"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Fout: Onbekende command-line optie &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="187"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Fout: Onbekend command-line argument &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="96"/>
        <source>SSR started</source>
        <translation>SSR gestart</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="127"/>
        <source>SSR stopped</source>
        <translation>SSR gestopt</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="228"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Fout: Kan geen .ssr map maken!</translation>
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
        <location filename="../AV/Output/OutputManager.cpp" line="346"/>
        <source>Fragment thread started.</source>
        <translation>Fragment-thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="364"/>
        <source>Next fragment ...</source>
        <translation>Volgende fragment ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="368"/>
        <source>Finishing ...</source>
        <translation>Afwerken ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="380"/>
        <source>Fragment thread stopped.</source>
        <translation>Fragment-thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="384"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation>Exceptie &apos;%1&apos; in fragment-thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="387"/>
        <source>Unknown exception in fragment thread.</source>
        <translation>Onbekende exceptie in fragment-thread.</translation>
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
        <translation>SimpleScreenRecorder heeft gedetecteerd dat je de propriëtaire NVIDIA-driver gebruikt met flipping ingeschakeld. Het is bekend dat dit storingen veroorzaakt tijdens de opname. Het is aangeraden om flipping uit te schakelen. Wil je dat ik dit voor je doe?

Je kan deze optie ook manueel veranderen in het NVIDIA-controlepaneel.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="108"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Ik kon flipping niet uitschakelen om een of andere reden - sorry! Probeer om het uit te schakelen in het NVIDIA-controlepaneel.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>De opname is opgeslagen. Je kan nu de video bewerken, of her-encoderen met betere instellingen om het bestand kleiner te maken (de standaardinstellingen zijn geoptimaliseerd voor kwaliteit en snelheid, niet bestandsgrootte).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>Terug naar het beginscherm</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Video input</source>
        <translation>Video input</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>Record the entire screen</source>
        <translation>Neem het hele scherm op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="247"/>
        <source>Record a fixed rectangle</source>
        <translation>Neem een vaste rechthoek op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="248"/>
        <source>Follow the cursor</source>
        <translation>Volg de cursor</translation>
    </message>
    <message>
        <source>Record OpenGL (experimental)</source>
        <translation type="obsolete">OpenGL opname (experimenteel)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="241"/>
        <source>Input profile</source>
        <translation>Inputprofiel</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="250"/>
        <source>Record OpenGL</source>
        <translation>Neem OpenGL op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="259"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Selecteer welke monitor opgenomen moet worden in een multi-monitor configuratie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>Record entire screen with cursor</source>
        <translation>Neem het hele scherm met cursor op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="261"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation>Neem het hele scherm waarop de cursor zich bevindt op, in plaats van de cursorpositie te volgen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <source>Select rectangle...</source>
        <translation>Selecteer rechthoek...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="263"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Gebruik de muis om de opgenomen rechthoek te selecteren.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="264"/>
        <source>Select window...</source>
        <translation>Selecteer venster...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Gebruik de muis om een venster te selecteren om op te nemen.
Hint: Als je op de rand van het venster klikt, zal het hele venster worden opgenomen (inclusief de randen). Anders wordt
enkel het client-gedeelte (binnenkant) van het venster opgenomen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="269"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL-instellingen...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Verander de instellingen voor OpenGL opnames.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="272"/>
        <source>Left:</source>
        <translation>Links:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De x-coordinaat van de linkerbovenhoek van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="278"/>
        <source>Top:</source>
        <translation>Boven:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="282"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De y-coordinaat van de linkerbovenhoek van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="284"/>
        <source>Width:</source>
        <translation>Breedte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="288"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De breedte van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="290"/>
        <source>Height:</source>
        <translation>Hoogte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="294"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De hoogte van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="296"/>
        <source>Frame rate:</source>
        <translation>Beelden per seconde:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="300"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Het aantal beelden per seconde in de uiteindelijke video. Hogere frame rates gebruiken meer CPU-tijd.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="301"/>
        <source>Scale video</source>
        <translation>Schaal video</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="302"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Schakel schalen in of uit. Schalen gebruikt meer CPU-tijd, maar als de geschaalde video kleiner is, zou dit het encoderen sneller kunnen maken.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="303"/>
        <source>Scaled width:</source>
        <translation>Geschaalde breedte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="307"/>
        <source>Scaled height:</source>
        <translation>Geschaalde hoogte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="311"/>
        <source>Record cursor</source>
        <translation>Neem de cursor op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="393"/>
        <source>Audio input</source>
        <translation>Audio input</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="395"/>
        <source>Record audio</source>
        <translation>Neem audio op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="396"/>
        <source>Backend:</source>
        <translation>Backend:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="411"/>
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
        <location filename="../GUI/PageInput.cpp" line="426"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>De PulseAudio-bron die gebruikt zal worden om op te nemen.
Een &apos;monitor&apos; is een bron die de audio opneemt die wordt afgespeeld door andere applicaties.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="433"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Indien aangevinkt zullen de poorten automatisch verbonden worden met de systeemopnamepoorten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="435"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Indien aangevinkt zullen de poorten automatisch verbonden worden met alles dat verbinding maakt met de systeemafspeelpoorten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="916"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Alle schermen: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="920"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Scherm %1: %2x%3 op %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1132"/>
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
        <location filename="../GUI/PageInput.cpp" line="408"/>
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
        <location filename="../GUI/PageInput.cpp" line="414"/>
        <location filename="../GUI/PageInput.cpp" line="423"/>
        <source>Source:</source>
        <translation>Bron:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="417"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>De ALSA-bron die gebruikt wordt voor opname.
De standaardkeuze is meestal goed. De &apos;shared&apos; bronnen kunnen door meerdere programma&apos;s tegelijk worden opgenomen, maar zijn mogelijk minder betrouwbaar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="419"/>
        <location filename="../GUI/PageInput.cpp" line="428"/>
        <source>Refresh</source>
        <translation>Vernieuwen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="420"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Vernieuwt de lijst met ALSA-bronnen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="429"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Vernieuwt de lijst met PulseAudio-bronnen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="432"/>
        <source>Record system microphone</source>
        <translation>Neem systeemmicrofoon op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="434"/>
        <source>Record system speakers</source>
        <translation>Neem systeemluidsprekers op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="482"/>
        <source>Back</source>
        <translation>Terug</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="483"/>
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
        <location filename="../GUI/PageOutput.cpp" line="247"/>
        <source>Video</source>
        <translation>Video</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="249"/>
        <location filename="../GUI/PageOutput.cpp" line="329"/>
        <source>Codec:</source>
        <translation>Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="254"/>
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
        <location filename="../GUI/PageOutput.cpp" line="258"/>
        <location filename="../GUI/PageOutput.cpp" line="342"/>
        <source>Codec name:</source>
        <translation>Codecnaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="264"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elke libav/ffmpeg-videocodec gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <source>Bit rate (in kbps):</source>
        <translation type="obsolete">Bitrate (in kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>De video-bitrate (in kilobit per seconde). Een hogere waarde betekent een hogere kwaliteit.
Als je geen idee hebt waar je moet beginnen, probeer dan 5000 en verander het indien nodig.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="269"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="280"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="287"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU-gebruik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="289"/>
        <source>fastest</source>
        <translation>snelste</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="294"/>
        <source>slowest</source>
        <translation>traagste</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="295"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>De encodeersnelheid. Een hogere waarde gebruikt *minder* CPU-tijd. (Ik heb de naam niet gekozen, dit is de naam
die gebruikt wordt door de VP8-encoder). Hogere waarden resulteren in lagere beeldkwaliteit, tenzij je de bitrate ook verhoogt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="274"/>
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
        <location filename="../GUI/PageOutput.cpp" line="265"/>
        <location filename="../GUI/PageOutput.cpp" line="349"/>
        <source>Bit rate (in kbit/s):</source>
        <translation>Bitrate (in kbit/s):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="285"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>De encodeersnelheid. Een hogere snelheid gebruikt minder CPU (waardoor meer beelden per seconde opgenomen kunnen worden),
maar resulteert in grotere bestanden. De kwaliteit verandert normaal gezien niet veel.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <location filename="../GUI/PageOutput.cpp" line="352"/>
        <source>Custom options:</source>
        <translation>Aangepaste opties:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="299"/>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Aangepaste opties gescheiden door komma&apos;s (b.v. optie1=waarde1,optie2=waarde2,optie3=waarde3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <source>Allow frame skipping</source>
        <translation>Frames overslaan toestaan</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="301"/>
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
        <location filename="../GUI/PageOutput.cpp" line="327"/>
        <source>Audio</source>
        <translation>Audio</translation>
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
        <location filename="../GUI/PageOutput.cpp" line="348"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elke libav/ffmpeg-audiocodec gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>De video-bitrate (in kilobit per seconde). Een hogere waarde betekent een hogere kwaliteit. De typische waarde is 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="376"/>
        <source>Back</source>
        <translation>Terug</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="377"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="631"/>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <source>not installed</source>
        <translation>niet geinstalleerd</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="633"/>
        <location filename="../GUI/PageOutput.cpp" line="641"/>
        <source>not supported by container</source>
        <translation>niet ondersteund door container</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="684"/>
        <source>Save recording as</source>
        <translation>Opname opslaan als</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="525"/>
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
        <location filename="../GUI/PageRecord.cpp" line="162"/>
        <source>Recording</source>
        <translation>Opname</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="168"/>
        <source>Edit schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="171"/>
        <source>Enable recording hotkey</source>
        <translation>Opname-sneltoets inschakelen</translation>
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
        <translation>Schakel geluidsnotificaties in</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="177"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="179"/>
        <source>Hotkey:</source>
        <translation>Sneltoets:</translation>
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
        <translation>De toets die je moet indrukken (in combinatie met de gegeven modifiers) om de opname te starten of te pauzeren.
Het programma dat je aan het opnemen bent zal de toets niet ontvangen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Information</source>
        <translation>Informatie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="240"/>
        <source>Total time:</source>
        <translation>Totale tijd:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>FPS in:</source>
        <translation>FPS in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="244"/>
        <source>FPS out:</source>
        <translation>FPS uit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Size in:</source>
        <translation>Grootte in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="248"/>
        <source>Size out:</source>
        <translation>Grootte uit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="250"/>
        <source>File name:</source>
        <translation>Bestandsnaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="253"/>
        <source>File size:</source>
        <translation>Bestandsgrootte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="255"/>
        <source>Bit rate:</source>
        <translation>Bitrate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="278"/>
        <source>Preview</source>
        <translation>Voorbeeld</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="282"/>
        <source>Preview frame rate:</source>
        <translation>Voorbeeld FPS:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="286"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Opmerking: Voorbeeld vereist extra CPU-tijd (vooral bij hoge FPS).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="335"/>
        <source>Log</source>
        <translation>Log</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="350"/>
        <location filename="../GUI/PageRecord.cpp" line="358"/>
        <source>Cancel recording</source>
        <translation>Opname annuleren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="351"/>
        <location filename="../GUI/PageRecord.cpp" line="360"/>
        <source>Save recording</source>
        <translation>Opname opslaan</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="365"/>
        <source>Quit</source>
        <translation>Afsluiten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="415"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Je hebt de huidige opname nog niet opgeslagen, als je het programma nu sluit zal deze verloren gaan.
Weet je zeker dat je het programma wilt sluiten?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="427"/>
        <source>Hide window</source>
        <translation>Verberg venster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="429"/>
        <source>Show window</source>
        <translation>Toon venster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="968"/>
        <source>Encoding remaining data ...</source>
        <translation>Overblijvende data encoderen ...</translation>
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
        <location filename="../GUI/PageRecord.cpp" line="749"/>
        <source>Starting output ...</source>
        <translation>Output starten ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="764"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Fout: Kan de grootte van de OpenGL-applicatie niet krijgen omdat de GLInject input niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="808"/>
        <source>Started output.</source>
        <translation>Output gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="828"/>
        <source>Stopping output ...</source>
        <translation>Output stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="846"/>
        <source>Stopped output.</source>
        <translation>Output gestopt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="877"/>
        <source>Starting input ...</source>
        <translation>Input starten ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="883"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Fout: Kan de GLInject input niet starten omdat deze niet aangemaakt is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="908"/>
        <source>Started input.</source>
        <translation>Input gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="937"/>
        <source>Stopping input ...</source>
        <translation>Input stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="952"/>
        <source>Stopped input.</source>
        <translation>Input gestopt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="630"/>
        <source>Starting page ...</source>
        <translation>Pagina starten ...</translation>
    </message>
    <message>
        <source>Error: Something went wrong during GLInject initialization.</source>
        <translation type="obsolete">Fout: Er ging iets fout tijdens de GLInject initialisatie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="662"/>
        <source>Started page.</source>
        <translation>Pagina gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="694"/>
        <source>Stopping page ...</source>
        <translation>Pagina stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="721"/>
        <source>Stopped page.</source>
        <translation>Pagina gestopt.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application because GLInject has not been started.</source>
        <translation type="obsolete">Fout: Kan de grootte van de OpenGL-applicatie niet krijgen omdat GLInject niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="769"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Fout: Kon de grootte van de OpenGL-applicatie niet krijgen. Ofwel is de applicatie niet correct gestart, ofwel heeft de applicatie nog geen OpenGL-venster gemaakt. Als je wil beginnen met opnemen voordat de applicatie is gestart, dan moet je schalen inschakelen en manueel de videogrootte instellen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="653"/>
        <location filename="../GUI/PageRecord.cpp" line="817"/>
        <location filename="../GUI/PageRecord.cpp" line="913"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Fout: Er ging iets fout tijdens de initialisatie.</translation>
    </message>
    <message>
        <source>Error: Could not create a GLInject input because GLInject has not been started.</source>
        <translation type="obsolete">Fout: Kan geen GLInject input maken omdat GLInject niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1061"/>
        <location filename="../GUI/PageRecord.cpp" line="1071"/>
        <source>Pause recording</source>
        <translation>Opname pauzeren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1064"/>
        <location filename="../GUI/PageRecord.cpp" line="1074"/>
        <source>Start recording</source>
        <translation>Opname starten</translation>
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
        <translation>Voorbeeld stoppen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1104"/>
        <source>Start preview</source>
        <translation>Voorbeeld starten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1145"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Fout: Er ging iets fout bij het maken van de synth.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1193"/>
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
