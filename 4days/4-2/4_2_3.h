//
// Created by User on 2021-06-28.
//

#ifndef FUNC_STUDENT_H
#define FUNC_STUDENT_H
#include "person.h"

struct Student: public Person{
    std::string grade;
    Student(std::string _name, Grade _grade)
        : Person{_name}, grade(getGradeLabel(_grade)){};

    void print() const;
};

void print();

#endif //FUNC_STUDENT_H
