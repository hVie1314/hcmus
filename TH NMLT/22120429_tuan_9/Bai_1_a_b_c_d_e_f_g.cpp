#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;

//a. viet ham nhap xuat ma tran

//ham nhap
void Input(int A[][MAX], int& col, int& line)
{
	cout << "Input number of column: "; cin >> col;
	cout << "Input number of line: "; cin >> line;
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

//b. Viet ham tinh tong cac phan tu tren duong bien cua ma tran 
int SumOnBorder(int A[][MAX], int col, int line)
{
	int sum = 0;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 || i == line - 1)
			{
				sum += A[i][j];
			}
			else if (j == 0 || j == col - 1)
			{
				sum += A[i][j];
			}
		}
	}
	return sum;
}

//c. Tinh tong cac duong cheo chinh va cac duong cheo phu cua ma tran
int SumOnDiagonal(int A[][MAX], int col, int line)
{
	int sum = 0;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j || i + j == col - 1)
				// duong cheo chinh co index: i = j
				// duong cheo phu co in index: i + j = col - 1
			{
				sum += A[i][j];
			}
			if (i == j && i + j == col - 1)
				// truong hop phan tu cung nam tren duong cheo chinh va phu -> cong them 1 lan nua
			{
				sum += A[i][j];
			}
		}
	}
	return sum;
}

//d. Viet ham tinh tong hang thu k cua ma tran 
int SumInLineK(int A[][MAX], int col, int k)
{
	int sum = 0;
	for (int i = 0; i < col; i++)
	{
		sum += A[k][i];
	}
	return sum;
}

//e. viet ham tim hang co tong lon nhat cua ma tran
int LineHaveMaxSum(int A[][MAX], int col, int line)
{
	int lineMax = 0;
	int sumMax = 0;
	for (int i = 0; i < line; i++)
	{
		int sum = 0;
		for (int j = 0; j < col; j++)
		{
			sum += A[i][j];
		}
		if (sum > sumMax)
		{
			sumMax = sum;
			lineMax = i;
		}
	}
	return lineMax;
}

//f. Viet ham tim cac gia tri yen ngua cua ma tran
//ham kiem tra dieu kien lon nhat tren hang
bool IsMaxInLine(int A[][MAX], int col, int lineI, int index) // index: vi tri line can xet
{
	bool isMax = true;
	int max = A[lineI][index]; // vi tri can so sanh tren hang 
	for (int i = 0; i < col; i++) // duyet tung phan tu tren hang so sanh voi max
	{
		if (A[lineI][i] > max) isMax = false;
	}
	return isMax;
}
//ham kiem tra dieu kien nho nhat tren cot
bool IsMinInCol(int A[][MAX], int colI, int line, int index) // index: vi tri col can xet
{
	bool isMin = true;
	int min = A[index][colI]; // vi tri can so sanh tren cot 
	for (int i = 0; i < line; i++) // duyet tung phan tu cua cot so sanh voi min
	{
		if (A[i][colI] < min) isMin = false;
	}
	return isMin;
}
//ham tim vi tri yen ngua
void HorseSaddle(int A[][MAX], int col, int line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (IsMaxInLine(A, col, i, j) && IsMinInCol(A, j, line, i))
			{
				cout << A[i][j] << " ";
			}
		}
	}
}

//g. viet chuong trinh chinh kiem thu cac ham da viet tren
int main()
{
	int A[100][100];
	int col = 0, line = 0;
	int k = 0;
	Input(A, col, line);
	Output(A, col, line);
	cout << "\nSum of elements on border of matrix: " << SumOnBorder(A, col, line) << endl;
	cout << "\nSum of elements on diagonal line of matrix: " << SumOnDiagonal(A, col, line) << endl;
	cout << "\nInput line k: "; cin >> k;
	cout << "Sum of elements in line k: " << SumInLineK(A, col, k) << endl;
	cout << "\nLine have max sum in matrix: " << LineHaveMaxSum(A, col, line) << endl;
	cout << "\nHorse saddle elements in matrix: ";
	HorseSaddle(A, col, line);
	return 0;
}