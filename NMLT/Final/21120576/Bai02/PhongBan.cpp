#include "PhongBan.h"

void nhapPB(PhongBan& pb)
{
	cout << "Nhap ma phong: ";
	cin >> pb.maPhong;
	cout << "Nhap so luong nhan vien: ";
	cin >> pb.soluong;
	cout << "Nhap ten truong phong: ";
	cin.ignore();
	cin.getline(pb.tenTP, 99);
}

void nhapDanhSachPB(PhongBan pb[], int& n)
{
	cout << "\n========= NHAP DANH SACH PHONG BAN =========\n";
	cout << "Nhap so luong phong ban: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "------- Nhap phong ban " << i + 1 << " -------\n";
		nhapPB(pb[i]);
	}
}

void xuatPB(PhongBan pb)
{
	cout << "Ma phong: " << pb.maPhong << endl;
	cout << "So luong nhan vien: " << pb.soluong << endl;
	cout << "Ten truong phong: " << pb.tenTP << endl;
}

void xuatDanhSachPB(PhongBan pb[], int n)
{
	cout << "\n========== DANH SACH PHONG BAN =============\n";
	for (int i = 0; i < n; i++) {
		cout << "-------- Phong ban " << i + 1 << " -----------\n";
		xuatPB(pb[i]);
	}
}

PhongBan PBCoSoNVNhieuNhat(PhongBan pb[], int n)
{
	PhongBan maxNV = pb[0];
	int maxIndex = 0;
	for (int i = 1; i < n; i++) {
		if (maxNV.soluong < pb[i].soluong) {
			maxNV = pb[i];
			maxIndex = i;
		}
		else if (maxNV.soluong == pb[i].soluong) {
			if (maxIndex != i) {
				if (strlen(maxNV.tenTP) < strlen(pb[i].tenTP)) {
					maxNV = pb[i];
				}
			}
		}
	}
	return maxNV;
}
