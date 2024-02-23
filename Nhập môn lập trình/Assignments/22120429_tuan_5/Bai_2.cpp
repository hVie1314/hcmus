/*
Bài 2. Tính tổng các phần tử có giá trị lớn hơn giá trị liền trước nó 
trong mảng một chiều các số thực.
*/

#include <iostream>

using namespace std;

void Input(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

float Sum(float a[], int n) 
{
	float sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1])
		{
			sum += a[i];
		}
	}
	return sum;
}

int main()
{
	int n; 
	cout << "Enter numbers of elements of array: "; cin >> n;
	float a[100];
	Input(a, n);
	cout << "Sum: " << Sum(a, n);
	return 0;
}