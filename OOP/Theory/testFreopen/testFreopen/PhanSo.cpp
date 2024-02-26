#include "PhanSo.h"


int PhanSo::UCLN()
{
	int a = abs(tu); int b = abs(mau);
	while (a != b) {
		if (a > b) a = a - b;
		if (b > a) b = b - a;
	}
	return a;
}

PhanSo::PhanSo()
{
	tu = 0;
	mau = 0;
}

PhanSo::PhanSo(int _tu, int _mau)
{
	tu = _tu;
	mau = _mau;
}

void PhanSo::rutGon() {
	int ucln = UCLN();
	tu /= ucln;
	mau /= ucln;
}
PhanSo PhanSo::operator++()
{
	tu += mau;
	return *this;
}

PhanSo PhanSo::operator++(int t)
{
	PhanSo temp(tu, mau);
	tu += mau;
	return temp;
}

PhanSo PhanSo::operator+(const PhanSo& other)
{
	PhanSo res;
	res.tu = tu* other.mau + other.tu * mau;
	res.mau = mau * other.mau;
	return res;
}

PhanSo PhanSo::operator-(const PhanSo& other)
{
	PhanSo res;
	res.tu = tu * other.mau - other.tu * mau;
	res.mau = mau * other.mau;
	return res;
}

PhanSo PhanSo::operator*(const PhanSo& other)
{
	PhanSo res;
	res.tu = tu * other.tu;
	res.mau = mau * other.mau;
	return res;
}

PhanSo PhanSo::operator/(const PhanSo& other)
{
	PhanSo res;
	res.tu = tu * other.mau;
	res.mau = mau * other.tu;
	return res;
}

PhanSo PhanSo::operator=(const PhanSo& other)
{
	tu = other.tu;
	mau = other.mau;
	return *this;
}

istream& operator>>(istream& in, PhanSo& p)
{
	cout << "Nhap lan luot tu va mau: ";
	in >> p.tu >> p.mau;
	return in;
}

ostream& operator<<(ostream& out, const PhanSo& p)
{
	cout << p.tu << "/" << p.mau;
	return out;
}
