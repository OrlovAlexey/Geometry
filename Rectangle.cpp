#include "Rectangle.hpp"


Rectangle::Rectangle(Point point1, Point point2, double k) {
    vertices[0] = point1;
    vertices[2] = point2;

    Line h(vertices[0], vertices[2]);
    double another_k1 = tan(atan(k) + atan(-h.a / h.b));
    Line l1(vertices[0], another_k1);
    Line l2;
    if (!cmp(another_k1, 0.0)) {
        l2 = Line(vertices[2], -1.0 / another_k1);
    }
    else {
        l2 = Line(Point(vertices[2].x, 0), Point(vertices[2].x, 1));
    }
    vertices[1] = intersect(l1, l2);

    double another_k2 = tan(atan(-h.a / h.b) - atan(1.0/k));
    Line l3(vertices[0], another_k2);
    Line l4;
    if (!cmp(another_k2, 0.0)) {
        l4 = Line(vertices[2], -1.0 / another_k2);
    }
    else {
        l4 = Line(Point(vertices[2].x, 0), Point(vertices[2].x, 1));
    }
    vertices[3] = intersect(l3, l4);

}

Point Rectangle::center() const {
    return Point((vertices[0].x + vertices[2].x) / 2, (vertices[0].y + vertices[2].y) / 2);
}

std::pair<Line, Line> Rectangle::diagonals() const {
    return pair(Line(vertices[0], vertices[2]),Line(vertices[1], vertices[3]));
}

double Rectangle::perimeter() {
    return 2.0 * (point_distance(vertices[0],vertices[1]) + point_distance(vertices[1], vertices[2]));
}

double Rectangle::area() {
    return point_distance(vertices[0],vertices[1]) * point_distance(vertices[1], vertices[2]);
}

void Rectangle::rotate(Point center, double angle) {
    (*this).Polygon::rotate(center, angle);
}

void Rectangle::reflex(Point center) {
    (*this).Polygon::reflex(center);
}

void Rectangle::reflex(Line axis) {
    (*this).Polygon::reflex(axis);
}

void Rectangle::scale(Point center, double coeff) {
    (*this).Polygon::scale(center, coeff);
}