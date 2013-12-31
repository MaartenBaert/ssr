if ENABLE_SSRPROGRAM

bin_PROGRAMS = simplescreenrecorder

simplescreenrecorder_CPPFLAGS = \
	$(QT4_CFLAGS) \
	-I$(top_builddir)/3rdparty \
	-I$(srcdir)/AV/Input \
	-I$(srcdir)/AV/Output \
	-I$(srcdir)/AV \
	-I$(srcdir)/common \
	-I$(srcdir)/GUI
simplescreenrecorder_CFLAGS = \
	-pthread
simplescreenrecorder_CXXFLAGS = \
	-pthread \
	-std=c++0x \
	-flax-vector-conversions
simplescreenrecorder_LDFLAGS = \
	-pthread \
	$(QT4_LIBS) \
	-L$(top_builddir)/3rdparty \
	-lrt -lavformat -lavcodec -lavutil -lswscale -lX11 -lXext -lXfixes -lasound -lsoxr

if ! ENABLE_ASSERT
simplescreenrecorder_CPPFLAGS += -DNDEBUG -DQT_NO_DEBUG
endif

if ENABLE_X86_ASM
simplescreenrecorder_CPPFLAGS += -DSSR_USE_X86_ASM=1
else
simplescreenrecorder_CPPFLAGS += -DSSR_USE_X86_ASM=0
endif

if ENABLE_FFMPEG_VERSIONS
simplescreenrecorder_CPPFLAGS += -DSSR_USE_FFMPEG_VERSIONS=1
else
simplescreenrecorder_CPPFLAGS += -DSSR_USE_FFMPEG_VERSIONS=0
endif

if ENABLE_PULSEAUDIO
simplescreenrecorder_CPPFLAGS += -DSSR_USE_PULSEAUDIO=1
simplescreenrecorder_LDFLAGS += -lpulse
else
simplescreenrecorder_CPPFLAGS += -DSSR_USE_PULSEAUDIO=0
endif

if ENABLE_JACK
simplescreenrecorder_CPPFLAGS += -DSSR_USE_JACK=1
simplescreenrecorder_LDFLAGS += -ljack
else
simplescreenrecorder_CPPFLAGS += -DSSR_USE_JACK=0
endif

simplescreenrecorder_SOURCES = \
	AV/Input/ALSAInput.cpp \
	AV/Input/ALSAInput.h \
	AV/Input/GLInjectInput.cpp \
	AV/Input/GLInjectInput.h \
	AV/Input/GLInjectLauncher.cpp \
	AV/Input/GLInjectLauncher.h \
	AV/Input/JACKInput.cpp \
	AV/Input/JACKInput.h \
	AV/Input/PulseAudioInput.cpp \
	AV/Input/PulseAudioInput.h \
	AV/Input/X11Input.cpp \
	AV/Input/X11Input.h \
	AV/Output/AudioEncoder.cpp \
	AV/Output/AudioEncoder.h \
	AV/Output/BaseEncoder.cpp \
	AV/Output/BaseEncoder.h \
	AV/Output/Muxer.cpp \
	AV/Output/Muxer.h \
	AV/Output/OutputManager.cpp \
	AV/Output/OutputManager.h \
	AV/Output/OutputSettings.h \
	AV/Output/SyncDiagram.cpp \
	AV/Output/SyncDiagram.h \
	AV/Output/Synchronizer.cpp \
	AV/Output/Synchronizer.h \
	AV/Output/VideoEncoder.cpp \
	AV/Output/VideoEncoder.h \
	AV/Output/X264Presets.cpp \
	AV/Output/X264Presets.h \
	AV/AVWrapper.cpp \
	AV/AVWrapper.h \
	AV/FastScaler.cpp \
	AV/FastScaler.h \
	AV/FastScaler_Convert.cpp \
	AV/FastScaler_Convert.h \
	AV/FastScaler_Scale.cpp \
	AV/FastScaler_Scale.h \
	AV/Resampler.cpp \
	AV/Resampler.h \
	AV/SimpleSynth.cpp \
	AV/SimpleSynth.h \
	AV/SourceSink.cpp \
	AV/SourceSink.h \
	common/ByteQueue.cpp \
	common/ByteQueue.h \
	common/DetectCPUFeatures.cpp \
	common/DetectCPUFeatures.h \
	common/Logger.cpp \
	common/Logger.h \
	common/MutexDataPair.h \
	common/TempBuffer.h \
	GUI/AudioPreviewer.cpp \
	GUI/AudioPreviewer.h \
	GUI/ElidedLabel.cpp \
	GUI/ElidedLabel.h \
	GUI/HotkeyListener.cpp \
	GUI/HotkeyListener.h \
	GUI/Icons.cpp \
	GUI/Icons.h \
	GUI/MainWindow.cpp \
	GUI/MainWindow.h \
	GUI/PageDone.cpp \
	GUI/PageDone.h \
	GUI/PageInput.cpp \
	GUI/PageInput.h \
	GUI/PageOutput.cpp \
	GUI/PageOutput.h \
	GUI/PageRecord.cpp \
	GUI/PageRecord.h \
	GUI/PageWelcome.cpp \
	GUI/PageWelcome.h \
	GUI/VideoPreviewer.cpp \
	GUI/VideoPreviewer.h \
	Global.h \
	Main.cpp \
	Main.h \
	Version.cpp \
	Version.h
