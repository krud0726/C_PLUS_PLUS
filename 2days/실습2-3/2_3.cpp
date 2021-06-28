#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {

    std::array<int, 10> arr;
    for(auto &iter : arr)
        cin >>iter;

    cout<< *std::max_element(begin(arr),end(arr))<<" "<<*std::min_element(begin(arr),end(arr))<<endl;

    return 0;

}
