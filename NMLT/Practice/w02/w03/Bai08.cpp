#include <iostream>

using namespace std;

int main() {

    int a, b, c;
    cout << "Nhap lan luot 3 do dai: ";
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b || a == c || b == c) {
            if (a == b && a == c && b == c) {
                cout << "Tam giac deu";
            }
            else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
                cout << "Tam giac vuong can";
            }
            else {
                cout << "Tam giac can";
            }
        }
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            cout << "Tam giac vuong";
        }
        else {
            cout << "Tam giac thuong";
        }
    }
    else {
        cout << "Khong phai la tam giac";
    }

	return 0;
}