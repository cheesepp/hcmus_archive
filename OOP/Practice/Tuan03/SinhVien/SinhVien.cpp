#define _CRT_SECURE_NO_WARNINGS
#include "SinhVien.h"


const int MAX = 30;

// -----------------  Cac constructor cua sinh vien -----------------

SinhVien::SinhVien()
{
	HoTen = new char[30];
	Ma = new char[20];
	NgSinh.Ngay = NgSinh.Thang = NgSinh.Nam = 0;
	Marks[0] = Marks[1] = Marks[2] = 0;
}
SinhVien::SinhVien(char* hoTen, char* ma, NgaySinh ngaySinh, float marks[]) {
	HoTen = new char[30];
	Ma = new char[20];
	strcpy(HoTen, hoTen);
	strcpy(Ma, ma);
	NgSinh.Ngay = ngaySinh.Ngay;
	NgSinh.Thang = ngaySinh.Thang;
	NgSinh.Nam = ngaySinh.Nam;

	for (int i = 0; i < 3; ++i)
		Marks[i] = marks[i];
}

// --------------------------------------------------------------------

SinhVien::SinhVien(const SinhVien& s) {
	HoTen = new char[30];
	Ma = new char[20];
	strcpy(this->HoTen, s.HoTen);
	strcpy(this->Ma, s.Ma);
	
	NgSinh.Ngay = s.NgSinh.Ngay;
	NgSinh.Thang = s.NgSinh.Thang;
	NgSinh.Nam = s.NgSinh.Nam;
	for (int i = 0; i < 3; ++i)
		Marks[i] = s.Marks[i];
}

// ------------------------- Setter ----------------------------
void SinhVien::setHoTen(char* hoTen) {
	strcpy(HoTen, hoTen);
}
void SinhVien::setMa(char* ma) {
	strcpy(Ma, ma);
}
void SinhVien::setNgaySinh(const NgaySinh& d) {
	this->NgSinh.Ngay = d.Ngay;
	this->NgSinh.Thang = d.Thang;
	this->NgSinh.Nam = d.Nam;
}
void SinhVien::setMark0(const float& mark) {
	Marks[0] = mark;
}
void SinhVien::setMark1(const float& mark) {
	Marks[1] = mark;
}
void SinhVien::setMark2(const float& mark) {
	Marks[2] = mark;
}

// -------------------------------------------------------------

// ------------------------- Getter ----------------------------

char* SinhVien::getHoTen() {
	return HoTen;
}

char* SinhVien::getMa() {
	return Ma;
}

NgaySinh SinhVien::getNgaySinh() {
	return NgSinh;
}

float* SinhVien::getMarks() {
	return Marks;
}

// --------------------------------------------------------------

// Toan tu gan bang cho SinhVien
SinhVien& SinhVien::operator=(const SinhVien& s) {
	strcpy(HoTen, s.HoTen);
	strcpy(Ma, s.Ma);
	NgSinh.Ngay = s.NgSinh.Ngay;
	NgSinh.Thang = s.NgSinh.Thang;
	NgSinh.Nam = s.NgSinh.Nam;
	for (int i = 0; i < 3; ++i)
		Marks[i] = s.Marks[i];
	return *this;
}

// Destructor SinhVien
SinhVien::~SinhVien()
{
	delete[]HoTen;
	delete[] Ma;
	NgSinh.Ngay = NgSinh.Thang = NgSinh.Nam = 0;
	Marks[0] = Marks[1] = Marks[2] = 0;
}

// Ham nhap sinh vien
void SinhVien::Nhap() {
	cout << "Nhap ho ten: ";
	cin.ignore();
	cin.getline(HoTen, 29, '\n');
	cout << "Nhap ma: ";
	cin.getline(Ma, 19, '\n');
	cout << "Nhap ngay sinh (lan luot ngay, thang, nam): ";
	cin >> NgSinh.Ngay;
	cin >> NgSinh.Thang;
	cin >> NgSinh.Nam;
	cout << "Nhap lan luot diem bai tap, giua ki va cuoi ki: ";
	for (int i = 0; i < 3; ++i)
		cin >> Marks[i];
}

// Ham xuat sinh vien
void SinhVien::Xuat() {
	cout << "Ho ten: " << HoTen << "||Ma so: " << Ma << "||Ngay sinh : ";
	cout << NgSinh.Ngay << "/" << NgSinh.Thang << "/" << NgSinh.Nam;
	float DiemTB = Marks[0] * 0.25 + Marks[1] * 0.25 + Marks[2] * 0.5;
	cout << "||Diem trung binh: " << DiemTB;
}

// Ham xep loai sinh vien
string SinhVien::xeploai() {
	float stdAvg = Marks[0] * 0.25
		+ Marks[1] * 0.25
		+ Marks[2] * 0.5;
	if (stdAvg >= 9) {
		return "Xuat sac";
	}
	if (stdAvg >= 8 && stdAvg < 9) {
		return "Gioi";
	}
	if (stdAvg >= 7 && stdAvg < 8) {
		return "Kha";
	}
	if (stdAvg >= 6 && stdAvg < 7) {
		return "Trung binh";
	}
	if (stdAvg < 6) {
		return "Yeu";
	}
}
