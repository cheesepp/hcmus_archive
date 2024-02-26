#pragma once
#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class PhanSo {
private:
	int tu;
	int mau;
public:
	void nhap();
	void xuat();
	void toiGian();
	int getterTu();
	void setterTu(int);
	int getterMau();
	void setterMau(int);
	PhanSo& operator= (const PhanSo&);
	PhanSo operator+ (PhanSo);
	PhanSo operator- (PhanSo);
	PhanSo operator* (PhanSo);
	PhanSo operator/ (PhanSo);
	bool operator> (const PhanSo&);
};

#endif // !PHANSO_H
