//
// Created by User on 2021-07-04.
//

#include "student.h"
#include <iostream>

void Student::modifyGPA(double gpa)
{
    _gpa = gpa;
}

void Student::print() const
{
    std::cout << _id << " " << _name << " " << _gpa << std::endl;
}
