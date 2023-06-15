#include "Line.hpp"


Line::Line(const Point& point1, const Point& point2) {
    a = point1.y - point2.y;
    b = point2.x - point1.x;
    c = (point1.x * point2.y) - (point2.x * point1.y);
}

Line::Line(double coeff_k, double coeff_b) {
    a = (cmp(coeff_k, 0.0) ? 0.0 : -coeff_k);
    b = 1.0;
    c = (cmp(coeff_b, 0.0) ? 0.0 : -coeff_b);
}

Line::Line(const Point& point, double coeff_k) {
    a = (cmp(coeff_k, 0.0) ? 0 : -coeff_k);
    b = 1.0;
    c = -(a * point.x) - (b * point.y);
}

bool Line::operator== (const Line& line) const {
    double ratio_a, ratio_b, ratio_c;
    bool special_case_a = false, special_case_b = false, special_case_c = false;
    if (!cmp(line.a, 0.0)) {
        ratio_a = this->a / line.a;
    }
    else {
        if (!cmp(this->a, 0.0)) {
            return false;
        }
        special_case_a = true;
    }
    if (!cmp(line.b, 0.0)) {
        ratio_b = this->b / line.b;
    }
    else {
        if (!cmp(this->b, 0.0)) {
            return false;
        }
        special_case_b = true;
    }
    if (!cmp(line.c, 0.0)) {
        ratio_c = this->c / line.c;
    }
    else {
        if (!cmp(this->c, 0.0)) {
            return false;
        }
        special_case_c = true;
    }
    if (special_case_a) {
        ratio_a = ratio_b;
    }
    if (special_case_b) {
        ratio_b = ratio_a;
    }
    if (special_case_c) {
        ratio_c = ratio_a;
    }
    if (special_case_c && special_case_a) {
        ratio_c = ratio_b;
    }

    if (cmp(ratio_a, ratio_b) && cmp(ratio_b, ratio_c)) {
        return true;
    }
    return false;
}

bool Line::operator!= (const Line& line) const {
    return !(*this == line);
}

Point intersect(Line line1, Line line2) {
    Point result;
    double a1, a2, b1, b2, c1, c2;
    a1 = line1.a;
    b1 = line1.b;
    c1 = line1.c;
    a2 = line2.a;
    b2 = line2.b;
    c2 = line2.c;
    double det = a1 * b2 - a2 * b1;
    if (!cmp(det, 0.0)) {
        result.x = cmp((b1 * c2 - b2 * c1) / det, 0.0) ? 0.0 : (b1 * c2 - b2 * c1) / det;
        result.y = cmp((a2 * c1 - a1 * c2) / det, 0.0) ? 0.0 : (a2 * c1 - a1 * c2) / det;
        return result;
    }
    return Point(1000000001, 1000000001);
}