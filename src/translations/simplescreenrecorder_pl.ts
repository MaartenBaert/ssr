<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="pl_PL">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>About SimpleScreenRecorder</source>
        <translation>O SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="120"/>
        <source>For more information:</source>
        <translation>Więcej informacji:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="121"/>
        <source>The source code of this program can be found at:</source>
        <translation>Kod źródłowy aplikacji można znaleźć na:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="122"/>
        <source>This program uses:</source>
        <translation>Aplikacja wykorzystuje:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="123"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 dla interfejsu graficznego</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="124"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 lub %2 (zależy od dystrybucji) do kodowania wideo/audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="125"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 do podpinania funkcji systemowych przy nagrywaniu OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="35"/>
        <source>OpenGL Settings</source>
        <translation>Opcje OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="38"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Uwaga: nagrywanie OpenGL działa przez wstrzykniecie biblioteki do nagrywanego programu. Ta biblioteka nadpisze niektóre funkcje systemowe w celu przechwycenia klatek zanim zostaną wyświetlone na ekranie. Jeśli usiłujesz nagrać grę, która wykrywa próby hakowania po stronie klienta, jest (teoretycznie) możliwe że gra uzna to za próbę hakowania. Może to doprowadzić do zbanowania twojego konta, dlatego dobrym pomysłem jest sprawdzenie czy aplikacja, którą planujesz nagrać nie zbanuje cię, zanim zaczniesz nagrywać. Zostałeś ostrzeżony :)&lt;/p&gt;

&lt;p&gt;Uwaga 2: nagrywanie OpenGL jest eksperymentalne i może nie działać a nawet doprowadzić do zatrzymania programu. Jeśli obawiasz się o utratę danych zrób kopie zapasową.&lt;/p&gt;

&lt;p&gt;Jeśli chcesz nagrywać gry z platformy Steam zapoznaj się z tym: &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="52"/>
        <source>Choose channel</source>
        <translation>Wybierz kanał</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="54"/>
        <source>Channel name:</source>
        <translation>Nazwa kanału:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="56"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation type="unfinished">Nazwy kanałów są używane do identyfikacji aplikacji. Użyj tej opcji jeśli chcesz nagrać wiele aplikacji w tym samym czasie.
Jeśli pozostawisz to pole pustym, domyślną nazwą bedzie &quot;kanał-TWOJANAZWAUŻYTKOWNIKA&quot;.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="74"/>
        <source>Launch application</source>
        <translation>Uruchom aplikację</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="76"/>
        <source>Command:</source>
        <translation>Polecenie:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="78"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Polecenie uruchamiające aplikację, która ma być nagrywana.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="80"/>
        <source>Working directory:</source>
        <translation>Katalog roboczy:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="82"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Polecenie zostanie wykonane w tym katalogu. Jeśli pozostawisz to pole pustym, katalog roboczy nie będzie zmieniony.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>Launch automatically</source>
        <translation>Uruchom automatycznie</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="85"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Jeśli zaznaczone, aplikacja zostanie uruchomiona automatycznie, gdy tylko przejdziesz do strony z nagrywaniem. Jeśli nie zaznaczone, nagrywanie będzie musiało zostać uruchomione ręcznie.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="87"/>
        <source>Launch now</source>
        <translation>Uruchom teraz</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="108"/>
        <source>Stream settings</source>
        <translation>Opcje wideo</translation>
    </message>
    <message>
        <source>Source:</source>
        <translation type="obsolete">Źródło:</translation>
    </message>
    <message>
        <source>Start the OpenGL application automatically</source>
        <translation type="obsolete">Uruchom aplikację OpenGL automatycznie</translation>
    </message>
    <message>
        <source>If checked, the above command will be executed automatically (combined with some environment variables). If not checked,
you have to start the OpenGL application yourself (the full command, including the required environment variables, is shown in the log).</source>
        <translation type="obsolete">Po zaznaczeniu powyższe polecenie (wraz z kilkoma zmiennymi środowiskowymi) zostanie automatycznie uruchomione.
Jeśli nie zaznaczone, aplikacja OpenGL będzie musiała być uruchomiona oddzielnie(kompletne polecenie wraz z zmiennymi środowiskowymi można znaleźć w logu).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Złagodź uprawnienia do pamięci współdzielonej (potencjalnie ryzykowne)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Po zaznaczeniu inni użytkownicy na tej samej maszynie będą mieli dostęp do pamięci współdzielonej wykorzystywanej do komunikacji z aplikacją OpenGL.
To oznacza (teoretycznie) że inni użytkownicy mogą oglądać to co nagrywasz, modyfikować klatki, wstawiać własne klatki lub po prostu zakłócać komunikację.
Dotyczy to również użytkowników zalogowanych zdalnie (ssh). Zaleca się jedynie w przypadku nagrywania jako inny użytkownik.</translation>
    </message>
    <message>
        <source>Maximum image size (megapixels):</source>
        <translation type="obsolete">Maksymalny rozmiar obrazu (w megapikselach):</translation>
    </message>
    <message>
        <source>This setting changes the amount of shared memory that will be allocated to send frames back to the main program.
The size of the shared memory can&apos;t be changed anymore once the program has been started, so if the program you
are trying to record is too large, recording won&apos;t work. 2 megapixels should be enough in almost all cases. Be careful,
high values will use a lot of memory!</source>
        <translation type="obsolete">Ta opcja zmienia rozmiar pamięci współdzielonej jak będzie zarezerwowana do przesyłania klatek do głównego programu.
Po uruchomieniu aplikacji nie będzie możliwości zmiany tego parametru. Jeśli nagrywany program jest zbyt duży nagrywanie
nie będzie działało. 2 megapiksele powinny wystarczyć w większości przypadków.
Durze wartości będą zajmowały większa ilości pamięci!</translation>
    </message>
    <message>
        <source>Capture front buffer instead of back buffer</source>
        <translation type="obsolete">Przechwytuj z przedniego bufora</translation>
    </message>
    <message>
        <source>If checked, the injected library will read the front buffer (the frame that&apos;s currently on the screen) rather than the back buffer
(the new frame). This may be useful for some special applications that draw directly to the screen.</source>
        <translation type="obsolete">Po zaznaczeniu wstrzyknięta biblioteka będzie czytała z przedniego bufora (aktualnie wyświetlana klatka) zamiast tylnego bufora
(następna klatka). Przydatne dla aplikacji rysujących bezpośrednio na ekranie.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>Limit application frame rate</source>
        <translation>Ograniczenie klatek na sekundę aplikacji</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="111"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Po zaznaczeniu wstrzyknięta biblioteka spowolni aplikację do prędkości nagrywania. Dzięki czemu aplikacja nie będzie marnowała
