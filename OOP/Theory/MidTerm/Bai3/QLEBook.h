#pragma once
#ifndef QLEBOOK_H
#define QLEBOOK_H
#include "CEBook.h"

class QLEBook {
private:
	vector<CEBook> list;
public:
	void readFile(string);
	void writeFile(string, int);
	void thongKeISBN();
	void sapXepGiaSachGiamDan();
	void sapXepSachTangTheoNgay();
};


#endif // !QLEBOOK_H
