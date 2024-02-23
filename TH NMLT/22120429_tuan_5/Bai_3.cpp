#include <iostream>
#include <iomanip> 

using namespace std;

float SumFrom1ToN(unsigned int n)
{
	float sum = 0.0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

//a. use recusion
float S_Recusion(unsigned int n)
{
	if (n == 1) return 0;
	return (1.0 / SumFrom1ToN(n)) + S_Recusion(--n);
}

//b. do not use recusion
float S(unsigned int n)
{
	float sum = 1;
	for (int i = 2; i <= n; i++)
	{
		sum += 1.0 / SumFrom1ToN(i);
	}
	return sum;
}


int main()
{
	unsigned int n = 0;
	cout << "Enter n: "; cin >> n;
	cout << "a. Use Recusion S(" << n << "): " << setprecision(3) << S_Recusion(n) << endl;
	cout << "b. Do not use Recusion S(" << n << "): " << setprecision(3) << S(n) << endl;
	return 0;
}