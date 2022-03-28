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

#include "PageRecord.h"

#include "CommandLineOptions.h"
#include "Icons.h"
#include "Dialogs.h"
#include "EnumStrings.h"
#include "MainWindow.h"
#include "PageInput.h"
#include "PageOutput.h"
#include "DialogRecordSchedule.h"

#include "HotkeyListener.h"

#include "Muxer.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"
#include "Synchronizer.h"
#include "X11Input.h"
#if SSR_USE_OPENGL_RECORDING
#include "GLInjectInput.h"
#endif
#if SSR_USE_V4L2
#include "V4L2Input.h"
#endif
#if SSR_USE_ALSA
#include "ALSAInput.h"
#endif
#if SSR_USE_PULSEAUDIO
#include "PulseAudioInput.h"
#endif
#if SSR_USE_JACK
#include "JACKInput.h"
#endif
#include "SimpleSynth.h"
#include "VideoPreviewer.h"
#include "AudioPreviewer.h"

static QString GetNewSegmentFile(const QString& file, bool add_timestamp) {
	QFileInfo fi(file);
	QDateTime now = QDateTime::currentDateTime();
	QString newfile;
	unsigned int counter = 0;
	do {
		++counter;
		newfile = fi.completeBaseName();
		if(add_timestamp) {
			if(!newfile.isEmpty())
				newfile += "-";
			newfile += now.toString("yyyy-MM-dd_hh.mm.ss");
		}
		if(counter != 1) {
			if(!newfile.isEmpty())
				newfile += "-";
			newfile += QString::number(counter);
		}
		if(!fi.suffix().isEmpty())
			newfile += "." + fi.suffix();
		newfile = fi.path() + "/" + newfile;
	} while(QFileInfo(newfile).exists());
	return newfile;
}

static std::vector<std::pair<QString, QString> > GetOptionsFromString(const QString& str) {
	std::vector<std::pair<QString, QString> > options;
	QStringList optionlist = SplitSkipEmptyParts(str, ',');
	for(int i = 0; i < optionlist.size(); ++i) {
		QString a = optionlist[i];
		int p = a.indexOf('=');
		if(p < 0) {
			options.push_back(std::make_pair(a.trimmed(), QString()));
		} else {
			options.push_back(std::make_pair(a.mid(0, p).trimmed(), a.mid(p + 1).trimmed()));
		}
	}
	return options;
}

static QString ReadableSizeIEC(uint64_t size, const QString& suffix) {
	if(size < (uint64_t) 10 * 1024)
		return QString::number(size) + " " + suffix;
	if(size < (uint64_t) 10 * 1024 * 1024)
		return QString::number((size + 512) / 1024) + " Ki" + suffix;
	if(size < (uint64_t) 10 * 1024 * 1024 * 1024)
		return QString::number((size / 1024 + 512) / 1024) + " Mi" + suffix;
	return QString::number((size / (1024 * 1024) + 512) / 1024) + " Gi" + suffix;
}

static QString ReadableSizeSI(uint64_t size, const QString& suffix) {
	if(size < (uint64_t) 10 * 1000)
		return QString::number(size) + " " + suffix;
	if(size < (uint64_t) 10 * 1000 * 1000)
		return QString::number((size + 500) / 1000) + " k" + suffix;
	if(size < (uint64_t) 10 * 1000 * 1000 * 1000)
		return QString::number((size / 1000 + 500) / 1000) + " M" + suffix;
	return QString::number((size / (1000 * 1000) + 512) / 1024) + " G" + suffix;
}

static QString ReadableTime(int64_t time_micro) {
	unsigned int time = (time_micro + 500000) / 1000000;
	return QString("%1:%2:%3")
			.arg(time / 3600)
			.arg((time / 60) % 60, 2, 10, QLatin1Char('0'))
			.arg(time % 60, 2, 10, QLatin1Char('0'));
}

static QString ReadableWidthHeight(unsigned int width, unsigned int height) {
	if(width == 0 && height == 0)
		return "?";
	return QString::number(width) + "x" + QString::number(height);
}

class QTextEditSmall : public QTextEdit {

public:
	QTextEditSmall(QWidget *parent) : QTextEdit(parent) {}
	QTextEditSmall(const QString& text, QWidget *parent) : QTextEdit(text, parent) {}
	virtual QSize sizeHint() const override { return QSize(-1, 100); }

};

// sound notification sequences
#if SSR_USE_ALSA
static const std::array<SimpleSynth::Note, 1> SEQUENCE_RECORD_START = {{
	{0    , 500, 10000, 440.0f * exp2f( 3.0f / 12.0f), 0.8f}, // C5
}};
static const std::array<SimpleSynth::Note, 2> SEQUENCE_RECORD_STOP = {{
	{0    , 500, 20000, 440.0f * exp2f( 3.0f / 12.0f), 0.8f}, // C5
	{10000, 500, 20000, 440.0f * exp2f(-2.0f / 12.0f), 0.8f}, // G4
}};
static const std::array<SimpleSynth::Note, 4> SEQUENCE_RECORD_ERROR = {{
	{0    , 500, 20000, 440.0f * exp2f(-2.0f / 12.0f), 0.8f}, // G4
	{10000, 500, 20000, 440.0f * exp2f(-2.0f / 12.0f), 0.8f}, // G4
	{20000, 500, 20000, 440.0f * exp2f(-6.0f / 12.0f), 0.4f}, // D#4
	{20000, 500, 20000, 440.0f * exp2f(-9.0f / 12.0f), 0.6f}, // C4
}};
#endif

PageRecord::PageRecord(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_page_started = false;
	m_input_started = false;
	m_output_started = false;
	m_previewing = false;

	m_schedule_active = false;
	m_schedule_time_zone = SCHEDULE_TIME_ZONE_LOCAL;

#if SSR_USE_ALSA
	m_last_error_sound = std::numeric_limits<int64_t>::min();
#endif

	m_stdin_reentrant = false;

	QGroupBox *groupbox_recording = new QGroupBox(tr("Recording"), this);
	{
		m_pushbutton_record = new QPushButton(groupbox_recording);

		m_label_schedule_status = new QLabel(groupbox_recording);
		m_pushbutton_schedule_activate = new QPushButton(groupbox_recording);
		m_pushbutton_schedule_edit = new QPushButton(tr("Edit schedule"), groupbox_recording);
		m_pushbutton_schedule_edit->setToolTip(tr("The recording schedule can be used to automatically start or pause the recording at a predefined time."));

		m_checkbox_hotkey_enable = new QCheckBox(tr("Enable recording hotkey"), groupbox_recording);
		m_checkbox_hotkey_enable->setToolTip(tr("The recording hotkey is a global keyboard shortcut that can be used to start or pause the recording at any time,\n"
												"even when the SimpleScreenRecorder window is not visible. This way you can create recordings without having the\n"
												"SimpleScreenRecorder window show up in the final video."));
#if SSR_USE_ALSA
		m_checkbox_sound_notifications_enable = new QCheckBox(tr("Enable sound notifications"), groupbox_recording);
		m_checkbox_sound_notifications_enable->setToolTip(tr("When enabled, a sound will be played when the recording is started or paused, or when an error occurs."));
#endif
		QLabel *label_hotkey = new QLabel(tr("Hotkey:"), groupbox_recording);
		m_checkbox_hotkey_ctrl = new QCheckBox(tr("Ctrl +"), groupbox_recording);
		m_checkbox_hotkey_shift = new QCheckBox(tr("Shift +"), groupbox_recording);
		m_checkbox_hotkey_alt = new QCheckBox(tr("Alt +"), groupbox_recording);
		m_checkbox_hotkey_super = new QCheckBox(tr("Super +"), groupbox_recording);
		m_combobox_hotkey_key = new QComboBox(groupbox_recording);
		m_combobox_hotkey_key->setToolTip(tr("The key that you have to press (combined with the given modifiers) to start or pause recording.\n"
											 "The program that you are recording will not receive the key press."));
		// Note: The choice of keys is currently rather limited, because capturing key presses session-wide is a bit harder than it looks.
		// For example, applications are not allowed to capture the F1-F12 keys (on Ubuntu at least). The A-Z keys don't have this limitation apparently.
		for(unsigned int i = 0; i < 26; ++i) {
			m_combobox_hotkey_key->addItem(QString('A' + i));
		}

		connect(m_pushbutton_record, SIGNAL(clicked()), this, SLOT(OnRecordStartPause()));
		connect(m_pushbutton_schedule_activate, SIGNAL(clicked()), this, SLOT(OnScheduleActivateDeactivate()));
		connect(m_pushbutton_schedule_edit, SIGNAL(clicked()), this, SLOT(OnScheduleEdit()));
		connect(m_checkbox_hotkey_enable, SIGNAL(clicked()), this, SLOT(OnUpdateHotkeyFields()));
#if SSR_USE_ALSA
		connect(m_checkbox_sound_notifications_enable, SIGNAL(clicked()), this, SLOT(OnUpdateSoundNotifications()));
#endif
		connect(m_checkbox_hotkey_ctrl, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_checkbox_hotkey_shift, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_checkbox_hotkey_alt, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_checkbox_hotkey_super, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_combobox_hotkey_key, SIGNAL(activated(int)), this, SLOT(OnUpdateHotkey()));

		QVBoxLayout *layout = new QVBoxLayout(groupbox_recording);
		layout->addWidget(m_pushbutton_record);
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_label_schedule_status, 2);
			layout2->addWidget(m_pushbutton_schedule_activate, 1);
			layout2->addWidget(m_pushbutton_schedule_edit, 1);
		}
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_checkbox_hotkey_enable);
#if SSR_USE_ALSA
			layout2->addWidget(m_checkbox_sound_notifications_enable);
