<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="sk_SK">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>About SimpleScreenRecorder</source>
        <translation>O programe SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="120"/>
        <source>For more information:</source>
        <translation>Pre viac informácií:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="121"/>
        <source>The source code of this program can be found at:</source>
        <translation>Zdrojový kód tohto programu nájdete na:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="122"/>
        <source>This program uses:</source>
        <translation>Tento program používa:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="123"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 ako grafické používateľské rozhranie</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="124"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 alebo %2 pre spracovanie videa/zvuku (podľa Vašej distribúcie)</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="125"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 na napojenie na systémové funkcie pre nahrávanie OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="35"/>
        <source>OpenGL Settings</source>
        <translation>Nastavenia OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="38"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Upozornenie: Nahrávanie OpenGL pracuje na princípu &quot;injektáže&quot; knižnice do nahrávanej aplikácie . Táto knižnica nahrádza niektoré systémové funkcie vlastnými za účelom zachytenia snímky ešte pred jej zobrazením na obrazovke. Ak nahrávate hru, ktorá obsahuje funkcie pre detekciu podvádzania (anti-cheat a anti-hack ochrana), je tu (teoretické) riziko, že hra toto vyhodnotí ako podvádzanie. Vzhľadom na to, že by takáto skutočnosť mohla viesť až k zablokovaniu vášho herného účtu, je dobré sa *vopred* uistiť, že k ničomu takému nedôjde. Každopádne, varovali sme Vás :-).&lt;/p&gt;

&lt;p&gt;Ďalšie upozornenie: Nahrávanie OpenGL je experimentálne a nemusí fungovať správne, prípadne môže viesť až k pádu nahrávanej aplikácie. Ak sa bojíte prípadnej straty údajov, včas a pravidelne zálohujte!&lt;/p&gt;

&lt;p&gt;Ak chcete nahrávať hry zo Steamu, prečítajte si, prosím &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;tento návod&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="52"/>
        <source>Choose channel</source>
        <translation>Výber kanála</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="54"/>
        <source>Channel name:</source>
        <translation>Názov kanála:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="56"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Názvy kanálov sa používajú na identifikáciu aplikácií. Potrebujete ich iba vtedy, ak sa chystáte nahrávať viacero aplikácií s rovnakým názvom.
Ak toto nastavenie ponecháte prázdne, použije sa predvolený názov &apos;kanál-MENOVÁŠHOPOUŽÍVATEĽA&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Znížiť zabezpečenie prístupu ku zdieľanej pamäti (rizikové)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Ak je táto možnosť aktivovaná, bude iným používateľom na tomto počítači umožnený prístup ku zdieľanej pamäti, ktorá je použitá na komunikáciu s OpenGL aplikáciou.
To znamená, že iní používatelia môžu (teoreticky) čítať, upravovať alebo narušiť komunikáciu s programom.
To platí aj pre vzdialene pripojených používateľov (ssh). Tuto možnosť použite iba v prípade, že chcete nahrávať program bežiaci s oprávneniami iného používateľa.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="74"/>
        <source>Launch application</source>
        <translation>Spustenie aplikácie</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="76"/>
        <source>Command:</source>
        <translation>Príkaz:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="78"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Tento príkaz bude použitý na spustenie programu, ktorý má byť nahrávaný.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="80"/>
        <source>Working directory:</source>
        <translation>Pracovný adresár:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="82"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Príkaz bude spustený vo vybranom adresári. Ak necháte toto pole prázdne, pracovný adresár sa nezmení.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>Launch automatically</source>
        <translation>Spustiť automaticky</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="85"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Ak je táto možnosť aktivovaná, aplikácia bude spustená automaticky pred spustením nahrávania. V opačnom prípade spustite aplikáciu ručne.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="87"/>
        <source>Launch now</source>
        <translation>Spustiť teraz</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="108"/>
        <source>Stream settings</source>
        <translation>Nastavenia streamu</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>Limit application frame rate</source>
        <translation>Obmedziť počet snímok za sekundu v aplikácii</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="111"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Ak je táto možnosť aktivovaná, dôjde k zníženiu počtu snímok za sekundu v aplikácii na úroveň frekvencie snímok nahrávania.
Tým sa dá zabrániť plytvaniu procesorového času na snímky, ktoré aj tak nebudú nahrané a v niektorých prípadoch tým dosiahnete plynulejší záznam.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="120"/>
        <source>Close</source>
        <translation>Zavrieť</translation>
    </message>
