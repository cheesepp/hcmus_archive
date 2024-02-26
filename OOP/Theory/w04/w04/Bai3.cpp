#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
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



class Laptop {
private:
	string ten;
	Ngay date;
public:
	Ngay getterDate();
	void Nhap();
	void Xuat();
	bool operator>(Laptop);
};
class MangLapTop {
private:
	vector <Laptop> list;
public:
	void Nhap();
	Laptop LapTopCuNhat();
};
void MangLapTop::Nhap() {
	while(!cin.eof()) {
	Laptop temp;
		temp.Nhap();
		list.push_back(temp);
	}
}
Laptop MangLapTop::LapTopCuNhat() {
	Laptop min = list[0];
	for (int i = 1; i < list.size(); ++i) {
		if (min>list[i])
			min = list[i];
	}
	return min;
}
Ngay Laptop::getterDate() {
	return date;
}

//Laptop::Laptop(string _ten, Ngay _ngay) {
//	ten = _ten;
//	date.setterNgay(_ngay.getterNgay());
//	date.setterThang(_ngay.getterThang());
//	date.setterNam(_ngay.getterNam());
//}

void Laptop::Nhap() {
	cin >> ten;
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

	
}

void Laptop::Xuat() {
	cout << ten << " " << date.getterNgay() << "/" << date.getterThang() << "/" << date.getterNam() << endl;
}

bool Laptop::operator>(Laptop b) {
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



void docFile(string fileName) {

	ifstream in(fileName);
	if (!in) {
		cout << "Khong mo duoc file!";
		return;
	}

}

int main() {

	freopen("INPUT.TXT", "rt", stdin);
	MangLapTop m;
	m.Nhap();
	Laptop min = m.LapTopCuNhat();
	freopen("OUTPUT.TXT", "wt", stdout);
	min.Xuat();


	return 0;
}