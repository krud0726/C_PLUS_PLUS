//
// Created by User on 2021-07-02.
//

#ifndef EXAMPLE_STRING_H
#define EXAMPLE_STRING_H

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

class String{
public:
    // 기본 생성자
    String();
    // 생성자 1
    String(const char* s);
    // 소멸자
    ~String() noexcept;
    // 이동 생성자
    String(String&& s) noexcept;
    // 이동 대입 연산자
    String& operator=(String&& s) noexcept{
        std::cout<<"move assignment operator"<<std::endl;
        String tmp(std::move(s));
        swap(tmp);
        return *this;
    }

    // 복사 생성자
    String(const String& s) noexcept;

    // 복사 대입 연산자
    String& operator=(const String& s) noexcept{
        std::cout<<"copy assignment operator" << std::endl;
        String tmp(s);
        swap(tmp);
        return *this;
    }

public:
    const char* data() const;
    bool empty() const;
    size_t size() const;
    String& append(const String& str);
    String& append(const char* str);
    int compare(const String& s) const;
    int compare(const char* s) const;

private:
    std::vector<char> _data;
    void swap(String& other) noexcept{
        using std::swap;
        swap(this->_data, other._data);
    };

};
#endif //EXAMPLE_STRING_H
