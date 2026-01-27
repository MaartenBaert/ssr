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

#include "DialogRecordSchedule.h"

#include "EnumStrings.h"
#include "PageRecord.h"

ENUMSTRINGS(enum_schedule_time_zone) = {
	{SCHEDULE_TIME_ZONE_LOCAL, "local"},
	{SCHEDULE_TIME_ZONE_UTC, "utc"},
};
ENUMSTRINGS(enum_schedule_action) = {
	{SCHEDULE_ACTION_START, "start"},
	{SCHEDULE_ACTION_PAUSE, "pause"},
};

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
const QTimeZone SCHEDULE_TIME_ZONE_QTIMEZONES[SCHEDULE_TIME_ZONE_COUNT] = {
	QTimeZone::LocalTime,
	QTimeZone::UTC,
};
#else
const Qt::TimeSpec SCHEDULE_TIME_ZONE_QTIMESPECS[SCHEDULE_TIME_ZONE_COUNT] = {
	Qt::LocalTime,
	Qt::UTC,
};
#endif

const QString SCHEDULE_ACTION_TEXT[SCHEDULE_ACTION_COUNT] {
	RecordScheduleEntryWidget::tr("Start"),
	RecordScheduleEntryWidget::tr("Pause"),
};

RecordScheduleEntryWidget::RecordScheduleEntryWidget(QWidget* parent)
	: QWidget(parent) {

	QLabel *label_time = new QLabel(tr("Time:"), this);
	m_datetimeedit_time = new QDateTimeEdit(this);
	m_datetimeedit_time->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
	m_datetimeedit_time->setCalendarPopup(true);

	QLabel *label_action = new QLabel(tr("Action:"), this);
	m_combobox_action = new QComboBox(this);
	for(unsigned int i = 0; i < SCHEDULE_ACTION_COUNT; ++i) {
		m_combobox_action->addItem(SCHEDULE_ACTION_TEXT[i]);
	}

	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->setContentsMargins(5, 5, 5, 5);
	layout->addWidget(label_time);
	layout->addWidget(m_datetimeedit_time);
	layout->addSpacing(10);
	layout->addWidget(label_action);
	layout->addWidget(m_combobox_action);

}

QDateTimeEdit* RecordScheduleEntryWidget::GetDateTimeEdit() {
	return m_datetimeedit_time;
}

RecordScheduleEntryWidget::~RecordScheduleEntryWidget() {
	// nothing
}

void RecordScheduleEntryWidget::UpdateValidation(const QDateTime& current_time, bool is_valid) {
	QDateTime entry_time = m_datetimeedit_time->dateTime();
	qint64 secs_diff = current_time.secsTo(entry_time);
	
	// Check if in past or more than 4 weeks in future
	bool is_invalid = (secs_diff < 0) || (secs_diff > 4 * 7 * 24 * 60 * 60);
	
	// Also mark invalid if the parent says it's not in chronological order
	is_invalid = is_invalid || !is_valid;
	
	if(is_invalid) {
		m_datetimeedit_time->setStyleSheet("QDateTimeEdit { background-color: #ffcccc; }");
	} else {
		m_datetimeedit_time->setStyleSheet("");
	}
}

