//
// Created by User on 2021-07-08.
//

#ifndef EMPLOYEEMANAGER_EMPLOYEE_H
#define EMPLOYEEMANAGER_EMPLOYEE_H

#include <iostream>

class Employee {
public:
    Employee(const std::string& name, const std::string& deptName, long wage);
    void changeDept(std::string newDeptName);
    size_t getEmployeeID();
    virtual void print(int depth) { };
    bool operator==(const Employee& e) const {
        return _name == e._name &&
                    _deptName == e._deptName && _wage == e._wage;
    }
    bool operator != (const Employee& e){
        return !operator==(e);
    }
    friend std::ostream& operator<<(std::ostream& os, const Employee& e);

private:
    size_t _id;             // 사번
    std::string _name;      // 이름
    std::string _deptName;  // 부서명
    long _wage;             // 급여
};

#endif //EMPLOYEEMANAGER_EMPLOYEE_H
