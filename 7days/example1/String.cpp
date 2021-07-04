//
// Created by User on 2021-07-02.
//

#include "String.h"
#include <exception>
using namespace std;

// 기본 생성자
String::String() {
    cout << "default constructor" << endl;
}

// 생성자 1
String::String(const char* s)
{
    cout << "constructor with the one argument" << endl;
    _data.insert(_data.begin(), s, s+ strlen(s)+1);
}

// 소멸자
String::~String() noexcept{
    cout << "destructor" << endl;
}

// 이동 생성자
String::String(String &&s) noexcept : _data(move(s._data)){
    cout <<"move constructor" <<endl;
}

// 복사 생성자
String::String(const String &s) noexcept : _data(s._data) {
    cout << " copy constructor" << endl;
}

const char* String::data() const {
    return this->_data.data();
}

bool String::empty() const {
    return _data.empty();
}

size_t String::size() const {
    return _data.size();
}

String& String::append(const String &str) {
    _data.insert(_data.end()-1, str._data.begin(), str._data.end());
    return *this;
}

String& String::append(const char *str) {
    _data.insert(_data.end()-1, str, str+strlen(str));
    return *this;
}

int String::compare(const String &s) const {
    return _data == s._data? 0 : -1;
}

int String::compare(const char *s) const {
    const char* tmp = (const char*)_data.data();
    if(strcmp(tmp, s) == 0)
        return 0;
    else
        return -1;
}
