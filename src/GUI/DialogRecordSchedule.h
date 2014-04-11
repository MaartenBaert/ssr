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

/*class ComboBox_ScheduleTiming : public QComboBox {
	Q_OBJECT
	Q_PROPERTY(PageRecord::enum_schedule_timing timing READ GetTiming WRITE SetTiming USER true)

public:
	ComboBox_ScheduleTiming(QWidget* parent = NULL);
	PageRecord::enum_schedule_timing GetTiming();
	void SetTiming(PageRecord::enum_schedule_timing timing);

};

class ScheduleModel : public QAbstractItemModel {

private:
	std::vector<PageRecord::ScheduleEntry> m_schedule;

	int m_row_height;

public:
	ScheduleModel();
	~ScheduleModel();

	virtual QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
	virtual QModelIndex parent(const QModelIndex& index) const override;
	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

};*/

class RecordScheduleEntryWidget : public QFrame {
	Q_OBJECT

private:
	QComboBox *m_combobox_timing;
	QTimeEdit *m_timeedit_time;
	QComboBox *m_combobox_action;

public:
	RecordScheduleEntryWidget(PageRecord::ScheduleEntry entry, QWidget* parent = NULL);
	~RecordScheduleEntryWidget();

};

class RecordScheduleListWidget : public QWidget {
	Q_OBJECT

private:
	std::vector<RecordScheduleEntryWidget*> m_entries;

	QVBoxLayout *m_layout;

public:
	RecordScheduleListWidget(QWidget* parent = NULL);
	~RecordScheduleListWidget();

	void AddEntry(PageRecord::ScheduleEntry entry);
	void RemoveEntry(unsigned int index);

};

class DialogRecordSchedule : public QDialog {
	Q_OBJECT

private:
	PageRecord *m_parent;

	//QItemEditorFactory m_editor_factory;
	//QItemDelegate *m_item_delegate;
	//ScheduleModel m_schedule_model;

	QComboBox *m_combobox_timezone;
	QLabel *m_label_time;
	//QTreeView *m_treeview_schedule;
	RecordScheduleListWidget *m_schedule_list;

	QDateTime m_clock_time;
	QTimer *m_timer_clock;

public:
	DialogRecordSchedule(PageRecord* parent);
	~DialogRecordSchedule();

private:
	QDateTime GetCurrentTime();

private slots:
	void OnWriteBack();
	void OnTimeZoneChanged();
	void OnUpdateTime();
	void OnAdd();
	void OnRemove();
	void OnMoveUp();
	void OnMoveDown();

};
