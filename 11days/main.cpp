#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(const string& name) : name(name) {
        cout << "Person is constructed!" << endl;
    };
    ~Person() {
        cout << "Person is destructed!" <<endl;
    };
    void print() const {
        cout << "Person Name: " << name << endl;
    }
private:
    string name;
};


class Student : public Person {
public:
    Student(const string& name, const string& schoolName) : Person(name), schoolName(schoolName) {
        cout << "Student is constructed!" << endl;
    };
    ~Student(){
        cout << "Student is destructed!" << endl;
    }
    void print() const{
        Person::print();
        cout << "School Name: " << schoolName << endl;
    }

private:
    string schoolName;
};


int main() {
    Person p1{"park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}
