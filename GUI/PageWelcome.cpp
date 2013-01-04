/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

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

#include "StdAfx.h"
#include "PageWelcome.h"

#include "MainWindow.h"

PageWelcome::PageWelcome(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	QLabel *label_welcome = new QLabel("Welcome to SimpleScreenRecorder!\n\n"
									   "Despite the name, this program is actually quite complex. Don't worry though, there are really just two things that you "
									   "need to know. One, the default settings are usually fine. If you don't know what something does, just use the default. "
									   "Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.\n\n"
									   "This program is still in beta. If you find a bug, please report it. You can contact me at maarten-baert@hotmail.com.", this);
	label_welcome->setWordWrap(true);
	QPushButton *button_about = new QPushButton("About SimpleScreenRecorder", this);
	QPushButton *button_continue = new QPushButton("Continue", this);

	connect(button_about, SIGNAL(clicked()), this, SLOT(AboutDialog()));
	connect(button_continue, SIGNAL(clicked()), m_main_window, SLOT(GoPageInput()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(label_welcome);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_about);
		layout2->addStretch();
	}
	layout->addStretch();
	layout->addWidget(button_continue);

}

void PageWelcome::AboutDialog() {
	DialogAbout dialog(this);
	dialog.exec();
}

DialogAbout::DialogAbout(PageWelcome* parent)
	: QDialog(parent) {

	setWindowTitle("About SimpleScreenRecorder");

	QTextBrowser *textbrowser = new QTextBrowser(this);
	textbrowser->setSource(QUrl("qrc:/about.htm"));
	textbrowser->setOpenExternalLinks(true);
	textbrowser->setMinimumSize(700, 500);

	QPushButton *pushbutton_close = new QPushButton("Close", this);

	connect(pushbutton_close, SIGNAL(clicked()), this, SLOT(accept()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(textbrowser);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addStretch();
		layout2->addWidget(pushbutton_close);
		layout2->addStretch();
	}

}
