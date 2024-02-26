#pragma once
#include <iostream>
using namespace std;
class NgaySinh {
public:
	int* Ngay;
	int* Thang;
	int* Nam;
};
class SinhVien
{
private:
	char* HoTen;
	char* Ma;
	NgaySinh Date;
	float Marks[3];
public:
	SinhVien();
	SinhVien(char*, char*, char*, float[]);
	SinhVien(const SinhVien&);
	SinhVien operator=(const SinhVien&);
	~SinhVien();
	void Nhap();
	void Xuat();
};

