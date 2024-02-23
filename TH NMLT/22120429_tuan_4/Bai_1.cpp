#include <iostream>
#include <math.h>

using namespace std;

double calculator(float a, float b, char opt) {
	double result = 0;
	switch (opt) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		case '^':
			result = pow(a,b);
			break;
	}
	return result;
}

int main() {
	double a = 0, b = 0;
	char opt = 'null';
	cout << "Enter a, b: ";
	cin >> a >> b;
	cout << "Enter operator (+, -, *, /, ^): ";
	cin >> opt;
	cout << "Testing Calculate" << endl;
	cout << "Result: " << calculator(a, b, opt) << endl;
	return 0;
}