#endif
		}
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(label_hotkey);
			layout2->addWidget(m_checkbox_hotkey_ctrl);
			layout2->addWidget(m_checkbox_hotkey_shift);
			layout2->addWidget(m_checkbox_hotkey_alt);
			layout2->addWidget(m_checkbox_hotkey_super);
			layout2->addWidget(m_combobox_hotkey_key);
		}
	}
	QSplitter *splitter_vertical = new QSplitter(Qt::Vertical, this);
	{
		QSplitter *splitter_horizontal = new QSplitter(Qt::Horizontal, splitter_vertical);
		{
			QGroupBox *groupbox_information = new QGroupBox(tr("Information"), splitter_horizontal);
			{
				QLabel *label_total_time = new QLabel(tr("Total time:"), groupbox_information);
				m_label_info_total_time = new QLabel(groupbox_information);
				QLabel *label_frame_rate_in = new QLabel(tr("FPS in:"), groupbox_information);
				m_label_info_frame_rate_in = new QLabel(groupbox_information);
				QLabel *label_frame_rate_out = new QLabel(tr("FPS out:"), groupbox_information);
				m_label_info_frame_rate_out = new QLabel(groupbox_information);
				QLabel *label_size_in = new QLabel(tr("Size in:"), groupbox_information);
				m_label_info_size_in = new QLabel(groupbox_information);
				QLabel *label_size_out = new QLabel(tr("Size out:"), groupbox_information);
				m_label_info_size_out = new QLabel(groupbox_information);
				QLabel *label_file_name = new QLabel(tr("File name:"), groupbox_information);
				m_label_info_file_name = new ElidedLabel(QString(), Qt::ElideMiddle, groupbox_information);
				m_label_info_file_name->setMinimumWidth(100);
				QLabel *label_file_size = new QLabel(tr("File size:"), groupbox_information);
				m_label_info_file_size = new QLabel(groupbox_information);
				QLabel *label_bit_rate = new QLabel(tr("Bit rate:"), groupbox_information);
				m_label_info_bit_rate = new QLabel(groupbox_information);
				m_checkbox_show_recording_area = new QCheckBox(tr("Show recording area"), groupbox_information);
				m_checkbox_show_recording_area->setToolTip(tr("When enabled, the recorded area is marked on the screen."));

				connect(m_checkbox_show_recording_area, SIGNAL(clicked()), this, SLOT(OnUpdateRecordingFrame()));

				QGridLayout *layout = new QGridLayout(groupbox_information);
				layout->addWidget(label_total_time, 0, 0);
				layout->addWidget(m_label_info_total_time, 0, 1);
				layout->addWidget(label_frame_rate_in, 1, 0);
				layout->addWidget(m_label_info_frame_rate_in, 1, 1);
				layout->addWidget(label_frame_rate_out, 2, 0);
				layout->addWidget(m_label_info_frame_rate_out, 2, 1);
				layout->addWidget(label_size_in, 3, 0);
				layout->addWidget(m_label_info_size_in, 3, 1);
				layout->addWidget(label_size_out, 4, 0);
				layout->addWidget(m_label_info_size_out, 4, 1);
				layout->addWidget(label_file_name, 5, 0);
				layout->addWidget(m_label_info_file_name, 5, 1);
				layout->addWidget(label_file_size, 6, 0);
				layout->addWidget(m_label_info_file_size, 6, 1);
				layout->addWidget(label_bit_rate, 7, 0);
				layout->addWidget(m_label_info_bit_rate, 7, 1);
				layout->addWidget(m_checkbox_show_recording_area, 9, 0, 1, 2);
				layout->setColumnStretch(1, 1);
				layout->setRowStretch(8, 1);
			}
			QGroupBox *groupbox_preview = new QGroupBox(tr("Preview"), splitter_horizontal);
			{
				m_preview_page1 = new QWidget(groupbox_preview);
				{
					QLabel *label_preview_frame_rate = new QLabel(tr("Preview frame rate:"), m_preview_page1);
					m_spinbox_preview_frame_rate = new QSpinBox(m_preview_page1);
					m_spinbox_preview_frame_rate->setRange(1, 1000);
					m_spinbox_preview_frame_rate->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
					QLabel *label_preview_note = new QLabel(tr("Note: Previewing requires extra CPU time (especially at high frame rates)."), m_preview_page1);
					label_preview_note->setWordWrap(true);
					label_preview_note->setAlignment(Qt::AlignLeft | Qt::AlignTop);
					label_preview_note->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::MinimumExpanding);

					QGridLayout *layout = new QGridLayout(m_preview_page1);
					layout->setMargin(0);
					layout->addWidget(label_preview_frame_rate, 0, 0);
					layout->addWidget(m_spinbox_preview_frame_rate, 0, 1);
					layout->addWidget(label_preview_note, 1, 0, 1, 2);
				}
				m_preview_page2 = new QWidget(groupbox_preview);
				{
					m_video_previewer = new VideoPreviewer(m_preview_page2);
					m_label_mic_icon = new QLabel(m_preview_page2);
					m_label_mic_icon->setPixmap(g_icon_microphone.pixmap(24, 24));
					m_audio_previewer = new AudioPreviewer(m_preview_page2);

					QVBoxLayout *layout = new QVBoxLayout(m_preview_page2);
					layout->setMargin(0);
					layout->addWidget(m_video_previewer);
					{
						QHBoxLayout *layout2 = new QHBoxLayout();
						layout->addLayout(layout2);
						layout2->addStretch();
						layout2->addWidget(m_label_mic_icon);
						layout2->addWidget(m_audio_previewer);
						layout2->addStretch();
					}
				}
				m_pushbutton_preview_start_stop = new QPushButton(groupbox_preview);

				connect(m_pushbutton_preview_start_stop, SIGNAL(clicked()), this, SLOT(OnPreviewStartStop()));

				QVBoxLayout *layout = new QVBoxLayout(groupbox_preview);
				{
					m_stacked_layout_preview = new QStackedLayout();
					layout->addLayout(m_stacked_layout_preview);
					m_stacked_layout_preview->addWidget(m_preview_page1);
					m_stacked_layout_preview->addWidget(m_preview_page2);
				}
				layout->addWidget(m_pushbutton_preview_start_stop);
			}

			splitter_horizontal->addWidget(groupbox_information);
			splitter_horizontal->addWidget(groupbox_preview);
			splitter_horizontal->setStretchFactor(0, 1);
			splitter_horizontal->setStretchFactor(1, 3);
		}
		QGroupBox *groupbox_log = new QGroupBox(tr("Log"), splitter_vertical);
		{
			m_textedit_log = new QTextEditSmall(groupbox_log);
			m_textedit_log->setReadOnly(true);

			QVBoxLayout *layout = new QVBoxLayout(groupbox_log);
			layout->addWidget(m_textedit_log);
		}

		splitter_vertical->addWidget(splitter_horizontal);
		splitter_vertical->addWidget(groupbox_log);
		splitter_vertical->setStretchFactor(0, 3);
		splitter_vertical->setStretchFactor(1, 1);
	}

	QPushButton *button_cancel = new QPushButton(g_icon_cancel, tr("Cancel recording"), this);
	QPushButton *button_save = new QPushButton(g_icon_save, tr("Save recording"), this);

	if(CommandLineOptions::GetSysTray()) {
		m_systray_icon = new QSystemTrayIcon(g_icon_ssr_idle, m_main_window);
		QMenu *menu = new QMenu(m_main_window);
		m_systray_action_start_pause = menu->addAction(QString(), this, SLOT(OnRecordStartPause()));
		m_systray_action_start_pause->setIconVisibleInMenu(true);
		m_systray_action_cancel = menu->addAction(g_icon_cancel, tr("Cancel recording"), this, SLOT(OnRecordCancel()));
		m_systray_action_cancel->setIconVisibleInMenu(true);
		m_systray_action_save = menu->addAction(g_icon_save, tr("Save recording"), this, SLOT(OnRecordSave()));
		m_systray_action_save->setIconVisibleInMenu(true);
		menu->addSeparator();
		m_systray_action_show_hide = menu->addAction(QString(), m_main_window, SLOT(OnShowHide()));
		m_systray_action_show_hide->setIconVisibleInMenu(true);
		m_systray_action_quit = menu->addAction(g_icon_quit, tr("Quit"), m_main_window, SLOT(close()));
		m_systray_action_quit->setIconVisibleInMenu(true);
		m_systray_icon->setContextMenu(menu);
	} else {
		m_systray_icon = NULL;
	}

	connect(button_cancel, SIGNAL(clicked()), this, SLOT(OnRecordCancel()));
	connect(button_save, SIGNAL(clicked()), this, SLOT(OnRecordSave()));
	if(m_systray_icon != NULL)
		connect(m_systray_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), m_main_window, SLOT(OnSysTrayActivated(QSystemTrayIcon::ActivationReason)));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(groupbox_recording);
	layout->addWidget(splitter_vertical);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_cancel);
		layout2->addWidget(button_save);
	}

	m_stdin_notifier = new QSocketNotifier(0, QSocketNotifier::Read, this);
	connect(m_stdin_notifier, SIGNAL(activated(int)), this, SLOT(OnStdin()));

	m_timer_schedule = new QTimer(this);
	m_timer_schedule->setSingleShot(true);
	m_timer_update_info = new QTimer(this);
	connect(m_timer_schedule, SIGNAL(timeout()), this, SLOT(OnScheduleTimer()));
	connect(m_timer_update_info, SIGNAL(timeout()), this, SLOT(OnUpdateInformation()));
	connect(&m_hotkey_start_pause, SIGNAL(Triggered()), this, SLOT(OnRecordStartPause()), Qt::QueuedConnection);
	connect(Logger::GetInstance(), SIGNAL(NewLine(Logger::enum_type,QString)), this, SLOT(OnNewLogLine(Logger::enum_type,QString)), Qt::QueuedConnection);

	UpdateSysTray();
	UpdateRecordButton();
	UpdateSchedule();
	UpdatePreview();
	OnUpdateRecordingFrame();

	if(m_systray_icon != NULL)
		m_systray_icon->show();

}

