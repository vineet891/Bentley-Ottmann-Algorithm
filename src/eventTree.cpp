#include "includes/eventTree.hpp"
#include <iostream>
using namespace std;

// Constructors and Initializers
EventTree::EventTree() {
    endNull = new Node();
    endNull->color = 0;
    endNull->left = nullptr;
    endNull->right = nullptr;
    root = endNull;
}

void EventTree::initNull(NodePtr n, NodePtr p) {
    n->data = Point();
    n->parent = p;
    n->left = nullptr;
    n->right = nullptr;
} 

// Print Functions
void EventTree::printNode(NodePtr node) {
    cout << "\nNode - ";
    node->data.printPoint();
    for(auto seg: node->segData) {
        seg.printSegment();
    }
}

void EventTree::preOrderHelper(NodePtr root) {
    if(root != endNull) {
        this->printNode(root);
        preOrderHelper(root->left);
        preOrderHelper(root->right);
    }
}

void EventTree::preOrder() {
    cout<< "\nPreorder Traversal\n";
    this->preOrderHelper(this->root);
}

void EventTree::postOrderHelper(NodePtr root) {
    if(root != endNull) {
        postOrderHelper(root->left);
        postOrderHelper(root->right);
        this->printNode(root);
    }
}

void EventTree::postOrder() {
    cout<< "\nPostorder Traversal\n";
    this->postOrderHelper(this->root);
}

void EventTree::inOrderHelper(NodePtr root) {
    if(root != endNull) {
        inOrderHelper(root->left);
        this->printNode(root);
        inOrderHelper(root->right);
    }
}

void EventTree::inOrder() {
    cout<< "\nInorder Traversal\n";
    this->inOrderHelper(this->root);

}

// Tree Utils - Tree Operations
void EventTree::rightRotate(NodePtr node) {
    NodePtr temp = node->left;
    node->left = temp->right;
    if(temp->right != endNull) {
        temp->right->parent = node;
    }
    temp->parent = node->parent;
    if(node->parent == nullptr) {
        this->root = temp;
    } else if (node == node->parent->right) {
        node->parent->right = temp;
    } else {
        node->parent->left = temp;
    }
    temp->right = node;
    node->parent = temp;
}

void EventTree::leftRotate(NodePtr node) {
    NodePtr temp = node->right;
    node->right = temp->left;
    if(temp->left != endNull) {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if(node->parent == nullptr) {
        this->root = temp;
    } else if (node == node->parent->left) {
        node->parent->left = temp;
    } else {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

// Insert Fucntions
// Balancing tree after insertion
void EventTree::insertHelper(NodePtr node) {
    NodePtr temp;

    while (node->parent->color == 1) {
        if(node->parent == node->parent->parent->right) {
            temp = node->parent->parent->left;
            // Case-1
            if(temp->color == 1) {
                temp->color = 1;
                node->parent->parent->color = 1;
                node->parent->color = 0;
                node = node->parent->parent;
            } 
            // Case-2
            else {
                if  (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->parent->color = 1;
                node->parent->color = 0;
                leftRotate(node->parent->parent);
            }
        } else {
            temp = node->parent->parent->right;
            // Case-3
            if(temp->color == 1) {
                temp->color = 0;
                node->parent->parent->color = 1;
                node->parent->color = 0;
                node = node->parent->parent;            
            }
            // Case-4
            else {
                if  (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->parent->color = 1;
                node->parent->color = 0;
                rightRotate(node->parent->parent);
            }
        }
        if(node == this->root) { break; }
    }    
    this->root->color = 0;
}

void EventTree::insertInitTreeHelper(NodePtr ue, Segment s, bool UE) {
    Point p = UE? s.UE : s.LE;
    if(ue==endNull) {
        cout << "No point found. Adding point to tree...\n";
        Node *node = new Node();
        node->parent = nullptr;
        node->data = p;
        node->segData.push_back(s);
        node->left = endNull;
        node->right = endNull;
        node->color = 1;

        Node *node1 = new Node();
        node->parent = nullptr;

        NodePtr temp = nullptr;
        NodePtr curr = this->root;

        while(curr != endNull) {
            temp = curr;
            if(node->data.cmp(curr->data)) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        node->parent = temp;
        if(temp == nullptr) {
            root = node;
            node->color = 0;
            return;
        } else if (node->data.cmp(temp->data)) {
            temp->left = node;
        } else {
            temp->right = node;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertHelper(node);

    } else {
        cout << "Point found. Updating node by adding segment...\n";
        ue->segData.push_back(s);        
    }
}

// Insertion without balancing
void EventTree::insertTree(Segment s) {

    NodePtr ue = this->searchTree(s.UE);
    NodePtr le = this->searchTree(s.LE);

    // Handling Upper Endpoint
    insertInitTreeHelper(ue, s, true);

    // Handling Lower End Point
    insertInitTreeHelper(le, s, false);
    
}

// Search Function
NodePtr EventTree::searchHelper(NodePtr root, Point key) {
    if (root == endNull || key.isEqual(root->data)) {
        return root;
    }

    if(key.cmp(root->data)) {
        return this->searchHelper(root->left, key);
    }
    return this->searchHelper(root->right, key);
}

NodePtr EventTree::searchTree(Point s) {
    return this->searchHelper(this->root, s);
}