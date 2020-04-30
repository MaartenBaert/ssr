<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="ru_RU">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>About SimpleScreenRecorder</source>
        <translation>О SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="120"/>
        <source>For more information:</source>
        <translation>Более подробная информация доступна на сайте:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="121"/>
        <source>The source code of this program can be found at:</source>
        <translation>Исходный код программы можно найти здесь:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="122"/>
        <source>This program uses:</source>
        <translation>Эта программа использует:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="123"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 — графический интерфейс</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="124"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 или %2 — кодирование аудио/видео (зависит от вашего дистрибутива)</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="125"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 — для подключения системных функций при записи OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="35"/>
        <source>OpenGL Settings</source>
        <translation>Настройки OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="38"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Предупреждение: для записи OpenGL потребуется ввести в записываемую программу дополнительную библиотеку. Эта библиотека перераспределит некоторые системные функции так, чтобы записывать кадры до их отображения на экране. Если вы попытаетесь записать игру, которая умеет распознавать взлом со стороны клиента, то (теоретически) это может быть расценено как попытка взлома. Ваша учётная запись может быть заблокирована, так что перед тем, как начинать запись, учтите возможные последствия. Вы предупреждены :)&lt;/p&gt;

&lt;p&gt;Ещё одно предупреждение: запись через OpenGL это экспериментальная функция, которая может привести к аварийному завершению работы программы или же не сработать вообще. Если вы беспокоитесь за сохранность ваших данных, то обязательно сделайте резервную копию!&lt;/p&gt;

&lt;p&gt;Если вы хотите записывать игры из Steam, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;для начала прочтите вот это&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="52"/>
        <source>Choose channel</source>
        <translation>Выбрать канал</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="54"/>
        <source>Channel name:</source>
        <translation>Имя канала:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="56"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Имена каналов используются для идентификации приложений. Используйте имена только в случае записи нескольких приложений одновременно. Если оставить поле пустым, то по умолчанию приложению будет присвоено имя «channel-ВАШЕИМЯПОЛЬЗОВАТЕЛЯ».</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Упростить доступ к совместной памяти (небезопасно)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Если включить эту функцию, то у пользователей вашего компьютера появится возможность подключаться к совместной памяти, которая используется программой для записи через OpenGL. Это означает, что другие пользователи (теоретически) могут видеть то, что вы записываете, модифицировать запись, вставлять свои кадры или просто прерывать соединение. Это также применимо и к удалённым пользователям, подключённым через SSH. Используйте эту опцию только тогда, когда нужно записать программу, запущенную от имени другого пользователя.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="74"/>
        <source>Launch application</source>
        <translation>Запустить приложение</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="76"/>
        <source>Command:</source>
        <translation>Команда:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="78"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Команда запуска программы, которая будет записываться.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="80"/>
        <source>Working directory:</source>
        <translation>Рабочий каталог:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="82"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Каталог, в котором будет выполнена команда. Если оставить поле пустым, рабочий каталог не изменится.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>Launch automatically</source>
        <translation>Запускать автоматически</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="85"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Если флажок установлен, то записываемая программа запустится сразу же после перехода к окну записи. 
