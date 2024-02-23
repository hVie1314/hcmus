#include <iostream>

using namespace std;

//a. ham nhap xuat mang
void Input(int a[], int &n)
{
	cout << "Enter number of elements of array: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Arr[" << i << "] = "; 
		cin >> a[i];
	}
	
}

void Output(int a[], int n)
{
	cout << "------Array------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Arr[" << i << "] = " << a[i] << endl;
	}
}

//b. ham tim gia tri x va tra ve vi tri cua gia tri do trong mang 
void FindX(int a[], int n)
{
	bool check = false;
	int x;
	cout << "Enter the value of x to find: ";
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			cout << "Index of x in array: " << i << endl;
			check = true;
		}
	}
	if (!check)
	{
		cout << "x not found!" << endl;
	}
}

int main()
{
	int arr[1000];
	int n, x;
	Input(arr, n);
	Output(arr, n);
	FindX(arr, n);
	return 0;
}