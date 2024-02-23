#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Khai bao kieu Sinh vien 
struct Student
{
	string name;
	int id;
	float marks[3];
};

// ham nhap sinh vien 
void Input(Student& st)
{
	cout << "Nhap ten sinh vien: ";
	cin.ignore();
	getline(cin, st.name);
	cout << "Nhap id sinh vien: ";
	cin >> st.id;
	cout << "Nhap diem cua sinh vien" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Nhap diem thu " << i + 1 << " : ";
		cin >> st.marks[i];
	}
}

// ham xuat sinh vien 
void Output(Student st)
{
	cout << " " << setw(19) << left << st.id << setw(22) << st.name;
	for (int i = 0; i < 3; i++)
	{
		cout << right << setw(15) << st.marks[i];
	}
}

// ham nhap mot mang danh sach cac sinh vien 
void InputList(Student st[], int& n)
{
	cout << "Nhap so luong sinh vien trong danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nSinh vien thu " << i + 1 << endl;
		Input(st[i]);
		cout << "\n---------------------------------------------------------------------------------------\n";
	}
}

// ham xuat mot mang danh sach cac sinh vien 
void OutputList(Student st[], int n)
{
	cout << "\n----------------------------------DANH SACH SINH VIEN----------------------------------\n\n";
	cout << setw(3) << "ID" << setw(26) << "Ho Va Ten" << setw(28) << "Diem 1" << setw(15) << "Diem 2" << setw(15) << "Diem 3" << endl;
	for (int i = 0; i < n; i++)
	{
		Output(st[i]);
		cout << endl;
	}
	cout << "\n---------------------------------------------------------------------------------------\n\n";
}

//ham xuat sinh vien voi id da cho
void OutputWithId(Student st[], int n, int id)
{
	bool exist = false;
	for (int i = 0; i < n; i++)
	{
		if (st[i].id == id)
		{
			cout << setw(3) << "ID" << setw(26) << "Ho Va Ten" << setw(28) << "Diem 1" << setw(15) << "Diem 2" << setw(15) << "Diem 3" << endl;
			Output(st[i]);
			exist = true;
		}
	}
	if (!exist)
		cout << "Id khong ton tai trong danh sach!";
	if (exist)
		cout << "\n\nDa luu thong tin vao file!";
}

//ham xuat sinh vien voi ten da cho
void OutputWithName(Student st[], int n, string &name)
{
	bool exist = false;
	for (int i = 0; i < n; i++)
	{
		if (st[i].name == name)
		{
			cout << setw(3) << "ID" << setw(26) << "Ho Va Ten" << setw(28) << "Diem 1" << setw(15) << "Diem 2" << setw(15) << "Diem 3" << endl;
			Output(st[i]);
			exist = true;
		}
	}
	if (!exist)
		cout << "Ten sinh vien khong ton tai trong danh sach!";
	if (exist)
		cout << "\n\nDa luu thong tin vao file!";
}

//ham tinh diem trung binh
float AvgPoint(Student st)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += st.marks[i];
	}
	return sum / 3.0;
}

// ham tim va xuat sinh vien co diem trung binh cao nhat
void MaxAvgPoint(Student st[], int n, float &max)
{
	max = AvgPoint(st[0]);
	for (int i = 1; i < n; i++)
	{
		if (AvgPoint(st[i]) > max)
		{
			max = AvgPoint(st[i]);
		}
	}
	cout << "\nSinh Vien Co Diem Trung Binh Cao Nhat" << endl << endl;
	cout << setw(3) << "ID" << setw(26) << "Ho Va Ten" << setw(28) << "Diem 1" << setw(15) << "Diem 2" << setw(15) << "Diem 3" << endl;
	for (int i = 0; i < n; i++)
	{
		if (AvgPoint(st[i]) == max)
		{
			Output(st[i]);
			cout << endl;
		}
	}
	cout << "\nDiem Trung Binh: " << setprecision(2) << fixed << max << endl;
	cout << "\nDa luu thong tin vao file!" << endl;
}

//them 1 sinh vien vao trong danh sach 
void AddStudent(Student st[], int& n)
{
	Input(st[n++]);
}

//ghi thong tin vao file
void InputFile(ifstream& ifs, Student& st)
{
	ifs.ignore();
	getline(ifs, st.name);
	ifs >> st.id;
	for (int i = 0; i < 3; i++)
	{
		ifs >> st.marks[i];
	}
}

