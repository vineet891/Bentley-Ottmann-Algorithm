#pragma once

#include "eventTree.hpp"
#include "statusTree.hpp"
using namespace std;

class SweepLine
{
private:
    // StatusTree status;
    vector<Segment> status;
    EventTree events;    

    /// Initializing the event tree
    void initEventHelper(vector<Segment> segments);    

    /// Util Functions
    vector<Segment> findCSeg(EventPtr e);
    int getLeftMost(vector<Segment> u, vector<Segment> c);
    int getRightMost(vector<Segment> u, vector<Segment> c);
    int getNeigh(Segment s);


    /// Main Function
    Point findIntersectHelper();

public:
    Point e;
    /// Constructors
    SweepLine();
    SweepLine(vector<Segment> segments);

    /// Accessor FUnctions
    EventTree getEventTree();

    /// Bentley Ottmann main algorihtm function
    vector<Point> findIntersection();

    /// Handling the different cases of event points
    vector<Point> handleEventPoint(EventPtr e);

    /// Find New Events
    void findNewEvents(Segment s1, Segment s2, EventPtr p);

};