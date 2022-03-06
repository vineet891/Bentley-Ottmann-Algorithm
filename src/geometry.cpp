#include "includes/geometry.hpp"
using namespace std;

Point::Point(int x1, int y1) {
    x = x1;
    y = y1;
};

int Point::xHelp () { return this->x; }
int Point::yHelp () { return this->y; }
int Point::getX() { return this->xHelp(); };
int Point::getY() { return this->yHelp(); };

Segment::Segment(Point U, Point L) {
    UE = U;
    LE = L;
}

bool Segment::cmp (Segment s2) {
    return (this->UE.getY() > s2.UE.getY()) || ( (this->UE.getY() == s2.UE.getY()) && (this->UE.getX() > s2.UE.getX()) );
}
