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
	bool isAscen = true;
	while (dup != 0) {
		int tmp = dup % 10;
		if (tmp >= (dup / 10 % 10)) {
			dup /= 10;
			continue;
		}
		else {
			isAscen = false;
			break;
		}
	}
	
	if (isAscen) {
		cout << "Cac chu so tang dan";
	}
	else {
		cout << "Cac chu so giam dan";
	}
	return 0;
}