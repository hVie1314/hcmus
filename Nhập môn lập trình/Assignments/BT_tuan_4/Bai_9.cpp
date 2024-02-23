/*
Bài 9. Nhập vào số nguyên dương n, kiểm tra số đó có toàn chẵn hoặc toàn lẻ hay không.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
     unsigned int n, t, tmp; 
     cin >> n;
     bool checkEven = true, checkOdd = true;
     t = n;
     while (n != 0 && checkEven == true) {
        tmp = n % 10;
        n /= 10;
        if (tmp % 2 != 0) {
            checkEven = false;
        }
     }
     if (!checkEven) {
        while (t != 0 && checkOdd == true) {
            tmp = t % 10;
            t /= 10;
            if (tmp % 2 != 1) {
                checkOdd = false;
            }
        }
     }
     if (checkEven) {
        cout << "La so toan chan." << endl;
     } else if (checkOdd) {
        cout << "La so toan le." << endl;
     } else {
        cout << "Khong la so toan chan va cung khong la so toan le.";
     }
     
     return 0;
}