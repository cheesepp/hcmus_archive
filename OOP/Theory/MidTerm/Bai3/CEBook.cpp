#include "CEBook.h"

CMyDate::CMyDate() {
	ngay = 0;
	thang = 0;
	nam = 0;
}

CMyDate::CMyDate(int _ngay, int _thang, int _nam) {
	ngay = _ngay;
	thang = _thang;
	nam = _nam;
}

int CMyDate::getNgay() {
	return ngay;
}

int CMyDate::getThang() {
	return thang;
}
int CMyDate::getNam() {
	return nam;
}

void CMyDate::setNgay(int _ngay) {
	ngay = _ngay;
}
void CMyDate::setThang(int _thang) {
	thang = _thang;
}
void CMyDate::setNam(int _nam) {
	nam = _nam;
}

bool CMyDate::operator>(const CMyDate& other) {
	if (nam > other.nam)
		return true;
	else if (nam == other.nam && thang > other.thang)
		return true;
	else if (nam == other.nam && thang == other.thang && ngay > other.ngay)
		return true;
	return false;
}

CMyDate& CMyDate::operator=(const CMyDate& ngay) {
	this->ngay = ngay.ngay;
	this->thang = ngay.thang;
	this->nam = ngay.nam;;

	return *this;
}

istream& operator>>(istream& in, CMyDate& x) {

	in >> x.ngay >> x.nam >> x.thang;
	return in;
}

ostream& operator<<(ostream& out, const CMyDate& x) {

	out << x.ngay << "/" << x.thang << "/" << x.nam;
	return out;
}

CEBook::CEBook() {
	ISBN = "";
	ten = "";
	tacgia = "";
	date.setNgay(0);
	date.setThang(0);
	date.setNam(0);
	theLoai = "";
	nhaXB = "";
	price = 0.0;
}

CEBook::CEBook(string _ISBN, string _ten, string _tacgia, CMyDate _date, string _theLoai, string _nhaXB, long double _price) {
	ISBN = _ISBN;
	ten = _ten;
	tacgia = _tacgia;
	date = _date;
	theLoai = _theLoai;
	nhaXB = _nhaXB;
	price = _price;
}

CEBook::CEBook(const CEBook& ceBook) {
	ISBN = ceBook.ISBN;
	ten = ceBook.ten;
	tacgia = ceBook.tacgia;
	date = ceBook.date;
	theLoai = ceBook.theLoai;
	nhaXB = ceBook.nhaXB;
	price = ceBook.price;
}

bool CEBook::operator>(const CEBook& other) {
	if (price > other.price) return true;
	return false;
}

bool CEBook::operator>=(const CEBook& other) {
	if (price >= other.price) return true;
	return false;
}

bool CEBook::operator<(const CEBook& other) {
	if (price < other.price) return true;
	return false;
}

bool CEBook::operator<=(const CEBook& other) {
	if (price <= other.price) return true;
	return false;
}

CEBook& CEBook::operator=(const CEBook& ceBook) {
	ISBN = ceBook.ISBN;
	ten = ceBook.ten;
	tacgia = ceBook.tacgia;
	date = ceBook.date;
	theLoai = ceBook.theLoai;
	nhaXB = ceBook.nhaXB;
	price = ceBook.price;
	return *this;
}

string CEBook::getISBN() const {
	return ISBN;
}

string CEBook::getTen() const {
	return ten;
}

string CEBook::getTacGia() const {
	return tacgia;
}

CMyDate CEBook::getNgayXB() const {
	return date;
}

string CEBook::getTheLoai() const {
	return theLoai;
}

string CEBook::getNhaXB() const {
	return nhaXB;
}

long double CEBook::getGia() const {
	return price;
}

void CEBook::setISBN(string _ISBN) {
	ISBN = _ISBN;
}

void CEBook::setTen(string _ten) {
	ten = _ten;
}

void CEBook::setNhaXB(string _nhaXB) {
	nhaXB = _nhaXB;
}

void CEBook::setTacGia(string _tacgia) {
	tacgia = _tacgia;
}

void CEBook::setNgayXB(CMyDate _ngayxb) {
	date = _ngayxb;
}

void CEBook::setTheLoai(string _tl) {
	theLoai = _tl;
}


void CEBook::setGia(long double _price) {
	price = _price;
}