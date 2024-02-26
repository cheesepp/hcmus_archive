#include "PhanSo.h"

void PhanSo::nhap() {
	cin >> tu >> mau;
}

void PhanSo::xuat() {
	cout << tu << "/" << mau;
}

int PhanSo::getterTu() {
	return tu;
}
int PhanSo::getterMau() {
	return mau;
}

void PhanSo::setterTu(int _tu) {
	tu = _tu;
}

void PhanSo::setterMau(int _mau) {
	mau = _mau;
}

void PhanSo::toiGian() {
	int tuTmp = tu;
	int mauTmp = mau;
	while (tuTmp != mauTmp) {
		if (tuTmp > mauTmp) tuTmp = tuTmp - mauTmp;
		else mauTmp = mauTmp - tuTmp;
	}
	tu = tu / mauTmp;
	mau = mau / mauTmp;
}

PhanSo PhanSo:: operator+ (PhanSo b) {
	this->toiGian();
	b.toiGian();
	int tu1 = tu * b.mau + b.tu * mau;
	int mau1 = mau * b.mau;
	PhanSo a;
	a.setterTu(tu1);
	a.setterMau(mau1);
	return a;
}

PhanSo PhanSo:: operator- (PhanSo b) {
	this->toiGian();
	b.toiGian();
	int tu1 = tu * b.mau - b.tu * mau;
	int mau1 = mau * b.mau;
	PhanSo a;
	a.setterTu(tu1);
	a.setterMau(mau1);
	return a;
}

PhanSo PhanSo::operator* (PhanSo b) {
	this->toiGian();
	b.toiGian();
	int tu1 = tu * b.tu;
	int mau1 = mau * b.mau;
	PhanSo a;
	a.setterTu(tu1);
	a.setterMau(mau1);
	return a;
}

PhanSo PhanSo::operator/ (PhanSo b) {
	this->toiGian();
	b.toiGian();
	int tu1 = tu * b.mau;
	int mau1 = mau * b.tu;
	PhanSo a;
	a.setterTu(tu1);
	a.setterMau(mau1);
	return a;
}

PhanSo& PhanSo::operator= (const PhanSo& b) {
	this->tu = b.tu;
	this->mau = b.mau;
	return *this;
}

bool PhanSo::operator> (const PhanSo& b) {
	if ((tu * 1.0 / mau) > (b.tu * 1.0 / b.mau)) {
		return true;
	}
	return false;
}





