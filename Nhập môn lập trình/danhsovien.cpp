#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

void Input(int a[][100], int& m, int& n) {
	//cout << "input two dimensional array " << m << "x" << n << ":" << endl;
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];

			//a[i][j] = random(-20, 20);
		}
		cout << endl;
	}
}

void Output(int a[][100], int m, int n) {
	cout << "output two dimensional array " << m << "x" << n << ":" << endl;
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

bool CheckRaise(int arr[], int n)
{
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
} 

void BubbleSort(int a[], int m) {
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m - 1 - i; j++)
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
	srand((int)time(0));
	int arr[100][100];
	int n,m;
	cout << "input number of row: "; cin >> m;
	cout << "input number of column: "; cin >> n;
	Input(arr, m, n);
	Output(arr, m, n);
	int tmp[1000];
	bool isRaise = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[j] = arr[i][j];
		}
		if (CheckRaise(tmp, m)) {
			cout << "Dong thu " << i << " tang dan" << endl;
			isRaise = true;
		}

	}
	if (isRaise = false)
	{
		if (n % 2 == 1)
		{
			int line = n / 2 ;
			for (int i = 0; i < n; i++)
			{
				tmp[i] = arr[line][i];
			}
			BubbleSort(tmp, m);
			
			// debug
			cout << "tmp: " << endl
			for (int i = 0; i < n; i++)
			{
				cout << 
			}



			for (int i = 0; i < n; i++)
			{
				arr[line][i] = tmp[i];
			}
		}
		else if (n % 2 == 0)
		{
			int line = n / 2;
			for (int i = 0; i < n; i++)
			{
				tmp[i] = arr[line][i];
			}
			BubbleSort(tmp, m);
			for (int i = 0; i < n; i++)
			{
				arr[line][i] = tmp[i];
			}
			line--;
			for (int i = 0; i < n; i++)
			{
				tmp[i] = arr[line][i];
			}
			BubbleSort(tmp, m);
			for (int i = 0; i < n; i++)
			{
				arr[line][i] = tmp[i];
			}
		}
		
	}
	cout << "Mang sau khi dc sap xep: " << endl;
	Output(arr, m, n);
	return 0;
}