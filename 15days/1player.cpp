#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class FootballPlayer{
public:
    FootballPlayer(std::string  name, long salary) : name(std::move(name)), salary(salary) {}
    virtual ~FootballPlayer() noexcept {}

    long getSalary() const{ return salary; }
    string getName() const{ return name; }

    virtual long getBonus() const = 0;
    virtual std::string print() const{
        std::string str = getName();
        str += " (" + to_string(getSalary()) + ", " + to_string(getBonus()) + ")";
        return str;
    }

    friend std::ostream& operator<<(std::ostream& str, const FootballPlayer& player);

private:
    string name;
    long salary;
};

class Foward final : public FootballPlayer{
public:
    Foward() = default;
    Foward(const std::string& name, long salary) : FootballPlayer(name, salary) { }
    virtual ~Foward() noexcept{
        std::cout << "Forward " << FootballPlayer::print() << " is destroyed!" << std::endl;
    }
    long getBonus() const override{
        return (long)(getSalary() * 0.2);
    }

    std::string print() const override{
        std::string str = "Forward: ";
        str += getName() + " (" + to_string(getSalary()) + ", " + to_string(getBonus()) + ")";
        return str;
    }
};

class Goalkeeper final : public FootballPlayer{
public:
    Goalkeeper() = default;
    Goalkeeper(const std::string& name, long salary) : FootballPlayer(name, salary) { }
    virtual ~Goalkeeper() noexcept{
        std::cout << "Goalkeeper " << FootballPlayer::print() << " is destroyed!" << std::endl;
    }

    long getBonus() const override{
        return (long)(getSalary() * 0.1);
    }

    std::string print() const override{
        std::string str = "Goalkeepr: ";
        str += getName() + " (" + to_string(getSalary()) + ", " + to_string(getBonus()) + ")";
        return str;
    }

};

int main() {
    vector<unique_ptr<FootballPlayer>> players;
    bool done = true;

    while(done){
        char command;
        cin >> command;

        switch(command){
            case 'f':
            case 'F':{
                string name; long salary;
                cin >> name >> salary;
                players.emplace_back(make_unique<Foward>(name, salary));
                break;
            }
            case 'g':
            case 'G':{
                string name; long salary;
                cin >> name >> salary;
                players.emplace_back(make_unique<Goalkeeper>(name, salary));
                break;
            }
            default:{
                done = false;
                break;
            }
        }

    }
    long totalIncome = 0;
    for(const auto& person : players){
        totalIncome += (*person).getSalary() + (*person).getBonus();
        cout << *person << endl;
    }

    cout << "Total Income: " << totalIncome << endl;
    return 0;
}


std::ostream& operator<<(std::ostream& str, const FootballPlayer& player){
    std::cout << player.print();
    return str;
}
