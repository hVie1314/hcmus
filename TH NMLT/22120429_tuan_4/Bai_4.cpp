#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
	bool check = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			check = false;
	}
	return check;
}

unsigned int sumOfPrime(int n) {
	unsigned sum = 0;
	for (int i = 1; i <= n; i++) {
		if (isPrime(i)) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	unsigned int n = 50;
	cout << "Sum of S(" << n << "): " << sumOfPrime(n) << endl;
}