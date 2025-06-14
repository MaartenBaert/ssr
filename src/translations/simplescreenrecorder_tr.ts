<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="tr_TR">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>About SimpleScreenRecorder</source>
        <translation>SimpleScreenRecorder Hakkında</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="120"/>
        <source>For more information:</source>
        <translation>Daha fazla bilgi için:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="121"/>
        <source>The source code of this program can be found at:</source>
        <translation>Bu programın kaynak kodlarına şu adresten ulaşabilirsiniz:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="122"/>
        <source>This program uses:</source>
        <translation>Bu program şunları kullanır:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="123"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 grafik kullanıcı arayüzü için</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="124"/>
        <source>%1 for video/audio encoding</source>
        <translation>%1 video/ses kodlaması için</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="125"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1, OpenGL kaydı için sistem fonksiyonlarını yakalamak amacıyla</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="35"/>
        <source>OpenGL Settings</source>
        <translation>OpenGL  Ayarları</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="38"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Uyarı: OpenGL kaydı, kaydedilecek programa bir kütüphane enjekte ederek çalışır. Bu kütüphane, kareleri ekranda görüntülenmeden önce yakalamak için bazı sistem işlevlerini geçersiz kılacaktır. Eğer istemci tarafında hile girişimlerini tespit etmeye çalışan bir oyunu kaydetmeye çalışıyorsanız, bu oyun teorik olarak bu durumu bir hack olarak kabul edebilir. Bu durum yasaklanmanıza bile neden olabilir, bu nedenle kaydetmek istediğiniz programın sizi yasaklamayacağından *kaydetmeye çalışmadan önce* emin olmak iyi bir fikirdir. Bizden söylemesi :) &lt;/p&gt;

&lt;p&gt;Başka bir uyarı: OpenGL kaydı deneyseldir, çalışmayabilir veya kaydedilen programın çökmesine neden olabilir. Program verilerinizi kaybetme konusunda endişeleriniz varsa, öncelikle bir yedek oluşturun!&lt;/p&gt;

&lt;p&gt;Steam oyunlarını kaydetmek istiyorsanız, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;öncelikle burayı okuyun&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="52"/>
        <source>Choose channel</source>
        <translation>Kanal seç</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="54"/>
        <source>Channel name:</source>
        <translation>Kanal adı</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="56"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Kanal isimleri, uygulamaları tanımlamak için kullanılır. Bunu sadece aynı anda birden fazla uygulamayı kaydetmek istiyorsanız kullanmanız gerekir. Bu alanı boş bırakırsanız, varsayılan olarak channel-YOURUSERNAME ismi kullanılacaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Paylaşılan bellek izinlerini esnetin (güvensiz)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="59"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Eğer işaretlenirse, aynı makinedeki diğer kullanıcılar OpenGL programıyla iletişimde kullanılan paylaşılan belleğe erişebilir. Bu, diğer kullanıcıların (teorik olarak) kaydettiğiniz görüntüyü görebilmeleri, kareleri değiştirebilmeleri, kendi karelerini enjekte edebilmeleri veya iletişimi kesintiye uğratabilmeleri anlamına gelir. Bu durum, uzaktan (örneğin SSH ile) oturum açmış kullanıcılar için de geçerlidir. Bu seçeneği yalnızca, farklı bir kullanıcı hesabı altında çalışan bir programı kaydetmeniz gerektiğinde etkinleştirmelisiniz.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="74"/>
        <source>Launch application</source>
        <translation>Uygulamayı başlat</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="76"/>
        <source>Command:</source>
        <translation>Komut:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="78"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Bu komut, kaydedilmesi gereken programı başlatmak için çalıştırılacaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="80"/>
        <source>Working directory:</source>
        <translation>Çalışma dizini:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="82"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Komut bu dizinde çalıştırılacaktır. Eğer bu alanı boş bırakırsanız, çalışma dizini değiştirilmeden kalacaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>Launch automatically</source>
        <translation>Otomatik olarak başlat</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="85"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Eğer işaretlenirse, kayıt sayfasına gittiğinizde uygulama otomatik olarak başlatılacaktır. İşaretlenmezse, uygulamayı manuel olarak başlatmanız gerekecektir.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="87"/>
        <source>Launch now</source>
        <translation>Şimdi başlat</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="108"/>
        <source>Stream settings</source>
        <translation>Yayın ayarları</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>Limit application frame rate</source>
        <translation>Uygulama kare hızını sınırlayın</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="111"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Eğer işaretlenirse, enjekte edilen kütüphane uygulamayı yavaşlatır, böylece kare hızı kayıt kare hızını aşmaz. Bu seçenek, uygulamanın kaydedilmeyecek kareler için CPU zamanını boşa harcamasını engelleyerek bazen daha akıcı video elde edilmesini sağlar (bu durum uygulamaya bağlıdır).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="120"/>
        <source>Close</source>
        <translation>Kapat</translation>
    </message>
