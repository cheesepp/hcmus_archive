#include "QLEBook.h"


int main() {
	QLEBook list;
	list.readFile("INPUT.txt");
	list.sapXepGiaSachGiamDan();
	list.thongKeISBN();
	list.sapXepSachTangTheoNgay();
	return 0;
}