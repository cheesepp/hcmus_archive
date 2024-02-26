#pragma once
#define MAX 100
#include <iostream>
#include <fstream>
using namespace std;

//(10đ) Khai báo cấu trúc với các thông tin đã cho.
struct PhongBan {
	unsigned int maPhong;
	unsigned int soluong;
	char tenTP[100];
};

//(15đ) Nhập danh sách các phòng ban
void nhapPB(PhongBan& pb);
void nhapDanhSachPB(PhongBan pb[], int &n);

// Hàm để test
void xuatPB(PhongBan pb);
void xuatDanhSachPB(PhongBan pb[], int n);

//(15đ) Tìm phòng ban có số lượng nhân viên nhiều nhất.Nếu có
//nhiều phòng ban cùng số lượng nhân viên thì trả về phòng ban có
//tên trường phòng dài nhất
PhongBan PBCoSoNVNhieuNhat(PhongBan pb[], int n);



