/*
Copyright (c) 2012-2015 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
*/

#include <cstdint>
#include <cstring>

#include <iostream>
#include <sstream>
#include <string>

#define UNUSED(x) (void) (x)

// Generic number-to-string conversion and vice versa.
// Unlike the standard functions, these are locale-independent, and the functions never throw exceptions.
template<typename T> inline std::string NumToString(T number) {
	std::ostringstream ss;
	ss << number;
	return ss.str();
}
template<> inline std::string NumToString<int8_t>(int8_t number) {
	std::ostringstream ss;
	ss << (int) number;
	return ss.str();
}
template<> inline std::string NumToString<uint8_t>(uint8_t number) {
	std::ostringstream ss;
	ss << (unsigned int) number;
	return ss.str();
}
template<typename T> inline bool StringToNum(const std::string& str, T* number) {
	std::istringstream ss(str);
	ss >> *number;
	return !ss.fail();
}
template<> inline bool StringToNum<int8_t>(const std::string& str, int8_t* number) {
	int num;
	std::istringstream ss(str);
	ss >> num;
	*number = num;
	return (!ss.fail() && num >= -128 && num <= 127);
}
template<> inline bool StringToNum<uint8_t>(const std::string& str, uint8_t* number) {
	unsigned int num;
	std::istringstream ss(str);
	ss >> num;
	*number = num;
	return (!ss.fail() && num <= 255);
}

// Increases the size to a multiple of 16 (for alignment).
inline size_t GrowAlign16(size_t size) {
	return (size_t) (size + 15) & ~((size_t) 15);
}

// Returns the time of the monotonic clock in microseconds.
uint64_t MonotonicTimeMicro();

// Returns a random number from a global random number generator which is seeded automatically.
uint64_t RandomUInt64();

// Returns the user runtime directory.
std::string GetRuntimeDir();

// Returns the program name (i.e. filename of the binary).
std::string GetProgramName();

// Returns the error string corresponding to the last error that occurred.
std::string ErrorString();
