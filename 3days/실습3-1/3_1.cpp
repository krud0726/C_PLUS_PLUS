#include <iostream>
#include <memory>

using namespace std;

void update(unique_ptr<int> &a, unique_ptr<int> &b);

int main(void)
{
    unique_ptr<int> num1 {new int{}};
    unique_ptr<int> num2 {new int{}};

    cin >> *num1 >> *num2;

    update(num1, num2);

    cout<< *num1 <<endl;
    cout<< *num2 <<endl;

    return 0;
}

void update(unique_ptr<int> &a, unique_ptr<int> &b)
{
    int temp = *a;
    *a = temp + *b;
    *b = temp - *b;
}
