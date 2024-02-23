#include <iostream> 
using namespace std;

int main() {
    float soLuong = 0, donGia = 0, tien = 0;
    cout << "Nhap so luong: "; 
    cin >> soLuong;
    cout << "Nhap don gia: ";
    cin >> donGia;

    tien = soLuong * donGia;
    tien = tien * 1.1;

    cout << tien << endl;
    return 0;
}