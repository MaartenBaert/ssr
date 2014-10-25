SUBDIRS = data glinject scripts src

EXTRA_DIST = \
	AUTHORS.md \
	CHANGELOG.md \
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
