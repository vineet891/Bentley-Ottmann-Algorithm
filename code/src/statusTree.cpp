#include "../includes/statusTree.hpp"
#include "../includes/geometry.hpp"
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
    cout << "\nSNode - ";
    node->data.printSegment();
}

/// Pre Order Traversal Helper FUnction
void StatusTree::preOrderHelper(StatusPtr root)
{
    if (root != endNull)
    {
        this->printSNode(root);
        preOrderHelper(root->left);
        preOrderHelper(root->right);
    }
}

void StatusTree::preOrder()
{
    cout << "\nPreorder Traversal\n";
    this->preOrderHelper(this->root);
}

void StatusTree::postOrderHelper(StatusPtr root)
{
    if (root != endNull)
    {
        postOrderHelper(root->left);
        postOrderHelper(root->right);
        this->printSNode(root);
    }
}

void StatusTree::postOrder()
{
    cout << "\nPostorder Traversal\n";
    this->postOrderHelper(this->root);
}

void StatusTree::inOrderHelper(StatusPtr root)
{
    if (root != endNull)
    {
        inOrderHelper(root->left);
        this->printSNode(root);
        inOrderHelper(root->right);
    }
}

void StatusTree::inOrder()
{
    cout << "\nInorder Traversal\n";
    this->inOrderHelper(this->root);
}

/// Tree Utils - Tree Operations
void StatusTree::rightRotate(StatusPtr node)
{
    StatusPtr temp = node->left;
    node->left = temp->right;
    if (temp->right != endNull)
    {
        temp->right->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr)
    {
        this->root = temp;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = temp;
    }
    else
    {
        node->parent->left = temp;
    }
    temp->right = node;
    node->parent = temp;
}
