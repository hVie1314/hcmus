#include <iostream>

using namespace std;

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
	cout << "------Array------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Arr[" << i << "] = " << a[i] << endl;
	}
}

//a. ham tinh gia tri trung binh
float AvgOfArr(int a[], int n)
{	
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum / n;
}

//b. ham tim so lon nhat
int FindMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

//c. ham tim so lon thu hai
int FindMax2(int a[], int n)
{
	int max1, max2;
	if(a[0] > a[1]) {
		max1 = a[0];
		max2 = a[1];
	}
	else {
		max1 = a[1];
		max2 = a[0];
	}
	for (int i = 2; i < n; i++) 
	{
		if (a[i] >= max1) 
		{
			max2 = max1;
			max1 = a[i];
		}
		else if (a[i] > max2) 
		{
			max2 = a[i];
		}
	}
	return max2;
}

int main()
{
	int arr[1000];
	int n;
	Input(arr, n);
	cout << endl << "-------------" << endl;
	cout << "a. Average of array: " << AvgOfArr(arr, n) << endl;
	cout << "b. Max of array: " << FindMax(arr, n) << endl;
	cout << "c. Second max of array: " << FindMax2(arr, n) << endl;
	return 0;
}