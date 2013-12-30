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

#include "SSRVideoStreamWatcher.h"

#include "Logger.h"

#include <dirent.h>
#include <sys/inotify.h>
#include <sys/ioctl.h>

SSRVideoStreamWatcher::SSRVideoStreamWatcher() {

	m_fd_notify = -1;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

SSRVideoStreamWatcher::~SSRVideoStreamWatcher() {
	Free();
}

void SSRVideoStreamWatcher::Init() {

	// initialize inotify
	m_fd_notify = inotify_init1(IN_CLOEXEC | IN_NONBLOCK);
	if(m_fd_notify == -1) {
		Logger::LogError("[SSRVideoStreamWatcher::Init] " + QObject::tr("Error: Can't initialize inotify!", "don't translate 'inotify'"));
		throw SSRStreamException();
	}

	// watch shared memory directory
	if(inotify_add_watch(m_fd_notify, "/dev/shm", IN_CREATE | IN_DELETE) == -1) {
		Logger::LogError("[SSRVideoStreamWatcher::Init] " + QObject::tr("Error: Can't watch shared memory directory!"));
		throw SSRStreamException();
	}

	// get all the files that existed already
	DIR *dir = NULL;
	try {

		// open directory
		dir = opendir("/dev/shm");
		if(dir == NULL) {
			Logger::LogError("[SSRVideoStreamWatcher::Init] " + QObject::tr("Error: Can't open shared memory directory!"));
			throw SSRStreamException();
		}

		// get list of files
		for( ; ; ) {

			// get one file
			dirent *d = readdir(dir);
			if(d == NULL)
				break;

			// parse the name
			Stream stream;
			if(!ParseName(d->d_name, &stream))
				continue;

			// add the stream
			Logger::LogInfo("[SSRVideoStreamWatcher::Init] " + QObject::tr("Added pre-existing stream %1.").arg(d->d_name));
			//TODO//add_callback(stream, m_streams.size());
			m_streams.push_back(stream);

		}

		// close directory
		closedir(dir);
		dir = NULL;

	} catch(...) {
		if(dir != NULL) {
			closedir(dir);
			dir = NULL;
		}
		throw;
	}

}

void SSRVideoStreamWatcher::Free() {
	if(m_fd_notify != -1) {
		close(m_fd_notify);
		m_fd_notify = -1;
	}
}

bool SSRVideoStreamWatcher::ParseName(const std::string& name, Stream* stream) {
	std::string prefix = "ssr-video-";
	if(name.compare(0, prefix.length(), prefix) != 0)
		return false;
	size_t p1 = name.find_first_of('-', prefix.length());
	if(p1 == std::string::npos)
		return false;
	size_t p2 = name.find_first_of('-', p1 + 1);
	if(p2 == std::string::npos)
		return false;
	stream->m_pid.assign(name.begin() + prefix.length(), name.begin() + p1);
	stream->m_source.assign(name.begin() + p1 + 1, name.begin() + p2);
	stream->m_program_name.assign(name.begin() + p2 + 1, name.end());
	return true;
}

void SSRVideoStreamWatcher::HandleChanges(AddCallback add_callback, RemoveCallback remove_callback) {

	// find out how much we can read
	int len;
	if(ioctl(m_fd_notify, FIONREAD, &len) == -1) {
		Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Error: Can't get read length from inotify!", "don't translate 'inotify'"));
		throw SSRStreamException();
	}
	if(len == 0)
		return;

	// read all the changes
	std::vector<char> buffer(len);
	if(read(m_fd_notify, buffer.data(), buffer.size()) != (ssize_t) buffer.size()) {
		Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Error: Can't read from inotify!", "don't translate 'inotify'"));
		throw SSRStreamException();
	}

	// parse the changes
	size_t pos = 0;
	while(pos < buffer.size()) {

		// read the event structure
		if(buffer.size() - pos < sizeof(inotify_event)) {
			Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Error: Received partial event from inotify!", "don't translate 'inotify'"));
			throw SSRStreamException();
		}
		inotify_event *event = (inotify_event*) (buffer.data() + pos);
		pos += sizeof(inotify_event);

		// ignore events with no name
		if(event->len == 0)
			continue;

		// read the name
		if(buffer.size() - pos < event->len) {
			Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Error: Received partial name from inotify!", "don't translate 'inotify'"));
			throw SSRStreamException();
		}
		std::string name(buffer.data() + pos, event->len - 1);
		pos += event->len;

		// parse the name
		Stream stream;
		if(!ParseName(name, &stream))
			continue;

		// handle events
		if(event->mask & IN_CREATE) {
			if(std::find(m_streams.begin(), m_streams.end(), stream) == m_streams.end()) {
				Logger::LogInfo("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Added stream %1.").arg(QString::fromStdString(name)));
				add_callback(stream, m_streams.size());
				m_streams.push_back(stream);
			} else {
				Logger::LogWarning("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Warning: Added stream %1, but it exists already!").arg(QString::fromStdString(name)));
			}
		}
		if(event->mask & IN_DELETE) {
			auto p = std::find(m_streams.begin(), m_streams.end(), stream);
			if(p != m_streams.end()) {
				Logger::LogInfo("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Removed stream %1.").arg(QString::fromStdString(name)));
				remove_callback(stream, p - m_streams.begin());
				m_streams.erase(p);
			} else {
				Logger::LogWarning("[SSRVideoStreamWatcher::GetChanges] " + QObject::tr("Warning: Removed stream %1, but it does not exist!").arg(QString::fromStdString(name)));
			}
		}

	}

}
