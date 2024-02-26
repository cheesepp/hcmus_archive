#include <iostream> 
#include <string>
using namespace std;

class NhanVien {
protected:
	string HoTen;
	string NgaySinh;
	string DiaChi;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};

void NhanVien::Nhap() {
	cout << "Nhap ten: ";
	getline(cin, HoTen);
	cin.ignore();
	cout << "Ngay sinh: (dd/mm/yyyy)";
	cin >> NgaySinh;
	cout << "Dia chi: ";
	getline(cin, DiaChi);
}

void NhanVien::Xuat() {
	cout << "Ho ten: " << HoTen << endl;
	cout << "Ngay sinh: " << NgaySinh << endl;
	cout << "Dia chi: " << DiaChi << endl;
}

float NhanVien::TinhLuong() {
	return 0;
}
//Khai bao lop con
class NVSanXuat : public NhanVien {
private:
	int SoSanPham;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};

void NVSanXuat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so san pham: ";
	cin >> SoSanPham;
}

void NVSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "So san pham " << SoSanPham;
}

float NVSanXuat::TinhLuong() {
	return SoSanPham * 100000;
}

//Nhan vien cong nhat
class NVCongNhat : public NhanVien {
private:
	int SoNgayCong;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};

void NVCongNhat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so ngay cong: ";
	cin >> SoNgayCong;
}

void NVCongNhat::Xuat() {
	NhanVien::Xuat();
	cout << endl << "So ngay cong: " << SoNgayCong;
}
float NVCongNhat::TinhLuong() {
	return SoNgayCong * 200000;
}
//Nhan vien quan ly
class NVQuanLy : public NhanVien {
private:
	int LuongCoBan;
	int HeSoLuong;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};

void NVQuanLy::Nhap() {
	NhanVien::Nhap();
	cin.ignore();
	cout << "Nhap luong co ban: ";
	cin >> LuongCoBan;
	cout << "Nhap he so luong: ";
	cin >> HeSoLuong;
}

void NVQuanLy::Xuat() {
	NhanVien::Xuat();
	cin.ignore();
	cout << endl << "Luong co ban: " << LuongCoBan;
	cout << endl << "He so luong: " << HeSoLuong;
}
float NVQuanLy::TinhLuong() {
	return LuongCoBan * HeSoLuong;
}
int main() {
	NVCongNhat nv_congnhat[100];
	int s1_nvcn = 0;
	NVSanXuat nv_sanxuat[100];
	int s1_nvsx = 0;
	NVQuanLy nv_quanly[100];
	int s1_nvql = 0;
	float TongLuong = 0;
	for (int i = 0; i < s1_nvcn; ++i) {
		TongLuong += nv_congnhat[i].TinhLuong();
	}
	for (int i = 0; i < s1_nvsx; ++i) {
		TongLuong += nv_sanxuat[i].TinhLuong();
	}
	for (int i = 0; i < s1_nvql; ++i) {
		TongLuong += nv_quanly[i].TinhLuong();
	}

}



























