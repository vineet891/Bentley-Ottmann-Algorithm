#include "includes/tree.hpp"
// #include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    string inp_str = "", line;
    int n;
    vector<Segment> input;
    if(argv[1]=="-file") {
        ifstream f(argv[2]);
        if (!f) {
            cout << "File Not Found:" << argv[1] << endl;
            return 0;
        }
        // while(getline(*f, line)) {
        //     cout << line;
        // }
        std::stringstream buffer;
        buffer << f.rdbuf();
        inp_str = buffer.str();
    } else {
        cout << "Enter number of segments: ";
        cin >> n;
        int t;
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for (int j=0; j<4; j++) {
                cin >> t;
                temp.push_back(t);
            }
            Segment s = Segment( Point(temp[0], temp[1]), Point(temp[2], temp[3]) );
            input.push_back(s);            
        }
    }
    RbTree rb ;
    for(auto i: input) { 
        i.printSegment(); 
        rb.insertTree(i);
    }

    rb.inOrder();
    rb.postOrder();
    rb.preOrder();

    
    
    return 0;
}