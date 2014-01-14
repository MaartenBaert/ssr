<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="nl_NL">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="80"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Over SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>For more information:</source>
        <translation>Voor meer informatie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>The source code of this program can be found at:</source>
        <translation>De broncode van dit programma kan gevonden worden op:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>This program uses:</source>
        <translation>Dit programma gebruikt:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 voor de grafische gebruikersinterface</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="93"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 of %2 (afhankelijk van je distributie) voor video/audio-encoding</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="94"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 voor het hooken van systeemfuncties voor OpenGL opnames</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="785"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL instellingen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="788"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Waarschuwing: OpenGL opname werkt door een library te injecteren in het programma dat wordt opgenomen. Deze library zal sommige systeemfuncties vervangen om beelden op te nemen voor ze weergegeven worden op het scherm. Als je probeert om een spel op te nemen dat probeert om hacking-pogingen te detecteren, dan is het (theoretisch) mogelijk dat het spel dit als een hack zal zien. Dit zou ervoor kunnen zorgen dat je geband wordt, dus het is een goed idee om eerst te controleren dat het programma dat je wil opnemen je niet zal bannen, *voordat* je het probeert. Je bent gewaarschuwd :).&lt;/p&gt;

&lt;p&gt;Nog een waarschuwing: OpenGL opname is experimenteel, het werkt niet altijd en het kan het programma dat je wil opnemen zelfs laten crashen. Als je vreest data te verliezen, maak dan eerst een backup!&lt;/p&gt;

&lt;p&gt;Als je Steam-spellen wil opnemen, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;lees dan eerst dit&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="801"/>
        <source>Command:</source>
        <translation>Commando:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="803"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Dit commando zal worden uitgevoerd om het programma dat opgenomen moet worden te starten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="805"/>
        <source>Working directory:</source>
        <translation>Werkmap:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="807"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Het commando zal worden uitgevoerd in deze map. Als je dit leeglaat, dan wordt de werkmap niet veranderd.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="809"/>
        <source>Start the OpenGL application automatically</source>
        <translation>Start de OpenGL-applicatie automatisch</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="810"/>
        <source>If checked, the above command will be executed automatically (combined with some environment variables). If not checked,
you have to start the OpenGL application yourself (the full command, including the required environment variables, is shown in the log).</source>
        <translation>Indien aangevinkt zal het bovenstaande commando automatisch worden uitgevoerd (samen met een aantal omgevingsvariabelen).
Indien niet aangevinkt moet je zelf de OpenGL-applicatie starten (het volledige commando, inclusief de vereiste omgevingsvariabelen, zal worden weergegeven in de log).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="813"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Geen strikte permissies voor gedeeld geheugen (onveilig)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="814"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Indien aangevinkt zullen andere gebruikers op dezelfde machine toegang hebben tot het gedeeld geheugen dat gebruikt wordt om te communiceren met het OpenGL-programma.
Dit betekent dat andere gebruikers (theoretisch) kunnen zien wat je opneemt, de beelden aanpassen, hun eigen beelden injecteren, of simpelweg de communicatie verstoren.
Dit geldt zelfs voor gebruikers die op afstand inloggen (ssh). Je moet dit enkel inschakelen als je een programma moet opnemen dat uitgevoerd wordt als een andere gebruiker.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="818"/>
        <source>Maximum image size (megapixels):</source>
        <translation>Maximum afbeeldingsgrootte (megapixels):</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="820"/>
        <source>This setting changes the amount of shared memory that will be allocated to send frames back to the main program.
The size of the shared memory can&apos;t be changed anymore once the program has been started, so if the program you
are trying to record is too large, recording won&apos;t work. 2 megapixels should be enough in almost all cases. Be careful,
high values will use a lot of memory!</source>
        <translation>Deze instelling verandert de hoeveelheid gedeeld geheugen die zal worden gereserveerd om beelden terug te sturen naar het hoofdprogramma.
