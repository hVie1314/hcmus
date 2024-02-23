/*
Bai04: Tim dong nao co chua nhieu so chan nhat trong ma tran so nguyen.
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

void EvenNumOfLineMax(int arr[][100], int col, int line)
{
	int lineMaxIndex = 0;
	int evenNum = 0;
	for (int i = 0; i < line; i++)
	{
		int countEvenNum = 0;
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] % 2 == 0)
				countEvenNum++;
		}
		if (countEvenNum > evenNum)
		{
			evenNum = countEvenNum;
			lineMaxIndex = i;
		}
	}
	cout << "Line " << lineMaxIndex << " has the most even numbers" << endl;
}

int main()
{
	srand((int)time(0));
	int arr[100][100];
	int line, col;
	Input(arr, col, line);
	Output(arr, col, line);
	EvenNumOfLineMax(arr, col, line);
	return 0;
}