#include "sinhvien.h"

char* SinhVien::getHoTen() {
	return this->HoTen;
}

char* SinhVien::getID() {
	return this->ID;
}

Date SinhVien::getNgaySinh() {
	return this->NgaySinh;
}

SinhVien::SinhVien() {
	HoTen = nullptr;
	ID = nullptr;
	NgaySinh = Date(0,0,0);
	Marks[0] = 0;
	Marks[1] = 0;
	Marks[2] = 0;
	Avg = 0.0;
}

SinhVien::SinhVien(char* HoTen, char* ID, Date NgaySinh, int Marks0, int Marks1, int Marks2) {
	this->HoTen = HoTen;
	this->ID = ID;
	this->NgaySinh = NgaySinh;
	this->Marks[0] = Marks0;
	this->Marks[1] = Marks1;
	this->Marks[2] = Marks2;
}

SinhVien::SinhVien(const SinhVien& sv) {
	HoTen = sv.HoTen;
	ID = sv.ID;
	NgaySinh = sv.NgaySinh;
	Marks[0] = sv.Marks[0];
	Marks[1] = sv.Marks[1];
	Marks[2] = sv.Marks[2];
	Avg = sv.Avg;
}

SinhVien::~SinhVien() {
	delete[] HoTen;
	delete[] ID;
}



/*----- Implementation SinhVien class -----*/

ostream& operator << (ostream& out, SinhVien& std) {
	out << std.HoTen << " "
		<< std.ID << " "
		<< std.NgaySinh << " "
		<< std.Marks[0] << " "
		<< std.Marks[1] << " "
		<< std.Marks[2];
	return out;
}


/*-------- Nhap Sinh Vien ---------*/
void SinhVien::input_std(SinhVien& std) {
	//cin.ignore();
	cout << "Name: ";
	HoTen = new char[30];
	cin.getline(std.HoTen, 30);

	cout << "ID: ";
	std.ID = new char[10];
	cin.getline(std.ID, 10);

	cout << "Date of birth: ";
	cin >> std.NgaySinh;

	cout << "Mark 1 (On class): ";
	cin >> std.Marks[0];
	cout << "Mark 2 (Mid-term): ";
	cin >> std.Marks[1];
	cout << "Mark 3 (Final): ";
	cin >> std.Marks[2];
}
istream& operator>>(istream& in, SinhVien& std) {
	std.input_std(std);
	return in;
}

SinhVien& SinhVien::operator=(const SinhVien& sv) {
	if (this != &sv) {
		HoTen = new char[strlen(sv.HoTen) + 1];
		strcpy(HoTen, sv.HoTen);
		ID = new char[strlen(sv.ID) + 1];
		strcpy(ID, sv.ID);
		NgaySinh = sv.NgaySinh;
		for (int i = 0; i < 3; i++) {
			Marks[i] = sv.Marks[i];
		}
	}
	return *this;
}

double SinhVien::getAvg() { // Tinh diem trung binh cua sinh vien
	double Avg = Marks[0] * 0.25 + Marks[1] * 0.25 + Marks[2] * 0.5;
	return Avg;
}

void SinhVien::rankSV() { // Ham xep loai sinh vien
	if (getAvg() < 5) {
		cout << "Yeu";
		return;
	}
	if (getAvg() < 6.5) {
		cout << "Trung Binh";
		return;
	}
	if (getAvg() < 8) {
		cout << "Kha";
		return;
	}
	if (getAvg() < 9) {
		cout << "Gioi";
		return;
	}
	else {
		cout << "Xuat Sac";
		return;
	}
}