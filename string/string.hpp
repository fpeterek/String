//
//  string.hpp
//  string
//
//  Created by Filip Peterek on 16/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef string_hpp
#define string_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>


class string {
    
    char * c_str;
    
    void mem_alloc(unsigned long long bytes);
    
    string reversed_substr(long long end, long long begin) const;
    
public:
    
    static const size_t npos = -1;
    
    string();
    string(const char * str);
    string(const string & str);
    
    size_t length() const;
    
    void assign(const char * str);
    void operator= (const char * str);
    void assign(const string & str);
    void operator= (const string & str);
    
    void append(const char * str);
    void operator+=(const char * str);
    void append(const string & str);
    void operator+=(const string & str);
    
    void append(const char c);
    void operator+=(const char c);
    
    string concatenate(const char * str)   const;
    string operator+(const char * str)     const;
    string concatenate(const string & str) const;
    string operator+(const string & str)   const;
    
    bool compare(const char * str)       const;
    bool operator== (const char * str)   const;
    bool compare(const string & str)     const;
    bool operator== (const string & str) const;
    
    const char & at(long long pos)          const;
    const char & operator[] (long long pos) const;
    char & at(long long pos);
    char & operator[](long long pos);
    
    string reverse() const;
    
    size_t find(const char * str)   const;
    size_t find(const string & str) const;
    
    string substring(long long begin)           const;
    string substring(long long begin, long long end) const;
    
    const char * c_string() const;
    
};

std::ostream & operator<< (std::ostream & os, const string & s);

#endif /* string_hpp */
