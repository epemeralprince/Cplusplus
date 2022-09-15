#include "String.h"
#include <string.h>

String::String(const char* chars) {
    this->_len = strlen(chars);
    this->_capable_size = _len+1;
    this->_str = new char[_capable_size];
    for (unsigned int i = 0; i < _capable_size; i++) {
        _str[i] = chars[i];
    }
}

String::String(const char* chars, unsigned int pos, unsigned int len = 0) {
    if (len==0) this->_len = strlen(chars+pos);
    else this->_len = len;
    this->_capable_size = _len+1;
    this->_str = new char[_capable_size];
    for (unsigned int i = 0; i < _capable_size; i++) {
        _str[i] = chars[i];
    }
}

String::String(unsigned int len, char ch) {
    this->_len = len;
    this->_capable_size = _len+1;
    this->_str = new char[_capable_size];
    for (unsigned int i = 0; i < len; i++) {
        _str[i] = ch;
    }
    _str[len] = '\0';
}

String::String(std::initializer_list<char> il) {}

String::String(const String& str) {
    this->_len = str._len;
    this->_capable_size = str._capable_size;
    this->_str = new char[_capable_size];
    for (unsigned int i = 0; i < _capable_size; i++) {
        _str[i] = str[i];
    }
}

String::String(String&& str) {
    this->_len = str._len;
    this->_capable_size = str._capable_size;
    this->_str = str._str;
    str._str = nullptr;
}

String::~String() {
    delete _str;
}

String& String::operator=(const String& str) {
    if (this==&str) return *this;
    this->_len = str._len;
    this->_capable_size = str._capable_size;
    delete this->_str;
    this->_str = new char[_capable_size];
    for (unsigned int i = 0; i < _capable_size; i++) {
        _str[i] = str[i];
    }
}

bool String::operator==(const String& str) const {
    if (this->_len!=str._len) return false;
    for (unsigned int i = 0; i < this->_len; i++) {
        if (this->operator[i]!=str[i]) return false;
    }
    return true;
}

char& String::operator[](unsigned int index) {
    return *(this->_str+index);
}

const char& String::operator[](unsigned int index) const {
    return *(this->_str+index);
}

};