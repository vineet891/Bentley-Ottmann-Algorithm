# Bentley-Ottmann Algorithm - Line Intersections

Partial Fulfillment of CS F364 Design and Analysis of Algorithms

## Project Team - Team

- [Pavan Kumar Reddy Yannam](https://github.com/PavanReddy28/)
- [Vineet Venkatesh](https://github.com/vineet891/)
- [BVS Ruthvik]()
- [Ishaan Khushu]()

## Implementation of Algorithm

Details regarding the algorithm, functions utilized and general workflow can be viewed via Doxygen documentation.

## Building and Running

Implementation of Balanced Binary Search trees for Status and Event Queues.
- Red Black trees were chosen over AVL self balancing trees as red-black trees have faster insertion and deletion times.

```
$ g++ -o main.exe src/main.cpp
$ ./main.exe test/<test_filename>.txt
```
or
```
bash run.sh
```

## Testing and Visualization

Test cases used are present in the "test" directory.

Test results visualization on a cartesian plot:

![Test 0](../../visualization/result.jpg)

## Performance Analysis

Performance analysis was performed by plotting the number of segments vs time taken to run the program (T(n,k) plot). We later compare this with O((k+n)logn) plot.

Analysis showed that:

- T(n, k) ε O((k+n)logn)

## Reference
```
Bentley, Jon Louis, and Thomas A. Ottmann. "Algorithms for reporting and counting geometric intersections." IEEE Transactions on computers 28.09 (1979): 643-647.
```

# Contributing
- Include all source code in ./src directory.
- Include all library code files in ./src/includes directory.
- Include all test code in ./test directory.