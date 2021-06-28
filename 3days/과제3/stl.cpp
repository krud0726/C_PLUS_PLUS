#include "student.h"

using namespace std;

unique_ptr<StudentInfo> make_student(){
    unique_ptr<StudentInfo> ptr(new StudentInfo);

    cin >> ptr->name;

    for(int i =0; i<SUBJECT_NO; i++)
    {
        cin >> ptr->scores[i];
    }
    return move(ptr);
}

void print(const StudentInfo& si) {
    int sum;
    double average;

    cout<< si.name << "\t";
    for(int i=0; i<SUBJECT_NO; i++)
    {
        sum += si.scores[i];
        cout << si.scores[i] << "\t";
    }
    average = (double)sum/SUBJECT_NO;

    cout<< sum << "\t"<<average<<endl;
    sum =0;
}

void print_all(const vector<unique_ptr<StudentInfo>>& vec) {

    for(auto & iter : vec)
    {
        print(*iter);
    }

}