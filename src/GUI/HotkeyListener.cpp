/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

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

#include "Global.h"
#include "HotkeyListener.h"

HotkeyListener g_hotkey_listener;

HotkeyListener::HotkeyListener() {
	m_keycode = 0;
	m_modifiers = 0;
}

void HotkeyListener::EnableHotkey(unsigned int keysym, unsigned int modifiers) {
	DisableHotkey();
	m_keycode = XKeysymToKeycode(QX11Info::display(), keysym);
	m_modifiers = modifiers;
	// ignore state of caps lock (LockMask) and num lock (Mod2Mask)
	unsigned int masks[] = {0, LockMask, Mod2Mask, LockMask | Mod2Mask};
	for(unsigned int i = 0; i < sizeof(masks) / sizeof(masks[0]); ++i) {
		unsigned int m = masks[i] | m_modifiers;
		XGrabKey(QX11Info::display(), m_keycode, m, QX11Info::appRootWindow(), false, GrabModeAsync, GrabModeAsync);
	}
	QAbstractEventDispatcher::instance()->setEventFilter(&HotkeyListener::StaticEventFilter);
}

void HotkeyListener::DisableHotkey() {
	if(m_keycode == 0)
		return;
	QAbstractEventDispatcher::instance()->setEventFilter(NULL);
	unsigned int masks[] = {0, LockMask, Mod2Mask, LockMask | Mod2Mask};
	for(unsigned int i = 0; i < sizeof(masks) / sizeof(masks[0]); ++i) {
		unsigned int m = masks[i] | m_modifiers;
		XUngrabKey(QX11Info::display(), m_keycode, m, QX11Info::appRootWindow());
	}
	m_keycode = 0;
}

bool HotkeyListener::EventFilter(void* message) {
	XEvent *ev = (XEvent*) message;
	unsigned int modifiers = ev->xkey.state & ~LockMask & ~Mod2Mask;
	if(ev->type == KeyPress && ev->xkey.keycode == m_keycode && modifiers == m_modifiers) {
		emit Triggered();
		return true;
	}
	return false;
}

bool HotkeyListener::StaticEventFilter(void* message) {
	return g_hotkey_listener.EventFilter(message);
}
