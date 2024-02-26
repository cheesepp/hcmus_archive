//#include <iostream>
//using namespace std;
//
//int findMaxDigit(int n) {
//    
//    int max = n % 10;
//    while (n != 0) {
//        if (max < n % 10) {
//            max = n % 10;
//        }
//        n /= 10;
//    }
//    return max;
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
//    int maxDigit = findMaxDigit(n);
//
//    cout << "Chu so lon nhat la: " << maxDigit;
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