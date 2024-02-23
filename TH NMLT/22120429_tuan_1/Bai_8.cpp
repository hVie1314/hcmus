#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Nhap bien so xe: ";
    cin >> n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    sum %= 10;
    cout << "So nut la: " << sum << endl;
    return 0;
}