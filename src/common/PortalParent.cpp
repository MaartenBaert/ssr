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

#include "PortalParent.h"

#if SSR_USE_PORTAL
#include "Logger.h"
#include <QPlatformSurfaceEvent>
#if SSR_USE_WAYLAND_PARENTING
#include <qpa/qplatformnativeinterface.h>
#include <wayland-client.h>
#include "xdg-foreign-client-protocol.h"
#endif

PortalParent::PortalParent(QWidget *parent_window, std::function<void(const QString&)> ready)
	: m_ready(ready) {
	m_timer.setSingleShot(true);
	connect(&m_timer, &QTimer::timeout, this, [this]() {
		Release();
		Finish(QString());
	});

	if(parent_window == NULL) {
		Finish(QString());
		return;
	}
	QWidget *window = parent_window->window();
	// This is Qt's platform, not XDG_SESSION_TYPE: an XWayland window has an XID.
	if(QGuiApplication::platformName() == QStringLiteral("xcb")) {
		Finish(QStringLiteral("x11:%1").arg(qulonglong(window->winId()), 0, 16));
		return;
	}
	if(!QGuiApplication::platformName().startsWith(QStringLiteral("wayland"))) {
		Finish(QString());
		return;
	}

#if SSR_USE_WAYLAND_PARENTING
	window->winId(); // ensure the top-level native window exists
	m_window = window->windowHandle();
	QPlatformNativeInterface *native = QGuiApplication::platformNativeInterface();
	auto *display = static_cast<wl_display*>(native->nativeResourceForIntegration("wl_display"));
	if(!m_window || display == NULL) {
		Finish(QString());
		return;
	}
	m_window->installEventFilter(this);
	connect(m_window.data(), &QObject::destroyed, this, [this]() {
		Release();
		Finish(QString());
	});

	m_registry = wl_display_get_registry(display);
	static const wl_registry_listener registry_listener = {
		[](void *data, wl_registry *registry, uint32_t name, const char *interface, uint32_t) {
			auto *self = static_cast<PortalParent*>(data);
			if(strcmp(interface, "zxdg_exporter_v2") == 0 && self->m_exporter == NULL)
				self->m_exporter = static_cast<zxdg_exporter_v2*>(wl_registry_bind(registry, name, &zxdg_exporter_v2_interface, 1));
		},
		[](void*, wl_registry*, uint32_t) {}
	};
	wl_registry_add_listener(m_registry, &registry_listener, this);
	m_sync = wl_display_sync(display);
	static const wl_callback_listener sync_listener = {
		[](void *data, wl_callback*, uint32_t) {
			auto *self = static_cast<PortalParent*>(data);
			wl_callback_destroy(self->m_sync);
			self->m_sync = NULL;
			wl_registry_destroy(self->m_registry);
			self->m_registry = NULL;
			auto *native = QGuiApplication::platformNativeInterface();
			auto *surface = self->m_window ? static_cast<wl_surface*>(native->nativeResourceForWindow("surface", self->m_window)) : NULL;
			if(self->m_exporter == NULL || surface == NULL) {
				self->Release();
				self->Finish(QString());
				return;
			}
			self->m_exported = zxdg_exporter_v2_export_toplevel(self->m_exporter, surface);
			static const zxdg_exported_v2_listener exported_listener = {
				[](void *data, zxdg_exported_v2*, const char *handle) {
					auto *self = static_cast<PortalParent*>(data);
					self->Finish(QStringLiteral("wayland:") + QString::fromUtf8(handle));
				}
			};
			zxdg_exported_v2_add_listener(self->m_exported, &exported_listener, self);
		}
	};
	wl_callback_add_listener(m_sync, &sync_listener, this);
	// Parenting is optional; an unsupported/unresponsive compositor must not
	// prevent selection. This deadline never blocks the GUI.
	m_timer.start(500);
#else
	Finish(QString());
#endif
}

PortalParent::~PortalParent() {
	Release();
}

void PortalParent::Finish(const QString& identifier) {
	m_timer.stop();
	m_identifier = identifier;
	if(!m_ready)
		return;
	auto ready = m_ready;
	m_ready = nullptr;
	if(identifier.isEmpty())
		Logger::LogWarning("[PortalParent] " + tr("Could not identify the parent window for the desktop portal dialog."));
	// Also defer the X11/fallback paths so callers can store this object first.
	QTimer::singleShot(0, this, [this, ready]() { ready(m_identifier); });
}

void PortalParent::Release() {
	m_identifier.clear();
#if SSR_USE_WAYLAND_PARENTING
	if(m_exported != NULL) {
		zxdg_exported_v2_destroy(m_exported);
		m_exported = NULL;
	}
	if(m_exporter != NULL) {
		zxdg_exporter_v2_destroy(m_exporter);
		m_exporter = NULL;
	}
	if(m_sync != NULL) {
		wl_callback_destroy(m_sync);
		m_sync = NULL;
	}
	if(m_registry != NULL) {
		wl_registry_destroy(m_registry);
		m_registry = NULL;
	}
#endif
}

bool PortalParent::eventFilter(QObject *object, QEvent *event) {
	if(object == m_window && event->type() == QEvent::PlatformSurface &&
			static_cast<QPlatformSurfaceEvent*>(event)->surfaceEventType() == QPlatformSurfaceEvent::SurfaceAboutToBeDestroyed) {
		Release();
		Finish(QString());
	}
	return QObject::eventFilter(object, event);
}
#endif
