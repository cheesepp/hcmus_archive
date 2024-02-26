#pragma once
#ifndef NGAY_H
#define NGAY_H
#include <iostream>
#include <string>
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


#endif // !NGAY_H
