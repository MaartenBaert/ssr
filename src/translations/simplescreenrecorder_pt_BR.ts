<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="pt_BR">
<context>
    <name>DialogAbout</name>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="80"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Sobre o SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="89"/>
        <source>For more information:</source>
        <translation>Para mais informações:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="90"/>
        <source>The source code of this program can be found at:</source>
        <translation>O código fonte deste programa pode ser achado em:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="91"/>
        <source>This program uses:</source>
        <translation>Este programa usa:</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="92"/>
        <source>%1 for the graphical user interface</source>
        <translation>%1 para a interface gráfica de usuário</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="93"/>
        <source>%1 or %2 (depending on your distribution) for video/audio encoding</source>
        <translation>%1 ou %2 (dependendo da sua distribuição) para codificação de vídeo/áudio</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="94"/>
        <source>%1 for hooking system functions for OpenGL recording</source>
        <translation>%1 para unir as funções do sistema para gravação de OpenGL</translation>
    </message>
</context>
<context>
    <name>DialogGLInject</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="786"/>
        <source>OpenGL Settings</source>
        <translation>Configurações do OpenGL</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="789"/>
        <source>&lt;p&gt;Warning: OpenGL recording works by injecting a library into the program that will be recorded. This library will override some system functions in order to capture the frames before they are displayed on the screen. If you are trying to record a game that tries to detect hacking attempts on the client side, it&apos;s (theoretically) possible that the game will consider this a hack. This might even get you banned, so it&apos;s a good idea to make sure that the program you want to record won&apos;t ban you, *before* you try to record it. You&apos;ve been warned :).&lt;/p&gt;

&lt;p&gt;Another warning: OpenGL recording is experimental, it may not work or even crash the program you are recording. If you are worried about losing program data, make a backup first!&lt;/p&gt;

&lt;p&gt;If you want to record Steam games, &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt;read this first&lt;/a&gt;.&lt;/p&gt;</source>
        <translation>&lt;p&gt; Aviso: a gravação do OpenGL funciona inserindo uma biblioteca no programa que será gravado. Esta biblioteca vai substituir algumas funções do sistema, a fim de capturar os quadros antes de serem mostrados no vídeo. Se você está tentando gravar um jogo que tenta detectar tentativas de invasão no lado do cliente, é (teoricamente) possível que o jogo vai considerar isso uma invasão. Isso pode até ter proibido e você ser banido, por isso é uma boa ideia se certificar de que o programa que você deseja gravar não vai bani-lo, * antes * de tentar gravá-lo. Você foi avisado :). &lt;/ P&gt;

&lt;p&gt; Outro aviso: A gravação OpenGL é experimental, ela pode não funcionar ou até mesmo travar o programa que você está gravando. Se você está preocupado com a perda de dados do programa, faça um backup primeiro! &lt;/ P&gt;

&lt;p&gt; Se você quer gravar jogos Steam (da Valve), &lt;a href=&quot;http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/&quot;&gt; leia isto primeiro &lt;/ a&gt;. &lt;/ p&gt;
</translation>
    </message>
    <message>
        <source>Launch application</source>
        <translation type="obsolete">Inicie o aplicativo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="802"/>
        <source>Command:</source>
        <translation>Comando:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="804"/>
        <source>This command will be executed to start the program that should be recorded.</source>
        <translation>Este comando será executado para iniciar o programa que deve ser gravado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="806"/>
        <source>Working directory:</source>
        <translation>Diretório de trabalho:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="808"/>
        <source>The command will be executed in this directory. If you leave this empty, the working directory won&apos;t be changed.</source>
        <translation>O comando será executado neste diretório. Se você deixar esse campo vazio, o diretório de trabalho não será alterado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="810"/>
        <source>Start the OpenGL application automatically</source>
        <translation>Inicie o aplicativo OpenGL automaticamente</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="811"/>
        <source>If checked, the above command will be executed automatically (combined with some environment variables). If not checked,
you have to start the OpenGL application yourself (the full command, including the required environment variables, is shown in the log).</source>
        <translation>Se selecionado, o comando acima será executado automaticamente (combinado com algumas variáveis ​​de ambiente). Se não estiver selecionado, você tem que iniciar o aplicativo OpenGL (o comando completo, incluindo as variáveis ​​de ambiente necessárias, é mostrado no log).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="814"/>
        <source>Relax shared memory permissions (insecure)</source>
        <translation>Relaxe as permissões de memória compartilhada (inseguro)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="815"/>
        <source>If checked, other users on the same machine will be able to attach to the shared memory that&apos;s used for communication with the OpenGL program.
This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.
This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user.</source>
        <translation>Se estiver marcado, outros usuários na mesma máquina serão capazes de se anexar na memória compartilhada que é usada para a comunicação com o programa OpenGL.
Isso significa que outros usuários podem (teoricamente) ver o que você está gravando, modificar os quadros, inserir seus próprios quadros, ou simplesmente interromper a comunicação.
Isto se aplica até aos usuários que estão conectados remotamente (ssh). Você só deve permitir que isso se você precisa gravar um programa que é executado como um usuário diferente.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="819"/>
        <source>Maximum image size (megapixels):</source>
        <translation>Tamanho máximo da imagem (megapixels):</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="821"/>
        <source>This setting changes the amount of shared memory that will be allocated to send frames back to the main program.
The size of the shared memory can&apos;t be changed anymore once the program has been started, so if the program you
are trying to record is too large, recording won&apos;t work. 2 megapixels should be enough in almost all cases. Be careful,
high values will use a lot of memory!</source>
        <translation>Esta configuração altera a quantidade de memória compartilhada que será destinada para enviar quadros de volta para o programa principal.
O tamanho da memória compartilhada não pode mais ser alterada assim que o programa foi iniciado, por isso, se o programa que você estiver tentando gravar é muito grande, a gravação não irá funcionar. 2 megapixels deve ser suficiente na maioria dos casos. Tenha cuidado, valores elevados usarão muita memória!</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="825"/>
        <source>Capture front buffer instead of back buffer</source>
        <translation>Captura de buffer frontal em vez de buffer de fundo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="826"/>
        <source>If checked, the injected library will read the front buffer (the frame that&apos;s currently on the screen) rather than the back buffer
(the new frame). This may be useful for some special applications that draw directly to the screen.</source>
        <translation>Se selecionado, a biblioteca inserida vai ler o buffer frontal (o quadro que está atualmente na tela), em vez do buffer de fundo (o novo quadro). Isto pode ser útil para alguns aplicativos especiais, que desenham diretamente na tela.</translation>
    </message>
    <message>
        <source>Launch automatically</source>
        <translation type="obsolete">Iniciar automaticamente</translation>
    </message>
    <message>
        <source>If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually.</source>
        <translation type="obsolete">Se estiver marcado, o aplicativo será iniciado automaticamente quando você for para a página de gravação. Se não estiver marcado, você tem que iniciá-lo manualmente.</translation>
    </message>
    <message>
        <source>Launch now</source>
        <translation type="obsolete">Iniciar agora</translation>
    </message>
    <message>
        <source>Select stream</source>
        <translation type="obsolete">Selecione o fluxo</translation>
    </message>
    <message>
        <source>Active streams:</source>
        <translation type="obsolete">Fluxos ativos:</translation>
    </message>
    <message>
        <source>Record the latest stream that matches:</source>
        <translation type="obsolete">Grave a último fluxo que corresponde a:</translation>
    </message>
    <message>
        <source>User:</source>
        <translation type="obsolete">Usuário:</translation>
    </message>
    <message>
        <source>Process:</source>
        <translation type="obsolete">Processo:</translation>
    </message>
    <message>
        <source>Source:</source>
        <translation type="obsolete">Fonte:</translation>
    </message>
    <message>
        <source>Program name:</source>
        <translation type="obsolete">Nome do programa:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="829"/>
        <source>Limit application frame rate</source>
        <translation>Limite a taxa de quadros do aplicativo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="830"/>
        <source>If checked, the injected library will slow down the application so the frame rate doesn&apos;t become higher than the recording frame rate.
