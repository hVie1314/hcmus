/*
Bai02: Tim trung binh cong tung cot cua ma tran so nguyen.
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

void AvgOfCol(int arr[][100], int col, int line)
{
	for (int i = 0; i < col; i++)
	{
		float sum = 0;
		for (int j = 0; j < line; j++)
		{
			sum += arr[j][i];
		}
		float avg = sum / line;
		cout << "Average of column " << i << ": " << avg << endl;
	}
}

int main()
{
	srand((int)time(0));
	int arr[100][100];
	int line, col;
	Input(arr, col, line);
	Output(arr, col, line);
	AvgOfCol(arr, col, line);
	return 0;
}