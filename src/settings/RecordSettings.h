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

#include "SimpleJSON.h"

enum enum_schedule_timezone {
	SCHEDULE_TIMEZONE_LOCAL,
	SCHEDULE_TIMEZONE_UTC,
};
enum enum_schedule_timing {
	SCHEDULE_TIMING_RELATIVE,
	SCHEDULE_TIMING_ABSOLUTE,
};
enum enum_schedule_action {
	SCHEDULE_ACTION_START,
	SCHEDULE_ACTION_PAUSE,
};

struct ScheduleEntry {

	enum_schedule_timing m_timing;
	unsigned int m_hour, m_minute, m_second;
	enum_schedule_action m_action;

	inline ScheduleEntry() { Defaults(); }
	void Defaults();
	void FromJSON(const SimpleJSON& json);
	void ToJSON(SimpleJSON& json);

};

struct RecordSettings {

	bool m_hotkey_enable;
	Qt::Key m_hotkey_key;
	Qt::KeyboardModifiers m_hotkey_modifiers;

	bool m_sound_notifications;
	unsigned int m_preview_frame_rate;

	enum_schedule_timezone m_schedule_timezone;
	std::vector<ScheduleEntry> m_schedule_entries;

	inline RecordSettings() { Defaults(); }
	void Defaults();
	void FromJSON(const SimpleJSON& json);
	void ToJSON(SimpleJSON& json);

};
