if ENABLE_SSRPROGRAM

# This is messy but it works. If you know a better way, please tell me.
# This would obviously have been a lot easier if all projects used autotools, but I don't feel like
# setting up a new build system for a 3rd party library. Besides, cmake is probably a better build system,
# I only use automake because it is easier to package (at least for Ubuntu).

nodist_noinst_DATA = \
	libsoxr.a \
	soxr.h

soxr-make:
	$(MAKE) -C "$(srcdir)/soxr/Release"
soxr-make-clean:
	$(MAKE) -C "$(srcdir)/soxr/Release" clean
soxr-make-distclean:
	$(MAKE) -C "$(srcdir)/soxr/Release" distclean
libsoxr.a: soxr-make
	cp "$(srcdir)/soxr/Release/src/libsoxr.a" "$@"
soxr.h: $(srcdir)/soxr/src/soxr.h
	cp "$<" "$@"

clean-local: soxr-make-clean
distclean-local: soxr-make-distclean

.PHONY: soxr-make soxr-make-clean soxr-make-distclean

endif
