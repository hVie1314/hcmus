#include <iostream> 
using namespace std;

int main() {
	int a, b, c, d;
	cout << "Enter numbers: ";
	cin >> a >> b >> c >> d;
	int max = a, min = a;
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
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	return 0;
}