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

#include "XdgDesktopPortal.h"

#if SSR_USE_PORTAL

#include "Logger.h"
#include "PortalParent.h"

#include <QDBusArgument>
#include <QDBusObjectPath>
#include <QDBusPendingCall>
#include <QDBusPendingCallWatcher>
#include <QDBusPendingReply>
#include <QDBusReply>
#include <QDBusUnixFileDescriptor>

#include <fcntl.h>

const QString XdgDesktopPortal::SERVICE_NAME = QStringLiteral("org.freedesktop.portal.Desktop");
const QString XdgDesktopPortal::OBJECT_PATH = QStringLiteral("/org/freedesktop/portal/desktop");
const QString XdgDesktopPortal::INTERFACE_SCREENCAST = QStringLiteral("org.freedesktop.portal.ScreenCast");
const QString XdgDesktopPortal::INTERFACE_SESSION = QStringLiteral("org.freedesktop.portal.Session");
const QString XdgDesktopPortal::INTERFACE_REQUEST = QStringLiteral("org.freedesktop.portal.Request");
const QString XdgDesktopPortal::INTERFACE_PROPERTIES = QStringLiteral("org.freedesktop.DBus.Properties");

XdgDesktopPortal *XdgDesktopPortal::s_instance = NULL;

XdgDesktopPortal::XdgDesktopPortal()
	: m_bus(QDBusConnection::sessionBus()) {

	assert(s_instance == NULL);
	s_instance = this;

	m_token_counter = 0;
	m_generation = 0;
	m_state = STATE_IDLE;
	m_requested_types = SOURCETYPE_ANY;
	m_record_cursor = true;
	m_session_closed_subscribed = false;

}

XdgDesktopPortal::~XdgDesktopPortal() {
	Cancel();
	assert(s_instance == this);
	s_instance = NULL;
}

QString XdgDesktopPortal::UniqueNameEscaped() {
	QString name = m_bus.baseService();
	if(name.startsWith(QLatin1Char(':')))
		name.remove(0, 1);
	name.replace(QLatin1Char('.'), QLatin1Char('_'));
	return name;
}

QString XdgDesktopPortal::NewToken() {
	return QStringLiteral("ssr%1").arg(++m_token_counter);
}

QString XdgDesktopPortal::PredictedRequestPath(const QString& token) {
	return QStringLiteral("/org/freedesktop/portal/desktop/request/%1/%2").arg(UniqueNameEscaped(), token);
}

void XdgDesktopPortal::SubscribeRequest(const QString& path, const char *slot) {
	if(!m_bus.connect(SERVICE_NAME, path, INTERFACE_REQUEST, QStringLiteral("Response"), this, slot)) {
		Logger::LogWarning("[XdgDesktopPortal::SubscribeRequest] " + tr("Warning: Failed to subscribe to Request::Response signal at %1.").arg(path));
	}
}

void XdgDesktopPortal::UnsubscribeRequest(const QString& path, const char *slot) {
	m_bus.disconnect(SERVICE_NAME, path, INTERFACE_REQUEST, QStringLiteral("Response"), this, slot);
}

void XdgDesktopPortal::QueryCapabilities(uint *out_available_types, uint *out_available_cursor_modes, uint *out_version) {
	// Keep the existing defaults when properties are missing or cannot be read.
	*out_available_types = SOURCETYPE_MONITOR | SOURCETYPE_WINDOW;
	*out_available_cursor_modes = 1; // Hidden
	*out_version = 1;

	QDBusMessage msg = QDBusMessage::createMethodCall(SERVICE_NAME, OBJECT_PATH, INTERFACE_PROPERTIES, QStringLiteral("GetAll"));
	msg << INTERFACE_SCREENCAST;
	QDBusReply<QVariantMap> reply = m_bus.call(msg, QDBus::Block, 500);
	if(!reply.isValid())
		return;

	QVariantMap properties = reply.value();
	*out_version = properties.value(QStringLiteral("version"), 1u).toUInt();
	bool ok = false;
	uint types = properties.value(QStringLiteral("AvailableSourceTypes")).toUInt(&ok);
	if(ok && types != 0)
		*out_available_types = types;
	uint modes = properties.value(QStringLiteral("AvailableCursorModes")).toUInt(&ok);
	if(ok && modes != 0)
		*out_available_cursor_modes = modes;
}

