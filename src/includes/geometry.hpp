using namespace std;

class Point {
    int x;
    int y;
    
    int xHelp();
    int yHelp();

    public:
    
    Point(int x, int y);
    Point() = default;
    bool cmp (Point p2);
    bool isEqual(Point p);
    int getX();
    int getY();
    void printPoint();
        
};

class Segment {

    public:
    Point UE;
    Point LE;

    Segment(Point U, Point L);
    Segment() = default;
    bool cmp (Segment p2);
    bool isEqual(Segment p);
    void printSegment();

};