
#include "Function.h"

int main()
{
    int a1[MAX];
    int n;
    int a2[MAX];
    int a2Num = 0;
    int matrix[MAX][MAX];
    int m;
    
    //a) (10đ) Nhập và xuất một mảng số nguyên Arr1 gồm N phần tử(N
    //	>= 9 và là số chính phương).
    inputArr1(a1, n);
    outputArr1(a1, n);

    //b) (20đ) Tạo mảng con Arr2 chứa tất cả các số nguyên tố từ mảng
    //Arr1.
    primeArr2(a2, a1, n, a2Num);
    cout << "\n========= MANG SO NGUYEN TO ============\n";
    outputArr1(a2, a2Num);

    //c) (10đ) Tạo mảng 2 chiều Matrix có M dòng và M cột, với M = √�.
    //Trong đó, giá trị Matrix[i][j] = Arr1[j + M * i]
    cout << "\n========= MA TRAN ============\n";
    createMatrix(matrix, a1, n, m);
    cout << "Tao mang 2 chieu thanh cong! \n";

    // Kiểm tra ma trận được nhập
    outputMatrix(matrix, m);

    //d) (20đ) Tính tích của tất cả các phần tử trên 2 đường biên trái và
    //phải
    cout << "\n======== TINH TICH PHAN 2 BIEN ==========\n";
    int result = tichPhanTu2Bien(matrix, m);
    cout << "Tich cua tat ca phan tu tren 2 duong bien trai phai: " << result << endl;
}