void XdgDesktopPortal::RequestSource(QWidget *parent_window, uint types, bool record_cursor, bool restore) {
	QString restore_token;
	if(restore)
		restore_token = !m_restore_token.isEmpty() ? m_restore_token : m_requested_restore_token;

	// cancel/close anything that was in progress before
	Cancel();

	Logger::LogInfo("[XdgDesktopPortal::RequestSource] " + tr("Requesting screen/window selection from the desktop portal ..."));

	m_requested_types = types;
	m_record_cursor = record_cursor;
	m_requested_restore_token = restore_token;
	m_state = STATE_EXPORTING_PARENT;
	uint generation = m_generation;
	m_parent = new PortalParent(parent_window, [this, generation](const QString&) {
		if(generation != m_generation)
			return;
		CallCreateSession();
	});

}

void XdgDesktopPortal::Cancel() {
	m_restore_token.clear();
	m_requested_restore_token.clear();
	++m_generation; // invalidate any pending async replies from this point on
	if(!m_active_request_path.isEmpty()) {
		QDBusMessage msg = QDBusMessage::createMethodCall(SERVICE_NAME, m_active_request_path, INTERFACE_REQUEST, QStringLiteral("Close"));
		m_bus.asyncCall(msg);
		UnsubscribeRequest(m_active_request_path, SLOT(OnCreateSessionResponse(uint,QVariantMap,QDBusMessage)));
		UnsubscribeRequest(m_active_request_path, SLOT(OnSelectSourcesResponse(uint,QVariantMap,QDBusMessage)));
		UnsubscribeRequest(m_active_request_path, SLOT(OnStartResponse(uint,QVariantMap,QDBusMessage)));
		m_active_request_path.clear();
	}
	CloseSession();
	delete m_parent;
	m_parent = NULL;
	m_state = STATE_IDLE;
}

void XdgDesktopPortal::CallCreateSession() {

	m_state = STATE_CREATING_SESSION;

	QString token = NewToken();
	QString session_token = NewToken();
	QString path = PredictedRequestPath(token);
	m_active_request_path = path;
	SubscribeRequest(path, SLOT(OnCreateSessionResponse(uint,QVariantMap,QDBusMessage)));

	QVariantMap options;
	options.insert(QStringLiteral("handle_token"), token);
	options.insert(QStringLiteral("session_handle_token"), session_token);

	QDBusMessage msg = QDBusMessage::createMethodCall(SERVICE_NAME, OBJECT_PATH, INTERFACE_SCREENCAST, QStringLiteral("CreateSession"));
	msg << options;

	uint generation = m_generation;
	QDBusPendingCall pending = m_bus.asyncCall(msg);
	QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pending, this);
	connect(watcher, &QDBusPendingCallWatcher::finished, this, [this, watcher, path, generation]() {
		watcher->deleteLater();
		if(generation != m_generation)
			return;
		QDBusPendingReply<QDBusObjectPath> reply = *watcher;
		if(reply.isError()) {
			Fail(tr("Failed to call CreateSession: %1").arg(reply.error().message()));
			return;
		}
		QString actual_path = reply.value().path();
		if(actual_path != path) {
			UnsubscribeRequest(path, SLOT(OnCreateSessionResponse(uint,QVariantMap,QDBusMessage)));
			m_active_request_path = actual_path;
			SubscribeRequest(actual_path, SLOT(OnCreateSessionResponse(uint,QVariantMap,QDBusMessage)));
		}
	});

}

void XdgDesktopPortal::OnCreateSessionResponse(uint response, const QVariantMap& results, const QDBusMessage& message) {
	if(message.path() != m_active_request_path)
		return;
	if(m_state != STATE_CREATING_SESSION)
		return;
	UnsubscribeRequest(m_active_request_path, SLOT(OnCreateSessionResponse(uint,QVariantMap,QDBusMessage)));
	m_active_request_path.clear();
	if(response == 1) {
		Cancel();
		emit SourceCancelled();
		return;
	}
	if(response != 0) {
		Fail(tr("The desktop portal could not create a screen cast session (response code %1).").arg(response));
		return;
	}
	m_session_handle = results.value(QStringLiteral("session_handle")).toString();
	if(m_session_handle.isEmpty()) {
		Fail(tr("The desktop portal did not return a session handle."));
		return;
	}
	SubscribeSessionClosed();
	CallSelectSources();
}

