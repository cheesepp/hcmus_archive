#include "CongTy.h"

CongTy::CongTy() {
	list = nullptr;
}

CongTy::CongTy(const CongTy& cty) {

	sz = cty.sz;
	capacity = cty.capacity;

	list = new NhanVien * [capacity];

	for (int i = 0; i < capacity; i++) {
		list[i] = nullptr;
	}

	for (int i = 0; i < sz; i++) {

		list[i] = cty.list[i];
	}
}

CongTy& CongTy::operator=(const CongTy& cty) {

	sz = cty.sz;
	capacity = cty.capacity;

	list = new NhanVien * [capacity];

	for (int i = 0; i < capacity; i++) {
		list[i] = nullptr;
	}

	for (int i = 0; i < sz; i++) {

		list[i] = cty.list[i];
	}
	

	return *this;
}

void CongTy::input() {
	
	cout << "Nhap so luong nhan vien: ";
	cin >> sz;

	list = new NhanVien * [sz];
	for (int i = 0; i < sz; i++) {
		list[i] = nullptr;
	}

	for (int i = 0; i < sz; i++) {
		cout << "\n================== NHAP NHAN VIEN ===================\n";
		int opt;

		do {

			cout << "\n===============================\n";
			cout << "||1. Them Nhan vien cong nhat||\n";
			cout << "||2. Them Nhan vien san xuat ||\n";
			cout << "===============================\n";
			cout << "Vui long chon: ";
			cin >> opt;
			if (opt != 1 && opt != 2) {
				cout << "Chi chon 1 trong 2! Vui long chon lai!\n";
			}
		} while (opt != 1 && opt != 2);

		if (opt == 1) {
			list[i] = new NVCongNhat();
			list[i]->input();
		}
		else {
			list[i] = new NVSanXuat();
			list[i]->input();
		}
	}
}

void CongTy::print() const {
	
	for (int i = 0; i < sz; i++) {
		cout << "------------- Nhan vien " << i + 1 << " ----------------- \n";
		list[i]->print();
	}
}

long CongTy::sumSalary() {
	long sum = 0;
	for (int i = 0; i < sz; i++) {
		sum += list[i]->salary();
	}

	return sum;
}

void CongTy::maxSalary() {

	long max = list[0]->salary();
	int empIndex = 0;
	for (int i = 1; i < sz; i++) {
		if (max < list[i]->salary()) {
			max = list[i]->salary();
			empIndex = i;
		}
	}

	cout << "\nNhan vien co luong cao nhat la: " << endl;
	list[empIndex]->print();
}

float CongTy::avgSalary() {

	return sumSalary() * 1.0f / sz;
}

void CongTy::findEmpById(char* id) {

	for (int i = 0; i < sz; i++) {
		if (strcmp(list[i]->getMaNV(), id) == 0) {
			list[i]->print();
		}
	}
}

void CongTy::findEmpByName(char* name) {

	for (int i = 0; i < sz; i++) {
		if (strcmp(list[i]->getHoten(), name) == 0) {
			list[i]->print();
		}
	}
}

void CongTy::findEmpBornMonth5() {

	for (int i = 1; i < sz; i++) {
		if (list[i]->getNgaySinh().getThang() == 5) {
			list[i]->print();
		}
	}
}

void CongTy::addEmployee() {
	

	cout << "\n================== THEM NHAN VIEN ===================\n";
	int opt;

	do {

		cout << "\n=============================\n";
		cout << "||1. Them Nhan vien cong nhat||\n";
		cout << "||2. Them Nhan vien san xuat ||\n";
		cout << "============================== \n";
		cout << "Vui long chon: ";
		cin >> opt;
		if (opt != 1 && opt != 2) {
			cout << "Chi chon 1 trong 2! Vui long chon lai!\n";
		}
	} while (opt != 1 && opt != 2);
	NhanVien* c;
	if (opt == 1) {
		c = new NVCongNhat();
		c->input();
	}
	else {
		c = new NVSanXuat();
		c->input();
	}


	if (sz + 1 >= capacity) {
		NhanVien** temp = new NhanVien*[sz + 1];
		for (int i = 0; i < capacity * 2; i++) {
			temp[i] = nullptr;
		}
		capacity *= 2;

		for (int i = 0; i < sz; i++) {
			temp[i] = list[i];
		}

		temp[sz] = c;
		delete[]list;
		list = temp;
		sz++;
		return;
	}

	list[sz] = c;
	sz++;

	writeListEmp("ds_NhanVien.dat");

}

