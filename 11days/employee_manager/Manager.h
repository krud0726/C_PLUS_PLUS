//
// Created by User on 2021-07-08.
//

#ifndef EMPLOYEEMANAGER_MANAGER_H
#define EMPLOYEEMANAGER_MANAGER_H
#include "Employee.h"
#include <map>
#include <optional>
#include <memory>

class Manager: public Employee{
public:
    Manager(const std::string& name, const std::string& deptName, long wage);
    bool addEmployee(Employee* employee);
    bool moveDept(size_t ID, const std::string& deptName);
    std::optional<Employee> excludeEmployee(size_t ID);
    void print(int depth) override;
    friend std::ostream & operator<<(std::ostream& os, const Manager& e);

private:
    std::map<size_t, Employee*> employees;
};
#endif //EMPLOYEEMANAGER_MANAGER_H
