#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector <int> num;
    int SIZE, input;

    cin >> SIZE;

    for(int i=0; i<SIZE; i++)
    {
        cin >>input;
        num.push_back(input);
    }
    sort(num.begin(), num.end());

    for(int i =0; i<SIZE; i++)
    {
        cout<<num[i]<<" ";
    }

    return 0;
}
