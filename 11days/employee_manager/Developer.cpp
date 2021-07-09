//
// Created by User on 2021-07-08.
//

#include "Developer.h"

Developer::Developer(const std::string &name, const std::string &deptName, long wage)
        : Employee(name, deptName, wage) { }

void Developer::print(int depth) {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Developer& d)
{
    std::cout << *(Employee*)&d;
    return os;
}