#include <iostream>

using namespace std;

struct DNode
{
	int data;
	DNode* pNext;
	DNode* pPre;
};

struct DList
{
	DNode* pHead;
	DNode* pTail;
};

void initialize(DList* &list)
{
	list = new DList;
	list->pHead = list->pTail = nullptr;
}

bool isEmpty(DList* list)
{
	return (list->pHead == nullptr) && (list->pTail == nullptr);
}

DNode* createDNode(int val)
{
	DNode* node = new DNode;
	if (node == nullptr) return nullptr;
	node->data = val;
	node->pNext = nullptr;
	node->pPre = nullptr;
	return node;
}

void insertHead(DList* list, int val)
{
	DNode* node = createDNode(val);
	//check if list is empty
	if (isEmpty(list))
	{
		list->pHead = list->pTail = node;
		return;
	}
	node->pNext = list->pHead;
	list->pHead->pPre = node;
	list->pHead = node;
}

void pushBack(DList* list, int val)
{
	DNode* node = createDNode(val);
	if (isEmpty(list))
	{
		list->pHead = list->pTail = node;
		return;
	}
	node->pPre = list->pTail;
	list->pTail->pNext = node;
	list->pTail = node;
}

//insert val after node which has data = key
void insertaAfter(DList* list, int key, int val)
{

}

void insertBefore(DList* list, int key, int val)
{

}

void deleteHead(DList* list)
{

}

void  deleteTail(DList* list)
{

}

//delete node after node has val
void deleteAfter(DList* list, int val)
{

}

void deleteBefore(DList* list, int val)
{

}


void printList(DList* list)
{
	while (list->pHead != nullptr)
	{
		cout << list->pHead->data << " ";
		list->pHead = list->pHead->pNext;
	}
	cout << endl;
}

void deInitialize(DList* list)
{
	while (list->pHead != nullptr)
	{
		DNode* temp = list->pHead;
		list->pHead = list->pHead->pNext;
		delete temp;
	}
	list = nullptr;
}

int main()
{
	DList* list = nullptr;
	initialize(list);
	
	insertHead(list, 1);
	insertHead(list, 2);
	pushBack(list, 3);


	printList(list);

	return 0;
}