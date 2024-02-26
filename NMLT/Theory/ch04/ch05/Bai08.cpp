#include <iostream>

using namespace std;

int main() {

	int h;
	cout << "Nhap chieu cao h: ";
	cin >> h;

	cout << endl;
	cout << " ================ SQUARE STAR PATTERN ====================\n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	cout << " ================ HOLLOW SQUARE STAR PATTERN ====================\n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			if (i >= 1 && i < h - 1 && j >= 1 && j < h - 1) {
				cout << " ";
				continue;
			}
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	cout << " ================ RIGHT TRIANGLE STAR PATTERN ====================\n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	cout << " ================ HOLLOW RIGHT TRIANGLE STAR PATTERN ====================\n";
	int k = h - 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			if (j >= k) cout << "*";
			else cout << " ";
		}
		k--;
		cout << endl;
	}

	cout << endl;
	cout << " ================ MIRRORED RIGHT STAR PATTERN ====================\n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			if (i >= 1 && i < h - 1 && j >= 1 && j < i) {
				cout << " ";
				continue;
			}
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	int k1 = h - 1;
	cout << " ================ HOLLOW MIRRORED RIGHT STAR PATTERN ====================\n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			if (j >= k1) {
				if (i >= 1 && i < h - 1 && j > k1 && j < h - 1) {
					cout << " ";
					continue;
				}
				else cout << "*";
			}
			else cout << " ";
		}
		k1--;
		cout << endl;
	}
	return 0;
}