if ENABLE_SSRPROGRAM

# This makefile is based on the 'lib-src' makefile from Audacity.
# This is messy but it works. If you know a better way, please tell me.
# This would obviously have been a lot easier if all projects used autotools, but I don't feel like
# setting up a new build system for a 3rd party library. Besides, cmake is probably a better build system,
# I only use automake because it is easier to package (at least for Ubuntu).

SUBDIRS = soxr

nodist_noinst_DATA = \
	libsoxr.a \
	soxr.h

libsoxr.a: soxr/src/libsoxr.a
	cp "$(builddir)/soxr/src/libsoxr.a" "$@"
soxr.h: $(srcdir)/soxr/src/soxr.h
	cp "$<" "$@"

# Overwrite install* targets from automake. We do not want to install anything
# from the lib-src libraries, because we statically link these libraries.
install:
install-dvi:
install-data:
install-exec:
install-html:
install-info:
install-ps:
install-pdf:
installdirs:
uninstall:

# Overwrite check target. We do not want to run the tests from the libraries.
check:

# Overwrite distclean rule to avoid running distclean for unconfigured libraries
# (and then failing due to the missing Makefile).
distclean:
	@for subdir in $(SUBDIRS); do \
	if test -f $$subdir/Makefile; then \
	echo "Making $@ in $$subdir"; \
	$(MAKE) $(AM_MAKEFLAGS) -C $$subdir $@ || exit 1; \
	fi; \
	done
	rm -f Makefile

# Overwrite maintainer-clean rule to avoid running maintainer-clean for
# unconfigured libraries (and then failing due to the missing Makefile).
maintainer-clean:
	@for subdir in $(SUBDIRS); do \
	if test -f $$subdir/Makefile; then \
	echo "Making $@ in $$subdir"; \
	$(MAKE) $(AM_MAKEFLAGS) -C $$subdir $@ || exit 1; \
	fi; \
	done
	rm -f Makefile

.PHONY: check install install-dvi install-data install-exec install-html install-info install-ps install-pdf installdirs uninstall distclean maintainer-clean

endif
