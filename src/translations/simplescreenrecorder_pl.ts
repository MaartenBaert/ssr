<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="pl_PL">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="80"/>
        <source>About SimpleScreenRecorder</source>
        <translation>O SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>For more information:</source>
        <translation>Więcej informacji:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>The source code of this program can be found at:</source>
        <translation>Kod źródłowy aplikacji można znaleźć na:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>This program uses:</source>
        <translation>Aplikacja wykorzystuje:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 dla interfejsu graficznego</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="93"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 lub %2 (zależy od dystrybucji) do kodowania wideo/audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="94"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 do podpinania funkcji systemowych przy nagrywaniu OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="780"/>
        <source>OpenGL Settings</source>
        <translation>Opcje OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="783"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Uwaga: nagrywanie OpenGL działa przez wstrzykniecie biblioteki do nagrywanego programu. Ta biblioteka nadpisze niektóre funkcje systemowe w celu przechwycenia klatek zanim zostaną wyświetlone na ekranie. Jeśli usiłujesz nagrać grę, która wykrywa próby hakowania po stronie klienta, jest (teoretycznie) możliwe że gra uzna to za próbę hakowania. Może to doprowadzić do zbanowania twojego konta, dlatego dobrym pomysłem jest sprawdzenie czy aplikacja, którą planujesz nagrać nie zbanuje cię, zanim zaczniesz nagrywać. Zostałeś ostrzeżony :)&lt;/p&gt;

&lt;p&gt;Uwaga 2: nagrywanie OpenGL jest eksperymentalne i może nie działać a nawet doprowadzić do zatrzymania programu. Jesli obawiasz sie o utratę danych zrób kopie zapasową.&lt;/p&gt;

&lt;p&gt;Jeśli chcesz nagrywać gry z platformy Steam zapoznaj sie z tym: &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="796"/>
        <source>Command:</source>
        <translation>Polecenie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="798"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Polecenie uruchamiające aplikację, która ma być nagrywana.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="800"/>
        <source>Start the OpenGL application automatically</source>
        <translation>Uruchom aplikację OpenGL automatycznie</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="801"/>
        <source>If checked, the above command will be executed automatically (combined with some environment variables). If not checked,
you have to start the OpenGL application yourself (the full command, including the required environment variables, is shown in the log).</source>
        <translation>Po zaznaczeniu powyrzsze polecenie(wraz z kilkoma zmiennymi środowiskowymi) zostanie automatycznie uruchomione.
Jeśli nie zaznaczone, aplikacja OpenGL będzie musiała byc uruchomiona oddzielnie(kompletne polecenie wraz z zmiennymi środowiskowymi można znaleźć w logu).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="804"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Złagodź uprawnienia do pamięci współdzielonej(potencjalnie ryzykowne)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="805"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Po zaznaczeniu inni użytkownicy na tej samej maszynie będą mieli dostęp do pamięci współdzielonej wykorzystywanej do komunikacji z aplikacją OpenGL.
To oznacza (teoretycznie) że inni użytkownicy mogą oglądać to co nagrywasz, modyfikować klatki, wstawiać własne klatki lub po prostu zakłócać komunikację.
Dotyczy to również użytkowników zalogowanych zdalnie (ssh). Zaleca się jedynie w przypadku nagrywania jako inny użytkownik.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="809"/>
        <source>Maximum image size (megapixels):</source>
        <translation>Maksymalny rozmiar obrazu (w megapikselach):</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="811"/>
        <source>This setting changes the amount of shared memory that will be allocated to send frames back to the main program.
The size of the shared memory can&apos;t be changed anymore once the program has been started, so if the program you
are trying to record is too large, recording won&apos;t work. 2 megapixels should be enough in almost all cases. Be careful,
high values will use a lot of memory!</source>
        <translation>Ta opcja zmienia rozmiar pamięci współdzielonej jak będzie zarezerwowana do przesyłania klatek do głównego programu.
Po uruchomieniu aplikacji nie będzie możliwości zmiany tego parametru. Jeśli nagrywany program jest zbyt duży nagrywanie
nie będzie działało. 2 megapiksele powinny wystarczyć w większości przypadków.
Durze wartości będą zajmowały większa ilości pamięci!</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="815"/>
        <source>Capture front buffer instead of back buffer</source>
        <translation>Przechwytuj z przedniego bufora</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="816"/>
        <source>If checked, the injected library will read the front buffer (the frame that&apos;s currently on the screen) rather than the back buffer
