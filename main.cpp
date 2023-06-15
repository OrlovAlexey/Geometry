#include <iostream>
#include "geometry.h"

int main(){

    Point p1(0.0, 0.0);
    Point p2(0.0, 1.0);

    Point p3(1.0, 1.0);
    Point p4(1.0, 0.0);

    Point p11(0.0, 0.0);
    Point p21(0.0, 0.5);
    Point p31(0.5, 1.0);
    Point p41(0.5, 0.0);
    Point p51(-0.000001, -0.000001);
    Line L1(p1, p3);
    Line L2(p2, p4);
//    cout << L.a << " " << L.b <<  " " << L.c << '\n';
//    cout << (poly2.isSimilarTo(poly1));


//    Ellipse elp(p1, p2, 10);
//    pair<Line, Line> pa = elp.directrices();
//    cout << elp.eccentricity() << '\n';
//    cout << pa.first.a << " " << pa.first.b << " " << pa.first.c <<'\n';
//    cout << pa.second.a << " " << pa.second.b << " " << pa.second.c <<'\n';
//    cout << intersect(L1, L2).x << " " << intersect(L1, L2).y << '\n';


//    Square a(p1, p3);
//    Rectangle b(p1, p3,1);
//    cout << (a == b) << '\n';
//    cout << (b == a) << '\n';
//
//    Shape *aa = &a;
//    Shape *bb = &b;
//    cout << (*bb == *aa) << '\n';
//    cout << (*aa == *bb) << '\n';


    Triangle tri(p1,p2,p3);
    cout << tri.circumscribedCircle().center().x << '\t' <<tri.circumscribedCircle().center().y << '\n';
    cout << tri.inscribedCircle().center().x << '\t' << tri.inscribedCircle().center().y << '\n';
    cout << tri.centroid().x << '\t' << tri.centroid().y << '\n';
    cout << tri.orthocenter().x <<'\t' << tri.orthocenter().y << '\n';
    cout << tri.EulerLine().a << " " << tri.EulerLine().b << " " << tri.EulerLine().c << '\n';
//    cout << tri.ninePointsCircle().center().x << '\t' << tri.ninePointsCircle().center().y << '\t' << tri.ninePointsCircle().r << '\n';

//    Rectangle rec1{p2, p3, p4, p1};
//    Square rec2(p3, p1);

//    rec1.rotate(p1, 90.0);
//    rec1.scale(p1, 10);

//    cout << (*bb == rec1) << '\n';

//    cout << rec1.perimeter() << '\n';
//    cout << rec1.a.x << " " << rec1.a.y << '\n';
//    cout << rec1.b.x << " " << rec1.b.y << '\n';
//    cout << rec1.c.x << " " << rec1.c.y << '\n';
//    cout << rec1.d.x << " " << rec1.d.y << '\n';
//    cout << rec2.a.x << " " << rec2.a.y << '\n';
//    cout << rec2.b.x << " " << rec2.b.y << '\n';
//    cout << rec2.c.x << " " << rec2.c.y << '\n';
//    cout << rec2.d.x << " " << rec2.d.y << '\n';
    return 0;
}