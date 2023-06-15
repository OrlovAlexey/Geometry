#include "Polygon.hpp"


Polygon::Polygon(const vector<Point>& points) {
    int size = points.size();
    vertices.resize(size);
    for (int i = 0; i < size; ++i) {
        vertices[i] = points[i];
    }
}

Polygon::Polygon(initializer_list<Point> lst) {
    int size = lst.size();
    vertices.resize(size);
    std::copy(lst.begin(), lst.end(), vertices.begin());
}

int Polygon::verticesCount() const {
    return vertices.size();
}

const vector<Point> Polygon::getVertices() {
    return vertices;
}

bool Polygon::isConvex() const {
    int i, j, k;
    int size = vertices.size();
    double cross_product;
    int flag = 0;

    if (size < 3) {
        return false;
    }
    for (i = 0; i < size; ++i) {
        j = (i + 1) % size;
        k = (i + 2) % size;
        cross_product = (vertices[j].x - vertices[i].x) * (vertices[k].y - vertices[j].y);
        cross_product -= (vertices[j].y - vertices[i].y) * (vertices[k].x - vertices[j].x);
        if (cross_product < 0) {
            flag |= 1;
        }
        else if (cross_product > 0) {
            flag |= 2;
        }
        if (flag == 3) {
            return false;
        }
    }
    if (flag != 0)
        return true;
    else
        return false;
}

double Polygon::perimeter() {
    double result = 0.0;
    int size = vertices.size();
    for (int i = 1; i < size + 1; ++i) {
        result += point_distance(vertices[i-1], vertices[i % size]);
    }
    return result;
}

double Polygon::area() {
    double result = 0.0;
    int size = vertices.size();
    for (int i = 0; i < size; ++i) {
        result += vertices[i].x * vertices[(i+1) % size].y;
        result -= vertices[(i+1) % size].x * vertices[i].y;
    }
    return 0.5 * abs(result);
}

