#include <iostream> 
using namespace std;

int main() {
	float km = 0;
	int money = 0;
	cout << "Enter the km: "; cin >> km;
	if (km <= 1) {
		money = km * 22000;
	}
	else if (km <= 5) {
		money = 22000 + (km - 1) * 20000;
	}
	else {
		money = 22000 + 4 * 20000 + (km - 5) * 18000;
	}
	if (km >= 120)
		money *= 0.9;
	cout << "Money: " << money << endl;
	
	return 0;
}