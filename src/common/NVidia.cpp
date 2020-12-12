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

#include "NVidia.h"

bool NVidiaGetFlipping() {
	QString program = "nvidia-settings";
	QStringList args;
	args << "-tq" << "AllowFlipping";
	QProcess p;
	p.start(program, args);
	p.waitForFinished();
	if(p.exitCode() != 0)
		return false;
	QString result = p.readAll();
	return (result.trimmed() == "1");
}

bool NVidiaSetFlipping(bool enable) {
	QString program = "nvidia-settings";
	QStringList args;
	args << "-a" << ((enable)? "AllowFlipping=1" : "AllowFlipping=0");
	QProcess p;
	p.start(program, args);
	p.waitForFinished();
	if(p.exitCode() != 0)
		return false;
	return (NVidiaGetFlipping() == enable);
}
