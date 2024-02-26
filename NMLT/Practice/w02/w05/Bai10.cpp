//#include <iostream>
//using namespace std;
//
//int tinhF(int n) {
//    
//    int f0 = 1;
//    int f1 = 2;
//    int fn;
//
//    if (n < 0) return -1;
//    if (n == 0) return 1;
//    if (n == 1) return 2;
//
//    for (int i = 1; i < n; i++) {
//        fn = 3 * f1 - 2*f0;
//        f0 = f1;
//        f1 = fn;
//    }
//
//    return fn;
//}
//
//void nhapSoDuong() {
//
//    int n;
//
//    cout << "Nhap mot so nguyen duong n: ";
//    cin >> n;
//
//    cout << "Gia tri cua Fn la: " << tinhF(n);
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