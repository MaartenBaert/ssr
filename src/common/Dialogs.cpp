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

#include "Dialogs.h"

QMessageBox::StandardButton MessageBox(QMessageBox::Icon icon, QWidget* parent, const QString& title, const QString& text,
									   QMessageBox::StandardButtons buttons, QMessageBox::StandardButton defaultButton) {

	// create message box
	QMessageBox mb(icon, title, text, buttons, parent);
	mb.setDefaultButton(defaultButton);

	// translate standard buttons
	if(buttons & QMessageBox::Yes)
		mb.button(QMessageBox::Yes)->setText(QMessageBox::tr("&Yes"));
	if(buttons & QMessageBox::No)
		mb.button(QMessageBox::No)->setText(QMessageBox::tr("&No"));
	if(buttons & QMessageBox::Cancel)
		mb.button(QMessageBox::Cancel)->setText(QMessageBox::tr("&Cancel"));

	// show dialog
	return (QMessageBox::StandardButton) mb.exec();

}
