//
// Created by User on 2021-07-14.
//
#include "Circle.h"
using namespace shape;

Circle::Circle(const Point &c, size_t r) : center(c.x, c.y), radius(r) { }
Circle::Circle(const std::vector<Point> &points) : IShape(points) { }

Circle::~Circle() noexcept{
    std::cout << "Circle is destructed!" << std::endl;
}

double Circle::getArea() const {
    return _round((double)radius*(double)radius*M_PI, 2);
}

double Circle::getPerimeter() const {
    return _round(2*M_PI*(double)radius, 2);
}

std::unique_ptr<IShape> Circle::clone() const {
    return std::unique_ptr<IShape>(new Circle(*this));
}

std::string Circle::toString() const {
    std::string str = "type: ";
    str = str + typeid(*this).name() + ", " + "center: " + "(" + std::to_string(center.x) + ", " + std::to_string(center.y) + "), ";

    return str;
}
