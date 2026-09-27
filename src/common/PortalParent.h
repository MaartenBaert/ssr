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
#include <QPointer>
#include <QTimer>
#include <QWindow>
#include <functional>

#if SSR_USE_WAYLAND_PARENTING
struct wl_registry;
struct wl_callback;
struct zxdg_exporter_v2;
struct zxdg_exported_v2;
#endif

// Keeps the exported surface alive until the portal request/session is closed.
// All Wayland events are dispatched by Qt; no nested event loop is needed.
class PortalParent : public QObject {
private:
	QPointer<QWindow> m_window;
	QString m_identifier;
	QTimer m_timer;
	std::function<void(const QString&)> m_ready;
#if SSR_USE_WAYLAND_PARENTING
	wl_registry *m_registry = NULL;
	wl_callback *m_sync = NULL;
	zxdg_exporter_v2 *m_exporter = NULL;
	zxdg_exported_v2 *m_exported = NULL;
#endif

public:
	PortalParent(QWidget *parent_window, std::function<void(const QString&)> ready);
	~PortalParent();
	inline QString GetIdentifier() { return m_identifier; }

private:
	void Finish(const QString& identifier);
	void Release();
	bool eventFilter(QObject *object, QEvent *event) override;
};
#endif
