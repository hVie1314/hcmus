#include <iostream>
#include <cstring>
using namespace std;

struct SinhVien {
    int id;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB = 0;
    char hocluc[10] = "-";
    SinhVien* next;
};

SinhVien* head = nullptr;

SinhVien* NhapSinhVien() {
    SinhVien* sv = new SinhVien;
    cout << "Nhap ID: ";
    cin >> sv->id;
    cout << "Nhap ten: ";
    cin.ignore();
    cin.getline(sv->ten, 30);
    cout << "Nhap gioi tinh: ";
    cin >> sv->gioiTinh;
    cout << "Nhap tuoi: ";
    cin >> sv->tuoi;
    cout << "Nhap diem Toan: ";
    cin >> sv->diemToan;
    cout << "Nhap diem Ly: ";
    cin >> sv->diemLy;
    cout << "Nhap diem Hoa: ";
    cin >> sv->diemHoa;
    sv->diemTB = (sv->diemToan + sv->diemLy + sv->diemHoa) / 3;
    if (sv->diemTB >= 8.0) {
        strcpy(sv->hocluc, "Gioi");
    }
    else if (sv->diemTB >= 6.5) {
        strcpy(sv->hocluc, "Kha");
    }
    else if (sv->diemTB >= 5.0) {
        strcpy(sv->hocluc, "Trung binh");
    }
    else {
        strcpy(sv->hocluc, "Yeu");
    }
    return sv;
}

void InSinhVien(SinhVien* sv) {
    cout << "ID: " << sv->id << endl;
    cout << "Ten: " << sv->ten << endl;
    cout << "Gioi tinh: " << sv->gioiTinh << endl;
    cout << "Tuoi: " << sv->tuoi << endl;
    cout << "Diem Toan: " << sv->diemToan << endl;
    cout << "Diem Ly: " << sv->diemLy << endl;
    cout << "Diem Hoa: " << sv->diemHoa << endl;
    cout << "Diem TB: " << sv->diemTB << endl;
    cout << "Hoc luc: " << sv->hocluc << endl << endl;
}

void ThemSinhVien() {
    SinhVien* sv = NhapSinhVien();
    sv->next = head;
    head = sv;
    cout << "Da them sinh vien!" << endl;
}

void CapNhatSinhVien(int id) {
    SinhVien* sv = head;
    while (sv) {
        if (sv->id == id) {
            sv = NhapSinhVien();
            cout << "Da cap nhat thong tin sinh vien!" << endl;
            return;
        }
        sv = sv->next;
    }
    cout << "Khong tim thay sinh vien co ID: " << id << endl;
}

void XoaSinhVien(int id) {
    SinhVien* sv = head;
    SinhVien* prev = nullptr;
    while (sv) {
        if (sv->id == id) {
            if (prev) {
                prev->next = sv->next;
            } else {
                head = sv->next;
            }
            delete sv;
            cout << "Da xoa sinh vien co ID: " << id << endl;
            return;
        }
        prev = sv;
        sv = sv->next;
    }
    cout << "Khong tim thay sinh vien co ID: " << id << endl;
}

void TimKiemSinhVien(const char* ten) {
    SinhVien* sv = head;
    bool found = false;
    while (sv) {
        if (strstr(sv->ten, ten) != nullptr) {
            InSinhVien(sv);
            found = true;
        }
        sv = sv->next;
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ten " << ten << endl;
    }
}

void swap(SinhVien*& a, SinhVien*& b) {
    SinhVien* temp = a;
    a = b;
    b = temp;
}

void SapXepTheoDiemTB() {
    if (!head) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    SinhVien* current = head;
    SinhVien* index = nullptr;
    while (current) {
        index = current->next;
        while (index) {
            if (current->diemTB < index->diemTB) {
                swap(current, index);
            }
            index = index->next;
        }
        current = current->next;
    }
    cout << "Da sap xep danh sach theo diem trung binh giam dan!" << endl;
}

void SapXepTheoTen() {
    if (!head) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    SinhVien* current = head;
    SinhVien* index = nullptr;
    while (current) {
        index = current->next;
        while (index) {
            if (strcmp(current->ten, index->ten) > 0) {
                swap(current, index);
            }
            index = index->next;
        }
        current = current->next;
    }
    cout << "Da sap xep danh sach theo ten tang dan!" << endl;
}

void HienThiDanhSachSinhVien() {
    if (!head) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }
    SinhVien* sv = head;
    while (sv) {
        InSinhVien(sv);
        sv = sv->next;
    }
}

int main() {
    int choice = 0;
    while (true) {
        cout << "------------- Quan Ly Sinh Vien ----------------" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat thong tin sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. Tim kiem sinh vien theo ten" << endl;
        cout << "5. Sap xep sinh vien theo diem trung binh" << endl;
        cout << "6. Sap xep sinh vien theo ten" << endl;
        cout << "7. Hien thi danh sach sinh vien" << endl;
        cout << "8. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ThemSinhVien();
            break;
        case 2:
            int id;
            cout << "Nhap ID cua sinh vien can cap nhat: ";
            cin >> id;
            CapNhatSinhVien(id);
            break;
        case 3:
            int idXoa;
            cout << "Nhap ID cua sinh vien can xoa: ";
            cin >> idXoa;
            XoaSinhVien(idXoa);
            break;
        case 4:
            char tenTimKiem[30];
            cout << "Nhap ten sinh vien can tim kiem: ";
            cin.ignore();
            cin.getline(tenTimKiem, 30);
            TimKiemSinhVien(tenTimKiem);
            break;
        case 5:
            SapXepTheoDiemTB();
            break;
        case 6:
            SapXepTheoTen();
            break;
        case 7:
            HienThiDanhSachSinhVien();
            break;
        case 8:
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    }
    return 0;
}
