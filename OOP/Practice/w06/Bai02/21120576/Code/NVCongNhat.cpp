#include "NVCongNhat.h"

NVCongNhat::NVCongNhat() : NhanVien() {
	soNgay = 0;
}

NVCongNhat::NVCongNhat(char* ma, char* ten, Ngay ngsinh, char* diachi, char* gioiTinh, int soNgay) : NhanVien(ma, ten, ngsinh, diachi, gioiTinh) {
	this->soNgay = soNgay;
}

NVCongNhat::NVCongNhat(const NVCongNhat& _nvcn) : NhanVien(_nvcn) {
	soNgay = _nvcn.soNgay;
}


int NVCongNhat::getSoNgay() const {
	return soNgay;
}

void NVCongNhat::setSoNgay(int sn) {
	soNgay = sn;
}

void NVCongNhat::input() {

	NhanVien::input();
	cout << "Nhap so ngay: ";
	do {
		cin >> soNgay;
		if (soNgay < 22 || soNgay > 26) {
			cout << "So ngay phai tu 22 den 26! Vui long nhap lai!\n";
		}
	} while (soNgay < 22 || soNgay > 26);

}

void NVCongNhat::print() {
	NhanVien::print();
	cout << "So ngay: " << soNgay << endl;
}

long NVCongNhat::salary() {
	return soNgay * 500000;
}

NVCongNhat& NVCongNhat::operator=(const NVCongNhat& other) {
	NhanVien::operator=(other);
	this->soNgay = other.soNgay;
	return *this;
}

ofstream& NVCongNhat::writeFile(ofstream& fout)
{
	NhanVien::writeFile(fout);
	fout << soNgay << endl;
	return fout;
}