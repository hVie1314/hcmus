#include <iostream>

using namespace std;

int MaxOf2(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int MaxOf4(int a, int b, int c, int d)
{
	return MaxOf2(MaxOf2(a, b), MaxOf2(c, d));
}

int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	cout << "Enter 4 integer numbers: ";
	cin >> a >> b >> c >> d;
	cout << MaxOf4(a, b, c, d) << endl;
	return 0;
}