DialogRecordSchedule::DialogRecordSchedule(PageRecord* parent)
	: QDialog(parent) {

	m_parent = parent;

	m_clock_time = QDateTime();

	setWindowTitle(tr("Recording schedule"));

	QLabel *label_info = new QLabel(tr("Time zone:"), this);
	m_combobox_timezone = new QComboBox(this);
	m_combobox_timezone->addItem(tr("Local time"));
	m_combobox_timezone->addItem(tr("UTC"));
	m_combobox_timezone->setCurrentIndex(m_parent->GetScheduleTimeZone());
	QLabel *label_time = new QLabel(tr("Current time:"), this);
	m_label_time = new QLabel(this);
	m_label_time->setMinimumWidth(GetTextWidth(m_label_time->fontMetrics(), "0000-00-00 00:00:00 XXXXX") + 10);
	m_label_time->setAlignment((m_label_time->alignment() & ~Qt::AlignHorizontal_Mask) | Qt::AlignRight);

	m_widgetrack_schedule = new WidgetRack(this);
	m_widgetrack_schedule->setMinimumSize(500, 300);
	{
		std::vector<ScheduleEntry> schedule = m_parent->GetScheduleEntries();
		for(unsigned int i = 0; i < schedule.size(); ++i) {
			RecordScheduleEntryWidget *widget = new RecordScheduleEntryWidget(m_widgetrack_schedule->viewport());
			widget->SetTime(schedule[i].time);
			widget->SetAction(schedule[i].action);
			connect(widget->GetDateTimeEdit(), SIGNAL(dateTimeChanged(const QDateTime&)), this, SLOT(OnDateTimeChanged()));
			m_widgetrack_schedule->AddWidget(i, widget);
		}
	}

	QPushButton *pushbutton_add = new QPushButton(QIcon::fromTheme("list-add"), tr("Add"), this); // TODO icons
	QPushButton *pushbutton_remove = new QPushButton(QIcon::fromTheme("list-remove"), tr("Remove"), this);
	QPushButton *pushbutton_move_up = new QPushButton(QIcon::fromTheme("go-up"), tr("Move up"), this);
	QPushButton *pushbutton_move_down = new QPushButton(QIcon::fromTheme("go-down"), tr("Move down"), this);

	QPushButton *pushbutton_close = new QPushButton(tr("Close"), this);
	pushbutton_close->setDefault(true);

	connect(m_combobox_timezone, SIGNAL(activated(int)), this, SLOT(OnTimeZoneChanged()));
	connect(pushbutton_add, SIGNAL(clicked()), this, SLOT(OnAdd()));
	connect(pushbutton_remove, SIGNAL(clicked()), this, SLOT(OnRemove()));
	connect(pushbutton_move_up, SIGNAL(clicked()), this, SLOT(OnMoveUp()));
	connect(pushbutton_move_down, SIGNAL(clicked()), this, SLOT(OnMoveDown()));
	connect(pushbutton_close, SIGNAL(clicked()), this, SLOT(OnClose()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(label_info);
		layout2->addWidget(m_combobox_timezone);
		layout2->addSpacing(10);
		layout2->addStretch();
		layout2->addWidget(label_time);
		layout2->addWidget(m_label_time);
	}
	layout->addWidget(m_widgetrack_schedule);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(pushbutton_add);
		layout2->addWidget(pushbutton_remove);
		layout2->addWidget(pushbutton_move_up);
		layout2->addWidget(pushbutton_move_down);
	}
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addStretch();
		layout2->addWidget(pushbutton_close);
		layout2->addStretch();
	}

	m_timer_clock = new QTimer(this);
	m_timer_clock->setSingleShot(true);
	connect(m_timer_clock, SIGNAL(timeout()), this, SLOT(OnUpdateTime()));

	OnTimeZoneChanged();
	OnUpdateTime();

	setMinimumSize(minimumSizeHint()); // workaround for Qt bug

}

DialogRecordSchedule::~DialogRecordSchedule() {

}

void DialogRecordSchedule::OnTimeZoneChanged() {
	m_clock_time = QDateTime();
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
	QTimeZone timezone = SCHEDULE_TIME_ZONE_QTIMEZONES[m_combobox_timezone->currentIndex()];
#else
	Qt::TimeSpec spec = SCHEDULE_TIME_ZONE_QTIMESPECS[m_combobox_timezone->currentIndex()];
#endif
	for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
		RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
		widget->SetTimeZone(timezone);
#else
		widget->SetTimeSpec(spec);
#endif
	}
	OnUpdateTime();
}

