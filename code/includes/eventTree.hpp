#pragma once

#include "geometry.hpp"
#include "constant.hpp"
#include <vector>
using namespace std;

/**
 * @file eventTree.hpp
 * Class containing event queue implementation using red-black balanced binary search trees. * 
 * 
 */
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


class EventTree
{

private:
    EventPtr endNull;

    /// Init leaf null nodes of red black trees
    void initNull(EventPtr node, EventPtr p);
    /// Print Helpers
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
    void preOrder();
    void postOrder();
    void inOrder();
    /// Tree Utils
    EventPtr getMinNode(EventPtr node);
    EventPtr getMaxNode(EventPtr node);
    EventPtr getSuccNode(EventPtr node);
    EventPtr getPredNode(EventPtr node);
    EventPtr getRoot();
    bool isEmpty();
    /// Insert Function
    void insertTree(Segment p);
    /// Search Function
    EventPtr searchTree(Point key);
    /// Delete Function
    void deleteNode(Point data);
};
