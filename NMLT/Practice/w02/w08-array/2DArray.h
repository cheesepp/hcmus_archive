#pragma once
#include "1DArray.h"

// Bài 1: Viết các hàm nhập, xuất một mảng số nguyên hai chiều có m dòng và n
// cột.Xác định phần tử lớn nhất và nhỏ nhất trong mảng.
void inputI2DArr(int a[][MAX], int& m, int& n);
void outputI2DArr(int a[][MAX], int m, int n);
void findMinMax(int a[][MAX], int m, int n);

//Bài 2: Viết hàm nhập, xuất và sắp xếp ma trận các số thực tăng dần từ trên
//xuống dưới và từ trái sang phải bằng hai phương pháp dùng và không dùng
//mảng phụ
void inputF2DArr(float a[][MAX], int& m, int& n);
void outputF2DArr(float a[][MAX], int m, int n);
void sort2DArr(float a[][MAX], int m, int n);
void sort2DArrWExArr(float arr[][MAX], int m, int n);

//Bài 3: Cho một mảng số nguyên A có m dòng và n cột.Một phần tử được gọi là
//điểm yên ngựa nếu phần tử đó là phần tử nhỏ nhất trong dòng và lớn nhất trong
//cột.Viết hàm xác định tất cả các đểm yên ngựa có thể có trong mảng
void findHorseSaddle(int a[][MAX], int m, int n);

//Bài 4: Cho ma trận các số nguyên A(m x n).Hãy xây dựng ma trận B(m x n) từ
//ma trận A sao cho B[i][j] = số lượng phần tử dương xung quanh A[i][j] trong ma
//trận A(B[i][j] tối đa là 8 và nhỏ nhất là 0)
void create2DArr(int a[][MAX], int m, int n, int b[][MAX]);

//Bài 5: Hãy sắp xếp ma trận sao cho dòng có tổng nhỏ hơn nằm ở trên và dòng
//có tổng dòng lớn hơn nằm ở dưới.
void sortBySumRow(int a[][MAX], int m, int n);