<?xml version='1.0' encoding='utf-8'?>
<!DOCTYPE TS>
<TS language="hu_HU" version="2.0">
<context>
    <name>DialogAbout</name>
    <message>
        <location line="78" filename="../GUI/PageWelcome.cpp"/>
        <source>About SimpleScreenRecorder</source>
        <translation>A SimpleScreenRecorder névjegye</translation>
    </message>
    <message>
        <location line="87" filename="../GUI/PageWelcome.cpp"/>
        <source>For more information:</source>
        <translation>További információk:</translation>
    </message>
    <message>
        <location line="88" filename="../GUI/PageWelcome.cpp"/>
        <source>The source code of this program can be found at:</source>
        <translation>A program forráskódja megtalálható a következő helyen:</translation>
    </message>
    <message>
        <location line="89" filename="../GUI/PageWelcome.cpp"/>
        <source>This program uses:</source>
        <translation>A program a következőket használja:</translation>
    </message>
    <message>
        <location line="90" filename="../GUI/PageWelcome.cpp"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 a grafikus felhasználói felülethez</translation>
    </message>
    <message>
        <location line="91" filename="../GUI/PageWelcome.cpp"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 vagy %2 (a disztribúciótól függően) a videó- és hangkódoláshoz</translation>
    </message>
    <message>
        <location line="92" filename="../GUI/PageWelcome.cpp"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 a rendszerfüggvények kapcsolásához az OpenGL rögzítésnél</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location line="34" filename="../GUI/DialogGLInject.cpp"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL beállítások</translation>
    </message>
    <message>
        <location line="37" filename="../GUI/DialogGLInject.cpp"/>
        <source>&lt;p>Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it's (theoretically) possible that the game will consider this a hack. This might even get you banned, so it's a good idea to make sure that the program you want to record won't ban you, *before* you try to record it. You've been warned :).&lt;/p>

&lt;p>Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p>

&lt;p>If you want to record Steam games, &lt;a href="http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/">read this first&lt;/a>.&lt;/p></source>
        <translation>&lt;p>Figyelmeztetés: az OpenGL alkalmazások felvétele egy programkönyvtár beültetésével történik abba a programba, amely rögzítésre fog kerülni. Ez a programkönyvtár felül fog bírálni néhány rendszerfüggvényt annak érdekében, hogy a képkockákat a képernyőn való megjelenítésük előtt rögzítse. Ha olyan játékról szeretne felvételt készíteni, amely megpróbálja a kliens oldalon felismerni a csalási kísérleteket, akkor (elméletileg) lehetséges, hogy a játék ezt csalásnak fogja gondolni. Ez akár a kitiltásához is vezethet, ezért a rögzítési kísérlet *előtt* jó ötlet lehet meggyőződni arról, hogy a rögzíteni kívánt program nem fogja kitiltani önt. Mi figyelmeztettük :).&lt;/p>

&lt;p>Egy másik figyelmeztetés: az OpenGL rögzítés kísérleti funkció, előfordulhat, hogy nem működik, vagy akár az éppen rögzített programot összeomlásához is vezethet. Ha aggódik a program adatainak elvesztésével kapcsolatban, akkor először készítsen biztonsági mentést!&lt;/p>

&lt;p>Ha Steam játékokat szeretne rögzíteni, akkor &lt;a href="http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/">először ezt olvassa el&lt;/a>.&lt;/p></translation>
    </message>
    <message>
        <location line="51" filename="../GUI/DialogGLInject.cpp"/>
        <source>Choose channel</source>
        <translation>Csatorna kiválasztása	</translation>
    </message>
    <message>
        <location line="53" filename="../GUI/DialogGLInject.cpp"/>
        <source>Channel name:</source>
        <translation>Csatorna neve:</translation>
    </message>
    <message>
        <location line="55" filename="../GUI/DialogGLInject.cpp"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name 'channel-YOURUSERNAME' will be used.</source>
        <translation>A csatornaneveket az alkalmazások azonosításához használják. Csak akkor kell ezt használnia, ha egyszerre több alkalmazást szeretne rögzíteni.
Ha ezt üresen hagyja, akkor az alapértelmezett „channel-FELHASZNÁLÓNÉV” név lesz használva.</translation>
    </message>
    <message>
        <location line="57" filename="../GUI/DialogGLInject.cpp"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Osztott memória jogosultságok gyengítése (nem biztonságos)</translation>
    </message>
    <message>
        <location line="58" filename="../GUI/DialogGLInject.cpp"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that's used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Ha be van jelölve, akkor az azonos rendszeren lévő egyéb felhasználók képesek lesznek hozzácsatolni ahhoz az osztott memóriához, amelyet az OpenGL programmal történő kommunikációhoz használnak.
Ez azt jelenti, hogy a többi felhasználó (elméletileg) láthatja, amit rögzít, módosíthatják a képkockákat, beültethetik a saját képkockáikat, vagy egyszerűen zavarhatják a kommunikációt.
Ez még azokra a felhasználókra is alkalmazható, akik távolról jelentkeznek be (SSH). Csak akkor kell ezt engedélyeznie, ha egy olyan programot kell rögzítenie, amelyet eltérő felhasználóként futtat.</translation>
    </message>
    <message>
        <location line="73" filename="../GUI/DialogGLInject.cpp"/>
        <source>Launch application</source>
        <translation>Alkalmazás indítása</translation>
    </message>
    <message>
        <location line="75" filename="../GUI/DialogGLInject.cpp"/>
        <source>Command:</source>
        <translation>Parancs:</translation>
    </message>
    <message>
        <location line="77" filename="../GUI/DialogGLInject.cpp"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Ez a parancs lesz végrehajtva annak a programnak az indításához, amelyet rögzíteni kell.</translation>
    </message>
    <message>
        <location line="79" filename="../GUI/DialogGLInject.cpp"/>
        <source>Working directory:</source>
        <translation>Munkakönyvtár:</translation>
    </message>
    <message>
        <location line="81" filename="../GUI/DialogGLInject.cpp"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won't be changed.</source>
        <translation>A parancs ebben a könyvtárban lesz végrehajtva. Ha ezt üresen hagyja, akkor a munkakönyvtár nem lesz megváltoztatva.</translation>
    </message>
    <message>
        <location line="83" filename="../GUI/DialogGLInject.cpp"/>
        <source>Launch automatically</source>
        <translation>Automatikus indítás</translation>
    </message>
    <message>
        <location line="84" filename="../GUI/DialogGLInject.cpp"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Ha be van jelölve, akkor az alkalmazás automatikusan el lesz indítva, amikor a rögzítő oldalra megy. Ha nincs bejelölve, akkor kézzel kell elindítania azt.</translation>
    </message>
    <message>
        <location line="86" filename="../GUI/DialogGLInject.cpp"/>
        <source>Launch now</source>
        <translation>Indítás most</translation>
    </message>
    <message>
        <location line="107" filename="../GUI/DialogGLInject.cpp"/>
        <source>Stream settings</source>
        <translation>Adatfolyam beállítások</translation>
    </message>
    <message>
        <location line="109" filename="../GUI/DialogGLInject.cpp"/>
        <source>Limit application frame rate</source>
        <translation>Alkalmazás képkockasebességének korlátozása</translation>
    </message>
    <message>
        <location line="110" filename="../GUI/DialogGLInject.cpp"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn't become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won't be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Ha be van jelölve, akkor a beültetett programkönyvtár le fogja lassítani az alkalmazást, így a képkockasebesség nem lesz magasabb a rögzítés képkockasebességénél.
