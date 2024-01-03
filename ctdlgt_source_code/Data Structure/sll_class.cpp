#include <iostream>

using namespace std;

struct SNode
{
    int key;
    SNode* pNext;
};

struct SList
{
    SNode* pHead;
    SNode* pTail;
};
/*
void initialize(SList** w_list)
{
    *w_list = new SList;
    (*w_list) ->pHead = nullptr;
    (*w_list) ->pTail = nullptr;
}
*/

void initialize(SList*& w_list)
{
    w_list = new SList;
    w_list->pHead = nullptr;
    w_list->pTail = nullptr;
    // w_list->pHead = w_list->pTail = nullptr;
}
/*
void initialize(SList& w_list)
{
    w_list.pHead = w_list.pTail = nullptr;
}

SList* initialize()
{
    return new SList{ nullptr, nullptr };
}
*/


SNode* newNode(int value)
{
    SNode* node = new SNode;
    if (node == nullptr) return nullptr;
    node->key = value;
    node->pNext = nullptr;
    return node;
}

// This function checks if the list is empty.
bool isEmpty(const SList* r_list)
{
    return (r_list->pHead == nullptr && r_list->pTail == nullptr);
}

// This function adds a new node with the specified value to the front of the list.
SNode* pushFront(SList* u_list, int r_val)
{
    SNode* node = newNode(r_val);
    if (isEmpty(u_list)) 
    {
        u_list->pHead = node = u_list->pTail = node;
        return node;
    }
    node->pNext = u_list->pHead;
    u_list->pHead = node;
    return node;
}

// This function adds a new node with the specified value to the back of the list.
SNode* pushBack(SList* u_list, int r_val)
{
    SNode* node = newNode(r_val);
    if (isEmpty(u_list)) {
        u_list->pHead = u_list->pTail = node;
        return node;
    }
    u_list->pTail->pNext = node;
    u_list->pTail = node;
    return node;
}

// This function inserts a new node with the specified value after the specified node.
SNode* insertAfter(SList* u_list, SNode* u_node, int r_val)
{
    if (u_list == nullptr || u_node == nullptr) return nullptr;
    SNode* node = newNode(r_val);
    node->pNext = u_node->pNext;
    u_node->pNext = node;
    //check neu la node cuoi -> set lai pTail
    if (u_list->pTail == u_node)
    {
        u_list->pTail = node;
    }
    return node;
}

SNode* insertBefore(SList* u_list, SNode* u_node, int r_val)
{
    if (u_list == nullptr || u_node == nullptr) return;
    if (u_node == u_list->pHead)
    {
        pushFront(u_list, r_val);
        return;
    }
    SNode* curr = u_list->pHead;
    while (curr->pNext == u_node)
    {
        curr = curr->pNext;
    }
    insertAfter(curr, r_val);
    //ideal don gian: chen phia sau sau do swap key;
    // do ....
}

// This function removes the node at the front of the list.
void popFront(SList* u_list)
{
    if (isEmpty(u_list)) return;
    SNode* node = u_list->pHead;
    u_list->pHead = node->pNext;
    if (u_list->pTail == node)
    {
        u_list->pTail = nullptr;
    }
    delete node;
}

// This function removes the node at the back of the list.
void popBack(SList* u_list)
{
    if (isEmpty(u_list)) return;
    SNode* node = u_list->pHead;
    //check if list only has an element
    if (u_list->pHead == u_list->pTail)
    {
        u_list->pHead = u_list->pTail = nullptr;
        delete node;
        return;
    }
    while (node->pNext != u_list->pTail)
    {
        node = node->pNext;
    }
    delete u_list->pTail;
    u_list->pTail = node;
    u_list->pTail->pNext = nullptr;
}

// This function removes the node after the specified node.
void removeAfter(SNode* u_node)
{
    if (u_node == nullptr || u_node->pNext == nullptr) return;
    SNode* temp = u_node->pNext;
    u_node->pNext = temp->pNext;
    delete temp;
}

// This function searches for a node with the specified value in the list.
SNode* search(SList* r_list, int r_val)
{
    SNode* temp = r_list->pHead;
    while (temp != nullptr) {
        if (temp->key == r_val) {
            return temp;
        }
        temp = temp->pNext;
    }
    return nullptr;
}

// This function deinitializes the list by freeing the memory allocated for the list and its nodes.
void deinitialize(SList** w_list)
{
    //better
    SNode* temp = (*w_list)->pHead;
    while (temp != nullptr) {
        SNode* next = temp->pNext;
        delete temp;
        temp = next;
    }
    delete* w_list;
    *w_list = nullptr;
    
    /*while (!isEmpty(*w_list))
    {
        popFront(*w_list);
    }
    delete (*w_list);
    *w_list = nullptr;*/
}

// This function merges the two lists u_list_a and u_list_b. The result is stored in u_list_a.
void merge(SList* u_list_a, SList* u_list_b)
{
    if (u_list_b->pHead == nullptr) {
        return;
    }
    if (u_list_a->pHead == nullptr) {
        *u_list_a = *u_list_b;
        u_list_b->pHead = nullptr;
        u_list_b->pTail = nullptr;
        return;
    }
    u_list_a->pTail->pNext = u_list_b->pHead;
    u_list_a->pTail = u_list_b->pTail;
    u_list_b->pHead = nullptr;
    u_list_b->pTail = nullptr;
}

// This function swaps the contents of the two lists u_list_a and u_list_b.
void swap(SList* u_list_a, SList* u_list_b)
{
    SList* temp = u_list_a;
    u_list_a = u_list_b;
    u_list_a = temp;
}

// This function reverses the order of the nodes in the list u_list.
void reverse(SList* u_list)
{
    SNode* prev = nullptr;
    SNode* curr = u_list->pHead;
    SNode* next = nullptr;
    u_list->pTail = u_list->pHead;
    while (curr != nullptr) {
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }
    u_list->pHead = prev;
}

// This function sorts the nodes in the list u_list in ascending order based on their key values.
void sort(SList* u_list) {
    SNode* current = u_list->pHead;
    while (current != nullptr) {
        SNode* min = current;
        SNode* temp = current->pNext;
        while (temp != nullptr) {
            if (temp->key < min->key) {
                min = temp;
            }
            temp = temp->pNext;
        }
        int temp_val = current->key;
        current->key = min->key;
        min->key = temp_val;
        current = current->pNext;
    }
}

void print(const SList* r_list) {
    SNode* node = r_list->pHead;
    while (node != nullptr) {
        cout << node->key << " ";
        node = node->pNext;
    }
    cout << endl;
}

int main()
{
    SList* my_list;
    initialize(my_list);

    pushFront(my_list, 3);
    pushBack(my_list, 4);
    pushFront(my_list, 2);
    pushBack(my_list, 5);
    insertAfter(my_list->pHead, 1);

    cout << "Initial list contents: ";
    print(my_list);

    cout << "Searching for value 3..." << endl;
    SNode* search_result = search(my_list, 3);
    if (search_result != nullptr) {
        cout << "Found value 3!" << endl;
    }
    else {
        cout << "Could not find value 3." << endl;
    }

    popFront(my_list);
    cout << "List contents after popping front: ";
    print(my_list);

    popBack(my_list);
    cout << "List contents after popping back: ";
    print(my_list);

    cout << "Reversing list..." << endl;
    reverse(my_list);
    cout << "List contents after reversing: ";
    print(my_list);

    cout << "Sorting list..." << endl;
    sort(my_list);
    cout << "List contents after sorting: ";
    print(my_list);

    deinitialize(&my_list);
    return 0;
}
