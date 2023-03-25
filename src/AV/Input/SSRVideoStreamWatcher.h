/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

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

#pragma once
#include "Global.h"

#include "SSRVideoStream.h"

#include "../glinject/ShmStructs.h"

class SSRVideoStreamWatcher {

public:
	typedef void (*AddCallback)(const SSRVideoStream&, void*);
	typedef void (*RemoveCallback)(const SSRVideoStream&, size_t, void*);

private:
	std::string m_channel_directory;
	bool m_relax_permissions;

	int m_fd_notify;

	std::vector<SSRVideoStream> m_streams;

public:
	SSRVideoStreamWatcher(const std::string& channel, bool relax_permissions);
	~SSRVideoStreamWatcher();

private:
	void Init();
	void Free();

public:
	// Handles all changes since the last call to this function.
	void HandleChanges(AddCallback add_callback, RemoveCallback remove_callback, void* userdata);

	// Returns a list of streams that are currently active.
	inline const std::vector<SSRVideoStream>& GetStreams() { return m_streams; }

};
