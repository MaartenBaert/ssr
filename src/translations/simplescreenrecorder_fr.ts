<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="fr_FR">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="78"/>
        <source>About SimpleScreenRecorder</source>
        <translation type="unfinished">À propos de SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="87"/>
        <source>For more information:</source>
        <translation type="unfinished">Pour plus d&apos;information:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="88"/>
        <source>The source code of this program can be found at:</source>
        <translation type="unfinished">Le code source de ce programme peut être trouvé à:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>This program uses:</source>
        <translation type="unfinished">Ce programme utilise:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>%1 for the graphical user interface</source>
        <translation type="unfinished">%1 pour l&apos;interface graphique utilisateur</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation type="unfinished">%1 ou %2 (en fonction de votre distribution) pour l&apos;encodage video/audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation type="unfinished">%1 pour activer les fonctions du système d&apos;enregistrement d&apos;OpenGL </translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="34"/>
        <source>OpenGL Settings</source>
        <translation type="unfinished">Les paramètres d&apos;OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="37"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation type="unfinished">&lt;p&gt;Attention: l&apos;enregistrement d&apos;OpenGL fonctionne par injection d&apos;une bibliothèque qui sera enregistrée dans le programme. Cette bibliothèque remplace certaines fonctions du système afin de capturer les images avant leur affichage sur l&apos;écran. Si vous essayez d&apos;enregistrer un jeu qui essaie de détecter les tentatives de piratage du côté client, il est (théoriquement) possible que le jeu  considère cela comme un piratage. Le jeu pourrait même vous refuser l&apos;accès, c&apos;est donc une bonne idée de vérifier que le programme ,que vous souhaitez enregistrer, ne vous interdira pas son utilisation, * avant * d&apos;essayer de l&apos;enregistrer. Vous avez été averti :).&lt;/p&gt;

&lt;p&gt;Si vous souhaitez enregistrer des jeux de la plate-forme Steam, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;lire cela d&apos;abord&lt;/a&gt;.&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="51"/>
        <source>Choose channel</source>
        <translation type="unfinished">Choisissez le canal</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="53"/>
        <source>Channel name:</source>
        <translation type="unfinished">Nom du canal:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="55"/>
        <source>Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.
If you leave this empty, the default name &apos;channel-YOURUSERNAME&apos; will be used.</source>
        <translation type="unfinished">Les noms de canaux sont utilisés pour identifier les applications. Vous avez besoin d&apos;utiliser cette option seulement si vous voulez enregistrer plusieurs applications en même temps.
Si vous laissez ce champ vide, le nom par défaut &quot;channel-VOTRENOMUTILISTEUR &apos;sera utilisé.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="57"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation type="unfinished">Autorisations de partage de mémoire en mode « Relax » (non sécurisé)</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="58"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation type="unfinished">Si elle est cochée, les autres utilisateurs de la machine pourront  utiliser la mémoire partagée qu&apos;utilise le programme OpenGl pour la communication.
Cela veut dire que les autres utilisateurs peuvent (théoriquement) voir ce que vous enregistrez, modifier les trames, inclure leurs propres trames, ou simplement perturber la communication.
Ceci s&apos;applique aussi aux utilisateurs connectés à distance (ssh). Vous ne devez l&apos;activer que si vous avez besoin d&apos;enregistrer un programme activé par un autre utilisateur.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="73"/>
        <source>Launch application</source>
        <translation type="unfinished">Lancer l&apos;application</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="75"/>
        <source>Command:</source>
        <translation type="unfinished">Commande :</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="77"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation type="unfinished">Cette commande sera exécutée pour démarrer le programme qui doit être enregistré.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="79"/>
        <source>Working directory:</source>
        <translation type="unfinished">Dossier de travail:</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="81"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation type="unfinished">La commande sera exécutée dans ce répertoire. Si vous laissez ce champ vide, le répertoire de travail courant sera utilisé.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="83"/>
        <source>Launch automatically</source>
        <translation type="unfinished">Lancer automatiquement</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="84"/>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation type="unfinished">Si elle est cochée, l&apos;application se lance automatiquement dès que vous allez à la page d&apos;enregistrement. Si elle n&apos;est pas cochée, vous devez la démarrer  manuellement.</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="86"/>
        <source>Launch now</source>
        <translation type="unfinished">Lancer maintenant</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="107"/>
        <source>Stream settings</source>
        <translation type="unfinished">Paramètres de flux</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="109"/>
        <source>Limit application frame rate</source>
        <translatorcomment>Translation is for something like &quot;Frame rate limit of the application&quot;. I hope this is the right meaning</translatorcomment>
        <translation type="unfinished">Vitesse de trame limite de l&apos;application</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="110"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation type="unfinished">Si elle est cochée, la bibliothèque injectée va ralentir l&apos;application de sorte que le taux de trame ne dépasse pas celui d&apos;enregistrement.
Cela empêche l&apos;application de gaspiller du temps CPU pour des trames qui ne seraient pas enregistrées, et cela entraîne parfois des vidéos plus fluides
(cela dépend de l&apos;application).</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="119"/>
        <source>Close</source>
        <translation type="unfinished">Fermer</translation>
    </message>
