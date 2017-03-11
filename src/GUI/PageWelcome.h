/*
Copyright (c) 2012-2016 Maarten Baert <maarten-baert@hotmail.com>

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
#include "Global.h"

class MainWindow;

class PageWelcome : public QWidget {
	Q_OBJECT

private:
	MainWindow *m_main_window;
	
	QComboBox *m_combobox_profile;
	QPushButton *m_pushbutton_load_profile;
	QPushButton *m_pushbutton_delete_profile;
	QLineEdit *m_lineedit_new_profile;
	QPushButton *m_pushbutton_new_profile;
	
	void ReadProfiles(QComboBox* m_combobox_profile); // basically a static function
	

public:
	PageWelcome(MainWindow* main_window);
	QString GetAnyProfile(); // returns the first profile in alphabetical order, or "default" if none exist

private slots:
	void AboutDialog();
	void LoadProfile(); // wrapper to LoadSettings
	void NewProfile(); // also a wrapper
	void DeleteProfile();

};

class DialogAbout : public QDialog {
	Q_OBJECT

private:

public:
	DialogAbout(PageWelcome* parent);

};
