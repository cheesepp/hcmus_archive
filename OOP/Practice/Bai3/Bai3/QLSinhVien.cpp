#define _CRT_SECURE_NO_WARNINGS
#include "QLSinhVien.h"
#include <fstream>
#include <string>

/*Ho ten
Ma so
Ngay sinh
DiemBaiTap DiemGiuaKy DiemCuoiKy*/
QLSinhVien::QLSinhVien()
{
	arrSV = NULL;
	n = 0;
	
}


QLSinhVien::~QLSinhVien()
{
	delete[] arrSV;
	n = 0;
	cout << "ngu";
}
bool QLSinhVien::ReadFile(const char* filename) {
	ifstream fin(filename);
	if (!fin) {
		cout << "Ko mo duoc " << filename;
		return false;
	}
	cout << "Mo thanh cong " << filename;
	fin >> n;
	arrSV = new SinhVien[n];
	for (int i = 0; i < n; ++i) {
		fin.ignore();

		char hoTen[30];
		fin.getline(hoTen, 29, '\n');
		arrSV[i].setHoTen(hoTen);

		char maSo[20];
		fin.getline(maSo, 20,'\n');
		arrSV[i].setMa(maSo);
		NgaySinh ngSinh;

		char buffer[30];
		fin.getline(buffer,29, '\n'); //Doc ngay thang nam sinh

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
		/*SinhVien temp(hoTen, maSo, ngSinh, marks);*/

	}
	cout << endl << "Doc file thanh cong!!";
	return true;
}
bool QLSinhVien::WriteFile(const char* filename) {
	ofstream fout(filename);
	if (!fout) {
		fout << "Ko mo duoc file" << filename;
		return false;
	}
	cout << endl << "Da mo " << filename;
	for (int i = 0; i < n; ++i) {
		fout << "Ho ten: " << arrSV[i].getHoTen() << "||Ma so: " << arrSV[i].getMa() << "||Ngay sinh : ";
		fout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam;
		float DiemTB = arrSV[i].getMarks()[0] * 0.25 + arrSV[i].getMarks()[1] * 0.25 + arrSV[i].getMarks()[2] * 0.5;
		fout << "||Diem trung binh: " << DiemTB << endl;
	}
	return true;
}

bool QLSinhVien::SVNhoHonDTBLop(string filename) {
	ofstream fout(filename);
	if (!fout) {		
		fout << "Ko mo duoc file" << filename;
		return false;
	}
	cout << endl << "Da mo " << filename;
	float avgMark = 0;
	for (int i = 0; i < n; i++) {
		float stdAvg = arrSV[i].getMarks()[0] * 0.25
			+ arrSV[i].getMarks()[1] * 0.25
			+ arrSV[i].getMarks()[2] * 0.5;
		avgMark += stdAvg;
	}
	
	avgMark = avgMark * 1.0 / n;
	cout << avgMark << endl;
	for (int i = 0; i < n; i++) {
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
	return true;
}

bool QLSinhVien::ThemSV(string filename, SinhVien sv) {
	SinhVien* newArr = new SinhVien[n + 1];
	for (int i = 0; i < n; i++) {
		/*newArr[i].setHoTen(arrSV[i].getHoTen());
		newArr[i].setMa(arrSV[i].getMa());
		newArr[i].setNgaySinh(arrSV[i].getNgaySinh());
		newArr[i].setMark0(arrSV[i].getMarks()[0]);
		newArr[i].setMark1(arrSV[i].getMarks()[1]);
		newArr[i].setMark2(arrSV[i].getMarks()[2]);*/
		newArr[i] = arrSV[i];
	}
	/*newArr[n].setHoTen(sv.getHoTen());
	newArr[n].setMa(sv.getMa());
	newArr[n].setNgaySinh(sv.getNgaySinh());
	newArr[n].setMark0(sv.getMarks()[0]);
	newArr[n].setMark1(sv.getMarks()[1]);
	newArr[n].setMark2(sv.getMarks()[2]);*/
	newArr[n] = sv;
	delete[] arrSV;
	arrSV = new SinhVien[n + 1];
	
	n++;
	for (int i = 0; i < n; i++)
	{
		arrSV[i] = newArr[i];
	}
	ofstream fout(filename, std::ios_base::app);
	if (!fout) {
		fout << "Ko mo duoc file" << filename;
		return false;
	}
	cout << endl << "Da mo " << filename;
	fout << "Ho ten: " << sv.getHoTen() << "||Ma so: " << sv.getMa() << "||Ngay sinh : ";
	fout << sv.getNgaySinh().Ngay << "/" << sv.getNgaySinh().Thang << "/" << sv.getNgaySinh().Nam;
	float DiemTB = sv.getMarks()[0] * 0.25 + sv.getMarks()[1] * 0.25 + sv.getMarks()[2] * 0.5;
	fout << "||Diem trung binh: " << DiemTB << endl;
	return true;
}


void QLSinhVien::XuatDSSV() {
	for (int i = 0; i < n; i++) {
		cout << "Ho ten: " << arrSV[i].getHoTen() << "||Ma so: " << arrSV[i].getMa() << "||Ngay sinh : ";
		cout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam;
		float DiemTB = arrSV[i].getMarks()[0] * 0.25 + arrSV[i].getMarks()[1] * 0.25 + arrSV[i].getMarks()[2] * 0.5;
		cout << "||Diem trung binh: " << DiemTB;
		cout << "||Xep loai: " << arrSV[i].xeploai() << endl;
	}
}

void QLSinhVien::SVCungNgaySinh() {
	time_t now = time(0);

	char* dt = ctime(&now);

	std::tm* ptm = std::localtime(&now);
	for (int i = 0; i < n; i++) {
		if (arrSV[i].getNgaySinh().Ngay == ptm->tm_mday && arrSV[i].getNgaySinh().Thang == (ptm->tm_mon + 1)) {
			cout << "Ho ten: " << arrSV[i].getHoTen() << "||Ma so: " << arrSV[i].getMa() << "||Ngay sinh : ";
			cout << arrSV[i].getNgaySinh().Ngay << "/" << arrSV[i].getNgaySinh().Thang << "/" << arrSV[i].getNgaySinh().Nam;
			float DiemTB = arrSV[i].getMarks()[0] * 0.25 + arrSV[i].getMarks()[1] * 0.25 + arrSV[i].getMarks()[2] * 0.5;
			cout << "||Diem trung binh: " << DiemTB;
			cout << "||Xep loai: " << arrSV[i].xeploai() << endl;
		}
	}
}

