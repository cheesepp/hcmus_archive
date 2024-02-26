#include <iostream>

using namespace std;

int main() {

	char n;
	cout << "Nhap mot chu cai: ";
	cin >> n;
	if (n >= 'A' && n <= 'Z')
	{
		cout << n << " doi sang chu thuong thanh: ";
		n = n + 32;
		cout << n << endl;
	}
	else if (n >= 'a' && n <= 'z')
	{
		cout << n << " doi sang chu hoa thanh: ";
		n = n - 32;
		cout << n << endl;
	}
	return 0;
}