void InputListFile(ifstream& ifs, Student st[], int& n)
{
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		InputFile(ifs, st[i]);
	}
}

int main()
{
	Student st[100];
	int n = 0, id = 0;
	float max = 0;
	string name;
	int choice;
	ifstream ifs("input.txt", ios::in);
	ofstream ofs("output.txt", ios::out);

	//tao menu 
	while (1)
	{
		cout << "\n----------------------------------------- MENU ----------------------------------------\n";
		cout << "* 1. Nhap Danh Sach Sinh Vien" << endl;
		cout << "* 2. In Danh Sach Sinh Vien" << endl;
		cout << "* 3. Tim Sinh Vien Theo ID" << endl;
		cout << "* 4. Tim Sinh Vien Theo Ten" << endl;
		cout << "* 5. In Thong Tin Sinh Vien Co Diem Trung Binh Cong Cao Nhat" << endl;
		cout << "* 6. Them Sinh Vien Vao Danh Sach" << endl;
		cout << "* 7. Doc Danh Sach Tu File" << endl;
		cout << "* 0. Thoat Chuong Trinh";
		cout << "\n---------------------------------------------------------------------------------------\n";
		cout << endl << "Moi Ban Nhap Lua Chon: ";
		cin >> choice;
		cout << endl;

		//chia cac truong hop
		switch (choice)
		{
		case 1:
			InputList(st, n);
			break;
		case 2:
			OutputList(st, n);
			break;
		case 3:
			// xuat sinh vien voi id da cho
			cout << "Nhap Id Cua Sinh Vien Can Tim: ";
			cin >> id;
			cout << endl;
			OutputWithId(st, n, id);
			cout << "\n\n---------------------------------------------------------------------------------------\n";
			// luu thong tin sinh vien vua tim duoc vao file
			for (int i = 0; i < n; i++)
			{
				if (st[i].id == id)
				{
					ofs << st[i].name << endl;
					ofs << st[i].id << endl;
					for (int i = 0; i < 3; i++)
					{
						ofs << st[i].marks[i] << " ";
					}
					ofs << endl;
				}
			}
			break;
		case 4:
			// xuat sinh vien voi ten da cho
			cout << "\nNhap Ten Cua Sinh Vien Can In: ";
			cin.ignore();
			getline(cin, name);
			cout << endl;
			OutputWithName(st, n, name);
			cout << "\n\n---------------------------------------------------------------------------------------\n";
			//luu thong tin sinh vien vua tim duoc vao file
			for (int i = 0; i < n; i++)
			{
				if (st[i].name == name)
				{
					ofs << st[i].name << endl;
					ofs << st[i].id << endl;
					for (int i = 0; i < 3; i++)
					{
						ofs << st[i].marks[i] << " ";
					}
					ofs << endl;
				}
			}
			break;
		case 5:
			// tim va xuat sinh vien co diem trung binh cao nhat
			MaxAvgPoint(st, n, max);
			cout << "\n---------------------------------------------------------------------------------------\n\n";
			//luu thong tin sinh vien vua tim duoc vao file
			for (int i = 0; i < n; i++)
			{
				if (AvgPoint(st[i]) == max)
				{
					ofs << st[i].name << endl;
					ofs << st[i].id << endl;
					for (int i = 0; i < 3; i++)
					{
						ofs << st[i].marks[i] << " ";
					}
					ofs << endl;
				}
			}
			break;
		case 6:
			AddStudent(st, n);
			break;
		case 7:
			InputListFile(ifs, st, n);
			cout << "Da Lay Danh Sach Tu File!" << endl;
			cout << "\n---------------------------------------------------------------------------------------\n";
			break;
		case 8:
			// ghi vao file
			
			break;
		case 0:
			return 0;
		}
	}
	ifs.close();
	ofs.close();

	return 0;
}


/*
* ghi them sinh vien vao danh sach trong file

			ofs << n << endl;
			for (int i = 0; i < n; i++)
			{
				ofs << st[i].name << endl;
				ofs << st[i].id << endl;
				for (int i = 0; i < 3; i++)
				{
					ofs << st[i].marks[i] << " ";
				}
				ofs << endl;
			}
			break;
*/