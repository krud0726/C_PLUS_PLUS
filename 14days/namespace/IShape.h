//
// Created by User on 2021-07-14.
//

#ifndef NS_ISHAPE_H
#define NS_ISHAPE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <typeinfo>
#include <memory>
namespace shape{
    struct Point{
        int x = 0;
        int y = 0;

        Point(int _x, int _y) : x(_x), y(_y) { };
    };

    struct IShape{
        IShape() = default;
        IShape(const std::vector<Point> &points);

        virtual ~IShape() noexcept;
        virtual std::unique_ptr<IShape> clone() const = 0;
        virtual double getArea() const = 0;
        virtual double getPerimeter() const = 0;

        friend std::ostream &operator<<(std::ostream &str, const IShape &shape);

    protected:
        virtual std::string toString() const;
        std::vector<Point> points;
    };

    std::ostream &operator<<(std::ostream &os, const IShape &shape);
    double _round(double v, int place);
    double _dist(const Point p1, const Point p2);
}
#endif //NS_ISHAPE_H
