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

#include "DialogRecordSchedule.h"

RecordScheduleEntryWidget::RecordScheduleEntryWidget(PageRecord::ScheduleEntry entry, QWidget* parent)
	: QWidget(parent) {

	QLabel *label_time = new QLabel(tr("Time:"), this);
	m_combobox_timing = new QComboBox(this);
	m_combobox_timing->addItem(tr("After previous action"));
	m_combobox_timing->addItem(tr("At absolute time"));
	m_combobox_timing->setCurrentIndex(entry.m_timing);
	m_timeedit_time = new QTimeEdit(QTime(entry.m_hour, entry.m_minute, entry.m_second), this);
	m_timeedit_time->setDisplayFormat("hh:mm:ss");

	QLabel *label_action = new QLabel(tr("Action:"), this);
	m_combobox_action = new QComboBox(this);
	m_combobox_action->addItem(tr("Start recording"));
	m_combobox_action->addItem(tr("Pause recording"));
	m_combobox_action->setCurrentIndex(entry.m_action);
	m_combobox_action->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	QGridLayout *layout = new QGridLayout(this);
	layout->setMargin(5);
	layout->addWidget(label_time, 0, 0);
	layout->addWidget(m_combobox_timing, 0, 1);
	layout->addWidget(m_timeedit_time, 0, 2);
	layout->addWidget(label_action, 1, 0);
	layout->addWidget(m_combobox_action, 1, 1, 1, 2);

}

RecordScheduleEntryWidget::~RecordScheduleEntryWidget() {

}

PageRecord::ScheduleEntry RecordScheduleEntryWidget::Get() {
	PageRecord::ScheduleEntry entry;
	entry.m_timing = (PageRecord::enum_schedule_timing) m_combobox_timing->currentIndex();
	entry.m_hour = m_timeedit_time->time().hour();
	entry.m_minute = m_timeedit_time->time().minute();
	entry.m_second = m_timeedit_time->time().second();
	entry.m_action = (PageRecord::enum_schedule_action) m_combobox_action->currentIndex();
	return entry;
}

DialogRecordSchedule::DialogRecordSchedule(PageRecord* parent)
	: QDialog(parent) {

	m_parent = parent;

	setWindowTitle(tr("Recording schedule"));

	QLabel *label_info = new QLabel(tr("Time zone:"), this);
	m_combobox_timezone = new QComboBox(this);
	m_combobox_timezone->addItem(tr("Local time"));
	m_combobox_timezone->addItem(tr("UTC"));
	QLabel *label_time = new QLabel(tr("Current time:"), this);
	m_label_time = new QLabel(this);
	m_label_time->setMinimumWidth(m_label_time->fontMetrics().width("00:00:00") + 10);
	m_label_time->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	m_widgetrack_schedule = new WidgetRack(this);
	m_widgetrack_schedule->setMinimumSize(500, 300);
	{
		auto schedule = m_parent->GetSchedule();
		for(unsigned int i = 0; i < schedule.size(); ++i) {
			PageRecord::ScheduleEntry entry = schedule[i];
			QWidget *widget = new RecordScheduleEntryWidget(entry, m_widgetrack_schedule->viewport());
			m_widgetrack_schedule->AddWidget(i, widget);
		}
	}

	QPushButton *pushbutton_add = new QPushButton(QIcon::fromTheme("list-add"), tr("Add"), this);
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

	QVBoxLayout *layout = new QVBoxLayout(this);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(label_info);
		layout2->addWidget(m_combobox_timezone);
		layout2->addSpacing(30);
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

	m_clock_time = QDateTime();
	OnUpdateTime();

	setMinimumSize(minimumSizeHint()); // workaround for Qt bug

}

DialogRecordSchedule::~DialogRecordSchedule() {

}

std::vector<PageRecord::ScheduleEntry> DialogRecordSchedule::GetSchedule() {
	std::vector<PageRecord::ScheduleEntry> schedule;
	for(unsigned int i = 0; i < m_widgetrack_schedule->GetWidgetCount(); ++i) {
		RecordScheduleEntryWidget *widget = static_cast<RecordScheduleEntryWidget*>(m_widgetrack_schedule->GetWidget(i));
		schedule[i] = widget->Get();
	}
	return schedule;
}

QDateTime DialogRecordSchedule::GetCurrentTime() {
	if(m_combobox_timezone->currentIndex() == PageRecord::SCHEDULE_TIMEZONE_LOCAL)
		return QDateTime::currentDateTime();
	else
		return QDateTime::currentDateTimeUtc();
}

void DialogRecordSchedule::OnTimeZoneChanged() {
	m_clock_time = QDateTime();
	OnUpdateTime();
}

void DialogRecordSchedule::OnUpdateTime() {
	QDateTime now = GetCurrentTime();
	if(m_clock_time.isNull() || now > m_clock_time || now.msecsTo(m_clock_time) > 100)
		m_clock_time = now.addMSecs(-now.time().msec());
	m_label_time->setText(m_clock_time.toString("hh:mm:ss"));
	m_clock_time = m_clock_time.addSecs(1);
	m_timer_clock->start(now.msecsTo(m_clock_time));
}

void DialogRecordSchedule::OnAdd() {
	PageRecord::ScheduleEntry entry{PageRecord::SCHEDULE_TIMING_RELATIVE, 0, 0, 0, PageRecord::SCHEDULE_ACTION_START};
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	unsigned int index = (selected == WidgetRack::NO_SELECTION)? m_widgetrack_schedule->GetWidgetCount() : selected + 1;
	QWidget *widget = new RecordScheduleEntryWidget(entry, m_widgetrack_schedule->viewport());
	m_widgetrack_schedule->AddWidget(index, widget);
	m_widgetrack_schedule->SetSelected(index);
	m_widgetrack_schedule->MakeVisible(widget);
}

void DialogRecordSchedule::OnRemove() {
	unsigned int selected = m_widgetrack_schedule->GetSelected();
	if(selected != WidgetRack::NO_SELECTION) {
		m_widgetrack_schedule->RemoveWidget(selected);
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
