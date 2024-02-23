#include <iostream> 
using namespace std;

int main() {
	float oldIndex, newIndex, index, money;
	int people;
	do {
		cout << "Enter old water index: " << endl; cin >> oldIndex;
		cout << "Enter new water index: " << endl; cin >> newIndex;
		cout << "Enter a number of users: " << endl; cin >> people;
	} while (oldIndex > newIndex);
	index = newIndex - oldIndex;

	if (index <= 4 * people) {
		money = index * 4400;
	}
	else if (index <= 6 * people) {
		money = 4 * people * 4400 + (index - 4 * people) * 8300;
	}
	else {
		money = 4 * people * 4400 + 2 * people * 8300 + (index - (4 + 2) * people) * 10500;
	}
	money /= people;
	cout << "Money per person: " << money << endl;

	return 0;
}