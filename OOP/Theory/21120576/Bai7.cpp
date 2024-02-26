#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
class ToaDo {
private:
    float x;
    float y;
public:
    void Nhap();
    void Xuat();
    float getterX();
    float getterY();
    void setterX(float);
    void setterY(float);
};

void ToaDo::Nhap() {
    cin >> x >> y;
}

void ToaDo::Xuat() {
    cout << x << " " << y << endl;
}
float ToaDo::getterX() {
    return x;
}

float ToaDo::getterY() {
    return y;
}

void ToaDo::setterX(float _x) {
    x = _x;
}

void ToaDo::setterY(float _y) {
    y = _y;
}


class ThienThach {
private:
    string ma;
    ToaDo tam;
    float banKinh;
    float tocDoBay;
public:
    void Nhap();
    void Xuat();
    float thoiGian();
    string getterMa();
    void operator=(ThienThach);
};

void ThienThach::Nhap() {
    string temp;
    getline(cin, temp);
    vector<int> spacePos;
    int commaPos;
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == ' ') spacePos.push_back(i);
        else if (temp[i] == ',') commaPos = i;
    }
    ma = temp.substr(0, spacePos[0]);
    tam.setterX(stof(temp.substr(spacePos[0] + 2, commaPos)));
    tam.setterY(stof(temp.substr(commaPos + 2, spacePos[2] - 1)));
    banKinh = stof(temp.substr(spacePos[2] + 1, spacePos[3]));
    tocDoBay = stof(temp.substr(spacePos[3] + 1));
}

void ThienThach::Xuat() {
    cout << ma << endl;
    tam.Xuat();
    cout << banKinh << endl;
    cout << tocDoBay << endl;
}

float ThienThach::thoiGian() {
    float t = (sqrt(pow(tam.getterX(), 2) + pow(tam.getterY(), 2)) - banKinh) *1.0f / tocDoBay;
    return t;
}

void ThienThach::operator=(ThienThach tt) {
    ma = tt.ma;
    tam.setterX(tt.tam.getterX());
    tam.setterY(tt.tam.getterY());
    banKinh = tt.banKinh;
    tocDoBay = tt.tocDoBay;
}

string ThienThach::getterMa() {
    return ma;
}

class MangThienThach {
private:
    vector<ThienThach> list;
public:
    void Nhap();
    void Xuat();
    ThienThach chamNhanhNhat();
};

void MangThienThach::Nhap() {
    while (!cin.eof()) {
        ThienThach tmp;
        tmp.Nhap();
        list.push_back(tmp);
    }
}

void MangThienThach::Xuat() {
    for (int i = 0; i < list.size(); i++) {
        list[i].Xuat();
    }
}

ThienThach MangThienThach::chamNhanhNhat() {
    ThienThach min = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (min.thoiGian() > list[i].thoiGian()) {
            min = list[i];
        }
    }
    return min;
}


int main()
{
    freopen("INPUT.TXT", "r", stdin);
    MangThienThach list;
    list.Nhap();
    ThienThach min = list.chamNhanhNhat();
    list.Xuat();
    freopen("OUPUT.TXT", "w", stdout);
    cout << min.getterMa() << " " << fixed << setprecision(3) << min.thoiGian();
}