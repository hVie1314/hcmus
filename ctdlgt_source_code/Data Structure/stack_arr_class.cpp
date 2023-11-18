#include <iostream>

using namespace std;

#define MAX_SIZE 100

struct Stack
{
	int data[MAX_SIZE];
	int top;
};

void initialize(Stack*& stack)
{
	stack = new Stack;
	stack->top = 0;
}

void deInitialize(Stack* stack)
{

}

bool isEmpty(Stack* stack)
{
	return stack->top == 0;
}

bool isFull(Stack* stack)
{
	return stack->top == MAX_SIZE;
}

void push(Stack* stack, int val)
{
	if (isFull(stack))
	{
		cout << "Err: stack is full" << endl;
		return;
	}
	stack->data[stack->top++] = val;
}
void pop(Stack* stack)
{
	if (isEmpty) return;
	stack->top--;
}

int top(const Stack* stack)
{
	return stack->data[stack->top - 1];
}

int main()
{

	return 0;
}

