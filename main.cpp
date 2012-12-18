#include "StdAfx.h"
/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

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

int main(int argc, char* argv[]) {

	XInitThreads();

	QApplication application(argc, argv);
	QCoreApplication::setOrganizationName("SimpleScreenRecorder");
	QCoreApplication::setApplicationName("SimpleScreenRecorder");

	MainWindow mainwindow;
	mainwindow.show();

	return application.exec();

	/*Logger logger;
	unsigned int width = 960, height = 540, framerate = 60, samplerate = 44100;

	logger.Log("Starting ...");

	Muxer muxer(&logger, "/tmp/test-ssr-v2.mkv");
	VideoEncoder venc(&logger, &muxer, width, height, framerate);
	AudioEncoder aenc(&logger, &muxer, samplerate);
	muxer.Start();

	Synchronizer synchr(&logger, &venc, &aenc);
	for(unsigned int part = 0; part < 1; ++part) {
		if(part != 0) {
			synchr.NewSegment();
			usleep(1000000);
		}
		VideoInput vin(&logger, &synchr, width, height);
		AudioInput ain(&logger, &synchr);
		unsigned int time = 60;
		for(unsigned int i = 0; i < time; ++i) {
			usleep(1000000);
			logger.Log("(1) " + QString::number(i + 1) + "/" + QString::number(time) + " ... queue = " + QString::number(venc.GetQueuedFrameCount()));
		}
	}

	venc.Finish();
	aenc.Finish();

	logger.Log("Stopping ...");
	while(!muxer.IsDone()) {
		usleep(10000);
	}
	logger.Log("Done!");

	return 0;*/
}
