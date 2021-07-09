//
// Created by User on 2021-07-07.
//
#include "String.h"

size_t String::getSize() const{
    return strlen(_data);
}

char* String::getStr() const{
    return _data;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
    if(s._data != nullptr){
        std::cout << s._data;
    }
    return os;
}

bool String::operator==(const String& c) const{
    // strcmp는 함수 성공시 0을 반환
    if((_data != nullptr) && (!strcmp(_data, c._data))) {
        return true;
    }
    else
    {
        return false;
    }
}
