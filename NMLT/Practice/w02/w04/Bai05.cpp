#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    float x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Nhap mot so nguyen duong n: ";
    do {
        cin >> n;
        if (n <= 0) {
            cout << "Phai nhap so nguyen duong! Yeu cau nhap lai!";
        }

    } while (n <= 0);

    int sum = 0;
    int i = 0;
    while (i <= n) {
        sum += pow(x, i);
        i++;
    }

    cout << "Ket qua: " << sum;
}