#include <iostream>

using namespace std;

int main()
{
    int month, year;
    cout << "Nhap lan luot thang va nam: "; 
    cin >> month >> year;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "31 ngay!\n";
        break;
    case 2:
        if (year % 4 == 0)
            cout << "29 ngay!\n";
        else cout << "28 ngay!\n";
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "30 ngay!\n";
    default:
        cout << "Khong tim thay!";
    }
    return 0;
}
