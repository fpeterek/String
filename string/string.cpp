//
//  string.cpp
//  string
//
//  Created by Filip Peterek on 16/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "string.hpp"

string::string() {
    
    c_str = (char *) malloc(1);
    c_str[0] = '\0';
    
}

string::string(const char * str) {
    
    c_str = (char *) malloc(1);
    c_str[0] = '\0';
    
    assign(str);
    
}

string::string(const string & str) {
    
    c_str = (char *) malloc(1);
    c_str[0] = '\0';
    
    assign(str.c_string());
    
}

size_t string::length() const {
    
    return strlen(c_str);
    
}

void string::assign(const char * str) {
    
    mem_alloc(strlen(str) + 1);
    strcpy(c_str, str);
    
}

void string::operator=(const char * str) {
    assign(str);
}

void string::assign(const string & str) {
    assign(str.c_string());
}

void string::operator= (const string & str) {
    assign(str.c_string());
}

void string::append(const char * str) {
    
    mem_alloc(length() + strlen(str) + 1);
    c_str = strcat(c_str, str);
    
}

void string::operator+=(const char * str) {
    append(str);
}

void string::append(const string & str) {
    append(str.c_string());
}

void string::operator+=(const string & str) {
    append(str.c_string());
}

string string::concatenate(const char * str) const {
    
    string newString = c_str;
    newString.append(str);
    return newString;
    
}

string string::operator+(const char * str) const {
    return concatenate(str);
}

string string::concatenate(const string & str) const {
    return concatenate(str.c_string());
}

string string::operator+(const string & str) const {
    return concatenate(str.c_string());
}

string string::reversed_substr(long long end, long long begin) const {
    
    char temp[end - begin];
    
    long long c = 0;
    for (long long i = end - 1; i >= begin; --i) {
        temp[c++] = c_str[i];
    }
    temp[c] = '\0';
    
    return string(temp);
    
}

string string::reverse() const {
    return reversed_substr(length(), 0);
}

string string::substring(long long begin, long long end) const {
    
    string substr;
    
    if (begin > length() or end > length()) {
        throw std::out_of_range("Accessing element out of range");
    }
    
    if (begin > end) {
        return reversed_substr(begin, end);
    }
    
    for (size_t i = begin; i < end; ++i) {
        const char temp[2] = { c_str[i], '\0'};
        substr.append( temp );
    }
    
    return substr;
    
}

string string::substring(long long begin) const {
    return substring(begin, length());
}

bool string::compare(const char * str) const {
    return not strcmp(c_str, str);
}

bool string::operator==(const char * str) const {
    return compare(str);
}

bool string::compare(const string & str) const {
    return compare(str.c_string());
}

bool string::operator==(const string & str) const {
    return compare(str.c_string());
}

const char & string::at(long long pos) const {
    
    if (pos < 0) {
        pos = length() + pos;
    }
    
    if ( (unsigned long long)pos >= strlen(c_str) ) {
        throw std::out_of_range("Accessing element out of range. ");
    }
    
    return c_str[pos];
    
}

const char & string::operator[](long long pos) const {
    return at(pos);
}

char & string::at(long long pos) {
    
    if (pos < 0) {
        pos = length() + pos;
    }
    
    if ( (unsigned long long)pos >= strlen(c_str) ) {
        throw std::out_of_range("Accessing element out of range. ");
    }
    
    return c_str[pos];
    
}

char & string::operator[](long long pos) {
    return at(pos);
}

size_t string::find(const char * str) const {
    
    size_t position = -1;
    
    const char * substrPos = strstr(c_str, str);
    
    if (substrPos == nullptr) {
        return position;
    }
    
    position = substrPos - c_str;
    return position;
    
}

size_t string::find(const string & str) const {
    
    return find(str.c_string());
    
}

void string::mem_alloc(unsigned long long bytes) {
    
    if (c_str == nullptr) {
        c_str = (char *)malloc(bytes);
    }
    c_str = (char *)realloc(c_str, bytes);
    
    if (c_str == nullptr) {
        throw std::runtime_error("Memory allocation fail. ");
    }
    
}

const char * string::c_string() const {
    
    return c_str;
    
}

std::ostream & operator<< (std::ostream & os, const string & s) {
    
    return os << s.c_string();
    
}
