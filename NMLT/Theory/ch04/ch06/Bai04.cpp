//#include <iostream>
//using namespace std;
//
//int reverseDigit(int n) {
//
//	int dup = n;
//	int rev = 0;
//	while (dup != 0) {
//		int tmp = dup % 10;
//		rev = rev * 10 + tmp;
//		dup /= 10;
//	}
//
//	return rev;
//}
//
//void checkPalindromNum(int n) {
//
//	int checkPal = reverseDigit(n);
//
//	if (checkPal == n) {
//		cout << "Palindrome!";
//	}
//	else {
//		cout << "Not Palindrome!";
//	}
//
//	cout << endl;
//}
//
//int main() {
//
//	int n;
//
//	do {
//		cout << "Nhap so duong n: ";
//		cin >> n;
//		if (n < 0) {
//			cout << "Phai nhap so duong!\n";
//		}
//	} while (n < 0);
//
//	cout << "So dao nguoc cua " << n << " la: " << reverseDigit(n) << endl;
//
//	checkPalindromNum(n);
//    return 0;
//}