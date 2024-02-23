#include <iostream> 
using namespace std;

int main() {
	int a, b, c, d, medium, remain;
	cout << "Enter numbers: ";
	cin >> a >> b >> c >> d;
	int max = a, min = a;
	int sum = a + b + c + d;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	if (d > max) {
		max = d;
	}
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	if (d < min) {
		min = d;
	}
	if (a != min && a != max) {
		medium = a;
	}
	else if (b != min && b != max) {
		medium = b;
	}
	else if (c != min && c != max) {
		medium = c;
	}
	remain = sum - max - min - medium;
	if (medium > remain) {
		cout << min << " " << remain << " " << medium << " " << max << endl;
	}
	else {
		cout << min << " " << medium << " " << remain << " " << max << endl;
	}
	
	return 0;
}