nodist_simplescreenrecorder_SOURCES =

clean-local: clean-qrc-extra clean-moc-extra

########## Qt resource system ##########

EXTRA_DIST = \
	resources.qrc

nodist_simplescreenrecorder_SOURCES += \
	qrc_resources.cpp

qrc_resources.cpp: $(srcdir)/resources.qrc \
		$(top_srcdir)/data/img/header.png \
		$(top_srcdir)/data/img/icon-ssr.png \
		$(top_srcdir)/data/img/icon-ssr-recording.png \
		$(top_srcdir)/data/about.htm
	$(SED) "s|%DATADIR%|$(top_srcdir)/data|" "$(srcdir)/resources.qrc" > "resources_generated.qrc"
	$(RCC) -name resources "resources_generated.qrc" -o "qrc_resources.cpp"

clean-qrc-extra:
	rm -f "resources_generated.qrc"
	rm -f "qrc_resources.cpp"

########## Qt meta object compiler ##########

nodist_simplescreenrecorder_SOURCES += \
	moc_X11Input.cpp \
	moc_SyncDiagram.cpp \
	moc_Logger.cpp \
	moc_AudioPreviewer.cpp \
	moc_ElidedLabel.cpp \
	moc_HotkeyListener.cpp \
	moc_MainWindow.cpp \
	moc_PageDone.cpp \
	moc_PageInput.cpp \
	moc_PageOutput.cpp \
	moc_PageRecord.cpp \
	moc_PageWelcome.cpp \
	moc_VideoPreviewer.cpp

moc_X11Input.cpp: $(srcdir)/AV/Input/X11Input.h
	$(MOC) "$<" -o "$@"
moc_SyncDiagram.cpp: $(srcdir)/AV/Output/SyncDiagram.h
	$(MOC) "$<" -o "$@"
moc_Logger.cpp: $(srcdir)/common/Logger.h
	$(MOC) "$<" -o "$@"
moc_AudioPreviewer.cpp: $(srcdir)/GUI/AudioPreviewer.h
	$(MOC) "$<" -o "$@"
moc_ElidedLabel.cpp: $(srcdir)/GUI/ElidedLabel.h
	$(MOC) "$<" -o "$@"
moc_HotkeyListener.cpp: $(srcdir)/GUI/HotkeyListener.h
	$(MOC) "$<" -o "$@"
moc_MainWindow.cpp: $(srcdir)/GUI/MainWindow.h
	$(MOC) "$<" -o "$@"
moc_PageDone.cpp: $(srcdir)/GUI/PageDone.h
	$(MOC) "$<" -o "$@"
moc_PageInput.cpp: $(srcdir)/GUI/PageInput.h
	$(MOC) "$<" -o "$@"
moc_PageOutput.cpp: $(srcdir)/GUI/PageOutput.h
	$(MOC) "$<" -o "$@"
moc_PageRecord.cpp: $(srcdir)/GUI/PageRecord.h
	$(MOC) "$<" -o "$@"
moc_PageWelcome.cpp: $(srcdir)/GUI/PageWelcome.h
	$(MOC) "$<" -o "$@"
moc_VideoPreviewer.cpp: $(srcdir)/GUI/VideoPreviewer.h
	$(MOC) "$<" -o "$@"

clean-moc-extra:
	rm -f moc_*.cpp

########## Qt translation system ##########

translationsdir = $(pkgdatadir)/translations

simplescreenrecorder_CPPFLAGS += -DSSR_TRANSLATIONS_PATH=\"$(translationsdir)\"

nodist_translations_DATA = \
	simplescreenrecorder_de.qm \
	simplescreenrecorder_es.qm \
	simplescreenrecorder_nl.qm \
	simplescreenrecorder_pl.qm \
	simplescreenrecorder_zh_CN.qm

EXTRA_DIST += \
	translations/simplescreenrecorder_de.ts \
	translations/simplescreenrecorder_es.ts \
	translations/simplescreenrecorder_nl.ts \
	translations/simplescreenrecorder_pl.ts \
	translations/simplescreenrecorder_zh_CN.ts

simplescreenrecorder_de.qm: $(srcdir)/translations/simplescreenrecorder_de.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_es.qm: $(srcdir)/translations/simplescreenrecorder_es.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_nl.qm: $(srcdir)/translations/simplescreenrecorder_nl.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_pl.qm: $(srcdir)/translations/simplescreenrecorder_pl.ts
	$(LRELEASE) "$<" -qm "$@"
simplescreenrecorder_zh_CN.qm: $(srcdir)/translations/simplescreenrecorder_zh_CN.ts
	$(LRELEASE) "$<" -qm "$@"

.PHONY: clean-qrc-extra clean-moc-extra

endif
