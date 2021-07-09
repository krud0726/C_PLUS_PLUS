//
// Created by User on 2021-07-07.
//

#ifndef EIGHT4_COMPLEX_H
#define EIGHT4_COMPLEX_H
#include <iostream>

template <typename T, size_t N>
auto find(const T (&array) [N], const T& value)
{
    for(auto i=0; i< N; i++)
    {
        if(array[i] == value) return true;
    }
    return false;
}


class Complex{
public:
    // 생성자, 소멸자 이외의 copy / move 생성자, copy / move 대입 연산자는
    // 컴파일러가 생성해 주는 default operations 사용함
    Complex() : _r(0), _i(0) {};
    Complex(double r) : _r(r) { };
    Complex(double r, double i) : _r(r), _i(i) { };
    ~Complex() = default;

    // 필요한 멤버함수 , 연산자 정의
    Complex add(const Complex& c) {return {_r+c._r, _i+c._i};};
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

    double size() const;
    bool operator < (const Complex& c) const;
    bool operator ==(const Complex& c) const;

private:
    double _r = 0;
    double _i = 0;
};

#endif //EIGHT4_COMPLEX_H
