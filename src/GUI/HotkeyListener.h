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

// Currently this class supports only one hotkey, and it's global because there can be only one X11 event filter.
class HotkeyListener : public QObject {
	Q_OBJECT

private:
	unsigned int m_keycode, m_modifiers;

public:
	HotkeyListener();

	// X11 modifiers:
	// - Ctrl = ControlMask
	// - Shift = ShiftMask
	// - Alt = Mod1Mask
	// - Super = Mod4Mask
	void EnableHotkey(unsigned int keysym, unsigned int modifiers);
	void DisableHotkey();

	bool EventFilter(void* message);
	static bool StaticEventFilter(void* message);

signals:
	void Triggered();

};

extern HotkeyListener g_hotkey_listener;