Ez megakadályozza az alkalmazást a processzoridő pazarlásában azok képkockáknál, amelyek nem lesznek rögzítve, és ez néha simább videót eredményez (ez az alkalmazástól függ).</translation>
    </message>
    <message>
        <location line="119" filename="../GUI/DialogGLInject.cpp"/>
        <source>Close</source>
        <translation>Bezárás</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location line="124" filename="../AV/FastResampler.cpp"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Hiba: az újramintavételezési arány kívül esik a tartományon!</translation>
    </message>
    <message>
        <location line="128" filename="../AV/FastResampler.cpp"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Hiba: az elcsúszási arány kívül esik a tartományon!</translation>
    </message>
    <message>
        <location line="158" filename="../AV/FastResampler.cpp"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Az újramintavételezési arány %1 (%2 volt).</translation>
    </message>
    <message>
        <location line="116" filename="../AV/FastScaler.cpp"/>
        <source>Warning: Pixel format is not supported (%1 -> %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Figyelmeztetés: a képpontformátum nem támogatott (%1 -> %2), szoftveres méretezés használata helyette. Ez nem probléma, de a teljesítmény rosszabb lesz.</translation>
    </message>
    <message>
        <location line="125" filename="../AV/FastScaler.cpp"/>
        <location line="119" filename="../Benchmark.cpp"/>
        <location line="200" filename="../Benchmark.cpp"/>
        <source>Error: Can't get swscale context!</source>
        <comment>Don't translate 'swscale'</comment>
        <translation>Hiba: nem lehet lekérni a szoftveres méretezés környezetét!</translation>
    </message>
    <message>
        <location line="147" filename="../AV/FastScaler.cpp"/>
        <location line="172" filename="../AV/FastScaler.cpp"/>
        <location line="197" filename="../AV/FastScaler.cpp"/>
        <location line="219" filename="../AV/FastScaler.cpp"/>
        <location line="242" filename="../AV/FastScaler.cpp"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don't translate 'fallback'</comment>
        <translation>Figyelmeztetés: a memória nincs megfelelően az SSE-hez igazítva, tartalék átalakító használata helyette. Ez nem probléma, de a teljesítmény rosszabb lesz.</translation>
    </message>
    <message>
        <location line="32" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don't translate 'overrun'</comment>
        <translation>Figyelmeztetés: túlfutás történt, néhány minta elveszett.</translation>
    </message>
    <message>
        <location line="34" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Error: Can't recover device after overrun!</source>
        <comment>Don't translate 'overrun'</comment>
        <translation>Hiba: nem lehet visszaállítani az eszközt a túlfutás után!</translation>
    </message>
    <message>
        <location line="38" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Error: Can't start PCM device after overrun!</source>
        <comment>Don't translate 'overrun'</comment>
        <translation>Hiba: nem lehet elindítani a PCM-eszközt a túlfutás után!</translation>
    </message>
    <message>
        <location line="66" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="63" filename="../AV/Input/GLInjectInput.cpp"/>
        <location line="56" filename="../AV/Input/JACKInput.cpp"/>
        <location line="207" filename="../AV/Input/X11Input.cpp"/>
        <source>Stopping input thread ...</source>
        <translation>Bemeneti szál leállítása…</translation>
    </message>
    <message>
        <location line="96" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="232" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Generating source list ...</source>
        <translation>Forráslista előállítása…</translation>
    </message>
    <message>
        <location line="115" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Hiba: nem sikerült frissíteni az ALSA beállításokat!</translation>
    </message>
    <message>
        <location line="175" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Figyelmeztetés: nem sikerült megnyitni a következő hangkártyát: %1.</translation>
    </message>
    <message>
        <location line="181" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Figyelmeztetés: nem sikerült információkat lekérni a következő hangkártyához: %1.</translation>
    </message>
    <message>
        <location line="162" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Talált bővítmény: [%1] %2</translation>
    </message>
    <message>
        <location line="185" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Found card: [%1] %2</source>
        <translation>Talált kártya: [%1] %2</translation>
    </message>
    <message>
        <location line="210" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Found device: [%1] %2</source>
        <translation>Talált eszköz: [%1] %2</translation>
    </message>
    <message>
        <location line="259" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="123" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't open PCM device!</source>
        <translation>Hiba: nem nyitható meg a PCM-eszköz!</translation>
    </message>
    <message>
        <location line="263" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="127" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't get PCM hardware parameters!</source>
        <translation>Hiba: nem lehet lekérni a PCM-hardver paramétereit!</translation>
    </message>
    <message>
        <location line="269" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="133" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't set access type!</source>
        <translation>Hiba: nem lehet beállítani a hozzáférési típust!</translation>
    </message>
    <message>
        <location line="275" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="139" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't set sample format!</source>
        <translation>Hiba: nem lehet beállítani a mintavételezési formátumot!</translation>
    </message>
    <message>
        <location line="282" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="146" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't set sample rate!</source>
        <translation>Hiba: nem lehet beállítani a mintavételezési gyakoriságot!</translation>
    </message>
    <message>
        <location line="286" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="150" filename="../AV/SimpleSynth.cpp"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Figyelmeztetés: a(z) %1 mintavételi gyakoriság nem támogatott, %2 használata helyette. Ez nem probléma.</translation>
    </message>
    <message>
        <location line="295" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="158" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't set channel count!</source>
        <translation>Hiba: nem lehet beállítani a csatornaszámot!</translation>
    </message>
    <message>
        <location line="299" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Figyelmeztetés: a(z) %1 csatornaszám nem támogatott, %2 használata helyette. Ez nem probléma.</translation>
    </message>
    <message>
        <location line="308" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="165" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't set period size!</source>
        <translation>Hiba: nem lehet beállítani az időszak méretét!</translation>
    </message>
    <message>
        <location line="312" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="169" filename="../AV/SimpleSynth.cpp"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Figyelmeztetés: a(z) %1 időszakméret nem támogatott, %2 használata helyette. Ez nem probléma.</translation>
    </message>
    <message>
        <location line="321" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="178" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't set buffer size!</source>
        <translation>Hiba: nem lehet beállítani a puffer méretét!</translation>
    </message>
    <message>
        <location line="325" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="182" filename="../AV/SimpleSynth.cpp"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Figyelmeztetés: a(z) %1 pufferméret nem támogatott, %2 használata helyette. Ez nem probléma.</translation>
    </message>
    <message>
        <location line="333" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="190" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't apply PCM hardware parameters!</source>
        <translation>Hiba: nem lehet alkalmazni a PCM-hardver paramétereit!</translation>
    </message>
    <message>
        <location line="351" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Error: Can't start PCM device!</source>
        <translation>Hiba: nem lehet elindítani a PCM-eszközt!</translation>
    </message>
    <message>
        <location line="372" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="180" filename="../AV/Input/GLInjectInput.cpp"/>
        <location line="238" filename="../AV/Input/JACKInput.cpp"/>
        <location line="299" filename="../AV/Input/PulseAudioInput.cpp"/>
        <location line="345" filename="../AV/Input/X11Input.cpp"/>
        <source>Input thread started.</source>
        <translation>Bemeneti szál elindítva.</translation>
    </message>
    <message>
        <location line="387" filename="../AV/Input/ALSAInput.cpp"/>
        <source>Error: Can't read samples!</source>
        <translation>Hiba: nem lehet olvasni a mintákat!</translation>
    </message>
    <message>
        <location line="413" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="248" filename="../AV/Input/GLInjectInput.cpp"/>
        <location line="289" filename="../AV/Input/JACKInput.cpp"/>
        <location line="388" filename="../AV/Input/PulseAudioInput.cpp"/>
        <location line="444" filename="../AV/Input/X11Input.cpp"/>
        <source>Input thread stopped.</source>
        <translation>Bemeneti szál leállítva.</translation>
    </message>
    <message>
        <location line="417" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="252" filename="../AV/Input/GLInjectInput.cpp"/>
        <location line="293" filename="../AV/Input/JACKInput.cpp"/>
        <location line="392" filename="../AV/Input/PulseAudioInput.cpp"/>
        <location line="448" filename="../AV/Input/X11Input.cpp"/>
        <source>Exception '%1' in input thread.</source>
        <translation>„%1” kivétel a bemeneti szálban.</translation>
    </message>
    <message>
        <location line="420" filename="../AV/Input/ALSAInput.cpp"/>
        <location line="255" filename="../AV/Input/GLInjectInput.cpp"/>
        <location line="296" filename="../AV/Input/JACKInput.cpp"/>
        <location line="395" filename="../AV/Input/PulseAudioInput.cpp"/>
        <location line="451" filename="../AV/Input/X11Input.cpp"/>
        <source>Unknown exception in input thread.</source>
        <translation>Ismeretlen kivétel a bemeneti szálban.</translation>
    </message>
    <message>
        <location line="149" filename="../AV/Input/GLInjectInput.cpp"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Hiba: nem sikerült olvasni az adatfolyamot, ez általában azt jelenti, hogy az adatfolyam már elmúlt.</translation>
    </message>
    <message>
        <location line="72" filename="../AV/Input/JACKInput.cpp"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Hiba: nem sikerült kapcsolódni a JACK kiszolgálóhoz!</translation>
    </message>
    <message>
        <location line="81" filename="../AV/Input/JACKInput.cpp"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Hiba: nem sikerült létrehozni a JACK portot!</translation>
    </message>
    <message>
        <location line="87" filename="../AV/Input/JACKInput.cpp"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Hiba: nem sikerült beállítani a JACK-folyamat visszahívását!</translation>
    </message>
    <message>
        <location line="91" filename="../AV/Input/JACKInput.cpp"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Hiba: nem sikerült beállítani a JACK mintavételezési gyakoriság visszahívását!</translation>
    </message>
    <message>
        <location line="95" filename="../AV/Input/JACKInput.cpp"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Hiba: nem sikerült beállítani a JACK xrun visszahívását!</translation>
    </message>
    <message>
        <location line="99" filename="../AV/Input/JACKInput.cpp"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Hiba: nem sikerült beállítani a JACK port kapcsolódási visszahívását!</translation>
    </message>
    <message>
        <location line="104" filename="../AV/Input/JACKInput.cpp"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Hiba: nem sikerült aktiválni a JACK klienst!</translation>
    </message>
    <message>
        <location line="112" filename="../AV/Input/JACKInput.cpp"/>
        <location line="123" filename="../AV/Input/JACKInput.cpp"/>
        <location line="252" filename="../AV/Input/JACKInput.cpp"/>
        <source>Connecting port %1 to %2.</source>
        <translation>%1 port kapcsolása ide: %2.</translation>
    </message>
    <message>
        <location line="256" filename="../AV/Input/JACKInput.cpp"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>%1 port leválasztása innen: %2.</translation>
    </message>
    <message>
        <location line="35" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don't translate 'pa_mainloop_prepare'</comment>
        <translation>Hiba: a pa_mainloop_prepare hívás sikertelen!</translation>
    </message>
    <message>
        <location line="39" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don't translate 'pa_mainloop_poll'</comment>
        <translation>Hiba: a pa_mainloop_poll hívás sikertelen!</translation>
    </message>
    <message>
        <location line="43" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don't translate 'pa_mainloop_dispatch'</comment>
        <translation>Hiba: a pa_mainloop_dispatch hívás sikertelen!</translation>
    </message>
    <message>
        <location line="53" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Could not create main loop!</source>
        <translation>Hiba: nem sikerült létrehozni a fő ciklust!</translation>
    </message>
    <message>
        <location line="60" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Could not create context!</source>
        <translation>Hiba: nem sikerült létrehozni a környezetet!</translation>
    </message>
    <message>
        <location line="64" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn't use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Hiba: nem sikerült kapcsolódni! Ok: %1
Lehetséges, hogy a rendszere nem PulseAudio háttérprogramot használ. Próbálja meg az ALSA háttérprogramot használni helyette.</translation>
    </message>
    <message>
        <location line="77" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Hiba: a kapcsolódási kísérlet nem sikerült! Ok: %1</translation>
    </message>
    <message>
        <location line="114" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Hiba: nem sikerült létrehozni az adatfolyamot! Ok: %1</translation>
    </message>
    <message>
        <location line="121" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Hiba: nem sikerült kapcsolódni az adatfolyamhoz! Ok: %1</translation>
    </message>
    <message>
        <location line="132" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Hiba: az adatfolyam-kapcsolódási kísérlet nem sikerült! Ok: %1</translation>
    </message>
    <message>
        <location line="223" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Found source: [%1] %2</source>
        <translation>Talált forrás: [%1] %2</translation>
    </message>
    <message>
        <location line="244" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Hiba: nem sikerült lekérni a források neveit! Ok: %1</translation>
    </message>
    <message>
        <location line="313" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don't translate 'pa_stream_peek'</comment>
        <translation>Hiba: a pa_stream_peek hívás sikertelen!</translation>
    </message>
    <message>
        <location line="377" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Figyelmeztetés: a hangforrás fel lett függesztve. A jelenlegi szakasz le lesz állítva, amíg a forrás nem folytatódik.</translation>
    </message>
    <message>
        <location line="382" filename="../AV/Input/PulseAudioInput.cpp"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Figyelmeztetés: az adatfolyam át lett helyezve egy eltérő forrásba.</translation>
    </message>
    <message>
        <location line="64" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Created video stream reader.</source>
        <translation>Videó adatfolyam olvasó létrehozva.</translation>
    </message>
    <message>
        <location line="69" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Error: Can't open video stream file!</source>
        <translation>Hiba: nem lehet megnyitni a videó adatfolyam fájlt!</translation>
    </message>
    <message>
        <location line="76" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Error: Can't resize video stream file!</source>
        <translation>Hiba: nem lehet átméretezni a videó adatfolyam fájlt!</translation>
    </message>
    <message>
        <location line="83" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Error: Can't memory-map video stream file!</source>
        <translation>Hiba: nem lehet leképezni a memóriába a videó adatfolyam fájlt!</translation>
    </message>
    <message>
        <location line="92" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Error: Can't open video frame file!</source>
        <translation>Hiba: nem lehet megnyitni a videoképkocka fájlt!</translation>
    </message>
    <message>
        <location line="142" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Destroyed video stream reader.</source>
        <translation>Videó adatfolyam olvasó megsemmisítve.</translation>
    </message>
    <message>
        <location line="238" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Hiba: a videoképkocka fájl mérete hibás!</translation>
    </message>
    <message>
        <location line="247" filename="../AV/Input/SSRVideoStreamReader.cpp"/>
        <source>Error: Can't memory-map video frame file!</source>
        <translation>Hiba: nem lehet leképezni a memóriába a videoképkocka fájlt!</translation>
    </message>
    <message>
        <location line="88" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't create channel directory!</source>
        <translation>Hiba: nem lehet létrehozni csatornakönyvtárat!</translation>
    </message>
    <message>
        <location line="95" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't stat channel directory!</source>
        <translation>Hiba: nem lehet elérni a csatornakönyvtárat!</translation>
    </message>
    <message>
        <location line="99" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Hiba: a csatornakönyvtár nem szabályos könyvtár!</translation>
    </message>
    <message>
        <location line="104" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't set channel directory mode!</source>
        <translation>Hiba: nem lehet beállítani a csatornakönyvtár módját!</translation>
    </message>
    <message>
        <location line="109" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Hiba: a csatornakönyvtár egy másik felhasználó tulajdona. Válasszon másik csatornanevet, vagy engedélyezzen gyengített fájljogosultságokat, ha mindenképp használni szeretné.</translation>
    </message>
    <message>
        <location line="121" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't initialize inotify!</source>
        <comment>don't translate 'inotify'</comment>
        <translation>Hiba: nem lehet előkészíteni az inotify hívást!</translation>
    </message>
    <message>
        <location line="127" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't watch channel directory!</source>
        <translation>Hiba: nem lehet megfigyelni a csatornakönyvtárat!</translation>
    </message>
    <message>
        <location line="139" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't open channel directory!</source>
        <translation>Hiba: nem lehet megnyitni a csatornakönyvtárat!</translation>
    </message>
    <message>
        <location line="157" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Előre meglévő adatfolyam (%1) hozzáadva.</translation>
    </message>
    <message>
        <location line="192" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't get read length from inotify!</source>
        <comment>don't translate 'inotify'</comment>
        <translation>Hiba: nem lehet lekérni az olvasási hosszt az inotify értesítésből!</translation>
    </message>
    <message>
        <location line="200" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Can't read from inotify!</source>
        <comment>don't translate 'inotify'</comment>
        <translation>Hiba: nem lehet olvasni az inotify értesítésből!</translation>
    </message>
    <message>
        <location line="210" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don't translate 'inotify'</comment>
        <translation>Hiba: részleges esemény érkezett az inotify értesítésből!</translation>
    </message>
    <message>
        <location line="222" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don't translate 'inotify'</comment>
        <translation>Hiba: részleges név érkezett az inotify értesítésből!</translation>
    </message>
    <message>
        <location line="236" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Added stream %1.</source>
        <translation>%1 adatfolyam hozzáadva.</translation>
    </message>
    <message>
        <location line="244" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Removed stream %1.</source>
        <translation>%1 adatfolyam eltávolítva.</translation>
    </message>
    <message>
        <location line="270" filename="../AV/Input/SSRVideoStreamWatcher.cpp"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Elhagyott %1 adatfolyam törölve.</translation>
    </message>
    <message>
        <location line="74" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Hiba: nem támogatott X11-kép képpontformátum!</translation>
    </message>
    <message>
        <location line="186" filename="../AV/Input/X11Input.cpp"/>
        <location line="112" filename="../AV/Output/VideoEncoder.cpp"/>
        <source>Error: Width or height is zero!</source>
        <translation>Hiba: a szélesség vagy a magasság nulla!</translation>
    </message>
    <message>
        <location line="190" filename="../AV/Input/X11Input.cpp"/>
        <location line="116" filename="../AV/Output/VideoEncoder.cpp"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Hiba: a szélesség vagy a magasság túl nagy, a legnagyobb szélesség és magasság %1!</translation>
    </message>
    <message>
        <location line="236" filename="../AV/Input/X11Input.cpp"/>
        <location line="118" filename="../GUI/HotkeyListener.cpp"/>
        <source>Error: Can't open X display!</source>
        <comment>Don't translate 'display'</comment>
        <translation>Hiba: nem lehet megnyitni az X-megjelenítőt!</translation>
    </message>
    <message>
        <location line="245" filename="../AV/Input/X11Input.cpp"/>
        <source>Using X11 shared memory.</source>
        <translation>Az X11 osztott memóriájának használata.</translation>
    </message>
    <message>
        <location line="248" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Can't create shared image!</source>
        <translation>Hiba: nem lehet létrehozni osztott képet!</translation>
    </message>
    <message>
        <location line="253" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Can't get shared memory!</source>
        <translation>Hiba: nem lehet lekérni az osztott memóriát!</translation>
    </message>
    <message>
        <location line="258" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Can't attach to shared memory!</source>
        <translation>Hiba: nem lehet hozzácsatolni az osztott memóriához!</translation>
    </message>
    <message>
        <location line="264" filename="../AV/Input/X11Input.cpp"/>
        <source>Not using X11 shared memory.</source>
        <translation>Nem használja az X11 osztott memóriáját.</translation>
    </message>
    <message>
        <location line="271" filename="../AV/Input/X11Input.cpp"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don't translate 'XFixes'</comment>
        <translation>Figyelmeztetés: az XFixes-t nem támogatja az X-kiszolgáló, a kurzor rejtve lesz.</translation>
    </message>
    <message>
        <location line="329" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Hiba: érvénytelen képernyő határoló doboz!</translation>
    </message>
    <message>
        <location line="393" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Can't attach server to shared memory!</source>
        <translation>Hiba: nem lehet hozzácsatolni a kiszolgálót az osztott memóriához!</translation>
    </message>
    <message>
        <location line="399" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Can't get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Hiba: nem lehet lekérni a képet (osztott memória használata)!
    Általában ez azt jelenti, hogy a rögzítendő terület nincs teljesen a képernyőn belül. Vagy megváltoztatta a képernyőfelbontást?</translation>
    </message>
    <message>
        <location line="410" filename="../AV/Input/X11Input.cpp"/>
        <source>Error: Can't get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Hiba: nem lehet lekérni a képet (nem használ osztott memóriát)!
    Általában ez azt jelenti, hogy a rögzítendő terület nincs teljesen a képernyőn belül. Vagy megváltoztatta a képernyőfelbontást?</translation>
    </message>
    <message>
        <location line="99" filename="../AV/Output/AudioEncoder.cpp"/>
        <source>Error: Channel count is zero.</source>
        <translation>Hiba: a csatornaszám nulla.</translation>
    </message>
    <message>
        <location line="103" filename="../AV/Output/AudioEncoder.cpp"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Hiba: a mintavételezési gyakoriság nulla.</translation>
    </message>
    <message>
        <location line="140" filename="../AV/Output/AudioEncoder.cpp"/>
        <source>Using sample format %1.</source>
        <translation>%1 mintavételezési formátum használata.</translation>
    </message>
    <message>
        <location line="145" filename="../AV/Output/AudioEncoder.cpp"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Hiba: a kódoló egy nem támogatott mintavételezési formátumot igényel!</translation>
    </message>
    <message>
        <location line="176" filename="../AV/Output/AudioEncoder.cpp"/>
        <location line="197" filename="../AV/Output/AudioEncoder.cpp"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Hiba: a hangkockák kódolása nem sikerült!</translation>
    </message>
    <message>
        <location line="31" filename="../AV/Output/BaseEncoder.cpp"/>
        <location line="40" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Error: Option '%1' could not be parsed!</source>
        <translation>Hiba: a(z) „%1” kapcsoló feldolgozása nem sikerült!</translation>
    </message>
    <message>
        <location line="96" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Stopping encoder thread ...</source>
        <translation>Kódoló szál leállítása…</translation>
    </message>
    <message>
        <location line="155" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Error: Can't open codec!</source>
        <translation>Hiba: nem lehet megnyitni a kodeket!</translation>
    </message>
    <message>
        <location line="163" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Warning: Codec option '%1' was not recognised!</source>
        <translation>Figyelmeztetés: a(z) „%1” kodek kapcsoló nem volt felismerhető!</translation>
    </message>
    <message>
        <location line="179" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Encoder thread started.</source>
        <translation>Kódoló szál elindítva.</translation>
    </message>
    <message>
        <location line="211" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Flushing encoder ...</source>
        <translation>Kódoló kiürítése…</translation>
    </message>
    <message>
        <location line="225" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Encoder thread stopped.</source>
        <translation>Kódoló szál leállítva.</translation>
    </message>
    <message>
        <location line="229" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Exception '%1' in encoder thread.</source>
        <translation>„%1” kivétel a kódoló szálban.</translation>
    </message>
    <message>
        <location line="232" filename="../AV/Output/BaseEncoder.cpp"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Ismeretlen kivétel a kódoló szálban.</translation>
    </message>
    <message>
        <location line="71" filename="../AV/Output/Muxer.cpp"/>
        <source>Stopping encoders ...</source>
        <translation>Kódolók leállása…</translation>
    </message>
    <message>
        <location line="78" filename="../AV/Output/Muxer.cpp"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Várakozás a muxer szál leállítására…</translation>
    </message>
    <message>
        <location line="133" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't write header!</source>
        <comment>Don't translate 'header'</comment>
        <translation>Hiba: nem lehet kiírni a fejlécet!</translation>
    </message>
    <message>
        <location line="144" filename="../AV/Output/Muxer.cpp"/>
        <source>Finishing encoders ...</source>
        <translation>Kódolók befejezése…</translation>
    </message>
    <message>
        <location line="186" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't find chosen output format!</source>
        <translation>Hiba: nem található a kiválasztott kimeneti formátum!</translation>
    </message>
    <message>
        <location line="190" filename="../AV/Output/Muxer.cpp"/>
        <source>Using format %1 (%2).</source>
        <translation>%1 formátum használata (%2).</translation>
    </message>
    <message>
        <location line="196" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't allocate format context!</source>
        <translation>Hiba: nem lehet lefoglalni formátumkörnyezetet!</translation>
    </message>
    <message>
        <location line="203" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't open output file!</source>
        <translation>Hiba: nem lehet megnyitni a kimeneti fájlt!</translation>
    </message>
    <message>
        <location line="216" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't write trailer, continuing anyway.</source>
        <comment>Don't translate 'trailer'</comment>
        <translation>Hiba: nem lehet kiírni a záró részt, folytatás mindenképp.</translation>
    </message>
    <message>
        <location line="254" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't find codec!</source>
        <translation>Hiba: nem található kodek!</translation>
    </message>
    <message>
        <location line="264" filename="../AV/Output/Muxer.cpp"/>
        <source>Using codec %1 (%2).</source>
        <translation>%1 kodek használata (%2).</translation>
    </message>
    <message>
        <location line="273" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't create new stream!</source>
        <translation>Hiba: nem lehet létrehozni új adatfolyamot!</translation>
    </message>
    <message>
        <location line="283" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't get codec context defaults!</source>
        <translation>Hiba: nem lehet lekérni a kodek környezet alapértelmezéseit!</translation>
    </message>
    <message>
        <location line="296" filename="../AV/Output/Muxer.cpp"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Figyelmeztetés: ezt a kodeket kísérletinek tekinti a libav/ffmpeg.</translation>
    </message>
    <message>
        <location line="312" filename="../AV/Output/Muxer.cpp"/>
        <source>Muxer thread started.</source>
        <translation>Muxer szál elindítva.</translation>
    </message>
    <message>
        <location line="371" filename="../AV/Output/Muxer.cpp"/>
        <source>Error: Can't write frame to muxer!</source>
        <translation>Hiba: nem lehet kiírni a keretet a muxerbe!</translation>
    </message>
    <message>
        <location line="399" filename="../AV/Output/Muxer.cpp"/>
        <source>Muxer thread stopped.</source>
        <translation>Muxer szál leállítva.</translation>
    </message>
    <message>
        <location line="403" filename="../AV/Output/Muxer.cpp"/>
        <source>Exception '%1' in muxer thread.</source>
        <translation>„%1” kivétel a muxer szálban.</translation>
    </message>
    <message>
        <location line="406" filename="../AV/Output/Muxer.cpp"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Ismeretlen kivétel a muxer szálban.</translation>
    </message>
    <message>
        <location line="205" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Szinkronizáló szál leállítása…</translation>
    </message>
    <message>
        <location line="322" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Figyelmeztetés: nem monoton időbélyeggel rendelkező videoképkocka érkezett.</translation>
    </message>
    <message>
        <location line="348" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Figyelmeztetés: videopuffer túlcsordulás, néhány képkocka el fog veszni. A hangbemenet túl lassúnak tűnik.</translation>
    </message>
    <message>
        <location line="405" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Figyelmeztetés: nem monoton időbélyeggel rendelkező hangminták érkeztek.</translation>
    </message>
    <message>
        <location line="430" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Figyelmeztetés: túl sok hangminta, minták eldobása a hang és a videó szinkronban tartásához.</translation>
    </message>
    <message>
        <location line="436" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Figyelmeztetés: nincs elég hangminta, csend beszúrása a hang és a videó szinkronban tartásához.</translation>
    </message>
    <message>
        <location line="502" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Figyelmeztetés: a hangbemenet túl lassú több mint 2%-kal!</translation>
    </message>
    <message>
        <location line="506" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Figyelmeztetés: a hangbemenet túl gyors több mint 2%-kal!</translation>
    </message>
    <message>
        <location line="541" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Figyelmeztetés: hangpuffer túlcsordulás, új szakasz indítása a hang és a videó szinkronban tartásához (néhány videó és/vagy hang elveszhet). A videobemenet túl lassúnak tűnik.</translation>
    </message>
    <message>
        <location line="577" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Figyelmeztetés: lyuk érkezett a hang adatfolyamban, csend beszúrása a hang és a videó szinkronban tartásához.</translation>
    </message>
    <message>
        <location line="877" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Synchronizer thread started.</source>
        <translation>Szinkronizáló szál elindítva.</translation>
    </message>
    <message>
        <location line="899" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Szinkronizáló szál leállítva.</translation>
    </message>
    <message>
        <location line="903" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Exception '%1' in synchronizer thread.</source>
        <translation>„%1” kivétel a szinkronizáló szálban.</translation>
    </message>
    <message>
        <location line="906" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Ismeretlen kivétel a szinkronizáló szálban.</translation>
    </message>
    <message>
        <location line="120" filename="../AV/Output/VideoEncoder.cpp"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Hiba: a szélesség vagy a magasság nem páros szám!</translation>
    </message>
    <message>
        <location line="124" filename="../AV/Output/VideoEncoder.cpp"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Hiba: a képkockasebesség nulla!</translation>
    </message>
    <message>
        <location line="181" filename="../AV/Output/VideoEncoder.cpp"/>
        <source>Using pixel format %1.</source>
        <translation>%1 képpontformátum használata.</translation>
    </message>
    <message>
        <location line="195" filename="../AV/Output/VideoEncoder.cpp"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Hiba: a képpontformátumot nem támogatja a kodek!</translation>
    </message>
    <message>
        <location line="225" filename="../AV/Output/VideoEncoder.cpp"/>
        <location line="245" filename="../AV/Output/VideoEncoder.cpp"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Hiba: a videoképkockák kódolása nem sikerült!</translation>
    </message>
    <message>
        <location line="40" filename="../AV/SimpleSynth.cpp"/>
        <source>Using real-time priority.</source>
        <translation>Valós idejű prioritás használata.</translation>
    </message>
    <message>
        <location line="50" filename="../AV/SimpleSynth.cpp"/>
        <source>Using nice priority.</source>
        <comment>Don't translate 'nice', it's a UNIX parameter that defines the priority of a process.</comment>
        <translation>Nice prioritás használata.</translation>
    </message>
    <message>
        <location line="55" filename="../AV/SimpleSynth.cpp"/>
        <source>Warning: Can't increase the thread priority.</source>
        <translation>Figyelmeztetés: nem lehet növelni a szálprioritást.</translation>
    </message>
    <message>
        <location line="63" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't recover device after underrun!</source>
        <comment>Don't translate 'underrun'</comment>
        <translation>Hiba: nem lehet visszaállítani az eszközt az aláfutás után!</translation>
    </message>
    <message>
        <location line="90" filename="../AV/SimpleSynth.cpp"/>
        <source>Stopping synth thread ...</source>
        <translation>Szintetizáló szál leállítása…</translation>
    </message>
    <message>
        <location line="223" filename="../AV/SimpleSynth.cpp"/>
        <source>Synth thread started.</source>
        <translation>Szintetizáló szál elindítva.</translation>
    </message>
    <message>
        <location line="276" filename="../AV/SimpleSynth.cpp"/>
        <source>Error: Can't write samples!</source>
        <translation>Hiba: nem lehet kiírni a mintákat!</translation>
    </message>
    <message>
        <location line="284" filename="../AV/SimpleSynth.cpp"/>
        <source>Synth thread stopped.</source>
        <translation>Szintetizáló szál leállítva.</translation>
    </message>
    <message>
        <location line="288" filename="../AV/SimpleSynth.cpp"/>
        <source>Exception '%1' in synth thread.</source>
        <translation>„%1” kivétel a szintetizáló szálban.</translation>
    </message>
    <message>
        <location line="291" filename="../AV/SimpleSynth.cpp"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Ismeretlen kivétel a szintetizáló szálban.</translation>
    </message>
    <message>
        <location line="46" filename="../common/CPUFeatures.cpp"/>
        <source>CPU features</source>
        <translation>Processzor szolgáltatásai</translation>
    </message>
    <message>
        <location line="159" filename="../GUI/DialogGLInject.cpp"/>
        <source>The application could not be launched.</source>
        <translation>Az alkalmazást nem sikerült elindítani.</translation>
    </message>
    <message>
        <location line="164" filename="../GUI/HotkeyListener.cpp"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don't translate 'XInput2'</comment>
        <translation>Figyelmeztetés: az XInput2-t nem támogatja az X-kiszolgáló, a gyorsbillentyűk esetleg nem működnek néhány alkalmazásban.</translation>
    </message>
    <message>
        <location line="119" filename="../Main.cpp"/>
        <source>Error: Command-line option '%1' does not take a value!</source>
        <translation>Hiba: a(z) „%1” parancssori kapcsoló nem vár értéket!</translation>
    </message>
    <message>
        <location line="150" filename="../Main.cpp"/>
        <source>Error: Unknown command-line option '%1'!</source>
        <translation>Hiba: ismeretlen parancssori kapcsoló: „%1”!</translation>
    </message>
    <message>
        <location line="160" filename="../Main.cpp"/>
        <source>Error: Unknown command-line argument '%1'!</source>
        <translation>Hiba: ismeretlen parancssori argumentum: „%1”!</translation>
    </message>
    <message>
        <location line="200" filename="../Main.cpp"/>
        <source>SSR started</source>
        <translation>SSR elindítva</translation>
    </message>
    <message>
        <location line="228" filename="../Main.cpp"/>
        <source>SSR stopped</source>
        <translation>SSR leállítva</translation>
    </message>
    <message>
        <location line="245" filename="../Main.cpp"/>
        <source>Error: Can't create .ssr directory!</source>
        <translation>Hiba: nem lehet létrehozni a .ssr könyvtárat!</translation>
    </message>
    <message>
        <location line="160" filename="../Benchmark.cpp"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation>BGRA %1 -> BGRA %2  |  SWScale %3 ha  |  Tartalék %4 ha (%5%)  |  SSSE3 %6 ha (%7%)</translation>
    </message>
    <message>
        <location line="238" filename="../Benchmark.cpp"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation>%1 %2 -> %3 %4  |  SWScale %5 ha  |  Tartalék %6 ha (%7%)  |  SSSE3 %8 ha (%9%)</translation>
    </message>
    <message>
        <location line="248" filename="../Benchmark.cpp"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Méretező teljesítménytesztjének indítása…</translation>
    </message>
    <message>
        <location line="255" filename="../Benchmark.cpp"/>
        <source>Starting converter benchmark ...</source>
        <translation>Átalakító teljesítménytesztjének indítása…</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location line="74" filename="../GUI/MainWindow.cpp"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don't translate 'flipping' unless NVIDIA does the same</comment>
        <translation>A SimpleScreenRecorder azt észlelte, hogy a zárt NVIDIA illesztőprogramot használja, és engedélyezve van a képernyő tükrözése. Ismert, hogy ez grafikai problémákhoz vezethet rögzítés közben. Ajánlott a tükrözés letiltása. Szeretné, hogy ezt megtegyem önnek?

Ezt a beállítást kézzel is megváltoztathatja az NVIDIA vezérlőpultján.</translation>
    </message>
    <message>
        <location line="90" filename="../GUI/MainWindow.cpp"/>
        <source>I couldn't disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don't translate 'flipping' unless NVIDIA does the same</comment>
        <translation>Nem tudtam letiltani a tükrözést valamilyen oknál fogva - elnézést! Próbálja meg letiltani az NVIDIA vezérlőpultján.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location line="30" filename="../GUI/PageDone.cpp"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>A felvétel mentésre került. Most már szerkesztheti a videót, vagy újrakódolhatja jobb beállításokkal, hogy kisebbé tegye a fájlt (az alapértelmezett beállítások a minőségre és a sebességre vannak optimalizálva, nem a fájlméretre).</translation>
    </message>
    <message>
        <location line="33" filename="../GUI/PageDone.cpp"/>
        <source>Back to the start screen</source>
        <translation>Vissza a kezdő képernyőre</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location line="113" filename="../GUI/PageInput.cpp"/>
        <source>Video input</source>
        <translation>Videobemenet</translation>
    </message>
    <message>
        <location line="116" filename="../GUI/PageInput.cpp"/>
        <source>Record the entire screen</source>
        <translation>A teljes képernyő rögzítése</translation>
    </message>
    <message>
        <location line="117" filename="../GUI/PageInput.cpp"/>
        <source>Record a fixed rectangle</source>
        <translation>Egy adott terület rögzítése</translation>
    </message>
    <message>
        <location line="118" filename="../GUI/PageInput.cpp"/>
        <source>Follow the cursor</source>
        <translation>A kurzor követése</translation>
    </message>
    <message>
        <location line="119" filename="../GUI/PageInput.cpp"/>
        <source>Record OpenGL (experimental)</source>
        <translation>OpenGL rögzítése (kísérleti)</translation>
    </message>
    <message>
        <location line="125" filename="../GUI/PageInput.cpp"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Válassza ki, hogy mely monitort kell rögzíteni egy többmonitoros konfigurációnál.</translation>
    </message>
    <message>
        <location line="126" filename="../GUI/PageInput.cpp"/>
        <source>Select rectangle...</source>
        <translation>Terület kijelölése…</translation>
    </message>
    <message>
        <location line="127" filename="../GUI/PageInput.cpp"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Használja az egeret a rögzítendő terület kijelöléséhez.</translation>
    </message>
    <message>
        <location line="128" filename="../GUI/PageInput.cpp"/>
        <source>Select window...</source>
        <translation>Ablak kiválasztása…</translation>
    </message>
    <message>
        <location line="129" filename="../GUI/PageInput.cpp"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Használja az egeret a rögzítendő ablak kiválasztásához.
Tipp: ha rákattint egy ablak keretére, akkor a teljes ablak rögzítésre kerül (beleértve a kereteket is). Egyébként csak az ablak kliensterülete lesz rögzítve.</translation>
    </message>
    <message>
        <location line="132" filename="../GUI/PageInput.cpp"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL beállítások…</translation>
    </message>
    <message>
        <location line="133" filename="../GUI/PageInput.cpp"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Beállítások megváltoztatása az OpenGL rögzítésnél.</translation>
    </message>
    <message>
        <location line="134" filename="../GUI/PageInput.cpp"/>
        <source>Left:</source>
        <translation>Balra:</translation>
    </message>
    <message>
        <location line="138" filename="../GUI/PageInput.cpp"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A rögzítendő terület bal felső sarkának X koordinátája.
Tipp: ezt az értéket az egérgörgővel vagy a fel/le nyilakkal is megváltoztathatja.</translation>
    </message>
    <message>
        <location line="140" filename="../GUI/PageInput.cpp"/>
        <source>Top:</source>
        <translation>Fent:</translation>
    </message>
    <message>
        <location line="144" filename="../GUI/PageInput.cpp"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A rögzítendő terület bal felső sarkának Y koordinátája.
Tipp: ezt az értéket az egérgörgővel vagy a fel/le nyilakkal is megváltoztathatja.</translation>
    </message>
    <message>
        <location line="146" filename="../GUI/PageInput.cpp"/>
        <source>Width:</source>
        <translation>Szélesség:</translation>
    </message>
    <message>
        <location line="150" filename="../GUI/PageInput.cpp"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A rögzítendő terület szélessége.
Tipp: ezt az értéket az egérgörgővel vagy a fel/le nyilakkal is megváltoztathatja.</translation>
    </message>
    <message>
        <location line="152" filename="../GUI/PageInput.cpp"/>
        <source>Height:</source>
        <translation>Magasság:</translation>
    </message>
    <message>
        <location line="156" filename="../GUI/PageInput.cpp"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A rögzítendő terület magassága.
Tipp: ezt az értéket az egérgörgővel vagy a fel/le nyilakkal is megváltoztathatja.</translation>
    </message>
    <message>
        <location line="158" filename="../GUI/PageInput.cpp"/>
        <source>Frame rate:</source>
        <translation>Képkockasebesség:</translation>
    </message>
    <message>
        <location line="162" filename="../GUI/PageInput.cpp"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>A végső videóban lévő másodpercenkénti képkockák száma. A magasabb képkockasebesség több processzoridőt használ.</translation>
    </message>
    <message>
        <location line="163" filename="../GUI/PageInput.cpp"/>
        <source>Scale video</source>
        <translation>Videó méretezése</translation>
    </message>
    <message>
        <location line="164" filename="../GUI/PageInput.cpp"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Méretezés engedélyezése vagy letiltása. A méretezés több processzoridőt használ, de ha a méretezett videó kisebb, akkor gyorsabbá teheti a kódolást.</translation>
    </message>
    <message>
        <location line="165" filename="../GUI/PageInput.cpp"/>
        <source>Scaled width:</source>
        <translation>Méretezett szélesség:</translation>
    </message>
    <message>
        <location line="169" filename="../GUI/PageInput.cpp"/>
        <source>Scaled height:</source>
        <translation>Méretezett magasság:</translation>
    </message>
    <message>
        <location line="173" filename="../GUI/PageInput.cpp"/>
        <source>Record cursor</source>
        <translation>Kurzor rögzítése</translation>
    </message>
    <message>
        <location line="243" filename="../GUI/PageInput.cpp"/>
        <source>Audio input</source>
        <translation>Hangbemenet</translation>
    </message>
    <message>
        <location line="245" filename="../GUI/PageInput.cpp"/>
        <source>Record audio</source>
        <translation>Hang rögzítése</translation>
    </message>
    <message>
        <location line="246" filename="../GUI/PageInput.cpp"/>
        <source>Backend:</source>
        <translation>Háttérprogram:</translation>
    </message>
    <message>
        <location line="255" filename="../GUI/PageInput.cpp"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>A hang háttérprogram, amely használva lesz a rögzítésnél.
Az ALSA háttérprogram is működni fog azokon a rendszereken, amelyek PulseAudio háttérprogramot használnak, de jobb közvetlenül a PulseAudio háttérprogram használata.</translation>
    </message>
    <message>
        <location line="257" filename="../GUI/PageInput.cpp"/>
        <location line="265" filename="../GUI/PageInput.cpp"/>
        <source>Source:</source>
        <translation>Forrás:</translation>
    </message>
    <message>
        <location line="260" filename="../GUI/PageInput.cpp"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The 'shared' sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Az ALSA forrás, amely használva lesz a rögzítésnél.
Az alapértelmezés általában megfelelő. Az „osztott” források lehetővé teszik több programnak is az egyidejű rögzítést, de ezek kevésbé megbízhatóak lehetnek.</translation>
    </message>
    <message>
        <location line="262" filename="../GUI/PageInput.cpp"/>
        <location line="270" filename="../GUI/PageInput.cpp"/>
        <source>Refresh</source>
        <translation>Frissítés</translation>
    </message>
    <message>
        <location line="263" filename="../GUI/PageInput.cpp"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Frissíti az ALSA források listáját.</translation>
    </message>
    <message>
        <location line="268" filename="../GUI/PageInput.cpp"/>
        <source>The PulseAudio source that will be used for recording.
A 'monitor' is a source that records the audio played by other applications.</source>
        <comment>Don't translate 'monitor' unless PulseAudio does this as well</comment>
        <translation>A PulseAudio forrás, amely használva lesz a rögzítésnél.
A „monitor” egy olyan forrás, amely a más alkalmazások által lejátszott hangot rögzíti.</translation>
    </message>
    <message>
        <location line="271" filename="../GUI/PageInput.cpp"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Frissíti a PulseAudio források listáját.</translation>
    </message>
    <message>
        <location line="274" filename="../GUI/PageInput.cpp"/>
        <source>Record system microphone</source>
        <translation>Rendszer mikrofon rögzítése</translation>
    </message>
    <message>
        <location line="275" filename="../GUI/PageInput.cpp"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Ha be van jelölve, akkor a portok automatikusan csatlakoztatva lesznek a rendszer rögzítési portjaihoz.</translation>
    </message>
    <message>
        <location line="276" filename="../GUI/PageInput.cpp"/>
        <source>Record system speakers</source>
        <translation>Rendszer hangszórók rögzítése</translation>
    </message>
    <message>
        <location line="277" filename="../GUI/PageInput.cpp"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Ha be van jelölve, akkor a portok automatikusan csatlakoztatva lesznek bármihez, ami a rendszer lejátszási portjaihoz kapcsolódik.</translation>
    </message>
    <message>
        <location line="312" filename="../GUI/PageInput.cpp"/>
        <source>Back</source>
        <translation>Vissza</translation>
    </message>
    <message>
        <location line="313" filename="../GUI/PageInput.cpp"/>
        <source>Continue</source>
        <translation>Folytatás</translation>
    </message>
    <message>
        <location line="673" filename="../GUI/PageInput.cpp"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Minden kijelző: %1x%2</translation>
    </message>
    <message>
        <location line="677" filename="../GUI/PageInput.cpp"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>%1. kijelző: %2x%3, kezdés: %4,%5</translation>
    </message>
    <message>
        <location line="839" filename="../GUI/PageInput.cpp"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>%1. kijelző</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location line="82" filename="../GUI/PageOutput.cpp"/>
        <location line="85" filename="../GUI/PageOutput.cpp"/>
        <location line="88" filename="../GUI/PageOutput.cpp"/>
        <location line="91" filename="../GUI/PageOutput.cpp"/>
        <location line="127" filename="../GUI/PageOutput.cpp"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. 'MP4 files'</comment>
        <translation>%1 fájlok</translation>
    </message>
    <message>
        <location line="94" filename="../GUI/PageOutput.cpp"/>
        <location line="100" filename="../GUI/PageOutput.cpp"/>
        <location line="107" filename="../GUI/PageOutput.cpp"/>
        <source>Other...</source>
        <translation>Egyéb…</translation>
    </message>
    <message>
        <location line="106" filename="../GUI/PageOutput.cpp"/>
        <source>Uncompressed</source>
        <translation>Tömörítetlen</translation>
    </message>
    <message>
        <location line="161" filename="../GUI/PageOutput.cpp"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Hiba: nem sikerült találni semmilyen alkalmas konténert a libavformat programkönyvtárban!</translation>
    </message>
    <message>
        <location line="165" filename="../GUI/PageOutput.cpp"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Hiba: nem sikerült találni semmilyen alkalmas videokodeket a libavcodec programkönyvtárban!</translation>
    </message>
    <message>
        <location line="169" filename="../GUI/PageOutput.cpp"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Hiba: nem sikerült találni semmilyen alkalmas hangkodeket a libavcodec programkönyvtárban!</translation>
    </message>
    <message>
        <location line="175" filename="../GUI/PageOutput.cpp"/>
        <source>File</source>
        <translation>Fájl</translation>
    </message>
    <message>
        <location line="177" filename="../GUI/PageOutput.cpp"/>
        <source>Save as:</source>
        <translation>Mentés másként:</translation>
    </message>
    <message>
        <location line="179" filename="../GUI/PageOutput.cpp"/>
        <source>The recording will be saved to this location.</source>
        <translation>A felvétel erre a helyre lesz elmentve.</translation>
    </message>
    <message>
        <location line="180" filename="../GUI/PageOutput.cpp"/>
        <source>Browse...</source>
        <translation>Tallózás…</translation>
    </message>
    <message>
        <location line="181" filename="../GUI/PageOutput.cpp"/>
        <source>Separate file per segment</source>
        <translation>Fájl szétválasztása szakaszonként</translation>
    </message>
    <message>
        <location line="182" filename="../GUI/PageOutput.cpp"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is 'test.mkv', the segments will be saved as 'test-YYYY-MM-DD_HH.MM.SS.mkv'.</source>
        <translation>Ha be van jelölve, akkor különálló videofájl lesz létrehozva minden alkalommal, amikor szünetelteti és folytatja a rögzítést. Ha az eredeti fájlnév „próba.mkv”, akkor a szakaszok „próba-ÉÉÉÉ-HH-NN_ÓÓ.PP.MM.mkv” néven lesznek elmentve.</translation>
    </message>
    <message>
        <location line="184" filename="../GUI/PageOutput.cpp"/>
        <source>Container:</source>
        <translation>Konténer:</translation>
    </message>
    <message>
        <location line="192" filename="../GUI/PageOutput.cpp"/>
        <source>The container (file format) that will be used to save the recording.
Note that not all codecs are supported by all containers, and that not all media players can read all file formats.
- Matroska (MKV) supports all the codecs, but is less well-known.
- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video
   (and many media players only support AAC audio).
- WebM is intended for embedding video into websites (with the HTML5 &lt;video> tag). The format was created by Google.
   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.
   It supports only VP8 and Vorbis.
- OGG supports only Theora and Vorbis.</source>
        <translation>A konténer (fájlformátum), amely a felvétel mentéséhez lesz használva.
Vegye figyelembe, hogy nem minden konténer támogat minden kodeket, és hogy nem minden médialejátszó képes beolvasni minden fájlformátumot.
- Matroska (MKV): minden kodeket támogat, de kevésbé ismert.
- MP4: a legismertebb formátum és szinte minden modern médialejátszó le fogja játszani, de csak H.264 videót támogat
   (és a legtöbb lejátszó csak az AAC hangot támogatja).
- WebM: weboldalakba ágyazott videóhoz készítették (a HTML5-ös &lt;video> címkével). A formátumot a Google hozta létre.
   A WebM formátumot alapértelmezetten támogatja a Firefox, a Chrome és az Opera, illetve bővítmények érhetők el az Internet Explorer és a Safari böngészőkhöz.
   Csak VP8 és Vorbis kodekeket támogat.
- OGG: csak Theora és Vorbis kodekeket támogat.</translation>
    </message>
    <message>
        <location line="201" filename="../GUI/PageOutput.cpp"/>
        <source>Container name:</source>
        <translation>Konténer neve:</translation>
    </message>
    <message>
        <location line="207" filename="../GUI/PageOutput.cpp"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Tapasztalt felhasználóknak. Bármilyen libav/ffmpeg formátumot használhat, de számos ezek közül nem hasznos, vagy esetleg nem működik.</translation>
    </message>
    <message>
        <location line="223" filename="../GUI/PageOutput.cpp"/>
        <source>Video</source>
        <translation>Videó</translation>
    </message>
    <message>
        <location line="225" filename="../GUI/PageOutput.cpp"/>
        <location line="305" filename="../GUI/PageOutput.cpp"/>
        <source>Codec:</source>
        <translation>Kodek:</translation>
    </message>
    <message>
        <location line="230" filename="../GUI/PageOutput.cpp"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn't really recommended because the quality isn't very good.</source>
        <translation>A kodek, amely a videó adatfolyam tömörítéséhez lesz használva.
- H.264 (libx264): kiemelkedően a legjobb kodek - kiváló minőségű és nagyon gyors.
- VP8 (libvpx): elég jó, de meglehetősen lassú.
- Theora (libtheora): nem igazán ajánlott, mert a minősége nem túl jó.</translation>
    </message>
    <message>
        <location line="234" filename="../GUI/PageOutput.cpp"/>
        <location line="318" filename="../GUI/PageOutput.cpp"/>
        <source>Codec name:</source>
        <translation>Kodek neve:</translation>
    </message>
    <message>
        <location line="240" filename="../GUI/PageOutput.cpp"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Tapasztalt felhasználóknak. Bármilyen libav/ffmpeg videokodeket használhat, de számos ezek közül nem hasznos, vagy esetleg nem működik.</translation>
    </message>
    <message>
        <location line="241" filename="../GUI/PageOutput.cpp"/>
        <location line="325" filename="../GUI/PageOutput.cpp"/>
        <source>Bit rate (in kbps):</source>
        <translation>Bitsebesség (kbps):</translation>
    </message>
    <message>
        <location line="243" filename="../GUI/PageOutput.cpp"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>A videó bitsebessége (kilobit per másodpercben). A magasabb érték jobb minőséget jelent.
Ha nincs ötlete, hogy merre induljon, akkor próbáljon meg 5000-et, és változtassa meg, ha szükséges.</translation>
    </message>
    <message>
        <location line="245" filename="../GUI/PageOutput.cpp"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don't translate this unless you can come up with something sensible</comment>
        <translation>Állandó sebességtényező:</translation>
    </message>
    <message>
        <location line="250" filename="../GUI/PageOutput.cpp"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Ez a beállítás megváltoztatja a videó minőségét. Az alacsonyabb érték jobb minőséget jelent.
A megengedett tartomány 0-51 között van (a 0 jelenti a veszteségmentest, az alapértelmezett 23).</translation>
    </message>
    <message>
        <location line="256" filename="../GUI/PageOutput.cpp"/>
        <source>Preset:</source>
        <comment>libx264 setting: don't translate this unless you can come up with something sensible</comment>
        <translation>Alapbeállítás:</translation>
    </message>
    <message>
        <location line="261" filename="../GUI/PageOutput.cpp"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn't be affected too much.</source>
        <translation>A kódolás sebessége. A nagyobb sebesség kevesebb processzort használ (magasabb rögzítési képkockasebességeket lehetővé téve), de nagyobb fájlokat eredményez. A minőséget nem érintheti túl nagy mértékben.</translation>
    </message>
    <message>
        <location line="263" filename="../GUI/PageOutput.cpp"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don't translate this unless you can come up with something sensible</comment>
        <translation>Használt processzor:</translation>
    </message>
    <message>
        <location line="265" filename="../GUI/PageOutput.cpp"/>
        <source>fastest</source>
        <translation>leggyorsabb</translation>
    </message>
    <message>
        <location line="270" filename="../GUI/PageOutput.cpp"/>
        <source>slowest</source>
        <translation>leglassabb</translation>
    </message>
    <message>
        <location line="271" filename="../GUI/PageOutput.cpp"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn't choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>A kódolás sebessége. A magasabb érték *kevesebb* processzoridőt használ. (Nem én választottam ki a nevet, ez a VP8 kódoló által használt név). A magasabb értékek alacsonyabb minőségű videót eredményeznek, hacsak nem növeli meg a bitsebességet is.</translation>
    </message>
    <message>
        <location line="273" filename="../GUI/PageOutput.cpp"/>
        <location line="328" filename="../GUI/PageOutput.cpp"/>
        <source>Custom options:</source>
        <translation>Egyéni beállítások:</translation>
    </message>
    <message>
        <location line="275" filename="../GUI/PageOutput.cpp"/>
        <location line="330" filename="../GUI/PageOutput.cpp"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Egyéni kodekbeállítások vesszővel elválasztva (például beállítás1=érték1,beállítás2=érték2,beállítás3=érték3).</translation>
    </message>
    <message>
        <location line="276" filename="../GUI/PageOutput.cpp"/>
        <source>Allow frame skipping</source>
        <translation>Képkockák kihagyásának engedélyezése</translation>
    </message>
    <message>
        <location line="277" filename="../GUI/PageOutput.cpp"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn't affect the appearance of the video.</source>
        <translation>Ha be van jelölve, akkor a videokódolónak engedélyezett lesz a képkockák kihagyása, ha a bemenet képkockasebessége alacsonyabb a kimenet képkockasebességénél. Ha nincs bejelölve, akkor a bemeneti képkockák kettőzve lesznek a lyukak kitöltéséhez.
Ez növeli a fájlméretet és a processzorhasználatot, de néhány esetben csökkenti a késleltetést az élő adatfolyamoknál.
Nem kellene érintenie a videó megjelenését.</translation>
    </message>
    <message>
        <location line="303" filename="../GUI/PageOutput.cpp"/>
        <source>Audio</source>
        <translation>Hang</translation>
    </message>
    <message>
        <location line="310" filename="../GUI/PageOutput.cpp"/>
        <source>The codec that will be used to compress the audio stream. You shouldn't worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you're only recording your own voice (i.e. no music), the quality won't matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it's very fast.</source>
        <translation>A kodek, amely a hang adatfolyam tömörítéséhez lesz használva. Nem kell túlságosan aggódnia emiatt, mert a hangadat mérete általában elhanyagolható a videoadat méretéhez viszonyítva.
És ha csak a saját hangját rögzíti (azaz nem zenét), akkor a minőség nem igazán számít egyébként.
- Vorbis (libvorbis): nagyszerű, ez az ajánlott kodek.
- MP3 (libmp3lame): meglehetősen jó.
- AAC: egy jó kodek, de az itt használt megvalósítása (libvo_aacenc vagy a kísérleti ffmpeg aac kódoló)
   elég rossz. Csak akkor használja, ha nincs más választása.
- Tömörítetlen: egyszerűen tömörítés nélkül fogja tárolni a hangadatokat. A fájl meglehetősen nagy lesz, de nagyon gyors.</translation>
    </message>
    <message>
        <location line="324" filename="../GUI/PageOutput.cpp"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Tapasztalt felhasználóknak. Bármilyen libav/ffmpeg hangkodeket használhat, de számos ezek közül nem hasznos, vagy esetleg nem működik.</translation>
    </message>
    <message>
        <location line="327" filename="../GUI/PageOutput.cpp"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>A hang bitsebessége (kilobit per másodpercben). A magasabb érték jobb minőséget jelent. A jellemző érték 128.</translation>
    </message>
    <message>
        <location line="344" filename="../GUI/PageOutput.cpp"/>
        <source>Back</source>
        <translation>Vissza</translation>
    </message>
    <message>
        <location line="345" filename="../GUI/PageOutput.cpp"/>
        <source>Continue</source>
        <translation>Folytatás</translation>
    </message>
    <message>
        <location line="564" filename="../GUI/PageOutput.cpp"/>
        <location line="572" filename="../GUI/PageOutput.cpp"/>
        <source>not installed</source>
        <translation>nincs telepítve</translation>
    </message>
    <message>
        <location line="566" filename="../GUI/PageOutput.cpp"/>
        <location line="574" filename="../GUI/PageOutput.cpp"/>
        <source>not supported by container</source>
        <translation>nem támogatja a konténer</translation>
    </message>
    <message>
        <location line="617" filename="../GUI/PageOutput.cpp"/>
        <source>Save recording as</source>
        <translation>Felvétel mentése másként</translation>
    </message>
    <message>
        <location line="657" filename="../GUI/PageOutput.cpp"/>
        <source>You did not select an output file!</source>
        <translation>Nem választott kimeneti fájlt!</translation>
    </message>
    <message>
        <location line="662" filename="../GUI/PageOutput.cpp"/>
        <source>The file '%1' already exists. Are you sure that you want to overwrite it?</source>
        <translation>A(z) „%1” fájl már létezik. Biztosan felül akarja írni?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location line="146" filename="../GUI/PageRecord.cpp"/>
        <source>Recording</source>
        <translation>Felvétel</translation>
    </message>
    <message>
        <location line="150" filename="../GUI/PageRecord.cpp"/>
        <source>Enable recording hotkey</source>
        <translation>Felvétel gyorsbillentyű engedélyezése</translation>
    </message>
    <message>
        <location line="151" filename="../GUI/PageRecord.cpp"/>
        <source>Enable sound notifications</source>
        <translation>Hangértesítések engedélyezése</translation>
    </message>
    <message>
        <location line="152" filename="../GUI/PageRecord.cpp"/>
        <source>Hotkey:</source>
        <translation>Gyorsbillentyű:</translation>
    </message>
    <message>
        <location line="153" filename="../GUI/PageRecord.cpp"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <location line="154" filename="../GUI/PageRecord.cpp"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location line="155" filename="../GUI/PageRecord.cpp"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location line="156" filename="../GUI/PageRecord.cpp"/>
        <source>Super +</source>
        <translation>Szuper +</translation>
    </message>
    <message>
        <location line="158" filename="../GUI/PageRecord.cpp"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>Az a billentyű, amelyet meg kell nyomnia (a megadott módosítókkal együtt) a felvétel indításához vagy szüneteltetéséhez. A program, amelyet éppen rögzít, nem fogja megkapni a billentyűlenyomást.</translation>
    </message>
    <message>
        <location line="198" filename="../GUI/PageRecord.cpp"/>
        <source>Information</source>
        <translation>Információk</translation>
    </message>
    <message>
        <location line="200" filename="../GUI/PageRecord.cpp"/>
        <source>Total time:</source>
        <translation>Teljes idő:</translation>
    </message>
    <message>
        <location line="202" filename="../GUI/PageRecord.cpp"/>
        <source>FPS in:</source>
        <translation>FPS (be):</translation>
    </message>
    <message>
        <location line="204" filename="../GUI/PageRecord.cpp"/>
        <source>FPS out:</source>
        <translation>FPS (ki):</translation>
    </message>
    <message>
        <location line="206" filename="../GUI/PageRecord.cpp"/>
        <source>Size in:</source>
        <translation>Méret (be):</translation>
    </message>
    <message>
        <location line="208" filename="../GUI/PageRecord.cpp"/>
        <source>Size out:</source>
        <translation>Méret (ki):</translation>
    </message>
    <message>
        <location line="210" filename="../GUI/PageRecord.cpp"/>
        <source>File name:</source>
        <translation>Fájlnév:</translation>
    </message>
    <message>
        <location line="213" filename="../GUI/PageRecord.cpp"/>
        <source>File size:</source>
        <translation>Fájlméret:</translation>
    </message>
    <message>
        <location line="215" filename="../GUI/PageRecord.cpp"/>
        <source>Bit rate:</source>
        <translation>Bitsebesség:</translation>
    </message>
    <message>
        <location line="238" filename="../GUI/PageRecord.cpp"/>
        <source>Preview</source>
        <translation>Előnézet</translation>
    </message>
    <message>
        <location line="242" filename="../GUI/PageRecord.cpp"/>
        <source>Preview frame rate:</source>
        <translation>Előnézet képkockasebessége:</translation>
    </message>
    <message>
        <location line="246" filename="../GUI/PageRecord.cpp"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Megjegyzés: Az előnézet további processzoridőt igényel (különösen magas képkockasebességeknél).</translation>
    </message>
    <message>
        <location line="295" filename="../GUI/PageRecord.cpp"/>
        <source>Log</source>
        <translation>Napló</translation>
    </message>
    <message>
        <location line="310" filename="../GUI/PageRecord.cpp"/>
        <location line="318" filename="../GUI/PageRecord.cpp"/>
        <source>Cancel recording</source>
        <translation>Felvétel megszakítása</translation>
    </message>
    <message>
        <location line="311" filename="../GUI/PageRecord.cpp"/>
        <location line="320" filename="../GUI/PageRecord.cpp"/>
        <source>Save recording</source>
        <translation>Felvétel mentése</translation>
    </message>
    <message>
        <location line="325" filename="../GUI/PageRecord.cpp"/>
        <source>Quit</source>
        <translation>Kilépés</translation>
    </message>
    <message>
        <location line="368" filename="../GUI/PageRecord.cpp"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Még nem mentette el a jelenlegi felvételt. Ha most kilép, akkor az el fog veszni.
Biztosan ki akar lépni?</translation>
    </message>
    <message>
        <location line="380" filename="../GUI/PageRecord.cpp"/>
        <source>Hide window</source>
        <translation>Ablak elrejtése</translation>
    </message>
    <message>
        <location line="382" filename="../GUI/PageRecord.cpp"/>
        <source>Show window</source>
        <translation>Ablak megjelenítése</translation>
    </message>
    <message>
        <location line="535" filename="../GUI/PageRecord.cpp"/>
        <source>Starting page ...</source>
        <translation>Oldal indítása…</translation>
    </message>
    <message>
        <location line="556" filename="../GUI/PageRecord.cpp"/>
        <location line="698" filename="../GUI/PageRecord.cpp"/>
        <location line="783" filename="../GUI/PageRecord.cpp"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Hiba: valami elromlott az előkészítés közben.</translation>
    </message>
    <message>
        <location line="563" filename="../GUI/PageRecord.cpp"/>
        <source>Started page.</source>
        <translation>Oldal elindítva.</translation>
    </message>
    <message>
        <location line="587" filename="../GUI/PageRecord.cpp"/>
        <source>Stopping page ...</source>
        <translation>Oldal leállása…</translation>
    </message>
    <message>
        <location line="830" filename="../GUI/PageRecord.cpp"/>
        <source>Encoding remaining data ...</source>
        <translation>Hátralévő adatok kódolása…</translation>
    </message>
    <message>
        <location line="612" filename="../GUI/PageRecord.cpp"/>
        <source>Stopped page.</source>
        <translation>Oldal leállítva.</translation>
    </message>
    <message>
        <location line="637" filename="../GUI/PageRecord.cpp"/>
        <source>Starting output ...</source>
        <translation>Kimenet indítása…</translation>
    </message>
    <message>
        <location line="648" filename="../GUI/PageRecord.cpp"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Hiba: nem sikerült lekérni az OpenGL alkalmazás méretét, mert a GLInject bemenet nem lett létrehozva.</translation>
    </message>
    <message>
        <location line="653" filename="../GUI/PageRecord.cpp"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn't started correctly, or the application hasn't created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Hiba: nem sikerült lekérni az OpenGL alkalmazás méretét. Vagy az alkalmazás nem lett helyesen elindítva, vagy az alkalmazás még nem hozott létre OpenGL ablakot. Ha el szeretné indítani a rögzítést az alkalmazás indítása előtt, akkor engedélyeznie kell a méretezést, és kézzel kell megadnia a videó méretét.</translation>
    </message>
    <message>
        <location line="689" filename="../GUI/PageRecord.cpp"/>
        <source>Started output.</source>
        <translation>Kimenet elindítva.</translation>
    </message>
    <message>
        <location line="709" filename="../GUI/PageRecord.cpp"/>
        <source>Stopping output ...</source>
        <translation>Kimenet leállása…</translation>
    </message>
    <message>
        <location line="727" filename="../GUI/PageRecord.cpp"/>
        <source>Stopped output.</source>
        <translation>Kimenet leállítva.</translation>
    </message>
    <message>
        <location line="754" filename="../GUI/PageRecord.cpp"/>
        <source>Starting input ...</source>
        <translation>Bemenet indítása…</translation>
    </message>
    <message>
        <location line="759" filename="../GUI/PageRecord.cpp"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Hiba: nem sikerült elindítani a GLInject bemenetet, mert az nem lett létrehozva.</translation>
    </message>
    <message>
        <location line="778" filename="../GUI/PageRecord.cpp"/>
        <source>Started input.</source>
        <translation>Bemenet elindítva.</translation>
    </message>
    <message>
        <location line="803" filename="../GUI/PageRecord.cpp"/>
        <source>Stopping input ...</source>
        <translation>Bemenet leállítása…</translation>
    </message>
    <message>
        <location line="814" filename="../GUI/PageRecord.cpp"/>
        <source>Stopped input.</source>
        <translation>Bemenet leállítva.</translation>
    </message>
    <message>
        <location line="901" filename="../GUI/PageRecord.cpp"/>
        <location line="912" filename="../GUI/PageRecord.cpp"/>
        <source>Pause recording</source>
        <translation>Felvétel szüneteltetése</translation>
    </message>
    <message>
        <location line="905" filename="../GUI/PageRecord.cpp"/>
        <location line="915" filename="../GUI/PageRecord.cpp"/>
        <source>Start recording</source>
        <translation>Felvétel indítása</translation>
    </message>
    <message>
        <location line="923" filename="../GUI/PageRecord.cpp"/>
        <source>Stop preview</source>
        <translation>Előnézet leállítása</translation>
    </message>
    <message>
        <location line="926" filename="../GUI/PageRecord.cpp"/>
        <source>Start preview</source>
        <translation>Előnézet indítása</translation>
    </message>
    <message>
        <location line="955" filename="../GUI/PageRecord.cpp"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Hiba: valami elromlott a szintetizátor létrehozásakor.</translation>
    </message>
    <message>
        <location line="995" filename="../GUI/PageRecord.cpp"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Biztosan meg akarja szakítani ezt a felvételt?</translation>
    </message>
    <message>
        <location line="1010" filename="../GUI/PageRecord.cpp"/>
        <source>You haven't recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>Nem rögzített semmit, nincs mit menteni.

A kezdés gomb felül van ;).</translation>
    </message>
