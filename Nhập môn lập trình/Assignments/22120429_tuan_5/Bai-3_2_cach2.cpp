/*
Bài 3. Đếm số lượng các phần tử có giá trị khác nhau trong mảng 
một chiều các số thực.
*/

//Method 2: Đếm phân phối

#include <iostream>

using namespace std;

void Input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

int Count(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int check = 0;
		for (int j = i; j < n; j++)
		{
			if (a[i] == a[j])
			{
				check++;
			}
		}
		if (check == 1)
			count++;
	}
	return count;
}

int main()
{
	int a[100];
	int n;
	cout << "Enter numbers of elements of array: "; cin >> n;
	Input(a, n);
	cout << Count(a, n) << endl;
	return 0;
}