//
// Created by User on 2021-07-04.
//
#include "school.h"

void School::addStudent(const std::string& id, const Student& s)
{
    if(!students.count(id))
        students.insert({id, s});
}
void School::deleteStudent(const std::string& id)
{
    students.erase(id);
}
void School::modifyStudentGPA(const std::string& id, double gpa)
{
    auto find_it = students.find(id);
    if(find_it != students.end())
    {
        find_it->second.modifyGPA(gpa);
    }
}

bool School::findStudent(const std::string& id) const
{
    auto find_it = students.find(id);
    if(find_it != students.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void School::print(const std::string& id)const
{
    auto find_it = students.find(id);
    if(find_it != students.end())
    {
        find_it->second.print();
    }
}

