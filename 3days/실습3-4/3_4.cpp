#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> count(26);
    int index;
    string word;

    cin >> word;

    for(int i=0; i<word.size(); i++)
    {
        index = word[i] - 'a';

        if(count[index] == 0)
        {
            count[index] = word.find(word[i])+1;
        }
    }

    for(int i=0; i<26; i++)
    {
        cout<< count[i] <<" ";
    }

    return 0;
}
