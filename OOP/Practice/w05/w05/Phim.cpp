#include "Phim.h"

Phim::Phim()
{
	id = new char[6];
	tenPhim = new char[20];
	theLoai = new char[20];
	nhaSX = new char[20];
	namSX = 0;
	xepHang = -1;
}

void Phim::input()
{
	cout << "Nhap id: ";
	cin.ignore();
	cin.getline(id, 5);
	cout << "Nhap ten phim: ";
	cin.getline(tenPhim, 19);
	cout << "Nhap the loai: ";
	cin.getline(theLoai, 19);
	cout << "Nhap nha san xuat: ";
	cin.getline(nhaSX, 19);
	cout << "Nhap nam san xuat: ";
	cin >> namSX;
	cout << "Nhap xep hang: ";
	cin >> xepHang;
}

void Phim::output()
{
	cout << "ID: " << id << endl;
	cout << "Ten phim: " << tenPhim << endl;
	cout << "The loai: " << theLoai << endl;
	cout << "Nha san xuat: " << nhaSX << endl;
	cout << "Nam san xuat: " << namSX << endl;
	cout << "Xep hang: " << xepHang << endl;
}

int Phim::getNamSX() const
{
	return namSX;
}

char* Phim::getTheLoai() const
{
	return theLoai;
}

Phim& Phim::operator=(const Phim& p)
{
	strcpy(id, p.id);
	strcpy(tenPhim, p.tenPhim);
	strcpy(theLoai, p.theLoai);
	strcpy(nhaSX, p.nhaSX);
	namSX = p.namSX;
	xepHang = p.xepHang;
	return *this;
}

Phim::~Phim()
{
	delete[] id;
	delete[] tenPhim;
	delete[] theLoai;
	delete[] nhaSX;
}
