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

#pragma once
#include "Global.h"

#if SSR_USE_PORTAL

#include <QDBusConnection>
#include <QDBusMessage>

class PortalParent;

// Requests a screen or window to record from the XDG Desktop Portal
// ScreenCast interface (org.freedesktop.portal.ScreenCast). This is the
// standard way to obtain screen capture permission and a PipeWire stream
// under Wayland, where SSR can't access the compositor directly.
//
// Selection is retained for the session lifetime. Each capture connection calls
// OpenPipeWireRemote() to obtain a fresh remote, without selecting again.
// RemoteReady() transfers FD ownership to its receiver.
//
// Only one request/session is active at a time. Starting a new request, or
// calling Cancel(), invalidates and closes whatever came before.
//
// See: https://flatpak.github.io/xdg-desktop-portal/docs/doc-org.freedesktop.portal.ScreenCast.html
class XdgDesktopPortal : public QObject {
	Q_OBJECT

public:
	enum enum_sourcetype {
		SOURCETYPE_MONITOR = 1,
		SOURCETYPE_WINDOW  = 2,
	};

	// Common combinations, usable directly as a RequestSource() type mask.
	static const uint SOURCETYPE_ANY = SOURCETYPE_MONITOR | SOURCETYPE_WINDOW;

private:
	enum enum_state {
		STATE_IDLE,
		STATE_EXPORTING_PARENT,
		STATE_CREATING_SESSION,
		STATE_SELECTING_SOURCES,
		STATE_STARTING,
		STATE_READY,
	};

	static const QString SERVICE_NAME;
	static const QString OBJECT_PATH;
	static const QString INTERFACE_SCREENCAST;
	static const QString INTERFACE_SESSION;
	static const QString INTERFACE_REQUEST;
	static const QString INTERFACE_PROPERTIES;

	static XdgDesktopPortal *s_instance;

	QDBusConnection m_bus;
	uint m_token_counter;
	uint m_generation; // bumped on every RequestSource()/Cancel() to invalidate replies from a superseded request
	enum_state m_state;
	bool m_record_cursor;
	QString m_restore_token; // single-use token retained only while SSR runs
	QString m_requested_restore_token;
	PortalParent *m_parent = NULL;
	uint m_requested_types; // bitmask of enum_sourcetype values
	QString m_session_handle; // object path of the org.freedesktop.portal.Session, as returned (as a string) by CreateSession
	QString m_active_request_path;
	bool m_session_closed_subscribed;
	quint32 m_node_id;

public:
	XdgDesktopPortal();
	~XdgDesktopPortal();

	inline static XdgDesktopPortal* GetInstance() { assert(s_instance != NULL); return s_instance; }

	// Returns whether a request or an active session currently exists.
	inline bool IsActive() { return m_state != STATE_IDLE; }

	// Starts a new screen/window selection, cancelling anything in progress.
	// types is a bitmask of enum_sourcetype values (e.g. SOURCETYPE_ANY).
	// restore attempts to reuse the previous selection (e.g. after a cursor change).
	// The result is delivered asynchronously through the signals below.
	void RequestSource(QWidget *parent_window, uint types, bool record_cursor, bool restore = false);
	inline bool GetRecordCursor() { return m_record_cursor; }

	// Cancels any request in progress and closes the active session (if any).
	void Cancel();
	inline bool HasSource() { return m_state == STATE_READY; }
	void OpenPipeWireRemote(uint request_id);

signals:
	void SourceReady();
	// request_id lets the receiver discard replies for an earlier page visit.
	void RemoteReady(int pipewire_fd, quint32 node_id, uint request_id);

	// The user cancelled the portal's selection dialog.
	void SourceCancelled();

	// The request failed, or a previously granted session was closed
	// unexpectedly (e.g. because the user revoked it, or the compositor
	// tore it down).
	void SourceFailed(QString error_message);

private:
	QString UniqueNameEscaped();
	QString NewToken();
	QString PredictedRequestPath(const QString& token);
	void SubscribeRequest(const QString& path, const char *slot);
	void UnsubscribeRequest(const QString& path, const char *slot);

	void QueryCapabilities(uint *out_available_types, uint *out_available_cursor_modes, uint *out_version);

	void CallCreateSession();
	void CallSelectSources();
	void CallStart();

	void SubscribeSessionClosed();
	void CloseSession();

	void Fail(const QString& message);

private slots:
	void OnCreateSessionResponse(uint response, const QVariantMap& results, const QDBusMessage& message);
	void OnSelectSourcesResponse(uint response, const QVariantMap& results, const QDBusMessage& message);
	void OnStartResponse(uint response, const QVariantMap& results, const QDBusMessage& message);
	void OnSessionClosed(const QDBusMessage& message);

};

#endif
