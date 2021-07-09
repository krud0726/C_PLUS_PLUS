//
// Created by User on 2021-07-08.
//

#include "Employee.h"

static size_t ID = 1;

Employee::Employee(const std::string &name, const std::string &deptName, long wage)
    : _id(ID++), _name(name), _deptName(deptName), _wage(wage) { }

void Employee::changeDept(std::string newDeptName) {
    _deptName = newDeptName;
}

size_t Employee::getEmployeeID() {
    return _id;
}

std::ostream& operator<<(std::ostream& os, const Employee& e)
{
    std::cout << e._deptName << "\t" << e._id << "\t" << e._name << "\t" << e._wage << std::endl;
    return os;
}