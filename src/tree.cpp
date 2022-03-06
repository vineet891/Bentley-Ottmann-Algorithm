#include "includes/tree.hpp"
using namespace std;

void RbTree::initNull(NodePtr n, NodePtr p) {
    n->data = Segment();
    n->parent = p;
    n->left = nullptr;
    n->right = nullptr;
}