Если оставить функцию выключенной, то нужно будет запустить программу самостоятельно.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="87"/>
        <source>Launch now</source>
        <translation>Запустить сейчас</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="108"/>
        <source>Stream settings</source>
        <translation>Настройка потокового видео</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>Limit application frame rate</source>
        <translation>Ограничить частоту кадров приложения</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="111"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Если включить эту функцию, то подключённая библиотека будет замедлять приложение таким образом, чтобы частота кадров приложения не превышала частоту кадров записи. Благодаря этому приложение не будет расходовать ресурсы процессора на те кадры, которые не попадут в конечную запись. Иногда это позволяет получить более качественную запись (зависит от приложения).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="120"/>
        <source>Close</source>
        <translation>Закрыть</translation>
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
        <translation type="unfinished">Закрыть</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Ошибка: коэффициент передискретизации вне допустимого диапазона!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Ошибка: коэффициент смещения (drift) вне допустимого диапазона!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Коэффициент передискретизации — %1 (ранее — %2).</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="129"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Предупреждение: формат пикселов не поддерживается (%1 -&gt; %2), используется swscale. Это не ошибка, но снижает производительность.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="138"/>
        <location filename="../Benchmark.cpp" line="124"/>
        <location filename="../Benchmark.cpp" line="205"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Ошибка: не удалось получить контекст swscale!</translation>
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
        <translation>Предупреждение: память не выровнена надлежащим образом для SSE, используется резервный (fallback) конвертер. Это не ошибка, но снижает производительность.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="33"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Предупреждение: произошло переполнение (overrun), некоторые сэмплы потеряны.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Ошибка: не удалось восстановить устройство после переполнения (overrun)!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="39"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Ошибка: не удалось запустить PCM-устройство после переполнения (overrun)!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="67"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="55"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation>Остановка входного потока...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="97"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation>Создание списка источников...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Ошибка: не удалось обновить конфигурацию ALSA!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="163"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Найден подключаемый модуль: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="176"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Предупреждение: не удалось подключиться к звуковой карте %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="182"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Предупреждение: не удалось получить информацию о звуковой карте %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="186"/>
        <source>Found card: [%1] %2</source>
        <translation>Найдена карта: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="211"/>
        <source>Found device: [%1] %2</source>
        <translation>Найдено устройство: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="260"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Ошибка: не удалось подключиться к PCM-устройству!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="264"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Ошибка: не удалось получить параметры PCM-устройства!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="270"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Ошибка: не удалось установить тип доступа!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="276"/>
        <location filename="../AV/SimpleSynth.cpp" line="140"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Ошибка: не удалось установить формат сэмплов!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="283"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Ошибка: не удалось установить частоту дискретизации!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="287"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Предупреждение: частота дискретизации %1 не поддерживается, используется %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="296"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Ошибка: не удалось установить количество каналов!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="300"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Предупреждение: количество каналов %1 не поддерживается, используется %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="309"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Ошибка: не удалось установить размер промежутка!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="313"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Предупреждение: размер промежутка %1 не поддерживается, используется %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="322"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Ошибка: не удалось установить размер буфера!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="326"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Предупреждение: размер буфера %1 не поддерживается, используется %2. Ничего страшного.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Ошибка: не удалось применить параметры PCM-устройства!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="352"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Ошибка: не удалось запустить PCM-устройство!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="237"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/X11Input.cpp" line="439"/>
        <source>Input thread started.</source>
        <translation>Входной поток запущен.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="388"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Ошибка: не удалось прочесть сэмплы!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="414"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="358"/>
        <location filename="../AV/Input/JACKInput.cpp" line="288"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/X11Input.cpp" line="554"/>
        <source>Input thread stopped.</source>
        <translation>Входной поток остановлен.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="418"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="362"/>
        <location filename="../AV/Input/JACKInput.cpp" line="292"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/X11Input.cpp" line="558"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Исключение «%1» во входном потоке.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="421"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="365"/>
        <location filename="../AV/Input/JACKInput.cpp" line="295"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/X11Input.cpp" line="561"/>
        <source>Unknown exception in input thread.</source>
        <translation>Неизвестное исключение во входном потоке.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="259"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Ошибка: не удалось прочесть поток данных. Обычно это означает, что поток данных больше не существует.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="71"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Ошибка: не удалось подключиться к JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="80"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Ошибка: не удалось создать порт JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="86"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Ошибка: не удалось установить обратный вызов процесса JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="90"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Ошибка: не удалось установить обратный вызов частоты дискретизации JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="94"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Ошибка: не удалось установить обратный вызов xrun JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="98"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Ошибка: не удалось установить обратный вызов подключения к порту JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="103"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Ошибка: не удалось включить клиент JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="111"/>
        <location filename="../AV/Input/JACKInput.cpp" line="122"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Подключение порта %1 к %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="255"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>Отключение порта %1 от %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="34"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Ошибка: не удалось выполнить pa_mainloop_prepare!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="38"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Ошибка: не удалось выполнить pa_mainloop_poll!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="42"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Ошибка: не удалось выполнить pa_mainloop_dispatch!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="52"/>
        <source>Error: Could not create main loop!</source>
        <translation>Ошибка: не удалось создать главный цикл!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="59"/>
        <source>Error: Could not create context!</source>
        <translation>Ошибка: не удалось создать контекст!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Ошибка: не удалось подключиться! Причина: %1
Возможно, в вашей системе не используется PulseAudio. Попробуйте использовать сервер ALSA.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="68"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio.</source>
        <translation>Ошибка: не удалось подключиться! Причина: %1
