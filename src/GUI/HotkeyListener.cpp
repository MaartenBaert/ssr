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

#include "HotkeyListener.h"

#include "Logger.h"

/*
In theory, global hotkeys are pretty easy to implement since X11 has functions specifically for this purpose (XGrabKey/XUngrabKey).
Unfortunately, some programs (particularly games that use SDL < 2.0) abuse the keyboard grab function in X11: They simply grab the
entire keyboard all the time, which breaks all global hotkeys (not just SSR, also Alt+Tab, volume keys, ...). There is no way to
avoid this: 'active' grabs (= grab the entire keyboard) always get priority over 'passive' grabs (= grab one key).

The Mumble devs apparently found a solution, but it's ugly and relies on XInput2, so I still keep the original code as a fallback.

XInput2 has two types of keyboards: there is a 'master' keyboard that is normally used by applications, and one or more 'slave'
keyboards that correspond to actual physical keyboards. A normal keyboard grab only affects the master keyboard, not the slaves
attached to that master. So even when a misbehaving application grabs the entire keyboard, it is still possible to monitor hotkeys
simply by monitoring all slaves (in case you were wondering: no, monitoring the master keyboard doesn't work, I tried that).

So now there are two possible solutions:
(1) Create passive grabs for the hotkeys on all slave keyboards.
	Disadvantages: Requires hotplug detection because slaves can change, could be problematic if the user picks a really stupid
	hotkey (like Esc) and some application does a full grab with that hotkey as the only way out, creates problems with modifiers
	(example for Ctrl+R hotkey: press Ctrl, press R, release Ctrl, release R -> Ctrl is now stuck until it is pressed again).
(2) Create passive grabs for the hotkeys on all master keyboards, and use raw input to monitor all slaves.
	Disadvantages: Modifiers must be emulated, serials must be stored to avoid double triggering of the same hotkey, misbehaving
	clients will still receive key presses, key repeat becomes impossible, wastes some CPU since it monitors all keys all the time.

I decided to go with (2) because it sounds more reliable. It's also closer to what Mumble does.
XInput2 makes it easy to detect key repeat, so I decided to ignore those for consistency (it didn't really serve a purpose anyway).

This code is partially based on the global hotkey code from Mumble:
https://github.com/mumble-voip/mumble/blob/master/src/mumble/GlobalShortcut_unix.cpp

This is a good source of information about Xlib cookie events and XInput2 (check the other pages as well):
http://who-t.blogspot.be/2009/07/xlib-cookie-events.html
*/

HotkeyListener *HotkeyListener::s_instance = NULL;

HotkeyCallback::HotkeyCallback() {
	m_is_bound = false;
}

HotkeyCallback::~HotkeyCallback() {
	if(m_is_bound)
		HotkeyListener::GetInstance()->UnbindCallback(m_iterator);
}

void HotkeyCallback::Bind(unsigned int keysym, unsigned int modifiers) {
	Unbind();
	m_iterator = HotkeyListener::GetInstance()->BindCallback(keysym, modifiers, this);
	m_is_bound = true;
}

void HotkeyCallback::Unbind() {
	if(m_is_bound) {
		HotkeyListener::GetInstance()->UnbindCallback(m_iterator);
		m_is_bound = false;
	}
}

void HotkeyCallback::Trigger() {
	emit Triggered();
}

HotkeyListener::HotkeyListener() {
	assert(s_instance == NULL);

	m_x11_display = NULL;
	m_x11_screen = 0;
	m_has_xinput2 = false;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

	s_instance = this;
}

HotkeyListener::~HotkeyListener() {
	assert(s_instance == this);

	assert(m_callbacks.empty());
	Free();

	s_instance = NULL;
}

