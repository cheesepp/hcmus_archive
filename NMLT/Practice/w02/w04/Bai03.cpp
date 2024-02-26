#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;

    cout << "Nhap mot so nguyen duong n (n > 1): ";
    do {
        cin >> n;
        if (n <= 1) {
            cout << "Phai nhap so nguyen > 1! Yeu cau nhap lai!\n";
        }

    } while (n <= 1);

    float sum = 1;
    int i = 2;
    while (i <= n) {
        sum += (1 * 1.0f / ((i - 1) * i));
        i++;
    }

    cout << "Ket qua: " << sum;
}