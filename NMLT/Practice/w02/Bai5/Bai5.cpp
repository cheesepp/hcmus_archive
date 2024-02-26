// Bai5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define PI 3.14
using namespace std;
int main()
{
    // a) Dien tich be mat va the tich khoi hop
    int chieuCao, chieuSau, chieuRong;
    cout << "Nhap lan luot chieu cao, chieu sau va chieu rong: "; 
    cin >> chieuCao >> chieuSau >> chieuRong;
    int SKhoiHop = 2 * chieuCao * chieuRong + 2 * chieuRong * chieuSau + 2 * chieuCao * chieuSau;
    cout << "Dien tich be mat khoi hop: " << SKhoiHop << endl;
    int VKhoiHop = chieuCao * chieuRong * chieuSau;
    cout << "The tich khoi hop: " << VKhoiHop << endl;

    // b) Dien tich be mat va the tich khoi lap phuong
    int canh;
    cout << "Nhap canh khoi lap phuong: ";
    cin >> canh;
    int SLapPhuong = 4 * canh * canh;
    cout << "Dien tich be mat khoi lap phuong: " << SLapPhuong << endl;
    int VLapPhuong = canh * canh * canh;
    cout << "The tich khoi lap phuong: " << VLapPhuong << endl;

    // c) Dien tich be mat va the tich khoi tru tron
    float banKinh, cCao;
    cout << "Nhap lan luot ban kinh va chieu cao cua khoi tru tron: ";
    cin >> banKinh >> cCao;
    float Sxq = 2 * PI * banKinh * cCao;
    cout << "Dien tich be mat khoi tru tron: " << Sxq << endl;
    float VTru = PI * banKinh * banKinh * cCao;
    cout << "The tich khoi tru tron: " << VTru;

    return 0;
}

