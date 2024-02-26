#pragma once
#include <iostream>
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
	void ThemSV(SinhVien sv);
	void SVNhoHonDTBLop(); //Sinh vien co diem tb nho hon diem tb lop
	void XepLoaiSV();
	void XuatDSSV();
	void SVCungNgaySinh();
};


