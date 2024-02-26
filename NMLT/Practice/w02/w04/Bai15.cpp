#include <iostream>
using namespace std;

int main() {
    int k, k1;
    cout << "Nhap so hang thu k cua day Fibonacci can in: ";
    cin >> k;
    cin >> k1;

    if (k < 0) {
        cout << "Vui long nhap mot so nguyen duong." << endl;
    }
    else {
        int a1 = 1, a2 = 1;
        if (k == 1 || k == 2) {
            cout << 1;
            return 1;
        }
        int i = 3, a;
        while (i <= k)
        {
            a = a1 + a2;
            a1 = a2;
            a2 = a;
            i++;
        }
        cout << "So hang thu " << k << " cua day Fibonacci la: " << a << endl;
    }
    return 0;
}