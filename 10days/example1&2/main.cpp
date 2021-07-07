#include "my_vector.h"
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    my_vector<int> vec = {1,2,3,4,5};
    my_vector<int> vec2(vec);

    *(vec2.begin()) = 50;

    for(const auto& it : vec2)
        cout << it << " ";

    cout << '\n';

    cout << (my_accumulate(vec2.begin(), vec2.end(), 0) == accumulate(vec2.begin(), vec2.end(), 0)) << '\n';
    return 0;
}
