#include <iostream>
using namespace std;

void Input(int a[][20], int &m, int &n)
{
	cout << "Enter number of line: ";
	cin >> m;
	cout << "Enter number of column: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]:";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Output(int a[][20], int m, int n)
{
	cout << "Matrix " << m << "x" << n << ": " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//tim ma tran 2*3 co tong lon nhat tu ma tran a
void FindMaxSumInMatrix2x3(int a[][20], int m, int n, int subM, int subN)
{
	int sum = 0, max = _I32_MIN;
	int tmp[20][20];

	for (int i = 0; i <= m - 2; i++)
	{
		for (int j = 0; j <= n - 3; j++)
		{
			sum = 0;
			//hard code for matrix 2x3
			//sum += a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
			
			//for lager submatrix
			for (int k = 0; k < subM; k++)
			{
				for (int l = 0; l < subN; l++)
				{
					sum += a[i + k][j + l];
				}
			}

			cout << "sum " << i << j << ": " << sum << endl;

			//check if sum > max => max is this submatrix 
			if (sum > max)
			{
				max = sum;
				for (int k = 0; k < subM; k++)
				{
					for (int l = 0; l < subN; l++)
					{
						tmp[k][l] = a[i + k][j + l];
					}
				}
			}
		}
	}
	cout << "Sunmatrix " << subM << "x" << subN << " has max sum is: " << endl;
	Output(tmp, subM, subN);
}

int main()
{
	int a[20][20];
	int m = 0, n = 0;
	Input(a, m, n);
	Output(a, m, n);
	FindMaxSumInMatrix2x3(a, m, n, 2, 3);
	return 0;
}