#!/usr/bin/env python3
"""Exercise Wayland selection and retry without a compositor or screen capture.

Run against a Qt5/Qt6 build with WITH_PORTAL enabled:
    dbus-run-session -- xvfb-run -a python3 tests/wayland_portal.py /path/to/simplescreenrecorder

Requires python-dbus, PyGObject, Xvfb and dbus-run-session. Always use an isolated
D-Bus session: this test owns the portal service name. Settings and logs are
written to a temporary directory, printed at exit for failure diagnosis.

The mock closes the first session during selection. The next selection succeeds
but stalls negotiation while commands attempt to reenter initialization. The
session closes during the modal wait (or, with the optional "timeout" argument,
the wait reaches its deadline). Later connections return closed sockets to
exercise failure cleanup and repeated visits with a retained selection.
"""
import os
import re
import socket
import subprocess
import sys
import tempfile

import dbus
import dbus.service
import dbus.mainloop.glib
from pathlib import Path
from gi.repository import GLib
if len(sys.argv) not in (2, 3):
    raise SystemExit('Usage: wayland_portal.py /path/to/simplescreenrecorder [timeout]')

test_timeout = len(sys.argv) == 3 and sys.argv[2] == 'timeout'

dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
bus = dbus.SessionBus()
name = dbus.service.BusName('org.freedesktop.portal.Desktop', bus)
objects = []

class Request(dbus.service.Object):

    @dbus.service.signal('org.freedesktop.portal.Request', signature='ua{sv}')
    def Response(self, code, results):
        pass

    @dbus.service.method('org.freedesktop.portal.Request', in_signature='', out_signature='')
    def Close(self):
        pass

class Session(dbus.service.Object):

    @dbus.service.signal('org.freedesktop.portal.Session', signature='a{sv}')
    def Closed(self, details):
        pass

    @dbus.service.method('org.freedesktop.portal.Session', in_signature='', out_signature='')
    def Close(self):
        pass

class Portal(dbus.service.Object):
    creates = 0
    opens = 0
    capability_queries = 0

    @dbus.service.method('org.freedesktop.DBus.Properties', in_signature='s', out_signature='a{sv}')
    def GetAll(self, interface):
        assert interface == 'org.freedesktop.portal.ScreenCast'
        self.capability_queries += 1
        return {'version': dbus.UInt32(4), 'AvailableSourceTypes': dbus.UInt32(3), 'AvailableCursorModes': dbus.UInt32(3)}

    def request(self, sender, options):
        path = '/org/freedesktop/portal/desktop/request/' + sender[1:].replace('.', '_') + '/' + str(options['handle_token'])
        req = Request(bus, path)
        objects.append(req)
        return (dbus.ObjectPath(path), req)

    @dbus.service.method('org.freedesktop.portal.ScreenCast', in_signature='a{sv}', out_signature='o', sender_keyword='sender')
    def CreateSession(self, options, sender):
        self.creates += 1
        path, req = self.request(sender, options)
        self.session_path = '/org/freedesktop/portal/desktop/session/mock/s' + str(self.creates)
        self.session = Session(bus, self.session_path)
        objects.append(self.session)
        session_path = self.session_path
        GLib.timeout_add(20, lambda: req.Response(0, {'session_handle': session_path}))
        return path

    @dbus.service.method('org.freedesktop.portal.ScreenCast', in_signature='oa{sv}', out_signature='o', sender_keyword='sender')
    def SelectSources(self, session, options, sender):
        assert options['types'] == 3
        assert options['cursor_mode'] == 2
        assert options['persist_mode'] == 1
        path, req = self.request(sender, options)
        if self.creates == 1:
            GLib.timeout_add(20, lambda: self.session.Closed({}))
        else:
            GLib.timeout_add(20, lambda: req.Response(0, {}))
        return path

    @dbus.service.method('org.freedesktop.portal.ScreenCast', in_signature='osa{sv}', out_signature='o', sender_keyword='sender')
    def Start(self, session, parent, options, sender):
        assert re.fullmatch(r"x11:[0-9a-f]+", str(parent)), parent
        assert int(str(parent)[4:], 16) != 0, parent
        path, req = self.request(sender, options)
        streams = dbus.Array([dbus.Struct((dbus.UInt32(42), dbus.Dictionary({}, signature='sv')), signature='ua{sv}')], signature='(ua{sv})')
        GLib.timeout_add(20, lambda: req.Response(0, {'streams': streams}))
        return path

    @dbus.service.method('org.freedesktop.portal.ScreenCast', in_signature='oa{sv}', out_signature='h')
    def OpenPipeWireRemote(self, session, options):
        self.opens += 1
        client, peer = socket.socketpair()
        result = dbus.types.UnixFd(client.fileno())
        client.close()
        if self.opens == 1:
            # Keep the connection alive but never send a negotiated format.
            # Commands must not interrupt or reenter the modal wait.
            self.stalled_peer = peer
            for command in ('record-start', 'record-pause', 'record-cancel',
                            'record-save', 'schedule-activate', 'quit'):
                GLib.timeout_add(700, send, command)
            if not test_timeout:
                GLib.timeout_add(1100, lambda: self.session.Closed({}))
        else:
            peer.close()
        return result
