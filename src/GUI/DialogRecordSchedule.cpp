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

const Qt::TimeSpec SCHEDULE_TIME_ZONE_TIMESPECS[SCHEDULE_TIME_ZONE_COUNT] = {
	Qt::LocalTime,
	Qt::UTC,
};
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
	layout->setMargin(5);
	layout->addWidget(label_time);
	layout->addWidget(m_datetimeedit_time);
	layout->addSpacing(10);
	layout->addWidget(label_action);
	layout->addWidget(m_combobox_action);

}

RecordScheduleEntryWidget::~RecordScheduleEntryWidget() {
	// nothing
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
	connect(pushbutton_close, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this, SIGNAL(accepted()), this, SLOT(OnWriteBack()));
	connect(this, SIGNAL(rejected()), this, SLOT(OnWriteBack()));

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
	Qt::TimeSpec spec = SCHEDULE_TIME_ZONE_TIMESPECS[m_combobox_timezone->currentIndex()];
	for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
		RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
		widget->SetTimeSpec(spec);
	}
	OnUpdateTime();
}

void DialogRecordSchedule::OnUpdateTime() {
	QDateTime now = QDateTime::currentDateTimeUtc();
	if(m_clock_time.isNull() || now > m_clock_time || now.msecsTo(m_clock_time) > 100)
		m_clock_time = now.addMSecs(-now.time().msec());
	Qt::TimeSpec spec = SCHEDULE_TIME_ZONE_TIMESPECS[m_combobox_timezone->currentIndex()];
	m_label_time->setText(m_clock_time.toTimeSpec(spec).toString("yyyy-MM-dd hh:mm:ss t"));
	m_clock_time = m_clock_time.addSecs(1);
	m_timer_clock->start(now.msecsTo(m_clock_time));
}

void DialogRecordSchedule::OnAdd() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	unsigned int index = (selected == WidgetRack::NO_SELECTION)? m_widgetrack_schedule->GetWidgetCount() : selected + 1;
	RecordScheduleEntryWidget *widget = new RecordScheduleEntryWidget(m_widgetrack_schedule->viewport());
	Qt::TimeSpec spec = SCHEDULE_TIME_ZONE_TIMESPECS[m_combobox_timezone->currentIndex()];
	if(selected == WidgetRack::NO_SELECTION) {
		QDateTime time = QDateTime::currentDateTimeUtc().toTimeSpec(spec).addSecs(60);
		time.setTime(QTime(time.time().hour(), 0, 0, 0));
		widget->SetTime(time.addSecs(60 * 60));
	} else {
		widget->SetTime(static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(selected))->GetTime());
	}
	m_widgetrack_schedule->AddWidget(index, widget);
	m_widgetrack_schedule->SetSelected(index);
	m_widgetrack_schedule->MakeVisible(widget);
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
	}
}

void DialogRecordSchedule::OnMoveUp() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	if(selected != WidgetRack::NO_SELECTION && selected > 0) {
		m_widgetrack_schedule->MoveWidget(selected, selected - 1);
		m_widgetrack_schedule->MakeVisible(m_widgetrack_schedule->GetWidget(selected - 1));
	}
}

void DialogRecordSchedule::OnMoveDown() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	if(selected != WidgetRack::NO_SELECTION && selected < m_widgetrack_schedule->GetWidgetCount() - 1) {
		m_widgetrack_schedule->MoveWidget(selected, selected + 1);
		m_widgetrack_schedule->MakeVisible(m_widgetrack_schedule->GetWidget(selected + 1));
	}
}

void DialogRecordSchedule::OnWriteBack() {
	m_parent->SetScheduleTimeZone((enum_schedule_time_zone) m_combobox_timezone->currentIndex());
	std::vector<ScheduleEntry> schedule(m_widgetrack_schedule->GetWidgetCount());
	for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
		RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
		schedule[i].time = widget->GetTime();
		schedule[i].action = widget->GetAction();
	}
	m_parent->SetScheduleEntries(schedule);
}
