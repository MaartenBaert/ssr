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

#include "MainWindow.h"

#include "Logger.h"
#include "CommandLineOptions.h"
#include "Icons.h"
#include "Dialogs.h"
#include "EnumStrings.h"
#include "NVidia.h"
#include "PageWelcome.h"
#include "PageInput.h"
#include "PageOutput.h"
#include "PageRecord.h"
#include "PageDone.h"

ENUMSTRINGS(MainWindow::enum_nvidia_disable_flipping) = {
	{MainWindow::NVIDIA_DISABLE_FLIPPING_ASK, "ask"},
	{MainWindow::NVIDIA_DISABLE_FLIPPING_YES, "yes"},
	{MainWindow::NVIDIA_DISABLE_FLIPPING_NO, "no"},
};

const QString MainWindow::WINDOW_CAPTION = "SimpleScreenRecorder";

MainWindow::MainWindow()
	: QMainWindow() {

	m_nvidia_reenable_flipping = false;
	m_old_geometry = QRect();

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

	LoadSettings();

	GoPageStart();

	// warning for non-X11 window systems (e.g. Wayland)
	if(!IsPlatformX11()) {
		MessageBox(QMessageBox::Warning, NULL, MainWindow::WINDOW_CAPTION,
				   MainWindow::tr("You are using a non-X11 window system (e.g. Wayland) which is currently not supported by SimpleScreenRecorder. "
								  "Several features will most likely not work properly. "
								  "In order to solve this, you should log out, choose a X11/Xorg session at the login screen, and then log back in."),
				   BUTTON_OK, BUTTON_OK);
	}

	// warning for glitch with proprietary NVIDIA drivers
	if(GetNVidiaDisableFlipping() == NVIDIA_DISABLE_FLIPPING_ASK || GetNVidiaDisableFlipping() == NVIDIA_DISABLE_FLIPPING_YES) {
		if(NVidiaGetFlipping()) {
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
				if(NVidiaSetFlipping(false)) {
					m_nvidia_reenable_flipping = true;
				} else {
					SetNVidiaDisableFlipping(NVIDIA_DISABLE_FLIPPING_ASK);
					MessageBox(QMessageBox::Warning, NULL, MainWindow::WINDOW_CAPTION,
							   MainWindow::tr("I couldn't disable flipping for some reason - sorry! Try disabling it in the NVIDIA control panel.",
											  "Don't translate 'flipping' unless NVIDIA does the same"),
							   BUTTON_OK, BUTTON_OK);
				}
			}
		}
	}

	// change minimum size based on screen resolution
	QSize preferred_size = minimumSizeHint() + QSize(style()->pixelMetric(QStyle::PM_ScrollBarExtent), 0);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	QSize available_size(0, 0);
	for(QScreen *screen : QApplication::screens()) {
		QSize size = screen->availableGeometry().size() - QSize(80, 80);
		available_size = (available_size.isNull())? size : available_size.boundedTo(size);
	}
#else
	QSize available_size = QApplication::desktop()->availableGeometry().size() - QSize(80, 80);
#endif
	//qDebug() << preferred_size << available_size;
	if(!available_size.isNull())
		setMinimumSize(preferred_size.boundedTo(available_size));

	// show the window if needed
	if(!CommandLineOptions::GetStartHidden()) {
		show();
	}
	m_page_record->UpdateShowHide();

	// start recording and/or activate schedule if needed
	if(CommandLineOptions::GetStartRecording()) {
		m_page_record->OnRecordStart();
	}
	if(CommandLineOptions::GetActivateSchedule()) {
		m_page_record->OnScheduleActivate();
	}

}

MainWindow::~MainWindow() {
	// nothing
}

void MainWindow::LoadSettings() {

	QSettings settings(CommandLineOptions::GetSettingsFile(), QSettings::IniFormat);

	SetNVidiaDisableFlipping(StringToEnum(settings.value("global/nvidia_disable_flipping", QString()).toString(), NVIDIA_DISABLE_FLIPPING_ASK));

	m_page_welcome->LoadSettings(&settings);
	m_page_input->LoadSettings(&settings);
	m_page_output->LoadSettings(&settings);
	m_page_record->LoadSettings(&settings);

}

void MainWindow::SaveSettings() {

	QSettings settings(CommandLineOptions::GetSettingsFile(), QSettings::IniFormat);
	settings.clear();

	settings.setValue("global/nvidia_disable_flipping", EnumToString(GetNVidiaDisableFlipping()));

	m_page_welcome->SaveSettings(&settings);
	m_page_input->SaveSettings(&settings);
	m_page_output->SaveSettings(&settings);
	m_page_record->SaveSettings(&settings);

}

bool MainWindow::IsBusy() {
	return (QApplication::activeModalWidget() != NULL || QApplication::activePopupWidget() != NULL);
}

bool MainWindow::Validate() {
	if(!m_page_input->Validate())
		return false;
	if(!m_page_output->Validate())
		return false;
	return true;
}

void MainWindow::Quit() {
	SaveSettings();
	if(m_nvidia_reenable_flipping) {
		NVidiaSetFlipping(true);
	}
	QApplication::quit();
}

void MainWindow::closeEvent(QCloseEvent* event) {
	if(m_page_record->ShouldBlockClose()) {
		event->ignore();
		return;
	}
	event->accept();
	Quit();
}

void MainWindow::GoPageStart() {
	if(m_page_welcome->GetSkipPage()) {
		m_stacked_layout->setCurrentWidget(m_page_input);
	} else {
		m_stacked_layout->setCurrentWidget(m_page_welcome);
	}
}
void MainWindow::GoPageWelcome() {
	m_stacked_layout->setCurrentWidget(m_page_welcome);
}
void MainWindow::GoPageInput() {
	m_stacked_layout->setCurrentWidget(m_page_input);
}
void MainWindow::GoPageOutput() {
	m_stacked_layout->setCurrentWidget(m_page_output);
	m_page_output->StartPage();
}
void MainWindow::GoPageRecord() {
	m_stacked_layout->setCurrentWidget(m_page_record);
	m_page_record->StartPage();
}
void MainWindow::GoPageDone() {
	m_stacked_layout->setCurrentWidget(m_page_done);
}

void MainWindow::OnShow() {
	if(IsBusy())
		return;
	if(isVisible())
		return;
	show();
	if(!m_old_geometry.isNull()) {
		setGeometry(m_old_geometry);
		m_old_geometry = QRect();
	}
	m_page_record->UpdateShowHide();
}

void MainWindow::OnHide() {
	if(IsBusy())
		return;
	if(!isVisible())
		return;
	m_old_geometry = geometry();
	hide();
	m_page_record->UpdateShowHide();
}

void MainWindow::OnShowHide() {
	if(isVisible()) {
		OnHide();
	} else {
		OnShow();
	}
}

void MainWindow::OnSysTrayActivated(QSystemTrayIcon::ActivationReason reason) {
	if(reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick) {
		OnShowHide();
	}
}
