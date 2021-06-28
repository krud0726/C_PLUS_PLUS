#include <iostream>

using namespace std;

int main() {

    int SIZE = 0;
    int index = 0;
    cin >> SIZE;

    int *arr = new int[SIZE];

    for(int i=0; i<SIZE; i++)
    {
        cin >> arr[i];
    }

    cin >> index;

    cout << arr[arr[index]] <<endl;

    delete [] arr;

    return 0;


}
