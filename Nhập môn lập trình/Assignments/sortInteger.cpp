//given an integer. soft digits in integer to decreasing sequence
//just use normal math to calculate integer, do not use array or vector
//digit in integer don't repeat

#include <iostream>

using namespace std;

int main()
{
	int n = 0, m = 0, t = 0, len = 1, max1 = 0, max2 = 0, res = 0;

	cout << "Enter number: "; cin >> n;

	//get length end max digit of integer
	m = n;
	while (m != 0)
	{
		len++;
		t = m % 10;
		m /= 10;
		if (t > max1) max1 = t;
	}

	res = max1;

	while (len > 2)
	{
		m = n;
		max2 = 0;
		while (m != 0)
		{
			t = m % 10;
			m /= 10;
			if (t >= max2 && t < max1)
			{
				max2 = t;
			}			
		}
		res = res * 10 + max2;
		max1 = max2;
		len--;
	}
	cout << res << endl;

	return 0;
}