zasobów na klatki które nie będą nagrane oraz może sprawić że nagranie będzie płynniejsze (zależy od aplikacji).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="120"/>
        <source>Close</source>
        <translation>Zamknij</translation>
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
        <translation type="unfinished">Zamknij</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Błąd: współczynnik próbkowania poza skalą! </translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Błąd: współczynnik przesunięcia poza skalą! </translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Współczynnik próbkowania wynosi %1 (było %2).</translation>
    </message>
    <message>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="obsolete">Uwaga: Format pikseli nie jest wspierany (%1 -&gt; %2), w zamian zostanie użyty swscale. To nie jest problem lecz wydajność będzie gorsza.</translation>
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
        <translation>Błąd: nie można otrzymać kontekstu swcale!</translation>
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
        <translation>Uwaga: pamięć nie jest poprawnie wyrównana dla SSE, użyto konwertera &apos;fallback&apos;. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Uwaga: nastąpił overrun, część próbek została utracona.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="37"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Błąd: nie można przywrócić urządzenia po zdarzeniu overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="41"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Błąd: bie można uruchomić urządzenia PCM po zdarzeniu overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="71"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="59"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="66"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation>Zatrzymywanie wejściowego wątku...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="102"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation>Generowanie listy źródeł...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="121"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Błąd: Nie udało się zaktualizować konfiguracji ALSY!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Uwaga: Nie udało się otworzyć karty dźwiękowej %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="187"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Uwaga: nie udało się pozyskać informacji nt karty dźwiękowej %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="168"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Znaleziono wtyczkę: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="191"/>
        <source>Found card: [%1] %2</source>
        <translation>Znaleziono kartę: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="216"/>
        <source>Found device: [%1] %2</source>
        <translation>Znaleziono urządzenie: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="271"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Błąd: nie można otworzyć urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Błąd: nie można odczytać parametrów urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="281"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Błąd: nie można ustawić trybu pracy!</translation>
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
        <translation>Błąd: nie można ustawić formatu próbkowania!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="330"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Błąd: nie mozna ustawić częstotliwości próbkowania!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>UWaga: częstotliwość próbkowania %1 nie jest obsługiwana. W zamian zostanie użyta częstotliwość %2. Nie jest to błąd krytyczny.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="343"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Błąd: Nie można ustawić liczby kanałów!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="347"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uwaga: liczba kanałów %1 nie jest obsługiwana. Zostaną użyte %2. To nie jest błąd krytyczny.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="356"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Błąd: Nie można ustawić rozmiaru cyklu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="360"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uwaga: rozmiar cyklu %1 nie jest wspierany, użyto %2. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="369"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Błąd: nie można ustawić rozmiaru bufora!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uwaga: rozmiar bufora %1 nie jest obsługiwany, zostanie użyty rozmiar %2. To nie jest błąd krytyczny.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="381"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Błąd: Nie można ustawić parametrów urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="407"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Błąd: Nie można uruchomić urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="428"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="263"/>
        <location filename="../AV/Input/X11Input.cpp" line="465"/>
        <source>Input thread started.</source>
        <translation>Uruchomiono wątek wejścia.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="452"/>
        <source>Error: Can&apos;t wait for new samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation type="obsolete">Błąd: Nie można sprawdzić czy próbki są dostępne!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="469"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Błąd: Nie można odczytać próbki!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="500"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="358"/>
        <location filename="../AV/Input/JACKInput.cpp" line="302"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="294"/>
        <location filename="../AV/Input/X11Input.cpp" line="585"/>
        <source>Input thread stopped.</source>
        <translation>Zatrzymano wątek wejścia.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="504"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="362"/>
        <location filename="../AV/Input/JACKInput.cpp" line="306"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="589"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Wyjątek &apos;%1&apos; w wątku wejścia.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="507"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="365"/>
        <location filename="../AV/Input/JACKInput.cpp" line="309"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="301"/>
        <location filename="../AV/Input/X11Input.cpp" line="592"/>
        <source>Unknown exception in input thread.</source>
        <translation>Nieznany wyjątek w wątku wejścia.</translation>
    </message>
    <message>
        <source>Error: Image is too small!</source>
        <translation type="obsolete">Błąd: Obraz jest zbyt mały!</translation>
    </message>
    <message>
        <source>Error: Image is too large!</source>
        <translation type="obsolete">Błąd: Obraz jest zbyt duży!</translation>
    </message>
    <message>
        <source>Error: Image doesn&apos;t fit in memory!</source>
        <translation type="obsolete">Błąd: Obraz nie mieści się w pamięci!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="318"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Błąd: Pamięć współdzielona jest nie osiągalna!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="323"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Błąd: Nie można nawiązać połączenia z pamięcią współdzieloną!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation type="obsolete">Błąd: Nie ma dostępu do pamięci współdzielonej klatki!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation type="obsolete">Błąd: Nie można połączyć się z pamięcią współdzieloną klatki!</translation>
    </message>
    <message>
        <source>Full command</source>
        <translation type="obsolete">Całe polecenie</translation>
    </message>
    <message>
        <source>Error: Can&apos;t run command!</source>
        <translation type="obsolete">Błąd: nie można wykonać polecenia!</translation>
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
        <translation type="unfinished">Błąd: pa_mainloop_prepare zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="38"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="unfinished">Błąd: pa_mainloop_poll zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="42"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="unfinished">Błąd: pa_mainloop_dispatch zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="52"/>
        <source>Error: Could not create main loop!</source>
        <translation type="unfinished">Błąd: Nie można utworzyć głównej pętli!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="59"/>
        <source>Error: Could not create context!</source>
        <translation type="unfinished">Błąd: Nie można utworzyć kontekstu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation type="unfinished">Błąd nie można się połączyć! Powód: %1
