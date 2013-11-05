/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

This file is part of SimpleScreenRecorder.

SimpleScreenRecorder is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SimpleScreenRecorder is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SimpleScreenRecorder.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Global.h"
#include "GLInjectLauncher.h"

#include "Main.h"
#include "Logger.h"

#include "../glinject/ShmStructs.h"

const unsigned int GLInjectLauncher::CBUFFER_SIZE = 5;

GLInjectLauncher::GLInjectLauncher(const QString& command, bool run_command, bool relax_permissions, unsigned int max_bytes, unsigned int target_fps, bool record_cursor, bool capture_front, bool limit_fps) {

	m_command = command;
	m_run_command = run_command;
	m_relax_permissions = relax_permissions;
	m_max_bytes = max_bytes;
	m_target_fps = target_fps;
	m_record_cursor = record_cursor;
	m_capture_front = capture_front;
	m_limit_fps = limit_fps;

	m_hotkey_last_counter = 0;

	m_shm_main_id = -1;
	m_shm_main_ptr = (char*) -1;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

GLInjectLauncher::~GLInjectLauncher() {

	// free everything
	Free();

}

void GLInjectLauncher::GetCurrentSize(unsigned int* width, unsigned int* height) {
	GLInjectHeader *header = (GLInjectHeader*) m_shm_main_ptr;
	std::atomic_thread_fence(std::memory_order_acquire);
	*width = header->current_width;
	*height = header->current_height;
	std::atomic_thread_fence(std::memory_order_release);
}

uint32_t GLInjectLauncher::GetFrameCounter() {
	GLInjectHeader *header = (GLInjectHeader*) m_shm_main_ptr;
	std::atomic_thread_fence(std::memory_order_acquire);
	uint32_t counter = header->frame_counter;
	std::atomic_thread_fence(std::memory_order_release);
	return counter;
}

void GLInjectLauncher::UpdateHotkey(bool enabled, unsigned int keysym, unsigned int modifiers) {
	GLInjectHeader *header = (GLInjectHeader*) m_shm_main_ptr;
	std::atomic_thread_fence(std::memory_order_acquire);
	header->hotkey_enabled = enabled;
	header->hotkey_keycode = XKeysymToKeycode(QX11Info::display(), keysym);
	header->hotkey_modifiers = modifiers;
	std::atomic_thread_fence(std::memory_order_release);
}

bool GLInjectLauncher::GetHotkeyPressed() {
	GLInjectHeader *header = (GLInjectHeader*) m_shm_main_ptr;
	std::atomic_thread_fence(std::memory_order_acquire);
	unsigned int new_hotkey_counter = header->hotkey_counter;
	std::atomic_thread_fence(std::memory_order_release);
	bool event = (new_hotkey_counter != m_hotkey_last_counter);
	m_hotkey_last_counter = new_hotkey_counter;
	return event;
}

void GLInjectLauncher::Init() {

	// allocate main shared memory
	m_shm_main_id = shmget(IPC_PRIVATE, sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * CBUFFER_SIZE, IPC_CREAT | ((m_relax_permissions)? 0777 : 0700));
	if(m_shm_main_id == -1) {
		Logger::LogError("[GLInjectLauncher::Init] " + QObject::tr("Error: Can't get shared memory!"));
		throw GLInjectException();
	}
	m_shm_main_ptr = (char*) shmat(m_shm_main_id, NULL, SHM_RND);
	if(m_shm_main_ptr == (char*) -1) {
		Logger::LogError("[GLInjectLauncher::Init] " + QObject::tr("Error: Can't attach to shared memory!"));
		throw GLInjectException();
	}
	memset(m_shm_main_ptr, 0, sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * CBUFFER_SIZE);

	// allocate frame shared memory
	for(unsigned int i = 0; i < CBUFFER_SIZE; ++i) {
		m_shm_frames.push_back(ShmFrame());
		m_shm_frames.back().m_id = shmget(IPC_PRIVATE, m_max_bytes, IPC_CREAT | ((m_relax_permissions)? 0777 : 0700));
		if(m_shm_frames.back().m_id == -1) {
			Logger::LogError("[GLInjectLauncher::Init] " + QObject::tr("Error: Can't get frame shared memory!"));
			throw GLInjectException();
		}
		m_shm_frames.back().m_shm_ptr = (char*) shmat(m_shm_frames.back().m_id, NULL, SHM_RND);
		if(m_shm_frames.back().m_shm_ptr == (char*) -1) {
			Logger::LogError("[GLInjectLauncher::Init] " + QObject::tr("Error: Can't attach to frame shared memory!"));
			throw GLInjectException();
		}
		GLInjectFrameInfo *frameinfo = (GLInjectFrameInfo*) (m_shm_main_ptr + sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * i);
		frameinfo->shm_id = m_shm_frames.back().m_id;
		memset((void*) m_shm_frames.back().m_shm_ptr, 0, m_max_bytes);
	}

	// initialize the memory
	GLInjectHeader *header = (GLInjectHeader*) m_shm_main_ptr;
	header->cbuffer_size = CBUFFER_SIZE;
	header->max_bytes = m_max_bytes;
	header->target_fps = m_target_fps;
	header->flags = ((m_record_cursor)? GLINJECT_FLAG_RECORD_CURSOR : 0) | ((m_capture_front)? GLINJECT_FLAG_CAPTURE_FRONT : 0) | ((m_limit_fps)? GLINJECT_FLAG_LIMIT_FPS : 0);
	header->hotkey_enabled = false;
	header->hotkey_modifiers = 0;
	header->hotkey_keycode = 0;
	header->read_pos = 0;
	header->write_pos = 0;
	header->current_width = 0;
	header->current_height = 0;
	header->frame_counter = 0;
	header->hotkey_counter = 0;
	std::atomic_thread_fence(std::memory_order_release);

	// generate the full command
	QString full_command = "LD_PRELOAD=libssr-glinject.so SSR_GLINJECT_SHM=" + QString::number(m_shm_main_id) + " " + m_command;
	Logger::LogInfo("[GLInjectLauncher::Init] " + QObject::tr("Full command") + ": " + full_command);

	// run it
	if(m_run_command) {
		QStringList args;
		args.push_back("-c");
		args.push_back(full_command);
		if(!QProcess::startDetached("/bin/sh", args, QDir::homePath())) {
			Logger::LogError("[GLInjectLauncher::Init] " + QObject::tr("Error: Can't run command!"));
			throw GLInjectException();
		}
	}

}

void GLInjectLauncher::Free() {

	// free frame shared memory
	while(!m_shm_frames.empty()) {
		if(m_shm_frames.back().m_shm_ptr != (char*) -1) {
			shmdt((void*) m_shm_frames.back().m_shm_ptr);
		}
		if(m_shm_frames.back().m_id != -1) {
			shmctl(m_shm_frames.back().m_id, IPC_RMID, NULL);
		}
		m_shm_frames.pop_back();
	}

	// free main shared memory
	if(m_shm_main_ptr != (char*) -1) {
		shmdt((void*) m_shm_main_ptr);
		m_shm_main_ptr = (char*) -1;
	}
	if(m_shm_main_id != -1) {
		shmctl(m_shm_main_id, IPC_RMID, NULL);
		m_shm_main_id = -1;
	}

}
