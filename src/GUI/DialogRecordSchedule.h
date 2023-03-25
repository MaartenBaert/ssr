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

// TODO: #include "PageRecord.h"
// TODO: #include "RecordSettings.h"
#include "WidgetRack.h"

class PageRecord;

enum enum_schedule_time_zone {
	SCHEDULE_TIME_ZONE_LOCAL,
	SCHEDULE_TIME_ZONE_UTC,
	SCHEDULE_TIME_ZONE_COUNT // must be last
};
enum enum_schedule_action {
	SCHEDULE_ACTION_START,
	SCHEDULE_ACTION_PAUSE,
	SCHEDULE_ACTION_COUNT // must be last
};

struct ScheduleEntry {
	QDateTime time;
	enum_schedule_action action;
};

extern const Qt::TimeSpec SCHEDULE_TIME_ZONE_TIMESPECS[SCHEDULE_TIME_ZONE_COUNT];
extern const QString SCHEDULE_ACTION_TEXT[SCHEDULE_ACTION_COUNT];

class RecordScheduleEntryWidget : public QWidget {
	Q_OBJECT

private:
	//QComboBox *m_combobox_timing;
	//QTimeEdit *m_timeedit_time;
	QDateTimeEdit *m_datetimeedit_time;
	QComboBox *m_combobox_action;

public:
	RecordScheduleEntryWidget(QWidget* parent = NULL);
	~RecordScheduleEntryWidget();

	inline void Print(const QString& str) { qDebug() << "timespec" << str << m_datetimeedit_time->dateTime() << m_datetimeedit_time->timeSpec(); }

	inline void SetTimeSpec(Qt::TimeSpec spec) { m_datetimeedit_time->setTimeSpec(spec); m_datetimeedit_time->setDateTime(m_datetimeedit_time->dateTime()); }

	inline void SetTime(const QDateTime& time) { m_datetimeedit_time->setTimeSpec(time.timeSpec()); m_datetimeedit_time->setDateTime(time); }
	inline void SetAction(enum_schedule_action action) { m_combobox_action->setCurrentIndex(clamp((int) action, 0, (int) SCHEDULE_ACTION_COUNT - 1)); }

	inline QDateTime GetTime() { return m_datetimeedit_time->dateTime(); }
	inline enum_schedule_action GetAction() { return (enum_schedule_action) clamp(m_combobox_action->currentIndex(), 0, (int) SCHEDULE_ACTION_COUNT - 1); }

};

class DialogRecordSchedule : public QDialog {
	Q_OBJECT

private:
	PageRecord *m_parent;

	QComboBox *m_combobox_timezone;
	QLabel *m_label_time;
	WidgetRack *m_widgetrack_schedule;

	QTimer *m_timer_clock;
	QDateTime m_clock_time;

public:
	DialogRecordSchedule(PageRecord* parent);
	~DialogRecordSchedule();

private slots:
	void OnTimeZoneChanged();
	void OnUpdateTime();
	void OnAdd();
	void OnRemove();
	void OnMoveUp();
	void OnMoveDown();
	void OnWriteBack();

};
