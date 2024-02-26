#pragma once
#ifndef SINHVIEN_H
#define SINHVIEN_H
#define CRT_SECURE_NO_WARNINGS
#include "List.h"

using namespace std;

struct Ngay {
	int ngay;
	int thang;
	int nam;
};

class SinhVien {
private:
	char* ten;
	char* maSo;
	Ngay ngaySinh;
	vector<float> diem;
public:
	SinhVien(const SinhVien&);
	SinhVien(char*, char*, Ngay, vector<float>);
	~SinhVien();
	
};

class MangSinhVien {
private:
	SinhVien* list;
	int size;
public:
	MangSinhVien();
	~MangSinhVien();
	void readFile(string);
	void writeFile(string);
	void sinhVienDuoiTrungBinh(float aveMark);
	void themSinhVien(const SinhVien&);
	void xepLoaiSinhVien();
	void xuatSinhVienXepLoai();
	void sinhVienCungSinhNhat();
};

SinhVien::SinhVien(const SinhVien& sv) {
	strcpy(ten, sv.ten);
	strcpy(maSo, sv.maSo);
	strcpy(ten, sv.ten);
	diem = sv.diem;
}

SinhVien::SinhVien(char* _ten, char* _maSo, Ngay _ngaySinh, vector<float> diem) {
	strcpy(ten, _ten);
	strcpy(maSo, _maSo);
	ngaySinh.ngay = _ngaySinh.ngay;
	ngaySinh.thang = _ngaySinh.thang;
	ngaySinh.nam = _ngaySinh.nam;
}

SinhVien::~SinhVien() {
	delete[] ten;
	delete[] maSo;
}

MangSinhVien::MangSinhVien() {
	list = new SinhVien[1];
}



#endif // !SINH

