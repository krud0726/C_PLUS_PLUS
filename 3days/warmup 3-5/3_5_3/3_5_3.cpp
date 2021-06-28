#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int input, ten, one, result;
    int cycle = 0;
    int temp;

    string str1;
    string str2;

    cin >> input;
    temp = input;

    while((input != temp) || (cycle == 0))
    {
        ten = input / 10;
        one = input % 10;

        result = ten + one;

        str1 = to_string(one);
        str2 = to_string((result % 10));
        str1 += str2;

        input = stoi(str1);
        cycle++;
    }

    cout << cycle <<endl;
    return 0;

}