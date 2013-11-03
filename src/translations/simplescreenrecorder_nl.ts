<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="nl_NL">
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="780"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL instellingen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="783"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Waarschuwing: OpenGL opname werkt door een library te injecteren in het programma dat wordt opgenomen. Deze library zal sommige systeemfuncties vervangen om beelden op te nemen voor ze weergegeven worden op het scherm. Als je probeert om een spel op te nemen dat probeert om hacking-pogingen te detecteren, dan is het (theoretisch) mogelijk dat het spel dit als een hack zal zien. Dit zou ervoor kunnen zorgen dat je geband wordt, dus het is een goed idee om eerst te controleren dat het programma dat je wil opnemen je niet zal bannen, *voordat* je het probeert. Je bent gewaarschuwd :).&lt;/p&gt;

&lt;p&gt;Nog een waarschuwing: OpenGL opname is experimenteel, het werkt niet altijd en het kan het programma dat je wil opnemen zelfs laten crashen. Als je vreest data te verliezen, maak dan eerst een backup!&lt;/p&gt;

&lt;p&gt;Als je Steam-spellen wil opnemen, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;lees dan eerst dit&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="796"/>
        <source>Command:</source>
        <translation>Commando:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="798"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Dit commando zal worden uitgevoerd om het programma dat opgenomen moet worden te starten.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="800"/>
        <source>Start the OpenGL application automatically</source>
        <translation>Start de OpenGL-applicatie automatisch</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="801"/>
        <source>If checked, the above command will be executed automatically (combined with some environment variables). If not checked,
you have to start the OpenGL application yourself (the full command, including the required environment variables, is shown in the log).</source>
        <translation>Indien aangevinkt zal het bovenstaande commando automatisch worden uitgevoerd (samen met een aantal omgevingsvariabelen).
Indien niet aangevinkt moet je zelf de OpenGL-applicatie starten (het volledige commando, inclusief de vereiste omgevingsvariabelen, zal worden weergegeven in de log).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="804"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Geen strikte permissies voor gedeeld geheugen (onveilig)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="805"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Indien aangevinkt zullen andere gebruikers op dezelfde machine toegang hebben tot het gedeeld geheugen dat gebruikt wordt om te communiceren met het OpenGL-programma.
Dit betekent dat andere gebruikers (theoretisch) kunnen zien wat je opneemt, de beelden aanpassen, hun eigen beelden injecteren, of simpelweg de communicatie verstoren.
Dit geldt zelfs voor gebruikers die op afstand inloggen (ssh). Je moet dit enkel inschakelen als je een programma moet opnemen dat uitgevoerd wordt als een andere gebruiker.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="809"/>
        <source>Maximum image size (megapixels):</source>
        <translation>Maximum afbeeldingsgrootte (megapixels):</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="811"/>
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
        <location filename="../GUI/PageInput.cpp" line="816"/>
        <source>If checked, the injected library will read the front buffer (the frame that&apos;s currently on the screen) rather than the back buffer
(the new frame). This may be useful for some special applications that draw directly to the screen.</source>
        <translation>Indien aangevinkt zal de geinjecteerde library de front buffer lezen (het beeld dat op dit moment op het scherm staat) in plaats van de back buffer
(het nieuwe beeld). Dit zou nuttig kunnen zijn voor sommige speciale applicaties die rechtstreeks op het scherm tekenen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="819"/>
        <source>Limit application frame rate</source>
        <translation type="unfinished">Limiteer de framerate van de applicatie</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="820"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Indien ingeschakeld zal de geinjecteerde library de applicatie vertragen zodat de frame rate niet hoger wordt dan de frame rate van de opname.
Dit verhindert dat de applicatie CPU-tijd gebruikt voor beelden die niet opgenomen zullen worden, en resulteert soms in vloeiendere video
(dit hangt af van de applicatie).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="825"/>
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
        <translation type="unfinished">Framerate:</translation>
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
        <location filename="../GUI/PageInput.cpp" line="220"/>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation type="unfinished">Het ALSA-apparaat dat gebruikt zal worden om op te nemen. Normaal hoort dit &apos;default&apos; te zijn.
Je kan dit veranderen naar iets zoals plughw:0,0 (dit betekent geluidskaard 0 input 0 met plugins ingeschakeld).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="226"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation type="unfinished">De PulseAudio-bron die gebruikt zal worden om op te nemen.
Een &apos;monitor&apos; is een bron die de audio opneemt die wordt afgespeeld door andere applicaties.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="571"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation type="unfinished">Alle schermen: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="575"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation type="unfinished">Scherm %1: %2x%3 at %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="717"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation type="unfinished">Scherm %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="749"/>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="216"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>De audio-backend die gebruikt zal worden om op te nemen.
De ALSA-backend zal ook werken op systemen die PulseAudio gebruiken, maar het is beter om de PulseAudio-backend rechtstreeks te gebruiken.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="218"/>
        <source>Device:</source>
        <translation>Apparaat:</translation>
    </message>
    <message>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <translation type="obsolete">Het ALSA-apparaat dat gebruikt zal worden om op te nemen. Normaal hoort dit &apos;default&apos; te zijn.
