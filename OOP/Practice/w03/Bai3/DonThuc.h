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
	void xuat();
	float getterHeso();
	int getterBac();
	float tinhGiaTri(float);
	DonThuc operator+ (const DonThuc&);
	DonThuc operator- (const DonThuc&);
	DonThuc operator* (const DonThuc&);
	DonThuc operator/ (const DonThuc&);
	DonThuc operator= (const DonThuc&);
};

class DaThuc {
private:
	DonThuc* daThuc;
	int n;
public:
	DaThuc();
	DaThuc(int size);
	~DaThuc();
	DonThuc* getterDaThuc();
	void setterDaThuc(const DonThuc&);
	void nhap();
	void xuat();
	float tinhDaThuc(float x);
	DaThuc congDaThuc(const DaThuc&);
	DaThuc truDaThuc(const DaThuc&);
	DaThuc nhanDaThuc(const DaThuc&);
	DaThuc chiaDaThuc(const DaThuc&);
};
#endif // !DONTHUC_H
