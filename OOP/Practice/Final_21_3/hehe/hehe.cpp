#include <iostream>
#include <string>
using namespace std;
class Nguoi {
protected:
    string ten;
    string ngaySinh;

public:
    Nguoi() {}
    Nguoi(string _ten, string _ngaySinh) : ten(_ten), ngaySinh(_ngaySinh) {}

    virtual void nhap();
    virtual void xuat();
    friend istream& operator>>(istream& is, Nguoi& nguoi);
    friend ostream& operator<<(ostream& os, const Nguoi& nguoi);
};

void Nguoi::nhap() {
    cin >> *this;
}

void Nguoi::xuat() {
    cout << *this;
}

istream& operator>>(istream& is, Nguoi& nguoi) {
    cout << "Nhập tên: ";
    is >> nguoi.ten;
    cout << "Nhập ngày sinh: ";
    is >> nguoi.ngaySinh;
    return is;
}

ostream& operator<<(ostream& os, const Nguoi& nguoi) {
    os << "Tên: " << nguoi.ten << endl;
    os << "Ngày sinh: " << nguoi.ngaySinh << endl;
    return os;
}

class HocSinh : public Nguoi {
private:
    int soLopDangHoc;

public:
    HocSinh() {}
    HocSinh(string _ten, string _ngaySinh, int _soLopDangHoc)
        : Nguoi(_ten, _ngaySinh), soLopDangHoc(_soLopDangHoc) {}

    void nhap() {
        cin >> *this;
    }
    void xuat() {
        cout << *this;
    }

    friend istream& operator>>(istream& is, HocSinh& hocSinh);
    friend ostream& operator<<(ostream& os, const HocSinh& hocSinh);
};



istream& operator>>(istream& is, HocSinh& hocSinh) {
    is >> static_cast<Nguoi&>(hocSinh);
    cout << "Nhập số lớp đang học: ";
    is >> hocSinh.soLopDangHoc;
    return is;
}

ostream& operator<<(ostream& os, const HocSinh& hocSinh) {
    os << static_cast<const Nguoi&>(hocSinh);
    os << "Số lớp đang học: " << hocSinh.soLopDangHoc << endl;
    return os;
}



class GiaoVien : public Nguoi {
private:
    string truongDangDay;

public:
    GiaoVien() {}
    GiaoVien(string _ten, string _ngaySinh, string _truongDangDay)
        : Nguoi(_ten, _ngaySinh), truongDangDay(_truongDangDay) {}

    void nhap() {
        cin >> *this;
    }

    void xuat() {
        cout << *this;
    }

    friend istream& operator>>(istream& is, GiaoVien& giaoVien);
    friend ostream& operator<<(ostream& os, const GiaoVien& giaoVien);
};

istream& operator>>(istream& is, GiaoVien& giaoVien) {
    is >> static_cast<Nguoi&>(giaoVien);
    cout << "Nhập trường đang dạy: ";
    is >> giaoVien.truongDangDay;
    return is;
}

ostream& operator<<(ostream& os, const GiaoVien& giaoVien) {
    os << static_cast<const Nguoi&>(giaoVien);
    os << "Trường đang dạy: " << giaoVien.truongDangDay << endl;
    return os;
}

