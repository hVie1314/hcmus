#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* pNext;
	Node* pRev;
};

struct Queue
{
	Node* pFront;
	Node* pRear;
};

void initialize(Queue*& que)
{
	que = new Queue;
	que->pFront = nullptr;
	que->pRear = nullptr;
}

void deinitialize(Queue*& que)
{
	while (que->pFront != nullptr)
	{
		Node* temp = que->pFront;
		que->pFront = que->pFront->pNext;
		delete temp;
	}
	delete que;
	que = nullptr;
}

Node* createNode(int val)
{
	Node* node = new Node;
	if (!node) return nullptr;
	node->data = val;
	node->pNext = nullptr;
	node->pRev = nullptr;
	return node;
}

bool isEmpty(Queue* que)
{
	return que->pFront == nullptr && que->pRear == nullptr;
}

void push(Queue* que, int val)
{
	Node* node = createNode(val);
	if (isEmpty(que))
	{
		que->pFront = que->pRear = node;
	}
	else
	{
		que->pRear->pNext = node;
		node->pRev = que->pRear;
		que->pRear = node;
	}
}

void pop(Queue* que)
{
	if (isEmpty(que)) return;
	Node* temp = que->pFront;
	que->pFront = que->pFront->pNext;
	delete temp;
}

int top(Queue* que)
{
	if (isEmpty(que))
	{
		// throw an exception or return a special value to handle the error
		cerr << "Queue is empty" << endl;
		throw exception();
	}
	return que->pFront->data;
}

int main()
{
	Queue* que = nullptr;
	initialize(que);

	push(que, 1);
	push(que, 2);
	push(que, 3);
	push(que, 4);
	push(que, 5);

	while (!isEmpty(que))
	{
		cout << top(que) << " ";
		pop(que);
	}
	deinitialize(que);
	return 0;
}