void CongTy::deleteEmployee() {

	char* id = new char[7];
	cout << "Nhap id nhan vien can xoa: \n";
	cin.ignore();
	cin.getline(id, 6);
	int deletePos = -1;
	for (int i = 0; i < sz; i++) {
		if (strcmp(id, list[i]->getMaNV()) == 0) {
			deletePos = i;
			break;
		}
	}

	NhanVien** temp = new NhanVien * [sz - 1];

	for (int i = 0; i < sz - 1; i++) {
		temp[i] = nullptr;
	}

	for (int i = 0; i < deletePos; i++) {
		temp[i] = list[i];
	}

	for (int i = deletePos + 1; i < sz; i++) {
		temp[i] = list[i];
	}

	delete[] list;
	list = temp;
	sz--;
	delete id;


	writeListEmp("ds_NhanVien.dat");

}

void CongTy::writeListEmp(string filename) {
	
	ofstream fout(filename, ios::trunc);
	if (!fout) {
		cout << "Khong the mo file!";
		exit(1);
	}
	cout << "Mo file thanh cong!\n";
	fout << sz << endl;
	for (int i = 0; i < sz; i++) {
		list[i]->writeFile(fout);
	}
}

void CongTy::readListEmp(string filename) {
	
	ifstream fin(filename);
	if (!fin) {
		cout << "Khong the mo file!";
		exit(1);
	}
	cout << "Mo file thanh cong!\n";
	char buffer[10] = "";

	fin.getline(buffer, 10, '\n');
	sz = atoi(buffer);

	list = new NhanVien * [sz];

	for (int i = 0; i < sz; i++) {
		list[i] = nullptr;
	}

	for (int i = 0; i < sz; i++) {
		char* maNV = new char[6];
		char* hoten = new char[20];
		char* diaChi = new char[50];
		char* gioiTinh = new char[5];
		
		fin.getline(maNV, 6, '\n');
		fin.getline(hoten, 20, '\n');
		fin.getline(diaChi, 50, '\n');
		fin.getline(gioiTinh, 5, '\n');
	
		Ngay ngaySinh;

		char buffngs[30];
		fin.getline(buffngs, 29, '\n');
		stringstream s(buffngs);
		
		char buffer[10] = "";
		s.getline(buffer, 10, '/');
		int ngay = atoi(buffer);
		s.getline(buffer, 10, '/');
		int thang = atoi(buffer);
		s.getline(buffer, 10, '\n');
		int nam = atoi(buffer);

		ngaySinh.setNgay(ngay);
		ngaySinh.setThang(thang);
		ngaySinh.setNam(nam);


		int so;
		char So[10] = "";
		fin.getline(So, 9, '\n');
		so = atoi(So);
		if (so >= 22) {
			list[i] = new NVCongNhat(maNV, hoten, ngaySinh, diaChi, gioiTinh, so);
		}
		else {
			list[i] = new NVSanXuat(maNV, hoten, ngaySinh, diaChi, gioiTinh, so);
		}
	}
}



void CongTy::empWhoseSalaryLessThanAvg(string filename) {

	ofstream fout(filename, ios::trunc);
	if (!fout) {
		cout << "Khong the mo file!";
		exit(1);
	}
	cout << "Mo file thanh cong!\n";
	
	float avg = sumSalary() * 1.0f / sz; 
	fout << "Muc luong trung binh cua nhan vien cong ty la: " << fixed << setprecision(2) << avg << endl;
	fout << "Nhung nhan vien co muc luong thap hon luong trung binh: " << endl;
	for (int i = 0; i < sz; i++) {
		if (list[i]->salary() < avg) {
			list[i]->writeFile(fout);
		}
	}
}

CongTy::~CongTy() {
	delete[] list;
}