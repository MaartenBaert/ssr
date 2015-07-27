noinst_LTLIBRARIES = libssr-stream.la

libssr_stream_la_CPPFLAGS = \
	-I$(srcdir)/common \
	-I$(srcdir)/server \
	-I$(srcdir)/client
libssr_stream_la_CFLAGS = -pthread
libssr_stream_la_CXXFLAGS = -pthread -std=c++0x
libssr_stream_la_LDFLAGS = -pthread

if ! ENABLE_ASSERT
libssr_stream_la_CPPFLAGS += -DNDEBUG
endif

libssr_stream_la_SOURCES = \
	ClientConnection.cpp \
	ClientConnection.h \
	Common.cpp \
	Common.h \
	FileDescriptor.cpp \
	FileDescriptor.h \
	MessageHelpers.h \
	Protocol.h \
	QueueBuffer.h \
	Server.cpp \
	Server.h \
	ServerConnection.cpp \
	ServerConnection.h \
	VideoFrame.cpp \
	VideoFrame.h
