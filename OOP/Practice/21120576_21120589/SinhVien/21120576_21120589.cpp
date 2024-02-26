#include "SinhVien.h"
#include "QLSinhVien.h"

void menu() {

	QLSinhVien list;
	int option;
	list.ReadFile("INPUT.txt");
	cout << "\n================== CHUONG TRINH QUAN LI SINH VIEN ======================\n";
	do {
		cout << "======================================================================\n";
		cout << "|| Nhap mot trong cac tuy chon sau:                                 ||\n";
		cout << "|| 1: Ghi danh sach sinh vien hien co vao file OUPUT.txt            ||\n";
		cout << "|| 2: Ghi danh sach sinh vien co diem trung binh thap               ||\n";
		cout << "|| hon diem trung binh lop vao file OUTPUTTB.txt                    ||\n";
		cout << "|| 3: Them mot sinh vien vao danh sach va update vao file INPUT.txt ||\n";
		cout << "|| 4: Xuat ra cac sinh vien co cung ngay sinh nhat voi ngay hien tai||\n";
		cout << "|| 5: Xuat danh sach sinh vien da xep loai                          ||\n";
		cout << "|| 0: Thoat chuong trinh                                            ||\n";
		cout << "======================================================================\n";
		cout << "Vui long chon: ";
		cin >> option;

		switch (option) {
		case 1:
		{
			bool hasWritten = list.WriteFile("OUTPUT.txt");
			if (hasWritten) cout << "Ghi file thanh cong!\n";
			else cout << "Ghi file khong thanh cong!\n";
			break;
		}
		case 2:
		{
			list.SVNhoHonDTBLop("OUTPUTTB.txt");
			break;
		}
		case 3: {
			cout << "\n==================== NHAP SINH VIEN ======================\n";
			SinhVien sv;
			sv.Nhap();
			if (list.ThemSV("INPUT.txt", sv)) {
				cout << "Them sinh vien thanh cong!\n";
			}
			else {
				cout << "Them sinh vien chua thanh cong!\n";
			}
			break;

		}

		case 4:
		{
			list.SVCungNgaySinh();
			break;
		}
		case 5:
		{
			list.XuatDSSV();
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