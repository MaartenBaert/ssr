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

#include "ServerConnection.h"

#include "Common.h"
#include "MessageHelpers.h"
#include "Protocol.h"
#include "Server.h"

#include <fcntl.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define CONNECTION_PRINT(message) \
	std::cerr << "[SSR-Stream] <" << m_id << "|" << m_name << "> " << message << std::endl;

ServerConnection::ServerConnection(Server* server, uint32_t id) {

	m_server = server;
	m_id = id;
	m_name = "---";

	m_stats_timestamp = 0;
	m_stats_fps = 0;

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

ServerConnection::~ServerConnection() {

	Free();

	CONNECTION_PRINT("Destroyed.");

}

void ServerConnection::Init() {

	// accept incoming connection
	do {
		m_socket = accept4(m_server->GetListeningSocket(), NULL, NULL, SOCK_NONBLOCK | SOCK_CLOEXEC);
	} while(m_socket == -1 && errno == EINTR);
	if(m_socket == -1)
		throw std::runtime_error("Can't accept incoming connection! Reason: " + ErrorString());

}

void ServerConnection::Free() {
	if(m_socket != -1) {
		close(m_socket);
		m_socket = -1;
	}
}

void ServerConnection::ReadFromSocket() {

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

	// prepare message
	// size excluding padding at end: CMSG_LEN(datasize) = CMSG_ALIGN(headersize) + datasize
	// size including padding at end: CMSG_SPACE(datasize) = CMSG_ALIGN(headersize) + CMSG_ALIGN(datasize)
	// CMSG_ALIGN is Linux-specific and should be avoided
	struct msghdr msg;
	struct iovec vec;
	char control_buffer[CMSG_SPACE(sizeof(int) * SSRSTREAM_MAX_FDS)];
	//TODO// the above assumes a single message with many FDs, is this correct?
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = &vec;
	msg.msg_iovlen = 1;
	msg.msg_control = control_buffer;
	msg.msg_controllen = sizeof(control_buffer);
	msg.msg_flags = 0;
	vec.iov_base = m_receive_queue.Reserve(len);
	vec.iov_len = len;

	// receive data
	ssize_t bytes;
	do {
		bytes = recvmsg(m_socket, &msg, 0);
	} while(bytes == -1 && errno == EINTR);
	if(bytes == -1)
		throw std::runtime_error("Can't read from socket! Reason: " + ErrorString());

	std::cerr << "[Ancillary] Received " << bytes << " bytes." << std::endl;
	try {

		// make sure we got all control data
		if(msg.msg_flags & MSG_CTRUNC)
			throw std::runtime_error("Control data was lost during read from socket!");

		// decode control data, save all file descriptors
		for(struct cmsghdr *cmsg = CMSG_FIRSTHDR(&msg); cmsg != NULL; cmsg = CMSG_NXTHDR(&msg, cmsg)) {
			if(cmsg->cmsg_level == SOL_SOCKET && cmsg->cmsg_type == SCM_RIGHTS) {
				std::cerr << "[Ancillary]   +- SOL_SOCKET/SCM_RIGHTS" << std::endl;
				uint32_t num_fds = (cmsg->cmsg_len - CMSG_LEN(0)) / sizeof(int);
				int *fds = (int*) CMSG_DATA(cmsg);
				for(uint32_t i = 0; i < num_fds; i++) {
					std::cerr << "[Ancillary]     +- FD: " << fds[i] << std::endl;
					m_receive_queue_fds.push_back(std::make_shared<FileDescriptor>(fds[i]));
					fds[i] = -1;
				}
			}
		}

	} catch(...) {

		// decode control data again, close all remaining file descriptors
		for(struct cmsghdr *cmsg = CMSG_FIRSTHDR(&msg); cmsg != NULL; cmsg = CMSG_NXTHDR(&msg, cmsg)) {
			if(cmsg->cmsg_level == SOL_SOCKET && cmsg->cmsg_type == SCM_RIGHTS) {
				uint32_t num_fds = (cmsg->cmsg_len - CMSG_LEN(0)) / sizeof(int);
				int *fds = (int*) CMSG_DATA(cmsg);
				for(uint32_t i = 0; i < num_fds; i++) {
					if(fds[i] == -1) {
						close(fds[i]);
					}
				}
			}
		}

		throw;
	}

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

void ServerConnection::WriteToSocket() {

	// don't do anything if the socket is already closed or there is no data
	if(m_closed || m_send_queue.IsEmpty())
		return;

	// send data
	ssize_t bytes;
	do {
		bytes = send(m_socket, m_send_queue.GetData(), m_send_queue.GetSize(), MSG_NOSIGNAL);
	} while(bytes == -1 && errno == EINTR);
	if(bytes == -1) {
		if(errno == EAGAIN || errno == EWOULDBLOCK)
			return; // optimistic write failed, try again later
		throw std::runtime_error("Can't write to socket! Reason: " + ErrorString());
	}

	// drop sent data
	m_send_queue.Pop(bytes);

}

void ServerConnection::ConnectionError() {
	CONNECTION_PRINT("Connection error.");
	m_closed = true;
}

void ServerConnection::ConnectionClosed() {
	CONNECTION_PRINT("Connection closed.");
	m_closed = true;
}

void ServerConnection::CloseAfterException() {
	CONNECTION_PRINT("Connection closed (internal error).");
	m_closed = true;
}

void ServerConnection::SendVideoSetup(uint32_t frame_rate, uint32_t flags) {
	CONNECTION_WRITE_MESSAGE(mo, MessageServerVideoSetup);
	mo->message = MESSAGE_SERVER_VIDEO_SETUP;
	mo->frame_rate = frame_rate;
	mo->flags = flags;
	CONNECTION_WRITE_MESSAGE_PUSH(mo);
}

void ServerConnection::SendVideoFrameRelease() {
	CONNECTION_WRITE_MESSAGE(mo, MessageServerVideoFrameRelease);
	mo->message = MESSAGE_SERVER_VIDEO_FRAME_RELEASE;
	CONNECTION_WRITE_MESSAGE_PUSH(mo);
}

void ServerConnection::ProcessReceiveQueue() {
	for( ; ; ) {
		if(m_receive_queue.GetSize() < 1)
			return;
		uint8_t message = *((uint8_t*) m_receive_queue.GetData());
		switch(message) {
			case MESSAGE_CLIENT_NAME: {
				CONNECTION_READ_MESSAGE(mi, MessageClientName);
				m_name = std::string(mi->name, strnlen(mi->name, sizeof(mi->name)));
				CONNECTION_PRINT("Name changed.");
				CONNECTION_READ_MESSAGE_POP(mi);
				break;
			}
			case MESSAGE_CLIENT_VIDEO_STATS: {
				CONNECTION_READ_MESSAGE(mi, MessageClientVideoStats);
				m_stats_timestamp = mi->timestamp;
				m_stats_fps = mi->fps;
				//TODO// callback?
				CONNECTION_READ_MESSAGE_POP(mi);
				break;
			}
			case MESSAGE_CLIENT_VIDEO_FRAME: {
				CONNECTION_READ_MESSAGE(mi, MessageClientVideoFrame);
				if(mi->width < SSRSTREAM_MIN_WIDTH || mi->height < SSRSTREAM_MIN_HEIGHT)
					throw std::runtime_error("Video frame width or height is too small!");
				if(mi->width > SSRSTREAM_MAX_WIDTH || mi->height > SSRSTREAM_MAX_HEIGHT)
					throw std::runtime_error("Video frame width or height is too large!");
				if((uint32_t) abs(mi->stride) < mi->width * 4 || (uint32_t) abs(mi->stride) > SSRSTREAM_MAX_STRIDE)
					throw std::runtime_error("Video frame stride is invalid!");
				if(m_receive_queue_fds.empty())
					throw std::runtime_error("Video frame did not attach a file descriptor!");
				std::unique_ptr<VideoFrame> video_frame(new VideoFrame(mi->width, mi->height, mi->stride, m_receive_queue_fds.front()));
				m_receive_queue_fds.pop_front();
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
