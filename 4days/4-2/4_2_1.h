//
// Created by User on 2021-06-28.
//

#ifndef FUNC_PERSON_H
#define FUNC_PERSON_H
#include <iostream>
#include <string>

enum Grade {FRESH=1, SOPHOMORE, JUNIOR, SENIOR};
struct Person{
    std::string name;
};

void print(Person& p);
std::string& getGradeLabel(const Grade grade);

#endif //FUNC_PERSON_H
