//
// Created by User on 2021-07-14.
//

#ifndef NS_CIRCLE_H
#define NS_CIRCLE_H
#include "IShape.h"

namespace shape{
    class Circle final : public IShape{
    public:
        Circle() = default;

        Circle(const Point &c, size_t r);

        explicit Circle(const std::vector<Point> &points);

        virtual ~Circle() noexcept;

        double getArea() const override;

        double getPerimeter() const override;

        virtual std::unique_ptr<IShape> clone() const;

    protected:
        std::string toString() const override;

    private:
        Point center = {0, 0};
        size_t radius = 0;
    };
}
#endif //NS_CIRCLE_H
