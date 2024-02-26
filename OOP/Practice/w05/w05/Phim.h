#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Phim
{
private:
	char* id;
	char* tenPhim;
	char* theLoai;
	char* nhaSX;
	int namSX;
	int xepHang;
public:
	Phim();
	void input();
	void output();
	int getNamSX() const;
	char* getTheLoai() const;
	Phim& operator=(const Phim&);
	~Phim();
};

