#!/bin/bash

echo "Compiling...."
g++ -o main code/main.cpp code/src/geometry.cpp code/src/eventTree.cpp -std=c++11
echo "Compiled Succesfully."
./main -file test/test1.txt