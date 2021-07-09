//
// Created by User on 2021-07-08.
//

#ifndef EMPLOYEEMANAGER_DEVELOPER_H
#define EMPLOYEEMANAGER_DEVELOPER_H
#include "Employee.h"
class Developer: public Employee{
public:
    Developer(const std::string& name, const std::string& deptName, long wage);
    void print(int depth) override;
    friend std::ostream& operator<<(std::ostream& os, const Developer& d);

};


#endif //EMPLOYEEMANAGER_DEVELOPER_H
