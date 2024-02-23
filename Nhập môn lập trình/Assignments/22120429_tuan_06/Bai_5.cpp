/*
Bai05: Kiem tra xem tren ma tran so nguyen co cot nao giam dan hay khong?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// ham sinh so ngau nhien
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}
//nhap mang
void Input(int a[][100], int& col, int& line) {
	cout << "Input two dimensional array " << col << "x" << line << ":" << endl;
	cout << "Input number of column: "; cin >> col;
	cout << "Input number of row: "; cin >> line;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//nhap tay
			//cout << "a[" << i << "][" << j << "]=";
			//cin >> a[i][j];

			//tao gia tri tu dong 
			a[i][j] = random(-10, 10);
		}
		//cout << endl;
	}
}
//xuat mang
void Output(int a[][100], int col, int line) {
	cout << "Output two dimensional array " << col << "x" << line << ":" << endl;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << right << setw(3) << setfill(' ') << a[i][j] << " ";
		}
		cout << endl;
	}
}

void CheckDecreaseCol(int arr[][100], int col, int line)
{
	for (int i = 0; i < col; i++)
	{
		bool IsDecrease = true;
		for (int j = 0; j < line - 1; j++)
		{
			if (arr[j][i] < arr[j + 1][i])
			{
				IsDecrease = false;
			}
		}
		if (IsDecrease)
		{
			cout << "Column " << i << " is decrease" << endl;
			for (int j = 0; j < line; j++)
			{
				cout << arr[j][i] << endl;
			}
		}
	}
}

int main()
{
	srand((int)time(0));
	int arr[100][100];
	int line, col;
	Input(arr, col, line);
	Output(arr, col, line);
	CheckDecreaseCol(arr, col, line);
	return 0;
}