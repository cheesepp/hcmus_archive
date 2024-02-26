//#include <iostream>
//using namespace std;
//
//bool isMirroredNum(int n) {
//    
//    int dup = n;
//    int k = 0;
//    while (dup != 0) {
//        int temp = dup % 10;
//        k = k * 10 + temp;
//        dup /= 10;
//    }
//
//    cout << n << " " << k << endl;
//
//    if (k == n) return true;
//    return false;
//}
//
//void nhapSoDuong() {
//
//    int n;
//
//    cout << "Nhap mot so nguyen duong n (1 <= n <= 10.000.000): ";
//    do {
//        cin >> n;
//        if (n < 1 || n > 10000000) {
//            cout << "Nhap khong hop le! Yeu cau nhap lai!";
//        }
//
//    } while (n < 1 || n > 10000000);
//
//    if (isMirroredNum(n)) {
//        cout << "La so co tinh dao nguoc!";
//    }
//    else {
//        cout << "Khong phai la so co tinh dao nguoc!";
//    }
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