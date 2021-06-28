#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num1, num2, num3, result;
    int index = 0;

    std::vector<int> v(10);

    cin>>num1;
    cin>>num2;
    cin>>num3;

    result = num1*num2*num3;
    while(result !=0)
    {
        index = result %10;
        v[index] = v[index] +1;
        result =result /10;
    }

    for(int i =0; i<10; i++)
    {
        cout<<v[i]<<endl;
    }

    return 0;
}
