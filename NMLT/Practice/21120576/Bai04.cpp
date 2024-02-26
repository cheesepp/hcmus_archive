#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	float chuVi;
	cout << "Nhap chu vi hinh chu nhat: ";
	cin >> chuVi;
	float chieuRong = chuVi / 5;
	float dienTich = chieuRong * 1.5 * chieuRong;
	cout << "Dien tich hinh chu nhat: " << dienTich;

	return 0;
}