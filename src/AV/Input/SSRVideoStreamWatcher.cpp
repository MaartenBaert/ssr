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

#include "SSRVideoStreamWatcher.h"

#include "Logger.h"

#include <dirent.h>
#include <signal.h>
#ifdef __linux__
#include <sys/inotify.h>
#endif
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

static bool ProcessExists(pid_t pid) {
	if(kill(pid, 0) == 0)
		return true; // no errors, process exists
	if(errno == ESRCH)
		return false; // process does not exist
	return true; // process exists, but isn't owned by us
}

static bool SSRVideoStreamParse(const std::string& filename, SSRVideoStream* stream) {

	// check the prefix
	std::string prefix = "video-";
	if(filename.compare(0, prefix.length(), prefix) != 0)
		return false;

	// split into parts
	size_t pos = prefix.length();
	std::array<std::string, 2> parts;
	for(size_t i = 0; i < parts.size(); ++i) {
		size_t dash = filename.find_first_of('-', pos);
		if(dash == std::string::npos)
			return false;
		parts[i] = filename.substr(pos, dash - pos);
		pos = dash + 1;
	}

	// save the parts
	stream->m_stream_name = filename.substr(prefix.length());
	if(!StringToNum(parts[0], &stream->m_creation_time))
		return false;
	if(!StringToNum(parts[1], &stream->m_process_id))
		return false;

	return true;
}

SSRVideoStreamWatcher::SSRVideoStreamWatcher(const std::string& channel, bool relax_permissions) {

	m_channel_directory = "/dev/shm/ssr-" + ((channel.empty())? "channel-" + GetUserName() : channel);
	m_relax_permissions = relax_permissions;

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

	// create channel directory (permissions may be wrong because of umask, fix this later)
	if(mkdir(m_channel_directory.c_str(), (m_relax_permissions)? 0777 : 0700) == -1) {
		if(errno != EEXIST) { // does the directory already exist?
			Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Can't create channel directory!"));
			throw SSRStreamException();
		}
	}

	// directory already exists, check ownership and permissions
	struct stat statinfo;
	if(lstat(m_channel_directory.c_str(), &statinfo) == -1) {
		Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Can't stat channel directory!"));
		throw SSRStreamException();
	}
	if(!S_ISDIR(statinfo.st_mode) || S_ISLNK(statinfo.st_mode)) {
		Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Channel directory is not a regular directory!"));
		throw SSRStreamException();
	}
	if(statinfo.st_uid == geteuid()) {
		if(chmod(m_channel_directory.c_str(), (m_relax_permissions)? 0777 : 0700) == -1) {
			Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Can't set channel directory mode!"));
			throw SSRStreamException();
		}
	} else {
		if(!m_relax_permissions) {
			Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Channel directory is owned by a different user! "
																			"Choose a different channel name, or enable relaxed file permissions to use it anyway."));
			throw SSRStreamException();
		}
	}

#ifdef __linux__
	// initialize inotify
	m_fd_notify = inotify_init1(IN_CLOEXEC | IN_NONBLOCK);
	if(m_fd_notify == -1) {
		Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Can't initialize inotify!", "don't translate 'inotify'"));
		throw SSRStreamException();
	}

	// watch channel directory
	if(inotify_add_watch(m_fd_notify, m_channel_directory.c_str(), IN_CREATE | IN_DELETE | IN_MOVED_FROM | IN_MOVED_TO) == -1) {
		Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Can't watch channel directory!"));
		throw SSRStreamException();
	}
