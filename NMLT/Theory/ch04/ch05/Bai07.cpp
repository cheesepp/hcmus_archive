//#include <iostream>
//
//using namespace std;
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
//
//	// decimal to binary
//    int binary[16];
//
//    int i = 0;
//    while (n > 0) {
//        binary[i] = n % 2;
//        n = n / 2;
//        i++;
//    }
//	cout << "Binary number: ";
//	for (int j = i - 1; j >= 0; j--)
//        cout << binary[j];
//
//	// binary to decimal
//	int decimal = 0;
//	for (int j = 0; j < i; j++) {
//		decimal += binary[j] * pow(2, j);
//	}
//
//	cout << "\nDecimal number: " << decimal;
//
//	return 0;
//}