#pragma once

using namespace std;

/**
 * @file statusTree.hpp
 * Class containing status queue implementation using red-black balanced binary search trees. * 
 * 
 */
struct Status
{
    Segment data;
    Status *parent;
    Status *left;
    Status *right;
    int color;
};

typedef Status *StatusPtr;

class StatusTree
{

private:
    StatusPtr endNull;

    /// Init leaf null nodes of red black trees
    void initNull(StatusPtr node, StatusPtr p);
    /// Print Helpers
    void preOrderHelper(StatusPtr root);
    void postOrderHelper(StatusPtr root);
    void inOrderHelper(StatusPtr root);
    /// Tree Util Operations
    void rightRotate(StatusPtr node);
    void leftRotate(StatusPtr node);
    /// Insert Helper
    void insertHelper(StatusPtr node);
    void insertInitTreeHelper(StatusPtr ue, Segment s, bool UE);
    /// Search Helper
    StatusPtr searchHelper(StatusPtr root, Point key);
    /// Delete Helpers
    void deleteFix(StatusPtr node);
    void transplant(StatusPtr l, StatusPtr r);
    void deleteHelper(StatusPtr root, Point key);

public:
    StatusPtr root;

    /// Constructor
    StatusTree();
    /// Print Functions
    void printSNode(StatusPtr node);
    void preOrder();
    void postOrder();
    void inOrder();
    /// Tree Utils
    StatusPtr getMinSNode(StatusPtr node);
    StatusPtr getMaxSNode(StatusPtr node);
    StatusPtr getSuccSNode(StatusPtr node);
    StatusPtr getPredSNode(StatusPtr node);
    StatusPtr getRoot();
    /// Insert Function
    void insertTree(Segment p);
    /// Search Function
    StatusPtr searchTree(Point key);
    /// Delete Function
    void deleteSNode(Point data);
};
