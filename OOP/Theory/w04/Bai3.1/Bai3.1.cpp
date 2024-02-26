// Bai3.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
class NhanVat {
private:
    string ten;
public:
    void Nhap();
    void Xuat();
    string getterTen();
    bool operator> (NhanVat&);
    int sizeTen();
};

void NhanVat::Nhap() {
    getline(cin, ten);
}

void NhanVat::Xuat() {
    cout << ten;
}

string NhanVat::getterTen() {
    return ten;
}


int NhanVat::sizeTen() {
    int size = 0;
    for (int i = ten.length() - 1; i >= 0; i--) {
            size++;
        if (ten[i] == ' ') {
            return size;
        }
    }
    return size;
}

bool NhanVat::operator>(NhanVat& b) {
    if (this->sizeTen() > b.sizeTen())
        return true;
    return false;
}

class MangNhanVat {
private:
    vector<NhanVat> list;
public:
    void Nhap();
    NhanVat timMax();
};

void MangNhanVat::Nhap() {

    while (!cin.eof()) {
        NhanVat temp;
        temp.Nhap();
        list.push_back(temp);
   }
}

NhanVat MangNhanVat::timMax() {
    NhanVat max = list[0];
    for (int i = 0; i < list.size(); i++) {
        if (list[i] > max) max = list[i];
    }
    return max;
}


int main()
{
    freopen("INPUT.TXT", "rt", stdin);
    MangNhanVat a;
    a.Nhap();
    NhanVat max = a.timMax();
    freopen("OUTPUT.TXT", "wt", stdout);
    max.Xuat();
    cout << " " << max.sizeTen();

}