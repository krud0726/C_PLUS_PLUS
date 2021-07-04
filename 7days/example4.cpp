#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

enum Command {
        ADD,
        DEL,
        MOD,
        FIN,
        QUI
};
class Person{
public:
    Person() {}
    Person(string name, string number) : name(name), number(number) {}

    void modifyNumber(string na, string num);
    void print() const;
private:
    string name;
    string number;

};

void print(const pair<string, Person>& p);


int main() {
    int num;
    string name;
    string phone;
    map<std::string, Person> persons;
    map<std::string, Command> cmd ={
            {"add", ADD}, {"del", DEL}, {"mod", MOD},
            {"fin", FIN}, {"qui", QUI}
    };

    cin >> num;

    generate_n(inserter(persons, persons.begin()), num, [&](){
        cin >> name >> phone;
        Person p(name, phone);
        pair<string, Person> in = pair<string, Person> {name, p};
        return in;
    });

    while(true)
    {
        string input;
        cin >> input;
        Command c;

        transform(begin(input), end(input), begin(input), [](char& c){return tolower(c); });
        c = cmd[input];

        switch(c)
        {
            case ADD:{
                cin >> name >> phone;
                Person p{name, phone};
                pair<string, Person> ad = pair<string, Person> {name, p};
                if(!persons.count(name))
                    persons.insert(ad);
                break;
            }
            case DEL:{
                cin >> name;
                persons.erase(name);
                break;
            }
            case MOD:{
                cin >> name >> phone;
                auto find_it = persons.find(name);
                if(find_it != persons.end())
                {
                    find_it->second.modifyNumber(name, phone);
                }
                break;
            }
            case FIN:{
                cin >> name;
                auto find_it = persons.find(name);
                if(find_it != persons.end())
                {
                    find_it->second.print();
                }
                break;
            }
            case QUI:
                for_each(persons.begin(), persons.end(), print);
                return 0;
            default:
                cout<<"Invalid Command"<<endl;
        }
    }


}

void Person::modifyNumber(const std::string na, const std::string num) {
    name = na;
    number = num;
}

void Person::print() const {
    cout << name << " " << number <<endl;
}

void print(const pair<string, Person>& p)
{
   p.second.print();
}
