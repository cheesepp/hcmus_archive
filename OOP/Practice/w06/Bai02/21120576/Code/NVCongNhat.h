#pragma once
#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

#include "NhanVien.h"

class NVCongNhat : public NhanVien {
private:
	int soNgay;

public:
	NVCongNhat();
	NVCongNhat(char*, char*, Ngay, char*, char*, int);
	NVCongNhat(const NVCongNhat&);
	int getSoNgay() const;
	void setSoNgay(int);
	void input();
	void print();
	long salary();
	NVCongNhat& operator=(const NVCongNhat&);
	ofstream& writeFile(ofstream&);
};
#endif // !NVCONGNHAT_H
