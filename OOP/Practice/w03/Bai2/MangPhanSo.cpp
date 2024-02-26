#include "MangPhanSo.h"

MangPhanSo::MangPhanSo() {
	n = 0;
	list = NULL;
}

MangPhanSo::MangPhanSo(int size) {
	n = size;
	list = new PhanSo[n];
}

MangPhanSo::~MangPhanSo() {
	delete[] list;
}

void MangPhanSo::nhap() {
	for (int i = 0; i < n; i++) {
		list[i].nhap();
	}
}

void MangPhanSo::xuat() {

	for (int i = 0; i < n; i++) {
		list[i].xuat();
		cout << " ";
	}
}

float MangPhanSo::tinhTong() {
	PhanSo sum = list[0];
	for (int i = 1; i < n; i++) {
		sum = sum + list[i];
	}
	return sum.getterTu() * 1.0f / sum.getterMau();
}

void MangPhanSo::sapXepMang() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (list[i] > list[j]) {
				PhanSo temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}

void MangPhanSo::docFile(string file) {
	ifstream fin(file);
	if (!fin) {
		cout << "\nKhong mo duoc file!\n";
		return;
	}
	string str = "";
	getline(fin, str);
	n = stoi(str);
	list = new PhanSo[n];
	for (int i = 0; i < n; i++) {
		if (!fin.eof()) {
			getline(fin, str);
			int pos = str.find_first_of('/');
			int tu = stoi(str.substr(0, pos));
			int mau = stoi(str.substr(pos + 1));

			PhanSo a;
			a.setterTu(tu);
			a.setterMau(mau);
			list[i] = a;
		}
	}
	cout << "\nDoc file thanh cong!\n";
	xuat();
	fin.close();
}

void MangPhanSo::ghiFile(string file) {
	ofstream fout(file);
	if (!fout) {
		cout << "\nKhong mo duoc file!\n";
		return;
	}

	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << list[i].getterTu() << "/" << list[i].getterMau() << endl;
	}
	cout << "\nGhi file thanh cong!\n";
	fout.close();
}