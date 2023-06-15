#include "Rectangle.hpp"


class Square : public Rectangle {
protected:
    Square() = default;
    Square(Point, Point);
    Circle inscribedCircle() const;
    Circle circumscribedCircle() const;
    double perimeter() override;
    double area() override;
    using Polygon::operator==;
    using Polygon::operator!=;
    using Polygon::isCongruentTo;
    using Polygon::isSimilarTo;
    using Polygon::containsPoint;

    void rotate(Point, double) override;
    void reflex(Point) override;
    void reflex(Line) override;
    void scale(Point, double) override;
    ~Square() = default;
};