//
// Created by User on 2021-07-12.
//

#include "Rectangle.h"

Rectangle::Rectangle(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    IShape::points.push_back(p1);
    IShape::points.push_back(p2);
    IShape::points.push_back(p3);
    IShape::points.push_back(p4);
}

Rectangle::Rectangle(std::vector<Point> &points) : IShape(points) { }


double Rectangle::getPerimeter() const {
    double width = _dist(IShape::points[0], IShape::points[3]);
    double height = _dist(IShape::points[0], IShape::points[1]);

    return _round(2*(width+height), 2);
}

double Rectangle::getArea() const {
    double width = _dist(IShape::points[0] , IShape::points[3]);
    double height = _dist(IShape::points[0], IShape::points[1]);

    return _round(width*height, 2);
}

std::unique_ptr<IShape> Rectangle::clone() const {
    return std::unique_ptr<IShape>(new Rectangle(*this));
}

