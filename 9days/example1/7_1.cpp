#include <iostream>
#include <string>
#include <map>
#include <initializer_list>
#include <utility>

using namespace std;

class Phonebook{
    map<string, int> contacts;
public:
    Phonebook(initializer_list<pair<const string, int>> lst) :contacts(lst) {}

    void print() const{
        for(const auto it : contacts)
        {
            cout << it.first << " " << it.second <<endl;
        }
    }
};

int main() {
    Phonebook p = {{"Kim", 24}, {"Lee", 21}};
    p.print();
    return 0;
}
