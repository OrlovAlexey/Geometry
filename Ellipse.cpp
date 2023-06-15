#include "Ellipse.hpp"
#include <cmath>

Ellipse::Ellipse(Point focus1, Point focus2, double distance) {
    c = 0.5 * point_distance(focus1, focus2);
    a = 0.5 * distance;
    b = sqrt(a * a - c * c);
    e = c / a;
    f1 = focus1;
    f2 = focus2;
}

pair<Point,Point> Ellipse::focuses() const {
    return make_pair(f1, f2);
}

pair<Line, Line> Ellipse::directrices() const {
    Point center((f1.x + f2.x) / 2, (f1.y + f2.y) / 2);
    Line main_line(f1, f2);
    Point p1(center.x + a/e * cos(main_line.a / main_line.b), center.y + a/e * sin(main_line.a / main_line.b));
    Point p2(center.x - a/e * cos(main_line.a / main_line.b), center.y - a/e * sin(main_line.a / main_line.b));
    Line d1,d2;
    if (!cmp(main_line.a, 0.0)) {
        d1 = Line(p1, -main_line.b / main_line.a);
        d2 = Line(p2, -main_line.b / main_line.a);
    }
    else {
        Point p3(a/e, 0);
        Point p4(a/e, 1);
        d1 = Line(p3, p4);
        Point p5(-a/e, 0);
        Point p6(-a/e, 1);
        d2 = Line(p5, p6);
    }
    return make_pair(d1, d2);
}

double Ellipse::eccentricity() const {
    return e;
}

Point Ellipse::center() const {
    return Point((f1.x + f2.x) / 2, (f1.y + f2.y) / 2);
}

double Ellipse::perimeter() {
//    return 4 * a * std::comp_ellint_2(e);
    return 0;
}

double Ellipse::area() {
    return M_PI * a * b;
}

bool Ellipse::operator== (const Shape& shape) const {
    Ellipse elp;
    try {
        elp = dynamic_cast<const Ellipse&>(shape);
    } catch (...) {
        return false;
    }
    if (cmp(e, elp.e) && cmp(f1.x, elp.f1.x) &&  cmp(f1.y, elp.f1.y) &&  cmp(f2.x, elp.f2.x) &&  cmp(f2.y, elp.f2.y)) {
        return true;
    }
    return false;
}

bool Ellipse::operator!= (const Shape& shape) const {
    return !(*this == shape);
}

bool Ellipse::isCongruentTo(const Shape& shape) {
    Ellipse elp;
    try {
        elp = dynamic_cast<const Ellipse&>(shape);
    } catch (...) {
        return false;
    }
    if (cmp(e, elp.e) && cmp(point_distance(f1, f2), point_distance(elp.f1, elp.f2))) {
        return true;
    }
    return false;
}

bool Ellipse::isSimilarTo(const Shape& shape) {
    Ellipse elp;
    try {
        elp = dynamic_cast<const Ellipse&>(shape);
    } catch (...) {
        return false;
    }
    if (cmp(e, elp.e)) {
        return true;
    }
    return false;
}

bool Ellipse::containsPoint(Point point) {
    if (point_distance(f1, point) + point_distance(f2, point) <= 2 * a) {
        return true;
    }
    return false;
}

void Ellipse::rotate(Point center, double angle) {
    double angleRadian = angle * M_PI / 180;
    double x0 = center.x;
    double y0 = center.y;
    double x1 = (f1.x - x0) * cos(angleRadian) - (f1.y - y0) * sin(angleRadian) + x0;
    double y1 = (f1.x - x0) * sin(angleRadian) + (f1.y - y0) * cos(angleRadian) + y0;
    double x2 = (f2.x - x0) * cos(angleRadian) - (f2.y - y0) * sin(angleRadian) + x0;
    double y2 = (f2.x - x0) * sin(angleRadian) + (f2.y - y0) * cos(angleRadian) + y0;
    f1.x = x1;
    f1.y = y1;
    f2.x = x2;
    f2.y = y2;
}

void Ellipse::reflex(Point center) {
    this->scale(center, -1);
}

void Ellipse::reflex(Line axis) {
    f1 = reflect_over_Line(axis, f1);
    f2 = reflect_over_Line(axis, f2);
}

void Ellipse::scale(Point center, double coeff) {
    double x0 = center.x, y0 = center.y;
    f1.x = x0 + coeff * (f1.x - x0);
    f1.y = y0 + coeff * (f1.y - y0);
    f2.x = x0 + coeff * (f2.x - x0);
    f2.y = y0 + coeff * (f2.y - y0);
    c = point_distance(f1, f2);
    a = abs(coeff) * a;
    b = sqrt(a * a - c * c);
    e = c / a;
}