(the new frame). This may be useful for some special applications that draw directly to the screen.</source>
        <translation>Po zaznaczeniu wstrzyknięta biblioteka będzie czytała z przedniego bufora (aktualnie wyświetlana klatka) zamiast tylnego bufora
(następna klatka). Przydatne dla aplikacji rysujących bezpośrednio na ekranie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="819"/>
        <source>Limit application frame rate</source>
        <translation>Ograniczenie klatek na sekundę aplikacji</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="820"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Po zaznaczeniu wstrzyknięta biblioteka spowolni aplikację do prędkości nagrywania. Dzieki czemu aplikacja nie będzie marnowała
zasobów na klatki które nie będą nagrane oraz może sprawić że nagranie bedze płynniejsze(zależy od aplikacji).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="825"/>
        <source>Close</source>
        <translation>Zamknij</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Nagranie zostało zapisane. Możesz juz je edytować lub ponownie zakodować z lepszymi ustawieniami w celu zmniejszenia rozmiaru pliku (domyślne ustawienia są zoptymalizowane pod katem jakości oraz szybkości nie rozmiaru pliku).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>Powrót do początkowego ekranu</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="77"/>
        <source>Video input</source>
        <translation>Wejście wideo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="80"/>
        <source>Record the entire screen</source>
        <translation>Nagrywaj cały ekran</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="81"/>
        <source>Record a fixed rectangle</source>
        <translation>Nagrywaj wskazany obszar</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="82"/>
        <source>Follow the cursor</source>
        <translation>Śledź kursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="83"/>
        <source>Record OpenGL (experimental)</source>
        <translation>Nagrywanie OpeGL(eksperymentalne)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="89"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Wybierz który monitor ma byc nagrywany jeśli posiadasz wiecej niż jeden.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="90"/>
        <source>Select rectangle...</source>
        <translation>Wyznacz obszar...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="91"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Wyznacz obszar do nagrywania przy pomcy myszki.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="92"/>
        <source>Select window...</source>
        <translation>Zaznacz okno...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="93"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Korzystając z myszy zaznacz obszar do nagrywania.
Podpowiedź: Jeżeli klikniesz obramowanie okna, wówczas całe okno zostanie zaznaczone(wraz z obramowaniem).
W przeciwnym razie jedynie wnętrze okna będzie nagrywane.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="96"/>
        <source>OpenGL settings...</source>
        <translation>Opcje OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="97"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Zmień ustawienia nagrywania OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="98"/>
        <source>Left:</source>
        <translation>Lewo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="102"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Położenie X górnego-lewego rogu obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="104"/>
        <source>Top:</source>
        <translation>Góra:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="108"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Położenie Y górnego-lewego rogu obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="110"/>
        <source>Width:</source>
        <translation>Szerokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="114"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Szerokość obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="116"/>
        <source>Height:</source>
        <translation>Wysokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="120"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Wysokość obszaru nagrywania.
Podpowiedź: Możesz zmienić tę wartość przy pomocy kółka myszy lub strzałek góra/dół.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="122"/>
        <source>Frame rate:</source>
        <translation>Liczba klatek na sekundę:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="126"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Liczba klatek na sekundę z jaką będzie nagrywany obraz. Wyrzsze wartości wykorzystują bardziej CPU.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>Scale video</source>
        <translation>Skaluj wideo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="128"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Włącz lub wyłącz skalowanie nagrania. Skalowanie zwiększa wykorzystanie procesora lecz może skrócić czas kodowania jeśli obraz jest mniejszy.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="129"/>
        <source>Scaled width:</source>
        <translation>Przeskalowana szerokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Scaled height:</source>
        <translation>Przeskalowana wysokość:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="137"/>
        <source>Record cursor</source>
        <translation>Nagraj kursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="207"/>
        <source>Audio input</source>
        <translation>Wejście audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="209"/>
        <source>Record audio</source>
        <translation>Nagrywaj audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="210"/>
        <source>Backend:</source>
        <translation>Podsystem:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="220"/>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation>Urządzenie ALSA które będzie wykorzystywane do nagrywania. Wartość standardowa: &apos;default&apos;.
