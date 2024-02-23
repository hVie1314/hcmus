#include <iostream>
#include <string>

using namespace std;

struct MatHang
{
	string tenMatHang;
	int donGia;
	int soLuong;
};

// ham nhap mat hang
void Nhap(MatHang &mh)
{
	cout << "Nhap ten mat hang: ";
	cin.ignore();
	getline(cin, mh.tenMatHang);
	cout << "Nhap don gia: ";
	cin >> mh.donGia;
	cout << "Nhap so luong ton: ";
	cin >> mh.soLuong;
}

// ham xuat mat hang
void Xuat(MatHang mh)
{
	cout << "\nTen mat hang: " << mh.tenMatHang << endl;
	cout << "Don gia: " << mh.donGia << endl;
	cout << "So luong ton: " << mh.soLuong << endl;
}

// ham nhap danh sach mat hang 
void NhapDanhSach(MatHang dsmh[], int &n)
{
	cout << "Nhap so luong mat hang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap hang thu " << i << endl;
		Nhap(dsmh[i]);
	}
}

//ham xuat danh sach mat hang
void XuatDanhSach(MatHang dsmh[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nThong tin mat hang thu " << i;
		Xuat(dsmh[i]);
	}
}

//tinh tien cho moi mat hang
double TinhTien(MatHang mh)
{
	double tien = mh.soLuong * mh.donGia;
	return tien;
}

//tinh thanh tien
void ThanhTien(MatHang dsmh[], int n)
{
	double thanhTien = 0;
	for (int i = 0; i < n; i++)
	{
		thanhTien += TinhTien(dsmh[i]);
	}
	cout << "\n--------------------------\n";
	cout << "Thanh tien: " << thanhTien << endl;
}

int main()
{
	MatHang mh[100];
	int n = 0;
	NhapDanhSach(mh, n);
	XuatDanhSach(mh, n);
	ThanhTien(mh, n);
	return 0;
}