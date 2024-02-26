// Bai6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;
int main()
{
    float canhTamGiac, banKinh;
    cout << "Nhap lan luot chieu dai canh tam giac deu va ban kinh: ";
    cin >> canhTamGiac >> banKinh;

    float dtHTron = PI * banKinh * banKinh;
    float part = dtHTron / 6;
    float dtTGD = (sqrt(3) / 4) * canhTamGiac * canhTamGiac;
    float dienTich = dtTGD * 3 + dtHTron - dtHTron * 1.0f / 2;
    cout << "Dien tich cua hinh la: " << dienTich;

    return 0;
}