#include "Triangle.hpp"


Triangle::Triangle(Point point1, Point point2, Point point3) {
    vertices[0] = point1;
    vertices[1] = point2;
    vertices[2] = point3;
}

Circle Triangle::circumscribedCircle() {
    double side1 = point_distance(vertices[0], vertices[1]);
    double side2 = point_distance(vertices[1], vertices[2]);
    double side3 = point_distance(vertices[2], vertices[0]);
    double radius = 0.25 * side1 * side2 * side3 / area();
    double x1 = vertices[0].x, x2 = vertices[1].x, x3 = vertices[2].x, y1 = vertices[0].y, y2 = vertices[1].y, y3 = vertices[2].y;
    double det = x1 * (y2 - y3) - y1 * (x2 - x3) + (x2 * y3 - x3 * y2);
    double det1 = (x1 * x1 + y1 * y1) * (y2 - y3) - y1 * (x2 * x2 + y2 * y2 - x3 * x3 - y3 * y3) + ((x2 * x2 + y2 * y2) * y3 - (x3 * x3 + y3 * y3) * y2);
    double det2 = x1 * (x2 * x2 + y2 * y2 - x3 * x3 - y3 * y3) - (x1 * x1 + y1 * y1) * (x2 - x3) + (x2 * (x3 * x3 + y3 * y3) - x3 * (x2 * x2 + y2 * y2));
    Point center(0.5 * det1 / det, 0.5 * det2 / det);
    return Circle(center, radius);
}

Circle Triangle::inscribedCircle() {
    double radius = 2 * area() / perimeter();
    double C = point_distance(vertices[0], vertices[1]);
    double A = point_distance(vertices[1], vertices[2]);
    double B = point_distance(vertices[2], vertices[0]);
    Point center ((A * vertices[0].x + B * vertices[1].x + C * vertices[2].x) / (A + B + C), (A * vertices[0].y + B * vertices[1].y + C * vertices[2].y) / (A + B + C));
    return Circle(center, radius);
}

Point Triangle::centroid() {
    return Point((vertices[0].x + vertices[1].x + vertices[2].x) / 3, (vertices[0].y + vertices[1].y + vertices[2].y) / 3);
}

Point Triangle::orthocenter() {
    Line l1(vertices[0], vertices[1]);
    Line l2(vertices[1], vertices[2]);
    Line p1;
    if (!cmp(l2.a, 0.0)) {
        p1 = Line(vertices[0], l2.b / l2.a);
    }
    else {
        p1 = Line(Point(vertices[0].x, 0.0), Point(vertices[0].x, 1.0));
    }
    Line p2;
    if (!cmp(l1.a, 0.0)) {
        p2 = Line(vertices[2], l1.b / l1.a);
    }
    else {
        p2 = Line(Point(vertices[2].x, 0.0), Point(vertices[2].x, 1.0));
    }
    return intersect(p1, p2);
}

Line Triangle::EulerLine() {
    return Line(orthocenter(), circumscribedCircle().center());
}

Circle Triangle::ninePointsCircle() {
    Point o1 = orthocenter();
    Point o2 = circumscribedCircle().center();
    Point center((o1.x + o2.x) / 2, (o1.y + o2.y) / 2);
    Point mid((vertices[0].x + vertices[1].x) / 2, (vertices[0].y + vertices[1].y) / 2);
    return Circle(center, point_distance(center, mid));
}

double Triangle::perimeter() {
    double side1 = point_distance(vertices[0], vertices[1]);
    double side2 = point_distance(vertices[1], vertices[2]);
    double side3 = point_distance(vertices[2], vertices[0]);
    return side1 + side2 + side3;
}

double Triangle::area() {
    double side1 = point_distance(vertices[0], vertices[1]);
    double side2 = point_distance(vertices[1], vertices[2]);
    double side3 = point_distance(vertices[2], vertices[0]);
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

void Triangle::rotate(Point center, double angle) {
    (*this).Polygon::rotate(center, angle);
}

void Triangle::reflex(Point center) {
    (*this).Polygon::reflex(center);
}

void Triangle::reflex(Line axis) {
    (*this).Polygon::reflex(axis);
}

void Triangle::scale(Point center, double coeff) {
    (*this).Polygon::scale(center, coeff);
}