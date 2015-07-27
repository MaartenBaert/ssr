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

#include "Server.h"

#include "Common.h"
#include "ServerConnection.h"

#include <fcntl.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

Server::Server(const std::string& socket_file, bool relax_permissions) {

	m_socket_file = socket_file;
	m_relax_permissions = relax_permissions;
	m_connection_id_counter = 0;

	m_listening_socket = -1;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

	std::cerr << "[SSR-Stream] Server created." << std::endl;

}

Server::~Server() {

	Free();

	std::cerr << "[SSR-Stream] Server destroyed." << std::endl;

}

void Server::Init() {

	// create socket
	m_listening_socket = socket(AF_UNIX, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
	if(m_listening_socket == -1)
		throw std::runtime_error("Can't create listening socket! Reason: " + ErrorString());

	// unlink existing socket, if any
	unlink(m_socket_file.c_str());

	// bind socket
	sockaddr_un address;
	memset(&address, 0, sizeof(address));
	address.sun_family = AF_UNIX;
	strncpy(address.sun_path, m_socket_file.c_str(), sizeof(address.sun_path) - 1);
	if(bind(m_listening_socket, (sockaddr*) &address, sizeof(address)) == -1)
		throw std::runtime_error("Can't bind socket! Reason: " + ErrorString());

	// start listening
	if(listen(m_listening_socket, 64) == -1)
		throw std::runtime_error("Can't start listening for incoming connections! Reason: " + ErrorString());

}

void Server::Free() {
	m_connections.clear();
	if(m_listening_socket != -1) {
		close(m_listening_socket);
		m_listening_socket = -1;
	}
}

void Server::Update(int timeout) {

	// generate poll list
	std::vector<pollfd> poll_list(m_connections.size() + 1);
	for(size_t i = 0; i < m_connections.size(); ++i) {
		poll_list[i].fd = m_connections[i]->GetSocket();
		poll_list[i].events = (m_connections[i]->HasDataToSend())? POLLIN | POLLOUT : POLLIN;
	}
	size_t li = m_connections.size();
	{
		poll_list[li].fd = m_listening_socket;
		poll_list[li].events = POLLIN;
	}

	// do poll
	if(poll(poll_list.data(), poll_list.size(), timeout) == -1 && errno != EINTR)
		throw std::runtime_error("Poll failed! Reason: " + ErrorString());

	// handle events
	for(size_t i = 0; i < m_connections.size(); ++i) {
		int events = poll_list[i].events, revents = poll_list[i].revents;
		assert(!(revents & POLLNVAL));
		try {
			if(revents & POLLIN)
				m_connections[i]->ReadFromSocket();
			// The previous read may have generated data that we want to write, but we didn't necessarily ask for POLLOUT
			// during the poll so there is no way to tell whether writing is possible. In most cases writing will work,
			// and even if it doesn't work it is still safe to try because the socket is nonblocking anyway.
			// So, if we have data but we don't know whether writing is possible, then try it anyway.
			if(m_connections[i]->HasDataToSend() && (!(events & POLLOUT) || (revents & POLLOUT)))
				m_connections[i]->WriteToSocket();
			if(revents & POLLERR)
				m_connections[i]->ConnectionError();
			if(revents & POLLHUP)
				m_connections[i]->ConnectionClosed();
		} catch(std::exception& e) {
			std::cerr << "[SSR-Stream] Exception in connection " << m_connections[i]->GetID() << ": " << e.what() << std::endl;
			m_connections[i]->CloseAfterException();
		} catch(...) {
			std::cerr << "[SSR-Stream] Unknown exception in connection " << m_connections[i]->GetID() << "." << std::endl;
			m_connections[i]->CloseAfterException();
		}
	}
	{
		int revents = poll_list[li].revents;
		assert(!(revents & POLLNVAL));
		if(revents & POLLIN) {
			try {
				std::unique_ptr<ServerConnection> s(new ServerConnection(this, ++m_connection_id_counter));
				m_connections.push_back(std::move(s));
			} catch(std::exception& e) {
				std::cerr << "[SSR-Stream] Exception in new connection: " << e.what() << std::endl;
			} catch(...) {
				std::cerr << "[SSR-Stream] Unknown exception in new connection." << std::endl;
			}
			if(m_callback_connection_added) {
				try {
					m_callback_connection_added(m_connections.back().get());
				} catch(std::exception& e) {
					std::cerr << "[SSR-Stream] Exception in new connection: " << e.what() << std::endl;
				} catch(...) {
					std::cerr << "[SSR-Stream] Unknown exception in new connection." << std::endl;
				}
			}
		}
		if(revents & POLLERR)
			throw std::runtime_error("Listening socket error!");
		if(revents & POLLHUP)
			throw std::runtime_error("Listening socket closed!");
	}

	// delete closed sockets
	size_t j = 0;
	for(size_t i = 0; i < m_connections.size(); ++i) {
		if(!m_connections[i]->IsClosed()) {
			if(i != j)
				m_connections[j] = std::move(m_connections[i]);
			++j;
		}
	}
	m_connections.resize(j);

}
