#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Stack {
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

int calPostfix(string str) {
    int n = str.length();
    Stack* st = NULL;
    for (int i = 0; i < n; i++) {
        if (isdigit(str[i])) {
            bool minus = false;
            if (str[i - 1] == '-') {
                minus = true;
            }
            string temp = "";
            temp += str[i];
            int j = 0;
            for (j = i + 1; j < n; j++) {
                if (isdigit(str[j])) {
                    temp += str[j];
                }
                else break;
            }
            int num = stoi(temp);
            if (minus) {
                num = - num;
            }
            push(st, num);
            i = j;
        }
        else if (str[i] == '+') {
            int num2 = pop(st);
            int num1 = pop(st);
            int res = num1 + num2;
            push(st, res);
        }
        else if (str[i] == '-' && !isdigit(str[i + 1])) {
            int num2 = pop(st);
            int num1 = pop(st);
            int res = num1 - num2;
            push(st, res);
        }
        else if (str[i] == '*') {
            int num2 = pop(st);
            int num1 = pop(st);
            int res = num1 * num2;
            push(st, res);
        }
        else if (str[i] == '/') {
            int num2 = pop(st);
            int num1 = pop(st);
            int res = num1 / num2;
            push(st, res);
        }
        else if (str[i] == '^') {
            int num2 = pop(st);
            int num1 = pop(st);
            int res = pow(num1, num2);
            push(st, res);
        }
    }
    return top(st);
}

int main() {
    string str = "";
    getline(cin, str);
    int res = calPostfix(str);
    cout << res;
    return 0;
}