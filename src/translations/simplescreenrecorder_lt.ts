<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="lt_LT">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="78"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Apie SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="87"/>
        <source>For more information:</source>
        <translation>Išsamesnei informacijai žiūrėkite:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="88"/>
        <source>The source code of this program can be found at:</source>
        <translation>Pirminį programos kodą galite rasti adresu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>This program uses:</source>
        <translation>Ši programa naudoja:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 grafinei naudotojo sąsajai</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 ar %2 (priklausomai nuo jūsų distribucijos) vaizdo/garso įrašų kodavimui</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 sistemos funkcijų gaudymui, OpenGL įrašymams</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="34"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL Nustatymai</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="37"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Įspėjimas: OpenGL įrašinėjimas veikia, įskiepyjant į įrašinėjamą programą biblioteką. Ši biblioteka nustelbs kai kurias funkcijas tam, kad galėtų užvaldyti kadrus dar prieš tai, kai jie bus rodomi ekrane. Jeigu bandote įrašinėti žaidimą, kuris kliento pusėje bando aptikti įsilaužimų bandymus, tuomet (teoriškai) gali būti, kad žaidimas tai laikys įsilaužimu. Tai netgi gali sąlygoti, kad jums bus uždrausta žaisti, taigi, *prieš* bandant įrašinėti, yra gerai įsitikinti, kad programa, kurią įrašinėsite, jusų neuždraus. Jūs buvote įspėti :).&lt;/p&gt;

&lt;p&gt;Kitas įspėjimas: OpenGL įrašinėjimas yra eksperimentinis, jis gali neveikti arba netgi priversti įrašinėjamą programą užstrigti. Jeigu bijote prarasti programos duomenis, iš pradžių, susikurkite atsarginę duomenų kopiją!&lt;/p&gt;

&lt;p&gt;Jeigu norite įrašinėti Steam žaidimus, tuomet &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;iš pradžių, skaitykite čia&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="51"/>
        <source>Choose channel</source>
        <translation>Kanalo pasirinkimas</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="53"/>
        <source>Channel name:</source>
        <translation>Kanalo pavadinimas:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="55"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Kanalo pavadinimai yra naudojami, siekiant atpažinti programas. Tai yra reikalinga tik tuo atveju, jeigu norite tuo pačiu metu įrašinėti kelias programas.
Jeigu paliksite šį lauką tuščią, bus naudojamas numatytasis kanalo pavadinimas &quot;channel-JŪSŲNAUDOTOJOVARDAS&quot;.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="57"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Susilpninti bendrosios atminties leidimus (nesaugu)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Jei pažymėta, kiti, to pačio kompiuterio naudotojai, galės prisitvirtinti prie, susisiekimui su OpenGL programa naudojamos, bendrosios atminties.
Tai reiškia, kad kiti naudotojai gali (teoriškai) matyti ką jūs įrašinėjate, keisti kadrus, įskiepyti savo pačių kadrus arba, tiesiog, sugriauti susisiekimą.
Tai netgi taikoma naudotojams, kurie yra prisijungę nuotoliniu būdu (ssh). Jūs turėtumėte tai įjungti tik tuo atveju, jeigu norite įrašinėti programą,
kuri yra vykdoma kaip kitas naudotojas.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="73"/>
        <source>Launch application</source>
        <translation>Programos paleidimas</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="75"/>
        <source>Command:</source>
        <translation>Komanda:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="77"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Ši komanda bus įvykdyta, kad paleistų, norimą įrašinėti, programą.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="79"/>
        <source>Working directory:</source>
        <translation>Darbinis katalogas:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="81"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Komanda bus įvykdyta šiame kataloge. Jeigu tai paliksite tuščią, tuomet darbinis katalogas pakeistas nebus.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="83"/>
        <source>Launch automatically</source>
        <translation>Paleisti automatiškai</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Jei pažymėta, programa bus automatiškai paleista, kai tik pereisite į įrašymo puslapį. Jei nepažymėta, tuomet turėsite paleisti programą rankiniu būdu.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="86"/>
        <source>Launch now</source>
        <translation>Paleisti dabar</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="107"/>
        <source>Stream settings</source>
        <translation>Srauto nustatymai</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="109"/>
        <source>Limit application frame rate</source>
        <translation>Riboti programos kadrų dažnį</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Jei pažymėta, įskiepyta biblioteka sulėtins programas tam, kad kadrų dažnis netaptų didesnis nei įrašinėjimo kadrų dažnis.