</context>
<context>
    <name>DialogRecordSchedule</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="78"/>
        <source>Recording schedule</source>
        <translation>Plán nahrávania</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="80"/>
        <source>Time zone:</source>
        <translation>Časová zóna:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="82"/>
        <source>Local time</source>
        <translation>Miestny čas</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="83"/>
        <source>UTC</source>
        <translation>UTC</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="85"/>
        <source>Current time:</source>
        <translation>Aktuálny čas:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="102"/>
        <source>Add</source>
        <translation>Pridať</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="103"/>
        <source>Remove</source>
        <translation>Odstrániť</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="104"/>
        <source>Move up</source>
        <translation>Presunúť vyššie</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="105"/>
        <source>Move down</source>
        <translation>Presunúť nižšie</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="107"/>
        <source>Close</source>
        <translation>Zavrieť</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Chyba: Pomer prevzorkovania je mimo rozsahu!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Chyba: Pomer posunu je mimo rozsahu!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Pomer prevzorkovania je %1 (bol %2).</translation>
    </message>
    <message>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="obsolete">Upozornenie: Formát pixelov nie je podporovaný (%1 -&gt; %2), miesto neho sa používa swscale. Nejedná sa o problém, ale zníži sa výkon.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="129"/>
        <source>Warning: No fast pixel format conversion available (%1,%2 -&gt; %3,%4), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Upozornenie: Nie je dostupná žiadna rýchla metóda konverzie pixelov (%1, %2 -&gt; %3, %4), použije sa swscale. Nejedná sa o problém, ale zníži sa výkon.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="138"/>
        <location filename="../Benchmark.cpp" line="124"/>
        <location filename="../Benchmark.cpp" line="205"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Chyba: Nie je možné získať &apos;swscale&apos; kontext!</translation>
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
        <translation>Upozornenie: Pamäť nie je správne zarovnaná pre SSE, bude použitý záložný konvertor. Nejedná sa o problém, ale zníži sa výkon.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Upozornenie: Došlo k pretečeniu (overrun), niektoré snímky boli zahodené.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="37"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Chyba: Nepodarilo sa obnoviť zariadenie po pretečení (overrun)!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="41"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Chyba: Nepodarilo sa naštartovať zariadenie PCM po pretečení (overrun)!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="71"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="59"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="66"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation>Zastavuje sa vstupné vlákno...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="102"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation>Generuje sa zoznam zdrojov...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="121"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Chyba: Nepodarilo sa aktualizovať konfiguráciu ALSA!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="168"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Nájdený plugin: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Upozornenie: Nepodarilo sa otvoriť zvukovú kartu %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="187"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Upozornenie: Nepodarilo sa získať informácie o zvukovej karte %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="191"/>
        <source>Found card: [%1] %2</source>
        <translation>Nájdená karta: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="216"/>
        <source>Found device: [%1] %2</source>
        <translation>Nájdené zariadenie: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="271"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Chyba: Nepodarilo sa otvoriť zariadenie PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Chyba: Nepodarilo sa získať hardvérové parametre PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="281"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Chyba: Nepodarilo sa nastaviť typ prístupu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="292"/>
        <source>Error: Can&apos;t set sample format mask!</source>
        <translation>Chyba: Nepodarilo sa nastaviť formátovú masku vzorky!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="297"/>
        <location filename="../AV/SimpleSynth.cpp" line="140"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Chyba: Nepodarilo sa nastaviť formát vzorkovania!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="330"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Chyba: Nepodarilo sa nastaviť frekvenciu vzorkovania!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Upozornenie: Frekvencia vzorkovania %1 nie jepodporovaná, miesto nej sa použije %2. Nejedná sa o problém.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="343"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Chyba: Nepodarilo sa nastaviť počet kanálov!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="347"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Upozornenie: Počet kanálov %1 nie je podporovaný, miesto neho sa použije %2. Nejedná sa o problém.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="356"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Chyba: Nepodarilo sa nastaviť veľkosť periódy!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="360"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Upozornenie: Veľkosť periódy %1 nie je podporovaná, miesto nej sa použije %2. Nejedná sa o problém.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="369"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Chyba: Nepodarilo sa nastaviť veľkosť vyrovnávacej pamäte!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Upozornenie: Veľkosť vyrovnávacej pamäte %1 nie je podporovaná, miesto nej sa použije %2. Nejedná sa o problém.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="381"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Chyba: Nepodarilo sa použiť hardvérové parametre PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="407"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Chyba: Nepodarilo sa spustiť PCM zariadenie!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="428"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="263"/>
        <location filename="../AV/Input/X11Input.cpp" line="465"/>
        <source>Input thread started.</source>
        <translation>Vstupné vlákno bolo spustené.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="452"/>
        <source>Error: Can&apos;t wait for new samples!</source>
        <translation>Chyba: Nedá sa čakať na nové vzorky!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="469"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Chyba: Nie je možné prečítať vzorky!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="500"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="358"/>
        <location filename="../AV/Input/JACKInput.cpp" line="302"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="294"/>
        <location filename="../AV/Input/X11Input.cpp" line="585"/>
        <source>Input thread stopped.</source>
        <translation>Vstupné vlákno zastavené.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="504"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="362"/>
        <location filename="../AV/Input/JACKInput.cpp" line="306"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="589"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Výnimka &apos;%1&apos; vo vstupnom vlákne.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="507"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="365"/>
        <location filename="../AV/Input/JACKInput.cpp" line="309"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="301"/>
        <location filename="../AV/Input/X11Input.cpp" line="592"/>
        <source>Unknown exception in input thread.</source>
        <translation>Neznáma výnimka vo vstupnom vlákne.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="259"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Chyba: Nepodarilo sa prečítať stream, toto obyčajne znamená, že stream medzičasom zmizol.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="75"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Chyba: Nepodarilo sa pripojiť k serveru JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="84"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Chyba: Nepodarilo sa vytvoriť prípojku JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="100"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Chyba: Nepodarilo sa nastaviť spätné volanie (callback) pre proces JACK servera!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Chyba: Nepodarilo sa nastaviť spätné volanie (callback) pre vzorkovaciu frekvenciu JACK servera!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="108"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Chyba: Nepodarilo sa nastaviť spätné volanie (callback) pre xrun JACK servera!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Chyba: Nepodarilo sa nastaviť spätné volanie (callback) pre pripojenie prípojky serveru JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="117"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Chyba: Nepodarilo sa aktivovať klienta JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="125"/>
        <location filename="../AV/Input/JACKInput.cpp" line="136"/>
        <location filename="../AV/Input/JACKInput.cpp" line="265"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Pripájanie prípojky %1 k %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="269"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>Odpájanie prípojky %1 od %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="34"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Chyba: Zlyhalo volanie pa_mainloop_prepare!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="38"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Chyba: Zlyhalo volanie pa_mainloop_poll!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="42"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Chyba: Zlyhalo volanie pa_mainloop_dispatch!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="52"/>
        <source>Error: Could not create main loop!</source>
        <translation>Chyba: Nepodarilo sa vytvoriť hlavnú slučku!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="59"/>
        <source>Error: Could not create context!</source>
        <translation>Chyba: Nepodarilo sa vytvoriť kontext!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Chyba: Spojenie zlyhalo! Príčina: %1
Je možné, že váš systém nepoužíva PulseAudio. Skúste miesto neho použiť ALSA.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="68"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio.</source>
        <translation>Chyba: Spojenie zlyhalo! Príčina: %1