void DialogRecordSchedule::OnUpdateTime() {
	QDateTime now = QDateTime::currentDateTimeUtc();
	if(m_clock_time.isNull() || now > m_clock_time || now.msecsTo(m_clock_time) > 100)
		m_clock_time = now.addMSecs(-now.time().msec());
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
	QTimeZone timezone = SCHEDULE_TIME_ZONE_QTIMEZONES[m_combobox_timezone->currentIndex()];
	m_label_time->setText(m_clock_time.toTimeZone(timezone).toString("yyyy-MM-dd hh:mm:ss t"));
#else
	Qt::TimeSpec spec = SCHEDULE_TIME_ZONE_QTIMESPECS[m_combobox_timezone->currentIndex()];
	m_label_time->setText(m_clock_time.toTimeSpec(spec).toString("yyyy-MM-dd hh:mm:ss t"));
#endif
	m_clock_time = m_clock_time.addSecs(1);
	m_timer_clock->start(now.msecsTo(m_clock_time));
	
	UpdateAllValidations();
}

void DialogRecordSchedule::OnAdd() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	unsigned int index = (selected == WidgetRack::NO_SELECTION)? m_widgetrack_schedule->GetWidgetCount() : selected + 1;
	RecordScheduleEntryWidget *widget = new RecordScheduleEntryWidget(m_widgetrack_schedule->viewport());
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
	QTimeZone timezone = SCHEDULE_TIME_ZONE_QTIMEZONES[m_combobox_timezone->currentIndex()];
#else
	Qt::TimeSpec spec = SCHEDULE_TIME_ZONE_QTIMESPECS[m_combobox_timezone->currentIndex()];
#endif
	if(selected == WidgetRack::NO_SELECTION) {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
		QDateTime time = QDateTime::currentDateTimeUtc().toTimeZone(timezone).addSecs(60);
#else
		QDateTime time = QDateTime::currentDateTimeUtc().toTimeSpec(spec).addSecs(60);
#endif
		time.setTime(QTime(time.time().hour(), 0, 0, 0));
		widget->SetTime(time.addSecs(60 * 60));
	} else {
		widget->SetTime(static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(selected))->GetTime());
	}
	connect(widget->GetDateTimeEdit(), SIGNAL(dateTimeChanged(const QDateTime&)), this, SLOT(OnDateTimeChanged()));
	m_widgetrack_schedule->AddWidget(index, widget);
	m_widgetrack_schedule->SetSelected(index);
	m_widgetrack_schedule->MakeVisible(widget);
	UpdateAllValidations();
}

void DialogRecordSchedule::OnRemove() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	if(selected != WidgetRack::NO_SELECTION) {
		m_widgetrack_schedule->RemoveWidget(selected);
		if(selected < m_widgetrack_schedule->GetWidgetCount()) {
			m_widgetrack_schedule->SetSelected(selected);
		} else if(m_widgetrack_schedule->GetWidgetCount() != 0) {
			m_widgetrack_schedule->SetSelected(m_widgetrack_schedule->GetWidgetCount() - 1);
		}
		UpdateAllValidations();
	}
}

void DialogRecordSchedule::OnMoveUp() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	if(selected != WidgetRack::NO_SELECTION && selected > 0) {
		m_widgetrack_schedule->MoveWidget(selected, selected - 1);
		m_widgetrack_schedule->MakeVisible(m_widgetrack_schedule->GetWidget(selected - 1));
		UpdateAllValidations();
	}
}

void DialogRecordSchedule::OnMoveDown() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	if(selected != WidgetRack::NO_SELECTION && selected < m_widgetrack_schedule->GetWidgetCount() - 1) {
		m_widgetrack_schedule->MoveWidget(selected, selected + 1);
		m_widgetrack_schedule->MakeVisible(m_widgetrack_schedule->GetWidget(selected + 1));
		UpdateAllValidations();
	}
}

