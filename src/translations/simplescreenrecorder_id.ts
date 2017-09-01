<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="id_ID">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="98"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Tentang SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="107"/>
        <source>For more information:</source>
        <translation>Untuk informasi lebih lanjut:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="108"/>
        <source>The source code of this program can be found at:</source>
        <translation>Kode sumber program ini dapat ditemukan di:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="109"/>
        <source>This program uses:</source>
        <translation>Program ini menggunakan:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="110"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 untuk antarmuka pengguna grafis</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="111"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 atau %2 (tergantung pada distribusi Anda) untuk enkoding video/audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="112"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 untuk fungsi sistem hooking bagi perekaman OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="34"/>
        <source>OpenGL Settings</source>
        <translation>Pengaturan OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="37"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;Peringatan: Perekaman OpenGL bekerja dengan cara menyuntikan sebuah pustaka kedalam program yang akan direkam. Pustaka ini akan menggantikan beberapa fungsi sistem untuk menangkap frame sebelum mereka ditampilkan pada layar. Jika Anda mencoba merekam sebuah game yang dapat mendeteksi upaya peretasan pada sisi klien, secara teoritis game tersebut dapat menganggap ini adalah peretasan. Hal ini bahkan dapat membuat Anda diblokir, jadi ada baiknya Anda memastikan bahwa game yang ingin Anda rekam tidak memblokir Anda, *sebelum* Anda mencoba merekamnya. Anda sudah diberi peringatan :).&lt;/p&gt;

&lt;p&gt;Peringatan lain: Perekaman OpenGL bersifat eksperimental, mungkin tidak berhasil atau bahkan merusak program yang Anda rekam. Jika Anda khawatir kehilangan data program, buatlah cadangan terlebih dulu!&lt;/p&gt;

&lt;p&gt;Jika Anda ingin merekam game Steam, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;baca ini dulu&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="51"/>
        <source>Choose channel</source>
        <translation>Pilih saluran</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="53"/>
        <source>Channel name:</source>
        <translation>Nama saluran:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="55"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation>Nama saluran digunakan untuk mengidentifikasi aplikasi. Anda hanya perlu menggunakan ini jika ingin merekam beberapa aplikasi secara bersamaan.
Jika Anda membiarkan ini kosong, nama standar &apos;channel-YOURUSERNAME&apos; yang akan digunakan.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="57"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Izin memori berbagi yang longgar (tidak aman)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Jika dicentang, pengguna lain pada mesin yang sama akan dapat melampirkan pada memori bersama yang digunakan untuk komunikasi dengan program OpenGL.
Hal ini berarti (secara teori) pengguna lain dapat melihat apa yang Anda rekam, memodifikasi frame, menyuntikkan framenya sendiri atau hanya mengganggu komunikasi.
Ini bahkan berlaku untuk pengguna yang login dari jarak jauh (ssh). Anda sebaiknya hanya mengaktifkan ini jika Anda perlu merekam program yang berjalan sebagai pengguna yang berbeda.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="73"/>
        <source>Launch application</source>
        <translation>Luncurkan aplikasi</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="75"/>
        <source>Command:</source>
        <translation>Perintah:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="77"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Perintah ini akan dieksekusi untuk menjalankan program yang ingin direkam.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="79"/>
        <source>Working directory:</source>
        <translation>Direktori kerja:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="81"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Perintah ini akan dieksekusi didalam direktori ini. Jika Anda membiarkannya kosong, direktori kerja tidak akan diubah.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="83"/>
        <source>Launch automatically</source>
        <translation>Luncurkan secara otomatis</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Jika dicentang, aplikasi akan diluncurkan secara otomatis begitu Anda masuk ke halaman rekaman. Jika tidak dicentang, Anda harus memulainya secara manual.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="86"/>
        <source>Launch now</source>
        <translation>Luncurkan sekarang</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="107"/>
        <source>Stream settings</source>
        <translation>Pengaturan Stream</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="109"/>
        <source>Limit application frame rate</source>
        <translation>Batasi frame rate aplikasi</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Jika dicentang, pustaka yang disuntikkan akan memperlambat aplikasi sehingga frame rate tidak lebih tinggi dari frame rate perekaman.