PageRecord::~PageRecord() {
	StopPage(false);
}

bool PageRecord::ShouldBlockClose() {
	if(m_output_manager != NULL) {
		if(MessageBox(QMessageBox::Warning, this, MainWindow::WINDOW_CAPTION,
					  tr("You have not saved the current recording yet, if you quit now it will be lost.\n"
						 "Are you sure that you want to quit?"), BUTTON_YES | BUTTON_NO, BUTTON_YES) != BUTTON_YES) {
			return true;
		}
	}
	return false;
}

void PageRecord::UpdateShowHide() {
	if(m_systray_icon == NULL)
		return;
	if(m_main_window->isVisible()) {
		m_systray_action_show_hide->setText(tr("Hide window"));
	} else {
		m_systray_action_show_hide->setText(tr("Show window"));
	}
}

void PageRecord::LoadSettings(QSettings *settings) {
	SetHotkeyEnabled(settings->value("record/hotkey_enable", true).toBool());
	SetHotkeyCtrlEnabled(settings->value("record/hotkey_ctrl", false).toBool());
	SetHotkeyShiftEnabled(settings->value("record/hotkey_shift", false).toBool());
	SetHotkeyAltEnabled(settings->value("record/hotkey_alt", false).toBool());
	SetHotkeySuperEnabled(settings->value("record/hotkey_super", true).toBool());
	SetHotkeyKey(settings->value("record/hotkey_key", 'r' - 'a').toUInt());
#if SSR_USE_ALSA
	SetSoundNotificationsEnabled(settings->value("record/sound_notifications_enable", false).toBool());
#endif
	SetShowRecordingArea(settings->value("record/show_recording_area", false).toBool());
	SetPreviewFrameRate(settings->value("record/preview_frame_rate", 10).toUInt());
	SetScheduleTimeZone(StringToEnum(settings->value("record/schedule_time_zone", QString()).toString(), SCHEDULE_TIME_ZONE_LOCAL));
	unsigned int num_entries = clamp(settings->value("record/schedule_num_entries", 0).toUInt(), 0u, 1000u);
	m_schedule_entries.clear();
	m_schedule_entries.resize(num_entries);
	Qt::TimeSpec spec = SCHEDULE_TIME_ZONE_TIMESPECS[GetScheduleTimeZone()];
	for(unsigned int i = 0; i < num_entries; ++i) {
		QString timestring = settings->value(QString("record/schedule_entry%1_time").arg(i), QString()).toString();
		QString actionstring = settings->value(QString("record/schedule_entry%1_action").arg(i), QString()).toString();
		m_schedule_entries[i].time = QDateTime::fromString(timestring, "yyyy-MM-dd hh:mm:ss");
		m_schedule_entries[i].time.setTimeSpec(spec);
		m_schedule_entries[i].action = StringToEnum(actionstring, SCHEDULE_ACTION_START);
	}
	OnUpdateHotkeyFields();
#if SSR_USE_ALSA
	OnUpdateSoundNotifications();
#endif
	OnUpdateRecordingFrame();
}

void PageRecord::SaveSettings(QSettings *settings) {
	settings->setValue("record/hotkey_enable", IsHotkeyEnabled());
	settings->setValue("record/hotkey_ctrl", IsHotkeyCtrlEnabled());
	settings->setValue("record/hotkey_shift", IsHotkeyShiftEnabled());
	settings->setValue("record/hotkey_alt", IsHotkeyAltEnabled());
	settings->setValue("record/hotkey_super", IsHotkeySuperEnabled());
	settings->setValue("record/hotkey_key", GetHotkeyKey());
#if SSR_USE_ALSA
	settings->setValue("record/sound_notifications_enable", AreSoundNotificationsEnabled());
#endif
	settings->setValue("record/show_recording_area", GetShowRecordingArea());
	settings->setValue("record/preview_frame_rate", GetPreviewFrameRate());
	settings->setValue("record/schedule_time_zone", EnumToString(GetScheduleTimeZone()));
	settings->setValue("record/schedule_num_entries", (unsigned int) m_schedule_entries.size());
	for(unsigned int i = 0; i < m_schedule_entries.size(); ++i) {
		settings->setValue(QString("record/schedule_entry%1_time").arg(i), m_schedule_entries[i].time.toString("yyyy-MM-dd hh:mm:ss"));
		settings->setValue(QString("record/schedule_entry%1_action").arg(i), EnumToString(m_schedule_entries[i].action));
	}
}

