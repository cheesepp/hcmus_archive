//#include <iostream>
//using namespace std;
//
//void hoanviSoNguyen(int& a, int& b) {
//
//    cout << "So ban dau " << a << " va " << b << endl;
//    int temp = a;
//    a = b;
//    b = temp;
//
//    cout << "Sau khi hoan vi " << a << " va " << b << endl;
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
//    hoanviSoNguyen(a, b);
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