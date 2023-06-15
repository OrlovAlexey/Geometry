#include "Point.hpp"
#include "Line.hpp"


class Shape {
public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
    virtual bool operator== (const Shape&) const = 0;
    virtual bool operator!= (const Shape&) const = 0;
    virtual bool isCongruentTo(const Shape&) = 0;
    virtual bool isSimilarTo(const Shape&) = 0;
    virtual bool containsPoint(Point point) = 0 ;

    virtual void rotate(Point center, double) = 0;
    virtual void reflex(Point) = 0;
    virtual void reflex(Line) = 0;
    virtual void scale(Point, double) = 0;
    virtual ~Shape() = 0;
};

