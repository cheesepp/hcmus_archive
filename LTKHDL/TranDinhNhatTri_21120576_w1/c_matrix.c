#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ham tao ma tran
double** createMatrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

// ham dien ma tran ngau nhien
void fillRandomMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand();
        }
    }
}

int main() {

    srand(time(0)); // bo tao so ngau nhien

    double c_time[3] = { 0 }; // khai bao mang tinh thoi gian


    int size[3] = { 10, 100, 1000 }; // khai bao mang kich thuoc

    // nhan hai ma  tran
    for (int t = 0; t < 3; t++) {
        double** A = createMatrix(size[t]);
        fillRandomMatrix(A, size[t]);

        double** B = createMatrix(size[t]);
        fillRandomMatrix(B, size[t]);

        double** result = createMatrix(size[t]);

        clock_t begin = clock();
        for (int i = 0; i < size[t]; i++) {
            for (int j = 0; j < size[t]; j++) {
                for (int k = 0; k < size[t]; k++) {
                    result[i][j] += (A[i][k] * B[k][j]);
                }
            }

        }
        
        // giai phong bo nho
        for (int i = 0; i < size[t]; i++) {
            free(A[i]);
            free(B[i]);
            free(result[i]);
        }
        free(A);
        free(B);
        free(result);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        c_time[t] = time_spent;

    }

    // ghi ket qua
    for (int t = 0; t < 3; t++) {
        printf("%f ", c_time[t]);
    }



    return 0;
}