This stops the application from wasting CPU time for frames that won&apos;t be recorded, and sometimes results in smoother video
(this depends on the application).</source>
        <translation>Se estiver marcado, a biblioteca inserida vai diminuir a velocidade do aplicativo para que a taxa de quadros não se torne maior do que a taxa de quadros da gravação.
Isso evita que o aplicativo desperdiçe tempo de CPU para os quadros que não serão gravados, e às vezes resulta em um vídeo mais suave (isso depende do aplicativo).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="835"/>
        <source>Close</source>
        <translation>Fecha</translation>
    </message>
</context>
<context>
    <name>PageDone</name>
    <message>
        <location filename="../GUI/PageDone.cpp" line="30"/>
        <source>The recording has been saved. You can edit the video now, or re-encode it with better settings to make the file smaller (the default settings are optimized for quality and speed, not file size).</source>
        <translation>A gravação foi salva. Você pode editar o vídeo agora, ou re-codificá-lo com melhores configurações para tornar o arquivo menor (as configurações padrão são otimizados para a qualidade e velocidade, e não o para o tamanho do arquivo).</translation>
    </message>
    <message>
        <location filename="../GUI/PageDone.cpp" line="33"/>
        <source>Back to the start screen</source>
        <translation>Voltar à tela inicial</translation>
    </message>
</context>
<context>
    <name>PageInput</name>
    <message>
        <location filename="../GUI/PageInput.cpp" line="78"/>
        <source>Video input</source>
        <translation>Entrada de vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="81"/>
        <source>Record the entire screen</source>
        <translation>Grave a tela toda</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="82"/>
        <source>Record a fixed rectangle</source>
        <translation>Grave um retângulo fixo</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="83"/>
        <source>Follow the cursor</source>
        <translation>Siga o cursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="84"/>
        <source>Record OpenGL (experimental)</source>
        <translation>Grave OpenGL (experimental)</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="90"/>
        <source>Select what monitor should be recorded in a multi-monitor configuration.</source>
        <translation>Selecione qual o monitor deve ser gravado numa configuração multi monitor.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="91"/>
        <source>Select rectangle...</source>
        <translation>Selecione um retângulo...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="92"/>
        <source>Use the mouse to select the recorded rectangle.</source>
        <translation>Ume o mouse para selecionar o retângulo gravado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="93"/>
        <source>Select window...</source>
        <translation>Selecione uma janela...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="94"/>
        <source>Use the mouse to select a window to record.
Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only
the client area of the window will be recorded.</source>
        <translation>Use o mouse para selecionar uma janela para gravar.
Dica: Se você clicar na borda de uma janela, a janela inteira será gravada (incluindo as bordas). Caso contrário, só a área de cliente da janela será gravada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="97"/>
        <source>OpenGL settings...</source>
        <translation>Configurações do OpenGL ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="98"/>
        <source>Change the settings for OpenGL recording.</source>
        <translation>Altere as configurações para gravação OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="99"/>
        <source>Left:</source>
        <translation>Esquerda:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="103"/>
        <source>The x coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A coordenada x do canto superior esquerdo do retângulo gravado.
Dica: Você também pode alterar esse valor com a roda de rolagem do mouse ou com as setas para cima / para baixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="105"/>
        <source>Top:</source>
        <translation>Topo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="109"/>
        <source>The y coordinate of the upper-left corner of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A coordenada y do canto superior esquerdo do retângulo gravado.
Dica: Você também pode alterar esse valor com a roda de rolagem do mouse ou com as setas para cima / para baixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="111"/>
        <source>Width:</source>
        <translation>Largura:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="115"/>
        <source>The width of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A largura do retângulo gravado.
Dica: Você também pode alterar esse valor com a roda de rolagem do mouse ou com as setas para cima / para baixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="117"/>
        <source>Height:</source>
        <translation>Altura:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="121"/>
        <source>The height of the recorded rectangle.
Hint: You can also change this value with the scroll wheel or the up/down arrows.</source>
        <translation>A altura do retângulo gravado.
Dica: Você também pode alterar esse valor com a roda de rolagem do mouse ou com as setas para cima / para baixo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="123"/>
        <source>Frame rate:</source>
        <translation>Taxa de quadros:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="127"/>
        <source>The number of frames per second in the final video. Higher frame rates use more CPU time.</source>
        <translation>O número de quadros por segundo no vídeo final. Taxas de quadros mais altas usam mais tempo de CPU.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="128"/>
        <source>Scale video</source>
        <translation>Video em escala</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="129"/>
        <source>Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster.</source>
        <translation>Ativar ou desativar a escala. Escala usa mais tempo de CPU, mas se o vídeo é dimensionado menor, a codificação pode ficar mais rápida.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="130"/>
        <source>Scaled width:</source>
        <translation>Largura em escala:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="134"/>
        <source>Scaled height:</source>
        <translation>Altura em escala:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="138"/>
        <source>Record cursor</source>
        <translation>Grave o cursor</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="208"/>
        <source>Audio input</source>
        <translation>Entrada de áudio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="210"/>
        <source>Record audio</source>
        <translation>Grave o áudio</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="211"/>
        <source>Backend:</source>
        <translation>Backend:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="220"/>
        <source>The audio backend that will be used for recording.
The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly.</source>
        <translation>O backend de áudio que vai ser utilizado para a gravação.
O backend ALSA (Advanced Linux Sound Architecture) também irá trabalhar em sistemas que usam PulseAudio, mas é melhor usar o backend PulseAudio diretamente.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="222"/>
        <source>Device:</source>
        <translation>Dispositivo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="224"/>
        <source>The ALSA device that will be used for recording. Normally this should be &apos;default&apos;.
You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).</source>
        <comment>Don&apos;t translate &apos;default&apos; and &apos;plughw&apos;</comment>
        <translation>O dispositivo ALSA (Advanced Linux Sound Architecture) que será utilizado para gravação. Normalmente deixe no &apos;default&apos; (padrão).
Você pode mudar isso para algo como plughw: 0,0 (o que significa placa de som 0 entrada 0 com plugins ativado).</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="227"/>
        <source>Source:</source>
        <translation>Fonte:</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="230"/>
        <source>The PulseAudio source that will be used for recording.
A &apos;monitor&apos; is a source that records the audio played by other applications.</source>
        <comment>Don&apos;t translate &apos;monitor&apos; unless PulseAudio does this as well</comment>
        <translation>A fonte PulseAudio que será utilizada para gravação.
O &apos;monitor&apos; é uma fonte que grava o áudio reproduzido por outros aplicativos.
</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="232"/>
        <source>Refresh</source>
        <translation>Atualiza</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="233"/>
        <source>Refreshes the list of PulseAudio sources.</source>
        <translation>Atualiza a lista de fontes do PulseAudio.</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="258"/>
        <source>Back</source>
        <translation>Volta</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="259"/>
        <source>Continue</source>
        <translation>Continua</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="577"/>
        <source>All screens: %1x%2</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Todas as telas: %1x%2</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="581"/>
        <source>Screen %1: %2x%3 at %4,%5</source>
        <comment>This appears in the screen selection combobox</comment>
        <translation>Tela %1: %2x%3 em %4,%5</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="723"/>
        <source>Screen %1</source>
        <comment>This appears in the screen labels</comment>
        <translation>Tela %1</translation>
    </message>
    <message>
        <location filename="../GUI/PageInput.cpp" line="755"/>
        <source>You did not enter a command to start the OpenGL application that you want to record.
