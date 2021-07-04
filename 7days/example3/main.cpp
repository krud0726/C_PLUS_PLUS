#include "school.h"
#include <algorithm>
#include <map>
using namespace std;

enum Command {ADD, DELETE, PRINT, FIND, MODIFY, QUIT, INVALID};

pair<string, Student> make_student(){
    cout << "Enter id, name, gpa: ";
    string id;
    string studentName;
    double gpa;
    cin >> id >> studentName >> gpa;
    Student s{id, studentName, gpa};
    pair<string, Student> result = pair<string, Student>{id, s};
    return result;
}

Command getCommand(const string& command){
    static map<string, Command> cmd = {
            {"add", ADD}, {"delete",DELETE}, {"print", PRINT},
            {"find",FIND}, {"modify", MODIFY}, {"quit", QUIT},
            {"invalid", INVALID}
    };

    auto find_it = cmd.find(command);
    if(find_it != end(cmd))
        return cmd[command];
    else
        return cmd["invalid"];
}



int main() {
    cout << "Set School Name : ";
    string schoolName;
    cin >> schoolName;
    School& school = School::getInstance(schoolName);

    while(true)
    {
        cout<< "Enter Command: ";
        string cmd;
        cin >> cmd;
        transform(begin(cmd), end(cmd), begin(cmd), [](char& c){return tolower(c);});
        Command c = getCommand(cmd);

        switch(c)
        {
            case ADD:{
                auto r = make_student();
                school.addStudent(r.first, r.second);
                break;
            }
            case DELETE: {
                cout << "Enter id: ";
                string id;
                cin >> id;
                school.deleteStudent(id);
                break;
            }
            case FIND: {
                cout << "Enter id: ";
                string id;
                cin >> id;
                auto r = school.findStudent(id);
                if(r) school.print(id);
                break;
            }
            case PRINT: {
                school.print();
                break;
            }
            case MODIFY:{
                cout << "Enter id, gpa: ";
                string id;
                double gpa;
                cin >> id >> gpa;
                school.modifyStudentGPA(id, gpa);
                break;
            }
            case QUIT:
                return 0;
            default:
                cout << "Invalid Command" << endl;
        }
    }

}
