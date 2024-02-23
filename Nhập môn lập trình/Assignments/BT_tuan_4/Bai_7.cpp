/*
Bài 7. Bạn có tờ 200.000 từ 3 tờ giấy bạc 1000 đồng, 2000 đồng và 5000 đồng.
Hãy viết chương trình tìm ra cách đổi từ các đồng tiền trên sao cho tổng bằng 200.000.
*/

#include <iostream>
using namespace std;

int main() {
     int money = 200;
     int n1, n2, n5, count = 0;
     n1 = money / 1;
     n2 = money / 2;
     n5 = money / 5;
    cout << n1 << " " << n2 << " " << n5 << endl;
     for (int i = 0; i <= n1; i ++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 0; k <= n5; k++) {
                if (i * 1 + j * 2 + k * 5 == money) {
                    count++;
                    cout << "Cach " << count << ":" << endl;
                    cout << i << " to " << "1k vnd." << endl;
                    cout << j << " to " << "2k vnd." << endl;
                    cout << k << " to " << "5k vnd." << endl;
                }
            }
        }
     }
     return 0;
}