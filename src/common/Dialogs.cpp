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

#include "Dialogs.h"

enum_button MessageBox(QMessageBox::Icon icon, QWidget* parent, const QString& title, const QString& text, int buttons, enum_button default_button) {

	// create message box
	QMessageBox mb(icon, title, text, QMessageBox::NoButton, parent);

	// button data
	struct ButtonData {
		enum_button button;
		QString text;
		QMessageBox::ButtonRole role;
		QPushButton *ptr;
	};
	ButtonData buttondata[] = {
		{BUTTON_OK        , QDialogButtonBox::tr("&OK")        , QMessageBox::AcceptRole, NULL},
		{BUTTON_CANCEL    , QDialogButtonBox::tr("&Cancel")    , QMessageBox::RejectRole, NULL},
		{BUTTON_YES       , QDialogButtonBox::tr("&Yes")       , QMessageBox::YesRole   , NULL},
		{BUTTON_YES_ALWAYS, QDialogButtonBox::tr("Yes, always"), QMessageBox::YesRole   , NULL},
		{BUTTON_NO        , QDialogButtonBox::tr("&No")        , QMessageBox::NoRole    , NULL},
		{BUTTON_NO_NEVER  , QDialogButtonBox::tr("No, never")  , QMessageBox::NoRole    , NULL},
	};

	// add buttons
	for(unsigned int i = 0; i < sizeof(buttondata) / sizeof(buttondata[0]); ++i) {
		if(buttons & buttondata[i].button) {
			buttondata[i].ptr = mb.addButton(buttondata[i].text, buttondata[i].role);
			if(default_button == buttondata[i].button)
				mb.setDefaultButton(buttondata[i].ptr);
		}
	}

	// show dialog
	mb.exec();

	// check which button was pressed
	QAbstractButton *clicked = mb.clickedButton();
	if(clicked == NULL)
		return BUTTON_NONE;
	for(unsigned int i = 0; i < sizeof(buttondata) / sizeof(buttondata[0]); ++i) {
		if(clicked == buttondata[i].ptr) {
			return buttondata[i].button;
		}
	}
	return BUTTON_NONE;

}

QString InputBox(QWidget* parent, const QString& title, const QString& text, const QString& value) {

	QInputDialog dialog(parent);
	dialog.setInputMode(QInputDialog::TextInput);
	dialog.setOkButtonText(QDialogButtonBox::tr("&OK"));
	dialog.setCancelButtonText(QDialogButtonBox::tr("&Cancel"));

	dialog.setWindowTitle(title);
	dialog.setLabelText(text);
	dialog.setTextValue(value);

	if(!dialog.exec())
		return QString();
	return dialog.textValue();

}