Je kan dit veranderen naar iets zoals plughw:0,0 (dit betekent geluidskaard 0 input 0 met plugins ingeschakeld).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="223"/>
        <source>Source:</source>
        <translation>Bron:</translation>
    </message>
    <message>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <translation type="obsolete">De PulseAudio-bron die gebruikt zal worden om op te nemen.
Een &apos;monitor&apos; is een bron die de audio opneemt die wordt afgespeeld door andere applicaties.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="228"/>
        <source>Refresh</source>
        <translation>Vernieuwen</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="229"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Vernieuwt de lijst met PulseAudio-bronnen.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="254"/>
        <source>Back</source>
        <translation>Terug</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="255"/>
        <source>Continue</source>
        <translation>Verder</translation>
    </message>
    <message>
        <source>All screens: %1x%2</source>
        <comment>this appears in the screen selection combobox</comment>
        <translation type="obsolete">Alle schermen: %1x%2</translation>
    </message>
    <message>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>this appears in the screen selection combobox</comment>
        <translation type="obsolete">Scherm %1: %2x%3 at %4,%5</translation>
    </message>
    <message>
        <source>Screen %1</source>
        <translation type="obsolete">Scherm %1</translation>
    </message>
    <message>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Press the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation type="obsolete">Je hebt geen commando ingegeven om de OpenGL-applicatie die je wil opnemen te starten.
Klik op de &apos;OpenGL instellingen&apos; knop en geef een commando in.</translation>
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
        <source>files</source>
        <comment>this appears in the file dialog, e.g. &apos;h264 files&apos;</comment>
        <translation type="obsolete">bestanden</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="58"/>
        <location filename="../GUI/PageOutput.cpp" line="61"/>
        <location filename="../GUI/PageOutput.cpp" line="64"/>
        <location filename="../GUI/PageOutput.cpp" line="67"/>
        <location filename="../GUI/PageOutput.cpp" line="103"/>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation type="unfinished">bestanden</translation>
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
        <translation type="unfinished">Voor gevorderde gebruikers. Je kan elke libav/ffmpeg-videocodec gebruiken, maar veel zijn niet nuttig of werken niet.</translation>
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
        <translation type="unfinished">Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="231"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation type="unfinished">Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="238"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation type="unfinished">CPU-gebruik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>fastest</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="245"/>
        <source>slowest</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="246"/>
        <source>The encoding speed. A higher value uses *less* CPU-time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Constant rate factor:</source>
        <translation type="obsolete">Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Deze instelling verandert de videokwaliteit. Een lagere waarde betekent een hogere kwaliteit.
Het toegestane bereik is 0-51 (0 betekent verliesvrij, de standaardwaarde is 23).</translation>
    </message>
    <message>
        <source>Preset:</source>
        <translation type="obsolete">Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="236"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>De encodeersnelheid. Een hogere snelheid gebruikt minder CPU (waardoor hogere opname-framerates mogelijk worden),
