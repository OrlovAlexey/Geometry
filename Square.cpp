#include "Square.hpp"


Square::Square(Point point1, Point point2) {
    vertices[0] = point1;
    vertices[2] = point2;
    double angleRadian = M_PI / 2;
    double cosinus = cos(angleRadian);
    double sinus = sin(angleRadian);
    double x0 = (vertices[0].x + vertices[2].x) / 2;
    double y0 = (vertices[0].y + vertices[2].y) / 2;
    double x1 = ((vertices[0].x - x0) * cosinus - (vertices[0].y - y0) * sinus + x0);
    if (cmp(x1, 0.0)) x1 = 0.0;
    double y1 = ((vertices[0].x - x0) * sinus + (vertices[0].y - y0) * cosinus + y0);
    if (cmp(y1, 0.0)) y1 = 0.0;
    double x2 = ((vertices[2].x - x0) * cosinus - (vertices[2].y - y0) * sinus + x0);
    if (cmp(x2, 0.0)) x2 = 0.0;
    double y2 = ((vertices[2].x - x0) * sinus + (vertices[2].y - y0) * cosinus + y0);
    if (cmp(y2, 0.0)) y2 = 0.0;
    vertices[3] = Point(x1, y1);
    vertices[1] = Point(x2, y2);
}

Circle Square::circumscribedCircle() const {
    return Circle(Point((vertices[0].x + vertices[2].x) / 2, (vertices[0].y + vertices[2].y) / 2), point_distance(vertices[0],vertices[2]));
}

Circle Square::inscribedCircle() const {
    return Circle(Point((vertices[0].x + vertices[2].x) / 2, (vertices[0].y + vertices[2].y) / 2), point_distance(vertices[0], vertices[1]) / 2);
}

double Square::perimeter() {
    return 4 * point_distance(vertices[0], vertices[1]);
}

double Square::area() {
    return point_distance(vertices[0], vertices[1]) * point_distance(vertices[0], vertices[1]);
}

void Square::rotate(Point center, double angle) {
    (*this).Polygon::rotate(center, angle);
}

void Square::reflex(Point center) {
    (*this).Polygon::reflex(center);
}

void Square::reflex(Line axis) {
    (*this).Polygon::reflex(axis);
}

void Square::scale(Point center, double coeff) {
    (*this).Polygon::scale(center, coeff);
}