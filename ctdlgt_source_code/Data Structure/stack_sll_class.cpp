#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* pNext;
};

struct Stack
{
	Node* pTop;
};

void initialize(Stack*& stack)
{
	stack = new Stack;
	stack->pTop = nullptr;
}

void deinitialize(Stack*& stack)
{
	while (stack->pTop != nullptr)
	{
		Node* temp = stack->pTop;
		stack->pTop = stack->pTop->pNext;
		delete temp;
	}
	delete stack;
	stack = nullptr;
}

Node* createNode(int val)
{
	Node* node = new Node;
	if (!node) return nullptr;
	node->data = val;
	node->pNext = nullptr;
	return node;
}

bool isEmpty(Stack* stack)
{
	return stack->pTop == nullptr;
}

void push(Stack* stack, int val)
{
	Node* node = createNode(val);
	if (isEmpty(stack))
	{
		stack->pTop = node;
	}
	else
	{
		node->pNext = stack->pTop;
		stack->pTop = node;
	}
}

int top(Stack* stack)
{
	if (isEmpty(stack))
	{
		// throw an exception or return a special value to handle the error
		cerr << "Queue is empty" << endl;
		throw exception();
	}
	return stack->pTop->data;
}

void pop(Stack* stack)
{
	if (isEmpty(stack)) return;
	Node* temp = stack->pTop;
	stack->pTop = stack->pTop->pNext;
	delete temp;
}

int main()
{
	Stack* stack = nullptr;
	initialize(stack);

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);

	while (!isEmpty(stack))
	{
		cout << top(stack) << " ";
		pop(stack);
	}

	deinitialize(stack);
	return 0;
}