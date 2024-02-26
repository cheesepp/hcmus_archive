#include "QLSinhVien.h"
#include <fstream>

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
}
bool QLSinhVien::ReadFile(const char* filename) {
	ifstream fin(filename);
	if (!fin) {
		cout << "Ko mo duoc " << filename;
		return false;
	}
	cout << "Mo thanh cong " << filename << endl;
	fin >> n;
	arrSV = new SinhVien[n];
	for (int i = 0; i < n; ++i) {

	}
}

bool QLSinhVien::WriteFile(const char* filename) {
	ofstream fout(filename);
	if (!fout) {
		cout << "Ko mo duoc " << filename;
		return false;
	}
	cout << "Mo thanh cong " << filename << endl;
	fout << n;
	arrSV = new SinhVien[n];
	for (int i = 0; i < n; ++i) {
		fout << arrSV[i].
	}
}
