#include "DonThuc.h"
#include "DaThuc.h"

int main() {

    DaThuc d1;
    d1.nhap();

    DaThuc d2;
    d2.nhap();

    DaThuc d3 = d1.congDaThuc(d2);
    DaThuc d4 = d1.truDaThuc(d2);
    DaThuc d5 = d1.nhanDaThuc(d2);
    DaThuc d6 = d1.chiaDaThuc(d2);

    cout << "\nd1 + d2 = ";
    d3.xuat();
    cout << endl;
    cout << "\nd1 - d2 = ";
    d4.xuat();
    cout << endl;
    cout << "\nd5 = dt1 * dt2 = ";
    d5.xuat();
    cout << endl;
    cout << "d6 = d2 / d2 = ";
    d6.xuat();

    return 0;
}
