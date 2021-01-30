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

class CommandLineException : public std::exception {
public:
	inline virtual const char* what() const throw() override {
		return "CommandLineException";
	}
};

class CommandLineOptions {

private:
	QString m_settings_file;
	QString m_log_file;
	QString m_stats_file;
	bool m_redirect_stderr;
	bool m_systray;
	bool m_start_hidden;
	bool m_start_recording;
	bool m_activate_schedule;
	bool m_sync_diagram;
	bool m_benchmark;
	bool m_gui;

	static CommandLineOptions *s_instance;

public:
	CommandLineOptions();
	~CommandLineOptions();

	void Parse();

	inline static CommandLineOptions* GetInstance() { assert(s_instance != NULL); return s_instance; }

	inline static const QString& GetSettingsFile() { return GetInstance()->m_settings_file; }
	inline static const QString& GetLogFile() { return GetInstance()->m_log_file; }
	inline static const QString& GetStatsFile() { return GetInstance()->m_stats_file; }
	inline static bool GetRedirectStderr() { return GetInstance()->m_redirect_stderr; }
	inline static bool GetSysTray() { return GetInstance()->m_systray; }
	inline static bool GetStartHidden() { return GetInstance()->m_start_hidden; }
	inline static bool GetStartRecording() { return GetInstance()->m_start_recording; }
	inline static bool GetActivateSchedule() { return GetInstance()->m_activate_schedule; }
	inline static bool GetSyncDiagram() { return GetInstance()->m_sync_diagram; }
	inline static bool GetBenchmark() { return GetInstance()->m_benchmark; }
	inline static bool GetGui() { return GetInstance()->m_gui; }

};

QString GetVersionInfo();
QString GetApplicationSystemDir(const QString& subdir = QString());
QString GetApplicationUserDir(const QString& subdir = QString());
