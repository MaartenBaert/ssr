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

#include "Main.h"
#include "MainWindow.h"

#include "Version.h"

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
	QPushButton *button_continue = new QPushButton(QIcon::fromTheme("go-next"), tr("Continue"), this);

	connect(button_about, SIGNAL(clicked()), this, SLOT(AboutDialog()));
	connect(button_continue, SIGNAL(clicked()), m_main_window, SLOT(GoPageInput()));
	
	QGroupBox *group_settings = new QGroupBox(tr("Settings profiles"), this);
	{
		m_combobox_profile = new QComboBox(group_settings);
		ReadProfiles(m_combobox_profile);
		m_pushbutton_load_profile = new QPushButton(tr("Load profile"), group_settings);
		m_pushbutton_delete_profile = new QPushButton(tr("Delete profile"), group_settings);
		m_lineedit_new_profile = new QLineEdit(group_settings);
		m_pushbutton_new_profile = new QPushButton(tr("New profile"), group_settings);
		
		connect(m_pushbutton_load_profile,   SIGNAL(clicked()), this, SLOT(  LoadProfile()));
		connect(m_pushbutton_delete_profile, SIGNAL(clicked()), this, SLOT(DeleteProfile()));
		connect(m_pushbutton_new_profile,    SIGNAL(clicked()), this, SLOT(   NewProfile()));
		
		QGridLayout *layout = new QGridLayout(group_settings);
		layout->addWidget(m_combobox_profile, 0, 0);
		layout->addWidget(m_pushbutton_load_profile, 0, 1);
		layout->addWidget(m_pushbutton_delete_profile, 0, 2);
		layout->addWidget(m_lineedit_new_profile, 1, 0);
		layout->addWidget(m_pushbutton_new_profile, 1, 1, 1, 2);
	}
	// sigh... layouts can't have tooltips... (I want all the profile widgets to show the same tooltip)
	group_settings->setToolTip(tr("The settings are saved to the current profile with every page change.\n"
								  "The default profile is called \"default\".\n"
								  "Users of version 0.2.2 or older will find their settings in the \"settings\" profile."));

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
	layout->addWidget(group_settings);
	layout->addStretch();
	layout->addWidget(button_continue);

}

void PageWelcome::LoadProfile() {
	m_main_window->LoadSettings(m_combobox_profile->currentText());
}

void PageWelcome::DeleteProfile() {
	QFile::remove(GetApplicationUserDir() + "/" + m_combobox_profile->currentText() + ".conf");
	ReadProfiles(m_combobox_profile);
	m_main_window->LoadSettings(GetAnyProfile());
}

void PageWelcome::NewProfile() { 
	// QSettings constructor will create the file if it doesn't exist, so we do nothing here
	m_main_window->LoadSettings(m_lineedit_new_profile->text());
	
	// update list
	ReadProfiles(m_combobox_profile);
	
	// set the combobox to display this new profile
	m_combobox_profile->setCurrentIndex(
						m_combobox_profile->findText(m_main_window->GetProfile())
										);
}

void PageWelcome::ReadProfiles(QComboBox* combobox) {
	combobox->clear();
	// this code is basically copied from ../Main.cpp
	QDir dir(GetApplicationUserDir());
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
	dir.setNameFilters(QStringList("*.conf"));
	for(QFileInfo conffile : dir.entryInfoList())
		combobox->addItem(conffile.completeBaseName());
}

QString PageWelcome::GetAnyProfile() {
	// returns the first profile in alphabetical order, or "default" if none exist
	if (m_combobox_profile->count() < 1)
		m_combobox_profile->addItem("default");
	m_combobox_profile->setCurrentIndex(0);
	return m_combobox_profile->itemText(0);
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
	html_about.replace("%USES_QT4%", tr("%1 for the graphical user interface").arg("<a href=\"https://qt-project.org/\">Qt 4</a>"));
	html_about.replace("%USES_LIBAV_FFMPEG%", tr("%1 or %2 (depending on your distribution) for video/audio encoding").arg("<a href=\"http://libav.org/\">libav</a>").arg("<a href=\"http://ffmpeg.org/\">ffmpeg</a>"));
	html_about.replace("%USES_ELFHACKS%", tr("%1 for hooking system functions for OpenGL recording").arg("<a href=\"https://github.com/nullkey/elfhacks\">elfhacks</a>"));
	html_about.replace("%VERSION%", SSR_VERSION);
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
