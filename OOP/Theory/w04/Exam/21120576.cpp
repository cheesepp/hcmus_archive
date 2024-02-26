#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

string generateID(set<string>& existingIDs) {
	string id = "";
	srand(time(NULL)); 

	for (int i = 0; i < 6; i++) {
		id += to_string(rand() % 10);
	}

	while (existingIDs.count(id) > 0) {
		id = "";
		for (int i = 0; i < 6; i++) {
			id += to_string(rand() % 10);
		}
	}

	existingIDs.insert(id);

	return id;
}

class Ngay {
private:
	int ngay;
	int thang;
	int nam;
public:
	Ngay();
	Ngay(int, int, int);
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int);
	void setThang(int);
	void setNam(int);
	Ngay& operator= (const Ngay&);
	friend istream& operator>> (istream&, Ngay&);
	friend ostream& operator<< (ostream&, const Ngay&);
	bool operator>(const Ngay&);
	long dayToHours();
};

Ngay::Ngay() {
	ngay = 0;
	thang = 0;
	nam = 0;
}

Ngay::Ngay(int _ng, int _th, int _n) {
	ngay = _ng;
	thang = _th;
	nam = _n;
}

long Ngay::dayToHours() {

	int soNgayTrongThang[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return ngay * 24 + thang * soNgayTrongThang[thang] * 24 + nam * 365 * 24;
}

bool Ngay::operator>(const Ngay& other) {
	if (nam > other.nam)
		return true;
	else if (nam == other.nam && thang > other.thang)
		return true;
	else if (nam == other.nam && thang == other.thang && ngay > other.ngay)
		return true;
	return false;
}


int Ngay::getNgay() {
	return ngay;
}

int Ngay::getThang() {
	return thang;
}
int Ngay::getNam() {
	return nam;
}

void Ngay::setNgay(int _ngay) {
	ngay = _ngay;
}
void Ngay::setThang(int _thang) {
	thang = _thang;
}
void Ngay::setNam(int _nam) {
	nam = _nam;
}

Ngay& Ngay::operator=(const Ngay& ngay) {
	this->ngay = ngay.ngay;
	this->thang = ngay.thang;
	this->nam = ngay.nam;;

	return *this;
}

istream& operator>>(istream& in, Ngay& x) {

	in >> x.ngay >> x.thang >> x.nam;
	return in;
}

ostream& operator<<(ostream& out, const Ngay& x) {

	out << x.ngay << "/" << x.thang << "/" << x.nam;
	return out;
}
// ===================================== MOCK DATA ===================================

vector <string> listOfNames = { "Nguyen Thi Huong", "Le Van An" , "Tran Thi Minh Chau", "Pham Duc Tung", "Dang Thanh Ha" , "Vu Minh Duc" , "Ngo Thi Thu Huong" , "Trinh Quang Minh" , "Ly Thanh Tung" , "Hoang Thi Nhung" };

vector <string> listOfIDs = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

vector <Ngay> listOfDates = { Ngay(22, 4, 2003), Ngay(30, 6, 1997) ,Ngay(25, 7, 2002), Ngay(28, 3, 2000), Ngay(21, 4, 1995), Ngay(22, 8, 1997),
Ngay(18, 2, 1993), Ngay(17, 5, 2003), Ngay(16, 8, 1998) , Ngay(31, 5, 1999), };

vector <int> listOfAlbums = {2, 1, 5, 7, 6, 13, 9, 2, 5, 4};

vector <int> listOfPerformDate = { 20, 15, 23, 19, 5, 50, 26, 26, 6, 12 };

vector <long> listOfFollowers = { 1200000, 48000 , 1100000 , 12000 ,1250000 , 10000 , 1300000 , 20000, 1020000, 125000 };

vector <int> listOfgameShows = { 34, 12, 25, 40, 24, 65, 33, 32, 10, 41 };

// ========================================================================================

class CaSi {
protected:
	string hoten;
	string maso;
	Ngay ngsinh;
	int soAlbumPH;
	int sobuoiBDTrongThang;
	int followers;
public:
	CaSi();
	CaSi(string, string, Ngay, int, int, int);
	CaSi(const CaSi&);
	string getHoten() const;
	string getMaso() const;
	Ngay getNgSinh() const;
	int getSoAlbumPH() const;
	int getSoBuoiBDTrongThang() const;
	int getFollowers() const;
	void setHoten(string);
	void setMaso(string);
	void setNgSinh(Ngay);
	void setSoAlbumPH(int);
	void setSoBuoiBDTrongThang(int);
	void setFollowers(int);
	friend istream& operator>>(istream& in, CaSi&);
	friend ostream& operator<<(ostream& out, const CaSi&);

	virtual long salary() = 0;
};


CaSi::CaSi() {
	hoten = "";
	maso = "";
	ngsinh.setNgay(0);
	ngsinh.setThang(0);
	ngsinh.setNam(0);
	soAlbumPH = 0;
	sobuoiBDTrongThang = 0;
	followers = 0;
	
}

CaSi::CaSi(string _hoten, string _maso, Ngay _ngsinh, int _soAlbum, int _sobuoiBD, int _followers) {
	hoten = _hoten;
	maso = _maso;
	ngsinh = _ngsinh;
	soAlbumPH = _soAlbum;
	sobuoiBDTrongThang = _sobuoiBD;
	followers = _followers;
}

CaSi::CaSi(const CaSi& cs) {
	hoten = cs.hoten;
	maso = cs.maso;
	ngsinh = cs.ngsinh;
	soAlbumPH = cs.soAlbumPH;
	sobuoiBDTrongThang = cs.sobuoiBDTrongThang;
	followers = cs.followers;
}

string CaSi::getHoten() const {
	return hoten;
}

string CaSi::getMaso() const {
	return maso;
}

Ngay CaSi::getNgSinh() const {
	return ngsinh;
}

int CaSi::getSoAlbumPH() const {
	return soAlbumPH;
}

int CaSi::getSoBuoiBDTrongThang() const {
	return sobuoiBDTrongThang;
}

int CaSi::getFollowers() const {
	return followers;
}

void CaSi::setHoten(string _ht) {
	hoten = _ht;
}

void CaSi::setMaso(string _ms) {
	maso = _ms;
}

void CaSi::setNgSinh(Ngay _ngsinh) {
	ngsinh = _ngsinh;
}

void CaSi::setSoAlbumPH(int _so) {
	soAlbumPH = _so;
}

void CaSi::setSoBuoiBDTrongThang(int _so) {
	sobuoiBDTrongThang = _so;
}

void CaSi::setFollowers(int _followers) {
	followers = _followers;
}

istream& operator>>(istream& in, CaSi& cs) {
	in.ignore();
	cout << "Nhap hoten: ";
	getline(in, cs.hoten);
	cout << "Nhap maso: ";
	in >> cs.maso;
	cout << "Nhap ngsinh";
	in >> cs.ngsinh;
	cout << "Nhap so luong album phat hanh: ";
	in >> cs.soAlbumPH;
	cout << "Nhap so buoi bieu dien trong thang: ";
	in >> cs.sobuoiBDTrongThang;
	cout << "Nhap so luong nguoi theo doi: ";
	in >> cs.followers;

	return in;

}

ostream& operator<<(ostream& os, const CaSi& cs) {
	os << "Ho ten: " << cs.hoten << endl;
	os << "Ma so: " << cs.maso << endl;
	os << "Ngay sinh: " << cs.ngsinh << endl;
	os << "So album phat hanh: " << cs.soAlbumPH << endl;
	os << "So buoi dien trong thang: " << cs.sobuoiBDTrongThang << endl;
	os << "So nguoi theo doi: " << cs.followers << endl;

	return os;

}

class CaSiChuaNoi : public CaSi {
public:
	CaSiChuaNoi();
	CaSiChuaNoi(string, string, Ngay, int, int, int);
	CaSiChuaNoi(const CaSiChuaNoi&);
	long salary();
	friend istream& operator>>(istream& in, CaSiChuaNoi&);
	friend ostream& operator<<(ostream& out, const CaSiChuaNoi&);
};


CaSiChuaNoi::CaSiChuaNoi() :CaSi() {}

CaSiChuaNoi::CaSiChuaNoi(string _hoten, string _ms, Ngay _ngsinh, int _soAlbum, int _soBuoi, int _followers) 
	:CaSi(_hoten, _ms, _ngsinh, _soAlbum, _soBuoi, _followers) {}

CaSiChuaNoi::CaSiChuaNoi(const CaSiChuaNoi& cscn): CaSi(cscn) {}

istream& operator>>(istream& in, CaSiChuaNoi& cscn) {
	CaSi* t = &cscn;
	in >> *t;
	return in;
}

ostream& operator<<(ostream& out, CaSiChuaNoi& cscn) {
	CaSi* t = &cscn;
	out << *t;
	return out;
}


long CaSiChuaNoi::salary() {
	return 3000000 + 250000 * getSoBuoiBDTrongThang();
}

class CaSiDaNoi : public CaSi {
private:
	int soGameShowTG;
public:
	CaSiDaNoi();
	CaSiDaNoi(string, string, Ngay, int, int, int, int);
	CaSiDaNoi(const CaSiDaNoi&);
	long salary();
	int getSoGameShowTG() const;
	void setSoGameShowTG(int);
	friend istream& operator>>(istream& in, CaSiDaNoi&);
	friend ostream& operator<<(ostream& out, CaSiDaNoi&);
};

CaSiDaNoi::CaSiDaNoi() : CaSi(), soGameShowTG(0) {
	
}

CaSiDaNoi::CaSiDaNoi(string _hoten, string _ms, Ngay _ngsinh, int _soAlbum, int _soBuoi, int _followers, int _soGameShow)
	:CaSi(_hoten, _ms, _ngsinh, _soAlbum, _soBuoi, _followers), soGameShowTG(_soGameShow) {
	assert(followers > 1000000);
}

CaSiDaNoi::CaSiDaNoi(const CaSiDaNoi& csdn) : CaSi(csdn) {
	soGameShowTG = csdn.soGameShowTG;
	assert(csdn.followers > 1000000);
}

int CaSiDaNoi::getSoGameShowTG() const {
	return soGameShowTG;
}

void CaSiDaNoi::setSoGameShowTG(int _soGS) {
	soGameShowTG = _soGS;
}

long CaSiDaNoi::salary() {
	return 20000000 + 500000 * getSoBuoiBDTrongThang() * 5000000 * soGameShowTG;
}

istream& operator>>(istream& in, CaSiDaNoi& csdn) {
	CaSi* t = &csdn;
	in >> *t;
	cout << "Nhap so game show da tham gia: ";
	in >> csdn.soGameShowTG;
	return in;
}

ostream& operator<<(ostream& out, CaSiDaNoi& csdn) {
	CaSi* t = &csdn;
	out << *t;
	out << "So game show tham gia: " << csdn.soGameShowTG << endl;
	return out;
}


class FDTEntertainment {
private:
	vector<CaSi*> list;
public:
	FDTEntertainment();
	FDTEntertainment(int);
	FDTEntertainment(const FDTEntertainment&);
	~FDTEntertainment();
	void thongKeCaSi();
	long long tongLuongPhaiTra();
	void caSiSinhGanNgay();
	void nhap();
	void xuat();
	void xoaCaSi(string);
	void generateRandomSingers();
};

FDTEntertainment::FDTEntertainment() {
	list.resize(0);
}

FDTEntertainment::FDTEntertainment(int size) {
	list.resize(size);
}

FDTEntertainment::FDTEntertainment(const FDTEntertainment& other) {
	if (list.size() > other.list.size()) {
		list.resize(other.list.size());
	}
	for (int i = 0; i < list.size(); i++) {
		list[i] = other.list[i];
	}
}

FDTEntertainment::~FDTEntertainment() {
	for (int i = 0; i < list.size(); i++) {
		delete list[i];
	}
}

void FDTEntertainment::nhap() {
	int size;
	cout << "Nhap so luong ca si: ";
	cin >> size;
	int i = 0;
	list.resize(size);
	for (int i = 0; i < size; i++) {
		list[i] = nullptr;
	}

	while (i < size) {
		int opt;
		do {

			cout << "\n========================================\n";
			cout << "||1. Ghi thong tin ca si chua noi||\n";
			cout << "||2. Ghi thong tin ca si da noi  ||\n";
			cout << "========================================\n";
			cout << "Vui long chon: ";
			cin >> opt;
			if (opt != 1 && opt != 2) {
				cout << "Chi duoc nhap 1 hoac 2! Vui long nhap lai!\n";
			}
		} while (opt != 1 && opt != 2);


		CaSi* cs = nullptr;
		if (opt == 1) {
			cs = new CaSiChuaNoi;
		}

		else if (opt == 2) {
			cs = new CaSiDaNoi;
		}
		cin >> *cs;
		list.push_back(cs);
		i++;
	}
}

void FDTEntertainment::xuat() {
	for (int i = 0; i < list.size(); i++) {
		cout << endl;
		cout << *list[i];
		cout << endl;
	}
}

void FDTEntertainment::thongKeCaSi() {
	int numOfInfamousSingers = 0;
	int numOfFamousSingers = 0;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getFollowers() <= 1000000) {
			numOfInfamousSingers++;
		}
		else {
			numOfFamousSingers++;
		}
	}

	cout << "So luong ca si chua noi tieng la: " << numOfInfamousSingers << endl;
	cout << "So luong ca si da noi tieng la: " << numOfFamousSingers << endl;
}

