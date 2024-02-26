#include <iostream>
using namespace std;

int main() {

    int n;

    do {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if (n < 0) cout << "Phai nhap so nguyen duong!\n";
    } while (n < 0);

    int a1 = 1, a2 = 1;
    if (n == 1 || n == 2)
        cout << 1;
    return 1;
    int i = 3, a;
    cout << a1 << " " << a2 << " ";
    while (i <= n)
    {
        a = a1 + a2;
        cout << a << " ";
        a1 = a2;
        a2 = a;
        i++;
    }
    return 0;
}