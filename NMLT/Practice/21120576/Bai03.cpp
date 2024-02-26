#include <iostream>
#define PI 3.14
using namespace std;

int main() {

	float r;
	cout << "Nhap ban kinh duong tron: ";
	cin >> r;
	float chuVi = 2 * PI * r;
	cout << "Chu vi hinh tron: " << chuVi << endl;
	float dienTich = PI * r * r;
	cout << "Dien tich hinh tron: " << dienTich << endl;
	return 0;
}