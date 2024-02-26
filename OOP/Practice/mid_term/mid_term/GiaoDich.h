#pragma once
#include <iostream>
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

class GiaoDich
{
protected:
	string ma;
	Ngay ngGD;
	int soluong;
	double dongia;
public:
	GiaoDich();
	GiaoDich(const GiaoDich&);
	int getSoLuong();
	double getDonGia();
	Ngay getNgay();
	//void setSoLuong(int);
	virtual void nhap();
	virtual void xuat();
	virtual double salary() {
		return 0;
	}
	virtual GiaoDich& operator=(const GiaoDich&);
};

