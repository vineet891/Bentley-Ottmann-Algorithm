#include "includes/eventTree.hpp"
#include "includes/statusTree.hpp"
#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    vector<Segment> segments;
    if (!string(argv[1]).compare("-file"))
    {
        /// Reading input from test case files
        cout << "Reading input from test case file " << argv[2] << "...." << endl;
        ifstream f;
        f.open(argv[2]);
        if (!f)
        {
            cerr << "File Not Found:" << argv[1] << endl;
            return 0;
        }

        f >> n;
        int t;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
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
        int t;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 4; j++)
            {
                cin >> t;
                temp.push_back(t);
            }
            Segment s = Segment(Point(temp[0], temp[1]), Point(temp[2], temp[3]));
            segments.push_back(s);
        }
        cout << "Done reading input from user.\n";
    }

    /// Inserting to Event Tree
    cout << "Inserting into Event Tree...\n";
    EventTree et;
    for (auto i : segments)
    {
        cout << "\n";
        i.printSegment();
        et.insertTree(i);
    }
    et.inOrder();
    cout << "\nEvent Tree Ready.\n";

    return 0;
}