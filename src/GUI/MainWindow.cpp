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

#include "Global.h"
#include "MainWindow.h"

#include "Main.h"
#include "Icons.h"
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

	LoadSettings();

}

MainWindow::~MainWindow() {

}

void MainWindow::LoadSettings() {
	QSettings settings(GetApplicationUserDir() + "/settings.conf", QSettings::IniFormat);
	m_page_input->LoadSettings(&settings);
	m_page_output->LoadSettings(&settings);
	m_page_record->LoadSettings(&settings);
}

void MainWindow::SaveSettings() {
	QSettings settings(GetApplicationUserDir() + "/settings.conf", QSettings::IniFormat);
	settings.clear();
	m_page_input->SaveSettings(&settings);
	m_page_output->SaveSettings(&settings);
	m_page_record->SaveSettings(&settings);
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

void MainWindow::GoPageWelcome() {
	m_stacked_layout->setCurrentWidget(m_page_welcome);
}
void MainWindow::GoPageInput() {
	m_stacked_layout->setCurrentWidget(m_page_input);
}
void MainWindow::GoPageOutput() {
	m_stacked_layout->setCurrentWidget(m_page_output);
	m_page_output->PageStart();
}
void MainWindow::GoPageRecord() {
	m_stacked_layout->setCurrentWidget(m_page_record);
	m_page_record->PageStart();
}
void MainWindow::GoPageDone() {
	m_stacked_layout->setCurrentWidget(m_page_done);
}
