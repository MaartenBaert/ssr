if ENABLE_SSRPROGRAM

desktopdir = $(pkgdatadir)/applications
icon256dir = $(pkgdatadir)/icons/hicolor/256x256/apps

dist_desktop_DATA = \
	simplescreenrecorder.desktop

nodist_icon256_DATA = \
	simplescreenrecorder.png

simplescreenrecorder.png: $(srcdir)/img/icon-ssr.png
	cp "$<" "$@"

clean-local:
	rm -f "simplescreenrecorder.png"

########## Data files used by 'src' ##########

EXTRA_DIST = \
	img/header.png \
	img/icon-ssr.png \
	img/icon-ssr-recording.png \
	about.htm

endif
