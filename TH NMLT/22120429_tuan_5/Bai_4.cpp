#include <iostream>

using namespace std;

void Swap(float &a, float &b)
{
	float tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	float a = 0, b = 0;
	cout << "Enter 2 number: " << endl;
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	Swap(a, b);
	cout << "Numbers after swap: " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	return 0;
}