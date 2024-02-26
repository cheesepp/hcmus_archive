#include <iostream>
using namespace std;

int main() {

	int a, b;
	cout << "Nhap lan luot hai so nguyen: ";
	cin >> a >> b;
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	cout << "UCLN: " << a;
	return 0;
}