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

	int maxDig = n % 10;
	int minDig = n % 10;
	int dup = n;
	dup /= 10;
	while (dup != 0) {
		int tmp = dup % 10;
		if (maxDig < tmp) maxDig = tmp;
		if (minDig > tmp) minDig = tmp;
		dup /= 10;
	}

	cout << "Chu so lon nhat: " << maxDig << endl;
	cout << "Chu so be nhat: " << minDig << endl;
	return 0;
}