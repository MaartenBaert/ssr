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

/*std::array<QString, 2> g_schedule_timing_strings = {
	"Relative",
	"Absolute",
};
std::array<QString, 2> g_schedule_action_strings = {
	"Start recording",
	"Pause recording",
};

ComboBox_ScheduleTiming::ComboBox_ScheduleTiming(QWidget* parent)
	: QComboBox(parent) {
	for(QString &str : g_schedule_timing_strings) {
		addItem(str);
	}
}

PageRecord::enum_schedule_timing ComboBox_ScheduleTiming::GetTiming() {
	return (PageRecord::enum_schedule_timing) currentIndex();
}

void ComboBox_ScheduleTiming::SetTiming(PageRecord::enum_schedule_timing timing) {
	setCurrentIndex(timing);
}

ScheduleModel::ScheduleModel() {

	qRegisterMetaType<PageRecord::enum_schedule_timing>();
	qRegisterMetaType<PageRecord::enum_schedule_action>();

	m_schedule.push_back({PageRecord::SCHEDULE_TIMING_AFTER_PREVIOUS, 1, 2, 3, 4, 5, PageRecord::SCHEDULE_ACTION_START});
	m_schedule.push_back({PageRecord::SCHEDULE_TIMING_FIXED_TIME, 6, 7, 8, 9, 10, PageRecord::SCHEDULE_ACTION_START});
	m_schedule.push_back({PageRecord::SCHEDULE_TIMING_AFTER_PREVIOUS, 11, 12, 13, 14, 15, PageRecord::SCHEDULE_ACTION_PAUSE});

	QComboBox dummy;
	m_row_height = dummy.sizeHint().height();

}

ScheduleModel::~ScheduleModel() {

}

QModelIndex ScheduleModel::index(int row, int column, const QModelIndex& parent) const {
	assert(!parent.isValid());
	return createIndex(row, column);
}

QModelIndex ScheduleModel::parent(const QModelIndex& index) const {
	assert(index.isValid());
	return QModelIndex();
}

int ScheduleModel::rowCount(const QModelIndex& parent) const {
	if(parent.isValid())
		return 0;
	else
		return m_schedule.size();
}

int ScheduleModel::columnCount(const QModelIndex& parent) const {
	Q_UNUSED(parent);
	return 8;
}

Qt::ItemFlags ScheduleModel::flags(const QModelIndex& index) const {
	assert(index.isValid());
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

QVariant ScheduleModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if(orientation == Qt::Horizontal) {
		if(role == Qt::DisplayRole) {
			switch(section) {
				case 0: return QString("Timing");
				case 1: return QString("Month");
				case 2: return QString("Day");
				case 3: return QString("Hour");
				case 4: return QString("Minute");
				case 5: return QString("Second");
				case 6: return QString("Action");
				case 7: return QString("---");
			}
		}
	}
	return QVariant();
}

QVariant ScheduleModel::data(const QModelIndex& index, int role) const {
	assert(index.isValid());
	const PageRecord::ScheduleEntry &entry = m_schedule[index.row()];
	if(role == Qt::DisplayRole) {
		switch(index.column()) {
			case 0: return g_schedule_timing_strings[entry.m_timing];
			case 1: return entry.m_month;
			case 2: return entry.m_day;
			case 3: return entry.m_hour;
			case 4: return entry.m_minute;
			case 5: return entry.m_second;
			case 6: return g_schedule_action_strings[entry.m_action];
			case 7: return QDateTime(QDate(2014, entry.m_month, entry.m_day), QTime(entry.m_hour, entry.m_minute, entry.m_second));
		}
	}
	if(role == Qt::EditRole) {
		switch(index.column()) {
			case 0: return QVariant::fromValue(entry.m_timing);
			case 1: return entry.m_month;
			case 2: return entry.m_day;
			case 3: return entry.m_hour;
			case 4: return entry.m_minute;
			case 5: return entry.m_second;
			case 6: return (int) entry.m_action;
			case 7: return QDateTime(QDate(2014, entry.m_month, entry.m_day), QTime(entry.m_hour, entry.m_minute, entry.m_second));
		}
	}
	if(role == Qt::SizeHintRole) {
		return QSize(100, m_row_height);
	}
	return QVariant();
}

bool ScheduleModel::setData(const QModelIndex& index, const QVariant& value, int role) {
	assert(index.isValid());
	PageRecord::ScheduleEntry &entry = m_schedule[index.row()];
	if(role == Qt::EditRole) {
		switch(index.column()) {
			case 0: entry.m_timing = value.value<PageRecord::enum_schedule_timing>(); return true;
			case 1: entry.m_month = value.toInt(); return true;
			case 2: entry.m_day = value.toInt(); return true;
			case 3: entry.m_hour = value.toInt(); return true;
			case 4: entry.m_minute = value.toInt(); return true;
			case 5: entry.m_second = value.toInt(); return true;
			case 6: entry.m_action = (PageRecord::enum_schedule_action) value.toInt(); return true;
		}
	}
	return false;
}*/

