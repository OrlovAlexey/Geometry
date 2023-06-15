#include <cmath>


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


