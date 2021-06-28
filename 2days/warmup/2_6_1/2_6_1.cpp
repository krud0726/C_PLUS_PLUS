#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int SIZE;
    int num;

    cin >> SIZE;

    vector<int> vec;

    for(int i =0; i<SIZE; i++)
    {
        cin >> num;
        vec.push_back(num);
    }
    cout<< *std::min_element(vec.begin(),vec.end())<< " "<< *std::max_element(vec.begin(), vec.end());
    return 0;
}
