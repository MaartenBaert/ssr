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

// A scroll area that tries to stay invisible if possible. The goal is to keep SSR functional even when the screen
// resolution is too small to show the full GUI, but without affecting the behaviour under normal conditions.
class HiddenScrollArea : public QScrollArea {
	Q_OBJECT

public:
	HiddenScrollArea(QWidget* parent);
	~HiddenScrollArea();

	virtual QSize sizeHint() const override;
	virtual QSize minimumSizeHint() const override;

};
