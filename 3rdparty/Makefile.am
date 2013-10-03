if ENABLE_SSRPROGRAM

# This is messy but it works. If you know a better way, please tell me.
# This would obviously have been a lot easier if all projects used autotools, but I don't feel like
# setting up a new build system for a 3rd party library. Besides, cmake is probably a better build system,
# I only use automake because it is easier to package (at least for Ubuntu).

nodist_noinst_DATA = \
	libsoxr.a \
	soxr.h

libsoxr.a: $(srcdir)/soxr
	mkdir -p "$(srcdir)/soxr/build"
	cd "$(srcdir)/soxr/build"; cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=FALSE ..
	cd "$(srcdir)/soxr/build"; $(MAKE)
	cp "$(srcdir)/soxr/build/src/libsoxr.a" "$@"

soxr.h: $(srcdir)/soxr/src/soxr.h
	cp "$<" "$@"

clean-local:
	rm -f "libsoxr.a" "soxr.h"

endif
