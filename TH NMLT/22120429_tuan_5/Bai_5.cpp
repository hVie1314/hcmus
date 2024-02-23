#include <iostream>

using namespace std;

//a. use recusion
int Fib_Recusion(int n)
{
	if (n <= 1) return n;
	return Fib_Recusion(n - 1) + Fib_Recusion(n - 2);
}

//b. do not use recusion
int Fib(int n)
{
	int a = 1, b = 0, tmp;
	while (n > 0)
	{
		tmp = a;
		a += b;
		b = tmp;
		n--;
	}
	return b;
}

int main()
{
	int n = 0;
	cout << "Enter n: "; cin >> n;
	cout << "a. Use Recusion _ Fib(" << n << "): " << Fib_Recusion(n) << endl;
	cout << "b. Do not use Recusion _ Fib(" << n << "): " << Fib(n) << endl;
	return 0;
}

/*
While loop
	Time complexity: O(N)
	Space complexity: Constant
	Function calls: 51
	Time needed: 0.000001ms

Recursion
	Time complexity: O(2^N)
	Space complexity: O(n)
	Function calls: 20.365.011.074
	Time needed: 176.742ms
*/