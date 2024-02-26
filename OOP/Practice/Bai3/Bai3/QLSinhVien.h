#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "SinhVien.h"
class QLSinhVien
{
private:
	SinhVien* arrSV;
	int n;
public:
	QLSinhVien();
	~QLSinhVien();
	bool ReadFile(const char*);
	bool WriteFile(const char*);
	bool ThemSV(string,SinhVien sv);
	bool SVNhoHonDTBLop(string); //Sinh vien co diem tb nho hon diem tb lop
	void XepLoaiSV();
	void XuatDSSV();
	void SVCungNgaySinh();
};