De grootte van het gedeeld geheugen kan niet meer veranderd worden eens het programma gestart is, dus als het programma dat je probeert
op te nemen te groot is, dan zal de opname mislukken. 2 megapixels zou genoeg moeten zijn in bijna alle gevallen. Wees voorzichtig, grote waarden
zullen veel geheugen gebruiken!</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="824"/>
        <source>Capture front buffer instead of back buffer</source>
        <translation>Neem de front buffer op in plaats van de back buffer</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="825"/>
        <source>If checked, the injected library will read the front buffer (the frame that&apos;s currently on the screen) rather than the back buffer
(the new frame). This may be useful for some special applications that draw directly to the screen.</source>
        <translation>Indien aangevinkt zal de geinjecteerde library de front buffer lezen (het beeld dat op dit moment op het scherm staat) in plaats van de back buffer
(het nieuwe beeld). Dit zou nuttig kunnen zijn voor sommige speciale applicaties die rechtstreeks op het scherm tekenen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="828"/>
        <source>Limit application frame rate</source>
        <translation>Limiteer beelden per seconde van de applicatie</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="829"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Indien ingeschakeld zal de geinjecteerde library de applicatie vertragen zodat het aantal beelden per seconde niet hoger wordt dan de frame rate van de opname.
Dit verhindert dat de applicatie CPU-tijd gebruikt voor beelden die niet opgenomen zullen worden, en resulteert soms in vloeiendere video
(dit hangt af van de applicatie).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="834"/>
        <source>Close</source>
        <translation>Sluiten</translation>
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
        <location filename="../GUI/PageInput.cpp" line="77"/>
        <source>Video input</source>
        <translation>Video input</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="80"/>
        <source>Record the entire screen</source>
        <translation>Neem het hele scherm op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="81"/>
        <source>Record a fixed rectangle</source>
        <translation>Neem een vaste rechthoek op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="82"/>
        <source>Follow the cursor</source>
        <translation>Volg de cursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="83"/>
        <source>Record OpenGL (experimental)</source>
        <translation>OpenGL opname (experimenteel)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="89"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Selecteer welke monitor opgenomen moet worden in een multi-monitor configuratie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="90"/>
        <source>Select rectangle...</source>
        <translation>Selecteer rechthoek...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="91"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Gebruik de muis om de opgenomen rechthoek te selecteren.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="92"/>
        <source>Select window...</source>
        <translation>Selecteer venster...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="93"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Gebruik de muis om een venster te selecteren om op te nemen.
Hint: Als je op de rand van het venster klikt, zal het hele venster worden opgenomen (inclusief de randen). Anders wordt
enkel het client-gedeelte (binnenkant) van het venster opgenomen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="96"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL-instellingen...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="97"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Verander de instellingen voor OpenGL opnames.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="98"/>
        <source>Left:</source>
        <translation>Links:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="102"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De x-coordinaat van de linkerbovenhoek van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="104"/>
        <source>Top:</source>
        <translation>Boven:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="108"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De y-coordinaat van de linkerbovenhoek van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="110"/>
        <source>Width:</source>
        <translation>Breedte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="114"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De breedte van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="116"/>
        <source>Height:</source>
        <translation>Hoogte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="120"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>De hoogte van de opgenomen rechthoek.
Hint: Je kan deze waarde ook aanpassen met het scrollwiel of de omhoog/omlaag-pijltjes.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="122"/>
        <source>Frame rate:</source>
        <translation>Beelden per seconde:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="126"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Het aantal beelden per seconde in de uiteindelijke video. Hogere frame rates gebruiken meer CPU-tijd.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>Scale video</source>
        <translation>Schaal video</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="128"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Schakel schalen in of uit. Schalen gebruikt meer CPU-tijd, maar als de geschaalde video kleiner is, zou dit het encoderen sneller kunnen maken.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="129"/>
        <source>Scaled width:</source>
        <translation>Geschaalde breedte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Scaled height:</source>
        <translation>Geschaalde hoogte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="137"/>
        <source>Record cursor</source>
        <translation>Neem de cursor op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="207"/>
        <source>Audio input</source>
        <translation>Audio input</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="209"/>
        <source>Record audio</source>
        <translation>Neem audio op</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="210"/>
        <source>Backend:</source>
        <translation>Backend:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="223"/>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation>Het ALSA-apparaat dat gebruikt zal worden om op te nemen. Normaal hoort dit &apos;default&apos; te zijn.
