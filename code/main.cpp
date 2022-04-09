#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include "includes/sweepLine.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    int n, v;
    vector<Segment> segments;

    /// Checking verbose argument option
    if (argc>2 && !string(argv[2]).compare("-v"))
    {
        v = 3;
    }
    else
    {
        v = 2;
    }

    /// Reading input:
    if (argc>1 && !string(argv[1]).compare("-f"))
    {
        /// Reading input from test case files
        cout << "Reading input from test case file " << argv[v] << "...." << endl;
        ifstream f;
        f.open(argv[v]);
        if (!f)
        {
            cerr << "File Not Found:" << argv[v] << endl;
            return 0;
        }

        f >> n;
        double t;
        for (int i = 0; i < n; i++)
        {
            vector<double> temp;
            for (int j = 0; j < 4; j++)
            {
                if (!f.eof())
                {
                    f >> t;
                    temp.push_back(t);
                }
            }
            Segment s = Segment(Point(temp[0], temp[1]), Point(temp[2], temp[3]));
            segments.push_back(s);
        }
        f.close();
        cout << "Done reading input from test case file.\n";
    }
    else
    {
        /// Reading input from user
        cout << "Reading input from user....\n";
        cout << "Enter number of segments: ";
        cin >> n;
        double t;
        for (int i = 0; i < n; i++)
        {
            vector<double> temp;
            for (int j = 0; j < 4; j++)
            {
                cin >> t;
                temp.push_back(t);
            }
            Segment s = temp[1] > temp[3] ? Segment(Point(temp[0], temp[1]), Point(temp[2], temp[3])) : Segment(Point(temp[2], temp[3]), Point(temp[0], temp[1]));
            segments.push_back(s);
        }
        cout << "Done reading input from user.\n";
    }
    
    /// Sweep Line
   
    vector<Point> p1;
    for(auto seg1 : segments) {
        for(auto seg2 : segments) {            
            if(!seg1.isEqual(seg2) && seg1.does_intersect(seg2)) {                
                Point p = seg1.intersection(seg2);
                p.printPoint();
                p1.push_back(p);
            }
        }
    }



     for(int i=0; i<segments.size(); i++) {
        Segment seg1 = segments[i];
        if(i!=segments.size()-1) { cout << seg1.UE.getX() << "," << seg1.UE.getY() << "," << seg1.LE.getX() << "," << seg1.LE.getY() << ","; }
        else { cout << seg1.UE.getX() << "," << seg1.UE.getY() << "," << seg1.LE.getX() << "," << seg1.LE.getY() << " "; }
    }
    for(int i=0; i<p1.size(); i++) {
        if(i!=p1.size()-1) { cout << p1[i].getX()<< ","<<p1[i].getY() << ","; }
        else { cout << p1[i].getX()<< ","<<p1[i].getY(); }
    }

    // SweepLine sweep = SweepLine(segments);
    // vector<Point> res = sweep.findIntersection();

    // cout << "Final Intersection points :\n";
    // for(auto p:res) { p.printPoint(); }

    /// Verbose Statments
    // if (!string(argv[2]).compare("-v"))
    // {
    //     cout << "\nEvent Tree -\n";
    //     // sweep.getEventTree().inOrder();
    // }    

    return 0;
}