#include <iostream> 
using namespace std;

int main() {
    float a, b, tong = 0, hieu = 0, tich = 0, thuong = 0;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    tong = a + b;
    hieu = a - b;
    tich = a * b;
    thuong = a / b;
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    cout << "Thuong: " << thuong << endl;
    return 0;
}