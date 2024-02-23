#include <iostream>
#include <math.h>


using namespace std;

int giaiThua(int n) {
	int giaiThua = 1; 
	for (int i = n; i > 1; i--) {
		giaiThua *= i;
	}
	return giaiThua;
}

double luyThua(int x, int i) {
	double luyThua = pow(x, i);
	return luyThua;
}

double luyThuaAm1(int n) {
	double luyThuaAm1 = pow(-1, n);
	return luyThuaAm1;
}

double luyThuaN1(int n) {
	double luyThuaN1 = pow(-1, n - 1);
	return luyThuaN1;
}

void inKetQua(int n, int x) {
	double bieuThuc1 = 0;
	for (int i = 1; i <= n; i++) {
		bieuThuc1 += 1.0 / giaiThua(i);
	}
	cout << "Ket qua bieu thuc 1: " << bieuThuc1 << endl;

	double bieuThuc2 = 0;
	for (int i = 1; i <= n; i++) {
		bieuThuc2 += luyThuaN1(i) / giaiThua(i);
	}
	cout << "Ket qua bieu thuc 2: " << bieuThuc2 << endl;

	double bieuThuc3 = 0;
	for (int i = 1; i <= n; i++) {
		bieuThuc3 += luyThuaAm1(i) * (luyThua(x, i) / giaiThua(i));
	}
	cout << "Ket qua bieu thuc 3: " << bieuThuc3 << endl;

}

int main() {
	double x = 0;
	unsigned int n = 0;
	cout << "Enter x, n: ";
	cin >> x >> n;
	inKetQua(n, x);
	return 0;
}