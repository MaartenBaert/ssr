<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="el_GR">
<context>
    <name>DialogAbout</name>
    <message>
        <source>About SimpleScreenRecorder</source>
        <translation>Σχετικά με το SimpleScreenRecorder</translation>
    </message>
    <message>
        <source>For more information:</source>
        <translation>Για περισσότερες πληροφορίες:</translation>
    </message>
    <message>
        <source>The source code of this program can be found at:</source>
        <translation>Ο πηγαίος κώδικας αυτού του προγράμματος μπορεί να βρεθεί στο:</translation>
    </message>
    <message>
        <source>This program uses:</source>
        <translation>Αυτό το πρόγραμμα χρησιμοποιεί:</translation>
    </message>
    <message>
        <source>%1 for the graphical user interface</source>
        <translation>%1 για το γραφικό περιβάλλον εργασίας</translation>
    </message>
    <message>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1ή%2 (εξαρτάται από την διανομή) για την κωδικοποίηση βίντεο και ήχου</translation>
    </message>
    <message>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 για την διασύνδεση των λειτουργιών του συστήματος με την εγγραφή για OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <source>OpenGL Settings</source>
        <translation>Ρυθμίσεις OpenGL</translation>
    </message>
    <message>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt;*Προειδοποίηση*:Η εγγραφή OpenGL λειτουργεί «εκχύοντας» μια βιβλιοθήκη μέσα στο πρόγραμμα που θα εγγραφεί. Αυτή η βιβλιοθήκη θα παρακάμψει κάποιες λειτουργίες του συστήματος προκειμένου να καταγράψει τα καρέ πριν εμφανιστούν στην οθόνη. Αν προσπαθείτε να εγγράψετε ένα παιχνίδι το οποίο προσπαθεί να εντοπίσει απόπειρες «σπασίματος»(hacking), θεωρητικά είναι δυνατόν το παιχνίδι να εκλάβει την ενέργεια ως «πειρατεία». Αυτό μπορεί να έχει ως αποτέλεσμα την απομάκρυνσή σας από το παιχνίδι(ban). Οπότε είναι καλό να σιγουρέψετε πρώτα ότι το παιχνίδι που προσπαθείτε να εγγράψετε δεν θα σας απαγορεύσει την πρόσβαση(ban). Έχετε προειδοποιηθεί :).&lt;/p&gt;

&lt;p&gt;Άλλη μια προειδοποίηση: Η εγγραφή μέσω OpenGL είναι πειραματική και μπορεί να μην λειτουργήσει σωστά ή ακόμη και να σπάσει(crash) το πρόγραμμα που προσπαθείτε να εγγράψετε. Αν ανησυχείτε για την απώλεια δεδομένων, καλό θα είναι να πάρετε ένα αντίγραφο ασφαλείας πρώτα!&lt;/p&gt;

&lt;p&gt;Αν θέλετε να εγγράψετε παιχνίδια από το Steam,  &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;διαβάστε πρώτα εδώ&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <source>Choose channel</source>
        <translation>Επιλέξετε κανάλι</translation>
    </message>
    <message>
        <source>Channel name:</source>
        <translation>Όνομα καναλιού:</translation>
    </message>
    <message>
        <source>Channel names are used to identify applications. You only need to change this if you want to record multiple applications at the same time.</source>
        <translation type="obsolete">Τα ονόματα καναλιών χρησιμοποιούνται για να αναγνωρίσουν τις εφαρμογές. Χρειάζεται να το αλλάξετε αυτό μόνον αν εγγράφετε πολλαπλές εφαρμογές την ίδια στιγμή.</translation>
    </message>
    <message>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>«Χαλαρώστε» τα κοινά δικαιώματα της μνήμης (ανασφαλές)</translation>
    </message>
    <message>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Αν χρησιμοποιήσετε αυτή τη λειτουργία άλλοι χρήστες στην ίδια συσκευή θα μπορούν να συνδεθούν στην κοινή μνήμη που χρησιμοποιείται για την επικοινωνία με το πρόγραμμα OpenGL. Αυτό σημαίνει ότι άλλοι χρήστες μπορούν (θεωρητικά) να δουν τι μαγνητοσκοποείται, να αλλάξουν τα καρέ, να εισάγουν τα δικά τους καρέ, ή απλά να διακόψουν την επικοινωνία. Αυτό ισχύει ακόμη και για χρήστες που είναι συνδεδεμένοι απομακρυσμένα (ssh). Αυτό πρέπει να το ενεργοποιήσετε μόνον αν καταγράφετε ένα πρόγραμμα που τρέχει ως άλλος χρήστης.</translation>
    </message>
    <message>
        <source>Launch application</source>
        <translation>Εκκίνηση εφαρμογής</translation>
    </message>
    <message>
        <source>Command:</source>
        <translation>Εντολή:</translation>
    </message>
    <message>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Αυτή η εντολή θα εκτελεστεί για να εκκινήσει το πρόγραμμα που πρέπει να μαγνητοσκοπηθεί.</translation>
    </message>
    <message>
        <source>Working directory:</source>
        <translation>Κατάλογος εργασίας:</translation>
    </message>
    <message>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>Η εντολή θα εκτελεστεί σε αυτόν τον κατάλογο. Αν το αφήσετε κενό, ο κατάλογος εργασίας δεν θα αλλάξει.</translation>
    </message>
    <message>
        <source>Launch automatically</source>
        <translation>Αυτόματη εκκίνηση</translation>
    </message>
    <message>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation>Αν ενεργοποιηθεί, η εφαρμογή θα εκκινεί αυτόματα αφού πάτε στην σελίδα εγγραφής. Αν δεν ενεργοποιηθεί, θα πρέπει να την εκκινήσετε χειροκίνητα.</translation>
    </message>
    <message>
        <source>Launch now</source>
        <translation>Εκκίνηση τώρα</translation>
    </message>
    <message>
        <source>Stream settings</source>
        <translation>Ρυθμίσεις ροής</translation>
    </message>
    <message>
        <source>Limit application frame rate</source>
        <translation>Οριοθετείστε τον ρυθμό καρέ της εφαρμογής</translation>
    </message>
    <message>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Αν ενεργοποιηθεί, η βιβλιοθήκη που θα εισαχθεί θα καθυστερήσει την εφαρμογή έτσι ώστε ο ρυθμός των καρέ να μην γίνει μεγαλύτερος από τον ρυθμό των καρέ που εγγράφονται.
