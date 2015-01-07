<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="ru_RU">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="78"/>
        <source>About SimpleScreenRecorder</source>
        <translation>О SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="87"/>
        <source>For more information:</source>
        <translation>Более подробная информация на моем сайте:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="88"/>
        <source>The source code of this program can be found at:</source>
        <translation>Исходный код программы можно найти здесь:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>This program uses:</source>
        <translation>Эта программа использует:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 - графический интерфейс</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 или %2 - кодирование аудио/видео (зависит от вашего дистрибутива)</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 - для подключения системных функций при записи OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="34"/>
        <source>OpenGL Settings</source>
        <translation>Настройки OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="37"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Предупреждение: Для записи OpenGL потребуется ввести в записываемую программу дополнительную библиотеку. Эта библиотека перераспределит некоторые системные функции так, чтобы записывать кадры прежде чем они отобразятся на экране. Если вы попытаетесь записать игру, которая умеет распознавать взлом со стороны клиента, то (теоретически) это может быть расценено как попытка взлома. Ваш аккаунт может быть заблокирован, так что перед тем, как начинать запись, учтите возможные последствия. Я вас предупредил :).&lt;/p&gt;

&lt;p&gt;Еще одно предупреждение: Запись через OpenGL это эксперементальная функция, которая может привести к вылетам из или же не сработать вообще. Если вы беспокоитесь за сохранность ваших данных, то обязательно сделайте резервную копию!&lt;/p&gt;

&lt;p&gt;Если вы хотите записывать игры из Steam &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;для начала прочтите вот это&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="51"/>
        <source>Choose channel</source>
        <translation>Выбрать канал</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="53"/>
        <source>Channel name:</source>
        <translation>Имя канала:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="55"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Имена каналов используются для идентификации приложений. Используйте имена только в случае записи нескольких приложений одновременно.
Если оставить поле пустым, то по-умолчанию приложению присвоится имя &quot;канал-ВАШЕИМЯ&quot;.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="57"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Упростить доступ к совместной памяти (небезопасно)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Если включить эту функцию то у пользователей вашего компьютера появится возможность подключаться к совместной памяти которая используется программой для записи через OpenGL. 
Это означает что другие пользователи (теоретически) могут видеть то, что вы записываете, модифицировать запись, вставлять свои кадры или просто прерывать соединение. 
Это также применимо и к удаленным пользователям, подключенным через SSH. Используйте эту опцию только тогда, когда нужно записать программу, запущенную от имени другого пользователя.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="73"/>
        <source>Launch application</source>
        <translation>Запустить приложение</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="75"/>
        <source>Command:</source>
        <translation>Команда:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="77"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Команда запуска программы, которая будет записываться. </translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="79"/>
        <source>Working directory:</source>
        <translation>Рабочая директория:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="81"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Директория в которой будет выполнена команда. Если оставить поле пустым рабочая директория не изменится.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="83"/>
        <source>Launch automatically</source>
        <translation>Запускать автоматически</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Если флажок установлен, то записываемая программа запустится сразу же после перехода к окну записи. 
Если оставить функцию выключенной, то нужно будет запустить программу самостоятельно.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="86"/>
        <source>Launch now</source>
        <translation>Запустить сейчас</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="107"/>
        <source>Stream settings</source>
        <translation>Настройка потокового видео</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="109"/>
        <source>Limit application frame rate</source>
        <translation>Ограничить частоту кадров приложения</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Если включить эту функцию, то подключенная библиотека будет замедлять приложение таким образом, чтобы частота кадров приложения не превышала частоту кадров записи.
