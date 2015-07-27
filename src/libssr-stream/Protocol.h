/*
Copyright (c) 2012-2015 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
*/

#pragma once

#include <cstdint>
#include <cassert>

#pragma pack(push, 1)

// Maximum number of file descriptors that can be sent/received in a single read/write operation.
// Passing file descriptors over UNIX domain sockets is poorly documented, but as far as I can tell
// there is no way to know in advance how many file descriptors will be received, so this number must
// be high enough to handle the most extreme cases without data loss. Increasing this number will increase
// the memory usage slightly, but there is no processing cost.
#define SSRSTREAM_MAX_FDS 256

// Minimum and maximum video frame width and height.
#define SSRSTREAM_MIN_WIDTH 2
#define SSRSTREAM_MIN_HEIGHT 2
#define SSRSTREAM_MAX_WIDTH 16384
#define SSRSTREAM_MAX_HEIGHT 16384

// Maximum video frame stride (bytes per row).
#define SSRSTREAM_MAX_STRIDE (SSRSTREAM_MAX_WIDTH * 4)

enum enum_message_client {
	MESSAGE_CLIENT_NAME                = 0,
	MESSAGE_CLIENT_VIDEO_STATS         = 40,
	MESSAGE_CLIENT_VIDEO_FRAME         = 41,
};
enum enum_message_server {
	MESSAGE_SERVER_VIDEO_SETUP         = 40,
	MESSAGE_SERVER_VIDEO_FRAME_RELEASE = 41,
};

enum enum_video_flags {
	VIDEO_FLAG_ACTIVE        = 0x0001,
	VIDEO_FLAG_RECORD_CURSOR = 0x0002,
	VIDEO_FLAG_LIMIT_FPS     = 0x0004,
};

struct MessageClientName {
	uint8_t message;
	char name[64];
};
struct MessageClientVideoStats {
	uint8_t message;
	uint64_t timestamp;
	uint32_t fps;
};
struct MessageClientVideoFrame {
	uint8_t message;
	uint64_t timestamp;
	uint32_t width, height;
	int32_t stride; // negative means upside-down
	// FD attached
};

struct MessageServerVideoSetup {
	uint8_t message;
	uint32_t frame_rate;
	uint32_t flags;
};
struct MessageServerVideoFrameRelease {
	uint8_t message;
};

#pragma pack(pop)