Αυτό σταματά την εφαρμογή από το να απασχολεί την CPU για τους ρυθμούς των καρέ που δεν θα εγγραφούν, και κάποιες φορές έχει ως αποτέλεσμα ομαλότερο βίντεο (αυτό εξαρτάται από την εφαρμογή).</translation>
    </message>
    <message>
        <source>Close</source>
        <translation>Κλείσιμο</translation>
    </message>
    <message>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>DialogRecordSchedule</name>
    <message>
        <source>Recording schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Time zone:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Local time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>UTC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Current time:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Add</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Remove</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Move up</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Move down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Close</source>
        <translation type="unfinished">Κλείσιμο</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <source>Error: Resample ratio is out of range!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Drift ratio is out of range!</source>
        <translation></translation>
    </message>
    <message>
        <source>Resample ratio is %1 (was %2).</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Stopping input thread ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Generating source list ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not update ALSA configuration!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Could not open sound card %1.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set access type!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample format!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set channel count!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set period size!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation></translation>
    </message>
    <message>
        <source>Input thread started.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t read samples!</source>
        <translation></translation>
    </message>
    <message>
        <source>Input thread stopped.</source>
        <translation></translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Unknown exception in input thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not connect to JACK!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not create JACK port!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not set JACK process callback!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not activate JACK client!</source>
        <translation></translation>
    </message>
    <message>
        <source>Connecting port %1 to %2.</source>
        <translation></translation>
    </message>
    <message>
        <source>Disconnecting port %1 from %2.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not create main loop!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not create context!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Stream was moved to a different source.</source>
        <translation></translation>
    </message>
    <message>
        <source>Created video stream reader.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation></translation>
    </message>
    <message>
        <source>Destroyed video stream reader.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Added pre-existing stream %1.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Added stream %1.</source>
        <translation></translation>
    </message>
    <message>
        <source>Removed stream %1.</source>
        <translation></translation>
    </message>
    <message>
        <source>Deleted abandoned stream %1.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Width or height is zero!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Using X11 shared memory.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t create shared image!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation></translation>
    </message>
    <message>
        <source>Not using X11 shared memory.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Invalid screen bounding box!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Channel count is zero.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Sample rate is zero.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Encoding of audio frame failed!</source>
        <translation></translation>
    </message>
    <message>
        <source>Stopping encoder thread ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open codec!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation></translation>
    </message>
    <message>
        <source>Encoder thread started.</source>
        <translation></translation>
    </message>
    <message>
        <source>Flushing encoder ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Encoder thread stopped.</source>
        <translation></translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Unknown exception in encoder thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Stopping encoders ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Waiting for muxer thread to stop ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Finishing encoders ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation></translation>
    </message>
    <message>
        <source>Using format %1 (%2).</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open output file!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t find codec!</source>
        <translation></translation>
    </message>
    <message>
        <source>Using codec %1 (%2).</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t create new stream!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation></translation>
    </message>
    <message>
        <source>Muxer thread started.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation></translation>
    </message>
    <message>
        <source>Muxer thread stopped.</source>
        <translation></translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Unknown exception in muxer thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Stopping synchronizer thread ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation></translation>
    </message>
    <message>
        <source>Synchronizer thread started.</source>
        <translation></translation>
    </message>
    <message>
        <source>Synchronizer thread stopped.</source>
        <translation></translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Unknown exception in synchronizer thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Width or height is not an even number!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Frame rate is zero!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Encoding of video frame failed!</source>
        <translation></translation>
    </message>
    <message>
        <source>Using real-time priority.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Stopping synth thread ...</source>
        <translation></translation>
    </message>
    <message>
        <source>Synth thread started.</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t write samples!</source>
        <translation></translation>
    </message>
    <message>
        <source>Synth thread stopped.</source>
        <translation></translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>Unknown exception in synth thread.</source>
        <translation></translation>
    </message>
    <message>
        <source>CPU features</source>
        <translation></translation>
    </message>
    <message>
        <source>The application could not be launched.</source>
        <translation></translation>
    </message>
    <message>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation></translation>
    </message>
    <message>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation></translation>
    </message>
    <message>
        <source>SSR started</source>
        <translation></translation>
    </message>
    <message>
        <source>SSR stopped</source>
        <translation></translation>
    </message>
    <message>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Found plugin: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Found card: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Found device: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Found source: [%1] %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Starting scaler benchmark ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Using sample format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Using pixel format %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Starting converter benchmark ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Sending of audio frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Receiving of audio packet failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t copy parameters to stream!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t create new codec context!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Stopping fragment thread ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Fragment thread started.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Next fragment ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Finishing ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Fragment thread stopped.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Exception &apos;%1&apos; in fragment thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Unknown exception in fragment thread.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Sending of video frame failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Receiving of video packet failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Could not get source info! Reason: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Stream is a monitor.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Stream is not a monitor.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Warning: Xinerama is not supported by X server, multi-monitor support may not work properly.</source>
        <comment>Don&apos;t translate &apos;Xinerama&apos;</comment>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Warning: No monitors detected, multi-monitor support may not work properly.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Command-line option &apos;%1&apos; requires a value!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Warning: No fast pixel format conversion available (%1,%2 -&gt; %3,%4), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set sample format mask!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t wait for new samples!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t open V4L2 device!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t read capabilities of V4L2 device!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: V4L2 device does not support video capture!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: V4L2 device does not support streaming io!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t set capture format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: V4L2 device does not support YUYV pixel format!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Warning: Resolution %1x%2 is not supported, using %3x%4 instead. The video will be scaled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Using color space %1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Buffer request failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Buffer query failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Buffer mmap failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Buffer queue failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Failed to start stream!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Buffer dequeue failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Buffer requeue failed!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Error: Can&apos;t create configuration directory!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Detected fractional screen scale factor, scaling was disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Detecting screen configuration ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Screen %1:</source>
        <translation type="unfinished">Οθόνη %1:</translation>
    </message>
    <message>
        <source>Dead space %1:</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Το SimpleScreenRecorder εντόπισε πως χρησιμοποιείτε τον κλειστού κώδικα οδηγό της NVIDIA με την λειτουργία flipping ενεργοποιημένη. Είναι γνωστό πως αυτό δημιουργεί προβλήματα κατά την εγγραφή. Προτείνεται να απενεργοποιήσετε την λειτουργία flipping . Θέλετε να την απενεργοποιήσω εγώ για εσάς;

