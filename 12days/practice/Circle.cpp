//
// Created by User on 2021-07-12.
//
#include "Circle.h"

Circle::Circle(const Point &c, size_t r) : center(c.x, c.y), radius(r) { }
Circle::Circle(const std::vector<Point> &points) : IShape(points) { }

Circle::~Circle() noexcept {
    std::cout << "Circle is destructed!" << std::endl;
}
double Circle::getArea() const {
    return _round((double)radius*(double)radius*M_PI,2);
}

double Circle::getPerimeter() const {
    return _round(2*M_PI*(double)radius, 2);
}

std::unique_ptr<IShape> Circle::clone() const {
    return std::unique_ptr<IShape>(new Circle(*this));
}

std::string Circle::toString() const {
    std::string str = "type: ";
    str = str + typeid(*this).name() + ", " + "points: ";

    // 기본적으로 <iostream> 헤더파일 내부에 <string>이 내장되어 있다.
    for(const auto& s : points)
        str += "(" + std::to_string(s.x) + ", " + std::to_string(s.y) + "), ";

    return str;

}
