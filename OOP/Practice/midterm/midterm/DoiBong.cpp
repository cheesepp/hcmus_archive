#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
class DoiBong
{
private:
	char* tendoi;
	int tranThang;
	int tranHoa;
	int tranThua;
	int banThang;
	int banThua;
public:
	DoiBong() {
		tendoi = new char[100];
		tranThang = 0;
		tranHoa = 0;
		tranThua = 0;
		banThang = 0;
		banThua = 0;
	}

	DoiBong(char* _ten, int _thang, int _hoa, int _thua) {
		tendoi = new char[100];
		strcpy(tendoi, _ten);
		tranThang = _thang;
		tranHoa = _hoa;
		tranThua = _thua;
	}

	DoiBong(const DoiBong& other) {
		tendoi = new char[100];
		strcpy(tendoi, other.tendoi);
		tranThang = other.tranThang;
		tranHoa = other.tranHoa;
		tranThua = other.tranThua;
	}

	//~DoiBong() {
	//	delete[]tendoi;
	//}

	void input() {
		cin.ignore();
		tendoi = new char[100];
		cout << "Nhap ten doi: ";
		cin.getline(tendoi, 99);
		cout << "Nhap tran thang: ";
		cin >> tranThang;
		cout << "Nhap tran hoa: ";
		cin >> tranHoa;
		cout << "Nhap tran thua: ";
		cin >> tranThua;
		cout << "Nhap so ban thang: ";
		cin >> banThang;
		cout << "Nhap so ban thua: ";
		cin >> banThua;
	}

	void print() {
		cout << "Ten doi: " << tendoi << endl;
		cout << "Diem so: " << tinhDiem() << endl;
		cout << "Hieu so: " << hieuSo() << endl;
	}

	int tinhDiem() const {
		return tranThang * 3 + tranHoa * 1;
	}

	int hieuSo() const {
		return tranThang - tranThua;
	}

	void thiDau(DoiBong doithu, int soBanThang, int soBanThua) {
		if (soBanThang > soBanThua) tranThang++;
		else if (soBanThang == soBanThua) tranHoa++;
		else tranThua++;
		banThang += soBanThang;
		banThua += soBanThua;	
	}

	bool operator>=(const DoiBong& other) {
		if (hieuSo() >= other.hieuSo()) return true;

		return false;
	}

	bool operator<=(const DoiBong& other) {
		if (hieuSo() <= other.hieuSo()) return true;

		return false;
	}

	bool operator< (const DoiBong& other) {
		if (hieuSo() < other.hieuSo()) return true;

		return false;
	}

	bool operator> (const DoiBong& other) {
		if (hieuSo() > other.hieuSo()) return true;

		return false;
	}

	DoiBong& operator= (const DoiBong& other) {
		strcpy(tendoi, other.tendoi);
		tranThang = other.tranThang;
		tranHoa = other.tranHoa;
		tranThua = other.tranThua;
		return *this;
	}

};