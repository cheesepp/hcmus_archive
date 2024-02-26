// ch05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int elecPowerUsage;
    cout << "Nhap so dien thang nay: ";
    do {
        cin >> elecPowerUsage;
        if (elecPowerUsage < 0) {
            cout << "So dien phai lon hon 0! Yeu cau nhap lai!\n";
        }

    } while (elecPowerUsage < 0);
    double fee;
    if (elecPowerUsage <= 50) {
        fee = elecPowerUsage*1.678;
    }
    else if (elecPowerUsage > 50 && elecPowerUsage <= 100) {
        fee = 50 * 1.678 + (elecPowerUsage - 50) * 1.734;
    }
    else if (elecPowerUsage > 100 && elecPowerUsage <= 200) {
        fee = 50 * 1.678 + 50 * 1.734 + (elecPowerUsage - 100) * 2.014;
    }
    else if (elecPowerUsage > 200 && elecPowerUsage <= 300) {
        fee = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (elecPowerUsage - 200) * 2.536;
    }
    else if (elecPowerUsage > 300 && elecPowerUsage <= 400) {
        fee = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (elecPowerUsage - 300) * 2.834;
    }
    else if (elecPowerUsage > 400) {
        fee = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (elecPowerUsage - 400) * 2.927;
    }
    cout << "Phi tien dien thang nay la: " << fee << " VND/kWh";

    return 0;
}