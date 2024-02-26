#include "NVSanXuat.h"

NVSanXuat::NVSanXuat() : NhanVien() {
	soSanPham = 0;
}

NVSanXuat::NVSanXuat(char* ma, char* ten, Ngay ngsinh, char* diachi, char* gioitinh, int soSP) : NhanVien(ma, ten, ngsinh, diachi, gioitinh) {
	soSanPham = soSP;
}

NVSanXuat::NVSanXuat(const NVSanXuat& _nvsx) : NhanVien(_nvsx) {
	soSanPham = _nvsx.soSanPham;
}


int NVSanXuat::getSoSP() const {
	return soSanPham;
}

void NVSanXuat::setSoSP(int ssp) {
	soSanPham = ssp;
}

void NVSanXuat::input() {
	NhanVien::input();
	cout << "Nhap so san pham: ";
	do {
		cin >> soSanPham;
		if (soSanPham < 10 || soSanPham > 15) {
			cout << "So san pham phai tu 10 den 15! Vui long nhap lai!\n";
		}
	} while (soSanPham < 10 || soSanPham > 15);
}

void NVSanXuat::print() {
	NhanVien::print();
	cout << "So san pham: " << soSanPham << endl;
}

long NVSanXuat::salary() {
	return soSanPham * 50000;
}

NVSanXuat& NVSanXuat::operator=(const NVSanXuat& other) {
	NhanVien::operator=(other);
	this->soSanPham = other.soSanPham;
	return *this;
}


ofstream& NVSanXuat::writeFile(ofstream& fout)
{
	NhanVien::writeFile(fout);
	fout << soSanPham << endl;
	return fout;
}
