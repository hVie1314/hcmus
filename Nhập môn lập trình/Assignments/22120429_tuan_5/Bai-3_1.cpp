/*
Bài 3. Hãy kiểm tra mảng số nguyên có tồn tại 2 giá trị giống nhau liên 
tiếp hay không? 
*/

#include <iostream>

using namespace std;

void Input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

bool Check(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
			return true;
	}
	return false;
}

int main()
{
	int a[100];
	int n;
	cout << "Enter numbers of elements of array: "; cin >> n;
	Input(a, n);
	if (Check(a, n))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}