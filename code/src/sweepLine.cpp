#include "../includes/sweepLine.hpp"
#include <iostream>
using namespace std;

/// Constructor
SweepLine::SweepLine(vector<Segment> segments) {
    initEventHelper(segments);
}

/// InitEventTree
void SweepLine::initEventHelper(vector<Segment> segments) {
    cout << "Inserting into Event Tree...\n";
    for (auto i : segments)
    {
        events.insertTree(i);
    }
    cout << "\nEvent Tree Ready.\n";
}

/// Accessor Functions
EventTree SweepLine::getEventTree() {
    return this->events;
}

/// Bentley Ottmann main algorithm function
vector<IntersectPoints> SweepLine::findIntersection() {
    vector<IntersectPoints> res;
    while(!events.isEmpty()) {
        EventPtr node = events.getMinNode(events.getRoot());
        events.deleteNode(node->data);
    }
    
    return res;
}

/// Handling the different cases of event points
// vector<IntersectPoints> SweepLine::handleEventPoint(Event e) {
//     for(auto seg:e.upperSeg) { 

//         status.push_back(seg); 
//     }
    
// }

