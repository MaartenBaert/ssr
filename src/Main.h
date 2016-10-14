/*
Copyright (c) 2012-2016 Maarten Baert <maarten-baert@hotmail.com>

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

extern bool g_option_logfile;
extern QString g_option_statsfile;
extern bool g_option_syncdiagram;
extern bool g_option_systray;
extern bool g_option_start_hidden;

QString GetApplicationSystemDir(const QString& subdir = QString());
QString GetApplicationDataDir(const QString& subdir = QString());
QString GetApplicationConfigDir(const QString& subdir = QString());
QString GetAppXDGDir(const QString& subdir, const char* xdg_env_name, const char* default_xdg_home_subdir);
QString GetVersionInfo();

bool NVidiaDetectFlipping();
bool NVidiaDisableFlipping();
