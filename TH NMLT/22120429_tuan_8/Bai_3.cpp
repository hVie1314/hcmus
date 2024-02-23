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

//a. them phan tu vao mang
void InsEleToArr(int a[], int& n, int val, int pos)
{
	++n;
	for (int i = n - 1; i > pos; i--)
	{
		a[i] = a[i - 1];
	}
	a[pos] = val;
}

//b. xoa phan tu khoi mang
void DeleteEle(int a[], int &n, int pos)
{
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

//c. tach mang 
void separatearr(int a[], int n, int evenA[], int &n1, int oddA[], int &n2)
{
	for (int i = 0; i < n; i++)
	{
		int value = a[i];
		if (value % 2 == 0)
		{
			evenA[n1++] = a[i];
		} 
		else {
			oddA[n2++] = a[i];
		}
	}
}

int main()
{
	Input(arr, n);
	cout << endl << "-----------------" << endl;
	//a
	cout << "Enter element want to insert: ";
	cin >> val;
	cout << "Enter position: ";
	cin >> pos;
	InsEleToArr(arr, n, val, pos);
	cout << "-----Array after insert-----" << endl;
	Output(arr, n);

	//b
	cout << endl << "-----------------" << endl;
	cout << "Enter position want to delete: ";
	cin >> pos;
	DeleteEle(arr, n, pos);
	cout << "-----Array after delete-----" << endl;
	Output(arr, n);

	//c
	cout << endl << "-----------------" << endl;
	separatearr(arr, n, evenArr, n1, oddArr, n2);
	cout << "---even number array---" << endl;
	Output(evenArr, n1);
	cout << endl << "---odd number array---" << endl;
	Output(oddArr, n2);
	return 0;
}