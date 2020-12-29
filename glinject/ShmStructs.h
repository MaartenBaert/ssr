/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#pragma once

/*
A captured video stream is transmitted to SimpleScreenRecorder using shared memory files (i.e. files in /dev/shm).
The system is entirely lock-free and thread-safe, but supports only a single reader and a single writer.

There are two types of files:

>>>> /dev/shm/ssr-video-PID-SOURCE-DESCRIPTION <<<<
> PID is the process ID of the application, SOURCE is the source of the stream (should be unique for this process), DESCRIPTION can be anything.
> This file contains a GLInjectHeader struct followed by a GLInjectFrameInfo struct for each frame in the ring buffer.

>>>> /dev/shm/ssr-videoframeNUM-PID-SOURCE-DESCRIPTION <<<<
> NUM is the position of the frame in the ring buffer (starting from zero).
> This file contains one video frame. The file size is not constant, it may be enlarged when the video frame size changes. The size can only increase, not decrease.

*/

// Disable padding to make sure the 32-bit and 64-bit libs are compatible.
#pragma pack(push, 1)

#define GLINJECT_RING_BUFFER_SIZE 4

#define GLINJECT_IDENTIFIER 0x8af7a476

#define GLINJECT_FLAG_CAPTURE_ENABLED  0x0001
#define GLINJECT_FLAG_RECORD_CURSOR    0x0002
#define GLINJECT_FLAG_LIMIT_FPS        0x0004

struct GLInjectHeader {

	// identifier
	uint32_t identifier;

	// ring buffer
	uint32_t ring_buffer_read_pos, ring_buffer_write_pos;

	// video stream info: set by the captured application
	uint32_t current_width, current_height;
	uint32_t frame_counter;

	// capture parameters: set by SimpleScreenRecorder
	uint32_t capture_flags;
	uint32_t capture_target_fps;

};

struct GLInjectFrameInfo {

	// frame info: set by the captured application
	int64_t timestamp;
	uint32_t width, height;
	int32_t stride; // stride can be negative, this means the frame is upside-down (this is typical for OpenGL)

};

#pragma pack(pop)