Możliwe że twój system nie korzysta z PulseAudio. Spróbuj użyć podsystemu ALSA.</translation>
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
        <translation type="unfinished">Błąd: Próba połączenia zawiodła! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="119"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="unfinished">Błąd: Nie można stworzyć strumienia! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="126"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="unfinished">Błąd: Nie można połączyć strumienia! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="137"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="unfinished">Błąd: Prób połączenia strumienia zawiodła! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="228"/>
        <source>Found source: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="249"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="unfinished">Błąd: Nie udało się odczytać nazw źródeł! Powód: %1</translation>
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
        <translation type="unfinished">Błąd: pa_stream_peek zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="416"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="unfinished">Uwaga: Źródło audio zostało wstrzymane. Aktualny segment zostanie zatrzymany do momentu wznowienia źródła.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="421"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="unfinished">Uwaga: Strumień został przesunięty do innego źródła.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="68"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="unfinished">Błąd: Nie wspierany format pikseli X11 obrazu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="41"/>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="118"/>
        <source>Error: Width or height is zero!</source>
        <translation type="unfinished">Błąd: Wysokość lub szerokość wynosi zero!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="45"/>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="122"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="unfinished">Błąd: Szerokość lub wysokość jest zbyt duża, maksymalna wysokość i szerokość wynosi %1!</translation>
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
        <translation type="unfinished">Błąd: Nie można otworzyć X display!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="266"/>
        <source>Using X11 shared memory.</source>
        <translation type="unfinished">Korzystanie z pamięci współdzielonej X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="313"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="unfinished">Błąd: Nie można utworzyć współdzielonego obrazu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="268"/>
        <source>Not using X11 shared memory.</source>
        <translation type="unfinished">Nie użyto pamięci współdzielonej X11.</translation>
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
        <translation type="obsolete">Uwaga: XFixes nie jest wspierane przez serwer, kursor został schowany.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="406"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="unfinished">Błąd: Błędny zakres pola ekranu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="328"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="unfinished">Błąd: Nie można połączyć serwera z pamięcią współdzieloną!</translation>
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
        <translation type="unfinished">Ekran %1:</translation>
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
        <translation type="unfinished">Błąd: Nie otrzymano obrazu (wykorzystując pamięć współdzieloną)!
    Zazwyczaj oznacza to że nagrywany obszar wkracza poza ekran. Czy zmieniono rozdzielczość ekranu?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="547"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished">Błąd: Nie otrzymano obrazu (bez wykorzystywania pamięci współdzielonej)!
    Zazwyczaj oznacza to że nagrywany obszar wkracza poza ekran. Czy zmieniono rozdzielczość ekranu?</translation>
    </message>
    <message>
        <source>Error: Sample rate it zero.</source>
        <translation type="obsolete">Błąd: Częstotliwość próbkowania wynosi zero.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="172"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation type="unfinished"></translation>
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
        <translation type="unfinished">Błąd: Koder wymaga nie wspieranego formatu próbkowania!</translation>
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
        <translation type="unfinished">Błąd: Kodowanie audio zawiodło!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation type="unfinished">Zatrzymywanie wątku kodowania ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="267"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="unfinished">Błąd: Kodek nie został odnaleziony!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="277"/>
        <source>Using codec %1 (%2).</source>
        <translation type="unfinished">Kodek %1 (%2) został użyty.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="320"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="unfinished">Uwaga: Ten kodek jest uważany za eksperymentalny przez libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="30"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="39"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="164"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="unfinished">Błąd: Nie można otworzyć kodeka!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="188"/>
        <source>Encoder thread started.</source>
        <translation type="unfinished">Rozpoczęto wątek kodowania.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="217"/>
        <source>Flushing encoder ...</source>
        <translation type="unfinished">Oczyszczanie kodera ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="228"/>
        <source>Encoder thread stopped.</source>
        <translation type="unfinished">Zatrzymano wątek kodowania.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="unfinished">Wyjątek &apos;%1&apos; w wątku kodera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="235"/>
        <source>Unknown exception in encoder thread.</source>
        <translation type="unfinished">Nieznany wyjątek w wątku kodera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="70"/>
        <source>Stopping encoders ...</source>
        <translation type="unfinished">Zatrzymywanie kodera ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="77"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="unfinished">Oczekiwanie na zakończenie wątku multipleksowania ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="146"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="unfinished">Błąd: Nie można zapisać nagłówka (&apos;header&apos;)!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="157"/>
        <source>Finishing encoders ...</source>
        <translation type="unfinished">Zakańczanie koderów ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="288"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="unfinished">Błąd: Nie udało się rozpocząć nowego strumienia!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="307"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="unfinished">Błąd: Nie otrzymano kontekstu kodeka!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="unfinished">Błąd: Nie znaleziono formatu wyjścia!</translation>
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
        <translation type="unfinished">Użyto formatu %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="209"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="unfinished">Błąd: Nie można przydzielić kontekstu formatu!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="unfinished">Błąd: Nie można otworzyć pliku wyjściowego!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="229"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="unfinished">Błąd: nie można zapisać &apos;trailer&apos;, mimo to kontynuowano.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="295"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="336"/>
        <source>Muxer thread started.</source>
        <translation type="unfinished">Uruchomiono wątek multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="396"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="unfinished">Błąd: Nie można zapisać klatki do multipleksera!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="424"/>
        <source>Muxer thread stopped.</source>
        <translation type="unfinished">Zatrzymano wątek multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="428"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="unfinished">Wyjątek &apos;%1&apos; w wątku multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="431"/>
        <source>Unknown exception in muxer thread.</source>
        <translation type="unfinished">Nieznany wyjątek w wątku multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="220"/>
        <source>Stopping synchronizer thread ...</source>
        <translation type="unfinished">Zatrzymywanie wątku synchronizacji ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="328"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="unfinished">Uwaga: Otrzymano wideo z nie monotonicznym znacznikiem czasu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="355"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="unfinished">Uwaga: Przepełniono bufor wideo, niektóre klatki zostaną utracone. Wejście audio wygląda na zbyt wolne.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="412"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="unfinished">Uwaga: Otrzymano audio z nie monotonicznym znacznikiem czasu.</translation>
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
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="515"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="unfinished">Uwaga: Wejście audio jest o 2% zbyt szybkie!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="554"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="unfinished">Uwaga: Przepełniono bufor audio, rozpoczęto kolejny segment by utrzymać audio w synchronizacji z wideo (część wideo i/lub audio może zostać utracone). Wejście wideo wygląda na zbyt wolne.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="590"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="891"/>
        <source>Synchronizer thread started.</source>
        <translation type="unfinished">Rozpoczęto wątek synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="913"/>
        <source>Synchronizer thread stopped.</source>
        <translation type="unfinished">Zatrzymano wątek synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="917"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="unfinished">Wyjątek &apos;%1&apos; w wątku synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="920"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="unfinished">Nieznany wyjątek w wątku synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="49"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="126"/>
        <source>Error: Width or height is not an even number!</source>
        <translation type="unfinished">Błąd: Szerokość lub wysokość nie jest liczbą parzystą!</translation>
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
        <translation type="obsolete">Błąd: Ilość klatek na sekundę wynosi zero!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="263"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="284"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="unfinished">Błąd: Kodowanie wideo zawiodło!</translation>
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
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="91"/>
        <source>Stopping synth thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="224"/>
        <source>Synth thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="277"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="285"/>
        <source>Synth thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="289"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="292"/>
        <source>Unknown exception in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="45"/>
        <source>CPU features</source>
        <translation type="unfinished">Opcje procesora</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="90"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="98"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="unfinished">Błąd: Opcja &apos;%1&apos; wiersza poleceń nie przyjmuje wartości!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="195"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="unfinished">Błąd: Nieznana opcja wiersza poleceń: &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="203"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="unfinished">Błąd: Nieznany argument wiersza poleceń: &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="253"/>
        <source>Error: Can&apos;t create configuration directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="99"/>
        <source>SSR started</source>
        <translation type="unfinished">SSR wystartował</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="133"/>
        <source>SSR stopped</source>
        <translation type="unfinished">SSR zatrzymany</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="obsolete">Błąd: Nie można utworzyć lokacji .ssr!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="259"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation type="unfinished"></translation>
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
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>The application could not be launched.</source>
        <translation type="unfinished"></translation>
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
        <translation>SimpleScreenRecorder wykrył że korzystasz z własnościowych sterowników NVIDIA z włączoną opcją &apos;flipping&apos; która powoduje błędy w trakcie nagrywania. Zalecane jest jej wyłączenie. Chcesz bym to za ciebie zrobił?

Możesz zmienić tę opcję samodzielnie w panelu kontrolnym NVIDIA.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="104"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Z nieznanych przyczyn nie mogłem wyłączyć opcji &apos;flipping&apos; - przykro mi! Spróbuj wyłączyć ją w panelu kontrolnym NVIDIA..</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="31"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Nagranie zostało zapisane. Możesz już je edytować lub ponownie zakodować z lepszymi ustawieniami w celu zmniejszenia rozmiaru pliku (domyślne ustawienia są zoptymalizowane pod katem jakości oraz szybkości nie rozmiaru pliku).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="35"/>
        <source>Open folder</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="38"/>
        <source>Back to the start screen</source>
        <translation>Powrót do początkowego ekranu</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="273"/>
        <source>Video input</source>
        <translation>Wejście wideo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record the entire screen</source>
        <translation>Nagrywaj cały ekran</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>Record a fixed rectangle</source>
        <translation>Nagrywaj wskazany obszar</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="278"/>
        <source>Follow the cursor</source>
        <translation>Śledź kursor</translation>
    </message>
    <message>
        <source>Record OpenGL (experimental)</source>
        <translation type="obsolete">Nagrywanie OpenGL (eksperymentalne)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Input profile</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="280"/>
        <source>Record OpenGL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="283"/>
        <source>Record V4L2 device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="295"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Wybierz który monitor ma być nagrywany jeśli posiadasz więcej niż jeden.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="296"/>
        <source>Record entire screen with cursor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="297"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="298"/>
        <source>Select rectangle...</source>
        <translation>Wyznacz obszar...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="299"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Wyznacz obszar do nagrywania przy pomocy myszki.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="300"/>
        <source>Select window...</source>
        <translation>Zaznacz okno...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="301"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Korzystając z myszy zaznacz obszar do nagrywania.
