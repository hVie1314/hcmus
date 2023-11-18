#include <iostream>
#define HASH_SIZE 11

using namespace std;

struct Node
{
    int value;
    Node* pNext;
};

Node* hashTable[HASH_SIZE]; 

int hashFunc(int data)
{
    return data % HASH_SIZE;
}

void insert(int data)
{
    int index = hashFunc(data);
    Node* node = new Node;
    if (!node) return;
    node->value = data;
    node->pNext = NULL;
    if (hashTable[index] == NULL)
    {
        hashTable[index] = node;
    } 
    else 
    {
        node->pNext = hashTable[index]; //insert node to head of linked list
        hashTable[index] = node;
    }   
}

int search(int data)
{
    int index = hashFunc(data);
    Node* curr = hashTable[index];
    while (curr != NULL)
    {
        if (curr->value == data) return 1;
        curr = curr->pNext;
    }
    return 0;
}

int main()
{
    insert(21);
    insert(13);
    cout << search(21) << endl;
    cout << search(9) << endl;
    cout << search(5) << endl;
    return 0;
}