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
    int j = 2;
    while ( j < n) {
        isPrime = true;
        for (int i = 2; i <= sqrt(j); i++) {
            if (j % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) cout << j << " ";
        else {
            j++;
            continue;
        }
        j++;

    }

}