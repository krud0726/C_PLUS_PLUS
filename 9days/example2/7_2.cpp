#include <iostream>

using namespace std;

class complex{
public:
    complex(double real=0, double imaginary =0) : r(real), i(imaginary) {};

    complex operator+(const complex& c)
    {
        r = r + c.r;
        i = i + c.i;
        return complex(r,i);
    }

    friend ostream& operator<<(ostream& os, const complex& c);
private:
    double r{0}, i{0};
};

ostream& operator<<(ostream& os, const complex& c)
{
    os << c.r << " + " << c.i << "i";
    return os;
}

int main() {
    complex c1(1,1), c2(2,2);
    complex c3(c1);

    cout << c3 <<endl;

    complex c4 = c1 + c2;
    cout << c4 <<endl;

    return 0;
}
