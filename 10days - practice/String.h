//
// Created by User on 2021-07-07.
//

#ifndef EIGHT4_STRING_H
#define EIGHT4_STRING_H
#include <string.h>
#include <algorithm>
#include <iostream>

class String{
public:
    String() : _size(0), _data(nullptr) { }// 기본생성자
    String(const char* str)
    {
        _size = strlen(str);
        _data = new char[_size];
        strcpy(_data, str);
    }// 생성자 1

    String(const String& str)
    {
        _size = str._size;
        _data = new char[_size];
        strcpy(_data, str._data);
    }// 복사 생성자

    String(String &&str) : _size(str._size), _data(str._data){
        str._size = 0;
        str._data = nullptr;
    }// 이동 생성자

    String& operator=(const String& str) noexcept
    {
        _size = str._size;
        if(str._data != nullptr) {
            delete []_data;
            _data = new char[str._size];
            strcpy(_data, str._data);
        }
        else
            _data = nullptr;

        return *this;
    }// 복사 대입 연산자

    String& operator=(String&& str) noexcept
    {
        if(this != &str) {
            delete[] _data;
            _size = str._size;
            _data = str._data;

            str._size = 0;
            str._data = nullptr;
        }

        return *this;
    }// 이동 대입 연산자자

    ~String()
    {
        if(_data){
            delete[] _data;
        }
    }// 소멸자

    // six rules을 준수하여 default operators를 모두 구현하시오.

    // 필요한 멤버함수, 연산자 정의

    // getter method
    size_t getSize() const;
    char* getStr() const;

    // operator <<
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    bool operator ==(const String& c) const;


private:
    size_t _size = 0;
    char* _data = nullptr;
};


#endif //EIGHT4_STRING_H
