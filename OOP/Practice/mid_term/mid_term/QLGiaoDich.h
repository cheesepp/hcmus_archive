#pragma once
#include "GiaoDich.h"
#include "GDVang.h"
#include "GDTienTe.h"
class QLGiaoDich: public GDVang, public GDTienTe
{
private:
	GiaoDich** list;
	int sz;
	int capacity;
public:
	QLGiaoDich();
	QLGiaoDich(int);
	QLGiaoDich(const QLGiaoDich& other);
	void nhap();
	void xuat();
	void tongSoLuong();
	void maxGDTienTe();
	void GDT1N2021();
};

