#pragma once

#include "geometry.hpp"
#include "constant.hpp"
#include <vector>
using namespace std;

/**
 * @file statusTree.hpp
 * Class containing status queue implementation using red-black balanced binary search trees. * 
 * 
 */


/// Class containing event queue implementation using red-black balanced binary search trees. 
struct Event
{
    vector<Segment> upperSeg;
    vector<Segment> lowerSeg;
    vector<Segment> cSeg;
    Point data;
    Event *parent;
    Event *left;
    Event *right;
    int color;
};

typedef Event *EventPtr;

/// Description of EventTree class
class EventTree
{

private:
    EventPtr endNull;

    /// Init leaf null nodes of red black trees
    void initNull(EventPtr node, EventPtr p);
    /// Print Helpers - helper function 
    void preOrderHelper(EventPtr root);
    void postOrderHelper(EventPtr root);
    void inOrderHelper(EventPtr root);
    /// Tree Util Operations
    void rightRotate(EventPtr node);
    void leftRotate(EventPtr node);
    /// Insert Helper
    void insertHelper(EventPtr node);
    void insertInitTreeHelper(EventPtr ue, Segment s, bool UE);
    /// Search Helper
    EventPtr searchHelper(EventPtr root, Point key);
    /// Delete Helpers
    void deleteFix(EventPtr node);
    void transplant(EventPtr l, EventPtr r);
    void deleteHelper(EventPtr root, Point key);

public:
    EventPtr root;

    /// Constructor
    EventTree();
    /// Print Functions
    void printNode(EventPtr node);
    /// Function which prints the preorder traversal of the event tree.
    /// @returns Doesn't return anything.
    /// @see postOrder() inOrder()
    void preOrder();
    /// Function which prints the postorder traversal of the event tree.
    /// @returns Doesn't return anything.
    /// @see preOrder() inOrder()
    void postOrder();
    /// Function which prints the inorder traversal of the event tree.
    /// @returns Doesn't return anything.
    ///@see preOrder() postOrder()
    void inOrder();
    /// Tree Utils -
    /// Get min Node 
    /// @param node Root node
    /// @see getMaxNode() getSuccNode() getPredNode()
    EventPtr getMinNode(EventPtr node);
    /// Tree Utils -
    /// Get max Node 
    /// @param node Root node
    /// @see getMaxNode() getSuccNode() getPredNode()
    EventPtr getMaxNode(EventPtr node);
    /// Tree Utils - 
    /// Get Successive Node 
    /// @param node Root node
    /// @see getMaxNode() getSuccNode() getPredNode()
    EventPtr getSuccNode(EventPtr node);
    /// Tree Utils -
    /// Get Predecessor Node 
    /// @param node Root node
    /// @see getMaxNode() getSuccNode() getPredNode()
    EventPtr getPredNode(EventPtr node);
    /// Tree Utils -
    /// Get root 
    /// @see getMaxNode() getSuccNode() getPredNode()
    EventPtr getRoot();
    bool isEmpty();
    /// Insert Function - Insert into tree
    /// @param p Takes segment p as input and inserts it into the tree.
    void insertTree(Segment p);
    /// Search Function used to search for a node in the tree
    /// @param key The point to search for.
    EventPtr searchTree(Point key);
    /// Delete Function used to delete node from the tree
    /// @param data Node to be deleted.
    void deleteNode(Point data);
};