Click the &apos;OpenGL settings&apos; button and enter a command.</source>
        <translation>Você não entrou com um comando para iniciar o aplicativo OpenGL que você deseja gravar.
Clique no botão ‘Configurações do OpenGL’ e digite um comando.</translation>
    </message>
</context>
<context>
    <name>PageOutput</name>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="59"/>
        <location filename="../GUI/PageOutput.cpp" line="62"/>
        <location filename="../GUI/PageOutput.cpp" line="65"/>
        <location filename="../GUI/PageOutput.cpp" line="68"/>
        <location filename="../GUI/PageOutput.cpp" line="104"/>
        <source>files</source>
        <comment>This appears in the file dialog, e.g. &apos;MP4 files&apos;</comment>
        <translation>arquivos</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="71"/>
        <location filename="../GUI/PageOutput.cpp" line="77"/>
        <location filename="../GUI/PageOutput.cpp" line="84"/>
        <source>Other...</source>
        <translation>Outro...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="83"/>
        <source>Uncompressed</source>
        <translation>Sem compressão</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="138"/>
        <source>Error: Could not find any suitable container in libavformat!</source>
        <translation>Erro: Não foi possível encontrar nenhum recipiente adequado na libavformat!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="142"/>
        <source>Error: Could not find any suitable video codec in libavcodec!</source>
        <translation>Erro: Não foi possível encontrar qualquer codec de vídeo adequado na libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="146"/>
        <source>Error: Could not find any suitable audio codec in libavcodec!</source>
        <translation>Erro: Não foi possível encontrar nenhum codec de áudio adequado na libavcodec!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="150"/>
        <source>File</source>
        <translation>Arquivo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="152"/>
        <source>Save as:</source>
        <translation>Grave como:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="154"/>
        <source>The recording will be saved to this location.</source>
        <translation>A gravação será salva neste local.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="155"/>
        <source>Browse...</source>
        <translation>Procure...</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="156"/>
        <source>Separate file per segment</source>
        <translation>Arquivo separado por segmento</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="157"/>
        <source>If checked, a separate video file will be created every time you pause and resume the recording.
If the original file name is &apos;test.mkv&apos;, the segments will be saved as &apos;test-0001.mkv&apos;, &apos;test-0002.mkv&apos;, ...
File names that exist already will be skipped.</source>
        <translation>Se selecionado, um arquivo de vídeo em separado será criado toda vez que você interromper e retomar a gravação.
Se o nome do arquivo original é &quot;test.mkv &apos;, os segmentos serão salvas como&apos; test-0001.mkv &apos;,&apos; test-0002.mkv &apos;, ...
Os nomes de arquivos que já existem serão pulados.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="160"/>
        <source>Container:</source>
        <translation>Recipiente:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="168"/>
        <source>The container (file format) that will be used to save the recording.
Note that not all codecs are supported by all containers, and that not all media players can read all file formats.
- Matroska (MKV) supports all the codecs, but is less well-known.
- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video
   (and many media players only support AAC audio).
- WebM is intended for embedding video into websites (with the HTML5 &lt;video&gt; tag). The format was created by Google.
   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.
   It supports only VP8 and Vorbis.
- OGG supports only Theora and Vorbis.</source>
        <translation>O recipiente (formato de arquivo) que será usado para guardar a gravação.
Note que nem todos os codecs são suportados por todos os recipientes, e que nem todos os players de mídia pode ler todos os formatos de arquivo.
- Matroska (MKV) suporta todos os codecs, mas é menos conhecido.
- MP4 é o formato mais conhecido e vai tocar em praticamente qualquer media player moderno, mas só suporta vídeo H.264 (e muitos players de mídia suportam apenas áudio AAC).
- WebM destina-se a incorporação de vídeo em sites (com o tag &lt;video&gt; do HTML5). O formato foi criado pelo Google.
    WebM é suportado por padrão no Firefox, Chrome e Opera, e plugins estão disponíveis para o Internet Explorer e Safari.
    Ele suporta apenas VP8 e Vorbis.
- OGG suporta apenas Theora e Vorbis.
</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="177"/>
        <source>Container name:</source>
        <translation>Nome do recipiente:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="183"/>
        <source>For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.</source>
        <translation>Para usuários avançados. Você pode usar qualquer formato libav/ffmpeg, mas muitos deles não são úteis ou podem não funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="199"/>
        <source>Video</source>
        <translation>Vídeo</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="201"/>
        <location filename="../GUI/PageOutput.cpp" line="281"/>
        <source>Codec:</source>
        <translation>Codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="206"/>
        <source>The codec that will be used to compress the video stream.
- H.264 (libx264) is by far the best codec - high quality and very fast.
- VP8 (libvpx) is quite good but also quite slow.
- Theora (libtheora) isn&apos;t really recommended because the quality isn&apos;t very good.</source>
        <translation>O codec que vai ser usado para comprimir o fluxo de vídeo.
- H.264 (libx264) é de longe o melhor codec - de alta qualidade e muito rápido.
- VP8 (libvpx) é muito bom, mas também muito lento.
- Theora (libtheora) não é muito recomendado porque a qualidade não é muito boa.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="210"/>
        <location filename="../GUI/PageOutput.cpp" line="294"/>
        <source>Codec name:</source>
        <translation>Nome do codec:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="216"/>
        <source>For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.</source>
        <translation>Para usuários avançados. Você pode usar qualquer codec de vídeo libav/ffmpeg, mas muitos deles não são úteis ou podem não funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="217"/>
        <location filename="../GUI/PageOutput.cpp" line="301"/>
        <source>Bit rate (in kbps):</source>
        <translation>Taxa de bits (em kbps):</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="219"/>
        <source>The video bit rate (in kilobit per second). A higher value means a higher quality.
If you have no idea where to start, try 5000 and change it if needed.</source>
        <translation>A taxa de bits de vídeo (em kilobits por segundo). Um valor mais alto significa maior qualidade.
Se você não tem ideia por onde começar, tente 5000 e mude se necessário.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="221"/>
        <source>Constant rate factor:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Constant rate factor:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="226"/>
        <source>This setting changes the video quality. A lower value means a higher quality.
The allowed range is 0-51 (0 means lossless, the default is 23).</source>
        <translation>Essa configuração altera a qualidade do vídeo. Um valor mais baixo significa maior qualidade.
O intervalo permitido é 0-51 (0 significa sem perdas, o padrão é 23).</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="232"/>
        <source>Preset:</source>
        <comment>libx264 setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>Preset:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="237"/>
        <source>The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),
but results in larger files. The quality shouldn&apos;t be affected too much.</source>
        <translation>A velocidade de codificação. A velocidade mais alta usa menos CPU (tornando possível taxas de quadros de gravação mais altas), mas resulta em arquivos maiores. A qualidade não muda muito.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="239"/>
        <source>CPU used:</source>
        <comment>libvpx setting: don&apos;t translate this unless you can come up with something sensible</comment>
        <translation>CPU usada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="241"/>
        <source>fastest</source>
        <translation>mais rápido</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="246"/>
        <source>slowest</source>
        <translation>mais lento</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="247"/>
        <source>The encoding speed. A higher value uses *less* CPU time. (I didn&apos;t choose the name, this is the name
used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.</source>
        <translation>A velocidade de codificação. Um valor mais alto usa *menos* tempo de CPU. (Eu não escolhi o nome, este é o nome utilizado pelo codificador VP8). Valores mais altos resultam em vídeos de qualidade inferior, a menos que você aumente a taxa de bits também.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="249"/>
        <location filename="../GUI/PageOutput.cpp" line="304"/>
        <source>Custom options:</source>
        <translation>Opções personalizadas:</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="251"/>
        <location filename="../GUI/PageOutput.cpp" line="306"/>
        <source>Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)</source>
        <translation>Opções de codec personalizadas separadas por vírgula (por exemplo opção1 = valor1, opção2 = valor2, opção3 = valor3)</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="252"/>
        <source>Allow frame skipping</source>
        <translation>Permite pular quadro</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="253"/>
        <source>If checked, the video encoder will be allowed to skip frames if the input frame rate is
lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.
This increases the file size and CPU usage, but reduces the latency for live streams in some cases.
It shouldn&apos;t affect the appearance of the video.</source>
        <translation>Se marcada, o codificador de vídeo permitirá pular quadros se a taxa de quadros de entrada é menor do que a taxa de quadros de saída. Se não estiver marcada, quadros de entrada será duplicada para preencher os buracos.
Isso aumenta o tamanho do arquivo e uso de CPU, mas reduz a latência para transmissões ao vivo em alguns casos.
Não deve afetar a aparência do vídeo.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="279"/>
        <source>Audio</source>
        <translation>Áudio</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="286"/>
        <source>The codec that will be used to compress the audio stream. You shouldn&apos;t worry too much about
this, because the size of the audio data is usually negligible compared to the size of the video data.
And if you&apos;re only recording your own voice (i.e. no music), the quality won&apos;t matter that much anyway.
- Vorbis (libvorbis) is great, this is the recommended codec.
- MP3 (libmp3lame) is reasonably good.
- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)
   are pretty bad. Only use it if you have no other choice.
- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it&apos;s very fast.</source>
        <translation>O codec que vai ser usado para comprimir o fluxo de áudio. Você não deve se preocupar muito com isto, porque o tamanho dos dados de áudio é usualmente desprezível em comparação com o tamanho dos dados de vídeo.
E se você só está gravando a sua própria voz (ou seja, sem música), a qualidade não vai importar tanto assim de qualquer maneira.
- Vorbis (libvorbis) é ótimo, este é o codec recomendado.
- MP3 (libmp3lame) é razoavelmente bom.
- AAC é um bom codec, mas as implementações usadas aqui (libvo_aacenc ou o experimental ffmpeg aac encoder) são muito ruins. Use somente se você não tem outra escolha.
- Sem compressão simplesmente armazena os dados de som sem compactá-lo. O arquivo vai ser muito grande, mas é muito rápido.
</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="300"/>
        <source>For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.</source>
        <translation>Para usuários avançados. Você pode usar qualquer codec de áudio libav/ffmpeg, mas muitos deles não são úteis ou podem não funcionar.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="303"/>
        <source>The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.</source>
        <translation>A taxa de bits de áudio (em kilobits por segundo). Um valor mais alto significa  maior qualidade. O valor típico é de 128.</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="320"/>
        <source>Back</source>
        <translation>Volta</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="321"/>
        <source>Continue</source>
        <translation>Continua</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="547"/>
        <location filename="../GUI/PageOutput.cpp" line="555"/>
        <source>not installed</source>
        <translation>não instalado</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="549"/>
        <location filename="../GUI/PageOutput.cpp" line="557"/>
        <source>not supported by container</source>
        <translation>não suportado pelo recipiente</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="600"/>
        <source>Save recording as</source>
        <translation>Salve a gravação como</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="640"/>
        <source>You did not select an output file!</source>
        <translation>Você não selecionou um arquivo de saída!</translation>
    </message>
    <message>
        <location filename="../GUI/PageOutput.cpp" line="645"/>
        <source>The file &apos;%1&apos; already exists. Are you sure that you want to overwrite it?</source>
        <translation>O arquivo &apos;% 1&apos; já existe. Você tem certeza que quer substituí-lo?</translation>
    </message>
</context>
<context>
    <name>PageRecord</name>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="147"/>
        <source>Recording</source>
        <translation>Gravando</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="151"/>
        <source>Enable recording hotkey</source>
        <translation>Habilita hotkey de gravação</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="152"/>
        <source>Enable sound notifications</source>
        <translation>Habilita sons de notificações</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="153"/>
        <source>Hotkey:</source>
        <translation>Hotkey:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="154"/>
        <source>Ctrl +</source>
        <translation>Ctrl +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="155"/>
        <source>Shift +</source>
        <translation>Shift +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="156"/>
        <source>Alt +</source>
        <translation>Alt +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="157"/>
        <source>Super +</source>
        <translation>Super +</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="159"/>
        <source>The key that you have to press (combined with the given modifiers) to start or pause recording.
The program that you are recording will not receive the key press.</source>
        <translation>A tecla que você tem que apertar (combinada com os modificadores de dados) para iniciar ou pausar a gravação.
O programa que você está gravando não receberá a tecla pressionada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="199"/>
        <source>Information</source>
        <translation>Informação</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="201"/>
        <source>Total time:</source>
        <translation>Tempo total:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="203"/>
        <source>FPS in:</source>
        <translation>FPS de entrada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="205"/>
        <source>FPS out:</source>
        <translation>FPS de saída:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="207"/>
        <source>Size in:</source>
        <translation>Tamanho de entrada:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="209"/>
        <source>Size out:</source>
        <translation>Tamanho de saída:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="211"/>
        <source>File name:</source>
        <translation>Nome do arquivo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="214"/>
        <source>File size:</source>
        <translation>Tamanho do arquivo:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="216"/>
        <source>Bit rate:</source>
        <translation>Taxa de bits:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="239"/>
        <source>Preview</source>
        <translation>Pré-visualização</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="243"/>
        <source>Preview frame rate:</source>
        <translation>Pré-visualização da taxa de quadros:</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="247"/>
        <source>Note: Previewing requires extra CPU time (especially at high frame rates).</source>
        <translation>Nota: A pré-visualização requer tempo extra de CPU (especialmente com altas taxas de quadros).</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="296"/>
        <source>Log</source>
        <translation>Log</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="311"/>
        <location filename="../GUI/PageRecord.cpp" line="319"/>
        <source>Cancel recording</source>
        <translation>Cancela a gravação</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="312"/>
        <location filename="../GUI/PageRecord.cpp" line="318"/>
        <source>Save recording</source>
        <translation>Salve a gravação</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="366"/>
        <source>You have not saved the current recording yet, if you quit now it will be lost.
Are you sure that you want to quit?</source>
        <translation>Você ainda não salvou a gravação atual, se você desistir agora ela será perdida.