void DialogRecordSchedule::OnClose() {
	// Validate the schedule
	QString error_message;
	int validation_result = ValidateSchedule(error_message);
	
	// validation_result: 0 = error (past/chronological/cancelled), 1 = success
	if(validation_result == 0) {
		// Show error if there's a message
		if(!error_message.isEmpty()) {
			QMessageBox::warning(this, tr("Recording schedule"), error_message);
		}
		// Write back data and close
		m_parent->SetScheduleTimeZone((enum_schedule_time_zone) m_combobox_timezone->currentIndex());
		std::vector<ScheduleEntry> schedule(m_widgetrack_schedule->GetWidgetCount());
		for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
			RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
			schedule[i].time = widget->GetTime();
			schedule[i].action = widget->GetAction();
		}
		m_parent->SetScheduleEntries(schedule);
		accept();
		return;
	}
	
	// Write back data
	m_parent->SetScheduleTimeZone((enum_schedule_time_zone) m_combobox_timezone->currentIndex());
	std::vector<ScheduleEntry> schedule(m_widgetrack_schedule->GetWidgetCount());
	for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
		RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
		schedule[i].time = widget->GetTime();
		schedule[i].action = widget->GetAction();
	}
	m_parent->SetScheduleEntries(schedule);
	accept();
}

void DialogRecordSchedule::OnDateTimeChanged() {
	UpdateAllValidations();
}

void DialogRecordSchedule::UpdateAllValidations() {
	QDateTime now = QDateTime::currentDateTimeUtc();
	
	for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
		RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
		QDateTime entry_time = widget->GetTime();
		
		// Check if this entry is in chronological order
		bool is_valid = true;
		if(i > 0) {
			RecordScheduleEntryWidget *prev_widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i - 1));
			QDateTime prev_time = prev_widget->GetTime();
			if(entry_time <= prev_time) {
				is_valid = false;
			}
		}
		
		widget->UpdateValidation(now, is_valid);
	}
}

int DialogRecordSchedule::ValidateSchedule(QString& error_message) {
	QDateTime now = QDateTime::currentDateTimeUtc();
	bool has_past_dates = false;
	bool has_chronological_issues = false;
	bool has_far_future_dates = false;
	
	// Check if schedule is currently active
	bool schedule_is_active = m_parent->IsScheduleActive();
	
	for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
		RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
		QDateTime entry_time = widget->GetTime();
		
		qint64 secs_diff = now.secsTo(entry_time);
		
		// Check if in past (only if schedule is not active)
		if(!schedule_is_active && secs_diff < 0) {
			has_past_dates = true;
		}
		
		// Check if more than 4 weeks in future
		if(secs_diff > 4 * 7 * 24 * 60 * 60) {
			has_far_future_dates = true;
		}
		
		// Check chronological order
		if(i > 0) {
			RecordScheduleEntryWidget *prev_widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i - 1));
			QDateTime prev_time = prev_widget->GetTime();
			if(entry_time <= prev_time) {
				has_chronological_issues = true;
			}
		}
	}
	
	// Check for critical errors first
	if(has_past_dates || has_chronological_issues) {
		if(has_past_dates && has_chronological_issues) {
			error_message = tr("There are dates in the past and dates are not in chronological order.");
		} else if(has_past_dates) {
			error_message = tr("There are dates in the past.");
		} else {
			error_message = tr("Dates are not in chronological order.");
		}
		return 0; // Error
	}
	
	// Check for warning about far future dates
	if(has_far_future_dates) {
		QMessageBox::StandardButton reply = QMessageBox::question(
			this,
			tr("Recording schedule"),
			tr("Some dates are more than four weeks in the future. Are you sure this is correct?"),
			QMessageBox::Yes | QMessageBox::No
		);
		if(reply == QMessageBox::Yes) {
			return 1; // Success
		} else {
			// User clicked No, don't save and don't show additional error
			error_message = "";
			return 0; // User cancelled
		}
	}
	
	return 1; // Success
}
