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

#include "Icons.h"

QIcon g_icon_ssr, g_icon_ssr_paused, g_icon_ssr_recording;
QIcon g_icon_pause, g_icon_record;

void LoadIcons() {

	g_icon_ssr = QIcon::fromTheme("simplescreenrecorder");
	g_icon_ssr_paused = QIcon::fromTheme("simplescreenrecorder-paused");
	g_icon_ssr_recording = QIcon::fromTheme("simplescreenrecorder-recording");

	g_icon_pause = QIcon::fromTheme("media-playback-pause");
	g_icon_record = QIcon::fromTheme("media-record");

}
