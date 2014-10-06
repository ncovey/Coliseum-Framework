/*
#include "str.h"

using namespace CF;
using namespace EGG;

// ctor
str::str(){}
str::str(const str&){}
// dtor
str::~str(){}

//////////////////////////////////////////////////////////////////////////
// operator overloads
str& str::operator=(const str&){}
str& str::operator=(const char*){}
str& str::operator=(const char){}
str& str::operator+=(const str&){}
str& str::operator+=(const char*){}
str& str::operator+=(const char){}
const char& str::operator[](const unsigned int) const{}
char& str::operator[](const unsigned int){}

//////////////////////////////////////////////////////////////////////////
// getters
unsigned int str::size() const{}
const char* str::c_str() const{}
// uppercase
str& str::getupper() const{}
// lowercase
str& str::getlower() const{}
// get part of string
const str& str::substr(unsigned int begin, unsigned int end) const{}

// case-sensitive
bool str::haschar(const char) const{}
// not case-sensitive
bool str::hasncasechar(const char) const{}
// case-sensitive
bool str::hasstr(const str&) const{}
bool str::hasstr(const char*) const{}
// not case-sensitive
bool str::hasncasestr(const str&) const{}
bool str::hasncasestr(const char*) const{}

// returns index of first instance, -1 if not found
int str::findchar(const char) const{}
// returns index of first char of the str in the str
int str::findstr(const str&) const{}
int str::findstr(const char*) const{}

//////////////////////////////////////////////////////////////////////////
// manipulators
void str::clear(){}
// uppercase
str& str::makeupper(){}
// lowercase
str& str::makelower(){}
// removes the first chars
void str::truncfront(unsigned int numChars){}
// removes the last chars
void str::truncback(unsigned int numChars){}

// replace part of the string
void str::replace(unsigned int begin, unsigned int end, const str&){}
void str::replace(unsigned int begin, unsigned int end, const char*){}

// removes the character at the index
void str::remove(unsigned int){}
// removes all instances of the character
void str::remove(const char){}
// removes all instances of the string
void str::remove(const str&){}
void str::remove(const char*){}
*/