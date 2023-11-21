#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct SinhVien {
    int id;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    char hocLuc[10];
};

// them sinh vien
void themSinhVien(vector<SinhVien>& danhSachSinhVien, SinhVien sinhVien) 
{
    danhSachSinhVien.push_back(sinhVien);
}

// cap nhat thong tin sinh vien theo ID
void capNhatSinhVien(vector<SinhVien>& danhSachSinhVien, int id, SinhVien sinhVienMoi) 
{
    for (SinhVien& sv : danhSachSinhVien) 
    {
        if (sv.id == id) 
        {
            sv = sinhVienMoi;
            return;
        }
    }
}

// xoa sinh vien theo ID
void xoaSinhVien(vector<SinhVien>& danhSachSinhVien, int id) 
{
    for (int i = 0; i < danhSachSinhVien.size(); i++) 
    {
        if (danhSachSinhVien[i].id == id) 
        {
            danhSachSinhVien.erase(danhSachSinhVien.begin() + i);
            return;  
        }
    }
}

// tim kie sinh vien theo ten
vector<SinhVien> timSinhVienTheoTen(const vector<SinhVien>& danhSachSinhVien, const char* ten)
{
    vector<SinhVien> ketQua;
    for (const SinhVien& sv : danhSachSinhVien) 
    {
        if (strcmp(sv.ten, ten) == 0) 
        {
            ketQua.push_back(sv);
        }
    }
    return ketQua;
}

// sap xep sinh vien theo diem trung binh
void sapXepTheoGPA(vector<SinhVien>& danhSachSinhVien)
{
    sort(danhSachSinhVien.begin(), danhSachSinhVien.end(),
        [](const SinhVien& a, const SinhVien& b) {
            return a.diemTB > b.diemTB;
        }
    );
}

// sap xep sinh vie theo ten
void sapXepTheoTen(vector<SinhVien>& danhSachSinhVien) 
{
    sort(danhSachSinhVien.begin(), danhSachSinhVien.end(),
        [](const SinhVien& a, const SinhVien& b) { return strcmp(a.ten, b.ten) < 0; });
}

// hien thi danh sach sinh vien
void hienThiDanhSach(const vector<SinhVien>& danhSachSinhVien) 
{
    for (const SinhVien& sv : danhSachSinhVien) 
    {
        cout << "ID: " << sv.id << endl;
        cout << "Ten: " << sv.ten << endl; 
        cout << "Tuoi: " << sv.tuoi << endl;
        cout << "Điem TB: " << sv.diemTB << endl << endl;
    }
}

int main() 
{
    vector<SinhVien> danhSachSinhVien;

    SinhVien sv1 = { 1, "Nguyen Van A", "Nam", 20, 8.5, 7.8, 8.0, 0, "-" };
    SinhVien sv2 = { 2, "Tran Thi B", "Nu", 21, 7.2, 6.5, 7.0, 0, "-" };
    SinhVien sv3 = { 3, "Le Van C", "Nam", 22, 9.0, 8.5, 7.7, 0, "-" };
    SinhVien sv4 = { 4, "Pham Van D", "Nam", 19, 8.0, 7.5, 8.5, 0, "-" };
    SinhVien sv5 = { 5, "Hoang Thi E", "Nu", 20, 7.7, 8.2, 8.8, 0, "-" };

    themSinhVien(danhSachSinhVien, sv1);
    themSinhVien(danhSachSinhVien, sv2);
    themSinhVien(danhSachSinhVien, sv3);
    themSinhVien(danhSachSinhVien, sv4);
    themSinhVien(danhSachSinhVien, sv5);

    cout << "Danh sach sinh vien truoc khi sap xep theo ten: " << endl;
    hienThiDanhSach(danhSachSinhVien);

    sapXepTheoTen(danhSachSinhVien);
    cout << "Danh sach sinh vien sau khi sap xep theo ten: " << endl;
    hienThiDanhSach(danhSachSinhVien);

    vector<SinhVien> ketQuaTimKiem = timSinhVienTheoTen(danhSachSinhVien, "Nguyen Van A");
    if (!ketQuaTimKiem.empty()) {
        cout << "Sinh vien có ten 'Nguyen Van A':" << endl;
        hienThiDanhSach(ketQuaTimKiem);
    } else {
        cout << "Khong tim thay sinh vien co ten 'Nguyen Van A'." << endl;
    }

    SinhVien svMoi = { 2, "Tran Thi C", "Nu", 22, 7.8, 7.0, 7.5, 0, "-" };
    capNhatSinhVien(danhSachSinhVien, 2, svMoi);
    cout << "Danh sach sinh vien sau khi cap nhat:" << endl;
    hienThiDanhSach(danhSachSinhVien);

    xoaSinhVien(danhSachSinhVien, 5);
    cout << "Danh sach sinh vien sau khi xoa:" << endl;
    hienThiDanhSach(danhSachSinhVien);

    return 0;
}

