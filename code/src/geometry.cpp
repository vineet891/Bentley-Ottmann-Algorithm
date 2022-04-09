#include "../includes/geometry.hpp"
#include <iostream>
#include <limits>
using namespace std;

Point::Point(double x1, double y1)
{
    x = x1;
    y = y1;
};

bool Point::cmp(Point p2)
{
    return (this->getY() > p2.getY()) || ((this->getY() == p2.getY()) && (this->getX() < p2.getX()));
};
bool Point::isEqual(Point p)
{
    return (this->getY() == p.getY()) && (this->getX() == p.getX());
};

void Point::printPoint()
{
    cout << "Point : (" << this->getX() << "," << this->getY() << ")\n";
}

double Point::xHelp() { return this->x; }
double Point::yHelp() { return this->y; }
double Point::getX() { return this->xHelp(); };
double Point::getY() { return this->yHelp(); };

Segment::Segment(Point U, Point L)
{
    UE = U;
    LE = L;
    slope = slopeCal(U, L);
    c = getVal(U);
}

double Segment::slopeCal(Point U, Point L)
{
    return (U.getY() - L.getY()) / (U.getX() - L.getX());
}

double Segment::getVal(Point p)
{
    return p.getY() - (slope * p.getX());
}

bool Segment::isPresent(Point p)
{
    return (getVal(p) - c) < numeric_limits<double>::epsilon();
}

bool onSegment(Point p, Point q, Point r) {
    if (q.getX() <= max(p.getX(), r.getX()) && q.getX() >= min(p.getX(), r.getX()) &&
        q.getY() <= max(p.getY(), r.getY()) && q.getY() >= min(p.getY(), r.getY()))
        return true;

    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
              (q.getX() - p.getX()) * (r.getY() - q.getY());

    if (val == 0) return 0;    // collinear
    return (val > 0) ? 1 : 2;  // clock or counterclock wise
}

bool Segment::does_intersect(Segment l2) {
    int o1 = orientation(this->UE, this->LE, l2.UE);
    int o2 = orientation(this->UE, this->LE, l2.LE);
    int o3 = orientation(l2.UE, l2.LE, this->UE);
    int o4 = orientation(l2.UE, l2.LE, this->LE);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(this->UE, l2.UE, this->LE)) return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(this->UE, l2.LE, this->LE)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(l2.UE, this->UE, l2.LE)) return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(l2.UE, this->LE, l2.LE)) return true;

    return false;
}

Point Segment::intersection(Segment s)
{
    Point p1 = UE, p2 = LE, p3 = s.UE, p4 = s.LE;

    // if (p1.getX() == p2.getX())
    // {
    //     double c = (p4.getY() - p3.getY()) / (p4.getX() - p3.getX());
    //     double d = p3.getY() - c * p3.getX();
    //     return Point(p1.getX(), c * p1.getX() + d);
    // }
    // if (p3.getX() == p4.getX())
    // {
    //     double a = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    //     double b = p1.getY() - a * p1.getX();
    //     return Point(p3.getX(), a * p3.getX() + b);
    // }

    double a = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    double b = p1.getY() - a * p1.getX();
    double c = (p4.getY() - p3.getY()) / (p4.getX() - p3.getX());
    double d = p3.getY() - c * p3.getX();
    return Point(-(b - d) / (a - c), a * (-(b - d) / (a - c)) + b);
}

bool Segment::cmp(Segment s2)
{
    return (this->UE.getY() > s2.UE.getY()) || ((this->UE.getY() == s2.UE.getY()) && (this->UE.getX() < s2.UE.getX()));
}

bool Segment::isEqual(Segment s)
{
    return (this->UE.getY() == s.UE.getY()) && (this->UE.getX() == s.UE.getX()) && (this->LE.getY() == s.LE.getY()) && (this->LE.getX() == s.LE.getX());
}

void Segment::printSegment()
{
    cout << "Segment : " << endl;
    cout << "Upper End point: (" << this->UE.getX() << "," << this->UE.getY() << ")\n";
    cout << "Lower End point: (" << this->LE.getX() << "," << this->LE.getY() << ")\n";
}