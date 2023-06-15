#pragma once
#include "Point.hpp"
#include "Line.hpp"
#include "Shape.hpp"

#include <vector>

using std::vector;
using std::initializer_list;
using std::pair;


class Polygon : public Shape {
protected:
    vector<Point> vertices;
public:
    Polygon() = default;
    Polygon(const vector<Point>&);
    Polygon(initializer_list<Point>);
    int verticesCount() const;
    const vector<Point> getVertices();
    bool isConvex() const;
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
    ~Polygon() = default;
};

double get_angle(Point a, Point b, Point c);