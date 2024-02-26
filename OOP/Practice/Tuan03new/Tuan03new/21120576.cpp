#include "DonThuc.h"

//int main()
//{
//	DonThuc a;
//	DonThuc b;
//	DonThuc c;
//	b.nhap();
//	c.nhap();
//	b.xuat();
//
//	cout << "\nCong 2 don thuc: \n";
//	a = b + c;
//	a.xuat();
//	
//	cout << "\nTru 2 don thuc: \n";
//	a = b - c;
//	a.xuat();
//	
//	cout << "\nNhan 2 don thuc: \n";
//	a = b * c;
//	a.xuat();
//	
//	cout << "\nChia 2 don thuc: \n";
//	a = b / c;
//	a.xuat();
//}

int main() {
    /* DonThuc dt1(3, 4);
     DonThuc dt2(2, 3);

     cout << "dt1 = ";
     dt1.xuat();
     cout << "dt2 = ";
     dt2.xuat();

     float x = 2;
     cout << "Gia tri cua dt1 tai x = " << x << " la " << dt1.tinhGiaTri(x) << endl;

     DonThuc dt3 = dt1 + dt2;
     DonThuc dt4 = dt1 - dt2;
     DonThuc dt5 = dt1 * dt2;
     DonThuc dt6 = dt1 / dt2;

     cout << "dt3 = dt1 + dt2 = ";
     dt3.xuat();
     cout << "dt4 = dt1 - dt2 = ";
     dt4.xuat();
     cout << "dt5 = dt1 * dt2 = ";
     dt5.xuat();
     cout << "dt6 = dt1 / dt2 = ";
     dt6.xuat();*/

    DaThuc dt7(4);
    dt7.getterDaThuc()[0] = DonThuc(1, 3);
    dt7.getterDaThuc()[1] = DonThuc(-1, 2);
    dt7.getterDaThuc()[2] = DonThuc(-7, 1);
    dt7.getterDaThuc()[3] = DonThuc(3, 0);


    DaThuc dt8(2);
    dt8.getterDaThuc()[0] = DonThuc(1, 1);
    dt8.getterDaThuc()[1] = DonThuc(-3, 0);

    cout << "dt7 = ";
    dt7.xuat();
    cout << "dt8 = ";
    dt8.xuat();

    //cout << "Gia tri cua dt7 tai x = " << x << " la " << dt7.tinhDaThuc(x) << endl;

    DaThuc dt9 = dt7.congDaThuc(dt8);
    DaThuc dt10 = dt7.truDaThuc(dt8);
    DaThuc dt11 = dt7.nhanDaThuc(dt8);
    DaThuc dt12 = dt7.chiaDaThuc(dt8);

    cout << "\ndt9 = dt7 + dt8 = ";
    dt9.xuat();
    cout << endl;
    cout << "\ndt10 = dt7 - dt8 = ";
    dt10.xuat();
    cout << endl;
    cout << "\ndt11 = dt7 * dt8 = ";
    dt11.xuat();
    cout << endl;
    cout << "dt12 = dt7 / dt8 = ";
    dt12.xuat();

    return 0;
}
