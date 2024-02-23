#include <iostream> 
using namespace std;

int main() {
	int day, money;
	char roomClass;
	cout << "Enter numbers of days: "; cin >> day;
	cout << "Enter class of room (A, B, C): "; cin >> roomClass;
	if (roomClass == 'A' || roomClass == 'a') {
		money = day * 450000;
	}
	else if (roomClass == 'B' || roomClass == 'b') {
		money = day * 350000;
	}
	else {
		money = day * 250000;
	}
	if (day >= 12) {
		if (roomClass == 'C' || roomClass == 'c') {
			money *= 0.9;
		}
		else {
			money *= 0.92;
		}
	}
	cout << "Money: " << money << endl;
	return 0;
}