Это предотвратит дополнительную нагрузку на процессор для тех кадров, которые не попадут в конечную запись. и, как результат, вы получите более качественную запись 
(зависит от приложения).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="119"/>
        <source>Close</source>
        <translation>Закрыть</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="116"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="125"/>
        <location filename="../Benchmark.cpp" line="117"/>
        <location filename="../Benchmark.cpp" line="190"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="147"/>
        <location filename="../AV/FastScaler.cpp" line="172"/>
        <location filename="../AV/FastScaler.cpp" line="197"/>
        <location filename="../AV/FastScaler.cpp" line="219"/>
        <location filename="../AV/FastScaler.cpp" line="242"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Предупреждение: Произошла перегрузка, некоторые сэмплы потеряны.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Ошибка: Не удалось восстановить устройство после перегрузки!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Ошибка: Не удалось запустить PCM устройство после перегрузки!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="63"/>
        <location filename="../AV/Input/JACKInput.cpp" line="56"/>
        <location filename="../AV/Input/X11Input.cpp" line="207"/>
        <source>Stopping input thread ...</source>
        <translation type="unfinished">Останавливаю процесс ввода...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="96"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="232"/>
        <source>Generating source list ...</source>
        <translation type="unfinished">Генерирую список источников...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="115"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation type="unfinished">Ошибка: Не удается обновить конфигурацию ALSA!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="162"/>
        <source>Found plugin: [%1] %2</source>
        <translation type="unfinished">Найден плагин: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="175"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation type="unfinished">Предупреждение: Не удается подключиться к звуковой карте %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation type="unfinished">Предупреждение: Не удается получить информацию о звуковой карте %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="185"/>
        <source>Found card: [%1] %2</source>
        <translation type="unfinished">Найдена карта: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="210"/>
        <source>Found device: [%1] %2</source>
        <translation type="unfinished">Найдено устройство: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="259"/>
        <location filename="../AV/SimpleSynth.cpp" line="123"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation type="unfinished">Ошибка: Не удалось подключиться к PCM устройству!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="263"/>
        <location filename="../AV/SimpleSynth.cpp" line="127"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation type="unfinished">Ошибка: Не удалось получить параметры PCM устройства!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="269"/>
        <location filename="../AV/SimpleSynth.cpp" line="133"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation type="unfinished">Ошибка: Не удалось установить тип доступа!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="139"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation type="unfinished">Ошибка: Не удалось установить формат сэмпла!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="282"/>
        <location filename="../AV/SimpleSynth.cpp" line="146"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation type="unfinished">Ошибка: Не удалось установить частоту сэмпла!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="286"/>
        <location filename="../AV/SimpleSynth.cpp" line="150"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Предупреждение: Частота сэмпла %1 не поддерживается, используйте вместо него %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="295"/>
        <location filename="../AV/SimpleSynth.cpp" line="158"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation type="unfinished">Ошибка: Не удалось установить глубину канала!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="299"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Предупреждение: Глубина канала %1 не поддерживается, используйте вместо него %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="308"/>
        <location filename="../AV/SimpleSynth.cpp" line="165"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation type="unfinished">Ошибка: Не удалось установить размер промежутка!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="312"/>
        <location filename="../AV/SimpleSynth.cpp" line="169"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Предупреждение: Размер промежутка %1 не поддерживается, используйте вместо него %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="321"/>
        <location filename="../AV/SimpleSynth.cpp" line="178"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation type="unfinished">Ошибка: Не могу установить размер буффера!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/SimpleSynth.cpp" line="182"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Предупреждение: Размер буффера %1 не поддерживается, используйте вместо него %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="333"/>
        <location filename="../AV/SimpleSynth.cpp" line="190"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation type="unfinished">Ошибка: Не удалось применить параметры устройства PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="351"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation type="unfinished">Ошибка: Не удалось запустить устройство PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="372"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="180"/>
        <location filename="../AV/Input/JACKInput.cpp" line="238"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="299"/>
        <location filename="../AV/Input/X11Input.cpp" line="345"/>
        <source>Input thread started.</source>
        <translation type="unfinished">Процесс ввода начат.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="387"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation type="unfinished">ОШибка: Не удалось прочесть сэмплы!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="413"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="248"/>
        <location filename="../AV/Input/JACKInput.cpp" line="286"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="388"/>
        <location filename="../AV/Input/X11Input.cpp" line="444"/>
        <source>Input thread stopped.</source>
        <translation type="unfinished">Процесс ввода остановлен.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="417"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="252"/>
        <location filename="../AV/Input/JACKInput.cpp" line="290"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="392"/>
        <location filename="../AV/Input/X11Input.cpp" line="448"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation type="unfinished">В процессе ввода появилось исключение &quot;%1&quot;.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="420"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="255"/>
        <location filename="../AV/Input/JACKInput.cpp" line="293"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="395"/>
        <location filename="../AV/Input/X11Input.cpp" line="451"/>
        <source>Unknown exception in input thread.</source>
        <translation type="unfinished">Неизвестное исключение  в процессе ввода.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="149"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation type="unfinished">Ошибка: Не удалось прочесть поток, что обычно означает </translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="72"/>
        <source>Error: Could not connect to JACK!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="81"/>
        <source>Error: Could not create JACK port!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="87"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="91"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="95"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="99"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not activate JACK client!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <location filename="../AV/Input/JACKInput.cpp" line="123"/>
        <location filename="../AV/Input/JACKInput.cpp" line="247"/>
        <source>Connecting port %1 to %2.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <source>Disconnecting port %1 from %2.</source>
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
        <location filename="../AV/Input/PulseAudioInput.cpp" line="223"/>
        <source>Found source: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="313"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="377"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="382"/>
        <source>Warning: Stream was moved to a different source.</source>
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
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="88"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="95"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="99"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="104"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="109"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="121"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="127"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="139"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="157"/>
        <source>Added pre-existing stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="192"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="200"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="210"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="222"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="236"/>
        <source>Added stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="244"/>
        <source>Removed stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="270"/>
        <source>Deleted abandoned stream %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="186"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="112"/>
        <source>Error: Width or height is zero!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="190"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="116"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="236"/>
        <location filename="../GUI/HotkeyListener.cpp" line="118"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="245"/>
        <source>Using X11 shared memory.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="253"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="264"/>
        <source>Not using X11 shared memory.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="271"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="329"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="393"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="399"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="410"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="99"/>
        <source>Error: Channel count is zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="103"/>
        <source>Error: Sample rate is zero.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="140"/>
        <source>Using sample format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="145"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="31"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="40"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="155"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="163"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="179"/>
        <source>Encoder thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="211"/>
        <source>Flushing encoder ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="225"/>
        <source>Encoder thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="229"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Unknown exception in encoder thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="71"/>
        <source>Stopping encoders ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="78"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="133"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="144"/>
        <source>Finishing encoders ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="186"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="190"/>
        <source>Using format %1 (%2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="196"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="254"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="264"/>
        <source>Using codec %1 (%2).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="273"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="283"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="296"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="312"/>
        <source>Muxer thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="371"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="399"/>
        <source>Muxer thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="403"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="406"/>
        <source>Unknown exception in muxer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="205"/>
        <source>Stopping synchronizer thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="322"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="348"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="405"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="430"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="436"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="502"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="506"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="541"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="577"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="877"/>
        <source>Synchronizer thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="899"/>
        <source>Synchronizer thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="903"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="906"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="120"/>
        <source>Error: Width or height is not an even number!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="124"/>
        <source>Error: Frame rate is zero!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="181"/>
        <source>Using pixel format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="195"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="225"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="245"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="40"/>
        <source>Using real-time priority.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="50"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="55"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="63"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="90"/>
        <source>Stopping synth thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="223"/>
        <source>Synth thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="276"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="284"/>
        <source>Synth thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="288"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="291"/>
        <source>Unknown exception in synth thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="46"/>
        <source>CPU features</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="159"/>
        <source>The application could not be launched.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="164"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="119"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="150"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="160"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="200"/>
        <source>SSR started</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="226"/>
        <source>SSR stopped</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="243"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="156"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="226"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="236"/>
        <source>Starting scaler benchmark ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="243"/>
        <source>Starting converter benchmark ...</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder обнаружил что вы используете проприетарный драйвер NVIDIA с включенной опцией &quot;flipping&quot;. Эта опция может создавать помехи при записи.  Я настоятельно рекомендую ее отключить. Хотите чтобы я сделал это за вас?

Вы также можете самомтоятельно отключить ее через контрольную панель NVIDIA.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="90"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Мне не удалось отключить &quot;flipping&quot;... Попробуйте отключить его через кнонтрольную панель NVIDIA.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Ваша запись сохранена. Теперь вы можете начать редактирование либо перекодировать запись для достижения меньшего размера файла (настройки по-умолчанию оптимизированы на скорость и качество, но не на размер).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>Вернуться к главному экрану</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="113"/>
        <source>Video input</source>
        <translation>Настройки видео</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="116"/>
        <source>Record the entire screen</source>
        <translation>Записать весь экран</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="117"/>
        <source>Record a fixed rectangle</source>
        <translation>Записать выделенную область</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="118"/>
        <source>Follow the cursor</source>
        <translation>Следовать за курсором</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="119"/>
        <source>Record OpenGL (experimental)</source>
        <translation>Записать OpenGL (эксперементально)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="125"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Выберите монитор, который будет использоватся для записи.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="126"/>
        <source>Select rectangle...</source>
        <translation>Выбрать область...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Используйте мышку чтобы выделить область для записи.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="128"/>
        <source>Select window...</source>
        <translation>Выбрать окно...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="129"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Используйте мышку чтобы выбрать окно для записи.
Совет: Если вы кликните по границам окна - будет записано окно целиком, 
в противном случае запишется только рабочая часть окна.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="132"/>
        <source>OpenGL settings...</source>
        <translation>Настройки OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Изменить настройки записи OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="134"/>
        <source>Left:</source>
        <translation>Слева:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="138"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Х координата верхнего левого угла записываемой области.
Совет: Вы можете также изменять это значение с помощью 
колесика мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="140"/>
        <source>Top:</source>
        <translation>Сверху:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="144"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Y координата верхнего левого угла записываемой области.
Совет: Вы можете также изменять это значение с помощью 
колесика мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="146"/>
        <source>Width:</source>
        <translation>Ширина:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="150"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Ширина записываемой области.
Совет: Вы можете также изменять это значение
с помощью колесика мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="152"/>
        <source>Height:</source>
        <translation>Высота:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="156"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Высота записываемой области.
Совет: Вы можете также изменять это значение 
с помощью колесика мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="158"/>
        <source>Frame rate:</source>
        <translation>Частота кадров:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="162"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Количество кадров в секунду у финального видео. 
Более высокая частота кадров потребует больше 
вычислительной мощности процессора.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="163"/>
        <source>Scale video</source>
        <translation>Растянуть видео</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="164"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Включает или отключает растяжение. 
Растяжение требует больше мощности процессора, 
однако видео получаются меньше размером и кодируются быстрее.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="165"/>
        <source>Scaled width:</source>
        <translation>Ширина:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="169"/>
        <source>Scaled height:</source>
        <translation>Высота:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="173"/>
        <source>Record cursor</source>
        <translation>Записывать курсор</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Audio input</source>
        <translation>Настройки звука</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="245"/>
        <source>Record audio</source>
        <translation>Записывать звук</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>Backend:</source>
        <translation>Сервер:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="255"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Звуковой сервер, который будет использован при записи.
Сервер ALSA также будет работать на системах с предустановленным 
PulseAudio, однако лучше всего использовать именно PulseAudio. </translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="257"/>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>Source:</source>
        <translation>Источник:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Источник сервера ALSA, который будет использован при записи. 
Настройки по-умолчанию обычно работают лучше всего.
&quot;Общие&quot; источники позволяют разным программам записываться 
одновременно, однако это может быть ненадежно.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Refresh</source>
        <translation>Обновить</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="263"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Обновляет список источников ALSA.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="268"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Источник сервера PulseAudio, который будет использован при записи.
&quot;Monitor&quot; это источник, записывающий звук других приложений.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Обновляет список источников PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="274"/>
        <source>Record system microphone</source>
        <translation>Записывать звук с микрофона</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="275"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Если флажок установлен, то программа автоматически 
подключится к портам записи вашего компьютера.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record system speakers</source>
        <translation>Записывать звук с колонок</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Если флажок установлен, то программа автоматически 
подключится к любым портам вывода звука вашего компьютера.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Back</source>
        <translation>Назад</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="313"/>
        <source>Continue</source>
        <translation>Далее</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="673"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Все экраны: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="677"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Экран %1: %2x%3 в %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="839"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Экран %1</translation>
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
        <translation>Файлы %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>Другой...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>Без сжатия</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="161"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Ошибка: Не могу найти подходящий контейнер в libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="165"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Ошибка: Не могу найти подходящий видеокодек в libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="169"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Ошибка: Не могу найти подходящий аудиокодек в libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="175"/>
        <source>File</source>
        <translation>Файл</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Save as:</source>
        <translation>Сохранить как:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="179"/>
        <source>The recording will be saved to this location.</source>
        <translation>Запись будет сохранена в эту папку.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="180"/>
        <source>Browse...</source>
        <translation>Обзор...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Separate file per segment</source>
        <translation>Разбить файл на сегменты</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Если установить флажок, то программа будет создавать 
новый видеофайл при каждой паузе и возврате к записи.
Если имя оригинального файла &quot;test.mkv&quot;, то имена сегментов 
будут иметь имя &apos;test-ГГГГ-MM-ДД_ЧЧ.MM.СС.mkv&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="184"/>
        <source>Container:</source>
        <translation>Контейнер:</translation>
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
        <translation>Контейнер (формат файла) который будет использован для записи.
Имейте ввиду что контейнер может не поддерживать все типы кодеков 
и не все медиаплееры поддерживают все типы файлов.
- Матрешка (MKV) поддерживает все типы кодеков, но он мало распространен.
- MP4 более популярный формат и его могут проигрывать 
   практически все современные медиаплееры, однако он поддерживает только кодек H.264
   (при этом большинство медиаплееров поддерживает звук лишь в формате AAC).
- WebM предназначен для встраивания видео в вебсайты (при помощи тэга &lt;video&gt; в HTML). 
   Формат создан Google. WebM по-умолчанию поддерживается в Firefox, Chrome и Opera 
   (также существуют плагины для Internet Explorer и Safari)
   WebM поддерживает только VP8 и Vorbis.
- OGG поддерживает только Theora и Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>Container name:</source>
        <translation>Имя контейнера:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="207"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Для продвинутых пользователей. 
Вы можете использовать любой формат libav/ffmpeg, 
однако многие из них попросту бесполезны и могут не работать.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="223"/>
        <source>Video</source>
        <translation>Видео</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <location filename="../GUI/PageOutput.cpp" line="305"/>
        <source>Codec:</source>
        <translation>Кодек:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="230"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Кодек, который будет использован для сжатия видеопотока вашего видео.
- H.264 (libx264) пока что лучший кодек - высокое качество и отличная скорость.
- VP8 (libvpx) весьма хороший, но при этом весьма медленный кодек.
- Theora (libtheora) настоятельно не рекомендую использовать, 
   качество у него очень посредственное.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="234"/>
        <location filename="../GUI/PageOutput.cpp" line="318"/>
        <source>Codec name:</source>
        <translation>Имя кодека:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Для продвинутых пользователей. 
Вы можете использовать любой libav/ffmpeg видео кодек, 
однако многие из них попросту бесполезны и могут не работать.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="241"/>
        <location filename="../GUI/PageOutput.cpp" line="325"/>
        <source>Bit rate (in kbps):</source>
        <translation>Битрейт (в kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="243"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Битрейт вашего видео (в килобитах в секунду). 
Более высокое значение даст более высокое качество.
Если вы понятия не имеете какое значение выставить - 
попробуйте начать с 5000 и изменяйте при необходимости.</translation>
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
        <translation>Эта настройка изменяет качество видео. Чем меньше значение тем выше качество.
Допустимое значение: 0-51 (0 означает &quot;без потерь&quot;, 23 - значение по-умолчанию).</translation>
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
        <translation>Скорость кодирования вашего видео. 
Более высокая скорость будет меньше нагружать процессор 
(что делает возможным записывать при высокой частоте кадров), 
но в результате вы получите файл большего размера. 
На качестве конечного видео это сказаться не должно. </translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="263"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Нагрузка на CPU:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="265"/>
        <source>fastest</source>
        <translation>наибыстрейший</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>slowest</source>
        <translation>очень медленный</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="271"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Скорость кодирования.
</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="273"/>
        <location filename="../GUI/PageOutput.cpp" line="328"/>
        <source>Custom options:</source>
        <translation>Пользовательские настройки:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="275"/>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Пользовательские настройки для кодека, разделенные запятыми 
Пример: настройка1=значение1,настройка2=значение2, настройка3=значение3</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="276"/>
        <source>Allow frame skipping</source>
        <translation>Разрешить пропуск кадров</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Если установить флажок, то программа разрешит кодировщику видео 
пропускать кадры в том случае если входная частота кадров ниже выходной.
 Если флажок снят, то программа будет дублировать входящие кадры 
чтобы заполнить пробелы. Это повысит размер конечного файла и нагрузку 
на процессор, однако (в ряде случаев) это уменьшит задержку при потоковой 
трансляции через интернет. На качество на качество получаемого видео опция 
не влияет.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Audio</source>
        <translation>Звук</translation>
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
        <translation>Кодек, который будет использован для кодирования вашего аудиопотока. Можете особо не волноваться по его поводу,
потому как размер аудиоданных не в пример меньше, чем размер видеоданных. И если вы записываете только свой голос 
(без музыки) - можете выставлять любые настройки качества.
- Vorbis (libvorbis) превосходный кодек, рекомендую использовать именно его.
-MP3 (libmp3lame) довольно хороший кодек.
- AAC хороший кодек, но в данной программе он реализован плохо (libvo_aacenc или экспериментальный энкодер FFMPEG AAC)
   Используйте только когда у вас нет другого выбора.
- Если  выбрать &quot;без сжатия&quot; то звук будет просто помещен в файл без компрессии. Файл получится довольно большой, 
   зато кодирование пройдет очень быстро. </translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="324"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Для продвинутых пользователей. 
Вы можете использовать любой libav/ffmpeg кодек, 
однако многие из них попросту бесполезны и могут не работать.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="327"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Битрейт звука (в килобитах в секунду). 
Более высокое значение даст более высокое качество. 
Обычно используют значение 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="344"/>
        <source>Back</source>
        <translation>Назад</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Continue</source>
        <translation>Далее</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="564"/>
        <location filename="../GUI/PageOutput.cpp" line="572"/>
        <source>not installed</source>
        <translation>не установлена</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="566"/>
        <location filename="../GUI/PageOutput.cpp" line="574"/>
        <source>not supported by container</source>
        <translation>не поддерживается контейнером</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="617"/>
        <source>Save recording as</source>
        <translation>Сохранить запись как</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="657"/>
        <source>You did not select an output file!</source>
        <translation>Вы не выбрали выходной файл!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="662"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>Запись &quot;%1&quot; уже существует. Вы уверены что хотите перезаписать ее?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="146"/>
        <source>Recording</source>
        <translation>Запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="150"/>
        <source>Enable recording hotkey</source>
        <translation>Включить горячие клавиши</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Enable sound notifications</source>
        <translation>Включить звуковое оповещение</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Hotkey:</source>
        <translation>Горячая клавиша:</translation>
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
        <translation>Клавиша, которую потребуется нажать (в сочетании с кнопкой-модификатором) для начала или приостановки записи. </translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="198"/>
        <source>Information</source>
        <translation>Информация</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="200"/>
        <source>Total time:</source>
        <translation>Всего прошло:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="202"/>
        <source>FPS in:</source>
        <translation>FPS (вход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="204"/>
        <source>FPS out:</source>
        <translation>FPS (выход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="206"/>
        <source>Size in:</source>
        <translation>Размер (вход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="208"/>
        <source>Size out:</source>
        <translation>Размер (выход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="210"/>
        <source>File name:</source>
        <translation>Имя файла:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="213"/>
        <source>File size:</source>
        <translation>Размер файла:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="215"/>
        <source>Bit rate:</source>
        <translation>Битрейт:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Preview</source>
        <translation>Предпросмотр</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>Preview frame rate:</source>
        <translation>Битрейт предпросмотра:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Примечание: Предпросмотр создаст дополнительную нагрузку на процессор (особенно при высоком битрейте).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="295"/>
        <source>Log</source>
        <translation>Журнал</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="310"/>
        <location filename="../GUI/PageRecord.cpp" line="318"/>
        <source>Cancel recording</source>
        <translation>Отменить запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="311"/>
        <location filename="../GUI/PageRecord.cpp" line="320"/>
        <source>Save recording</source>
        <translation>Сохранить запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="325"/>
        <source>Quit</source>
        <translation>Выход</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="368"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Текущая запись не была сохранена и если вы выйдите она будет потеряна.
Вы действительно хотите выйти?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="380"/>
        <source>Hide window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="382"/>
        <source>Show window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="535"/>
        <source>Starting page ...</source>
        <translation>Запускаю...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="556"/>
        <location filename="../GUI/PageRecord.cpp" line="698"/>
        <location filename="../GUI/PageRecord.cpp" line="783"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Ошибка: Во время инициализации что-то пошло не так.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="563"/>
        <source>Started page.</source>
        <translation>Запущено.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="587"/>
        <source>Stopping page ...</source>
        <translation>Останавливаю...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="612"/>
        <source>Stopped page.</source>
        <translation>Остановлено.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="637"/>
        <source>Starting output ...</source>
        <translation>Начинаю вывод...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="648"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Ошибка: Не могу получить размер приложения OpenGL из-за отсутствия файла ввода GLInject.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="653"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Ошибка: Не могу получить размер приложения OpenGL. Тут могут быть две проблемы: либо приложение запущено неправильно, либо оно еще не успело создать окно OpenGL. Если вы хотите начать запись до запуска приложения - включите растяжение и введите размер видео вручную.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="689"/>
        <source>Started output.</source>
        <translation>Вывод начат.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="709"/>
        <source>Stopping output ...</source>
        <translation>Прекращаю вывод...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="727"/>
        <source>Stopped output.</source>
        <translation>Вывод прекращен.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="754"/>
        <source>Starting input ...</source>
        <translation>Начинаю ввод...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="759"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Ошибка: Не могу запустить ввод GLInject так как он не был создан.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="778"/>
        <source>Started input.</source>
        <translation>Ввод начат.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="803"/>
        <source>Stopping input ...</source>
        <translation>Прекращаю ввод...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="814"/>
        <source>Stopped input.</source>
        <translation>Ввод прекращен.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="830"/>
        <source>Encoding remaining data ...</source>
        <translation>Кодирую оставшиеся данные...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="901"/>
        <location filename="../GUI/PageRecord.cpp" line="912"/>
        <source>Pause recording</source>
        <translation>Приостановить запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="905"/>
        <location filename="../GUI/PageRecord.cpp" line="915"/>
        <source>Start recording</source>
        <translation>Начать запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="923"/>
        <source>Stop preview</source>
        <translation>Остановить предпросмотр</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="926"/>
        <source>Start preview</source>
        <translation>Начать предпросмотр</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="955"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="995"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Вы уверены что хотите отменить запись?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1010"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>Вы ничего не записали. Сохранять нечего.

Кнопка записи находится сверху, если что ;).</translation>
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
        <translation>&lt;p&gt;Добро пожаловать в SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Несмотря на название, у моей программы есть множество настроек. Но не волнуйтесь, на самом деле вам нужно знать всего две вещи. Во-первых, настройки по-умолчанию обычно работают лучше всего. Если вы не знаете как работает та или иная настройка - просто оставьте все как есть. Во-вторых, практически каждая настройка имеет всплывающую подсказку. Просто наведите мышку на интересующую вас настройку чтобы узнать что она делает.&lt;/p&gt;

&lt;p&gt;За подробной информацией заходите на мой сайт:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="44"/>
        <source>About SimpleScreenRecorder</source>
        <translation>О SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="45"/>
        <source>Continue</source>
        <translation>Продолжить</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="28"/>
        <source>Profile</source>
        <translation>Профиль</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Сохранить</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Сохранить текущие настройки в этот профиль.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Новый</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Создать новый профиль с текущими настройками.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Удалить</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Удалить этот профиль.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(пусто)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Ошибка: Не могу загрузить профиль!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Вы уверены что хотите перезаписать этот профиль?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Введите имя для профиля:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Профиль с таким именем уже существует. Вы уверены что хотите заменить его?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Вы уверены что хотите удалить этот профиль?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation type="unfinished">&amp;OK</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation type="unfinished">&amp;Отмена</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation type="unfinished">&amp;Да</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation type="unfinished">Да, всегда</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation type="unfinished">&amp;Нет</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation type="unfinished">Нет, никогда</translation>
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
        <translation type="obsolete">&amp;Отмена</translation>
    </message>
    <message>
        <source>&amp;Yes</source>
        <translation type="obsolete">&amp;Да</translation>
    </message>
    <message>
        <source>Yes, always</source>
        <translation type="obsolete">Да, всегда</translation>
    </message>
    <message>
        <source>&amp;No</source>
        <translation type="obsolete">&amp;Нет</translation>
    </message>
    <message>
        <source>No, never</source>
        <translation type="obsolete">Нет, никогда</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Диаграмма Синхронизации</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="251"/>
        <source>Video in</source>
        <translation>Видео (вход)</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="252"/>
        <source>Audio in</source>
        <translation>Аудио (вход)</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="253"/>
        <source>Video out</source>
        <translation>Видео (выход)</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="254"/>
        <source>Audio out</source>
        <translation>Аудио (выход)</translation>
    </message>
</context>
</TS>