</context>
<context>
    <name>DialogRecordSchedule</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="86"/>
        <source>Recording schedule</source>
        <translation>Kayıt programı</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="88"/>
        <source>Time zone:</source>
        <translation>Zaman dilimi:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="90"/>
        <source>Local time</source>
        <translation>Yerel zaman</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="91"/>
        <source>UTC</source>
        <translation>UTC (Koordinatlı Evrensel Zaman)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="93"/>
        <source>Current time:</source>
        <translation>Şu anki zaman:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="110"/>
        <source>Add</source>
        <translation>Ekle</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="111"/>
        <source>Remove</source>
        <translation>Kaldır</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="112"/>
        <source>Move up</source>
        <translation>Yukarı taşı</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="113"/>
        <source>Move down</source>
        <translation>Aşağı taşı</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="115"/>
        <source>Close</source>
        <translation>Kapat</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Hata: Yeniden örnekleme oranı aralık dışında!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Hata: Sürüklenme oranı aralık dışında!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Yeniden örnekleme oranı %1&apos;dir (önceki %2 idi).</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="129"/>
        <source>Warning: No fast pixel format conversion available (%1,%2 -&gt; %3,%4), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Uyarı: Hızlı piksel formatı dönüşümü mevcut değil (%1,%2 -&gt; %3,%4), bunun yerine swscale kullanılıyor. Bu bir sorun değil, ancak performans daha düşük olacaktır.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="138"/>
        <location filename="../Benchmark.cpp" line="124"/>
        <location filename="../Benchmark.cpp" line="205"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Hata: swscale bağlamı alınamıyor!</translation>
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
        <translation>Uyarı: Bellek SSE için düzgün hizalanmamış, bunun yerine fallback dönüştürücü kullanılıyor. Bu bir sorun değil, ancak performans daha düşük olacaktır.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="35"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Uyarı: Bir overrun meydana geldi, bazı örnekler kayboldu.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="37"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Hata: Overrun sonrası cihaz kurtarılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="41"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Hata: Overrun sonrası PCM cihazı başlatılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="71"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="174"/>
        <location filename="../AV/Input/JACKInput.cpp" line="59"/>
        <location filename="../AV/Input/PipeWireInput.cpp" line="71"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="66"/>
        <location filename="../AV/Input/X11Input.cpp" line="214"/>
        <source>Stopping input thread ...</source>
        <translation>Giriş iş parçacığı durduruluyor...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="102"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="237"/>
        <source>Generating source list ...</source>
        <translation>Kaynak listesi oluşturuluyor...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="121"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Hata: ALSA yapılandırması güncellenemedi!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="168"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Bulunan eklenti: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Uyarı: Ses kartı %1 açılamadı.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="187"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Uyarı: Ses kartı %1 için bilgi alınamadı.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="191"/>
        <source>Found card: [%1] %2</source>
        <translation>Bulunan kart: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="216"/>
        <source>Found device: [%1] %2</source>
        <translation>Bulunan cihaz: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="271"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Hata: PCM cihazı açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="128"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Hata: PCM donanım parametreleri alınamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="281"/>
        <location filename="../AV/SimpleSynth.cpp" line="134"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Hata: Erişim türü ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="292"/>
        <source>Error: Can&apos;t set sample format mask!</source>
        <translation>Hata: Örnek format maskesi ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="297"/>
        <location filename="../AV/SimpleSynth.cpp" line="140"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Hata: Örnek format ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="151"/>
        <source>Using sample format %1.</source>
        <translation>Örnek format kullanılıyor: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="330"/>
        <location filename="../AV/SimpleSynth.cpp" line="147"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Hata: Örnekleme oranı ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="334"/>
        <location filename="../AV/SimpleSynth.cpp" line="151"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uyarı: Örnekleme oranı %1 desteklenmiyor, bunun yerine %2 kullanılıyor. Bu bir sorun değil.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="343"/>
        <location filename="../AV/SimpleSynth.cpp" line="159"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Hata: Kanal sayısı ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="347"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uyarı: Kanal sayısı %1 desteklenmiyor, bunun yerine %2 kullanılıyor. Bu bir sorun değil.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="356"/>
        <location filename="../AV/SimpleSynth.cpp" line="166"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Hata: Periyot boyutu ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="360"/>
        <location filename="../AV/SimpleSynth.cpp" line="170"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uyarı: Periyot boyutu %1 desteklenmiyor, bunun yerine %2 kullanılıyor. Bu bir sorun değil.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="369"/>
        <location filename="../AV/SimpleSynth.cpp" line="179"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Hata: Tampon (buffer) boyutu ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="373"/>
        <location filename="../AV/SimpleSynth.cpp" line="183"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Uyarı: Tampon (buffer) boyutu %1 desteklenmiyor, bunun yerine %2 kullanılıyor. Bu bir sorun değil.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="381"/>
        <location filename="../AV/SimpleSynth.cpp" line="191"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Hata: PCM donanım parametreleri uygulanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="407"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Hata: PCM cihazı başlatılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="428"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="290"/>
        <location filename="../AV/Input/JACKInput.cpp" line="251"/>
        <location filename="../AV/Input/PipeWireInput.cpp" line="199"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="335"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="263"/>
        <location filename="../AV/Input/X11Input.cpp" line="465"/>
        <source>Input thread started.</source>
        <translation>Giriş iş parçacığı başlatıldı.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="452"/>
        <source>Error: Can&apos;t wait for new samples!</source>
        <translation>Hata: Yeni örnekler için beklenemiyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="469"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Hata: Örnekler okunamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="500"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="360"/>
        <location filename="../AV/Input/JACKInput.cpp" line="302"/>
        <location filename="../AV/Input/PipeWireInput.cpp" line="213"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="428"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="296"/>
        <location filename="../AV/Input/X11Input.cpp" line="585"/>
        <source>Input thread stopped.</source>
        <translation>Giriş iş parçacığı durduruldu.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="504"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="364"/>
        <location filename="../AV/Input/JACKInput.cpp" line="306"/>
        <location filename="../AV/Input/PipeWireInput.cpp" line="217"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="432"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="300"/>
        <location filename="../AV/Input/X11Input.cpp" line="589"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>&apos;%1&apos; giriş iş parçacığında istisna oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="507"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="367"/>
        <location filename="../AV/Input/JACKInput.cpp" line="309"/>
        <location filename="../AV/Input/PipeWireInput.cpp" line="220"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="435"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="303"/>
        <location filename="../AV/Input/X11Input.cpp" line="592"/>
        <source>Unknown exception in input thread.</source>
        <translation>Giriş iş parçacığında bilinmeyen istisna oluştu</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="259"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Hata: Akış okunamadı, bu genellikle akışın zaten sonlandığı anlamına gelir.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="75"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Hata: JACK&apos;e bağlanılamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="84"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Hata: JACK portu oluşturulamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="100"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Hata: JACK işlem geri çağrısı ayarlanamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Hata: JACK örnekleme oranı geri çağrısı ayarlanamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="108"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Hata: JACK xrun geri çağrısı ayarlanamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Hata: JACK port bağlantı geri çağrısı ayarlanamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="117"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Hata: JACK istemcisi etkinleştirilemedi!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="125"/>
        <location filename="../AV/Input/JACKInput.cpp" line="136"/>
        <location filename="../AV/Input/JACKInput.cpp" line="265"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Port %1, %2&apos;ye bağlanıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="269"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>Port %1, %2&apos;den ayrılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="46"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="41"/>
        <location filename="../AV/Input/X11Input.cpp" line="193"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="119"/>
        <source>Error: Width or height is zero!</source>
        <translation>Hata: Genişlik veya yükseklik sıfır!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="50"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="45"/>
        <location filename="../AV/Input/X11Input.cpp" line="197"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="123"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Hata: Genişlik veya yükseklik çok büyük, maksimum genişlik ve yükseklik %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="54"/>
        <location filename="../AV/Input/V4L2Input.cpp" line="49"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="127"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Hata: Genişlik veya yükseklik çift sayı değil!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="105"/>
        <source>Error: Failed to create main loop!</source>
        <translation>Hata: Ana döngü oluşturulamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="125"/>
        <source>Error: Failed to create stream!</source>
        <translation>Hata: Akış oluşturulamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="168"/>
        <source>Error: Failed to connect stream!</source>
        <translation>Hata: Akış bağlanamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="206"/>
        <source>Error in main loop: %1</source>
        <translation>Hata: Ana döngüde hata: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="230"/>
        <source>Warning: Failed to dequeue buffer!</source>
        <translation>Uyarı: Tampon kuyruktan çıkarılamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="242"/>
        <location filename="../AV/Input/PipeWireInput.cpp" line="297"/>
        <source>Error: Unknown pixel format!</source>
        <translation>Hata: Bilinmeyen piksel formatı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="269"/>
        <source>Error: Failed to parse format!</source>
        <translation>Hata: Biçim çözümlenemedi!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="274"/>
        <source>Error: Invalid media type!</source>
        <translation>Hata: Geçersiz medya türü!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="279"/>
        <source>Error: Failed to parse video format!</source>
        <translation>Hata: Video formatı çözümlenemedi!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PipeWireInput.cpp" line="300"/>
        <source>Video format: %1x%2 %3</source>
        <translation>Video formatı: %1x%2 %3</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="34"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Hata: pa_mainloop_prepare başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="38"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Hata: pa_mainloop_poll başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="42"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Hata: pa_mainloop_dispatch başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="52"/>
        <source>Error: Could not create main loop!</source>
        <translation>Hata: Ana döngü oluşturulamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="59"/>
        <source>Error: Could not create context!</source>
        <translation>Hata: Bağlam oluşturulamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Hata: Bağlanılamadı! Sebep: %1 Sisteminizin PulseAudio kullanmıyor olması olası. Bunun yerine ALSA kullanmayı deneyin.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="68"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio.</source>
        <translation>Hata: Bağlanılamadı! Sebep: %1 Sisteminizin PulseAudio kullanmaması olabilir.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="82"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Hata: Bağlantı denemesi başarısız oldu! Sebep: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="119"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Hata: Akış oluşturulamadı! Sebep: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="126"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Hata: Akış bağlanamadı! Sebep: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="137"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Hata: Akış bağlantı denemesi başarısız oldu! Sebep: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="228"/>
        <source>Found source: [%1] %2</source>
        <translation>Kaynak bulundu: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="249"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Hata: Kaynakların adları alınamadı! Sebep: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="297"/>
        <source>Error: Could not get source info! Reason: %1</source>
        <translation>Hata: Kaynak bilgileri alınamadı! Sebep: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="302"/>
        <source>Stream is a monitor.</source>
        <translation>Akış bir monitördür.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="304"/>
        <source>Stream is not a monitor.</source>
        <translation>Akış bir monitör değildir.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="349"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Hata: pa_stream_peek başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="416"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Uyarı: Ses kaynağı askıya alındı. Mevcut segment, kaynak devam ettirilene kadar durdurulacaktır.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="421"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Uyarı: Akış farklı bir kaynağa taşındı.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation>Video akış okuyucusu oluşturuldu.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Hata: Video akış dosyası açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation>Hata: Video akış dosyası yeniden boyutlandırılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Hata: Video akış dosyası bellek haritalanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Hata: Video kare dosyası açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation>Video akış okuyucusu yok edildi.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Hata: Video kare dosyasının boyutu yanlış!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Hata: Video kare dosyası bellek haritalanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="94"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation>Hata: Kanal dizini oluşturulamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="102"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation>Hata: Kanal dizininin durumu alınamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="106"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Hata: Kanal dizini normal bir dizin değil!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="111"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation>Hata: Kanal dizini modu ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="116"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Hata: Kanal dizini farklı bir kullanıcıya ait! Farklı bir kanal adı seçin veya yine de kullanmak için esnek dosya izinlerini etkinleştirin.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="126"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Hata: inotify başlatılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation>Hata: Kanal dizini izlenemiyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation>Hata: Kanal dizini açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Var olan akış %1 eklendi.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Hata: inotify&apos;dan okuma uzunluğu alınamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Hata: inotify&apos;den okuma yapılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Hata: inotify&apos;den kısmi olay alındı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Hata: inotify&apos;den kısmi ad alındı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation>Akış %1 eklendi.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation>Akış %1 kaldırıldı.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Terk edilmiş akış %1 silindi.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="99"/>
        <source>Error: Can&apos;t open V4L2 device!</source>
        <translation>Hata: V4L2 cihazı açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="107"/>
        <source>Error: Can&apos;t read capabilities of V4L2 device!</source>
        <translation>Hata: V4L2 cihazının yetenekleri okunamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="111"/>
        <source>Error: V4L2 device does not support video capture!</source>
        <translation>Hata: V4L2 cihazı video yakalamayı desteklemiyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="115"/>
        <source>Error: V4L2 device does not support streaming io!</source>
        <translation>Hata: V4L2 cihazı akış IO&apos;yu desteklemiyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="132"/>
        <source>Error: Can&apos;t set capture format!</source>
        <translation>Hata: Yakalama formatı ayarlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="136"/>
        <source>Error: V4L2 device does not support YUYV pixel format!</source>
        <translation>Hata: V4L2 cihazı YUYV piksel formatını desteklemiyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="140"/>
        <source>Warning: Resolution %1x%2 is not supported, using %3x%4 instead. The video will be scaled.</source>
        <translation>Uyarı: Çözünürlük %1x%2 desteklenmiyor, yerine %3x%4 kullanılıyor. Video ölçeklendirilecektir.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="183"/>
        <source>Using color space %1.</source>
        <translation>Renk alanı %1 kullanılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="193"/>
        <source>Error: Buffer request failed!</source>
        <translation>Hata: Tampon bellek isteği başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="203"/>
        <source>Error: Buffer query failed!</source>
        <translation>Hata: Tampon bellek sorgusu başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="209"/>
        <source>Error: Buffer mmap failed!</source>
        <translation>Hata: Tampon bellek mmap başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="222"/>
        <source>Error: Buffer queue failed!</source>
        <translation>Hata: Tampon bellek kuyruğu başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="230"/>
        <source>Error: Failed to start stream!</source>
        <translation>Hata: Akış başlatılamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="273"/>
        <source>Error: Buffer dequeue failed!</source>
        <translation>Hata: Tampon bellek kuyruktan çıkarılamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/V4L2Input.cpp" line="290"/>
        <source>Error: Buffer requeue failed!</source>
        <translation>Hata: Tampon bellek yeniden kuyruğa alınamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="68"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Hata: Desteklenmeyen X11 görüntü piksel formatı!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="257"/>
        <location filename="../GUI/HotkeyListener.cpp" line="115"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Hata: X display açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="266"/>
        <source>Using X11 shared memory.</source>
        <translation>X11 paylaşımlı belleği kullanılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="268"/>
        <source>Not using X11 shared memory.</source>
        <translation>X11 paylaşımlı belleği kullanılmıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="275"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Uyarı: XFixes X sunucusu tarafından desteklenmiyor, imleç gizlendi.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="313"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Hata: Paylaşılan görüntü oluşturulamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="318"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Hata: Paylaşılan bellek alınamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="323"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Hata: Paylaşılan belleğe bağlanılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="328"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Hata: Sunucu paylaşılan belleğe bağlanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="355"/>
        <source>Detecting screen configuration ...</source>
        <translation>Ekran yapılandırması algılanıyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="373"/>
        <source>Warning: Xinerama is not supported by X server, multi-monitor support may not work properly.</source>
        <comment>Don&apos;t translate &apos;Xinerama&apos;</comment>
        <translation>Uyarı: Xinerama X sunucusu tarafından desteklenmiyor, çoklu monitör desteği düzgün çalışmayabilir.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation>Uyarı: Monitör algılanmadı, çoklu monitör desteği düzgün çalışmayabilir.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="386"/>
        <source>Screen %1:</source>
        <translation>Ekran %1:</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="406"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Hata: Geçersiz ekran sınır kutusu!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="450"/>
        <source>Dead space %1:</source>
        <translation>Boş alan %1:</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="536"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Hata: Görüntü alınamıyor (paylaşılan bellek kullanılıyor)! Genellikle bu, kayıt alanının tamamen ekranın içinde olmadığı anlamına gelir. Yoksa ekran çözünürlüğünü mü değiştirdiniz?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="547"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Hata: Görüntü alınamıyor (paylaşılan bellek kullanılmıyor)! Genellikle bu, kayıt alanının tamamen ekranın içinde olmadığı anlamına gelir. Yoksa ekran çözünürlüğünü mü değiştirdiniz?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="105"/>
        <source>Error: Channel count is zero.</source>
        <translation>Hata: Kanal sayısı sıfır.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="109"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Hata: Örnekleme oranı sıfır.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="156"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Hata: Kodlayıcı, desteklenmeyen bir örnek biçimi gerektiriyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="189"/>
        <source>Error: Sending of audio frame failed!</source>
        <translation>Hata: Ses çerçevesi gönderilemedi!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="210"/>
        <source>Error: Receiving of audio packet failed!</source>
        <translation>Hata: Ses paketi alımı başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="223"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="245"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Hata: Ses çerçevesinin kodlanması başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="30"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="39"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Hata: Seçenek &apos;%1&apos; ayrıştırılamadı!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation>Kodlayıcı iş parçacığı durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="164"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Hata: Codec açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="172"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation>Uyarı: Codec seçeneği &apos;%1&apos; tanınmadı!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="190"/>
        <source>Encoder thread started.</source>
        <translation>Kodlayıcı iş parçacığı başlatıldı.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="219"/>
        <source>Flushing encoder ...</source>
        <translation>Kodlayıcı temizleniyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="230"/>
        <source>Encoder thread stopped.</source>
        <translation>Kodlayıcı iş parçacığı durduruldu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="234"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Kodlayıcı iş parçacığında istisna &apos;%1&apos; oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="237"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Kodlayıcı iş parçacığında bilinmeyen bir istisna oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="70"/>
        <source>Stopping encoders ...</source>
        <translation>Kodlayıcılar durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="77"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Kodlayıcı iş parçacığının durmasını bekliyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <location filename="../AV/Output/Muxer.cpp" line="124"/>
        <source>Error: Can&apos;t copy parameters to stream!</source>
        <translation>Hata: Parametreler akışa kopyalanamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="146"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Hata: Header yazılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="157"/>
        <source>Finishing encoders ...</source>
        <translation>Kodlayıcılar tamamlanıyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="200"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Hata: Seçilen çıktı biçimi bulunamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="204"/>
        <source>Using format %1 (%2).</source>
        <translation>Format &apos;%1&apos; (%2) kullanılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="210"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Hata: Biçim bağlamı ayrıştırılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="217"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Hata: Çıktı dosyası açılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="230"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Hata: &quot;Trailer&quot; yazılamıyor, yine de devam ediliyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="269"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Hata: Codec bulunamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="279"/>
        <source>Using codec %1 (%2).</source>
        <translation>Codec &apos;%1&apos; (%2) kullanılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="290"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Hata: Yeni akış oluşturulamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="297"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation>Hata: Yeni codec bağlamı oluşturulamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="309"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Hata: Codec bağlamı varsayılanları alınamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="322"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Uyarı: Bu codec, libav/ffmpeg tarafından deneysel olarak değerlendiriliyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="338"/>
        <source>Muxer thread started.</source>
        <translation>Muxer iş parçacığı başlatıldı.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="398"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Hata: Çerçeve muxer&apos;a yazılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="426"/>
        <source>Muxer thread stopped.</source>
        <translation>Muxer iş parçacığı durduruldu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="430"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Muxer iş parçacığında istisna &apos;%1&apos; oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="433"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Muxer iş parçacığında bilinmeyen istisna oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="70"/>
        <source>Stopping fragment thread ...</source>
        <translation>Parça dizisi durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="347"/>
        <source>Fragment thread started.</source>
        <translation>Parça dizisi başlatıldı.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="365"/>
        <source>Next fragment ...</source>
        <translation>Sonraki parça ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="369"/>
        <source>Finishing ...</source>
        <translation>Bitiriliyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="381"/>
        <source>Fragment thread stopped.</source>
        <translation>Parça dizisi durduruldu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="385"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation>Parça dizisinde istisna &apos;%1&apos; oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="388"/>
        <source>Unknown exception in fragment thread.</source>
        <translation>Parça dizisinde bilinmeyen istisna oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="225"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Eşzamanlayıcı dizisi durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="333"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Uyarı: Monotonik olmayan zaman damgasına sahip bir video karesi alındı.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="360"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Uyarı: Video tamponu taşması, bazı kareler kaybolacak. Ses girişi çok yavaş görünüyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="417"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Uyarı: Monotonik olmayan zaman damgasına sahip ses örnekleri alındı.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="442"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Uyarı: Çok fazla ses örneği, sesin video ile senkronize kalması için örnekler atlanacak.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="448"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Uyarı: Yeterli sayıda ses örneği yok, sesin video ile senkronize kalması için sessizlik ekleniyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="516"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Uyarı: Ses girişi %2&apos;den fazla çok yavaş!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="520"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Uyarı: Ses girişi %2&apos;den fazla çok hızlı!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="559"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Uyarı: Ses tamponu taşması, sesi video ile senkronize tutmak için yeni bir segment başlatılıyor (bazı video ve/veya ses kaybolabilir). Video girişi çok yavaş görünüyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="595"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Uyarı: Ses akışında boşluk alındı, sesi video ile senkronize tutmak için sessizlik ekleniyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="896"/>
        <source>Synchronizer thread started.</source>
        <translation>Eşzamanlayıcı dizisi başlatıldı.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="918"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Eşzamanlayıcı dizisi durduruldu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="922"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Eşzamanlayıcı dizisinde istisna &apos;%1&apos; oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="925"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Eşzamanlayıcı dizisinde bilinmeyen bir istisna oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="131"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Hata: Kare hızı sıfır!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="188"/>
        <source>Using pixel format %1.</source>
        <translation>Piksel formatı %1 kullanılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="202"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Hata: Piksel formatı codec tarafından desteklenmiyor!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="230"/>
        <source>Error: Sending of video frame failed!</source>
        <translation>Hata: Video karesi gönderimi başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="251"/>
        <source>Error: Receiving of video packet failed!</source>
        <translation>Hata: Video paketi alımı başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="264"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="285"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Hata: Video karesi kodlama başarısız oldu!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="41"/>
        <source>Using real-time priority.</source>
        <translation>Gerçek zamanlı öncelik kullanılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="51"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation>Nice önceliği kullanılıyor.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation>Uyarı: Dizi önceliği artırılamıyor.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="64"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Hata: Underrun sonrası cihaz kurtarılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="91"/>
        <source>Stopping synth thread ...</source>
        <translation>Synth dizisi durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="224"/>
        <source>Synth thread started.</source>
        <translation>Synth dizisi başlatıldı.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="277"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Hata: Örnekler yazılamıyor!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="285"/>
        <source>Synth thread stopped.</source>
        <translation>Synth dizisi durduruldu.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="289"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Synth dizisinde istisna &apos;%1&apos; oluştu.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="292"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Synth dizisinde bilinmeyen bir istisna oluştu.</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="165"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation>BGRA %1&apos;den BGRA %2&apos;ye | SWScale %3 mikrosaniye | Yedekleme %4 mikrosaniye (%5%) | SSSE3 %6 mikrosaniye (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="243"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation>%1 %2&apos;den %3 %4&apos;e | SWScale %5 mikrosaniye | Yedekleme %6 mikrosaniye (%7%) | SSSE3 %8 mikrosaniye (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="253"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Ölçekleyici kıyaslaması(benchmark) başlatılıyor ...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="260"/>
        <source>Starting converter benchmark ...</source>
        <translation>Dönüştürücü kıyaslaması (benchmark) başlatılıyor ...</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="90"/>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation>Hata: Komut satırı seçeneği &apos;%1&apos; bir değer gerektiriyor!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="98"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Hata: Komut satırı seçeneği &apos;%1&apos; bir değer almıyor!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="195"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Hata: Bilinmeyen komut satırı seçeneği &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="203"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Hata: Bilinmeyen komut satırı argümanı &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../common/CommandLineOptions.cpp" line="253"/>
        <source>Error: Can&apos;t create configuration directory!</source>
        <translation>Hata: Yapılandırma dizini oluşturulamıyor!</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="45"/>
        <source>CPU features</source>
        <translation>CPU özellikleri</translation>
    </message>
    <message>
        <location filename="../common/ScreenScaling.cpp" line="122"/>
        <source>Detected fractional screen scale factor, scaling was disabled.</source>
        <translation>Kesirli (fractional) ekran ölçekleme faktörü algılandı, ölçekleme devre dışı bırakıldı.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="160"/>
        <source>The application could not be launched.</source>
        <translation>Uygulama başlatılamadı.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="161"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation>Uyarı: XInput2 X sunucusu tarafından desteklenmiyor, kısayol tuşları bazı uygulamalarda çalışmayabilir.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="105"/>
        <source>SSR started</source>
        <translation>SSR başlatıldı.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="139"/>
        <source>SSR stopped</source>
        <translation>SSR durduruldu.</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>You are using a non-X11 window system (e.g. Wayland) which is only partially supported by SimpleScreenRecorder. Several features will most likely not work properly, consider choosing a X11/Xorg session at the login screen if you experience issues. SimpleScreenRecorder is able to record Wayland sessions using the PipeWire backend, provided that your Wayland compositor supports it.</source>
        <translation>X11 olmayan bir pencere sistemi (örn. Wayland) kullanıyorsunuz ve bu, SimpleScreenRecorder tarafından kısmen destekleniyor. Birçok özellik muhtemelen düzgün çalışmayacaktır, sorun yaşarsanız oturum açma ekranında X11/Xorg oturumunu seçmeyi düşünün. SimpleScreenRecorder, Wayland oturumlarını PipeWire arka ucu kullanarak kaydedebilir, ancak Wayland bileşiminizin bunu desteklemesi gerekmektedir.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="86"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder, tescilli NVIDIA sürücüsünü flipping etkinleştirilmiş olarak kullandığınızı algıladı. Bu, kayıt sırasında aksaklıklara neden olduğu bilinen bir durumdur. Flipping&apos;i devre dışı bırakmanız önerilir. Bunu sizin için yapmamı ister misiniz?

Bu seçeneği ayrıca NVIDIA kontrol panelinde manuel olarak da değiştirebilirsiniz.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="104"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Bir nedenle flipping&apos;i devre dışı bırakamadım - üzgünüm! NVIDIA kontrol panelinde bunu devre dışı bırakmayı deneyin.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="31"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Kayıt kaydedildi. Şimdi videoyu düzenleyebilir veya dosyayı daha küçük hale getirmek için daha iyi ayarlarla yeniden kodlayabilirsiniz (varsayılan ayarlar kalite ve hız için optimize edilmiştir, dosya boyutu için değil).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="35"/>
        <source>Open folder</source>
        <translation>Klasörü aç</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="38"/>
        <source>Back to the start screen</source>
        <translation>Başlangıç ekranına dön</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="291"/>
        <source>Input profile</source>
        <translation>Giriş profili</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="293"/>
        <source>Video input</source>
        <translation>Video girişi</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="295"/>
        <location filename="../GUI/PageInput.cpp" line="523"/>
        <source>Backend:</source>
        <translation>Arka yüz:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="307"/>
        <source>The video backend that will be used for recording.</source>
        <translation>Kayıt için kullanılacak video arka yüzü.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="309"/>
        <source>Record the entire screen</source>
        <translation>Tüm ekranı kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="310"/>
        <source>Record a fixed rectangle</source>
        <translation>Sabit bir dikdörtgen alanı kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="311"/>
        <source>Follow the cursor</source>
        <translation>İmleci takip et</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="316"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Çoklu monitör yapılandırmasında hangi monitörün kaydedileceğini seçin.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="317"/>
        <source>Record entire screen with cursor</source>
        <translation>İmleçle birlikte tüm ekranı kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="318"/>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation>İmleç konumunu takip etmek yerine, imlecin bulunduğu ekranın tamamını kaydet.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="319"/>
        <source>Select rectangle...</source>
        <translation>Dikdörtgen seç...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="320"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Kayıt edilecek dikdörtgen alanı seçmek için fareyi kullan.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="321"/>
        <source>Select window...</source>
        <translation>Pencere seç...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="322"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Kayıt için bir pencere seçmek amacıyla fareyi kullanın. İpucu: Bir pencerenin kenarına tıklarsanız, tüm pencere (kenarlar dahil) kaydedilecektir. Aksi takdirde yalnızca pencerenin istemci alanı kaydedilecektir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="325"/>
        <source>Left:</source>
        <translation>Sol:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="329"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Kaydedilen dikdörtgen alanın sol üst köşesinin x koordinatı. İpucu: Bu değeri kaydırma tekerleği veya yukarı/aşağı okları ile de değiştirebilirsiniz</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="331"/>
        <source>Top:</source>
        <translation>Üst:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="335"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Kaydedilen dikdörtgen alanın sol üst köşesinin y koordinatı. İpucu: Bu değeri kaydırma tekerleği veya yukarı/aşağı okları ile de değiştirebilirsiniz.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="337"/>
        <location filename="../GUI/PageInput.cpp" line="357"/>
        <location filename="../GUI/PageInput.cpp" line="372"/>
        <source>Width:</source>
        <translation>Genişlik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="341"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Kaydedilen dikdörtgen alanın genişliği. İpucu: Bu değeri kaydırma tekerleği veya yukarı/aşağı okları ile de değiştirebilirsiniz.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="343"/>
        <location filename="../GUI/PageInput.cpp" line="362"/>
        <location filename="../GUI/PageInput.cpp" line="377"/>
        <source>Height:</source>
        <translation>Yükseklik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="347"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Kaydedilen dikdörtgen alanın yüksekliği. İpucu: Bu değeri kaydırma tekerleği veya yukarı/aşağı okları ile de değiştirebilirsiniz.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="350"/>
        <source>OpenGL settings...</source>
        <translation>OpenGL ayarları...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="351"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>OpenGL kaydı için ayarları değiştir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="354"/>
        <source>V4L2 device:</source>
        <translation>V4L2 cihazı:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="356"/>
        <source>The V4L2 device to record (e.g. /dev/video0).</source>
        <translation>Kayıt edilecek V4L2 cihazı (örneğin, /dev/video0).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="361"/>
        <location filename="../GUI/PageInput.cpp" line="376"/>
        <source>The width of the video.</source>
        <translation>Videonun genişliği</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="366"/>
        <location filename="../GUI/PageInput.cpp" line="381"/>
        <source>The height of the video.</source>
        <translation>Videonun yüksekliği</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="369"/>
        <location filename="../GUI/PageInput.cpp" line="541"/>
        <location filename="../GUI/PageInput.cpp" line="550"/>
        <source>Source:</source>
        <translation>Kaynak:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="371"/>
        <source>The PipeWire source to record.</source>
        <translation>Kayıt edilecek PipeWire kaynağı</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="383"/>
        <source>Frame rate:</source>
        <translation>Kare hızı:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="387"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Son videodaki saniye başına kare sayısı. Daha yüksek kare hızları daha fazla CPU zamanı kullanır.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="388"/>
        <source>Scale video</source>
        <translation>Videoyu ölçekle</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="389"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Ölçeklemeyi etkinleştir veya devre dışı bırak. Ölçekleme daha fazla CPU zamanı kullanır, ancak ölçeklenmiş video daha küçükse, kodlamayı hızlandırabilir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="390"/>
        <source>Scaled width:</source>
        <translation>Ölçeklenmiş genişlik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="394"/>
        <source>Scaled height:</source>
        <translation>Ölçeklenmiş yükseklik:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="398"/>
        <source>Record cursor</source>
        <translation>İmleci kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="520"/>
        <source>Audio input</source>
        <translation>Ses girişi</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="522"/>
        <source>Record audio</source>
        <translation>Sesi kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="535"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Kayıt için kullanılacak ses altyapısı. ALSA altyapısı PulseAudio kullanan sistemlerde de çalışacaktır, ancak PulseAudio altyapısını doğrudan kullanmak daha iyidir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="538"/>
        <source>The audio backend that will be used for recording.</source>
        <translation>Kayıt için kullanılacak ses altyapısı.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="544"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Kayıt için kullanılacak ALSA kaynağı. Varsayılan genellikle iyidir. &apos;Paylaşılan&apos; kaynaklar, aynı anda birden fazla programın kayıt yapmasına izin verir, ancak daha az güvenilir olabilirler.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="546"/>
        <location filename="../GUI/PageInput.cpp" line="555"/>
        <source>Refresh</source>
        <translation>Yenile</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="547"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>ALSA kaynaklarının listesini yeniler.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="553"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Kayıt için kullanılacak PulseAudio kaynağı. Bir &apos;monitor&apos;, diğer uygulamalar tarafından çalınan sesi kaydeden bir kaynaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="556"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>PulseAudio kaynaklarının listesini yeniler.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="559"/>
        <source>Record system microphone</source>
        <translation>Sistem mikrofonunu kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="560"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Seçildiğinde, portlar otomatik olarak sistem yakalama portlarına bağlanacaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="561"/>
        <source>Record system speakers</source>
        <translation>Sistem hoparlörlerini kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="562"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Seçildiğinde, portlar otomatik olarak sistem oynatma portlarına bağlanan her şeye bağlanacaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="609"/>
        <source>Back</source>
        <translation>Geri</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="610"/>
        <source>Continue</source>
        <translation>Devam et</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1064"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Tüm ekranlar: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1068"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Ekran %1: %2x%3 %4,%5 konumunda</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="1287"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Ekran %1</translation>
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
        <translation>%1 dosyalar</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation>Diğer...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation>Sıkıştırılmamış</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="173"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Hata: Uygun bir kapsayıcı bulamayan libavformat kütüphanesinde hata!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Hata: libavcodec içinde uygun bir video codec bileşeni bulunamadı!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Hata: libavcodec içinde uygun bir ses codec bileşeni bulunamadı!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Output profile</source>
        <translation>Çıkış profili</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="191"/>
        <source>File</source>
        <translation>Dosya</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="193"/>
        <source>Save as:</source>
        <translation>Farklı kaydet:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="195"/>
        <source>The recording will be saved to this location.</source>
        <translation>Kayıt bu konuma kaydedilecektir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="196"/>
        <source>Browse...</source>
        <translation>Gözat...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>Separate file per segment</source>
        <translation>Her segment için ayrı dosya</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="198"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation>Seçildiğinde, kaydı duraklatıp yeniden başlattığınızda her seferinde ayrı bir video dosyası oluşturulacaktır. Seçilmediğinde, kaydedilen tüm segmentler tek bir video dosyasında birleştirilecektir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="200"/>
        <source>Add timestamp</source>
        <translation>Zaman damgası ekle</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Seçildiğinde, geçerli tarih ve saat dosya adına otomatik olarak eklenir. Orijinal dosya adı &apos;test.mkv&apos; ise, video &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos; olarak kaydedilecektir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="203"/>
        <source>Container:</source>
        <translation>Kapsayıcı (Container):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="208"/>
        <source>(not installed)</source>
        <translation>(yüklenmedi)</translation>
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
        <translation>Kapsayıcı (dosya formatı), kaydın kaydedileceği formatı belirler. 
Not: Tüm codec bileşenleri tüm kapsayıcılar (containerlar) tarafından desteklenmez ve tüm medya oynatıcıları tüm dosya formatlarını okuyamaz.
- Matroska (MKV) tüm codec bileşenlerini destekler, ancak daha az bilinir.
- MP4 en bilinen formattır ve neredeyse tüm modern medya oynatıcılarında oynatılabilir, ancak yalnızca H.264 video 
   (ve birçok medya oynatıcı sadece AAC ses desteğine sahiptir).
- WebM, videoları web sitelerine gömmek için (HTML5 &lt;video&gt; etiketiyle) tasarlanmıştır. Format Google tarafından oluşturulmuştur. 
   WebM, varsayılan olarak Firefox, Chrome ve Opera tarafından desteklenir ve Internet Explorer ve Safari için eklentiler mevcuttur. 
   Yalnızca VP8 ve Vorbis&apos;i destekler.
- OGG yalnızca Theora ve Vorbis&apos;i destekler.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="220"/>
        <source>Container name:</source>
        <translation>Kapsayıcı (container) adı:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Gelişmiş kullanıcılar için. Herhangi bir libav/ffmpeg formatını kullanabilirsiniz, ancak bunların birçoğu kullanışlı değildir veya çalışmayabilir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="227"/>
        <source>Warning: This format will produce unreadable files if the recording is interrupted! Consider using MKV instead.</source>
        <translation>Uyarı: Bu format, kayıt kesintiye uğrarsa okunamayan dosyalar oluşturacaktır! Bunun yerine MKV kullanmayı düşünün.</translation>
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
        <translation>Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="257"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Videonun sıkıştırılmasında kullanılacak codec bileşeni.
- H.264 (libx264) açık ara en iyi codec - yüksek kalite ve çok hızlı.
- VP8 (libvpx) oldukça iyi, ancak oldukça yavaş.
- Theora (libtheora) pek tavsiye edilmez çünkü kalitesi pek iyi değildir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Codec name:</source>
        <translation>Codec adı:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="267"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Gelişmiş kullanıcılar için. Herhangi bir libav/ffmpeg video codec bileşenini kullanabilirsiniz, ancak bunların birçoğu kullanışlı değildir veya çalışmayabilir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="268"/>
        <location filename="../GUI/PageOutput.cpp" line="352"/>
        <source>Bit rate (in kbit/s):</source>
        <translation>Bit hızı (kbit/s cinsinden):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Video bit hızı (kilobit/saniye cinsinden). Daha yüksek bir değer daha yüksek kalite anlamına gelir. Nereden başlayacağınız hakkında hiçbir fikriniz yoksa, 5000 ile başlayın ve gerekirse değiştirin.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="272"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Sabit hız faktörü:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Bu ayar, video kalitesini değiştirir. Daha düşük bir değer, daha yüksek kalite anlamına gelir. 
İzin verilen aralık 0-51&apos;dir (0 kayıpsız demektir, varsayılan değer 23&apos;tür).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="283"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Ön ayar:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="288"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Kodlama hızı. Daha yüksek bir hız, daha az CPU kullanır (daha yüksek kayıt kare hızlarını mümkün kılar), ancak daha büyük dosyalar oluşturur. Kalite çok fazla etkilenmemelidir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="290"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Kullanılan CPU:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="292"/>
        <source>fastest</source>
        <translation>en hızlı</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="297"/>
        <source>slowest</source>
        <translation>en yavaş</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="298"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Kodlama hızı. Daha yüksek bir değer, daha az CPU süresi kullanır. (İsmi ben seçmedim, bu isim VP8 kodlayıcısı tarafından kullanılıyor). Daha yüksek değerler, bit hızını da artırmadığınız sürece daha düşük kaliteli video sonuçları verir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <location filename="../GUI/PageOutput.cpp" line="355"/>
        <source>Custom options:</source>
        <translation>Özel seçenekler:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="302"/>
        <location filename="../GUI/PageOutput.cpp" line="357"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Virgülle ayrılmış şekilde özel codec seçenekleri  (ör. option1=value1,option2=value2,option3=value3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Allow frame skipping</source>
        <translation>Kare atlamaya izin ver</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="304"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>İşaretlendiğinde, video kodlayıcı, giriş kare hızı çıkış kare hızından düşük olduğunda kare
 atlamaya izin verir. İşaretlenmediğinde, giriş kareleri boşlukları doldurmak için çoğaltılır. 
Bu, dosya boyutunu ve CPU kullanımını artırır, ancak bazı durumlarda canlı yayınlar için gecikmeyi azaltır. 
Video görüntüsünü etkilememelidir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Audio</source>
        <translation>Ses</translation>
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
        <translation>Ses akışını sıkıştırmak için kullanılacak codec. Bunun için çok fazla endişelenmenize gerek yok, 
çünkü ses verisinin boyutu genellikle video verisinin boyutuna kıyasla ihmal edilebilir düzeydedir.
Ve eğer yalnızca kendi sesinizi kaydediyorsanız (yani müzik yoksa), kalite pek de önemli olmayacaktır.
- Vorbis (libvorbis) harikadır, bu önerilen codec&apos;tir.
- MP3 (libmp3lame) gayet iyidir.
- AAC iyi bir codec&apos;tir, ancak burada kullanılan uygulamalar (libvo_aacenc veya deneysel ffmpeg aac kodlayıcı) oldukça 
   kötüdür. Başka seçeneğiniz yoksa kullanın.
- Sıkıştırılmamış, ses verisini sıkıştırmadan saklar. Dosya oldukça büyük olacaktır, ancak çok hızlıdır.
</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="351"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>İleri düzey kullanıcılar için. Herhangi bir libav/ffmpeg ses codec&apos;ini kullanabilirsiniz, ancak bunların birçoğu faydalı değildir veya çalışmayabilir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="354"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Ses bit hızı (kilobit/saniye cinsinden). Daha yüksek bir değer, daha yüksek kalite anlamına gelir. Tipik değer 128&apos;dir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="379"/>
        <source>Back</source>
        <translation>Geri</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="380"/>
        <source>Continue</source>
        <translation>Devam et</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="528"/>
        <source>You did not select an output file!</source>
        <translation>Seçili bir çıktı dosyanız yok!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="646"/>
        <location filename="../GUI/PageOutput.cpp" line="654"/>
        <source>not installed</source>
        <translation>kurulu değil!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="648"/>
        <location filename="../GUI/PageOutput.cpp" line="656"/>
        <source>not supported by container</source>
        <translation>kapsayıcı (container) tarafından desteklenmiyor</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="699"/>
        <source>Save recording as</source>
        <translation>Kaydı farklı kaydet</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="179"/>
        <source>Recording</source>
        <translation>Kayıt</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="185"/>
        <source>Edit schedule</source>
        <translation>Zamanlamayı düzenle</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="186"/>
        <source>The recording schedule can be used to automatically start or pause the recording at a predefined time.</source>
        <translation>Kayıt zamanlaması, kaydı önceden tanımlanmış bir zamanda otomatik olarak başlatmak veya duraklatmak için kullanılabilir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="188"/>
        <source>Enable recording hotkey</source>
        <translation>Kayıt kısayolunu etkinleştir</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="189"/>
        <source>The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,
even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the
SimpleScreenRecorder window show up in the final video.</source>
        <translation>Kayıt kısayolu, SimpleScreenRecorder penceresi görünmese bile, kaydı herhangi bir zamanda başlatmak veya 
duraklatmak için kullanılabilen evrensel bir klavye kısayoludur. Bu sayede, asıl videoda SimpleScreenRecorder 
penceresinin görünmediği kayıtlar oluşturabilirsiniz.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="193"/>
        <source>Enable sound notifications</source>
        <translation>Ses bildirimlerini etkinleştir</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="194"/>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation>Etkinleştirirseniz, kayıt başlatıldığında, duraklatıldığında ya da bir hata oluştuğunda bir ses çalınacaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="196"/>
        <source>Hotkey:</source>
        <translation>Kısayol tuşu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="197"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="198"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="199"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="200"/>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="202"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>Kaydı başlatmak veya duraklatmak için (belirtilen modifiye tuşlarıyla birlikte) basmanız gereken tuş.
Kayıt yaptığınız program bu tuşu algılamayacaktır.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="255"/>
        <source>Information</source>
        <translation>Bilgi</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="257"/>
        <source>Total time:</source>
        <translation>Toplam süre:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="259"/>
        <source>FPS in:</source>
        <translation>FPS giriş:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="261"/>
        <source>FPS out:</source>
        <translation>FPS çıkış:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="263"/>
        <source>Size in:</source>
        <translation>Boyut giriş:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="265"/>
        <source>Size out:</source>
        <translation>Boyut çıkış:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="267"/>
        <source>File name:</source>
        <translation>Dosya adı:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="270"/>
        <source>File size:</source>
        <translation>Dosya boyutu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="272"/>
        <source>Bit rate:</source>
        <translation>Bit hızı:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="274"/>
        <source>Show recording area</source>
        <translation>Kayıt alanını göster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="275"/>
        <source>When enabled, the recorded area is marked on the screen.</source>
        <translation>Etkinleştirirseniz, kaydedilen alan ekranda işaretlenir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="300"/>
        <source>Preview</source>
        <translation>Önizleme</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="304"/>
        <source>Preview frame rate:</source>
        <translation>Önizleme kare hızı:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="308"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Not: Önizleme, (özellikle yüksek kare hızlarında) ekstra CPU süresi gerektirir.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="357"/>
        <source>Log</source>
        <translation>Günlük (log)</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="372"/>
        <location filename="../GUI/PageRecord.cpp" line="380"/>
        <source>Cancel recording</source>
        <translation>Kaydı iptal et</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="373"/>
        <location filename="../GUI/PageRecord.cpp" line="382"/>
        <source>Save recording</source>
        <translation>Kaydı sakla</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="387"/>
        <source>Quit</source>
        <translation>Çık</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="438"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
What would you like to do with it?</source>
        <translation>Henüz mevcut kaydı saklamadınız, eğer şimdi çıkarsanız, kaydınız kaybolacaktır.
Ne yapmak istersiniz?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="458"/>
        <source>Hide window</source>
        <translation>Pencereyi gizle</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="460"/>
        <source>Show window</source>
        <translation>Pencereyi göster</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="687"/>
        <source>Starting page ...</source>
        <translation>Başlangıç sayfası ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="709"/>
        <location filename="../GUI/PageRecord.cpp" line="886"/>
        <location filename="../GUI/PageRecord.cpp" line="995"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Hata: Başlatma sırasında bir sorun oluştu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="718"/>
        <source>Started page.</source>
        <translation>Sayfa başlatıldı.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="751"/>
        <source>Stopping page ...</source>
        <translation>Sayfa durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="778"/>
        <source>Stopped page.</source>
        <translation>Sayfa durduruldu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="807"/>
        <source>Starting output ...</source>
        <translation>Çıktı başlatılıyor ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="821"/>
        <source>Output file: %1</source>
        <translation>Çıktı dosyası: %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="832"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Hata: OpenGL uygulamasının boyutu alınamadı çünkü GLInject girişi oluşturulmadı.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="837"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Hata: OpenGL uygulamasının boyutu alınamadı. Uygulama ya düzgün başlatılmadı, ya da uygulama henüz bir OpenGL penceresi oluşturmadı. Uygulamayı başlatmadan önce kayıt başlatmak istiyorsanız, ölçeklendirmeyi etkinleştirip video boyutunu manuel olarak girmeniz gerekiyor.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="876"/>
        <source>Started output.</source>
        <translation>Çıktı başlatıldı.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="897"/>
        <source>Stopping output ...</source>
        <translation>Çıktı durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="915"/>
        <source>Stopped output.</source>
        <translation>Çıktı durduruldu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="947"/>
        <source>Starting input ...</source>
        <translation>Giriş başlatılıyor ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="958"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Hata: GLInject girişi oluşturulmadığı için başlatılamadı.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="990"/>
        <source>Started input.</source>
        <translation>Giriş başlatıldı.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1025"/>
        <source>Stopping input ...</source>
        <translation>Giriş durduruluyor ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1046"/>
        <source>Stopped input.</source>
        <translation>Giriş durduruldu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1062"/>
        <source>Encoding remaining data ...</source>
        <translation>Kalan veriler kodlanıyor ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1160"/>
        <location filename="../GUI/PageRecord.cpp" line="1170"/>
        <source>Pause recording</source>
        <translation>Kaydı duraklat</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1163"/>
        <location filename="../GUI/PageRecord.cpp" line="1173"/>
        <source>Start recording</source>
        <translation>Kaydı başlat</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1181"/>
        <source>Deactivate schedule</source>
        <translation>Zamanlayıcıyı devre dışı bırak</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1191"/>
        <source>Activate schedule</source>
        <translation>Zamanlayıcıyı etkinleştir</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1200"/>
        <source>Stop preview</source>
        <translation>Önizlemeyi durdur</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1203"/>
        <source>Start preview</source>
        <translation>Önizlemeyi başlat</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1244"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Hata: Synth oluşturulurken bir şeyler ters gitti.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1308"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Bu kaydı iptal etmek istediğinizden emin misiniz?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1325"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.</source>
        <translation>Herhangi bir şey kayıt etmediniz, kaydedilecek bir şey yok.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1342"/>
        <source>Triggering scheduled action &apos;%1&apos; ...</source>
        <translation>Zamanlanmış eylem &apos;%1&apos; tetikleniyor ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1353"/>
        <source>Schedule: %1 in %2</source>
        <translation>Zamanlama: %2 içinde %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1360"/>
        <source>Schedule: (none)</source>
        <translation>Zamanlama: (yok)</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1364"/>
        <source>Schedule: (inactive)</source>
        <translation>Zamanlama: (etkin değil)</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1428"/>
        <location filename="../GUI/PageRecord.cpp" line="1445"/>
        <source>Standard input read error (%1).</source>
        <translation>Standart giriş okuma hatası (%1).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1433"/>
        <location filename="../GUI/PageRecord.cpp" line="1450"/>
        <source>Standard input closed (%1).</source>
        <translation>Standart giriş kapandı (%1).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1463"/>
        <source>Received command &apos;%1&apos;.</source>
        <translation>Komut alındı: &apos;%1&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1483"/>
        <source>Unknown command.</source>
        <translation>Bilinmeyen komut.</translation>
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
        <translation>&lt;p&gt;SimpleScreenRecorder&apos;a hoş geldiniz!&lt;/p&gt;

&lt;p&gt;Adına rağmen, bu program aslında pek çok seçeneğe sahiptir. Ancak endişelenmeyin, bilmeniz gereken sadece iki şey var. Birincisi, varsayılan ayarlar genellikle uygundur. Bir şeyin ne işe yaradığını bilmiyorsanız, varsayılanı kullanın. İkincisi, neredeyse tüm ayarlarda bilgi ipuçları bulunmaktadır. Ne işe yaradığını öğrenmek için farenizi üzerine getirin.&lt;/p&gt;

&lt;p&gt;Daha fazla bilgi için:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="51"/>
        <source>About SimpleScreenRecorder</source>
        <translation>SimpleScreenRecorder Hakkında</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="52"/>
        <source>Skip this page next time</source>
        <translation>Bir dahaki sefere bu sayfayı atla</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="53"/>
        <source>Go directly to the input page when the program is started.</source>
        <translation>Program başlatıldığında doğrudan giriş sayfasına git.</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="76"/>
        <source>Continue</source>
        <translation>Devam et</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Kaydet</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Mevcut ayarları bu profile kaydet.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Yeni</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Mevcut ayarlarla yeni bir profil oluştur.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Sil</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Bu profili sil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(yok)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Hata: Profil yüklenemiyor!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Bu profilin üzerine yazmak istediğinizden emin misiniz?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Yeni profil için bir ad girin:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Aynı adla bir profil zaten var. Bu profili değiştirmek istediğinizden emin misiniz?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Bu profili silmek istediğinizden emin misiniz?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="74"/>
        <source>&amp;OK</source>
        <translation>&amp;Tamam</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="75"/>
        <source>&amp;Cancel</source>
        <translation>&amp;İptal</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Evet</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Evet, her zaman</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Hayır</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Hayır, asla</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="41"/>
        <source>Discard</source>
        <translation>Vazgeç</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="42"/>
        <source>Save</source>
        <translation>Kaydet</translation>
    </message>
</context>
<context>
    <name>RecordScheduleEntryWidget</name>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="47"/>
        <source>Start</source>
        <translation>Başla</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="48"/>
        <source>Pause</source>
        <translation>Duraklat</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="54"/>
        <source>Time:</source>
        <translation>Zaman:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogRecordSchedule.cpp" line="59"/>
        <source>Action:</source>
        <translation>Eylem:</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Senkronizasyon Diyagramı</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="262"/>
        <source>Video in</source>
        <translation>Video girişi</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="263"/>
        <source>Audio in</source>
        <translation>Ses girişi</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="264"/>
        <source>Video out</source>
        <translation>Video çıkışı</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="265"/>
        <source>Audio out</source>
        <translation>Ses çıkışı</translation>
    </message>
</context>
</TS>
