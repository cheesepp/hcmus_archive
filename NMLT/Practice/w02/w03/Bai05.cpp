#include <iostream>

using namespace std;

int main() {

	int a, b, c, d;
	cout << "Nhap lan luot 4 so nguyen: ";
	cin >> a >> b >> c >> d;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{
		int temp = a;
		a = c;
		c = temp;
	}

	if (a > d)
	{
		int temp = d;
		d = a;
		a = temp;
	}

	if (b > c) {
		int temp = b;
		b = c;
		c = temp;
	}
	
	if (b > d) {
		int temp = b;
		b = d;
		d = temp;
	}
	if (c > d) {
		int temp = c;
		c = d;
		d = temp;
	}
	cout << "Sau khi sap xep: " << a << " " << b << " " << c << " " << d;
	return 0;
}