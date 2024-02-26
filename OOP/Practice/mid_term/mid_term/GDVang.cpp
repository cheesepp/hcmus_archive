#include "GDVang.h"

GDVang::GDVang() : GiaoDich()
{
	loaivang = "";
}

GDVang::GDVang(const GDVang& other): GiaoDich(other)
{
	loaivang = other.loaivang;
}

void GDVang::nhap()
{
	GiaoDich::nhap();
	cout << "Nhap loai vang: ";
	cin >> loaivang;
}

void GDVang::xuat()
{
	GiaoDich::xuat();
	cout << "Loai vang: " << loaivang << endl;
}

double GDVang::salary()
{
	return soluong*dongia;
}

GDVang& GDVang::operator=(const GDVang& other)
{
	GiaoDich::operator=(other);
	loaivang = other.loaivang;
	return *this;
}


