#include "DonThuc.h"


DonThuc::DonThuc() {
	heso = 0;
	bac = 0;
}

DonThuc::DonThuc(float _hs, int _bac) {
	heso = _hs;
	bac = _bac;
}
void DonThuc::nhap() {
	cout << "Nhap he so va bac: ";
	cin >> heso >> bac;
}

void DonThuc::xuat() const {
	if (bac != 0)
		cout << heso << "*" << "x" << "^" << bac;
	else
		cout << heso;
}

float DonThuc::getterHeso() {
	return heso;
}

int DonThuc::getterBac() {
	return bac;
}


float DonThuc::tinhGiaTri(float x) {
	return pow(heso * x, bac);
}
DonThuc DonThuc::operator+ (const DonThuc& b) {
	int heso1;
	if (bac == b.bac) {
		heso1 = heso + b.heso;
		DonThuc a(heso1, bac);
		return a;
	}
	else {
		return DonThuc();
	}
}

DonThuc DonThuc::operator- (const DonThuc& b) {
	int heso1;
	if (bac == b.bac) {
		heso1 = heso - b.heso;
		DonThuc a(heso1, bac);
		return a;
	}
	else {
		return DonThuc();
	}
}

DonThuc DonThuc::operator* (const DonThuc& b) {
	float heso1 = heso * b.heso;
	int bac1 = bac + b.bac;
	DonThuc a(heso1, bac1);
	return a;
}

DonThuc DonThuc::operator/ (const DonThuc& b) {
	float heso1 = heso * 1.0 / b.heso;
	int bac1 = bac - b.bac;
	DonThuc a(heso1, bac1);
	return a;
}

DonThuc& DonThuc::operator= (const DonThuc& b) {
	heso = b.heso;
	bac = b.bac;
	return *this;
}

void DonThuc::setterBac(int _bac) {
	bac = _bac;
}

void DonThuc::setterHeso(float _heso) {
	heso = _heso;
}