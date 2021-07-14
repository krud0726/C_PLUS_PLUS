#include <iostream>
#include "IShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "List.h"

using namespace std;
using namespace shape;
using namespace container;


int main() {
    auto r1 = make_shared<Rectangle>(
            Point{0,0}, Point{0,2}, Point{2,2}, Point{2,0});

    auto t1 = make_shared<Triangle>(
            Point{0,0}, Point{0,2}, Point{2,2});

    auto c1 = make_shared<Circle>( Point{1,1}, 3);

    List<shared_ptr<IShape>, 3> shapes;

    shapes.add(shared_ptr<IShape>{r1});
    shapes.add(shared_ptr<IShape>{t1});
    shapes.add(shared_ptr<IShape>{c1});

    for(const auto& s : shapes){
        if(s == nullptr) continue;
        cout << *s << endl;
    }

    shapes.remove(r1); shapes.remove(c1);

    for(const auto& s : shapes){
        if(s== nullptr) continue;
        cout << *s << endl;
    }
    return 0;
}