</context>
<context>
    <name>Logger</name>
    <message>
        <location filename="../AV/FastResampler.cpp" line="124"/>
        <source>Error: Resample ratio is out of range!</source>
        <translation type="unfinished">Erreur: Le taux de ré-échantillonnage est hors limite!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="128"/>
        <source>Error: Drift ratio is out of range!</source>
        <translation type="unfinished">Erreur: Le taux de dérive est hors limite!</translation>
    </message>
    <message>
        <location filename="../AV/FastResampler.cpp" line="158"/>
        <source>Resample ratio is %1 (was %2).</source>
        <translation type="unfinished">Le taux de ré-échantillonnage est %1 (était %2).</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="116"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation type="unfinished">Attention: Le format de pixel n&apos;est pas pris en charge (%1 -&gt; %2), utilisation de swscale à la place. Ce n&apos;est pas un problème, mais la performance sera pire.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="125"/>
        <location filename="../Benchmark.cpp" line="119"/>
        <location filename="../Benchmark.cpp" line="200"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir le swscale du contexte!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="147"/>
        <location filename="../AV/FastScaler.cpp" line="172"/>
        <location filename="../AV/FastScaler.cpp" line="197"/>
        <location filename="../AV/FastScaler.cpp" line="219"/>
        <location filename="../AV/FastScaler.cpp" line="242"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation type="unfinished">Attention: La mémoire n&apos;est pas correctement alignée pour SSE utilisation du convertisseur de  « fallback » à la place. Ce n&apos;est pas un problème, mais la performance sera pire.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Attention: Un « overrun » a eu lieu, certains échantillons ont été perdus.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Erreur: Impossible de récupérer le périphérique après un « overrun »!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation type="unfinished">Erreur: Impossible de démarrer le périphérique PCM après un « overrun »!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="63"/>
        <location filename="../AV/Input/JACKInput.cpp" line="56"/>
        <location filename="../AV/Input/X11Input.cpp" line="207"/>
        <source>Stopping input thread ...</source>
        <translation type="unfinished">Arrêt du flux d&apos;entrée ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="96"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="232"/>
        <source>Generating source list ...</source>
        <translation type="unfinished">Création de la liste des sources ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="115"/>
        <source>Error: Could not update ALSA configuration!</source>
        <translation type="unfinished">Erreur: Impossible de mettre à jour la configuration ALSA!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="162"/>
        <source>Found plugin: [%1] %2</source>
        <translation type="unfinished">Plugin trouvé:[%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="175"/>
        <source>Warning: Could not open sound card %1.</source>
        <translation type="unfinished">Avertissement: Impossible d&apos;ouvrir la carte son %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="181"/>
        <source>Warning: Could not get info for sound card %1.</source>
        <translation type="unfinished">Avertissement: Impossible d&apos;obtenir les informations de la carte son %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="185"/>
        <source>Found card: [%1] %2</source>
        <translation type="unfinished">Carte trouvée:[%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="210"/>
        <source>Found device: [%1] %2</source>
        <translation type="unfinished">Périphérique trouvé: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="259"/>
        <location filename="../AV/SimpleSynth.cpp" line="123"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;ouvrir le périphérique PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="263"/>
        <location filename="../AV/SimpleSynth.cpp" line="127"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir les paramètres du matériel PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="269"/>
        <location filename="../AV/SimpleSynth.cpp" line="133"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation type="unfinished">Erreur: Impossible de définir le type d&apos;accès!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="275"/>
        <location filename="../AV/SimpleSynth.cpp" line="139"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation type="unfinished">Erreur: Impossible de définir le format d&apos;échantillonnage!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="282"/>
        <location filename="../AV/SimpleSynth.cpp" line="146"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation type="unfinished">Erreur: Impossible de définir la fréquence d&apos;échantillonnage!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="286"/>
        <location filename="../AV/SimpleSynth.cpp" line="150"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Attention: Le taux d&apos;échantillonnage %1 n&apos;est pas pris en charge, utilisation de %2 à la place. Ce n&apos;est pas un problème.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="295"/>
        <location filename="../AV/SimpleSynth.cpp" line="158"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation type="unfinished">Erreur: Impossible de définir le nombre de canaux!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="299"/>
        <source>Warning: Channel count %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Attention: le nombre de canaux %1 n&apos;est pas pris en charge, utilisation de %2 à la place. Ce n&apos;est pas un problème.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="308"/>
        <location filename="../AV/SimpleSynth.cpp" line="165"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation type="unfinished">Erreur: Impossible de définir la taille de la période!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="312"/>
        <location filename="../AV/SimpleSynth.cpp" line="169"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Attention: La taille %1 de la période n&apos;est pas pris en charge, utilisation de %2 à la place. Ce n&apos;est pas un problème.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="321"/>
        <location filename="../AV/SimpleSynth.cpp" line="178"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation type="unfinished">Erreur: Impossible de définir la taille de la mémoire tampon!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="325"/>
        <location filename="../AV/SimpleSynth.cpp" line="182"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation type="unfinished">Attention:La taille %1 de la mémoire tampon n&apos;est pas pris en charge, utilisation de %2 à la place. Ce n&apos;est pas un problème.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="333"/>
        <location filename="../AV/SimpleSynth.cpp" line="190"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;appliquer les paramètres du matériel PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="351"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation type="unfinished">Erreur: Impossible de démarrer le matériel PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="372"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="180"/>
        <location filename="../AV/Input/JACKInput.cpp" line="238"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="299"/>
        <location filename="../AV/Input/X11Input.cpp" line="345"/>
        <source>Input thread started.</source>
        <translation type="unfinished">Flux d&apos;entrée démarré.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="387"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation type="unfinished">Erreur: Impossible de lire les échantillons!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="413"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="248"/>
        <location filename="../AV/Input/JACKInput.cpp" line="289"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="388"/>
        <location filename="../AV/Input/X11Input.cpp" line="444"/>
        <source>Input thread stopped.</source>
        <translation type="unfinished">Flux d&apos;entrée arrêté.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="417"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="252"/>
        <location filename="../AV/Input/JACKInput.cpp" line="293"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="392"/>
        <location filename="../AV/Input/X11Input.cpp" line="448"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation type="unfinished">Exception &apos;%1&apos; sur le flux d&apos;entrée.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="420"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="255"/>
        <location filename="../AV/Input/JACKInput.cpp" line="296"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="395"/>
        <location filename="../AV/Input/X11Input.cpp" line="451"/>
        <source>Unknown exception in input thread.</source>
        <translation type="unfinished">Une exception inconnue sur le flux d&apos;entrée.</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="149"/>
        <source>Error: Could not read stream, this usually means that the stream was already gone.</source>
        <translation type="unfinished">Erreur: Impossible de lire le flux, cela signifie généralement qu&apos;il est déjà fini.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="72"/>
        <source>Error: Could not connect to JACK!</source>
        <translation type="unfinished">Erreur: Impossible de connecter le JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="81"/>
        <source>Error: Could not create JACK port!</source>
        <translation type="unfinished">Erreur: Impossible de créer le port pour le JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="87"/>
        <source>Error: Could not set JACK process callback!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;activer le processus de rappel du JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="91"/>
        <source>Error: Could not set JACK sample rate callback!</source>
        <translation type="unfinished">Erreur: Impossible de définir la fréquence d&apos;échantillonnage du processus de rappel du JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="95"/>
        <source>Error: Could not set JACK xrun callback!</source>
        <translation type="unfinished">Erreur: Impossible de définir le « xrun » du processus de rappel du JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="99"/>
        <source>Error: Could not set JACK port connect callback!</source>
        <translation type="unfinished">Erreur: Impossible de définir le port du processus de rappel pour le JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="104"/>
        <source>Error: Could not activate JACK client!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;activer le client pour le JACK!</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="112"/>
        <location filename="../AV/Input/JACKInput.cpp" line="123"/>
        <location filename="../AV/Input/JACKInput.cpp" line="252"/>
        <source>Connecting port %1 to %2.</source>
        <translation type="unfinished">Connexion du port %1 à %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/JACKInput.cpp" line="256"/>
        <source>Disconnecting port %1 from %2.</source>
        <translation type="unfinished">Déconnection du port %1 de %2.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation type="unfinished">Erreur: pa_mainloop_prepare a échoué!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation type="unfinished">Erreur: pa_mainloop_poll a échoué!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation type="unfinished">Erreur: pa_mainloop_dispatch a échoué!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation type="unfinished">Erreur: Impossible de créer la boucle principale!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
        <source>Error: Could not create context!</source>
        <translation type="unfinished">Erreur: Impossible de créer le contexte!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation type="unfinished">Erreur: Impossible de se connecter! Raison: %1
Il est possible que votre système n&apos;utilise pas PulseAudio. Essayez d&apos;utiliser le backend ALSA à la place.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation type="unfinished">Erreur: La tentative de connexion a échoué! Raison: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation type="unfinished">Erreur: Impossible de créer le flux! Raison: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation type="unfinished">Erreur: Impossible de se connecter au flux! Raison: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation type="unfinished">Erreur: Tentative de connexion au flux ratée! Raison: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="223"/>
        <source>Found source: [%1] %2</source>
        <translation type="unfinished">Source trouvée: [%1] %2</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir les noms des sources! Raison: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="313"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation type="unfinished">Erreur: pa_stream_peek a échoué!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="377"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation type="unfinished">Attention: La source audio a été suspendue. Le segment en cours sera arrêté jusqu&apos;à ce que la source soit relancée.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="382"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation type="unfinished">Attention: Le flux a été déplacé sur une autre source.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="64"/>
        <source>Created video stream reader.</source>
        <translation type="unfinished">Le lecteur de flux vidéo est créé.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="69"/>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;ouvrir le fichier de flux vidéo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="76"/>
        <source>Error: Can&apos;t resize video stream file!</source>
        <translation type="unfinished">Erreur: Impossible de redimensionner le fichier de flux vidéo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="83"/>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation type="unfinished">Erreur: Impossible de mapper la mémoire sur le fichier de flux vidéo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="92"/>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;ouvrir le fichier d&apos;images vidéo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="142"/>
        <source>Destroyed video stream reader.</source>
        <translation type="unfinished">Le lecteur de flux vidéo est détruit.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="238"/>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation type="unfinished">Erreur: La taille du fichier d&apos;images vidéo est incorrect!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamReader.cpp" line="247"/>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation type="unfinished">Erreur: Impossible de mapper en mémoire le fichier des images vidéo!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="88"/>
        <source>Error: Can&apos;t create channel directory!</source>
        <translation type="unfinished">Erreur: Impossible de créer le répertoire du canal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="95"/>
        <source>Error: Can&apos;t stat channel directory!</source>
        <translatorcomment>I understand stat as the command to get status of file </translatorcomment>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir le status du répertoire du canal par la commande stat!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="99"/>
        <source>Error: Channel directory is not a regular directory!</source>
        <translation type="unfinished">Erreur: Le répertoire du canal n&apos;est pas un répertoire standard!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="104"/>
        <source>Error: Can&apos;t set channel directory mode!</source>
        <translation type="unfinished">Erreur: Impossible de régler le mode du répertoire du canal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="109"/>
        <source>Error: Channel directory is owned by a different user! Choose a different channel name, or enable relaxed file permissions to use it anyway.</source>
        <translation type="unfinished">Erreur: Le répertoire du canal est détenu par un autre utilisateur! Choisissez un nom de canal différent, ou donnez des permissions ouvertes au répertoire pour pouvoir l&apos;utiliser quand même.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="121"/>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Erreur: Impossible d&apos;initialiser inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="127"/>
        <source>Error: Can&apos;t watch channel directory!</source>
        <translation type="unfinished">Erreur: Impossible de regarder le répertoire du canal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="139"/>
        <source>Error: Can&apos;t open channel directory!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;ouvrir le répertoire du canal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="157"/>
        <source>Added pre-existing stream %1.</source>
        <translation type="unfinished">Flux %1 pré-existant ajouté.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="192"/>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir de inotify la longueur lue!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="200"/>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Erreur: Impossible de lire à partir inotify!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="210"/>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Erreur: Réception de inotify d&apos;un événement incomplet!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="222"/>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="unfinished">Erreur: Réception de inotify d&apos;un nom incomplet!</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="236"/>
        <source>Added stream %1.</source>
        <translation type="unfinished">Ajout du flux %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="244"/>
        <source>Removed stream %1.</source>
        <translation type="unfinished">Suppression du flux %1.</translation>
    </message>
    <message>
        <location filename="../AV/Input/SSRVideoStreamWatcher.cpp" line="270"/>
        <source>Deleted abandoned stream %1.</source>
        <translation type="unfinished">Le flux abandonné %1 est supprimé.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation type="unfinished">Erreur: Format X11 en pixel de l&apos;image non supporté!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="186"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="112"/>
        <source>Error: Width or height is zero!</source>
        <translation type="unfinished">Erreur: Largeur ou hauteur nulle!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="190"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="116"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation type="unfinished">Erreur: Largeur ou hauteur trop grande, la largeur et la hauteur maximale est de %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="236"/>
        <location filename="../GUI/HotkeyListener.cpp" line="118"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation type="unfinished">Erreur: Impossible d&apos;ouvrir le display X!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="245"/>
        <source>Using X11 shared memory.</source>
        <translation type="unfinished">Utilisation de la mémoire partagée X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation type="unfinished">Erreur: Impossible de créer d&apos;images partagées!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="253"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir de la mémoire partagée!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="258"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation type="unfinished">Erreur: Impossible de joindre la mémoire partagée!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="264"/>
        <source>Not using X11 shared memory.</source>
        <translation type="unfinished">Pas d&apos;utilisation de la mémoire partagée X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="271"/>
        <source>Warning: XFixes is not supported by X server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation type="unfinished">Avertissement: Xfixes n&apos;est pas pris en charge par le serveur X, le curseur a été caché.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="329"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation type="unfinished">Erreur: Zone de délimitation de l&apos;écran invalide!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="393"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation type="unfinished">Erreur: Impossible au serveur de joindre la mémoire partagée!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="399"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir d&apos;image (utilisation de la mémoire partagée)!
Habituellement, cela signifie que la zone d&apos;enregistrement n&apos;est pas complètement à l&apos;intérieur de l&apos;écran. Ou avez-vous changé la résolution de l&apos;écran?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="410"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir d&apos;image (pas d&apos;utilisation de la mémoire partagée)!
    Habituellement, cela signifie que la zone d&apos;enregistrement n&apos;est pas complètement à l&apos;intérieur de l&apos;écran. Ou avez-vous changé la résolution de l&apos;écran?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="99"/>
        <source>Error: Channel count is zero.</source>
        <translation type="unfinished">Erreur: Le nombre de canaux est égal à zéro.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="103"/>
        <source>Error: Sample rate is zero.</source>
        <translation type="unfinished">Erreur: Le taux d&apos;échantillonnage est de zéro.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="140"/>
        <source>Using sample format %1.</source>
        <translation type="unfinished">Utilisation du format de l&apos;échantillon %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="145"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation type="unfinished">Erreur: L&apos;encodeur demande un format de l&apos;échantillon non supporté!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="176"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="197"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation type="unfinished">Erreur: L&apos;encodage de la trame audio a échoué!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="31"/>
        <location filename="../AV/Output/BaseEncoder.cpp" line="40"/>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="unfinished">Erreur: L&apos;option &apos;%1&apos; n&apos;a pas pu être analysée!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Stopping encoder thread ...</source>
        <translation type="unfinished">Arrêt du thread de l&apos;encodeur ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="155"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;ouvrir le codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="163"/>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation type="unfinished">Attention: L&apos;option du codec &apos;%1&apos; n&apos;est pas reconnue!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="179"/>
        <source>Encoder thread started.</source>
        <translation type="unfinished">Le thread de l&apos;encodeur est démarré.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="211"/>
        <source>Flushing encoder ...</source>
        <translation type="unfinished">Arrêt des encodages …</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="225"/>
        <source>Encoder thread stopped.</source>
        <translation type="unfinished">Thread de l&apos;encodeur arrêté.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="229"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation type="unfinished">Exception &apos;%1&apos; sur le thread de l&apos;encodeur.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="232"/>
        <source>Unknown exception in encoder thread.</source>
        <translation type="unfinished">Une exception inconnue sur le thread de l&apos;encodeur.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="71"/>
        <source>Stopping encoders ...</source>
        <translation type="unfinished">Arrêt de l&apos;encodeur ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="78"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation type="unfinished">En attente du thread du multiplexeur pour arrêter ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="133"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation type="unfinished">Erreur: Impossible d&apos;écrire le header!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="144"/>
        <source>Finishing encoders ...</source>
        <translation type="unfinished">Finition des encodages ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="186"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation type="unfinished">Erreur: Impossible de trouver le format de sortie choisi!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="190"/>
        <source>Using format %1 (%2).</source>
        <translation type="unfinished">Utilisation du format %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="196"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;allouer le contexte du format!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="203"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;ouvrir le fichier de sortie!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="216"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation type="unfinished">Erreur: Impossible d&apos;écrire le trailer, on continue de toute façon.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="254"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation type="unfinished">Erreur: Impossible de trouver le codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="264"/>
        <source>Using codec %1 (%2).</source>
        <translation type="unfinished">Utilisation du codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="273"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation type="unfinished">Erreur: Impossible de créer un nouveau flux!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="283"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir le contexte par défaut du codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="296"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation type="unfinished">Attention: Ce codec est considéré comme expérimental par libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="312"/>
        <source>Muxer thread started.</source>
        <translation type="unfinished">Le thread du multiplexeur est démarré.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="371"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;écrire la trame à multiplexer!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="399"/>
        <source>Muxer thread stopped.</source>
        <translation type="unfinished">Thread du multiplexeur arrêté.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="403"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation type="unfinished">Exception &apos;%1&apos; sur le thread du multiplexeur.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="406"/>
        <source>Unknown exception in muxer thread.</source>
        <translation type="unfinished">Une exception inconnue sur le thread du  multiplexeur.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="205"/>
        <source>Stopping synchronizer thread ...</source>
        <translation type="unfinished">Arrêt du thread du synchroniseur ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="322"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation type="unfinished">Attention: Échantillons vidéo reçus avec timestamp non monotone.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="348"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation type="unfinished">Attention: Débordement du tampon vidéo, certaines images seront perdues. L&apos;entrée audio semble être trop lente.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="405"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation type="unfinished">Attention: Échantillons audio reçus avec timestamp non monotone.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="430"/>
        <source>Warning: Too many audio samples, dropping samples to keep the audio in sync with the video.</source>
        <translation type="unfinished">Attention: Trop nombreux échantillons audio, abandon d&apos;échantillons pour garder l&apos;audio en synchronisation avec la vidéo.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="436"/>
        <source>Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished">Attention: Pas assez d&apos;échantillons audio, insertion de silences pour garder l&apos;audio en synchronisation avec la vidéo.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="502"/>
        <source>Warning: Audio input is more than 2% too slow!</source>
        <translation type="unfinished">Attention: l&apos;entrée audio est plus de 2% trop lente!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="506"/>
        <source>Warning: Audio input is more than 2% too fast!</source>
        <translation type="unfinished">Attention: l&apos;entrée audio est plus de 2% trop rapide!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="541"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation type="unfinished">Attention: débordement de tampon audio, démarrage d&apos;un nouveau segment pour garder l&apos;audio en synchronisation avec la vidéo (certaines vidéos et/ou audios peuvent être perdus). L&apos;entrée vidéo semble être trop lente.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="577"/>
        <source>Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video.</source>
        <translation type="unfinished">Attention: Réception d&apos;un trou dans une flux audio, insertion de silence pour conserver les données audio en synchronisation avec la vidéo.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="877"/>
        <source>Synchronizer thread started.</source>
        <translation type="unfinished">Thread du synchroniseur démarré.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="899"/>
        <source>Synchronizer thread stopped.</source>
        <translation type="unfinished">Thread du synchroniseur arrêté.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="903"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation type="unfinished">Exception &apos;%1&apos; sur le thread du synchroniseur.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="906"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation type="unfinished">Une exception inconnue sur le thread du synchroniseur.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="120"/>
        <source>Error: Width or height is not an even number!</source>
        <translation type="unfinished">Erreur: La largeur ou la hauteur n&apos;est pas un nombre pair!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="124"/>
        <source>Error: Frame rate is zero!</source>
        <translation type="unfinished">Erreur: Le taux de trame est égal à zéro!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="181"/>
        <source>Using pixel format %1.</source>
        <translation type="unfinished">Utilisation du format pixel %1.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="195"/>
        <source>Error: The pixel format is not supported by the codec!</source>
        <translation type="unfinished">Erreur: Le format de pixel n&apos;est pas pris en charge par le codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="225"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="245"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation type="unfinished">Erreur: Le codage des images vidéo a échoué!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="40"/>
        <source>Using real-time priority.</source>
        <translation type="unfinished">Utilisation de la priorité real-time.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="50"/>
        <source>Using nice priority.</source>
        <comment>Don&apos;t translate &apos;nice&apos;, it&apos;s a UNIX parameter that defines the priority of a process.</comment>
        <translation type="unfinished">Utilisation de la priorité via nice.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="55"/>
        <source>Warning: Can&apos;t increase the thread priority.</source>
        <translation type="unfinished">Attention: Impossible d&apos;augmenter la priorité du thread.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="63"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation type="unfinished">Erreur: Impossible de récupérer le périphérique après &apos;underrun&apos;!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="90"/>
        <source>Stopping synth thread ...</source>
        <translation type="unfinished">Arrêt du thread du synthé ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="223"/>
        <source>Synth thread started.</source>
        <translation type="unfinished">Thread du synthé démarré.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="276"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation type="unfinished">Erreur: Impossible d&apos;écrire les échantillons!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="284"/>
        <source>Synth thread stopped.</source>
        <translation type="unfinished">Thread du synthé arrêté.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="288"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation type="unfinished">Exception &apos;%1&apos; sur le thread du synthé.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="291"/>
        <source>Unknown exception in synth thread.</source>
        <translation type="unfinished">Une exception inconnue sur le flux du synthé.</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="160"/>
        <source>BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</source>
        <translatorcomment>No translation seems better than wrong understanding!</translatorcomment>
        <translation type="unfinished">BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="238"/>
        <source>%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</source>
        <translatorcomment>No translation seems better than wrong understanding!</translatorcomment>
        <translation type="unfinished">%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="248"/>
        <source>Starting scaler benchmark ...</source>
        <translation type="unfinished">Démarrage des essais de réglage ...</translation>
    </message>
    <message>
        <location filename="../Benchmark.cpp" line="255"/>
        <source>Starting converter benchmark ...</source>
        <translation type="unfinished">Démarrage de l&apos;évaluation du convertisseur ...</translation>
    </message>
    <message>
        <location filename="../common/CPUFeatures.cpp" line="46"/>
        <source>CPU features</source>
        <translation type="unfinished">Les fonctions du CPU</translation>
    </message>
    <message>
        <location filename="../GUI/DialogGLInject.cpp" line="159"/>
        <source>The application could not be launched.</source>
        <translation type="unfinished">L&apos;application n&apos;a pas pu être lancée.</translation>
    </message>
    <message>
        <location filename="../GUI/HotkeyListener.cpp" line="164"/>
        <source>Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.</source>
        <comment>Don&apos;t translate &apos;XInput2&apos;</comment>
        <translation type="unfinished">Attention: XInput2 n&apos;est pas pris en charge par le serveur X, les raccourcis peuvent ne pas fonctionner dans certaines applications.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="119"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation type="unfinished">Erreur: l&apos;option &apos;%1&apos; en ligne de commande ne prend pas de valeur!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="150"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation type="unfinished">Erreur: Option inconnue &apos;%1&apos; dans la ligne de commande!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="160"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation type="unfinished">rreur: Argument inconnu &apos;%1&apos; dans la ligne de commande!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="200"/>
        <source>SSR started</source>
        <translation type="unfinished">SSR démarré</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="228"/>
        <source>SSR stopped</source>
        <translation type="unfinished">SSR arrêté</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="245"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation type="unfinished">Erreur: Impossible de créer le répertoire .ssr!</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="74"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="unfinished">SimpleScreenRecorder a détecté que vous utilisez le pilote propriétaire NVIDIA avec l&apos;option « Flipping » active. Ceci est connu pour créer des défauts lors de l&apos;enregistrement. Il est recommandé de désactiver l&apos; option « Flipping ». Voulez-vous que je le fasse pour vous?

Vous pouvez également modifier manuellement cette option dans le panneau de contrôle NVIDIA.</translation>
    </message>
    <message>
        <location filename="../GUI/MainWindow.cpp" line="90"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation type="unfinished">Je ne peux pas désactiver l&apos;option flipping pour quelque raison - désolé! Essayez de la désactiver dans le panneau de contrôle NVIDIA.</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation type="unfinished">L&apos;enregistrement a été sauvegardé. Vous pouvez éditer la vidéo maintenant, ou ré-encoder avec de meilleurs paramètres pour réduire la taille du  fichier  (les paramètres par défaut sont optimisés pour la qualité et la vitesse mais pas  la taille du fichier).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation type="unfinished">Retour à l&apos;écran de démarrage</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="113"/>
        <source>Video input</source>
        <translation type="unfinished">Entrée vidéo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="116"/>
        <source>Record the entire screen</source>
        <translation type="unfinished">Enregistrer la totalité de l&apos;écran</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="117"/>
        <source>Record a fixed rectangle</source>
        <translation type="unfinished">Enregistrer un rectangle choisi</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="118"/>
        <source>Follow the cursor</source>
        <translation type="unfinished">Suivre le curseur</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="119"/>
        <source>Record OpenGL (experimental)</source>
        <translation type="unfinished">Enregistrement OpenGL (expérimental)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="125"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation type="unfinished">Choisissez le moniteur qui doit être enregistré dans une configuration multi-moniteur.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="126"/>
        <source>Select rectangle...</source>
        <translation type="unfinished">Sélectionnez le rectangle...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation type="unfinished">Utilisez la souris pour sélectionner le rectangle à enregistrer.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="128"/>
        <source>Select window...</source>
        <translation type="unfinished">Sélectionnez la fenêtre...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="129"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation type="unfinished">Utilisez la souris pour sélectionner la fenêtre à enregistrer.
Astuce: Si vous cliquez sur la bordure d&apos;une fenêtre, la fenêtre entière sera enregistrée (y compris les bords). Sinon, seule la zone cliente de la fenêtre sera enregistrée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="132"/>
        <source>OpenGL settings...</source>
        <translation type="unfinished">Les paramètres d&apos;OpenGL...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="133"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation type="unfinished">Modifiez les paramètres pour l&apos;enregistrement OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="134"/>
        <source>Left:</source>
        <translation type="unfinished">Gauche:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="138"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation type="unfinished">La coordonnée X du coin supérieur gauche du rectangle à enregistrer.
Astuce: Vous pouvez également modifier cette valeur avec la molette de défilement ou les flèches haut / bas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="140"/>
        <source>Top:</source>
        <translation type="unfinished">Haut:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="144"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation type="unfinished">Coordonnée y du coin supérieur gauche du rectangle à enregistrer.
Astuce: Vous pouvez également modifier cette valeur avec la molette de défilement ou les flèches haut / bas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="146"/>
        <source>Width:</source>
        <translation type="unfinished">Largeur:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="150"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation type="unfinished">La largeur du rectangle à enregistrer.
Astuce: Vous pouvez également modifier cette valeur avec la molette de défilement ou les flèches haut / bas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="152"/>
        <source>Height:</source>
        <translation type="unfinished">Hauteur:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="156"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation type="unfinished">La hauteur du rectangle à enregistrer.
Astuce: Vous pouvez également modifier cette valeur avec la molette de défilement ou les flèches haut / bas.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="158"/>
        <source>Frame rate:</source>
        <translation type="unfinished">Taux de trame:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="162"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation type="unfinished">Le nombre d&apos;images par seconde dans la vidéo finale. Des taux de trame plus élevés utilisent plus de temps CPU.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="163"/>
        <source>Scale video</source>
        <translation type="unfinished">Paramètres de la vidéo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="164"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation type="unfinished">Activer ou désactiver la mise à l&apos;échelle. Une mise à l&apos;échelle utilise plus de temps CPU, mais une plus petite échelle pour la vidéo peut rendre l&apos;encodage plus rapide.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="165"/>
        <source>Scaled width:</source>
        <translation type="unfinished">Largeur de l&apos;image:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="169"/>
        <source>Scaled height:</source>
        <translation type="unfinished">Hauteur de l&apos;image:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="173"/>
        <source>Record cursor</source>
        <translation type="unfinished">Enregistrement du curseur</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="243"/>
        <source>Audio input</source>
        <translation type="unfinished">Entrée audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="245"/>
        <source>Record audio</source>
        <translation type="unfinished">Enregistrement audio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="246"/>
        <source>Backend:</source>
        <translation type="unfinished">Arrière-plan:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="255"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation type="unfinished">L&apos;arrière-plan audio qui sera utilisé pour l&apos;enregistrement.
L&apos;arrière-plan audio ALSA fonctionne également sur les systèmes qui utilisent PulseAudio, mais il est préférable d&apos;utiliser l&apos;arrière-plan audio PulseAudio directement.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="257"/>
        <location filename="../GUI/PageInput.cpp" line="265"/>
        <source>Source:</source>
        <translation type="unfinished">La source:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="260"/>
        <source>The ALSA source that will be used for recording.
The default is usually fine. The &apos;shared&apos; sources allow multiple programs to record at the same time, but they may be less reliable.</source>
        <translation type="unfinished">La source audio ALSA qui sera utilisée pour l&apos;enregistrement.
La valeur par défaut est habituellement très bien. Les sources «partagées» permettent à plusieurs programmes d&apos;enregistrer en même temps, mais elles peuvent être moins fiables.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="262"/>
        <location filename="../GUI/PageInput.cpp" line="270"/>
        <source>Refresh</source>
        <translation type="unfinished">Actualiser</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="263"/>
        <source>Refreshes the list of ALSA sources.</source>
        <translation type="unfinished">Actualise la liste des sources ALSA.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="268"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation type="unfinished">La source PulseAudio qui sera utilisée pour l&apos;enregistrement.
Un «monitor» est une source qui enregistre le son produit par d&apos;autres applications.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="271"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation type="unfinished">Actualise la liste des sources PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="274"/>
        <source>Record system microphone</source>
        <translation type="unfinished">Enregistre le microphone système</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="275"/>
        <source>If checked, the ports will be automatically connected to the system capture ports.</source>
        <translation type="unfinished">Si elle est cochée, les ports seront automatiquement connectés aux ports de capture du système.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="276"/>
        <source>Record system speakers</source>
        <translation type="unfinished">Enregistre les haut-parleurs du système</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="277"/>
        <source>If checked, the ports will be automatically connected to anything that connects to the system playback ports.</source>
        <translation type="unfinished">Si elle est cochée, les ports seront automatiquement connectés à tout ce qui se connecte à des ports de lecture du système.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="312"/>
        <source>Back</source>
        <translatorcomment>I understand that back is: going back (undo last action)</translatorcomment>
        <translation type="unfinished">Annuler</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="313"/>
        <source>Continue</source>
        <translation type="unfinished">Continuer</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="673"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation type="unfinished">Tous les écrans: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="677"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation type="unfinished">Écran %1: %2x%3 à %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="839"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation type="unfinished">Écran %1</translation>
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
        <translation type="unfinished">Fichiers %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="94"/>
        <location filename="../GUI/PageOutput.cpp" line="100"/>
        <location filename="../GUI/PageOutput.cpp" line="107"/>
        <source>Other...</source>
        <translation type="unfinished">Autres...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="106"/>
        <source>Uncompressed</source>
        <translation type="unfinished">Décompressé</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="161"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation type="unfinished">Erreur: Impossible de trouver un conteneur approprié dans libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="165"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation type="unfinished">Erreur: Impossible de trouver un codec vidéo approprié dans libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="169"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation type="unfinished">Erreur: Impossible de trouver un codec audio approprié dans libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="175"/>
        <source>File</source>
        <translation type="unfinished">Fichier</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Save as:</source>
        <translation type="unfinished">Enregistrer sous:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="179"/>
        <source>The recording will be saved to this location.</source>
        <translation type="unfinished">L&apos;enregistrement sera enregistré à cet emplacement.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="180"/>
        <source>Browse...</source>
        <translation type="unfinished">Afficher...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="181"/>
        <source>Separate file per segment</source>
        <translation type="unfinished">Un fichier séparé par segment</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="182"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-YYYY-MM-DD_HH.MM.SS.mkv&apos;.</source>
        <translation type="unfinished">Si elle est cochée, un fichier vidéo distinct sera créé à chaque fois que vous faites une pause et une reprise de l&apos;enregistrement.
Si le nom de fichier d&apos;origine est «test.mkv », les segments seront enregistrés en tant que « test-AAAA-MM-JJ_HH.MM.SS.mkv ».</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="184"/>
        <source>Container:</source>
        <translation type="unfinished">Conteneur:</translation>
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
        <translation type="unfinished">Le conteneur (format de fichier) qui sera utilisé pour sauvegarder l&apos;enregistrement.
Notez que tous les codecs ne sont pas supportés par tous les conteneurs, et que pas tous les lecteurs  multimédia peuvent  lire tous les formats de fichiers.
- Matroska (MKV) prend en charge tous les codecs, mais il n&apos;est pas très connu.
- MP4 est le format le plus connu et sera lu par la plus part des lecteurs de multimédia modernes, mais ne supporte que la vidéo H.264
    (et de nombreux lecteurs de multimédia ne lise que l&apos;audio AAC).
- WebM est conçu pour l&apos;intégration de vidéo dans les sites Web (avec le HTML5 &lt;video&gt;). Le format a été créé par Google.
    WebM est supporté par défaut dans Firefox, Chrome et Opera, et les plugins sont disponibles pour Internet Explorer et Safari.
    Il ne supporte que VP8 et Vorbis.
- OGG supporte seulement Theora et Vorbis.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <source>Container name:</source>
        <translation type="unfinished">Nom du conteneur:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="207"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation type="unfinished">Pour les utilisateurs confirmés. Vous pouvez utiliser n&apos;importe quel format de libav / ffmpeg, mais beaucoup d&apos;entre eux ne sont pas utiles ou peuvent ne pas fonctionner.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="223"/>
        <source>Video</source>
        <translation type="unfinished">Vidéo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="225"/>
        <location filename="../GUI/PageOutput.cpp" line="305"/>
        <source>Codec:</source>
        <translation type="unfinished">Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="230"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation type="unfinished">Le codec qui sera utilisé pour compresser le flux vidéo.
- H.264 (libx264) est de loin le meilleur codec - de haute qualité et très rapide.
- VP8 (libvpx) est assez bon, mais aussi plutôt lent.
- Theora (libtheora) n&apos;est pas vraiment recommandé parce que la qualité n&apos;est pas très bonne.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="234"/>
        <location filename="../GUI/PageOutput.cpp" line="318"/>
        <source>Codec name:</source>
        <translation type="unfinished">Nom du codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="240"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation type="unfinished">Pour les utilisateurs confirmés. Vous pouvez utiliser n&apos;importe quel codec vidéo de libav / ffmpeg, mais beaucoup d&apos;entre eux ne sont pas utiles ou peuvent ne pas fonctionner.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="241"/>
        <location filename="../GUI/PageOutput.cpp" line="325"/>
        <source>Bit rate (in kbps):</source>
        <translation type="unfinished">Débit binaire (en kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="243"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation type="unfinished">Le débit binaire vidéo (en kilobits par seconde). Une valeur plus élevée signifie une qualité supérieure.
Si vous avez aucune idée par où commencer, essayez 5000 et ensuite le changer si nécessaire.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="245"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translatorcomment>Not translated as requested by developer</translatorcomment>
        <translation type="unfinished">Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="250"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation type="unfinished">Ce paramètre modifie la qualité vidéo. Une valeur plus faible signifie une qualité supérieure.
La plage autorisée est 0-51 (0 signifie sans perte, la valeur par défaut est 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="256"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translatorcomment>Not translated as requested by developer</translatorcomment>
        <translation type="unfinished">Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="261"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation type="unfinished">La vitesse d&apos;encodage. Une vitesse plus élevée utilise moins de CPU (rendant possible des taux de trame d&apos;enregistrement  plus élevés), mais crée des fichiers plus volumineux. La qualité ne devrait pas être trop affectée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="263"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation type="unfinished">CPU utilisée:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="265"/>
        <source>fastest</source>
        <translation type="unfinished">Le plus rapide</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="270"/>
        <source>slowest</source>
        <translation type="unfinished">Le plus lent</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="271"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation type="unfinished">La vitesse d&apos;encodage. Une valeur plus élevée utilise * moins * de temps CPU. (Je ne choisis pas le nom, c&apos;est le nom utilisé par le codeur de VP8). Des valeurs élevées produisent une vidéo de qualité inférieure , à moins que vous augmentiez aussi le taux de bit.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="273"/>
        <location filename="../GUI/PageOutput.cpp" line="328"/>
        <source>Custom options:</source>
        <translation type="unfinished">Options personnalisées:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="275"/>
        <location filename="../GUI/PageOutput.cpp" line="330"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation type="unfinished">Des options codec personnalisées séparées par des virgules (ex option1 = valeur1, option2 = valeur2, option3 = valeur3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="276"/>
        <source>Allow frame skipping</source>
        <translation type="unfinished">Autoriser le saut d&apos;image</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="277"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation type="unfinished">Si elle est cochée, l&apos;encodeur vidéo sera autorisé à ignorer des images si le taux de trame d&apos;entrée est inférieur au taux de trame de sortie. Si elle n&apos;est pas coché, des images d&apos;entrée seront dupliquées pour combler les trous.
Cela augmente la taille du fichier et l&apos;utilisation du processeur, mais réduit le temps de latence pour les flux en direct dans certains cas.
Ceci ne devrait pas affecter l&apos;aspect de la vidéo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>Audio</source>
        <translation type="unfinished">Audio</translation>
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
        <translation type="unfinished">Le codec qui sera utilisé pour compresser le flux de données audio. Vous ne devriez pas trop se soucier de ceci, parce que la taille des données audio est, en général, négligeable par rapport à la taille des données vidéo.
Et si vous enregistrer simplement votre propre voix (pas de musique), la qualité importera très peu de toute façon.
- Vorbis (libvorbis) est super, c&apos;est le codec recommandé.
- MP3 (libmp3lame) est raisonnablement bon.
- AAC est un bon codec, mais les implémentations utilisées ici (libvo_aacenc ou l&apos;encodeur expérimental AAC  de ffmpeg)
    sont assez mauvaises. Ne l&apos;utilisez que si vous avez pas d&apos;autre choix.
- Le mode &apos;Non compressé&apos; enregistrera simplement les données sonores sans les compresser. Le fichier sera assez grand, mais il est très rapide.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="324"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation type="unfinished">Pour les utilisateurs confirmés. Vous pouvez utiliser n&apos;importe quel codec audio de libav / ffmpeg, mais beaucoup d&apos;entre eux ne sont pas utiles ou peuvent ne pas fonctionner.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="327"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation type="unfinished">Le débit binaire audio (en kilobits par seconde). Une valeur plus élevée signifie une qualité supérieure. La valeur typique est de 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="344"/>
        <source>Back</source>
        <translation type="unfinished">Retour</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="345"/>
        <source>Continue</source>
        <translation type="unfinished">Continuer</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="564"/>
        <location filename="../GUI/PageOutput.cpp" line="572"/>
        <source>not installed</source>
        <translation type="unfinished">non installé</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="566"/>
        <location filename="../GUI/PageOutput.cpp" line="574"/>
        <source>not supported by container</source>
        <translation type="unfinished">non supporté par le conteneur</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="617"/>
        <source>Save recording as</source>
        <translation type="unfinished">Enregistrer l&apos;enregistrement dans</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="657"/>
        <source>You did not select an output file!</source>
        <translation type="unfinished">Vous n&apos;avez pas choisi de fichier de sortie! </translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="662"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation type="unfinished">Le fichier &apos;%1&apos; existe déjà. Êtes-vous sûr de vouloir le remplacer ?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="146"/>
        <source>Recording</source>
        <translation type="unfinished">En cours d&apos;enregistrement</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="150"/>
        <source>Enable recording hotkey</source>
        <translation type="unfinished">Activer le raccourci d&apos;enregistrement</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Enable sound notifications</source>
        <translation type="unfinished">Activer les notifications sonores</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Hotkey:</source>
        <translation type="unfinished">Raccourci:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="153"/>
        <source>Ctrl +</source>
        <translation type="unfinished">Ctrl +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="154"/>
        <source>Shift +</source>
        <translation type="unfinished">Maj +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="155"/>
        <source>Alt +</source>
        <translation type="unfinished">Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="156"/>
        <source>Super +</source>
        <translatorcomment>I don&apos;t translate because  don&apos;t know this key</translatorcomment>
        <translation type="unfinished">Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="158"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translatorcomment>I translate &quot;... the pressed key.&quot; and not &quot;.... the key press.&quot;</translatorcomment>
        <translation type="unfinished">La clé à utiliser (combinée avec les modificateurs donnés) pour lancer ou interrompre l&apos;enregistrement.
Le programme que vous enregistrez ne verra pas la touche utilisée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="198"/>
        <source>Information</source>
        <translation type="unfinished">Information</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="200"/>
        <source>Total time:</source>
        <translation type="unfinished">Temps total:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="202"/>
        <source>FPS in:</source>
        <translation type="unfinished">FPS en entrée:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="204"/>
        <source>FPS out:</source>
        <translation type="unfinished">FPS en sortie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="206"/>
        <source>Size in:</source>
        <translation type="unfinished">Taille de l&apos;entrée:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="208"/>
        <source>Size out:</source>
        <translation type="unfinished">Taille de la sortie:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="210"/>
        <source>File name:</source>
        <translation type="unfinished">Nom du fichier:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="213"/>
        <source>File size:</source>
        <translation type="unfinished">Taille du fichier:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="215"/>
        <source>Bit rate:</source>
        <translation type="unfinished">Débit en bit:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="238"/>
        <source>Preview</source>
        <translation type="unfinished">Aperçu</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="242"/>
        <source>Preview frame rate:</source>
        <translation type="unfinished">Aperçu du taux de trame:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="246"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation type="unfinished">Note: La prévisualisation nécessite du temps CPU supplémentaire (surtout à des cadences élevées).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="295"/>
        <source>Log</source>
        <translation type="unfinished">Journal</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="310"/>
        <location filename="../GUI/PageRecord.cpp" line="318"/>
        <source>Cancel recording</source>
        <translation type="unfinished">Annuler l&apos;enregistrement</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="311"/>
        <location filename="../GUI/PageRecord.cpp" line="320"/>
        <source>Save recording</source>
        <translation type="unfinished">Sauvegarder l&apos;enregistrement</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="325"/>
        <source>Quit</source>
        <translation type="unfinished">Quitter</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="368"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation type="unfinished">Vous n&apos;avez pas encore sauvegardé l&apos;enregistrement en cours, si vous quittez maintenant il sera perdu.
Êtes-vous sûr de vouloir quitter?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="380"/>
        <source>Hide window</source>
        <translation type="unfinished">Masquer la fenêtre</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="382"/>
        <source>Show window</source>
        <translation type="unfinished">Afficher la fenêtre</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="535"/>
        <source>Starting page ...</source>
        <translation type="unfinished">La page de départ ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="556"/>
        <location filename="../GUI/PageRecord.cpp" line="698"/>
        <location filename="../GUI/PageRecord.cpp" line="783"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation type="unfinished">Erreur: Quelque chose s&apos;est mal passé lors de l&apos;initialisation.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="563"/>
        <source>Started page.</source>
        <translation type="unfinished">La page de démarrage.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="587"/>
        <source>Stopping page ...</source>
        <translation type="unfinished">Arrêt de la page ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="612"/>
        <source>Stopped page.</source>
        <translation type="unfinished">Page arrêtée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="637"/>
        <source>Starting output ...</source>
        <translation type="unfinished">Démarrage de la sortie ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="648"/>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir la taille de l&apos;application OpenGL parce que l&apos;entrée de GLInject n&apos;a pas été créée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="653"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation type="unfinished">Erreur: Impossible d&apos;obtenir la taille de l&apos;application OpenGL. Soit l&apos;application n&apos;a pas démarré correctement, ou l&apos;application n&apos;a pas encore créé une fenêtre OpenGL. Si vous voulez commencer l&apos;enregistrement avant de démarrer l&apos;application, vous devez activer l&apos;échelle et entrez la taille de la vidéo manuellement.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="689"/>
        <source>Started output.</source>
        <translation type="unfinished">Sortie démarrée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="709"/>
        <source>Stopping output ...</source>
        <translation type="unfinished">Arrêt de la sortie ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="727"/>
        <source>Stopped output.</source>
        <translation type="unfinished">Sortie arrêtée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="754"/>
        <source>Starting input ...</source>
        <translation type="unfinished">Démarrage de l&apos;entrée ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="759"/>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation type="unfinished">Erreur: Impossible de démarrer l&apos;entrée de GLInject parce qu&apos;elle n&apos;a pas été créée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="778"/>
        <source>Started input.</source>
        <translation type="unfinished">Entrée démarrée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="803"/>
        <source>Stopping input ...</source>
        <translation type="unfinished">Arrêt de l&apos;entrée ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="814"/>
        <source>Stopped input.</source>
        <translation type="unfinished">Entrée arrêtée.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="830"/>
        <source>Encoding remaining data ...</source>
        <translation type="unfinished">Coder des données restantes ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="901"/>
        <location filename="../GUI/PageRecord.cpp" line="912"/>
        <source>Pause recording</source>
        <translation type="unfinished">Suspendre l&apos;enregistrement</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="905"/>
        <location filename="../GUI/PageRecord.cpp" line="915"/>
        <source>Start recording</source>
        <translation type="unfinished">Démarrer l&apos;enregistrement</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="923"/>
        <source>Stop preview</source>
        <translation type="unfinished">Arrêter l&apos;aperçu</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="926"/>
        <source>Start preview</source>
        <translation type="unfinished">Démarrer l&apos;aperçu</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="955"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation type="unfinished">Erreur: Quelque chose s&apos;est mal passé lors de la création du synthé.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="995"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation type="unfinished">Êtes-vous sûr de vouloir annuler cet enregistrement?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="1010"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation type="unfinished">Vous n&apos;avez rien enregistré, il n&apos;y a rien à sauver.

Le bouton de démarrage est en haut;).</translation>
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
        <translation type="unfinished">&lt;p&gt;Bienvenue sur SimpleScreenRecorder!&lt;/p&gt;&gt;

&lt;p&gt;Malgré son nom ce programme possède de fait de nombreuses options, Cependant ne vous inquiétez pas, il n&apos;y a que deux choses que vous devez connaître. Un, les paramètres par défaut sont généralement parfaits. Si vous ne savez pas ce que quelque chose fait, il suffit d&apos;utiliser les valeurs par défaut. Deux, pratiquement tous les paramètres possèdent des infobulles. Il suffit de passer la souris sur le paramètre pour savoir ce qu&apos;il fait.&lt;/p&gt;

&lt;p&gt;Pour plus d&apos;information:&lt;br&gt;
%1&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="44"/>
        <source>About SimpleScreenRecorder</source>
        <translation type="unfinished">À propos de SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="45"/>
        <source>Continue</source>
        <translation type="unfinished">Continuer</translation>
    </message>
</context>
<context>
    <name>ProfileBox</name>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="28"/>
        <source>Profile</source>
        <translation type="unfinished">Profile</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="37"/>
        <source>Save</source>
        <translation type="unfinished">Enregistrer</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="38"/>
        <source>Save the current settings to this profile.</source>
        <translation type="unfinished">Enregistrer les paramètres courants dans ce profil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="39"/>
        <source>New</source>
        <translation type="unfinished">Nouveau</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="40"/>
        <source>Create a new profile with the current settings.</source>
        <translation type="unfinished">Créer un nouveau profil avec les paramètres actuels.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="41"/>
        <source>Delete</source>
        <translation type="unfinished">Effacer</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="42"/>
        <source>Delete this profile.</source>
        <translation type="unfinished">Effacer ce profil.</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="96"/>
        <source>(none)</source>
        <translation type="unfinished">(aucun)</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="139"/>
        <source>Error: Can&apos;t load profile!</source>
        <translation type="unfinished">Erreur: Impossible de charger le profile!</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="147"/>
        <source>Are you sure that you want to overwrite this profile?</source>
        <translation type="unfinished">Êtes-vous sûr que de vouloir écraser ce profil?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="159"/>
        <source>Enter a name for the new profile:</source>
        <translation type="unfinished">Entrez un nom pour le nouveau profil:</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="165"/>
        <source>A profile with the same name already exists. Are you sure that you want to replace it?</source>
        <translation type="unfinished">Un profil de même nom existe déjà. Êtes-vous sûr que de vouloir le remplacer?</translation>
    </message>
    <message>
        <location filename="../GUI/ProfileBox.cpp" line="181"/>
        <source>Are you sure that you want to delete this profile?</source>
        <translation type="unfinished">Êtes-vous sûr que de vouloir supprimer ce profil?</translation>
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
        <translation type="unfinished">&amp;Annuler</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="37"/>
        <source>&amp;Yes</source>
        <translation type="unfinished">&amp;Oui</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="38"/>
        <source>Yes, always</source>
        <translation type="unfinished">Oui, toujours</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="39"/>
        <source>&amp;No</source>
        <translation type="unfinished">&amp;Non</translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="40"/>
        <source>No, never</source>
        <translation type="unfinished">Non, jamais</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="50"/>
        <source>Synchronization Diagram</source>
        <translation type="unfinished">Diagramme de synchronisation</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="251"/>
        <source>Video in</source>
        <translation type="unfinished">Entrée vidéo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="252"/>
        <source>Audio in</source>
        <translation type="unfinished">Entrée audio</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="253"/>
        <source>Video out</source>
        <translation type="unfinished">Sortie vidéo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="254"/>
        <source>Audio out</source>
        <translation type="unfinished">Sortie audio</translation>
    </message>
</context>
</TS>