Você tem certeza que quer sair?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="518"/>
        <source>Starting page ...</source>
        <translation>Iniciando a página...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="537"/>
        <location filename="../GUI/PageRecord.cpp" line="686"/>
        <location filename="../GUI/PageRecord.cpp" line="773"/>
        <source>Error: Something went wrong during initialization.</source>
        <translation>Erro: Ocorreu um erro durante a inicialização.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="544"/>
        <source>Started page.</source>
        <translation>Página iniciada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="573"/>
        <source>Stopping page ...</source>
        <translation>Parando a página ...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="599"/>
        <source>Stopped page.</source>
        <translation>Página parada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="626"/>
        <source>Starting output ...</source>
        <translation>Iniciando a saída...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="637"/>
        <source>Error: Could not get the size of the OpenGL application because GLInject has not been started.</source>
        <translation>Erro: Não foi possível obter o tamanho do aplicativo OpenGL porque o GLInject não foi iniciado.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="642"/>
        <source>Error: Could not get the size of the OpenGL application. Either the application wasn&apos;t started correctly, or the application hasn&apos;t created an OpenGL window yet. If you want to start recording before starting the application, you have to enable scaling and enter the video size manually.</source>
        <translation>Erro: Não foi possível obter o tamanho do aplicativo OpenGL. Ou o aplicativo não foi iniciado corretamente, ou o aplicativo não criou uma janela OpenGL ainda. Se você quer começar a gravar antes de iniciar o aplicativo, você tem que ativar a escala e digitar o tamanho do vídeo manualmente.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="749"/>
        <source>Error: Could not create a GLInject input because GLInject has not been started.</source>
        <translation>Erro: Não foi possível criar uma entrada GLInject porque o GLInject não foi iniciado.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application because the GLInject input has not been created.</source>
        <translation type="obsolete">Erro: Não foi possível obter o tamanho do aplicativo OpenGL porque a entrada GLInject não foi criada.</translation>
    </message>
    <message>
        <source>Error: Could not get the size of the OpenGL application.</source>
        <translation type="obsolete">Erro: Não foi possível obter o tamanho do aplicativo OpenGL.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="678"/>
        <source>Started output.</source>
        <translation>Saída iniciada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="697"/>
        <source>Stopping output ...</source>
        <translation>Parando a saída...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="715"/>
        <source>Stopped output.</source>
        <translation>Saída parada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="744"/>
        <source>Starting input ...</source>
        <translation>Iniciando a entrada...</translation>
    </message>
    <message>
        <source>Error: Could not start the GLInject input because it has not been created.</source>
        <translation type="obsolete">Erro: Não foi possível iniciar a entrada GLInject porque ela não foi criada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="768"/>
        <source>Started input.</source>
        <translation>Entrada iniciada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="794"/>
        <source>Stopping input ...</source>
        <translation>Parando a entrada...</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="808"/>
        <source>Stopped input.</source>
        <translation>Entrada parada.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="871"/>
        <location filename="../GUI/PageRecord.cpp" line="875"/>
        <source>Pause recording</source>
        <translation>Pause a gravação</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="878"/>
        <location filename="../GUI/PageRecord.cpp" line="882"/>
        <source>Start recording</source>
        <translation>Inicie a gravação</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="891"/>
        <source>Stop preview</source>
        <translation>Pare a pré-visualização</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="894"/>
        <source>Start preview</source>
        <translation>Inicie a pré-visualização</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="928"/>
        <source>Error: Something went wrong while creating the synth.</source>
        <translation>Erro: Ocorreu um erro durante a criação do sintetizador.</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="960"/>
        <source>Are you sure that you want to cancel this recording?</source>
        <translation>Você tem certeza que quer cancelar esta gravação?</translation>
    </message>
    <message>
        <location filename="../GUI/PageRecord.cpp" line="973"/>
        <source>You haven&apos;t recorded anything, there is nothing to save.

The start button is at the top ;).</source>
        <translation>Você não gravou nada, não há nada para salvar.

O botão de iniciar está no topo;).</translation>
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
        <translation>&lt;p&gt; Bem-vindo ao SimpleScreenRecorder! &lt;/ p&gt;

&lt;p&gt; Apesar do nome, este programa realmente tem um monte de opções. Não se preocupe, existem realmente apenas duas coisas que você precisa saber. Um, as configurações padrão são geralmente boas. Se você não sabe o que faz alguma coisa, é só usar o padrão. Dois, quase todas as configurações têm dicas. Basta passar o mouse sobre alguma coisa para descobrir o que ela faz. &lt;/ P&gt;

&lt;p&gt; Para mais informações: &lt;br&gt;
%1 &lt;/ p&gt;</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="46"/>
        <source>About SimpleScreenRecorder</source>
        <translation>Sobre o SimpleScreenRecorder</translation>
    </message>
    <message>
        <location filename="../GUI/PageWelcome.cpp" line="47"/>
        <source>Continue</source>
        <translation>Continue</translation>
    </message>
</context>
<context>
    <name>QMessageBox</name>
    <message>
        <location filename="../common/Dialogs.cpp" line="31"/>
        <source>&amp;Yes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="33"/>
        <source>&amp;No</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../common/Dialogs.cpp" line="35"/>
        <source>&amp;Cancel</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../AV/FastScaler.cpp" line="76"/>
        <source>Warning: Pixel format is not supported (%1 -&gt; %2), using swscale instead. This is not a problem, but performance will be worse.</source>
        <translation>Aviso: formato de pixel não é suportado (%1 -&gt;%2), usando swscale em vez disso. Isto não é um problema, mas o desempenho será pior.</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="85"/>
        <source>Error: Can&apos;t get swscale context!</source>
        <comment>Don&apos;t translate &apos;swscale&apos;</comment>
        <translation>Erro: Não é possível obter o contexto swscale!</translation>
    </message>
    <message>
        <location filename="../AV/FastScaler.cpp" line="104"/>
        <location filename="../AV/FastScaler.cpp" line="127"/>
        <source>Warning: Memory is not properly aligned for SSE, using fallback converter instead. This is not a problem, but performance will be worse.</source>
        <comment>Don&apos;t translate &apos;fallback&apos;</comment>
        <translation>Aviso: A memória não está alinhada corretamente para SSE, usando conversor fallback em vez disso. Isto não é um problema, mas o desempenho será pior.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="32"/>
        <source>Warning: An overrun has occurred, some samples were lost.</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Aviso: Um overrun ocorreu, algumas amostras foram perdidas.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="34"/>
        <source>Error: Can&apos;t recover device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Erro: Não é possível recuperar o dispositivo depois do sobrecarga de dados!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="38"/>
        <source>Error: Can&apos;t start PCM device after overrun!</source>
        <comment>Don&apos;t translate &apos;overrun&apos;</comment>
        <translation>Erro: Não foi possível iniciar o dispositivo PCM após o overrun!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="66"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="55"/>
        <location filename="../AV/Input/X11Input.cpp" line="206"/>
        <source>Stopping input thread ...</source>
        <translation>Parando segmento de entrada ...</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="89"/>
        <location filename="../AV/SimpleSynth.cpp" line="89"/>
        <source>Error: Can&apos;t open PCM device!</source>
        <translation>Erro: Não foi possível abrir o dispositivo de PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="93"/>
        <location filename="../AV/SimpleSynth.cpp" line="93"/>
        <source>Error: Can&apos;t get PCM hardware parameters!</source>
        <translation>Erro: Não foi possível obter parâmetros de hardware PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="99"/>
        <location filename="../AV/SimpleSynth.cpp" line="99"/>
        <source>Error: Can&apos;t set access type!</source>
        <translation>Erro: Não foi possível definir o tipo de acesso!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="105"/>
        <location filename="../AV/SimpleSynth.cpp" line="105"/>
        <source>Error: Can&apos;t set sample format!</source>
        <translation>Erro: Não foi possível definir o formato da amostra!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="112"/>
        <location filename="../AV/SimpleSynth.cpp" line="112"/>
        <source>Error: Can&apos;t set sample rate!</source>
        <translation>Erro: Não foi possível definir a taxa de amostragem!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="116"/>
        <location filename="../AV/SimpleSynth.cpp" line="116"/>
        <source>Warning: Sample rate %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Aviso: Taxa de amostragem %1 não é suportada, usando %2 no lugar. Isto não é um problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="124"/>
        <location filename="../AV/SimpleSynth.cpp" line="124"/>
        <source>Error: Can&apos;t set channel count!</source>
        <translation>Erro: Não foi possível definir o número de canais!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="131"/>
        <location filename="../AV/SimpleSynth.cpp" line="131"/>
        <source>Error: Can&apos;t set period size!</source>
        <translation>Erro: Não foi possível definir o tamanho do período!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="135"/>
        <location filename="../AV/SimpleSynth.cpp" line="135"/>
        <source>Warning: Period size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Aviso: tamanho do período %1 não é suportado, usando %2 no lugar. Isto não é um problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="144"/>
        <location filename="../AV/SimpleSynth.cpp" line="144"/>
        <source>Error: Can&apos;t set buffer size!</source>
        <translation>Erro: Não foi possível definir o tamanho do buffer!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="148"/>
        <location filename="../AV/SimpleSynth.cpp" line="148"/>
        <source>Warning: Buffer size %1 is not supported, using %2 instead. This is not a problem.</source>
        <translation>Atenção: O tamanho do buffer%1 não é suportado, usando %2 no lugar. Isto não é um problema.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="156"/>
        <location filename="../AV/SimpleSynth.cpp" line="156"/>
        <source>Error: Can&apos;t apply PCM hardware parameters!</source>
        <translation>Erro: Não foi possível aplicar parâmetros de hardware PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="174"/>
        <source>Error: Can&apos;t start PCM device!</source>
        <translation>Erro: Não foi possível iniciar o dispositivo PCM!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="195"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="95"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="298"/>
        <location filename="../AV/Input/X11Input.cpp" line="333"/>
        <source>Input thread started.</source>
        <translation>Segmento de entrada iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="215"/>
        <location filename="../AV/SimpleSynth.cpp" line="207"/>
        <source>Error: Can&apos;t check whether samples are available!</source>
        <translation>Erro: Não foi possível verificar se as amostras estão disponíveis!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="228"/>
        <source>Error: Can&apos;t read samples!</source>
        <translation>Erro: Não foi possível ler as amostras!</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="254"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="155"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="387"/>
        <location filename="../AV/Input/X11Input.cpp" line="423"/>
        <source>Input thread stopped.</source>
        <translation>Segmento de entrada parado.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="258"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="159"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="391"/>
        <location filename="../AV/Input/X11Input.cpp" line="427"/>
        <source>Exception &apos;%1&apos; in input thread.</source>
        <translation>Exceção &apos;%1&apos; no segmento de entrada.</translation>
    </message>
    <message>
        <location filename="../AV/Input/ALSAInput.cpp" line="261"/>
        <location filename="../AV/Input/GLInjectInput.cpp" line="162"/>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="394"/>
        <location filename="../AV/Input/X11Input.cpp" line="430"/>
        <source>Unknown exception in input thread.</source>
        <translation>Exceção desconhecida no segmento de entrada.</translation>
    </message>
    <message>
        <source>Error: No streams found!</source>
        <translation type="obsolete">Erro: Nenhum fluxo encontrado!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="35"/>
        <source>Error: pa_mainloop_prepare failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_prepare&apos;</comment>
        <translation>Erro: pa_mainloop_prepare falhou!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="39"/>
        <source>Error: pa_mainloop_poll failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_poll&apos;</comment>
        <translation>Erro: pa_mainloop_poll falhou!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="43"/>
        <source>Error: pa_mainloop_dispatch failed!</source>
        <comment>Don&apos;t translate &apos;pa_mainloop_dispatch&apos;</comment>
        <translation>Erro: pa_mainloop_dispatch falhou!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="53"/>
        <source>Error: Could not create main loop!</source>
        <translation>Erro: Não foi possível criar o loop principal!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="60"/>
        <source>Error: Could not create context!</source>
        <translation>Erro: Não foi possível criar o contexto!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="64"/>
        <source>Error: Could not connect! Reason: %1
