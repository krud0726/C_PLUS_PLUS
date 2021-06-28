//
// Created by User on 2021-06-28.
//

#ifndef FUNC_PROFESSOR_H
#define FUNC_PROFESSOR_H
#include "person.h"

struct Professor: public Person{
    std::string roomNo;
    Professor(std::string _name, std::string _roomNo)
        : Person{_name}, roomNo(_roomNo) {};

    void print() const;
};

void print();

#endif //FUNC_PROFESSOR_H
