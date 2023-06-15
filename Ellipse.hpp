#pragma once
#include "Point.hpp"
#include "Line.hpp"
#include "Shape.hpp"

#include <cmath>
#include <iostream>
#include <utility>

using std::pair;
using std::make_pair;


class Ellipse : public Shape {
protected:// a, b - полуоси; с = sqrt(a^2 + b^2); e - эксцентриситет
    double a, b, c, e;// Что это (имена), и почему в public?
    Point f1, f2;// так просто формулы было легче писать
public:
    Ellipse() = default;
    Ellipse(Point, Point, double);
    std::pair<Point,Point> focuses() const;
    std::pair<Line, Line> directrices() const;

    double eccentricity() const;
    Point center() const;
    double perimeter() override;
    double area() override;
    bool operator== (const Shape&) const override;
    bool operator!= (const Shape&) const override;
    bool isCongruentTo(const Shape&) override;
    bool isSimilarTo(const Shape&) override;
    bool containsPoint(Point point) override;

    void rotate(Point, double) override;
    void reflex(Point) override;
    void reflex(Line) override;
    void scale(Point, double) override;
    ~Ellipse() = default;
};
