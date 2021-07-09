#include <iostream>
#include "Complex.h"
#include "List.h"
#include "String.h"

using namespace std;

void tc1() {
    List<Complex, 10> cList;
    cList.add(Complex(1,1));
    cList.add(Complex(2,2));

    auto removed_complex = cList.remove(Complex(2,2));
    cout << "removed: " << removed_complex.value_or(0) << "\n";

    auto found_complex = cList.find(Complex(1,1));
    cout << "found: " << found_complex.value_or(0) << '\n';

    cout << "all elements in cList" << endl;
    for(const auto &c : cList)
        cout << c << endl;
}

void tc2() {
    List<String, 10> sList;
    sList.add("abc");
    sList.add("def");

    auto found_string = sList.find("gef");
    cout << "found: " << found_string.value_or("") << "\n";

    found_string = sList.find("def");
    cout << "found: " << found_string.value_or("") << '\n';

    auto removed_string = sList.remove("abc");
    cout << "removed: " << removed_string.value_or("") << "\n";

    cout << "all elements in sList" << endl;
    for (const auto &s : sList) {
        cout << s << endl;
    }
}

int main()
{
    int cmd = 0;
    cin >> cmd;
    switch(cmd){
        case 1:{
            tc1();
            break;
        }
        case 2:{
            tc2();
            break;
        }
    }
}