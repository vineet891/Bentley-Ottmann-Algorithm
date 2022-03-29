#include "includes/eventTree.hpp"
#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    string inp_str = "", line;
    int n;
    vector<Segment> segments;
    if (argv[1] == "-file")
    {
        ifstream f(argv[2]);
        if (!f)
        {
            cout << "File Not Found:" << argv[1] << endl;
            return 0;
        }
        // while(getline(*f, line)) {
        //     cout << line;
        // }
        std::stringstream buffer;
        buffer << f.rdbuf();
        inp_str = buffer.str();
    }
    else
    {
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
    }
    EventTree et;
    for (auto i : segments)
    {
        cout << "\n";
        i.printSegment();
        et.insertTree(i);
    }

    et.inOrder();
    et.postOrder();
    et.preOrder();
    
    et.deleteNode(segments[0].LE);
    cout << "Deleted Point - ";
    segments[0].LE.printPoint();
    
    et.inOrder();
    et.postOrder();
    et.preOrder();

    return 0;
}