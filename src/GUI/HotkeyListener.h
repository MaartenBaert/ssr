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

struct Hotkey {
	unsigned int m_keycode, m_modifiers;
	inline bool operator==(const Hotkey& other) const { return (m_keycode == other.m_keycode && m_modifiers == other.m_modifiers); }
	inline bool operator<(const Hotkey& other) const { return (m_keycode < other.m_keycode || (m_keycode == other.m_keycode && m_modifiers < other.m_modifiers)); }
};

class HotkeyCallback;
typedef std::multimap<Hotkey, HotkeyCallback*>::iterator HotkeyIterator;

class HotkeyCallback : public QObject {
	Q_OBJECT

private:
	bool m_is_bound;
	HotkeyIterator m_iterator;

public:
	HotkeyCallback();
	~HotkeyCallback();

	// X11 modifiers:
	// - Ctrl = ControlMask
	// - Shift = ShiftMask
	// - Alt = Mod1Mask
	// - Super = Mod4Mask
	void Bind(unsigned int keysym, unsigned int modifiers);
	void Unbind();

public: // internal
	void Trigger();

signals:
	void Triggered(); // important: always use a queued connection for consistent results

};

class HotkeyListener : public QObject {
	Q_OBJECT

private:
	std::multimap<Hotkey, HotkeyCallback*> m_callbacks;

	Display *m_x11_display;
	int m_x11_screen;
	Window m_x11_root;

	bool m_has_xinput2;
	int m_xinput2_opcode;
	unsigned int m_xinput2_raw_modifiers;
	unsigned long m_xinput2_ignore_serial;
	std::set<int> m_xinput2_master_keyboards;

	static HotkeyListener *s_instance;

public:
	HotkeyListener();
	~HotkeyListener();

private:
	void Init();
	void Free();

	void GrabHotkey(const Hotkey& hotkey, bool enable);
	void ProcessHotkey(const Hotkey& hotkey);

public:
	inline static HotkeyListener* GetInstance() { assert(s_instance != NULL); return s_instance; }

public: // internal
	HotkeyIterator BindCallback(unsigned int keysym, unsigned int modifiers, HotkeyCallback* callback);
	void UnbindCallback(HotkeyIterator it);

private slots:
	void ProcessEvents();

};
