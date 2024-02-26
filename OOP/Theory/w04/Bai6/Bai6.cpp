#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class ThoiGian {
private:
	string gio;
	string phut;
	string giay;
public:
	string getterGio();
	string getterPhut();
	string getterGiay();
	void setterGio(string);
	void setterPhut(string);
	void setterGiay(string);
	int doiSangGiay();
	bool operator>= (ThoiGian);
};

string ThoiGian::getterGio() {
	return gio;
}

string ThoiGian::getterPhut() {
	return phut;
}
string ThoiGian::getterGiay() {
	return giay;
}

void ThoiGian::setterGio(string _gio) {
	gio = _gio;
}
void ThoiGian::setterPhut(string _phut) {
	phut = _phut;
}
void ThoiGian::setterGiay(string _giay) {
	giay = _giay;
}

int ThoiGian::doiSangGiay() {
	return stoi(gio) * 3600 + stoi(phut) * 60 + stoi(giay);
}

bool ThoiGian::operator>=(ThoiGian b) {

	if (this->doiSangGiay() >= b.doiSangGiay()) return true;
	return false;
}

class CaSi {
private:
	string ma;
	string ten;
	ThoiGian tg;
	int binhChon;
public:
	CaSi();
	void Nhap();
	void Xuat();
	ThoiGian getterTG();
	string getterMa();
	int getterBinhChon();
	void setterBinhChon(int);
	string getterTen();
	bool operator>=(CaSi);
	void operator=(CaSi);

};

CaSi::CaSi() {
	ma = "";
	ten = "";
	tg.setterGio("00");
	tg.setterGiay("00");
	tg.setterPhut("00");
	binhChon = 0;
}

void CaSi::Nhap() {

	string temp;
	getline(cin, temp);
	int firstSp = 0;
	int lastSp = temp.length() - 1;

	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] == ' ') {
			firstSp = i;
			break;
		}
	}
	
	for (int i = temp.length(); i >= 0; i--) {
		if (temp[i] == ' ') {
			lastSp = i;
			break;
		}
	}

	ma = temp.substr(0, firstSp);
	ten = temp.substr(firstSp + 1, lastSp - 4);
	stringstream s(temp.substr(lastSp + 1));

	int i = 0;

	while (!s.eof()) {
		string buffer;
		getline(s, buffer, ':');
		if (i == 0) tg.setterGio(buffer);
		if (i == 1) tg.setterPhut(buffer);
		if (i == 2) tg.setterGiay(buffer);
		i++;
	}

}

void CaSi::Xuat() {
	cout << ten;
}

ThoiGian CaSi::getterTG() {
	return tg;
}

string CaSi::getterMa() {
	return ma;
}

string CaSi::getterTen() {
	return ten;
}

int CaSi::getterBinhChon() {
	return binhChon;
}

void CaSi::setterBinhChon(int vote) {
	binhChon = vote;
}

bool CaSi::operator>=(CaSi casi) {

	if (tg >= casi.getterTG()) return true;
	return false;
}

void CaSi::operator=( CaSi casi) {
	ma = casi.ma;
	ten = casi.ten;
	tg.setterGio(casi.tg.getterGio());
	tg.setterPhut(casi.tg.getterPhut());
	tg.setterGiay(casi.tg.getterGiay());
	binhChon = casi.binhChon;
}

class MangCaSi {
private:
	vector<CaSi> list;
public:
	void Nhap();
	void caSiBauNhieuNhat(string);
};

void MangCaSi::Nhap() {
	
	while (!cin.eof()) {
		CaSi temp;
		temp.Nhap();
		list.push_back(temp);
	}
}

void MangCaSi::caSiBauNhieuNhat(string tgian) {

	string batDau = tgian.substr(0, tgian.find(" "));
	string ketThuc = tgian.substr(tgian.find(" ") + 1);

	vector<CaSi> soBinhChon;

	ThoiGian bd;
	bd.setterGio(batDau.substr(0, 2));
	bd.setterPhut(batDau.substr(4, 6));
	if (batDau.length() == 5) {
		bd.setterGiay("00");
	}
	else {
		bd.setterGiay(batDau.substr(7));
	}
	
	ThoiGian kt;
	kt.setterGio(ketThuc.substr(0, 2));
	kt.setterPhut(ketThuc.substr(4, 6));
	if (ketThuc.length() == 5) {
		kt.setterGiay("00");
	}
	else {
		kt.setterGiay(ketThuc.substr(7));
	}

	CaSi prevMax;
	int count = 0;

	for (int i = 0; i < list.size(); i++) {

		if (list[i].getterTG() >= bd && kt >= list[i].getterTG()) {
			list[i].setterBinhChon(list[i].getterBinhChon() + 1);
			soBinhChon.push_back(list[i]);
		}
	}

	for (int i = 0; i < soBinhChon.size(); i++) {
		for (int j = i + 1; j < soBinhChon.size(); j++) {
			if (soBinhChon[j] >= soBinhChon[i]) {
				CaSi temp = soBinhChon[i];
				soBinhChon[i] = soBinhChon[j];
				soBinhChon[j] = temp;

			}
		}
	}

	for (int i = 0; i < soBinhChon.size(); i++) {
		for (int j = i + 1; j < soBinhChon.size(); j++) {
			if (soBinhChon[i].getterMa() == soBinhChon[j].getterMa()) {
				soBinhChon[i].setterBinhChon(soBinhChon[i].getterBinhChon() + 1);
			}
		}
	}

	CaSi max = soBinhChon[0];
	for (int i = 0; i < soBinhChon.size(); i++) {
		if (max.getterBinhChon() < soBinhChon[i].getterBinhChon()) {
			max = soBinhChon[i];
		}
	}

	cout << max.getterTen() << " " << max.getterBinhChon();

}
int main() {

	string temp;
	freopen("INPUT.TXT", "rt", stdin);
	getline(cin, temp, '\n');
	MangCaSi m;
	m.Nhap();
	freopen("OUTPUT.TXT", "wt", stdout);
	m.caSiBauNhieuNhat(temp);

	return 0;
}