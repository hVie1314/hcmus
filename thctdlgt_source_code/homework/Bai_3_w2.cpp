#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 1000; 

char stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(char value) {
    if (!isFull()) {
        stack[++top] = value;
    }
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (!isEmpty()) {
        return stack[top];
    }
    return '\0';
}

string convert(string& input) {
    string result = input;
    size_t pos;

    while ((pos = result.find("and")) != string::npos) { //string::npos -> khong tim thay
        result.replace(pos, 3, "&");
    }

    while ((pos = result.find("or")) != string::npos) {
        result.replace(pos, 2, "|");
    }

    while ((pos = result.find("not")) != string::npos) {
        result.replace(pos, 3, "!");
    }

    return result;
}

string infixToPostfix(string infix) {
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix += pop();
                postfix += ' ';
            }
            if (!isEmpty() && peek() == '(') {
                pop();
            }
        } else if (c == '&' || c == '|' || c == '!') {
            while (!isEmpty() && peek() != '(') {
                postfix += pop();
                postfix += ' ';
            }
            push(c);
        } else {
            postfix += c;
            postfix += ' ';
        }
    }
    while (!isEmpty()) {
        postfix += pop();
        postfix += ' ';
    }
    return postfix;
}


int main() {
    string input = "a and (b or c)";
    string infix = convert(input);
    cout << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    return 0;
}
