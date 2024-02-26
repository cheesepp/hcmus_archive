#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;

    cout << "Nhap mot so nguyen duong n: ";
    do {
        cin >> n;
        if (n <= 0) {
            cout << "Phai nhap so nguyen duong! Yeu cau nhap lai!";
        }

    } while (n <= 0);

    bool isPrime = true;
    int i = 2;
    while (i <= sqrt(n)) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
        i++;
    }

    if (isPrime) cout << n << " la so nguyen to!";
    else cout << n << " khong la so nguyen to!";
}