#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a, b;
	cout << "Enter a, b: ";
	cin >> a >> b;
	int tong, hieu, tich, luyThua;
	float thuong;
	char symbol;
	cout << "Enter calculation (+, -, *, /, ^): ";
	cin >> symbol;
	switch (symbol) {
		case '+': 
			tong = a + b;
			cout << "Sum: " << tong << endl;
			break;
		case '-':
			hieu = a - b;
			cout << "Sub: " << hieu << endl;
			break;
		case '*':
			tich = a * b;
			cout << "Mul: " << tich << endl;
			break;
		case '/':
			thuong = a / b;
			cout << "Div: " << thuong << endl;
			break;
		case '^':
			luyThua = pow(a,b);
			cout << "luyThua: " << luyThua << endl;
	}
	return 0;
}