Hal ini menghentikan aplikasi dari membuang waktu CPU untuk frame yang tidak ingin direkam, dan terkadang menghasilkan video yang lebih halus
(ini tergantung dari aplikasi).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="119"/>
        <source>Close</source>
        <translation>Tutup</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation>Kesalahan: Rasio resample diluar jangkauan!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation>Kesalahan: Rasio drift diluar jangkauan!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation>Rasio resample %1 (sebelumnya %2).</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="130"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Peringatan: Format piksel tidak didukung (%1 -&gt; %2), menggunakan swscale sebagai gantinya. Ini bukan sebuah masalah, tetapi kinerjanya akan lebih buruk.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="139"/>
        <location filename="../Benchmark.cpp" line="124"/>
        <location filename="../Benchmark.cpp" line="205"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Kesalahan: Tidak bisa mendapatkan konteks swscale!</translation>
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
        <translation>Peringatan: Memori tidak sesuai untuk SSE, menggunakan fallback converter sebagai gantinya. Ini bukan sebuah masalah, tapi kinerjanya akan lebih buruk.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Peringatan: Terjadi sebuah overrun, beberapa sampel hilang.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Kesalahan: Tidak dapat memulihkan perangkat setelah overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Kesalahan: Tidak dapat memulai perangkat PCM setelah overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="63"/>
        <location filename="../AV/Input/JACKInput.cpp" line="56"/>
        <location filename="../AV/Input/X11Input.cpp" line="207"/>
        <source>Stopping input thread ...</source>
        <translation>Menghentikan thread input ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="96"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="232"/>
        <source>Generating source list ...</source>
        <translation>Menghasilkan daftar sumber ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="115"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation>Kesalahan: Tidak dapat memperbarui konfigurasi ALSA!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="162"/>
        <source>Found plugin: [%1] %2</source>
        <translation>Pengaya ditemukan: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="175"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation>Peringatan: Tidak dapat membuka kartu suara %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation>Peringatan: Tidak dapat memperoleh info untuk kartu suara %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="185"/>
        <source>Found card: [%1] %2</source>
        <translation>Kartu ditemukan: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="210"/>
        <source>Found device: [%1] %2</source>
        <translation>Perangkat ditemukan: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="259"/>
        <location filename="../AV/SimpleSynth.cpp" line="123"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Kesalahan: Tidak dapat membuka perangkat PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="263"/>
        <location filename="../AV/SimpleSynth.cpp" line="127"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Kesalahan: Tidak dapat memperoleh parameter perangkat keras PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="269"/>
        <location filename="../AV/SimpleSynth.cpp" line="133"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Kesalahan: Tidak dapat mengatur tipe akses!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="139"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Kesalahan: Tidak dapat mengatur format sampel!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="282"/>
        <location filename="../AV/SimpleSynth.cpp" line="146"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Kesalahan: Tidak dapat mengatur sample rate!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="286"/>
        <location filename="../AV/SimpleSynth.cpp" line="150"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Peringatan: Sample rate %1 tidak didukung, menggunakan %2 sebagai gantinya. Ini bukan sebuah masalah.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="295"/>
        <location filename="../AV/SimpleSynth.cpp" line="158"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Kesalahan: Tidak dapat mengatur jumlah saluran!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="299"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Peringatan: Jumlah saluran %1 tidak didukung, menggunakan %2 sebagai gantinya. Ini bukan sebuah masalah.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="308"/>
        <location filename="../AV/SimpleSynth.cpp" line="165"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Kesalahan: Tidak dapat mengatur ukuran periode!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="312"/>
        <location filename="../AV/SimpleSynth.cpp" line="169"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Peringatan: Ukuran periode %1 tidak didukung, menggunakan %2 sebagai gantinya. Ini bukan sebuah masalah.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="321"/>
        <location filename="../AV/SimpleSynth.cpp" line="178"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Kesalahan: Tidak dapat mengatur ukuran buffer!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/SimpleSynth.cpp" line="182"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Peringatan: Ukuran buffer %1 tidak didukung, menggunakan %2 sebagai gantinya. Ini bukan sebuah masalah.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="333"/>
        <location filename="../AV/SimpleSynth.cpp" line="190"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Kesalahan: Tidak dapat menerapkan parameter perangkat keras PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="351"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Kesalahan: Tidak dapat memulai perangkat PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="372"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="180"/>
        <location filename="../AV/Input/JACKInput.cpp" line="238"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="299"/>
        <location filename="../AV/Input/X11Input.cpp" line="345"/>
        <source>Input thread started.</source>
        <translation>Thread input telah dijalankan.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="387"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Kesalahan: Tidak dapat membaca sampel!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="413"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="248"/>
        <location filename="../AV/Input/JACKInput.cpp" line="289"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="388"/>
        <location filename="../AV/Input/X11Input.cpp" line="444"/>
        <source>Input thread stopped.</source>
        <translation>Thread input telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="417"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="252"/>
        <location filename="../AV/Input/JACKInput.cpp" line="293"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="392"/>
        <location filename="../AV/Input/X11Input.cpp" line="448"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Pengecualian &apos;%1&apos; di thread input.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="420"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="255"/>
        <location filename="../AV/Input/JACKInput.cpp" line="296"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="395"/>
        <location filename="../AV/Input/X11Input.cpp" line="451"/>
        <source>Unknown exception in input thread.</source>
        <translation>Pengecualian tidak diketahui di thread input.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="149"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation>Kesalahan: Tidak dapat membaca aliran, ini biasanya berarti aliran sudah hilang.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="72"/>
        <source>Error: Could not connect to JACK!</source>
        <translation>Kesalahan: Tidak dapat tersambung dengan JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="81"/>
        <source>Error: Could not create JACK port!</source>
        <translation>Kesalahan: Tidak dapat membuat port JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="87"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation>Kesalahan: Tidak dapat mengatur callback proses JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="91"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation>Kesalahan: Tidak dapat mengatur callback sample rate JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="95"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation>Kesalahan: Tidak dapat mengatur calback xrun JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="99"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation>Kesalahan: Tidak dapat mengatur callback sambungan port JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not activate JACK client!</source>
        <translation>Kesalahan: Tidak dapat mengaktifkan klien JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <location filename="../AV/Input/JACKInput.cpp" line="123"/>
        <location filename="../AV/Input/JACKInput.cpp" line="252"/>
        <source>Connecting port %1 to %2.</source>
        <translation>Menyambungkan port %1 dengan %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="256"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation>Memutus sambungan port %%1 dari %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Kesalahan: pa_mainloop_prepare gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Kesalahan: pa_mainloop_poll gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Kesalahan: pa_mainloop_dispatch gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation>Kesalahan: Tidak dapat membuat main loop!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
        <source>Error: Could not create context!</source>
        <translation>Kesalahan: Tidak dapat membuat konteks!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Kesalahan: Tidak dapat tersambung! Alasan: %1
