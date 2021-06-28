#include <iostream>
#include <vector>

using namespace std;

int main() {
    int SIZE;
    int QUESTION;

    cin >> SIZE>>QUESTION;

    std::vector<std::vector<int>> vec(SIZE);
    std::vector<int> vec2;

    for(int i=0; i<SIZE; i++)
    {
        int size_1d;
        int num;

        cin >>size_1d;

        for(int j=0; j<size_1d; j++)
        {
            cin >>num;
            vec[i].push_back(num);
        }
    }

    for(int m =0; m<QUESTION; m++)
    {
        int row,col;
        cin >> row>> col;
        vec2.push_back(vec[row][col]);
    }

    for(int k=0; k<vec2.size(); k++)
    {
        cout<<vec2[k]<<endl;
    }

    return 0;

}