Je možné, že váš systém nepoužíva PulseAudio.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="82"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Chyba: Pokus o pripojenie zlyhal! Príčina: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="119"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Chyba: Nepodarilo sa vytvoriť stream! Príčina: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="126"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Chyba:Nepodarilo sa pripojiť stream! Príčina: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="137"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Chyba: Pokus o pripojenie streamu zlyhal! Príčina: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="228"/>
        <source>Found source: [%1] %2</source>
        <translation>Nájdený zdroj: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="249"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Chyba: Nepodarilo sa získať názvy zdrojov! Príčina: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="297"/>
        <source>Error: Could not get source info! Reason: %1</source>
        <translation>Chyba: Nepodarilo sa získať informácie o zdroji! Príčina: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="302"/>
        <source>Stream is a monitor.</source>
        <translation>Stream je monitor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="304"/>
        <source>Stream is not a monitor.</source>
        <translation>Stream nie je monitor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="349"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Chyba: Zlyhalo volanie pa_stream_peek!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="416"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Upozornenie: Zdroj zvuku bol pozastavený. Aktuálny segment bude zastavený do času, kedy bude zdroj pokračovať v činnosti.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="421"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Upozornenie: Stream bol presunutý do iného zdroja.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation>Vytvorený čítač video streamu.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Chyba: Nepodarilo sa otvoriť súbor video streamu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation>Chyba: Nepodarilo sa zmeniť veľkosť súboru video streamu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Chyba: Nepodarilo sa namapovať súbor video streamu do pamäte!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Chyba: Nepodarilo sa otvoriť súbor video rámca!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation>Zrušený čítač video streamu.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Chyba: Veľkosť súboru video rámca je nesprávna!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Chyba: Nepodarilo sa namapovať súbor video rámca je nesprávna!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="94"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation>Chyba: Nepodario sa vytvoriť adresár kanálov!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="102"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation>Chyba: Zlyhalo volanie stat na adresár kanálov!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="106"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Chyba: Adresár kanálov nie je adresárom!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="111"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation>Chyba: Nepodarilo sa nastaviť práva pre adresár kanálov!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="116"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Chyba: Adresár kanálov vlastní iný používateľ! Použite iný názov kanála alebo použite menej striktné práva na súbor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="126"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Chyba: Nepodarilo sa inicializovať inofity!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation>Chyba: Nie je možne sledovať adresár kanálov!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation>Chyba: Zlyhalo otvorenie adresára kanálov!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Pridaný už existujúci stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Chyba: Zlyhalo zisťovanie dĺžky čítania od inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Chyba: Zlyhalo čítanie z inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Chyba: Obdržaná neúplná udalosť od inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Chyba: Obdržané neúplné meno od inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation>Pridaný stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation>Odstránený stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Odstránený opustený stream %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="68"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Chyba: Nepodporovaný X11 formát obrazových pixelov!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="41"/>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="118"/>
        <source>Error: Width or height is zero!</source>
        <translation>Chyba: Šírka alebo výška je nulová!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="45"/>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="122"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Chyba: Šírka alebo výška je príliš veľká, maximálna šírka a výška je %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="99"/>
        <source>Error: Can&apos;t open V4L2 device!</source>
        <translation>Chyba: Nedá sa otvoriť zariadenie V4L2!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="107"/>
        <source>Error: Can&apos;t read capabilities of V4L2 device!</source>
        <translation>Chyba: Nedajú sa zistiť vlastnosti zariadenia V4L2!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="111"/>
        <source>Error: V4L2 device does not support video capture!</source>
        <translation>Chyba: Zariadenie V4L2 nepodporuje záznam videa!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="115"/>
        <source>Error: V4L2 device does not support streaming io!</source>
        <translation>Chyba: Zariadenie V4L2 nepodporuje streaming io!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="132"/>
        <source>Error: Can&apos;t set capture format!</source>
        <translation>Chyba: Nedá sa nastaviť formát záznamu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="136"/>
        <source>Error: V4L2 device does not support YUYV pixel format!</source>
        <translation>Chyba: Zariadenie V4L2 nepodporuje formát pixelov YUYV!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="140"/>
        <source>Warning: Resolution %1x%2 is not supported, using %3x%4 instead. The video will be scaled.</source>
        <translation>Upozornenie: Rozlíšenie %1x%2 nie je podporované, miesto neho sa používa %3x%4. Veľkosť videa bude upravená.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="183"/>
        <source>Using color space %1.</source>
        <translation>Používa sa farebný priestor %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="193"/>
        <source>Error: Buffer request failed!</source>
        <translation>Chyba: Požiadavka na vyrovnávaciu pamäť zlyhala!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="203"/>
        <source>Error: Buffer query failed!</source>
        <translation>Chyba: Dopyt na vyrovnávaciu pamäť zlyhal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="209"/>
        <source>Error: Buffer mmap failed!</source>
        <translation>Chyba: Volanie mmap vo vyrovnávacej pamäti zlyhalo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="222"/>
        <source>Error: Buffer queue failed!</source>
        <translation>Chyba: Volanie queue vo vyrovnávacej pamäti zlyhalo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="230"/>
        <source>Error: Failed to start stream!</source>
        <translation>Chyba: Nepodarilo sa spustiť stream!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="273"/>
        <source>Error: Buffer dequeue failed!</source>
        <translation>Chyba: Volanie dequeue vo vyrovnávacej pamäti zlyhalo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="288"/>
        <source>Error: Buffer requeue failed!</source>
        <translation>Chyba: Volanie requeue vo vyrovnávacej pamäti zlyhalo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="257"/>
        <location filename="../GUI/HotkeyListener.cpp" line="115"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Chyba: Nepodarilo sa otvoriť X displej!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="266"/>
        <source>Using X11 shared memory.</source>
        <translation>Používa sa zdieľaná pamäť X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="313"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Chyba: Nepodarilo sa vytvoriť zdieľaný obrázok!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="318"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Chyba: Nepodarilo sa získať zdieľanú pamäť!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="323"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Chyba: Zlyhalo pripojenie ku zdieľanej pamäti!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="268"/>
        <source>Not using X11 shared memory.</source>
        <translation>Nepoužíva sa zdieľaná pamäť X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="275"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Upozornenie: X server nepodporuje XFixes, kurzor bol skrytý.</translation>
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
        <translation>Upozornenie: X server nepodporuje rozšírenie Xinerama, podpora viacerých monitorov nemusí fungovať správne.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation>Upozornenie: Neboli zistené žiadne monitory, podpora viacerých monitorov nemusí fungovať správne.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="386"/>
        <source>Screen %1:</source>
        <translation type="unfinished">Obrazovka %1:</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="406"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Chyba: Neplatný región ohraničenia obrazovky!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="328"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Chyba: Nepodarilo sa pripojiť server ku zdieľanej pamäti!</translation>
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
        <translation>Chyba: Nepodarilo sa získať obrázok (s použitím zdieľanej pamäte)!
    Toto zvyčajne znamená, že oblasť na nahrávanie (alebo jej časť) sa nachádza mimo obrazovky. Alebo ste zmenili rozlíšenie?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="547"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Chyba: Nepodarilo sa získať obrázok (bez použitia zdieľanej pamäte)!
    Toto zvyčajne znamená, že oblasť na nahrávanie (alebo jej časť) sa nachádza mimo obrazovky. Alebo ste zmenili rozlíšenie?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="100"/>
        <source>Error: Channel count is zero.</source>
        <translation>Chyba: Počet kanálov je nula.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="104"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Chyba: Frekvencia vzorkovania je nulová.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="142"/>
        <source>Using sample format %1.</source>
        <translation>Používa sa formát vzorkovania %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="147"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Chyba: Enkodér vyžaduje nepodporovaný formát vzorkovania!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <source>Error: Sending of audio frame failed!</source>
        <translation>Chyba: Posielanie zvukového rámca zlyhalo!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Receiving of audio packet failed!</source>
        <translation>Chyba: Príjem zvukového paketu zlyhal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="210"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="232"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Chyba: Enkódovanie zvukového rámca zlyhalo!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="30"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="39"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Chyba: Možnosť &apos;%1&apos; sa nepodarilo prečítať!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation>Zastavuje sa vlákno enkodéra...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="164"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Chyba: Nepodarilo sa otvoriť kodek!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="172"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation>Upozornenie: Možnosť kodeku &apos;%1&apos; nebola rozpoznaná!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="188"/>
        <source>Encoder thread started.</source>
        <translation>Vlákno enkodéra bolo spustené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="217"/>
        <source>Flushing encoder ...</source>
        <translation>Vyprázdňovanie údajov enkodéra...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="228"/>
        <source>Encoder thread stopped.</source>
        <translation>Vlákno enkodéra bolo zastavené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Výnimka &apos;%1&apos; vo vlákne enkodéra.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="235"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Neznáma výnimka vo vlákne enkodéra.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="70"/>
        <source>Stopping encoders ...</source>
        <translation>Zastavujú sa enkodéry...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="77"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Čaká sa na zastavenie vlákna multiplexora...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <location filename="../AV/Output/Muxer.cpp" line="124"/>
        <source>Error: Can&apos;t copy parameters to stream!</source>
        <translation>Chyba: Nie je možné skopírovať parametre do streamu!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="146"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Chyba: Nie je možné zapísať hlavičky!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="157"/>
        <source>Finishing encoders ...</source>
        <translation>Dokončuje sa enkódovanie...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Chyba: Nepodarilo sa nájsť zvolený výstupný formát!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Using format %1 (%2).</source>
        <translation>Používa sa formát %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="209"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Chyba: Nepodarilo sa alokovať kontext pre formát!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Chyba: Nepodarilo sa otvoriť výstupný súbor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="229"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Chyba: Nepodarilo sa zapísať trailer, pokračujem napriek tomu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="267"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Chyba: Nepodarilo sa nájsť kodek!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="277"/>
        <source>Using codec %1 (%2).</source>
        <translation>Používa sa kodek %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="288"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Chyba: Nepodarilo sa vytvoriť nový stream!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="295"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation>Chyba: Nepodarilo sa vytvoriť nový kontext pre kodek!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="307"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Chyba: Nepodarilo sa získať predvolený kontext pre kodek!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="320"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Upozornenie: Tento kodek libav/ffmpeg označuje ako experimentálny.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="336"/>
        <source>Muxer thread started.</source>
        <translation>Vlákno multiplexora bolo spustené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="396"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Chyba: Zlyhalo zapísanie rámca do multiplexora!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="424"/>
        <source>Muxer thread stopped.</source>
        <translation>Vlákno multiplexora bolo zastavené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="428"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Výnimka &apos;%1&apos; vo vlákne multiplexora.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="431"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Neznáma výnimka vo vlákne multiplexora.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="220"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Zastavuje sa vlákno synchronizátora...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="328"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Upozornenie: Prijatý video rámec s nestúpajúcou časovou značkou.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="355"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Upozornenie: Pretečenie vyrovnávacej pamäte videa, niektoré snímky budú zahodené. Vyzerá, že zvukový stup je príliš pomalý.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="412"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Upozornenie: Prijaté zvukové vzorky nemajú stúpajúce časové značky.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="437"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Upozornenie: Príliš mnoho zvukových vzoriek, vzorky budú zahodené, aby bola zachovaná synchronizácia s videom.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="443"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Upozornenie: Nedostatok zvukových vzoriek, vloží sa ticho, aby bola zachovaná synchronizácia s videom.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="511"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Upozornenie: Zvukový vstup je o viac ako 2% pomalší!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="515"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Upozornenie: Zvukový vstup je o viac ako 2% rýchlejší!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="554"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Upozornenie: Pretečenie vyrovnávacej pamäte zvuku, bude vytvorený nový segment, aby bola zachovaná synchronizácia s videom (časti videa a/alebo zvuku sa môžu stratiť). Vyzerá, že vstup videa je príliš pomalý.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="590"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Upozornenie: Zistená medzera vo zvukovom streame, vloží sa ticho, aby bola zachovaná synchronizácia s videom.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="891"/>
        <source>Synchronizer thread started.</source>
        <translation>Vlákno synchronizovača bolo spustené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="913"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Vlákno synchronizovača bolo zastavené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="917"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Výnimka &apos;%1&apos; vo vlákne synchronizovača.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="920"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Neznáma výnimka vo vlákne synchronizovača.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="49"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="126"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Chyba: Šírka alebo výška nie je párne číslo!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="130"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Chyba: Snímková frekvencia je nulová!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="187"/>
        <source>Using pixel format %1.</source>
        <translation>Používa sa formát pixelov %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="201"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Chyba: Formát pixelov nie je podporovaný kodekom!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="229"/>
        <source>Error: Sending of video frame failed!</source>
        <translation>Chyba: Zlyhalo odosielanie video rámca!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="250"/>
        <source>Error: Receiving of video packet failed!</source>
        <translation>Chyba: Zlyhalo prijímanie paketu videa!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="263"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="284"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Chyba: Zlyhalo enkódovanie video rámca!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="41"/>
        <source>Using real-time priority.</source>
        <translation>Používa sa real-time priorita.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="51"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation>Používa sa priorita podľa nice.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation>Upozornenie: Nie je možné zvýšiť prioritu vlákna.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="64"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Upozornenie: Nepodarilo sa obnoviť zariadenie po podtečení (underrun)!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="91"/>
        <source>Stopping synth thread ...</source>
        <translation>Zastavuje sa vlákno syntetizéra...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="224"/>
        <source>Synth thread started.</source>
        <translation>Vlákno syntetizéra bolo spustené.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="277"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Chyba: Nepodarilo sa zapísať vzorky!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="285"/>
        <source>Synth thread stopped.</source>
        <translation>Vlákno syntetizéra bolo zastavené.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="289"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Výnimka &apos;%1&apos; vo vlákne syntetizéra.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="292"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Neznáma výnimka vo vlákne syntetizéra.</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="45"/>
        <source>CPU features</source>
        <translation>Vlastnosti CPU</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>The application could not be launched.</source>
        <translation>Aplikáciu sa nepodarilo spustiť.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="161"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation>Upozornenie: X server nepodporuje XInput2, klávesové skratky nemusia v niektorých programoch fungovať.</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="90"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation>Chyba: Voľba príkazového riadka &apos;%1&apos; vyžaduje zadanie hodnoty!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="98"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Chyba: Voľba príkazového riadka &apos;%1&apos; nepodporuje zadávanie hodnôt!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="195"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Chyba: Neznáma voľba príkazového riadka &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="203"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Chyba: Neznámy argument príkazového riadka &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="253"/>
        <source>Error: Can&apos;t create configuration directory!</source>
        <translation>Chyba: Nepodarilo sa vytvoriť adresár s konfiguráciou!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="99"/>
        <source>SSR started</source>
        <translation>SSR spustený</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="133"/>
        <source>SSR stopped</source>
        <translation>SSR zastavený</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="obsolete">Chyba: Nepodarilo sa vytvoriť adresár .ssr!</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="165"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation>BGRA %1 na BGRA %2  |  SWScale %3 us  |  Záložný %4 us (%5%)  |  SSSE3 %6 us (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="243"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation>%1 %2 na %3 %4  |  SWScale %5 us  |  Záložný %6 us (%7%)  |  SSSE3 %8 us (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="253"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Spúšťa sa test výkonu škálovača...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="260"/>
        <source>Starting converter benchmark ...</source>
        <translation>Spúšťa sa test výkonu konvertora...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="70"/>
        <source>Stopping fragment thread ...</source>
        <translation>Zastavuje sa vlákno fragmentu...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="347"/>
        <source>Fragment thread started.</source>
        <translation>Vlákno fragmentu bolo spustené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="365"/>
        <source>Next fragment ...</source>
        <translation>Ďalší fragment...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="369"/>
        <source>Finishing ...</source>
        <translation>Prebieha dokončovanie...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="381"/>
        <source>Fragment thread stopped.</source>
        <translation>Vlákno fragmentu bolo zastavené.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="385"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation>Výnimka &apos;%1&apos; vo vlákne fragmentu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="388"/>
        <source>Unknown exception in fragment thread.</source>
        <translation>Neznáma výnimka vo vlákne fragmentu.</translation>
    </message>
    <message>
        <location filename="../common/ScreenScaling.cpp" line="120"/>
        <source>Detected fractional screen scale factor, scaling was disabled.</source>
        <translation>Zistená zlomková mierka zobrazenia, úprava veľkosti bola vypnutá.</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>You are using a non-X11 window system (e.g. Wayland) which is currently not supported by SimpleScreenRecorder. Several features will most likely not work properly. In order to solve this, you should log out, choose a X11/Xorg session at the login screen, and then log back in.</source>
        <translation>Používate grafický systém odlišný od X11 (napr. Wayland) a tento momentálne SimpleScreenRecorder nepodporuje. Nejaké funkcie nemusia pracovať správne. Pre vyriešenie sa odhláste, vyberte reláciu X11/Xorg na obrazovke prihlásenia a opäť sa prihláste.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="86"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translatorcomment>NVIDIA X Server Settings is the name of the tool in my system, I hope it&apos;s the same across distributions</translatorcomment>
        <translation>SimpleScreenRecorder zistil, že používate uzavretý ovládač NVIDIA s aktivovanou funkciou &quot;Flipping&quot;. To je zvyčajne zdrojom chýb počas nahrávania, preto odporúčame &quot;Flipping&quot; vypnúť. Chcete, aby sme to urobili za vás?

Túto funkciu môžete takisto vypnúť ručne v nástroji NVIDIA X Server Settings.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="104"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translatorcomment>NVIDIA X Server Settings is the name of the tool in my system, I hope it&apos;s the same across distributions</translatorcomment>
        <translation>Bohužiaľ, nepodarilo sa nám vypnúť &quot;Flipping&quot;! Skúste ho vypnúť ručne pomocou nástroja NVIDIA X Server Settings.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="31"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Záznam bol uložený. Teraz môžete video upraviť alebo prekonvertovať s lepšími nastaveniami a zmeniť tak celkovú veľkosť videa (predvolené nastavenia sú optimalizované na dosiahnutie dobrej kvality a rýchlosti, nie malej veľkosti).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="35"/>
        <source>Open folder</source>
        <translation>Otvoriť priečinok</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="38"/>
        <source>Back to the start screen</source>
        <translation>Späť na úvodnú obrazovku</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="273"/>
        <source>Video input</source>
        <translation>Video vstup</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record the entire screen</source>
        <translation>Nahrávať celú obrazovku</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>Record a fixed rectangle</source>
        <translation>Nahrávať vybranú obdĺžnikovú oblasť</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="278"/>
        <source>Follow the cursor</source>
        <translation>Sledovať kurzor myši</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Input profile</source>
        <translation>Vstupný profil</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="280"/>
        <source>Record OpenGL</source>
        <translation>Nahrať OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="283"/>
        <source>Record V4L2 device</source>
        <translation>Nahrať zariadenie V4L2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="295"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Vyberte, ktorý monitor sa má nahrávať v konfigurácii s viacerými monitormi. konfigurace počítače s více monitory.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="296"/>
        <source>Record entire screen with cursor</source>
        <translation>Nahrávať celú obrazovku s kurzorom</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="297"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation>Nahrávať celú obrazovku, na ktorej sa nachádza kurzor miesto sledovania pozície kurzora.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="298"/>
        <source>Select rectangle...</source>
        <translation>Vyberte obdĺžnik...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="299"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Pomocou myši vyberte obdĺžnikovú oblasť, ktorá bude nahrávaná.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="300"/>
        <source>Select window...</source>
        <translation>Vyberte okno...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="301"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Pomocou myši vyberte okno, ktoré bude nahrávané.
Tip: Ak kliknete na okraj okna, bude nahrané celé okno vrátane okrajov. V opačnom prípade
bude nahraný iba vnútorný obsah okna.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="305"/>
        <source>OpenGL settings...</source>
        <translation>Nastavenia OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="306"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Zmeniť nastavenia pre nahrávanie OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="310"/>
        <source>The V4L2 device to record (e.g. /dev/video0).</source>
        <translation>Zariadenie V4L2, ktoré má byť nahrávané (napr. /dev/video0).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Left:</source>
        <translation>Vľavo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="316"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Súradnice X ľavého horného rohu nahrávaného obdĺžnika.
Tip: Hodnotu môžete zmeniť aj pomocou kolečka myši alebo šípol hore/dole.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="318"/>
        <source>Top:</source>
        <translation>Hore:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="322"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Súradnica Y ľavého horného rohu nahrávaného obdĺžnika.
Tip: Hodnotu môžete zmeniť aj pomocou kolečka myši alebo šípok hore/dole.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="324"/>
        <source>Width:</source>
        <translation>Šírka:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="328"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Šírka nahrávaného obdĺžnika.
Tip: Hodnotu môžete zmeniť aj pomocou kolečka myši alebo šípok hore/dole.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="330"/>
        <source>Height:</source>
        <translation>Výška:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="334"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Výška nahrávaného obdĺžnika.
Tip: Hodnotu môžete zmeniť aj pomocou kolečka myši alebo šípok hore/dole.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="336"/>
        <source>Frame rate:</source>
        <translation>Snímková frekvencia:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="340"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Frekvencia snímok výsledného videa. Vyššia frekvencia vyžaduje viac procesorového výkonu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="341"/>
        <source>Scale video</source>
        <translation>Zmena veľkosti videa</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="342"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Aktivuje funkciu zmeny veľkosti videa. Zmena veľkosti vyžaduje viac procesorového výkonu,
ale ak bude video menšie, jeho enkódovanie môže byť rýchlejšie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="343"/>
        <source>Scaled width:</source>
        <translation>Cieľová šírka:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="347"/>
        <source>Scaled height:</source>
        <translation>Cieľová výška:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="351"/>
        <source>Record cursor</source>
        <translation>Nahrávať kurzor myši</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="441"/>
        <source>Audio input</source>
        <translation>Záznam zvuku</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="443"/>
        <source>Record audio</source>
        <translation>Nahrávať zvuk</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="444"/>
        <source>Backend:</source>
        <translation>Rozhranie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="456"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Zvukové rozhranie, ktoré bude použité pre nahrávanie zvuku.
Rozhranie ALSA bude fungovať aj na systémoch, ktoré použivajú PulseAudio, ale v takých prípadoch je lepšie použiť priamo PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="459"/>
        <source>The audio backend that will be used for recording.</source>
        <translation>Zvukové rozhranie, ktoré bude použité pre nahrávanie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="462"/>
        <location filename="../GUI/PageInput.cpp" line="471"/>
        <source>Source:</source>
        <translation>Zdroj:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="465"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Zdroj rozhrania ALSA, ktorý bude použitý pre záznam zvuku.
Predvolené nastavenie spravidla vyhovuje. Zdieľané (&quot;shared&quot;) zdroje umožňujú nahrávat vo viacerých aplikáciach súčasne, môžu však byť menej spoľahlivé.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="467"/>
        <location filename="../GUI/PageInput.cpp" line="476"/>
        <source>Refresh</source>
        <translation>Obnoviť</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="468"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Obnoví zoznam zdrojov rozhrania ALSA.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="474"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Zdroj rozhrania PulseAudio, ktorý bude použitý pre záznam zvuku.
Zdroj &quot;monitor&quot; umožňuje nahrávanie zvuku, ktorý produkujú iné aplikácie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="477"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Obnoví zoznam zdrojov rozhrania PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="480"/>
        <source>Record system microphone</source>
        <translation>Nahrávať systémový mikrofón</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="481"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>V prípade aktivovania tejto možnosti budú prípojky automaticky napojené na systémové vstupné (záznam) prípojky.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="482"/>
        <source>Record system speakers</source>
        <translation>Nahrávať systémové reproduktory</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="483"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>V prípade aktivovania tejto možnosti budú prípojky pripojené na všetko, čo je pripojené na výstupné (playback) prípojky systému.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="530"/>
        <source>Back</source>
        <translation>Späť</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="531"/>
        <source>Continue</source>
        <translation>Pokračovať</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="964"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Všetky obrazovky: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="968"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Obrazovka %1: %2x%3 na súrad. %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1206"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Obrazovka %1</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <location filename="../GUI/PageOutput.cpp" line="85"/>
        <location filename="../GUI/PageOutput.cpp" line="88"/>
        <location filename="../GUI/PageOutput.cpp" line="91"/>
        <location filename="../GUI/PageOutput.cpp" line="133"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>súbory %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>Iné...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>Bez kompresie</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="173"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Chyba: Nepodarilo sa nájsť vhodný kontajner v knižnici libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Chyba: Nepodarilo sa nájsť vhodný video kodek v knižnici libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Chyba: Nepodarilo sa nájsť vhodný audio kodek v knižnici libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Output profile</source>
        <translation>Výstupný profil</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="191"/>
        <source>File</source>
        <translation>Súbor</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="193"/>
        <source>Save as:</source>
        <translation>Uložiť ako:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="195"/>
        <source>The recording will be saved to this location.</source>
        <translation>Umiestnenie, kam bude záznam uložený.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="196"/>
        <source>Browse...</source>
        <translation>Prehliadať...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>Separate file per segment</source>
        <translation>Samostatný súbor pre každý segment</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="203"/>
        <source>Container:</source>
        <translation>Kontajner:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="208"/>
        <source>(not installed)</source>
        <translation>(nenainštalovaný)</translation>
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
        <translation>Kontejner (súborový formát), ktorý bude použitý na uloženie záznamu.
Je dôležité vedieť, že nie všetky kodeky sú podporované všetkými kontajnermi a nie všetky prehrávače sú schopné všetky formáty prehrať.
- Matroska (MKV) podporuje všetky kodeky, ale je menej známy.
- MP4 je dobre známy formát, ktorý prehrá väčšina moderných prehrávačov, ale podporuje iba video kodek H.264
    (mnoho prehrávačov vie čítať tento formát iba v kombinácii so zvukovým kodekom AAC).
- WebM je navrhnutý pre videá vkladané do webových stránok (pomocou HTML5 značky &lt;video&gt;). Formát bol vytvorený Googlom a je podporovaný
    prehliadačmi Firefox, Chrome a Opera, pre Internet Explorer a Safari existujú pluginy. Formát podporuje iba kodeky VP8 a Vorbis.
- OGG podporuje iba kodeky Theora a Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Container name:</source>
        <translation>Názov kontajneru:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Pre pokročilých používateľov. Môžete využiť ľubovoľný formát knižníc libav/ffmpeg, ale nie všetky sú užitočné a niektoré nemusia fungovať vôbec.</translation>
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
        <translation>Kodek:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="257"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Kodek, ktorý bude použitý na spracovanie toku videa.
- H.264 (libx264) je v súčasnej dobe najlepší kodek - veľmi rýchly a zároveň kvalitný.
- VP8 (libvpx) je celkom dobrý, ale trošku pomalší.
- Theora (libtheora) nie je príliš odporúčaný z dôvodu nižšej kvality.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Codec name:</source>
        <translation>Názov kodeku:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Pre pokročilých používateľov. Môžete využiť ľubovoľný formát knižníc libav/ffmpeg, ale nie všetky sú užitočné a niektoré nemusia fungovať vôbec.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation>Ak je táto voľba aktivovaná pri každom pozastavení a opätovnom spustení nahrávania bude vytvorený nový súbor videa. Ak túto voľbu neaktivujete, všetky nahrané segmenty budú spojené do jedného súboru.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <source>Add timestamp</source>
        <translation>Pridať časovú značku</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Ak je táto voľba aktivovaná, bude k názvu súboru automaticky pripájaný dátum a čas.
Ak bol pôvodný názov súboru &apos;test.mkv&apos;, video bude uložené ako &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="227"/>
        <source>Warning: This format will produce unreadable files if the recording is interrupted! Consider using MKV instead.</source>
        <translation>Upozornenie: Ak je nahrávanie prerušené, pri použití tohto formátu získate nečitateľné súbory! Zvážte radšej použitie MKV.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="268"/>
        <location filename="../GUI/PageOutput.cpp" line="352"/>
        <source>Bit rate (in kbit/s):</source>
        <translation>Bitový tok (v kbit/s):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Bitový tok videa (v kilobitoch za sekundu). Vyššia hodnota znamená vyššiu kvalitu videa.
Ak neviete, kde začať, vyskúšajte hodnotu 5000 a zmeňte v prípade potreby.</translation>
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
        <translation>Toto nastavenie určuje kvalitu videa. Nižšia hodnota znamená vyššiu kvalitu.
Povolený rozsah je 0-51 (0 znamená bezstratový záznam, predvolená hodnota je 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="283"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Prednastavenie (preset):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="288"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Rýchlosť enkódovania. Vyššia rýchlosť vyžaduje menej procesorového času (a umožňuje tak dosiahnuť vyššiu snímkovú frekvenciu),
ale vytvára väčšie súbory. Toto nastavenie by nemalo mať veľký vplyv na kvalitu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="290"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU used:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="292"/>
        <source>fastest</source>
        <translation>najrýchlejšia</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <source>slowest</source>
        <translation>najpomalšia</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="298"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Rýchlosť enkódovania. Vyššia hodnota znamená *nižšiu* procesorovú zátaž a predstavuje nižšiu kvalitu,
ak zároveň nezmeníte aj hodnotu bitového toku.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <location filename="../GUI/PageOutput.cpp" line="355"/>
        <source>Custom options:</source>
        <translation>Ďalšie parametre:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <location filename="../GUI/PageOutput.cpp" line="357"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Voliteľné parametre kodeku, oddelené čiarkami (napr. voľba1=hodnota1,voľba2=hodnota2,voľba3=hodnota3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Allow frame skipping</source>
        <translation>Povoliť vynechávanie snímok</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="304"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Ak je aktivovaná táto voľba, video enkodér bude môcť preskočiť snímky, v prípade, že je vstupná
snímková frekvencia nižšia ako výstupná. Pri vypnutí tejto voľby budú chýbajúce snímky zdvojené,
čo zvyšuje záťaž na procesor a prispieva k väčšej veľkosti videa, ale môže znižovať oneskorenie
pri vysielaní streamu online. Táto voľba by nemala mať vplyv na kvalitu videa.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Audio</source>
        <translation>Zvuk</translation>
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
        <translation>Kodek, ktorý bude použitý pre spracovanie zvukového streamu. Toto nastavenie nie je príliš dôležité,
pretože veľkosť zvukových dát je zanedbateľná v porovnaní s objemom obrazových dát.
- Vorbis (libvorbis) je vynikajúci a je to odporúčaný kodek.
- MP3 (libmp3lame) je pomerne dobrý.
- AAC je dobrý kodek, ale tu použitá implementácia (libvo_aacenc alebo experimentální ffmpeg aac) na tom nie je najlepšie.
    Použite iba v prípade, že nemáte inú možnosť.
- Bez kompresie bude zvukový záznam uložený bez ďalšieho spracovania. Záznam je veľmi rýchly, ale výsledný súbor bude väčší.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Pre pokročilých používateľov. Môžete využiť ľubovoľný formát knižníc libav/ffmpeg, ale nie všetky sú užitočné a niektoré nemusia fungovať vôbec.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Bitový tok zvuku (v kilobitoch za sekundu). Vyššia hodnota znamená vyššiu kvalitu zvuku. Typická hodnota je 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="379"/>
        <source>Back</source>
        <translation>Späť</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="380"/>
        <source>Continue</source>
        <translation>Pokračovať</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="637"/>
        <location filename="../GUI/PageOutput.cpp" line="645"/>
        <source>not installed</source>
        <translation>nie je nainštalované</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <location filename="../GUI/PageOutput.cpp" line="647"/>
        <source>not supported by container</source>
        <translation>nie je podporované kontajnerom</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="690"/>
        <source>Save recording as</source>
        <translation>Uložiť nahrávku ako</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="528"/>
        <source>You did not select an output file!</source>
        <translation>Nebol vybraný výstupný súbor!</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="176"/>
        <source>Recording</source>
        <translation>Nahrávanie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="182"/>
        <source>Edit schedule</source>
        <translation>Upraviť plán nahr.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="183"/>
        <source>The recording schedule can be used to automatically start or pause the recording at a predefined time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="185"/>
        <source>Enable recording hotkey</source>
        <translation>Povoliť klávesovú skratku</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="186"/>
        <source>The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,
even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the
SimpleScreenRecorder window show up in the final video.</source>
        <translation>Klávesová skratka pre nahrávanie je globálna skratka, ktorú môžete použiť kedykoľvek na spustenie alebo pozastavenie nahrávania, aj vtedy, keď okno SimpleScreenRecorder-a nie je viditeľné. Takto môžete nahrať video bez toho, aby sa v nej objavilo okno SimpleScreenRecorder-a.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="190"/>
        <source>Enable sound notifications</source>
        <translation>Povoliť zvukovú signalizáciu</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="191"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation>Ak je aktivované, pri spustení alebo pozastavení prehrávania a pri výskyte chyby bude prehrané zvukové znamenie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="193"/>
        <source>Hotkey:</source>
        <translation>Klávesová skratka:</translation>
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
        <translation>Kombinácia klávesov pre spustenie, pozastavenie alebo ukončenie nahrávania.
Tieto klávesy budú odchytené a nebudú zaregistrované nahrávanou aplikáciou.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="252"/>
        <source>Information</source>
        <translation>Informácie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="254"/>
        <source>Total time:</source>
        <translation>Celkový čas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="256"/>
        <source>FPS in:</source>
        <translation>Vstup snímky/s:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="258"/>
        <source>FPS out:</source>
        <translation>Výstup snímky/s:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="260"/>
        <source>Size in:</source>
        <translation>Veľkosť vstupu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="262"/>
        <source>Size out:</source>
        <translation>Veľkosť výstupu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="264"/>
        <source>File name:</source>
        <translation>Názov súboru:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="267"/>
        <source>File size:</source>
        <translation>Veľkosť súboru:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="269"/>
        <source>Bit rate:</source>
        <translation>Bitový tok:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="271"/>
        <source>Show recording area</source>
        <translation>Zobraziť oblasť nahrávania</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="272"/>
        <source>When enabled, the recorded area is marked on the screen.</source>
        <translation>Ak je zapnuté, oblasť nahrávania zostane označená.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="297"/>
        <source>Preview</source>
        <translation>Ukážka</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="301"/>
        <source>Preview frame rate:</source>
        <translation>Snímková frekvencia ukážky:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="305"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Poznámka: Ukážka je náročná na procesorový čas (obzvlášť pri vysokých snímkových frekvenciách).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="354"/>
        <source>Log</source>
        <translation>Záznam</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="369"/>
        <location filename="../GUI/PageRecord.cpp" line="377"/>
        <source>Cancel recording</source>
        <translation>Zrušiť nahrávanie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="370"/>
        <location filename="../GUI/PageRecord.cpp" line="379"/>
        <source>Save recording</source>
        <translation>Uložiť nahrávku</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="384"/>
        <source>Quit</source>
        <translation>Ukončiť</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="435"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Aktuálna nahrávka ešte nebola uložená, ak teraz program ukončíte, bude stratená.
Naozaj chcete program ukončiť?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="447"/>
        <source>Hide window</source>
        <translation>Skryť okno</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="449"/>
        <source>Show window</source>
        <translation>Zobraziť okno</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="659"/>
        <source>Starting page ...</source>
        <translation>Spúšťa sa stránka...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="681"/>
        <location filename="../GUI/PageRecord.cpp" line="858"/>
        <location filename="../GUI/PageRecord.cpp" line="961"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Chyba: V priebehu inicializácie sa vyskytol problém.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="690"/>
        <source>Started page.</source>
        <translation>Spustená stránka.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="723"/>
        <source>Stopping page ...</source>
        <translation>Zastavuje sa stránka...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="750"/>
        <source>Stopped page.</source>
        <translation>Zastavená stránka.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="779"/>
        <source>Starting output ...</source>
        <translation>Spúšťa sa výstup...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="793"/>
        <source>Output file: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="804"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Chyba: Nepodarilo sa zistiť veľkosť OpenGL aplikácie, pretože vstup GLInject nebol vytvorený.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="809"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Chyba: Nepodarilo sa zistiť veľkosť OpenGL aplikácie. Buď nebol program správne spustený alebo aplikácia ešte nevytvorila OpenGL okno. Ak chcete spustiť nahrávanie pred spustením programu, musíte povoliť zmenu veľkosti videa a zadať veľkosť videa ručne.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="848"/>
        <source>Started output.</source>
        <translation>Spustený výstup.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="869"/>
        <source>Stopping output ...</source>
        <translation>Zastavuje sa výstup...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="887"/>
        <source>Stopped output.</source>
        <translation>Zastavený výstup.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="919"/>
        <source>Starting input ...</source>
        <translation>Spúšťa sa vstup...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="930"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Chyba: Nepodarilo sa spustiť GLInject vstup, pretože nebol vytvorený.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="956"/>
        <source>Started input.</source>
        <translation>Spustený vstup.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="988"/>
        <source>Stopping input ...</source>
        <translation>Zastavuje sa vstup...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1006"/>
        <source>Stopped input.</source>
        <translation>Zastavený vstup.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1022"/>
        <source>Encoding remaining data ...</source>
        <translation>Enkódujú sa zostavajúce dáta...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1116"/>
        <location filename="../GUI/PageRecord.cpp" line="1126"/>
        <source>Pause recording</source>
        <translation>Pozastaviť nahrávanie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1119"/>
        <location filename="../GUI/PageRecord.cpp" line="1129"/>
        <source>Start recording</source>
        <translation>Spustiť nahrávanie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1137"/>
        <source>Deactivate schedule</source>
        <translation>Deaktivovať plán nahr.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1147"/>
        <source>Activate schedule</source>
        <translation>Aktivovať plán nahr.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1156"/>
        <source>Stop preview</source>
        <translation>Zastaviť ukážku</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1159"/>
        <source>Start preview</source>
        <translation>Spustiť ukážku</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1200"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Chyba: V priebehu vytvárania syntetizéra sa vyskytol problém.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1264"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Naozaj chcete zrušiť nahrávanie?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1281"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.</source>
        <translation>Nič ste nenahrali, nie je čo uložiť.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1298"/>
        <source>Triggering scheduled action &apos;%1&apos; ...</source>
        <translation>Spúšťa sa naplánovaná akcia &apos;%1&apos;...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1309"/>
        <source>Schedule: %1 in %2</source>
        <translation>Plán nahr.: %1 o %2</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1316"/>
        <source>Schedule: (none)</source>
        <translation>Plán nahr.: (žiadny)</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1320"/>
        <source>Schedule: (inactive)</source>
        <translation>Plán nahr.: (neaktívny)</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1384"/>
        <location filename="../GUI/PageRecord.cpp" line="1401"/>
        <source>Standard input read error (%1).</source>
        <translation>Chyba čítania štandardného vstupu (%1).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1389"/>
        <location filename="../GUI/PageRecord.cpp" line="1406"/>
        <source>Standard input closed (%1).</source>
        <translation>Štandardný vstup uzatvorený (%1).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1419"/>
        <source>Received command &apos;%1&apos;.</source>
        <translation>Prijatý príkaz &apos;%1&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1439"/>
        <source>Unknown command.</source>
        <translation>Neznámy príkaz.</translation>
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
        <translation>&lt;p&gt;Vitajte v aplikácii SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Napriek svojmu názvu (v preklade JednoduchýNahrávačObrazovky) ponúka tento program množstvo funkcií. Ale nebojte sa, sú tu len dve veci, ktoré potrebujete vedieť. Prvou je to, že predvolené nastavenia sú obvykle postačujúce. Ak nejakej voľbe nerozumiete, jednoducho ju nemeňte. A tá druhá je, že takmer všetky voľby majú popis. Stačí podržať myš nad danou voľbou a zobrazí sa.&lt;/p&gt;

&lt;p&gt;Pre viac informácií:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="51"/>
        <source>About SimpleScreenRecorder</source>
        <translation>O aplikaci SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="52"/>
        <source>Skip this page next time</source>
        <translation>Túto obrazovku už nezobrazovať</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="53"/>
        <source>Go directly to the input page when the program is started.</source>
        <translation>Po spustení programu prejsť priamo do nastavení vstupu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="76"/>
        <source>Continue</source>
        <translation>Pokračovať</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Uložiť</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Uložiť aktuálne nastavenia do tohto profilu.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Nový</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Vytvoriť nový profil s aktuálnymi nastaveniami.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Odstrániť</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Odstrániť tento profil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(žiadny)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Chyba: Nedá sa načítať profil!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Nazoaj chcete prepísať tento profil?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Zadejte názov nového profilu:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Profil s takýmto menom už existuje. Naozaj ho chcete nahradiť?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Naozaj chcete odstrániť tento profil?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation>O&amp;K</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation>&amp;Zrušiť</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>Án&amp;o</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Áno, vždy</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Nie</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Nie, nikdy</translation>
    </message>
</context>
<context>
    <name>RecordScheduleEntryWidget</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="39"/>
        <source>Start</source>
        <translation>Spustiť</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="40"/>
        <source>Pause</source>
        <translation>Pozastaviť</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="46"/>
        <source>Time:</source>
        <translation>Čas:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="51"/>
        <source>Action:</source>
        <translation>Akcia:</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Diagram synchronizácie</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="257"/>
        <source>Video in</source>
        <translation>Vstup videa</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="258"/>
        <source>Audio in</source>
        <translation>Vstup zvuku</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="259"/>
        <source>Video out</source>
        <translation>Výstup videa</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="260"/>
        <source>Audio out</source>
        <translation>Výstup zvuku</translation>
    </message>
</context>
</TS>
