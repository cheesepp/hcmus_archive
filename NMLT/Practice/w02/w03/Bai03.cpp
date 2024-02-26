#include <iostream>

using namespace std;

int main() {

	int a, b;
	cout << "Nhap hai so a va b: ";
	cin >> a >> b;
	if (a == 0) {
		if (b == 0) cout << "Phuong trinh vo so nghiem!";
		else cout << "Phuong trinh vo nghiem!";
	}
	else {
		if (b == 0) cout << "Phuong trinh vo so nghiem!";
		else {
			float x = -b * 1.0f / a;
			cout << "Phuong trinh co 1 nghiem duy nhat x = -b/a = " << x;
		}
	}
	return 0;
}