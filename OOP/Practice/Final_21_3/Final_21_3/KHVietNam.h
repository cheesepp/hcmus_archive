#pragma once
#include "KhachHang.h"
class KHVietNam : public KhachHang
{
private:
	int doiTuongKH;
	int dinhMuc;
	DiaChi diaChi;
public:
	KHVietNam();
	~KHVietNam();
	void input();
	void output();
	float thanhTien();
	int getLoaiDT();
};

