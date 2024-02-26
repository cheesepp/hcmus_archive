//#include <iostream>
//using namespace std;
//
//bool isPrime(int n) {
//    bool isPrime = true;
//
//    for (int i = 2; i <= sqrt(n); i++) {
//        if (n % i == 0) {
//            isPrime = false;
//        }
//    }
//    return isPrime;
//}
//
//void printPrimeNumLessOrEqualToN(int n) {
//    if (n < 2) {
//        cout << "Khong co so nguyen to!";
//        return;
//    }
//    int count = 1;
//    for (int i = 2; i <= n; i++) {
//        if (isPrime(i)) {
//            cout << "#" << count << " = " << i << endl;
//            count++;
//        }
//    }
//}
//int main() {
//    int n;
//
//    do {
//        cout << "Nhap so duong n: ";
//        cin >> n;
//        if (n < 0) {
//            cout << "Phai nhap so duong!";
//        }
//    } while (n < 0);
//
//    printPrimeNumLessOrEqualToN(n);
//    return 0;
//}