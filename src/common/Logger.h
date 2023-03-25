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

class Logger : public QObject {
	Q_OBJECT

public:
	enum enum_type {
		TYPE_INFO,
		TYPE_WARNING,
		TYPE_ERROR,
		TYPE_STDERR
	};

private:
	std::mutex m_mutex;
	QFile m_log_file;

	std::thread m_capture_thread;
	int m_capture_pipe[2], m_shutdown_pipe[2], m_original_stderr;

	static Logger *s_instance;

public:
	Logger();
	~Logger();

	void SetLogFile(const QString& filename);
	void RedirectStderr();

	// These functions are thread-safe.
	static void LogInfo(const QString& str);
	static void LogWarning(const QString& str);
	static void LogError(const QString& str);

	inline static Logger* GetInstance() { assert(s_instance != NULL); return s_instance; }

signals:
	void NewLine(Logger::enum_type type, QString str);

private:
	void CaptureThread();

};

Q_DECLARE_METATYPE(Logger::enum_type)
