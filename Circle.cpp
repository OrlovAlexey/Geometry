#include "Circle.hpp"


Circle::Circle(Point center, double radius) {
    f1 = center;
    a = radius;
}

double Circle::radius() const {
    return a;
}

double Circle::perimeter() {
    return 2.0 * M_PI * a;
}

double Circle::area() {
    return M_PI * a * a;
}

bool Circle::operator== (const Shape& shape) const {
    Circle cir;
    try {
        cir = dynamic_cast<const Circle&>(shape);
    } catch (...) {
        return false;
    }
    if (f1 == cir.f1 && cir.a == a) {
        return true;
    }
    return false;
}

bool Circle::operator!= (const Shape& shape) const {
    return !(*this == shape);
}

bool Circle::isCongruentTo(const Shape& shape) {
    Circle cir;
    try {
        cir = dynamic_cast<const Circle&>(shape);
    } catch (...) {
        return false;
    }
    if (cir.a == a) {
        return true;
    }
    return false;
}

bool Circle::isSimilarTo(const Shape& shape) {
    Circle cir;
    try {
        cir = dynamic_cast<const Circle&>(shape);
    } catch (...) {
        return false;
    }
    return true;
}

bool Circle::containsPoint(Point point) {
    if (point_distance(point, f1) <= a) {
        return true;
    }
    return false;
}

void Circle::rotate(Point center, double angle) {
    double angleRadian = angle * M_PI / 180;
    double x0 = center.x;
    double y0 = center.y;
    double x = (f1.x - x0) * cos(angleRadian) - (f1.y - y0) * sin(angleRadian) + x0;
    double y = (f1.x - x0) * sin(angleRadian) + (f1.y - y0) * cos(angleRadian) + y0;
    f1.x = x;
    f1.y = y;
}

void Circle::reflex(Point center) {
    this->scale(center, -1.0);
}

void Circle::reflex(Line axis) {
    f1 = reflect_over_Line(axis, f1);
}

void Circle::scale(Point center, double coeff) {
    double x0 = center.x, y0 = center.y;
    f1.x = x0 + coeff * (f1.x - x0);
    f1.y = y0 + coeff * (f1.y - y0);
    a *= abs(coeff);
}