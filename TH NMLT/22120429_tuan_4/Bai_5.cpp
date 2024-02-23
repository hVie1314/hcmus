#include <iostream>
#include <math.h>

using namespace std;

int BinToDec(long bin) {
	int dec = 0, tmp = 0, remainder = 0;
	while (bin != 0) {
		remainder = bin % 10;
		bin /= 10;
		dec += remainder * pow(2, tmp);
		tmp++;
	}
	return dec;
}

int main() {
	long bin;
	cout << "Enter binary number need to conver (8bit): ";
	cin >> bin;
	cout << "Bin number after convert to decimal: " << BinToDec(bin) << endl;
	return 0;
}