Tai neleidžia programai eikvoti procesoriaus laiko kadrams, kurie nebus įrašinėjami ir kaip pasekmė, kartais, yra gaunamas glotnesnis
vaizdo įrašas (tai priklauso nuo programos).
</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="119"/>
        <source>Close</source>
        <translation>Užverti</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Klaida: Skaitmeninimo dažnio keitimo santykis yra už ribų!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Klaida: Dreifo santykis yra už ribų!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Skaitmeninimo dažnio keitimo santykis yra %1 (buvo %2).</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="130"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Įspėjimas: Pikselių formatas nepalaikomas (%1 -&gt; %2), vietoj to, naudojama swscale. Tai nėra problema, tačiau našumas bus prastesnis.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="139"/>
        <location filename="../Benchmark.cpp" line="122"/>
        <location filename="../Benchmark.cpp" line="203"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Klaida: Nepavyksta gauti swscale konteksto!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="161"/>
        <location filename="../AV/FastScaler.cpp" line="186"/>
        <location filename="../AV/FastScaler.cpp" line="211"/>
        <location filename="../AV/FastScaler.cpp" line="235"/>
        <location filename="../AV/FastScaler.cpp" line="257"/>
        <location filename="../AV/FastScaler.cpp" line="280"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation>Įspėjimas: Atmintis SSE nėra deramai išlygiuota, vietoj to, naudojamas fallback keitiklis. Tai nėra problema, tačiau našumas bus prastesnis.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Įspėjimas: Įvyko overrun, kai kurie mėginiai buvo prarasti.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Klaida: Nepavyko atkurti įrenginio po overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Klaida: Nepavyko pradėti PCM įrenginio po overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="63"/>
        <location filename="../AV/Input/JACKInput.cpp" line="56"/>
        <location filename="../AV/Input/X11Input.cpp" line="207"/>
        <source>Stopping input thread ...</source>
        <translation>Sustabdoma įvesties gija ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="96"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="232"/>
        <source>Generating source list ...</source>
        <translation>Kuriamas šaltinio sąrašas ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="115"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Klaida: Nepavyko atnaujinti ALSA konfigūracijos!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="162"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Rastas papildinys: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="175"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Įspėjimas: Nepavyko atverti garso plokštės %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Įspėjimas: Nepavyko gauti %1 garso plokštės informacijos.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="185"/>
        <source>Found card: [%1] %2</source>
        <translation>Rasta plokštė: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="210"/>
        <source>Found device: [%1] %2</source>
        <translation>Rastas įrenginys: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="259"/>
        <location filename="../AV/SimpleSynth.cpp" line="123"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Klaida: Nepavyksta atverti PCM įrenginio!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="263"/>
        <location filename="../AV/SimpleSynth.cpp" line="127"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Klaida: Nepavyksta gauti PCM aparatinės įrangos parametrų!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="269"/>
        <location filename="../AV/SimpleSynth.cpp" line="133"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Klaida: Nepavyksta nustatyti prieigos tipo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="139"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Klaida: Nepavyksta nustatyti mėginio formato!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="282"/>
        <location filename="../AV/SimpleSynth.cpp" line="146"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Klaida: Nepavyksta nustatyti skaitmeninimo dažnio!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="286"/>
        <location filename="../AV/SimpleSynth.cpp" line="150"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Įspėjimas: Skaitmeninimo dažnis %1 yra nepalaikomas, vietoj to, naudojamas %2. Tai nėra problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="295"/>
        <location filename="../AV/SimpleSynth.cpp" line="158"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Klaida: Nepavyksta nustatyti kanalų skaičiaus!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="299"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Įspėjimas: Kanalų skaičius %1 yra nepalaikomas, vietoj to, naudojama %2. Tai nėra problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="308"/>
        <location filename="../AV/SimpleSynth.cpp" line="165"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Klaida: Nepavyksta nustatyti periodo dydį!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="312"/>
        <location filename="../AV/SimpleSynth.cpp" line="169"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Įspėjimas: Periodo dydis %1 nėra palaikomas, vietoj to, naudojamas %2. Tai nėra problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="321"/>
        <location filename="../AV/SimpleSynth.cpp" line="178"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Klaida: Nepavyksta nustatyti buferio dydžio!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/SimpleSynth.cpp" line="182"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Įspėjimas: Buferio dydis %1 yra nepalaikomas, vietoj to, naudojamas %2. Tai nėra problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="333"/>
        <location filename="../AV/SimpleSynth.cpp" line="190"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Klaida: Nepavyksta pritaikyti PCM aparatinės įrangos parametrų!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="351"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Klaida: Nepavyksta paleisti PCM įrenginio!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="372"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="180"/>
        <location filename="../AV/Input/JACKInput.cpp" line="238"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="299"/>
        <location filename="../AV/Input/X11Input.cpp" line="345"/>
        <source>Input thread started.</source>
        <translation>Įvesties gija pradėta.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="387"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Klaida: Nepavyksta skaityti mėginius!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="413"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="248"/>
        <location filename="../AV/Input/JACKInput.cpp" line="289"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="388"/>
        <location filename="../AV/Input/X11Input.cpp" line="444"/>
        <source>Input thread stopped.</source>
        <translation>Įvesties gija sustabdyta.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="417"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="252"/>
        <location filename="../AV/Input/JACKInput.cpp" line="293"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="392"/>
        <location filename="../AV/Input/X11Input.cpp" line="448"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Išimtis &apos;%1&apos; įvesties gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="420"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="255"/>
        <location filename="../AV/Input/JACKInput.cpp" line="296"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="395"/>
        <location filename="../AV/Input/X11Input.cpp" line="451"/>
        <source>Unknown exception in input thread.</source>
        <translation>Nežinoma išimtis įvesties gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="149"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Klaida: Nepavyko skaityti srauto. tai, dažniausiai, reiškia, kad srautas jau buvo dingęs.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="72"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Klaida: Nepavyko prisijungti prie JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="81"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Klaida: Nepavyko sukurti JACK prievado!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="87"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Klaida: Nepavyko nustatyti JACK proceso atgalinio skambinimo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="91"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Klaida: Nepavyko nustatyti JACK skaitmeninimo dažnio atgalinio skambinimo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="95"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Klaida: Nepavyko nustatyti JACK xrun atgalinio skambinimo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="99"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Klaida: Nepavyko nustatyti JACK prievado prijungimo atgalinio skambinimo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Klaida: Nepavyko aktyvuoti JACK kliento!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <location filename="../AV/Input/JACKInput.cpp" line="123"/>
        <location filename="../AV/Input/JACKInput.cpp" line="252"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Jungiamas prievadas %1 prie %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="256"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>Atjungiamas prievadas %1 nuo %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Klaida: pa_mainloop_prepare nepavyko!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Klaida: pa_mainloop_poll nepavyko!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Klaida: pa_mainloop_dispatch nepavyko!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation>Klaida: Nepavyko sukurti pagrindinio ciklo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
        <source>Error: Could not create context!</source>
        <translation>Klaida: Nepavyko sukurti konteksto!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Klaida: Nepavyko prisijungti! Priežastis: %1
