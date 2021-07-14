//
// Created by User on 2021-07-14.
//

#ifndef NS_RECTANGLE_H
#define NS_RECTANGLE_H
#include "IShape.h"

namespace shape{
    class Rectangle final : public IShape{
    public:
        Rectangle() = default;

        Rectangle(const Point &p1, const Point &p2, const Point &p3, const Point &p4);

        Rectangle(std::vector<Point> &points);

        virtual ~Rectangle() noexcept{
            std::cout << "Rectangle is destructed!" << std::endl;
        }

        double getPerimeter() const override;
        double getArea() const override;

        std::unique_ptr<IShape> clone() const override;
    };
}
#endif //NS_RECTANGLE_H
