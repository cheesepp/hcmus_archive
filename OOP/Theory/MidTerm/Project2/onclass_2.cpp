#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;


class DocGia {
private:
	string hoten;
	string gioiTinh;
	string ma;
	string phai;
	string day;
public:
	virtual int Nhap() {

		string buffer = "";
		getline(cin, buffer, ',');
		ma = buffer;

		getline(cin, buffer, ' ');
		getline(cin, buffer, ',');
		hoten = buffer;

		getline(cin, buffer, ' ');
		getline(cin, buffer, ',');
		phai = buffer;

		getline(cin, buffer, ' ');
		getline(cin, buffer, ',');
		day = buffer;
		int namSinh;
		int start = (int)buffer.find_last_of('/');
		int end = (int)buffer.find_last_of(',');
		
		namSinh = stoi(buffer.substr(start + 1,end));

		if (2023 - namSinh >= 12) return 2;
		else return 1;
	
	}
};


class Child:public DocGia{
private:
	string bl;
public: 
	virtual void NhapC() {
		string buffer = "";
		getline(cin, buffer, '.');
		bl = buffer;
		getline(cin, buffer, '\n');
	}
};

class Adult:public DocGia{
private:
	string cmnd;
public:
	virtual void NhapA() {
		string buffer = "";
		getline(cin, buffer, '.');
		cmnd = buffer;
		getline(cin, buffer, '\n');

	}
};

class ThuVien {
private:
	vector<DocGia*> list;
public:
	void Nhap() {
		Adult* listAD = new Adult[100];
		int sizeAD = 0;
		Child* listTE = new Child[100];
		int sizeTE = 0;
		while (!cin.eof()) {
			DocGia temp;
			if (temp.Nhap() == 1) {
				Child TE;
				TE.NhapC();
				listTE[sizeTE++] = TE;
			}
			else {
				Adult AD;
				AD.NhapA();
				listAD[sizeAD++] = AD;
			}
		}
		list.push_back(listAD);
		list.push_back(listTE);
	}
};

int main() {
	freopen("onclass_2.txt", "r", stdin);
	ThuVien list;

	list.Nhap();
}