Μπορείτε να αλλάξετε αυτή την επιλογή χειροκίνητα από τον πίνακα ελέγχου και ρυθμίσεων της NVIDIA.</translation>
    </message>
    <message>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Δεν μπόρεσα να απενεργοποιήσω την λειτουργία flipping για κάποιο λόγο - Συγγνώμη!. Δοκιμάστε την να απενεργοποιήσετε από τον πίνακα ελέγχου και ρυθμίσεων της NVIDIA.</translation>
    </message>
    <message>
        <source>You are using a non-X11 window system (e.g. Wayland) which is currently not supported by SimpleScreenRecorder. Several features will most likely not work properly. In order to solve this, you should log out, choose a X11/Xorg session at the login screen, and then log back in.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>Η εγγραφή έχει αποθηκευτεί. Μπορείτε να επεξεργαστείτε το βίντεο τώρα, ή να το επανα-κωδικοποιήσετε με καλύτερες ρυθμίσεις για να μικρύνετε το μέγεθος του αρχείου (οι προεπιλεγμένες ρυθμίσεις στοχεύουν σε καλύτερη ποιότητα και ταχύτητα, όχι μέγεθος αρχείου).</translation>
    </message>
    <message>
        <source>Back to the start screen</source>
        <translation>Πίσω στην αρχική οθόνη</translation>
    </message>
    <message>
        <source>Open folder</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <source>Video input</source>
        <translation>Εισαγωγή βίντεο</translation>
    </message>
    <message>
        <source>Record the entire screen</source>
        <translation>Εγγραφή ολόκληρης της οθόνης</translation>
    </message>
    <message>
        <source>Record a fixed rectangle</source>
        <translation>Εγγραφή επιλεγμένου πλαισίου</translation>
    </message>
    <message>
        <source>Follow the cursor</source>
        <translation>Ακολούθησε τον δείκτη</translation>
    </message>
    <message>
        <source>Record OpenGL (experimental)</source>
        <translation type="obsolete">Εγγραφή OpenGL (πειραματικό)</translation>
    </message>
    <message>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Επιλέξτε ποια οθόνη πρέπει να εγγραφεί όταν υπάρχουν πολλαπλές οθόνες.</translation>
    </message>
    <message>
        <source>Select rectangle...</source>
        <translation>Επιλέξτε πλαίσιο...</translation>
    </message>
    <message>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Χρησιμοποιήστε το ποντίκι για να επιλέξετε την επιφάνεια που θα εγγραφεί.</translation>
    </message>
    <message>
        <source>Select window...</source>
        <translation>Επιλέξτε παράθυρο...</translation>
    </message>
    <message>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Χρησιμοποιήστε το ποντίκι για να επιλέξετε ένα παράθυρο που θα εγγραφεί.
Υπόδειξη: Αν κάνετε κλικ στο περίγραμμα του παραθύρου ,όλο το παράθυρο θα εγγραφεί (μαζί με το περίγραμμα). Διαφορετικά θα εγγραφεί μόνο το περιεχόμενο του παραθύρου.</translation>
    </message>
    <message>
        <source>OpenGL settings...</source>
        <translation>Ρυθμίσεις OpenGL...</translation>
    </message>
    <message>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Αλλάξτε τις ρυθμίσεις για την εγγραφή OpenGL.</translation>
    </message>
    <message>
        <source>Left:</source>
        <translation>Αριστερά:</translation>
    </message>
    <message>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Η συντεταγμένη x της αριστερής πάνω γωνίας του πλαισίου που θα εγγραφεί.
Υπόδειξη: Μπορείτε επίσης να αλλάξετε αυτή την τιμή με την ροδέλα του ποντικιού η τα πάνω/κάτω βελάκια.</translation>
    </message>
    <message>
        <source>Top:</source>
        <translation>Επάνω:</translation>
    </message>
    <message>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Η συνεταγμένη y της επάνω αριστερής γωνίας του πλαισίου που θα εγγραφεί.
Υπόδειξη: Μπορείτε επίσης να αλλάξετε την τιμή με την ροδέλα του ποντικιού η τα επάνω/κάτω βελάκια.</translation>
    </message>
    <message>
        <source>Width:</source>
        <translation>Πλάτος:</translation>
    </message>
    <message>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Το πλάτος του πλαισίου που θα εγγραφεί.
Υπόδειξη: Μπορείτε επίσης να αλλάξετε την τιμή με την ροδέλα του ποντικιού ή τα επάνω/κάτω βελάκια.</translation>
    </message>
    <message>
        <source>Height:</source>
        <translation>Ύψος:</translation>
    </message>
    <message>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>Το ύψος του πλαισίου που θα εγγραφεί.
