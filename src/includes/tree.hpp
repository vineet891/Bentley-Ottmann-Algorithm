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

class RbTree {

    private:
    NodePtr root;
    NodePtr endNull;

    void initNull(NodePtr node, NodePtr p);
    // Print Helpers
    void preOrderHelper(NodePtr root);
    void postOrderHelper(NodePtr root);
    void inOrderHelper(NodePtr root);
    //Search Helper
    NodePtr searchHelper(NodePtr root, Segment key);
    // Delete Helpers
    void deleteFix(NodePtr node);
    void transplant(NodePtr l, NodePtr r);
    void deleteHelper(NodePtr root, Segment key);
    // Insert Helper
    void insertFix(NodePtr node);

    public:
    // Constructor
    RbTree();
    // Print Functions
    void preOrder();
    void postOrder();
    void inOrder();
    // Search Function
    NodePtr searchTree(Segment key);
    // Delete Function
    void deleteNode(Segment data);
    // Tree Utils
    NodePtr getMinNode(NodePtr node);
    NodePtr getMaxNode(NodePtr node);
    NodePtr getSuccNode(NodePtr node);
    NodePtr getPredNode(NodePtr node);
    NodePtr getRoot();
    // Tree Operations
    void rightRotate(NodePtr node);
    void leftRotate(NodePtr node);
    // Insert Function
    void insert(Segment s);

};
