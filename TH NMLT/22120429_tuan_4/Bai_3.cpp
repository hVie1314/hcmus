/*
	Giá trị trả vể của hàm là 6561  (9^4)
	Vì đây là hàm đệ quy nên hàm sẽ gọi lại chính nó 4 lần,
	(vì điều kiện c = 0 sẽ return, mà c ban đầu = 5, sau mỗi lần gọi c-- 
	nên sẽ gọi 4 lần ứng với c =4, 3, 2, 1)
	Mỗi lần chạy hàm sẽ trả về giá trị 9 * 1 = 9
	Hàm chạy 4 lần => 9 * 9 * 9 * 9 = 9^4 = 6561
*/

#include <iostream>

using namespace std;

int f(int& x, int c) {
	c -= 1;
	if (c == 0) return 1;
	x += 1;
	return f(x, c) * x;
}

int main() {
	int p = 5;
	cout << f(p, p) << endl;
	return 0;
}