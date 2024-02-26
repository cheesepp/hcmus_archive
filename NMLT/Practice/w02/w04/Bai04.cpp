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

    int sum = 0;
    int i = 1;
    while (i <= n) {
        int temp = 1;
        int j = 1;
        while (j <= i) {
            temp *= j;
            j++;
        }
        sum += temp;
        i++;
    }

    cout << "Ket qua: " << sum;
}