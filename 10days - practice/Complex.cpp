//
// Created by User on 2021-07-07.
//

#include "Complex.h"
#include <cmath>

double Complex::size() const
{
    return sqrt(_r*_r + _i*_i);
}
bool Complex::operator < (const Complex& c) const
{
    return size() < c.size();
}
bool Complex::operator ==(const Complex& c) const
{
    return (_r == c._r && _i == c._i);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    std::cout << c._r << "+" << c._i << "i";
    return os;
}