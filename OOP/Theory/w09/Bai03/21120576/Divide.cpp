#include "Divide.h"

Divide::Divide() {
	num1 = 0;
	num2 = 0;
}

Divide::~Divide() {}

void Divide::input() {
	cout << "Nhap so chia: ";
	cin >> num1;
	cout << "Nhap so bi chia: ";
	cin >> num2;
}

double Divide::division() {
	if (num2 == 0) {
		throw myException("Khong the chia cho so 0!");
	}
	return num1 * 1.0 / num2;
}