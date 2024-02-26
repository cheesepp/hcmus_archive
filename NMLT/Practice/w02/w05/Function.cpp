#include "Function.h"

// Bai 1: Tim so hoan chinh
bool isCompletedNum(int n) {
    int sum = 0;
    int prod = 1;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
            prod *= i;
        }
    }

    if (sum == prod)
        return true;
    return false;
}

// Bai 2: Tim so doi xung
bool isMirroredNum(int n) {

    int dup = n;
    int k = 0;
    while (dup != 0) {
        int temp = dup % 10;
        k = k * 10 + temp;
        dup /= 10;
    }

    cout << n << " " << k << endl;

    if (k == n) return true;
    return false;
}

// Bai 3: Tim so hoan hao
bool isPerfectNum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    if (sum == n * 2)
        return true;
    return false;
}

// Bai 4: Tim chu so lon nhat
int findMaxDigit(int n) {

    int max = n % 10;
    while (n != 0) {
        if (max < n % 10) {
            max = n % 10;
        }
        n /= 10;
    }
    return max;
}

// Bai 5: Dem so am
int demSoAm() {

    float num;
    int count = 0;
    cout << "Nhap so thuc n: ";
    while (cin >> num) {
        if (num == 0) {
            return count;
        }
        else if (num < 0) {
            count++;
        }
        else {
            continue;
        }
    }
}

// Bai 6: Tim uoc chung lon nhat
void UCLN(int tempA, int tempB) {

    int a = tempA;
    int b = tempB;
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }

    cout << "UCLN cua hai so " << tempA << " " << tempB << " la: " << a;
}

// Bai 7: Tim boi chung nho nhat
void BCNN(int tempA, int tempB) {

    int a = tempA;
    int b = tempB;
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }

    cout << "BCNN cua hai so " << tempA << " " << tempB << " la: " << (tempA * tempB) * 1.0f / a;
}

// Bai 8: Hoan vi hai so nguyen
void hoanviSoNguyen(int& a, int& b) {

    cout << "So ban dau " << a << " va " << b << endl;
    int temp = a;
    a = b;
    b = temp;

    cout << "Sau khi hoan vi " << a << " va " << b << endl;
}

// Bai 9: Chuyen so thap phan sang nhi phan
void decToBin(int dec) {
    int binary = 0, bit = 0;

    if (dec >= 0) {
        long long binaryNumber = 0;
        int p = 0;
        while (dec > 0)
        {
            binaryNumber += (dec % 2) * pow(10, p);
            ++p;
            dec /= 2;
        }
        cout << "Dang nhi phan: " << binaryNumber << endl;
    }
    else {
        long long temp = abs(dec);
        long long binaryNumber = 0;
        int p = 0;
        while (temp > 0)
        {
            binaryNumber += (temp % 2) * pow(10, p);
            ++p;
            temp /= 2;
        }

        long long full1 = 11111111;
        binaryNumber = full1 - binaryNumber;


        cout << "Dang nhi phan: " << binaryNumber << endl;
    }


}

// Bai 10: Tim Fn
int tinhF(int n) {

    int f0 = 1;
    int f1 = 2;
    int fn;

    if (n < 0) return -1;
    if (n == 0) return 1;
    if (n == 1) return 2;

    for (int i = 1; i < n; i++) {
        fn = 3 * f1 - 2 * f0;
        f0 = f1;
        f1 = fn;
    }

    return fn;
}

