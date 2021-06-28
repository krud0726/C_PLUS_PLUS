#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int SIZE;
    int limit;
    int input;

    cin >> SIZE >> limit;

    vector<int> v(SIZE);
    vector<int>::iterator it = begin(v);

    for_each(v.begin(), v.end(), [&](int num)
    {
       cin >> input;
       *it = input;
       it++;
    });

    it = remove_if(v.begin(), v.end(), [&](int num){
       return num >= limit;
    });
    v.resize(it - v.begin());

    for_each(v.begin(), v.end(), [](int num){
       cout<< num << " ";
    });

    return 0;

}