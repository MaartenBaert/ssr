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

#pragma once
#include "Global.h"

// Buttons that can be used with the MessageBox function.
enum enum_button : int {
	BUTTON_NONE       = 0x0000,
	BUTTON_OK         = 0x0001,
	BUTTON_CANCEL     = 0x0002,
	BUTTON_YES        = 0x0004,
	BUTTON_YES_ALWAYS = 0x0008,
	BUTTON_NO         = 0x0010,
	BUTTON_NO_NEVER   = 0x0020,
};

// Shows a standard Qt dialog with translated buttons.
enum_button MessageBox(QMessageBox::Icon icon, QWidget* parent, const QString& title, const QString& text, int buttons = BUTTON_OK, enum_button default_button = BUTTON_NONE);

// Shows a simple dialog that asks the user to enter a string.
QString InputBox(QWidget* parent, const QString& title, const QString& text, const QString& value);
