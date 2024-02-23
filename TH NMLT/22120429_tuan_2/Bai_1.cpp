#include <iostream>
using namespace std;

int main() {
    float oldElecIndex, newElecIndex, elecIndex;
    unsigned int money = 0;
    do {
        cout << "Enter old electric index: ";
        cin >> oldElecIndex;
        cout << "Enter new electic index: ";
        cin >> newElecIndex;
    } while (oldElecIndex > newElecIndex);

    elecIndex = newElecIndex - oldElecIndex;
    
    if (elecIndex <= 100) {
        money = elecIndex*1400;
    } else if (elecIndex <= 150) {
        money = 100*1400 + (elecIndex - 100)*1500;
    } else if (elecIndex <= 200) {
        money = 100*1400 + 50*1500 + (elecIndex - 100 - 50)*1700;
    } else {
        money = 100*1400 + 50*1500 + 50*1700 + (elecIndex - 100 - 50 - 50)*1900;
    }
    cout << "Money: " << money << endl;
    return 0;
}