Gali būti, kad jūsų sistema nenaudoja PulseAudio. Vietoj to, pabandykite ALSA vidinę pusę.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Klaida: Prisijungimo bandymas nepavyko! Priežastis: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Klaida: Nepavyko sukurti srauto! Priežastis: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Klaida: Nepavyko prijungti srauto! Priežastis: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Klaida: Srauto prisijungimo bandymas nepavyko! Priežastis: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="223"/>
        <source>Found source: [%1] %2</source>
        <translation>Rastas šaltinis: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Klaida: Nepavyko gauti šaltinių pavadinimų! Priežastis: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="313"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Klaida: pa_stream_peek nepavyko!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="377"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Įspėjimas: Garso šaltinis buvo pristabdytas. Esamas segmentas bus sustabdytas, kol šaltinis nebus pratęstas.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="382"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Įspėjimas: Srautas buvo perkeltas į kitą šaltinį.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation>Sukurtas vaizdo srauto skaitlys.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Klaida: Nepavyksta atverti vaizdo srauto failo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation>Klaida: Nepavyksta pakeisti vaizdo srauto failo dydį!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Klaida: Nepavyksta paskirstyti atminties vaizdo srauto failui!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Klaida: Nepavyksta atverti vaizdo kadro failą!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation>Sunaikintas vaizdo srauto skaitlys.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Klaida: Neteisingas vaizdo kadro failo dydis!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Klaida: Nepavyksta paskirstyti atminties vaizdo kadro failui!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="88"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation>Klaida: Nepavyksta sukurti kanalo katalogo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="95"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation>Klaida: Nepavyksta padaryti sisteminę iškvietą kanalo katalogui!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="99"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Klaida: Kanalo katalogas nėra normalus katalogas!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="104"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation>Klaida: Nepavyksta nustatyti kanalo katalogo veiksenos!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="109"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Klaida: Kanalo katalogo savininkas yra kitas naudotojas! Pasirinkite kitą kanalo pavadinimą arba, norėdami vis tiek jį naudoti, įjunkite susilpnintus failų leidimus.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="121"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Klaida: Nepavyksta inicijuoti inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="127"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation>Klaida: Nepavyksta stebėti kanalo katalogo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="139"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation>Klaida: Nepavyksta atverti kanalo katalogo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="157"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Pridėtas prieš tai buvęs srautas %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="192"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Klaida: Nepavyksta gauti skaitymo ilgio iš inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="200"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Klaida: Nepavyksta skaityti iš inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="210"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Klaida: Gautas dalinis įvykis iš inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="222"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Klaida: Gautas dalinis pavadinimas iš inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="236"/>
        <source>Added stream %1.</source>
        <translation>Pridėtas srautas %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="244"/>
        <source>Removed stream %1.</source>
        <translation>Pašalintas srautas %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="270"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Ištrintas pamestas srautas %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Klaida: Nepalaikomas X11 paveikslo pikselių formatas!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="186"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="113"/>
        <source>Error: Width or height is zero!</source>
        <translation>Klaida: Plotis ar aukštis lygus nuliui!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="190"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="117"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Klaida: Plotis ar aukštis yra per dideli, didžiausias plotis ir aukštis yra %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="236"/>
        <location filename="../GUI/HotkeyListener.cpp" line="118"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Klaida: Nepavyksta atverti X display!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="245"/>
        <source>Using X11 shared memory.</source>
        <translation>Naudojama X11 bendroji atmintis.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Klaida: Nepavyksta sukurti bendrojo paveikslo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="253"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Klaida: Nepavyksta gauti bendrosios atminties!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Klaida: Nepavyksta prisitvirtinti prie bendrosios atminties!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="264"/>
        <source>Not using X11 shared memory.</source>
        <translation>Nenaudojama X11 bendrosios atminties.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="271"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Įspėjimas: X serveris nepalaiko XFixes, žymeklis yra paslėptas.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="329"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Klaida: Neteisingas ekraną ribojantis langas!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="393"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Klaida: Nepavyksta pritvirtinti serverio prie bendrosios atminties!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="399"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Klaida: Nepavyksta gauti paveikslo (naudojant bendrąją atmintį)!
    Dažniausiai, tai reiškia, kad įrašinėjimo sritis nėra pilnai ekrano vidinėse ribose. Arba gal jūs keitėte ekrano raišką?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="410"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Klaida: Nepavyksta gauti paveikslo (nenaudojant bendrąją atmintį)!
    Dažniausiai, tai reiškia, kad įrašinėjimo sritis nėra pilnai ekrano vidinėse ribose. Arba gal jūs keitėte ekrano raišką?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="99"/>
        <source>Error: Channel count is zero.</source>
        <translation>Klaida: Kanalų skaičius lygus nuliui.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="103"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Klaida: Skaitmeninimo dažnis lygus nuliui.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="140"/>
        <source>Using sample format %1.</source>
        <translation>Naudojamas %1 mėginių formatas.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="145"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Klaida: Koduotuvas reikalauja nepalaikomo mėginių formato!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Klaida: Garso kadro kodavimas nepavyko!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="31"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="40"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Klaida: Parinktis &quot;%1&quot; negali būti išanalizuota!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation>Sustabdoma koduotuvo gija ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="155"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Klaida: Nepavyksta atverti kodeko!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="163"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation>Įspėjimas: Kodeko parinktis &quot;%1&quot; buvo neatpažinta!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="179"/>
        <source>Encoder thread started.</source>
        <translation>Koduotuvo gija pradėta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="211"/>
        <source>Flushing encoder ...</source>
        <translation>Išvalomas koduotuvas ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="225"/>
        <source>Encoder thread stopped.</source>
        <translation>Koduotuvo gija sustabdyta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="229"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Išimtis &apos;%1&apos; koduotuvo gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Nežinoma išimtis koduotuvo gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="71"/>
        <source>Stopping encoders ...</source>
        <translation>Stabdomi koduotuvai ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="78"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Laukiama, kol bus sustabdyta tankintuvo gija ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="133"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Klaida: Nepavyksta įrašyti header!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="144"/>
        <source>Finishing encoders ...</source>
        <translation>Užbaigiami koduotuvai ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="186"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Klaida: Nepavyksta rasti pasirinkto išvesties formato!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="190"/>
        <source>Using format %1 (%2).</source>
        <translation>Naudojamas formatas %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="196"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Klaida: Nepavyksta paskirstyti formato konteksto!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Klaida: Nepavyksta atverti išvesties failo!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Klaida: Nepavyksta įrašyti trailer, vis tiek tęsiama.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="254"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Klaida: Nepavyksta rasti kodeko!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="264"/>
        <source>Using codec %1 (%2).</source>
        <translation>Naudojamas kodekas %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="273"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Klaida: Nepavyksta sukurti naujo srauto!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="283"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Klaida: Nepavyksta gauti kodeko konteksto numatytųjų reikšmių!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="296"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Įspėjimas: libav/ffmpeg šį kodeką laiko eksperimentiniu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="312"/>
        <source>Muxer thread started.</source>
        <translation>Tankintuvo gija pradėta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="371"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Klaida: Nepavyksta įrašyti kadro į tankintuvą!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="399"/>
        <source>Muxer thread stopped.</source>
        <translation>Tankintuvo gija sustabdyta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="403"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Išimtis &apos;%1&apos; tankintuvo gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="406"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Nežinoma išimtis tankintuvo gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="218"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Stabdoma sinchronizatoriaus gija ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="335"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Įspėjimas: Gautas vaizdo kadras su nemonotonine laiko žyma.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="361"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Įspėjimas: Vaizdo buferio perpildymas, kai kurie kadrai bus prarasti. Garso įvestis atrodo pernelyg lėta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="418"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Įspėjimas: Gauti garso mėginiai su nemonotonine laiko žyma.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="443"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Įspėjimas: Pernelyg daug garso mėginių, šalinami mėginiai, kad būtų išlaikytas garso ir vaizdo suderinimas.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="449"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Įspėjimas: Nepakanka garso mėginių, įterpiama tyla, kad būtų išlaikytas garso ir vaizdo suderinimas.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="515"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Įspėjimas: Garso įvestis yra daugiau nei 2% per lėta!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="519"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Įspėjimas: Garso įvestis yra daugiau nei 2% per greita!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="554"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Įspėjimas: Garso buferio perpildymas, pradedamas naujas segmentas, kad būtų išlaikytas garso ir vaizdo suderinimas (kai kurie vaizdai ir/ar garsai gali būti prarasti). Atrodo, kad vaizdo įvestis yra pernelyg lėta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="590"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Įspėjimas: Garso sraute yra gautas tarpas, įterpiama tyla, kad būtų išlaikytas garso ir vaizdo suderinimas.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="890"/>
        <source>Synchronizer thread started.</source>
        <translation>Sinchronizatoriaus gija pradėta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="912"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Sinchronizatoriaus gija sustabdyta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="916"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Išimtis &quot;%1&quot; sinchronizatoriaus gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="919"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Nežinoma išimtis sinchronizatoriaus gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="121"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Klaida: Plotis ar aukštis nėra lyginis skaičius!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="125"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Klaida: Kadrų dažnis lygus nuliui!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="182"/>
        <source>Using pixel format %1.</source>
        <translation>Naudojamas %1 pikselių formatas.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="196"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Klaida: Kodekas nepalaiko pikselių formato!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="226"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="246"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Klaida: Vaizdo kadro kodavimas nepavyko!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="40"/>
        <source>Using real-time priority.</source>
        <translation>Naudojama tikralaikė pirmenybė.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="50"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation>Naudojama nice pirmenybė.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="55"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation>Įspėjimas: Nepavyksta padidinti gijos pirmenybės.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="63"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Klaida: Nepavyksta atkurti įrenginio po underrun!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="90"/>
        <source>Stopping synth thread ...</source>
        <translation>Stabdoma sintezatoriaus gija ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="223"/>
        <source>Synth thread started.</source>
        <translation>Sintezatoriaus gija pradėta.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="276"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Klaida: Nepavyksta įrašyti mėginių!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="284"/>
        <source>Synth thread stopped.</source>
        <translation>Sintezatoriaus gija sustabdyta.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="288"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Išimtis &apos;%1&apos; sintezatoriaus gijoje.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="291"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Nežinoma išimtis sintezatoriaus gijoje.</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="163"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation>BGRA %1 iki BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="241"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation>%1 %2 iki %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="251"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Pradedamas perskaičiavimo įrenginio našumo testas ...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="258"/>
        <source>Starting converter benchmark ...</source>
        <translation>Pradedamas keitiklio našumo testas ...</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="46"/>
        <source>CPU features</source>
        <translation>Procesoriaus ypatybės</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="159"/>
        <source>The application could not be launched.</source>
        <translation>Nepavyko paleisti programos.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="164"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation>Įspėjimas: X serveris nepalaiko XInput2, kai kuriose programose gali neveikti spartieji klavišai.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="119"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Klaida: Komandų eilutės parinktis &quot;%1&quot; nepriima reikšmės!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="150"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Klaida: Nežinoma komandų eilutės parinktis &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="160"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Klaida: Nežinomas komandų eilutės argumentas &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="200"/>
        <source>SSR started</source>
        <translation>SSR paleista</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="228"/>
        <source>SSR stopped</source>
        <translation>SSR sustabdyta</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="245"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Klaida: Nepavyksta sukurti ssr katalogo!</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder aptiko, kad jūs naudojate nuosavybinę NVIDIA tvarkyklę su įjungtu &quot;flipping&quot;. Yra žinoma, kad tai, įrašymo metu, sukelia triktis. Rekomenduojama išjungti &quot;flipping&quot;. Ar norite, kad tai padaryčiau vietoj jūsų?