Kemungkinan sistem Anda tidak menggunakan PulseAudio. Coba gunakan backend ALSA.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Kesalahan: Upaya koneksi gagal! Alasan: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Kesalahan: Tidak dapat membuat aliran! Alasan: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Kesalahan: Tidak dapat terhubung dengan aliran! Alasan: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Kesalahan: Upaya koneksi aliran gagal! Alasan: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="223"/>
        <source>Found source: [%1] %2</source>
        <translation>Sumber ditemukan: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Kesalahan: Tidak bisa mendapatkan nama sumber! Alasan: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="313"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Kesalahan: pa_stream_peek gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="377"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Peringatan: Sumber audio telah ditangguhkan. Segmen saat ini akan dihentikan sampai sumbernya dilanjutkan.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="382"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Peringatan: Aliran dipindahkan ke sumber lain.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation>Pembaca aliran video telah dibuat.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation>Kesalahan: Tidak dapat membuka berkas aliran video!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation>Kesalahan: Tidak dapat mengubah ukuran berkas aliran video!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation>Kesalahan: Tidak dapat memetakan memori berkas aliran video!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation>Kesalahan: Tidak dapat membuka berkas frame video!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation>Pembaca aliran video dihancurkan.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation>Kesalahan: Ukuran berkas frame video tidak benar!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation>Kesalahan: Tidak dapat memetakan memori berkas frame video!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="94"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation>Kesalahan: Tidak dapat membuat direktori saluran!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="102"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation>Kesalahan: Tidak dapat stat direktori saluran!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="106"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation>Kesalahan: Direktori saluran bukan direktori biasa!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="111"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation>Kesalahan: Tidak dapat mengatur mode direktori saluran!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="116"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation>Kesalahan: Direktori saluran dimiliki oleh pengguna yang berbeda! Pilih nama saluran yang berbeda, atau aktifkan izin berkas longgar untuk menggunakannya.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="126"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Kesalahan: Tidak dapat menginisialisasi inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="132"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation>Kesalahan: Tidak dapat melihat direktori saluran!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="144"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation>Kesalahan: Tidak dapat membuka direktori saluran!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="162"/>
        <source>Added pre-existing stream %1.</source>
        <translation>Menambahkan aliran %1 yang sudah ada sebelumnya.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="197"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Kesalahan: Tidak bisa membaca panjang dari inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="205"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Kesalahan: Tidak dapat membaca dari inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="215"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Kesalahan: Menerima sebagian acara dari inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="227"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation>Kesalahan: Menerima sebagian nama dari inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="241"/>
        <source>Added stream %1.</source>
        <translation>Aliran %1 telah ditambahkan.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="249"/>
        <source>Removed stream %1.</source>
        <translation>Aliran %1 telah dihapus.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="275"/>
        <source>Deleted abandoned stream %1.</source>
        <translation>Aliran %1 yang ditinggalkan telah dihapus.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Kesalahan: Format piksel gambar X11 tidak didukung!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="186"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="97"/>
        <source>Error: Width or height is zero!</source>
        <translation>Kesalahan: Lebar atau tingginya nol!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="190"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="101"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Kesalahan: Lebar atau tinggi terlalu besar, lebar dan tinggi maksimal adalah %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="236"/>
        <location filename="../GUI/HotkeyListener.cpp" line="118"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Kesalahan: Tidak dapat membuka display X!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="245"/>
        <source>Using X11 shared memory.</source>
        <translation>Menggunakan memori bersama X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Kesalahan: Tidak dapat membuat gambar bersama!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="253"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Kesalahan: Tidak bisa mendapatkan memori bersama!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Kesalahan: Tidak dapat melampirkan memori bersama!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="264"/>
        <source>Not using X11 shared memory.</source>
        <translation>Tidak menggunakan memori bersama X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="271"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Peringatan: XFixes tidak didukung oleh server X, kursor telah disembunyikan.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="329"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Kesalahan: Kotak pembatas layar tidak valid!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="393"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Kesalahan: Tidak dapat melampirkan server ke memori bersama!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="399"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Kesalahan: Tidak bisa mendapatkan gambar (menggunakan memori bersama)!
    Biasanya ini berarti area perekaman tidak sepenuhnya berada di dalam layar. Atau apakah Anda mengubah resolusi layar?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="410"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Kesalahan: Tidak bisa mendapatkan gambar (tidak menggunakan memori bersama)!
    Biasanya ini berarti area perekaman tidak sepenuhnya berada di dalam layar. Atau apakah Anda mengubah resolusi layar?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="101"/>
        <source>Error: Channel count is zero.</source>
        <translation>Kesalahan: Jumlah salurannya nol.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="105"/>
        <source>Error: Sample rate is zero.</source>
        <translation>Kesalahan: Sample rate-nya nol.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="142"/>
        <source>Using sample format %1.</source>
        <translation>Menggunakan format sampel %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="147"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Kesalahan: Encoder memerlukan format sampel yang tidak didukung!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <source>Error: Sending of audio frame failed!</source>
        <translation>Kesalahan: Mengirim frame audio gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Receiving of audio packet failed!</source>
        <translation>Kesalahan: Menerima paket audio gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="210"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="232"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Kesalahan: Enkoding frame audio gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="31"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="40"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation>Kesalahan: Opsi &apos;%1&apos; tidak dapat diuraikan!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="97"/>
        <source>Stopping encoder thread ...</source>
        <translation>Menghentikan thread encoder ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="165"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Kesalahan: Tidak dapat membuka codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="173"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation>Peringatan: Opsi codec &apos;%1&apos; tidak dikenali!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="189"/>
        <source>Encoder thread started.</source>
        <translation>Thread encoder telah dijalankan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="218"/>
        <source>Flushing encoder ...</source>
        <translation>Flushing encoder ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="229"/>
        <source>Encoder thread stopped.</source>
        <translation>Thread encoder telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="233"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Pengecualian &apos;%1&apos; di thread encoder.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="236"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Pengecualian tidak dikenal di thread encoder.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="71"/>
        <source>Stopping encoders ...</source>
        <translation>Menghentikan encoder ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="78"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Menunggu thread muxer untuk berhenti ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="101"/>
        <location filename="../AV/Output/Muxer.cpp" line="125"/>
        <source>Error: Can&apos;t copy parameters to stream!</source>
        <translation>Kesalahan: Tidak dapat menyalin parameter ke aliran!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="147"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Kesalahan: Tidak bisa menulis header!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="158"/>
        <source>Finishing encoders ...</source>
        <translation>Menyelesaikan encoders ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="200"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Kesalahan: Tidak dapat menemukan format output yang dipilih!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="204"/>
        <source>Using format %1 (%2).</source>
        <translation>Menggunakan format %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="210"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Kesalahan: Tidak dapat mengalokasikan konteks format!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="217"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Kesalahan: Tidak dapat membuka berkas output!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="230"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Kesalahan: Tidak bisa menulis trailer, teruskan saja.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="268"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Kesalahan: Tidak dapat menemukan codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="278"/>
        <source>Using codec %1 (%2).</source>
        <translation>Menggunakan codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="289"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Kesalahan: Tidak dapat membuat aliran baru!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="296"/>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation>Kesalahan: Tidak dapat membuat konteks codec baru!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="308"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Kesalahan: Tidak bisa mendapatkan konteks codec standar!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="321"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Peringatan: Codec ini dianggap eksperimental oleh libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="337"/>
        <source>Muxer thread started.</source>
        <translation>Thread muxer telah dijalankan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="397"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Kesalahan: Tidak dapat menulis frame pada muxer!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="425"/>
        <source>Muxer thread stopped.</source>
        <translation>Thread muxer telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="429"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Pengecualian &apos;%1&apos; di thread muxer.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="432"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Pengecualian tidak dikenal di thread muxer.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="71"/>
        <source>Stopping fragment thread ...</source>
        <translation>Menghentikan thread fragment ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="347"/>
        <source>Fragment thread started.</source>
        <translation>Thread fragment telah dijalankan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="365"/>
        <source>Next fragment ...</source>
        <translation>Fragment berikutnya ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="369"/>
        <source>Finishing ...</source>
        <translation>Menyelesaikan ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="381"/>
        <source>Fragment thread stopped.</source>
        <translation>Thread fragment telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="385"/>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation>Pengecualian &apos;%1&apos; di thread fragment.</translation>
    </message>
    <message>
        <location filename="../AV/Output/OutputManager.cpp" line="388"/>
        <source>Unknown exception in fragment thread.</source>
        <translation>Pengecualian tidak dikenal di thread fragment.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="221"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Menghentikan thread synchronizer ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="329"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Peringatan: Menerima frame video dengan stempel waktu non-monotonik.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="356"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Peringatan: Video buffer overflow, beberapa frame akan hilang. Input audio sepertinya terlalu lambat.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="413"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Peringatan: Menerima sampel audio dengan stempel waktu non-monotonik.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="438"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation>Peringatan: Terlalu banyak sampel audio, menurunkan sampel agar audio tetap sinkron dengan video.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="444"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation>Peringatan: Sampel audio tidak cukup, memasukkan keheningan untuk menjaga agar audio tetap sinkron dengan video.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="510"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation>Peringatan: Input audio lebih dari 2% terlalu lambat!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="514"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation>Peringatan: Input audio lebih dari 2% terlalu cepat!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="549"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Peringatan: Audio buffer overflow, mulai segmen baru agar audio tetap sinkron dengan video (beberapa video dan/atau audio mungkin hilang). Input video sepertinya terlalu lambat.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="585"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation>Peringatan: Menerima lubang di aliran audio, memasukkan keheningan untuk menjaga agar audio tetap sinkron dengan video.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="886"/>
        <source>Synchronizer thread started.</source>
        <translation>Thread synchronizer telah dijalankan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="908"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Thread synchronizer telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="912"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Pengecualian &apos;%1&apos; di thread synchronizer.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="915"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Pengecualian tidak dikenal di thread synchronizer.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="105"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Kesalahan: Lebar atau tingginya bukan angka genap!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="109"/>
        <source>Error: Frame rate is zero!</source>
        <translation>Kesalahan: Frame rate-nya nol!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="166"/>
        <source>Using pixel format %1.</source>
        <translation>Menggunakan format piksel %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="180"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation>Kesalahan: Format piksel tidak didukung oleh codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="208"/>
        <source>Error: Sending of video frame failed!</source>
        <translation>Kesalahan: Mengirim frame video gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="229"/>
        <source>Error: Receiving of video packet failed!</source>
        <translation>Kesalahan: Menerima paket video gagal!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="242"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="263"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Kesalahan: Enkoding frame video gagal!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="40"/>
        <source>Using real-time priority.</source>
        <translation>Menggunakan prioritas real-time.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="50"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation>Menggunakan prioritas nice.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="55"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation>Peringatan: Tidak dapat meningkatkan prioritas thread.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="63"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Kesalahan: Tidak dapat memulihkan perangkat setelah underrun!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="90"/>
        <source>Stopping synth thread ...</source>
        <translation>Menghentikan thread synth ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="223"/>
        <source>Synth thread started.</source>
        <translation>Thread synth telah dijalankan.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="276"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Kesalahan: Tidak dapat menulis sampel!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="284"/>
        <source>Synth thread stopped.</source>
        <translation>Thread synth telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="288"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Pengecualian &apos;%1&apos; di thread synth.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="291"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Pengecualian tidak dikenal di thread synth.</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="165"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation>BGRA %1 ke BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="243"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation>%1 %2 ke %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="253"/>
        <source>Starting scaler benchmark ...</source>
        <translation>Memulai benchmark scaler ...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="260"/>
        <source>Starting converter benchmark ...</source>
        <translation>Memulai benchmark konverter ...</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="46"/>
        <source>CPU features</source>
        <translation>Fitur CPU</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="159"/>
        <source>The application could not be launched.</source>
        <translation>Aplikasi ini tidak dapat diluncurkan.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="164"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation>Peringatan: XInput2 tidak didukung oleh server X, pintasan papantik mungkin tidak berfungsi pada beberapa aplikasi.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="119"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Kesalahan: Opsi baris perintah &apos;%1&apos; tidak mengambil nilai!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="150"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Kesalahan: Opsi baris perintah &apos;%1&apos; tidak dikenal!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="160"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Kesalahan: Argumen baris perintah &apos;%1&apos; tidak dikenal!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="200"/>
        <source>SSR started</source>
        <translation>SSR telah dijalankan</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="228"/>
        <source>SSR stopped</source>
        <translation>SSR telah dihentikan</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="245"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Kesalahan: Tidak dapat membuat direktori .ssr!</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder telah mendeteksi bahwa Anda menggunakan driver NVIDIA proprietary dengan flipping diaktifkan. Hal ini diketahui menyebabkan gangguan pada saat perekaman. Dianjurkan untuk menonaktifkan flipping. Apakah Anda ingin menonaktifkannya?

