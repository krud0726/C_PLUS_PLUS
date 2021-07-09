//
// Created by User on 2021-07-08.
//
#include "Manager.h"

Manager::Manager(const std::string &name, const std::string &deptName, long wage) : Employee(name, deptName, wage) {
    employees.insert({this->getEmployeeID(), this});
};

bool Manager::addEmployee(Employee *employee) {
    std::pair<size_t, Employee*> p(employee->getEmployeeID(), employee);

    if(employee != nullptr){ employees.insert(p); return true; }
    else { return false; }
}

bool Manager::moveDept(size_t ID, const std::string &deptName) {
    auto it = employees.find(ID);
    if( it != employees.end())
    {
        it->second->changeDept(deptName);
        return true;
    }
    else { return false; }
}

std::optional<Employee> Manager::excludeEmployee(size_t ID) {
    auto it = employees.find(ID);

    if( it != employees.end()) { Employee temp(*(it->second)); employees.erase(ID); return temp; }
    else { return std::nullopt; }
}

void Manager::print(int depth) {

    std::cout << *this;

    for(auto& it : this->employees)
    {
        if( (it.second) == (employees.begin()->second))
        {
            continue;
        }
        else{
            Manager* p = dynamic_cast<Manager*>(it.second);
            for(auto f = p->employees.begin(); f != p->employees.end(); f++)
            {
                std::cout << *(f->second);
            }
        }
    }

}

std::ostream& operator<<(std::ostream& os, const Manager& e)
{
    if(e.employees.size() != 0) {
        std::cout << *(e.employees.begin()->second);
    }
    return os;
}