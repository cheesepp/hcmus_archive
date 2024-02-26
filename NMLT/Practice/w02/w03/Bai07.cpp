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
    }
    else if (distance > 120) {
        fee = 1 * 15000 + (distance - 5) * 13500 + (distance - 6) * 11000;
        fee = 0.9 * fee;
    }
    cout << "So tien can phai tra: " << fee << " vnd";

    return 0;
}
