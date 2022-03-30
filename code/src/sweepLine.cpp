#include "../includes/sweepLine.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

/// Constructor
SweepLine::SweepLine(vector<Segment> segments)
{
    initEventHelper(segments);
}

/// InitEventTree
void SweepLine::initEventHelper(vector<Segment> segments)
{
    cout << "Inserting into Event Tree...\n";
    for (auto i : segments)
    {
        events.insertTree(i);
    }
    cout << "\nEvent Tree Ready.\n";
}

/// Accessor Functions
EventTree SweepLine::getEventTree()
{
    return this->events;
}

/// Bentley Ottmann main algorihtm function
vector<Point> SweepLine::findIntersection()
{
    vector<Point> res;
    while (!events.isEmpty())
    {
        EventPtr node = events.getMinNode(events.getRoot());
        events.deleteNode(node->data);
        vector<Point> temp = handleEventPoint(node);
        res.insert(res.end(), temp.begin(), temp.end());
    }

    return res;
}

/// Handling the different cases of event points
vector<Point> SweepLine::handleEventPoint(EventPtr e)
{
    bool flag = true;
    this->e = e->data;
    vector<Point> res;
    vector<Segment> cSegTemp;
    if (status.empty())
    {
        flag = false;
    }
    if (flag)
    {
        cSegTemp = findCSeg(e);
    }

    int n = cSegTemp.size() + e->lowerSeg.size() + e->upperSeg.size();

    /// If Lp Cp Up union has more than one element
    if (n > 0)
    {
        res.push_back(e->data);
    }

    /// Delete from status queue (Lp union Cp)
    for (auto seg : e->lowerSeg)
    {
        auto i = find_if(status.begin(), status.end(), [seg](Segment s) {
            return s.cmp(seg);
        });
        if (i != status.end())
        {
            status.erase(i);
        }
    }
    for (auto seg : cSegTemp)
    {
        auto i =  find_if(status.begin(), status.end(), [seg](Segment s) {
            return s.cmp(seg);
        });
        if (i != status.end())
        {
            status.erase(i);
        }
    }

    /// Add to status queue (Up union Cp)
    for (auto seg : e->upperSeg)
    {
        auto i =  find_if(status.begin(), status.end(), [seg](Segment s) {
            return s.cmp(seg);
        });
        if (i == status.end())
        {
            status.push_back(seg);
        }
    }
    for (auto seg : cSegTemp)
    {
        auto i =  find_if(status.begin(), status.end(), [seg](Segment s) {
            return s.cmp(seg);
        });
        if (i == status.end())
        {
            status.push_back(seg);
        }
    }

    /// Sort the status queue

    auto comp = [&e](Segment s1, Segment s2) ->bool {
        Point p1 = s1.intersection(Segment(Point(0, e->data.getY()), e->data));
        Point p2 = s2.intersection(Segment(Point(0, e->data.getY()), e->data));
        return p1.getX() < p2.getX();
    };
    sort(status.begin(), status.end(), comp);

    /// Find new event points
    Segment s1 = status[getLeftMost(e->upperSeg, cSegTemp)];
    Segment s2 = status[getRightMost(e->upperSeg, cSegTemp)];
    if (cSegTemp.size() + e->upperSeg.size() == 0)
    {
        findNewEvents(s1, s2, e);
    }
    else
    {
        int t = getNeigh(s1);
        Segment s11 = status[getNeigh(s1) - 1];
        Segment s22 = status[getNeigh(s2) + 1];
        findNewEvents(s11, s1, e);
        findNewEvents(s22, s2, e);
    }
}

/// Find New Events
void SweepLine::findNewEvents(Segment s1, Segment s2, EventPtr p)
{
    Point inter = s1.intersection(s2);
    if (inter.getX() > p->data.getX() || inter.getY() < p->data.getY() || (inter.getX() == p->data.getX() && inter.getY() == p->data.getY()))
    {
        Event *e = new Event();
        vector<Segment> seg;
        seg.push_back(s1);
        seg.push_back(s2);
        events.insertPoint(inter, seg);
    }
}

/// Util Functions
vector<Segment> SweepLine::findCSeg(EventPtr e)
{
    vector<Segment> temp;
    for (auto seg : status)
    {
        if (seg.isPresent(e->data))
        {
            temp.push_back(seg);
        }
    }
    return temp;
}

bool comp1(Segment s1, Segment s2)
{
    return s1.cmp(s2);
}

int SweepLine::getLeftMost(vector<Segment> u, vector<Segment> c)
{
    sort(u.begin(), u.end(), comp1);
    sort(c.begin(), c.end(), comp1);
    if (u[0].cmp(c[0]))
    {
        Segment s1 = u[0];
        auto i =  find_if(status.begin(), status.end(), [s1](Segment s) {
            return s.cmp(s1);
        });
        return i - status.begin();
    }
    else
    {
        Segment s1 = u[0];
        auto i =  find_if(status.begin(), status.end(), [s1](Segment s) {
            return s.cmp(s1);
        });
        return i - status.begin();
    }
}

int SweepLine::getNeigh(Segment s)
{
    int count = 0;
    for (auto seg : status)
    {
        if (seg.isEqual(s))
        {
            return count;
        }
        count++;
    }
}

bool comp2(Segment s1, Segment s2)
{
    return !s1.cmp(s2);
}

int SweepLine::getRightMost(vector<Segment> u, vector<Segment> c)
{
    sort(u.begin(), u.end(), comp2);
    sort(c.begin(), c.end(), comp2);
    if (u[0].cmp(c[0]))
    {
        Segment s1 = u[0];
        auto i =  find_if(status.begin(), status.end(), [s1](Segment s) {
            return s.cmp(s1);
        });
        return i - status.begin();
    }
    else
    {
        Segment s1 = u[0];
        auto i =  find_if(status.begin(), status.end(), [s1](Segment s) {
            return s.cmp(s1);
        });
        return i - status.begin();
    }
}
