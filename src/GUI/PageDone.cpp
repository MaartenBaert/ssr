/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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

#include "PageDone.h"

#include "Icons.h"
#include "MainWindow.h"

PageDone::PageDone(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	QLabel *label_done = new QLabel(tr("The recording has been saved. You can edit the video now, or re-encode it with better settings to "
									   "make the file smaller (the default settings are optimized for quality and speed, not file size)."), this);
	label_done->setWordWrap(true);
	QPushButton *button_back = new QPushButton(g_icon_go_home, tr("Back to the start screen"), this);

	connect(button_back, SIGNAL(clicked()), m_main_window, SLOT(GoPageWelcome()));

	QVBoxLayout *layout_page = new QVBoxLayout(this);
	layout_page->addWidget(label_done);
	layout_page->addStretch();
	layout_page->addWidget(button_back);

}
