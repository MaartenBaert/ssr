if ENABLE_SSRPROGRAM

bin_PROGRAMS = simplescreenrecorder

simplescreenrecorder_CPPFLAGS = \
	$(QT4_CFLAGS) \
	-I$(srcdir)/AV/Input \
	-I$(srcdir)/AV/Output \
	-I$(srcdir)/AV \
	-I$(srcdir)/GUI
simplescreenrecorder_CFLAGS = \
	-pthread
simplescreenrecorder_CXXFLAGS = \
	-pthread \
	-std=c++11 \
	-flax-vector-conversions
simplescreenrecorder_LDFLAGS = \
	-pthread \
	$(QT4_LIBS) \
	-lrt -lavformat -lavcodec -lavutil -lswscale -lX11 -lXext -lXfixes -lasound

simplescreenrecorder_SOURCES = \
	AV/Input/ALSAInput.cpp \
	AV/Input/ALSAInput.h \
	AV/Input/GLInjectInput.cpp \
	AV/Input/GLInjectInput.h \
	AV/Input/GLInjectLauncher.cpp \
	AV/Input/GLInjectLauncher.h \
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
	AV/Output/Synchronizer.cpp \
	AV/Output/Synchronizer.h \
	AV/Output/VideoEncoder.cpp \
	AV/Output/VideoEncoder.h \
	AV/Output/X264Presets.cpp \
	AV/Output/X264Presets.h \
	AV/AVWrapper.cpp \
	AV/AVWrapper.h \
	AV/ByteQueue.cpp \
	AV/ByteQueue.h \
	AV/DetectCPUFeatures.cpp \
	AV/DetectCPUFeatures.h \
	AV/FastScaler.cpp \
	AV/FastScaler.h \
	AV/SourceSink.cpp \
	AV/SourceSink.h \
	GUI/AudioPreviewer.cpp \
	GUI/AudioPreviewer.h \
	GUI/ElidedLabel.cpp \
	GUI/ElidedLabel.h \
	GUI/HotkeyListener.cpp \
	GUI/HotkeyListener.h \
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
	Logger.cpp \
	Logger.h \
	Main.cpp \
	Main.h \
	MutexDataPair.h \
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
		$(top_srcdir)/data/img/icon.png \
		$(top_srcdir)/data/about.htm
	$(SED) "s|%DATADIR%|$(top_srcdir)/data|" "$(srcdir)/resources.qrc" > "resources_generated.qrc"
	$(RCC) -name resources "resources_generated.qrc" -o "qrc_resources.cpp"

clean-qrc-extra:
	rm -f "resources_generated.qrc"
	rm -f "qrc_resources.cpp"

########## Qt meta object compiler ##########

nodist_simplescreenrecorder_SOURCES += \
	moc_X11Input.cpp \
	moc_AudioPreviewer.cpp \
	moc_ElidedLabel.cpp \
	moc_HotkeyListener.cpp \
	moc_MainWindow.cpp \
	moc_PageDone.cpp \
	moc_PageInput.cpp \
	moc_PageOutput.cpp \
	moc_PageRecord.cpp \
	moc_PageWelcome.cpp \
	moc_VideoPreviewer.cpp \
	moc_Logger.cpp

moc_X11Input.cpp: $(srcdir)/AV/Input/X11Input.h
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
moc_Logger.cpp: $(srcdir)/Logger.h
	$(MOC) "$<" -o "$@"

clean-moc-extra:
	rm -f moc_*.cpp

endif
