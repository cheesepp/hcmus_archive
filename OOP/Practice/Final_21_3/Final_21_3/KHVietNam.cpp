#include "KHVietNam.h"

KHVietNam::KHVietNam(): KhachHang()
{
	doiTuongKH = 0;
	dinhMuc = 0;
}

KHVietNam::~KHVietNam()
{
}

void KHVietNam::input()
{
	KhachHang::input();
	do {
		cout << "Nhap doi tuong khach hang, luu y: \n";
		cout << "    1: Doi tuong sinh hoat\n";
		cout << "    2: Doi tuong kinh doanh\n";
		cout << "    3: Doi tuong san xuat\n";
		cout << "Vui long chon: ";
		cin >> doiTuongKH;
	} while (doiTuongKH != 1 && doiTuongKH != 2 && doiTuongKH != 3);
	switch (doiTuongKH)
	{
	case 1:
		dinhMuc = 150;
		break;
	case 2:
		dinhMuc = 300;
		break;
	case 3:
		dinhMuc = 500;
		break;
	}
	cout << "Nhap dia chi: ";
	diaChi.nhap();
	
}

void KHVietNam::output()
{
	KhachHang::output();
	cout << "Doi tuong Khach hang: ";
	switch (doiTuongKH) {
	case 1:
		cout << "Sinh hoat\n";
		break;
	case 2:
		cout << "Kinh doanh\n";
		break;
	case 3:
		cout << "San xuat\n";
		break;
	}
	cout << "Dinh muc: " << dinhMuc;
	cout << "Dia chi: ";
	diaChi.xuat();
}

float KHVietNam::thanhTien()
{
	if (soLuong < dinhMuc) {
		return soLuong * donGia;
	}
	return donGia * dinhMuc + (soLuong - dinhMuc) * donGia * 1.5;
}

int KHVietNam::getLoaiDT()
{
	return doiTuongKH;
}
