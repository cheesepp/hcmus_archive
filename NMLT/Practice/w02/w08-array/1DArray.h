#pragma once
#include <iostream>
#define MAX 25
using namespace std;

// Câu 1 Nhập, xuất mảng 1 chiều n phần tử số nguyên
void inputArr(int a[], int& n);
void outputArr(int a[], int n);

// Câu 2 Tìm phần tử lớn nhất trong mảng 1 chiều.
int findMaxElement(int a[], int n);

// Câu 3 Tính tổng các số không âm trong mảng 1 chiều.
int sumOfUnNegNum(int a[], int n);

// Câu 4 Tính tổng các phần tử tại vị trí chẵn trong mảng 1 chiều.
int sumOfEvenIndex(int a[], int n);

// Câu 5 Đếm số lượng số nguyên tố trong mảng 1 chiều.
int countPrimeNum(int a[], int n);

// Câu 6 Tìm phần tử âm lớn nhất trong mảng 1 chiều. Trả về phần tử đó.
int findNegMaxNum(int a[], int n);

// Câu 7 Tìm phần tử không âm nhỏ nhất trong mảng 1 chiều. Trả về phần tử đó.
int findNoneNegMinNum(int a[], int n);

// Câu 8 Kiểm tra mảng 1 chiều có tăng dần không.
void isIncrement(int a[], int n);

// Câu 9 Tính tổng các số chính phương trong mảng 1 chiều.
int sumSoChinhPhuong(int a[], int n);