Je kan dit veranderen naar iets zoals plughw:0,0 (dit betekent geluidskaard 0 input 0 met plugins ingeschakeld).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="229"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>De PulseAudio-bron die gebruikt zal worden om op te nemen.
Een &apos;monitor&apos; is een bron die de audio opneemt die wordt afgespeeld door andere applicaties.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="576"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Alle schermen: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="580"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Scherm %1: %2x%3 op %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="722"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Scherm %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="754"/>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation>Je hebt geen commando ingegeven om de OpenGL-applicatie die je wil opnemen te starten.
Klik op de &apos;OpenGL instellingen&apos; knop en geef een commando in.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="219"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>De audio-backend die gebruikt zal worden om op te nemen.
De ALSA-backend zal ook werken op systemen die PulseAudio gebruiken, maar het is beter om de PulseAudio-backend rechtstreeks te gebruiken.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="221"/>
        <source>Device:</source>
        <translation>Apparaat:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="226"/>
        <source>Source:</source>
        <translation>Bron:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="231"/>
        <source>Refresh</source>
        <translation>Vernieuwen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="232"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Vernieuwt de lijst met PulseAudio-bronnen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="257"/>
        <source>Back</source>
        <translation>Terug</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="258"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="70"/>
        <location filename="../GUI/PageOutput.cpp" line="76"/>
        <location filename="../GUI/PageOutput.cpp" line="83"/>
        <source>Other...</source>
        <translation>Andere...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <source>Uncompressed</source>
        <translation>Ongecomprimeerd</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="58"/>
        <location filename="../GUI/PageOutput.cpp" line="61"/>
        <location filename="../GUI/PageOutput.cpp" line="64"/>
        <location filename="../GUI/PageOutput.cpp" line="67"/>
        <location filename="../GUI/PageOutput.cpp" line="103"/>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>bestanden</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="137"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Fout: Kon geen enkele geschikte container vinden in libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="141"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Fout: Kon geen enkele geschikte videocodec vinden in libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="145"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Fout: Kon geen enkele geschikte audiocodec vinden in libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="149"/>
        <source>File</source>
        <translation>Bestand</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="151"/>
        <source>Save as:</source>
        <translation>Opslaan als:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="153"/>
        <source>The recording will be saved to this location.</source>
        <translation>De opname wordt opgeslagen op deze locatie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="154"/>
        <source>Browse...</source>
        <translation>Bladeren...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="155"/>
        <source>Separate file per segment</source>
        <translation>Apart bestand per segment</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="156"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation>Indien aangevinkt zal een apart videobestand aangemaakt worden elke keer wanneer je de opname pauzeert en hervat.
