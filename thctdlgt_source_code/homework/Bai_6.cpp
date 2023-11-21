#include <iostream>

using namespace std;

int** createMatrix(int m, int n)
{
    int** arr = new (nothrow) int*[m];
    if (!arr) return nullptr;

    for (int i = 0; i < m; i++)
    {
        arr[i] = new (nothrow) int[n];
        if (!arr[i]) return nullptr;
    }
    return arr;
}

void delMatrix(int**& arr, int m)
{
    for (int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}

void inputMatrix(int** arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void outputMatrix(int** arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void sumOfTwoMatrix(int** c, int** a, int** b, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main()
{
    int m = 0;
    int n = 0;
    cout << "m , n = "; cin >> m >> n;
    int** a = createMatrix(m ,n);
    int** b = createMatrix(m ,n);
    cout << "Nhap ma tran a: " << endl;
    inputMatrix(a, m , n);
    cout << "Nhap ma tran b: " << endl;
    inputMatrix(b, m, n);

    int** c = createMatrix(m ,n);
    sumOfTwoMatrix(c, a, b, m, n);

    outputMatrix(c, m, n);

    delMatrix(a, m);
    delMatrix(b, m);
    delMatrix(c, m);
    return 0;
}