Υπόδειξη: Μπορείτε επίσης να αλλάξετε την τιμή με την ροδέλα του ποντικιού ή τα επάνω/κάτω βελάκια.</translation>
    </message>
    <message>
        <source>Frame rate:</source>
        <translation>Ρυθμός καρέ:</translation>
    </message>
    <message>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>Ο αριθμός των καρέ ανά δευτερόλεπτο στο τελικό βίντεο. Μεγαλύτερος ρυθμός καρέ χρησιμοποιεί περισσότερη επεξεργαστική ισχύ(CPU).</translation>
    </message>
    <message>
        <source>Scale video</source>
        <translation>Κλίμακα βίντεο</translation>
    </message>
    <message>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Ενεργοποιήστε ή απενεργοποιήστε την κλιμάκωση. Η κλιμάκωση χρησιμοποιεί περισσότερη επεξεργαστική ισχύ, αλλά αν το κλιμακούμενο βίντεο είναι μικρότερο, μπορεί να κάνει την κωδικοποίηση γρηγορότερη.</translation>
    </message>
    <message>
        <source>Scaled width:</source>
        <translation>Κλιμάκωση πλάτους:</translation>
    </message>
    <message>
        <source>Scaled height:</source>
        <translation>Κλιμάκωση ύψους:</translation>
    </message>
    <message>
        <source>Record cursor</source>
        <translation>Εγγραφή δείκτη</translation>
    </message>
    <message>
        <source>Audio input</source>
        <translation>Είσοδος ήχου</translation>
    </message>
    <message>
        <source>Record audio</source>
        <translation>Εγγραφή ήχου</translation>
    </message>
    <message>
        <source>Backend:</source>
        <translation>Υποστήριξη ήχου:</translation>
    </message>
    <message>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>Η υποστήριξη ήχου που θα χρησιμοποιηθεί για την εγγραφή.
Η υποστήριξη ήχου ALSA θα δουλέψει επίσης σε συστήματα που χρησιμοποιούν το PulseAudio, αλλά είναι καλύτερο να χρησιμοποιήσετε την υποστήριξη ήχου PulseAudio απευθείας.</translation>
    </message>
    <message>
        <source>Source:</source>
        <translation>Πηγή:</translation>
    </message>
    <message>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation>Η πηγή ALSA που θα χρησιμοποιηθεί για την εγγραφή.
Η προεπιλογή συνήθως δουλεύει σωστά. Οι &apos;κοινόχρηστες&apos; πηγές επιτρέπουν σε πολλαπλά προγράμματα να εγγράψουν την ίδια στιγμή, αλλά μπορεί να είναι λιγότερο αξιόπιστο.</translation>
    </message>
    <message>
        <source>Refresh</source>
        <translation>Ανανέωση</translation>
    </message>
    <message>
        <source>Refreshes the list of ALSA sources.</source>
        <translation>Ανανεώστε την λίστα με τις πηγές ALSA.</translation>
    </message>
    <message>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>H πηγή PulseAudio που θα χρησιμοποιηθεί για την εγγραφή.
Ένα &apos;monitor&apos; είναι μια πηγή που εγγράφει τον ήχο που αναπαράγεται από άλλες εφαρμογές.</translation>
    </message>
    <message>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Ανανεώστε την λίστα με τις πηγές PulseAudio.</translation>
    </message>
    <message>
        <source>Record system microphone</source>
        <translation>Εγγράψτε το μικρόφωνο του συστήματος</translation>
    </message>
    <message>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation>Αν ενεργοποιηθεί, οι θύρες θα συνδεθούν αυτόματα με τις θύρες καταγραφής του συστήματος.</translation>
    </message>
    <message>
        <source>Record system speakers</source>
        <translation>Εγγραφή μεγαφώνων συστήματος</translation>
    </message>
    <message>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation>Αν ενεργοποιηθεί, οι θύρες θα συνδεθούν αυτόματα με οτιδήποτε είναι συνδεδεμένο στις θύρες αναπαραγωγής του συστήματος.</translation>
    </message>
    <message>
        <source>Back</source>
        <translation>Πίσω</translation>
    </message>
    <message>
        <source>Continue</source>
        <translation>Συνέχεια</translation>
    </message>
    <message>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Όλες οι οθόνες:%1x%2</translation>
    </message>
    <message>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Οθόνη %1: %2x%3 σε %4,%5</translation>
    </message>
    <message>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Οθόνη %1</translation>
    </message>
    <message>
        <source>Input profile</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Record OpenGL</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>The audio backend that will be used for recording.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Record entire screen with cursor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Record the entire screen on which the cursor is located, rather than following the cursor position.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Record V4L2 device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>The V4L2 device to record (e.g. /dev/video0).</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <source>%1 files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>%1 αρχεία</translation>
    </message>
    <message>
        <source>Other...</source>
        <translation>Άλλο...</translation>
    </message>
    <message>
        <source>Uncompressed</source>
        <translation>Χωρίς συμπίεση</translation>
    </message>
    <message>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translatorcomment>I don&apos;t translate the error message. It is important for someone be able to search in Web with the original (untranslated) error message.</translatorcomment>
        <translation>Σφάλμα: Could not find any suitable container in libavformat!</translation>
    </message>
    <message>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translatorcomment>I don&apos;t translate the error message. It is important for someone be able to search in Web with the original (untranslated) error message.</translatorcomment>
        <translation>Σφάλμα: Could not find any suitable video codec in libavcodec!</translation>
    </message>
    <message>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Σφάλμα: Could not find any suitable audio codec in libavcodec!</translation>
    </message>
    <message>
        <source>File</source>
        <translation>Αρχείο</translation>
    </message>
    <message>
        <source>Save as:</source>
        <translation>Αποθήκευση ως:</translation>
    </message>
    <message>
        <source>The recording will be saved to this location.</source>
        <translation>Η εγγραφή θα αποθηκευτεί σε αυτή την τοποθεσία.</translation>
    </message>
    <message>
        <source>Browse...</source>
        <translation>Περιήγηση...</translation>
    </message>
    <message>
        <source>Separate file per segment</source>
        <translation type="unfinished">Διαχωρισμός αρχείου ανά τμήμα</translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="obsolete">Αν ενεργοποιηθεί, ένα ξεχωριστό αρχείο βίντεο θα δημιουργείται κάθε φορά που σταματάτε και εκκινείτε την εγγραφή.
