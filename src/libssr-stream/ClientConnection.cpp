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

#include "ClientConnection.h"

#include "Common.h"
#include "MessageHelpers.h"
#include "Protocol.h"

#include <fcntl.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define CONNECTION_PRINT(message) \
	std::cerr << "[SSR-Stream] <" << m_name << "> " << message << std::endl;

ClientConnection::ClientConnection(const std::string& socket_file, const std::string& name) {

	m_socket_file = socket_file;
	m_name = name;

	m_socket = -1;
	m_closed = false;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

	CONNECTION_PRINT("Created.");

}

ClientConnection::~ClientConnection() {

	Free();

	CONNECTION_PRINT("Destroyed.");

}

void ClientConnection::Init() {

	// accept incoming connection
	m_socket = socket(AF_UNIX, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
	if(m_socket == -1)
		throw std::runtime_error("Can't create socket! Reason: " + ErrorString());

	// connect socket
	sockaddr_un address;
	memset(&address, 0, sizeof(address));
	address.sun_family = AF_UNIX;
	strncpy(address.sun_path, m_socket_file.c_str(), sizeof(address.sun_path) - 1);
	if(connect(m_socket, (sockaddr*) &address, sizeof(address)) == -1) {
		if(errno != EINPROGRESS)
			throw std::runtime_error("Can't connect socket! Reason: " + ErrorString());
	}

	// send name
	{
		CONNECTION_WRITE_MESSAGE(mo, MessageClientName);
		mo->message = MESSAGE_CLIENT_NAME;
		strncpy(mo->name, m_name.c_str(), sizeof(mo->name));
		CONNECTION_WRITE_MESSAGE_PUSH(mo);
	}

}

void ClientConnection::Free() {
	m_send_queue_fds.clear();
	if(m_socket != -1) {
		close(m_socket);
		m_socket = -1;
	}
}

void ClientConnection::ReadFromSocket() {

	// don't do anything if the socket is already closed
	if(m_closed)
		return;

	// get available length
	int len, res;
	do {
		res = ioctl(m_socket, FIONREAD, &len);
	} while(res == -1 && errno == EINTR);
	if(res == -1)
		throw std::runtime_error("Can't get read length! Reason: " + ErrorString());
	if(len == 0) {
		CONNECTION_PRINT("Connection closed (FIONREAD == 0).");
		m_closed = true;
		return;
	}

	// receive data
	ssize_t bytes;
	do {
		bytes = recv(m_socket, m_receive_queue.Reserve(len), len, 0);
	} while(bytes == -1 && errno == EINTR);
	if(bytes == -1)
		throw std::runtime_error("Can't read from socket! Reason: " + ErrorString());

	// was the connection closed?
	if(bytes == 0) {
		CONNECTION_PRINT("Connection closed (recv == 0).");
		m_closed = true;
		return;
	}

	// save received data
	m_receive_queue.Push(bytes);
	ProcessReceiveQueue();

}

void ClientConnection::WriteToSocket() {

	// don't do anything if the socket is already closed or there is no data
	if(m_closed || m_send_queue.IsEmpty())
		return;

	// check the number of file descriptors
	if(m_send_queue_fds.size() > SSRSTREAM_MAX_FDS)
		throw std::runtime_error("Number of queued file descriptors exceeds limit!");

	// prepare message
	// size excluding padding at end: CMSG_LEN(datasize) = CMSG_ALIGN(headersize) + datasize
	// size including padding at end: CMSG_SPACE(datasize) = CMSG_ALIGN(headersize) + CMSG_ALIGN(datasize)
	// CMSG_ALIGN is Linux-specific and should be avoided
	struct msghdr msg;
	struct iovec vec;
	char control_buffer[CMSG_SPACE(sizeof(int) * SSRSTREAM_MAX_FDS)];
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = &vec;
	msg.msg_iovlen = 1;
	msg.msg_control = control_buffer;
	msg.msg_controllen = (m_send_queue_fds.empty())? 0 : CMSG_SPACE(sizeof(int) * m_send_queue_fds.size());
	msg.msg_flags = 0;
	vec.iov_base = m_send_queue.GetData();
	vec.iov_len = m_send_queue.GetSize();
	if(!m_send_queue_fds.empty()) {
		struct cmsghdr *cmsg = CMSG_FIRSTHDR(&msg);
		cmsg->cmsg_len = CMSG_LEN(sizeof(int) * m_send_queue_fds.size());
		cmsg->cmsg_level = SOL_SOCKET;
		cmsg->cmsg_type = SCM_RIGHTS;
		int *fds = (int*) CMSG_DATA(cmsg);
		for(uint32_t i = 0; i < m_send_queue_fds.size(); i++) {
			fds[i] = m_send_queue_fds[i]->Get();
		}
	}

	// send data
	ssize_t bytes;
	do {
		bytes = sendmsg(m_socket, &msg, MSG_NOSIGNAL);
	} while(bytes == -1 && errno == EINTR);
	if(bytes == -1) {
		if(errno == EAGAIN || errno == EWOULDBLOCK)
			return; // optimistic write failed, try again later
		throw std::runtime_error("Can't write to socket! Reason: " + ErrorString());
	}

	// drop sent data
	m_send_queue.Pop(bytes);
	m_send_queue_fds.clear();

}

void ClientConnection::ConnectionError() {
	CONNECTION_PRINT("Connection error.");
	m_closed = true;
}

void ClientConnection::ConnectionClosed() {
	CONNECTION_PRINT("Connection closed.");
	m_closed = true;
}

void ClientConnection::Update(int timeout) {

	// generate poll list
	pollfd p;
	p.fd = GetSocket();
	p.events = (HasDataToSend())? POLLIN | POLLOUT : POLLIN;

	// do poll
	if(poll(&p, 1, timeout) == -1 && errno != EINTR)
		throw std::runtime_error("Poll failed! Reason: " + ErrorString());

	// handle events
	assert(!(p.revents & POLLNVAL));
	if(p.revents & POLLIN)
		ReadFromSocket();
	// The previous read may have generated data that we want to write, but we didn't necessarily ask for POLLOUT
	// during the poll so there is no way to tell whether writing is possible. In most cases writing will work,
	// and even if it doesn't work it is still safe to try because the socket is nonblocking anyway.
	// So, if we have data but we don't know whether writing is possible, then try it anyway.
	if(HasDataToSend() && (!(p.events & POLLOUT) || (p.revents & POLLOUT)))
		WriteToSocket();
	if(p.revents & POLLERR)
		ConnectionError();
	if(p.revents & POLLHUP)
		ConnectionClosed();

}

void ClientConnection::SendVideoStats(uint64_t timestamp, uint32_t fps) {
	CONNECTION_WRITE_MESSAGE(mo, MessageClientVideoStats);
	mo->message = MESSAGE_CLIENT_VIDEO_FRAME;
	mo->timestamp = timestamp;
	mo->fps = fps;
	CONNECTION_WRITE_MESSAGE_PUSH(mo);
}

void ClientConnection::SendVideoFrame(uint64_t timestamp, VideoFrame& frame) {
	CONNECTION_WRITE_MESSAGE(mo, MessageClientVideoFrame);
	mo->message = MESSAGE_CLIENT_VIDEO_FRAME;
	mo->timestamp = timestamp;
	mo->width = frame.GetWidth();
	mo->height = frame.GetHeight();
	mo->stride = frame.GetStride();
	m_send_queue_fds.push_back(frame.GetFD());
	CONNECTION_WRITE_MESSAGE_PUSH(mo);
}

void ClientConnection::ProcessReceiveQueue() {
	for( ; ; ) {
		if(m_receive_queue.GetSize() < 1)
			return;
		uint8_t message = *((uint8_t*) m_receive_queue.GetData());
		switch(message) {
			case MESSAGE_SERVER_VIDEO_SETUP: {
				CONNECTION_READ_MESSAGE(mi, MessageServerVideoSetup);
				//TODO// callback?
				CONNECTION_READ_MESSAGE_POP(mi);
				break;
			}
			case MESSAGE_SERVER_VIDEO_FRAME_RELEASE: {
				CONNECTION_READ_MESSAGE(mi, MessageServerVideoFrameRelease);
				//TODO// callback?
				CONNECTION_READ_MESSAGE_POP(mi);
				break;
			}
			default: {
				throw std::runtime_error("Unknown message: " + NumToString(message));
			}
		}
	}
}
