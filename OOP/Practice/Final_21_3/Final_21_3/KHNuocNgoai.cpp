#include "KHNuocNgoai.h"

KHNuocNgoai::KHNuocNgoai(): KhachHang()
{
	quocTich = "";
}

KHNuocNgoai::~KHNuocNgoai()
{
}

float KHNuocNgoai::thanhTien()
{
	return soLuong * donGia;
}