Αν το αρχικό όνομα αρχείου είναι &apos;test.mkv&apos;, τα τμήματα θα αποθηκευτούν ως &apos;test-YYYY-MM-DD-HH.MM.SS.mkv&apos;.</translation>
    </message>
    <message>
        <source>Container:</source>
        <translation>Κοντέινερ:</translation>
    </message>
    <message>
        <source>The container (file format) that will be used to save the recording.
Note that not all codecs are supported by all containers, and that not all media players can read all file formats.
- Matroska (MKV) supports all the codecs, but is less well-known.
- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video
   (and many media players only support AAC audio).
- WebM is intended for embedding video into websites (with the HTML5 &lt;video&gt; tag). The format was created by Google.
   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.
   It supports only VP8 and Vorbis.
- OGG supports only Theora and Vorbis.</source>
        <translation>Ο κοντέινερ (τύπος αρχείου) που θα χρησιμοποιηθεί για την εγγραφή.
Σημειώστε ότι όλοι οι κωδικοποιητές υποστηρίζονται από όλους τους κοντέινερς και ότι όλες οι συσκευές αναπαραγωγής πολυμέσων μπορούν να διαβάσουν όλες τις μορφές αρχείων.
- Το Matroska (MKV) υποστηρίζει όλους τους κωδικοποιητές, αλλά είναι λιγότερο δημοφιλές.
- Το MP4 είναι η πιο δημοφιλής μορφή αρχείου και θα αναπαραχθεί σχεδόν σε όλες τις σύγχρονες συσκευές αναπαραγωγής πολυμέσων, αλλά υποστηρίζει μόνο H.264 video 
 (και πολλές συσκευές αναπαραγωγής υποστηρίζουν μόνο ACC ήχο).
- Το WebM χρησιμοποιείται περισσότερο για ενσωματωμένο βίντεο σε ιστοσελίδες (με το HTML5 &lt;video&gt; tag). Ο τύπος αρχείου δημιουργήθηκε από την Google.
- Το WebM υποστηρίζεται από προεπιλογή στον Firefox, Chrome, και Opera, και προσθήκες(plugins) είναι διαθέσιμες για Internet Explorer και Safari.
- Υποστηρίζει μόνο VP8 και Vorbis.
- Το OGG υποστηρίζει μόνο Theora και Vorbis.</translation>
    </message>
    <message>
        <source>Container name:</source>
        <translation>Όνομα κοντέινερ:</translation>
    </message>
    <message>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Για προχωρημένους χρήστες. Μπορείτε να χρησιμοποιήσετε οποιοδήποτε libav/ffmpeg τύπο , αλλά πολλοί από αυτούς δεν είναι χρήσιμοι ή μπορεί να μην λειτουργήσουν σωστά.</translation>
    </message>
    <message>
        <source>Video</source>
        <translation>Βίντεο</translation>
    </message>
    <message>
        <source>Codec:</source>
        <translation>Κωδικοποιητής:</translation>
    </message>
    <message>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>Ο κωδικοποιητής που θα χρησιμοποιηθεί για να συμπιεστεί η ροή του βίντεο.
- Ο H.264(libx264) είναι μακράν ο καλύτερος κωδικοποιητής - υψηλή ποιότητα και αρκετά γρήγορος.
- Ο VP8 (libvpx) είναι αρκετά καλός αλλά επίσης αρκετά αργός.
- Ο Theora(libtheora) δεν προτείνεται γιατί η ποιότητα δεν είναι πολύ καλή.</translation>
    </message>
    <message>
        <source>Codec name:</source>
        <translation>Όνομα κωδικοποιητή:</translation>
    </message>
    <message>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Για προχωρημένους χρήστες. Μπορείτε να χρησιμοποιήσετε οποιονδήποτε libab/ffmpeg κωδικοποιητή βίντεο, αλλά αρκετοί δεν είναι χρήσιμοι ή ίσως να μην λειτουργήσουν σωστα.</translation>
    </message>
    <message>
        <source>Bit rate (in kbps):</source>
        <translation type="obsolete">Ρυθμός bit (σε kbps):</translation>
    </message>
    <message>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>Ο ρυθμός bit (σε kilobit ανά δευτερόλεπτο). Μεγαλύτερη τιμή σημαίνει καλύτερη ποιότητα.
Αν δεν γνωρίζετε από που να ξεκινήσετε, δοκιμάστε 5000 και αλλάξτε το αν χρειαστεί. </translation>
    </message>
    <message>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Αυτή η ρύθμιση αλλάζει την ποιότητα του βίντεο. Χαμηλότερη τιμή σημαίνει υψηλότερη ποιότητα.
Το επιτρεπόμενο εύρος είναι 0-51 (το 0 σημαίνει loosless(μη απωλεστικό), το προεπιλεγμένο είναι 23).</translation>
    </message>
    <message>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>Η ταχύτητα της συμπίεσης. Υψηλότερη ταχύτητα χρησιμοποιεί λιγότερη επεξεργαστική ισχύ (καθιστώντας δυνατόν την εγγραφή υψηλότερων ρυθμών καρέ),
 αλλά τα αποτελέσματα είναι μεγαλύτερου μεγέθους αρχεία. Η ποιότητα δεν πρέπει να επηρεαστεί πολύ. </translation>
    </message>
    <message>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU used:</translation>
    </message>
    <message>
        <source>fastest</source>
        <translation>Η πιο γρήγορη</translation>
    </message>
    <message>
        <source>slowest</source>
        <translation>Η πιο αργή</translation>
    </message>
    <message>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>Η ταχύτητα κωδικοποίησης. Μια υψηλότερη τιμή χρησιμοποιεί *λιγότερο* χρόνο επεξεργαστικής ισχύς (Το όνομα δεν είναι δική μου επιλογή, αυτό είναι το όνομα που χρησιμοποιείται από τον VP8 κωδικοποιητή). Υψηλότερες τιμές έχουν ως αποτέλεσμα χαμηλής ποιότητας βίντεο, εκτός και αν αυξήσετε τον ρυθμό bit επίσης.</translation>
    </message>
    <message>
        <source>Custom options:</source>
        <translation>Προσαρμοσμένες επιλογές:</translation>
    </message>
    <message>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Οι προσαρμοσμένες επιλογές κωδικοποιητή διαχωρίζονται με κόμμα (π.χ. επιλογή1=τιμή1,επιλογή2=τιμή2,επιλογή3=τιμή3)</translation>
    </message>
    <message>
        <source>Allow frame skipping</source>
        <translation>Επιτρέψτε την παράκαμψη των καρέ</translation>
    </message>
    <message>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Αν ενεργοποιηθεί, ο κωδικοποιητής βίντεο θα επιτρέπεται να παρακάμψει τα καρέ αν ο ρυθμός των καρέ που εισάγονται
