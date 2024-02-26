#include "DonThuc.h"


DonThuc::DonThuc() {
	heso = 0;
	bac = 0;
}

DonThuc::DonThuc(float _hs, int _bac) {
	heso = _hs;
	bac = _bac;
}
void DonThuc::nhap() {
	cout << "Nhap he so va bac: ";
	cin >> heso >> bac;
}

void DonThuc::xuat() {
	cout << heso << "*" << "x" << "^" << bac;
}

float DonThuc::getterHeso() {
	return heso;
}

int DonThuc::getterBac() {
	return bac;
}


float DonThuc::tinhGiaTri(float x) {
	return pow(heso * x, bac);
}
DonThuc DonThuc::operator+ (const DonThuc& b) {
	int heso1;
	if (bac == b.bac) {
		heso1 = heso + b.heso;
		DonThuc a(heso1, bac);
		return a;
	}
	else {
		cout << "Hai don thuc khong cung bac!";
		return DonThuc();
	}
}

DonThuc DonThuc::operator- (const DonThuc& b) {
	int heso1;
	if (bac == b.bac) {
		heso1 = heso - b.heso;
		DonThuc a(heso1, bac);
		return a;
	}
	else {
		cout << "Hai don thuc khong cung bac!";
		return DonThuc();
	}
}

DonThuc DonThuc::operator* (const DonThuc& b) {
	float heso1 = heso * b.heso;
	int bac1 = bac + b.bac;
	DonThuc a(heso1, bac1);
	return a;
}

DonThuc DonThuc::operator/ (const DonThuc& b) {
	float heso1 = heso * 1.0 / b.heso;
	int bac1 = bac - b.bac;
	DonThuc a(heso1, bac1);
	return a;
}

DonThuc DonThuc::operator= (const DonThuc& b) {
	this->heso = b.heso;
	this->bac = b.bac;
	return *this;
}

//float DaThuc::tinhDaThuc(float x) {
//	float sum = 0;
//	for (int i = 0; i < n + 1; i++) {
//		sum = sum + daThuc[i].tinhGiaTri(x);
//	}
//	return sum;
//}
//
//DaThuc DaThuc::congDaThuc(const DaThuc& b) {
//	vector<DonThuc> temp;
//	int sumSize = n + b.n;
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (daThuc[i].getterBac() == b.daThuc[j].getterBac()) {
//				DonThuc t = daThuc[i] + daThuc[j];
//				temp.push_back(t);
//			}
//			else {
//				
//			}
//		}
//	}
//	
//}

DaThuc::DaThuc() {
	daThuc = NULL;
	n = 0;
}

DaThuc::DaThuc(int size) {
	daThuc = new DonThuc[size];
	n = size;
}

void DaThuc::nhap() {
	cout << "Nhap so luong don thuc: ";
	cin >> n;
	daThuc = new DonThuc[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap don thuc " << i + 1 << ":" << endl;
		daThuc[i].nhap();
	}
}

void DaThuc::xuat() {
	for (int i = 0; i < n; i++) {
		daThuc[i].xuat();

	}
}

float DaThuc::tinhDaThuc(float x) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += daThuc[i].tinhGiaTri(x);
	}
	return res;
}

DaThuc DaThuc::congDaThuc(const DaThuc& b) {
	DaThuc res(n + b.n);
	int i = 0, j = 0, k = 0;
	while (i < n && j < b.n) {
		if (daThuc[i].getterBac() == daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++] + daThuc[j++];
		}
		else if (daThuc[i].getterBac() > daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++];
		}
		else {
			res.daThuc[k++] = daThuc[j++];
		}
	}
	while (i < n) {
		res.daThuc[k++] = daThuc[i++];
	}
	while (j < b.n) {
		res.daThuc[k++] = daThuc[j++];
	}
	return res;
}

DaThuc DaThuc::truDaThuc(const DaThuc& b) {
	DaThuc res(n + b.n);
	int i = 0, j = 0, k = 0;
	while (i < n && j < b.n) {
		if (daThuc[i].getterBac() == daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++] - daThuc[j++];
		}
		else if (daThuc[i].getterBac() > daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++];
		}
		else {
			res.daThuc[k++] = daThuc[j++] * (DonThuc(-1, 0));
		}
	}
	while (i < n) {
		res.daThuc[k++] = daThuc[i++];
	}
	while (j < b.n) {
		res.daThuc[k++] = daThuc[j++] * (DonThuc(-1, 0));
	}
	return res;
}

DaThuc DaThuc::nhanDaThuc(const DaThuc& b) {
	DaThuc res(n * b.n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < b.n; j++) {
			res.daThuc[k++] = daThuc[i] * daThuc[j];
		}
	}
	return res;
}

DaThuc DaThuc::chiaDaThuc(const DaThuc& b) {
	DaThuc res(n - b.n);
	DaThuc dividend(*this), divisor(b);
	for (int i = 0; i < res.n; i++) {
		DonThuc quotient = dividend.daThuc[0] / divisor.daThuc[0];
		res.daThuc[i] = quotient;
		DaThuc temp(1);
		temp.daThuc[0] = quotient * (divisor.daThuc[0] * DonThuc(-1, dividend.daThuc[0].getterBac() - divisor.daThuc[0].getterBac()));
		dividend = dividend.truDaThuc(temp);
		dividend.n--;
		for (int j = 0; j < dividend.n; j++) {
			dividend.daThuc[j] = dividend.daThuc[j + 1];
		}
		dividend.daThuc[dividend.n] = DonThuc();
	}
	return res;
}

DonThuc* DaThuc::getterDaThuc() {
	return daThuc;
}

// Hàm hủy của lớp Đa thức
DaThuc::~DaThuc() {
	delete[] daThuc;
}