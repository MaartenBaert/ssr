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

#pragma once
#include "Global.h"

class SSRVideoStreamWatcher {

public:
	struct Stream {
		std::string m_pid, m_source, m_program_name;
		inline bool operator==(const Stream& other) const {
			return (m_pid == other.m_pid && m_source == other.m_source && m_program_name == other.m_program_name);
		}
	};
	typedef void (*AddCallback)(const Stream&, size_t pos);
	typedef void (*RemoveCallback)(const Stream&, size_t pos);

private:
	int m_fd_notify;

	std::vector<Stream> m_streams;

public:
	SSRVideoStreamWatcher();
	~SSRVideoStreamWatcher();

private:
	void Init();
	void Free();

	bool ParseName(const std::string& name, Stream* stream);

public:
	// Handles all changes since the last call to this function.
	void HandleChanges(AddCallback add_callback, RemoveCallback remove_callback);

	// Returns a list of streams that are currently active.
	inline const std::vector<Stream>& GetStreams() { return m_streams; }

};