It is possible that your system doesn&apos;t use PulseAudio. Try using the ALSA backend instead.</source>
        <translation>Erro: Não foi possível conectar! Motivo:%1
É possível que o seu sistema não use o PulseAudio. Tente usar o backend ALSA em vez disso.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="77"/>
        <source>Error: Connection attempt failed! Reason: %1</source>
        <translation>Erro: Tentativa de conexão falhou! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="114"/>
        <source>Error: Could not create stream! Reason: %1</source>
        <translation>Erro: Não foi possível criar o fluxo! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="121"/>
        <source>Error: Could not connect stream! Reason: %1</source>
        <translation>Erro: Não foi possível criar o fluxo! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="132"/>
        <source>Error: Stream connection attempt failed! Reason: %1</source>
        <translation>Erro: Tentativa de conexão do fluxo falhou! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="244"/>
        <source>Error: Could not get names of sources! Reason: %1</source>
        <translation>Erro: Não foi possível obter os nomes das fontes! Motivo: %1</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="312"/>
        <source>Error: pa_stream_peek failed!</source>
        <comment>Don&apos;t translate &apos;pa_stream_peek&apos;</comment>
        <translation>Erro: pa_stream_peek falhou!</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="375"/>
        <source>Warning: Audio source was suspended. The current segment will be stopped until the source is resumed.</source>
        <translation>Aviso: a fonte de áudio foi suspensa. O segmento atual será interrompido até que a fonte seja retomada.</translation>
    </message>
    <message>
        <location filename="../AV/Input/PulseAudioInput.cpp" line="380"/>
        <source>Warning: Stream was moved to a different source.</source>
        <translation>Aviso: o fluxo foi transferido para uma fonte diferente.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open video stream file!</source>
        <translation type="obsolete">Erro: Não foi possível abrir o arquivo de fluxo de vídeo!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t lock video stream file!</source>
        <translation type="obsolete">Erro: Não foi possível bloquear arquivo de fluxo de vídeo!</translation>
    </message>
    <message>
        <source>Error: Size of video stream file is incorrect!</source>
        <translation type="obsolete">Erro: Tamanho do arquivo fluxo de vídeo está incorreto!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t memory-map video stream file!</source>
        <translation type="obsolete">Erro: Não foi possível mapear a memória do arquivo de fluxo de vídeo!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open video frame file!</source>
        <translation type="obsolete">Erro: Não foi possível  abrir o arquivo de quadros de vídeo!</translation>
    </message>
    <message>
        <source>Error: Size of video frame file is incorrect!</source>
        <translation type="obsolete">Erro: O tamanho do arquivo de quadros de vídeo está incorreto!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t memory-map video frame file!</source>
        <translation type="obsolete">Erro: Não foi possível mapear a memória do arquivo de quadros de vídeo!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t initialize inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Erro: Não foi possível inicializar o inotify!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t watch shared memory directory!</source>
        <translation type="obsolete">Erro: Não foi possível  observar o diretório de memória compartilhada!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t open shared memory directory!</source>
        <translation type="obsolete">Erro: Não foi possível abrir o o diretório de memória compartilhada!</translation>
    </message>
    <message>
        <source>Added pre-existing stream %1.</source>
        <translation type="obsolete">Adicionado fluxo pré-existente %1.</translation>
    </message>
    <message>
        <source>Error: Can&apos;t get read length from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Erro: Não foi possível  ler o comprimento do inotify!</translation>
    </message>
    <message>
        <source>Error: Can&apos;t read from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Erro: Não foi possível ler do inotify!</translation>
    </message>
    <message>
        <source>Error: Received partial event from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Erro: Recebido evento parcial do inotify!</translation>
    </message>
    <message>
        <source>Error: Received partial name from inotify!</source>
        <comment>don&apos;t translate &apos;inotify&apos;</comment>
        <translation type="obsolete">Erro: Recebido nome parcial do inotify!</translation>
    </message>
    <message>
        <source>Added stream %1.</source>
        <translation type="obsolete">Adicionado fluxo %1.</translation>
    </message>
    <message>
        <source>Warning: Tried to add stream %1, but it exists already!</source>
        <translation type="obsolete">Aviso: Tentei adicionar fluxo %1, mas já existe!</translation>
    </message>
    <message>
        <source>Removed stream %1.</source>
        <translation type="obsolete">Fluxo %1 removido.</translation>
    </message>
    <message>
        <source>Warning: Tried to remove stream %1, but it does not exist!</source>
        <translation type="obsolete">Aviso: Tentei remover Fluxo %1, mas não existe!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="74"/>
        <source>Error: Unsupported X11 image pixel format!</source>
        <translation>Erro: Formato X11 de imagem em pixels não suportado!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="185"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="57"/>
        <source>Error: Width or height is zero!</source>
        <translation>Erro: Largura ou altura é zero!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="189"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="61"/>
        <source>Error: Width or height is too large, the maximum width and height is %1!</source>
        <translation>Erro: Largura ou altura é muito grande, a largura máxima e altura é de %1!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="226"/>
        <source>Error: Can&apos;t open X display!</source>
        <comment>Don&apos;t translate &apos;display&apos;</comment>
        <translation>Erro: Não foi possível abrir o display X!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="235"/>
        <source>Using X11 shared memory.</source>
        <translation>Usando memória compartilhada X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="238"/>
        <source>Error: Can&apos;t create shared image!</source>
        <translation>Erro: Não foi possível  criar uma imagem compartilhada!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="103"/>
        <location filename="../AV/Input/X11Input.cpp" line="243"/>
        <source>Error: Can&apos;t get shared memory!</source>
        <translation>Erro: Não foi possível obter memória compartilhada!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="108"/>
        <location filename="../AV/Input/X11Input.cpp" line="248"/>
        <source>Error: Can&apos;t attach to shared memory!</source>
        <translation>Erro: Não foi possível  anexar à memória compartilhada!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="118"/>
        <source>Error: Can&apos;t get frame shared memory!</source>
        <translation>Erro: Não foi possível obter memória compartilhada do quadro!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="123"/>
        <source>Error: Can&apos;t attach to frame shared memory!</source>
        <translation>Erro: Não foi possível anexar à memória compartilhada do quadro!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="150"/>
        <source>Full command</source>
        <translation>Comando completo</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectLauncher.cpp" line="158"/>
        <source>Error: Can&apos;t run command!</source>
        <translation>Erro: Não foi possível executar o comando!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="254"/>
        <source>Not using X11 shared memory.</source>
        <translation>Não usando a memória compartilhada X11.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="262"/>
        <source>Warning: XFixes is not supported by server, the cursor has been hidden.</source>
        <comment>Don&apos;t translate &apos;XFixes&apos;</comment>
        <translation>Aviso: XFixes não é suportado pelo servidor, o cursor foi escondido.</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="317"/>
        <source>Error: Invalid screen bounding box!</source>
        <translation>Erro: Caixa delimitadora de tela inválida!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="373"/>
        <source>Error: Can&apos;t attach server to shared memory!</source>
        <translation>Erro: Não é possível anexar o servidor na memória compartilhada!</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="379"/>
        <source>Error: Can&apos;t get image (using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Erro: Não foi possível  obter uma imagem (usando memória compartilhada)!
     Normalmente isto significa que a área de gravação não está completamente no interior da de tela. Ou você mudou a resolução da tela?</translation>
    </message>
    <message>
        <location filename="../AV/Input/X11Input.cpp" line="390"/>
        <source>Error: Can&apos;t get image (not using shared memory)!
    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?</source>
        <translation>Erro: Não foi possível  obter uma imagem (não usando memória compartilhada)!
     Normalmente isto significa que a área de gravação não está completamente no interior da de tela. Ou você mudou a resolução da tela?</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="45"/>
        <source>Error: Sample rate it zero.</source>
        <translation>Erro: Taxa de amostragem é zero.</translation>
    </message>
    <message>
        <source>Warning: Codec option &apos;%1&apos; was not recognised!</source>
        <translation type="obsolete">Aviso: opção codec &apos;%1&apos; não foi reconhecida!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="126"/>
        <source>Error: Encoder requires an unsupported sample format!</source>
        <translation>Erro: Codificador requer um formato de amostragem não suportado!</translation>
    </message>
    <message>
        <location filename="../AV/Output/AudioEncoder.cpp" line="149"/>
        <location filename="../AV/Output/AudioEncoder.cpp" line="170"/>
        <source>Error: Encoding of audio frame failed!</source>
        <translation>Erro: Codificação do quadro de áudio falhou!</translation>
    </message>
    <message>
        <source>Error: Option &apos;%1&apos; could not be parsed!</source>
        <translation type="obsolete">Erro: Opção &apos;%1&apos; não pôde ser analisada!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="62"/>
        <source>Stopping encoder thread ...</source>
        <translation>Parando segmento do codificador ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="82"/>
        <source>Error: Can&apos;t find codec!</source>
        <translation>Erro: Não foi possível encontrar o codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="87"/>
        <source>Using codec %1 (%2).</source>
        <translation>Usando o codec %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="96"/>
        <source>Warning: This codec is considered experimental by libav/ffmpeg.</source>
        <translation>Aviso: Este o codec é considerado experimental pelo libav/ffmpeg.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="106"/>
        <source>Error: Can&apos;t open codec!</source>
        <translation>Erro: Não foi possível abrir o o codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="160"/>
        <source>Encoder thread started.</source>
        <translation>Segmento do codificador iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="189"/>
        <source>Flushing encoder ...</source>
        <translation>Esvaziando o codificador ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="196"/>
        <source>Encoder thread stopped.</source>
        <translation>Segmento do codificador parado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="200"/>
        <source>Exception &apos;%1&apos; in encoder thread.</source>
        <translation>Exceção &apos;%1&apos; no segmento do codificador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/BaseEncoder.cpp" line="203"/>
        <source>Unknown exception in encoder thread.</source>
        <translation>Exceção desconhecida no segmento do codificador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="72"/>
        <source>Stopping encoders ...</source>
        <translation>Parando codificadores ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="79"/>
        <source>Waiting for muxer thread to stop ...</source>
        <translation>Aguardando o segmento muxer parar ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="100"/>
        <source>Error: Can&apos;t write header!</source>
        <comment>Don&apos;t translate &apos;header&apos;</comment>
        <translation>Erro: Não foi possível gravar o header!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="111"/>
        <source>Finishing encoders ...</source>
        <translation>Finalizando os codificadores ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="143"/>
        <source>Error: Can&apos;t create new stream!</source>
        <translation>Erro: Não foi possível criar um novo fluxo!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="149"/>
        <source>Error: Can&apos;t get codec context defaults!</source>
        <translation>Erro: Não foi possível obter padrões de contexto do codec!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="195"/>
        <source>Error: Can&apos;t find chosen output format!</source>
        <translation>Erro: Não foi possível encontrar o formato de saída escolhido!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="199"/>
        <source>Using format %1 (%2).</source>
        <translation>Usando o formato %1 (%2).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="204"/>
        <source>Error: Can&apos;t allocate format context!</source>
        <translation>Erro: Não foi possível alocar contexto de formato!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="211"/>
        <source>Error: Can&apos;t open output file!</source>
        <translation>Erro: Não foi possível abrir o arquivo de saída!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="224"/>
        <source>Error: Can&apos;t write trailer, continuing anyway.</source>
        <comment>Don&apos;t translate &apos;trailer&apos;</comment>
        <translation>Erro: Não foi possível gravar o trailer, continuando mesmo assim.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="257"/>
        <source>Muxer thread started.</source>
        <translation>Fluxo do segmento do muxer começado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="311"/>
        <source>Error: Can&apos;t write frame to muxer!</source>
        <translation>Erro: Não foi possível gravar quadro para o muxer!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="339"/>
        <source>Muxer thread stopped.</source>
        <translation>Fluxo do segmento muxer parado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="343"/>
        <source>Exception &apos;%1&apos; in muxer thread.</source>
        <translation>Exceção &apos;%1&apos; no segmento muxer.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Muxer.cpp" line="346"/>
        <source>Unknown exception in muxer thread.</source>
        <translation>Exceção desconhecida no segmento muxer.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="119"/>
        <source>Stopping synchronizer thread ...</source>
        <translation>Parando fluxo sincronizador ...</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="237"/>
        <source>Warning: Received video frame with non-monotonic timestamp.</source>
        <translation>Aviso: Quadro de vídeo recebido com carimbo do tempo não-monotônico.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="269"/>
        <source>Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.</source>
        <translation>Aviso: Sobrecarga no buffer de video, alguns quadros serão perdidos. A entrada de áudio parece ser muito lenta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="341"/>
        <source>Warning: Received audio samples with non-monotonic timestamp.</source>
        <translation>Aviso: amostras de áudio recebidas com carimbo do tempo não-monotônico.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="365"/>
        <source>Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost). The video input seems to be too slow.</source>
        <translation>Aviso: Sobrecarga no buffer de áudio, começando novo segmento para manter o áudio em sincronia com o vídeo (algum vídeo e/ou áudio podem ser perdidos). A entrada de vídeo parece ser muito lenta.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="388"/>
        <source>Warning: Desynchronization is too high, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Atenção: A dessincronização é demasiado elevada, iniciando um novo segmento para manter o áudio sincronizado com o vídeo (algum vídeo e/ ou áudio podem ser perdidos).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="398"/>
        <source>Warning: Audio input is more than 5% too slow!</source>
        <translation>Atenção: A entrada de áudio é mais do que 5% muito lenta!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="402"/>
        <source>Warning: Audio input is more than 5% too fast!</source>
        <translation>Atenção: A entrada de áudio é mais do que 5% muito rápida!</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="432"/>
        <source>Warning: Received hole in audio stream, starting new segment to keep the audio in sync with the video (some video and/or audio may be lost).</source>
        <translation>Aviso: Buraco recebido no fluxo de áudio, iniciando um novo segmento para manter o áudio em sincronia com o vídeo (algum vídeo e/ou áudio podem ser perdidos).</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="712"/>
        <source>Synchronizer thread started.</source>
        <translation>Fluxo sincronizador iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="734"/>
        <source>Synchronizer thread stopped.</source>
        <translation>Fluxo sincronizador parado.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="738"/>
        <source>Exception &apos;%1&apos; in synchronizer thread.</source>
        <translation>Exceção &apos;%1&apos; no fluxo sincronizador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="741"/>
        <source>Unknown exception in synchronizer thread.</source>
        <translation>Exceção desconhecida no fluxo do sincronizador.</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="65"/>
        <source>Error: Width or height is not an even number!</source>
        <translation>Erro: Largura ou altura não é um número inteiro!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="69"/>
        <source>Error: Frame rate it zero!</source>
        <translation>Erro: Taxa de quadros é zero!</translation>
    </message>
    <message>
        <location filename="../AV/Output/VideoEncoder.cpp" line="202"/>
        <location filename="../AV/Output/VideoEncoder.cpp" line="222"/>
        <source>Error: Encoding of video frame failed!</source>
        <translation>Erro: Codificação do quadro de vídeo falhou!</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="73"/>
        <source>Error: Flushing resampler failed! Reason: %s</source>
        <translation>Erro: Esvaziamento da nova amostragem falhou! Motivo:%s</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="90"/>
        <source>Resampling from %1 to %2.</source>
        <translation>Nova amostra de %1 para %2.</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="96"/>
        <source>Error: Can&apos;t create resampler! Reason: %s</source>
        <translation>Erro: Não foi possível criar nova amostragem! Motivo: %s</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="100"/>
        <source>Resampling not needed.</source>
        <translation>Nova amostra não é necessária.</translation>
    </message>
    <message>
        <location filename="../AV/Resampler.cpp" line="140"/>
        <source>Error: Resampling failed!</source>
        <translation>Erro: Nova amostra falhou!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="27"/>
        <source>Warning: An underrun has occurred, some samples were too late.</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Aviso: Uma falta de dados ocorreu, algumas amostras chegaram muito tarde.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="29"/>
        <source>Error: Can&apos;t recover device after underrun!</source>
        <comment>Don&apos;t translate &apos;underrun&apos;</comment>
        <translation>Erro: Não foi possível recuperar o dispositivo depois da falta de dados!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="56"/>
        <source>Stopping synth thread ...</source>
        <translation>Parando o fluxo do sintetizador ...</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="189"/>
        <source>Synth thread started.</source>
        <translation>Fluxo do sintetizador iniciado.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="257"/>
        <source>Error: Can&apos;t write samples!</source>
        <translation>Erro: Não foi possível gravar as amostras!</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="265"/>
        <source>Synth thread stopped.</source>
        <translation>Fluxo do sintetizador parado.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="269"/>
        <source>Exception &apos;%1&apos; in synth thread.</source>
        <translation>Exceção &apos;%1&apos; no fluxo do sintetizador.</translation>
    </message>
    <message>
        <location filename="../AV/SimpleSynth.cpp" line="272"/>
        <source>Unknown exception in synth thread.</source>
        <translation>Exceção desconhecida no fluxo do sintetizador.</translation>
    </message>
    <message>
        <location filename="../common/DetectCPUFeatures.cpp" line="39"/>
        <source>CPU features</source>
        <translation>Recursos da CPU</translation>
    </message>
    <message>
        <source>The application could not be launched.</source>
        <translation type="obsolete">O aplicativo não pode iniciar.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="116"/>
        <source>Error: Command-line option &apos;%1&apos; does not take a value!</source>
        <translation>Erro: opção da linha de comando &apos;%1&apos; não tem um valor!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="144"/>
        <source>Error: Unknown command-line option &apos;%1&apos;!</source>
        <translation>Erro: Opção desconhecida na linha de comando &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="154"/>
        <source>Error: Unknown command-line argument &apos;%1&apos;!</source>
        <translation>Erro: Argumento desconhecido na linha de comando &apos;%1&apos;!</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="181"/>
        <source>SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?

