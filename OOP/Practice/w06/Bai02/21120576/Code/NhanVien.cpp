#include "NhanVien.h"

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


NhanVien::NhanVien() {
	maNV = new char[6];
	hoten = new char[20];
	diaChi = new char[50];
	gioiTinh = new char[5];
	ngaySinh.setNgay(0);
	ngaySinh.setThang(0);
	ngaySinh.setNam(0);
}

NhanVien::NhanVien(char* maNV, char* hoten, Ngay ngay, char* diaChi, char* gioiTinh) {
	this->maNV = new char[6];
	this->hoten = new char[20];
	this->diaChi = new char[50];
	this->gioiTinh = new char[5];
	strcpy(this->maNV, maNV);

	strcpy(this->hoten, hoten);

	this->ngaySinh = ngay;

	strcpy(this->diaChi, diaChi);
	strcpy(this->gioiTinh, gioiTinh);
}

NhanVien::NhanVien(const NhanVien& NhanVien) {
	maNV = new char[6];
	hoten = new char[20];
	diaChi = new char[50];
	gioiTinh = new char[5];
	strcpy(this->maNV,NhanVien.maNV);

	strcpy(this->hoten, NhanVien.hoten);

	this->ngaySinh = NhanVien.ngaySinh;

	strcpy(this->diaChi,NhanVien.diaChi);
	strcpy(this->gioiTinh, NhanVien.gioiTinh);

}

char* NhanVien::getMaNV() const {
	return maNV;
}

void NhanVien::setMaNV(char* _maNV) {
	strcpy(maNV, _maNV);
}

char* NhanVien::getHoten() const {
	return hoten;
}

void NhanVien::setHoten(char* hoten) {
	strcpy(this->hoten, hoten);
}

char* NhanVien::getDiaChi() const {
	return diaChi;
}

void NhanVien::setDiaChi(char* diaChi) {
	strcpy(this->diaChi, diaChi);
}

char* NhanVien::getGioiTinh() const {
	return gioiTinh;
}

void NhanVien::setGioiTinh(char* gioiTinh) {
	strcpy(this->gioiTinh, gioiTinh);
}

Ngay NhanVien::getNgaySinh() const {
	return ngaySinh;
}

void NhanVien::setNgaySinh(const Ngay& ngay) {
	this->ngaySinh = ngay;
}

void NhanVien::input() {
	maNV = new char[6];
	hoten = new char[20];
	diaChi = new char[50];
	gioiTinh = new char[5];

	cout << "Nhap ID: ";
	cin.ignore();
	do {
		cin.getline(maNV, 6);
		if (strlen(maNV) < 5) {
			cout << "Ma nhan vien phai gom 5 ki tu! Vui long nhap lai!\n";
		}

	} while (strlen(maNV) < 5);

	cout << "Nhap ho ten: ";
	cin.getline(hoten, 19);

	cout << "Nhap dia chi: ";
	cin.getline(diaChi, 49);

	cout << "Nhap gioi tinh (ghi thuong): ";
	cin.getline(gioiTinh, 4);

	cout << "Nhap ngay thang nam sinh: ";
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	int tuoiHienTai = now->tm_year + 1900 - ngaySinh.getNam();
	/*do {

		cin >> ngaySinh;
		if (strcmp(gioiTinh, "nam") && (tuoiHienTai < 18 || tuoiHienTai > 60)) {
			cout << "So tuoi cua nhan vien nam phai trong 18 den 60! Vui long nhap lai!\n";
		}
		
		if (strcmp(gioiTinh, "nu") && (tuoiHienTai < 18 || tuoiHienTai > 55)) {
			cout << "So tuoi cua nhan vien nu phai trong 18 den 55! Vui long nhap lai!\n";
		}
	} while ((strcmp(gioiTinh, "nam") && (tuoiHienTai < 18 || tuoiHienTai > 60))
		&& (strcmp(gioiTinh, "nu") && (tuoiHienTai < 18 || tuoiHienTai > 55)));*/
	cin >> ngaySinh;
}

void NhanVien::print() {
	cout << "ID: " << maNV << endl;
	cout << "Ho ten: " << hoten << endl;
	cout << "Gioi tinh: " << gioiTinh << endl;
	cout << "Dia chi: " << diaChi << endl;
	cout << "Ngay sinh: " << ngaySinh << endl;
}

NhanVien& NhanVien::operator=(const NhanVien& NhanVien) {

	strcpy(this->maNV, NhanVien.maNV);
	strcpy(this->hoten, NhanVien.hoten);
	strcpy(this->diaChi, NhanVien.diaChi);
	this->ngaySinh = NhanVien.ngaySinh;

	return *this;
}

ofstream& operator<<(ofstream& fout, NhanVien nv) {

	nv.writeFile(fout);

	return fout;
}


ofstream& NhanVien::writeFile(ofstream& fout) {

	fout << maNV << endl;
	fout << hoten << endl;
	fout << diaChi << endl;
	fout << gioiTinh << endl;
	fout << ngaySinh.getNgay() << "/" << ngaySinh.getThang() << "/" << ngaySinh.getNam() << endl;

	return fout;
}

NhanVien::~NhanVien() {
	delete[] maNV;
	delete[] hoten;
	delete[] diaChi;
	delete[] gioiTinh;
}