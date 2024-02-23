#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;
// ham sinh so ngau nhien
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

void Input(int a[][100], int& m, int& n) {
	//cout << "input two dimensional array " << m << "x" << n << ":" << endl;
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			//nhap tay
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];

			//tao gia tri tu dong 
			//a[i][j] = random(-20, 20);
		}
		cout << endl;
	}
}
// nhap mang
void Output(int a[][100], int m, int n) {
	cout << "output two dimensional array " << m << "x" << n << ":" << endl;
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
// liem tra mang 1 chieu tang 
bool CheckRaise(int arr[], int n)
{
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
} 
//sort
void BubbleSort(int a[], int m) {
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				//swap
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
	bool isRaise = false; //check xem mang 1 chieu co tang hay ko 
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
	if (isRaise = false) // neu ko tang thi sap xep lai
	{
		if (n % 2 == 1) // TH1: lay 1 dong
		{
			int line = n / 2 ;
			for (int i = 0; i < n; i++)
			{
				tmp[i] = arr[line][i];
			}
			BubbleSort(tmp, m);

			// tra tmp vao matrix
			for (int i = 0; i < n; i++)
			{
				arr[line][i] = tmp[i];
			}
		}
		else if (n % 2 == 0) //TH2 lay 2 dong
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