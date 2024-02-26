/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int distance;
    cout << "Nhap khoang cach: ";
    cin >> distance;
    int fee;
    if (distance <= 1) {
        fee = 15000;
    }
    else if (distance > 1 && distance <= 6) {
        fee = 1 * 15000 + (distance - 1) * 13500;
    }
    else if (distance > 6) {
        fee = 1 * 15000 + (distance - 5) * 13500 + (distance - 6) * 11000;
    } else if (distance > 120) {
        fee = 1 * 15000 + (distance - 5) * 13500 + (distance - 6) * 11000;
        fee = 0.9 * fee;
    }
    cout << "So tien can phai tra: " << fee << " vnd";

    return 0;
}
