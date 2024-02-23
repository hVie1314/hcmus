#include <iostream>
using namespace std;

int main() {
	float toan, li, hoa, heSoToan, heSoLi, heSoHoa, diemTB;
	cout << "Nhap diem thi toan, li, hoa: ";
	cin >> toan >> li >> hoa;
	cout << "Nhap he so mo toan, li , hoa: ";
	cin >> heSoToan >> heSoLi >> heSoHoa;
	
	diemTB = (toan * heSoToan + li * heSoLi + hoa * heSoHoa) / (heSoToan + heSoLi + heSoHoa);
	cout << diemTB;
	
	return 0;
}