bool Polygon::operator== (const Shape& shape) const {
    Polygon poly;
    try {
        poly = dynamic_cast<const Polygon&>(shape);
    } catch (...) {
        return false;
    }
    int size1 = vertices.size();
    int size2 = poly.vertices.size();
    if (size1 != size2) {
        return false;
    }
    bool flag;
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = 0; j < size2; ++j) {
            if (vertices[(i+j) % size1] != poly.vertices[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = size2-1; j >= 0; --j) {
            if (vertices[(i - j + size1) % size1] != poly.vertices[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

bool Polygon::operator!= (const Shape& shape) const {
    return !(*this == shape);
}

double get_angle( Point a, Point b, Point c )
{
    Point ab(b.x - a.x, b.y - a.y);
    Point cb(b.x - c.x, b.y - c.y);
    double dot = (ab.x * cb.x + ab.y * cb.y);
    double cross = (ab.x * cb.y - ab.y * cb.x);
    double alpha = atan2(cross, dot);
    return alpha * 180. / M_PI;
}

bool Polygon::isCongruentTo(const Shape& shape) {
    Polygon poly;
    try {
        poly = dynamic_cast<const Polygon &>(shape);
    } catch (...) {
        return false;
    }
    vector<pair<double, pair<double, double>>> sides1, sides2; // side + cosine + sinus with sign

    int size1 = this->vertices.size();
    int size2 = poly.vertices.size();
    if (size1 != size2) {
        return false;
    }

    sides1.clear();
    sides1.resize(size1);
    for (int i = 0; i < size1; ++i) {
        double angle = get_angle(vertices[i], vertices[(i + 1) % size1], vertices[(i + 2) % size1]);
        sides1.push_back({point_distance(vertices[i], vertices[(i + 1) % size1]), {abs(cos(angle)), sin(angle)}});// Для начала векторам можно было resize сделать.
    }
    sides2.clear();
    sides2.resize(size2);
    for (int i = 0; i < size2; ++i) {
        double angle = get_angle(vertices[i], vertices[(i + 1) % size1], vertices[(i + 2) % size1]);
        sides2.push_back({point_distance(vertices[i], vertices[(i + 1) % size1]), {abs(cos(angle)), sin(angle)}});
    }
    bool flag;
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = 0; j < size2; ++j) {
            if (!cmp(sides1[(i + j) % size1].first, sides2[j].first) ||
                !cmp(sides1[(i + j) % size1].second.first, sides2[j].second.first) ||
                !cmp(sides1[(i + j) % size1].second.second, sides2[j].second.second)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = size2 - 1; j >= 0; --j) {
            if (!cmp(sides1[(i - j + size1) % size1].first, sides2[j].first) ||
                !cmp(sides1[(i - j + size1) % size1].second.first, sides2[j].second.first) ||
                !cmp(sides1[(i - j + size1) % size1].second.second, sides2[j].second.second)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

bool Polygon::isSimilarTo(const Shape& shape) {
    Polygon poly;
    try {
        poly = dynamic_cast<const Polygon&>(shape);
    } catch (...) {
        return false;
    }
    vector<double> sides1, sides2;

    int size1 = this->vertices.size();
    int size2 = poly.vertices.size();
    if (size1 != size2) {
        return false;
    }
    sides1.clear();
    for (int i = 0; i < size1; ++i) {
        sides1.push_back(point_distance(vertices[i],vertices[(i+1) % size1]));
    }
    sides2.clear();
    for (int i = 0; i < size2; ++i) {
        sides2.push_back(point_distance(poly.vertices[i],poly.vertices[(i+1) % size1]));
    }
    bool flag;
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = 0; j < size2; ++j) {
            if (!cmp(sides1[(i + j) % size1] / sides1[(i + j + 1) % size1], sides2[j] / sides2[(j + 1) % size2])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = 0; j < size2; ++j) {
            if (!cmp(sides1[(i + j) % size1] / sides1[(i + j + 1) % size1], sides2[(j + 1) % size2] / sides2[j])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = size2-1; j >= 0; --j) {
            if (!cmp(sides1[(i - j + size1) % size1] / sides1[(i - j + size1 + 1) % size1], sides2[j] / sides2[(j+1) % size2])) {
                flag = false;
            }
        }
        if (flag) {
            return true;
        }
    }
    for (int i = 0; i < size1; ++i) {
        flag = true;
        for (int j = size2-1; j >= 0; --j) {
            if (!cmp(sides1[(i - j + size1) % size1] / sides1[(i - j + size1 + 1) % size1], sides2[(j+1) % size2] / sides2[j])) {
                flag = false;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}


bool Polygon::containsPoint(Point point) {
    int size = vertices.size();
    bool flag = 0;
    double S, S1, S2, S3;
    int i1, i2;
    for (int i = 0; i < size; ++i) {
        i1 = (i+1) % size;
        while (!flag) {
            i2 = (i1 + 1) % size;
            if (i2 == i) {
                break;
            }
            S = abs (vertices[i1].x * (vertices[i2].y - vertices[i].y) +
                     vertices[i2].x * (vertices[i].y - vertices[i1].y) +
                     vertices[i].x  * (vertices[i1].y - vertices[i2].y));
            S1 = abs(vertices[i1].x * (vertices[i2].y - point.y) +
                     vertices[i2].x * (point.y - vertices[i1].y) +
                     point.x * (vertices[i1].y - vertices[i2].y));
            S2 = abs (vertices[i].x * (vertices[i2].y - point.y) +
                      vertices[i2].x * (point.y - vertices[i].y) +
                      point.x * (vertices[i].y - vertices[i2].y));
            S3 = abs (vertices[i1].x * (vertices[i].y - point.y) +
                      vertices[i].x * (point.y - vertices[i1].y) +
                      point.x * (vertices[i1].y - vertices[i].y));
            if (cmp(S, S1 + S2 + S3)) {
                flag = true;
                break;
            }
            i1 = i1 + 1;
            if (i1 >= size) {
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    return flag;
}

void Polygon::rotate(Point center, double angle) {
    double angleRadian = angle * M_PI / 180;
    double cosinus = cos(angleRadian);
    double sinus = sin(angleRadian);
    for (size_t j = 0; j < vertices.size(); j++)
    {
        double x = ((vertices[j].x - center.x) * cosinus - (vertices[j].y - center.y) * sinus + center.x);
        double y = ((vertices[j].x - center.x) * sinus + (vertices[j].y - center.y) * cosinus + center.y);
        if (cmp(x,0.0)) {
            x = 0.0;
        }
        if (cmp(y,0.0)) {
            y = 0.0;
        }
        vertices[j].x = x;
        vertices[j].y = y;
    }
}

void Polygon::reflex(Point point) {
    this->scale(point, -1.0);
}


void Polygon::reflex(Line axis) {
    int size = vertices.size();
    for (int i = 0; i < size; ++i) {
        vertices[i] = reflect_over_Line(axis, vertices[i]);
    }
}

void Polygon::scale(Point center, double coeff) {
    double x0 = center.x, y0 = center.y;
    int size = vertices.size();
    for (int i = 0; i < size; ++i) {
        vertices[i].x = x0 + coeff * (vertices[i].x - x0);
        vertices[i].y = y0 + coeff * (vertices[i].y - y0);
    }
}