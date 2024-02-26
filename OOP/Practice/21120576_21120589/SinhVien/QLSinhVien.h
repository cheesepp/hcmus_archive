#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "SinhVien.h"

// Class khai bao cac thuoc tinh va phuong thuc cua QLSinhVien

class QLSinhVien
{
private:
	SinhVien* arrSV;
	int n;
public:
	QLSinhVien(); // Constructor
	~QLSinhVien(); // Destructor
	bool ReadFile(const char*); // Ghi file
	bool WriteFile(const char*); // Doc file
	bool ThemSV(const char*, SinhVien sv); // Them sinh vien
	bool SVNhoHonDTBLop(const char*); //Sinh vien co diem tb nho hon diem tb lop
	void XepLoaiSV(); // Xep loai sinh vien
	void XuatDSSV(); // Xuat DSSV da xep loai
	void SVCungNgaySinh(); // Tim sinh vien cung ngay sinh voi ngay hien tai
};


