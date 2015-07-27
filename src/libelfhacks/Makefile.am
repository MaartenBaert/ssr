if ENABLE_GLINJECTLIB

noinst_LTLIBRARIES = libelfhacks.la

libelfhacks_la_CPPFLAGS =
libelfhacks_la_CFLAGS = -pthread
libelfhacks_la_LDFLAGS = -pthread

if ! ENABLE_ASSERT
libelfhacks_la_CPPFLAGS += -DNDEBUG
endif

libelfhacks_la_SOURCES = \
	elfhacks.c \
	elfhacks.h

endif
