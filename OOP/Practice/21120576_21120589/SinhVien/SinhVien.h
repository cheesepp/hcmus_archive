#pragma once
#include <iostream>
using namespace std;

// Class khai bao cac thuoc tinh va phuong thuc cua SinhVien

class NgaySinh {
public:
	int Ngay;
	int Thang;
	int Nam;
};

class SinhVien
{
private:
	char* HoTen;
	char* Ma;
	NgaySinh NgSinh;
	float Marks[3];
public:
	void setHoTen(char*);
	void setMa(char*);
	void setNgaySinh(const NgaySinh&);
	void setMark0(const float&);
	void setMark1(const float&);
	void setMark2(const float&);

	char* getHoTen();
	char* getMa();
	NgaySinh getNgaySinh();
	float* getMarks();

	SinhVien(); // Constructor
	SinhVien(char*, char*, NgaySinh, float[]); // Attribute Constructor
	SinhVien(const SinhVien&); // Copy constructor
	SinhVien& operator=(const SinhVien&); // Assign operator
	~SinhVien(); // Destructor
	void Nhap(); // Ham nhap
	void Xuat(); // Ham xuat
	string xeploai(); // Ham xep loai sinh vien
};

