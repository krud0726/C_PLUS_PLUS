//
// Created by User on 2021-07-14.
//

#include "Triangle.h"

using namespace shape;
Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3) {
    IShape::points.push_back(p1);
    IShape::points.push_back(p2);
    IShape::points.push_back(p3);
}

Triangle::Triangle(std::vector<Point> &points) : IShape(points) { }

double Triangle::getPerimeter() const {
    double a = _dist(IShape::points[0], IShape::points[1]);
    double b = _dist(IShape::points[0], IShape::points[2]);
    double c = _dist(IShape::points[1], IShape::points[2]);

    return (a+b+c);
}

double Triangle::getArea() const {
    double a = _dist(IShape::points[0], IShape::points[1]);
    double b = _dist(IShape::points[0], IShape::points[2]);
    double c = _dist(IShape::points[1], IShape::points[2]);

    double s = (a+b+c) / 2;
    s = sqrt(s*(s-a)*(s-b)*(s-c));

    return s;
}

std::unique_ptr<IShape> Triangle::clone() const {
    return std::unique_ptr<IShape>(new Triangle(*this));
}

