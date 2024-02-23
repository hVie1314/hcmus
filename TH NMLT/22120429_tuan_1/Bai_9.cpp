#include <iostream>
using namespace std;

int main() {
    unsigned int money, n500k, n100k, n1k;
    cout << "Nhap so tien muon doi: ";
    cin >> money;

    n500k = money / 500000;
    money -= n500k*500000;
    n100k = money / 100000;
    money -= n100k*100000;
    n1k = money / 1000;

    cout << "Cac loai tien doi duoc la: " << endl;
    cout << n500k << " to 500 ngan vnd" << endl;
    cout << n100k << " to 100 ngan vnd" << endl;
    cout << n1k << " to 1 ngan vnd" << endl;

    return 0;
}