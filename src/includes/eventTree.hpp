#include "geometry.hpp"
using namespace std;

struct Node {
    Segment data;
    Node* parent;
    Node* left;
    Node* right;
    int color;
};

typedef Node *NodePtr;

class EventTree {

    private:
    NodePtr endNull;

    // Init Leave null nodes of red black trees
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
    //Search Helper
    NodePtr searchHelper(NodePtr root, Segment key);
    // Delete Helpers
    void deleteFix(NodePtr node);
    void transplant(NodePtr l, NodePtr r);
    void deleteHelper(NodePtr root, Segment key);

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
    void insertTree(Segment s);
    // Search Function
    NodePtr searchTree(Segment key);
    // Delete Function
    void deleteNode(Segment data);

};
