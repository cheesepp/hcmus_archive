// Bai9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	/*float soTienGui;
	float laiSuat;
	int soThangGui;
	cout << "Nhap so tien gui: ";
	cin >> soTienGui;
	cout << "Nhap so thang gui: ";
	cin >> soThangGui;
	cout << "Nhap lai suat (don vi %): ";
	cin >> laiSuat;
	
	laiSuat = laiSuat * 1.0f / 100;

	float soTienLai = soTienGui * pow((1 + laiSuat), soThangGui) - soTienGui;
	cout << "So tien lai: " << soTienLai;*/

	int* a = new int;
	*a = 2;
	int* b =  a;
	*a = 5;
	cout << *b;

	return 0;

}