είναι μικρότερος από τον αριθμό των καρέ που εξάγονται. Αν δεν ενεργοποιηθεί, τα εισαγόμενα καρέ θα γίνουν διπλότυπο για να γεμίσουν τα κενά.
Αυτό αυξάνει το μέγεθος του αρχείου και την χρήση επεξεγραστικής ισχύς, αλλά μειώνει την καθυστέρηση για τις ροές δεδομένων σε κάποιες περιπτώσεις.
Δεν πρέπει να επηρεάσει την εμφάνιση του βίντεο.</translation>
    </message>
    <message>
        <source>Audio</source>
        <translation>Ήχος</translation>
    </message>
    <message>
        <source>The codec that will be used to compress the audio stream. You shouldn&apos;t worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you&apos;re only recording your own voice (i.e. no music), the quality won&apos;t matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it&apos;s very fast.</source>
        <translation>Ο κωδικοποιητής που θα χρησιμοποιηθεί για να συμπιέσει την ροή ήχου. Δεν πρέπει να ανησυχείτε πολύ γι&apos; αυτό,
γιατί το μέγεθος των δεδομένων ήχου συνήθως είναι αμελητέο συγκρινόμενο με το μέγεθος των δεδομένων βίντεο. 
Αν εγγράφετε μόνο την δική σας φωνή (π.χ. χωρίς μουσική), η ποιότητα δεν θα παίζει σημασία έτσι κι αλλιώς.
- Ο Vorbis (libvorbis) είναι πολύ καλός και προτείνεται.
- Ο MP3 (libmp3lame) είναι αξιόπιστος.
- Ο AAC είναι καλός κωδικοποιητής, αλλά η εφαρμογή του η οποία χρησιμοποιείται εδώ (libvo_aacenc ή ο πειραματικός ffmpeg aac encoder)
είναι αρκετά κακή. Χρησιμοποιήστε τον μόνο αν δεν έχετε άλλη επιλογή.
- Η ασυμπίεστη μορφή απλά θα αποθηκεύσει τα δεδομένα ήχου χωρίς να τα συμπιέσει. Το αρχείο θα είναι αρκετά μεγάλο ,
αλλά η λειτουργία είναι αρκετά γρήγορη.</translation>
    </message>
    <message>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Για προχωρημένους χρήστες. Μπορείτε να χρησιμοποιήσετε οποιονδήποτε κωδικοποιητή libav/ffmpeg, αλλά πολλοί από αυτούς δεν είναι χρήσιμοι ή ίσως να μην δουλέψουν.</translation>
    </message>
    <message>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>Ο ρυθμός bit του ήχου (σε kilobit ανά δευτερόλεπτο). Μια μεγαλύτερη τιμή σημαίνει υψηλότερη ποιότητα. Το τυπική τιμή είναι 128.</translation>
    </message>
    <message>
        <source>Back</source>
        <translation>Πίσω</translation>
    </message>
    <message>
        <source>Continue</source>
        <translation>Συνέχεια</translation>
    </message>
    <message>
        <source>not installed</source>
        <translation>Δεν είναι εγκατεστημένο</translation>
    </message>
    <message>
        <source>not supported by container</source>
        <translation>Δεν υποστηρίζεται από τον κοντέινερ</translation>
    </message>
    <message>
        <source>Save recording as</source>
        <translation>Αποθήκευση εγγραφής ως</translation>
    </message>
    <message>
        <source>You did not select an output file!</source>
        <translation>Δεν έχετε επιλέξει αρχείο εξόδου!</translation>
    </message>
    <message>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation type="obsolete">Το αρχείο &apos;%1&apos; υπάρχει ήδη. Είστε σίγουροι πως θέλετε να το αντικαταστήσετε;</translation>
    </message>
    <message>
        <source>(not installed)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Output profile</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.If unchecked, all recorded segments will be combined into a single video file.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Add timestamp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>If checked, the current date and time will be appended to the file name automatically.
If the original file name is &apos;test.mkv&apos;, the video will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Bit rate (in kbit/s):</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Warning: This format will produce unreadable files if the recording is interrupted! Consider using MKV instead.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <source>Recording</source>
        <translation>Εγγραφή</translation>
    </message>
    <message>
        <source>Enable recording hotkey</source>
        <translation>Ενεργοποιήστε το πλήκτρο συντόμευσης εγγραφής</translation>
    </message>
    <message>
        <source>Enable sound notifications</source>
        <translation>Ενεργοποιήστε τις ηχητικές ειδοποιήσεις</translation>
    </message>
    <message>
        <source>Hotkey:</source>
        <translation>Πλήκτρο συντόμευσης:</translation>
    </message>
    <message>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>Το πλήκτρο που πρέπει να πατήσετε (σε συνδυασμό με τον τροποποιητή που δίδεται) για να ξεκινήσετε ή να παγώσετε την εγγραφή.
