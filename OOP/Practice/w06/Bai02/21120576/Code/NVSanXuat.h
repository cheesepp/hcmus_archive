#pragma once
#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#include "NhanVien.h"

class NVSanXuat : public NhanVien {
private:
	int soSanPham;
public:
	NVSanXuat();
	NVSanXuat(char*, char*, Ngay, char*, char*, int);
	NVSanXuat(const NVSanXuat&);
	int getSoSP() const;
	void setSoSP(int);
	void input();
	void print();
	long salary();
	NVSanXuat& operator=(const NVSanXuat&);
	ofstream& writeFile(ofstream&);
};
#endif // !NVSANXUAT_H
