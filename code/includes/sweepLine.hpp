#pragma once

#include "eventTree.hpp"
#include "statusTree.hpp"
using namespace std;

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

    /// Accessor Functions
    /// @returns Accessory function to return events.
    EventTree getEventTree();
    /// Bentley Ottmann main algorithm function
    /// Find the intersection points
    vector<Point> findIntersection();

    /// Handling the different cases of event points 
    /// @param e Event e to be handled
    vector<Point> handleEventPoint(EventPtr e);

    /// Find New Events
    /// @param e Event e to be handled
    /// @param p EventPtr e to be handled
    void findNewEvents(Segment s1, Segment s2, EventPtr p);

};