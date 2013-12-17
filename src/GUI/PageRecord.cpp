/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

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

#include "Global.h"
#include "PageRecord.h"

#include "Main.h"
#include "Icons.h"
#include "MainWindow.h"
#include "PageInput.h"
#include "PageOutput.h"

#include "HotkeyListener.h"

#include "Muxer.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"
#include "Synchronizer.h"
#include "X11Input.h"
#include "GLInjectLauncher.h"
#include "GLInjectInput.h"
#include "ALSAInput.h"
#if SSR_USE_PULSEAUDIO
#include "PulseAudioInput.h"
#endif
#if SSR_USE_JACK
#include "JACKInput.h"
#endif
#include "SimpleSynth.h"
#include "VideoPreviewer.h"
#include "AudioPreviewer.h"

#include <X11/keysym.h>
#include <X11/keysymdef.h>

static QString GetNewSegmentFile(const QString& file, unsigned int* counter, bool check_existing) {
	QFileInfo fi(file);
	QString path = fi.path(), basename = fi.completeBaseName(), suffix = fi.suffix();
	QString newfile;
	do {
		++*counter;
		if(suffix.isEmpty())
			newfile = path + "/" + basename + QString("-%1").arg(*counter, 4, 10, QLatin1Char('0'));
		else
			newfile = path + "/" + basename + QString("-%1").arg(*counter, 4, 10, QLatin1Char('0')) + "." + suffix;
	} while(check_existing && QFileInfo(newfile).exists());
	return newfile;
}

