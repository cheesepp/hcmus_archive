#pragma once
#include "GiaoDich.h"
class GDTienTe : public GiaoDich
{
private:
	double tigia;
	string loaitt;
public:
	GDTienTe();
	GDTienTe(const GDTienTe&);
	string getLoaiTT() const;
	void nhap();
	void xuat();
	double salary();
	GDTienTe& operator=(const GDTienTe&);
};