bool PageRecord::TryStartPage() {
	if(m_page_started)
		return true;
	if(!m_main_window->Validate())
		return false;
	m_main_window->GoPageRecord();
	assert(m_page_started);
	return true;
}

void PageRecord::StartPage() {

	if(m_page_started)
		return;

	assert(!m_input_started);
	assert(!m_output_started);

	// save the settings in case libav/ffmpeg decides to kill the process
	m_main_window->SaveSettings();

	// clear the log
	m_textedit_log->clear();

	// clear the preview
	if(m_previewing) {
		m_video_previewer->Reset();
		m_audio_previewer->Reset();
	}

	PageInput *page_input = m_main_window->GetPageInput();
	PageOutput *page_output = m_main_window->GetPageOutput();

	// get the video input settings
	m_video_area = page_input->GetVideoArea();
	m_video_area_follow_fullscreen = page_input->GetVideoAreaFollowFullscreen();
#if SSR_USE_V4L2
	m_v4l2_device = page_input->GetVideoV4L2Device();
#endif
	m_video_x = page_input->GetVideoX();
	m_video_y = page_input->GetVideoY();
#if SSR_USE_OPENGL_RECORDING
	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
		m_video_in_width = 0;
		m_video_in_height = 0;
	} else {
#else
	{
#endif
		m_video_in_width = page_input->GetVideoW();
		m_video_in_height = page_input->GetVideoH();
	}
	m_video_in_width = page_input->GetVideoW();
	m_video_in_height = page_input->GetVideoH();
	m_video_frame_rate = page_input->GetVideoFrameRate();
	m_video_scaling = page_input->GetVideoScalingEnabled();
	m_video_scaled_width = page_input->GetVideoScaledW();
	m_video_scaled_height = page_input->GetVideoScaledH();
	m_video_record_cursor = page_input->GetVideoRecordCursor();

	// get the audio input settings
	m_audio_enabled = page_input->GetAudioEnabled();
	m_audio_channels = 2;
	m_audio_sample_rate = 48000;
	m_audio_backend = page_input->GetAudioBackend();
#if SSR_USE_ALSA
	m_alsa_source = page_input->GetALSASourceName();
#endif
#if SSR_USE_PULSEAUDIO
	m_pulseaudio_source = page_input->GetPulseAudioSourceName();
#endif
#if SSR_USE_JACK
	bool jack_connect_system_capture = page_input->GetJackConnectSystemCapture();
	bool jack_connect_system_playback = page_input->GetJackConnectSystemPlayback();
#endif

	// override sample rate for problematic cases (these are hard-coded for now)
	if(page_output->GetContainer() == PageOutput::CONTAINER_OTHER && page_output->GetContainerAVName() == "flv") {
		m_audio_sample_rate = 44100;
	}

#if SSR_USE_OPENGL_RECORDING
	// get the glinject settings
	QString glinject_channel = page_input->GetGLInjectChannel();
	bool glinject_relax_permissions = page_input->GetGLInjectRelaxPermissions();
	QString glinject_command = page_input->GetGLInjectCommand();
	QString glinject_working_directory = page_input->GetGLInjectWorkingDirectory();
	bool glinject_auto_launch = page_input->GetGLInjectAutoLaunch();
	bool glinject_limit_fps = page_input->GetGLInjectLimitFPS();
#endif

	// get file settings
	m_file_base = page_output->GetFile();
	m_file_protocol = page_output->GetFileProtocol();
	m_separate_files = page_output->GetSeparateFiles();
	m_add_timestamp = page_output->GetAddTimestamp();

	// get the output settings
	m_output_settings.file = QString(); // will be set later
	m_output_settings.container_avname = page_output->GetContainerAVName();

	m_output_settings.video_codec_avname = page_output->GetVideoCodecAVName();
	m_output_settings.video_kbit_rate = page_output->GetVideoKBitRate();
	m_output_settings.video_options.clear();
	m_output_settings.video_width = 0;
	m_output_settings.video_height = 0;
	m_output_settings.video_frame_rate = m_video_frame_rate;
	m_output_settings.video_allow_frame_skipping = page_output->GetVideoAllowFrameSkipping();

	m_output_settings.audio_codec_avname = (m_audio_enabled)? page_output->GetAudioCodecAVName() : QString();
	m_output_settings.audio_kbit_rate = page_output->GetAudioKBitRate();
	m_output_settings.audio_options.clear();
	m_output_settings.audio_channels = m_audio_channels;
	m_output_settings.audio_sample_rate = m_audio_sample_rate;

	// some codec-specific things
	// you can get more information about all these options by running 'ffmpeg -h' or 'avconv -h' from a terminal
	switch(page_output->GetVideoCodec()) {
		case PageOutput::VIDEO_CODEC_H264: {
			// x264 has a 'constant quality' mode, where the bit rate is simply set to whatever is needed to keep a certain quality. The quality is set
			// with the 'crf' option. 'preset' changes the encoding speed (and hence the efficiency of the compression) but doesn't really influence the quality,
			// which is great because it means you don't have to experiment with different bit rates and different speeds to get good results.
			m_output_settings.video_options.push_back(std::make_pair(QString("crf"), QString::number(page_output->GetH264CRF())));
			m_output_settings.video_options.push_back(std::make_pair(QString("preset"), EnumToString(page_output->GetH264Preset())));
			break;
		}
		case PageOutput::VIDEO_CODEC_VP8: {
			// The names of there parameters are very unintuitive. The two options we care about (because they change the speed) are 'deadline' and 'cpu-used'.
			// 'deadline=best' is unusably slow. 'deadline=good' is the normal setting, it tells the encoder to use the speed set with 'cpu-used'. Higher
			// numbers will use *less* CPU, confusingly, so a higher number is faster. I haven't done much testing with 'realtime' so I'm not sure if it's a good idea here.
			// It sounds useful, but I think it will use so much CPU that it will slow down the program that is being recorded.
			m_output_settings.video_options.push_back(std::make_pair(QString("deadline"), QString("good")));
			m_output_settings.video_options.push_back(std::make_pair(QString("cpu-used"), QString::number(page_output->GetVP8CPUUsed())));
			break;
		}
		case PageOutput::VIDEO_CODEC_OTHER: {
			m_output_settings.video_options = GetOptionsFromString(page_output->GetVideoOptions());
			break;
		}
		default: break; // to keep GCC happy
	}
	switch(page_output->GetAudioCodec()) {
		case PageOutput::AUDIO_CODEC_OTHER: {
			m_output_settings.audio_options = GetOptionsFromString(page_output->GetAudioOptions());
			break;
		}
		default: break; // to keep GCC happy
	}

	// only show the recording frame option when using a fixed rectangle
	GroupVisible({m_checkbox_show_recording_area}, (m_video_area == PageInput::VIDEO_AREA_FIXED));

	// hide the audio previewer if there is no audio
	GroupVisible({m_label_mic_icon, m_audio_previewer}, m_audio_enabled);

	Logger::LogInfo("[PageRecord::StartPage] " + tr("Starting page ..."));

	try {

#if SSR_USE_OPENGL_RECORDING
		// for OpenGL recording, create the input now
		if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
			if(glinject_auto_launch)
				GLInjectInput::LaunchApplication(glinject_channel, glinject_relax_permissions, glinject_command, glinject_working_directory);
			m_gl_inject_input.reset(new GLInjectInput(glinject_channel, glinject_relax_permissions, m_video_record_cursor, glinject_limit_fps, m_video_frame_rate));
		}
#endif

#if SSR_USE_JACK
		if(m_audio_enabled) {
			// for JACK, start the input now
			if(m_audio_backend == PageInput::AUDIO_BACKEND_JACK)
				m_jack_input.reset(new JACKInput(jack_connect_system_capture, jack_connect_system_playback));
		}
#endif

	} catch(...) {
		Logger::LogError("[PageRecord::StartPage] " + tr("Error: Something went wrong during initialization."));
#if SSR_USE_OPENGL_RECORDING
		m_gl_inject_input.reset();
#endif
#if SSR_USE_JACK
		m_jack_input.reset();
#endif
	}

	Logger::LogInfo("[PageRecord::StartPage] " + tr("Started page."));

	m_page_started = true;
	m_recorded_something = false;
	m_wait_saving = false;
	m_error_occurred = false;
	UpdateSysTray();
