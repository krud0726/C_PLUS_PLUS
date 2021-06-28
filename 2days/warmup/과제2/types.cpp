#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string button;
    int i_count = 0;
    int l_count = 0;
    int f_count = 0;
    int d_count = 0;

    while(cin>>button)
    {
        transform(button.begin(), button.end(), button.begin(), ::tolower);

        if(!button.compare("int"))
        {
            i_count++;
            cout<<numeric_limits<int>::max() <<" ";
            cout<<numeric_limits<int>::min() <<endl;
        }
        else if(!button.compare("long"))
        {
            l_count++;
            cout<<numeric_limits<long long>::max() <<" ";
            cout<<numeric_limits<long long>::min() <<endl;
        }
        else if(!button.compare("float"))
        {
            f_count++;
            cout<<numeric_limits<float>::max() <<" ";
            cout<<numeric_limits<float>::min() <<endl;
        }
        else if(!button.compare("double"))
        {
            d_count++;
            cout<<numeric_limits<double>::max() <<" ";
            cout<<numeric_limits<double>::min() <<endl;
        }
        else if(!button.compare("quit"))
        {
            break;
        }
        else
        {
            cout<<"Invalid Command"<<endl;
        }
    }
    cout<<"=== the number of types ==="<<endl;
    cout<<"int: "<<i_count<<endl;
    cout<<"long: "<<l_count<<endl;
    cout<<"float: "<<f_count<<endl;
    cout<<"double: "<<d_count<<endl;
    return 0;
}