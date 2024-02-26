#pragma once
#ifndef DONTHUC_H
#define DONTHUC_H
#include <iostream>
#include <vector>

using namespace std;

class DonThuc {
private:
	float heso;
	int bac;
public:
	DonThuc();
	DonThuc(float, int);
	void nhap();
	void xuat() const;
	float getterHeso();
	int getterBac();
	void setterHeso(float);
	void setterBac(int);
	float tinhGiaTri(float);
	DonThuc operator+ (const DonThuc&);
	DonThuc operator- (const DonThuc&);
	DonThuc operator* (const DonThuc&);
	DonThuc operator/ (const DonThuc&);
	DonThuc& operator= (const DonThuc&);
};
#endif // !DONTHUC_H