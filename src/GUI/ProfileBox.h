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

#pragma once
#include "Global.h"

class ProfileBox : public QGroupBox {
	Q_OBJECT

public:
	typedef void (*LoadCallback)(QSettings*, void*);
	typedef void (*SaveCallback)(QSettings*, void*);

private:
	struct Profile {
		QString m_name;
		bool m_can_delete;
		bool operator<(const Profile& other) const { return (m_name < other.m_name); }
	};

private:
	QString m_type;
	LoadCallback m_load_callback;
	SaveCallback m_save_callback;
	void *m_userdata;

	std::vector<Profile> m_profiles;

	QComboBox *m_combobox_profiles;
	QPushButton *m_pushbutton_save, *m_pushbutton_new, *m_pushbutton_delete;

public:
	ProfileBox(const QString& title, QWidget* parent, const QString& type, LoadCallback load_callback, SaveCallback save_callback, void* userdata);

	QString GetProfileName();
	unsigned int FindProfile(const QString& name);

private:
	void LoadProfiles();
	void LoadProfilesFromDir(std::vector<Profile>* profiles, const QString& path, bool can_delete);
	void UpdateProfileFields();

private slots:
	void OnProfileChange();
	void OnProfileSave();
	void OnProfileNew();
	void OnProfileDelete();

public:
	inline unsigned int GetProfile() { return clamp(m_combobox_profiles->currentIndex(), 0, (int) m_profiles.size()); }
	inline void SetProfile(unsigned int profile) { m_combobox_profiles->setCurrentIndex(clamp(profile, 0u, (unsigned int) m_profiles.size())); UpdateProfileFields(); }

};
