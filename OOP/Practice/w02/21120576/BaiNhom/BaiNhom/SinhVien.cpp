#include "SinhVien.h"

const int MAX = 100;

SinhVien::SinhVien()
{
	HoTen = Ma = NULL;
	Date.Ngay = Date.Thang = Date.Nam = NULL;
	Marks[0] = Marks[1] = Marks[2] = 0;
}
SinhVien::SinhVien(char* hoTen, char* ma, char* ngaySinh, float marks[]) {
	strcpy(HoTen, hoTen);
	strcpy(Ma, ma);
	
	for (int i = 0; i < 3; ++i)
		Marks[i] = marks[i];
}

SinhVien::SinhVien(const SinhVien& s) {
	*this = s;
}
SinhVien SinhVien::operator=(const SinhVien& s) {
	SinhVien temp;
	strcpy_s(temp.HoTen,MAX, s.HoTen);
	strcpy_s(temp.Ma, MAX, s.Ma);
	strcpy_s(temp.Date.Ngay, MAX, s.Date.Ngay);
	strcpy_s(temp.Date.Thang, MAX, s.Date.Thang);
	strcpy_s(temp.Date.Nam, MAX, temp.Date.Nam);
	for (int i = 0; i < 3; ++i)
		temp.Marks[i] = s.Marks[i];	
}
SinhVien::~SinhVien()
{
}
void SinhVien::Nhap() {
	cin >> HoTen;
	cin >> Ma;
	cin >> Date.Ngay;
	cin >> Date.Thang;
	cin >> Date.Nam;
	for (int i = 0; i < 3; ++i)
		cin >> Marks[i];
}
void SinhVien::Xuat() {
	cout << "Ho ten: " << HoTen << "/" << "Ma so: " << Ma << "/" << "Ngay sinh: ";
	cout << Date.Ngay << "/" << Date.Thang << "/" << Date.Nam;
	float DiemTB = Marks[0] * 0.25 + Marks[1] * 0.25 + Marks[2] * 0.5;
}
