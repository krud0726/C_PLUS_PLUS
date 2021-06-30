//
// Created by User on 2021-06-29.
//

#ifndef CLASS_2_SCHOOL_H
#define CLASS_2_SCHOOL_H
#include "student.h"
#include <map>
#include <string>

/*
 singletone pattern
 특정 클래스의 인스턴스를 1개만 생성되도록 제한하고 이를 공유하는 방법이다.
 이 패턴은 new 키워드로 클래스의 인스턴스를 직접 생성할 수 없도록 하고,
 해당 클래스내의 특정 함수로 부터 해당 클래스의 인스턴스를 전달 받는 방식이다.
 */
class School{
public:
    //singletone pattern ---------------
    static School& getInstance(std::string name){
        static School s{name};
        return s;
    };

    School (School const&) = delete;
    School (School&&) = delete;
    School & operator=(School const&) = delete;
    School & operator=(School&&) = delete;
    ~School() = default;
    // ------------------------

    void addStudent(const std::string& id, const Student& s);
    void deleteStudent(const std::string& id);
    void modifyStudentGPA(const std::string& id, double gpa);

    bool findStudent(const std::string& id) const;

    void print() const{
        std::cout << "School Name: "<< _name << ", "<< "# of Student: "<< students.size() << '\n';
        for(const auto& s: students)
            s.second.print();
    }
    void print(const std::string& id) const;

private:
    // you can create an instance of Student class directly.
    School(std::string name): _name(name) {};
    std::string _name;
    std::map<std::string, Student> students;
};

#endif //CLASS_2_SCHOOL_H
