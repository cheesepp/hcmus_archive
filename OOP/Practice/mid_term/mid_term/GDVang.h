#pragma once
#include "GiaoDich.h"
class GDVang : public GiaoDich
{
private:
	string loaivang;
public:
	GDVang();
	GDVang(const GDVang&);
	void nhap();
	void xuat();
	double salary();
	GDVang& operator=(const GDVang& other);

};

