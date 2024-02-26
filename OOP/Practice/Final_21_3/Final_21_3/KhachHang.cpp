#include "KhachHang.h"

int Ngay::getNgay() {
	return ngay;
}

int Ngay::getThang() {
	return thang;
}
int Ngay::getNam() {
	return nam;
}

void Ngay::setNgay(int _ngay) {
	ngay = _ngay;
}
void Ngay::setThang(int _thang) {
	thang = _thang;
}
void Ngay::setNam(int _nam) {
	nam = _nam;
}


Ngay& Ngay::operator=(const Ngay& ngay) {
	this->ngay = ngay.ngay;
	this->thang = ngay.thang;
	this->nam = ngay.nam;;

	return *this;
}

istream& operator>>(istream& in, Ngay& x) {

	in >> x.ngay >> x.thang >> x.nam;
	return in;
}

ostream& operator<<(ostream& out, const Ngay& x) {

	out << x.ngay << "/" << x.thang << "/" << x.nam;
	return out;
}
DiaChi::DiaChi() {
	sonha = 0;
	tenduong = "";
	phuong = "";
	quan = "";
	tp = "";
}

DiaChi::DiaChi(const DiaChi& other) {
	sonha = other.sonha;
	tenduong = other.tenduong;
	phuong = other.phuong;
	quan = other.quan;
	tp = other.tp;
}

string DiaChi::getQuan() {

	return quan;

}

string DiaChi::getTP() {

	return tp;

}
void DiaChi::nhap() {
	cout << "Nhap dia chi: \n";
	cout << "  So nha: ";
	cin >> sonha;
	cout << "  Duong: ";
	cin.ignore();
	getline(cin, tenduong);
	cout << "  Phuong: ";
	getline(cin, phuong);
	cout << "  Quan: ";
	getline(cin, quan);
	cout << "  Thanh pho (neu thanh pho hcm thi chi can nhap TPHCM): ";
	getline(cin, tp);
}

void DiaChi::xuat() {
	cout << "Dia chi: \n";
	cout << "  So nha: " << sonha << endl;
	cout << "  Duong: " << tenduong << endl;
	cout << "  Phuong: " << phuong << endl;
	cout << "  Quan: " << quan << endl;
	cout << "  Thanh pho: " << tp << endl;
}

KhachHang::KhachHang()
{
	maKH = "";
	hoTen = "";
	soLuong = 0;
	donGia = 0;
}

KhachHang::~KhachHang()
{
}

void KhachHang::input()
{
	cin.ignore();
	do {

		cout << "Nhap ma khach hang: ";
		getline(cin, maKH);
	} while (maKH.length() != 6);

	cout << "Nhap ho ten: ";
	getline(cin, hoTen);
	cout << "Nhap ngay ra hoa don: ";
	cin >> ngayHD;
	cout << "Nhap so luong: ";
	cin >> soLuong;
	do {

	cout << "Nhap don gia (2000, 3000 vnd/kwh): ";
	cin >> donGia;

	} while (donGia <= 2000 || donGia >= 3000);
}

void KhachHang::output()
{
	cout << "Ma khach hang: " << maKH << endl;
	cout << "Ho ten: " << hoTen << endl;
	cout << "Ngay ra hoa don: " << ngayHD << endl;
	cout << "So luong: " << soLuong << endl;
	cout << "Don gia: " << donGia << endl;
}

string KhachHang::getMaKH()
{
	return maKH;
}

float KhachHang::getSoLuong()
{
	return soLuong;
}