#if SSR_USE_ALSA
	OnUpdateSoundNotifications();
#endif

	UpdateInput();
	OnUpdateRecordingFrame();

	OnUpdateInformation();
	m_timer_update_info->start(1000);

	m_schedule_active = false;
	UpdateSchedule();

}

void PageRecord::StopPage(bool save) {

	if(!m_page_started)
		return;

	m_schedule_active = false;
	UpdateSchedule();

	StopOutput(true);
	StopInput();

	Logger::LogInfo("[PageRecord::StopPage] " + tr("Stopping page ..."));

	if(m_output_manager != NULL) {

		// stop the output
		if(save)
			FinishOutput();
		m_output_manager.reset();

		// delete the file if it isn't needed
		if(!save && m_file_protocol.isNull()) {
			if(QFileInfo(m_output_settings.file).exists())
				QFile(m_output_settings.file).remove();
		}

	}

#if SSR_USE_OPENGL_RECORDING
	// stop GLInject input
	m_gl_inject_input.reset();
#endif

#if SSR_USE_JACK
	// stop JACK input
	m_jack_input.reset();
#endif

	Logger::LogInfo("[PageRecord::StopPage] " + tr("Stopped page."));

	m_page_started = false;
	UpdateSysTray();
#if SSR_USE_ALSA
	OnUpdateSoundNotifications();
#endif
	OnUpdateRecordingFrame();

	m_timer_update_info->stop();
	OnUpdateInformation();

}

void PageRecord::StartOutput() {
	assert(m_page_started);

	if(m_output_started)
		return;

#if SSR_USE_ALSA
	if(m_simple_synth != NULL) {
		m_simple_synth->PlaySequence(SEQUENCE_RECORD_START.data(), SEQUENCE_RECORD_START.size());
		usleep(200000);
	}
#endif

	try {

		Logger::LogInfo("[PageRecord::StartOutput] " + tr("Starting output ..."));

		if(m_output_manager == NULL) {

			// set the file name
			m_output_settings.file = GetNewSegmentFile(m_file_base, m_add_timestamp);

			// log the file name
			{
				QString file_name;
				if(m_file_protocol.isNull())
					file_name = m_output_settings.file;
				else
					file_name = "(" + m_file_protocol + ")";
				Logger::LogInfo("[PageRecord::StartOutput] " + tr("Output file: %1").arg(file_name));
			}

			// for X11 recording, update the video size (if possible)
			if(m_x11_input != NULL)
				m_x11_input->GetCurrentSize(&m_video_in_width, &m_video_in_height);

#if SSR_USE_OPENGL_RECORDING
			// for OpenGL recording, detect the video size
			if(m_video_area == PageInput::VIDEO_AREA_GLINJECT && !m_video_scaling) {
				if(m_gl_inject_input == NULL) {
					Logger::LogError("[PageRecord::StartOutput] " + tr("Error: Could not get the size of the OpenGL application because the GLInject input has not been created."));
					throw GLInjectException();
				}
				m_gl_inject_input->GetCurrentSize(&m_video_in_width, &m_video_in_height);
				if(m_video_in_width == 0 && m_video_in_height == 0) {
					Logger::LogError("[PageRecord::StartOutput] " + tr("Error: Could not get the size of the OpenGL application. Either the "
									 "application wasn't started correctly, or the application hasn't created an OpenGL window yet. If "
									 "you want to start recording before starting the application, you have to enable scaling and enter "
									 "the video size manually."));
					throw GLInjectException();
				}
			}
#endif

			// calculate the output width and height
			if(m_video_scaling) {
				// Only even width and height is allowed because some pixel formats (e.g. YUV420) require this.
				m_output_settings.video_width = m_video_scaled_width / 2 * 2;
				m_output_settings.video_height = m_video_scaled_height / 2 * 2;
#if SSR_USE_OPENGL_RECORDING
			} else if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
				// The input size is the size of the OpenGL application and can't be changed. The output size is set to the current size of the application.
				m_output_settings.video_width = m_video_in_width / 2 * 2;
				m_output_settings.video_height = m_video_in_height / 2 * 2;
#endif
			} else {
				// If the user did not explicitly select scaling, then don't force scaling just because the recording area is one pixel too large.
				// One missing row/column of pixels is probably better than a blurry video (and scaling is SLOW).
				m_video_in_width = m_video_in_width / 2 * 2;
				m_video_in_height = m_video_in_height / 2 * 2;
				m_output_settings.video_width = m_video_in_width;
				m_output_settings.video_height = m_video_in_height;
			}

			// start the output
			m_output_manager.reset(new OutputManager(m_output_settings));

		} else {

			// start a new segment
			m_output_manager->GetSynchronizer()->NewSegment();

		}

		Logger::LogInfo("[PageRecord::StartOutput] " + tr("Started output."));

		m_output_started = true;
		m_recorded_something = true;
		UpdateSysTray();
		UpdateRecordButton();
		UpdateInput();
		OnUpdateRecordingFrame();

	} catch(...) {
		Logger::LogError("[PageRecord::StartOutput] " + tr("Error: Something went wrong during initialization."));
	}

}

void PageRecord::StopOutput(bool final) {
	assert(m_page_started);

	if(!m_output_started)
		return;

	Logger::LogInfo("[PageRecord::StopOutput] " + tr("Stopping output ..."));

	// if final, then StopPage will stop the output (and delete the file if needed)
	if(m_separate_files && !final) {

		// stop the output
		FinishOutput();
		m_output_manager.reset();

		// change the file name
		m_output_settings.file = QString();

		// reset the output video size
		m_output_settings.video_width = 0;
		m_output_settings.video_height = 0;

	}

	Logger::LogInfo("[PageRecord::StopOutput] " + tr("Stopped output."));

#if SSR_USE_ALSA
	// if final, don't play the notification (it would get interrupted anyway)
	if(m_simple_synth != NULL && !final)
		m_simple_synth->PlaySequence(SEQUENCE_RECORD_STOP.data(), SEQUENCE_RECORD_STOP.size());
#endif

	m_output_started = false;
	UpdateSysTray();
	UpdateRecordButton();
	UpdateInput();
	OnUpdateRecordingFrame();

}

