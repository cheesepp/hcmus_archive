#include "GDTienTe.h"

GDTienTe::GDTienTe(): GiaoDich()
{
	tigia = 0;
	loaitt = "";
}

GDTienTe::GDTienTe(const GDTienTe& other)
{
	tigia = other.tigia;
	loaitt = other.loaitt;
}

string GDTienTe::getLoaiTT() const
{
	return loaitt;
}

void GDTienTe::nhap()
{
	GiaoDich::nhap();
	cout << "Nhap ti gia: ";
	cin >> tigia;
	cout << "Nhap loai tien te: ";
	cin >> loaitt;
}

void GDTienTe::xuat()
{
	GiaoDich::xuat();
	cout << "Ti gia: " << tigia << endl;
	cout << "Loai tien te: " << loaitt << endl;
}

double GDTienTe::salary()
{
	if (loaitt == "vnd") {
		return soluong * dongia;
	}
	return soluong * dongia * tigia;
}

GDTienTe& GDTienTe::operator=(const GDTienTe& other)
{
	GiaoDich::operator=(other);
	tigia = other.tigia;
	loaitt = other.loaitt;
	return *this;
}