Возможно, в вашей системе не используется PulseAudio.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="82"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Ошибка: сбой попытки подключения! Причина: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="119"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Ошибка: не удалось создать поток данных! Причина: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="126"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Ошибка: не удалось подключить поток данных! Причина: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="137"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Ошибка: сбой попытки подключения потока данных! Причина: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="228"/>
        <source>Found source: [%1] %2</source>
        <translation>Найден источник: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="249"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Ошибка: не удалось получить имена источников! Причина: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="297"/>
        <source>Error: Could not get source info! Reason: %1</source>
        <translation>Ошибка: не удалось получить информацию об источнике! Причина: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="302"/>
        <source>Stream is a monitor.</source>
        <translation>Поток данных является монитором.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="304"/>
        <source>Stream is not a monitor.</source>
        <translation>Поток данных не является монитором.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="349"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Ошибка: не удалось выполнить pa_stream_peek!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="416"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Предупреждение: источник аудио приостановлен. Текущий сегмент будет остановлен до возобновления источника.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="421"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Предупреждение: поток данных был перемещён в другой источник.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation>Создано средство чтения видеопотока.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Ошибка: не удалось открыть файл видеопотока!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation>Ошибка: не удалось изменить размер файла видеопотока!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Ошибка: не удалось отобразить файл видеопотока в память!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Ошибка: не удалось открыть файл видеокадра!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation>Уничтожено средство чтения видеопотока.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Ошибка: неверный размер файла видеокадра!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Ошибка: не удалось отобразить файл видеокадра в память!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="94"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation>Ошибка: не удалось создать каталог канала!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="102"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation>Ошибка: не удалось получить информацию о каталоге канала!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="106"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Ошибка: каталог канала не является обычным каталогом!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="111"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation>Ошибка: не удалось установить режим каталога канала!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="116"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Ошибка: владельцем каталога канала является другой пользователь! Выберите другое имя канала (или включите менее строгие разрешения файла, чтобы всё же использовать его).</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="126"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Ошибка: не удалось инициализировать inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation>Ошибка: не удалось выполнить отслеживание каталога канала!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation>Ошибка: не удалось открыть каталог канала!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Добавлен существующий поток данных %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Ошибка: не удалось получить длину чтения из inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Ошибка: не удалось выполнить чтение из inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Ошибка: получено частичное событие из inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Ошибка: получено частичное имя из inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation>Добавлен поток данных %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation>Удалён поток данных %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Удалён отброшенный поток данных %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="70"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Ошибка: неподдерживаемый формат пикселов изображения X11!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="96"/>
        <source>Error: Width or height is zero!</source>
        <translation>Ошибка: ширина или высота равна нулю!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="100"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Ошибка: слишком большая ширина или высота, максимально допустимое значение — %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="249"/>
        <location filename="../GUI/HotkeyListener.cpp" line="115"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Ошибка: не удалось открыть диспетчер отображения системы X (X display)!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Using X11 shared memory.</source>
        <translation>Используется совместная память X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="305"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Ошибка: не удалось создать совместно используемое изображение!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="310"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Ошибка: не удалось получить совместную память!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="315"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Ошибка: не удалось присоединить к совместной памяти!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="260"/>
        <source>Not using X11 shared memory.</source>
        <translation>Не используется совместная память X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="267"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Предупреждение: XFixes не поддерживается X-сервером, курсор был скрыт.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="363"/>
        <source>Warning: Xinerama is not supported by X server, multi-monitor support may not work properly.</source>
        <comment>Don&apos;t translate &apos;Xinerama&apos;</comment>
        <translation>Предупреждение: Xinerama не поддерживается X-сервером, поддержка нескольких мониторов может работать некорректно.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="369"/>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation>Предупреждение: мониторы не обнаружены, поддержка нескольких мониторов может работать некорректно.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="388"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Ошибка: некорректный ограничивающий прямоугольник!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="320"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Ошибка: не удалось присоединить сервер к совместной памяти!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="505"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Ошибка: не удалось получить изображение (совместная память используется)!
    Обычно это означает, что область записи не полностью находится в пределах экрана. Возможно, вы изменили разрешение экрана?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="516"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Ошибка: не удалось получить изображение (совместная память не используется)!
    Обычно это означает, что область записи не полностью находится в пределах экрана. Возможно, вы изменили разрешение экрана?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="100"/>
        <source>Error: Channel count is zero.</source>
        <translation>Ошибка: количество каналов равно нулю.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="104"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Ошибка: частота дискретизации равна нулю.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="142"/>
        <source>Using sample format %1.</source>
        <translation>Используется формат сэмплов %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="147"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Ошибка: для работы кодировщика требуется формат сэмплов, который не поддерживается!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <source>Error: Sending of audio frame failed!</source>
        <translation>Ошибка: не удалось отправить аудиокадр!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Receiving of audio packet failed!</source>
        <translation>Ошибка: не удалось получить аудиопакет!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="210"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="232"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Ошибка: не удалось кодировать аудиокадр!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="30"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="39"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Ошибка: не удалось выполнить синтаксический разбор параметра «%1»!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation>Остановка потока кодировщика...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="164"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Ошибка: не удалось открыть кодек!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="172"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation>Предупреждение: параметр кодека «%1» не распознан!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="188"/>
        <source>Encoder thread started.</source>
        <translation>Поток кодировщика запущен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="217"/>
        <source>Flushing encoder ...</source>
        <translation>Очистка кодировщика...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="228"/>
        <source>Encoder thread stopped.</source>
        <translation>Поток кодировщика остановлен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Исключение «%1» в потоке кодировщика.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="235"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Неизвестное исключение в потоке кодировщика.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="70"/>
        <source>Stopping encoders ...</source>
        <translation>Остановка кодировщиков...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="77"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Ожидание остановки потока мультиплексора...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <location filename="../AV/Output/Muxer.cpp" line="124"/>
        <source>Error: Can&apos;t copy parameters to stream!</source>
        <translation>Ошибка: не удалось скопировать параметры в поток данных!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="146"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Ошибка: не удалось записать заголовок (header)!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="157"/>
        <source>Finishing encoders ...</source>
        <translation>Завершение кодировщиков...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Ошибка: не удалось найти выбранный формат вывода!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Using format %1 (%2).</source>
        <translation>Используется формат %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="209"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Ошибка: не удалось выделить контекст формата!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Ошибка: не удалось открыть выходной файл!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="229"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Ошибка: не удалось записать трейлер (trailer), но операция будет продолжена.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="267"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Ошибка: не удалось найти кодек!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="277"/>
        <source>Using codec %1 (%2).</source>
        <translation>Используется кодек %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="288"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Ошибка: не удалось создать новый поток данных!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="295"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation>Ошибка: не удалось создать новый контекст кодека!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="307"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Ошибка: не удалось получить параметры по умолчанию контекста кодека!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="320"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Предупреждение: этот кодек считается экспериментальным для libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="336"/>
        <source>Muxer thread started.</source>
        <translation>Поток мультиплексора запущен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="396"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Ошибка: не удалось записать кадр в мультиплексор!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="424"/>
        <source>Muxer thread stopped.</source>
        <translation>Поток мультиплексора остановлен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="428"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Исключение «%1» в потоке мультиплексора.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="431"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Неизвестное исключение в потоке мультиплексора.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="220"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Остановка потока синхронизатора...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="328"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Предупреждение: получен видеокадр с немонотонной временной меткой.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="355"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Предупреждение: переполнение видеобуфера, некоторые кадры будут потеряны. Похоже, аудиовход работает слишком медленно.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="412"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Предупреждение: получены аудиосэмплы с немонотонной временной меткой.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="437"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Предупреждение: слишком много аудиосэмплов. Сэмплы отбрасываются для поддержания синхронизации аудио и видео.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="443"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Предупреждение: недостаточно аудиосэмплов. Вставляется тишина для поддержания синхронизации аудио и видео.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="509"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Предупреждение: аудиовход работает слишком медленно (более чем на 2%)!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="513"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Предупреждение: аудиовход работает слишком быстро (более чем на 2%)!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="548"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Предупреждение: переполнение аудиобуфера. Начат новый сегмент для поддержания синхронизации аудио и видео (часть видео и/или аудио может быть потеряна). Похоже, видеовход работает слишком медленно.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="584"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Предупреждение: получен пробел в аудиопотоке. Вставляется тишина для поддержания синхронизации аудио и видео.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="885"/>
        <source>Synchronizer thread started.</source>
        <translation>Поток синхронизатора запущен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="907"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Поток синхронизатора остановлен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="911"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Исключение «%1» в потоке синхронизатора.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="914"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Неизвестное исключение в потоке синхронизатора.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="104"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Ошибка: ширина или высота не является чётным числом!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="108"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Ошибка: частота кадров равна нулю!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="165"/>
        <source>Using pixel format %1.</source>
        <translation>Используется формат пикселов %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="179"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Ошибка: формат пикселов не поддерживается этим кодеком!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="207"/>
        <source>Error: Sending of video frame failed!</source>
        <translation>Ошибка: не удалось отправить видеокадр!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="228"/>
        <source>Error: Receiving of video packet failed!</source>
        <translation>Ошибка: не удалось получить видеопакет!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="241"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="262"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Ошибка: не удалось кодировать видеокадр!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="41"/>
        <source>Using real-time priority.</source>
        <translation>Используется максимальный приоритет.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="51"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation>Используется приоритет «nice».</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation>Предупреждение: не удалось повысить приоритет потока.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="64"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Ошибка: не удалось восстановить устройство после опустошения (underrun)!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="91"/>
        <source>Stopping synth thread ...</source>
        <translation>Остановка потока синтезатора...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="224"/>
        <source>Synth thread started.</source>
        <translation>Поток синтезатора запущен.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="277"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Ошибка: не удалось записать сэмплы!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="285"/>
        <source>Synth thread stopped.</source>
        <translation>Поток синтезатора остановлен.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="289"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Исключение «%1» в потоке синтезатора.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="292"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Неизвестное исключение в потоке синтезатора.</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="45"/>
        <source>CPU features</source>
        <translation>Характеристики ЦП</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>The application could not be launched.</source>
        <translation>Не удалось запустить приложение.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="161"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation>Предупреждение: XInput2 не поддерживается X-сервером, комбинации клавиш могут не работать в некоторых приложениях.</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="78"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="86"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Ошибка: параметр командной строки «%1» не принимает значение!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="179"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Ошибка: неизвестный параметр командной строки «%1»!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="187"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Ошибка: неизвестный аргумент командной строки «%1»!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="96"/>
        <source>SSR started</source>
        <translation>Программа SSR запущена</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="127"/>
        <source>SSR stopped</source>
        <translation>Программа SSR остановлена</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="228"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Ошибка: не удалось создать каталог .ssr!</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="165"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation>BGRA %1 в BGRA %2  |  SWScale %3 мкс  |  Fallback %4 мкс (%5%)  |  SSSE3 %6 мкс (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="243"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation>%1 %2 в %3 %4  |  SWScale %5 мкс  |  Fallback %6 мкс (%7%)  |  SSSE3 %8 мкс (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="253"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Запуск теста производительности средства растяжения...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="260"/>
        <source>Starting converter benchmark ...</source>
        <translation>Запуск теста производительности конвертера...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="70"/>
        <source>Stopping fragment thread ...</source>
        <translation>Остановка потока фрагментов...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="346"/>
        <source>Fragment thread started.</source>
        <translation>Поток фрагментов запущен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="364"/>
        <source>Next fragment ...</source>
        <translation>Следующий фрагмент...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="368"/>
        <source>Finishing ...</source>
        <translation>Завершение...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="380"/>
        <source>Fragment thread stopped.</source>
        <translation>Поток фрагментов остановлен.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="384"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation>Исключение «%1» в потоке фрагментов.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="387"/>
        <source>Unknown exception in fragment thread.</source>
        <translation>Неизвестное исключение в потоке фрагментов.</translation>
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
        <translation>Программой SimpleScreenRecorder обнаружено, что используется закрытый драйвер NVIDIA с включённой опцией переключения (flipping). Эта опция может создавать помехи при записи. Настоятельно рекомендуется её отключить. Отключить эту опцию?

Вы также можете самостоятельно отключить её через панель управления NVIDIA.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="108"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Не удалось отключить опцию переключения (flipping)... Попробуйте отключить её через панель управления NVIDIA.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Запись сохранена. Теперь можно начать редактирование или перекодировать запись для достижения меньшего размера файла (настройки по умолчанию оптимизированы для обеспечения высокой скорости и качества, но не для уменьшения размера).</translation>
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
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Video input</source>
        <translation>Настройки видео</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>Record the entire screen</source>
        <translation>Записать весь экран</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="247"/>
        <source>Record a fixed rectangle</source>
        <translation>Записать выделенную область</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="248"/>
        <source>Follow the cursor</source>
        <translation>Следовать за курсором</translation>
    </message>
    <message>
        <source>Record OpenGL (experimental)</source>
        <translation type="obsolete">Записать OpenGL (экспериментально)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="241"/>
        <source>Input profile</source>
        <translation>Профиль для входа</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="250"/>
        <source>Record OpenGL</source>
        <translation>Запись OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="259"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Выберите монитор, который будет использоваться для записи.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>Record entire screen with cursor</source>
        <translation>Записать весь экран с курсором</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="261"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation>Записать весь экран, на котором расположен курсор, а не следовать за положением курсора.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <source>Select rectangle...</source>
        <translation>Выбрать область...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="263"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Используйте мышь, чтобы выделить область для записи.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="264"/>
        <source>Select window...</source>
        <translation>Выбрать окно...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Используйте мышь, чтобы выбрать окно для записи.
Совет: если вы щёлкните по границам окна — будет записано окно целиком, 
в противном случае запишется только рабочая часть окна.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="269"/>
        <source>OpenGL settings...</source>
        <translation>Настройки OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Изменить настройки записи OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="272"/>
        <source>Left:</source>
        <translation>Слева:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Координата верхнего левого угла записываемой области по оси Х.
Совет: вы также можете изменять это значение с помощью 
колеса мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="278"/>
        <source>Top:</source>
        <translation>Сверху:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="282"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Координата верхнего левого угла записываемой области по оси Y.
Совет: вы также можете изменять это значение с помощью 
колеса мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="284"/>
        <source>Width:</source>
        <translation>Ширина:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="288"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Ширина записываемой области.
Совет: вы также можете изменять это значение
с помощью колеса мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="290"/>
        <source>Height:</source>
        <translation>Высота:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="294"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Высота записываемой области.
Совет: вы также можете изменять это значение 
с помощью колеса мыши или стрелок вверх/вниз.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="296"/>
        <source>Frame rate:</source>
        <translation>Частота кадров:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="300"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Количество кадров в секунду у финального видео. 
Более высокая частота кадров потребует больше 
вычислительной мощности процессора.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="301"/>
        <source>Scale video</source>
        <translation>Растянуть видео</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="302"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Включает или отключает растяжение. Растяжение требует больше мощности процессора, однако видео получаются меньше размером и кодируются быстрее.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="303"/>
        <source>Scaled width:</source>
        <translation>Ширина:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="307"/>
        <source>Scaled height:</source>
        <translation>Высота:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="311"/>
        <source>Record cursor</source>
        <translation>Записывать курсор</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="393"/>
        <source>Audio input</source>
        <translation>Настройки звука</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="395"/>
        <source>Record audio</source>
        <translation>Записывать звук</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="396"/>
        <source>Backend:</source>
        <translation>Сервер:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="408"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Звуковой сервер, который будет использован при записи.
Сервер ALSA также будет работать в системах с предустановленным 
PulseAudio, но в таких системах рекомендуется использовать непосредственно сервер PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="411"/>
        <source>The audio backend that will be used for recording.</source>
        <translation>Аудиодвижок, который будет использоваться для записи.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="414"/>
        <location filename="../GUI/PageInput.cpp" line="423"/>
        <source>Source:</source>
        <translation>Источник:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="417"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Источник сервера ALSA, который будет использован при записи. 
Настройки по умолчанию обычно работают лучше всего.
«Общие» источники позволяют разным программам записываться 
одновременно, однако это может быть ненадёжно.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="419"/>
        <location filename="../GUI/PageInput.cpp" line="428"/>
        <source>Refresh</source>
        <translation>Обновить</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="420"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Обновляет список источников ALSA.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="426"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Источник сервера PulseAudio, который будет использован при записи.
«Monitor» — это источник, записывающий звук других приложений.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="429"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Обновляет список источников PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="432"/>
        <source>Record system microphone</source>
        <translation>Записывать звук с микрофона</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="433"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Если флажок установлен, то программа автоматически 
подключится к портам записи вашего компьютера.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="434"/>
        <source>Record system speakers</source>
        <translation>Записывать звук с колонок</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="435"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Если флажок установлен, то программа автоматически 
подключится к любым портам вывода звука вашего компьютера.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="482"/>
        <source>Back</source>
        <translation>Назад</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="483"/>
        <source>Continue</source>
        <translation>Далее</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="916"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Все экраны: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="920"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Экран %1: %2x%3 в %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1132"/>
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
        <location filename="../GUI/PageOutput.cpp" line="133"/>
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
        <location filename="../GUI/PageOutput.cpp" line="173"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Ошибка: не удалось найти подходящий контейнер в libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Ошибка: не удалось найти подходящий видеокодек в libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Ошибка: не удалось найти подходящий аудиокодек в libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Output profile</source>
        <translation>Профиль для выхода</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="191"/>
        <source>File</source>
        <translation>Файл</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="193"/>
        <source>Save as:</source>
        <translation>Сохранить как:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="195"/>
        <source>The recording will be saved to this location.</source>
        <translation>Запись будет сохранена в эту папку.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="196"/>
        <source>Browse...</source>
        <translation>Обзор...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>Separate file per segment</source>
        <translation>Разбить файл на сегменты</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="obsolete">Если флажок установлен, то программа будет создавать 
новый видеофайл при каждой паузе и возврате к записи.
Если исходное имя файла «test.mkv», то сегменты 
будут сохраняться с именем «test-ГГГГ-MM-ДД_ЧЧ.MM.СС.mkv».</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="203"/>
        <source>Container:</source>
        <translation>Контейнер:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="208"/>
        <source>(not installed)</source>
        <translation>(не установлено)</translation>
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
        <translation>Контейнер (формат файла), который будет использован для записи.
Имейте в виду, что обычно контейнеры поддерживают не все типы кодеков 
и проигрыватели мультимедиа поддерживают не все типы файлов.
- Matroska (MKV) поддерживает все типы кодеков, но этот формат мало распространён.
- MP4 является более популярным форматом, и его могут воспроизводить 
   практически все современные проигрыватели мультимедиа, однако он поддерживает только кодек H.264
   (при этом большинство проигрывателей мультимедиа поддерживает звук лишь в формате AAC).
- WebM предназначен для встраивания видео в веб-сайты (при помощи тега &lt;video&gt; в HTML). 
   Этот формат создан Google. WebM по умолчанию поддерживается в Firefox, Chrome и Opera 
   (также существуют подключаемые модули для Internet Explorer и Safari).
   WebM поддерживает только VP8 и Vorbis.
- OGG поддерживает только Theora и Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Container name:</source>
        <translation>Имя контейнера:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Для опытных пользователей. Вы можете использовать любой формат libav/ffmpeg, однако многие из них попросту бесполезны и могут не работать.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="247"/>
        <source>Video</source>
        <translation>Видео</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="249"/>
        <location filename="../GUI/PageOutput.cpp" line="329"/>
        <source>Codec:</source>
        <translation>Кодек:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="254"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Кодек, который будет использован для сжатия видеопотока вашего видео.
- H.264 (libx264) — лучший кодек, обеспечивает высокое качество и отличную скорость.
- VP8 (libvpx) — хороший, но при этом весьма медленный кодек.
- Theora (libtheora) — этот кодек не рекомендуется использовать (посредственное качество).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="258"/>
        <location filename="../GUI/PageOutput.cpp" line="342"/>
        <source>Codec name:</source>
        <translation>Имя кодека:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="264"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Для опытных пользователей. 
Вы можете использовать любой видеокодек libav/ffmpeg, 
однако многие из них попросту бесполезны и могут не работать.</translation>
    </message>
    <message>
        <source>Bit rate (in kbps):</source>
        <translation type="obsolete">Битрейт (кбит/с):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation>Если флажок установлен, при приостановке и возобновлении записи каждый раз будет создаваться отдельный видеофайл. Если флажок снят, все записанные сегменты будут объединены в один видеофайл.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <source>Add timestamp</source>
        <translation>Добавить временную метку</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Если флажок установлен, текущая дата и время будут добавлены к имени файла автоматически.
Если исходное имя файла «test.mkv», видео будет сохранено как «test-ГГГГ-ММ-ДД_ЧЧ.ММ.СС.mkv».</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="265"/>
        <location filename="../GUI/PageOutput.cpp" line="349"/>
        <source>Bit rate (in kbit/s):</source>
        <translation>Битрейт (кбит/с):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Битрейт видео (в килобитах в секунду). 
Чем выше значение, тем выше качество.
Если вы не знаете, какое значение установить, 
попробуйте начать с 5000 и изменяйте при необходимости.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="269"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Постоянный коэффициент потока (CRF):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="274"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Эта настройка изменяет качество видео. Чем ниже значение, тем выше качество.
Допустимое значение: 0—51 (0 — без потерь, 23 — значение по умолчанию).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="280"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Предустановка:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="285"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Скорость кодирования вашего видео. 
Более высокая скорость будет меньше нагружать процессор 
(что позволяет выполнять запись при высокой частоте кадров), 
но в результате вы получите файл большего размера. 
На качестве конечного видео это сказаться не должно.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="287"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Нагрузка на CPU:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="289"/>
        <source>fastest</source>
        <translation>наибыстрейший</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="294"/>
        <source>slowest</source>
        <translation>очень медленный</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="295"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Скорость кодирования. Чем выше значение, тем *ниже* нагрузка на процессор. С увеличением значения снижается качество видео (если только не увеличить также и битрейт).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <location filename="../GUI/PageOutput.cpp" line="352"/>
        <source>Custom options:</source>
        <translation>Пользовательские настройки:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="299"/>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Пользовательские настройки для кодека, разделённые запятыми. Пример: настройка1=значение1,настройка2=значение2, настройка3=значение3</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <source>Allow frame skipping</source>
        <translation>Разрешить пропуск кадров</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="301"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Если флажок установлен, то программа разрешит кодировщику видео пропускать кадры в том случае если входная частота кадров ниже выходной. Если флажок снят, то программа будет дублировать входящие кадры, чтобы заполнить пробелы. Это увеличит размер конечного файла и нагрузку на процессор, однако (в ряде случаев) уменьшит задержку при потоковой трансляции через Интернет. На качество получаемого видео опция не влияет.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="327"/>
        <source>Audio</source>
        <translation>Звук</translation>
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
        <translation>Кодек, который будет использован для сжатия аудиопотока вашего видео. Его выбор не играет особой роли, потому как размер аудиоданных не в пример меньше, чем размер видеоданных. И если вы записываете только свой голос 
(без музыки) — можете выставлять любые настройки качества.
- Vorbis (libvorbis) — превосходный кодек, рекомендуется использовать именно его.
- MP3 (libmp3lame) — довольно хороший кодек.
- AAC — хороший кодек, но в данной программе он реализован плохо (libvo_aacenc или экспериментальный кодировщик FFMPEG AAC).
   Используйте только в тех случаях, когда у вас нет другого выбора.
- Если выбрать вариант «Без сжатия», то звук будет просто помещён в файл без компрессии. Файл получится довольно большим, 
   зато кодирование пройдет очень быстро.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="348"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Для опытных пользователей. 
Вы можете использовать любой аудиокодек libav/ffmpeg, 
однако многие из них попросту бесполезны и могут не работать.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Битрейт звука (в килобитах в секунду). 
Чем выше значение, темы выше качество. 
Обычно используют значение 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="376"/>
        <source>Back</source>
        <translation>Назад</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="377"/>
        <source>Continue</source>
        <translation>Далее</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="631"/>
        <location filename="../GUI/PageOutput.cpp" line="639"/>
        <source>not installed</source>
        <translation>не установлена</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="633"/>
        <location filename="../GUI/PageOutput.cpp" line="641"/>
        <source>not supported by container</source>
        <translation>не поддерживается контейнером</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="684"/>
        <source>Save recording as</source>
        <translation>Сохранить запись как</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="525"/>
        <source>You did not select an output file!</source>
        <translation>Вы не выбрали выходной файл!</translation>
    </message>
    <message>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation type="obsolete">Запись «%1» уже существует. Действительно перезаписать её?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="162"/>
        <source>Recording</source>
        <translation>Запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="168"/>
        <source>Edit schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="171"/>
        <source>Enable recording hotkey</source>
        <translation>Включить горячие клавиши</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="172"/>
        <source>The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,
even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the
SimpleScreenRecorder window show up in the final video.</source>
        <translation>Горячие клавиши — глобальная комбинация клавиш, которую можно использовать для начала или приостановки записи в любой момент, даже когда окно SimpleScreenRecorder не отображается. Таким образом можно создавать записи, в которых не будет окна 
SimpleScreenRecorder.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="176"/>
        <source>Enable sound notifications</source>
        <translation>Включить звуковое оповещение</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="177"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation>Если этот параметр включён, при начале или приостановке записи или при появлении ошибки будет воспроизводиться звук.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="179"/>
        <source>Hotkey:</source>
        <translation>Горячая клавиша:</translation>
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
        <translation>Клавиша, которую потребуется нажать (в сочетании с клавишей-модификатором) для начала или приостановки записи.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Information</source>
        <translation>Информация</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="240"/>
        <source>Total time:</source>
        <translation>Всего прошло:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>FPS in:</source>
        <translation>FPS (вход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="244"/>
        <source>FPS out:</source>
        <translation>FPS (выход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Size in:</source>
        <translation>Размер (вход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="248"/>
        <source>Size out:</source>
        <translation>Размер (выход):</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="250"/>
        <source>File name:</source>
        <translation>Имя файла:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="253"/>
        <source>File size:</source>
        <translation>Размер файла:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="255"/>
        <source>Bit rate:</source>
        <translation>Битрейт:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="278"/>
        <source>Preview</source>
        <translation>Предпросмотр</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="282"/>
        <source>Preview frame rate:</source>
        <translation>Частота кадров предпросмотра:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="286"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Примечание: предпросмотр создаст дополнительную нагрузку на процессор (особенно при высокой частоте кадров).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="335"/>
        <source>Log</source>
        <translation>Журнал</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="350"/>
        <location filename="../GUI/PageRecord.cpp" line="358"/>
        <source>Cancel recording</source>
        <translation>Отменить запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="351"/>
        <location filename="../GUI/PageRecord.cpp" line="360"/>
        <source>Save recording</source>
        <translation>Сохранить запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="365"/>
        <source>Quit</source>
        <translation>Выход</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="415"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Текущая запись не сохранена и будет потеряна при выходе из программы.
Действительно выполнить выход?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="427"/>
        <source>Hide window</source>
        <translation>Скрыть окно</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="429"/>
        <source>Show window</source>
        <translation>Показать окно</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="630"/>
        <source>Starting page ...</source>
        <translation>Запуск...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="653"/>
        <location filename="../GUI/PageRecord.cpp" line="817"/>
        <location filename="../GUI/PageRecord.cpp" line="913"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Ошибка: во время инициализации что-то пошло не так.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="662"/>
        <source>Started page.</source>
        <translation>Запущено.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="694"/>
        <source>Stopping page ...</source>
        <translation>Остановка...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="721"/>
        <source>Stopped page.</source>
        <translation>Остановлено.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="749"/>
        <source>Starting output ...</source>
        <translation>Начало вывода...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="764"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Ошибка: не удалось получить размер приложения OpenGL из-за того, что ввод GLInject не был создан.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="769"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Ошибка: не удалось получить размер приложения OpenGL. Либо приложение запущено неправильно, либо оно ещё не успело создать окно OpenGL. Если вы хотите начать запись до запуска приложения — включите растяжение и введите размер видео вручную.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="808"/>
        <source>Started output.</source>
        <translation>Вывод начат.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="828"/>
        <source>Stopping output ...</source>
        <translation>Прекращение вывода...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="846"/>
        <source>Stopped output.</source>
        <translation>Вывод прекращён.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="877"/>
        <source>Starting input ...</source>
        <translation>Начало ввода...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="883"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Ошибка: не удалось запустить ввод GLInject, так как он не был создан.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="908"/>
        <source>Started input.</source>
        <translation>Ввод начат.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="937"/>
        <source>Stopping input ...</source>
        <translation>Прекращение ввода...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="952"/>
        <source>Stopped input.</source>
        <translation>Ввод прекращён.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="968"/>
        <source>Encoding remaining data ...</source>
        <translation>Кодирование оставшихся данных...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1061"/>
        <location filename="../GUI/PageRecord.cpp" line="1071"/>
        <source>Pause recording</source>
        <translation>Приостановить запись</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1064"/>
        <location filename="../GUI/PageRecord.cpp" line="1074"/>
        <source>Start recording</source>
        <translation>Начать запись</translation>
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
        <translation>Остановить предпросмотр</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1104"/>
        <source>Start preview</source>
        <translation>Начать предпросмотр</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1145"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Ошибка: при создании синтезатора что-то пошло не так.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1193"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Действительно отменить запись?</translation>
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
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation type="obsolete">Вы ничего не записали. Сохранять нечего.

Кнопка записи находится сверху, если что ;)</translation>
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
        <translation>&lt;p&gt;Добро пожаловать в SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Несмотря на название, у программы есть множество настроек. Но на самом деле вам нужно знать всего две вещи. Во-первых, настройки по умолчанию обычно работают лучше всего. Если вы не знаете, как работает та или иная настройка — просто оставьте всё как есть. Во-вторых, практически каждая настройка имеет всплывающую подсказку. Просто наведите курсор мыши на интересующую вас настройку, чтобы получить сведения о ней.&lt;/p&gt;

&lt;p&gt;Подробная информация доступна на сайте:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="51"/>
        <source>About SimpleScreenRecorder</source>
        <translation>О SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="52"/>
        <source>Skip this page next time</source>
        <translation>Не показывать это окно в следующий раз</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="53"/>
        <source>Go directly to the input page when the program is started.</source>
        <translation>Перейти прямо в окно ввода при запуске программы.</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="76"/>
        <source>Continue</source>
        <translation>Продолжить</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <source>Profile</source>
        <translation type="obsolete">Профиль</translation>
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
        <translation>(нет)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Ошибка: не удалось загрузить профиль!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Действительно перезаписать этот профиль?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Введите имя для профиля:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Профиль с таким именем уже существует. Действительно заменить его?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Действительно удалить этот профиль?</translation>
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
        <translation>&amp;Отмена</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Да</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Да, всегда</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Нет</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Нет, никогда</translation>
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
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Диаграмма синхронизации</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="257"/>
        <source>Video in</source>
        <translation>Видео (вход)</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="258"/>
        <source>Audio in</source>
        <translation>Аудио (вход)</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="259"/>
        <source>Video out</source>
        <translation>Видео (выход)</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="260"/>
        <source>Audio out</source>
        <translation>Аудио (выход)</translation>
    </message>
</context>
</TS>
