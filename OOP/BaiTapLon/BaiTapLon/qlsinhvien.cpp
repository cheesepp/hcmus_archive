#include "qlsinhvien.h"

// Constructor
QLSinhVien::QLSinhVien(int n) { 
	size = n;
	sv = new SinhVien[size];
}

QLSinhVien::~QLSinhVien() {
	delete[] sv;
}

SinhVien& QLSinhVien::operator[](int index) {
	if (index < 0 || index >= size) {
		cout << "Error!";
	}
	return sv[index];
}

int QLSinhVien::getSize() {
	return this->size;
}

// Ham nhap danh sach sinh vien
void QLSinhVien::nhap_DSSV() {
	for (int i = 0; i < size; i++) {
		cout << "Student " << i + 1 << ": \n";
		cin >> sv[i];
		cout << endl;
	}
}

// Ham xuat danh sach sinh vien
void QLSinhVien::xuat_DSSV() {
	cout << "Number of students: " << size << endl; // xuat so luong sinh vien
	for (int i = 0; i < size; i++) { // 
		cout << sv[i] << endl; // xuat thong tin tung sinh vien

	}
}

// Ham ghi danh sach sinh vien len file
void QLSinhVien::ghi_DSSV(char* filename) { 
	FILE* f = freopen(filename, "wt", stdout);
	xuat_DSSV();
	fclose(f);
}

// Ham doc danh sach sinh vien tu file
void QLSinhVien::doc_DSSV(char* filename) { 
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Error!" << endl;
		return;
	}
	char buffer[100] = "";

	fin.getline(buffer, 100, '\n');
	int n = 0;
	n = atoi(buffer);
	size = n;
	sv = new SinhVien[size];

	Date NgaySinh;
	int Marks[3] = { 0, 0, 0 };

	for (int i = 0; i < size; i++) {

		char* name = new char[30];
		char* ID = new char[10];

		fin.getline(buffer, 100);
		stringstream ss(buffer);


		ss.getline(name, 100, ' '); //doc ten sv
		ss.getline(ID, 100, ' '); //doc ID sv

		ss.getline(buffer, 3, '/'); //doc ngay sinh
		int day = atoi(buffer);
		NgaySinh.setDay(day);

		ss.getline(buffer, 3, '/'); //doc thang sinh
		int month = atoi(buffer);
		NgaySinh.setMonth(month);

		ss.getline(buffer, 5, ' '); //doc nam sinh
		int year = atoi(buffer);
		NgaySinh.setYear(year);

		ss.getline(buffer, 3, ' '); //doc diem bai tap
		Marks[0] = atoi(buffer);

		ss.getline(buffer, 3, ' '); //doc diem giua ky
		Marks[1] = atoi(buffer);

		ss.getline(buffer, 3, ' '); // doc diem cuoi ky
		Marks[2] = atoi(buffer);

		SinhVien sinhvien(name, ID, NgaySinh, Marks[0], Marks[1], Marks[2]);
		sv[i] = sinhvien;
	}
	fin.close();
}

// Lay diem trung binh cua lop
double QLSinhVien::getCAvg() { 
	double cAvg = 0;
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += sv[i].getAvg();
	}
	cAvg = sum / size;

	return cAvg;
}

// Ghi DSSV có diem trung binh thap dtb cua lop
void QLSinhVien::ghi_underAvgList(char* filename) { 

	FILE* f = freopen(filename, "wt", stdout);
	cout << "Class Average Marks: " << getCAvg() << endl;
	for (int i = 0; i < size; i++) {
		// Kiem tra co thap hon diem trung binh cua lop khong
		if (sv[i].getAvg() < getCAvg()) { 
			cout << sv[i] << " " << "(Average: " << sv[i].getAvg() << ")" << endl;
		}
	}

	fclose(f);

}

// Ham ghi DSSV co xep hang
void QLSinhVien::ghi_RankList(char* filename) {

	FILE* f = freopen(filename, "wt", stdout);
	for (int i = 0; i < size; i++) {
		cout << sv[i] << " " << "TB: " << sv[i].getAvg() << " Xep Loai: ";
		sv[i].rankSV();
		cout << endl;
	}

	fclose(f);

}

Date QLSinhVien::getCurDay() {
	Date curDate;
	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	int year = (now->tm_year + 1900);
	int month = (now->tm_mon + 1);
	int day = now->tm_mday;
	//cout << d << "/" << m << "/" << y;
	curDate.setDay(day);
	curDate.setMonth(month);
	curDate.setYear(year);
	return curDate;
}

void QLSinhVien::ghi_CurBirthdayList(char* filename) {
	FILE* f = freopen(filename, "wt", stdout);
	cout << "Current day: " << getCurDay() << endl;
	for (int i = 0; i < size; i++) {
		
		if (sv[i].getNgaySinh().getDay() == getCurDay().getDay() &&
			sv[i].getNgaySinh().getMonth() == getCurDay().getMonth()) {
			cout << sv[i] << endl;
		}
	}

	fclose(f);
}

void QLSinhVien::addSV(SinhVien svAdd) {
	SinhVien* newArr = new SinhVien[size + 1]; 
	for (int i = 0; i < size; i++) { 
		newArr[i] = sv[i];
	}
	newArr[size] = svAdd; 
	sv = new SinhVien[size + 1]; 

	size++;
	for (int i = 0; i < size; i++) 
	{
		sv[i] = newArr[i];
	}

}

