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
#include "Logger.h"

#include "Main.h"

Logger *Logger::g_instance = NULL;

Logger::Logger() {
	Q_ASSERT(g_instance == NULL);
	g_instance = this;
}

Logger::~Logger() {
	Q_ASSERT(g_instance == this);
	g_instance = NULL;
}

void Logger::Log(enum_type type, const QString& str) {
	Q_ASSERT(g_instance != NULL);
	VPair<SharedData>::Lock lock(&g_instance->m_shared_data);
	switch(type) {
		case TYPE_INFO:     fprintf(stderr, "%s\n", qPrintable(str));                   break;
		case TYPE_WARNING:  fprintf(stderr, "\033[1;33m%s\033[0m\n", qPrintable(str));  break;
		case TYPE_ERROR:    fprintf(stderr, "\033[1;31m%s\033[0m\n", qPrintable(str));  break;
	}
	lock->m_lines.push_back(std::make_pair(type, str));
}

std::vector<std::pair<Logger::enum_type, QString> > Logger::GetLines() {
	Q_ASSERT(g_instance != NULL);
	VPair<SharedData>::Lock lock(&g_instance->m_shared_data);
	auto lines = std::move(lock->m_lines);
	lock->m_lines.clear();
	return lines;
}