Anda juga dapat mengubah opsi ini secara manual di panel kontrol NVIDIA.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="90"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Flipping tidak dapat dinonaktifkan untuk beberapa alasan - maaf! Coba nonaktifkan di panel kontrol NVIDIA.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Rekaman telah disimpan. Anda bisa menyunting video sekarang, atau melakukan enkode ulang dengan pengaturan yang lebih baik untuk membuat berkas lebih kecil (pengaturan default dioptimalkan untuk kualitas dan kecepatan, bukan ukuran berkas).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>Kembali ke layar mulai</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="118"/>
        <source>Video input</source>
        <translation>Input video</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="121"/>
        <source>Record the entire screen</source>
        <translation>Merekam seluruh layar</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="122"/>
        <source>Record a fixed rectangle</source>
        <translation>Merekam persegi panjang tetap</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="123"/>
        <source>Follow the cursor</source>
        <translation>Mengikuti kursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="124"/>
        <source>Record OpenGL (experimental)</source>
        <translation>Merekam OpenGL (eksperimental)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="130"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Pilih monitor apa yang ingin direkam dalam konfigurasi multi-monitor.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="131"/>
        <source>Select rectangle...</source>
        <translation>Pilih persegi panjang ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="132"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Gunakan mouse untuk memilih persegi panjang yang direkam.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Select window...</source>
        <translation>Pilih jendela...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="134"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Gunakan mouse untuk memilih jendela yang akan direkam.