Jūs taip pat galite rankiniu būdu keisti šią parinktį NVIDIA valdymo skydelyje.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="90"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Atsiprašau, bet dėl kažkokios priežasties man nepavyko išjungti &quot;flipping&quot;! Pabandykite išjungti šią parinktį NVIDIA valdymo skydelyje.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Įrašas yra išsaugotas. Dabar, kad padarytumėte failą mažesniu, galite redaguoti arba perkoduoti vaizdo įrašą, naudodami geresnius nustatymus, (numatytieji nustatymai yra optimizuoti kokybei ir greičiui, o ne failo dydžiui).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>Atgal į pradžios puslapį</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="113"/>
        <source>Video input</source>
        <translation>Vaizdo įvestis</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="116"/>
        <source>Record the entire screen</source>
        <translation>Įrašinėti visą ekraną</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="117"/>
        <source>Record a fixed rectangle</source>
        <translation>Įrašinėti fiksuotą stačiakampį</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="118"/>
        <source>Follow the cursor</source>
        <translation>Sekti paskui žymeklį</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="119"/>
        <source>Record OpenGL (experimental)</source>
        <translation>Įrašinėti OpenGL (eksperimentinis)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="125"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Pasirinkite kuris ekranas turėtų būti įrašinėjamas kelių ekranų konfigūracijoje.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="126"/>
        <source>Select rectangle...</source>
        <translation>Pasirinkti stačiakampį...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Naudokite pelę, kad pasirinktumėte norimą įrašinėti stačiakampį.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="128"/>
        <source>Select window...</source>
        <translation>Pasirinkti langą...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="129"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Naudokite pelę, kad pasirinktumėte norimą įrašinėti langą.
