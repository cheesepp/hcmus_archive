/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Nhap lan luot 3 do dai: ";
    cin >> a >> b >> c;
    if(a + b > c && a + c > b && b + c > a) {
        if (a == b || a == c || b == c) {
            if (a == b && a == c && b == c) {
                cout << "Equilateral triangle";
            } else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
                cout << "Isosceles right triangle";
            }
            else {
                cout << "Isosceles triangle";
            }
        }
        else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
            cout << "Right triangle";
        }
    } else {
        cout << "Not a triangle";
    }

    return 0;
}
