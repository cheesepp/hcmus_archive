#pragma once
#include <iostream>
#include <string>
#include <fstream>

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

class DiaChi {
private:
	int sonha;
	string tenduong;
	string phuong;
	string quan;
	string tp;
public:
	DiaChi();
	DiaChi(const DiaChi& other);
	string getQuan();
	string getTP();
	void nhap();
	void xuat();
};

class KhachHang
{
protected:
	string maKH;
	string hoTen;
	Ngay ngayHD;
	float soLuong;
	long donGia;
public:
	KhachHang();
	~KhachHang();
	virtual void input();
	virtual void output();
	virtual float thanhTien() = 0;
	string getMaKH();
	float getSoLuong();
};