static std::vector<std::pair<QString, QString> > GetOptionsFromString(const QString& str) {
	std::vector<std::pair<QString, QString> > options;
	QStringList optionlist = str.split(',', QString::SkipEmptyParts);
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

static QString ReadableSize(uint64_t size, const QString& suffix) {
	if(size < (uint64_t) 10 * 1024)
		return QString::number(size) + " " + suffix;
	if(size < (uint64_t) 10 * 1024 * 1024)
		return QString::number((size + 512) / 1024) + " k" + suffix;
	if(size < (uint64_t) 10 * 1024 * 1024 * 1024)
		return QString::number((size / 1024 + 512) / 1024) + " M" + suffix;
	return QString::number((size / 1024 / 1024 + 512) / 1024) + " G" + suffix;
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
static const std::array<SimpleSynth::Note, 1> SEQUENCE_RECORD_START = {{
	{0    , 500, 10000, 440.0f * exp2f( 3.0f / 12.0f), 0.5f}, // C5
}};
static const std::array<SimpleSynth::Note, 2> SEQUENCE_RECORD_STOP = {{
	{0    , 500, 20000, 440.0f * exp2f( 3.0f / 12.0f), 0.5f}, // C5
	{10000, 500, 20000, 440.0f * exp2f(-2.0f / 12.0f), 0.5f}, // G4
}};
static const std::array<SimpleSynth::Note, 4> SEQUENCE_RECORD_ERROR = {{
	{0    , 500, 20000, 440.0f * exp2f(-2.0f / 12.0f), 0.5f}, // G4
	{10000, 500, 20000, 440.0f * exp2f(-2.0f / 12.0f), 0.5f}, // G4
	{20000, 500, 20000, 440.0f * exp2f(-6.0f / 12.0f), 0.3f}, // D#4
	{20000, 500, 20000, 440.0f * exp2f(-9.0f / 12.0f), 0.5f}, // C4
}};

const int PageRecord::PRIORITY_RECORD = 0;
const int PageRecord::PRIORITY_PREVIEW = -1;

PageRecord::PageRecord(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_page_started = false;
	m_input_started = false;
	m_output_started = false;
	m_previewing = false;

	m_last_error_sound = std::numeric_limits<int64_t>::min();

	QGroupBox *group_recording = new QGroupBox(tr("Recording"), this);
	{
		m_pushbutton_start_pause = new QPushButton(group_recording);

		m_checkbox_hotkey_enable = new QCheckBox(tr("Enable recording hotkey"), group_recording);
		m_checkbox_sound_notifications_enable = new QCheckBox(tr("Enable sound notifications"), group_recording);
		QLabel *label_hotkey = new QLabel(tr("Hotkey:"), group_recording);
		m_checkbox_hotkey_ctrl = new QCheckBox(tr("Ctrl +"), group_recording);
		m_checkbox_hotkey_shift = new QCheckBox(tr("Shift +"), group_recording);
		m_checkbox_hotkey_alt = new QCheckBox(tr("Alt +"), group_recording);
		m_checkbox_hotkey_super = new QCheckBox(tr("Super +"), group_recording);
		m_combobox_hotkey_key = new QComboBox(group_recording);
		m_combobox_hotkey_key->setToolTip(tr("The key that you have to press (combined with the given modifiers) to start or pause recording.\n"
											 "The program that you are recording will not receive the key press."));
		// Note: The choice of keys is currently rather limited, because capturing key presses session-wide is a bit harder than it looks.
		// For example, applications are not allowed to capture the F1-F12 keys (on Ubuntu at least). The A-Z keys don't have this limitation apparently.
		for(unsigned int i = 0; i < 26; ++i) {
			m_combobox_hotkey_key->addItem(QString('A' + i));
		}

		connect(m_pushbutton_start_pause, SIGNAL(clicked()), this, SLOT(OnRecordStartPause()));
		connect(m_checkbox_hotkey_enable, SIGNAL(clicked()), this, SLOT(OnUpdateHotkeyFields()));
		connect(m_checkbox_sound_notifications_enable, SIGNAL(clicked()), this, SLOT(OnUpdateSoundNotifications()));
		connect(m_checkbox_hotkey_ctrl, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_checkbox_hotkey_shift, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_checkbox_hotkey_alt, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_checkbox_hotkey_super, SIGNAL(clicked()), this, SLOT(OnUpdateHotkey()));
		connect(m_combobox_hotkey_key, SIGNAL(activated(int)), this, SLOT(OnUpdateHotkey()));

		QVBoxLayout *layout = new QVBoxLayout(group_recording);
		layout->addWidget(m_pushbutton_start_pause);
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_checkbox_hotkey_enable);
			layout2->addWidget(m_checkbox_sound_notifications_enable);
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
			QGroupBox *group_information = new QGroupBox(tr("Information"), splitter_horizontal);
			{
				QLabel *label_total_time = new QLabel(tr("Total time:"), group_information);
				m_label_info_total_time = new QLabel(group_information);
				QLabel *label_frame_rate_in = new QLabel(tr("FPS in:"), group_information);
				m_label_info_frame_rate_in = new QLabel(group_information);
				QLabel *label_frame_rate_out = new QLabel(tr("FPS out:"), group_information);
				m_label_info_frame_rate_out = new QLabel(group_information);
				QLabel *label_size_in = new QLabel(tr("Size in:"), group_information);
				m_label_info_size_in = new QLabel(group_information);
				QLabel *label_size_out = new QLabel(tr("Size out:"), group_information);
				m_label_info_size_out = new QLabel(group_information);
				QLabel *label_file_name = new QLabel(tr("File name:"), group_information);
				m_label_info_file_name = new ElidedLabel(QString(), Qt::ElideMiddle, group_information);
				m_label_info_file_name->setMinimumWidth(100);
				QLabel *label_file_size = new QLabel(tr("File size:"), group_information);
				m_label_info_file_size = new QLabel(group_information);
				QLabel *label_bit_rate = new QLabel(tr("Bit rate:"), group_information);
				m_label_info_bit_rate = new QLabel(group_information);

				QGridLayout *layout = new QGridLayout(group_information);
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
				layout->setColumnStretch(1, 1);
				layout->setRowStretch(8, 1);
			}
			QGroupBox *group_preview = new QGroupBox(tr("Preview"), splitter_horizontal);
			{
				m_preview_page1 = new QWidget(group_preview);
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
				m_preview_page2 = new QWidget(group_preview);
				{
					m_video_previewer = new VideoPreviewer(m_preview_page2);
					m_label_mic_icon = new QLabel(m_preview_page2);
					m_label_mic_icon->setPixmap(QIcon::fromTheme("audio-input-microphone").pixmap(24, 24));
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
				m_pushbutton_preview_start_stop = new QPushButton(group_preview);

				connect(m_pushbutton_preview_start_stop, SIGNAL(clicked()), this, SLOT(OnPreviewStartStop()));

				QVBoxLayout *layout = new QVBoxLayout(group_preview);
				{
					m_stacked_layout_preview = new QStackedLayout();
					layout->addLayout(m_stacked_layout_preview);
					m_stacked_layout_preview->addWidget(m_preview_page1);
					m_stacked_layout_preview->addWidget(m_preview_page2);
				}
				layout->addWidget(m_pushbutton_preview_start_stop);
			}

			splitter_horizontal->addWidget(group_information);
			splitter_horizontal->addWidget(group_preview);
			splitter_horizontal->setStretchFactor(0, 1);
			splitter_horizontal->setStretchFactor(1, 3);
		}
		QGroupBox *group_log = new QGroupBox(tr("Log"), splitter_vertical);
		{
			m_textedit_log = new QTextEditSmall(group_log);
			m_textedit_log->setReadOnly(true);

			QVBoxLayout *layout = new QVBoxLayout(group_log);
			layout->addWidget(m_textedit_log);
		}

		splitter_vertical->addWidget(splitter_horizontal);
		splitter_vertical->addWidget(group_log);
		splitter_vertical->setStretchFactor(0, 3);
		splitter_vertical->setStretchFactor(1, 1);
	}

	QPushButton *button_cancel = new QPushButton(QIcon::fromTheme("process-stop"), tr("Cancel recording"), this);
	QPushButton *button_save = new QPushButton(QIcon::fromTheme("document-save"), tr("Save recording"), this);

	if(g_option_systray) {
		m_systray_icon = new QSystemTrayIcon(m_main_window);
		QMenu *menu = new QMenu(m_main_window);
		m_systray_action_start_pause = menu->addAction(QString(), this, SLOT(OnRecordStartPause()));
		m_systray_action_save = menu->addAction(tr("Save recording"), this, SLOT(OnSave()));
		m_systray_action_cancel = menu->addAction(tr("Cancel recording"), this, SLOT(OnCancel()));
		menu->addSeparator();
		menu->addAction("Quit", m_main_window, SLOT(close()));
		m_systray_icon->setContextMenu(menu);
	} else {
		m_systray_icon = NULL;
	}

	connect(button_cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));
	connect(button_save, SIGNAL(clicked()), this, SLOT(OnSave()));
	if(m_systray_icon != NULL)
		connect(m_systray_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(OnSysTrayActivated(QSystemTrayIcon::ActivationReason)));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(group_recording);
	layout->addWidget(splitter_vertical);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_cancel);
		layout2->addWidget(button_save);
	}

	UpdateSysTray();
	UpdateRecordPauseButton();
	UpdatePreview();

	m_info_timer = new QTimer(this);
	m_glinject_event_timer = new QTimer(this);
	connect(m_info_timer, SIGNAL(timeout()), this, SLOT(OnUpdateInformation()));
	connect(m_glinject_event_timer, SIGNAL(timeout()), this, SLOT(OnCheckGLInjectEvents()));
	connect(&g_hotkey_listener, SIGNAL(Triggered()), this, SLOT(OnRecordStartPause()));
	connect(Logger::GetInstance(), SIGNAL(NewLine(Logger::enum_type,QString)), this, SLOT(OnNewLogLine(Logger::enum_type,QString)), Qt::QueuedConnection);

	if(m_systray_icon != NULL)
		m_systray_icon->show();

}

