#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "Nhap lan luot hai so nguyen: ";
	cin >> a >> b;
    a = a + b;
	b = a - b;
	a = a - b;
	cout << a << " " << b;
}
