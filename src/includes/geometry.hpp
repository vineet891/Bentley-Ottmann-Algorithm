using namespace std;

class Point {
    int x;
    int y;
    
    int xHelp();
    int yHelp();

    public:
    
    Point(int x, int y);
    Point() = default;
    int getX();
    int getY();
        
};

class Segment {
    Point UE;
    Point LE;

    public:

    Segment(Point U, Point L);
    Segment() = default;
    bool cmp (Segment p2);

};