void PageRecord::StartInput() {
	assert(m_page_started);

	if(m_input_started)
		return;

	assert(m_x11_input == NULL);
#if SSR_USE_ALSA
	assert(m_alsa_input == NULL);
#endif
#if SSR_USE_PULSEAUDIO
	assert(m_pulseaudio_input == NULL);
#endif

	try {

		Logger::LogInfo("[PageRecord::StartInput] " + tr("Starting input ..."));

		// start the video input
		if(m_video_area == PageInput::VIDEO_AREA_SCREEN || m_video_area == PageInput::VIDEO_AREA_FIXED || m_video_area == PageInput::VIDEO_AREA_CURSOR) {
			m_x11_input.reset(new X11Input(m_video_x, m_video_y, m_video_in_width, m_video_in_height, m_video_record_cursor,
										   m_video_area == PageInput::VIDEO_AREA_CURSOR, m_video_area_follow_fullscreen));
			connect(m_x11_input.get(), SIGNAL(CurrentRectangleChanged()), this, SLOT(OnUpdateRecordingFrame()), Qt::QueuedConnection);
		}
#if SSR_USE_OPENGL_RECORDING
		if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
			if(m_gl_inject_input == NULL) {
				Logger::LogError("[PageRecord::StartInput] " + tr("Error: Could not start the GLInject input because it has not been created."));
				throw GLInjectException();
			}
			m_gl_inject_input->SetCapturing(true);
		}
#endif
#if SSR_USE_V4L2
		if(m_video_area == PageInput::VIDEO_AREA_V4L2) {
			m_v4l2_input.reset(new V4L2Input(m_v4l2_device, m_video_in_width, m_video_in_height));
			m_v4l2_input->GetCurrentSize(&m_video_in_width, &m_video_in_height);
		}
#endif

		// start the audio input
		if(m_audio_enabled) {
#if SSR_USE_ALSA
			if(m_audio_backend == PageInput::AUDIO_BACKEND_ALSA)
				m_alsa_input.reset(new ALSAInput(m_alsa_source, m_audio_sample_rate));
#endif
#if SSR_USE_PULSEAUDIO
			if(m_audio_backend == PageInput::AUDIO_BACKEND_PULSEAUDIO)
				m_pulseaudio_input.reset(new PulseAudioInput(m_pulseaudio_source, m_audio_sample_rate));
#endif
			// JACK was started when the page was started
		}

		Logger::LogInfo("[PageRecord::StartInput] " + tr("Started input."));

		m_input_started = true;

	} catch(...) {
		Logger::LogError("[PageRecord::StartInput] " + tr("Error: Something went wrong during initialization."));
		m_x11_input.reset();
#if SSR_USE_OPENGL_RECORDING
		if(m_gl_inject_input != NULL)
			m_gl_inject_input->SetCapturing(false);
#endif
#if SSR_USE_V4L2
		m_v4l2_input.reset();
#endif
#if SSR_USE_ALSA
		m_alsa_input.reset();
#endif
#if SSR_USE_PULSEAUDIO
		m_pulseaudio_input.reset();
#endif
		// JACK shouldn't stop until the page stops
		return;
	}

}

void PageRecord::StopInput() {
	assert(m_page_started);

	if(!m_input_started)
		return;

	Logger::LogInfo("[PageRecord::StopInput] " + tr("Stopping input ..."));

	m_x11_input.reset();
#if SSR_USE_OPENGL_RECORDING
	if(m_gl_inject_input != NULL)
		m_gl_inject_input->SetCapturing(false);
#endif
#if SSR_USE_V4L2
	m_v4l2_input.reset();
#endif
#if SSR_USE_ALSA
	m_alsa_input.reset();
#endif
#if SSR_USE_PULSEAUDIO
	m_pulseaudio_input.reset();
#endif
	// JACK shouldn't stop until the page stops

	Logger::LogInfo("[PageRecord::StopInput] " + tr("Stopped input."));

	m_input_started = false;

}

void PageRecord::FinishOutput() {
	assert(m_output_manager != NULL);

	// tell the output manager to finish
	m_output_manager->Finish();

	// wait until it has actually finished
	m_wait_saving = true;
	//unsigned int frames_left = m_output_manager->GetVideoEncoder()->GetFrameLatency();
	unsigned int frames_done = 0, frames_total = 0;
	QProgressDialog dialog(tr("Encoding remaining data ..."), QString(), 0, frames_total, this);
	dialog.setWindowTitle(MainWindow::WINDOW_CAPTION);
	dialog.setWindowModality(Qt::WindowModal);
	dialog.setCancelButton(NULL);
	dialog.setMinimumDuration(500);
	while(!m_output_manager->IsFinished()) {
		unsigned int frames = m_output_manager->GetTotalQueuedFrameCount();
		if(frames > frames_total)
			frames_total = frames;
		if(frames_total - frames > frames_done)
			frames_done = frames_total - frames;
		//qDebug() << "frames_done" << frames_done << "frames_total" << frames_total << "frames" << frames;
		dialog.setMaximum(frames_total);
		dialog.setValue(frames_done);
		usleep(20000);
	}
	m_wait_saving = false;

}

void PageRecord::UpdateInput() {
	assert(m_page_started);

	if(m_output_started || m_previewing) {
		StartInput();
	} else {
		StopInput();
	}

	// get sources
	VideoSource *video_source = NULL;
	AudioSource *audio_source = NULL;
	if(m_video_area == PageInput::VIDEO_AREA_SCREEN || m_video_area == PageInput::VIDEO_AREA_FIXED|| m_video_area == PageInput::VIDEO_AREA_CURSOR)
		video_source = m_x11_input.get();
#if SSR_USE_OPENGL_RECORDING
	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT)
		video_source = m_gl_inject_input.get();
#endif
#if SSR_USE_V4L2
	if(m_video_area == PageInput::VIDEO_AREA_V4L2)
		video_source = m_v4l2_input.get();
#endif
	if(m_audio_enabled) {
#if SSR_USE_ALSA
		if(m_audio_backend == PageInput::AUDIO_BACKEND_ALSA)
			audio_source = m_alsa_input.get();
#endif
#if SSR_USE_PULSEAUDIO
		if(m_audio_backend == PageInput::AUDIO_BACKEND_PULSEAUDIO)
			audio_source = m_pulseaudio_input.get();
#endif
#if SSR_USE_JACK
		if(m_audio_backend == PageInput::AUDIO_BACKEND_JACK)
			audio_source = m_jack_input.get();
#endif
	}

	// connect sinks
	if(m_output_manager != NULL) {
		if(m_output_started) {
			m_output_manager->GetSynchronizer()->ConnectVideoSource(video_source, PRIORITY_RECORD);
			m_output_manager->GetSynchronizer()->ConnectAudioSource(audio_source, PRIORITY_RECORD);
		} else {
			m_output_manager->GetSynchronizer()->ConnectVideoSource(NULL);
			m_output_manager->GetSynchronizer()->ConnectAudioSource(NULL);
		}
	}
	if(m_previewing) {
		m_video_previewer->ConnectVideoSource(video_source, PRIORITY_PREVIEW);
		m_audio_previewer->ConnectAudioSource(audio_source, PRIORITY_PREVIEW);
	} else {
		m_video_previewer->ConnectVideoSource(NULL);
		m_audio_previewer->ConnectAudioSource(NULL);
	}

}

void PageRecord::UpdateSysTray() {
	if(m_systray_icon == NULL)
		return;
	GroupEnabled({m_systray_action_cancel, m_systray_action_save}, m_page_started);
	if(m_page_started) {
		if(m_error_occurred) {
			m_systray_icon->setIcon(g_icon_ssr_error);
		} else if(m_output_started) {
			m_systray_icon->setIcon(g_icon_ssr_recording);
		} else {
			m_systray_icon->setIcon(g_icon_ssr_paused);
		}
	} else {
		m_systray_icon->setIcon(g_icon_ssr_idle);
	}
	if(m_page_started && m_output_started) {
		m_systray_action_start_pause->setIcon(g_icon_pause);
		m_systray_action_start_pause->setText(tr("Pause recording"));
	} else {
		m_systray_action_start_pause->setIcon(g_icon_record);
		m_systray_action_start_pause->setText(tr("Start recording"));
	}
}

void PageRecord::UpdateRecordButton() {
	if(m_output_started) {
		m_pushbutton_record->setIcon(g_icon_pause);
		m_pushbutton_record->setText(tr("Pause recording"));
	} else {
		m_pushbutton_record->setIcon(g_icon_record);
		m_pushbutton_record->setText(tr("Start recording"));
	}
}

void PageRecord::UpdateSchedule() {
	if(!m_page_started)
		return;
	if(m_schedule_active) {
		m_pushbutton_schedule_activate->setText(tr("Deactivate schedule"));
		m_schedule_position = 0;
		QDateTime now = QDateTime::currentDateTimeUtc();
		while(m_schedule_position < m_schedule_entries.size()) {
			ScheduleEntry &entry = m_schedule_entries[m_schedule_position];
			if(now < entry.time)
				break;
			++m_schedule_position;
		}
	} else {
		m_pushbutton_schedule_activate->setText(tr("Activate schedule"));
	}
	OnScheduleTimer();
}

void PageRecord::UpdatePreview() {
	if(m_previewing) {
		m_video_previewer->SetFrameRate(GetPreviewFrameRate());
		m_stacked_layout_preview->setCurrentWidget(m_preview_page2);
		m_pushbutton_preview_start_stop->setText(tr("Stop preview"));
	} else {
		m_stacked_layout_preview->setCurrentWidget(m_preview_page1);
		m_pushbutton_preview_start_stop->setText(tr("Start preview"));
	}
}

