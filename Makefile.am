SUBDIRS = 3rdparty data glinject src

EXTRA_DIST = \
	COPYING \
	notes.txt \
	postinstall \
	README.md \
	simple-build-and-install \
	simple-uninstall \
	todo.txt

ACLOCAL_AMFLAGS = -I m4

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool
