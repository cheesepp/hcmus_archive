#include <iostream>
using namespace std;

int main() {
	
	int a, b, c;
	cout << "Nhap lan luot 3 so nguyen: ";
	cin >> a >> b >> c;
	a = a + b + c;
	a = a - b - c;
	c = a - b - c;
	a = a - b - c;
	cout << a << " " << b << " " << c;


	return 0;
}