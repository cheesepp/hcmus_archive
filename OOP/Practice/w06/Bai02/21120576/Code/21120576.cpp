#include "CongTy.h"

void menu() {

	CongTy cty;
	int option;
	cout << "\n============== CHUONG TRINH QUAN LI NHAN VIEN ==============\n";
	do {
		cout << "=========================================================\n";
		cout << "|| Nhap mot trong cac tuy chon sau:                    ||\n";
		cout << "|| 1: Nhap danh sach nhan vien                         ||\n";
		cout << "|| 2: Xuat danh sach nhan vien                         ||\n";
		cout << "|| 3: Ghi danh sach nhan vien vao file ds_NhanVien.dat ||\n";
		cout << "|| 4: Doc danh sach nhan vien tu file ds_NhanVien.dat  ||\n";
		cout << "|| 5: Tinh tong luong cua tat ca nhan vien             ||\n";
		cout << "|| 6: Tim nhan vien co luong cao nhat                  ||\n";
		cout << "|| 7: Tim nhan vien theo ma nhan vien                  ||\n";
		cout << "|| 8: Tim nhan vien theo ho ten                        ||\n";
		cout << "|| 9: Tim nhan vien sinh vao thang 5                   ||\n";
		cout << "|| 10:Them mot nhan vien moi                           ||\n";
		cout << "|| 11:Xoa mot nhan vien                                ||\n";
		cout << "|| 12:Ghi tat ca nhan vien co muc luong thap hon       ||\n";
		cout << "|| luong trung binh                                    ||\n";
		cout << "|| 0: Thoat chuong trinh                               ||\n";
		cout << "=========================================================\n";
		cout << "Vui long chon: ";
		cin >> option;

		switch (option) {
		case 1:
		{
			cty.input();
			cty.print();
			break;
		}
		case 2:
		{
			cty.print();
			break;
		}
		case 3:
		{
			cty.writeListEmp("ds_NhanVien.dat");
			break;
		}
		case 4: {
			cty.readListEmp("ds_NhanVien.dat");
			break;

		}

		case 5:
		{
			long sum = cty.sumSalary();
			cout << "Tong luong cua tat ca nhan vien: " << sum << endl;
			break;
		}
		case 6:
		{
			cty.maxSalary();
			
			break;
		}
		case 7:
		{
			cout << "Nhap ma nhan vien can tim: " << endl;
			char* maNV = new char[6];
			cin.ignore();
			do {
				cin.getline(maNV, 6);
				if (strlen(maNV) < 5) {
					cout << "Ma nhan vien phai gom 5 ki tu! Vui long nhap lai!\n";
				}

			} while (strlen(maNV) < 5);

			cty.findEmpById(maNV);
			delete[] maNV;
			
			break;
		}
		case 8:
		{
			cout << "Nhap ten nhan vien can tim: " << endl;
			char* hoten = new char[20];
			cin.ignore();
			cout << "Nhap ho ten: ";
			cin.getline(hoten, 19);

			cty.findEmpByName(hoten);
			delete[] hoten;
			
			break;
		}
		
		case 9:
		{
			

			cty.findEmpBornMonth5();
			
			break;
		}
		
		case 10:
		{
			

			cty.addEmployee();
			
			break;
		}
		
		case 11:
		{
			

			cty.deleteEmployee();
			
			break;
		}
		
		case 12:
		{
			

			cty.empWhoseSalaryLessThanAvg("emp_LowerAvgSalary.dat");
			
			break;
		}
		default:
			cout << "\n================= KET THUC CHUONG TRINH! ===================\n";
		}

	} while (option);
}
int main() {

	menu();

	return 0;
}