#include <iostream>

struct Node {
    int data;
    Node* pNext;
};

Node* createNode(int data) {
    Node* node = new Node;
    if (!node) return NULL;
    node->data = data;
    node->pNext = NULL;
    return node;
}

Node* pushFront(Node*& pHead, int data) {
    Node* node = createNode(data);
    if (!pHead) {
        pHead = node;
        return pHead;
    }
    node->pNext = pHead;
    pHead = node;
    return pHead;
}

Node* pushBack(Node*& pHead, int data) {
    Node* node = createNode(data);
    if (!pHead) {
        pHead = node;
        return pHead;
    }
    Node* pCurr = pHead;
    while (pCurr->pNext) {
        pCurr = pCurr->pNext;
    }
    pCurr->pNext = node;
    return pHead;
}

Node* pushMiddle(Node*& pHead, int data, Node* pPos) {
    if(!pHead || !pPos) return pHead; 
    Node* node = createNode(data);
    Node* temp = pPos->pNext;
    pPos->pNext = node;
    node->pNext = temp;
    return pHead;
}

Node* delFront(Node*& pHead) {
    if (!pHead) return NULL; //NULL
    Node* temp = pHead;
    pHead = pHead->pNext;
    delete temp;
    return pHead;
}

Node* delBack(Node*& pHead) {
    if (!pHead) return NULL;
    if (!pHead->pNext) {
        delete pHead;
        pHead = NULL;
        return pHead;
    }
    Node* pCurr = pHead;
    while (pCurr->pNext->pNext) {
        pCurr = pCurr->pNext;
    }
    Node* temp = pCurr->pNext;
    pCurr->pNext = pCurr->pNext->pNext;
    delete temp;
    return pHead;
}

Node* delMiddle(Node*& pHead, Node* pPos) { //delete node after pPos
    if (!pHead || !pPos || !pPos->pNext) return pHead;
    Node* temp = pPos->pNext;
    pPos->pNext = pPos->pNext->pNext;
    delete temp;
    return pHead;
}

void delAll(Node*& pHead) {
    if (!pHead) return;
    Node* pCurr = pHead;
    Node* temp = NULL;
    while (pCurr) {
        temp = pCurr;
        pCurr = pCurr->pNext;
        delete temp;
    }
    pHead = NULL;
}

void printList(Node* pHead) {
    if (!pHead) return;
    Node* pCurr = pHead;
    while (pCurr) {
        std::cout << pCurr->data << " ";
        pCurr = pCurr->pNext;
    }
}

Node* findNode(Node* pHead, int data)
{
    if (!pHead) return NULL;
    Node* pCurr = pHead;
    while (pCurr) {
        if (pCurr->data == data) {
            return pCurr;
        }
        pCurr = pCurr->pNext;
    }
    return NULL;
}

int main() {
    Node* pHead = NULL;
    pushFront(pHead, 1);
    pushFront(pHead, 2);
    pushBack(pHead, 3);
    pushBack(pHead, 4);
    printList(pHead);
    std::cout << std::endl;
    // 2 -> 1 -> 3 -> 4
    Node* found = findNode(pHead, 1);
    pushMiddle(pHead, 5, found);
    printList(pHead);
    std::cout << std::endl;
    // 2 -> 1 -> 5 -> 3 -> 4
    delFront(pHead);
    printList(pHead);
    std::cout << std::endl;
    // 1 -> 5 -> 3 -> 4
    delBack(pHead);
    printList(pHead);
    std::cout << std::endl;
    // 1 -> 5 -> 3
    delMiddle(pHead, found);
    printList(pHead);
    // 1 -> 3

    delAll(pHead);
    return 0;
}