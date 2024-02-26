//#include <iostream>
//using namespace std;
//
//bool isCompletedNum(int n) {
//    int sum = 0;
//    int prod = 1;
//    for (int i = 1; i < n; i++) {
//        if (n % i == 0) {
//            sum += i;
//            prod *= i;
//        }
//    }
//
//    if (sum == prod)
//        return true;
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
//    if (isCompletedNum(n)) {
//        cout << "La so hoan chinh!";
//    }
//    else {
//        cout << "Khong phai la so hoan chinh!";
//    }
//}
//
//
//int main() {
//    
//    nhapSoDuong();
//
//
//	return 0;
//}