RecordScheduleEntryWidget::RecordScheduleEntryWidget(PageRecord::ScheduleEntry entry, QWidget* parent)
	: QFrame(parent) {

	setFrameStyle(QFrame::Box);
	setBackgroundRole(QPalette::Window);
	setAutoFillBackground(true);

	QLabel *label_time = new QLabel(tr("Time:"), this);
	m_combobox_timing = new QComboBox(this);
	m_combobox_timing->addItem(tr("After previous action"));
	m_combobox_timing->addItem(tr("At fixed time"));
	m_combobox_timing->addItem(tr("At fixed date/time"));
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
	layout->setMargin(3);
	layout->addWidget(label_time, 0, 0);
	layout->addWidget(m_combobox_timing, 0, 1);
	layout->addWidget(m_timeedit_time, 0, 2);
	layout->addWidget(label_action, 1, 0);
	layout->addWidget(m_combobox_action, 1, 1, 1, 2);

}

RecordScheduleEntryWidget::~RecordScheduleEntryWidget() {

}

RecordScheduleListWidget::RecordScheduleListWidget(QWidget* parent)
	: QWidget(parent) {

	setBackgroundRole(QPalette::Dark);
	setAutoFillBackground(true);

	m_layout = new QVBoxLayout(this);
	m_layout->setMargin(3);
	m_layout->setSpacing(3);
	m_layout->addSpacing(20);
	m_layout->addStretch();

}

RecordScheduleListWidget::~RecordScheduleListWidget() {

}

void RecordScheduleListWidget::AddEntry(PageRecord::ScheduleEntry entry) {
	m_entries.push_back(new RecordScheduleEntryWidget(entry, this));
	m_layout->insertWidget(m_entries.size() - 1, m_entries.back());
}

void RecordScheduleListWidget::RemoveEntry(unsigned int index) {
	assert(index < m_entries.size());
	delete m_entries[index];
	m_entries.erase(m_entries.begin() + index);
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
	m_label_time->setMinimumWidth(m_label_time->fontMetrics().width("0000-00-00 00:00:00") + 20);
	m_label_time->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	/*m_editor_factory.registerEditor((QVariant::Type) qMetaTypeId<PageRecord::enum_schedule_timing>(), new QStandardItemEditorCreator<ComboBox_ScheduleTiming>());
	//m_editor_factory.registerEditor(qRegisterMetaType<PageRecord::enum_schedule_action>(), new QStandardItemEditorCreator<ComboBox_ScheduleAction>());

	m_item_delegate = new QItemDelegate(this);
	m_item_delegate->setItemEditorFactory(&m_editor_factory);

	m_treeview_schedule = new QTreeView(this);
	m_treeview_schedule->setUniformRowHeights(true);
	m_treeview_schedule->setItemsExpandable(false);
	m_treeview_schedule->setAllColumnsShowFocus(true);
	m_treeview_schedule->setIndentation(0);
	m_treeview_schedule->setItemDelegate(m_item_delegate);
	m_treeview_schedule->setModel(&m_schedule_model);

	{
		std::vector<unsigned int> column_widths = {100, 30, 30, 30, 30, 30, 150, 150};
		unsigned int total_width = 2;
		for(unsigned int i = 0; i < column_widths.size(); ++i) {
			unsigned int min_width = m_treeview_schedule->header()->fontMetrics().width(m_schedule_model.headerData(i, Qt::Horizontal, Qt::DisplayRole).toString()) + 10;
			unsigned int width = std::max(min_width, column_widths[i]);
			m_treeview_schedule->setColumnWidth(i, width);
			total_width += width + 2;
		}
		m_treeview_schedule->setMinimumWidth(total_width);
	}*/

	m_schedule_list = new RecordScheduleListWidget(this);
	m_schedule_list->AddEntry({PageRecord::SCHEDULE_TIMING_AFTER_PREVIOUS, 1, 2, 3, 4, 5, PageRecord::SCHEDULE_ACTION_START});
	m_schedule_list->AddEntry({PageRecord::SCHEDULE_TIMING_FIXED_TIME, 6, 7, 8, 9, 10, PageRecord::SCHEDULE_ACTION_START});
	m_schedule_list->AddEntry({PageRecord::SCHEDULE_TIMING_AFTER_PREVIOUS, 11, 12, 13, 14, 15, PageRecord::SCHEDULE_ACTION_PAUSE});

	QScrollArea *scroll_area = new QScrollArea(this);
	scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	scroll_area->setWidgetResizable(true);
	scroll_area->setWidget(m_schedule_list);

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
		layout2->addStretch();
		layout2->addWidget(label_time);
		layout2->addWidget(m_label_time);
	}
	layout->addWidget(scroll_area);
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
	m_label_time->setText(m_clock_time.toString("yyyy-MM-dd hh:mm:ss"));
	m_clock_time = m_clock_time.addSecs(1);
	m_timer_clock->start(now.msecsTo(m_clock_time));
}

void DialogRecordSchedule::OnAdd() {

}

void DialogRecordSchedule::OnRemove() {

}

void DialogRecordSchedule::OnMoveUp() {

}

void DialogRecordSchedule::OnMoveDown() {

}
