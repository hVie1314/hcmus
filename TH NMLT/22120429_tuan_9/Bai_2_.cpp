#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;

//ham nhap
void Input(int A[][MAX], int col, int line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "A[" << i << "][" << j << "]: ";
			cin >> A[i][j];
		}
		cout << endl;
	}
}

// ham xuat
void Output(int A[][MAX], int col, int line)
{
	cout << "Matrix " << col << "x" << line << endl;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << right << setw(4) << setfill(' ') << A[i][j];
		}
		cout << endl;
	}
}

//ham nhap col line 
void InputDimention(int& col, int& line)
{
	cout << "Input number of column: "; cin >> col;
	cout << "Input number of line: "; cin >> line;
}

// ham tinh tong 2 ma tran 
void SumOf2Matrix(int A[][MAX], int B[][MAX], int C[][MAX], int col, int line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

int main()
{
	int A[100][100], B[100][100], C[100][100];
	int col = 0, line = 0;

	InputDimention(col, line);
	cout << "\nInput matrix A " << endl;
	Input(A, col, line);
	cout << "\nInput matrix B " << endl;
	Input(B, col, line);

	SumOf2Matrix(A, B, C, col, line);

	cout << "\nMatrix A" << endl;
	Output(A, col, line);
	cout << "\nMatrix B" << endl;
	Output(B, col, line);

	cout << "\n----- Matrix A + B -----" << endl;
	Output(C, col, line);
	return 0;
}