void XdgDesktopPortal::CallSelectSources() {

	m_state = STATE_SELECTING_SOURCES;

	uint available_types, available_cursor_modes, version;
	QueryCapabilities(&available_types, &available_cursor_modes, &version);

	uint types = m_requested_types & available_types;
	if(types == 0)
		types = available_types; // requested type not advertised, let the portal decide what it can offer

	// Cursor mode is fixed for the session. Do not silently ignore the checkbox.
	uint cursor_mode = m_record_cursor ? 2u : 1u;
	if(!(available_cursor_modes & cursor_mode)) {
		Fail(m_record_cursor ? tr("The desktop does not support recording the cursor.")
		                    : tr("The desktop does not support hiding the cursor."));
		return;
	}

	QString token = NewToken();
	QString path = PredictedRequestPath(token);
	m_active_request_path = path;
	SubscribeRequest(path, SLOT(OnSelectSourcesResponse(uint,QVariantMap,QDBusMessage)));

	QVariantMap options;
	options.insert(QStringLiteral("handle_token"), token);
	options.insert(QStringLiteral("types"), types);
	options.insert(QStringLiteral("multiple"), false);
	options.insert(QStringLiteral("cursor_mode"), cursor_mode);
	if(version >= 4) {
		options.insert(QStringLiteral("persist_mode"), 1u); // this application lifetime only
		if(!m_requested_restore_token.isEmpty())
			options.insert(QStringLiteral("restore_token"), m_requested_restore_token);
	}
	// A submitted token cannot be reused, even if this request is cancelled.
	m_requested_restore_token.clear();

	QDBusMessage msg = QDBusMessage::createMethodCall(SERVICE_NAME, OBJECT_PATH, INTERFACE_SCREENCAST, QStringLiteral("SelectSources"));
	msg << QVariant::fromValue(QDBusObjectPath(m_session_handle)) << options;

	uint generation = m_generation;
	QDBusPendingCall pending = m_bus.asyncCall(msg);
	QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pending, this);
	connect(watcher, &QDBusPendingCallWatcher::finished, this, [this, watcher, path, generation]() {
		watcher->deleteLater();
		if(generation != m_generation)
			return;
		QDBusPendingReply<QDBusObjectPath> reply = *watcher;
		if(reply.isError()) {
			Fail(tr("Failed to call SelectSources: %1").arg(reply.error().message()));
			return;
		}
		QString actual_path = reply.value().path();
		if(actual_path != path) {
			UnsubscribeRequest(path, SLOT(OnSelectSourcesResponse(uint,QVariantMap,QDBusMessage)));
			m_active_request_path = actual_path;
			SubscribeRequest(actual_path, SLOT(OnSelectSourcesResponse(uint,QVariantMap,QDBusMessage)));
		}
	});

}

void XdgDesktopPortal::OnSelectSourcesResponse(uint response, const QVariantMap& results, const QDBusMessage& message) {
	if(message.path() != m_active_request_path)
		return;
	Q_UNUSED(results);
	if(m_state != STATE_SELECTING_SOURCES)
		return;
	UnsubscribeRequest(m_active_request_path, SLOT(OnSelectSourcesResponse(uint,QVariantMap,QDBusMessage)));
	m_active_request_path.clear();
	if(response == 1) {
		Cancel();
		emit SourceCancelled();
		return;
	}
	if(response != 0) {
		Fail(tr("The desktop portal could not configure the screen cast session (response code %1).").arg(response));
		return;
	}
	CallStart();
}

void XdgDesktopPortal::CallStart() {

	m_state = STATE_STARTING;

	QString token = NewToken();
	QString path = PredictedRequestPath(token);
	m_active_request_path = path;
	SubscribeRequest(path, SLOT(OnStartResponse(uint,QVariantMap,QDBusMessage)));

	QVariantMap options;
	options.insert(QStringLiteral("handle_token"), token);

	QDBusMessage msg = QDBusMessage::createMethodCall(SERVICE_NAME, OBJECT_PATH, INTERFACE_SCREENCAST, QStringLiteral("Start"));
	msg << QVariant::fromValue(QDBusObjectPath(m_session_handle)) << m_parent->GetIdentifier() << options;

	uint generation = m_generation;
	QDBusPendingCall pending = m_bus.asyncCall(msg);
	QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pending, this);
	connect(watcher, &QDBusPendingCallWatcher::finished, this, [this, watcher, path, generation]() {
		watcher->deleteLater();
		if(generation != m_generation)
			return;
		QDBusPendingReply<QDBusObjectPath> reply = *watcher;
		if(reply.isError()) {
			Fail(tr("Failed to call Start: %1").arg(reply.error().message()));
			return;
		}
		QString actual_path = reply.value().path();
		if(actual_path != path) {
			UnsubscribeRequest(path, SLOT(OnStartResponse(uint,QVariantMap,QDBusMessage)));
			m_active_request_path = actual_path;
			SubscribeRequest(actual_path, SLOT(OnStartResponse(uint,QVariantMap,QDBusMessage)));
		}
	});

}

