#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int size;
    int count;
    int sum;

    string str;

    cin >> size;

    vector <int> score(size);
    vector <string> v(size);

    for(int i =0; i<size; i++)
    {
        sum =0;
        count = 0;
        cin >> v[i];

        int length = v[i].length();

        for(int j=0; j<length; j++)
        {
            if(v[i][j] == 'O')
            {
                count = count+1;
            }
            else
            {
                count =0;
            }
            sum = sum+count;
        }
        score[i] = sum;
    }

    for(int i = 0; i<size; i++)
    {
        cout<< score[i]<<endl;
    }

    return 0;
}
