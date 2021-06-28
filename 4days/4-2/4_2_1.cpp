//
// Created by User on 2021-06-28.
//
#include "person.h"

void print(Person& p)
{
    std::cout<<p.name<<" person"<< std::endl;
}

std::string& getGradeLabel(const Grade grade){
    static std::string  gradeLabels[] = {"Fresh", "Sophomore", "Junior", "Senior"};
    return gradeLabels[grade-1];
}
