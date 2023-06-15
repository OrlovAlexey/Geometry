#pragma once
#include "Point.hpp"


// ax  + by + c = 0
class Line {
public:
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    Line() = default;
    Line(const Point&, const Point&);
    Line(double, double);
    Line(const Point&, double);
    bool operator== (const Line&) const;
    bool operator!= (const Line&) const;
    ~Line() = default;
};

Point intersect(Line line1, Line line2);

Point reflect_over_Line(Line line, Point point);

