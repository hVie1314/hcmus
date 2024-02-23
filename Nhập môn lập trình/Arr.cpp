#include <iostream>

using namespace std; 

void Input(int arr[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap arr[" << i << "]: ";
		cin >> arr[i];
	}
}

void Output(int arr[], int n)
{
	cout << "Xuat mang: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
		
	}
}

void InsE(int arr[], int& n, int val, int pos)
{
	++n;
	for (int i = n - 1; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = val;
}

void DelE(int arr[], int& n, int pos)
{
	for (int i = pos; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	--n;
}

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()
{
	int arr[1000];
	int n;
	cout << "Nhap so luong phan tu cua mang: "; cin >> n;
	Input(arr, n);
	//BubbleSort(arr, n);
	InsE(arr, n, 3, 10);
	//DelE(arr, n, 2);

	Output(arr, n);
	return 0;
}