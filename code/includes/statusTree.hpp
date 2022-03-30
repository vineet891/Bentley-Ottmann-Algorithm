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
    bool leaf;
};

typedef Status *StatusPtr;

class StatusTree
{

private:
    StatusPtr endNull;

    /// Init leaf null nodes of red black trees
    void initNull(StatusPtr node, StatusPtr p);

    /// Print Helpers - VIsualization
    void preOrderHelper(StatusPtr root);
    void postOrderHelper(StatusPtr root);
    void inOrderHelper(StatusPtr root);

    /// Tree Util Operations
    void rightRotate(StatusPtr node);
    void leftRotate(StatusPtr node);
    
    /// Search Helper
    StatusPtr searchHelper(StatusPtr root, Point key);
    
    /// Insert Helper
    void insertHelper(StatusPtr node);
    void insertInitTreeHelper(StatusPtr ue, Segment s, bool UE);
    
    /// Delete Helpers
    void deleteFix(StatusPtr node);
    void transplant(StatusPtr l, StatusPtr r);
    void deleteHelper(StatusPtr root, Point key);

    /// Swap Helper
    void swapHelper(StatusPtr n1, StatusPtr n2);

public:
    StatusPtr root;

    /// Constructor
    StatusTree();

    /// Print Functions - VIsualization
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

    /// Search
    StatusPtr searchTree(Point key);

    /// Add / Insert
    void insertTree(Segment p);

    /// Delete
    void deleteSNode(Point data);

    /// Swap
    void swapSNode(StatusPtr n1, StatusPtr n2);

    /// Update Operations
    void upperEndPoint(StatusPtr pu);   // Add/Insert segment to status and find the intersections with neighbors in the status queue. 
    void intersectPoint(StatusPtr pi);  // Swap the positions of segments in the status queue and find intersections with the new neighbors.
    void lowerEndPoint(StatusPtr pl);   // Delete the segment from status and find the intersection of neighbors of the segment we removed.
};
