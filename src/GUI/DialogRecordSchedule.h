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

#include "PageRecord.h"
#include "RecordSettings.h"
#include "WidgetRack.h"

class RecordScheduleEntryWidget : public QWidget {
	Q_OBJECT

private:
	QComboBox *m_combobox_timing;
	QTimeEdit *m_timeedit_time;
	QComboBox *m_combobox_action;

public:
	RecordScheduleEntryWidget(ScheduleEntry entry, QWidget* parent = NULL);
	~RecordScheduleEntryWidget();

	ScheduleEntry Get();

};

class DialogRecordSchedule : public QDialog {
	Q_OBJECT

private:
	PageRecord *m_parent;

	QComboBox *m_combobox_timezone;
	QLabel *m_label_time;
	WidgetRack *m_widgetrack_schedule;

	QDateTime m_clock_time;
	QTimer *m_timer_clock;

public:
	DialogRecordSchedule(PageRecord* parent);
	~DialogRecordSchedule();

	std::vector<ScheduleEntry> GetSchedule();

private:
	QDateTime GetCurrentTime();

private slots:
	void OnTimeZoneChanged();
	void OnUpdateTime();
	void OnAdd();
	void OnRemove();
	void OnMoveUp();
	void OnMoveDown();

};
