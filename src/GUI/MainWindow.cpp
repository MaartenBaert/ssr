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

#include "MainWindow.h"

#include "Main.h"
#include "Icons.h"
#include "Dialogs.h"
#include "NVidia.h"
#include "PageWelcome.h"
#include "PageInput.h"
#include "PageOutput.h"
#include "PageRecord.h"
#include "PageDone.h"

const QString MainWindow::WINDOW_CAPTION = "SimpleScreenRecorder";

MainWindow::MainWindow()
	: QMainWindow() {

	setWindowTitle(WINDOW_CAPTION);
	setWindowIcon(g_icon_ssr);

	QWidget *centralwidget = new QWidget(this);
	setCentralWidget(centralwidget);

	m_page_welcome = new PageWelcome(this);
	m_page_input = new PageInput(this);
	m_page_output = new PageOutput(this);
	m_page_record = new PageRecord(this);
	m_page_done = new PageDone(this);

	m_stacked_layout = new QStackedLayout(centralwidget);
	m_stacked_layout->addWidget(m_page_welcome);
	m_stacked_layout->addWidget(m_page_input);
	m_stacked_layout->addWidget(m_page_output);
	m_stacked_layout->addWidget(m_page_record);
	m_stacked_layout->addWidget(m_page_done);
	m_stacked_layout->setCurrentWidget(m_page_welcome);

	LoadSettings(m_page_welcome->GetAnyProfile());

	// warning for glitch with proprietary NVIDIA drivers
	if(GetNVidiaDisableFlipping() == NVIDIA_DISABLE_FLIPPING_ASK || GetNVidiaDisableFlipping() == NVIDIA_DISABLE_FLIPPING_YES) {
		if(NVidiaDetectFlipping()) {
			bool disable;
			if(GetNVidiaDisableFlipping() == NVIDIA_DISABLE_FLIPPING_ASK) {
				enum_button button = MessageBox(QMessageBox::Warning, NULL, MainWindow::WINDOW_CAPTION,
												MainWindow::tr("SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. "
															   "This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?\n\n"
															   "You can also change this option manually in the NVIDIA control panel.", "Don't translate 'flipping' unless NVIDIA does the same"),
												BUTTON_YES | BUTTON_YES_ALWAYS | BUTTON_NO | BUTTON_NO_NEVER, BUTTON_YES);
				if(button == BUTTON_YES_ALWAYS)
					SetNVidiaDisableFlipping(NVIDIA_DISABLE_FLIPPING_YES);
				if(button == BUTTON_NO_NEVER)
					SetNVidiaDisableFlipping(NVIDIA_DISABLE_FLIPPING_NO);
				disable = (button == BUTTON_YES || button == BUTTON_YES_ALWAYS);
			} else {
				disable = true;
			}
			if(disable) {
				if(!NVidiaDisableFlipping()) {
					SetNVidiaDisableFlipping(NVIDIA_DISABLE_FLIPPING_ASK);
					MessageBox(QMessageBox::Warning, NULL, MainWindow::WINDOW_CAPTION,
							   MainWindow::tr("I couldn't disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.",
											  "Don't translate 'flipping' unless NVIDIA does the same"),
							   BUTTON_OK, BUTTON_OK);
				}
			}
		}
	}

}

MainWindow::~MainWindow() {

}

void MainWindow::LoadSettings(QString profile /*= "settings"*/) {
	if (profile == "")
		profile = "settings";
	
	m_settings_profile = profile;
	
	QSettings settings(GetApplicationUserDir() + "/" + profile + ".conf", QSettings::IniFormat);

	SetNVidiaDisableFlipping(FindNVidiaDisableFlipping(settings.value("global/nvidia_disable_flipping", QString()).toString(), NVIDIA_DISABLE_FLIPPING_ASK));

	m_page_input->LoadSettings(&settings);
	m_page_output->LoadSettings(&settings);
	m_page_record->LoadSettings(&settings);

}

void MainWindow::SaveSettings() {

	QSettings settings(GetApplicationUserDir() + "/" + m_settings_profile + ".conf", QSettings::IniFormat);
	settings.clear();

	settings.setValue("global/nvidia_disable_flipping", GetNVidiaDisableFlippingName(GetNVidiaDisableFlipping()));

	m_page_input->SaveSettings(&settings);
	m_page_output->SaveSettings(&settings);
	m_page_record->SaveSettings(&settings);

}

MainWindow::enum_nvidia_disable_flipping MainWindow::FindNVidiaDisableFlipping(const QString& name, enum_nvidia_disable_flipping fallback) {
	if(name == "ask") return NVIDIA_DISABLE_FLIPPING_ASK;
	if(name == "yes") return NVIDIA_DISABLE_FLIPPING_YES;
	if(name == "no")  return NVIDIA_DISABLE_FLIPPING_NO;
	return fallback;
}

QString MainWindow::GetNVidiaDisableFlippingName(enum_nvidia_disable_flipping flipping) {
	switch(flipping) {
		case NVIDIA_DISABLE_FLIPPING_ASK: return "ask";
		case NVIDIA_DISABLE_FLIPPING_YES: return "yes";
		case NVIDIA_DISABLE_FLIPPING_NO:  return "no";
		default: assert(false); return QString();
	}
}

void MainWindow::closeEvent(QCloseEvent* event) {
	if(m_page_record->ShouldBlockClose()) {
		event->ignore();
		return;
	}
	SaveSettings();
	event->accept();
	QApplication::quit();
}

// save settings at every page, just because

void MainWindow::GoPageWelcome() {
	m_stacked_layout->setCurrentWidget(m_page_welcome);
	SaveSettings();
}
void MainWindow::GoPageInput() {
	m_stacked_layout->setCurrentWidget(m_page_input);
	SaveSettings();
}
void MainWindow::GoPageOutput() {
	m_stacked_layout->setCurrentWidget(m_page_output);
	m_page_output->PageStart();
	SaveSettings();
}
void MainWindow::GoPageRecord() {
	m_stacked_layout->setCurrentWidget(m_page_record);
	m_page_record->StartPage();
	SaveSettings();
}
void MainWindow::GoPageDone() {
	m_stacked_layout->setCurrentWidget(m_page_done);
}
