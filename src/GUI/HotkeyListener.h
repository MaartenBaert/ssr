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

#pragma once
#include "Global.h"

struct HotkeyData {
	unsigned int m_keycode, m_modifiers;
	inline bool operator==(const HotkeyData& other) const { return (m_keycode == other.m_keycode && m_modifiers == other.m_modifiers); }
	inline bool operator<(const HotkeyData& other) const { return (m_keycode < other.m_keycode || (m_keycode == other.m_keycode && m_modifiers < other.m_modifiers)); }
};

class HotkeyCallback;
typedef std::multimap<HotkeyData, HotkeyCallback*>::iterator HotkeyCallbackIterator;

class HotkeyCallback : public QObject {
	Q_OBJECT

private:
	bool m_is_bound;
	HotkeyCallbackIterator m_iterator;

public:
	HotkeyCallback();
	~HotkeyCallback();

	void Bind(Qt::Key key, Qt::KeyboardModifiers modifiers);
	void Unbind();

public: // internal
	void Trigger();

signals:
	void Triggered();

};

class HotkeyListener : public QObject {
	Q_OBJECT

private:
	std::multimap<HotkeyData, HotkeyCallback*> m_callbacks;

	Display *m_x11_display;
	int m_x11_screen;
	Window m_x11_root;

	bool m_has_xinput2;
	int m_xinput2_opcode;
	unsigned int m_xinput2_raw_modifiers;
	unsigned long m_xinput2_raw_serial;
	std::set<int> m_xinput2_master_keyboards;

	static HotkeyListener *s_instance;

public:
	HotkeyListener();
	~HotkeyListener();

private:
	void Init();
	void Free();

	void GrabHotkey(const HotkeyData& hotkey, bool enable);
	void ProcessHotkey(const HotkeyData& hotkey);

public:
	inline static HotkeyListener* GetInstance() { assert(s_instance != NULL); return s_instance; }

public: // internal
	HotkeyCallbackIterator BindCallback(Qt::Key key, Qt::KeyboardModifiers modifiers, HotkeyCallback* callback);
	void UnbindCallback(HotkeyCallbackIterator it);

private slots:
	void ProcessEvents();

};
