#include <iostream>
using namespace std;

struct NODE {
    int data;
    NODE* pLeft;
    NODE* pRight;
};

//1
NODE* createBSTNode(int data) {
    NODE* node = new NODE;
    if (!node) return nullptr;
    node->data = data;
    node->pLeft = nullptr;
    node->pRight = nullptr;
    return node;
}

//2
void NLR(NODE* pRoot) {
    if (!pRoot) return;
    
    std::cout << pRoot->data << " ";
    NLR(pRoot->pLeft);
    NLR(pRoot->pRight);
}

//3 
int sumNode(NODE* pRoot) {
    if (!pRoot) return 0;
    return pRoot->data + sumNode(pRoot->pLeft) + sumNode(pRoot->pRight); 
}

//4
int countLeaf(NODE* pRoot) {
    if (!pRoot) return 0;
    if (!pRoot->pLeft && !pRoot->pRight) return 1;
    return countLeaf(pRoot->pLeft) + countLeaf(pRoot->pRight);
}

//5
NODE* Search(NODE* pRoot, int x) {
    if (!pRoot || pRoot->data == x) return pRoot;
    if (x < pRoot->data) {
        return Search(pRoot->pLeft, x);
    }
    else if (x > pRoot->data) {
        return Search(pRoot->pRight, x);
    }
    else return nullptr;
}

//6
void Insert(NODE*& pRoot, int x) {
    if (!pRoot) {
        NODE* node = new NODE;
        node->data = x;
        node->pLeft = nullptr;
        node->pRight = nullptr;
        pRoot = node;
    }
    else {
        if (x == pRoot->data) return;
        else if (x < pRoot->data) {
            Insert(pRoot->pLeft, x);
        }
        else {
            Insert(pRoot->pRight, x);
        }
    }
}

//8
int height(NODE* pRoot) {
    if (!pRoot) return 0;
    return 1 + std::max(height(pRoot->pLeft), height(pRoot->pRight));
}

bool isAVL(NODE* pRoot) {
    if (!pRoot) return 1;
    if (abs(height(pRoot->pLeft) - height(pRoot->pRight)) >= 2) return 0;
    return isAVL(pRoot->pLeft);
    return isAVL(pRoot->pRight);
}



 
