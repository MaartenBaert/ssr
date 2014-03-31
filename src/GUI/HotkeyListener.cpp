/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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

#include "HotkeyListener.h"

HotkeyListener g_hotkey_listener;

static void GrabHotkey(const Hotkey& hotkey, bool enable) {
	// ignore state of caps lock (LockMask) and num lock (Mod2Mask)
	unsigned int masks[] = {0, LockMask, Mod2Mask, LockMask | Mod2Mask};
	for(unsigned int i = 0; i < sizeof(masks) / sizeof(masks[0]); ++i) {
		if(enable)
			XGrabKey(QX11Info::display(), hotkey.m_keycode, masks[i] | hotkey.m_modifiers, QX11Info::appRootWindow(), false, GrabModeAsync, GrabModeAsync);
		else
			XUngrabKey(QX11Info::display(), hotkey.m_keycode, masks[i] | hotkey.m_modifiers, QX11Info::appRootWindow());
	}
	QAbstractEventDispatcher::instance()->setEventFilter(&HotkeyListener::EventFilter);
}

HotkeyCallback::HotkeyCallback() {
	m_is_bound = false;
}

HotkeyCallback::~HotkeyCallback() {
	if(m_is_bound)
		g_hotkey_listener.UnbindCallback(m_iterator);
}

void HotkeyCallback::Bind(unsigned int keysym, unsigned int modifiers) {
	Unbind();
	m_iterator = g_hotkey_listener.BindCallback(keysym, modifiers, this);
	m_is_bound = true;
}

void HotkeyCallback::Unbind() {
	if(m_is_bound) {
		g_hotkey_listener.UnbindCallback(m_iterator);
		m_is_bound = false;
	}
}

void HotkeyCallback::Trigger() {
	emit Triggered();
}

HotkeyListener::HotkeyListener() {
}
HotkeyListener::~HotkeyListener() {
	assert(m_callbacks.empty());
}

HotkeyIterator HotkeyListener::BindCallback(unsigned int keysym, unsigned int modifiers, HotkeyCallback* callback) {
	Hotkey hotkey;
	hotkey.m_keycode = XKeysymToKeycode(QX11Info::display(), keysym);
	hotkey.m_modifiers = modifiers;
	if(m_callbacks.count(hotkey) == 0)
		GrabHotkey(hotkey, true);
	return m_callbacks.insert(std::make_pair(hotkey, callback));
}

void HotkeyListener::UnbindCallback(HotkeyIterator it) {
	Hotkey hotkey = it->first;
	m_callbacks.erase(it);
	if(m_callbacks.count(hotkey) == 0)
		GrabHotkey(hotkey, false);
}

bool HotkeyListener::EventFilter(void* message) {
	XEvent *ev = (XEvent*) message;
	if(ev->type == KeyPress) {
		Hotkey hotkey;
		hotkey.m_keycode = ev->xkey.keycode;
		hotkey.m_modifiers = ev->xkey.state & ~LockMask & ~Mod2Mask;
		auto range = g_hotkey_listener.m_callbacks.equal_range(hotkey);
		if(range.first != range.second) {
			for(auto it = range.first; it != range.second; ++it) {
				it->second->Trigger();
			}
			return true;
		}
	}
	return false;
}
