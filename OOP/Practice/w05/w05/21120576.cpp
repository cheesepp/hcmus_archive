#include "QLPhim.h"

int main() {

	QLPhim p;
	p.input();
	p.output();
	p.sapXepNamSX();
	p.output();
	Phim* e = new Phim();
	e->input();
	p.themPhim(e);
	p.output();
	p.ghiDanhSachPhim("input.dat");
	QLPhim q;
	q.docDanhSachPhim("input.dat");
	q.output();
	q.xoaPhimHBO("input.dat");
	q.output();
	return 0;
}