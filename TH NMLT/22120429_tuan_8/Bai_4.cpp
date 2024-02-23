#include <iostream>
#include <math.h>
using namespace std;

int arr[1000], evenArr[1000], oddArr[1000];
int n, n1 = 0, n2 = 0, pos, val;

//ham nhap xuat mang
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
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

// sort arr using bubble sort algorithm
void Sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	Input(arr, n);
	Sort(arr, n);
	cout << "----Array after sort----" << endl;
	Output(arr, n);
	return 0;
}