#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
void print(const pair<string, string>& p)
{
    cout << p.first << " " << p.second <<endl;
}
enum Command { ADD, DEL, MOD, FIN, QUI};

int main() {

    int SIZE;
    string name, num;
    map<std::string, Command> m;
    map<std::string, std::string> phone;

    m["add"] = Command::ADD;
    m["del"] = Command::DEL;
    m["mod"] = Command::MOD;
    m["fin"] = Command::FIN;
    m["qui"] = Command::QUI;

    cin >> SIZE;

    generate_n(inserter(phone, phone.begin()), SIZE, [&]()
    {
        string n, p;
        cin >> n;
        cin >> p;
        return make_pair(n, p);
    });

    while(true)
    {
        string cmd;
        cin >> cmd;

        transform(begin(cmd), end(cmd), begin(cmd), [](char &c) { return tolower(c);});

        Command c = m[cmd];
        switch(c){
            case ADD: {
                cin >> name >> num;
                if (!phone.count(name))
                    auto add = phone.insert({name, num});
                break;
            }
            case DEL: {
                cin >> name;
                phone.erase(name);
                break;
            }
            case MOD:{
                cin >> name >> num;
                auto find_it = phone.find(name);
                if(find_it != phone.end())
                    phone[name] = num;
                break;
            }
            case FIN: {
                cin >> name;
                auto f = phone.find(name);
                if (f != phone.end())
                    cout << f->first << " " << f->second << endl;
                break;
            }
            case QUI:
            {
                for_each(phone.begin(), phone.end(), print);
                return 0;
            }
        }
    }

}
