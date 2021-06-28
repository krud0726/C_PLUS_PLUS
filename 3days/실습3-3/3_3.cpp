#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector <int> num;
    int SIZE, input, position, n;

    cin >>SIZE;

    for(int i=0; i<SIZE; i++)
    {
        cin >> input;
        num.push_back(input);
    }

    cin >> position >> n;

    num.erase(num.begin()+position);
    auto it = remove(num.begin(), num.end(), n);
    num.resize(it - num.begin());

    cout<<num.size()<<endl;
    for(int i = 0; i<num.size(); i++)
    {
        cout<< num[i] << " ";
    }

    return 0;
}