Podpowiedź: Jeżeli klikniesz obramowanie okna, wówczas całe okno zostanie zaznaczone(wraz z obramowaniem).
W przeciwnym razie jedynie wnętrze okna będzie nagrywane.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="305"/>
        <source>OpenGL settings...</source>
        <translation>Opcje OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="306"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Zmień ustawienia nagrywania OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="310"/>
        <source>The V4L2 device to record (e.g. /dev/video0).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Left:</source>
        <translation>Lewo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="316"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Położenie X górnego-lewego rogu obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="318"/>
        <source>Top:</source>
        <translation>Góra:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="322"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Położenie Y górnego-lewego rogu obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="324"/>
        <source>Width:</source>
        <translation>Szerokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="328"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Szerokość obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="330"/>
        <source>Height:</source>
        <translation>Wysokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="334"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Wysokość obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="336"/>
        <source>Frame rate:</source>
        <translation>Liczba klatek na sekundę:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="340"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Liczba klatek na sekundę z jaką będzie nagrywany obraz. Wyższe wartości wykorzystują bardziej CPU.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="341"/>
        <source>Scale video</source>
        <translation>Skaluj wideo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="342"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Włącz lub wyłącz skalowanie nagrania. Skalowanie zwiększa wykorzystanie procesora lecz może skrócić czas kodowania jeśli obraz jest mniejszy.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="343"/>
        <source>Scaled width:</source>
        <translation>Przeskalowana szerokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="347"/>
        <source>Scaled height:</source>
        <translation>Przeskalowana wysokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="351"/>
        <source>Record cursor</source>
        <translation>Nagraj kursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="441"/>
        <source>Audio input</source>
        <translation>Wejście audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="443"/>
        <source>Record audio</source>
        <translation>Nagrywaj audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="444"/>
        <source>Backend:</source>
        <translation>Podsystem:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="459"/>
        <source>The audio backend that will be used for recording.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation type="obsolete">Urządzenie ALSA które będzie wykorzystywane do nagrywania. Wartość standardowa: &apos;default&apos;.
Możesz zmienić tą wartość na np: plughw:0,0 (co oznacza Karta dźwiękowa 0 oraz wejście 0 z włączonymi wtyczkami).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="474"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Źródło PulseAudio które będzie wykorzystywane do nagrywania.
&apos;monitor&apos; jest źródłem które przechwytuje audio z innych aplikacji.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="481"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Jeśli zaznaczone, porty zostaną automatycznie podłączone do nagrywanych portów systemowych.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="483"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Jeśli zaznaczone, porty zostaną automatycznie podłączone do czegokolwiek, co łączy się systemowymi portami odtwarzania.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="964"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Wszystkie ekrany: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="968"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Ekran %1: %2x%3 poz. %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1206"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Ekran %1</translation>
    </message>
    <message>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation type="obsolete">Nie wprowadzono polecenia uruchamiającego aplikację OpenGL którą chcesz nagrać.
Kliknij &apos;Opcje OpenGL&apos; w celu wprowadzenia polecenia.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="456"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Podsystem audio który bedzie wykorzystywany do nagrywania.
Podsystem ALSA bęzie również działał na systemach które korzystają z PulseAudio, aczkolwiek sugerowane jest korzystanie z PulseAudio.</translation>
    </message>
    <message>
        <source>Device:</source>
        <translation type="obsolete">Urządzenie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="462"/>
        <location filename="../GUI/PageInput.cpp" line="471"/>
        <source>Source:</source>
        <translation>Źródło:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="465"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Urządzenie ALSY, które zostanie wykorzystane do nagrywania.
&apos;default&apos; na ogół jest w porządku. Urządzenia &apos;shared&apos; pozwalają nagrywać kiulku programom naraz, ale mogą być bardziej zawodne.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="467"/>
        <location filename="../GUI/PageInput.cpp" line="476"/>
        <source>Refresh</source>
        <translation>Odśwież</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="468"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Odśwież listę urządzeń ALSY.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="477"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Odśwież listę źródeł PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="480"/>
        <source>Record system microphone</source>
        <translation>Nagrywaj systemowym mikrofonem</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="482"/>
        <source>Record system speakers</source>
        <translation>Nagrywaj systemowe głośniki</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="530"/>
        <source>Back</source>
        <translation>Wstecz</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="531"/>
        <source>Continue</source>
        <translation>Kontynuuj</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>Inny...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>Nieskompresowany</translation>
    </message>
    <message>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation type="obsolete">pliki</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="173"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Błąd: Nie znaleziono odpowiednich kontenerów w libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Błąd: Nie znaleziono odpowiednich kodeków w libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Błąd: Nie znaleziono odpowiednich kodeków audio w libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Output profile</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="191"/>
        <source>File</source>
        <translation>Plik</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="193"/>
        <source>Save as:</source>
        <translation>Zapisz jako:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="195"/>
        <source>The recording will be saved to this location.</source>
        <translation>Nagranie zostanie zapisane w tej lokalizacji.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="196"/>
        <source>Browse...</source>
        <translation>Przeglądaj...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>Separate file per segment</source>
        <translation type="unfinished">Oddzielne pliki na segment</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation type="obsolete">Po zaznaczeniu, oddzielny plik zostanie utworzony przy każdym zatrzymaniu i wznowieniu nagrywania.
Jeżeli oryginalna nazwa pliku brzmi &apos;test.mkv&apos;,segmenty zostaną zapisane jako &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
Nazwy plików które już istnieją zostaną pominięte.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="203"/>
        <source>Container:</source>
        <translation>Kontener:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="208"/>
        <source>(not installed)</source>
        <translation>(nie zainstalowany)</translation>
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
        <translation>Kontener (format pliku) jaki zostanie wykorzystany do zapisania nagrania.
Miej na uwadze że nie wszystkie kodeki są wspierane przez wszystkie kontenery oraz nie wszystkie odtwarzacze potrafią odczytać wszystkie formaty plików.
- Matroska (MKV) wspiera wszystkie kodeki lecz jest mniej znany.
- MP4 jest najbardziej znanym formatem i może być odtwarzany na prawie wszystkich współczesnych odtwarzaczach multimedialnych lecz wspiera wyłącznie
kodowanie H.264 (oraz wiele odtwarzaczy wspiera wyłącznie kodowanie audio AAC).
- WebM jest przeznaczone do filmów wbudowanych w strony internetowe(przy wykorzystaniu tagu HTML5 &lt;video&gt;). format został stworzony przez Google.
WebM jest domyślnie wspierany przez Firefox, Chrome oraz Operę, są również dostępne wtyczki do Internet Explorer oraz Safari.
Wspiera wyłącznie VP8 i Vorbis.
- OGG wspiera wyłącznie Theorę i Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Container name:</source>
        <translation>Nazwa kontenera:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Dla zaawansowanych użytkowników. Można wykorzystać dowolny format libav/ffmpeg lecz mogą okazać się nie przydatne lub nie działać.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <source>Video</source>
        <translation>Wideo</translation>
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
        <translation>Kodek który zostanie wykorzystany do kompresji wideo.
