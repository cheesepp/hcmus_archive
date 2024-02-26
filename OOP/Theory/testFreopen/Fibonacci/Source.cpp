//#include "Fibonacci.h"
//
//int main() {
//
//	Fibonacci f;
//	f.generateFibonacci(10);
//	f.print();
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double** createMatrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

void fillRandomMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand();
        }
    }
}

double** initializeMatrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

int main() {

    srand(time(0)); // Seed the random number generator

    double c_time[3] = { 0 };


    int size[3] = { 100, 200, 300 };

    for (int t = 0; t < 3; t++) {
        double** A = createMatrix(size[t]);
        fillRandomMatrix(A, size[t]);

        double** B = createMatrix(size[t]);
        fillRandomMatrix(B, size[t]);

        double** result = initializeMatrix(size[t]);

        clock_t begin = clock();
        for (int i = 0; i < size[t]; i++) {
            for (int j = 0; j < size[t]; j++) {
                for (int k = 0; k < size[t]; k++) {
                    result[i][j] += (A[i][k] * B[k][j]);
                }
            }

        }
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

    for (int t = 0; t < 3; t++) {
        printf("%f ", c_time[t]);
    }



    return 0;
}