void HotkeyListener::Init() {

	// open X11 display
	m_x11_display = XOpenDisplay(NULL);
	if(m_x11_display == NULL) {
		Logger::LogError("[HotkeyListener::Init] " + Logger::tr("Error: Can't open X display!", "Don't translate 'display'"));
		throw X11Exception();
	}
	m_x11_screen = DefaultScreen(m_x11_display);
	m_x11_root = RootWindow(m_x11_display, m_x11_screen);

	// try to use XInput2
	int first_event, first_error;
	if(XQueryExtension(m_x11_display, "XInputExtension", &m_xinput2_opcode, &first_event, &first_error)) {
		int major = 2, minor = 0;
		if(XIQueryVersion(m_x11_display, &major, &minor) == Success) {

			// initialize variables
			m_has_xinput2 = true;
			m_xinput2_raw_modifiers = 0;
			m_xinput2_ignore_serial = (unsigned long) -1;

			// choose the events that we want to listen to
			unsigned char mask[(XI_LASTEVENT + 7) / 8] = {0};
			XISetMask(mask, XI_RawKeyPress);
			XISetMask(mask, XI_RawKeyRelease);

			// create event mask
			XIEventMask evmask;
			evmask.deviceid = XIAllDevices;
			evmask.mask_len = sizeof(mask);
			evmask.mask = mask;

			// apply it
			XISelectEvents(m_x11_display, m_x11_root, &evmask, 1);

			// get all master keyboards (luckily hotplug support is not really needed here)
			m_xinput2_master_keyboards.clear();
			int device_count;
			XIDeviceInfo *device_info = XIQueryDevice(m_x11_display, XIAllMasterDevices, &device_count);
			if(device_info != NULL) {
				for(int i = 0; i < device_count; ++i) {
					if(device_info[i].use == XIMasterKeyboard)
						m_xinput2_master_keyboards.insert(device_info[i].deviceid);
				}
				XIFreeDeviceInfo(device_info);
			}

		}
	}
	if(!m_has_xinput2)
		Logger::LogWarning("[HotkeyListener::Init] " + Logger::tr("Warning: XInput2 is not supported by X server, hotkeys may not work in some applications.", "Don't translate 'XInput2'"));

	// send everything (normally this is done by XPending/XNextEvent, but those won't be called until there is some data)
	XFlush(m_x11_display);

	connect(new QSocketNotifier(ConnectionNumber(m_x11_display), QSocketNotifier::Read, this), SIGNAL(activated(int)), this, SLOT(ProcessEvents()));

}

void HotkeyListener::Free() {
	if(m_x11_display != NULL) {
		XCloseDisplay(m_x11_display);
		m_x11_display = NULL;
	}
}

void HotkeyListener::GrabHotkey(const Hotkey& hotkey, bool enable) {

	// we need to grab multiple modifiers combinations to ignore the state of caps lock (LockMask) and num lock (Mod2Mask)
	unsigned int masks[] = {0, LockMask, Mod2Mask, LockMask | Mod2Mask};

	// do we have XInput2?
	if(m_has_xinput2) {
		for(int device_id : m_xinput2_master_keyboards) {

			// choose the events that we want to listen to
			unsigned char mask[(XI_LASTEVENT + 7) / 8] = {0};
			XISetMask(mask, XI_KeyPress);
			XISetMask(mask, XI_KeyRelease);

			// create event mask
			XIEventMask evmask;
			evmask.deviceid = device_id;
			evmask.mask_len = sizeof(mask);
			evmask.mask = mask;

			// create grab modifiers
			XIGrabModifiers modifiers[4];
			for(unsigned int i = 0; i < sizeof(masks) / sizeof(masks[0]); ++i) {
				modifiers[i].modifiers = hotkey.m_modifiers | masks[i];
				modifiers[i].status = 0;
			}

			// grab/ungrab
			if(enable)
				XIGrabKeycode(m_x11_display, device_id, hotkey.m_keycode, m_x11_root, GrabModeAsync, GrabModeAsync, false, &evmask, sizeof(modifiers) / sizeof(modifiers[0]), modifiers);
			else
				XIUngrabKeycode(m_x11_display, device_id, hotkey.m_keycode, m_x11_root, sizeof(modifiers) / sizeof(modifiers[0]), modifiers);

		}
	} else {
		for(unsigned int i = 0; i < sizeof(masks) / sizeof(masks[0]); ++i) {
			if(enable)
				XGrabKey(m_x11_display, hotkey.m_keycode, hotkey.m_modifiers | masks[i], m_x11_root, false, GrabModeAsync, GrabModeAsync);
			else
				XUngrabKey(m_x11_display, hotkey.m_keycode, hotkey.m_modifiers | masks[i], m_x11_root);
		}
	}

	// send everything (normally this is done by XPending/XNextEvent, but those won't be called until there is some data)
	XFlush(m_x11_display);

}

void HotkeyListener::ProcessHotkey(const Hotkey& hotkey) {
	auto range = m_callbacks.equal_range(hotkey);
	if(range.first != range.second) {
		for(auto it = range.first; it != range.second; ++it) {
			it->second->Trigger();
		}
	}
}