Petunjuk: Jika Anda mengklik batas jendela, seluruh jendela akan direkam (termasuk batasnya). Jika tidak, hanya area klien jendela yang akan direkam.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="137"/>
        <source>OpenGL settings...</source>
        <translation>Pengaturan OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="138"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Ubah pengaturan untuk perekaman OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="139"/>
        <source>Left:</source>
        <translation>Kiri:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="143"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Koordinat x dari sudut kiri atas persegi panjang yang direkam.
Petunjuk: Anda juga dapat mengubah nilai ini dengan roda gulir atau panah atas/bawah.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="145"/>
        <source>Top:</source>
        <translation>Atas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="149"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Koordinat y dari sudut kiri atas persegi panjang yang direkam.
Petunjuk: Anda juga dapat mengubah nilai ini dengan roda gulir atau panah atas/bawah.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="151"/>
        <source>Width:</source>
        <translation>Lebar:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="155"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Lebar persegi panjang yang direkam.
Petunjuk: Anda juga dapat mengubah nilai ini dengan roda gulir atau panah atas/bawah.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="157"/>
        <source>Height:</source>
        <translation>Tinggi:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="161"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Tinggi persegi panjang yang direkam.
Petunjuk: Anda juga dapat mengubah nilai ini dengan roda gulir atau panah atas/bawah.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="163"/>
        <source>Frame rate:</source>
        <translation>Frame rate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="167"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Jumlah frame per detik di video final. Frame rate yang lebih tinggi menggunakan lebih banyak waktu CPU.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="168"/>
        <source>Scale video</source>
        <translation>Skala video</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="169"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Mengaktifkan atau menonaktifkan penskalaan. Penskalaan menggunakan lebih banyak waktu CPU, namun jika video berskala lebih kecil, itu bisa membuat enkoding lebih cepat.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="170"/>
        <source>Scaled width:</source>
        <translation>Skala lebar:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="174"/>
        <source>Scaled height:</source>
        <translation>Skala tinggi:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="178"/>
        <source>Record cursor</source>
        <translation>Rekam kursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="248"/>
        <source>Audio input</source>
        <translation>Input audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="250"/>
        <source>Record audio</source>
        <translation>Rekam audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="251"/>
        <source>Backend:</source>
        <translation>Backend:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Backend audio yang akan digunakan untuk merekam.
Backend ALSA juga akan bekerja pada sistem yang menggunakan PulseAudio, tapi lebih baik menggunakan backend PulseAudio secara langsung.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Source:</source>
        <translation>Sumber:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Sumber ALSA yang akan digunakan untuk merekam.
Nilai nya biasanya baik. Sumber &apos;bersama&apos; memungkinkan beberapa program untuk direkam pada saat bersamaan, namun mungkin kurang dapat diandalkan.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="267"/>
        <location filename="../GUI/PageInput.cpp" line="275"/>
        <source>Refresh</source>
        <translation>Segarkan</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="268"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Menyegarkan daftar sumber ALSA.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="273"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>Sumber PulseAudio yang akan digunakan untuk merekam.
