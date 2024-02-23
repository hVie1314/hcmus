#include <iostream> 
using namespace std;

int main() {
	float a, b, c;
	cout << "Enter 3 values: " << endl;
	cin >> a >> b >> c;
	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		cout << "Is a triangle" << endl;
	}
	else {
		cout << "Not a triangle" << endl;
	}
	return 0;
}