Το πρόγραμμα που εγγράφεται δεν θα αναγνωρίσει το πάτημα του πλήκτρου.</translation>
    </message>
    <message>
        <source>Information</source>
        <translation>Πληροφορίες</translation>
    </message>
    <message>
        <source>Total time:</source>
        <translation>Συνολικός χρόνος:</translation>
    </message>
    <message>
        <source>FPS in:</source>
        <translation>FPS in:</translation>
    </message>
    <message>
        <source>FPS out:</source>
        <translation>FPS out:</translation>
    </message>
    <message>
        <source>Size in:</source>
        <translation>Μέγεθος εισόδου:</translation>
    </message>
    <message>
        <source>Size out:</source>
        <translation>Μέγεθος εξόδου:</translation>
    </message>
    <message>
        <source>File name:</source>
        <translation>Όνομα αρχείου:</translation>
    </message>
    <message>
        <source>File size:</source>
        <translation>Μέγεθος αρχείου:</translation>
    </message>
    <message>
        <source>Bit rate:</source>
        <translation>Ρυθμός bit:</translation>
    </message>
    <message>
        <source>Preview</source>
        <translation>Προεπισκόπηση</translation>
    </message>
    <message>
        <source>Preview frame rate:</source>
        <translation>Προεπισκόπηση ρυθμού καρέ:</translation>
    </message>
    <message>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Σημείωση: Κάνοντας προεπισκόπηση απαιτείται έξτρα επεξεργαστική ισχύ (ειδικά σε υψηλούς ρυθμούς καρέ).</translation>
    </message>
    <message>
        <source>Log</source>
        <translation>Αρχείο καταγραφής</translation>
    </message>
    <message>
        <source>Cancel recording</source>
        <translation>Ακύρωση εγγραφής</translation>
    </message>
    <message>
        <source>Save recording</source>
        <translation>Αποθήκευση εγγραφής</translation>
    </message>
    <message>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Δεν έχετε αποθηκεύσει την τρέχουσα εγγραφή ακόμη, αν κάνετε έξοδο τώρα θα χαθεί.
Είστε σίγουροι ότι θέλετε να τερματίσετε την εφαρμογή;</translation>
    </message>
    <message>
        <source>Starting page ...</source>
        <translation>Έναρξη σελίδας ...</translation>
    </message>
    <message>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Σφάλμα: Συνέβη κάποιο λάθος κατά την διάρκεια της προετοιμασίας.</translation>
    </message>
    <message>
        <source>Started page.</source>
        <translation>Η σελίδα ξεκίνησε.</translation>
    </message>
    <message>
        <source>Stopping page ...</source>
        <translation>Η σελίδα τερματίζεται ...</translation>
    </message>
    <message>
        <source>Encoding remaining data ...</source>
        <translation>Υπόλοιπα δεδομένα κωδικοποίησης ...</translation>
    </message>
    <message>
        <source>Stopped page.</source>
        <translation>Η σελίδα τερματίστηκε.</translation>
    </message>
    <message>
        <source>Starting output ...</source>
        <translation>Έναρξη εξόδου ...</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation>Σφάλμα: Δεν μπορεί να ληφθεί το μέγεθος της εφαρμογής OpenGL γιατί η είσοδος του GLInject δεν έχει δημιουργηθεί.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Σφάλμα: Δεν μπορεί να ληφθεί το μέγεθος της εφαρμογής OpenGL. Είτε η εφαρμογή δεν εκκίνησε σωστά, ή η εφαρμογή δεν δημιούργησε ένα OpenGL παράθυρο ακόμη. Αν θέλετε να κάνετε εγγραφή πριν εκκινήσετε την εφαρμογή, πρέπει να ενεργοποιήσετε την επιλογή κλιμάκωσης(scaling) και να εισάγετε το μέγεθος του βίντεο χειροκίνητα.</translation>
    </message>
    <message>
        <source>Started output.</source>
        <translation>Η έξοδος ξεκίνησε.</translation>
    </message>
    <message>
        <source>Stopping output ...</source>
        <translation>Τερματισμός εξόδου ...</translation>
    </message>
    <message>
        <source>Stopped output.</source>
        <translation>Η έξοδος τερματίστηκε.</translation>
    </message>
    <message>
        <source>Starting input ...</source>
        <translation>Έναρξη εισόδου ...</translation>
    </message>
    <message>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation>Σφάλμα: Δεν μπορεί να εκκινήσει η είσοδος GLInject διότι δεν έχει δημιουργηθεί.</translation>
    </message>
    <message>
        <source>Started input.</source>
        <translation>Η είσοδος ξεκίνησε.</translation>
    </message>
    <message>
        <source>Stopping input ...</source>
        <translation>Τερματισμός εισόδου ...</translation>
    </message>
    <message>
        <source>Stopped input.</source>
        <translation>Η είσοδος τερματίστηκε.</translation>
    </message>
    <message>
        <source>Pause recording</source>
        <translation>Παύση εγγραφής</translation>
    </message>
    <message>
        <source>Start recording</source>
        <translation>Έναρξη εγγραφής</translation>
    </message>
    <message>
        <source>Stop preview</source>
        <translation>Τερματισμός προεπισκόποιησης</translation>
    </message>
    <message>
        <source>Start preview</source>
        <translation>Έναρξη προεπισκόποιησης</translation>
    </message>
    <message>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Σφάλμα: Συνέβη κάποιο λάθος κατά τη δημιουργία του synth.</translation>
    </message>
    <message>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Είστε βέβαιοι ότι θέλετε να ακυρώστε αυτή την εγγραφή;</translation>
    </message>
    <message>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation type="obsolete">Δεν έχετε εγγράψει κάτι, δεν υπάρχει κάτι για να αποθηκευτεί.

Το πλήκτρο έναρξης είναι στην κορυφή ;).</translation>
    </message>
    <message>
        <source>Quit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Hide window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Show window</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Edit schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,
