#pragma once

#include "eventTree.hpp"
#include "statusTree.hpp"
using namespace std;

/// Description of struct IntersectPoints

struct IntersectPoints {
    Point p;
    vector<Segment> segments;
};

/// Description of class SweepLine
class SweepLine
{
private:
    // StatusTree status;
    vector<Segment> status;
    EventTree events;    

    /// Initializing the event tree
    /// @param segments segments to initialize the event tree.
    void initEventHelper(vector<Segment> segments);    

    /// Main Function
    IntersectPoints findIntersectHelper();

public:
    /// Constructors
    SweepLine();
    SweepLine(vector<Segment> segments);

    /// Accessor Functions
    /// @returns Accessory function to return events.
    EventTree getEventTree();

    /// Bentley Ottmann main algorithm function
    /// Find the intersection points
    vector<IntersectPoints> findIntersection();

    /// Handling the different cases of event points 
    /// @param e Event e to be handled
    vector<IntersectPoints> handleEventPoint(Event e);

};