#include <iostream>

using namespace std;

int main() {

	int a, b, c;
	cout << "Nhap lan luot 3 so nguyen: "; 
	cin >> a >> b >> c;

	if (a == 0) {
		if (b == 0) {
			if (c == 0) cout << "Phuong trinh vo so nghiem!";
			else cout << "Phuong trinh vo nghiem!";
		}
		else {
			if (c == 0) cout << "Phuong trinh vo so nghiem!";
			else {
				float x = -c * 1.0f / b;
				cout << "Phuong trinh co 1 nghiem duy nhat x = -b/a = " << x;
			}
		}
	}
	else {
		float delta = b * b - 4 * a * c;
		if (delta < 0) cout << "Phuong trinh vo nghiem!";
		else if (delta == 0)
		{
			float x = -b * 1.0f / (2 * a);
			cout << "Phuong trinh co nghiem kep x1 = x2 = -b/2a = " << x;
		}
		else
		{
			float x1 = (-b + sqrt(delta)) * 1.0f / (2 * a);
			float x2 = (-b - sqrt(delta)) * 1.0f / (2 * a);
			
			cout << "Phuong trinh co 2 nghiem phan biet x1 = " << x1 << " x2 = " << x2;
		}
			
	}
	return 0;
}