long long FDTEntertainment::tongLuongPhaiTra() {
	int soThangPhaiTra;
	cout << "Nhap so thang: ";
	cin >> soThangPhaiTra;
	long long sum = 0;
	for (int i = 0; i < list.size(); i++) {
		sum += soThangPhaiTra * list[i]->salary();
	}

	return sum;
}

void FDTEntertainment::caSiSinhGanNgay() {

	int ngay, thang, nam;
	cout << "Nhap lan luot ngay thang nam can xet: ";
	cin >> ngay >> thang >> nam;
	Ngay ngayCanXet(ngay, thang, nam);


	long* khoangCachNgay = new long[list.size()] {0};

	int count = 0;
	cout << "\n============== 3 CA SI SINH GAN NGAY ===============\n";
	for(int i = 0; i < list.size(); i++)
	{
		khoangCachNgay[count++] = abs(list[i]->getNgSinh().dayToHours() - ngayCanXet.dayToHours());
	}

	for (int j = 0; j < 3; j++)
	{
		int minIndex = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (khoangCachNgay[i] < khoangCachNgay[minIndex])
				minIndex = i;
		}
		cout << *list[minIndex] << endl;
		khoangCachNgay[minIndex] = INT_MAX;
	}
}

void FDTEntertainment::xoaCaSi(string id) {

	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getMaso() == id) {
			list.erase(list.begin() + i);
			cout << "Da xoa ca si co ID " << id << " ra khoi danh sach!\n";
			return;
		}
	}
}


