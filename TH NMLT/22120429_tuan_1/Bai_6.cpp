#include <iostream>
using namespace std;

int main() {
    float c, s;
    cout << "Nhap chu vi hcn: ";
    cin >> c; 
    /*Dien tich cua hcn co chieu dai gap 1.5 lan chieu rong tinh duoc 
    theo cong thuc S = 0.06*C^2
    */
    s = 0.06*c*c;
    cout << "Dien tich: " << s << endl;
    return 0;
}