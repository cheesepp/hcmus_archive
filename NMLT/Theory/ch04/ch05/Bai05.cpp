#include <iostream>

using namespace std;

int main() {

	// 1. Print phone call in terms of characters
	cout << " ================ PHONE ====================\n";
	int phone;
	cout << "Nhap so dien thoai (toi da 9 chu so): ";
	do {

		cin >> phone;

		if (phone >= 1000000000) {
			cout << "Yeu cau toi da 9 chu so!";
		}

	} while (phone >= 1000000000);
	int dupPhone = phone;
	int exp = 8;
;	while (dupPhone != 0) {
		int tmp = dupPhone *pow(10, -exp);

		if(tmp == 0) cout << "zero ";
		if(tmp == 1) cout << "one ";
		if(tmp == 2) cout << "two ";
		if(tmp == 3) cout << "three ";
		if(tmp == 4) cout << "four ";
		if(tmp == 5) cout << "five ";
		if(tmp == 6) cout << "six ";
		if(tmp == 7) cout << "seven ";
		if(tmp == 8) cout << "eight ";
		if(tmp == 9) cout << "nine ";

		dupPhone = dupPhone % (int)pow(10, exp);
		exp--;
	}

	cout << endl;
	// 2. Check Palindrome number
	cout << " ================ PALINDROME ====================\n";
	int n;

	do {
		cout << "Nhap so duong n: ";
		cin >> n;
		if (n < 0) {
			cout << "Phai nhap so duong!\n";
		}
	} while (n < 0);

	int dupPalindrome = n;
	int rev = 0;
	while (dupPalindrome != 0) {
		int tmp = dupPalindrome % 10;
		rev = rev * 10 + tmp;
		dupPalindrome /= 10;
	}

	if (rev == n) {
		cout << "Palindrome!";
	}
	else {
		cout << "Not Palindrome!";
	}

	cout << endl;
	// 3. Check Amstrong number
	cout << " ================ AMSTRONG ====================\n";

	int ams;

	do {
		cout << "Nhap so duong: ";
		cin >> ams;
		if (ams < 0) {
			cout << "Phai nhap so duong!\n";
		}
	} while (ams < 0);

	int dupAms = ams;
	int sum = 0;
	while (dupAms != 0) {
		int tmp = dupAms % 10;
		sum += (tmp * tmp * tmp);
		dupAms /= 10;
	}

	if (sum == ams) {
		cout << "Amstrong number!";
	}
	else {
		cout << "Not Amstrong number!";
	}
	return 0;
}