Patarimas: Jei spustelėsite ant lango krašto, bus įrašinėjamas visas langas (kartu su kraštais). Kitu atveju,
bus įrašinėjama tik lango kliento sritis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="132"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL nustatymai...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Keisti OpenGL įrašymo nustatymus.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="134"/>
        <source>Left:</source>
        <translation>Kairė:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="138"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Įrašinėjamo stačiakampio viršutinio kairiojo kampo x koordinatė.
Patarimas: Šią reikšmę taip pat galite keisti pelės ratuko arba aukštyn/žemyn rodyklių pagalba.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="140"/>
        <source>Top:</source>
        <translation>Viršus:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="144"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Įrašinėjamo stačiakampio viršutinio kairiojo kampo y koordinatė.
Patarimas: Šią reikšmę taip pat galite keisti pelės ratuko arba aukštyn/žemyn rodyklių pagalba.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="146"/>
        <source>Width:</source>
        <translation>Plotis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="150"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Įrašinėjamo stačiakampio plotis.
Patarimas: Šią reikšmę taip pat galite keisti pelės ratuko arba aukštyn/žemyn rodyklių pagalba.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="152"/>
        <source>Height:</source>
        <translation>Aukštis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="156"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Įrašinėjamo stačiakampio aukštis.
Patarimas: Šią reikšmę taip pat galite keisti pelės ratuko arba aukštyn/žemyn rodyklių pagalba.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="158"/>
        <source>Frame rate:</source>
        <translation>Kadrų dažnis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="162"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Galutinio vaizdo įrašo kadrų dažnis per sekundę. Didesni kadrų dažniai naudoja daugiau procesoriaus laiko.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="163"/>
        <source>Scale video</source>
        <translation>Keisti vaizdo įrašo mastelį</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="164"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Įjungti ar išjungti mastelio keitimą. Mastelio keitimas naudoja daugiau procesoriaus laiko, tačiau, jeigu pakeistas mastelis yra mažesnis, 
tuomet jis gali pagreitinti kodavimą.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="165"/>
        <source>Scaled width:</source>
        <translation>Mastelio plotis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="169"/>
        <source>Scaled height:</source>
        <translation>Mastelio aukštis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="173"/>
        <source>Record cursor</source>
        <translation>Įrašinėti žymeklį</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Audio input</source>
        <translation>Garso įvestis</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="245"/>
        <source>Record audio</source>
        <translation>Įrašinėti garsą</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>Backend:</source>
        <translation>Vidinė pusė:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="255"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Įrašymui naudojama garso vidinė pusė.
