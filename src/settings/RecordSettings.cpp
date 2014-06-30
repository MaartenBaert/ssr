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

#include "RecordSettings.h"

#include "EnumTranslator.h"
#include "Logger.h"

ENUMSTRINGS(enum_schedule_timezone) = {
	{SCHEDULE_TIMEZONE_LOCAL, "local"},
	{SCHEDULE_TIMEZONE_UTC, "utc"},
};
ENUMSTRINGS(enum_schedule_timing) = {
	{SCHEDULE_TIMING_RELATIVE, "relative"},
	{SCHEDULE_TIMING_ABSOLUTE, "absolute"},
};
ENUMSTRINGS(enum_schedule_action) = {
	{SCHEDULE_ACTION_START, "start"},
	{SCHEDULE_ACTION_PAUSE, "pause"},
};

void ScheduleEntry::Defaults() {
	m_timing = SCHEDULE_TIMING_RELATIVE;
	m_hour = 0;
	m_minute = 0;
	m_second = 0;
	m_action = SCHEDULE_ACTION_START;
}

void ScheduleEntry::FromJSON(const SimpleJSON& json) {
	try {
		json["timing"].GetEnum(m_timing);
		json["hour"].GetNumber(m_hour);
		json["minute"].GetNumber(m_minute);
		json["second"].GetNumber(m_second);
		json["action"].GetEnum(m_action);
	} catch(const JSONException&) {
		Logger::LogError("[ScheduleEntry::FromJSON] " + Logger::tr("Error: Invalid JSON data."));
	}
}

void ScheduleEntry::ToJSON(SimpleJSON& json) {
	json("timing").SetEnum(m_timing);
	json("hour").SetNumber(m_hour);
	json("minute").SetNumber(m_minute);
	json("second").SetNumber(m_second);
	json("action").SetEnum(m_action);
}

void RecordSettings::Defaults() {

	m_hotkey_enable = true;
	m_hotkey_key = Qt::Key_R;
	m_hotkey_modifiers = Qt::ControlModifier;

	m_sound_notifications = false;
	m_preview_frame_rate = 10;

	m_schedule_timezone = SCHEDULE_TIMEZONE_LOCAL;
	m_schedule_entries.clear();

}

void RecordSettings::FromJSON(const SimpleJSON& json) {
	try {

		json["hotkey"]["enable"].GetBool(m_hotkey_enable);
		json["hotkey"]["key"].GetEnum(m_hotkey_key);
		const SimpleJSON &modifiers = json["hotkey"]["modifiers"];
		if(!modifiers.IsNull()) {
			m_hotkey_modifiers = 0;
			for(size_t i = 0; i < modifiers.GetElementCount(); ++i) {
				Qt::KeyboardModifier mod = Qt::NoModifier;
				modifiers[i].GetEnum(mod);
				m_hotkey_modifiers |= mod;
			}
		}

		json["sound_notifications"].GetBool(m_sound_notifications);
		json["preview_frame_rate"].GetNumber(m_preview_frame_rate);

		json["schedule"]["timezone"].GetEnum(m_schedule_timezone);
		const SimpleJSON &entries = json["schedule"]["entries"];
		m_schedule_entries.resize(entries.GetElementCount());
		for(size_t i = 0; i < entries.GetElementCount(); ++i) {
			m_schedule_entries[i].FromJSON(entries[i]);
		}

	} catch(const JSONException&) {
		Logger::LogError("[RecordSettings::FromJSON] " + Logger::tr("Error: Invalid JSON data."));
	}
}

void RecordSettings::ToJSON(SimpleJSON& json) {

	json("hotkey")("enable").SetBool(m_hotkey_enable);
	json("hotkey")("key").SetEnum(m_hotkey_key);
	json("hotkey")("modifiers").ResetArray();
	for(auto e : {Qt::ControlModifier, Qt::ShiftModifier, Qt::AltModifier, Qt::MetaModifier}) {
		if(m_hotkey_modifiers & e)
			json("hotkey")("modifiers").AddElement().SetEnum(m_preview_frame_rate);
	}

	json("sound_notifications").SetBool(m_sound_notifications);
	json("preview_frame_rate").SetNumber(m_preview_frame_rate);

	json("schedule")("timezone").SetEnum(m_schedule_timezone);
	const SimpleJSON &entries = json["schedule"]["entries"];
	entries.ResetArray();
	for(ScheduleEntry &entry : m_schedule_entries) {
		entry.ToJSON(entries.AddElement());
	}

}