HotkeyIterator HotkeyListener::BindCallback(unsigned int keysym, unsigned int modifiers, HotkeyCallback* callback) {
	Hotkey hotkey;
	hotkey.m_keycode = XKeysymToKeycode(m_x11_display, keysym);
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

void HotkeyListener::ProcessEvents() {

	XEvent event;
	while(XPending(m_x11_display) > 0) {
		XNextEvent(m_x11_display, &event);
		if(XGetEventData(m_x11_display, &event.xcookie)) {
			if(m_has_xinput2 && event.xcookie.extension == m_xinput2_opcode) {
				if(event.xcookie.evtype == XI_RawKeyPress) {
					XIDeviceEvent *xide = (XIDeviceEvent*) event.xcookie.data;
					if(!m_xinput2_master_keyboards.count(xide->deviceid)) {

						// emulate modifier keys
						int keysym_count;
						KeySym *keysym = XGetKeyboardMapping(m_x11_display, xide->detail, 1, &keysym_count);
						if(keysym_count > 0) {
							switch(keysym[0]) {
								case XK_Control_L: case XK_Control_R: m_xinput2_raw_modifiers |= ControlMask; break;
								case XK_Shift_L: case XK_Shift_R: m_xinput2_raw_modifiers |= ShiftMask; break;
								case XK_Alt_L: case XK_Alt_R: case XK_Meta_L: case XK_Meta_R: m_xinput2_raw_modifiers |= Mod1Mask; break;
								case XK_Super_L: case XK_Super_R: case XK_Hyper_L: case XK_Hyper_R: m_xinput2_raw_modifiers |= Mod4Mask; break;
							}
						}
						if(keysym != NULL)
							XFree(keysym);

						// process hotkey
						if(event.xcookie.serial != m_xinput2_ignore_serial) {
							Hotkey hotkey;
							hotkey.m_keycode = xide->detail;
							hotkey.m_modifiers = m_xinput2_raw_modifiers;
							ProcessHotkey(hotkey);
							m_xinput2_ignore_serial = event.xcookie.serial;
						}

					}
				}
				if(event.xcookie.evtype == XI_RawKeyRelease) {
					XIDeviceEvent *xide = (XIDeviceEvent*) event.xcookie.data;
					if(!m_xinput2_master_keyboards.count(xide->deviceid)) {

						// emulate modifier keys
						int keysym_count;
						KeySym *keysym = XGetKeyboardMapping(m_x11_display, xide->detail, 1, &keysym_count);
						if(keysym_count > 0) {
							switch(keysym[0]) {
								case XK_Control_L: case XK_Control_R: m_xinput2_raw_modifiers &= ~ControlMask; break;
								case XK_Shift_L: case XK_Shift_R: m_xinput2_raw_modifiers &= ~ShiftMask; break;
								case XK_Alt_L: case XK_Alt_R: case XK_Meta_L: case XK_Meta_R: m_xinput2_raw_modifiers &= ~Mod1Mask; break;
								case XK_Super_L: case XK_Super_R: case XK_Hyper_L: case XK_Hyper_R: m_xinput2_raw_modifiers &= ~Mod4Mask; break;
							}
						}
						if(keysym != NULL)
							XFree(keysym);

					}
				}
				if(event.xcookie.evtype == XI_KeyPress) {
					XIDeviceEvent *xide = (XIDeviceEvent*) event.xcookie.data;
					if(!(xide->flags & XIKeyRepeat)) {

						// process hotkey
						if(event.xcookie.serial != m_xinput2_ignore_serial) {
							Hotkey hotkey;
							hotkey.m_keycode = xide->detail;
							hotkey.m_modifiers = xide->mods.effective & ~LockMask & ~Mod2Mask;
							ProcessHotkey(hotkey);
							m_xinput2_ignore_serial = event.xcookie.serial;
						}

					}
				}
			}
			XFreeEventData(m_x11_display, &event.xcookie);
		} else {
			if(event.type == KeyPress) {
				Hotkey hotkey;
				hotkey.m_keycode = event.xkey.keycode;
				hotkey.m_modifiers = event.xkey.state & ~LockMask & ~Mod2Mask;
				ProcessHotkey(hotkey);
			}
			if(event.type == MappingNotify) {
				if(event.xmapping.request == MappingKeyboard || event.xmapping.request == MappingModifier)
					XRefreshKeyboardMapping(&event.xmapping);
				break;
			}
		}
	}

}
