#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int SIZE;
    int sum = 0;

    cin >> SIZE;

    vector<int> v(SIZE);

    for_each(v.begin(), v.end(), [&](int num){
        sum += SIZE--;
    });

    cout<< sum <<endl;
    return 0;
}