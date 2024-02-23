#include <iostream>

using namespace std;

//a. use recusion: Euclidean Algorithm
int UCLN_Recusion(int a, int b)
{
	if (b == 0) return a;
	return UCLN_Recusion(b, a % b);
}

//b. do not use recusion
int UCLN(int a, int b)
{
	while (a * b != 0)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return a + b;
}

int main()
{
	int a = 0, b = 0;
	cout << "Enter a, b: "; cin >> a >> b;
	cout << "a. Use Recusion: " << UCLN_Recusion(a, b) << endl;
	cout << "b. Do not use Recusion: " << UCLN(a, b) << endl;
	return 0;
}