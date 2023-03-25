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

struct SSRVideoStream {
	std::string m_stream_name;
	int64_t m_creation_time;
	unsigned int m_process_id;
	inline bool operator==(const SSRVideoStream& other) const {
		return (m_stream_name == other.m_stream_name);
	}
	inline bool operator<(const SSRVideoStream& other) const {
		return (m_creation_time < other.m_creation_time);
	}
};
