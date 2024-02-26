#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NongDan {
private:
	string maso;
	string phai;
	int sucLuc;
public:
	void Nhap();
	void Xuat();
};

void NongDan::Nhap() {
		cin >> maso;
		string buffer;
		int pos = 0;
		getline(cin, buffer);
		phai = "";
		for (int i = 0; i < buffer.size(); ++i) {
			if (buffer[i] >= '0' && buffer[i] <= '9') {
				pos = i;
				break;
			}
			phai += buffer[i];
		}
		for (int i = 0; i < phai.size() - 1; ++i) {
			phai[i] = phai[i + 1];
		}
		phai.resize(phai.size() - 2);
		buffer = buffer.substr(pos);
		sucLuc = stoi(buffer);
}

void NongDan::Xuat() {
	cout << maso << " " << phai << " " << sucLuc << endl;
}

class ChienBinh {
private:
	string maso;
	int sucAn;
	string tamTrang;
	int sucDanh;
public:
	void Nhap();
	void Xuat();
};

void ChienBinh::Nhap() {
		cin >> maso;
		cin >> sucAn;
		cin >> tamTrang;
		cin >> sucDanh;
}

void ChienBinh::Xuat() {
	cout << maso << " " << sucAn << " " << tamTrang << " " << sucDanh << endl;
}

class MangNhanVat {
private:
	vector<NongDan> lND;
	vector<ChienBinh> lCB;
public:
	void Nhap();
	void Xuat();

};

void MangNhanVat::Nhap() {
	
	while (!cin.eof()) {
		string temp;
		getline(cin, temp);
		int count = 0;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == ' ') {
				count++;
			}
		}
		if (count == 3) {
			NongDan temp;
			temp.Nhap();
			lND.push_back(temp);
		}
		else if (count == 4) {
			ChienBinh temp;
			temp.Nhap();
			lCB.push_back(temp);
		}
	}
}

void MangNhanVat::Xuat() {
	for (NongDan c : lND) {
		c.Xuat();
	}

	for (ChienBinh b : lCB) {
		b.Xuat();
	}
}



int main() {
	freopen("INPUT.TXT", "r", stdin);
	MangNhanVat list;
	list.Nhap();
	freopen("OUTPUT.TXT", "w", stdout);
	list.Xuat();
	return 0;
}