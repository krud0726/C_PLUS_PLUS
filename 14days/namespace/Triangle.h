//
// Created by User on 2021-07-14.
//

#ifndef NS_TRIANGLE_H
#define NS_TRIANGLE_H
#include "IShape.h"

namespace shape{
    class Triangle final : public IShape{
    public:
        Triangle() = default;
        Triangle(const Point &p1, const Point &p2, const Point &p3);

        Triangle(std::vector<Point> &points);

        virtual ~Triangle() noexcept{
            std::cout << "Triangle is destructed!" << std::endl;
        }

        double getPerimeter() const override;
        double getArea() const override;

        std::unique_ptr<IShape> clone() const override;
    };
}
#endif //NS_TRIANGLE_H
