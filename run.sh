#!/bin/bash

g++ -o main.exe src/main.cpp src/geometry.cpp src/tree.cpp -std=c++11
./main.exe test/test1.txt