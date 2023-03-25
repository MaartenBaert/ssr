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

template<typename E>
class EnumStrings {

private:
	static const EnumStrings SINGLETON;

private:
	std::vector<std::pair<E, QString> > m_to_string, m_from_string;

private:
	inline static bool CompareFirst(const std::pair<E, QString>& a, const std::pair<E, QString>& b) { return (a.first < b.first); }
	inline static bool CompareSecond(const std::pair<E, QString>& a, const std::pair<E, QString>& b) { return (a.second < b.second); }

public:
	EnumStrings(std::initializer_list<std::pair<E, QString> > list) {
		m_to_string = m_from_string = list;
		std::sort(m_to_string.begin(), m_to_string.end(), CompareFirst);
		std::sort(m_from_string.begin(), m_from_string.end(), CompareSecond);
	}
	inline static QString ToString(E value) {
		auto it = std::lower_bound(SINGLETON.m_to_string.begin(), SINGLETON.m_to_string.end(), std::make_pair(value, QString()), CompareFirst);
		if(it == SINGLETON.m_to_string.end() || it->first != value) {
			assert(false);
			return QString();
		}
		return it->second;
	}
	inline static E FromString(const QString& string, E fallback) {
		auto it = std::lower_bound(SINGLETON.m_from_string.begin(), SINGLETON.m_from_string.end(), std::make_pair((E) 0, string), CompareSecond);
		if(it == SINGLETON.m_from_string.end() || it->second != string)
			return fallback;
		return it->first;
	}

};

template<typename E>
inline QString EnumToString(E value) { return EnumStrings<E>::ToString(value); }
template<typename E>
inline E StringToEnum(const QString& string, E fallback) { return EnumStrings<E>::FromString(string, fallback); }

#define ENUMSTRINGS(E) template<> const EnumStrings<E> EnumStrings<E>::SINGLETON