void XdgDesktopPortal::OnStartResponse(uint response, const QVariantMap& results, const QDBusMessage& message) {
	if(message.path() != m_active_request_path)
		return;
	if(m_state != STATE_STARTING)
		return;
	UnsubscribeRequest(m_active_request_path, SLOT(OnStartResponse(uint,QVariantMap,QDBusMessage)));
	m_active_request_path.clear();
	if(response == 1) {
		Cancel();
		emit SourceCancelled();
		return;
	}
	if(response != 0) {
		Fail(tr("The desktop portal could not start the screen cast session (response code %1).").arg(response));
		return;
	}

	QVariant streams_variant = results.value(QStringLiteral("streams"));
	if(!streams_variant.canConvert<QDBusArgument>()) {
		Fail(tr("The desktop portal did not return any streams."));
		return;
	}

	quint32 node_id = 0;
	bool got_stream = false;

	// Must be const: QDBusArgument has separate const (demarshalling/read) and
	// non-const (marshalling/write) overloads of beginStructure()/beginArray()/etc.
	// A non-const object here would silently bind to the write overloads and
	// corrupt the read position (Qt logs "write from a read-only object" and
	// the subsequent reads produce garbage/undefined behaviour).
	const QDBusArgument arg = streams_variant.value<QDBusArgument>();
	arg.beginArray();
	while(!arg.atEnd()) {
		quint32 stream_node_id;
		QVariantMap stream_props;
		arg.beginStructure();
		arg >> stream_node_id >> stream_props;
		arg.endStructure();
		if(!got_stream) {
			node_id = stream_node_id;
			got_stream = true;
		}
	}
	arg.endArray();

	if(!got_stream) {
		Fail(tr("The desktop portal did not return any streams."));
		return;
	}

	m_restore_token = results.value(QStringLiteral("restore_token")).toString();
	m_node_id = node_id;
	m_state = STATE_READY;
	emit SourceReady();

}

void XdgDesktopPortal::OpenPipeWireRemote(uint request_id) {

	if(!HasSource()) {
		Fail(tr("No screen or window has been selected."));
		return;
	}

	QVariantMap options; // no options currently defined
	QDBusMessage msg = QDBusMessage::createMethodCall(SERVICE_NAME, OBJECT_PATH, INTERFACE_SCREENCAST, QStringLiteral("OpenPipeWireRemote"));
	msg << QVariant::fromValue(QDBusObjectPath(m_session_handle)) << options;

	uint generation = m_generation;
	QDBusPendingCall pending = m_bus.asyncCall(msg);
	QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(pending, this);
	connect(watcher, &QDBusPendingCallWatcher::finished, this, [this, watcher, generation, request_id]() {
		watcher->deleteLater();
		if(generation != m_generation)
			return;
		QDBusPendingReply<QDBusUnixFileDescriptor> reply = *watcher;
		if(reply.isError()) {
			Fail(tr("Failed to call OpenPipeWireRemote: %1").arg(reply.error().message()));
			return;
		}
		// QDBusUnixFileDescriptor closes its own fd on destruction, so duplicate
		// it for the receiver, which will hand it to pw_context_connect_fd()
		// (which takes ownership, and closes it even on failure).
		int fd = fcntl(reply.value().fileDescriptor(), F_DUPFD_CLOEXEC, 0);
		if(fd < 0) {
			Fail(tr("Failed to duplicate the PipeWire remote file descriptor."));
			return;
		}
		emit RemoteReady(fd, m_node_id, request_id);
	});

}

void XdgDesktopPortal::SubscribeSessionClosed() {
	if(m_session_closed_subscribed)
		return;
	if(m_bus.connect(SERVICE_NAME, m_session_handle, INTERFACE_SESSION, QStringLiteral("Closed"), this, SLOT(OnSessionClosed(QDBusMessage))))
		m_session_closed_subscribed = true;
}

void XdgDesktopPortal::OnSessionClosed(const QDBusMessage& message) {
	if(message.path() != m_session_handle)
		return;
	if(m_session_handle.isEmpty())
		return;
	Fail(tr("The screen cast session was closed (permission revoked, or the compositor ended it)."));
}

void XdgDesktopPortal::CloseSession() {
	if(m_session_closed_subscribed) {
		m_bus.disconnect(SERVICE_NAME, m_session_handle, INTERFACE_SESSION, QStringLiteral("Closed"), this, SLOT(OnSessionClosed(QDBusMessage)));
		m_session_closed_subscribed = false;
	}
	if(!m_session_handle.isEmpty()) {
		QDBusMessage msg = QDBusMessage::createMethodCall(SERVICE_NAME, m_session_handle, INTERFACE_SESSION, QStringLiteral("Close"));
		m_bus.asyncCall(msg); // fire and forget
		m_session_handle.clear();
	}
}

void XdgDesktopPortal::Fail(const QString& message) {
	Logger::LogError("[XdgDesktopPortal] " + message);
	Cancel();
	emit SourceFailed(message);
}

#endif
