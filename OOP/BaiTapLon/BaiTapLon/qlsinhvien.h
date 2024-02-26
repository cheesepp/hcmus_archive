#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef __QLSINHVIEN_H__
#include <string.h>
#include "date.h"
#include "sinhvien.h"
#include <fstream>
#include <sstream>

class QLSinhVien {
private:
	SinhVien* sv;
	int size;

public:
	QLSinhVien(int); // constructor
	~QLSinhVien(); // destructor
	SinhVien& operator[](int);
	int getSize();
	
	void nhap_DSSV(); // input DSSV
	void xuat_DSSV(); // output DSSV
	void ghi_DSSV(char*); // write DSSV
	void doc_DSSV(char*); // read DSSV

	double getCAvg(); // diem trung binh cua lop
	void ghi_underAvgList(char*); 

	void ghi_RankList(char*);

	Date getCurDay();
	void ghi_CurBirthdayList(char*);

	void addSV(SinhVien);
	


};



#endif // !__QLSINHVIEN_H__

