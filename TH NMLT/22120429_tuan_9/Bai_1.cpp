#include <iostream>
#include <math.h>

using namespace std;

struct PhanSo
{
    int tuSo;
    int mauSo;
};

//a. ham nhap xuat phan so 
//ham nhap 
void Nhap(PhanSo& ps)
{
    cout << "Nhap tu so: "; cin >> ps.tuSo;
    do
    {
        cout << "Nhap mau so: "; cin >> ps.mauSo;
        if (ps.mauSo == 0)
            cout << "mau so phai khac 0. Vui long nhap lai mau so!";
    } while (ps.mauSo == 0);
}

//ham xuat 
void Xuat(PhanSo ps)
{
    cout << ps.tuSo << "/" << ps.mauSo << " ";
}

//ham tim UCLN
int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

//b. ham rut gon phan so 
void RutGon(PhanSo& ps)
{
    int c = UCLN(ps.tuSo, ps.mauSo);
    ps.tuSo = ps.tuSo / c;
    ps.mauSo = ps.mauSo / c;
}

//ham tinh tong
PhanSo Tong(PhanSo a, PhanSo b)
{
    PhanSo tong;
    tong.tuSo = a.tuSo * b.mauSo + b.tuSo * a.mauSo;
    tong.mauSo = a.mauSo * b.mauSo;
    RutGon(tong);
    return tong;
}

//d. ham nhap xuat 1 mang cac phan so 
// ham nhap mang 
void NhapMang(PhanSo mps[], int& n)
{
    cout << "Nhap so luong phan tu cua mang: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan so thu " << i << endl;
        Nhap(mps[i]);
    }
}

// ham xuat mang 
void XuatMang(PhanSo mps[], int n)
{
    cout << "\nMang cac phan so vua nhap la: ";
    for (int i = 0; i < n; i++)
    {
        Xuat(mps[i]);
    }
}

//ham cong mang phan so 
void TongMang(PhanSo mps[], int n)
{
    PhanSo t = mps[0];
    for (int i = 1; i < n; i++)
    {
        t = Tong(t, mps[i]);
    }
    cout << "\n\nTong cac phan so trong mang la: ";
    Xuat(t);
}

int main()
{
    PhanSo mps[100];
    int n = 0;
    NhapMang(mps, n);
    XuatMang(mps, n);
    TongMang(mps, n);
    return 0;
}
