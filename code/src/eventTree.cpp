#include "../includes/eventTree.hpp"
#include <iostream>
using namespace std;

/// Constructors and Initializers
EventTree::EventTree()
{
    endNull = new Event();
    endNull->color = 0;
    endNull->left = nullptr;
    endNull->right = nullptr;
    root = endNull;
}

void EventTree::initNull(EventPtr n, EventPtr p)
{
    n->data = Point();
    n->parent = p;
    n->left = nullptr;
    n->right = nullptr;
}

/// Print Event - Point and Segment
void EventTree::printNode(EventPtr node)
{
    cout << "\nNode - ";
    node->data.printPoint();
    cout << "Upper Segments -\n";
    for (auto seg : node->upperSeg)
    {
        seg.printSegment();
    }
    cout << "Lower Segments -\n";
    for (auto seg : node->lowerSeg)
    {
        seg.printSegment();
    }
    cout << "Interior Segments -\n";
    for (auto seg : node->cSeg)
    {
        seg.printSegment();
    }
}

/// Pre Order Traversal Helper FUnction
void EventTree::preOrderHelper(EventPtr root)
{
    if (root != endNull)
    {
        this->printNode(root);
        preOrderHelper(root->left);
        preOrderHelper(root->right);
    }
}

void EventTree::preOrder()
{
    cout << "\nPreorder Traversal\n";
    this->preOrderHelper(this->root);
}

void EventTree::postOrderHelper(EventPtr root)
{
    if (root != endNull)
    {
        postOrderHelper(root->left);
        postOrderHelper(root->right);
        this->printNode(root);
    }
}

void EventTree::postOrder()
{
    cout << "\nPostorder Traversal\n";
    this->postOrderHelper(this->root);
}

void EventTree::inOrderHelper(EventPtr root)
{
    if (root != endNull)
    {
        inOrderHelper(root->left);
        this->printNode(root);
        inOrderHelper(root->right);
    }
}

void EventTree::inOrder()
{
    cout << "\nInorder Traversal\n";
    this->inOrderHelper(this->root);
}

/// Tree Utils - Tree Operations
bool EventTree::isEmpty()
{
    return root == endNull;
}

