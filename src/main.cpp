#include "includes/tree.hpp"
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    string input = "";
    ifstream f(argv[1]);
    if (!f) {
        cout << "File Not Found:" << argv[1] << endl;
        return 0;
    }
    std::stringstream buffer;
    buffer << f.rdbuf();
    input = buffer.str();

    // Test Code
    cout << input << endl;

    Point p1 (1, 2);  

    return 0;
}