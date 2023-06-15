#pragma once
#include "Polygon.hpp"
#include "Circle.hpp"

class Triangle : public Polygon {
public:
    Triangle() = default;
    Triangle(Point, Point, Point);

    Circle circumscribedCircle();
    Circle inscribedCircle();
    Point centroid();
    Point orthocenter();
    Line EulerLine();
    Circle ninePointsCircle();

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

    ~Triangle() = default;
};