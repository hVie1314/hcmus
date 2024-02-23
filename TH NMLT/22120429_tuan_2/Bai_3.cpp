#include <iostream>
using namespace std;

int main() {
	char c; 
	cout << "Enter character: ";
	cin >> c;
	if (c >= 65 && c <= 90) {
		c += 32;
		cout << c << endl;
	} else if (c >= 97 && c <= 122) {
		c -= 32;
		cout << c << endl;
	}
	
	return 0;
}
