#pragma once
#include "Phim.h"
#include "vector.h"
#include <fstream>
class QLPhim
{
private:
	vector<Phim*> ds_Phim;
public:
	QLPhim();
	QLPhim(int);
	void input();
	void output();
	void sapXepNamSX();
	void themPhim(Phim*);
	void ghiDanhSachPhim(string tenFile);
	void docDanhSachPhim(string tenFile);
	void xoaPhimHBO(string tenFile);
};