Możesz zmienić tą wartość na np: plughw:0,0 (co oznacza Karta dźwiękowa 0 oraz wejście 0 z włączonymi wtyczkami).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="226"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Źródło PulseAudio które będzie wykorzystywane do nagrywania.
&apos;monitor&apos; jest źródłem które przechwytuje audio z innych aplikacji.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="571"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Wszystkie ekrany: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="575"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Ekran %1: %2x%3 poz. %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="717"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Ekran %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="749"/>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation>Nie wprowadzono polecenia uruchamiającego aplikację OpenGL którą chcesz nagrać.
Kliknij &apos;Opcje OpenGL&apos; w celu wprowadzenia polecenia.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="216"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Podsystem audio który bedzie wykorzystywany do nagrywania.
Podsystem ALSA bęzie również działał na systemach które korzystaja z PulseAudio, aczkolwiek sugerowane jest korzystanie z PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="218"/>
        <source>Device:</source>
        <translation>Urządzenie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="223"/>
        <source>Source:</source>
        <translation>Źródło:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="228"/>
        <source>Refresh</source>
        <translation>Odśwież</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="229"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Odśwież listę źródeł PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="254"/>
        <source>Back</source>
        <translation>Wstecz</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="255"/>
        <source>Continue</source>
        <translation>Kontynuuj</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="70"/>
        <location filename="../GUI/PageOutput.cpp" line="76"/>
        <location filename="../GUI/PageOutput.cpp" line="83"/>
        <source>Other...</source>
        <translation>Inny...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="82"/>
        <source>Uncompressed</source>
        <translation>Nie skompresowany</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="58"/>
        <location filename="../GUI/PageOutput.cpp" line="61"/>
        <location filename="../GUI/PageOutput.cpp" line="64"/>
        <location filename="../GUI/PageOutput.cpp" line="67"/>
        <location filename="../GUI/PageOutput.cpp" line="103"/>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>pliki</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="137"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Błąd: Nie znaleziono odpowiednich kontenerów w libavformat!  </translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="141"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Błąd: Nie znaleziono odpowiednich kodeków w libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="145"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Błąd: Nie znaleziono odpowiednich kodeków audio w libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="149"/>
        <source>File</source>
        <translation>Plik</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="151"/>
        <source>Save as:</source>
        <translation>Zapisz jako:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="153"/>
        <source>The recording will be saved to this location.</source>
        <translation>Nagranie zostanie zapisane w tej lokalizacji.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="154"/>
        <source>Browse...</source>
        <translation>Przeglądaj...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="155"/>
        <source>Separate file per segment</source>
        <translation>Oddzielne pliki na segment</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="156"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation>Po zaznaczeniu, oddzielny plik zostanie utworzony przy każdym zatrzymaniu i wznowieniu nagrywania.
Jeżeli oryginalna nazwa pliku brzmi &apos;test.mkv&apos;,segmenty zostaną zapisane jako &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
Nazwy plików które już istnieją zostaną pominięte.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="159"/>
        <source>Container:</source>
        <translation>Kontener:</translation>
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
        <translation>Kontener (format pliku) jaki zostanie wykorzystany do zapisania nagrania.
Miej na uwadze że nie wszystkie kodeki są wspierane przez wszystkie kontenery oraz nie wszystkie odtwarzacze potrafią odczytać wszystkie formaty plików.
- Matroska (MKV) wspiera wszystkie kodeki lecz jest mniej znany.
- MP4 jest najbardziej znanym formatem i może być odtwarzany na prawie wszystkich współczesnych odtwarzaczach multimedialnych lecz wspiera wyłącznie
kodowanie H.264 (oraz wiele odtwarzaczy wspiera wyłącznie kodowanie audio AAC).
- WebM jest przeznaczone do filmów wbudowanych w strony internetowe(przy wykorzystaniu tagu HTML5 &lt;video&gt;). format został stworzony przez Google.
WebM jest domyślnie wspierany przez Firefox, Chrome oraz Operę, są również dostępne wtyczki do Internet Eksplorer oraz Safari.
Wspiera wyłącznie VP8 i Vorbis.
- OGG wspiera wyłącznie Theorę i Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="176"/>
        <source>Container name:</source>
        <translation>Nazwa kontenera:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Dla zaawansowanych użytkowników. Można wykorzystać dowolny format libav/ffmpeg lecz mogą okazać się nie przydatne lub nie działać.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>Video</source>
        <translation>Wideo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <location filename="../GUI/PageOutput.cpp" line="280"/>
        <source>Codec:</source>
        <translation>Kodek:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="205"/>
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
        <location filename="../GUI/PageOutput.cpp" line="209"/>
        <location filename="../GUI/PageOutput.cpp" line="293"/>
        <source>Codec name:</source>
        <translation>Nazwa kodeka:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="215"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Dla zaawansowanych użytkowników. Można wykorzystać dowolny format libav/ffmpeg lecz mogą okazać się nie przydatne lub nie działać.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="216"/>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <source>Bit rate (in kbps):</source>
        <translation>Szybkość transmisji (w kb/s):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="218"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Szybkość transmisji wideo (w kilobitach na sekundę). Wyższe wartości oznaczają wyższą jakość.
