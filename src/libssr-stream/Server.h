/*
Copyright (c) 2012-2015 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
*/

#pragma once

#include <cstdint>

#include <memory>
#include <string>
#include <vector>

class ServerConnection;

class Server {

public:
	typedef void ConnectionAddedCallback(ServerConnection* connection);
	typedef void ConnectionRemovedCallback(ServerConnection* connection);
	typedef void VideoStatsCallback(ServerConnection* connection);
	typedef void VideoFrameCallback(ServerConnection* connection);

private:
	std::string m_socket_file;
	bool m_relax_permissions;
	uint32_t m_connection_id_counter;

	std::function<ConnectionAddedCallback> m_callback_connection_added;
	std::function<ConnectionRemovedCallback> m_callback_connection_removed;
	std::function<VideoStatsCallback> m_callback_video_stats;
	std::function<VideoFrameCallback> m_callback_video_frame;

	int m_listening_socket;
	std::vector<std::unique_ptr<ServerConnection> > m_connections;

public:
	Server(const std::string& socket_file, bool relax_permissions);
	~Server();

	// Updates all connections. Timeout is in milliseconds, 0 means instant timeout, -1 means no timeout.
	void Update(int timeout);

private:
	void Init();
	void Free();

public:
	inline int GetListeningSocket() { return m_listening_socket; }

};