portal = Portal(bus, '/org/freedesktop/portal/desktop')
root = Path(tempfile.mkdtemp(prefix='ssr-wayland-test-'))
(root / 'settings.conf').write_text('[input]\nvideo_backend=wayland\naudio_enabled=false\n[output]\nfile=' + str(root / 'out.mkv') + '\n')
env = os.environ.copy()
env['LC_ALL'] = 'C'
env['QT_QPA_PLATFORM'] = 'xcb'
env['XDG_SESSION_TYPE'] = 'x11'
env['XDG_CONFIG_HOME'] = str(root / 'config')
env['XDG_DATA_HOME'] = str(root / 'data')
log = open(root / 'app.log', 'w')
proc = subprocess.Popen([sys.argv[1], '--settingsfile=' + str(root / 'settings.conf'), '--no-systray', '--no-redirect-stderr'], stdin=subprocess.PIPE, stdout=log, stderr=log, text=True, env=env)
loop = GLib.MainLoop()

def send(command):
    if proc.poll() is None:
        proc.stdin.write(command + '\n')
        proc.stdin.flush()
    return False
phase = 0
send('record-start')

def advance():
    global phase
    text = (root / 'app.log').read_text()
    if proc.poll() is not None:
        loop.quit()
        return False
    if phase == 0 and 'session was closed' in text:
        send('record-start')
        phase = 1
    elif phase == 1 and 'Video capture is unavailable' in text:
        send('record-cancel')
        send('record-start')
        phase = 2
    elif phase == 2 and 'Could not initialize Wayland video capture.' in text:
        send('record-cancel')
        send('record-start')
        phase = 3
    elif phase == 3 and text.count('Could not initialize Wayland video capture.') == 2:
        send('record-cancel')
        send('record-start')
        phase = 4
    elif phase == 4 and text.count('Could not initialize Wayland video capture.') == 3:
        send('quit')
        phase = 5
    return True
GLib.timeout_add(100, advance)

def finish():
    if proc.poll() is None:
        proc.kill()
    loop.quit()
    return False
GLib.timeout_add(20000, finish)
loop.run()
proc.wait()
log.close()
text = (root / 'app.log').read_text()
print('log:', root / 'app.log')
print('sessions:', portal.creates, 'remote connections:', portal.opens)
assert proc.returncode == 0, text
assert phase == 5, text
assert portal.creates == (2 if test_timeout else 3), (portal.creates, text)
assert portal.opens == 3, (portal.opens, text)
assert portal.capability_queries == portal.creates, (portal.capability_queries, text)
assert 'session was closed' in text, text
assert 'Video capture is unavailable' in text, text
assert 'video_backend=wayland' in (root / 'settings.conf').read_text()
assert 'Started output.' not in text, text
if test_timeout:
    assert 'Timed out while waiting for the PipeWire video format.' in text, text
else:
    assert 'session closed while preparing video capture.' in text, text
assert text.count('[PageRecord::StartPage] Started page.') == 4, text
print('PASS: modal wait, command guards, failure reporting, retry, session reuse, persistence')
