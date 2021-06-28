#include "shape.h"
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool compare_rec(const unique_ptr<Rectangle>& r1, const unique_ptr<Rectangle>& r2)
{
    return ((*r1).area > (*r2).area);
}

bool compare_cir(const unique_ptr<Circle>& c1, const unique_ptr<Circle>& c2)
{
    return ((*c1).area > (*c2).area);
}


int main() {
    vector<unique_ptr<Rectangle>> rvec;
    vector<unique_ptr<Circle>> cvec;
    double sum = 0;

    while(true)
    {
        string cmd;
        cin >> cmd;

        transform(begin(cmd), end(cmd), begin(cmd), [](char& c){return tolower(c);});
        Command c = getCommand(cmd);

        switch(c){
            case RECT:
                rvec.emplace_back(make_rectangle());
                break;
            case CIRCLE:
                cvec.emplace_back(make_circle());
                break;
            case PRINT:
                for_each(rvec.cbegin(),rvec.cend(),[&](const unique_ptr<Rectangle>& r){
                    cout<< "Rectangle: \t" << (*r).width << "\t"<<(*r).height<<"\t"<< (*r).area << endl;
                });
                for_each(cvec.cbegin(), cvec.cend(), [&](const unique_ptr<Circle>& c){
                    cout<< "Circle: \t" << (*c).radius << "\t"<<(*c).area<< endl;
                });
                break;
            case SUM:
                sum = accumulate(rvec.cbegin(), rvec.cend(), 0.0, [](double sum, const unique_ptr<Rectangle>& r){
                    return sum+(*r).area;
                });
                sum = sum + accumulate(cvec.cbegin(), cvec.cend(), 0.0, [](double sum, const unique_ptr<Circle>& c){
                    return sum+(*c).area;
                });
                cout << sum << endl;
                break;
            case SORT:
                sort(rvec.begin(), rvec.end(), compare_rec);
                sort(cvec.begin(), cvec.end(), compare_cir);
                break;
            case CLEAR:
                rvec.clear();
                cvec.clear();
                break;
            case QUIT:
                return 0;
            case INVALID:
                cout << "Invalid Command"<< "\n";
                break;
        }
    }

}
