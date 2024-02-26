#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;

    cout << "nhap mot so nguyen duong n: ";
    do {
        cin >> n;
        if (n <= 0) {
            cout << "phai nhap so nguyen duong! yeu cau nhap lai!";
        }

    } while (n <= 0);

    int sum = 0;
    int i = 1;
    while (i <= n) {
        int temp = 1;
        for (int j = 1; j <= i; j++) {
            temp *= j;
        }
        sum += temp;
        i++;
    }

    cout << "ket qua: " << sum;
}