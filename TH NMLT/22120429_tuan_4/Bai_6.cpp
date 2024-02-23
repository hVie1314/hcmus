#include <iostream>
#include <math.h>

using namespace std;

int DecToBin(int dec) {
	long long bin = 0;
	int p = 0;
	while (dec > 0) {
		bin += (dec % 2) * pow(10, p);
		dec /= 2;
		p++;
	}
	return bin;
}

int main() {
	int dec;
	cout << "Enter decimal number need to conver: ";
	cin >> dec;
	cout << "Decimal number after convert to binary: " << DecToBin(dec) << endl;
	return 0;
}