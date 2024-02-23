#include<iostream>

using namespace std;

void Nhapmang(int A[100][100], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
        cout << endl;
    }
}

void Xuatmang(int A[100][100], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
// kiem tra ma tran co doi xung hay khong 
bool Doixung(int A[100][100], int n, int m)
{
    if (n != m) return false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int A[100][100];
    int n = 0, m = 0;
    cout << "Nhap n, m: ";
    cin >> n >> m;
    Nhapmang(A, n, m);
    Xuatmang(A, n, m);

    if (Doixung(A, n, m))
    {
        cout << "Ma tran vua nhap doi xung" << endl;
    }
    else
    {
        cout << "Ma tran vua nhap khong doi xung" << endl;
    }
    return 0;
}