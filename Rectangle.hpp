#pragma once
#include "Polygon.hpp"


class Rectangle : public Polygon {
public:
    Rectangle() = default;
    Rectangle(Point, Point, double k);

    Point center() const;
    std::pair<Line, Line> diagonals() const;

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

    ~Rectangle() = default;
};