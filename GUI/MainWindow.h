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

#pragma once
#include "StdAfx.h"

class PageWelcome;
class PageInput;
class PageOutput;
class PageRecord;
class PageDone;

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	static const QString WINDOW_CAPTION;

private:
	QStackedLayout *m_stacked_layout;
	PageWelcome *m_page_welcome;
	PageInput *m_page_input;
	PageOutput *m_page_output;
	PageRecord *m_page_record;
	PageDone *m_page_done;

public:
	MainWindow();
	~MainWindow();

	void LoadSettings();
	void SaveSettings();

protected:
	virtual void closeEvent(QCloseEvent* event);

public:
	inline PageInput* GetPageInput() { return m_page_input; }
	inline PageOutput* GetPageOutput() { return m_page_output; }

public slots:
	void GoPageWelcome();
	void GoPageInput();
	void GoPageOutput();
	void GoPageRecord();
	void GoPageDone();

};
