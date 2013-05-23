if ENABLE_SSRPROGRAM

bin_PROGRAMS = simplescreenrecorder

simplescreenrecorder_CPPFLAGS = \
	$(QT4_CFLAGS)
simplescreenrecorder_CXXFLAGS = \
	-I$(srcdir)/AV/Encoder \
	-I$(srcdir)/AV/Input \
	-I$(srcdir)/AV \
	-I$(srcdir)/GUI \
	-I$(top_srcdir)/glinject \
	-std=c++0x \
	-flax-vector-conversions
simplescreenrecorder_LDFLAGS = \
	$(QT4_LIBS) \
	-lrt -lavformat -lavcodec -lavutil -lswscale -lX11 -lXext -lXfixes -lasound

simplescreenrecorder_SOURCES = \
	AV/Encoder/AudioEncoder.cpp \
	AV/Encoder/AudioEncoder.h \
	AV/Encoder/BaseEncoder.cpp \
	AV/Encoder/BaseEncoder.h \
	AV/Encoder/VideoEncoder.cpp \
	AV/Encoder/VideoEncoder.h \
	AV/Encoder/X264Presets.cpp \
	AV/Encoder/X264Presets.h \
	AV/Input/ALSAInput.cpp \
	AV/Input/ALSAInput.h \
	AV/Input/GLInjectInput.cpp \
	AV/Input/GLInjectInput.h \
	AV/Input/GLInjectLauncher.cpp \
	AV/Input/GLInjectLauncher.h \
	AV/Input/X11Input.cpp \
	AV/Input/X11Input.h \
	AV/AVWrapper.cpp \
	AV/AVWrapper.h \
	AV/Muxer.cpp \
	AV/Muxer.h \
	AV/Synchronizer.cpp \
	AV/Synchronizer.h \
	AV/YUVConverter.cpp \
	AV/YUVConverter.h \
	GUI/AudioPreviewer.cpp \
	GUI/AudioPreviewer.h \
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
	ByteQueue.cpp \
	ByteQueue.h \
	Global.h \
	Logger.cpp \
	Logger.h \
	Main.cpp \
	Main.h \
	Version.cpp \
	Version.h \
	VPair.h
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
	moc_HotkeyListener.cpp \
	moc_MainWindow.cpp \
	moc_PageDone.cpp \
	moc_PageInput.cpp \
	moc_PageOutput.cpp \
	moc_PageRecord.cpp \
	moc_PageWelcome.cpp

moc_X11Input.cpp: $(srcdir)/AV/Input/X11Input.h
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

clean-moc-extra:
	rm -f moc_*.cpp

endif
