/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#pragma once

#include <atomic>

// Disable padding to make sure the 32-bit and 64-bit libs are compatible.
#pragma pack(push, 1)

#define GLINJECT_FLAG_RECORD_CURSOR  0x0001
#define GLINJECT_FLAG_CAPTURE_FRONT  0x0002
#define GLINJECT_FLAG_LIMIT_FPS      0x0004

struct GLInjectHeader {
	// input
	uint32_t ring_buffer_size, max_bytes;
	uint32_t target_fps;
	uint32_t flags;
	uint32_t hotkey_enabled;
	uint32_t hotkey_keycode;
	uint32_t hotkey_modifiers;
	// input/output
	uint32_t read_pos, write_pos;
	// output
	uint32_t current_width, current_height;
	uint32_t frame_counter;
	uint32_t hotkey_counter;
};
struct GLInjectFrameInfo {
	// input
	int32_t shm_id;
	// output
	int64_t timestamp;
	uint32_t width, height;
};

#pragma pack(pop)
