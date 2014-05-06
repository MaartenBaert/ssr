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

#include <cstddef>
#include <cstdio>
#include <stdint.h>

#include <exception>
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
	inline SimpleJSON(nullptr_t) { m_type = JSONTYPE_NULL; }
	inline SimpleJSON(const SimpleJSON&) = default;
	inline SimpleJSON(SimpleJSON&&) = default;

	// copy assignments
	inline SimpleJSON& operator=(const SimpleJSON&) = default;
	inline SimpleJSON& operator=(SimpleJSON&&) = default;

	// other constructors
	inline SimpleJSON(const std::string& value) { *this = value; }
	inline SimpleJSON(const char* value) { *this = value; }
	inline SimpleJSON(int8_t value) { *this = value; }
	inline SimpleJSON(uint8_t value) { *this = value; }
	inline SimpleJSON(int16_t value) { *this = value; }
	inline SimpleJSON(uint16_t value) { *this = value; }
	inline SimpleJSON(int32_t value) { *this = value; }
	inline SimpleJSON(uint32_t value) { *this = value; }
	inline SimpleJSON(int64_t value) { *this = value; }
	inline SimpleJSON(uint64_t value) { *this = value; }
	inline SimpleJSON(float value) { *this = value; }
	inline SimpleJSON(double value) { *this = value; }
	inline SimpleJSON(bool value) { *this = value; }

	// general
	void Reset();
	inline enum_jsontype GetType() const { return m_type; }
	inline bool IsNull() const { return (m_type == JSONTYPE_NULL); }

	// for type object
	void ResetObject();
	size_t GetMemberCount() const;
	std::string GetMemberKey(size_t index) const;
	const SimpleJSON& GetMemberValue(size_t index) const;
	SimpleJSON& operator()(const std::string& key);
	const SimpleJSON& operator[](const std::string& key) const;

	// for type array
	void ResetArray();
	void ResizeArray(size_t size);
	size_t GetElementCount() const;
	SimpleJSON& AddElement();
	SimpleJSON& operator()(size_t index);
	const SimpleJSON& operator[](size_t index) const;

	// for type string
	SimpleJSON& operator=(const std::string& value);
	inline SimpleJSON& operator=(const char* value) { return *this = std::string(value); }
	std::string ToString(const std::string& fallback) const;

	// for type number
	SimpleJSON& operator=(int8_t value);
	SimpleJSON& operator=(uint8_t value);
	SimpleJSON& operator=(int16_t value);
	SimpleJSON& operator=(uint16_t value);
	SimpleJSON& operator=(int32_t value);
	SimpleJSON& operator=(uint32_t value);
	SimpleJSON& operator=(int64_t value);
	SimpleJSON& operator=(uint64_t value);
	SimpleJSON& operator=(float value);
	SimpleJSON& operator=(double value);
	int8_t ToInt8(int8_t fallback) const;
	uint8_t ToUint8(uint8_t fallback) const;
	int16_t ToInt16(int16_t fallback) const;
	uint16_t ToUint16(uint16_t fallback) const;
	int32_t ToInt32(int32_t fallback) const;
	uint32_t ToUint32(uint32_t fallback) const;
	int64_t ToInt64(int64_t fallback) const;
	uint64_t ToUint64(uint64_t fallback) const;
	float ToFloat(float fallback) const;
	double ToDouble(double fallback) const;

	// for type bool
	SimpleJSON& operator=(bool value);
	bool ToBool(bool fallback) const;

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

	// do not use these functions, they are only here to avoid accidental conversions from pointer to bool
	inline SimpleJSON(const void*) { }
	inline SimpleJSON& operator=(const void*) { return *this; }

};
