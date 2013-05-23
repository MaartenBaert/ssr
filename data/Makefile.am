if ENABLE_SSRPROGRAM

desktopdir = $(prefix)/share/applications
icon256dir = $(prefix)/share/icons/hicolor/256x256/apps

dist_desktop_DATA = \
	simplescreenrecorder.desktop

nodist_icon256_DATA = \
	simplescreenrecorder.png

simplescreenrecorder.png: $(srcdir)/img/icon.png
	cp "$<" "$@"

clean-local:
	rm -f "simplescreenrecorder.png"

########## Data files used by 'src' ##########

EXTRA_DIST = \
	img/header.png \
	img/icon.png \
	about.htm

endif
