#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
private:
	int tu;
	int mau;
	int UCLN();
public:
	PhanSo();
	PhanSo(int _tu, int _mau);
	void rutGon();

	PhanSo operator++();
	PhanSo operator++(int temp);
	PhanSo operator+(const PhanSo&);
	PhanSo operator-(const PhanSo&);
	PhanSo operator*(const PhanSo&);
	PhanSo operator/(const PhanSo&);
	PhanSo operator=(const PhanSo&);
	friend istream& operator>>(istream& in, PhanSo&);
	friend ostream& operator<<(ostream& out, const PhanSo&);

};

