//#include <iostream>
//#include <cstring>
//#include <fstream>
//using namespace std;
//
//class PhanSo {
//private:
//	int tu;
//	int mau;
//public:
//	PhanSo(int, int);
//	int GetterTu();
//	void SetterTu(int);
//	int GetterMau();
//	void SetterMau(int);
//	friend istream& operator>> (istream &, PhanSo&);
//	friend ostream& operator<< (ostream &, const PhanSo&);
//
//};
//
//PhanSo::PhanSo(int _tu, int _mau) {
//	tu = _tu;
//	mau = _mau;
//}
//
//int PhanSo::GetterTu() {
//	return tu;
//}
//
//void PhanSo::SetterTu(int _tu) {
//	tu = _tu;
//}
//
//int PhanSo::GetterMau() {
//	return mau;
//}
//
//void PhanSo::SetterMau(int _mau) {
//	mau = _mau;
//}
//
//istream& operator>> (istream& in, PhanSo& x) {
//	cout << "Nhap tu va mau cua phan so: ";
//	in >> x.tu >> x.mau;
//	return in;
//}
//
//ostream& operator<< (ostream& os, const PhanSo& x) {
//	os << x.tu << "/" << x.mau;
//	return os;
//}
//
//void docFile(string fileName) {
//
//	ifstream in(fileName);
//	if (!in) {
//		cout << "Khong mo duoc file!";
//		return;
//	}
//	
//}
//
//int main() {
//
//	
//
//	return 0;
//}