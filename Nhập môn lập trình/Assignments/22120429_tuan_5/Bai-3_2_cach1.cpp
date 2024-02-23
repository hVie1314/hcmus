/*
Bài 3. Đếm số lượng các phần tử có giá trị khác nhau trong mảng 
một chiều các số thực.
*/

//Method 1: Sử dụng mảng phụ

#include <iostream>

using namespace std;

int arr[1000];

void Input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void Check(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[a[i]]++;
	}
}

int Count()
{
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] > 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int a[100];
	int n;
	cout << "Enter numbers of elements of array: "; cin >> n;
	Input(a, n);
	Check(a, n);
	cout << Count() << endl;
	return 0;
}