You can also change this option manually in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>SimpleScreenRecorder detectou que você está usando o driver proprietário da NVIDIA com a inversão (flipping) habilitada. Isso é conhecido por causar falhas durante a gravação. É recomendável desativar a inversão. Você quer que eu faça isso para você?

Você também pode alterar essa opção manualmente no painel de controle da NVIDIA.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="186"/>
        <source>I couldn&apos;t disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.</source>
        <comment>Don&apos;t translate &apos;flipping&apos; unless NVIDIA does the same</comment>
        <translation>Não pude desativar a inversão (flipping) por algum motivo - desculpe! Tente desabilitá-la no painel de controle da NVIDIA.</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="192"/>
        <source>SSR started</source>
        <translation>SSR iniciado</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="201"/>
        <source>SSR stopped</source>
        <translation>SSR parado</translation>
    </message>
    <message>
        <location filename="../Main.cpp" line="209"/>
        <source>Error: Can&apos;t create .ssr directory!</source>
        <translation>Erro: Não foi possível criar o o diretório de .ssr!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="122"/>
        <source>Error: Image is too small!</source>
        <translation>Erro: A imagem é muito pequena!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="126"/>
        <source>Error: Image is too large!</source>
        <translation>Erro: A imagem é muito grande!</translation>
    </message>
    <message>
        <location filename="../AV/Input/GLInjectInput.cpp" line="134"/>
        <source>Error: Image doesn&apos;t fit in memory!</source>
        <translation>Erro: A imagem não cabe na memória!</translation>
    </message>
</context>
<context>
    <name>SyncDiagram</name>
    <message>
        <location filename="../AV/Output/SyncDiagram.cpp" line="49"/>
        <source>Synchronization Diagram</source>
        <translation>Diagrama de Sincronização</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="187"/>
        <source>Video in</source>
        <translation>Entrada de vídeo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="188"/>
        <source>Audio in</source>
        <translation>Entrada de áudio</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="189"/>
        <source>Video out</source>
        <translation>Saída de vídeo</translation>
    </message>
    <message>
        <location filename="../AV/Output/Synchronizer.cpp" line="190"/>
        <source>Audio out</source>
        <translation>Saída de áudio</translation>
    </message>
</context>
</TS>
