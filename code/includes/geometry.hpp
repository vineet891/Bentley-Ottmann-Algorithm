using namespace std;

/// Description of Point class
class Point
{
    double x;
    double y;

    double xHelp();
    double yHelp();

public:
    Point(double x, double y);
    Point() = default;
    bool cmp(Point p2);
    bool isEqual(Point p);
    double getX();
    double getY();
    void printPoint();
};

/// Description of Segment Class

class Segment
{

public:
    Point UE;
    Point LE;
    double slope;
    double c;

    Segment(Point U, Point L);
    Segment() = default;
    bool cmp(Segment p2);
    bool isEqual(Segment p);
    void printSegment();
    double slopeCal(Point U, Point L);
    double getVal(Point p);
    bool isPresent(Point p);
    bool does_intersect(Segment l2);
    Point intersection(Segment s);

};