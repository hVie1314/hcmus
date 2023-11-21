#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct Stack {
    double* stack;
    int top;
};

void init(Stack& s, int n) {
    s.stack = new double[n];
    s.top = -1;
}

bool isStackEmpty(Stack& s) {
    return s.top == -1;
}

void push(Stack& s, double data) {
    s.stack[++s.top] = data;
}

double pop(Stack& s) {
    return s.stack[s.top--];
}

int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

string infixToPostfix(string infix){
    Stack stack;
    init(stack, infix.length());
    string postfix = "";
    for(int i = 0; i < infix.length(); i++){
        if(infix[i] == '('){
            push(stack, '(');
        } else if(infix[i] == ')'){
            while(!isStackEmpty(stack) && stack.stack[stack.top] != '('){
                postfix += pop(stack);
                postfix += ' ';
            }
            pop(stack);
        } else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            while(!isStackEmpty(stack) && precedence(infix[i]) <= precedence(stack.stack[stack.top])){
                postfix += pop(stack);
                postfix += ' ';
            }
            push(stack, infix[i]);
        } else if(infix[i] >= '0' && infix[i] <= '9'){
            postfix += infix[i];
            if(i == infix.length() - 1 || !(infix[i + 1] >= '0' && infix[i + 1] <= '9')){
                postfix += ' ';
            }
        }
    }
    while(!isStackEmpty(stack)){
        postfix += pop(stack);
        postfix += ' ';
    }
    return postfix;
}

double calculate(string expression) {
    Stack stack;
    init(stack, expression.length());

    stringstream ss(expression);
    string token;
    while (ss >> token) {
        if (token == "+") {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            double result = operand1 + operand2;
            push(stack, result);
        } else if (token == "-") {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            double result = operand1 - operand2;
            push(stack, result);
        } else if (token == "*") {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            double result = operand1 * operand2;
            push(stack, result);
        } else if (token == "/") {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            double result = operand1 / operand2;
            push(stack, result);
        } else {
            push(stack, stod(token));
        }
    }
    return pop(stack);
}

int main() {
    string infix = "(22-88)*30  -   5/10  -       ((100+3)/3)";
    string postfix = infixToPostfix(infix);
    cout << "Bieu thuc hau to: " << postfix << endl;
    cout << "Gia tri cua bieu thuc: " << calculate(postfix) << endl;
    return 0;
}
