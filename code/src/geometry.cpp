#include "../includes/geometry.hpp"
#include <iostream>
#include <limits>
using namespace std;

Point::Point(int x1, int y1)
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

int Point::xHelp() { return this->x; }
int Point::yHelp() { return this->y; }
int Point::getX() { return this->xHelp(); };
int Point::getY() { return this->yHelp(); };

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

Point Segment::intersection(Segment s)
{
    Point p1 = UE, p2 = LE, p3 = s.UE, p4 = s.LE;

    if (p1.getX() == p2.getX())
    {
        double c = (p4.getY() - p3.getY()) / (p4.getX() - p3.getX());
        double d = p3.getY() - c * p3.getX();
        return Point(p1.getX(), c * p1.getX() + d);
    }
    if (p3.getX() == p4.getX())
    {
        double a = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        double b = p1.getY() - a * p1.getX();
        return Point(p3.getX(), a * p3.getX() + b);
    }

    double a = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX()),
           b = p1.getY() - a * p1.getX(),
           c = (p4.getY() - p3.getY()) / (p4.getX() - p3.getX()),
           d = p3.getY() - c * p3.getX();
    cout << (p2.getY() - p1.getY()) / (p2.getX() - p1.getX()) << " " << p1.getY() << " " << p3.getX() << " " << p1.getX() << endl;
    return Point(-(b - d) / (a - c), a * (-(b - d) / (a - c)) + b);
}

bool Segment::cmp(Segment s2)
{
    return (this->UE.getY() > s2.UE.getY()) || ((this->UE.getY() == s2.UE.getY()) && (this->UE.getX() < s2.UE.getX()));
}

bool Segment::isEqual(Segment s)
{
    return (this->UE.getY() == s.UE.getY()) && (this->UE.getX() == s.UE.getX());
}

void Segment::printSegment()
{
    cout << "Segment : " << endl;
    cout << "Upper End point: (" << this->UE.getX() << "," << this->UE.getY() << ")\n";
    cout << "Lower End point: (" << this->LE.getX() << "," << this->LE.getY() << ")\n";
}