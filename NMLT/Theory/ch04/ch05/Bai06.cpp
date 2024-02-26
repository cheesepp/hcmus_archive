#include <iostream>

using namespace std;

int main() {

    int n;

    do {
        cout << "Nhap so duong n: ";
        cin >> n;
        if (n < 0) {
            cout << "Phai nhap so duong!";
        }
    } while (n < 0);

    bool isPrime1 = true;
    bool isPrime2 = true;

    for (int i = 2; i < n; i++) {
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime1 = false;
                break;
            }
        }
        if (!isPrime1) continue;
        else {
            int t = n - i;
            for (int j = 2; j <= sqrt(t); j++) {
                if (t % j == 0) {
                    isPrime2 = false;
                    break;
                }
            }
            if (isPrime2) {
                cout << n << " = " << i << " + " << t;
                break;
            }
            else {
                continue;
            }
        }
    }

	return 0;
}