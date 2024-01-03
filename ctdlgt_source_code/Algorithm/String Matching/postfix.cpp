#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

bool isNum(char c)
{
	if (c >= '0' && c <= '9') return true;
	return false;
}

int getPriority(char c)
{
	if (c == '+' || c == '-')
	{
		return 1;
	}
	if (c == '*' || c == '/' || c == '%')
	{
		return 2;
	}
	return 0;
}

string infixToPostfix(string infix)
{
	string postfix;
	stack<char> stack;

	for (int i = 0; i < infix.size(); i++)
	{
		// nếu là rỗng thì bỏ qua
		if (infix[i] == ' ')
		{
			continue;
		}
		// nếu là toán hạng thì cộng vào postfix
		else if (isNum(infix[i]))
		{
			postfix += infix[i];
		}
		// nếu là ( thì push vào stack
		else if (infix[i] == '(')
		{
			stack.push(infix[i]);
		}
		// nếu là ) thì: 
		else if (infix[i] == ')')
		{
			// cộng vào trong postfix cho đến khi gặp (
			while (stack.top() != '(' && !stack.empty())
			{
				postfix += stack.top();
				stack.pop();
			}
			// và xóa dấu ( đó 
			stack.pop();
		}
		// nếu là toán tử thì: 
		else if (isOperator(infix[i]))
		{
			// nếu stack rỗng thì push vào trong stack
			if (stack.empty())
			{
				stack.push(infix[i]);
			}
			// nếu đầu stack không phải là toán tử thì push vào trong stack
			else if (stack.top() == '(')
			{
				stack.push(infix[i]);
			}
			// nếu đầu stack là một toán tử thì: 
			else
			{
				// kiểm tra nếu toán tử hiện tại có độ ưu tiên lớn hơn toán tử ở đầu stack
				// thì push vào đầu stack
				if (getPriority(infix[i]) > getPriority(stack.top()))
				{
					stack.push(infix[i]);
				}
				// nếu toán tử hiện tại có độ ưu tiên bằng với toán tử ở đầu stack
				// thì cộng đầu stack vào postfix sau đó push dô stack
				else if (getPriority(infix[i]) == getPriority(stack.top()))
				{
					postfix += stack.top();
					stack.pop();
					stack.push(infix[i]);
				}
				// nếu toán tử hiện tại có độ ưu tiên nhỏ hơn toán tử ở đầu stack
				else
				{
					// cộng vào postfix cho đến khi stack rỗng hoặc 
					// cho đến khi đầu stack không phải là một toán tử 
					while (!stack.empty() && isOperator(stack.top()))
					{
						postfix += stack.top();
						stack.pop();
					}
					stack.push(infix[i]);
				}
			}
		}
	}
	// nếu sau khi duyệt xong infix mà stack vẫn còn thì cộng hết vào trong postfix
	while (!stack.empty())
	{
		postfix += stack.top();
		stack.pop();
	}
	return postfix;
}

int postfixCal(string postfix)
{
	int res = 0;
	stack<int> stack;
	
	for (int i = 0; i < postfix.size(); i++)
	{
		if (isNum(postfix[i]))
		{
			stack.push(postfix[i] - '0');
		}
		else
		{
			int val1 = stack.top();
			stack.pop();
			int val2 = stack.top();
			stack.pop();
			int cal = 0;
			
			switch (postfix[i])
			{
			case '+':
				cal = val2 + val1;
				break;
			case '-':
				cal = val2 - val1;
				break;
			case '*':
				cal = val2 * val1;
				break;
			case '/':
				cal = val2 / val1;
				break;
			case '%':
				cal = val2 % val1;
			}
			stack.push(cal);
		}
	}
	return stack.top();
}

int main()
{
	string infix;
	string postfix;

	getline(cin, infix);

	postfix = infixToPostfix(infix);
	for (int i = 0; i < postfix.size(); i++)
	{
		cout << postfix[i] << " ";
	}
	cout << endl << postfixCal(postfix) << endl;
	return 0;
}