#endif

	// get all the files that existed already
	DIR *dir = NULL;
	try {

		// open directory
		dir = opendir(m_channel_directory.c_str());
		if(dir == NULL) {
			Logger::LogError("[SSRVideoStreamWatcher::Init] " + Logger::tr("Error: Can't open channel directory!"));
			throw SSRStreamException();
		}

		// get list of files
		for( ; ; ) {

			// get one file
			dirent *d = readdir(dir);
			if(d == NULL)
				break;

			// parse the name
			SSRVideoStream stream;
			if(!SSRVideoStreamParse(d->d_name, &stream))
				continue;

			// add the stream
			Logger::LogInfo("[SSRVideoStreamWatcher::Init] " + Logger::tr("Added pre-existing stream %1.").arg(d->d_name));
			m_streams.push_back(stream);

		}

		// close directory
		closedir(dir);
		dir = NULL;

		// sort by creation time
		std::sort(m_streams.begin(), m_streams.end());

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

void SSRVideoStreamWatcher::HandleChanges(AddCallback add_callback, RemoveCallback remove_callback, void* userdata) {
#ifdef __linux__

	// find out how much we can read
	int len;
	if(ioctl(m_fd_notify, FIONREAD, &len) == -1) {
		Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + Logger::tr("Error: Can't get read length from inotify!", "don't translate 'inotify'"));
		throw SSRStreamException();
	}
	if(len > 0) {

		// read all the changes
		std::vector<char> buffer(len);
		if(read(m_fd_notify, buffer.data(), buffer.size()) != (ssize_t) buffer.size()) {
			Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + Logger::tr("Error: Can't read from inotify!", "don't translate 'inotify'"));
			throw SSRStreamException();
		}

		// parse the changes
		size_t pos = 0;
		while(pos < buffer.size()) {

			// read the event structure
			if(buffer.size() - pos < sizeof(inotify_event)) {
				Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + Logger::tr("Error: Received partial event from inotify!", "don't translate 'inotify'"));
				throw SSRStreamException();
			}
			inotify_event *event = (inotify_event*) (buffer.data() + pos);
			pos += sizeof(inotify_event);

			// ignore events with no name
			if(event->len == 0)
				continue;

			// read the name
			if(buffer.size() - pos < event->len) {
				Logger::LogError("[SSRVideoStreamWatcher::GetChanges] " + Logger::tr("Error: Received partial name from inotify!", "don't translate 'inotify'"));
				throw SSRStreamException();
			}
			std::string name(buffer.data() + pos); // the name may be padded with null bytes that should be ignored
			pos += event->len;

			// parse the name
			SSRVideoStream stream;
			if(!SSRVideoStreamParse(name, &stream))
				continue;

			// handle events
			if(event->mask & (IN_CREATE | IN_MOVED_TO)) {
				if(std::find(m_streams.begin(), m_streams.end(), stream) == m_streams.end()) {
					Logger::LogInfo("[SSRVideoStreamWatcher::GetChanges] " + Logger::tr("Added stream %1.").arg(QString::fromStdString(stream.m_stream_name)));
					m_streams.push_back(stream);
					add_callback(stream, userdata);
				}
			}
			if(event->mask & (IN_DELETE | IN_MOVED_FROM)) {
				auto p = std::find(m_streams.begin(), m_streams.end(), stream);
				if(p != m_streams.end()) {
					Logger::LogInfo("[SSRVideoStreamWatcher::GetChanges] " + Logger::tr("Removed stream %1.").arg(QString::fromStdString(stream.m_stream_name)));
					size_t index =  p - m_streams.begin();
					m_streams.erase(p);
					remove_callback(stream, index, userdata);
				}
			}

		}

	}

	// delete abandoned streams
	for(unsigned int j = m_streams.size(); j > 0; ) {
		--j;

		// does the process still exist?
		if(ProcessExists(m_streams[j].m_process_id))
			continue;

		// if the process is dead, delete the files
		for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
			std::string filename = m_channel_directory + "/videoframe" + NumToString(i) + "-" + m_streams[j].m_stream_name;
			unlink(filename.c_str());
		}
		std::string filename = m_channel_directory + "/video-" + m_streams[j].m_stream_name;
		unlink(filename.c_str());
		Logger::LogInfo("[SSRVideoStreamWatcher::Init] " + Logger::tr("Deleted abandoned stream %1.").arg(QString::fromStdString(m_streams[j].m_stream_name)));

		// remove the stream
		SSRVideoStream stream = m_streams[j];
		m_streams.erase(m_streams.begin() + j);
		remove_callback(stream, j, userdata);

	}

#endif
}
