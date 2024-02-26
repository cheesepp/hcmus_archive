// Bai7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;
int main()
{
    float dtHinhTron;
    cout << "Nhap dien tich hinh tron: ";
    cin >> dtHinhTron;
    float banKinh = sqrt(dtHinhTron*1.0f / PI);
    cout << "Ban kinh hinh tron: " << banKinh;

    return 0;
}
