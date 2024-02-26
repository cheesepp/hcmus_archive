#include "GiaoDich.h"

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

GiaoDich::GiaoDich()
{
	ma = "";
	ngGD.setNgay(0);
	ngGD.setThang(0);
	ngGD.setNam(0);
	soluong = 0;
}

GiaoDich::GiaoDich(const GiaoDich& other)
{
	ma = other.ma;
	ngGD = other.ngGD;
	soluong = other.soluong;
	dongia = other.dongia;
}

int GiaoDich::getSoLuong()
{
	return soluong;
}

double GiaoDich::getDonGia()
{
	return dongia;
}

Ngay GiaoDich::getNgay()
{
	return ngGD;
}

void GiaoDich::nhap()
{
	cout << "Nhap ma giao dich: ";
	cin >> ma;
	cout << "Nhap ngay giao dich: ";
	cin >> ngGD;
	cout << "Nhap so luong giao dich: ";
	cin >> soluong;
	cout << "Nhap don gia: ";
	cin >> dongia;
}

void GiaoDich::xuat()
{
	cout << "Ma giao dich: " << ma << endl;
	cout << "Ngay giao dich: " << ngGD << endl;
	cout << "So luong giao dich: " << soluong << endl;
	cout << "Don gia: " << dongia << endl;
}

GiaoDich& GiaoDich::operator=(const GiaoDich& other)
{
	ma = other.ma;
	ngGD = other.ngGD;
	soluong = other.soluong;
	dongia = other.dongia;
	return *this;
}

