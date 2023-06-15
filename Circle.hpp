#pragma once
#include "Ellipse.hpp"

class Circle : public Ellipse {
public:// r = a, c = f1
    Circle() = default;
    Circle(Point, double);

    double radius() const;
    double perimeter() override;
    double area() override;

    bool operator==(const Shape &) const override;
    bool operator!=(const Shape &) const override;

    bool isCongruentTo(const Shape &) override;
    bool isSimilarTo(const Shape &) override;
    bool containsPoint(Point point) override;

    void rotate(Point, double) override;
    void reflex(Point) override;
    void reflex(Line) override;
    void scale(Point, double) override;

    ~Circle() = default;
};