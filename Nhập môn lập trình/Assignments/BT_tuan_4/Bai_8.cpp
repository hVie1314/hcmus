/*
Bài 8. Kiểm tra 1 số có phải số chính phương hay không.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
     int n; cin >> n;
     int square = sqrt(n);
     if (pow(square,2) == n) {
        cout << "La so chinh phuong." << endl;
     } else {
        cout << "Khong la so chinh phuong." << endl;
     }
     return 0;
}