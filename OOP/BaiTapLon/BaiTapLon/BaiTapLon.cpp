#define _CRT_SECURE_NO_WARNINGS
#include "date.h"
#include "sinhvien.h"
#include "qlsinhvien.h"


int main() {
	/*int n = 0;
	cout << "Number of students: ";
	cin >> n;

	QLSinhVien l(n);
	l.nhap_DSSV();
	l.xuat_DSSV();*/

	//l.ghi_DSSV();
	//l.underAvgList();

	QLSinhVien l1(0);
	l1.doc_DSSV((char*)"input.txt"); // doc file input
	// xuat danh sach sinh vien ra man hinh
	l1.xuat_DSSV();

	//// ghi file output1 da doc tu input
	//l1.ghi_DSSV((char*)"output1_DSSV.txt"); 
	//
	//// ghi ra danh sach sinh vien thap hon diem trung binh
	//l1.ghi_underAvgList((char*)"output2_DuoiTrungBinh.txt");

	//// ghi danh sach sinh vien co xep loai hoc luc
	//l1.ghi_RankList((char*)"output3_XepLoai.txt");

	//// ghi danh sach sinh vien co ngay sinh trung voi ngay hien tai
	//l1.ghi_CurBirthdayList((char*)"output4_NgaySinhTrungHienTai.txt");


	SinhVien sv1;
	cout << "Nhap Sinh Vien can them: \n";
	cin >> sv1;

	l1.addSV(sv1);
	l1.ghi_DSSV((char*)"output5_AddDSSV.txt");
	

	return 0;
}

