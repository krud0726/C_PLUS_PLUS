#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int N,X;
    cin >> N >> X;

    vector<int> num;

    generate_n(back_inserter(num), N, [](){return *(istream_iterator<int>{cin});});

    ostream_iterator<int> ost(cout, " ");
    copy_if(begin(num), end(num), ost, [=](int i){return i < X;});


    return 0;
}
