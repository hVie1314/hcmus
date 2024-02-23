#include <iostream>
using namespace std;

int main() {
    float a, b, tmp;
    cout << "Nhap gia tri cua 2 bien: ";
    cin >> a >> b;
    
    tmp = a;
    a = b; 
    b = tmp;

    cout << "Gia tri sau khi hoan doi la: " << a << " " << b << endl;
    return 0;
}