QString PageRecord::ReadStdinCommand() {
	for(int i = 0; i < m_stdin_buffer.size(); ++i) {
		if(m_stdin_buffer[i] == '\n') {
			QString command = QString::fromUtf8(m_stdin_buffer.data(), i);
			m_stdin_buffer = QByteArray(m_stdin_buffer.data() + i + 1, m_stdin_buffer.size() - i - 1);
			return command;
		}
	}
	return QString();
}

void PageRecord::OnUpdateHotkeyFields() {
	bool enabled = IsHotkeyEnabled();
	GroupEnabled({m_checkbox_hotkey_ctrl, m_checkbox_hotkey_shift, m_checkbox_hotkey_alt, m_checkbox_hotkey_super, m_combobox_hotkey_key}, enabled);
	OnUpdateHotkey();
}

void PageRecord::OnUpdateHotkey() {
	if(IsHotkeyEnabled()) {
		unsigned int modifiers = 0;
		if(IsHotkeyCtrlEnabled()) modifiers |= ControlMask;
		if(IsHotkeyShiftEnabled()) modifiers |= ShiftMask;
		if(IsHotkeyAltEnabled()) modifiers |= Mod1Mask;
		if(IsHotkeySuperEnabled()) modifiers |= Mod4Mask;
		m_hotkey_start_pause.Bind(XK_A + GetHotkeyKey(), modifiers);
	} else {
		m_hotkey_start_pause.Unbind();
	}
}

#if SSR_USE_ALSA
void PageRecord::OnUpdateSoundNotifications() {
	if(m_page_started && AreSoundNotificationsEnabled()) {
		if(m_simple_synth == NULL) {
			try {
				m_simple_synth.reset(new SimpleSynth("default", 48000));
			} catch(...) {
				Logger::LogError("[PageRecord::OnUpdateSoundNotifications] " + tr("Error: Something went wrong while creating the synth."));
			}
		}
	} else {
		m_simple_synth.reset();
	}
}
#endif

void PageRecord::OnUpdateRecordingFrame() {
	if(m_page_started && m_video_area == PageInput::VIDEO_AREA_FIXED && GetShowRecordingArea()) {
		if(m_recording_frame == NULL)
			m_recording_frame.reset(new RecordingFrameWindow(this, true));
		if(m_x11_input == NULL) {
			m_recording_frame->SetRectangle(QRect(m_video_x, m_video_y, m_video_in_width, m_video_in_height));
		} else {
			unsigned int x, y, width, height;
			m_x11_input->GetCurrentRectangle(&x, &y, &width, &height);
			m_recording_frame->SetRectangle(QRect(x, y, width, height));
		}
	} else {
		m_recording_frame.reset();
	}
}

void PageRecord::OnRecordStart() {
	if(m_main_window->IsBusy())
		return;
	if(!TryStartPage())
		return;
	if(m_wait_saving)
		return;
	if(!m_output_started)
		StartOutput();
}

void PageRecord::OnRecordPause() {
	if(m_main_window->IsBusy())
		return;
	if(!m_page_started)
		return;
	if(m_wait_saving)
		return;
	if(m_output_started)
		StopOutput(false);
}

void PageRecord::OnRecordStartPause() {
	if(m_page_started && m_output_started) {
		OnRecordPause();
	} else {
		OnRecordStart();
	}
}


void PageRecord::OnRecordCancel(bool confirm) {
	if(m_main_window->IsBusy())
		return;
	if(!m_page_started)
		return;
	if(m_wait_saving)
		return;
	if(m_output_manager != NULL && confirm) {
		if(MessageBox(QMessageBox::Warning, this, MainWindow::WINDOW_CAPTION, tr("Are you sure that you want to cancel this recording?"),
					  BUTTON_YES | BUTTON_NO, BUTTON_YES) != BUTTON_YES) {
			return;
		}
	}
	StopPage(false);
	m_main_window->GoPageOutput();
}

void PageRecord::OnRecordSave(bool confirm) {
	if(m_main_window->IsBusy())
		return;
	if(!m_page_started)
		return;
	if(m_wait_saving)
		return;
	if(!m_recorded_something && confirm) {
		MessageBox(QMessageBox::Information, this, MainWindow::WINDOW_CAPTION, tr("You haven't recorded anything, there is nothing to save."),
				   BUTTON_OK, BUTTON_OK);
		return;
	}
	StopPage(true);
	m_main_window->GoPageDone();
}

void PageRecord::OnScheduleTimer() {
	if(!m_page_started)
		return;
	if(m_schedule_active) {
		QDateTime now = QDateTime::currentDateTimeUtc();
		while(m_schedule_position < m_schedule_entries.size()) {
			ScheduleEntry &entry = m_schedule_entries[m_schedule_position];
			if(now < entry.time)
				break;
			Logger::LogInfo("[PageRecord::OnScheduleTimer] " + tr("Triggering scheduled action '%1' ...").arg(EnumToString(entry.action)));
			switch(entry.action) {
				case SCHEDULE_ACTION_START: OnRecordStart(); break;
				case SCHEDULE_ACTION_PAUSE: OnRecordPause(); break;
				default: break; // to keep GCC happy
			}
			++m_schedule_position;
		}
		if(m_schedule_position < m_schedule_entries.size()) {
			ScheduleEntry &entry = m_schedule_entries[m_schedule_position];
			int64_t msec = now.msecsTo(entry.time);
			m_label_schedule_status->setText(tr("Schedule: %1 in %2").arg(SCHEDULE_ACTION_TEXT[entry.action]).arg(ReadableTime(msec * 1000)));
			if(msec < 1000) {
				m_timer_schedule->start(msec);
			} else {
				m_timer_schedule->start((msec - 100) % 1000 + 100);
			}
		} else {
			m_label_schedule_status->setText(tr("Schedule: (none)"));
			m_timer_schedule->stop();
		}
	} else {
		m_label_schedule_status->setText(tr("Schedule: (inactive)"));
		m_timer_schedule->stop();
	}
}

void PageRecord::OnScheduleActivate() {
	if(m_main_window->IsBusy())
		return;
	if(!TryStartPage())
		return;
	if(!m_schedule_active) {
		m_schedule_active = true;
		UpdateSchedule();
	}
}

void PageRecord::OnScheduleDeactivate() {
	if(m_main_window->IsBusy())
		return;
	if(!m_page_started)
		return;
	if(m_schedule_active) {
		m_schedule_active = false;
		UpdateSchedule();
	}
}

void PageRecord::OnScheduleActivateDeactivate() {
	if(m_page_started && m_schedule_active) {
		OnScheduleDeactivate();
	} else {
		OnScheduleActivate();
	}
}

void PageRecord::OnScheduleEdit() {
	DialogRecordSchedule dialog(this);
	dialog.exec();
	UpdateSchedule();
}

void PageRecord::OnPreviewStartStop() {
	if(!m_page_started)
		return;
	if(m_wait_saving)
		return;
	m_previewing = !m_previewing;
	if(m_previewing) {
		m_video_previewer->Reset();
		m_audio_previewer->Reset();
	}
	UpdatePreview();
	UpdateInput();
	OnUpdateRecordingFrame();
}

