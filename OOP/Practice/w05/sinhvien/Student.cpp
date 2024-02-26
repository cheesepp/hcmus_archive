#include "Student.h"

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

