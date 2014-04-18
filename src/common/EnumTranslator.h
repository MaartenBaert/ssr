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

template<typename A, typename B>
class EnumTranslator {

private:
	static const EnumTranslator SINGLETON;

private:
	std::vector<std::pair<A, B> > m_to_second, m_to_first;

private:
	inline static bool CompareFirst(const std::pair<A, B>& a, const std::pair<A, B>& b) { return (a.first < b.first); }
	inline static bool CompareSecond(const std::pair<A, B>& a, const std::pair<A, B>& b) { return (a.second < b.second); }

public:
	EnumTranslator(std::initializer_list<std::pair<A, B> > list) {
		m_to_second = m_to_first = list;
		std::stable_sort(m_to_second.begin(), m_to_second.end(), CompareFirst);
		std::stable_sort(m_to_first.begin(), m_to_first.end(), CompareSecond);
	}
	inline static A ToFirst(const B& value, const A& fallback) {
		auto it = std::lower_bound(SINGLETON.m_to_first.begin(), SINGLETON.m_to_first.end(), std::make_pair(A(), value), CompareSecond);
		if(it == SINGLETON.m_to_first.end() || it->second != value)
			return fallback;
		return it->first;
	}
	inline static B ToSecond(const A& value, const B& fallback) {
		auto it = std::lower_bound(SINGLETON.m_to_second.begin(), SINGLETON.m_to_second.end(), std::make_pair(value, B()), CompareFirst);
		if(it == SINGLETON.m_to_second.end() || it->first != value)
			return fallback;
		return it->second;
	}

};

template<typename E>
inline QString EnumToString(E value) { return EnumTranslator<E, QString>::ToSecond(value, QString()); }
template<typename E>
inline E StringToEnum(const QString& string, E fallback) { return EnumTranslator<E, QString>::ToFirst(string, fallback); }

#define ENUMTRANSLATOR(A, B) template<> const EnumTranslator<A, B> EnumTranslator<A, B>::SINGLETON
#define ENUMSTRINGS(E) ENUMTRANSLATOR(E, QString)