ALSA vidinė pusė veiks sistemose, kurios naudoja PulseAudio, tačiau geriau naudoti PulseAudio vidinę pusę tiesiogiai.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="257"/>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>Source:</source>
        <translation>Šaltinis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Įrašinėjimui naudojamas ALSA šaltinis.
Įprastai, tinka numatytasis šaltinis. &quot;Bendrinami&quot; šaltiniai leidžia tuo pačiu metu įrašinėti kelioms programoms, tačiau jie gali būti ne tokie patikimi.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Refresh</source>
        <translation>Įkelti iš naujo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="263"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Iš naujo įkelia ALSA šaltinių sąrašą.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="268"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>PulseAudio šaltinis, kuris bus naudojamas įrašinėjimui.
&quot;Monitor&quot; yra šaltinis, kuris įrašinėja kitų programų grojamus garsus.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Iš naujo įkelia PulseAudio šaltinių sąrašą.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="274"/>
        <source>Record system microphone</source>
        <translation>Įrašinėti sistemos mikrofoną</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="275"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Jei pažymėta,prievadai bus automatiškai prijungti prie sistemos užvaldymo prievadų.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record system speakers</source>
        <translation>Įrašinėti sistemos garsiakalbius</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Jei pažymėta, prievadai bus automatiškai prijungti prie bet ko, kas jungiasi prie sistemos atkūrimo prievadų.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Back</source>
        <translation>Atgal</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="313"/>
        <source>Continue</source>
        <translation>Tęsti</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="680"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Visi ekranai: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="684"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Ekranas %1: %2x%3 ties %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="854"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Ekranas %1</translation>
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
        <translation>%1 failai</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>Kita...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>Nesuglaudintas</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="161"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Klaida:  Libavformat bibliotekoje nepavyko rasti jokio tinkamo konteinerio!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="165"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Klaida: Libavcodec bibliotekoje nepavyko rasti jokio tinkamo vaizdo kodeko!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="169"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Klaida: Libavcodec bibliotekoje nepavyko rasti jokio tinkamo garso kodeko!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="175"/>
        <source>File</source>
        <translation>Failas</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Save as:</source>
        <translation>Išsaugoti kaip:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="179"/>
        <source>The recording will be saved to this location.</source>
        <translation>Įrašas bus išsaugotas į šią vietą.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="180"/>
        <source>Browse...</source>
        <translation>Naršyti...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Separate file per segment</source>
        <translation>Atskirti failus segmentais</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Jei pažymėta, kas kartą jums pristabdžius ir pratęsus įrašinėjimą, bus sukuriamas atskiras vaizdo failas.
Jei pradinio failo pavadinimas yra &quot;testas.mkv&quot;, tai segmentai bus išsaugomi kaip &quot;testas-MMMM-mm-dd_VV.MM.SS.mkv&quot;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="184"/>
        <source>Container:</source>
        <translation>Konteineris:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>(not installed)</source>
        <translation type="unfinished"></translation>
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
        <translation>Konteineris (failo formatas), kuris bus naudojamas įrašo išsaugojimui.
Turėkite omenyje, kad ne visi konteineriai palaiko visus kodekus ir, kad ne visi medijos grotuvai gali skaityti visus failų formatus.
- Matroska (MKV) palaiko visus kodekus, tačiau nėra plačiai žinomas.
- MP4 yra labiausiai žinomas formatas ir, greičiausiai, galės būti grojamas beveik bet kuriame šiuolaikiniame medijos grotuve, tačiau palaiko tik H.264 vaizdą
   (ir daugelis medijos grotuvų palaiko tik AAC garsą).
- WebM yra skirtas vaizdo įtaisymui į internetines svetaines (su HTML5 &lt;video&gt; žyme). Formatą sukūrė Google.
   WebM formatą pagal numatymą palaiko Firefox, Chrome ir Opera, o naršyklėms Internet Explorer ir Safari yra prieinamas papildinys.
   Šis formatas palaiko tik VP8 ir Vorbis.
- OGG palaiko tik Theora ir Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>Container name:</source>
        <translation>Konteinerio pavadinimas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="207"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Pažengusiems naudotojams. Galite naudoti bet kurį libav/ffmpeg formatą, tačiau daugelis iš jų nėra naudingi arba gali neveikti.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="223"/>
        <source>Video</source>
        <translation>Vaizdo įrašas</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <location filename="../GUI/PageOutput.cpp" line="305"/>
        <source>Codec:</source>
        <translation>Kodekas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="230"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Kodekas, kuris bus naudojamas vaizdo srauto glaudinimui.
