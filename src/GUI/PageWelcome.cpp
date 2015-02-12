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

#include "PageWelcome.h"

#include "Icons.h"
#include "Main.h"
#include "MainWindow.h"

PageWelcome::PageWelcome(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	QLabel *label_logo = new QLabel(this);
	label_logo->setPixmap(QPixmap(":/header.png"));
	QLabel *label_welcome = new QLabel(this);
	label_welcome->setText(tr("<p>Welcome to SimpleScreenRecorder!</p>\n\n"
							  "<p>Despite the name, this program actually has a lot of options. Don't worry though, there are really just two things that you "
							  "need to know. One, the default settings are usually fine. If you don't know what something does, just use the default. "
							  "Two, almost all settings have tooltips. Just hover the mouse over something to find out what it does.</p>\n\n"
							  "<p>For more information:<br>\n"
							  "%1</p>").arg("<a href=\"http://www.maartenbaert.be/simplescreenrecorder/\">http://www.maartenbaert.be/simplescreenrecorder/</a>"));
	label_welcome->setWordWrap(true);
	label_welcome->setTextFormat(Qt::RichText);
	label_welcome->setTextInteractionFlags(Qt::TextBrowserInteraction);
	label_welcome->setOpenExternalLinks(true);
	QPushButton *button_about = new QPushButton(tr("About SimpleScreenRecorder"), this);
	QPushButton *button_continue = new QPushButton(g_icon_go_next, tr("Continue"), this);

	connect(button_about, SIGNAL(clicked()), this, SLOT(AboutDialog()));
	connect(button_continue, SIGNAL(clicked()), m_main_window, SLOT(GoPageInput()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addStretch();
		layout2->addWidget(label_logo);
		layout2->addStretch();
	}
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

	setWindowTitle(tr("About SimpleScreenRecorder"));

	QString html_about;
	{
		QFile file(":/about.htm");
		if(file.open(QIODevice::ReadOnly | QIODevice::Text))
			html_about = file.readAll();
	}

	html_about.replace("%MOREINFO%", tr("For more information:"));
	html_about.replace("%SOURCECODE%", tr("The source code of this program can be found at:"));
	html_about.replace("%USES%", tr("This program uses:"));
	html_about.replace("%USES_QT%", tr("%1 for the graphical user interface").arg("<a href=\"https://qt-project.org/\">Qt</a>"));
	html_about.replace("%USES_LIBAV_FFMPEG%", tr("%1 or %2 (depending on your distribution) for video/audio encoding").arg("<a href=\"http://libav.org/\">libav</a>").arg("<a href=\"http://ffmpeg.org/\">ffmpeg</a>"));
	html_about.replace("%USES_ELFHACKS%", tr("%1 for hooking system functions for OpenGL recording").arg("<a href=\"https://github.com/nullkey/elfhacks\">elfhacks</a>"));
	html_about.replace("%VERSION%", PACKAGE_VERSION);
	html_about.replace("%VERSIONINFO%", GetVersionInfo().replace("\n", "<br>\n"));

	QTextBrowser *textbrowser = new QTextBrowser(this);
	textbrowser->setHtml(html_about);
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