- H.264 (libx264) jest to zdecydowanie najlepszy kodek - wysoka jakość oraz prędkość.
- VP8 (libvpx) jest stosunkowo dobry lecz dość wolny.
- Theora (libtheora) nie jest zalecany ponieważ jakość nie jest zbyt dobra.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Codec name:</source>
        <translation>Nazwa kodeka:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Dla zaawansowanych użytkowników. Można wykorzystać dowolny format libav/ffmpeg lecz mogą okazać się nie przydatne lub nie działać.</translation>
    </message>
    <message>
        <source>Bit rate (in kbps):</source>
        <translation type="obsolete">Szybkość transmisji (w kb/s):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Szybkość transmisji wideo (w kilobitach na sekundę). Wyższe wartości oznaczają wyższą jakość.
Jeżeli nie wiesz od jakiej wartości zacząć, spróbuj 5000 i zmieniaj w miarę potrzeb.</translation>
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
        <translation>CPU used:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="292"/>
        <source>fastest</source>
        <translation>najszybsze</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <source>slowest</source>
        <translation>najwolniejsze</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="298"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Szybkość kodowania. Wyższa wartość oznacza *mniejsze* użycie procesora (nazwa nie jest moim pomysłem
i jest wykorzystywana przez VP8). Wyższe wartości skutkują gorszą jakością chyba że zwiększysz Szybkość transmisji.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Zmiana wartości wpływa na jakość wideo. Niższa wartość oznacza lepsza jakość.
Dopuszczalny przedział wartości: 0-51 (0 oznacza bezstratne, domyślnie 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <location filename="../GUI/PageOutput.cpp" line="85"/>
        <location filename="../GUI/PageOutput.cpp" line="88"/>
        <location filename="../GUI/PageOutput.cpp" line="91"/>
        <location filename="../GUI/PageOutput.cpp" line="133"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>pliki %1</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="obsolete">Jeśli zaznaczone, nowy plik wideo powstanie za każdym razem, gdy wstrzymasz i wznowisz nagrywanie.
Jeśli orignalna nazwa pliku to &quot;test.mkv&quot;, powstałe pliki zostaną zapisane jako &quot;test-ROK-MIESIAC-DZIEN_GODZINA.MINUTA.SEKUNDA.mkv&quot;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <source>Add timestamp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="unfinished"></translation>
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
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="288"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Tempo kodowania. Wyższa wartość wykorzystuje procesor w mniejszym stopniu (pozwalając na nagrywanie
z większą ilością klatek na sekundę) lecz powoduje że plik końcowy będzie większy. Jakość nie powinna ulec zmianie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <location filename="../GUI/PageOutput.cpp" line="355"/>
        <source>Custom options:</source>
        <translation>Ustawienia niestandardowe:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <location filename="../GUI/PageOutput.cpp" line="357"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Ustawienia niestandardowe kodeka oddzielone przecinkiem (np. opcja1=wartość1,opcja2=wartość2,opcja3=wartośc3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Allow frame skipping</source>
        <translation>Zezwól na pomijanie klatek</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="304"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Po zaznaczeniu koder będzie pomijał klatki jeżeli ilość klatek na wejściu będzie niższa niż na wyjściu.
W przypadku nie zaznaczenia klatki będą dublowane by wypełnić luki. Zwiększy to rozmiar pliku
oraz wykorzystanie procesora lecz zmniejsza opóźnienie w trakcie stremowania na żywo w niektórych przypadkach.
Nie powinno mieć wpływu na wygląd wideo.</translation>
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
        <translation>Kodek jaki zostanie wykorzystany do kompresji audio. Nie powinieneś się tym za bardzo przejmować
ponieważ rozmiar danych audio jest mniej istotny w porównaniu do danych wideo.
Jeżeli nagrywasz wyłącznie swój głos (bez muzyki) jakość nie będzie miała aż takiego znaczenia.
- Vorbis (libvorbis) jest świetny. Jest to zalecany kodek..
- MP3 (libmp3lame) jest dość dobry..
- AAC jest dobrym kodekiem ale wykorzystana implementacja (libvo_aacenc lub eksperymentalny koder fmpeg aac)
są słabe. Korzystaj wyłącznie przy braku innych opcji.
- Nie kompresowane oznacza że dźwięk nie będzie kompresowany. Plik będzie duży lecz nagrywanie będzie szybsze.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Dla zaawansowanych użytkowników. Można wykorzystać dowolny format libav/ffmpeg lecz mogą okazać się nie przydatne lub nie działać.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Szybkość transmisji audio (w kilobitach na sekundę). Wyższe wartości oznaczają wyższą jakość. Standardową wartością jest 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="379"/>
        <source>Back</source>
        <translation>Wstecz</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="380"/>
        <source>Continue</source>
        <translation>Kontynuuj</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="637"/>
        <location filename="../GUI/PageOutput.cpp" line="645"/>
        <source>not installed</source>
        <translation>nie zainstalowano</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <location filename="../GUI/PageOutput.cpp" line="647"/>
        <source>not supported by container</source>
        <translation>nie wspierane przez kontener</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="690"/>
        <source>Save recording as</source>
        <translation>Zapisz nagranie jako</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="528"/>
        <source>You did not select an output file!</source>
        <translation>Nie wskazano pliku do zapisania!</translation>
    </message>
    <message>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation type="obsolete">Plik &apos;%1&apos; już istnieje. Na pewno chcesz go nadpisać?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="176"/>
        <source>Recording</source>
        <translation>Nagranie</translation>
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
        <translation>Zezwól na skrót klawiszowy</translation>
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
        <translation>Włącz powiadomienia dźwiękowe</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="191"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="193"/>
        <source>Hotkey:</source>
        <translation>Skrót:</translation>
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
        <translation>Klawisz (wraz z modyfikatorem) przy pomocy którego uruchomisz/zatrzymasz nagrywanie.
Aplikacja którą nagrywasz nie przechwyci tych klawiszy.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="252"/>
        <source>Information</source>
        <translation>Informacje</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="254"/>
        <source>Total time:</source>
        <translation>Czas całkowity:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="256"/>
        <source>FPS in:</source>
        <translation>Klatki/s (wejście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="258"/>
        <source>FPS out:</source>
        <translation>klatki/s (wyjście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="260"/>
        <source>Size in:</source>
        <translation>Rozmiar (wejście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="262"/>
        <source>Size out:</source>
        <translation>Rozmiar (wyjście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="264"/>
        <source>File name:</source>
        <translation>Nazwa pliku:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="267"/>
        <source>File size:</source>
        <translation>Rozmiar pliku:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="269"/>
        <source>Bit rate:</source>
        <translation>Szybkość transmisji:</translation>
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
        <translation>Podgląd</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="301"/>
        <source>Preview frame rate:</source>
        <translation>Klatki na sekundę podglądu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="305"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Uwaga: Podgląd wykorzystuje dodatkowo procesor (zwłaszcza przy dużej liczbie klatek na sekundę).</translation>
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
        <translation>Anuluj nagranie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="370"/>
        <location filename="../GUI/PageRecord.cpp" line="379"/>
        <source>Save recording</source>
        <translation>Zapisz nagranie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="384"/>
        <source>Quit</source>
        <translation>Wyjście</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="435"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Nie zapisano aktualnego nagrania. Jeżeli teraz wyjdziesz zostanie ono utracone.
Czy na pewno chcesz wyjść?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="447"/>
        <source>Hide window</source>
        <translation>Ukryj okno</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="449"/>
        <source>Show window</source>
        <translation>Pokaż okno</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="793"/>
        <source>Output file: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1022"/>
        <source>Encoding remaining data ...</source>
        <translation>Kończenie procesu kodowania...</translation>
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
        <location filename="../GUI/PageRecord.cpp" line="779"/>
        <source>Starting output ...</source>
        <translation>Uruchamianie wyjścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="804"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Błąd: Nie udało się uzyskać wymiarów okna aplikacji OpenGL ponieważ wejście GLInject nie zostało utworzone.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="848"/>
        <source>Started output.</source>
        <translation>Uruchomiono wyjście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="869"/>
        <source>Stopping output ...</source>
        <translation>Zatrzymywanie wyjścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="887"/>
        <source>Stopped output.</source>
        <translation>Zatrzymano wyjście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="919"/>
        <source>Starting input ...</source>
        <translation>Uruchamianie wejścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="930"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Błąd: Nie udało się uruchomić wejścia GLInject ponieważ nie zostało ono utworzone.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="956"/>
        <source>Started input.</source>
        <translation>Uruchomiono wejście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="988"/>
        <source>Stopping input ...</source>
        <translation>Zatrzymywanie wejścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1006"/>
        <source>Stopped input.</source>
        <translation>Zatrzymano wejście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="659"/>
        <source>Starting page ...</source>
        <translation>Uruchamianie strony ...</translation>
    </message>
    <message>
        <source>Error: Something went wrong during GLInject initialization.</source>
        <translation type="obsolete">Błąd: Coś poszło nie tak przy inicjalizacji GLInject.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="690"/>
        <source>Started page.</source>
        <translation>Uruchomiono stronę.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="723"/>
        <source>Stopping page ...</source>
        <translation>Zatrzymywanie strony ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="750"/>
        <source>Stopped page.</source>
        <translation>Zatrzymano stronę.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application because GLInject has not been started.</source>
        <translation type="obsolete">Błąd: Nie udało się przechwycić rozmiaru aplikacji OpenGL ponieważ GLInject nie został uruchomiony.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="809"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Błąd: Nie udało się przechwycić rozmiaru aplikacji OpenGL. Aplikacja nie została prawidłowo uruchomiona lub aplikacja nie stworzyła jeszcze okna OpenGL. Jeżeli chcesz rozpocząć nagrywanie przed uruchomieniem aplikacji musisz zezwolić na skalowanie oraz ręcznie wprowadzić rozmiar wideo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="681"/>
        <location filename="../GUI/PageRecord.cpp" line="858"/>
        <location filename="../GUI/PageRecord.cpp" line="961"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Błąd: Coś poszło nie tak w trakcie inicjalizacji.</translation>
    </message>
    <message>
        <source>Error: Could not create a GLInject input because GLInject has not been started.</source>
        <translation type="obsolete">Błąd: Nie udało się stworzyć wejścia GLInject ponieważ GLInject nie został uruchomiony.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1116"/>
        <location filename="../GUI/PageRecord.cpp" line="1126"/>
        <source>Pause recording</source>
        <translation>Wstrzymaj nagrywanie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1119"/>
        <location filename="../GUI/PageRecord.cpp" line="1129"/>
        <source>Start recording</source>
        <translation>Rozpocznij nagrywanie</translation>
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
        <translation>Zatrzymaj podgląd</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1159"/>
        <source>Start preview</source>
        <translation>Rozpocznij podgląd</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1200"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Błąd: Coś poszło nie tak podczas tworzenia synth.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1264"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Czy na pewno chcesz anulować to nagrywanie?</translation>
    </message>
    <message>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation type="obsolete">Jeszcze nic nie zostało nagrane, nie ma czego zapisać.

Przycisk start jest na górze ;).</translation>
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
        <translation>&lt;p&gt;Witaj w SimpleScreenRecorder&lt;/p&gt;

&lt;p&gt;Wbrew temu co może sugerować nazwa ta aplikacja posiada wiele możliwości. Nie obawiaj się jednak ponieważ są tylko dwie rzeczy jakie powinieneś wiedzieć . Po pierwsze, domyślne wartości są zwykle wystarczające. Jeżeli nie wiesz do czego coś służy pozostaw wartość domyślną. Po drugie, prawie wszystkie opcje mają podpowiedzi. Wystarczy nakierować myszką na dany obiekt by dowiedzieć się do czego służy.&lt;/p&gt;

&lt;p&gt;Dalsze informacje na:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="51"/>
        <source>About SimpleScreenRecorder</source>
        <translation>O SimpleScreenRecorder</translation>
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
        <translation>Kontynuuj</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <source>Profile</source>
        <translation type="obsolete">Profil</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Zapisz</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Zapisz bieżące ustawienia w tym profilu.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Nowy</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Stwórz nowy profil na podstawie bieżących ustawień.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Usuń</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Usuń profil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(brak)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Błąd: nie udało się załadować profilu!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Czy napewno chcesz nadpisać profil?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Wprowadź nazwę dla nowego profilu:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Profil o takiej nazwie już istnieje. Czy na pewno chcesz go nadpisać?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Czy na pewno chcesz usunąć ten profil?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation>&amp;Ok</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation>&amp;Anuluj</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Tak</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Tak, zawsze</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Nie</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Nie, nigdy</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <source>CPU features</source>
        <translation type="obsolete">Opcje procesora</translation>
    </message>
    <message>
        <source>BGRA to YUV420 converter</source>
        <translation type="obsolete">Konwerter BGRA na YUV420</translation>
    </message>
    <message>
        <source>X86-specific instructions are disabled.</source>
        <translation type="obsolete">Szczegółowe instrukcje X86 są wyłączone.</translation>
    </message>
    <message>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="obsolete">Uwaga: Format pikseli nie jest wspierany (%1 -&gt; %2), w zamian zostanie użyty swscale. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <source>Using swscale for scaling.</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="obsolete">Wykorzystywanie swscale do skalowania.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="obsolete">Błąd: nie można otrzymać kontekstu swcale!</translation>
    </message>
    <message>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="obsolete">Uwaga: Pamięć nie jest poprawnie ustawiona do SSE, użyto konwertera &apos;fallback&apos;. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation type="obsolete">Błąd: nie można otworzyć urządzenia PCM!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation type="obsolete">Błąd: nie można otrzymać parametrów urządzenia PCM!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set access type!</source>
        <translation type="obsolete">Błąd: nie można ustawić typu dostępu!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample format!</source>
        <translation type="obsolete">Błąd: nie można ustawić formatu próbkowania!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation type="obsolete">Błąd: nie mozna ustawić częstotliwosci próbkowania!</translation>
    </message>
    <message>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This could be a problem if the difference is large.</source>
        <translation type="obsolete">Uwaga: Częstotliwość próbkowania %1 nie jest wspierana, %2 zostanie wykorzystana To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Uwaga: Nastąpiło zdarzenie (overrun), część próbek została utracona.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Błąd: Nie można odzyskać urządzenia po zdarzeniu (overrun)!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="obsolete">Błąd: Nie można uruchomić urządzenia PCM po zdarzeniu (overrun)!</translation>
    </message>
    <message>
        <source>Stopping input thread ...</source>
        <translation type="obsolete">Zatrzymywanie wejściowego wątku...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set channel count!</source>
        <translation type="obsolete">Błąd: Nie można ustawić liczby kanałów! </translation>
    </message>
    <message>
        <source>Error: Can&apos;t set period count!</source>
        <translation type="obsolete">Błąd: Nie można ustawić numeracji cyklów!</translation>
    </message>
    <message>
        <source>Warning: Period count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Uwaga: Numeracja cykli %1 nie jest wspierana, użyto %2. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t set period size!</source>
        <translation type="obsolete">Błąd: Nie można ustawić rozmiaru cyklu!</translation>
    </message>
    <message>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="obsolete">Uwaga: rozmiar cyklu %1 nie jest wspierany, użyto %2. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation type="obsolete">Błąd: Nie można ustawić parametrów urządzenia PCM!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation type="obsolete">Błąd: Nie można uruchomić urządzenia PCM!</translation>
    </message>
    <message>
        <source>Input thread started.</source>
        <translation type="obsolete">Uruchomiono wątek wejścia.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation type="obsolete">Błąd: Nie można sprawdzić czy próbki są dostępne!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t read samples!</source>
        <translation type="obsolete">Błąd: Nie można odczytać próbki!</translation>
    </message>
    <message>
        <source>Input thread stopped.</source>
        <translation type="obsolete">Zatrzymano wątek wejścia.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation type="obsolete">Wyjątek &apos;%1&apos; w wątku wejścia.</translation>
    </message>
    <message>
        <source>Unknown exception in input thread.</source>
        <translation type="obsolete">Nieznany wyjątek w wątku wejścia.</translation>
    </message>
    <message>
        <source>Error: Image is too small!</source>
        <translation type="obsolete">Błąd: Obraz jest zbyt mały!</translation>
    </message>
    <message>
        <source>Error: Image is too large!</source>
        <translation type="obsolete">Błąd: Obraz jest zbyt duży!</translation>
    </message>
    <message>
        <source>Error: Image doesn&apos;t fit in memory!</source>
        <translation type="obsolete">Błąd: Obraz nie mieści się w pamięci!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation type="obsolete">Błąd: Nie ma dostępu do pamięci współdzielonej klatki!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation type="obsolete">Błąd: Nie można połączyć się z pamięcią współdzieloną klatki!</translation>
    </message>
    <message>
        <source>Full command</source>
        <translation type="obsolete">Całe polecenie</translation>
    </message>
    <message>
        <source>Error: Can&apos;t run command!</source>
        <translation type="obsolete">Błąd: Nie można wykonać polecenia!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation type="obsolete">Błąd: pa_mainloop_prepare zawiódł!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="obsolete">Błąd: pa_mainloop_poll zawiódł!</translation>
    </message>
    <message>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="obsolete">Błąd: pa_mainloop_dispatch zawiódł!</translation>
    </message>
    <message>
        <source>Error: Could not create main loop!</source>
        <translation type="obsolete">Błąd: Nie można utworzyć głównej pętli!</translation>
    </message>
    <message>
        <source>Error: Could not create context!</source>
        <translation type="obsolete">Błąd: Nie można utworzyć kontekstu!</translation>
    </message>
    <message>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation type="obsolete">Błąd: Nie można się połączyć! Powód: %1
Możliwe że twój system nie korzysta z PulseAudio. Spróbuj użyć podsystemu ALSA.</translation>
    </message>
    <message>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation type="obsolete">Błąd: Próba połączenia zawiodła! Powód: %1</translation>
    </message>
    <message>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="obsolete">Błąd: Nie można stworzyć strumienia! Powód: %1</translation>
    </message>
    <message>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="obsolete">Błąd: Nie mozna połączyć strumienia! Powód: %1</translation>
    </message>
    <message>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="obsolete">Błąd: Prób połączenia strumienia zawiodła! Powód: %1</translation>
    </message>
    <message>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="obsolete">Błąd: Nie udało się odczytać nazw źródeł! Powód: %1</translation>
    </message>
    <message>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation type="obsolete">Błąd: pa_stream_peek zawiódł!</translation>
    </message>
    <message>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="obsolete">Uwaga: Źródło audio zostało wstrzymane. Aktualny segment zostanie zatrzymany do momentu wznowienia źródła.</translation>
    </message>
    <message>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="obsolete">Uwaga: Strumień został przesunięty do innego źródła.</translation>
    </message>
    <message>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="obsolete">Błąd: Nie wspierany format pikseli X11 obrazu!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="obsolete">Błąd: Nie można otworzyć X display!</translation>
    </message>
    <message>
        <source>Using X11 shared memory.</source>
        <translation type="obsolete">Korzystanie z pamięci współdzielonej X11.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="obsolete">Błąd: Nie można utworzyć współdzielonego obrazu!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="obsolete">Blad: pamięć współdzielona jest nie osiągalna!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="obsolete">Błąd: Nie można nawiązać połączenia z pamięcią współdzieloną!</translation>
    </message>
    <message>
        <source>Not using X11 shared memory.</source>
        <translation type="obsolete">Nie użyto pamięci współdzielonej X11.</translation>
    </message>
    <message>
        <source>Error: Width or height is zero!</source>
        <translation type="obsolete">Błąd: Wysokość lub szerokość wynosi zero!</translation>
    </message>
    <message>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="obsolete">Błąd: Szerokość lub wysokość jest zbyt duża, maksymalna wysokość i szerokość wynosi %1!</translation>
    </message>
    <message>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="obsolete">Uwaga: XFixes nie jest wspierane przez serwer, kursor został schowany.</translation>
    </message>
    <message>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="obsolete">Błąd: Błędny zakres pola ekranu!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="obsolete">Błąd: Nie można połączyć serwera z pamięcią współdzieloną!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="obsolete">Błąd: Nie otrzymano obrazu (wykorzystując pamięć współdzieloną)!
    Zazwyczaj oznacza to że nagrywany obszar wkracza poza ekran. Czy zmieniono rozdzielczość ekranu?</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="obsolete">Błąd: Nie otrzymano obrazu (bez wykorzystywania pamięci współdzielonej)!
    Zazwyczaj oznacza to że nagrywany obszar wkracza poza ekran. Czy zmieniono rozdzielczość ekranu?</translation>
    </message>
    <message>
        <source>Error: Sample rate it zero.</source>
        <translation type="obsolete">Błąd: Częstotliwość próbkowania wynosi zero.</translation>
    </message>
    <message>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="obsolete">Błąd: Koder wymaga nie wspieranego formatu próbkowania!</translation>
    </message>
    <message>
        <source>Error: Encoding of audio frame failed!</source>
        <translation type="obsolete">Błąd: Kodowanie audio zawiodło!</translation>
    </message>
    <message>
        <source>Stopping encoder thread ...</source>
        <translation type="obsolete">Zatrzymywanie wątku kodowania ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="obsolete">Błąd: Kodek nie został odnaleziony!</translation>
    </message>
    <message>
        <source>Using codec %1 (%2).</source>
        <translation type="obsolete">Kodek %1 (%2) został użyty.</translation>
    </message>
    <message>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="obsolete">Uwaga: Ten kodek jest uważany za eksperymentalny przez libav/ffmpeg.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="obsolete">Błąd: Nie można otworzyć kodeka!</translation>
    </message>
    <message>
        <source>Encoder thread started.</source>
        <translation type="obsolete">Rozpoczęto wątek kodowania.</translation>
    </message>
    <message>
        <source>Flushing encoder ...</source>
        <translation type="obsolete">Oczyszczanie kodera ...</translation>
    </message>
    <message>
        <source>Encoder thread stopped.</source>
        <translation type="obsolete">Zatrzymano wątek kodowania.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="obsolete">Wyjątek &apos;%1&apos; w wątku kodera.</translation>
    </message>
    <message>
        <source>Unknown exception in encoder thread.</source>
        <translation type="obsolete">Nieznany wyjątek w wątku kodera.</translation>
    </message>
    <message>
        <source>Stopping encoders ...</source>
        <translation type="obsolete">Zatrzymywanie kodera ...</translation>
    </message>
    <message>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="obsolete">Oczekiwanie na zakończenie wątku multipleksowania ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="obsolete">Błąd nie można zapisać nagłówka (&apos;header&apos;)!</translation>
    </message>
    <message>
        <source>Finishing encoders ...</source>
        <translation type="obsolete">Zakańczanie koderów ...</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="obsolete">Błąd: Nie udało się rozpocząć nowego strumienia!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="obsolete">Błąd: Nie otrzymano kontekstu kodeka!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="obsolete">Błąd: Nie znaleziono formatu wyjścia!</translation>
    </message>
    <message>
        <source>Using format %1 (%2).</source>
        <translation type="obsolete">Użyto formatu %1 (%2).</translation>
    </message>
    <message>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="obsolete">Błąd: Nie można przydzielić kontekstu formatu!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="obsolete">Błąd: Nie można otworzyć pliku wyjściowego!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="obsolete">Błąd: nie można zapisać &apos;trailer&apos;, mimo to kontynuowano.</translation>
    </message>
    <message>
        <source>Muxer thread started.</source>
        <translation type="obsolete">Uruchomiono wątek multipleksera.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="obsolete">Błąd: Nie można zapisać klatki do multipleksera!</translation>
    </message>
    <message>
        <source>Muxer thread stopped.</source>
        <translation type="obsolete">Zatrzymano wątek multipleksera.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="obsolete">Wyjątek &apos;%1&apos; w wątku multipleksera.</translation>
    </message>
    <message>
        <source>Unknown exception in muxer thread.</source>
        <translation type="obsolete">Nieznany wyjątek w wątku multipleksera.</translation>
    </message>
    <message>
        <source>Stopping synchronizer thread ...</source>
        <translation type="obsolete">Zatrzymywanie wątku synchronizacji ...</translation>
    </message>
    <message>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="obsolete">Uwaga: Otrzymano wideo z nie monotonicznym znacznikiem czasu.</translation>
    </message>
    <message>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="obsolete">Uwaga: Przepełniono bufor wideo, niektóre klatki zostaną utracone. Wejście audio wygląda na zbyt wolne.</translation>
    </message>
    <message>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="obsolete">Uwaga: Otrzymano audio z nie monotonicznym znacznikiem czasu.</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="obsolete">Uwaga: Wejście audio jest przyspieszone o 5% ! {2%?}</translation>
    </message>
    <message>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="obsolete">Uwaga: Przepełniono bufor audio, rozpoczęto kolejny segment by utrzymać audio w synchronizacji z wideo (część wideo i/lub audio może zostać utracone). Wejscie wideo wygląda na zbyt wolne.</translation>
    </message>
    <message>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="obsolete">Uwaga: Desynchronizacja jest zbyt duża, rozpoczęto kolejny segment by utrzymać audio w synchronizacji z wideo (część wideo i/lub audio może zostać utracone).</translation>
    </message>
    <message>
        <source> Warning: Audio input is more than 5% too slow!</source>
        <translation type="obsolete">Uwaga: Wejście audio jest opóźnione o 5% !</translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation type="obsolete">Uwaga: Wejście audio jest przyspieszone o 5% !</translation>
    </message>
    <message>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation type="obsolete">Uwaga: Otrzymano lukę w strumieniu audio, rozpoczęto kolejny segment by utrzymać audio w synchronizacji z wideo (część wideo i/lub audio może zostać utracone).</translation>
    </message>
    <message>
        <source>Synchronizer thread started.</source>
        <translation type="obsolete">Rozpoczęto wątek synchronizacji.</translation>
    </message>
    <message>
        <source>Synchronizer thread stopped.</source>
        <translation type="obsolete">Zatrzymano wątek synchronizacji.</translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="obsolete">Wyjątek &apos;%1&apos; w watku synchronizacji.</translation>
    </message>
    <message>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="obsolete">Nieznany wyjątek w wątku synchronizacji.</translation>
    </message>
    <message>
        <source>Error: Width or height is not an even number!</source>
        <translation type="obsolete">Błąd: Szerokość lub wysokość nie jest liczbą parzystą!</translation>
    </message>
    <message>
        <source>Error: Frame rate it zero!</source>
        <translation type="obsolete">Błąd: ilość klatek na sekundę wynosi zero!</translation>
    </message>
    <message>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="obsolete">Błąd: Kodowanie wideo zawiodło!</translation>
    </message>
    <message>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="obsolete">Błąd: Opcja &apos;%1&apos; wiersza poleceń nie przyjmuje wartości!</translation>
    </message>
    <message>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="obsolete">Błąd: Nieznana opcja wiersza poleceń: &apos;%1&apos;!</translation>
    </message>
    <message>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="obsolete">Błąd: Nieznany argument wiersza poleceń: &apos;%1&apos;!</translation>
    </message>
    <message>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">SimpleScreenRecorder wykrył że korzystasz z własnościowych sterowników NVIDIA z włączoną opcją &apos;flipping&apos; która powoduje błędy w trakcie nagrywania. Zalecane jest jej wyłączenie. Chcesz bym to za ciebie zrobił?

Możesz zmienić tę opcję samodzielnie w panelu kontrolnym NVIDIA.</translation>
    </message>
    <message>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="obsolete">Z nieznanych przyczyn nie mogłem wyłączyć opcji &apos;flipping&apos; - przykro mi! Spróbuj wyłączyć ją w panelu kontrolnym NVIDIA..</translation>
    </message>
    <message>
        <source>SSR started</source>
        <translation type="obsolete">SSR wystartował</translation>
    </message>
    <message>
        <source>SSR stopped</source>
        <translation type="obsolete">SSR zatrzymany</translation>
    </message>
    <message>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="obsolete">Błąd: Nie można utworzyć lokacji .ssr!</translation>
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
        <translation>Wejscie wideo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="258"/>
        <source>Audio in</source>
        <translation>Wejscie audio</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="259"/>
        <source>Video out</source>
        <translation>Wyjście wideo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="260"/>
        <source>Audio out</source>
        <translation>Wyjscie audio</translation>
    </message>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Diagram Synchronizacji</translation>
    </message>
</context>
</TS>
