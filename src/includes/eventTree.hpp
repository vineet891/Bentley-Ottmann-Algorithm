#include "geometry.hpp"
#include <vector>
using namespace std;

/**
 * @file evenTree.hpp
 * Class containing event queue implementation using red-black balanced binary search trees. * 
 * 
 */
struct Node
{
    vector<Segment> segData;
    Point data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

typedef Node *NodePtr;

class EventTree
{

private:
    NodePtr endNull;

    // Init leaf null nodes of red black trees
    void initNull(NodePtr node, NodePtr p);
    // Print Helpers
    void preOrderHelper(NodePtr root);
    void postOrderHelper(NodePtr root);
    void inOrderHelper(NodePtr root);
    // Tree Util Operations
    void rightRotate(NodePtr node);
    void leftRotate(NodePtr node);
    // Insert Helper
    void insertHelper(NodePtr node);
    void insertInitTreeHelper(NodePtr ue, Segment s, bool UE);
    // Search Helper
    NodePtr searchHelper(NodePtr root, Point key);
    // Delete Helpers
    void deleteFix(NodePtr node);
    void transplant(NodePtr l, NodePtr r);
    void deleteHelper(NodePtr root, Point key);

public:
    NodePtr root;

    // Constructor
    EventTree();
    // Print Functions
    void printNode(NodePtr node);
    void preOrder();
    void postOrder();
    void inOrder();
    // Tree Utils
    NodePtr getMinNode(NodePtr node);
    NodePtr getMaxNode(NodePtr node);
    NodePtr getSuccNode(NodePtr node);
    NodePtr getPredNode(NodePtr node);
    NodePtr getRoot();
    // Insert Function
    void insertTree(Segment p);
    // Search Function
    NodePtr searchTree(Point key);
    // Delete Function
    void deleteNode(Point data);
};
