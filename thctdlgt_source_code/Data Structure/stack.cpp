#include <iostream>

struct Stack
{
    int data;
    Stack* pNext;
};

Stack* createStack(int data) {
    Stack* stack = new Stack;
    if (!stack) return NULL;
    stack->data = data;
    stack->pNext = NULL;
    return stack;
}

bool empty(Stack* stack) {
    return stack == NULL;
}

int size(Stack* stack) {
    if (!stack) return 0;
    int count = 0;
    Stack* pCurr = stack;
    while (pCurr) {
        ++count;
        pCurr = pCurr->pNext;
    }
    return count;    
}

Stack* push(Stack*& stack, int data)
{
    Stack* st = createStack(data);
    if (!stack) {
        stack = st;
         return stack;
    }
    st->pNext = stack;
    stack = st;
    return stack;
}

int top(Stack* stack) 
{
    if (!stack) return -10000;
    return stack->data;
}

int pop(Stack*& stack) {
    if (!stack) return -10000;
    int data = stack->data;
    Stack* temp = stack;
    stack = stack->pNext;
    delete temp;
    return data;
}

void delStack(Stack*& stack) {
    if (!stack) return;
    Stack* temp = NULL;
    while (stack) {
        temp = stack;
        stack = stack->pNext;
        delete temp;
    } 
}

int  main() {
    Stack* stack = NULL;
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    std::cout << size(stack) << std::endl;
    while (!empty(stack)) {
        std::cout << top(stack) << std::endl;
        pop(stack);
    }

    delStack(stack);
    return 0; 
}