// Ham nhap so duong
void menu() {

    int bai;
    do {

        cout << "\n======= NHAP CAC TUY CHON SAU ========\n";
        cout << "|| 1. Tim so hoan chinh              ||\n";
        cout << "|| 2. Tim so doi xung                ||\n";
        cout << "|| 3. Tim so doi hoan hao            ||\n";
        cout << "|| 4. Tim chu so lon nhat            ||\n";
        cout << "|| 5. Dem so am                      ||\n";
        cout << "|| 6. Tim uoc chung lon nhat         ||\n";
        cout << "|| 7. Tim boi chung nho nhat         ||\n";
        cout << "|| 8. Hoan vi hai so nguyen          ||\n";
        cout << "|| 9. Chuyen thap phan sang nhi phan ||\n";
        cout << "|| 10. Tim Fn                        ||\n";
        cout << "|| 0. Ket thuc chuong trinh          ||\n";
        cout << "=======================================\n";

        cout << "Vui long chon: ";
        cin >> bai;


    switch (bai) {
            int n;
            int a, b;
    case 1: {

        cout << "Nhap mot so nguyen duong n (1 <= n <= 10.000.000): \n";
        do {
            cin >> n;
            if (n < 1 || n > 10000000) {
                cout << "Nhap khong hop le! Yeu cau nhap lai!\n";
            }


        } while (n < 1 || n > 10000000);

        if (isCompletedNum(n)) {
            cout << "La so hoan chinh!\n";
        }
        else {
            cout << "Khong phai la so hoan chinh!\n";
        }
    }
            break;

        case 2:
        {
            cout << "Nhap mot so nguyen duong n (1 <= n <= 10.000.000): \n";
            do {
                cin >> n;
                if (n < 1 || n > 10000000) {
                    cout << "Nhap khong hop le! Yeu cau nhap lai!\n";
                }

            } while (n < 1 || n > 10000000);

            if (isMirroredNum(n)) {
                cout << "La so co tinh dao nguoc!\n";
            }
            else {
                cout << "Khong phai la so co tinh dao nguoc!\n";
            }
        }
            break;

        case 3:
        {
            cout << "Nhap mot so nguyen duong n (1 <= n <= 100.000.000): \n";
            do {
                cin >> n;
                if (n < 1 || n > 100000000) {
                    cout << "Nhap khong hop le! Yeu cau nhap lai!\n";
                }

            } while (n < 1 || n > 100000000);

            if (isPerfectNum(n)) {
                cout << "La so hoan hao!\n";
            }
            else {
                cout << "Khong phai la so hoan hao!\n";
            }
        }
            break;

        case 4:
        {
            cout << "Nhap mot so nguyen duong n (1 <= n <= 10.000.000): \n";
            do {
                cin >> n;
                if (n < 1 || n > 10000000) {
                    cout << "Nhap khong hop le! Yeu cau nhap lai!\n";
                }

            } while (n < 1 || n > 10000000);

            int maxDigit = findMaxDigit(n);

            cout << "Chu so lon nhat la: " << maxDigit << endl;
        }
            break;

        case 5:
        {
            int countSoAm = demSoAm();

            cout << "So am dem duoc la: " << countSoAm;
        }
            break;

        case 6:
        {
            cout << "Nhap hai so nguyen duong: \n";
            do {
                cin >> a >> b;
                if (a <= 0 || b <= 0) {
                    cout << "Nhap khong hop le! Yeu cau nhap lai!\n";
                }

            } while (a <= 0 || b <= 0);

            UCLN(a, b);
        }
            break;

        case 7:
        {
            cout << "Nhap hai so nguyen duong: \n";
            do {
                cin >> a >> b;
                if (a <= 0 || b <= 0) {
                    cout << "Nhap khong hop le! Yeu cau nhap lai!\n";
                }

            } while (a <= 0 || b <= 0);

            BCNN(a, b);
        }
            break;

        case 8:
        {
            cout << "Nhap hai so nguyen duong: \n";
            do {
                cin >> a >> b;
                if (a <= 0 || b <= 0) {
                    cout << "Nhap khong hop le! Yeu cau nhap lai!\n";
                }

            } while (a <= 0 || b <= 0);

            hoanviSoNguyen(a, b);
        }
            break;

        case 9:
        {
            cout << "Nhap so nguyen n: \n";
            cin >> n;


            decToBin(n);
        }
            break;
        case 10:
        {
            cout << "Nhap mot so nguyen duong n: ";
            cin >> n;

            cout << "Gia tri cua Fn la: " << tinhF(n);
        }
            break;
        default:
            cout << "\n========= KET THUC CHUONG TRINH ===========\n";

    }
    } while (bai != 0);
}

