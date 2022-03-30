#pragma once

#include "eventTree.hpp"
#include "statusTree.hpp"
using namespace std;

struct IntersectPoints {
    Point p;
    vector<Segment> segments;
};

class SweepLine
{
private:
    // StatusTree status;
    vector<Segment> status;
    EventTree events;    

    /// Initializing the event tree
    void initEventHelper(vector<Segment> segments);    

    /// Main Function
    IntersectPoints findIntersectHelper();

public:
    /// Constructors
    SweepLine();
    SweepLine(vector<Segment> segments);

    /// Accessor FUnctions
    EventTree getEventTree();

    /// Bentley Ottmann main algorihtm function
    vector<IntersectPoints> findIntersection();

    /// Handling the different cases of event points
    vector<IntersectPoints> handleEventPoint(Event e);

};