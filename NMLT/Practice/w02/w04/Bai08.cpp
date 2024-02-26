#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b;
    cout << "Nhap hai so a, b: ";
    cin >> a >> b;
    if (a < 0) a = abs(a);
    if (b < 0) b = abs(b);
    int tempA = a;
    int tempB = b;
    while (tempA != tempB) {
        if (tempA > tempB) tempA = tempA - tempB;
        if (tempA < tempB) tempB = tempB - tempA;
    }

    cout << "UCLN: " << tempA << endl;
    int bcnn = (a * b) / tempA;
    cout << "BCNN: " << bcnn;
}