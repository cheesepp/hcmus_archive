#include <iostream>

using namespace std;

int main()
{
    int day, month, year;
    cout << "Nhap lan luot ngay, thang va nam: ";
    do {
        cin >> day >> month >> year;
        if (day == 29 && month == 2 && year % 4 != 0) {
            cout << "Khong hop le! Vui long nhap lai!\n";
        }
    } while (day == 29 && month == 2 && year % 4 != 0);
    int tg;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        tg = 31;
        break;
    case 2:
        if (year % 4 == 0)
            tg = 29;
        else tg = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        tg = 30;
        break;
    default:
        cout << "Khong tim thay!";
    }
    int daySau = day;
    int monthSau = month;
    int yearSau = year;
    
    if (daySau == tg) {
        if (monthSau == 12) {
            daySau++;
            monthSau = 1;
            yearSau++;
        }
        else {
            daySau = 1;
            monthSau++;
        }
    }
    else {
        daySau++;
    }
    cout << "Ngay sau do: " << daySau << " " << monthSau << " " << yearSau << endl;

    int dayTruoc = day;
    int monthTruoc = month;
    int yearTruoc = year;

    if (dayTruoc == 1) {
        if (monthTruoc == 1) {
            dayTruoc = 31;
            monthTruoc = 12;
            yearTruoc--;
        }
        else {
            monthTruoc--;
            switch (monthTruoc) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                dayTruoc = 31;
                break;
            case 2:
                if (yearTruoc % 4 == 0)
                    dayTruoc = 29;
                else dayTruoc = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dayTruoc = 30;
                break;
            }
        }
    }
    else {
        dayTruoc--;
    }

    cout << "Ngay truoc do: " << dayTruoc << " " << monthTruoc << " " << yearTruoc;
    return 0;
}
