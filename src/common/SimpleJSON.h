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

#include "EnumTranslator.h"

#include <cstddef>
#include <cstdio>
#include <stdint.h>

#include <exception>
#include <limits>
#include <map>
#include <memory>
#include <streambuf>
#include <string>
#include <vector>

class JSONException : public std::exception {};
class JSONParseException : public JSONException {
	inline virtual const char* what() const throw() override {
		return "JSONParseException";
	}
};
class JSONTypeException : public JSONException {
	inline virtual const char* what() const throw() override {
		return "JSONTypeException";
	}
};
class JSONIOException : public JSONException {
	inline virtual const char* what() const throw() override {
		return "JSONIOException";
	}
};

enum enum_jsontype {
	JSONTYPE_OBJECT,
	JSONTYPE_ARRAY,
	JSONTYPE_STRING,
	JSONTYPE_NUMBER,
	JSONTYPE_BOOL,
	JSONTYPE_NULL,
};

class SimpleJSON {

private:
	static const SimpleJSON NULL_VALUE;

private:
	enum_jsontype m_type;
	std::map<std::string, SimpleJSON> m_members; // for type object
	std::vector<std::map<std::string, SimpleJSON>::iterator> m_members_order;// for type object
	std::vector<std::unique_ptr<SimpleJSON> > m_elements; // for type array
	std::string m_string; // for type string and number
	bool m_bool; // for type bool

public:
	// default and copy constructors
	inline SimpleJSON() { m_type = JSONTYPE_NULL; }
	inline SimpleJSON(const SimpleJSON&) = default;
	inline SimpleJSON(SimpleJSON&&) = default;

	// copy assignments
	inline SimpleJSON& operator=(const SimpleJSON&) = default;
	inline SimpleJSON& operator=(SimpleJSON&&) = default;

	// general
	void Reset();
	inline enum_jsontype GetType() const { return m_type; }
	inline bool IsNull() const { return (m_type == JSONTYPE_NULL); }

	// for type object
	void ResetObject();
	size_t GetMemberCount() const;
	void GetMemberKey(size_t index, std::string& key) const;
	const SimpleJSON& GetMemberValue(size_t index) const;
	const SimpleJSON& operator[](const std::string& key) const;
	SimpleJSON& operator()(const std::string& key);

	// for type array
	void ResetArray();
	void ResizeArray(size_t size);
	size_t GetElementCount() const;
	SimpleJSON& AddElement();
	const SimpleJSON& operator[](size_t index) const;
	SimpleJSON& operator()(size_t index);

	// for type string
	inline void GetString(std::string& value) const {
		if(m_type == JSONTYPE_NULL)
			return;
		if(m_type != JSONTYPE_STRING)
			throw JSONTypeException();
		value = m_string;
	}
	inline void SetString(const std::string& value) {
		MakeType(JSONTYPE_STRING);
		m_string = value;
	}
	template<typename E> inline void GetEnum(E& value) const {
		if(m_type == JSONTYPE_NULL)
			return;
		if(m_type != JSONTYPE_STRING)
			throw JSONTypeException();
		if(!EnumTranslator<E, std::string>::ToFirst(value, m_string))
			throw JSONParseException();
	}
	template<typename E> inline void SetEnum(E value) {
		MakeType(JSONTYPE_STRING);
		if(!EnumTranslator<E, std::string>::ToSecond(value, m_string))
			throw JSONTypeException();
	}

	// for type number
	template<typename T> inline void GetNumber(T& value) const {
		static_assert(std::numeric_limits<T>::is_specialized, "Type is not numeric!");
		if(m_type == JSONTYPE_NULL)
			return;
		if(m_type != JSONTYPE_NUMBER)
			throw JSONTypeException();
		std::istringstream ss(m_string);
		ss >> value;
		if(ss.fail())
			throw JSONParseException();
	}
	template<typename T> inline void SetNumber(T value) {
		static_assert(std::numeric_limits<T>::is_specialized, "Type is not numeric!");
		static_assert(std::numeric_limits<T>::is_integer, "Type is not an integer!");
		MakeType(JSONTYPE_NUMBER);
		std::ostringstream ss;
		ss << value;
		m_string = ss.str();
	}
	template<> inline void SetNumber<float>(float value) {
		if(std::isfinite(value)) {
			MakeType(JSONTYPE_NUMBER);
			std::ostringstream ss;
			ss.precision(9); // ceil(24*log10(2))+1
			ss << value;
			m_string = ss.str();
		} else {
			Reset();
		}
	}
	template<> inline void SetNumber<double>(double value) {
		if(std::isfinite(value)) {
			MakeType(JSONTYPE_NUMBER);
			std::ostringstream ss;
			ss.precision(17); // ceil(53*log10(2))+1
			ss << value;
			m_string = ss.str();
		} else {
			Reset();
		}
	}

	// for type bool
	inline void GetBool(bool& value) const {
		if(m_type == JSONTYPE_NULL)
			return fallback;
		if(m_type != JSONTYPE_BOOL)
			throw JSONTypeException();
		value = m_bool;
	}
	inline void SetBool(bool value) {
		MakeType(JSONTYPE_BOOL);
		m_bool = value;
	}

	// serialize/unserialize
	void ReadFromStream(std::streambuf* stream);
	void WriteToStream(std::streambuf* stream, unsigned int indent = 0) const;
	void ReadFromString(const std::string& str);
	void WriteToString(std::string* str);
	void ReadFromFile(const std::string& filename);
	void WriteToFile(const std::string& filename);

	// comparison
	bool operator==(const SimpleJSON& other) const;
	inline bool operator!=(const SimpleJSON& other) const { return !(*this == other); }

private:
	void MakeType(enum_jsontype type);

};