maar resulteert in grotere bestanden. De kwaliteit verandert normaal gezien niet veel.</translation>
    </message>
    <message>
        <source>CPU used:</source>
        <translation type="obsolete">CPU-gebruik:</translation>
    </message>
    <message>
        <source>The encoding speed. A higher value uses *less* CPU  (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation type="obsolete">De encodeersnelheid. Een hogere waarde gebruikt *minder* CPU-tijd. (Ik heb de naam niet gekozen, dit is de naam
die gebruikt wordt door de VP8-encoder). Hogere waarden resulteren in lagere beeldkwaliteit, tenzij je de bitrate ook verhoogt.</translation>
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
        <translation>Indien aangevinkt zal de video-encoder beelden overslaan als de input framerate lager is
dan de output framerate. Indien niet aangevinkt zullen input frames worden verdubbeld om de gaten op te vullen.
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
    <name>QObject</name>
    <message>
        <location filename="../AV/DetectCPUFeatures.cpp" line="39"/>
        <source>CPU features</source>
        <translation>CPU-eigenschappen</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="38"/>
        <source>BGRA to YUV420 converter</source>
        <translation>BGRA naar YUV420 converter</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="41"/>
        <source>X86-specific instructions are disabled.</source>
        <translation>X86-specifieke instructies zijn uitgeschakeld.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="69"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Waarschuwing: Pixelformaat wordt niet ondersteund (%1 -&gt; %2), swscale wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="73"/>
        <source>Using swscale for scaling.</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="unfinished">Gebruik swscale voor schalen.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="82"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="unfinished">Fout: Kan geen swscale context krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="113"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="unfinished">Waarschuwing: Geheugen is niet goed uitgelijnd voor SSE, de fallback converter wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="obsolete">Waarschuwing: Geheugen is niet goed uitgelijnd voor SSE, de fallback converter wordt gebruikt in de plaats. Dit is geen probleem, maar performantie zal slechter zijn.</translation>
    </message>
    <message>
        <source>Using swscale for scaling.</source>
        <comment>don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="obsolete">Gebruik swscale voor schalen.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="obsolete">Fout: Kan geen swscale context krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="89"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Fout: Kan PCM apparaat niet openen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="93"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet krijgen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="99"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Fout: Kan toegangstype niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="105"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Fout: Kan sampleformaat niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="112"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Fout: Kan samplefrequentie niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This could be a problem if the difference is large.</source>
        <translation>Waarschuwing: Samplefrequentie %1 wordt niet ondersteund, %2 wordt gebruikt in de plaats. Dit kan een probleem zijn als het verschil groot is.</translation>
    </message>
    <message>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Waarschuwing: Er was een overrun, een aantal samples gingen verloren.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Fout: Kan apparaat niet herstellen na overrun!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Fout: Kan het PCM apparaat niet starten na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Waarschuwing: Er was een overrun, een aantal samples gingen verloren.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Fout: Kan apparaat niet herstellen na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Fout: Kan het PCM apparaat niet starten na overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="55"/>
        <location filename="../AV/Input/X11Input.cpp" line="206"/>
        <source>Stopping input thread ...</source>
        <translation>Stop input thread ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="125"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Fout: Kan het aantal kanalen niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="132"/>
        <source>Error: Can&apos;t set period count!</source>
        <translation>Fout: Kan het aantal periodes niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="136"/>
        <source>Warning: Period count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Aantal periodes %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="145"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Fout: Kan periodegrootte niet instellen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="149"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Waarschuwing: Periodegrootte %1 wordt niet ondersteund, gebruik %2 in de plaats. Dit is geen probleem.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="157"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Fout: Kan PCM hardwareparameters niet toepassen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="175"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Fout: Kan het PCM apparaat niet starten!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="196"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="95"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="333"/>
        <source>Input thread started.</source>
        <translation>Input thread gestart.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="216"/>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation>Fout: Kan niet controleren of samples beschikbaar zijn!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="229"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Fout: Kan samples niet lezen!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="255"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="155"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="387"/>
        <location filename="../AV/Input/X11Input.cpp" line="423"/>
        <source>Input thread stopped.</source>
        <translation>Input thread gestopt.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="259"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="159"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="391"/>
        <location filename="../AV/Input/X11Input.cpp" line="427"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Fout: Exceptie &apos;%1&apos; in input thread.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="262"/>
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
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="102"/>
        <source>Error: Can&apos;t get main shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="107"/>
        <source>Error: Can&apos;t attach to main shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="117"/>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="122"/>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="149"/>
        <source>Full command</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="157"/>
        <source>Error: Can&apos;t run command!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
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
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="312"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="375"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="380"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="185"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="57"/>
        <source>Error: Width or height is zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="189"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="61"/>
        <source>Error: Width or height is too large, the maximum width and height is 10000.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="226"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="235"/>
        <source>Using X11 shared memory.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="238"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="243"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="254"/>
        <source>Not using X11 shared memory.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="262"/>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="317"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="373"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="390"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="45"/>
        <source>Error: Sample rate it zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="126"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="149"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="170"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="62"/>
        <source>Stopping encoder thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="82"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="87"/>
        <source>Using codec %1 (%2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="106"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="160"/>
        <source>Encoder thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="189"/>
        <source>Flushing encoder ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="196"/>
        <source>Encoder thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="200"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="203"/>
        <source>Unknown exception in encoder thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="72"/>
        <source>Stopping encoders ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="79"/>
        <source>Waiting for muxer thread to stop by itself ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <source>Error: Can&apos;t write header!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="111"/>
        <source>Finishing encoders ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="143"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="149"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="195"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Using format %1 (%2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="204"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="211"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="224"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="257"/>
        <source>Muxer thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="311"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="339"/>
        <source>Muxer thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="343"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="346"/>
        <source>Unknown exception in muxer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="119"/>
        <source>Stopping synchronizer thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="237"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="269"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="334"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="345"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="368"/>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="377"/>
        <source> Warning: Audio input is more than 5% too slow!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="381"/>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="411"/>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="697"/>
        <source>Synchronizer thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="719"/>
        <source>Synchronizer thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="723"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="726"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="65"/>
        <source>Error: Width or height is not an even number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="69"/>
        <source>Error: Frame rate it zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="202"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="230"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="212"/>
        <source>Error: Keyframe flag was not set!</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="49"/>
        <source>Sync Diagram</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="187"/>
        <source>Video in</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="188"/>
        <source>Audio in</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="189"/>
        <source>Video out</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="190"/>
        <source>Audio out</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
