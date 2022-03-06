#!/bin/bash

g++ -o main src/main.cpp src/geometry.cpp src/tree.cpp src/eventTree.cpp src/statusTree.cpp -std=c++11
./main test/test1.txt