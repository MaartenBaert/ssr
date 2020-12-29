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

#include "Icons.h"

QIcon g_icon_ssr, g_icon_ssr_idle, g_icon_ssr_error, g_icon_ssr_paused, g_icon_ssr_recording;
QIcon g_icon_go_home, g_icon_go_previous, g_icon_go_next, g_icon_folder_open;
QIcon g_icon_pause, g_icon_record;
QIcon g_icon_cancel, g_icon_save, g_icon_quit;
QIcon g_icon_microphone;

void LoadIcons() {

	g_icon_ssr = QIcon::fromTheme("simplescreenrecorder");
	g_icon_ssr_idle = QIcon::fromTheme("simplescreenrecorder-idle");
	g_icon_ssr_error = QIcon::fromTheme("simplescreenrecorder-error");
	g_icon_ssr_paused = QIcon::fromTheme("simplescreenrecorder-paused");
	g_icon_ssr_recording = QIcon::fromTheme("simplescreenrecorder-recording");

	g_icon_go_home = QIcon::fromTheme("go-home");
	if(QApplication::layoutDirection() == Qt::RightToLeft) {
		g_icon_go_previous = QIcon::fromTheme("go-next");
		g_icon_go_next = QIcon::fromTheme("go-previous");
	} else {
		g_icon_go_previous = QIcon::fromTheme("go-previous");
		g_icon_go_next = QIcon::fromTheme("go-next");
	}
	g_icon_folder_open = QIcon::fromTheme("folder-open");

	g_icon_pause = QIcon::fromTheme("media-playback-pause");
	g_icon_record = QIcon::fromTheme("media-record");

	g_icon_cancel = QIcon::fromTheme("process-stop");
	g_icon_save = QIcon::fromTheme("document-save");
	g_icon_quit = QIcon::fromTheme("application-exit");

	g_icon_microphone = QIcon::fromTheme("audio-input-microphone");

}
