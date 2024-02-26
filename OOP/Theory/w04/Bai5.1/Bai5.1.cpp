// Bai5.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Ngay {
private:
	string ngay;
	string thang;
	string nam;
public:
	string getterNgay();
	string getterThang();
	string getterNam();
	void setterNgay(string);
	void setterThang(string);
	void setterNam(string);
};

string Ngay::getterNgay() {
	return ngay;
}

string Ngay::getterThang() {
	return thang;
}
string Ngay::getterNam() {
	return nam;
}

void Ngay::setterNgay(string _ngay) {
	ngay = _ngay;
}
void Ngay::setterThang(string _thang) {
	thang = _thang;
}
void Ngay::setterNam(string _nam) {
	nam = _nam;
}


class CauThu {
private:
	string stt;
	string ten;
	Ngay date;
	string gioiTinh;
public:
	void Nhap();
	void Xuat();
	Ngay getterDate();
	string getterGT();
	//string getterGT();
	int xuatTuoi();
	bool operator>(CauThu);
	
};

string CauThu::getterGT() {
	return gioiTinh;
}
Ngay CauThu::getterDate() {
	return date;
}

bool CauThu::operator>(CauThu b) {
	if (date.getterNam() > b.getterDate().getterNam()) {
		return true;
	}
	else if (date.getterNam() == b.getterDate().getterNam()) {
		if (date.getterThang() > b.getterDate().getterThang()) {
			return true;
		}
		else if (date.getterThang() == b.getterDate().getterThang()) {
			if (date.getterNgay() > b.getterDate().getterNgay()) {
				return true;
			}
			else
				return false;
		}
	}
	else
		return false;
}



void CauThu::Nhap() {
	cin >> stt;
	string tentmp;
	cin >> tentemp;
	string name;
	for (int i = 0; i < tentmp.size(); i++) {
		if (tentmp[i]<'0' || tentmp[i]>'9')
	}
	string temp;
	cin >> temp;
	stringstream s(temp);
	int i = 0;
	while (!s.eof()) {
		string buffer;
		getline(s, buffer, '/');
		if (i == 0) date.setterNgay(buffer);
		if (i == 1) date.setterThang(buffer);
		if (i == 2) date.setterNam(buffer);
		i++;
	}
	cin >> gioiTinh;
}


int CauThu::xuatTuoi() {
	return 2023 - stoi(date.getterNam());
}

class MangCauThu {
private:
	vector<CauThu> list;
public:
	void Nhap();
	CauThu nuCauThuMax();
};

CauThu MangCauThu::nuCauThuMax() {
	CauThu max;
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getterGT() == "F") {
			max = list[i];
			break;
		}
		
	}
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getterGT() == "F" && list[i] > max) {
			max = list[i];
		}
		
	}
	return max;
}

void MangCauThu::Nhap() {
	while (!cin.eof()) {
		CauThu temp;
		temp.Nhap();
		list.push_back(temp);
	}
}

void CauThu::Xuat() {}

int main()
{
    freopen("INPUT.TXT", "rt", stdin);
	MangCauThu a;
    a.Nhap();
    CauThu max = a.nuCauThuMax();
    freopen("OUTPUT.TXT", "wt", stdout);
    max.Xuat();
    cout << " " << max.xuatTuoi();
	return 0;
}