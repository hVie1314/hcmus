#include <iostream>
#include <math.h>

using namespace std;

//so arstrong 
bool IsArstrongNumber(unsigned int n)
{
	int t = n, sum = 0;
	while (t != 0)
	{
		sum += pow((t % 10), 3);
		t /= 10;
	}
	if (sum == n) return true;
	return false;
}



int main()
{
	int a, b;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;

	for (int i = a; i <= b; i++)
	{
		if (IsArstrongNumber(i)) cout << i << " ";
	}
	return 0;
}