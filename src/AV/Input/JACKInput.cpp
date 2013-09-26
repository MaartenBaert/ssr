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
#include "JACKInput.h"

#include "Logger.h"

JACKInput::JACKInput(unsigned int sample_rate) {

	m_sample_rate = sample_rate;
	m_channels = 2; // always 2 channels because the synchronizer and encoder don't support anything else at this point

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

JACKInput::~JACKInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[JACKInput::~JACKInput] Telling input thread to stop ...");
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void JACKInput::Init() {



	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&JACKInput::InputThread, this);

}

void JACKInput::Free() {

}

void JACKInput::InputThread() {
	try {

		Logger::LogInfo("[JACKInput::InputThread] Input thread started.");

		while(!m_should_stop) {

			usleep(10000); //TODO//

		}

		Logger::LogInfo("[JACKInput::InputThread] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[JACKInput::InputThread] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[JACKInput::InputThread] Unknown exception in input thread.");
	}
}
