#!/bin/bash

echo "Compiling...."
g++ -o main code/main.cpp code/src/geometry.cpp code/src/eventTree.cpp code/src/sweepLine.cpp -std=c++11
echo "Compiled Succesfully."
./main -f -v test/test2.txt