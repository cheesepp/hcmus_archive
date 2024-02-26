#pragma once
#ifndef __SINHVIEN_H__
#include "date.h"


class SinhVien {
private:
	char* HoTen;
	char* ID;
	Date NgaySinh;
	int Marks[3];
	double Avg ;
public:
	SinhVien();
	SinhVien(char*, char*, Date, int, int, int);
	SinhVien(const SinhVien&);
	~SinhVien();

	char* getHoTen();
	char* getID();
	Date getNgaySinh();

	void input_std(SinhVien& std);

	// overload istream/ostream operator
	friend ostream& operator << (ostream& out, SinhVien& std);
	friend istream& operator >> (istream& in, SinhVien& std);

	SinhVien& operator = (const SinhVien&);

	double getAvg();// lay diem trung binh Avg
	void rankSV();// Ham xep loai sinh vien

	

};

#endif // !__SINHVIEN_H__