</context>
<context>
    <name>PageWelcome</name>
    <message>
        <location line="34" filename="../GUI/PageWelcome.cpp"/>
        <source>&lt;p>Welcome to SimpleScreenRecorder!&lt;/p>

&lt;p>Despite the name, this program actually has a lot of options. Don't worry though, there are really just two things that you need to know. One, the default settings are usually fine. If you don't know what something does, just use the default. Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.&lt;/p>

&lt;p>For more information:&lt;br>
%1&lt;/p></source>
        <translation>&lt;p>Üdvözli a SimpleScreenRecorder!&lt;/p>

&lt;p>Senkit se tévesszen meg az elnevezés, a program igenis sok beállítási lehetőséggel rendelkezik. Ne aggódjon, csupán két dologra kell odafigyelnie. Először is az alapértelmezett beállítások általában megfelelőek. Ha valamiről nem tudja, hogy mire való, akkor egyszerűen csak használja az alapértelmezett beállításokat. Másodszor pedig a legtöbb beállításhoz tartozik súgóinformáció. Ezek megtekintéséhez csak húzza az adott beállítás fölé az egérkurzort.&lt;/p>

&lt;p>További információk:&lt;br>
%1&lt;/p></translation>
    </message>
    <message>
        <location line="44" filename="../GUI/PageWelcome.cpp"/>
        <source>About SimpleScreenRecorder</source>
        <translation>A SimpleScreenRecorder névjegye</translation>
    </message>
    <message>
        <location line="45" filename="../GUI/PageWelcome.cpp"/>
        <source>Continue</source>
        <translation>Folytatás</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location line="28" filename="../GUI/ProfileBox.cpp"/>
        <source>Profile</source>
        <translation>Profil</translation>
    </message>
    <message>
        <location line="37" filename="../GUI/ProfileBox.cpp"/>
        <source>Save</source>
        <translation>Mentés</translation>
    </message>
    <message>
        <location line="38" filename="../GUI/ProfileBox.cpp"/>
        <source>Save the current settings to this profile.</source>
        <translation>A jelenlegi beállítások mentése ebbe a profilba.</translation>
    </message>
    <message>
        <location line="39" filename="../GUI/ProfileBox.cpp"/>
        <source>New</source>
        <translation>Új</translation>
    </message>
    <message>
        <location line="40" filename="../GUI/ProfileBox.cpp"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Új profil létrehozása a jelenlegi beállításokkal.</translation>
    </message>
    <message>
        <location line="41" filename="../GUI/ProfileBox.cpp"/>
        <source>Delete</source>
        <translation>Törlés</translation>
    </message>
    <message>
        <location line="42" filename="../GUI/ProfileBox.cpp"/>
        <source>Delete this profile.</source>
        <translation>A profil törlése.</translation>
    </message>
    <message>
        <location line="96" filename="../GUI/ProfileBox.cpp"/>
        <source>(none)</source>
        <translation>(nincs)</translation>
    </message>
    <message>
        <location line="139" filename="../GUI/ProfileBox.cpp"/>
        <source>Error: Can't load profile!</source>
        <translation>Hiba: nem lehet betölteni a profilt!</translation>
    </message>
    <message>
        <location line="147" filename="../GUI/ProfileBox.cpp"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Biztosan felül akarja írni ezt a profilt?</translation>
    </message>
    <message>
        <location line="159" filename="../GUI/ProfileBox.cpp"/>
        <source>Enter a name for the new profile:</source>
        <translation>Adjon egy nevet az új profilnak:</translation>
    </message>
    <message>
        <location line="165" filename="../GUI/ProfileBox.cpp"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Már létezik egy ilyen nevű profil. Biztosan le akarja cserélni?</translation>
    </message>
    <message>
        <location line="181" filename="../GUI/ProfileBox.cpp"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Biztosan törölni akarja ezt a profilt?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location line="35" filename="../common/Dialogs.cpp"/>
        <location line="72" filename="../common/Dialogs.cpp"/>
        <source>&amp;OK</source>
        <translation>&amp;OK</translation>
    </message>
    <message>
        <location line="36" filename="../common/Dialogs.cpp"/>
        <location line="73" filename="../common/Dialogs.cpp"/>
        <source>&amp;Cancel</source>
        <translation>&amp;Mégse</translation>
    </message>
    <message>
        <location line="37" filename="../common/Dialogs.cpp"/>
        <source>&amp;Yes</source>
        <translation>&amp;Igen</translation>
    </message>
    <message>
        <location line="38" filename="../common/Dialogs.cpp"/>
        <source>Yes, always</source>
        <translation>Igen, mindig</translation>
    </message>
    <message>
        <location line="39" filename="../common/Dialogs.cpp"/>
        <source>&amp;No</source>
        <translation>&amp;Nem</translation>
    </message>
    <message>
        <location line="40" filename="../common/Dialogs.cpp"/>
        <source>No, never</source>
        <translation>Nem, soha</translation>
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
        <translation type="obsolete">&amp;Mégse</translation>
    </message>
    <message>
        <source>&amp;Yes</source>
        <translation type="obsolete">&amp;Igen</translation>
    </message>
    <message>
        <source>Yes, always</source>
        <translation type="obsolete">Igen, mindig</translation>
    </message>
    <message>
        <source>&amp;No</source>
        <translation type="obsolete">&amp;Nem</translation>
    </message>
    <message>
        <source>No, never</source>
        <translation type="obsolete">Nem, soha</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location line="50" filename="../AV/Output/SyncDiagram.cpp"/>
        <source>Synchronization Diagram</source>
        <translation>Szinkronizációs diagram</translation>
    </message>
    <message>
        <location line="251" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Video in</source>
        <translation>Videobemenet</translation>
    </message>
    <message>
        <location line="252" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Audio in</source>
        <translation>Hangbemenet</translation>
    </message>
    <message>
        <location line="253" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Video out</source>
        <translation>Videokimenet</translation>
    </message>
    <message>
        <location line="254" filename="../AV/Output/Synchronizer.cpp"/>
        <source>Audio out</source>
        <translation>Hangkimenet</translation>
    </message>
</context>
</TS>
