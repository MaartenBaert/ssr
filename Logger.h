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
#include "StdAfx.h"

#include "VPair.h"

class Logger {

public:
	enum enum_type {
		TYPE_INFO,
		TYPE_WARNING,
		TYPE_ERROR
	};

private:
	struct SharedData {
		std::vector<std::pair<enum_type, QString> > m_lines;
	};

private:
	VPair<SharedData> m_shared_data;

	static Logger *g_instance;

public:
	Logger();
	~Logger();

	// This function is thread-safe.
	static void Log(enum_type type, const QString& str);

	// This function is thread-safe.
	static std::vector<std::pair<enum_type, QString> > GetLines();

	// Some convenience functions.
	inline static void LogInfo(const QString& str) { Log(TYPE_INFO, str); }
	inline static void LogWarning(const QString& str) { Log(TYPE_WARNING, str); }
	inline static void LogError(const QString& str) { Log(TYPE_ERROR, str); }

};
