//
// Created by User on 2021-07-12.
//

#include "IShape.h"
#include <iostream>

using namespace std;

IShape::IShape(const std::vector<Point>& points) : points(points) {}

IShape::~IShape() noexcept {
    std::cout << "IShape is destructed!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const IShape& shape){
    std::cout << shape.toString() << "area: " << shape.getArea() << ", perimeter: " << shape.getPerimeter();
    return os;
}

double _round(double v, int place){
    const int adj = std::pow(10, place);
    return std::floor(v*(adj)+0.5)/adj;
};

double _dist(const Point p1, const Point p2){
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
};

std::string IShape::toString() const {
    std::string str = "";
    str = str + "type: " + typeid(*this).name() + ", ";
    str = str + "points: ";

    for(const auto& s : points)
        str = str + "(" + to_string(s.x) + ", " + to_string(s.y) + "), " ;

    return str;
}