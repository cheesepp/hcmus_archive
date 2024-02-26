// Bai8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, x;
    cout << "Nhap so nguyen duong n va x: ";
    cin >> n >> x;
    int ketQua = pow(x * x + 1, n);
    cout << "Ket qua cuoi cung: " << fixed << ketQua;

    return 0;
}
