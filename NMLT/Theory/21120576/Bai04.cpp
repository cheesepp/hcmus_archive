#include <iostream>
using namespace std;

int main() {

	int n;

	do {
		cout << "Nhap so duong n: ";
		cin >> n;
		if (n < 0) {
			cout << "Phai nhap so duong!\n";
		}
	} while (n < 0);

	int dup = n;
	int rev = 0;
	while (dup != 0) {
		int tmp = dup % 10;
		rev = rev * 10 + tmp;
		dup /= 10;
	}

	cout << "So ban dau: " << n << endl;
	cout << "So dao nguoc: " << rev;
	return 0;
}