#pragma once
#ifndef MANGPHANSO_H
#define MANGPHANSO_H
#include "PhanSo.h"

class MangPhanSo {
private:
	PhanSo* list;
	int n;
public:
	MangPhanSo();
	MangPhanSo(int);
	~MangPhanSo();
	void nhap();
	void xuat();
	float tinhTong();
	void sapXepMang();
	void docFile(string);
	void ghiFile(string);
};
#endif