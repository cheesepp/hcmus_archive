#pragma once
#ifndef NhanVien_H
#define NhanVien_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Ngay {
private:
	int ngay;
	int thang;
	int nam;
public:
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int);
	void setThang(int);
	void setNam(int);
	Ngay& operator= (const Ngay&);
	friend istream& operator>> (istream&, Ngay&);
	friend ostream& operator<< (ostream&, const Ngay&);
};
class NhanVien {
private:
	char* maNV;
	char* hoten;
	char* diaChi;
	char* gioiTinh;
	Ngay ngaySinh;

public:
	//Constructors
	NhanVien();
	NhanVien(char*, char*, Ngay, char*, char*);
	NhanVien(const NhanVien& NhanVien);
	~NhanVien();
	//getter, setter
	char* getMaNV() const;
	void setMaNV(char*);

	char* getHoten()const;
	void setHoten(char*);

	Ngay getNgaySinh() const;
	void setNgaySinh(const Ngay&);

	char* getDiaChi() const;
	void setDiaChi(char*);
	
	char* getGioiTinh() const;
	void setGioiTinh(char*);

	//other methods
	virtual void input();
	virtual void print();
	virtual NhanVien& operator=(const NhanVien&);
	virtual long salary() {
		return 0;
	}
	friend ofstream& operator<<(ofstream& fout, NhanVien nv);
	virtual ofstream& writeFile(ofstream&);
};

#endif