&apos;Monitor&apos; adalah sumber yang merekam audio yang dimainkan oleh aplikasi lain.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Menyegarkan daftar sumber PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="279"/>
        <source>Record system microphone</source>
        <translation>Rekam mikrofon sistem</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="280"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Jika dicentang, port akan otomatis terhubung ke port capture sistem.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="281"/>
        <source>Record system speakers</source>
        <translation>Rekam sistem speaker</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="282"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Jika dicentang, port akan terhubung secara otomatis ke apapun yang terhubung ke port playback sistem.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="325"/>
        <source>Back</source>
        <translation>Kembali</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="326"/>
        <source>Continue</source>
        <translation>Lanjut</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="698"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Semua layar: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="702"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Layar %1: %2x%3 di %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="872"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Layar %1</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="83"/>
        <location filename="../GUI/PageOutput.cpp" line="86"/>
        <location filename="../GUI/PageOutput.cpp" line="89"/>
        <location filename="../GUI/PageOutput.cpp" line="92"/>
        <location filename="../GUI/PageOutput.cpp" line="128"/>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>Berkas %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="95"/>
        <location filename="../GUI/PageOutput.cpp" line="101"/>
        <location filename="../GUI/PageOutput.cpp" line="108"/>
        <source>Other...</source>
        <translation>Lainnya...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Uncompressed</source>
        <translation>Tidak terkompresi</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="162"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Kesalahan: Tidak dapat menemukan container yang sesuai di libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="166"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Kesalahan: Tidak dapat menemukan codec video yang sesuai di libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="170"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Kesalahan: Tidak dapat menemukan codec audio yang sesuai di libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="180"/>
        <source>File</source>
        <translation>Berkas</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>Save as:</source>
        <translation>Simpan sebagai:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="184"/>
        <source>The recording will be saved to this location.</source>
        <translation>Rekaman akan disimpan ke lokasi ini.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="185"/>
        <source>Browse...</source>
        <translation>Jelajah...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="186"/>
        <source>Create separate timestamped file for each segment</source>
        <translation>Buat berkas dengan berstempel waktu terpisah untuk setiap segmen</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="187"/>
        <source>If checked, a separate timestamped video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation>Jika dicentang, berkas video dengan berstempel waktu terpisah akan dibuat setiap kali Anda menjeda dan melanjutkan rekaman.
Jika nama berkas aslinya adalah &apos;test.mkv&apos;, segmen akan disimpan sebagai &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="189"/>
        <source>Container:</source>
        <translation>Container:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="194"/>
        <source>(not installed)</source>
        <translation>(tidak terpasang)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="197"/>
        <source>The container (file format) that will be used to save the recording.
Note that not all codecs are supported by all containers, and that not all media players can read all file formats.
- Matroska (MKV) supports all the codecs, but is less well-known.
- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video
   (and many media players only support AAC audio).
- WebM is intended for embedding video into websites (with the HTML5 &lt;video&gt; tag). The format was created by Google.
   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.
   It supports only VP8 and Vorbis.
- OGG supports only Theora and Vorbis.</source>
        <translation>Container (format berkas) yang akan digunakan untuk menyimpan rekaman.
Perhatikan bahwa tidak semua codec didukung oleh semua container, dan tidak semua pemutar media dapat membaca semua format berkas.
- Matroska (MKV) mendukung semua codec, tetapi kurang dikenal.
- MP4 adalah format yang paling terkenal dan dapat diputar dihampir semua pemutar media modern, tetapi hanya
   mendukung video H.264 (dan banyak pemutar media hanya mendukung audio AAC).
- WebM ditujukan untuk menyematkan video ke situs web (dengan tag HTML5 &lt;video&gt;). Format ini dibuat oleh Google.
   WebM didukung secara bawaan di Firefox, Chrome dan Opera, serta tersedia pengaya untuk Internet Explorer dan Safari.
   WebM hanya mendukung VP8 dan Vorbis.
- OGG hanya mendukung Theora dan Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="206"/>
        <source>Container name:</source>
        <translation>Nama container:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="212"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Untuk pengguna tingkat lanjut. Anda bisa menggunakan semua format libav/ffmpeg, tapi banyak di antaranya tidak berguna atau mungkin tidak berfungsi.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="228"/>
        <source>Video</source>
        <translation>Video</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="230"/>
        <location filename="../GUI/PageOutput.cpp" line="310"/>
        <source>Codec:</source>
        <translation>Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="235"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Codec yang akan digunakan untuk mengkompres aliran video.
