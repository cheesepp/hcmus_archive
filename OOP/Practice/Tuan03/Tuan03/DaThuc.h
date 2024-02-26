#pragma once
#ifndef DATHUC_H
#define DATHUC_H
#include "DonThuc.h"

class DaThuc {
private:
	DonThuc* daThuc;
	int n;
public:
	DaThuc();
	DaThuc(int size);
	~DaThuc();
	//void releaseMemory();
	DonThuc* getterDaThuc();
	void setterDaThuc(const DonThuc&);
	void nhap();
	void xuat() const;
	float tinhDaThuc(float x);
	DaThuc congDaThuc(const DaThuc&);
	DaThuc truDaThuc(const DaThuc&);
	DaThuc nhanDaThuc(const DaThuc&);
	DaThuc chiaDaThuc(const DaThuc&);
	DaThuc& operator= (const DaThuc&);
	void reset();
};
#endif