Als de originele bestandsnaam &apos;test.mkv&apos; is, zullen de segmenten worden opgeslagen als &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
Bestandsnamen die al bestaan zullen worden overgeslagen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="159"/>
        <source>Container:</source>
        <translation>Container:</translation>
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
        <location filename="../GUI/PageOutput.cpp" line="176"/>
        <source>Container name:</source>
        <translation>Containernaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elk libav/ffmpeg-formaat gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>Video</source>
        <translation>Video</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <location filename="../GUI/PageOutput.cpp" line="280"/>
        <source>Codec:</source>
        <translation>Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="205"/>
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
        <location filename="../GUI/PageOutput.cpp" line="209"/>
        <location filename="../GUI/PageOutput.cpp" line="293"/>
        <source>Codec name:</source>
        <translation>Codecnaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="215"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elke libav/ffmpeg-videocodec gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="216"/>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <source>Bit rate (in kbps):</source>
        <translation>Bitrate (in kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="218"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>De video-bitrate (in kilobit per seconde). Een hogere waarde betekent een hogere kwaliteit.
Als je geen idee hebt waar je moet beginnen, probeer dan 5000 en verander het indien nodig.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="231"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="238"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU-gebruik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>fastest</source>
        <translation>snelste</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="245"/>
        <source>slowest</source>
        <translation>traagste</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="246"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>De encodeersnelheid. Een hogere waarde gebruikt *minder* CPU-tijd. (Ik heb de naam niet gekozen, dit is de naam
die gebruikt wordt door de VP8-encoder). Hogere waarden resulteren in lagere beeldkwaliteit, tenzij je de bitrate ook verhoogt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Deze instelling verandert de videokwaliteit. Een lagere waarde betekent een hogere kwaliteit.
Het toegestane bereik is 0-51 (0 betekent verliesvrij, de standaardwaarde is 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="236"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>De encodeersnelheid. Een hogere snelheid gebruikt minder CPU (waardoor meer beelden per seconde opgenomen kunnen worden),
maar resulteert in grotere bestanden. De kwaliteit verandert normaal gezien niet veel.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="248"/>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Custom options:</source>
        <translation>Aangepaste opties:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <location filename="../GUI/PageOutput.cpp" line="305"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Aangepaste opties gescheiden door komma&apos;s (b.v. optie1=waarde1,optie2=waarde2,optie3=waarde3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="251"/>
        <source>Allow frame skipping</source>
        <translation>Frames overslaan toestaan</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="252"/>
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
        <location filename="../GUI/PageOutput.cpp" line="299"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Voor gevorderde gebruikers. Je kan elke libav/ffmpeg-audiocodec gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>De video-bitrate (in kilobit per seconde). Een hogere waarde betekent een hogere kwaliteit. De typische waarde is 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="319"/>
        <source>Back</source>
        <translation>Terug</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="320"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="546"/>
        <location filename="../GUI/PageOutput.cpp" line="554"/>
        <source>not installed</source>
        <translation>niet geinstalleerd</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="548"/>
        <location filename="../GUI/PageOutput.cpp" line="556"/>
        <source>not supported by container</source>
        <translation>niet ondersteund door container</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="599"/>
        <source>Save recording as</source>
        <translation>Opname opslaan als</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <source>You did not select an output file!</source>
        <translation>Je hebt geen outputbestand gekozen!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="643"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>Het bestand &apos;%1&apos; bestaat al. Weet je zeker dat je het wil overschrijven?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="146"/>
        <source>Recording</source>
        <translation>Opname</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="150"/>
        <source>Enable recording hotkey</source>
        <translation>Opname-sneltoets inschakelen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Enable sound notifications</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Hotkey:</source>
        <translation>Sneltoets:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="153"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
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
        <translation>De toets die je moet indrukken (in combinatie met de gegeven modifiers) om de opname te starten of te pauzeren.
Het programma dat je aan het opnemen bent zal de toets niet ontvangen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="198"/>
        <source>Information</source>
        <translation>Informatie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="200"/>
        <source>Total time:</source>
        <translation>Totale tijd:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="202"/>
        <source>FPS in:</source>
        <translation>FPS in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="204"/>
        <source>FPS out:</source>
        <translation>FPS uit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="206"/>
        <source>Size in:</source>
        <translation>Grootte in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="208"/>
        <source>Size out:</source>
        <translation>Grootte uit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="210"/>
        <source>File name:</source>
        <translation>Bestandsnaam:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="213"/>
        <source>File size:</source>
        <translation>Bestandsgrootte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="215"/>
        <source>Bit rate:</source>
        <translation>Bitrate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Preview</source>
        <translation>Voorbeeld</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>Preview frame rate:</source>
        <translation>Voorbeeld FPS:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Opmerking: Voorbeeld vereist extra CPU-tijd (vooral bij hoge FPS).</translation>
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
        <translation>Opname annuleren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="311"/>
        <location filename="../GUI/PageRecord.cpp" line="317"/>
        <source>Save recording</source>
        <translation>Opname opslaan</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="365"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Je hebt de huidige opname nog niet opgeslagen, als je het programma nu sluit zal deze verloren gaan.
Weet je zeker dat je het programma wilt sluiten?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="625"/>
        <source>Starting output ...</source>
        <translation>Output starten ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="677"/>
        <source>Started output.</source>
        <translation>Output gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="696"/>
        <source>Stopping output ...</source>
        <translation>Output stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="714"/>
        <source>Stopped output.</source>
        <translation>Output gestopt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="743"/>
        <source>Starting input ...</source>
        <translation>Input starten ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="767"/>
        <source>Started input.</source>
        <translation>Input gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="793"/>
        <source>Stopping input ...</source>
        <translation>Input stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="807"/>
        <source>Stopped input.</source>
        <translation>Input gestopt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="517"/>
        <source>Starting page ...</source>
        <translation>Pagina starten ...</translation>
    </message>
    <message>
        <source>Error: Something went wrong during GLInject initialization.</source>
        <translation type="obsolete">Fout: Er ging iets fout tijdens de GLInject initialisatie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="543"/>
        <source>Started page.</source>
        <translation>Pagina gestart.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="572"/>
        <source>Stopping page ...</source>
        <translation>Pagina stoppen ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="598"/>
        <source>Stopped page.</source>
        <translation>Pagina gestopt.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="636"/>
        <source>Error: Could not get the size of the OpenGL application because GLInject has not been started.</source>
        <translation>Fout: Kan de grootte van de OpenGL-applicatie niet krijgen omdat GLInject niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="641"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Fout: Kon de grootte van de OpenGL-applicatie niet krijgen. Ofwel is de applicatie niet correct gestart, ofwel heeft de applicatie nog geen OpenGL-venster gemaakt. Als je wil beginnen met opnemen voordat de applicatie is gestart, dan moet je schalen inschakelen en manueel de videogrootte instellen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="536"/>
        <location filename="../GUI/PageRecord.cpp" line="685"/>
        <location filename="../GUI/PageRecord.cpp" line="772"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Fout: Er ging iets fout tijdens de initialisatie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="748"/>
        <source>Error: Could not create a GLInject input because GLInject has not been started.</source>
        <translation>Fout: Kan geen GLInject input maken omdat GLInject niet gestart is.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="870"/>
        <location filename="../GUI/PageRecord.cpp" line="874"/>
        <source>Pause recording</source>
        <translation>Opname pauzeren</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="877"/>
        <location filename="../GUI/PageRecord.cpp" line="881"/>
        <source>Start recording</source>
        <translation>Opname starten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="890"/>
        <source>Stop preview</source>
        <translation>Voorbeeld stoppen</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="893"/>
        <source>Start preview</source>
        <translation>Voorbeeld starten</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="927"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="959"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Weet je zeker dat je deze opname wilt annuleren?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="972"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>Je hebt nog niets opgenomen, er is niets om op te slaan.

De startknop staat bovenaan ;).</translation>
    </message>
</context>
<context>
    <name>PageWelcome</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="36"/>
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
        <location filename="../GUI/PageWelcome.cpp" line="46"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Over SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="47"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../common/DetectCPUFeatures.cpp" line="39"/>
        <source>CPU features</source>
        <translation>CPU-eigenschappen</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="76"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Waarschuwing: Pixelformaat wordt niet ondersteund (%1 -&gt; %2), swscale wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="85"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Fout: Kan geen swscale context krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="104"/>
        <location filename="../AV/FastScaler.cpp" line="127"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation>Waarschuwing: Geheugen is niet goed uitgelijnd voor SSE, de fallback converter wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="89"/>
        <location filename="../AV/SimpleSynth.cpp" line="89"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Fout: Kan PCM apparaat niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="93"/>
        <location filename="../AV/SimpleSynth.cpp" line="93"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="99"/>
        <location filename="../AV/SimpleSynth.cpp" line="99"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Fout: Kan toegangstype niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="105"/>
        <location filename="../AV/SimpleSynth.cpp" line="105"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Fout: Kan sampleformaat niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="112"/>
        <location filename="../AV/SimpleSynth.cpp" line="112"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Fout: Kan samplefrequentie niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Waarschuwing: Er was een overrun, een aantal samples gingen verloren.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fout: Kan apparaat niet herstellen na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Fout: Kan het PCM apparaat niet starten na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="55"/>
        <location filename="../AV/Input/X11Input.cpp" line="206"/>
        <source>Stopping input thread ...</source>
        <translation>Stop input thread ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
        <location filename="../AV/SimpleSynth.cpp" line="116"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Samplefrequentie %1 wordt niet ondersteund, %2 wordt gebruikt in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="124"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Fout: Kan het aantal kanalen niet instellen!</translation>
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
        <location filename="../AV/Input/ALSAInput.cpp" line="131"/>
        <location filename="../AV/SimpleSynth.cpp" line="131"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Fout: Kan periodegrootte niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="135"/>
        <location filename="../AV/SimpleSynth.cpp" line="135"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Periodegrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="144"/>
        <location filename="../AV/SimpleSynth.cpp" line="144"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="148"/>
        <location filename="../AV/SimpleSynth.cpp" line="148"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="156"/>
        <location filename="../AV/SimpleSynth.cpp" line="156"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet toepassen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="174"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Fout: Kan het PCM apparaat niet starten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="195"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="95"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="333"/>
        <source>Input thread started.</source>
        <translation>Input thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="215"/>
        <location filename="../AV/SimpleSynth.cpp" line="207"/>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation>Fout: Kan niet controleren of samples beschikbaar zijn!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="228"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Fout: Kan samples niet lezen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="254"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="155"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="387"/>
        <location filename="../AV/Input/X11Input.cpp" line="423"/>
        <source>Input thread stopped.</source>
        <translation>Input thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="258"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="159"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="391"/>
        <location filename="../AV/Input/X11Input.cpp" line="427"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Exceptie &apos;%1&apos; in input thread.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="261"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="162"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="394"/>
        <location filename="../AV/Input/X11Input.cpp" line="430"/>
        <source>Unknown exception in input thread.</source>
        <translation>Onbekende exceptie in input thread.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="122"/>
        <source>Error: Image is too small!</source>
        <translation>Fout: De afbeelding is te klein!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="126"/>
        <source>Error: Image is too large!</source>
        <translation>Fout: De afbeelding is te groot!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="134"/>
        <source>Error: Image doesn&apos;t fit in memory!</source>
        <translation>Fout: De afbeelding past niet in het geheugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="118"/>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation>Fout: Kan geen frame gedeeld geheugen krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="123"/>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation>Fout: Kan niet vastmaken aan frame gedeeld geheugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="150"/>
        <source>Full command</source>
        <translation>Volledig commando</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="158"/>
        <source>Error: Can&apos;t run command!</source>
        <translation>Fout: Kan commando niet uitvoeren!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Fout: pa_mainloop_prepare mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Fout: pa_mainloop_poll mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Fout: pa_mainloop_dispatch mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation>Fout: Kan geen hoofdlus maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
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
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Fout: Verbindingspoging mislukt! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Fout: Kan geen stream maken! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Fout: Kan stream niet verbinden! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Fout: Stream verbindingspoging mislukt! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Fout: Kan geen namen van bronnen krijgen! Reden: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="312"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Fout: pa_stream_peek mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="375"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Waarschuwing: De audiobron werd gestopt. Het huidige segment zal gestopt worden totdat de bron herstart.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="380"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Waarschuwing: Stream werd verplaatst naar een andere bron.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Fout: X11-afbeeldingspixelformaat wordt niet ondersteund!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="226"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Fout: Kan X display niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="235"/>
        <source>Using X11 shared memory.</source>
        <translation>Gebruik X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="238"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Fout: Kan geen gedeelde afbeelding maken!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="103"/>
        <location filename="../AV/Input/X11Input.cpp" line="243"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Fout: Kan geen gedeeld geheugen krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="108"/>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Fout: Kan niet vastmaken aan gedeeld geheugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="254"/>
        <source>Not using X11 shared memory.</source>
        <translation>Gebruik geen X11 gedeeld geheugen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="185"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="57"/>
        <source>Error: Width or height is zero!</source>
        <translation>Fout: Breedte of hoogte is nul!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="189"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="61"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Fout: Breedte of hoogte is te groot, de maximum breedte en hoogte is %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="262"/>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Waarschuwing: XFixes wordt niet ondersteund door de server, de cursor is verborgen.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="317"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Fout: Ongeldige schermrechthoek!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="373"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Fout: Kan server niet vastmaken aan gedeeld geheugen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Fout: Kan geen afbeelding krijgen (met gedeeld geheugen)!
    Meestal betekent dit dat het opgenomen gebied niet volledig binnen het scherm is. Of heb je de schermresolutie veranderd?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="390"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Fout: Kan geen afbeelding krijgen (zonder gedeeld geheugen)!
    Meestal betekent dit dat het opgenomen gebied niet volledig binnen het scherm is. Of heb je de schermresolutie veranderd?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="45"/>
        <source>Error: Sample rate it zero.</source>
        <translation>Fout: Samplefrequentie is nul.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="126"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Fout: Encoder vereist een sampleformaat dat niet ondersteund wordt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="149"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="170"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Fout: Encoderen van audioframe mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="62"/>
        <source>Stopping encoder thread ...</source>
        <translation>Stop encoder thread ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="82"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Fout: Kan de codec niet vinden!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="87"/>
        <source>Using codec %1 (%2).</source>
        <translation>Gebruik codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Waarschuwing: Deze codec wordt gezien als experimenteel door libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="106"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Fout: Kan codec niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="160"/>
        <source>Encoder thread started.</source>
        <translation>Encoder thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="189"/>
        <source>Flushing encoder ...</source>
        <translation>Encoder afwerken ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="196"/>
        <source>Encoder thread stopped.</source>
        <translation>Encoder thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="200"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Exceptie &apos;%1&apos; in encoder thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="203"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Onbekende exceptie in encoder thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="72"/>
        <source>Stopping encoders ...</source>
        <translation>Encoders stoppen ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="79"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Wacht tot muxer thread stopt ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Fout: Kan header niet schrijven!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="111"/>
        <source>Finishing encoders ...</source>
        <translation>Encoders afwerken ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="143"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Fout: Kan geen nieuwe stream maken!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="149"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Fout: Kan codec-context standaardwaarden niet krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="195"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Fout: Kan gekozen outputformaat niet vinden!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Using format %1 (%2).</source>
        <translation>Gebruik formaat %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="204"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Fout: Kan geen formaat-context maken!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="211"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Fout: Kan outputbestand niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="224"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Fout: Kan trailer niet schrijven, ga toch verder.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="257"/>
        <source>Muxer thread started.</source>
        <translation>Muxer thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="311"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Fout: Kan geen frame naar de muxer schrijven!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="339"/>
        <source>Muxer thread stopped.</source>
        <translation>Muxer thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="343"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Exceptie &apos;%1&apos; in muxer thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="346"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Onbekende exceptie in muxer thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="119"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Synchronisator thread stoppen ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="237"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Waarschuwing: Videobeeld met niet-monotone tijdswaarde ontvangen.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="269"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Waarschuwing: Video buffer overflow, sommige beelden zullen verloren gaan. De audio-input lijkt te traag te zijn.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="341"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Waarschuwing: Audiosamples met niet-monotone tijdswaarde ontvangen.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="365"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Waarschuwing: Audio buffer overflow, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan). De video-input lijkt te traag te zijn.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="388"/>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Waarschuwing: Desynchronisatie is te groot, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="398"/>
        <source>Warning: Audio input is more than 5% too slow!</source>
        <translation>Waarschuwing: Audio-input is meer dan 5% te traag!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="402"/>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation>Waarschuwing: Audio-input is meer dan 5% te snel!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="432"/>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Waarschuwing: Gat in de audiostream ontvangen, begin een nieuw segment om de audio synchroon met de video te houden (sommige video en/of audio kan verloren gaan).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="712"/>
        <source>Synchronizer thread started.</source>
        <translation>Synchronisator thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="734"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Synchronisator thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="738"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Exceptie &apos;%1&apos; in synchronisator thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="741"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Onbekende exceptie in synchronisator thread.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="65"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Fout: Breedte of hoogte is geen even getal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="69"/>
        <source>Error: Frame rate it zero!</source>
        <translation>Fout: Beelden per seconde is nul!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="202"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="225"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Fout: Encoderen van videobeeld mislukt!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="115"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Fout: Command-line optie &apos;%1&apos; neemt geen waarde aan!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="143"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Fout: Onbekende command-line optie &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="153"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Fout: Onbekend command-line argument &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="180"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder heeft gedetecteerd dat je de propriëtaire NVIDIA-driver gebruikt met flipping ingeschakeld. Het is bekend dat dit storingen veroorzaakt tijdens de opname. Het is aangeraden om flipping uit te schakelen. Wil je dat ik dit voor je doe?

Je kan deze optie ook manueel veranderen in het NVIDIA-controlepaneel.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="185"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Ik kon flipping niet uitschakelen om een of andere reden - sorry! Probeer om het uit te schakelen in het NVIDIA-controlepaneel.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="191"/>
        <source>SSR started</source>
        <translation>SSR gestart</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="200"/>
        <source>SSR stopped</source>
        <translation>SSR gestopt</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="208"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Fout: Kan geen .ssr-map maken!</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="73"/>
        <source>Error: Flushing resampler failed! Reason: %s</source>
        <translation>Fout: Afwerken van hersampler mislukt! Reden: %s</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="90"/>
        <source>Resampling from %1 to %2.</source>
        <translation>Hersamplen van %1 naar %2.</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="96"/>
        <source>Error: Can&apos;t create resampler! Reason: %s</source>
        <translation>Fout: Kan geen hersampler maken! Reden: %s</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="100"/>
        <source>Resampling not needed.</source>
        <translation>Hersamplen niet nodig.</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="140"/>
        <source>Error: Resampling failed!</source>
        <translation>Fout: Hersamplen mislukt!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="27"/>
        <source>Warning: An underrun has occurred, some samples were too late.</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="29"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Stopping synth thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="189"/>
        <source>Synth thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="257"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="265"/>
        <source>Synth thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="269"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="272"/>
        <source>Unknown exception in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="187"/>
        <source>Video in</source>
        <translation>Video in</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="188"/>
        <source>Audio in</source>
        <translation>Audio in</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="189"/>
        <source>Video out</source>
        <translation>Video uit</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="190"/>
        <source>Audio out</source>
        <translation>Audio uit</translation>
    </message>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="49"/>
        <source>Synchronization Diagram</source>
        <translation>Synchronisatie-diagram</translation>
    </message>
</context>
</TS>