- H.264 (libx264) yra geriausias kodekas - aukštos kokybės ir labai greitas.
- VP8 (libvpx) yra ganėtinai geras, tačiau ir ganėtinai lėtas.
- Theora (libtheora) nėra rekomenduojamas, kadangi jo kokybė nėra pati geriausia.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="234"/>
        <location filename="../GUI/PageOutput.cpp" line="318"/>
        <source>Codec name:</source>
        <translation>Kodeko pavadinimas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Pažengusiems naudotojams. Galite naudoti bet kurį libav/ffmpeg vaizdo kodeką, tačiau daugelis iš jų nėra naudingi arba gali neveikti.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="241"/>
        <location filename="../GUI/PageOutput.cpp" line="325"/>
        <source>Bit rate (in kbps):</source>
        <translation>Pralaidumas (kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="243"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Vaizdo pralaidumas (kilobitais per sekundę). Didesnė reikšmė reiškia geresnę kokybę.
Jeigu nežinote kur pradėti, pabandykite 5000 ir, jei reikia, keiskite.</translation>
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
        <translation>Šis nustatymas keičia vaizdo kokybę. Mažesnė reikšmė reiškia aukštesnę kokybę.
Leidžiamas rėžis yra 0-51 (0 reiškia nenuostolingąją kokybę, numatytoji reikšmė yra 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="256"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Išankstinė parinktis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Kodavimo greitis. Didesnis greitis naudoja daugiau procesoriaus išteklių (taip padarydamas įmanomą didesnio kadrų skaičiaus įrašymą),
tačiau kaip pasekmė, gaunami didesni failai. Kokybė neturėtų būti labai stipriai paveikta.</translation>
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
        <translation>greičiausiai</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>slowest</source>
        <translation>lėčiausiai</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="271"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Kodavimo greitis. Didesnė reikšmė naudoja *mažiau* procesoriaus laiko. (Ne aš parinkau pavadinimą, tai
pavadinimas, kurį naudoja VP8 koduotuvas). Didesnės reikšmės sąlygos žemesnės kokybės vaizdo įrašą,
nebent padidinsite taip pat ir pralaidumą.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="273"/>
        <location filename="../GUI/PageOutput.cpp" line="328"/>
        <source>Custom options:</source>
        <translation>Tinkintos parinktys:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="275"/>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Tinkintos kodeko parinktys, atskirtos kableliais (pvz.: parinktis1=reikšmė1, parinktis2=reikšmė2, parinktis3=reikšmė3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="276"/>
        <source>Allow frame skipping</source>
        <translation>Leisti kadrų praleidimą</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Jei pažymėta, vaizdo koduotuvui bus leidžiama praleisti kadrus tuo atveju, jei įvesties kadrų dažnis
bus žemesnis nei išvesties kadrų dažnis. Jei nepažymėta, tuomet įvesties kadrai bus dubliuojami,
kad būtų užpildyti tarpai. Tai padidina failo dydį ir procesoriaus naudojimą, tačiau kai kuriais atvejais
sumažina tiesioginių srautų delsą. Tai neturėtų paveikti vaizdo išvaizdos.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Audio</source>
        <translation>Garso įrašas</translation>
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
        <translation>Kodekas, kuris bus naudojamas garso srauto glaudinimui. Jūs neturėtumėte tuo pernelyg rūpintis,
kadangi garso duomenų dydis, palyginus su vaizdo duomenų dydžiu, dažniausiai, yra nedidelis.
Ir jeigu įrašinėjate tik savo balsą (t.y. jokios muzikos), tuomet kokybė vis tiek neturės didelės reikšmės.
- Vorbis (libvorbis) yra puikus, tai yra rekomenduojamas kodekas.
- MP3 (libmp3lame) yra ganėtinai geras.
- AAC yra geras kodekas, tačiau čia naudojami įgyvendinimai (libvo_aacenc ar eksperimentinis ffmpeg aac koduotuvas)
   yra gan blogi. Jį naudokite tik tuomet, jei neturite kito pasirinkimo.
- Nesuglaudintas, tiesiog talpins garso duomenis, jų neglaudindamas. Failas bus gan didelis, tačiau tai yra labai greita.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="324"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Pažengusiems naudotojams. Galite naudoti bet kurį libav/ffmpeg garso kodeką, tačiau daugelis iš jų nėra naudingi arba gali neveikti.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="327"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Garso pralaidumas (kilobitais per sekundę). Didesnė reikšmė reiškia geresnę kokybę. Numatyta reikšmė yra 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="344"/>
        <source>Back</source>
        <translation>Atgal</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Continue</source>
        <translation>Tęsti</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="474"/>
        <source>You did not select an output file!</source>
        <translation>Jūs nepasirinkote išvesties failo!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="479"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>Failas &apos;%1&apos; jau yra. Ar tikrai norite jį perrašyti?</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="580"/>
        <location filename="../GUI/PageOutput.cpp" line="588"/>
        <source>not installed</source>
        <translation>neįdiegta</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="582"/>
        <location filename="../GUI/PageOutput.cpp" line="590"/>
        <source>not supported by container</source>
        <translation>nepalaikoma konteinerio</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="633"/>
        <source>Save recording as</source>
        <translation>Išsaugoti įrašą kaip</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="146"/>
        <source>Recording</source>
        <translation>Įrašymas</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="150"/>
        <source>Enable recording hotkey</source>
        <translation>Įjungti įrašymo spartųjį klavišą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Enable sound notifications</source>
        <translation>Įjungti garso pranešimus</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Hotkey:</source>
        <translation>Spartusis klavišas:</translation>
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
        <translation>Klavišas, kuri turite nuspausti (kartu su nurodytais modifikatoriais), kad pradėtumėte ar pristabdytumėte įrašinėjimą.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="198"/>
        <source>Information</source>
        <translation>Informacija</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="200"/>
        <source>Total time:</source>
        <translation>Bendras laikas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="202"/>
        <source>FPS in:</source>
        <translation>Kadr./s įeina:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="204"/>
        <source>FPS out:</source>
        <translation>Kadr./s išeina:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="206"/>
        <source>Size in:</source>
        <translation>Dydis įeina:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="208"/>
        <source>Size out:</source>
        <translation>Dydis išeina:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="210"/>
        <source>File name:</source>
        <translation>Failo pavadinimas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="213"/>
        <source>File size:</source>
        <translation>Failo dydis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="215"/>
        <source>Bit rate:</source>
        <translation>Pralaidumas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Preview</source>
        <translation>Peržiūra</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>Preview frame rate:</source>
        <translation>Peržiūros kadrų dažnis:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Pastaba: Peržiūra reikalauja papildomo procesoriaus laiko (ypač esant dideliems kadrų dažniams).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="295"/>
        <source>Log</source>
        <translation>Žurnalas</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="310"/>
        <location filename="../GUI/PageRecord.cpp" line="318"/>
        <source>Cancel recording</source>
        <translation>Atsisakyti įrašo</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="311"/>
        <location filename="../GUI/PageRecord.cpp" line="320"/>
        <source>Save recording</source>
        <translation>Išsaugoti įrašą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="325"/>
        <source>Quit</source>
        <translation>Baigti</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="368"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Jūs dar nesate išsaugoję esamo įrašo, jeigu baigsite dabar, jis bus prarastas.
Ar tikrai norite baigti programos darbą?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="380"/>
        <source>Hide window</source>
        <translation>Slėpti langą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="382"/>
        <source>Show window</source>
        <translation>Rodyti langą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="545"/>
        <source>Starting page ...</source>
        <translation>Pradedamas puslapis ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="566"/>
        <location filename="../GUI/PageRecord.cpp" line="707"/>
        <location filename="../GUI/PageRecord.cpp" line="792"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Klaida: Kažkas įvyko inicijavimo metu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="573"/>
        <source>Started page.</source>
        <translation>Pradėtas puslapis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="597"/>
        <source>Stopping page ...</source>
        <translation>Stabdomas puslapis ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="622"/>
        <source>Stopped page.</source>
        <translation>Sustabdytas puslapis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="646"/>
        <source>Starting output ...</source>
        <translation>Pradedama išvestis ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="657"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Klaida: Nepavyko gauti OpenGL programos dydžio, nes GLInject įvestis nebuvo sukurta.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="662"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Klaida: Nepavyko gauti OpenGL programos dydžio. Arba programa nebuvo paleista teisingai, arba programa dar nesukūrė OpenGL lango. Jeigu jūs norite pradėti įrašinėti programą prieš ją paleidžiant, tuomet turite įjungti mastelio keitimą ir rankiniu būdu įvesti vaizdo dydį.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="698"/>
        <source>Started output.</source>
        <translation>Pradėta išvestis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="718"/>
        <source>Stopping output ...</source>
        <translation>Stabdoma išvestis ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="736"/>
        <source>Stopped output.</source>
        <translation>Sustabdyta išvestis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="763"/>
        <source>Starting input ...</source>
        <translation>Pradedama įvestis ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="768"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Klaida: Nepavyko pradėti GLInject įvesties, nes ji nebuvo sukurta.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="787"/>
        <source>Started input.</source>
        <translation>Pradėta įvestis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="812"/>
        <source>Stopping input ...</source>
        <translation>Stabdoma įvestis ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="823"/>
        <source>Stopped input.</source>
        <translation>Sustabdyta įvestis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="839"/>
        <source>Encoding remaining data ...</source>
        <translation>Koduojami likę duomenys...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="920"/>
        <location filename="../GUI/PageRecord.cpp" line="930"/>
        <source>Pause recording</source>
        <translation>Pristabdyti įrašymą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="923"/>
        <location filename="../GUI/PageRecord.cpp" line="933"/>
        <source>Start recording</source>
        <translation>Pradėti įrašymą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="941"/>
        <source>Stop preview</source>
        <translation>Stabdyti peržiūrą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="944"/>
        <source>Start preview</source>
        <translation>Pradėti peržiūrą</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="973"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Klaida: Kuriant sintezatorių, kažkas įvyko.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1015"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Ar tikrai norite atsisakyti šio įrašo?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1030"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>Jūs dar neįrašėte jokio vaizdo įrašo, taigi, nėra ko išsaugoti.

Įrašo pradžios mygtukas yra viršuje ;).</translation>
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
        <translation>&lt;p&gt;Sveiki atvykę į SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Nepaisant pavadinimo, šioje programoje yra daug parinkčių. Bet nesirūpinkite, yra tik keli dalykai, kuriuos turite žinoti. Pirmas, numatytieji nustatymai, dažniausiai, yra tinkami. Jeigu jūs nežinote ką kas nors daro, tiesiog naudokite numatytąją reikšmę. Antras, beveik visi nustatymai turi paaiškinimus. Tiesiog, užveskite ant ko nors pelę, kad sužinotumėte ką tai daro.&lt;/p&gt;

&lt;p&gt;Išsamesnei informacijai, žiūrėkite:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="44"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Apie SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="45"/>
        <source>Continue</source>
        <translation>Tęsti</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="28"/>
        <source>Profile</source>
        <translation>Profilis</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Išsaugoti</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Išsaugoti esamus nustatymus į šį profilį.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Naujas</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Sukurti naują profilį su esamais nustatymais.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Ištrinti</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Ištrinti šį profilį.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(nėra)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Klaida: Nepavyksta įkelti profilio!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Ar tikrai norite perrašyti šį profilį?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Įveskite naujo profilio pavadinimą:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Profilis tokiu pačiu pavadinimu jau yra. Ar tikrai norite jį pakeisti?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Ar tikrai norite ištrinti šį profilį?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation>&amp;Gerai</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation>&amp;Atsisakyti</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Taip</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Taip, visada</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Ne</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Ne, niekada</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Sinchronizacijos Grafikas</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="264"/>
        <source>Video in</source>
        <translation>Vaizdo įvestis</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="265"/>
        <source>Audio in</source>
        <translation>Garso įvestis</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="266"/>
        <source>Video out</source>
        <translation>Vaizdo išvestis</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="267"/>
        <source>Audio out</source>
        <translation>Garso išvestis</translation>
    </message>
</context>
</TS>
