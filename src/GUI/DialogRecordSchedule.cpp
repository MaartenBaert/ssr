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

#include "Logger.h"
#include "PageRecord.h"

RecordScheduleEntryWidget::RecordScheduleEntryWidget(PageRecord::ScheduleEntry entry, QWidget* parent)
	: QWidget(parent) {

	setFocusPolicy(Qt::ClickFocus);
	setAutoFillBackground(true);

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

const unsigned int RecordScheduleListWidget::INVALID_ENTRY = (unsigned int) -1;
const QPalette::ColorRole RecordScheduleListWidget::ROLE_NORMAL = QPalette::Base;
const QPalette::ColorRole RecordScheduleListWidget::ROLE_SELECTED = QPalette::Highlight;

RecordScheduleListWidget::RecordScheduleListWidget(QWidget* parent)
	: QWidget(parent) {

	m_selected_entry = INVALID_ENTRY;

	setBackgroundRole(QPalette::Dark);
	setAutoFillBackground(true);

	m_layout = new QVBoxLayout(this);
	m_layout->setMargin(0);
	m_layout->setSpacing(1);
	m_layout->addStretch();

	connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(OnFocusChange(QWidget*, QWidget*)));

}

RecordScheduleListWidget::~RecordScheduleListWidget() {

}

unsigned int RecordScheduleListWidget::GetEntryCount() {
	return m_entries.size();
}

PageRecord::ScheduleEntry RecordScheduleListWidget::GetEntry(unsigned int index) {
	assert(index < m_entries.size());
	return m_entries[index]->Get();
}

unsigned int RecordScheduleListWidget::GetSelectedEntry() {
	return m_selected_entry;
}

void RecordScheduleListWidget::SetSelectedEntry(unsigned int index) {
	if(m_selected_entry != INVALID_ENTRY)
		m_entries[m_selected_entry]->setBackgroundRole(ROLE_NORMAL);
	m_selected_entry = index;
	if(m_selected_entry != INVALID_ENTRY)
		m_entries[m_selected_entry]->setBackgroundRole(ROLE_SELECTED);
	assert(m_selected_entry < m_entries.size() || m_selected_entry == INVALID_ENTRY);
}

void RecordScheduleListWidget::AddEntry(unsigned int index, PageRecord::ScheduleEntry entry) {
	assert(index <= m_entries.size());
	RecordScheduleEntryWidget *widget = new RecordScheduleEntryWidget(entry, this);
	widget->setBackgroundRole(ROLE_NORMAL);
	m_entries.insert(m_entries.begin() + index, widget);
	m_layout->insertWidget(index, widget);
	if(m_selected_entry != INVALID_ENTRY && index <= m_selected_entry)
		++m_selected_entry;
	assert(m_selected_entry < m_entries.size() || m_selected_entry == INVALID_ENTRY);
}

void RecordScheduleListWidget::RemoveEntry(unsigned int index) {
	assert(index < m_entries.size());
	delete m_entries[index];
	m_entries.erase(m_entries.begin() + index);
	if(m_selected_entry != INVALID_ENTRY) {
		if(m_selected_entry == index) {
			if(m_selected_entry < m_entries.size()) {
				m_entries[m_selected_entry]->setBackgroundRole(ROLE_SELECTED);
			} else if(m_entries.size() != 0) {
				m_selected_entry = m_entries.size() - 1;
				m_entries[m_selected_entry]->setBackgroundRole(ROLE_SELECTED);
			} else {
				m_selected_entry = INVALID_ENTRY;
			}
		} else if(m_selected_entry > index) {
			--m_selected_entry;
		}
	}
	assert(m_selected_entry < m_entries.size() || m_selected_entry == INVALID_ENTRY);
}

void RecordScheduleListWidget::MoveEntry(unsigned int from, unsigned int to) {
	assert(from < m_entries.size());
	assert(to < m_entries.size());
	RecordScheduleEntryWidget *widget = m_entries[from];
	m_entries.erase(m_entries.begin() + from);
	m_entries.insert(m_entries.begin() + to, widget);
	m_layout->removeWidget(widget);
	m_layout->insertWidget(to, widget);
	if(m_selected_entry != INVALID_ENTRY) {
		if(m_selected_entry == from) {
			m_selected_entry = to;
		} else {
			if(m_selected_entry > from && m_selected_entry <= to)
				--m_selected_entry;
			if(m_selected_entry < from && m_selected_entry >= to)
				++m_selected_entry;
		}
	}
	assert(m_selected_entry < m_entries.size() || m_selected_entry == INVALID_ENTRY);
}

void RecordScheduleListWidget::OnFocusChange(QWidget* old_widget, QWidget* new_widget) {
	Q_UNUSED(old_widget);
	for(unsigned int i = 0; i < m_entries.size(); ++i) {
		if(m_entries[i]->isAncestorOf(new_widget)) {
			SetSelectedEntry(i);
			break;
		}
	}
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

	m_schedule_list = new RecordScheduleListWidget(this);

	m_scroll_area = new QScrollArea(this);
	m_scroll_area->setMinimumSize(500, 300);
	m_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//m_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // buggy with GTK style, maximumViewportSize() doesn't take the border into account :(
	m_scroll_area->setWidgetResizable(true);
	m_scroll_area->setWidget(m_schedule_list);

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
	connect(this, SIGNAL(accepted()), this, SLOT(OnWriteBack()));
	connect(this, SIGNAL(rejected()), this, SLOT(OnWriteBack()));

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
	layout->addWidget(m_scroll_area);
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

QDateTime DialogRecordSchedule::GetCurrentTime() {
	if(m_combobox_timezone->currentIndex() == PageRecord::SCHEDULE_TIMEZONE_LOCAL)
		return QDateTime::currentDateTime();
	else
		return QDateTime::currentDateTimeUtc();
}

void DialogRecordSchedule::OnWriteBack() {

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
	unsigned int selected = m_schedule_list->GetSelectedEntry();
	unsigned int index = (selected == RecordScheduleListWidget::INVALID_ENTRY)? m_schedule_list->GetEntryCount() : selected + 1;
	m_schedule_list->AddEntry(index, entry);
	m_schedule_list->SetSelectedEntry(index);
}

void DialogRecordSchedule::OnRemove() {
	unsigned int selected = m_schedule_list->GetSelectedEntry();
	if(selected != RecordScheduleListWidget::INVALID_ENTRY) {
		m_schedule_list->RemoveEntry(selected);
	}
}

void DialogRecordSchedule::OnMoveUp() {
	unsigned int selected = m_schedule_list->GetSelectedEntry();
	if(selected != RecordScheduleListWidget::INVALID_ENTRY && selected > 0) {
		m_schedule_list->MoveEntry(selected, selected - 1);
	}
}

void DialogRecordSchedule::OnMoveDown() {
	unsigned int selected = m_schedule_list->GetSelectedEntry();
	if(selected != RecordScheduleListWidget::INVALID_ENTRY && selected < m_schedule_list->GetEntryCount() - 1) {
		m_schedule_list->MoveEntry(selected, selected + 1);
	}
}
