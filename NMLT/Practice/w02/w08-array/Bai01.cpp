#include "1DArray.h"
#include "2DArray.h"


void menu2DArr() {
    int a[MAX][MAX];
    int m = 0;
    int n = 0;
    float b[MAX][MAX];
    int h = 0;
    int k = 0;
    int bai;
    do {
        cout << "======================== MANG 2 CHIEU ==========================\n";
        cout << "|| 1. Nhap ma tran m x n so nguyen                            ||\n";
        cout << "|| 2. Xuat ma tran m x n so nguyen                            ||\n";
        cout << "|| 3. Nhap ma tran m x n so thuc                              ||\n";
        cout << "|| 4. Xuat ma tran m x n so thuc                              ||\n";
        cout << "|| 5. Tim so lon nhat va be nhat trong ma tran so nguyen      ||\n";
        cout << "|| 6. Sap xep ma tran so thuc tang dan                        ||\n";
        cout << "|| 7. Sap xep ma tran so thuc tang dan dung mang phu          ||\n";
        cout << "|| 8. Tim diem yen ngua tren ma tran so nguyen                ||\n";
        cout << "|| 9. Tao ma tran dem so luong cac so duong xung quanh phan tu||\n";
        cout << "||10. Sap xep ma tran theo tong cac dong tang dan             ||\n";
        cout << "|| 0. Ket thuc chuong trinh                                   ||\n";
        cout << "================================================================\n";
        cout << "Vui long chon: ";
        cin >> bai;

        switch (bai) {
        case 1: {
            inputI2DArr(a, m, n);
            outputI2DArr(a, m, n);
            break;
        }
        case 2: {
            outputI2DArr(a, m, n);
            break;
        }
        case 3: {
            inputF2DArr(b, h, k);
            outputF2DArr(b, h, k);
            break;
        }
        case 4: {
            outputF2DArr(b, h, k);
            break;
        }
        case 5: {
            findMinMax(a, m, n);
            break;
        }
        case 6: {
            sort2DArr(b, h, k);
            break;
        }
        case 7: {
            sort2DArrWExArr(b, h, k);
            break;
        }
        case 8: {
            findHorseSaddle(a, m, n);
            break;
        }
        case 9: {
            int c[MAX][MAX];
            create2DArr(a, m, n, c);
            outputI2DArr(c, m, n);
            break;
        }
        case 10: {
            sortBySumRow(a, m, n);
            outputI2DArr(a, m, n);
            break;
        }
        default:
            cout << "\n============= KET THUC CHUONG TRINH ============\n";
        }
    } while (bai != 0);
}
void menu1DArr() {

    int a[MAX];
    int n = 0;
    int bai;
    do {

        cout << "\n======= NHAP CAC TUY CHON SAU ========\n";
        cout << "============= MANG 1 CHIEU ==============\n";
        cout << "|| 1.  Nhap mang n so nguyen            ||\n";
        cout << "|| 2.  Xuat mang                        ||\n";
        cout << "|| 3.  Tim phan tu lon nhat trong mang  ||\n";
        cout << "|| 4.  Tinh tong so khong am            ||\n";
        cout << "|| 5.  Tinh tong cac phan tu vi tri chan||\n";
        cout << "|| 6.  Tinh tong so nguyen to           ||\n";
        cout << "|| 7.  Tim so am lon nhat               ||\n";
        cout << "|| 8.  Tim so khong am be nhat          ||\n";
        cout << "|| 9.  Kiem tra mang tang dan           ||\n";
        cout << "|| 10. Tinh tong so chinh phuong        ||\n";
        cout << "|| 0. Ket thuc chuong trinh             ||\n";
        cout << "=========================================\n";

        cout << "Vui long chon: ";
        cin >> bai;


        switch (bai) {
        case 1: {
            inputArr(a, n);
            outputArr(a, n);
            break;
        }
        case 2: {
            outputArr(a, n);
            break;
        }
        case 3: {
            findMaxElement(a, n);
            break;
        }
        case 4: {
            sumOfUnNegNum(a, n);
            break;
        }
        case 5: {
            sumOfEvenIndex(a, n);
            break;
        }
        case 6: {
            countPrimeNum(a, n);
            break;
        }
        case 7: {
            findNegMaxNum(a, n);
            break;
        }
        case 8: {
            findNoneNegMinNum(a, n);
            break;
        }
        case 9: {
            isIncrement(a, n);
            break;
        }
        case 10: {
            sumSoChinhPhuong(a, n);
            break;
        }
        default:
            cout << "\n============= KET THUC CHUONG TRINH ============\n";
        }
    } while (bai != 0);
}

void menu() {

    int type;
    do {
        cout << "Nhap loai muon thao tac: \n";
        cout << "1. Mang 1 chieu\n";
        cout << "2. Mang 2 chieu\n";
        cout << "0. Ket thuc chuong trinh\n";
        cout << "Vui long chon: ";
        cin >> type;
        switch (type) {
        case 1: {
            menu1DArr();
            break;
        }
        case 2: {
            menu2DArr();
            break;
        }
        default:
            cout << "\nKet thuc chuong trinh!";
        }
    } while (type != 0);
}
int main() {

    menu();
	return 0;
}