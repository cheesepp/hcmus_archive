#pragma once
#define MAX 100
#include <iostream>
#include <fstream>
using namespace std;

//a) (10đ) Nhập và xuất một mảng số nguyên Arr1 gồm N phần tử(N
//	>= 9 và là số chính phương).
void inputArr1(int a[], int& n);
void outputArr1(int a[], int n);

//b) (20đ) Tạo mảng con Arr2 chứa tất cả các số nguyên tố từ mảng
//Arr1.
bool isPrime(int n);
void primeArr2(int a2[], int a1[], int n, int &a2Index);

//c) (10đ) Tạo mảng 2 chiều Matrix có M dòng và M cột, với M = √�.
//Trong đó, giá trị Matrix[i][j] = Arr1[j + M * i]
void createMatrix(int a[][MAX], int a1[], int n, int &m);

// Hàm test
void outputMatrix(int a[][MAX], int n);

//d) (20đ) Tính tích của tất cả các phần tử trên 2 đường biên trái và
//phải
int tichPhanTu2Bien(int a[][MAX], int m);
