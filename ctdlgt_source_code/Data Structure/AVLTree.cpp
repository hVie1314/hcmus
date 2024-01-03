#include <iostream>

using namespace std;

struct AVLNode
{
    int data;
    AVLNode* pLeft;
    AVLNode* pRight;
    int height;
};

struct AVLTree
{
    AVLNode* root;
};

void initialize(AVLTree*& tree)
{
    tree = new AVLTree;
    if (!tree)
    {
        return;
    }
    tree->root = nullptr;
}

AVLNode* createNode(int val)
{
    AVLNode* node = new AVLNode;
    if (!node)
    {
        return nullptr;
    }
    node->data = val;
    node->pLeft = nullptr;
    node->pRight = nullptr;
    node->height = 1;
    return node;
}

int height(AVLNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int updateHeight(AVLNode* node)
{
    return max(height(node->pLeft), height(node->pRight)) + 1;
}

int getBalance(AVLNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->pLeft) - height(node->pRight);
}

AVLNode* singleRightRotate(AVLNode* node)
{
    AVLNode* temp = node->pLeft;
    node->pLeft = temp->pRight;
    temp->pRight = node;
    node->height = updateHeight(node);
    temp->height = updateHeight(temp);
    return temp;
}

AVLNode* singleLeftRotate(AVLNode* node)
{
    AVLNode* temp = node->pRight;
    node->pRight = temp->pLeft;
    temp->pLeft = node;
    node->height = updateHeight(node);
    temp->height = updateHeight(temp);
    return temp;
}

AVLNode* doubleRightRotate(AVLNode* node)
{
    node->pLeft = singleLeftRotate(node->pLeft);
    return singleRightRotate(node);
}

AVLNode* doubleLeftRotate(AVLNode* node)
{
    node->pRight = singleRightRotate(node->pRight);
    return singleLeftRotate(node);
}

AVLNode* insertNode(AVLNode* node, int val)
{
    if (node == nullptr)
    {
        return createNode(val);
    }
    if (val == node->data)
    {
        return node; // do nothing
    }
    // insert to left
    else if (val < node->data)
    {
        node->pLeft = insertNode(node->pLeft, val);
        // check balance 
        if (getBalance(node) == 2)
        {
            // left - left case 
            if (val < node->pLeft->data)
            {
                return singleRightRotate(node);
            }
            else // left - right case
            {
                return doubleRightRotate(node);
            }
        }
    }
    // val > node->data
    // insert to right
    else
    {
        node->pRight = insertNode(node->pRight, val);
        // check balance
        if (getBalance(node) == -2)
        {
            // right - right case
            if (val > node->pRight->data)
            {
                return singleLeftRotate(node);
            }
            else // right - left case
            {
                return doubleLeftRotate(node);
            }
        }
    }

    // update height
    node->height = updateHeight(node);
    return node;
}

void insert(AVLTree* tree, int val)
{
    tree->root = insertNode(tree->root, val);
}

AVLNode* findMinNode(AVLNode* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->pLeft == nullptr)
    {
        return node;
    }
    else
    {
        return (findMinNode(node->pLeft));
    }
}

AVLNode* findMaxNode(AVLNode* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->pRight == nullptr)
    {
        return node;
    }
    else
    {
        return findMaxNode(node->pRight);
    }
}

AVLNode* removeNode(AVLNode* node, int val)
{
    //  STEP 1: remove like BS tree
    if (node == nullptr)
    {
        return nullptr;
    }
    if (val < node->data)
    {
        node->pLeft = removeNode(node->pLeft, val);
    }
    else if (val > node->data)
    {
        node->pRight = removeNode(node->pRight, val);
    }
    // val == node->data
    // node found 
    else 
    {
        // if node has 1 or 0 child 
        if (node->pLeft == nullptr || node->pRight == nullptr)
        {
            AVLNode* temp = node;
            if (node->pLeft == nullptr)
            {
                node = node->pRight;
            }
            else
            {
                node = node->pLeft;
            }
            delete temp;
            return node;
        }
        // else node has 2 children
        AVLNode* temp = findMaxNode(node->pLeft);
        node->data = temp->data;
        node->pLeft = removeNode(node->pLeft, temp->data);
    }
    if (node == nullptr)
    {
        return node;
    }

    // STEP 2: update height
    node->height = updateHeight(node);

    //STEP 3: check balance 
    int balance = getBalance(node);
    if (balance == 2) // node is unbalance to left
    {
        // left - left case
        if (getBalance(node->pLeft) >= 0)
        {
            return singleRightRotate(node);
        }
        else // left - right case`
        {
            return doubleRightRotate(node);
        }
    }
    else if (balance == -2) // node is unbalance to right 
    {
        // right - right case 
        if (getBalance(node->pRight) <= 0)
        {
            return singleLeftRotate(node);
        }
        else // right - left case 
        {
            return doubleLeftRotate(node);
        }
    }
    return node;
}

void remove(AVLTree* tree, int val)
{
    tree->root = removeNode(tree->root, val);
}

void LNRTravel(AVLNode* node)
{
    if (node == nullptr)
    {
        return;
    }
    LNRTravel(node->pLeft);
    cout << node->data << " ";
    LNRTravel(node->pRight);
}

void deleteTree(AVLNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->pLeft);
    deleteTree(root->pRight);
    delete root;
    root == nullptr;
}

void deinitialize(AVLTree*& tree)
{
    if (tree == nullptr)
    {
        return;
    }
    deleteTree(tree->root);
    delete tree;
    tree = nullptr;
}

int main()
{
    AVLTree* tree = nullptr;
    initialize(tree);

    insert(tree, 5);
    insert(tree, 9);
    insert(tree, 0);
    insert(tree, 7);
    insert(tree, 3);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 2);
    insert(tree, 1);
    insert(tree, 6);
    insert(tree, 8);

    cout << "In-order traversal after inserting: ";
    LNRTravel(tree->root);
    cout << endl;

    remove(tree, 1);
    remove(tree, 5);
    remove(tree, 9);
    remove(tree, 3);
    remove(tree, 7);

    cout << "In-order traversal after removing: ";
    LNRTravel(tree->root);
    cout << endl;

    deinitialize(tree);

    return 0;
}