void FDTEntertainment::generateRandomSingers() {
	int size;
	cout << "Nhap so luong ca si: ";
	cin >> size;
	set<string> existingIDs;
	for (int i = 0; i < size; i++) {
		int randomName = rand() % 10;
		string randomID = generateID(existingIDs);
		int randomDates = rand() % 10;
		int randomAlbums = rand() % 10;
		int randomPerform = rand() % 10;
		int randomFollowers = rand() % 10;

		if (listOfFollowers[randomFollowers] > 1000000) {
			int randomGameShow = rand() % 10;
			CaSi* cs = new CaSiDaNoi(listOfNames[randomName],randomID, listOfDates[randomDates], listOfAlbums[randomAlbums],
				listOfPerformDate[randomPerform], listOfFollowers[randomFollowers], listOfgameShows[randomGameShow]);
			list.push_back(cs);
			continue;
		}
			CaSi* cs = new CaSiChuaNoi(listOfNames[randomName], randomID,
				listOfDates[randomDates], listOfAlbums[randomAlbums], listOfPerformDate[randomPerform],listOfFollowers[randomFollowers]);
		list.push_back(cs);
	}
}

void menu() {

	FDTEntertainment company;
	int option;
	cout << "\n================== CHUONG TRINH QUAN LI CA SI ======================\n";
	do {
		cout << "========================================================================\n";
		cout << "|| Nhap mot trong cac tuy chon sau:                                   ||\n";
		cout << "|| 1: Nhap danh sach ca si                                            ||\n";
		cout << "|| 2: Tao mot danh sach ngau nhien cac ca si                          ||\n";
		cout << "|| 3: Thong ke cac ca si chua noi tieng va da noi tieng               ||\n";
		cout << "|| 4: Xoa mot ca si khoi danh sach                                    ||\n";
		cout << "|| 5: Xuat ra 3 ca si co ngay sinh gan voi ngay dang xet nhat         ||\n";
		cout << "|| 6: Tinh tong tien luong ma cong ty phai tra cho tung ca si         ||\n";
		cout << "|| 7: Xuat danh sach ca si                                            ||\n";
		cout << "|| 0: Thoat chuong trinh                                              ||\n";
		cout << "========================================================================\n";
		cout << "Vui long chon: ";
		cin >> option;

		switch (option) {
		case 1:
		{
			company.nhap();
			cout << "\n Tao danh sach thanh cong! \n";
			company.xuat();
			break;
		}
		case 2:
		{
			cout << "\n============== TAO DANH SACH CA SI NGAU NHIEN ===============\n";
			company.generateRandomSingers();
			cout << "\n Tao danh sach thanh cong! \n";
			company.xuat();
			break;
		}
		case 3: {
			cout << "\n============== THONG KE CA SI ===============\n";
			company.thongKeCaSi();
			break;

		}

		case 4:
		{
			string id;
			cout << "Nhap id muon xoa: ";
			cin >> id;
			company.xoaCaSi(id);
			break;
		}
		case 5:
		{
			company.caSiSinhGanNgay();
			break;
		}
		case 6:
		{
			long long tongLuong = company.tongLuongPhaiTra();
			cout << "Tong luong phai tra cho tung ca si la: " << tongLuong << endl;
			break;
		}

		case 7:
		{
			company.xuat();
			break;
		}
		default:
			cout << "\n================= KET THUC CHUONG TRINH! ===================\n";
		}

	} while (option);
}


int main() {

	menu();
	

	return 0;
}

