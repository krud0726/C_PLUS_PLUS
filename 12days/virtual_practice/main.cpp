#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;


class vehicle{
public:
    vehicle() : speed(0) { };

    void setSpeed(int sp)
    {
        speed += sp;
    }
    int GetSpeed() {
        return speed;
    }

    virtual void acclerate(){ }

private:
    int speed;
};

class GV70 : public vehicle{
public:
    GV70() : vehicle() { };

    void acclerate(){
        setSpeed(30);
        cout << "The speed of the gv70 has increased by " << GetSpeed() << " km/h."<<endl;
    }
    void brake(){
        setSpeed(-30);
        cout << "The speed of the gv70 has decreased by " << GetSpeed() << " km/h."<<endl;
    }
};

class Grandeur : public vehicle{
public:
    Grandeur() : vehicle() { };

    void acclerate(){
        setSpeed(20);
        cout << "The speed of the grandeur has increased by " << GetSpeed() << " km/h."<<endl;
    }
    void brake(){
        setSpeed(-20);
        cout << "The speed of the grandeur has decreased by " << GetSpeed() << " km/h."<<endl;
    }
};


class Carnibal : public vehicle{
public:
    Carnibal() : vehicle() { };

    void acclerate(){
        setSpeed(10);
        cout << "The speed of the carnibal has increased by " << GetSpeed() << " km/h."<<endl;
    }
    void brake(){
        setSpeed(-10);
        cout << "The speed of the carnibal has decreased by " << GetSpeed() << " km/h."<<endl;
    }
};

unique_ptr<vehicle> make_vehicle() {
    std::string choice;
    cin >> choice;

    if(choice == "gv70") return make_unique<GV70>();
    else if (choice == "grandeur") return make_unique<Grandeur> ();
    else if (choice == "carnibal") return make_unique<Carnibal> ();
    else return make_unique<GV70>();
}



int main() {
    std::vector<unique_ptr<vehicle>> test_vehicles;

    test_vehicles.push_back(make_vehicle()); // gv70
    test_vehicles.push_back(make_vehicle()); // grandeur
    test_vehicles.push_back(make_vehicle()); // carnibal

    for(auto& v : test_vehicles)
        (*v).acclerate();

}
