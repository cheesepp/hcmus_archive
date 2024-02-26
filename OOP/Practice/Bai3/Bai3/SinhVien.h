#pragma once
#include <iostream>
using namespace std;
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
	void setMark1 (const float&);
	void setMark2 (const float&);

	char* getHoTen();
	char* getMa();
	NgaySinh getNgaySinh();
	float* getMarks();

	SinhVien();
	SinhVien (char*,char*, NgaySinh, float[]);
	//SinhVien(const SinhVien&);
	SinhVien& operator=(const SinhVien&);
	~SinhVien();
	void Nhap();
	void Xuat();
	string xeploai();
};

