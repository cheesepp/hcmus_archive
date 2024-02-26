//#include <iostream>
//using namespace std;
//
//void BCNN(int tempA, int tempB) {
//
//    int a = tempA;
//    int b = tempB;
//    while (a != b) {
//        if (a > b) a = a - b;
//        else b = b - a;
//    }
//
//    cout << "BCNN cua hai so " << tempA << " " << tempB << " la: " << (tempA * tempB) * 1.0f / a;
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
//    BCNN(a, b);
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