even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the
SimpleScreenRecorder window show up in the final video.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>When enabled, a sound will be played when the recording is started or paused, or when an error occurs.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Deactivate schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Activate schedule</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>You haven&apos;t recorded anything, there is nothing to save.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Triggering scheduled action &apos;%1&apos; ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Schedule: %1 in %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Schedule: (none)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Schedule: (inactive)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Standard input read error (%1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Standard input closed (%1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Received command &apos;%1&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Unknown command.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Show recording area</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>When enabled, the recorded area is marked on the screen.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Output file: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>The recording schedule can be used to automatically start or pause the recording at a predefined time.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>PageWelcome</name>
    <message>
        <source>&lt;p&gt;Welcome to SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Despite the name, this program actually has a lot of options. Don&apos;t worry though, there are really just two things that you need to know. One, the default settings are usually fine. If you don&apos;t know what something does, just use the default. Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.&lt;/p&gt;

&lt;p&gt;For more information:&lt;br&gt;
%1&lt;/p&gt;</source>
        <translation>&lt;p&gt;Καλωσήλθατε στο SimpleScreenRecorder!&lt;/p&gt;

&lt;p&gt;Ανεξάρτητα από το όνομα του προγράμματος υπάρχουν πολλές δυνατότητες διαθέσιμες. Μην ανησυχείτε όμως, στην πραγματικότητα πρέπει να γνωρίζετε δυο πράγματα. Ένα, οι προεπιλεγμένες ρυθμίσεις συνήθως λειτουργούν ικανοποιητικά. Αν δεν γνωρίζετε την λειτουργία κάποιας ρύθμισης, απλά χρησιμοποιείστε την προεπιλεγμένη. Δύο, σχεδόν όλες οι ρυθμίσεις έχουν παραθυράκι επεξήγησης (tooltip), απλά μετακινήστε τον δείκτη του ποντικιού επάνω σε κάτι, για να δείτε τι ακριβώς κάνει.&lt;/p&gt;
&lt;p&gt;Για περισσότερες πληροφορίες:&lt;/br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <source>About SimpleScreenRecorder</source>
        <translation>Σχετικά με το SimpleScreenRecorder</translation>
    </message>
    <message>
        <source>Continue</source>
        <translation>Συνέχεια</translation>
    </message>
    <message>
        <source>Skip this page next time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Go directly to the input page when the program is started.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <source>Profile</source>
        <translation type="obsolete">Προφίλ</translation>
    </message>
    <message>
        <source>Save</source>
        <translation>Αποθήκευση</translation>
    </message>
    <message>
        <source>Save the current settings to this profile.</source>
        <translation>Αποθηκεύστε τις τρέχουσες ρυθμίσεις σε αυτό το προφίλ.</translation>
    </message>
    <message>
        <source>New</source>
        <translation>Νέο</translation>
    </message>
    <message>
        <source>Create a new profile with the current settings.</source>
        <translation>Δημιουργήστε ένα νέο προφίλ με τις τρέχουσες ρυθμίσεις.</translation>
    </message>
    <message>
        <source>Delete</source>
        <translation>Διαγραφή</translation>
    </message>
    <message>
        <source>Delete this profile.</source>
        <translation>Διαγράψτε αυτό το προφίλ.</translation>
    </message>
    <message>
        <source>(none)</source>
        <translation>(κανένα)</translation>
    </message>
    <message>
        <source>Error: Can&apos;t load profile!</source>
        <translation>Σφάλμα: Δεν μπορεί να φορτωθεί το προφίλ!</translation>
    </message>
    <message>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation>Είστε βέβαιοι ότι θέλετε να αντικαταστήσετε αυτό το προφίλ;</translation>
    </message>
    <message>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation>Ένα προφίλ με το ίδιο όνομα υπάρχει ήδη. Είστει βέβαιοι ότι θέλετε να το αντικαταστήσετε;</translation>
    </message>
    <message>
        <source>Are you sure that you want to delete this profile?</source>
        <translation>Είστε βέβαιοι ότι θέλετε να διαγράψετε αυτό το προφίλ;</translation>
    </message>
    <message>
        <source>Enter a name for the new profile:</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>QDialogButtonBox</name>
    <message>
        <source>&amp;OK</source>
        <translation type="unfinished">&amp;Εντάξει</translation>
    </message>
    <message>
        <source>&amp;Cancel</source>
        <translation type="unfinished">&amp;Ακύρωση</translation>
    </message>
    <message>
        <source>&amp;Yes</source>
        <translation type="unfinished">&amp;Ναι</translation>
    </message>
    <message>
        <source>Yes, always</source>
        <translation type="unfinished">Ναί, πάντα</translation>
    </message>
    <message>
        <source>&amp;No</source>
        <translation type="unfinished">&amp;Όχι</translation>
    </message>
    <message>
        <source>No, never</source>
        <translation type="unfinished">Όχι πάντα</translation>
    </message>
</context>
<context>
    <name>QMessageBox</name>
    <message>
        <source>&amp;OK</source>
        <translation type="obsolete">&amp;Εντάξει</translation>
    </message>
    <message>
        <source>&amp;Cancel</source>
        <translation type="obsolete">&amp;Ακύρωση</translation>
    </message>
    <message>
        <source>&amp;Yes</source>
        <translation type="obsolete">&amp;Ναι</translation>
    </message>
    <message>
        <source>Yes, always</source>
        <translation type="obsolete">Ναί, πάντα</translation>
    </message>
    <message>
        <source>&amp;No</source>
        <translation type="obsolete">&amp;Όχι</translation>
    </message>
    <message>
        <source>No, never</source>
        <translation type="obsolete">Όχι πάντα</translation>
    </message>
</context>
<context>
    <name>RecordScheduleEntryWidget</name>
    <message>
        <source>Start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Pause</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Time:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Action:</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <source>Synchronization Diagram</source>
        <translation>Διάγραμμα συγχρονισμού</translation>
    </message>
    <message>
        <source>Video in</source>
        <translation>Είσοδος βίντεο</translation>
    </message>
    <message>
        <source>Audio in</source>
        <translation>Είσοδος ήχου</translation>
    </message>
    <message>
        <source>Video out</source>
        <translation>Έξοδος βίντεο</translation>
    </message>
    <message>
        <source>Audio out</source>
        <translation>Έξοδος ήχου</translation>
    </message>
</context>
</TS>
