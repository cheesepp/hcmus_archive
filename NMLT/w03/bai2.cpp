/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double hour;
    cout << "Nhap thoi gian do xe: ";
    cin >> hour;
    int fee;
    if (hour >= 0 && hour <= 3) {
        fee = 5;
    }
    else if (hour > 3 && hour <= 9) {
        fee = 5 + 6 * round(hour - 1);
    }
    else if (hour > 9 && hour <= 24) {
        fee = 5 + 6 * round(hour - 1) + (hour - 5) * 60;
    }
    cout << "Phi do xe can phai tra: " << fee << "$";

    return 0;
}