void PageRecord::OnStdin() {

	// get available length
	int len, res;
	do {
		res = ioctl(0, FIONREAD, &len);
	} while(res == -1 && errno == EINTR);
	if(res == -1) {
		Logger::LogError("[PageRecord::OnStdin] " + tr("Standard input read error (%1).").arg("ioctl"));
		m_stdin_notifier->setEnabled(false);
		return;
	}
	if(len == 0) {
		Logger::LogInfo("[PageRecord::OnStdin] " + tr("Standard input closed (%1).").arg("ioctl"));
		m_stdin_notifier->setEnabled(false);
		return;
	}

	// read data
	QByteArray buffer(len, 0);
	ssize_t bytes;
	do {
		bytes = read(0, buffer.data(), buffer.size());
	} while(bytes == -1 && errno == EINTR);
	if(bytes == -1) {
		Logger::LogError("[PageRecord::OnStdin] " + tr("Standard input read error (%1).").arg("read"));
		m_stdin_notifier->setEnabled(false);
		return;
	}
	if(bytes == 0) {
		Logger::LogInfo("[PageRecord::OnStdin] " + tr("Standard input closed (%1).").arg("read"));
		m_stdin_notifier->setEnabled(false);
		return;
	}
	m_stdin_buffer.append(buffer.data(), bytes);

	// process commands
	if(!m_stdin_reentrant) {
		m_stdin_reentrant = true;
		for( ; ; ) {
			QString command = ReadStdinCommand();
			if(command.isNull())
				break;
			Logger::LogInfo("[PageRecord::OnStdin] " + tr("Received command '%1'.").arg(command));
			if(command == "record-start") {
				OnRecordStart();
			} else if(command == "record-pause") {
				OnRecordPause();
			} else if(command == "record-cancel") {
				OnRecordCancel(false);
			} else if(command == "record-save") {
				OnRecordSave(false);
			} else if(command == "schedule-activate") {
				OnScheduleActivate();
			} else if(command == "schedule-deactivate") {
				OnScheduleDeactivate();
			} else if(command == "window-show") {
				m_main_window->OnShow();
			} else if(command == "window-hide") {
				m_main_window->OnHide();
			} else if(command == "quit") {
				m_main_window->Quit();
			} else {
				Logger::LogError("[PageRecord::OnStdin] " + tr("Unknown command."));
			}
		}
		m_stdin_reentrant = false;
	}

}

void PageRecord::OnUpdateInformation() {

	if(m_page_started) {

		int64_t total_time = 0;
		double fps_in = 0.0;
		double fps_out = 0.0;
		uint64_t bit_rate = 0, total_bytes = 0;

		if(m_x11_input != NULL)
			fps_in = m_x11_input->GetFPS();
#if SSR_USE_OPENGL_RECORDING
		if(m_gl_inject_input != NULL)
			fps_in = m_gl_inject_input->GetFPS();
#endif
#if SSR_USE_V4L2
		if(m_v4l2_input != NULL)
			fps_in = m_v4l2_input->GetFPS();
#endif

		if(m_output_manager != NULL) {
			total_time = (m_output_manager->GetSynchronizer() == NULL)? 0 : m_output_manager->GetSynchronizer()->GetTotalTime();
			fps_out = m_output_manager->GetActualFrameRate();
			bit_rate = (uint64_t) (m_output_manager->GetActualBitRate() + 0.5);
			total_bytes = m_output_manager->GetTotalBytes();
		}

		QString file_name;
		if(m_file_protocol.isNull())
			file_name = (m_output_settings.file.isNull())? "?" : QFileInfo(m_output_settings.file).fileName();
		else
			file_name = "(" + m_file_protocol + ")";

		// for X11 recording, update the video size
		if(m_x11_input != NULL)
			m_x11_input->GetCurrentSize(&m_video_in_width, &m_video_in_height);

#if SSR_USE_OPENGL_RECORDING
		// for OpenGL recording, update the video size
		if(m_gl_inject_input != NULL)
			m_gl_inject_input->GetCurrentSize(&m_video_in_width, &m_video_in_height);
#endif

		m_label_info_total_time->setText(ReadableTime(total_time));
		m_label_info_frame_rate_in->setText(QString::number(fps_in, 'f', 2));
		m_label_info_frame_rate_out->setText(QString::number(fps_out, 'f', 2));
		m_label_info_size_in->setText(ReadableWidthHeight(m_video_in_width, m_video_in_height));
		m_label_info_size_out->setText(ReadableWidthHeight(m_output_settings.video_width, m_output_settings.video_height));
		m_label_info_file_name->setText(file_name);
		m_label_info_file_size->setText(ReadableSizeIEC(total_bytes, "B"));
		m_label_info_bit_rate->setText(ReadableSizeSI(bit_rate, "bit/s"));

		if(!CommandLineOptions::GetStatsFile().isNull()) {
			QString str = QString() +
					"capturing\t" + ((m_input_started)? "1" : "0") + "\n"
					"recording\t" + ((m_output_started)? "1" : "0") + "\n"
					"total_time\t" + QString::number(total_time) + "\n"
					"frame_rate_in\t" + QString::number(fps_in, 'f', 8) + "\n"
					"frame_rate_out\t" + QString::number(fps_out, 'f', 8) + "\n"
					"size_in_width\t" + QString::number(m_video_in_width) + "\n"
					"size_in_height\t" + QString::number(m_video_in_height) + "\n"
					"size_out_width\t" + QString::number(m_output_settings.video_width) + "\n"
					"size_out_height\t" + QString::number(m_output_settings.video_height) + "\n"
					"file_name\t" + file_name + "\n"
					"file_size\t" + QString::number(total_bytes) + "\n"
					"bit_rate\t" + QString::number(bit_rate) + "\n";
			QByteArray data = str.toUtf8();
			QByteArray old_file = QFile::encodeName(CommandLineOptions::GetStatsFile());
			QByteArray new_file = QFile::encodeName(CommandLineOptions::GetStatsFile() + "-new");
			// Qt doesn't get the permissions right (you can only change the permissions after creating the file, that's too late),
			// and it doesn't allow renaming a file over another file, so don't bother with QFile and just use POSIX and C functions.
			int fd = open(new_file.constData(), O_WRONLY | O_CREAT | O_CLOEXEC, 0600);
			if(fd != -1) {
				ssize_t b = write(fd, data.constData(), data.size()); Q_UNUSED(b);
				::close(fd);
				rename(new_file.constData(), old_file.constData());
			}
		}

	} else {

		m_label_info_total_time->clear();
		m_label_info_frame_rate_in->clear();
		m_label_info_frame_rate_out->clear();
		m_label_info_size_in->clear();
		m_label_info_size_out->clear();
		m_label_info_file_name->clear();
		m_label_info_file_size->clear();
		m_label_info_bit_rate->clear();

		if(!CommandLineOptions::GetStatsFile().isNull()) {
			QByteArray old_file = QFile::encodeName(CommandLineOptions::GetStatsFile());
			remove(old_file.constData());
		}

	}

}

void PageRecord::OnNewLogLine(Logger::enum_type type, QString string) {

#if SSR_USE_ALSA
	// play sound for errors
	//TODO// this is an ugly way to detect errors, this should be improved at some point
	int64_t time = hrt_time_micro();
	if(m_simple_synth != NULL && type == Logger::TYPE_ERROR && time > m_last_error_sound + 1000000) {
		m_simple_synth->PlaySequence(SEQUENCE_RECORD_ERROR.data(), SEQUENCE_RECORD_ERROR.size());
		m_last_error_sound = time;
	}
#endif

	// change system tray icon if an error has occurred
	if(m_page_started && type == Logger::TYPE_ERROR && !m_error_occurred) {
		m_error_occurred = true;
		UpdateSysTray();
	}

	// add line to log
	QTextCursor cursor = m_textedit_log->textCursor();
	QTextCharFormat format;
	bool should_scroll = (m_textedit_log->verticalScrollBar()->value() >= m_textedit_log->verticalScrollBar()->maximum());
	switch(type) {
		case Logger::TYPE_INFO:     format.setForeground(m_textedit_log->palette().windowText());  break;
		case Logger::TYPE_WARNING:  format.setForeground(Qt::darkYellow);                          break;
		case Logger::TYPE_ERROR:    format.setForeground(Qt::red);                                 break;
		case Logger::TYPE_STDERR:   format.setForeground(Qt::gray);                                break;
	}
	cursor.movePosition(QTextCursor::End);
	if(cursor.position() != 0)
		cursor.insertBlock();
	cursor.insertText(string, format);
	if(should_scroll)
		m_textedit_log->verticalScrollBar()->setValue(m_textedit_log->verticalScrollBar()->maximum());

}
