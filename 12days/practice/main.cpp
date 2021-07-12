#include <iostream>
#include "IShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include <numeric>

using namespace std;

void doingSomething(const vector<unique_ptr<IShape>>& shapes){
    for(const auto& s : shapes)
        cout << *s << endl;

    double totalArea = accumulate(shapes.cbegin(), shapes.cend(), 0.0,
                                  [](double cur_sum, const auto& rhs){
        return cur_sum+(*rhs).getArea();
    });

    double totalPerimeter = accumulate(shapes.cbegin(), shapes.cend(), 0.0,
                                       [](double cur_sum, const auto& rhs){
        return cur_sum + (*rhs).getPerimeter();
    });

    cout << "totalArea: " << totalArea << ", " << "totalPerimeter: " << totalPerimeter << endl;
}

int main() {
    vector<unique_ptr<IShape>> shapes;

    shapes.emplace_back(
            make_unique<Rectangle>(Point{0, 0}, Point{0, 2}, Point{2, 2}, Point{2, 0}));

    shapes.emplace_back(
            make_unique<Triangle>(Point{0, 0}, Point{0, 2}, Point{2, 2}));

    shapes.emplace_back(
            make_unique<Circle>(Point{1, 1}, 3));
    doingSomething(shapes);
    return 0;
}
