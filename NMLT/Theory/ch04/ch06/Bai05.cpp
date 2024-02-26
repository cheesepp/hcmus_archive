#include <iostream>
using namespace std;

void readMobilePhoneNumber(int phone) {
	int dupPhone = phone;
	int exp = 8;
	while (dupPhone != 0) {
		int tmp = dupPhone * pow(10, -exp);

		switch (tmp) {

			case 0:
				cout << "zero ";
				break;
			case 1:
				cout << "one ";
				break;
			case 2:
				cout << "two ";
				break;
			case 3:
				cout << "three ";
				break;
			case 4:
				cout << "four ";
				break;
			case 5:
				cout << "five ";
				break;
			case 6:
				cout << "six ";
				break;
			case 7:
				cout << "seven ";
				break;
			case 8:
				cout << "eight ";
				break;
			case 9:
				cout << "nine ";
				break;
		}

		dupPhone = dupPhone % (int)pow(10, exp);
		exp--;
	}
}

template <class T>
void swapNumbers(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {

	//int phone;
	//cout << "nhap so dien thoai (toi da 9 chu so): ";
	//do {

	//	cin >> phone;

	//	if (phone >= 1000000000) {
	//		cout << "yeu cau toi da 9 chu so!\n";
	//	}

	//} while (phone >= 1000000000);

	//readMobilePhoneNumber(phone);

	///*double a, b;
	/*cin >> a >> b;
	swapNumbers(a, b);
	cout << a << " " << b;*/
	int i = 10;
	printf("%d &i", &i);

    return 0;
}