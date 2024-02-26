#pragma once
#include "KHVietNam.h"
#include "KHNuocNgoai.h"
#include <vector>
class QLHoaDon
{
private:
	KhachHang** listHD;
	int cap;
	int size;
public:
	QLHoaDon();
	~QLHoaDon();
	void inputList();
	void outputList();
	void avgThanhTien();
	void timHDLonNhatMoiDoiTuong();
	void themKH(KhachHang*&);
	int getSize();
	void setSize(int);
	void readFile(string filename);
	void KHCoSoDienNhoHon150(string filename);
	void sapXepLoaiDT();
};