- H.264 (libx264) adalah codec terbaik - berkualitas tinggi dan sangat cepat.
- VP8 (libvpx) cukup bagus tapi juga cukup lambat.
- Theora (libtheora) tidak dianjurkan karena kualitasnya tidak terlalu bagus.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="239"/>
        <location filename="../GUI/PageOutput.cpp" line="323"/>
        <source>Codec name:</source>
        <translation>Nama codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="245"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Untuk pengguna tingkat lanjut. Anda bisa menggunakan semua codec video libav/ffmpeg, tapi banyak di antaranya tidak berguna atau mungkin tidak berfungsi.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="246"/>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Bit rate (in kbps):</source>
        <translation>Bit rate (dalam kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="248"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Bit rate video (dalam kilobit per detik). Nilai yang lebih tinggi berarti kualitas yang lebih tinggi.
Jika Anda tidak tahu harus mulai dari mana, cobalah 5000 dan ubah nilainya jika perlu.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="255"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Pengaturan ini untuk mengubah kualitas video. Nilai yang lebih rendah berarti kualitas yang lebih tinggi.
Rentang yang diizinkan adalah 0-51 (0 berarti lossless, defaultnya 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="266"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Kecepatan enkoding. Kecepatan yang lebih tinggi menggunakan lebih sedikit CPU (membuat frame rate perekaman lebih tinggi),
namun menghasilkan berkas yang lebih besar. Kualitasnya tidak terlalu terpengaruh.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="268"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU terpakai:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>fastest</source>
        <translation>tercepat</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="275"/>
        <source>slowest</source>
        <translation>terlambat</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="276"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Kecepatan enkoding. Nilai yang lebih tinggi menggunakan *lebih sedikit* waktu CPU. (Saya tidak memilih
namanya, ini adalah nama yang digunakan oleh encoder VP8). Nilai yang lebih tinggi menghasilkan
kualitas video yang lebih rendah, kecuali jika Anda menaikkan bit rate-nya juga.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="278"/>
        <location filename="../GUI/PageOutput.cpp" line="333"/>
        <source>Custom options:</source>
        <translation>Opsi kustom:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="280"/>
        <location filename="../GUI/PageOutput.cpp" line="335"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Opsi codec kustom dipisahkan dengan tanda koma (misal opsi1=nilai1,opsi2=nilai2,opsi3=nilai3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="281"/>
        <source>Allow frame skipping</source>
        <translation>Izinkan melewatkan frame</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="282"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Jika dicentang, encoder video akan diizinkan untuk melewatkan frame jika frame rate input
lebih rendah dibanding frame rate output. Jika tidak dicentang, frame input akan diduplikasi untuk mengisi lubang tersebut.
Hal ini meningkatkan ukuran berkas dan penggunaan CPU, namun mengurangi latency untuk live stream dalam beberapa kasus.
Ini tidak berpengaruh pada tampilan video.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="308"/>
        <source>Audio</source>
        <translation>Audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="315"/>
        <source>The codec that will be used to compress the audio stream. You shouldn&apos;t worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you&apos;re only recording your own voice (i.e. no music), the quality won&apos;t matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it&apos;s very fast.</source>
        <translation>Codec yang akan digunakan untuk mengkompres aliran audio. Sebaiknya Anda tidak perlu terlalu khawatir
tentang hal ini, karena ukuran data audio biasanya dapat diabaikan jika dibandingkan dengan ukuran data video.
Dan jika Anda hanya merekam suara Anda sendiri (tanpa musik), perbedaan kualitasnya tidak terlalu besar.
- Vorbis (libvorbis) hebat, ini adalah codec yang disarankan.
- MP3 (libmp3lame) cukup bagus.
- ACC adalah codec yang bagus, tetapi implementasi yang digunakan disini (libvo_aacenc atau encoder eksperimental
   aac ffmpeg) sangat buruk. Hanya gunakan ini jika Anda tidak punya pilihan lain.
- Tidak terkompresi akan menyimpan data suara tanpa mengkompresnya. Berkas akan cukup besar, tapi sangat cepat.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="329"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Untuk pengguna tingkat lanjut. Anda bisa menggunakan semua codec audio libav/ffmpeg, tapi banyak di antaranya tidak berguna atau mungkin tidak berfungsi.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="332"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Bit rate audio (dalam kilobit per detik). Nilai yang lebih tinggi berarti kualitas yang lebih tinggi. Nilai umumnya adalah 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="357"/>
        <source>Back</source>
        <translation>Kembali</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="358"/>
        <source>Continue</source>
        <translation>Lanjut</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="492"/>
        <source>You did not select an output file!</source>
        <translation>Anda belum memilih berkas output!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="497"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>Berkas &apos;%1&apos; sudah ada. Apakah Anda yakin ingin menimpanya?</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="598"/>
        <location filename="../GUI/PageOutput.cpp" line="606"/>
        <source>not installed</source>
        <translation>tidak terpasang</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="600"/>
        <location filename="../GUI/PageOutput.cpp" line="608"/>
        <source>not supported by container</source>
        <translation>tidak didukung oleh container</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="651"/>
        <source>Save recording as</source>
        <translation>Simpan rekaman sebagai</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="146"/>
        <source>Recording</source>
        <translation>Merekam</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="150"/>
        <source>Enable recording hotkey</source>
        <translation>Aktifkan pintasan perekaman</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Enable sound notifications</source>
        <translation>Aktifkan notifikasi suara</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Hotkey:</source>
        <translation>Pintasan:</translation>
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
        <translation>Tombol yang harus Anda tekan (dikombinasikan dengan pengubah yang diberikan) untuk memulai atau menjeda perekaman.
Program yang Anda rekam tidak akan menerima penekanan tombol.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="198"/>
        <source>Information</source>
        <translation>Informasi</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="200"/>
        <source>Total time:</source>
        <translation>Total waktu:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="202"/>
        <source>FPS in:</source>
        <translation>FPS in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="204"/>
        <source>FPS out:</source>
        <translation>FPS out:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="206"/>
        <source>Size in:</source>
        <translation>Ukuran in:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="208"/>
        <source>Size out:</source>
        <translation>Ukuran out:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="210"/>
        <source>File name:</source>
        <translation>Nama berkas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="213"/>
        <source>File size:</source>
        <translation>Ukuran berkas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="215"/>
        <source>Bit rate:</source>
        <translation>Bit rate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Preview</source>
        <translation>Pratinjau</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>Preview frame rate:</source>
        <translation>Pratinjau frame rate:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Catatan: Pratinjau membutuhkan waktu CPU ekstra (terutama pada frame rate yang tinggi).</translation>
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
        <translation>Batalkan perekaman</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="311"/>
        <location filename="../GUI/PageRecord.cpp" line="320"/>
        <source>Save recording</source>
        <translation>Simpan rekaman</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="325"/>
        <source>Quit</source>
        <translation>Keluar</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="368"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Anda belum menyimpan rekaman saat ini, jika Anda keluar sekarang maka rekaman akan hilang.
Apakah Anda yakin ingin keluar?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="380"/>
        <source>Hide window</source>
        <translation>Sembunyikan jendela</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="382"/>
        <source>Show window</source>
        <translation>Tampilkan jendela</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="550"/>
        <source>Starting page ...</source>
        <translation>Memulai halaman ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="571"/>
        <location filename="../GUI/PageRecord.cpp" line="712"/>
        <location filename="../GUI/PageRecord.cpp" line="797"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Kesalahan: Terjadi kesalahan saat inisialisasi.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="578"/>
        <source>Started page.</source>
        <translation>Halaman telah dimulai.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="602"/>
        <source>Stopping page ...</source>
        <translation>Menghentikan halaman ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="627"/>
        <source>Stopped page.</source>
        <translation>Halaman telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="651"/>
        <source>Starting output ...</source>
        <translation>Memulai output ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="662"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Kesalahan: Tidak bisa mendapatkan ukuran aplikasi OpenGL karena input GLInject belum dibuat.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="667"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Kesalahan: Tidak bisa mendapatkan ukuran aplikasi OpenGL. Hal ini disebabkan karena aplikasi tidak dimulai dengan benar, atau aplikasi belum membuat jendela OpenGL. Jika Anda ingin memulai perekaman sebelum memulai aplikasi, Anda harus mengaktifkan penskalaan dan memasukkan ukuran video secara manual.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="703"/>
        <source>Started output.</source>
        <translation>Output telah dimulai.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="723"/>
        <source>Stopping output ...</source>
        <translation>Menghentikan output ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="741"/>
        <source>Stopped output.</source>
        <translation>Output telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="768"/>
        <source>Starting input ...</source>
        <translation>Memulai input ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="773"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Kesalahan: Tidak dapat memulai input GLInject karena belum dibuat.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="792"/>
        <source>Started input.</source>
        <translation>Input telah dimulai.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="817"/>
        <source>Stopping input ...</source>
        <translation>Menghentikan input ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="828"/>
        <source>Stopped input.</source>
        <translation>Input telah dihentikan.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="844"/>
        <source>Encoding remaining data ...</source>
        <translation>Enkoding data yang tersisa ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="931"/>
        <location filename="../GUI/PageRecord.cpp" line="941"/>
        <source>Pause recording</source>
        <translation>Jeda perekaman</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="934"/>
        <location filename="../GUI/PageRecord.cpp" line="944"/>
        <source>Start recording</source>
        <translation>Mulai perekaman</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="952"/>
        <source>Stop preview</source>
        <translation>Hentikan pratinjau</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="955"/>
        <source>Start preview</source>
        <translation>Mulai pratinjau</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="984"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Kesalahan: Ada yang tidak beres saat membuat synth.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1026"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Apakah Anda yakin ingin membatalkan rekaman ini?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1041"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>Anda tidak merekam apapun, tidak ada yang disimpan.

Tombol mulai ada di atas ;).</translation>
    </message>
</context>
<context>
    <name>PageWelcome</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="40"/>
        <source>&lt;p&gt;Welcome to SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Despite the name, this program actually has a lot of options. Don&apos;t worry though, there are really just two things that you need to know. One, the default settings are usually fine. If you don&apos;t know what something does, just use the default. Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.&lt;/p&gt;

&lt;p&gt;For more information:&lt;br&gt;
%1&lt;/p&gt;</source>
        <translation>&lt;p&gt;Selamat Datang di SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Meski namanya begitu, program ini sebenarnya memiliki banyak opsi. Jangan khawatir, sebenarnya hanya ada dua hal yang perlu Anda ketahui. Pertama, pengaturan standar biasanya baik. Jika Anda tidak tahu harus melakukan apa, cukup gunakan pengaturan standar. Kedua, hampir semua pengaturan memiliki petunjuk. Cukup arahkan mouse diatas sesuatu untuk mencari tahu apa yang dilakukannya.&lt;/p&gt;

&lt;p&gt;Untuk informasi lebih lanjut:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="50"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Tentang SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="72"/>
        <source>Continue</source>
        <translation>Lanjut</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="28"/>
        <source>Profile</source>
        <translation>Profil</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation>Simpan</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation>Simpan pengaturan saat ini ke profil ini.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation>Baru</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation>Buat profil baru dengan pengaturan saat ini.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation>Hapus</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation>Hapus profil ini.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation>(tidak ada)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Kesalahan: Tidak dapat memuat profil!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Apakah Anda yakin ingin menimpa profil ini?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation>Masukkan nama untuk profil baru:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Profil dengan nama yang sama sudah ada. Apakah Anda yakin ingin menggantinya?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Anda yakin ingin menghapus profil ini?</translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <location filename="../common/Dialogs.cpp" line="72"/>
        <source>&amp;OK</source>
        <translation>&amp;OKE</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="36"/>
        <location filename="../common/Dialogs.cpp" line="73"/>
        <source>&amp;Cancel</source>
        <translation>&amp;Batal</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation>&amp;Ya</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation>Ya, selalu</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation>&amp;Tidak</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation>Tidak, jangan pernah</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation>Diagram Sinkronisasi</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="258"/>
        <source>Video in</source>
        <translation>Video in</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="259"/>
        <source>Audio in</source>
        <translation>Audio in</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="260"/>
        <source>Video out</source>
        <translation>Video out</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="261"/>
        <source>Audio out</source>
        <translation>Audio out</translation>
    </message>
</context>
</TS>
