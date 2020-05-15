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

extern QIcon g_icon_ssr, g_icon_ssr_idle, g_icon_ssr_error, g_icon_ssr_paused, g_icon_ssr_recording;
extern QIcon g_icon_go_home, g_icon_go_previous, g_icon_go_next, g_icon_folder_open;
extern QIcon g_icon_pause, g_icon_record;
extern QIcon g_icon_cancel, g_icon_save, g_icon_quit;
extern QIcon g_icon_microphone;

void LoadIcons();