PageRecord::~PageRecord() {
	StopPage(false);
}

bool PageRecord::ShouldBlockClose() {

	if(m_output_manager != NULL) {
		if(QMessageBox::warning(this, MainWindow::WINDOW_CAPTION,
								tr("You have not saved the current recording yet, if you quit now it will be lost.\n"
								   "Are you sure that you want to quit?"), QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
			return true;
		}
	}

	return false;

}

void PageRecord::LoadSettings(QSettings *settings) {
	SetHotkeyEnabled(settings->value("record/hotkey_enable", true).toBool());
	SetHotkeyCtrlEnabled(settings->value("record/hotkey_ctrl", true).toBool());
	SetHotkeyShiftEnabled(settings->value("record/hotkey_shift", false).toBool());
	SetHotkeyAltEnabled(settings->value("record/hotkey_alt", false).toBool());
	SetHotkeySuperEnabled(settings->value("record/hotkey_super", false).toBool());
	SetHotkeyKey(settings->value("record/hotkey_key", 'r' - 'a').toUInt());
	SetSoundNotificationsEnabled(settings->value("record/sound_notifications_enable", true).toBool());
	SetPreviewFrameRate(settings->value("record/preview_frame_rate", 10).toUInt());
	OnUpdateHotkeyFields();
	OnUpdateSoundNotifications();
}

void PageRecord::SaveSettings(QSettings *settings) {
	settings->setValue("record/hotkey_enable", IsHotkeyEnabled());
	settings->setValue("record/hotkey_ctrl", IsHotkeyCtrlEnabled());
	settings->setValue("record/hotkey_shift", IsHotkeyShiftEnabled());
	settings->setValue("record/hotkey_alt", IsHotkeyAltEnabled());
	settings->setValue("record/hotkey_super", IsHotkeySuperEnabled());
	settings->setValue("record/hotkey_key", GetHotkeyKey());
	settings->setValue("record/sound_notifications_enable", AreSoundNotificationsEnabled());
	settings->setValue("record/preview_frame_rate", GetPreviewFrameRate());
}

void PageRecord::StartPage() {

	if(m_page_started)
		return;

	Q_ASSERT(!m_input_started);
	Q_ASSERT(!m_output_started);

	// save the settings in case libav/ffmpeg decides to kill the process
	m_main_window->SaveSettings();

	// clear the log
	m_textedit_log->clear();

	// clear the preview
	m_video_previewer->Reset();
	m_audio_previewer->Reset();

	PageInput *page_input = m_main_window->GetPageInput();
	PageOutput *page_output = m_main_window->GetPageOutput();

	// get the video input settings
	m_video_area = page_input->GetVideoArea();
	m_video_x = page_input->GetVideoX();
	m_video_y = page_input->GetVideoY();
	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
		m_video_in_width = 0;
		m_video_in_height = 0;
	} else {
		m_video_in_width = page_input->GetVideoW();
		m_video_in_height = page_input->GetVideoH();
	}
	m_video_frame_rate = page_input->GetVideoFrameRate();
	m_video_scaling = page_input->GetVideoScalingEnabled();
	m_video_scaled_width = page_input->GetVideoScaledW();
	m_video_scaled_height = page_input->GetVideoScaledH();
	m_video_record_cursor = page_input->GetVideoRecordCursor();

	// get the audio input settings
	m_audio_enabled = page_input->GetAudioEnabled();
	m_audio_sample_rate = 44100;
	m_audio_backend = page_input->GetAudioBackend();
	m_alsa_device = page_input->GetALSADevice();
#if SSR_USE_PULSEAUDIO
	m_pulseaudio_source = page_input->GetPulseAudioSourceName();
#endif

	// get the glinject settings
	QString glinject_command = page_input->GetGLInjectCommand();
	QString glinject_working_directory = page_input->GetGLInjectWorkingDirectory();
	bool glinject_run_command = page_input->GetGLInjectRunCommand();
	bool glinject_relax_permissions = page_input->GetGLInjectRelaxPermissions();
	unsigned int glinject_megapixels = page_input->GetGLInjectMaxMegaPixels();
	bool glinject_capture_front = page_input->GetGLInjectCaptureFront();
	bool glinject_limit_fps = page_input->GetGLInjectLimitFPS();

	// get file settings
	m_file_base = page_output->GetFile();
	m_file_protocol = page_output->GetFileProtocol();
	m_separate_files = page_output->GetSeparateFiles();
	m_file_segment_counter = 0;

	// get the output settings
	if(m_separate_files)
		m_output_settings.file = GetNewSegmentFile(m_file_base, &m_file_segment_counter, m_file_protocol.isNull());
	else
		m_output_settings.file = m_file_base;
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
	m_output_settings.audio_sample_rate = m_audio_sample_rate;

	// some codec-specific things
	// you can get more information about all these options by running 'ffmpeg -h' or 'avconv -h' from a terminal
	switch(page_output->GetVideoCodec()) {
		case PageOutput::VIDEO_CODEC_H264: {
			// x264 has a 'constant quality' mode, where the bit rate is simply set to whatever is needed to keep a certain quality. The quality is set
			// with the 'crf' option. 'preset' changes the encoding speed (and hence the efficiency of the compression) but doesn't really influence the quality,
			// which is great because it means you don't have to experiment with different bit rates and different speeds to get good results.
			m_output_settings.video_options.push_back(std::make_pair(QString("crf"), QString::number(page_output->GetH264CRF())));
			m_output_settings.video_options.push_back(std::make_pair(QString("preset"), page_output->GetH264PresetName()));
			break;
		}
		case PageOutput::VIDEO_CODEC_VP8: {
			// The names of there parameters are very unintuitive. The two options we care about (because they change the speed) are 'deadline' and 'cpu-used'.
			// 'deadline'='best' is unusably slow. 'deadline'='good' is the normal setting, it tells the encoder to use the speed set with 'cpu-used'. Higher
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

	// hide the audio previewer if there is no audio
	GroupVisible({m_label_mic_icon, m_audio_previewer}, m_audio_enabled);

	Logger::LogInfo("[PageRecord::StartPage] " + tr("Starting page ..."));


	try {

		// for OpenGL recording, allocate shared memory and start the program now
		if(m_video_area == PageInput::VIDEO_AREA_GLINJECT)
			m_gl_inject_launcher.reset(new GLInjectLauncher(glinject_command, glinject_working_directory, glinject_run_command, glinject_relax_permissions, glinject_megapixels * 4 * 1024 * 1024,
															m_video_frame_rate, m_video_record_cursor, glinject_capture_front, glinject_limit_fps));

		if(m_audio_enabled) {
#if SSR_USE_JACK
			// for JACK, start the input now
			if(m_audio_backend == PageInput::AUDIO_BACKEND_JACK)
				m_jack_input.reset(new JACKInput());
#endif
		}

	} catch(...) {
		Logger::LogError("[PageRecord::StartPage] " + tr("Error: Something went wrong during initialization."));
		m_gl_inject_launcher.reset();
#if SSR_USE_JACK
		m_jack_input.reset();
#endif
	}

	Logger::LogInfo("[PageRecord::StartPage] " + tr("Started page."));

	m_page_started = true;
	m_recorded_something = false;
	UpdateSysTray();
	OnUpdateHotkey();
	OnUpdateSoundNotifications();

	UpdateInput();

	m_info_last_timestamp = hrt_time_micro();
	m_info_last_frame_counter = 0;
	m_info_input_frame_rate = 0.0;
	OnUpdateInformation();
	m_info_timer->start(1000);

	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT)
		m_glinject_event_timer->start(100);

}

void PageRecord::StopPage(bool save) {

	if(!m_page_started)
		return;

	StopOutput(true);
	StopInput();

	Logger::LogInfo("[PageRecord::StopPage] " + tr("Stopping page ..."));

	if(m_output_manager != NULL) {

		// stop the output
		if(save)
			m_output_manager->Finish();
		m_output_manager.reset();

		// delete the file if it isn't needed
		if(!save && m_file_protocol.isNull()) {
			if(QFileInfo(m_output_settings.file).exists())
				QFile(m_output_settings.file).remove();
		}

	}

	// free the shared memory for OpenGL recording
	// This doesn't stop the program, and the memory is only actually freed when the recorded program stops too.
	m_gl_inject_launcher.reset();

	// stop JACK input
#if SSR_USE_JACK
	m_jack_input.reset();
#endif

	Logger::LogInfo("[PageRecord::StopPage] " + tr("Stopped page."));

	m_page_started = false;
	UpdateSysTray();
	OnUpdateHotkey();
	OnUpdateSoundNotifications();

	m_info_timer->stop();
	OnUpdateInformation();

	m_glinject_event_timer->stop();

}

void PageRecord::StartOutput() {
	Q_ASSERT(m_page_started);

	if(m_output_started)
		return;

	if(m_simple_synth != NULL)
		m_simple_synth->PlaySequence(SEQUENCE_RECORD_START.data(), SEQUENCE_RECORD_START.size());

	try {

		Logger::LogInfo("[PageRecord::StartOutput] " + tr("Starting output ..."));

		if(m_output_manager == NULL) {

			// for OpenGL recording, detect the application size
			if(m_video_area == PageInput::VIDEO_AREA_GLINJECT && !m_video_scaling) {
				if(m_gl_inject_launcher == NULL) {
					Logger::LogError("[PageRecord::StartOutput] " + tr("Error: Could not get the size of the OpenGL application because GLInject has not been started."));
					throw GLInjectException();
				}
				m_gl_inject_launcher->GetCurrentSize(&m_video_in_width, &m_video_in_height);
				if(m_video_in_width == 0 && m_video_in_height == 0) {
					Logger::LogError("[PageRecord::StartOutput] " + tr("Error: Could not get the size of the OpenGL application. Either the "
									 "application wasn't started correctly, or the application hasn't created an OpenGL window yet. If "
									 "you want to start recording before starting the application, you have to enable scaling and enter "
									 "the video size manually."));
					throw GLInjectException();
				}
			}

			// calculate the output width and height
			if(m_video_scaling) {
				// Only even width and height is allowed because the final images are encoded as YUV.
				m_output_settings.video_width = m_video_scaled_width / 2 * 2;
				m_output_settings.video_height = m_video_scaled_height / 2 * 2;
			} else if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
				// The input size is the size of the OpenGL application and can't be changed. The output size is set to the current size of the application.
				m_output_settings.video_width = m_video_in_width / 2 * 2;
				m_output_settings.video_height = m_video_in_height / 2 * 2;
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
		UpdateRecordPauseButton();
		UpdateInput();

	} catch(...) {
		Logger::LogError("[PageRecord::StartOutput] " + tr("Error: Something went wrong during initialization."));
	}

}

void PageRecord::StopOutput(bool final) {
	Q_ASSERT(m_page_started);

	if(!m_output_started)
		return;

	Logger::LogInfo("[PageRecord::StopOutput] " + tr("Stopping output ..."));

	// if final, then StopPage will stop the output (and delete the file if needed)
	if(m_separate_files && !final) {

		// stop the output
		m_output_manager->Finish();
		m_output_manager.reset();

		// change the file name
		m_output_settings.file = GetNewSegmentFile(m_file_base, &m_file_segment_counter, m_file_protocol.isNull());

		// reset the output video size
		m_output_settings.video_width = 0;
		m_output_settings.video_height = 0;

	}

	Logger::LogInfo("[PageRecord::StopOutput] " + tr("Stopped output."));

	if(m_simple_synth != NULL)
		m_simple_synth->PlaySequence(SEQUENCE_RECORD_STOP.data(), SEQUENCE_RECORD_STOP.size());

	m_output_started = false;
	UpdateRecordPauseButton();
	UpdateInput();

}

void PageRecord::StartInput() {
	Q_ASSERT(m_page_started);

	if(m_input_started)
		return;

	Q_ASSERT(m_x11_input == NULL);
	Q_ASSERT(m_gl_inject_input == NULL);
	Q_ASSERT(m_alsa_input == NULL);
#if SSR_USE_PULSEAUDIO
	Q_ASSERT(m_pulseaudio_input == NULL);
#endif
/*#if SSR_USE_JACK
	Q_ASSERT(m_jack_input == NULL);
#endif*/

	try {

		Logger::LogInfo("[PageRecord::StartInput] " + tr("Starting input ..."));

		// start the video input
		if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
			if(m_gl_inject_launcher == NULL) {
				Logger::LogError("[PageRecord::StartInput] " + tr("Error: Could not create a GLInject input because GLInject has not been started."));
				throw GLInjectException();
			}
			m_gl_inject_input.reset(new GLInjectInput(m_gl_inject_launcher.get()));
		} else {
			m_x11_input.reset(new X11Input(m_video_x, m_video_y, m_video_in_width, m_video_in_height, m_video_record_cursor, m_video_area == PageInput::VIDEO_AREA_CURSOR));
		}

		// start the audio input
		if(m_audio_enabled) {
			if(m_audio_backend == PageInput::AUDIO_BACKEND_ALSA)
				m_alsa_input.reset(new ALSAInput(m_alsa_device, m_audio_sample_rate));
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
		m_gl_inject_input.reset();
		m_alsa_input.reset();
#if SSR_USE_PULSEAUDIO
		m_pulseaudio_input.reset();
#endif
#if SSR_USE_JACK
		m_jack_input.reset();
#endif
		return;
	}

}

void PageRecord::StopInput() {
	Q_ASSERT(m_page_started);

	if(!m_input_started)
		return;

	Logger::LogInfo("[PageRecord::StopInput] " + tr("Stopping input ..."));

	if(m_video_area != PageInput::VIDEO_AREA_GLINJECT) {
		m_info_last_frame_counter -= m_x11_input->GetFrameCounter();
	}

	m_x11_input.reset();
	m_gl_inject_input.reset();
	m_alsa_input.reset();
#if SSR_USE_PULSEAUDIO
	m_pulseaudio_input.reset();
#endif
	// JACK shouldn't stop until the page stops

	Logger::LogInfo("[PageRecord::StopInput] " + tr("Stopped input."));

	m_input_started = false;

}

void PageRecord::UpdateInput() {
	Q_ASSERT(m_page_started);

	if(m_output_started || m_previewing) {
		StartInput();
	} else {
		StopInput();
	}

	// get sources
	VideoSource *video_source = NULL;
	AudioSource *audio_source = NULL;
	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
		video_source = m_gl_inject_input.get();
	} else {
		video_source = m_x11_input.get();
	}
	if(m_audio_enabled) {
		if(m_audio_backend == PageInput::AUDIO_BACKEND_ALSA)
			audio_source = m_alsa_input.get();
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
	if(m_systray_icon != NULL)
		GroupEnabled({m_systray_action_start_pause, m_systray_action_save, m_systray_action_cancel}, m_page_started);
}

void PageRecord::UpdateRecordPauseButton() {
	if(m_output_started) {
		m_pushbutton_start_pause->setText(tr("Pause recording"));
		m_pushbutton_start_pause->setIcon(QIcon::fromTheme("media-playback-pause"));
		if(m_systray_icon != NULL) {
			m_systray_icon->setIcon(g_icon_ssr_recording);
			m_systray_action_start_pause->setText(tr("Pause recording"));
		}
	} else {
		m_pushbutton_start_pause->setText(tr("Start recording"));
		m_pushbutton_start_pause->setIcon(QIcon::fromTheme("media-record"));
		if(m_systray_icon != NULL) {
			m_systray_icon->setIcon(g_icon_ssr);
			m_systray_action_start_pause->setText(tr("Start recording"));
		}
	}
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

void PageRecord::OnUpdateHotkeyFields() {
	bool enabled = IsHotkeyEnabled();
	GroupEnabled({m_checkbox_hotkey_ctrl, m_checkbox_hotkey_shift, m_checkbox_hotkey_alt, m_checkbox_hotkey_super, m_combobox_hotkey_key}, enabled);
	OnUpdateHotkey();
}

void PageRecord::OnUpdateHotkey() {
	if(m_page_started && IsHotkeyEnabled()) {

		unsigned int modifiers = 0;
		if(IsHotkeyCtrlEnabled()) modifiers |= ControlMask;
		if(IsHotkeyShiftEnabled()) modifiers |= ShiftMask;
		if(IsHotkeyAltEnabled()) modifiers |= Mod1Mask;
		if(IsHotkeySuperEnabled()) modifiers |= Mod4Mask;
		g_hotkey_listener.EnableHotkey(XK_A + GetHotkeyKey(), modifiers);

		if(m_gl_inject_launcher != NULL)
			m_gl_inject_launcher->UpdateHotkey(IsHotkeyEnabled(), XK_A + GetHotkeyKey(), modifiers);

	} else {
		g_hotkey_listener.DisableHotkey();
	}
}

void PageRecord::OnUpdateSoundNotifications() {
	if(m_page_started && AreSoundNotificationsEnabled()) {
		if(m_simple_synth == NULL) {
			try {
				m_simple_synth.reset(new SimpleSynth("default", 44100));
			} catch(...) {
				Logger::LogError("[PageRecord::OnUpdateSoundNotifications] " + tr("Error: Something went wrong while creating the synth."));
			}
		}
	} else {
		m_simple_synth.reset();
	}
}

void PageRecord::OnRecordStartPause() {
	if(!m_page_started)
		return;
	if(m_output_started) {
		StopOutput(false);
	} else {
		StartOutput();
	}
}

void PageRecord::OnPreviewStartStop() {
	if(!m_page_started)
		return;
	m_video_previewer->Reset();
	m_audio_previewer->Reset();
	m_previewing = !m_previewing;
	UpdatePreview();
	UpdateInput();
}

void PageRecord::OnCancel() {
	if(!m_page_started)
		return;
	if(m_output_manager != NULL) {
		if(QMessageBox::warning(this, MainWindow::WINDOW_CAPTION, tr("Are you sure that you want to cancel this recording?"),
								QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
			return;
		}
	}
	StopPage(false);
	m_main_window->GoPageOutput();
}

void PageRecord::OnSave() {
	if(!m_page_started)
		return;
	if(!m_recorded_something) {
		QMessageBox::information(this, MainWindow::WINDOW_CAPTION, tr("You haven't recorded anything, there is nothing to save.\n\nThe start button is at the top ;)."),
								 QMessageBox::Ok);
		return;
	}
	StopPage(true);
	m_main_window->GoPageDone();
}

void PageRecord::OnSysTrayActivated(QSystemTrayIcon::ActivationReason reason) {
	if(reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick) {
		if(m_main_window->isVisible())
			m_main_window->hide();
		else
			m_main_window->show();
	}
}

void PageRecord::OnUpdateInformation() {

	if(m_page_started) {

		int64_t timestamp = hrt_time_micro();
		if(timestamp - m_info_last_timestamp > 10000) {
			uint32_t frame_counter;
			if(m_gl_inject_launcher != NULL) {
				frame_counter = m_gl_inject_launcher->GetFrameCounter();
			} else if(m_input_started) {
				Q_ASSERT(m_x11_input != NULL);
				frame_counter = m_x11_input->GetFrameCounter();
			} else {
				frame_counter = 0;
			}
			m_info_input_frame_rate = (double) (frame_counter - m_info_last_frame_counter) / ((double) (timestamp - m_info_last_timestamp) * 1.0e-6);
			m_info_last_timestamp = timestamp;
			m_info_last_frame_counter = frame_counter;
		}

		int64_t total_time = 0;
		double frame_rate = 0.0;
		uint64_t bit_rate = 0, total_bytes = 0;

		if(m_output_manager != NULL) {
			total_time = m_output_manager->GetSynchronizer()->GetTotalTime();
			frame_rate = m_output_manager->GetVideoEncoder()->GetActualFrameRate();
			bit_rate = (uint64_t) (m_output_manager->GetMuxer()->GetActualBitRate() + 0.5);
			total_bytes = m_output_manager->GetMuxer()->GetTotalBytes();
		}

		QString file_name = (m_file_protocol.isNull())? QFileInfo(m_output_settings.file).fileName() : "(" + m_file_protocol + ")";

		// for OpenGL recording, update the application size
		if(m_gl_inject_launcher != NULL) {
			m_gl_inject_launcher->GetCurrentSize(&m_video_in_width, &m_video_in_height);
		}

		m_label_info_total_time->setText(ReadableTime(total_time));
		m_label_info_frame_rate_in->setText(QString::number(m_info_input_frame_rate, 'f', 2));
		m_label_info_frame_rate_out->setText(QString::number(frame_rate, 'f', 2));
		m_label_info_size_in->setText(ReadableWidthHeight(m_video_in_width, m_video_in_height));
		m_label_info_size_out->setText(ReadableWidthHeight(m_output_settings.video_width, m_output_settings.video_height));
		m_label_info_file_name->setText(file_name);
		m_label_info_file_size->setText(ReadableSize(total_bytes, "B"));
		m_label_info_bit_rate->setText(ReadableSize(bit_rate, "bps"));

		if(!g_option_statsfile.isNull()) {
			QString str = QString() +
					"capturing\t" + ((m_input_started)? "1" : "0") + "\n"
					"recording\t" + ((m_output_started)? "1" : "0") + "\n"
					"total_time\t" + QString::number(total_time) + "\n"
					"frame_rate_in\t" + QString::number(m_info_input_frame_rate, 'f', 8) + "\n"
					"frame_rate_out\t" + QString::number(frame_rate, 'f', 8) + "\n"
					"size_in_width\t" + QString::number(m_video_in_width) + "\n"
					"size_in_height\t" + QString::number(m_video_in_height) + "\n"
					"size_out_width\t" + QString::number(m_output_settings.video_width) + "\n"
					"size_out_height\t" + QString::number(m_output_settings.video_height) + "\n"
					"file_name\t" + file_name + "\n"
					"file_size\t" + QString::number(total_bytes) + "\n"
					"bit_rate\t" + QString::number(bit_rate) + "\n";
			QByteArray data = str.toLocal8Bit();
			QByteArray old_file = g_option_statsfile.toLocal8Bit();
			QByteArray new_file = (g_option_statsfile + "-new").toLocal8Bit();
			// Qt doesn't get the permissions right (you can only change the permissions after creating the file, that's too late),
			// and it doesn't allow renaming a file over another file, so don't bother with QFile and just use POSIX and C functions.
			int fd = open(new_file.constData(), O_WRONLY | O_CREAT, 0600);
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

		if(!g_option_statsfile.isNull()) {
			QByteArray old_file = g_option_statsfile.toLocal8Bit();
			remove(old_file.constData());
		}

	}

}

void PageRecord::OnNewLogLine(Logger::enum_type type, QString str) {

	// play sound for errors
	int64_t time = hrt_time_micro();
	if(m_simple_synth != NULL && type == Logger::TYPE_ERROR && time > m_last_error_sound + 1000000) {
		m_simple_synth->PlaySequence(SEQUENCE_RECORD_ERROR.data(), SEQUENCE_RECORD_ERROR.size());
		m_last_error_sound = time;
	}

	// add line to log
	QTextCursor cursor = m_textedit_log->textCursor();
	QTextCharFormat format;
	bool should_scroll = (m_textedit_log->verticalScrollBar()->value() >= m_textedit_log->verticalScrollBar()->maximum());
	switch(type) {
		case Logger::TYPE_INFO:     format.setForeground(Qt::black);       break;
		case Logger::TYPE_WARNING:  format.setForeground(Qt::darkYellow);  break;
		case Logger::TYPE_ERROR:    format.setForeground(Qt::red);         break;
	}
	cursor.movePosition(QTextCursor::End);
	if(cursor.position() != 0)
		cursor.insertBlock();
	cursor.insertText(str, format);
	if(should_scroll)
		m_textedit_log->verticalScrollBar()->setValue(m_textedit_log->verticalScrollBar()->maximum());

}

void PageRecord::OnCheckGLInjectEvents() {
	if(m_gl_inject_launcher == NULL)
		return;
	if(m_gl_inject_launcher->GetHotkeyPressed()) {
		OnRecordStartPause();
	}
}
