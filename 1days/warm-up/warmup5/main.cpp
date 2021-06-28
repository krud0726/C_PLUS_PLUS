#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cin >> num1;
    cin >> num2;

    cout<<num1*(num2%10) <<endl;
    cout<<num1*((num2%100)/10)<<endl;
    cout<<num1*(num2/100)<<endl;
    cout<<num1*num2<<endl;
    return 0;
}
