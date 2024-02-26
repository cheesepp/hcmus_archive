#define _CRT_SECURE_NO_WARNINGS
#include "QLSinhVien.h"
#include <fstream>
#include <string>


// Constructor QLSinhVien
QLSinhVien::QLSinhVien()
{
	arrSV = NULL;
	n = 0;

}

// Destructor QLSinhVien
QLSinhVien::~QLSinhVien()
{
	delete[] arrSV;
	n = 0;
}

// Ham doc file danh sach sinh vien
bool QLSinhVien::ReadFile(const char* filename) {
	ifstream fin(filename); // mo file
	if (!fin) {
		cout << "Ko mo duoc " << filename;
		return false;
	}
	cout << "Mo thanh cong " << filename;
	fin >> n;
	arrSV = new SinhVien[n]; // cap phat so luong phan tu cho mang sinh vien
	for (int i = 0; i < n; ++i) {
		fin.ignore();

		char hoTen[30];
		fin.getline(hoTen, 29, '\n');
		arrSV[i].setHoTen(hoTen);

		char maSo[20];
		fin.getline(maSo, 20, '\n');
		arrSV[i].setMa(maSo);
		NgaySinh ngSinh;

		char buffer[30];
		fin.getline(buffer, 29, '\n'); //Doc ngay thang nam sinh

		char* ngay = strtok(buffer, "/"); //Tach ngay
		ngSinh.Ngay = atoi(ngay);

		char* thang = strtok(NULL, "/"); //Tach thang
		ngSinh.Thang = atoi(thang);

		char* nam = strtok(NULL, " "); //Tach nam
		ngSinh.Nam = atoi(nam);
		arrSV[i].setNgaySinh(ngSinh);

		float marks[3];
		for (int i = 0; i < 3; ++i) {
			fin >> marks[i];
		}
		arrSV[i].setMark0(marks[0]);
		arrSV[i].setMark1(marks[1]);
		arrSV[i].setMark2(marks[2]);

	}
	cout << endl << "Doc file thanh cong!!";
	fin.close();
	return true;
}

// Ham ghi file danh sach sinh vien
bool QLSinhVien::WriteFile(const char* filename) {
	ofstream fout(filename); // mo file
	if (!fout) {
		fout << "Ko mo duoc file" << filename;
		return false;
	}
	cout << endl << "Da mo " << filename;
	for (int i = 0; i < n; ++i) { // ghi danh sach sinh vien vao file
		fout << "Ho ten: " << arrSV[i].getHoTen() << "||Ma so: " << arrSV[i].getMa() << "||Ngay sinh : ";
		fout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam;
		float DiemTB = arrSV[i].getMarks()[0] * 0.25 + arrSV[i].getMarks()[1] * 0.25 + arrSV[i].getMarks()[2] * 0.5;
		fout << "||Diem trung binh: " << DiemTB << endl;
	}
	fout.close();
	return true;
}

// Ham tim cac sinh vien co diem trung binh be hon diem trung binh lop
bool QLSinhVien::SVNhoHonDTBLop(const char* filename) {
	ofstream fout(filename);
	if (!fout) {
		fout << "Ko mo duoc file" << filename;
		return false;
	}
	cout << endl << "Da mo " << filename;
	float avgMark = 0;
	for (int i = 0; i < n; i++) { // Ham tinh diem trung binh cua tinh sinh vien
		float stdAvg = arrSV[i].getMarks()[0] * 0.25
			+ arrSV[i].getMarks()[1] * 0.25
			+ arrSV[i].getMarks()[2] * 0.5;
		avgMark += stdAvg;
	}

	avgMark = avgMark * 1.0 / n; // diem trung binh cua lop
	cout << "\nDiem trung binh cua lop: " << avgMark << endl;
	for (int i = 0; i < n; i++) { // ghi danh sach sinh vien diem be hon diem trung binh vao file
		float stdAvg = arrSV[i].getMarks()[0] * 0.25
			+ arrSV[i].getMarks()[1] * 0.25
			+ arrSV[i].getMarks()[2] * 0.5;
		if (stdAvg < avgMark) {
			fout << "Ho ten: " << arrSV[i].getHoTen() << "||Ma so: " << arrSV[i].getMa() << "||Ngay sinh : ";
			fout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam;
			float DiemTB = arrSV[i].getMarks()[0] * 0.25 + arrSV[i].getMarks()[1] * 0.25 + arrSV[i].getMarks()[2] * 0.5;
			fout << "||Diem trung binh: " << DiemTB << endl;
		}
	}
	fout.close();
	return true;
}

// Ham them sinh vien
bool QLSinhVien::ThemSV(const char* filename, SinhVien sv) {

	SinhVien* newArr = new SinhVien[n + 1]; // Cap phat mang tam
	for (int i = 0; i < n; i++) { // Gan cac gia tri tu mang cu sang mang tam

		newArr[i] = arrSV[i];
	}
	newArr[n] = sv; // them sinh vien moi vao mang tam
	arrSV = new SinhVien[n + 1]; // cap phat mang moi cho mang sinh vien

	n++;
	for (int i = 0; i < n; i++) // gan lai cac gia tri cua mang tam vao mang sinh vien
	{
		arrSV[i] = newArr[i];
	}
	ofstream fout(filename, std::ios_base::trunc); // ghi mang moi vao file
	if (!fout) {
		fout << "Ko mo duoc file" << filename;
		return false;
	}
	cout << endl << "Da mo " << filename;
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << arrSV[i].getHoTen() << endl;
		fout << arrSV[i].getMa() << endl;
		fout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam << endl;
		fout << arrSV[i].getMarks()[0] << " " << arrSV[i].getMarks()[1] << " " << arrSV[i].getMarks()[2] << endl;
	}
	fout.close();
	return true;
}

// Ham xuat danh sach sinh vien
void QLSinhVien::XuatDSSV() {
	for (int i = 0; i < n; i++) {
		cout << "Ho ten: " << arrSV[i].getHoTen() << "||Ma so: " << arrSV[i].getMa() << "||Ngay sinh : ";
		cout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam;
		float DiemTB = arrSV[i].getMarks()[0] * 0.25 + arrSV[i].getMarks()[1] * 0.25 + arrSV[i].getMarks()[2] * 0.5;
		cout << "||Diem trung binh: " << DiemTB;
		cout << "||Xep loai: " << arrSV[i].xeploai() << endl;
	}
}

// Tim sinh vien cung ngay sinh voi ngay hien tai
void QLSinhVien::SVCungNgaySinh() {
	time_t now = time(0); // lay thoi diem hien tai

	char* dt = ctime(&now); // lay ngay thang nam cua diem hien tai

	std::tm* ptm = std::localtime(&now); // lay ngay thang nam cua diem hien tai

	for (int i = 0; i < n; i++) { // tim cac sinh vien co cung ngay sinh voi ngay hien tai
		if (arrSV[i].getNgaySinh().Ngay == ptm->tm_mday && arrSV[i].getNgaySinh().Thang == (ptm->tm_mon + 1)) {
			cout << "Ho ten: " << arrSV[i].getHoTen() << "||Ma so: " << arrSV[i].getMa() << "||Ngay sinh : ";
			cout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam;
			float DiemTB = arrSV[i].getMarks()[0] * 0.25 + arrSV[i].getMarks()[1] * 0.25 + arrSV[i].getMarks()[2] * 0.5;
			cout << "||Diem trung binh: " << DiemTB;
			cout << "||Xep loai: " << arrSV[i].xeploai() << endl;
		}
	}
}

