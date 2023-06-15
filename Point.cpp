#include "Point.hpp"


bool cmp(double a, double b) {
    double eps = 1e-6;
    return abs(a - b) <= eps;
}


Point::Point(double X, double Y) : x(X), y(Y) {}

bool Point::operator== (const Point& point) const {
    if (cmp(point.x, x) && cmp(point.y, y)) {
        return true;
    }
    return false;
}

bool Point::operator!= (const Point& point) const {
    return !(*this == point);
}

double point_distance(Point point1, Point point2) {
    double x1, x2, y1, y2;
    x1 = point1.x;
    x2 = point2.x;
    y1 = point1.y;
    y2 = point2.y;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}