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

#include "ProfileBox.h"

#include "Dialogs.h"
#include "Logger.h"
#include "Main.h"
#include "MainWindow.h"
#include "SimpleJSON.h"

ProfileBox::ProfileBox(QWidget* parent, const QString& type, LoadCallback load_callback, SaveCallback save_callback, void *userdata)
	: QGroupBox(tr("Profile"), parent) {

	m_type = type;
	m_load_callback = load_callback;
	m_save_callback = save_callback;
	m_userdata = userdata;
	m_last_profile = 0;

	m_combobox_profiles = new QComboBox(this);
	m_combobox_profiles->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	m_pushbutton_save = new QPushButton(tr("Save"), this);
	m_pushbutton_save->setToolTip(tr("Save the current settings to this profile."));
	m_pushbutton_new = new QPushButton(tr("New"), this);
	m_pushbutton_new->setToolTip(tr("Create a new profile with the current settings."));
	m_pushbutton_delete = new QPushButton(tr("Delete"), this);
	m_pushbutton_delete->setToolTip(tr("Delete this profile."));

	connect(m_combobox_profiles, SIGNAL(activated(int)), this, SLOT(OnProfileChange()));
	connect(m_pushbutton_save, SIGNAL(clicked()), this, SLOT(OnProfileSave()));
	connect(m_pushbutton_new, SIGNAL(clicked()), this, SLOT(OnProfileNew()));
	connect(m_pushbutton_delete, SIGNAL(clicked()), this, SLOT(OnProfileDelete()));

	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(m_combobox_profiles);
	layout->addWidget(m_pushbutton_save);
	layout->addWidget(m_pushbutton_new);
	layout->addWidget(m_pushbutton_delete);

	LoadProfiles();
	UpdateProfileFields();

}

QString ProfileBox::GetProfileName() {
	unsigned int profile = m_combobox_profiles->currentIndex();
	if(profile == 0)
		return QString();
	return m_profiles[profile - 1].m_name;
}

void ProfileBox::SetProfile(const QString& name) {
	unsigned profile = 0;
	for(unsigned int i = 0; i < m_profiles.size(); ++i) {
		if(m_profiles[i].m_name == name) {
			profile = i + 1;
			break;
		}
	}
	m_combobox_profiles->setCurrentIndex(profile);
	m_last_profile = profile;
	UpdateProfileFields();
	return 0;
}

void ProfileBox::LoadProfiles() {

	// get all profiles
	std::vector<Profile> profiles;
	LoadProfilesFromDir(&profiles, GetApplicationSystemDir(m_type), false);
	LoadProfilesFromDir(&profiles, GetApplicationUserDir(m_type), true);

	// sort and remove duplicates
	std::sort(profiles.begin(), profiles.end());
	m_profiles.clear();
	for(const Profile& p : profiles) {
		if(!m_profiles.empty() && m_profiles.back().m_name == p.m_name) {
			if(p.m_can_delete)
				m_profiles.back().m_can_delete = true;
		} else {
			m_profiles.push_back(p);
		}
	}

	// add profiles to combobox
	m_combobox_profiles->clear();
	m_combobox_profiles->addItem(tr("(none)"));
	for(unsigned int i = 0; i < m_profiles.size(); ++i) {
		m_combobox_profiles->addItem(QByteArray::fromPercentEncoding(m_profiles[i].m_name.toUtf8()));
	}

}

void ProfileBox::LoadProfilesFromDir(std::vector<Profile>* profiles, const QString& path, bool can_delete) {
	QDir dir(path);
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
	dir.setNameFilters(QStringList("*.conf"));
	for(QFileInfo file : dir.entryInfoList()) {
		Profile profile;
		profile.m_name = file.completeBaseName();
		profile.m_can_delete = can_delete;
		profiles->push_back(profile);
	}
}

void ProfileBox::UpdateProfileFields() {
	unsigned int profile = m_combobox_profiles->currentIndex();
	m_pushbutton_save->setEnabled(profile != 0);
	m_pushbutton_new->setEnabled(true);
	m_pushbutton_delete->setEnabled(profile != 0 && m_profiles[profile - 1].m_can_delete);
}

void ProfileBox::OnProfileChange() {
	if(m_combobox_profiles->currentIndex() == m_last_profile)
		return;
	m_last_profile = m_combobox_profiles->currentIndex();
	UpdateProfileFields();
	QString name = GetProfileName();
	if(name.isEmpty())
		return;
	QString filename = GetApplicationUserDir(m_type) + "/" + name + ".json";
	if(!QFileInfo(filename).exists()) {
		filename = GetApplicationSystemDir(m_type) + "/" + name + ".json";
		if(!QFileInfo(filename).exists()) {
			Logger::LogError("[ProfileBox::OnProfileChange] " + tr("Error: Can't load profile!"));
			return;
		}
	}
	SimpleJSON json;
	json.ReadFromFile(filename.toStdString());
	m_load_callback(json, m_userdata);
}

void ProfileBox::OnProfileSave() {
	QString name = GetProfileName();
	if(name.isEmpty())
		return;
	QString filename = GetApplicationUserDir(m_type) + "/" + name + ".json";
	if(MessageBox(QMessageBox::Warning, this, MainWindow::WINDOW_CAPTION, tr("Are you sure that you want to overwrite this profile?"), BUTTON_YES | BUTTON_NO, BUTTON_YES) == BUTTON_YES) {
		SimpleJSON json;
		m_save_callback(json, m_userdata);
		json.WriteToFile(filename.toStdString());
		LoadProfiles();
		SetProfile(name);
	}
}

void ProfileBox::OnProfileNew() {
	QString name = InputBox(this, MainWindow::WINDOW_CAPTION, tr("Enter a name for the new profile:"), "");
	if(name.isEmpty())
		return;
	name = name.toUtf8().toPercentEncoding();
	QString filename = GetApplicationUserDir(m_type) + "/" + name + ".json";
	if(!QFileInfo(filename).exists() || MessageBox(QMessageBox::Warning, this, MainWindow::WINDOW_CAPTION,
			tr("A profile with the same name already exists. Are you sure that you want to replace it?"), BUTTON_YES | BUTTON_NO, BUTTON_YES) == BUTTON_YES) {
		SimpleJSON json;
		m_save_callback(json, m_userdata);
		json.WriteToFile(filename.toStdString());
		LoadProfiles();
		SetProfile(name);
	}
}

void ProfileBox::OnProfileDelete() {
	QString name = GetProfileName();
	if(name.isEmpty())
		return;
	QString filename = GetApplicationUserDir(m_type) + "/" + name + ".json";
	if(MessageBox(QMessageBox::Warning, this, MainWindow::WINDOW_CAPTION, tr("Are you sure that you want to delete this profile?"), BUTTON_YES | BUTTON_NO, BUTTON_YES) == BUTTON_YES) {
		QFile(filename).remove();
		LoadProfiles();
		UpdateProfileFields();
	}
}
