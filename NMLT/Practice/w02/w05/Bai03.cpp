//#include <iostream>
//using namespace std;
//
//bool isPerfectNum(int n) {
//    int sum = 0;
//    for (int i = 1; i <= n; i++) {
//        if (n % i == 0) {
//            sum += i;
//        }
//    }
//
//    if (sum == n*2)
//        return true;
//    return false;
//}
//
//void nhapSoDuong() {
//
//    int n;
//
//    cout << "Nhap mot so nguyen duong n (1 <= n <= 100.000.000): ";
//    do {
//        cin >> n;
//        if (n < 1 || n > 100000000) {
//            cout << "Nhap khong hop le! Yeu cau nhap lai!";
//        }
//
//    } while (n < 1 || n > 100000000);
//
//    if (isPerfectNum(n)) {
//        cout << "La so hoan hao!";
//    }
//    else {
//        cout << "Khong phai la so hoan hao!";
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