void EventTree::rightRotate(EventPtr node)
{
    EventPtr temp = node->left;
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

void EventTree::leftRotate(EventPtr node)
{
    EventPtr temp = node->right;
    node->right = temp->left;
    if (temp->left != endNull)
    {
        temp->left->parent = node;
    }
    temp->parent = node->parent;
    if (node->parent == nullptr)
    {
        this->root = temp;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = temp;
    }
    else
    {
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

/// Insert Fucntions
/// Balancing tree after insertion
void EventTree::insertHelper(EventPtr node)
{
    EventPtr temp;

    while (node->parent->color == 1)
    {
        if (node->parent == node->parent->parent->right)
        {
            temp = node->parent->parent->left;
            /// Case-1
            if (temp->color == 1)
            {
                temp->color = 1;
                node->parent->parent->color = 1;
                node->parent->color = 0;
                node = node->parent->parent;
            }
            /// Case-2
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->parent->color = 1;
                node->parent->color = 0;
                leftRotate(node->parent->parent);
            }
        }
        else
        {
            temp = node->parent->parent->right;
            /// Case-3
            if (temp->color == 1)
            {
                temp->color = 0;
                node->parent->parent->color = 1;
                node->parent->color = 0;
                node = node->parent->parent;
            }
            /// Case-4
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->parent->color = 1;
                node->parent->color = 0;
                rightRotate(node->parent->parent);
            }
        }
        if (node == this->root)
        {
            break;
        }
    }
    this->root->color = 0;
}

void EventTree::insertInitTreeHelper(EventPtr ue, Segment temp, bool UE)
{
    Point p = UE ? temp.UE : temp.LE;
    if (ue == endNull)
    {
        Event *node = new Event();
        node->parent = nullptr;
        node->data = p;
        if (UE)
        {
            node->upperSeg.push_back(temp);
        }
        else
        {
            node->lowerSeg.push_back(temp);
        }
        node->left = endNull;
        node->right = endNull;
        node->color = 1;

        Event *node1 = new Event();
        node->parent = nullptr;

        EventPtr temp = nullptr;
        EventPtr curr = this->root;

        while (curr != endNull)
        {
            temp = curr;
            if (node->data.cmp(curr->data))
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        node->parent = temp;
        if (temp == nullptr)
        {
            root = node;
            node->color = 0;
            return;
        }
        else if (node->data.cmp(temp->data))
        {
            temp->left = node;
        }
        else
        {
            temp->right = node;
        }

        if (node->parent->parent == nullptr)
        {
            return;
        }

        insertHelper(node);
    }
    else
    {
        if (UE)
        {
            ue->upperSeg.push_back(temp);
        }
        else
        {
            ue->lowerSeg.push_back(temp);
        }
    }
}

/// Insertion without balancing
void EventTree::insertTree(Segment temp)
{

    EventPtr ue = this->searchTree(temp.UE);
    EventPtr le = this->searchTree(temp.LE);

    /// Handling Upper Endpoint
    insertInitTreeHelper(ue, temp, true);

    /// Handling Lower End Point
    insertInitTreeHelper(le, temp, false);
}

void EventTree::insertPoint(Point p, vector<Segment> seg)
{
    EventPtr ptr = this->searchTree(p);
    if (ptr == endNull)
    {
        insertPointHelper(p, seg);
    }
    else
    {
        ptr->cSeg = seg;
    }
}

void EventTree::insertPointHelper(Point p, vector<Segment> seg)
{
    Event *node = new Event();
    node->parent = nullptr;
    node->data = p;
    node->cSeg = seg;
    node->left = endNull;
    node->right = endNull;
    node->color = 1;

    Event *node1 = new Event();
    node->parent = nullptr;

    EventPtr temp = nullptr;
    EventPtr curr = this->root;

    while (curr != endNull)
    {
        temp = curr;
        if (node->data.cmp(curr->data))
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    node->parent = temp;
    if (temp == nullptr)
    {
        root = node;
        node->color = 0;
        return;
    }
    else if (node->data.cmp(temp->data))
    {
        temp->left = node;
    }
    else
    {
        temp->right = node;
    }

    if (node->parent->parent == nullptr)
    {
        return;
    }

    insertHelper(node);
}

/// Search Function Helper
EventPtr EventTree::searchHelper(EventPtr root, Point key)
{
    if (root == endNull || key.isEqual(root->data))
    {
        return root;
    }

    if (key.cmp(root->data))
    {
        return this->searchHelper(root->left, key);
    }
    return this->searchHelper(root->right, key);
}

/// Search Function
EventPtr EventTree::searchTree(Point temp)
{
    return this->searchHelper(this->root, temp);
}

/// Root accessor
EventPtr EventTree::getRoot()
{
    return root;
}

/// Get the minimum node.
EventPtr EventTree::getMinNode(EventPtr node)
{
    EventPtr temp = node;
    while (temp->left != endNull)
    {
        temp = temp->left;      
    }
    return temp;
}

/// Get the maximum node.
EventPtr EventTree::getMaxNode(EventPtr node)
{
    while (node->right != endNull)
    {
        node = node->right;
    }
    return node;
}

/// Transplant the tree - delete function helper
void EventTree::transplant(EventPtr l, EventPtr r)
{
    if (l->parent == nullptr)
    {
        root = r;
    }
    else if (l == l->parent->left)
    {
        l->parent->left = r;
    }
    else
    {
        l->parent->right = r;
    }
    r->parent = l->parent;
}

/// Delete Function
void EventTree::deleteHelper(EventPtr root, Point key)
{
    EventPtr temp = this->searchTree(key);

    if (temp == endNull)
    {
        cout << "Given point not on the Event Tree.";
        return;
    }

    EventPtr temp1 = temp;
    EventPtr temp2;
    int color = temp->color;
    if (temp->left == endNull)
    {
        temp2 = temp->right;
        transplant(temp, temp->right);
    }
    else if (temp->right == endNull)
    {
        temp2 = temp->left;
        this->transplant(temp, temp->left);
    }
    else
    {
        temp1 = getMinNode(temp->right);
        color = temp1->color;
        temp2 = temp1->right;
        if (temp1->parent == temp)
        {
            temp2->parent = temp1;
        }
        else
        {
            transplant(temp1, temp1->right);
            temp1->right = temp->right;
            temp1->right->parent = temp1;
        }

        transplant(temp, temp1);
        temp1->left = temp->left;
        temp1->left->parent = temp1;
        temp1->color = temp->color;
    }

    delete temp;
    if (color == 0)
    {
        deleteFix(temp2);
    }
}

/// Delete Fix Function
void EventTree::deleteFix(EventPtr node)
{
    EventPtr temp;
    while (node != root && node->color == 0)
    {
        if (node == node->parent->left)
        {
            temp = node->parent->right;
            if (temp->color == 1)
            {
                temp->color = 0;
                node->parent->color = 1;
                leftRotate(node->parent);
                temp = node->parent->right;
            }

            if (temp->left->color == 0 && temp->right->color == 0)
            {
                temp->color = 1;
                node = node->parent;
            }
            else
            {
                if (temp->right->color == 0)
                {
                    temp->left->color = 0;
                    temp->color = 1;
                    rightRotate(temp);
                    temp = node->parent->right;
                }

                temp->color = node->parent->color;
                node->parent->color = 0;
                temp->right->color = 0;
                leftRotate(node->parent);
                node = root;
            }
        }
        else
        {
            temp = node->parent->left;
            if (temp->color == 1)
            {
                temp->color = 0;
                node->parent->color = 1;
                rightRotate(node->parent);
                temp = node->parent->left;
            }

            if (temp->right->color == 0 && temp->right->color == 0)
            {
                temp->color = 1;
                node = node->parent;
            }
            else
            {
                if (temp->left->color == 0)
                {
                    temp->right->color = 0;
                    temp->color = 1;
                    leftRotate(temp);
                    temp = node->parent->left;
                }

                temp->color = node->parent->color;
                node->parent->color = 0;
                temp->left->color = 0;
                rightRotate(node->parent);
                node = root;
            }
        }
    }
    node->color = 0;
}

/// Delete Function
void EventTree::deleteNode(Point data)
{
    deleteHelper(this->root, data);
}