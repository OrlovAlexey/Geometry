#pragma once
#include <cmath>


bool cmp(double a, double b);

class Point {
public:
    double x;
    double y;
    Point() : x(0), y(0) {}
    Point(double, double);
    bool operator== (const Point&) const;
    bool operator!= (const Point&) const;
    ~Point() = default;
};

double point_distance(Point point1, Point point2);

