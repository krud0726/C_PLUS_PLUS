//
// Created by User on 2021-06-29.
//

#ifndef CLASS_2_STUDENT_H
#define CLASS_2_STUDENT_H
#include <string>
#include <iostream>

class Student{
public:
    Student(std::string id, std::string name, double gpa)
        :_id{id}, _name{name}, _gpa{gpa} {};
    ~Student() = default;

    void modifyGPA(double gpa);
    void print() const;

private:
    std::string _id, _name;
    double _gpa = 0.0;
};
#endif //CLASS_2_STUDENT_H
