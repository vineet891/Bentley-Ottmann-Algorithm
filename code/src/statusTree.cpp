#include "../includes/statusTree.hpp"
#include "../includes/geometry.hpp"
#include "./constant.hpp"
#include <iostream>
using namespace std;

/// Constructors and Initializers
StatusTree::StatusTree()
{
    endNull = new Status();
    endNull->color = 0;
    endNull->left = nullptr;
    endNull->right = nullptr;
    root = endNull;
}

void StatusTree::initNull(StatusPtr n, StatusPtr p)
{
    n->data = Segment();
    n->parent = p;
    n->left = nullptr;
    n->right = nullptr;
}

/// Print Status - Point and Segment
void StatusTree::printSNode(StatusPtr node)
{
    cout << "\nStatus Node - ";
    node->data.printSegment();
}