Jeżeli nie wiesz od jakiej wartości zacząć, spróbuj 5000 i zmieniaj w miarę potrzeb.</translation>
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
        <translation>CPU used:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>fastest</source>
        <translation>najszybsze</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="245"/>
        <source>slowest</source>
        <translation>najwolniejsze</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="246"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Szybkość kodowania.Wyższa wartość oznacza *mniejsze* użycie procesora (nazwa nie jest moim pomysłem
i jest wykorzystywana przez VP8). Wyższe wartości skutkują gorszą jakością chyba że zwiększysz Szybkość transmisji.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Zmiana wartości wpływa na jakość wideo. Niższa wartość oznacza lepsza jakość.
Dopuszczalny przedział wartości: 0-51 (0 oznacza bezstratne, domyślnie 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="236"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Tępo kodowania. Wyższa wartość wykorzystuje procesor w mniejszym stopniu(pozwalając na nagrywanie
z większą ilością klatek na sekundę) lecz powoduje że plik końcowy będzie większy. Jakość nie powinna ulec zmianie.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="248"/>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Custom options:</source>
        <translation>Ustawienia niestandardowe:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <location filename="../GUI/PageOutput.cpp" line="305"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Ustawienia niestandardowe kodeka oddzielone przecinkiem (np. opcja1=wartość1,opcja2=wartość2,opcja3=wartośc3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="251"/>
        <source>Allow frame skipping</source>
        <translation>Zezwól na pomijanie klatek</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="252"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Po zaznaczeniu koder będzie pomijał klatki jeżeli ilość klatek na wejsciu będzie niższa niz na wyjściu.
W prypadku nie zaznaczenia klatki będą dublowane by wypełnić luki. Zwiększy to rozmiar pliku
oraz wykorzystanie procesora lecz zmniejsza opuźnienie w trakcie stremowania na żywo w niektórych przypadkach.
Nie powinno mieć wpływu na wyglad wideo.</translation>
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
        <location filename="../GUI/PageOutput.cpp" line="299"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Dla zaawansowanych użytkowników. Można wykorzystać dowolny format libav/ffmpeg lecz mogą okazać się nie przydatne lub nie działać.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Szybkość transmisji audio (w kilobitach na sekundę). Wyższe wartości oznaczają wyższą jakość. Standardową wartością jest 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="319"/>
        <source>Back</source>
        <translation>Wstecz</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="320"/>
        <source>Continue</source>
        <translation>Kontynuuj</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="546"/>
        <location filename="../GUI/PageOutput.cpp" line="554"/>
        <source>not installed</source>
        <translation>nie zainstalowano</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="548"/>
        <location filename="../GUI/PageOutput.cpp" line="556"/>
        <source>not supported by container</source>
        <translation>nie wspierane przez kontener</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="599"/>
        <source>Save recording as</source>
        <translation>Zapisz nagranie jako</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <source>You did not select an output file!</source>
        <translation>Nie wskazano pliku do zapisania!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="643"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>Plik &apos;%1&apos; już istnieje. Na pewno chcesz go nadpisać?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="123"/>
        <source>Recording</source>
        <translation>Nagranie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="127"/>
        <source>Enable recording hotkey</source>
        <translation>Zezwól na skrót klawiszowy</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="128"/>
        <source>Hotkey:</source>
        <translation>Skrót:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="129"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="130"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="131"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="132"/>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="134"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>Klawisz (wraz z modyfikatorem) przy pomocy którego uruchomisz/zatrzymasz nagrywanie.
Aplikacja którą nagrywasz nie przechwyci tych klawiszy.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="168"/>
        <source>Information</source>
        <translation>Informacje</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="170"/>
        <source>Total time:</source>
        <translation>Czas całkowity:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="172"/>
        <source>FPS in:</source>
        <translation>Klatki/s (wejście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="174"/>
        <source>FPS out:</source>
        <translation>klatki/s (wyjście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="176"/>
        <source>Size in:</source>
        <translation>Rozmiar (wejście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="178"/>
        <source>Size out:</source>
        <translation>Rozmiar (wyjście):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="180"/>
        <source>File name:</source>
        <translation>Nazwa pliku:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="183"/>
        <source>File size:</source>
        <translation>Rozmiar pliku:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="185"/>
        <source>Bit rate:</source>
        <translation>Szybkość transmisji:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="208"/>
        <source>Preview</source>
        <translation>Podgląd</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="212"/>
        <source>Preview frame rate:</source>
        <translation>Klatki na sekundę podgladu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="216"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Uwaga: Podgląd wykorzystuje dodatkowo procesor (zwłaszcza przy dużej liczbie klatek na sekundę).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="265"/>
        <source>Log</source>
        <translation>Log</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="280"/>
        <location filename="../GUI/PageRecord.cpp" line="288"/>
        <source>Cancel recording</source>
        <translation>Anuluj nagranie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="281"/>
        <location filename="../GUI/PageRecord.cpp" line="287"/>
        <source>Save recording</source>
        <translation>Zapisz nagranie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="331"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Nie zapisano aktualnego nagrania. Jezeli teraz wyjdziesz zostanie ono utracone.
Czy na pewno chcesz wyjść?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="563"/>
        <source>Starting output ...</source>
        <translation>Uruchamianie wyjścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="611"/>
        <source>Started output.</source>
        <translation>Uruchomiono wyjście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="630"/>
        <source>Stopping output ...</source>
        <translation>Zatrzymywanie wyjścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="648"/>
        <source>Stopped output.</source>
        <translation>Zatrzymano wyjście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="670"/>
        <source>Starting input ...</source>
        <translation>Uruchamianie wejścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="693"/>
        <source>Started input.</source>
        <translation>Uruchomiono wejście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="715"/>
        <source>Stopping input ...</source>
        <translation>Zatrzymywanie wejścia ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="728"/>
        <source>Stopped input.</source>
        <translation>Zatrzymano wejście.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="480"/>
        <source>Starting page ...</source>
        <translation>Uruchamianie strony ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="488"/>
        <source>Error: Something went wrong during GLInject initialization.</source>
        <translation>Błąd: Coś poszło nie tak przy inicjalizacji GLInject.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="493"/>
        <source>Started page.</source>
        <translation>Uruchomiono stronę.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="521"/>
        <source>Stopping page ...</source>
        <translation>Zatrzymywanie strony ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="542"/>
        <source>Stopped page.</source>
        <translation>Zatrzymano stronę.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="570"/>
        <source>Error: Could not get the size of the OpenGL application because GLInject has not been started.</source>
        <translation>Błąd: Nie udało się przechwycić rozmiaru aplikacji OpenGL ponieważ GLInject nie został uruchomiony.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="575"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Błąd: Nie udało się przechwycić rozmiaru aplikacji OpenGL. Aplikacja nie została prawidłowo uruchomiona lub aplikacja nie stworzyła jeszcze okna OpenGL. Jeżeli chcesz rozpocząć nagrywanie przed uruchomieniem aplikacji musisz zezwolić na skalowanie oraz ręcznie wprowadzić rozmiar wideo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="619"/>
        <location filename="../GUI/PageRecord.cpp" line="698"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Błąd: Coś poszło nie tak w trakcie inicjalizacji.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="675"/>
        <source>Error: Could not create a GLInject input because GLInject has not been started.</source>
        <translation>Błąd: Nie udało się stworzyć wejścia GLInject ponieważ GLInject nie został uruchomiony.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="785"/>
        <location filename="../GUI/PageRecord.cpp" line="788"/>
        <source>Pause recording</source>
        <translation>Wstrzymaj nagrywanie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="790"/>
        <location filename="../GUI/PageRecord.cpp" line="793"/>
        <source>Start recording</source>
        <translation>Rozpocznij nagrywanie</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="801"/>
        <source>Stop preview</source>
        <translation>Zatrzymaj podgląd</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="804"/>
        <source>Start preview</source>
        <translation>Rozocznij podgląd</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="863"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Czy na pewno chcesz anulować to nagrywanie?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="876"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>Jeszcze nic nie zostało nagrane, nie ma czego zapisać.

Przycisk start jest na górze ;).</translation>
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
        <translation>&lt;p&gt;Witaj w SimpleScreenRecorder&lt;/p&gt;

&lt;p&gt;Wbrew temu co może sugerować nazwa ta aplikacja posiada wiele możliwości. Nie obawiaj się jednak ponieważ są tylko dwie rzeczy jakie powinieneś wiedzieć . Po pierwsze, domyślne wartości są zwykle wystarczające. Jeżeli nie wiesz do czego coś służy pozostaw wartość domyślną. Po drugie, prawie wszystkie opcje mają podpowiedzi. Wystarczy nakierować myszką na dany obiekt by dowiedzieć się do czego służy.&lt;/p&gt;

&lt;p&gt;Dalsze informacje na:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="46"/>
        <source>About SimpleScreenRecorder</source>
        <translation>O SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="47"/>
        <source>Continue</source>
        <translation>Kontynuuj</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../AV/DetectCPUFeatures.cpp" line="39"/>
        <source>CPU features</source>
        <translation>Opcje procesora</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="38"/>
        <source>BGRA to YUV420 converter</source>
        <translation>Konwerter BGRA na YUV420</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="41"/>
        <source>X86-specific instructions are disabled.</source>
        <translation>Szczegółowe instrukcje X86 są wyłączone.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="69"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Uwaga: Format pikseli nie jest wspierany (%1 -&gt; %2), w zamian zostanie użyty swscale. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="73"/>
        <source>Using swscale for scaling.</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Wykorzystywanie swscale do skalowania.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="82"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Błąd: nie można otrzymać kontekstu swcale!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="113"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation>Uwaga: Pamięć nie jest poprawnie ustawiona do SSE, użyto konwertera &apos;fallback&apos;. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="89"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Błąd: nie można otworzyć urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="93"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Błąd: nie można otrzymać parametrów urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="99"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Błąd: nie można ustawić typu dostępu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="105"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Błąd: nie można ustawić formatu próbkowania!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="112"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Błąd: nie mozna ustawić częstotliwosci próbkowania!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This could be a problem if the difference is large.</source>
        <translation>Uwaga: Częstotliwość próbkowania %1 nie jest wspierana, %2 zostanie wykorzystana To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Uwaga: Nastąpiło zdarzenie(overrun), część próbek została utracona.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Błąd: Nie można odzyskać urządzenia po zdarzeniu(overrun)!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Błąd: Nie można uruchomić urządzenia PCM po zdarzeniu (overrun)!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="55"/>
        <location filename="../AV/Input/X11Input.cpp" line="206"/>
        <source>Stopping input thread ...</source>
        <translation>Zatrzymywanie wejsciowego wątku...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="125"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Błąd: Nie można ustawić liczby kanałów! </translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="132"/>
        <source>Error: Can&apos;t set period count!</source>
        <translation>Błąd: Nie można ustawić numeracji cyklów!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="136"/>
        <source>Warning: Period count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uwaga: Numeracja cykli %1 nie jest wspierana, użyto %2. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="145"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Błąd: Nie można ustawić rozmiaru cyklu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="149"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uwaga: rozmiar cyklu %1 nie jest wspierany, użyto %2. To nie jest problem lecz wydajność będzie gorsza.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="157"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Błąd: Nie można ustawić parametrów urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="175"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Błąd: Nie można uruchomić urządzenia PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="196"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="95"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="333"/>
        <source>Input thread started.</source>
        <translation>Uruchomiono wątek wejścia.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="216"/>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation>Błąd: Nie mozna sprawdzić czy próbki są dostępne!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="229"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Błąd: Nie można odczytać próbki!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="255"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="155"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="387"/>
        <location filename="../AV/Input/X11Input.cpp" line="423"/>
        <source>Input thread stopped.</source>
        <translation>Zatrzymano wątek wejścia.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="259"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="159"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="391"/>
        <location filename="../AV/Input/X11Input.cpp" line="427"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Wyjątek &apos;%1&apos; w wątku wejścia.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="262"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="162"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="394"/>
        <location filename="../AV/Input/X11Input.cpp" line="430"/>
        <source>Unknown exception in input thread.</source>
        <translation>Nieznany wyjątek w wątku wejścia.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="122"/>
        <source>Error: Image is too small!</source>
        <translation>Błąd: Obraz jest zbyt mały!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="126"/>
        <source>Error: Image is too large!</source>
        <translation>Błąd: Obraz jest zbyt durzy!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="134"/>
        <source>Error: Image doesn&apos;t fit in memory!</source>
        <translation>Błąd: Obraz nie mieści się w pamięci!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="117"/>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation>Błąd: Nie ma dostępu do pamieci wspułdzielonej klatki!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="122"/>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation>Błąd: Nie można połączyć się z pamiecią wspułdzieloną klatki!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="149"/>
        <source>Full command</source>
        <translation>Całe polecenie</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="157"/>
        <source>Error: Can&apos;t run command!</source>
        <translation>Błąd: nie można wykonać polecenia!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Błąd: pa_mainloop_prepare zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Błąd: pa_mainloop_poll zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Błąd: pa_mainloop_dispatch zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation>Błąd:Nie można utworzyć głównej pętli!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
        <source>Error: Could not create context!</source>
        <translation>Błąd: nie można utworzyć kontekstu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Błąd nie można się połączyć! Powód: %1
Możliwe że twój system nie korzysta z PulseAudio. Spróbuj użyć podsystemu ALSA.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Błąd: Próba połączenia zawiodła! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Błąd: Nie można stworzyć strumienia! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Błąd: Nie mozna połączyć strumienia! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Błąd: Prób połączenia strumienia zawiodła! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Błąd: Nie udało się odczytac nazw źródeł! Powód: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="312"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Błąd: pa_stream_peek zawiódł!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="375"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Uwaga: Źródło audio zostało wstrzymane. Aktualny segment zostanie zatrzymany do momentu wznowienia źródła.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="380"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Uwaga: Strumień został przesunięty do innego źródła.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Błąd: Nie wspierany format pikseli X11 obrazu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="226"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Błąd:Nie można otworzyć X display!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="235"/>
        <source>Using X11 shared memory.</source>
        <translation>Korzystanie z pamięci współdzielonej X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="238"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Błąd: Nie można utworzyć współdzielonego obrazu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="102"/>
        <location filename="../AV/Input/X11Input.cpp" line="243"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Blad: pamięć współdzielona jest nie osiągalna!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="107"/>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Błąd: Nie można nawiązac połączenia z pamięcia współdzieloną!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="254"/>
        <source>Not using X11 shared memory.</source>
        <translation>Nie użyto pamięci współdzielonej X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="185"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="57"/>
        <source>Error: Width or height is zero!</source>
        <translation>Błąd: Wysokość lub szerokość wynosi zero!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="189"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="61"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Błąd: Szerokość lub wysokość jest zbyt durza, maksymalna wysokość i szerokość wynosi %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="262"/>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Uwaga: XFixes nie jest wspierane przez serwer, kursor został showany.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="317"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Błąd: Błędny zakres pola ekranu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="373"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Błąd: Nie można połączyć serwera z pamięcia współdzieloną!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Błąd: Nie otrzymano obrazu (wykorzystując pamięć współdzieloną)!
    Zazwyczaj oznacza to że nagrywany obszar wkracza poza ekran.Czy zmieniono rozdzielczość ekranu?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="390"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Błąd: Nie otrzymano obrazu (bez wykorzystywania pamięci współdzielonej)!
    Zazwyczaj oznacza to że nagrywany obszar wkracza poza ekran.Czy zmieniono rozdzielczość ekranu?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="45"/>
        <source>Error: Sample rate it zero.</source>
        <translation>Błąd: Częstotliwość próbkowania wynosi zero.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="126"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Błąd: Koder wymaga nie wspieranego formatu próbkowania!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="149"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="170"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Błąd: Kodowanie audio zawiodło!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="62"/>
        <source>Stopping encoder thread ...</source>
        <translation>Zatrzymywanie wątku kodowania ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="82"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Błąd: Kodek nie został odnaleziony!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="87"/>
        <source>Using codec %1 (%2).</source>
        <translation>Kodek %1 (%2) został użyty.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Uwaga: Ten kodek jest Uważany za eksperymentalny przez libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="106"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Błąd: Nie można otworzyć kodeka!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="160"/>
        <source>Encoder thread started.</source>
        <translation>Rozpoczęto wątek kodowania.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="189"/>
        <source>Flushing encoder ...</source>
        <translation>Oczyszczanie kodera ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="196"/>
        <source>Encoder thread stopped.</source>
        <translation>Zatrzymano wątek kodowania.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="200"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Wyjątek &apos;%1&apos; w wątku kodera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="203"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Nieznany wyjątek w wątku kodera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="72"/>
        <source>Stopping encoders ...</source>
        <translation>Zatrzymywanie kodera ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="79"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Oczekiwanie na zakończenie wątku multipleksowania ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Błąd nie można zapisać nagłówka (&apos;header&apos;)!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="111"/>
        <source>Finishing encoders ...</source>
        <translation>Zakańczanie koderów ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="143"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Błąd: Nie udało się rozpocząć nowego strumienia!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="149"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Błąd: Nie otrzymano kontekstu kodeka!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="195"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Błąd: Nie znaleziono formatu wyjścia!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Using format %1 (%2).</source>
        <translation>Użyto formatu %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="204"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Błąd: Nie można przydzielić kontekstu formatu!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="211"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Błąd: Nie można otworzyć pliku wyjściowego!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="224"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Błąd: nie można zapisać &apos;trailer&apos;, mimo to kontynuowano.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="257"/>
        <source>Muxer thread started.</source>
        <translation>Uruchomiono wątek multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="311"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Błąd: Nie można zapisać klatki do multipleksera!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="339"/>
        <source>Muxer thread stopped.</source>
        <translation>Zatrzymano wątek multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="343"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Wyjątek &apos;%1&apos; w wątku multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="346"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Nieznany wyjatek w wątku multipleksera.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="119"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Zatrzymywanie wątku synchronizacji ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="237"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Uwaga: Otrzymano wideo z nie monotonicznym znacznikiem czasu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="269"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Uwaga: Przepełniono bufor wideo, niektóre klatki zostaną utracone. Wejscie audio wygląda na zbyt wolne.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="334"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Uwaga: .Otrzymano audio z nie monotonicznym znacznikiem czasu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="345"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Uwaga: Przepełniono bufor audio, rozpoczęto kolejny segment by utrzymać audio w synchronizacji z wideo (część wideo i/lub audio może zostać utracone). Wejscie wideo wygląda na zbyt wolne.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="368"/>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Uwaga: desynchronizacja jest zbyt durza, rozpoczęto kolejny segment by utrzymać audio w synchronizacji z wideo (część wideo i/lub audio może zostać utracone).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="377"/>
        <source> Warning: Audio input is more than 5% too slow!</source>
        <translation>Uwaga: Wejście audio jest opóźnione o 5% !</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="381"/>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation>Uwaga: Wejście audio jest przyspieszone o 5% !</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="411"/>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Uwaga: Otrzymano lukę w strumieniu audio, rozpoczęto kolejny segment by utrzymać audio w synchronizacji z wideo (część wideo i/lub audio może zostać utracone).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="697"/>
        <source>Synchronizer thread started.</source>
        <translation>Rozpoczęto wątek synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="719"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Zatrzymano wątek synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="723"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Wyjątek &apos;%1&apos; w watku synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="726"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Nieznany wyjątek w wątku synchronizacji.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="65"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Błąd: Szerokość lub wysokość nie jest liczbą parzystą!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="69"/>
        <source>Error: Frame rate it zero!</source>
        <translation>Błąd: ilość klatek na sekundę wynosi zero!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="202"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="225"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Błąd: Kodowanie wideo zawiodło!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="92"/>
        <location filename="../Main.cpp" line="104"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Błąd: Opcja &apos;%1&apos; wiersza poleceń nie przyjmuje wartości!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="109"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Błąd: Nieznana opcja wiersza poleceń: &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="116"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Błąd: Nieznany argument wiersza poleceń: &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="141"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder wykrył że korzystasz z własnościowych sterowników NVIDIA z włączoną opcją &apos;flipping&apos; która powoduje błędy w trakcie nagrywania. Zalecane jest jej wyłączenie. Chcesz bym to za ciebie zrobił?

Możesz zmienić tę opcję samodzielnie w panelu kontrolnym NVIDIA.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="146"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Z nieznanych przyczyn nie mogłem wyłączyć opcji &apos;flipping&apos; - przykro mi! Spróbuj wyłączyć ją w panelu kontrolnym NVIDIA..</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="152"/>
        <source>SSR started</source>
        <translation>SSR wystartował</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="160"/>
        <source>SSR stopped</source>
        <translation>SSR zatrzymany</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="168"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Błąd: Nie można utworzyć lokacji .ssr!</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="187"/>
        <source>Video in</source>
        <translation>Wejscie wideo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="188"/>
        <source>Audio in</source>
        <translation>Wejscie audio</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="189"/>
        <source>Video out</source>
        <translation>Wyjście wideo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="190"/>
        <source>Audio out</source>
        <translation>Wyjscie audio</translation>
    </message>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="49"/>
        <source>Synchronization Diagram</source>
        <translation>Diagram Synchronizacji</translation>
    </message>
</context>
</TS>
