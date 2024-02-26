#include "MangPhanSo.h"

int main()
{
    MangPhanSo arr;

    arr.docFile("input.txt");
    cout << endl << "Tong phan so: " << arr.tinhTong() << endl;
    arr.sapXepMang();
    arr.xuat();
    cout << endl;
    arr.ghiFile("output.txt");
}

