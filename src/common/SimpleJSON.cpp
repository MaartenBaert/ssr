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

#include "SimpleJSON.h"

#include <cassert>
#include <cfloat>
#include <cmath>

#include <fstream>
#include <sstream>

inline void SkipWhitespace(std::streambuf* stream) {
	for( ; ; ) {
		int c = stream->sgetc();
		if(c != ' ' && c != '\t' && c != '\n' && c != '\r')
			break;
		stream->sbumpc();
	}
}

inline void WriteChar(std::streambuf* stream, char c) {
	if(stream->sputc(c) == EOF)
		throw JSONIOException();
}

inline void WriteData(std::streambuf* stream, const char* data, std::streamsize len) {
	if(stream->sputn(data, len) != len)
		throw JSONIOException();
}

inline unsigned int ReadHex(char c) {
	if(c >= '0' && c <= '9')
		return c - '0';
	if(c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if(c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	throw JSONParseException();
}

inline char WriteHex(unsigned int val) {
	if(val < 10)
		return '0' + val;
	return 'a' + val - 10;
}

inline void ReadString(std::streambuf* stream, std::string* str) {
	for( ; ; ) {
		int c = stream->sbumpc();
		if(c == EOF)
			throw JSONParseException();
		if(c == '"')
			break;
		if(c == '\\') {
			c = stream->sbumpc();
			if(c == EOF) {
				throw JSONParseException();
			} else if(c == '"') {
				*str += '"';
			} else if(c == '\\') {
				*str += '\\';
			} else if(c == '/') {
				*str += '/';
			} else if(c == 'b') {
				*str += '\b';
			} else if(c == 'f') {
				*str += '\f';
			} else if(c == 'n') {
				*str += '\n';
			} else if(c == 'r') {
				*str += '\r';
			} else if(c == 't') {
				*str += '\t';
			} else if(c == 'u') {
				int c1 = stream->sbumpc();
				if(c1 == EOF)
					throw JSONParseException();
				int c2 = stream->sbumpc();
				if(c2 == EOF)
					throw JSONParseException();
				int c3 = stream->sbumpc();
				if(c3 == EOF)
					throw JSONParseException();
				int c4 = stream->sbumpc();
				if(c4 == EOF)
					throw JSONParseException();
				unsigned int codepoint = (ReadHex(c1) << 12) | (ReadHex(c2) << 8) | (ReadHex(c3) << 4) | ReadHex(c4);
				if(codepoint < 0x0080) {
					*str += (char) codepoint;
				} else if(codepoint < 0x0800) {
					*str += (char) (0xc0 | (codepoint >> 6));
					*str += (char) (0x80 | (codepoint & 0x3f));
				} else {
					*str += (char) (0xe0 | (codepoint >> 12));
					*str += (char) (0x80 | ((codepoint >> 6) & 0x3f));
					*str += (char) (0x80 | (codepoint & 0x3f));
				}
			} else {
				throw JSONParseException();
			}
		} else if(c < 32 || c == 127) {
			throw JSONParseException();
		} else {
			*str += c;
		}
	}
}

inline void WriteString(std::streambuf* stream, const std::string& str) {
	WriteChar(stream, '"');
	for(char c : str) {
		if(c == '"') {
			WriteData(stream, "\\\"", 2);
		} else if(c == '\\') {
			WriteData(stream, "\\\\", 2);
		} else if(c == '\b') {
			WriteData(stream, "\\b", 2);
		} else if(c == '\f') {
			WriteData(stream, "\\f", 2);
		} else if(c == '\n') {
			WriteData(stream, "\\n", 2);
		} else if(c == '\r') {
			WriteData(stream, "\\r", 2);
		} else if(c == '\t') {
			WriteData(stream, "\\t", 2);
		} else if((c >= 0 && c <= 31) || c == 127) {
			char code[6] = {'\\', 'u', '0', '0', WriteHex((unsigned int) c >> 4), WriteHex((unsigned int) c & 0xf)};
			WriteData(stream, code, 6);
		} else {
			WriteChar(stream, c);
		}
	}
	WriteChar(stream, '"');
}

const SimpleJSON SimpleJSON::NULL_VALUE;

void SimpleJSON::Reset() {
	m_type = JSONTYPE_NULL;
	m_members.clear();
	m_members_order.clear();
	m_elements.clear();
	m_string.clear();
}

void SimpleJSON::ResetObject() {
	Reset();
	m_type = JSONTYPE_OBJECT;
}

size_t SimpleJSON::GetMemberCount() const {
	if(m_type == JSONTYPE_NULL)
		return 0;
	if(m_type != JSONTYPE_OBJECT)
		throw JSONTypeException();
	return m_members_order.size();
}

std::string SimpleJSON::GetMemberKey(size_t index) const {
	if(m_type != JSONTYPE_OBJECT)
		throw JSONTypeException();
	if(index >= m_members_order.size())
		throw JSONTypeException();
	return m_members_order[index]->first;
}

const SimpleJSON& SimpleJSON::GetMemberValue(size_t index) const {
	if(m_type != JSONTYPE_OBJECT)
		throw JSONTypeException();
	if(index >= m_members_order.size())
		throw JSONTypeException();
	return m_members_order[index]->second;
}

SimpleJSON& SimpleJSON::operator()(const std::string& key) {
	MakeType(JSONTYPE_OBJECT);
	auto p = m_members.emplace(key, nullptr);
	if(p.second)
		m_members_order.push_back(p.first);
	return p.first->second;
}

const SimpleJSON& SimpleJSON::operator[](const std::string& key) const {
	if(m_type == JSONTYPE_NULL)
		return NULL_VALUE;
	if(m_type != JSONTYPE_OBJECT)
		throw JSONTypeException();
	auto it = m_members.find(key);
	if(it == m_members.end())
		return NULL_VALUE;
	return it->second;
}

void SimpleJSON::ResetArray() {
	Reset();
	m_type = JSONTYPE_ARRAY;
}

void SimpleJSON::ResizeArray(size_t size) {
	MakeType(JSONTYPE_ARRAY);
	m_elements.resize(size);
}

size_t SimpleJSON::GetElementCount() const {
	if(m_type == JSONTYPE_NULL)
		return 0;
	if(m_type != JSONTYPE_ARRAY)
		throw JSONTypeException();
	return m_elements.size();
}

SimpleJSON& SimpleJSON::AddElement() {
	MakeType(JSONTYPE_ARRAY);
	m_elements.resize(m_elements.size() + 1);
	return m_elements.back();
}

SimpleJSON& SimpleJSON::operator()(size_t index) {
	MakeType(JSONTYPE_ARRAY);
	if(index >= m_elements.size())
		m_elements.resize(index + 1);
	return m_elements[index];
}

const SimpleJSON& SimpleJSON::operator[](size_t index) const {
	if(m_type != JSONTYPE_ARRAY)
		throw JSONTypeException();
	if(index >= m_elements.size())
		throw JSONTypeException();
	return m_elements[index];
}

SimpleJSON& SimpleJSON::operator=(const std::string& value) {
	MakeType(JSONTYPE_STRING);
	m_string = value;
	return *this;
}

std::string SimpleJSON::ToString(const std::string& fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_STRING)
		throw JSONTypeException();
	return m_string;
}

SimpleJSON& SimpleJSON::operator=(int8_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(uint8_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(int16_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(uint16_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(int32_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(uint32_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(int64_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(uint64_t value) {
	MakeType(JSONTYPE_NUMBER);
	std::ostringstream ss;
	ss << value;
	m_string = ss.str();
	return *this;
}

SimpleJSON& SimpleJSON::operator=(float value) {
	if(std::isfinite(value)) {
		MakeType(JSONTYPE_NUMBER);
		std::ostringstream ss;
		ss.precision(9); // ceil(24*log10(2))+1
		ss << value;
		m_string = ss.str();
	} else {
		Reset();
	}
	return *this;
}

SimpleJSON& SimpleJSON::operator=(double value) {
	if(std::isfinite(value)) {
		MakeType(JSONTYPE_NUMBER);
		std::ostringstream ss;
		ss.precision(17); // ceil(53*log10(2))+1
		ss << value;
		m_string = ss.str();
	} else {
		Reset();
	}
	return *this;
}

int8_t SimpleJSON::ToInt8(int8_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

uint8_t SimpleJSON::ToUint8(uint8_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

int16_t SimpleJSON::ToInt16(int16_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

uint16_t SimpleJSON::ToUint16(uint16_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

int32_t SimpleJSON::ToInt32(int32_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

uint32_t SimpleJSON::ToUint32(uint32_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

int64_t SimpleJSON::ToInt64(int64_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

uint64_t SimpleJSON::ToUint64(uint64_t fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

float SimpleJSON::ToFloat(float fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

double SimpleJSON::ToDouble(double fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_NUMBER)
		throw JSONTypeException();
	std::istringstream ss(m_string);
	ss >> fallback;
	if(ss.fail())
		throw JSONParseException();
	return fallback;
}

SimpleJSON& SimpleJSON::operator=(bool value) {
	MakeType(JSONTYPE_BOOL);
	m_bool = value;
	return *this;
}

bool SimpleJSON::ToBool(bool fallback) const {
	if(m_type == JSONTYPE_NULL)
		return fallback;
	if(m_type != JSONTYPE_BOOL)
		throw JSONTypeException();
	return m_bool;
}

void SimpleJSON::ReadFromStream(std::streambuf* stream) {

	Reset();

	// what type is it?
	int c = stream->sbumpc();
	if(c == EOF)
		throw JSONParseException();
	if(c == '{') { // object
		m_type = JSONTYPE_OBJECT;
		SkipWhitespace(stream);

		// is there anything in it?
		c = stream->sgetc();
		if(c == EOF)
			throw JSONParseException();
		if(c == '}') {
			stream->sbumpc();
		} else {
			for( ; ; ) {

				// read the key
				c = stream->sbumpc();
				if(c != '"')
					throw JSONParseException();
				std::string key;
				ReadString(stream, &key);
				SkipWhitespace(stream);

				// read the colon
				c = stream->sbumpc();
				if(c != ':')
					throw JSONParseException();
				SkipWhitespace(stream);

				// read one value
				auto p = m_members.emplace(key, nullptr);
				if(p.second)
					m_members_order.push_back(p.first);
				else
					throw JSONParseException();
				p.first->second.ReadFromStream(stream);

				// is there more?
				c = stream->sbumpc();
				if(c == EOF)
					throw JSONParseException();
				if(c == '}')
					break;
				if(c != ',')
					throw JSONParseException();
				SkipWhitespace(stream);

			}
		}

	} else if(c == '[') { // array
		m_type = JSONTYPE_ARRAY;
		SkipWhitespace(stream);

		// is there anything in it?
		c = stream->sgetc();
		if(c == EOF)
			throw JSONParseException();
		if(c == ']') {
			stream->sbumpc();
		} else {
			for( ; ; ) {

				// read one value
				m_elements.resize(m_elements.size() + 1);
				m_elements.back().ReadFromStream(stream);

				// is there more?
				c = stream->sbumpc();
				if(c == EOF)
					throw JSONParseException();
				if(c == ']')
					break;
				if(c != ',')
					throw JSONParseException();
				SkipWhitespace(stream);

			}
		}

	} else if(c == '"') { // string
		m_type = JSONTYPE_STRING;

		ReadString(stream, &m_string);

	} else if(c == '-' || (c >= '0' && c <= '9')) { // number
		m_type = JSONTYPE_NUMBER;
		m_string = c;

		// read the entire number (parsing will be done later)
		for( ; ; ) {
			c = stream->sgetc();
			if((c < '0' || c > '9') && c != '.' && c != 'e' && c != 'E' && c != '+' && c != '-')
				break;
			m_string += c;
			stream->sbumpc();
		}

	} else if(c == 't') { // true
		m_type = JSONTYPE_BOOL;
		m_bool = true;

		// make sure that it's actually 'true'
		if(stream->sbumpc() != 'r' || stream->sbumpc() != 'u' || stream->sbumpc() != 'e')
			throw JSONParseException();

	} else if(c == 'f') { // false
		m_type = JSONTYPE_BOOL;
		m_bool = false;

		// make sure that it's actually 'false'
		if(stream->sbumpc() != 'a' || stream->sbumpc() != 'l' || stream->sbumpc() != 's' || stream->sbumpc() != 'e')
			throw JSONParseException();

	} else if(c == 'n') { // null

		// make sure that it's actually 'null'
		if(stream->sbumpc() != 'u' || stream->sbumpc() != 'l' || stream->sbumpc() != 'l')
			throw JSONParseException();

	} else {
		throw JSONParseException();
	}

	SkipWhitespace(stream);

}

void SimpleJSON::WriteToStream(std::streambuf* stream, unsigned int indent) const {
	switch(m_type) {
		case JSONTYPE_OBJECT: {
			WriteChar(stream, '{');
			for(auto it = m_members_order.begin(); it != m_members_order.end(); it = ++it) {
				if(it != m_members_order.begin())
					WriteChar(stream, ',');
				WriteChar(stream, '\n');
				for(unsigned int i = 0; i <= indent; ++i)
					WriteChar(stream, '\t');
				WriteString(stream, (*it)->first);
				WriteData(stream, ": ", 2);
				(*it)->second.WriteToStream(stream, indent + 1);
			}
			if(!m_members_order.empty()) {
				WriteChar(stream, '\n');
				for(unsigned int i = 0; i < indent; ++i)
					WriteChar(stream, '\t');
			}
			WriteChar(stream, '}');
			break;
		}
		case JSONTYPE_ARRAY: {
			WriteChar(stream, '[');
			for(auto it = m_elements.begin(); it != m_elements.end(); it = ++it) {
				if(it != m_elements.begin())
					WriteChar(stream, ',');
				WriteChar(stream, '\n');
				for(unsigned int i = 0; i <= indent; ++i)
					WriteChar(stream, '\t');
				it->WriteToStream(stream, indent + 1);
			}
			if(!m_elements.empty()) {
				WriteChar(stream, '\n');
				for(unsigned int i = 0; i < indent; ++i)
					WriteChar(stream, '\t');
			}
			WriteChar(stream, ']');
			break;
		}
		case JSONTYPE_STRING: {
			WriteString(stream, m_string);
			break;
		}
		case JSONTYPE_NUMBER: {
			WriteData(stream, m_string.data(), m_string.size());
			break;
		}
		case JSONTYPE_BOOL: {
			if(m_bool)
				WriteData(stream, "true", 4);
			else
				WriteData(stream, "false", 5);
			break;
		}
		case JSONTYPE_NULL: {
			WriteData(stream, "null", 4);
			break;
		}
	}
}

void SimpleJSON::ReadFromString(const std::string& str) {
	std::stringbuf stream(str);
	ReadFromStream(&stream);
	if(stream.sgetc() != EOF)
		throw JSONParseException();
}

void SimpleJSON::WriteToString(std::string* str) {
	std::stringbuf stream;
	WriteToStream(&stream);
	*str = stream.str();
}

void SimpleJSON::ReadFromFile(const std::string& filename) {
	std::filebuf stream;
	if(stream.open(filename, std::ios_base::in | std::ios_base::binary) == NULL)
		throw JSONIOException();
	ReadFromStream(&stream);
	if(stream.sgetc() != EOF)
		throw JSONParseException();
}

void SimpleJSON::WriteToFile(const std::string& filename) {
	std::filebuf stream;
	if(stream.open(filename, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc) == NULL)
		throw JSONIOException();
	WriteToStream(&stream);
}

bool SimpleJSON::operator==(const SimpleJSON& other) const {
	if(m_type != other.m_type)
		return false;
	switch(m_type) {
		case JSONTYPE_OBJECT: {
			auto it1 = m_members.begin();
			auto it2 = other.m_members.begin();
			while(it1 != m_members.end() && it2 != other.m_members.end()) {
				if(it1->first != it2->first || it1->second != it2->second)
					return false;
				++it1; ++it2;
			}
			return (it1 == m_members.end() && it2 == other.m_members.end());
		}
		case JSONTYPE_ARRAY: {
			auto it1 = m_elements.begin();
			auto it2 = other.m_elements.begin();
			while(it1 != m_elements.end() && it2 != other.m_elements.end()) {
				if(*it1 != *it2)
					return false;
				++it1; ++it2;
			}
			return (it1 == m_elements.end() && it2 == other.m_elements.end());
		}
		case JSONTYPE_STRING:
		case JSONTYPE_NUMBER: {
			return (m_string == other.m_string);
		}
		case JSONTYPE_BOOL: {
			return (m_bool == other.m_bool);
		}
		case JSONTYPE_NULL: {
			return true;
		}
		default: assert(false); return false;
	}
}

void SimpleJSON::MakeType(enum_jsontype type) {
	if(m_type == type)
		return;
	Reset();
	m_type = type;
}
