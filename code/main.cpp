#include "includes/sweepLine.hpp"
#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n, v;
    vector<Segment> segments;

    /// Checking verbose argument option
    if (string(argv[2]).compare("-v"))
    {
        v = 2;
    }
    else
    {
        v = 3;
    }

    
    /// Reading input: 
    if (!string(argv[1]).compare("-f"))
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
            Segment s = temp[1]>temp[3]? Segment(Point(temp[0], temp[1]), Point(temp[2], temp[3])) : Segment(Point(temp[2], temp[3]), Point(temp[0], temp[1]));
            segments.push_back(s);
        }
        cout << "Done reading input from user.\n";
    }

    /// Inserting to Event Tree
    cout << "Inserting into Event Tree...\n";
    EventTree et;
    for (auto i : segments)
    {
        et.insertTree(i);
    }
    cout << "\nEvent Tree Ready.\n";

    /// Verbose Statments
    if (!string(argv[2]).compare("-v"))
    {
        et.inOrder();
    }

    return 0;
}