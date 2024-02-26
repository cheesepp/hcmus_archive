#include <iostream>

using namespace std;

int main() {
	
	int a, b, c, d;
	cout << "Nhap 4 so nguyen: ";
	cin >> a >> b >> c >> d;

	int min = a;
	min = (min > b) ? b : min;
	min = (min > c) ? c : min;
	min = (min > d) ? d : min;

	cout << "So be nhat la: " << min;
	return 0;
}