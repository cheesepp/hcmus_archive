//#include <iostream>
//using namespace std;
//
//void UCLN(int tempA, int tempB) {
//    
//    int a = tempA;
//    int b = tempB;
//    while (a != b) {
//        if (a > b) a = a - b;
//        else b = b - a;
//    }
//
//    cout << "UCLN cua hai so " << tempA << " " << tempB << " la: " << a;
//}
//
//void nhapSoDuong() {
//
//    int a, b;
//
//    cout << "Nhap hai so nguyen duong: ";
//    do {
//        cin >> a >> b;
//        if (a <= 0 || b <= 0) {
//            cout << "Nhap khong hop le! Yeu cau nhap lai!";
//        }
//
//    } while (a <= 0 || b <= 0);
//
//    UCLN(a, b);
//}
//
//
//int main() {
//
//    nhapSoDuong();
//
//
//    return 0;
//}