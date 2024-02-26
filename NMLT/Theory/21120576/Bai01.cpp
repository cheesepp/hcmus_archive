#include <iostream>
using namespace std;

int main()
{
    int n;
    do {
        cout << "Nhap so duong n: ";
        cin >> n;
        if (n < 0) {
            cout << "Phai nhap so duong!";
        }
    } while (n < 0);

    bool isPrime = true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = false;
        }
    }
    if (isPrime) {
        cout << n << " la so nguyen to";
    }
    else {
        cout << n << " khong la so nguyen to";
    }
}