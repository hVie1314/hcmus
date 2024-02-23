#include <iostream>
using namespace std;

float const PI = 3.14;

int main() {
    float r, c, s;
    cout << "Nhap ban kinh hinh tron: ";
    cin >> r;
    c = 2*r*PI;
    s = PI*r*r;
    cout << "Chu vi: " << c << endl;
    cout << "Ban kinh: " << s << endl;
    return 0;
}