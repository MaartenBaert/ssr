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

#include "FileDescriptor.h"
#include "QueueBuffer.h"
#include "VideoFrame.h"

#include <cstdint>

#include <deque>
#include <string>

class Server;

class ServerConnection {

private:
	Server *m_server;
	uint32_t m_id;
	std::string m_name;

	uint64_t m_stats_timestamp;
	uint32_t m_stats_fps;

	int m_socket;
	bool m_closed;
	QueueBuffer<uint8_t> m_send_queue, m_receive_queue;
	std::deque<std::shared_ptr<FileDescriptor> > m_receive_queue_fds;

public:
	ServerConnection(Server* server, uint32_t id);
	~ServerConnection();

private:
	void Init();
	void Free();

public:
	void ReadFromSocket();
	void WriteToSocket();
	void ConnectionError();
	void ConnectionClosed();
	void CloseAfterException();

public:
	void SendVideoSetup(uint32_t frame_rate, uint32_t flags);
	void SendVideoFrameRelease();

private:
	void ProcessReceiveQueue();

public:
	inline uint32_t GetID() { return m_id; }
	inline std::string GetName() { return m_name; }
	inline int GetSocket() { return m_socket; }
	inline bool IsClosed() { return m_closed; }
	inline bool HasDataToSend() { return !m_send_queue.IsEmpty(); }

};
